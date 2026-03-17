/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; private_preciseSignals.
; =======================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Kern - Precise signals.
;
;           Private uKernel variables.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

#include    "kern/kern.h"
#include    "macros_soc.h"

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup preciseSignals
 * @{
 */

/*!
 * \defgroup private_preciseSignals Private Precise Signals
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#if (KKERN_NB_PRECISE_SIGNALS > 0)

#define KPRCS_ANONYMOUS_ID          "Prcs_anonymous"
#define KPRCS_DEFAULT_SIGNAL_GROUP  "Def_Signal_Group"

extern  prcs_t      vKern_prcs[KNB_CORES][KKERN_NB_PRECISE_SIGNALS];    // Precise signals
extern  uint16_t    vKern_nbPrcs[KNB_CORES];                            // Nb of used precise signals
extern  uint16_t    vKern_nbMaxPrcs[KNB_CORES];                         // Max number of used precise signals
#endif

/**@}*/
/**@}*/
/**@}*/
