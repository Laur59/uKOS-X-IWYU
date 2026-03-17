/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; debug.
; ======

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;   Kern - Debug list management.
;
;   This module implements the debug list primitives.
;
;   Software debug system calls
;   ---------------------------
;
;   void    debug_init(void);
;   int32_t kern_stopProcess(proc_t *handle);
;   int32_t kern_reactivateProcess(proc_t *handle);
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

#include    "kern_types.h"  // IWYU pragma: keep

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup debug Debug
 *
 * \brief Debug
 *
 * Debug management
 *
 * @{
 */

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

extern  void    debug_init(void);

/*!
 * \brief Stop a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_stopProcess(process);
 * \endcode
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOPRO The process does not exist
 * \return      KERR_KERN_DBGER The process is already in the debug list
 * \return      KERR_KERN_DBNOS The process is attached to a sensitive list and cannot be stopped
 *
 */
extern  int32_t kern_stopProcess(proc_t *handle);

/*!
 * \brief Reactivate a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_reactivateProcess(process);
 * \endcode
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOPRO The process does not exist
 * \return      KERR_KERN_DBGER The process is not in the debug list
 *
 */
extern  int32_t kern_reactivateProcess(proc_t *handle);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
