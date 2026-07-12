/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     LLVM libc interface for the Arm Toolchain for Embedded (ATfE >= 22.1.0).
 *
 *           This module provides the integration layer between LLVM libc and
 *           uKOS-X kernel services. It implements:
 *           - I/O retargeting hooks (__llvm_libc_stdio_read/write + cookies)
 *           - dprintf/vdprintf shim (LLVM libc has no FILE*-based dprintf)
 *           - Memory allocation wrapping to uKOS-X memo_malloc
 *           - Finalisation (__llvm_libc_exit) and heap boundary symbol
 *
 *           Unlike newlib/picolibc, baremetal LLVM libc:
 *           - does not use the POSIX _open/_close/_read/_write syscall layer
 *             (standard I/O is retargeted via the __llvm_libc_stdio_* hooks),
 *           - does not provide unistd.h / sys headers or FILE*,
 *           - owns its own errno (__llvm_libc_errno is defined inside libc.a),
 *             so no per-process errno is managed here.
 */

#include    "llvmlibc.h"

#include    <stdarg.h>
#include    <stddef.h>
#include    <stdint.h>
#include    <stdio.h>       // for vsnprintf and ssize_t
#include    <string.h>

#include    <errno.h>
#include    <time.h>        // for time_t and the time() prototype

#include    "calendar/calendar.h"
#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros.h"
#include    "macros_core.h" // for INTERRUPTION_OFF / INTERRUPTION_RESTORE
#include    "memo/memo.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h" // for LOG / KFATAL_MANAGER
#include    "serial/serial.h"
#include    "types.h"

#ifdef CONFIG_MAN_LLVMLIBC_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "llvmlibc     LLVM libc manager (ATfE 22.1+)            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "llvmlibc manager\n"
                                    "================\n\n"

                                    "This manager provides integration between the LLVM libc C library\n"
                                    "(Arm Toolchain for Embedded) and uKOS-X kernel services. It retargets\n"
                                    "the standard I/O streams to the serial managers, provides a dprintf\n"
                                    "shim (LLVM libc has no FILE* support), and wraps the allocator onto\n"
                                    "the uKOS-X memo manager.\n\n"

                                    "LLVM libc advantages:\n"
                                    "- Actively developed, standards-focused (C23)\n"
                                    "- Will become the default C library in ATfE 24\n"
                                    "- Modular, testable implementation\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Llvmlibc,                               // Module name
    KID_FAM_GENERICS,                       // Family (defined in the module.h)
    KNUM_LLVMLIBC,                          // Module identifier (defined in the module.h)
    NULL,                                   // Address of the initialisation code (early pre-init)
    NULL,                                   // Address of the code (NULL for libraries)
    NULL,                                   // Address of the clean code (clean the module)
    " 1.0",                                 // Revision string (major . minor)
    (1U<<BSHOW),                            // Flags (BSHOW = visible with "man")
    0                                       // Execution cores
);

// Library specific
// ================

#define KLLVMLIBC_LN_OUTPUT_BUFFER  128U    // Size of the serial send buffer
#define KLLVMLIBC_LN_DPRINTF_BUFFER 256U    // Size of the dprintf fast-path stack buffer
#define KLLVMLIBC_LN_DPRINTF_BIG    2048U   // Size of the per-core dprintf overflow buffer

// Prototypes

static  void        local_outLine(serialManager_t serialManager, const uint8_t *output, uint32_t size);
static  uint8_t     local_inbyte(serialManager_t serialManager);
static  ssize_t     local_write(serialManager_t serialManager, const void *buf, size_t count);
static  ssize_t     local_read(serialManager_t serialManager, void *buf, size_t count);
static  ssize_t     local_fdwrite(uint32_t fd, const void *buf, size_t count);
static  ssize_t     local_fdread(uint32_t fd, void *buf, size_t count);
static  void        local_dprintfBigBufferInit(uint32_t core);
extern  void        crt0_exit(int number);

// Override the C-library exit() so a process terminates through crt0_exit without
// running LLVM libc's __cxa_finalize (see the exit() definition for the rationale).
void    exit(int status);

// POSIX / newlib compatibility symbols that prebuilt third-party archives
// (e.g. the Pico SDK TinyUSB port) reference but LLVM libc does not provide.
void    _exit(int status);
void    __assert_func(const char *file, int line, const char *func, const char *failedexpr);

// NOLINTBEGIN(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)

