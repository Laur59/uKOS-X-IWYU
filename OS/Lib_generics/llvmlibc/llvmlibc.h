/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     LLVM libc interface for the Arm Toolchain for Embedded (ATfE >= 22.1.0).
 *
 *           This module provides the integration layer between LLVM libc and
 *           uKOS-X kernel services. Unlike newlib/picolibc, baremetal LLVM libc
 *           does not use the POSIX _open/_read/_write syscall layer and does not
 *           provide FILE* (so no fprintf/dprintf). The integration therefore
 *           implements only:
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
 *           Note: errno storage belongs to LLVM libc (one global reached both
 *           by __llvm_libc_errno() and by the library's own Errno operators).
 *           uKOS-X does not redirect it - it cannot - but the kernel does give
 *           it per-process semantics by swapping it at every context switch in
 *           xLibrary_update(); see OS/Lib_kernels/kern/xLibrary.c.
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

#ifdef CONFIG_MAN_LLVMLIBC_S

#include    <stddef.h>      // for size_t
#include    <stdint.h>      // for uint32_t
#include    <sys/types.h>   // for ssize_t (llvmlibc compat header)

/*
 * Byte-level console access, exported for the downloadable applications.
 *
 * A downloadable application cannot reuse the system image's copy of LLVM libc:
 * the library is built with hidden visibility, so every libc symbol comes out
 * LOCAL HIDDEN in FLASH.elf and --just-symbols hands over globals only. An
 * application that calls printf() therefore links its own copy of the libc
 * stdio objects and must supply the __llvm_libc_stdio_* hooks itself -- see
 * llvmlibc_app_stdio.c, which the application build compiles into every target.
 * These two entry points are what that shim forwards to, so the console path,
 * the serial reservation and the framing all stay in one place.
 */
extern  ssize_t llvmlibc_fdwrite(uint32_t fd, const void *buf, size_t count);
extern  ssize_t llvmlibc_fdread(uint32_t fd, void *buf, size_t count);

#endif  // CONFIG_MAN_LLVMLIBC_S

#endif  // LLVMLIBC_H_
