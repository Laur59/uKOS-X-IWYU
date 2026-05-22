/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Important macros.
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

#ifdef RV32IMAC_S

// Kernel message delivery (ecall from process context only)
// GOTO_KERN_I/M push the message to 0(sp); SET_MESSAGE loads a0 from there
// and executes ecall so first_handle_trap captures it as vMessage.

#ifndef SET_MESSAGE
#define SET_MESSAGE     __asm volatile ("lw a0,0(sp)\n\tecall" ::: "a0", "memory")
#endif

// Interrupt masking – save and restore mstatus.MIE (bit 3).
// INTERRUPTION_OFF declares a function-scope variable; INTERRUPTION_RESTORE
// must appear in the same scope.

#ifndef INTERRUPTION_OFF
#define INTERRUPTION_OFF                                                            \
    uint32_t _saved_mstatus;                                                        \
    __asm volatile ("csrrci %0, mstatus, 8" : "=r"(_saved_mstatus) :: "memory")
#endif

#ifndef INTERRUPTION_RESTORE
#define INTERRUPTION_RESTORE                                                        \
    do {                                                                            \
        if ((_saved_mstatus & 0x8U) != 0U) {                                       \
            __asm volatile ("csrsi mstatus, 8" ::: "memory");                      \
        }                                                                           \
    } while (0)
#endif

// Peripheral interrupt threshold – no-op for Phase 3.3.
// (Hazard3 MEICONTEXT threshold programming deferred to Phase 3.4.)

#ifndef INTERRUPTION_SET_PERIPH
#define INTERRUPTION_SET_PERIPH ((void)0)
#endif

// Allow-all interrupt threshold – no-op for Phase 3.3.
// On ARM this sets BASEPRI=0; on Hazard3 it would set MEICONTEXT threshold=0.
// MEICONTEXT resets to 0 so no explicit write is needed; deferred to Phase 3.4.

#ifndef INTERRUPTION_SET
#define INTERRUPTION_SET        ((void)0)
#endif

// Critical-section interrupt save/restore.
// Uses csrrci/csrsi on mstatus bit 3 (MIE) — same mechanism as INTERRUPTION_OFF
// but stores the result in the caller-supplied variable instead of a local.

#ifndef INTERRUPTION_OFF_CRITICAL
#define INTERRUPTION_OFF_CRITICAL(savemMask)                                        \
    __asm volatile ("csrrci %0, mstatus, 8" : "=r"(savemMask) :: "memory")
#endif

#ifndef INTERRUPTION_RESTORE_CRITICAL
#define INTERRUPTION_RESTORE_CRITICAL(savemMask)                                    \
    do {                                                                             \
        if (((savemMask) & 0x8U) != 0U) {                                           \
            __asm volatile ("csrsi mstatus, 8" ::: "memory");                       \
        }                                                                            \
    } while (0)
#endif

// Priority-based preemption trigger – no PendSV on RISC-V.
// (Deferred to Phase 3.4; context switches happen via ecall only.)

#ifndef PREEMPTION
#define PREEMPTION      ((void)0)
#endif

// Exception-context guard – mirrors K210/GD32VF103 pattern.
// vExce_isException[core] is set by EXCEPTION_DISPATCH in first_riscv.c.
// The caller must have a local uint32_t core = GET_RUNNING_CORE.

#ifndef IS_EXCEPTION
#define IS_EXCEPTION    (vExce_isException[core])
#endif

#endif  // RV32IMAC_S