/*
 * ============================================================================
 * File-descriptor routing
 * ============================================================================
 *
 * Standard streams and dprintf targets are expressed as small integer file
 * descriptors that select a serial manager, mirroring the picolibc manager:
 *   - KSTDERR / KNOTR      : default serial manager (no reservation)
 *   - KSTDIN/KSTDOUT/KSYST : the running process's serial manager (reserved)
 *   - anything else        : that value used directly as a serial manager
 */

/*
 * \brief local_fdwrite
 *
 * - Route a buffer to the serial manager selected by the file descriptor
 */
static  ssize_t local_fdwrite(uint32_t fd, const void *buf, size_t count) {
    ssize_t         nbPrintChars;
    serialManager_t     serialManager;
    proc_t              *process;

    switch (fd) {

// KNOTR and KSTDERR: use the default Serial Communication Manager without to reserve it

        case KSTDERR:
        case KNOTR: {
            nbPrintChars = local_write(KDEF0, buf, count);
            break;
        }

// KSYST and KSTDIN and KSTDOUT: use the process specified Serial Communication Manager with its reservation

        case KSTDIN:
        case KSTDOUT:
        case KSYST: {
            kern_getProcessRun(&process);
            kern_getSerialForProcess(process, &serialManager);

            serial_reserve(serialManager, KMODE_WRITE, KWAIT_INFINITY);
            nbPrintChars = local_write(serialManager, buf, count);
            serial_release(serialManager, KMODE_WRITE);

            break;
        }

// KXXX: use the specified Serial Communication Manager with its reservation

        default: {
            serialManager = (serialManager_t)fd;

            serial_reserve(serialManager, KMODE_WRITE, KWAIT_INFINITY);
            nbPrintChars = local_write(serialManager, buf, count);
            serial_release(serialManager, KMODE_WRITE);

            break;
        }
    }
    return (nbPrintChars);
}

/*
 * \brief local_fdread
 *
 * - Read from the serial manager selected by the file descriptor
 */
static  ssize_t local_fdread(uint32_t fd, void *buf, size_t count) {
    ssize_t         nbReadChars;
    serialManager_t     serialManager;
    proc_t              *process;

    switch (fd) {

        case KSTDERR:
        case KNOTR: {
            nbReadChars = local_read(KDEF0, buf, count);
            break;
        }

        case KSTDIN:
        case KSTDOUT:
        case KSYST: {
            kern_getProcessRun(&process);
            kern_getSerialForProcess(process, &serialManager);

            serial_reserve(serialManager, KMODE_READ, KWAIT_INFINITY);
            nbReadChars = local_read(serialManager, buf, count);
            serial_release(serialManager, KMODE_READ);

            break;
        }

        default: {
            serialManager = (serialManager_t)fd;

            serial_reserve(serialManager, KMODE_READ, KWAIT_INFINITY);
            nbReadChars = local_read(serialManager, buf, count);
            serial_release(serialManager, KMODE_READ);

            break;
        }
    }
    return (nbReadChars);
}

/*
 * ============================================================================
 * dprintf / vdprintf shim
 * ============================================================================
 *
 * Baremetal LLVM libc has no FILE* support and therefore does not provide the
 * POSIX dprintf/vdprintf functions that uKOS-X uses throughout. They are
 * implemented here on top of vsnprintf (which LLVM libc does provide) and the
 * serial routing above. The prototypes are force-included via llvmlibc_shim.h.
 *
 * uKOS output that exceeds the fast-path stack buffer (the boot logo, "man"
 * help text, multi-line CLI results such as bench's) is reformatted into a
 * per-core static buffer rather than a heap allocation: dprintf runs on every
 * process, including ones with small stacks, so the overflow buffer cannot
 * live on the caller's stack, and a first version of this shim that routed it
 * through memo_malloc/memo_free was found (via a full toolchain bench sweep)
 * to corrupt the heap under sustained alloc/free churn. A static buffer has
 * no such failure mode; a dedicated per-core mutex serialises the rare case
 * where two processes on the same core both need it at once.
 */

static  char    vDprintfBigBuffer[KNB_CORES][KLLVMLIBC_LN_DPRINTF_BIG];
static  mutx_t  *vDprintfBigMutex[KNB_CORES];

/*
 * \brief local_dprintfBigBufferInit
 *
 * - Lazily create this core's big-buffer mutex. Race-free: bracketed by
 *   INTERRUPTION_OFF/RESTORE, mirroring the memo manager's local_init.
 */
