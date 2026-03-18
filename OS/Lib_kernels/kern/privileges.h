/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Privilege management.
 *
 *           This module implements the software primitives.
 *
 *           Privilege system calls
 *           ---------------------------
 *
 *           void    privileges_init(void) *
 *           int32_t kern_setPrivilegeMode(uint8_t mode) *
 *           void    kern_privilegeElevate(void) * !!! Not for user applications
 */

#pragma once

#include    <stdint.h>

#ifdef UKOS_S
#include    "macros_soc.h"
#endif

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup privileges Privileges
 *
 * \brief Privileges
 *
 * Privilege management
 *
 * @{
 */

#ifdef __cplusplus
extern  "C" {
#endif

#ifdef UKOS_S
extern  volatile    bool    vPriv_insideSVC[KNB_CORES];                 // Inside an SVC call
extern  volatile    bool    vPriv_insideException[KNB_CORES];
#endif

extern  void    privileges_init(void);

/*!
 * \brief Set the privilege mode
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_setPrivilegeMode(KPROC_PRIVILEGED);
 *    ...
 *    code executed in privileged mode
 *    ...
 *    status = kern_setPrivilegeMode(KPROC_USER);
 * \endcode
 *
 * - This function allows to change the execution mode (Privileged / user)
 *
 * \param[in]   mode            KPROC_USER, Reduction the process rights in the user mode
 * \param[in]   -               KPROC_PRIVILEGED, Elevate the process rights in the privileged mode
 * \return      KERR_KERN_NOERR OK
 *
 */
extern  int32_t kern_setPrivilegeMode(uint8_t mode);

/*!
 * \brief Elevate the privilege
 *
 * Call example in C:
 *
 * \code{.c} *
 *    kern_privilegeElevate();
 *    ...
 * \endcode
 *
 * - This is not a user call.
 * - Coming from the TRAP dispatcher.
 * - Set the privileged mode
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::naked]]
extern  void    kern_privilegeElevate(void);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
