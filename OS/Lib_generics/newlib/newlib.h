/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; newlib.
; =======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     newLib interface for gcc C compiler (reentrant version).
;
;           See: https://linux.die.net/man/
;
;           Fully or partially supported functions to support
;
;           Open - close - read - write newlib functions
;           _open_r
;           _close_r
;           _write_r
;           _read_r
;
;           Generic newlib functions
;           _times_r
;           _wait_r
;           __errno
;           _fork_r
;           _stat_r
;           _fstat_r
;           _link_r
;           _unlink_r
;           _lseek_r
;           _getpid_r
;           _kill_r
;
;           Allocator newlib functions
;           _sbrk_r
;           __wrap__malloc_r
;           __wrap__free_r
;           __wrap__realloc_r
;           __wrap__calloc_r
;
;           Suported devices controlled by the open - close - read - write newlib functions
;           urt0
;           urt1
;           urt2
;           urt3
;           urt4
;           cdc0
;           cdc1
;           wfi0
;
;           syst
;           def0
;           stdin
;           stdout
;           stderr
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#ifdef __riscv
#include    <machine/time.h>  // for _CLOCKS_PER_SEC_
#endif
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

// This value has to be re-defined accordingly to the
// µKernel specification. For an unclear reason, the newlib
// define:
// #define _CLOCKS_PER_SEC_ 100
// in a machine/time.h

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
