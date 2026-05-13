/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     picolibc interface for modern C compilers (GCC 14+, Clang 21+).
 *
 *           This module provides the integration layer between picolibc
 *           and uKOS-X kernel services. It implements:
 *           - Custom per-process errno mechanism
 *           - I/O redirection to serial device managers
 *           - Memory allocation wrapping to uKOS-X memo_malloc
 *           - System call implementations
 */

/*
 * CRITICAL: Include picolibc.h FIRST to define custom errno function
 * before any C library headers are included.
 */
#include    "picolibc.h"

#include    <stddef.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    <errno.h>
#include    <sys/stat.h>
#include    <sys/time.h>
#include    <sys/times.h>
#include    <sys/types.h>
#include    <time.h>
#include    <unistd.h>

#include    "calendar/calendar.h"
#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros.h"
#if (KKERN_WITH_STATISTICS_S == true)
#include    "macros_core.h"
#endif
#include    "memo/memo.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "types.h"

#ifdef CONFIG_MAN_PICOLIBC_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "picolibc     picolibc manager (GCC 14+, Clang 21+)     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "picolibc manager\n"
                                    "================\n\n"

                                    "This manager provides integration between picolibc C library\n"
                                    "and uKOS-X kernel services. It implements custom errno handling,\n"
                                    "I/O redirection, and memory allocation wrapping.\n\n"

                                    "Picolibc advantages:\n"
                                    "- Smaller code size (typically 10-30% reduction)\n"
                                    "- Modern C standards compliance (C23)\n"
                                    "- Better floating-point support\n"
                                    "- No Thread-Local Storage (TLS) overhead\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Picolibc,                               // Module name
    KID_FAM_GENERICS,                       // Family (defined in the module.h)
    KNUM_PICOLIBC,                          // Module identifier (defined in the module.h)
    NULL,                                   // Address of the initialisation code (early pre-init)
    NULL,                                   // Address of the code (NULL for libraries)
    NULL,                                   // Address of the clean code (clean the module)
    " 1.0",                                 // Revision string (major . minor)
    (1U<<BSHOW),                            // Flags (BSHOW = visible with "man")
    0                                       // Execution cores
);

// Library specific
// ================

typedef struct  devOptTab   devOptTab_t;

#define KPICOLIBC_LN_OUTPUT_BUFFER  128U    // Size of the send buffer

// Prototypes

static  void        local_outLine(serialManager_t serialManager, const uint8_t *output, uint32_t size);
static  uint8_t     local_inbyte(serialManager_t serialManager);
static  ssize_t local_write(serialManager_t serialManager, const void *buf, size_t count);
static  ssize_t local_read(serialManager_t serialManager, void *buf, size_t count);
extern  void        crt0_exit(int number);

// NOLINTBEGIN(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)

/*
 * ============================================================================
 * Custom errno function implementation
 * ============================================================================
 *
 * This function is called by picolibc whenever errno is accessed. It returns
 * a pointer to the current process's errno variable, enabling per-process
 * error state without Thread-Local Storage overhead.
 *
 * The kernel maintains errno as part of each process's control structure and
 * this function simply returns the appropriate pointer based on which process
 * is currently running.
 */

int *__ukos_get_errno(void) {
    proc_t *process;

    // Get the currently running process
    kern_getProcessRun(&process);

    // Return pointer to this process's errno
    // Note: The errno field must be added to proc_t structure
    return &process->oErrnoPicolibc;
}

/*
 * ============================================================================
 * I/O functions (open, close, read, write)
 * ============================================================================
 *
 * These functions redirect I/O operations to uKOS-X serial device managers.
 * Unlike newlib, picolibc uses non-reentrant function names without the _r suffix.
 */