static  void local_dprintfBigBufferInit(uint32_t core) {
    static  bool    vInit[KNB_CORES] = MCSET(false);

    INTERRUPTION_OFF;
    if (!vInit[core]) {
        vInit[core] = true;
        if (kern_createMutex("Llvmlibc_dprintf", &vDprintfBigMutex[core]) != KERR_KERN_NOERR) {
            LOG(KFATAL_MANAGER, "llvmlibc: create mutx");
            exit(EXIT_OS_PANIC);
        }
    }
    INTERRUPTION_RESTORE;
}

/*
 * \brief vdprintf
 *
 * - Formatted output of a va_list to a file descriptor
 */
int vdprintf(int fd, const char *format, va_list ap) {
    char        stackBuffer[KLLVMLIBC_LN_DPRINTF_BUFFER];
    char        *buffer;
    va_list     apCopy;
    int         nbChars;
    size_t      length;
    uint32_t    core = 0U;
    bool        usedBigBuffer = false;

// First pass: format into the stack buffer. vsnprintf returns the number of
// characters that WOULD have been written, so a value >= the buffer size means the
// output was truncated. A second copy of the arguments is kept so the string can be
// reformatted into vDprintfBigBuffer in that case: unlike picolibc (whose dprintf
// streams to _write with no total-length cap), this shim materialises the whole
// formatted string, and uKOS output such as the boot logo and the "man" help texts
// exceeds the stack buffer.

    va_copy(apCopy, ap);
    nbChars = vsnprintf(stackBuffer, sizeof(stackBuffer), format, ap);
    if (nbChars < 0) {
        va_end(apCopy);
        return (nbChars);
    }

    buffer = stackBuffer;
    length = (size_t)nbChars;

    if (length >= sizeof(stackBuffer)) {
        core = GET_RUNNING_CORE;
        local_dprintfBigBufferInit(core);
        kern_lockMutex(vDprintfBigMutex[core], KWAIT_INFINITY);
        usedBigBuffer = true;

// Still clamp defensively: a dprintf() call formatting more than 2 KB of output
// would be a bug elsewhere (nothing in uKOS currently comes close), not a
// reason to fail here.

        if (length >= sizeof(vDprintfBigBuffer[core])) {
            length = sizeof(vDprintfBigBuffer[core]) - 1U;
        }
        (void)vsnprintf(vDprintfBigBuffer[core], length + 1U, format, apCopy);
        buffer = vDprintfBigBuffer[core];
    }
    va_end(apCopy);

    (void)local_fdwrite((uint32_t)fd, buffer, length);

    if (usedBigBuffer) {
        kern_unlockMutex(vDprintfBigMutex[core]);
    }
    return (nbChars);
}

/*
 * \brief dprintf
 *
 * - Formatted output to a file descriptor
 */
int dprintf(int fd, const char *format, ...) {
    va_list ap;
    int     nbChars;

    va_start(ap, format);
    nbChars = vdprintf(fd, format, ap);
    va_end(ap);
    return (nbChars);
}

/*
 * ============================================================================
 * LLVM libc I/O retargeting hooks
 * ============================================================================
 *
 * LLVM libc redirects its standard streams through these hooks (see the
 * baremetal io.h retargeting interface). The cookies identify which stream is
 * being accessed; here they carry the integer file descriptor so the shared
 * routing helpers can select the appropriate serial manager.
 *
 * The cookies are initialised statically because uKOS-X uses its own start-up
 * code (not the ATfE crt0), so _platform_init() is never called.
 */

static  int     local_stdinFd  = KSTDIN;
static  int     local_stdoutFd = KSTDOUT;
static  int     local_stderrFd = KSTDERR;

void    *__llvm_libc_stdin_cookie  = &local_stdinFd;
void    *__llvm_libc_stdout_cookie = &local_stdoutFd;
void    *__llvm_libc_stderr_cookie = &local_stderrFd;

/*
 * \brief __llvm_libc_stdio_read
 *
 * - LLVM libc read retargeting hook
 */
ssize_t __llvm_libc_stdio_read(void *cookie, char *buf, size_t size) {
    uint32_t    fd = (cookie != NULL) ? (uint32_t)*(const int *)cookie : (uint32_t)KSTDIN;

    return local_fdread(fd, buf, size);
}

/*
 * \brief __llvm_libc_stdio_write
 *
 * - LLVM libc write retargeting hook
 */
ssize_t __llvm_libc_stdio_write(void *cookie, const char *buf, size_t size) {
    uint32_t    fd = (cookie != NULL) ? (uint32_t)*(const int *)cookie : (uint32_t)KSTDOUT;

    return local_fdwrite(fd, buf, size);
}

