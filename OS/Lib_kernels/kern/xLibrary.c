/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; xLibrary.
; =========

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;   Kern - C library integration for xlib management.
;
;   This module is responsible for C library integration with uKOS-X.
;   For newlib: creating and swapping the impure data (_impure_ptr).
    For picolibc: initialising per-process errno (no context switch overhead).
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

#include    "kern/private/private_xLibrary.h"

#include    <stdint.h>

#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros_soc.h"

#ifdef CONFIG_MAN_NEWLIB_S
#include    <sys/reent.h>
#include    "newlib/newlib.h"

// Per-process reentrancy structures for newlib
reent_t     vKern_impureData[KNB_CORES][KKERN_NB_PROCESSES];

#elifdef CONFIG_MAN_PICOLIBC_S
#include    "picolibc/picolibc.h"

// No global storage needed for picolibc - errno is stored per-process in proc_t

#else
#error "No C library configured (CONFIG_MAN_NEWLIB_S or CONFIG_MAN_PICOLIBC_S required)"
#endif

#ifdef CONFIG_MAN_NEWLIB_S

/*
 * \brief Initialise the impure data of the process (newlib)
 *
 * This function initialises the newlib reentrancy structure for the process
 * and sets the process's oLocal pointer to point to this structure.
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]   *handle     Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_initialise(proc_t *handle) {
    uint16_t    i;
    uint32_t    core;
    proc_t      *process = handle;

    core = GET_RUNNING_CORE;

    i = (uint16_t)(((uintptr_t)process - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));
    _REENT_INIT_PTR(&vKern_impureData[core][i]);
    process->oInternal.oLocal = &vKern_impureData[core][i];
}

/*
 * \brief update the impure pointer with the impure data of the process (newlib)
 *
 * This function updates the global _impure_ptr to point to the current process's
 * reentrancy structure. Called during context switches.
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_update(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (vKern_runProc[core]->oInternal.oLocal != nullptr) {
        _impure_ptr = (reent_t *)vKern_runProc[core]->oInternal.oLocal;
    }
}

#elifdef CONFIG_MAN_PICOLIBC_S

/*
 * \brief Initialise the per-process errno for picolibc
 *
 * This function initialises the errno variable stored in the process structure.
 * Picolibc uses __ukos_get_errno() to access this value, so no context switch
 * updates are required.
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]   *handle     Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_initialise(proc_t *handle) {
    proc_t      *process = handle;

    // Initialise per-process errno (stored in proc_t structure)
    process->oErrnoPicolibc = 0;
}

/*
 * \brief No-op for picolibc (no context switch update required)
 *
 * Picolibc uses __ukos_get_errno() which automatically returns the current
 * process's errno pointer, so no explicit update is needed during context switches.
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
void    xLibrary_update(void) {
    // No action needed for picolibc
    // errno is accessed via __ukos_get_errno() which automatically
    // returns the current process's errno pointer
}

#endif
