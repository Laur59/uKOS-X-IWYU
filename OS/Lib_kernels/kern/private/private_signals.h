/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Signal management.
 *
 *           Private uKernel variables.
 */

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup signals
 * @{
 */

/*!
 * \defgroup private_signals Private Signals
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

#define KSIGN_ANONYMOUS_ID  "Sign_anonymous"

typedef struct  dsin        dsin_t;

struct dsin {
            uint32_t    oSignalBitPending;                      // The pending signals
            uint32_t    oSignalBitGenerate;                     // The generated signals
            proc_t      *oSignalFromProcess;                    // Ptr on the process that generate the signals
};

struct  sign {
    const   char_t      *oIdentifier;                           // Group identifier
            uint16_t    oState;                                 // Group state
            #define     BSIGN_INSTALLED     0U                  // Group installed

            uint32_t    oGroupNumber;                           // Group number
            uint32_t    oUsedBit;                               // Used bit
            dsin_t      oSynchro[KKERN_NB_PROCESSES];           // Process synchro
            void        (*oCbOnWaiting)(sign_t *handle,
                                        uint32_t signals,
                                        proc_t *fromProcess);
};

extern  list_t      vKern_listSign[KNB_CORES];                  // Signal list (processes waiting for a signal)
extern  sign_t      vKern_sign[KNB_CORES][KKERN_NB_SIGNALS];    // Group of signals
extern  uint16_t    vKern_nbSign[KNB_CORES];                    // Nb of used signals
extern  uint16_t    vKern_nbMaxSign[KNB_CORES];                 // Max number of used signals

/**@}*/
/**@}*/
/**@}*/
