/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Important macros.
 */

#pragma once

#include    <stdint.h>

#include    "soc_reg.h"

// Multicore macro
// ---------------

#define KNB_CORES               1U
#define KCORE_0                 0U

#ifndef GET_RUNNING_CORE
#define GET_RUNNING_CORE        0U
#endif

#ifndef MCSET
#if     (KNB_CORES == 1)
#define MCSET(v)                { (v) }
#else
#error  "*** The number of cores (KNB_CORES) exceed 1"
#endif
#endif

// Baudrate macro
// --------------

[[maybe_unused]] static inline uint32_t BAUDRATE(uint32_t ck, uint32_t baudrate) {
    uint32_t divisor = baudrate * 16U;
    uint32_t div = ck / divisor;
    uint32_t remainder = ck % divisor;
    uint32_t rem = ((remainder * 16U) + (divisor / 2U)) / divisor;
    return (div << 4) | rem;
}

// Interruption macros
// -------------------

// nlbit = 3 (LEVEL3) -> LLL1 1111 (set by default at the start-up)
//
// LLLH HHHH means that the possible interruption level should be:
//
// 000H HHHH    31
// 001H HHHH    63
// 010H HHHH    95
// 011H HHHH    127
// 100H HHHH    159
// 101H HHHH    191
// 110H HHHH    223
// 111H HHHH    255
//
// ctl = 7 -> LLL = 011, level = 127
// MTH = 31

enum {

// Reserved names: all the possible levels
// Priorities used to set the ECLIC. levels indicated with _KERNEL_
// are reserved for the uKernel (!!! do not change those values)

        KINT_LEVEL_ALL               = 32U,
        KINT_LEVEL_KERNEL_PREEMPTION = 64U,
        KINT_LEVEL_KERNEL_TIMERS     = 96U,
        KINT_LEVEL_PERIPHERALS       = 128U,
        KINT_LEVEL_COMMUNICATIONS    = 160U,
        KINT_LEVEL_KERNEL_SWI        = 192U
};

// Reserved names: all the possible masks
// Masks used to filter some priorities
// KINT_IMASK_ALL               Allows all
// KINT_IMASK_KERNEL_PREEMPTION Allows only NMI, SWI, communications, peripherals, kernel timers, kernel preemptions
// KINT_IMASK_PERIPHERALS       Allows only NMI, SWI, communications, peripherals
// KINT_IMASK_COMMUNICATIONS    Allows only NMI, SWI, communications
// KINT_IMASK_KERNEL_TIMERS     Allows only NMI, SWI, communications, peripherals, kernel timers
// KINT_IMASK_KERNEL_SWI        Allows only NMI, SWI
// KINT_IMASK_OFF               Allows only NMI, SWI

#define KINT_IMASK_ALL                  (KINT_LEVEL_ALL - 1U)
#define KINT_IMASK_KERNEL_PREEMPTION    (KINT_LEVEL_KERNEL_PREEMPTION - 1U)
#define KINT_IMASK_KERNEL_TIMERS        (KINT_LEVEL_KERNEL_TIMERS - 1U)
#define KINT_IMASK_PERIPHERALS          (KINT_LEVEL_PERIPHERALS - 1U)
#define KINT_IMASK_COMMUNICATIONS       (KINT_LEVEL_COMMUNICATIONS - 1U)
#define KINT_IMASK_KERNEL_SWI           (KINT_LEVEL_KERNEL_SWI - 1U)
#define KINT_IMASK_OFF                  (KINT_LEVEL_KERNEL_SWI - 1U)

// Names for the user applications

#define KHW_PRIORITY_LOW                KINT_LEVEL_KERNEL_PREEMPTION
#define KHW_PRIORITY_MODERATE           KINT_LEVEL_KERNEL_TIMERS
#define KHW_PRIORITY_HIGH               KINT_LEVEL_PERIPHERALS
#define KHW_PRIORITY_VERY_HIGH          KINT_LEVEL_COMMUNICATIONS

// EXTI0 Used for passing messages (change the context)
// EXTI1 Used for preemption (change the context)

#define BKERN_MESSAGES          0U
#define BKERN_PREEMPTION        1U

#ifndef SET_MESSAGE
#define SET_MESSAGE             EXTI->SWIEV |= (1U<<BKERN_MESSAGES);                                                            \
                                while ((EXTI->SWIEV & (1U<<BKERN_MESSAGES)) != 0U) { ; }
#endif

#ifndef PREEMPTION
#define PREEMPTION              EXTI->SWIEV |= (1U<<BKERN_PREEMPTION)
#endif

#ifndef INTERRUPTION_SET
#define INTERRUPTION_SET        ECLIC->MTH = KINT_IMASK_ALL
#endif

#ifndef INTERRUPTION_SET_PERIPH
#define INTERRUPTION_SET_PERIPH ECLIC->MTH = KINT_IMASK_PERIPHERALS
#endif

#ifndef INTERRUPTION_OFF
#define INTERRUPTION_OFF        volatile    uint32_t    __saveECLIC_msk [[maybe_unused]];                                       \
                                __saveECLIC_msk = (uint32_t)ECLIC->MTH;                                                         \
                                (void)__saveECLIC_msk;                                                                          \
                                ECLIC->MTH = KINT_IMASK_OFF
#endif

#ifndef INTERRUPTION_RESTORE
#define INTERRUPTION_RESTORE    ECLIC->MTH = (uint8_t)__saveECLIC_msk
#endif

#ifndef INTERRUPTION_OFF_CRITICAL
#define INTERRUPTION_OFF_CRITICAL(savemMask)                                                                                    \
                                savemMask = (volatile uint32_t)ECLIC->MTH;                                                      \
                                ECLIC->MTH = KINT_IMASK_OFF
#endif

#ifndef INTERRUPTION_RESTORE_CRITICAL
#define INTERRUPTION_RESTORE_CRITICAL(savemMask)                                                                                \
                                ECLIC->MTH = (uint8_t)(savemMask)
#endif

extern  bool    vExce_isException[KNB_CORES];

#ifndef IS_EXCEPTION
#define IS_EXCEPTION            (vExce_isException[0])
#endif

// EXCEPTION_VECTOR and INTERRUPT_VECTOR macros moved to macros_core.h for IWYU compliance
// This resolves the circular dependency issue noted in the original comment
