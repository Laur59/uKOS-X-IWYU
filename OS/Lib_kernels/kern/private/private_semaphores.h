/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Semaphore management.
 *
 *           Private uKernel variables.
 */

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup semaphores
 * @{
 */

/*!
 * \defgroup private_semaphores Private Semaphores
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

#define KSEMA_ANONYMOUS_ID  "Sema_anonymous"

struct  sema {
    const   char_t      *oIdentifier;                           // Semaphore identifier
            uint16_t    oState;                                 // Semaphore state
            #define     BSEMA_INSTALLED     0U                  // Semaphore installed

            int32_t     oCounter;                               // Semaphore counter
            int32_t     oMaxCounter;                            // Semaphore counter max value
            #define     KSEMA_MAX_CPT       INT32_MAX           //
            #define     KSEMA_MIN_CPT       INT32_MIN           //

            proc_t      *oOwner;                                // Ptr on the process owner of the semaphore
            list_t      oList;                                  // Semaphore list
};

extern  sema_t      vKern_sema[KNB_CORES][KKERN_NB_SEMAPHORES]; // Semaphores
extern  uint16_t    vKern_nbSema[KNB_CORES];                    // Nb of used semaphores
extern  uint16_t    vKern_nbMaxSema[KNB_CORES];                 // Max number of used semaphores

/**@}*/
/**@}*/
/**@}*/
