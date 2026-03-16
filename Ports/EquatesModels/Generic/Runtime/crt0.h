/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; crt0.
; =====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     crt0 for the uKOS-X system.
;           See "ld.pdf" file, "Using LD, the GNU linker" page 48.
;
;-----
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
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
#if !(defined(__NO_EXTERN_MAIN))
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
