/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     crt0 for the uKOS-X system.
 *           See "ld.pdf" file, "Using LD, the GNU linker" page 48.
 */

#pragma once

#include    <stdint.h>

#include    "types.h"

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

// Runtime specific
// ================

extern  uint32_t    vCrt0_randomSeed;

extern  int32_t     aStart(uint32_t argc, const char_t *argv[]);
extern  int32_t     boot(void);
extern  void        crt0(void);
extern  void        exit_terminate(void);
extern  void        exce_init(void);        // NOLINT(readability-redundant-declaration): proper header declaration

#ifdef __cplusplus

// Do not declare main in c++

#else
#if (!defined(__NO_EXTERN_MAIN))
extern  int         main(int argc, const char *argv[]);
#endif
#endif

/*
 * \brief crt0_exit
 *
 * code = EXIT_OS_SUCCESS               --->        Success, commit a suicide
 * code = EXIT_OS_FAILURE               --->        Failure; commit a suicide
 * code = EXIT_OS_PANIC                 --->        Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_MALLOC_BROKEN   --->        Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_STACK_UNDERFLOW --->        Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_NO_SYSCALL      --->        Failure; panic. System is stopped
 * code = default                       --->        Failure; panic. System is stopped
 *
 * \param[in]   number  Exit number
 *
 * \note This function does not return a value (None).
 *
 */
void    crt0_exit(int number);

#ifdef __cplusplus
}
#endif
