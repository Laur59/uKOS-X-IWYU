/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; private_memo.
; =============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     memo manager.
;
;           Private uKernel variables.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \addtogroup memo
 * @{
 */

/*!
 * \defgroup private_memo Private Memo
 *
 * \brief Private memo variables and structures
 *
 * Internal memo structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#include    "kern/kern.h"
#include    "memo/memo.h"

#define KMAB_SIGNATURE      (((uint32_t)'m'<<24U) | ((uint32_t)'a'<<16U) | ((uint32_t)'b'<<8U) | (uint32_t)'_')

#ifdef __LP64__
// Mandatory:
// Some CPUs (like cortex m) need to have the stack 16-byte aligned.
// CPUs with caches need 64-byte alignments

struct  memoMab {
        const   char_t      *oIdentifier;                                   // Mab user identifier
                proc_t      *oProcess;                                      // Ptr on the process who has reserved the memory bloc
                uint32_t    oMabSignature;                                  // Mab signature
                uint32_t    oSzAllocated;                                   // Block size (allocated)
                uint32_t    oSzAvailable;                                   // Block size (available)
                uint32_t    oPadBlock;                                      // Paddering for the block alignement
                memoMab_t   *oPtrPreBlock;                                  // Ptr on the previous block
                memoMab_t   *oPtrNexBlock;                                  // Ptr on the next block
                uintptr_t   oAlign[2];                                      // To ensure the 64-byte alignment
};
typedef char p__LINE__[ ((sizeof(struct memoMab) % 64) == 0) ? 1 : -1];     // Just to generate a compiler error if not % 64

#else
// Mandatory:
// Some CPUs (like cortex m) need to have the stack 8-byte aligned.
// CPUs with caches need 32-byte alignments

struct  memoMab {
        const   char_t      *oIdentifier;                                   // Mab user identifier
                proc_t      *oProcess;                                      // Ptr on the process who has reserved the memory bloc
                uint32_t    oMabSignature;                                  // Mab signature
                uint32_t    oSzAllocated;                                   // Block size (allocated)
                uint32_t    oSzAvailable;                                   // Block size (available)
                uint32_t    oPadBlock;                                      // Paddering for the block alignement
                memoMab_t   *oPtrPreBlock;                                  // Ptr on the previous block
                memoMab_t   *oPtrNexBlock;                                  // Ptr on the next block
};
typedef char p__LINE__[ ((sizeof(struct memoMab) % 32) == 0) ? 1 : -1];     // Just to generate a compiler error if not % 32
#endif

typedef struct {
                uint32_t    oUsdMemory;                                     // Used memory
                uint32_t    oNbBlocks;                                      // Number of blocks
                uint32_t    oNbMaxBlocks;                                   // Max number of blocks
                uint32_t    oUsdMaxMemory;                                  // Max used memory
                uint32_t    oFailedAllocations;                             // Number of failed allocations
} mallocHeapInfo_t;

extern  mallocHeapInfo_t    vMemo_heapInfo;

/**@}*/
/**@}*/
/**@}*/
