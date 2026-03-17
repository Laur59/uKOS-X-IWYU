/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; private_temporal.
; =================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Kern - time management.
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
 * \addtogroup temporal
 * @{
 */

/*!
 * \defgroup private_temporal Private Temporal
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#include    <stdint.h>

#include    "kern/kern.h"
#include    "macros_soc.h"

extern              list_t      vKern_listWait[KNB_CORES];                  // Wait list (processes waiting for a time)
extern  volatile    uint32_t    vKern_TimeException[KNB_CORES];             // Sum of time spent inside all the exceptions

// Prototypes

/*!
 * \brief Get the next wake-up time (for the low power mode)
 *
 * \warning call usable only by the uKernel.
 *
 */
extern  uint32_t    temporal_getNextLowPowerTime(void);

/**@}*/
/**@}*/
/**@}*/
