/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * LLVM libc console hooks for the downloadable applications.
 *
 * A downloadable application cannot reuse the system image's copy of LLVM libc.
 * The library is built with hidden visibility, so every libc symbol it
 * contributes to FLASH.elf comes out LOCAL HIDDEN, and an application consumes
 * FLASH.elf through -Wl,--just-symbols, which imports globals only. Calling
 * printf() in an application therefore extracts printf.cpp.obj (and puts,
 * putchar, stdout, ...) from libc.a into the application's own link, where the
 * hidden references to the retargeting hooks have nothing to resolve against:
 *
 *   ld.lld: error: undefined hidden symbol: __llvm_libc_stdio_write
 *   ld.lld: error: undefined hidden symbol: __llvm_libc_stdout_cookie
 *
 * Forcing the entry points into the system image does not help -- they land
 * hidden there too. The fix is this file, which the application build compiles
 * into every target when C_LIBRARY=llvmlibc (see Applications/cmake/
 * application.cmake). It defines the hooks inside the application's own link,
 * where a hidden reference resolves normally, and forwards the bytes to the
 * system image through llvmlibc_fdwrite / llvmlibc_fdread -- ordinary uKOS-X
 * globals, so --just-symbols does hand them over. The serial reservation, the
 * output framing and the file-descriptor routing all stay in llvmlibc.c.
 *
 * The cost is the libc stdio code the application links for itself; the
 * console path is not duplicated.
 *
 * An application that prints only through dprintf() never triggers any of
 * this: dprintf is uKOS-X's own, and is exported from the system image.
 */

#include    <stddef.h>
#include    <stdint.h>
#include    <sys/types.h>   // for ssize_t (llvmlibc compat header)

#include    "llvmlibc/llvmlibc.h"

#ifdef CONFIG_MAN_LLVMLIBC_S

// The cookies carry the uKOS-X file descriptor of each standard stream, the
// same convention llvmlibc.c uses on the system side.

static  int     local_stdinFd  = KSTDIN;
static  int     local_stdoutFd = KSTDOUT;
static  int     local_stderrFd = KSTDERR;

void    *__llvm_libc_stdin_cookie  = &local_stdinFd;
void    *__llvm_libc_stdout_cookie = &local_stdoutFd;
void    *__llvm_libc_stderr_cookie = &local_stderrFd;

/*
 * \brief __llvm_libc_stdio_read
 *
 * - LLVM libc read retargeting hook, application side.
 */
ssize_t __llvm_libc_stdio_read(void *cookie, char *buf, size_t size) {
    uint32_t    fd = (cookie != NULL) ? (uint32_t)*(const int *)cookie : (uint32_t)KSTDIN;

    return (llvmlibc_fdread(fd, buf, size));
}

/*
 * \brief __llvm_libc_stdio_write
 *
 * - LLVM libc write retargeting hook, application side.
 */
ssize_t __llvm_libc_stdio_write(void *cookie, const char *buf, size_t size) {
    uint32_t    fd = (cookie != NULL) ? (uint32_t)*(const int *)cookie : (uint32_t)KSTDOUT;

    return (llvmlibc_fdwrite(fd, buf, size));
}

#endif  // CONFIG_MAN_LLVMLIBC_S
