/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * POSIX <fcntl.h> compatibility header for the LLVM libc build.
 *
 * Baremetal LLVM libc ships no <fcntl.h>. It also has no POSIX file layer at
 * all: unlike newlib and picolibc, it does not route stdio through
 * _open/_close/_read/_write, so uKOS-X implements no open() for this library
 * (the newlib and picolibc managers only ever provided a stub that fails).
 *
 * This header therefore declares NOTHING -- no open(), no creat(), no fcntl(),
 * and no O_* flags, which would be meaningless without a function to pass them
 * to. Code that really needs them must fail to compile.
 *
 * It exists because sources include <fcntl.h> out of habit without using it:
 * a_Basics/readIMU and n_NewLibs/basic both include it and reference no symbol
 * from it. Prefer deleting the include from such a source when touching it;
 * this header is what keeps the C-library-agnostic sources building meanwhile.
 *
 * If a future LLVM libc ships a real <fcntl.h>, this header would shadow it --
 * the compat/ directory precedes the toolchain include paths. Delete this file
 * at that point.
 */

#ifndef LLVMLIBC_COMPAT_FCNTL_H_
#define LLVMLIBC_COMPAT_FCNTL_H_

#ifndef CONFIG_MAN_LLVMLIBC_S
#error "LLVM libc compatibility <fcntl.h> reached from a non-llvmlibc build"
#endif

#endif  // LLVMLIBC_COMPAT_FCNTL_H_