/*
 * \brief _open
 *
 * - open - Open a file
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
int _open(const char_t *path, int oflag, int mode) {
    UNUSED(path);
    UNUSED(oflag);
    UNUSED(mode);

    errno = ENODEV;
    return (-1);
}

/*
 * \brief _close
 *
 * - close - Close a file descriptor
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
int _close(int fd) {
    UNUSED(fd);

    errno = EBADF;
    return (-1);
}

/*
 * \brief _write
 *
 * - write - Write to a file descriptor
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
ssize_t _write(int fd, const void *buf, size_t count) {
    ssize_t         nbPrintChars;
    serialManager_t     serialManager;
    ioChannel_t         ioChannel;
    uint32_t            stdio = (uint32_t)fd;
    proc_t              *process;

    switch (stdio) {

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
            kern_getSerialForProcess(process, &ioChannel);
            serialManager = (serialManager_t)ioChannel;

            serial_reserve(serialManager, KMODE_WRITE, KWAIT_INFINITY);
            nbPrintChars = local_write(serialManager, buf, count);
            serial_release(serialManager, KMODE_WRITE);

            break;
        }

// KXXX: use the specified Serial Communication Manager with its reservation

        default: {
            serialManager = (serialManager_t)stdio;

            serial_reserve(serialManager, KMODE_WRITE, KWAIT_INFINITY);
            nbPrintChars = local_write(serialManager, buf, count);
            serial_release(serialManager, KMODE_WRITE);

            break;
        }
    }
    return (nbPrintChars);
}

/*
 * \brief _read
 *
 * - read - Read from a file descriptor
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
ssize_t _read(int fd, void *buf, size_t count) {
    ssize_t         nbReadChars;
    serialManager_t     serialManager;
    ioChannel_t         ioChannel;
    uint32_t            stdio = (uint32_t)fd;
    proc_t              *process;

    switch (stdio) {

// KNOTR and KSTDERR: use the default Serial Communication Manager without to reserve it

        case KSTDERR:
        case KNOTR: {
            nbReadChars = local_read(KDEF0, buf, count);
            break;
        }

// KSYST and KSTDIN and KSTDOUT: use the process specified Serial Communication Manager with its reservation

        case KSTDIN:
        case KSTDOUT:
        case KSYST: {
            kern_getProcessRun(&process);
            kern_getSerialForProcess(process, &ioChannel);
            serialManager = (serialManager_t)ioChannel;

            serial_reserve(serialManager, KMODE_READ, KWAIT_INFINITY);
            nbReadChars = local_read(serialManager, buf, count);
            serial_release(serialManager, KMODE_READ);

            break;
        }

// KXXX: use the specified Serial Communication Manager with its reservation

        default: {
            serialManager = (serialManager_t)stdio;

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
 * File status functions
 * ============================================================================
 */

/*
 * \brief _fstat
 *
 * - fstat - Get file status
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
int _fstat(int fd, struct stat *st) {
    UNUSED(fd);

    // All file descriptors are character devices (TTY)
    st->st_mode = S_IFCHR;
    st->st_blksize = 0;
    return (0);
}

/*
 * \brief _isatty
 *
 * - isatty - Check if file descriptor is a TTY
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
int _isatty(int fd) {
    // All our file descriptors are TTYs (serial devices)
    switch (fd) {
        case 0:     // stdin
        case 1:     // stdout
        case 2:     // stderr
            return (1);

        default:
            errno = EBADF;
            return (0);
    }
}

/*
 * \brief _lseek
 *
 * - lseek - Reposition read/write file offset
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
off_t _lseek(int fd, off_t offset, int whence) {
    UNUSED(fd);
    UNUSED(offset);
    UNUSED(whence);

    // Serial devices don't support seeking
    errno = ESPIPE;
    return (off_t)(-1);
}

/*
 * ============================================================================
 * Process management functions
 * ============================================================================
 */

/*
 * \brief _getpid
 *
 * - getpid - Get process ID
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
pid_t _getpid(void) {
    proc_t      *process;
    uint32_t    core;
    int         id;

    core = GET_RUNNING_CORE;

    kern_getProcessRun(&process);
    id = (int)(((uintptr_t)process - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));
    return (pid_t)id;
}

/*
 * \brief _kill
 *
 * - kill - Send signal to a process
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
int _kill(pid_t pid, int sig) {
    UNUSED(pid);
    UNUSED(sig);

    errno = ENOSYS;     // Function not implemented
    return (-1);
}

/*
 * \brief _exit
 *
 * - exit - Terminate process
 *
 * This function terminates the current process and does not return.
 */
void _exit(int status) {
    // Call the CRT0 exit handler
    crt0_exit(status);

    // Should never reach here, but loop forever just in case
    while (1) {
        // Infinite loop
    }
}

/*
 * ============================================================================
 * Time functions
 * ============================================================================
 */