/*
 * ============================================================================
 * Memory allocation functions (linker-wrapped)
 * ============================================================================
 *
 * These wrap LLVM libc's malloc/free/realloc/calloc (which are undefined in
 * libc.a and expected to be provided) and redirect them to uKOS-X memo_malloc.
 * The linker --wrap mechanism turns calls to malloc() into __wrap_malloc(), etc.
 */

/*
 * \brief __wrap_malloc
 */
void *__wrap_malloc(size_t size) {
    void *address;

    address = memo_malloc(KMEMO_ALIGN_8, ((uint32_t)size * sizeof(uint8_t)), "__wrap_malloc");
    if (address == NULL) {
        errno = ENOMEM;
        return (NULL);
    }

    return (address);
}

/*
 * \brief __wrap_free
 */
void __wrap_free(void *ptr) {
    if (ptr != NULL) {
        memo_free(ptr);
    }
}

/*
 * \brief __wrap_realloc
 */
void *__wrap_realloc(void *ptr, size_t size) {
    void *address;

    // If ptr is NULL, realloc behaves like malloc
    if (ptr == NULL) {
        return __wrap_malloc(size);
    }

    // If size is 0, realloc behaves like free
    if (size == 0) {
        __wrap_free(ptr);
        return (NULL);
    }

    // Allocate new block
    address = memo_malloc(KMEMO_ALIGN_8, ((uint32_t)size * sizeof(uint8_t)), "__wrap_realloc");
    if (address == NULL) {
        errno = ENOMEM;
        return (NULL);
    }

    // Copy old data to new block (memo_malloc handles internal size tracking)
    memcpy(address, ptr, size);

    // Free old block
    memo_free(ptr);

    return (address);
}

/*
 * \brief __wrap_calloc
 */
void *__wrap_calloc(size_t nmemb, size_t size) {
    size_t  total_size;
    void    *address;

    // Check for overflow
    if (nmemb != 0 && size > SIZE_MAX / nmemb) {
        errno = ENOMEM;
        return (NULL);
    }

    total_size = nmemb * size;

    address = memo_malloc(KMEMO_ALIGN_8, (uint32_t)total_size, "__wrap_calloc");
    if (address == NULL) {
        errno = ENOMEM;
        return (NULL);
    }

    // Zero-initialise the allocated memory
    memset(address, 0, total_size);

    return (address);
}

/*
 * ============================================================================
 * Helper functions for I/O
 * ============================================================================
 */

/*
 * \brief local_write
 *
 * - Write a string to the comm device
 *
 */
static  ssize_t local_write(serialManager_t serialManager, const void *buf, size_t count) {
            uint8_t     output[KLLVMLIBC_LN_OUTPUT_BUFFER + 2];
            uint32_t    i, j = 0U;
    const   uint8_t     *wkAscii;

    wkAscii = (const uint8_t *)buf;

    for (i = 0U; i < count; i++) {
        output[j] = wkAscii[i];

        j++;
        if (j >= KLLVMLIBC_LN_OUTPUT_BUFFER) {
            local_outLine(serialManager, output, j);
            j = 0U;
        }
    }

    if (j > 0U) {
        local_outLine(serialManager, output, j);
    }
    return ((ssize_t)count);
}

/*
 * \brief local_read
 *
 * - Read a string to the comm device
 *
 */
static  ssize_t local_read(serialManager_t serialManager, void *buf, size_t count) {
    uint8_t     *ascii;
    uint32_t    i;
    bool        terminate = false;

    i = (uint32_t)count;
    if (count > 0U) {
        ascii = (uint8_t *)buf;

        i = 0U;
        do {
            *(ascii + i) = local_inbyte(serialManager);
            if ((*(ascii + i) == '\n') || (*(ascii + i) == '\r')) {
                terminate = true;
            }
            i++;
        } while ((i < (uint32_t)count) && (!terminate));
    }
    return ((ssize_t)i);
}

/*
 * \brief local_inbyte
 *
 * - Read a byte from the comm device
 *
 */
static  uint8_t local_inbyte(serialManager_t serialManager) {
    int32_t     status;
    uint32_t    size;
    uint8_t     byte = 0U;

    do {
        kern_suspendProcess(1U);
        size = 1U;
        status = serial_read(serialManager, &byte, &size);
    } while (status != KERR_SERIAL_NOERR);

    if (byte > 0x7FU) { byte = (uint8_t)'?'; }

    return (byte);
}

/*
 * \brief local_outLine
 *
 * - Write a string to the comm device
 *
 */
