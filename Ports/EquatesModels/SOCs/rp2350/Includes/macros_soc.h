/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; macros_soc.
; ===========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Important macros.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

#include    "Registers/RP2350_sio.h"

// Multicore macro
// ---------------

#define KNB_CORES               2U
#define KCORE_0                 0U
#define KCORE_1                 1U

#ifndef GET_RUNNING_CORE
#ifdef SECURE_S
#define GET_RUNNING_CORE        (SIO_S->CPUID & 1U)
#elif (defined(SECURE_NS))
#define GET_RUNNING_CORE        (SIO_NS->CPUID & 1U)
#else
#define GET_RUNNING_CORE        (SIO_S->CPUID & 1U)
#endif
#endif

#ifndef MCSET
#if     (KNB_CORES == 1)
#define MCSET(v)                { (v) }
#elif   (KNB_CORES == 2)
#define MCSET(v)                { (v), (v) }
#else
#error  "*** The number of cores (KNB_CORES) exceed 2"
#endif
#endif

// Baudrate macro
// --------------

#define BAUDRATE(UART, ck, baudrate)                                                                                            \
    do {                                                                                                                        \
        const uint32_t _den  = 16U * (uint32_t)(baudrate);                                                                      \
        const uint32_t _ibrd = (uint32_t)((uint32_t)(ck) / _den);                                                               \
        const uint32_t _rem  = (uint32_t)((uint32_t)(ck) % _den);                                                               \
                                                                                                                                \
        const uint32_t _fbrd = (uint32_t)((((uint64_t)_rem * (uint64_t)64U) + ((uint64_t)_den / 2U)) / (uint64_t)_den);         \
        REG(UART)->UARTIBRD = _ibrd;                                                                                            \
        REG(UART)->UARTFBRD = _fbrd;                                                                                            \
    } while (0)

// Interruption macros
// -------------------

enum {

// Reserved names: all the possible levels
// Priorities used to set the NVIC. levels indicated with _KERNEL_
// are reserved for the uKernel (!!! do not change those values)

        KINT_LEVEL_KERNEL_SWI = 1U,
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
// KINT_IMASK_COMMUNICATIONS    Allows only NMI, SWI, communications
// KINT_IMASK_PERIPHERALS       Allows only NMI, SWI, communications, peripherals
// KINT_IMASK_KERNEL_TIMERS     Allows only NMI, SWI, communications, peripherals, kernel timers
// KINT_IMASK_KERNEL_PREEMPTION Allows only NMI, SWI, communications, peripherals, kernel timers, kernel preemptions
// KINT_IMASK_ALL               Allows all

#define KINT_IMASK_OFF                  (KINT_LEVEL_KERNEL_SWI + 1U)
#define KINT_IMASK_KERNEL_SWI           (KINT_LEVEL_KERNEL_SWI + 1U)
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
