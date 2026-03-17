/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; private_softwareTimer.
; ======================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Kern - Software timers.
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
 * \addtogroup softwareTimer
 * @{
 */

/*!
 * \defgroup private_softwareTimer Private SoftwareTimer
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
#include    "types.h"

#if (KKERN_NB_SOFTWARE_TIMERS > 0)

#define KSTIM_ANONYMOUS     "Stim_anonymous"

struct  stim {
    const   char_t      *oIdentifier;                                   // Software timer identifier
            uint16_t    oState;                                         // Software timer state
            #define     BSTIM_INSTALLED         0U                      // Software timer installed
            #define     BSTIM_CONFIGURED        1U                      // Software timer configured
            #define     BSTIM_RE_CONFIGURED     2U                      // Software timer reconfigured
            #define     BSTIM_RUNNING           3U                      // Software timer is running
            #define     BSTIM_EXECUTED          4U                      // Software timer executed (once)

            uint32_t    oInitCounter;                                   // Initial time (decremented)
            uint32_t    oCounter;                                       // Continuous time (decremented)
            tspc_t      oTimerSpec;                                     // Software timer specifications
};

extern  uint16_t    vKern_curStim[KNB_CORES];                           // Currently executed software timer
extern  proc_t      *vStimer_handle[KNB_CORES];                         // Daemon Software timer handle
extern  stim_t      vKern_stim[KNB_CORES][KKERN_NB_SOFTWARE_TIMERS];    // Software timers
extern  uint16_t    vKern_nbStim[KNB_CORES];                            // Nb of used software timers
extern  uint16_t    vKern_nbMaxStim[KNB_CORES];                         // Max number of used software timers
#endif

/**@}*/
/**@}*/
/**@}*/
