/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - C library integration for xLibrary (newlib, picolib, etc.) management.
 *
 *           Private uKernel variables.
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

// No global impure data for picolibc - errno is picolibc's own global, parked
// in proc_t.oErrno while a process is not running

#elif defined(CONFIG_MAN_LLVMLIBC_S)
#include    "llvmlibc/llvmlibc.h"

// No global impure data for llvmlibc - errno is LLVM libc's own global, parked
// in proc_t.oErrno while a process is not running

// No global impure data for llvmlibc - errno is owned by LLVM libc (__llvm_libc_errno)

#else
#error "No C library configured (CONFIG_MAN_NEWLIB_S, CONFIG_MAN_PICOLIBC_S or CONFIG_MAN_LLVMLIBC_S required)"
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
