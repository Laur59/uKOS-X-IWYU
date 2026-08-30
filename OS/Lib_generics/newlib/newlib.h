/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     newLib interface for gcc C compiler (reentrant version).
 *
 *           See: https://linux.die.net/man/
 *
 *           Fully or partially supported functions to support
 *
 *           Open - close - read - write newlib functions
 *           _open_r
 *           _close_r
 *           _write_r
 *           _read_r
 *
 *           Generic newlib functions
 *           _times_r
 *           _wait_r
 *           __errno
 *           _fork_r
 *           _stat_r
 *           _fstat_r
 *           _link_r
 *           _unlink_r
 *           _lseek_r
 *           _getpid_r
 *           _kill_r
 *
 *           Allocator newlib functions
 *           _sbrk_r
 *           __wrap__malloc_r
 *           __wrap__free_r
 *           __wrap__realloc_r
 *           __wrap__calloc_r
 *
 *           Suported devices controlled by the open - close - read - write newlib functions
 *           urt0
 *           urt1
 *           urt2
 *           urt3
 *           urt4
 *           cdc0
 *           cdc1
 *           wfi0
 *
 *           syst
 *           def0
 *           stdin
 *           stdout
 *           stderr
 */

#pragma once

#include    <sys/reent.h>
#include    <unistd.h>        // for STDERR_FILENO, STDIN_FILENO, STDOUT_FILENO

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup newlib Newlib
 *
 * \brief Newlib
 *
 * Newlib management
 *
 * @{
 */

typedef struct  _reent  reent_t;

// Integer equivalence of stdin, stdout, stderr

#define KSTDIN      STDIN_FILENO
#define KSTDOUT     STDOUT_FILENO
#define KSTDERR     STDERR_FILENO

// _CLOCKS_PER_SEC_ must match the µKernel specification: the kernel counter has
// a 1-us resolution, so the value is 1'000'000. Two independent mechanisms make
// it so, and they agree.
//
// Upstream newlib gives Arm 100 in machine/time.h, following Arm semihosting,
// which counts centiseconds; RISC-V already gets 1'000'000 there. Both uKOS-X
// toolchains patch that header to move __arm__ into the microsecond branch --
// Patches/newlib/<version>/0002-Patch-time.h-for-uKOS.patch for GCC, and for
// LLVM the same file carried by ukos_patches 0001, which also fixes LLVM libc.
//
// Independently of the toolchain, configure_arm_core() and
// configure_riscv_core() in Ports/cmake/proj_config.cmake pass
// -D_CLOCKS_PER_SEC_=1000000 together with -D_MACHTIME_H_, the header's own
// include guard, so the header is suppressed and the value comes from the
// command line. uKOS-X therefore gets 1'000'000 even on an unpatched toolchain.
//
// The assertion below catches a build where neither mechanism applied.

#define CLOCKS_PER_SEC_CHECK(x) ((x) == 1000000U)
static_assert(CLOCKS_PER_SEC_CHECK(_CLOCKS_PER_SEC_), "_CLOCKS_PER_SEC_ must be 1000000");

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
