/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 *   Kernel shared types and forward declarations.
 *
 *   This header contains configuration macros, enums, type
 *   definitions, and forward declarations shared across
 *   kernel modules. It was created to break circular
 *   dependencies between kern.h and module headers.
 *
 *   Module headers include this file directly, while
 *   kern.h remains the public API for external code.
 */

/*
;------------------------------------------------------------------------
; kern_types.
; ===========
;
; Project:  uKOS-X
; Purpose:
;    Kernel shared types and forward declarations.
;
;           This header contains configuration macros, enums, type
;           definitions, and forward declarations shared across
;           kernel modules. It was created to break circular
;           dependencies between kern.h and module headers.
;
;           Module headers include this file directly, while
;           kern.h remains the public API for external code.
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup kern_types Kern Types
 *
 * \brief Kernel Shared Types
 *
 * Shared types, configuration, and forward declarations
 *
 * @{
 */

#include    <stdint.h>

#include    "types.h"       // IWYU pragma: keep

// Exported standard kernel configuration
// --------------------------------------

// Kernel functionalities

#ifndef KKERN_WITH_STATISTICS_S
#define KKERN_WITH_STATISTICS_S     true
#endif
#ifndef KKERN_WITH_DEBUG_S
#define KKERN_WITH_DEBUG_S          true
#endif
#ifndef KKERN_WITH_TRTC_S
#define KKERN_WITH_TRTC_S           true
#endif

// The number of objects

#ifndef KKERN_NB_PROCESSES
#define KKERN_NB_PROCESSES          48U
#endif
#if (defined(KKERN_NB_MAILBOXES))
static_assert((KKERN_NB_MAILBOXES >= 8U), "KKERN_NB_MAILBOXES shall be >= 8");
#else
#define KKERN_NB_MAILBOXES          48U
#endif
#if (defined(KKERN_NB_SEMAPHORES))
static_assert((KKERN_NB_SEMAPHORES >= 8U), "KKERN_NB_SEMAPHORES shall be >= 8");
#else
#define KKERN_NB_SEMAPHORES         48U
#endif
#if (defined(KKERN_NB_MUTEXES))
static_assert((KKERN_NB_MUTEXES >= 8U), "KKERN_NB_MUTEXES shall be >= 8");
#else
#define KKERN_NB_MUTEXES            48U
#endif
#if (defined(KKERN_NB_SIGNALS))
static_assert((KKERN_NB_SIGNALS >= 1U), "KKERN_NB_SIGNALS shall be >= 1");
#else
#define KKERN_NB_SIGNALS            8U
#endif
#ifndef KKERN_NB_SOFTWARE_TIMERS
#define KKERN_NB_SOFTWARE_TIMERS    8U
#endif
#ifndef KKERN_NB_POOLS
#define KKERN_NB_POOLS              8U
#endif
#ifndef KKERN_NB_PRECISE_SIGNALS
#define KKERN_NB_PRECISE_SIGNALS    8U
#endif

#define KKERN_NB_PRCS_CHECK(x)      ((x * KKERN_NB_SIGNALS) >= x)
static_assert(KKERN_NB_PRCS_CHECK(KKERN_NB_PRECISE_SIGNALS), "KKERN_NB_SIGNALS cannot be 0 when KKERN_NB_PRECISE_SIGNALS > 0");

// The kernel temporal (in ms)

#ifndef KKERN_TIC_TIME
#define KKERN_TIC_TIME              1U
#endif
#ifndef KKERN_TIC_FREQUENCY
#define KKERN_TIC_FREQUENCY         1000U
#endif
#ifndef KKERN_TICKCOUNT_PER_SECOND
#define KKERN_TICKCOUNT_PER_SECOND  (1000U * 1000U)
#endif
#ifndef KKERN_PROC_TIMEOUT
#define KKERN_PROC_TIMEOUT          20U
#endif

// Misc equates
// ------------

// Size of the object names identifiers + \0 !!! Always aligned !!!

#define KKERN_OBJECT_SZ_ID          31U                         //

// Special process handle (used by semaphores and signals)

#define KKERN_HANDLE_WRONG          ((proc_t *)0x00000000u)     // Wrong handle
#define KKERN_HANDLE_FROM_ISR       ((proc_t *)0x00000001u)     // From ISR (semaphore or other objects)
#define KKERN_HANDLE_BROADCAST      ((proc_t *)0x00000002u)     // Broadcast (signal broadcast)

// uKernel states

enum {
        KKERN_NOT_READY = 0U,                                   // Kernel not ready
        KKERN_INITIALISED,                                      // Kernel Initialised
        KKERN_RUNNING                                           // KernelRunning
};

// Critical sections

enum {
        KENTER_CRITICAL = 0U,                                   // Entry into a critical section
        KEXIT_CRITICAL                                          // Exit from a critical section
};

// Idle states

enum {
        KKERN_IDLE_IN = 0U,                                     // Enter in the idle process
        KKERN_IDLE_OUT                                          // Output from the idle process
};

// uKernel Low power modes (used by the idle process)

enum {
        KKERN_CPU_MODE_NORMAL = 0U,                             // CPU in a normal running mode
        KKERN_CPU_MODE_DEEP_SLEEP,                              // CPU in a deep low power mode
        KKERN_CPU_MODE_HIBERNATE,                               // CPU in a hibernate low power mode
        KKERN_CPU_MODE_STOP                                     // CPU in a stop mode
};

// Priorities