/*
 * \brief _gettimeofday
 *
 * - gettimeofday - Get current time
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
int _gettimeofday(struct timeval *tv, void *tz) {
    UNUSED(tz);

    uint64_t    unixTime;

    if (tv == NULL) {
        errno = EFAULT;
        return (-1);
    }

// Read the 64-bit time @ 1-us resolution
// Extract the seconds and the micro-seconds

    calendar_readUnixTime(KFROM_TIMER, &unixTime);

    tv->tv_sec  = (time_t)(unixTime / CLOCKS_PER_SEC);
    tv->tv_usec = (suseconds_t)(unixTime % CLOCKS_PER_SEC);
    return (0);
}

/*
 * \brief _times
 *
 * - times - Get process times
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
clock_t _times(struct tms *buf) {
    struct timeval  tv = { 0, 0 };

    if (buf == NULL) {
        errno = EFAULT;
        return (clock_t)(-1);
    }

    #if (KKERN_WITH_STATISTICS_S == true)
    proc_t  *process;

    kern_getProcessRun(&process);

    PRIVILEGE_ELEVATE;
    buf->tms_utime  = (clock_t) process->oStatistic.oTimePAvg;
    buf->tms_stime  = (clock_t)(process->oStatistic.oTimeKAvg + process->oStatistic.oTimeEAvg);
    buf->tms_cutime = (clock_t) process->oStatistic.oTimePCum;
    buf->tms_cstime = (clock_t)(process->oStatistic.oTimeKCum + process->oStatistic.oTimeECum);
    PRIVILEGE_RESTORE;

    #else
    *buf = (struct tms){ 0 };
    #endif

    _gettimeofday(&tv, NULL);
    return ((clock_t)tv.tv_usec);
}

/*
 * ============================================================================
 * Memory allocation functions (linker-wrapped)
 * ============================================================================
 *
 * These functions wrap picolibc's malloc/free/realloc/calloc and redirect
 * them to uKOS-X's memo_malloc() memory allocator.
 *
 * The linker --wrap mechanism is used:
 *   -Wl,--wrap=malloc,--wrap=free,--wrap=realloc,--wrap=calloc
 *
 * This causes calls to malloc() to be redirected to __wrap_malloc(), etc.
 */

/*
 * \brief __wrap_malloc
 *
 * - malloc - Allocate a memory block
 *
 * Picolibc version (no reent parameter, direct errno access)
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
 *
 * - free - Free a memory block
 *
 * Picolibc version (no reent parameter, direct errno access)
 */
void __wrap_free(void *ptr) {
    if (ptr != NULL) {
        memo_free(ptr);
    }
}

/*
 * \brief __wrap_realloc
 *
 * - realloc - Reallocate a memory block
 *
 * Picolibc version (no reent parameter, direct errno access)
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
 *
 * - calloc - Allocate and zero-initialise a memory block
 *
 * Picolibc version (no reent parameter, direct errno access)
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
            uint8_t     output[KPICOLIBC_LN_OUTPUT_BUFFER + 2];
            uint32_t    i, j = 0U;
    const   uint8_t     *wkAscii;

    wkAscii = (const uint8_t *)buf;

    for (i = 0U; i < count; i++) {
        output[j] = wkAscii[i];

        j++;
        if (j >= KPICOLIBC_LN_OUTPUT_BUFFER) {
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
 * Picolibc compatibility aliases
 * ============================================================================
 *
 * Picolibc calls functions without underscore prefix, so we need to provide
 * aliases or weak definitions.
 */

// Alias underscore versions to non-underscore versions
ssize_t write(int fd, const void *buf, size_t count) __attribute__((alias("_write")));
ssize_t read(int fd, void *buf, size_t count) __attribute__((alias("_read")));
int close(int fd) __attribute__((alias("_close")));
int fstat(int fd, struct stat *st) __attribute__((alias("_fstat")));
int isatty(int fd) __attribute__((alias("_isatty")));
off_t lseek(int fd, off_t offset, int whence) __attribute__((alias("_lseek")));
pid_t getpid(void) __attribute__((alias("_getpid")));
int gettimeofday(struct timeval *tv, void *tz) __attribute__((alias("_gettimeofday")));
clock_t times(struct tms *buf) __attribute__((alias("_times")));

/*
 * \brief stdout FILE pointer
 *
 * Picolibc requires stdout to be defined as a FILE pointer.
 * For embedded systems without file I/O, we can provide a dummy pointer.
 *
 * Note: These are declared as 'extern FILE * const' in stdio.h,
 * so we provide the actual storage here.
 *
 * However, some picolibc implementations (like ATfE) define stdin/stdout/stderr
 * as macros using _REENT, so we only define them as variables when needed.
 */
#ifndef _REENT_STDIN
static FILE __stdio_file[3];  // Storage for stdin, stdout, stderr
FILE * const stdin = &__stdio_file[0];
FILE * const stdout = &__stdio_file[1];
FILE * const stderr = &__stdio_file[2];
#endif

/*
 * \brief Heap boundaries for sbrk
 *
 * Picolibc's default sbrk implementation requires these symbols.
 * Since we're using memo_malloc, we don't need sbrk, but we
 * need to define these to satisfy the linker.
 */
char __heap_start[1];
char __heap_end[1];

/*
 * \brief Stub _sbrk implementation
 *
 * Some picolibc implementations (like ATfE) require _sbrk to be provided.
 * Since uKOS-X uses its own memory allocator (memo_malloc), we provide
 * a stub that always fails.
 */
void *_sbrk(ptrdiff_t incr)
{
    (void)incr;
    errno = ENOMEM;
    return (void *)-1;
}

// NOLINTEND(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)

#endif  // CONFIG_MAN_PICOLIBC_S
