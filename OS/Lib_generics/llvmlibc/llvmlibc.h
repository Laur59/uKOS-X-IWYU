/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     LLVM libc interface for the Arm Toolchain for Embedded (ATfE >= 22.1.0).
 *
 *           This module provides the integration layer between LLVM libc and
 *           uKOS-X kernel services. Unlike newlib/picolibc, baremetal LLVM libc
 *           does not use the POSIX _open/_read/_write syscall layer, does not
 *           provide FILE* (so no fprintf/dprintf), and owns its own errno
 *           storage. The integration therefore implements only:
 *
 *           I/O retargeting hooks (see libc/src/__support/OSUtil/baremetal/io.h)
 *           __llvm_libc_stdio_read
 *           __llvm_libc_stdio_write
 *           __llvm_libc_stdin_cookie / __llvm_libc_stdout_cookie / __llvm_libc_stderr_cookie
 *
 *           dprintf / vdprintf shim (LLVM libc has no FILE*-based dprintf)
 *
 *           Allocator functions (wrapped via linker --wrap onto memo_malloc)
 *           __wrap_malloc / __wrap_free / __wrap_realloc / __wrap_calloc
 *
 *           Finalisation and heap boundary symbols
 *           __llvm_libc_exit
 *           __llvm_libc_heap_limit
 *
 *           Note: errno is provided by LLVM libc itself (__llvm_libc_errno is
 *           defined inside libc.a), so uKOS-X does not manage a per-process
 *           errno for this C library.
 */

#ifndef LLVMLIBC_H_
#define LLVMLIBC_H_

/*
 * Integer equivalence of stdin, stdout, stderr.
 *
 * LLVM libc in ATfE does not ship <unistd.h>, so the STDIN/STDOUT/STDERR_FILENO
 * constants are defined here directly (they are only used inside this manager
 * to route the standard streams to the serial managers).
 */
#define KSTDIN      0
#define KSTDOUT     1
#define KSTDERR     2

#endif  // LLVMLIBC_H_