typedef enum {
        KKERN_PRIORITY_HIGH_Reserved = 0U,                      // 00 - High priority (highest priority)
        KKERN_PRIORITY_HIGH_01,                                 //
        KKERN_PRIORITY_HIGH_02,                                 //
        KKERN_PRIORITY_HIGH_03,                                 //
        KKERN_PRIORITY_HIGH_04,                                 //
        KKERN_PRIORITY_HIGH_05,                                 //
        KKERN_PRIORITY_HIGH_06,                                 //
        KKERN_PRIORITY_HIGH_07,                                 //
        KKERN_PRIORITY_HIGH_08,                                 //
        KKERN_PRIORITY_HIGH_09,                                 //
        KKERN_PRIORITY_HIGH_10,                                 //
        KKERN_PRIORITY_HIGH_11,                                 //
        KKERN_PRIORITY_HIGH_12,                                 //
        KKERN_PRIORITY_HIGH_13,                                 //
        KKERN_PRIORITY_HIGH_14,                                 //
        KKERN_PRIORITY_HIGH_15,                                 // 15

        KKERN_PRIORITY_MEDIUM_00,                               // 16 - Medium priority
        KKERN_PRIORITY_MEDIUM_01,                               //
        KKERN_PRIORITY_MEDIUM_02,                               //
        KKERN_PRIORITY_MEDIUM_03,                               //
        KKERN_PRIORITY_MEDIUM_04,                               //
        KKERN_PRIORITY_MEDIUM_05,                               //
        KKERN_PRIORITY_MEDIUM_06,                               //
        KKERN_PRIORITY_MEDIUM_07,                               //
        KKERN_PRIORITY_MEDIUM_08,                               //
        KKERN_PRIORITY_MEDIUM_09,                               //
        KKERN_PRIORITY_MEDIUM_10,                               //
        KKERN_PRIORITY_MEDIUM_11,                               //
        KKERN_PRIORITY_MEDIUM_12,                               //
        KKERN_PRIORITY_MEDIUM_13,                               //
        KKERN_PRIORITY_MEDIUM_14,                               //
        KKERN_PRIORITY_MEDIUM_15,                               // 31

        KKERN_PRIORITY_NORMAL_00,                               // 32 - Normal priority
        KKERN_PRIORITY_NORMAL_01,                               //
        KKERN_PRIORITY_NORMAL_02,                               //
        KKERN_PRIORITY_NORMAL_03,                               //
        KKERN_PRIORITY_NORMAL_04,                               //
        KKERN_PRIORITY_NORMAL_05,                               //
        KKERN_PRIORITY_NORMAL_06,                               //
        KKERN_PRIORITY_NORMAL_07,                               //
        KKERN_PRIORITY_NORMAL_08,                               //
        KKERN_PRIORITY_NORMAL_09,                               //
        KKERN_PRIORITY_NORMAL_10,                               //
        KKERN_PRIORITY_NORMAL_11,                               //
        KKERN_PRIORITY_NORMAL_12,                               //
        KKERN_PRIORITY_NORMAL_13,                               //
        KKERN_PRIORITY_NORMAL_14,                               //
        KKERN_PRIORITY_NORMAL_15,                               // 47

        KKERN_PRIORITY_LOW_00,                                  // 48 - Low priority
        KKERN_PRIORITY_LOW_01,                                  //
        KKERN_PRIORITY_LOW_02,                                  //
        KKERN_PRIORITY_LOW_03,                                  //
        KKERN_PRIORITY_LOW_04,                                  //
        KKERN_PRIORITY_LOW_05,                                  //
        KKERN_PRIORITY_LOW_06,                                  //
        KKERN_PRIORITY_LOW_07,                                  //
        KKERN_PRIORITY_LOW_08,                                  //
        KKERN_PRIORITY_LOW_09,                                  //
        KKERN_PRIORITY_LOW_10,                                  //
        KKERN_PRIORITY_LOW_11,                                  //
        KKERN_PRIORITY_LOW_12,                                  //
        KKERN_PRIORITY_LOW_13,                                  //
        KKERN_PRIORITY_LOW_14,                                  //
        KKERN_PRIORITY_LOW_IDLE,                                // 63 - Lowest priority reserved for the process idle

        KKERN_NB_PRIORITIES,                                    // 64 - Number of priorities (2^x)
} priority_t;

#define KKERN_MSK_PRIORITIES    (KKERN_NB_PRIORITIES - 1)       // 2'0011 1111


// uKernel types
// -------------

typedef struct  proc        proc_t;
typedef struct  spec        spec_t;
typedef struct  work        work_t;
typedef struct  stts        stts_t;
typedef struct  mbox        mbox_t;
typedef struct  sema        sema_t;
typedef struct  mutx        mutx_t;
typedef struct  atim        atim_t;
typedef struct  sync        sync_t;
typedef struct  stim        stim_t;
typedef struct  pool        pool_t;
typedef struct  prcs        prcs_t;
typedef struct  sign        sign_t;

typedef struct  list                list_t;
typedef struct  obje                obje_t;

struct  list {
    proc_t      *oFirst;                                                        // Ptr on the first process
    proc_t      *oLast;                                                         // Ptr on the last process
    uint16_t    oNbElements;                                                    // Number of elements of the list
};

struct  obje {
    list_t      *oList;                                                         // Ptr on the list where the process is linked
    proc_t      *oBack;                                                         // Ptr on the back process
    proc_t      *oForward;                                                      // Ptr on the forward process
};

/**@}*/
/**@}*/
