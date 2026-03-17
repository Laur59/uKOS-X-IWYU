/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; private_pools.
; ==============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Kern - Memory pools.
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
 * \addtogroup pools
 * @{
 */

/*!
 * \defgroup private_pools Private Pools
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

#if (KKERN_NB_POOLS > 0)

#define KPOOL_ANONYMOUS_ID  "Pool_anonymous"

struct  pool {
    const   char_t      *oIdentifier;                           // Memory pool identifier
            uint16_t    oState;                                 // Memory pool state
            #define     BPOOL_INSTALLED     0U                  // Memory pool installed
            #define     BPOOL_CONFIGURED    1U                  // Memory pool configured

            uint32_t    oNbBlocks;                              // Number of blocks
            uint32_t    oBlockSize;                             // Block size
            void        *oBlockArray;                           // Block array
            void        **oUsedBlocks;                          // Used Blocks
            sema_t      *oReleaseSema;                          // Semaphore to signal a pool release
};

extern  pool_t      vKern_pool[KNB_CORES][KKERN_NB_POOLS];      // Pools
extern  uint16_t    vKern_nbPool[KNB_CORES];                    // Nb of used pools
extern  uint16_t    vKern_nbMaxPool[KNB_CORES];                 // Max number of used pools
#endif

/**@}*/
/**@}*/
/**@}*/
