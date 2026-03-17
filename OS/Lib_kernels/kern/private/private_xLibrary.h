/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; private_xLibrary.
; =================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Kern - impure data for xLibrary (newlib, picolib, etc.) management.
;
;           Private uKernel variables.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup xLibrary
 * @{
 */

/*!
 * \defgroup private_xLibrary Private XLibrary
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#include    <string.h>      // IWYU pragma: keep

#include    "kern/kern.h"
#include    "macros_soc.h"

#ifdef CONFIG_MAN_NEWLIB_S
#include    <reent.h>
#include    "newlib/newlib.h"

extern  reent_t     vKern_impureData[KNB_CORES][KKERN_NB_PROCESSES];    // Array of impure pointer for newlib

#elif defined(CONFIG_MAN_PICOLIBC_S)
#include    "picolibc/picolibc.h"

// No global impure data for picolibc - errno is stored per-process in proc_t

#else
#error "No C library configured (CONFIG_MAN_NEWLIB_S or CONFIG_MAN_PICOLIBC_S required)"
#endif

// Prototypes

/*!
 * \brief Initialise the impure data of the process
 *
 * \param[in]   *handle     Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern  void    xLibrary_initialise(proc_t *handle);

/*!
 * \brief update the impure pointer with the impure data of the process
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern  void    xLibrary_update(void);

/**@}*/
/**@}*/
/**@}*/
