/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * POSIX <sys/types.h> compatibility header for the LLVM libc build.
 *
 * Baremetal LLVM libc ships no POSIX header under sys/ apart from sys/queue.h,
 * so a portable source that includes <sys/types.h> fails to compile. The types
 * it does define live in the llvm-libc-types/ directory, one per file; this
 * header re-exports the subset that exists on baremetal, the same way LLVM
 * libc's own public headers compose them.
 *
 * Absent from baremetal LLVM libc, and therefore absent here: pid_t, uid_t,
 * gid_t, mode_t, dev_t, ino_t, nlink_t, blksize_t, blkcnt_t and the BSD u_*
 * aliases. Code needing those needs a real operating system, not this header.
 *
 * See sys/time.h in this directory for how the compat/ directory is put on the
 * include path (llvmlibc builds only).
 */

#ifndef LLVMLIBC_COMPAT_SYS_TYPES_H_
#define LLVMLIBC_COMPAT_SYS_TYPES_H_

#ifndef CONFIG_MAN_LLVMLIBC_S
#error "LLVM libc compatibility <sys/types.h> reached from a non-llvmlibc build"
#endif

#include    <llvm-libc-types/size_t.h>       // IWYU pragma: export
#include    <llvm-libc-types/ssize_t.h>      // IWYU pragma: export
#include    <llvm-libc-types/off_t.h>        // IWYU pragma: export
#include    <llvm-libc-types/time_t.h>       // IWYU pragma: export
#include    <llvm-libc-types/suseconds_t.h>  // IWYU pragma: export
#include    <llvm-libc-types/clock_t.h>      // IWYU pragma: export

#endif  // LLVMLIBC_COMPAT_SYS_TYPES_H_
