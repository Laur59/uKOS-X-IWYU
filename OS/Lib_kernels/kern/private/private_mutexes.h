/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; private_mutexes.
; ================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Kern - Mutex management.
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
 * \addtogroup mutexes
 * @{
 */

/*!
 * \defgroup private_mutexes Private Mutexes
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

#define KMUTX_ANONYMOUS_ID  "Mutx_anonymous"

struct  mutx {
    const   char_t      *oIdentifier;                           // Mutex identifier
            uint16_t    oState;                                 // Mutex state
            #define     BMUTX_INSTALLED     0U                  // Mutex installed

            int32_t     oCounter;                               // Mutex counter
            int32_t     oMaxCounter;                            // Mutex counter max value
            #define     KMUTX_MAX_CPT       INT32_MAX           //
            #define     KMUTX_MIN_CPT       INT32_MIN           //

            proc_t      *oOwner;                                // Ptr on the process owner of the mutex
            list_t      oList;                                  // Mutex list
};

extern  mutx_t      vKern_mutx[KNB_CORES][KKERN_NB_MUTEXES];        // Mutex
extern  uint16_t    vKern_nbMutx[KNB_CORES];                    // Nb of used mutex
extern  uint16_t    vKern_nbMaxMutx[KNB_CORES];                 // Max number of used mutex

/**@}*/
/**@}*/
/**@}*/