static  void    local_outLine(serialManager_t serialManager, const uint8_t *output, uint32_t size) {
    int32_t     status;

    while (true) {
        status = serial_write(serialManager, output, size);
        if (status != KERR_SERIAL_NOERR) {
            kern_suspendProcess(1U);
        }
        else {

// Give some time to allow the manager to send the data
// before sending another bloc

            kern_suspendProcess(1U);
            return;
        }
    }
}

/*
 * ============================================================================
 * Time source
 * ============================================================================
 *
 * LLVM libc provides the calendar conversion functions (gmtime_r, localtime_r,
 * mktime, asctime, ...) but not time(), which needs a platform clock source.
 * uKOS-X supplies it from the kernel's 64-bit Unix-time counter (1-us
 * resolution). Note: CLOCKS_PER_SEC is 100 under LLVM libc, so the
 * microsecond-to-second divisor is spelled out explicitly.
 */

/*
 * \brief time
 *
 * - Return the current calendar time in seconds since the Unix epoch.
 */
time_t time(time_t *tloc) {
    uint64_t    unixTime = 0U;
    time_t      seconds;

    calendar_readUnixTime(KFROM_TIMER, &unixTime);
    seconds = (time_t)(unixTime / 1000000ULL);      // 64-bit counter is 1-us resolution

    if (tloc != NULL) {
        *tloc = seconds;
    }
    return (seconds);
}

/*
 * ============================================================================
 * POSIX environment / timezone stubs
 * ============================================================================
 *
 * The calendar manager configures the timezone with setenv("TZ", ...) followed
 * by tzset(). Baremetal LLVM libc provides neither a process environment nor
 * these functions, so uKOS-X supplies minimal stubs. There is no environment
 * to store into, so local time effectively runs in UTC under LLVM libc.
 */

/*
 * \brief setenv
 *
 * - No environment on baremetal; accept and ignore.
 */
int setenv(const char *name, const char *value, int overwrite) {
    (void)name;
    (void)value;
    (void)overwrite;
    return (0);
}

/*
 * \brief tzset
 *
 * - No timezone database on baremetal; no action.
 */
void tzset(void) {
    // No action: LLVM libc has no TZ environment support on baremetal
}

/*
 * ============================================================================
 * Finalisation and heap boundary
 * ============================================================================
 */

/*
 * \brief __llvm_libc_exit
 *
 * LLVM libc calls this after running destructors to finish execution in a way
 * appropriate for the platform. uKOS-X routes it to the CRT0 exit handler.
 */
void __llvm_libc_exit(int status) {
    crt0_exit(status);

    // Should never reach here, but loop forever just in case
    while (1) {
        // Infinite loop
    }
}

/*
 * \brief __llvm_libc_heap_limit
 *
 * LLVM libc's own allocator delimits the heap with [_end, __llvm_libc_heap_limit).
 * uKOS-X wraps malloc onto memo_malloc, so that allocator is not used; this
 * symbol is provided only to satisfy the linker should any object reference it.
 */
char __llvm_libc_heap_limit[1];

/*
 * ============================================================================
 * POSIX / newlib compatibility symbols
 * ============================================================================
 *
 * Prebuilt third-party archives (notably the Pico SDK TinyUSB port used by the
 * RP2350 target) are compiled against newlib and reference _exit and
 * __assert_func, neither of which LLVM libc provides (it has exit and
 * __assert_fail). uKOS-X supplies both, routing termination to the CRT0 exit.
 */

/*
 * \brief _exit
 *
 * - Terminate the program (POSIX name expected by newlib-compiled code).
 */
void _exit(int status) {
    crt0_exit(status);

    while (1) {
        // Should never reach here
    }
}

/*
 * \brief exit
 *
 * A uKOS-X process terminates (or panics the system) through crt0_exit. LLVM libc's
 * own exit() would first run __cxa_thread_finalize()/__cxa_finalize(), walking the
 * atexit / C++ finalisation list — meaningless for a per-process exit in a baremetal
 * RTOS, and it faults when that list is not in its initialised empty state. Route
 * exit() straight to crt0_exit, matching _exit() / __llvm_libc_exit() (and picolibc,
 * whose exit() only walks the empty .fini_array).
 */
void exit(int status) {
    crt0_exit(status);

    while (1) {
        // Should never reach here
    }
}

/*
 * \brief __assert_func
 *
 * - newlib assertion-failure handler. Terminates the program.
 */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr) {
    (void)file;
    (void)line;
    (void)func;
    (void)failedexpr;

    crt0_exit(1);

    while (1) {
        // Should never reach here
    }
}

// NOLINTEND(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)

#endif  // CONFIG_MAN_LLVMLIBC_S
