/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     Force-included declaration shim for the LLVM libc build.
 *
 *           uKOS-X code prints through the POSIX dprintf(fd, ...) function,
 *           obtained from <stdio.h> when building with newlib or picolibc.
 *           Baremetal LLVM libc has no FILE* support and therefore does NOT
 *           declare (or define) dprintf/vdprintf. uKOS-X provides its own
 *           implementation in llvmlibc.c, but the many callers that only
 *           include <stdio.h> need a visible prototype.
 *
 *           This header is injected into every translation unit via the
 *           compiler's -include option, but ONLY when C_LIBRARY=llvmlibc
 *           (see Ports/cmake/system.cmake and Applications/cmake/application.cmake).
 *           It therefore adds zero cost and zero risk to the newlib/picolibc
 *           builds, and does not require touching the dozens of call sites.
 */

#ifndef LLVMLIBC_SHIM_H_
#define LLVMLIBC_SHIM_H_

#ifdef CONFIG_MAN_LLVMLIBC_S

#include    <stdarg.h>

#ifdef __cplusplus
extern  "C" {
#endif

// POSIX-style formatted output to a file descriptor, implemented by uKOS-X
// in OS/Lib_generics/llvmlibc/llvmlibc.c on top of the serial managers.
int     dprintf(int fd, const char *format, ...);
int     vdprintf(int fd, const char *format, va_list ap);

// POSIX environment / timezone functions used by the calendar manager but not
// provided by baremetal LLVM libc. uKOS-X supplies minimal stubs in llvmlibc.c
// (no environment on baremetal; local time therefore runs in UTC).
int     setenv(const char *name, const char *value, int overwrite);
void    tzset(void);

#ifdef __cplusplus
}
#endif

#endif  // CONFIG_MAN_LLVMLIBC_S

#endif  // LLVMLIBC_SHIM_H_
