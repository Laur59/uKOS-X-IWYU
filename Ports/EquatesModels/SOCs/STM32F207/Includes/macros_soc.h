/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Important macros.
 */

#pragma once

#include    <stdint.h>

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

enum {

// Reserved names: all the possible levels
// Priorities used to set the NVIC. levels indicated with _KERNEL_
// are reserved for the uKernel (!!! do not change those values)

        KINT_LEVEL_KERNEL_SWI = 1U,
        KINT_LEVEL_VERY_HS_PERIPHERALS,
        KINT_LEVEL_COMMUNICATIONS,
        KINT_LEVEL_PERIPHERALS,
        KINT_LEVEL_KERNEL_TIMERS,
        KINT_LEVEL_KERNEL_PREEMPTION,
        KINT_LEVEL_ALL
};

// Reserved names: all the possible masks
// Masks used to filter some priorities
// KINT_IMASK_OFF               Allows only NMI, SWI
// KINT_IMASK_KERNEL_SWI        Allows only NMI, SWI
// KINT_LEVEL_VERY_HS_PERIPHERALS   Allows only NMI, SWI, HS peripherals, communications
// KINT_IMASK_COMMUNICATIONS        Allows only NMI, SWI, HS peripherals, communications
// KINT_IMASK_PERIPHERALS           Allows only NMI, SWI, HS peripherals, communications, peripherals
// KINT_IMASK_KERNEL_TIMERS         Allows only NMI, SWI, HS peripherals, communications, peripherals, kernel timers
// KINT_IMASK_KERNEL_PREEMPTION     Allows only NMI, SWI, HS peripherals, communications, peripherals, kernel timers, kernel preemptions
// KINT_IMASK_ALL               Allows all

#define KINT_IMASK_OFF                  (KINT_LEVEL_KERNEL_SWI + 1U)
#define KINT_IMASK_KERNEL_SWI           (KINT_LEVEL_KERNEL_SWI + 1U)
#define KINT_IMASK_VERY_HS_PERIPHERALS  (KINT_LEVEL_VERY_HS_PERIPHERALS + 1U)
#define KINT_IMASK_COMMUNICATIONS       (KINT_LEVEL_COMMUNICATIONS + 1U)
#define KINT_IMASK_PERIPHERALS          (KINT_LEVEL_PERIPHERALS + 1U)
#define KINT_IMASK_KERNEL_TIMERS        (KINT_LEVEL_KERNEL_TIMERS + 1U)
#define KINT_IMASK_KERNEL_PREEMPTION    (KINT_LEVEL_KERNEL_PREEMPTION + 1U)
#define KINT_IMASK_ALL                  (KINT_LEVEL_ALL + 1U)

// Names for the user applications

#define KHW_PRIORITY_LOW                KINT_LEVEL_KERNEL_PREEMPTION
#define KHW_PRIORITY_MODERATE           KINT_LEVEL_KERNEL_TIMERS
#define KHW_PRIORITY_HIGH               KINT_LEVEL_PERIPHERALS
#define KHW_PRIORITY_VERY_HIGH          KINT_LEVEL_COMMUNICATIONS

// 2^4 priority levels
// Priority shift inside the NVIC->PR (P3 P2 P1 P0 x x x x) !!! Vendor specific

#define KNVIC_PRIORITY_BITS     4U
#define KNVIC_PRIORITY_SHIFT    (8U - KNVIC_PRIORITY_BITS)

// PENDSVSET used for preemption (change the context)

#define BKERN_PREEMPTION        28U

// EXCEPTION_VECTOR and INTERRUPT_VECTOR macros moved to macros_core.h for IWYU compliance
