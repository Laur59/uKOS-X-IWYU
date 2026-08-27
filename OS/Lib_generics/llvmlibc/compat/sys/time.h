/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * POSIX <sys/time.h> compatibility header for the LLVM libc build.
 *
 * Baremetal LLVM libc ships no POSIX header under sys/ apart from sys/queue.h.
 * It declares struct timeval, suseconds_t and gettimeofday() in <time.h>
 * instead, so a portable source that follows POSIX and includes <sys/time.h>
 * fails to compile with a "file not found" error.
 *
 * This directory is added to the include path only when C_LIBRARY=llvmlibc
 * (see Ports/cmake/system.cmake and Applications/cmake/application.cmake).
 * The newlib and picolibc builds keep their own <sys/time.h>, and the OS and
 * application sources stay C-library agnostic.
 *
 * Only the declarations LLVM libc actually provides are exposed. The rest of
 * POSIX <sys/time.h> (settimeofday, utimes, getitimer/setitimer, struct
 * itimerval and the timeradd/timersub/timercmp macros) has no LLVM libc
 * counterpart and is deliberately absent; add it here if a port ever needs it.
 */

#ifndef LLVMLIBC_COMPAT_SYS_TIME_H_
#define LLVMLIBC_COMPAT_SYS_TIME_H_

#ifndef CONFIG_MAN_LLVMLIBC_S
#error "LLVM libc compatibility <sys/time.h> reached from a non-llvmlibc build"
#endif

// struct timeval, suseconds_t, time_t and gettimeofday() all live in <time.h>
// under baremetal LLVM libc.

#include    <time.h>    // IWYU pragma: export

#endif  // LLVMLIBC_COMPAT_SYS_TIME_H_
