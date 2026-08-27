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
 *           Only what LLVM libc does not declare itself belongs here: a
 *           declaration that the library also provides must match it exactly,
 *           including the __NOEXCEPT qualifier, or every C++ translation unit
 *           fails to compile.
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

// LLVM libc qualifies every declaration with __NOEXCEPT, which expands to
// noexcept in C++. A redeclaration without it is a hard error ("exception
// specification in declaration does not match previous declaration"), so every
// declaration below mirrors the qualifier. C ignores it.
#ifdef __cplusplus
#define KLLVMLIBC_NOEXCEPT  noexcept
#else
#define KLLVMLIBC_NOEXCEPT
#endif

#ifdef __cplusplus
extern  "C" {
#endif

// POSIX-style formatted output to a file descriptor, implemented by uKOS-X
// in OS/Lib_generics/llvmlibc/llvmlibc.c on top of the serial managers.
int     dprintf(int fd, const char *format, ...) KLLVMLIBC_NOEXCEPT;
int     vdprintf(int fd, const char *format, va_list ap) KLLVMLIBC_NOEXCEPT;

// POSIX timezone function used by the calendar manager: baremetal LLVM libc
// neither declares nor implements it, and uKOS-X supplies a minimal stub in
// llvmlibc.c (no environment on baremetal; local time therefore runs in UTC).
//
// setenv() is deliberately NOT declared here. <stdlib.h> already declares it --
// only the implementation is missing, and llvmlibc.c provides that. The former
// declaration collided with the libc one in every C++ translation unit.
void    tzset(void) KLLVMLIBC_NOEXCEPT;

#ifdef __cplusplus
}
#endif

#endif  // CONFIG_MAN_LLVMLIBC_S

#endif  // LLVMLIBC_SHIM_H_
