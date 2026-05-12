/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Connect the "kern" manager to the hardware.
 *
 * Uses TIMER0 ALARM0 (1-ms tick) and ALARM1 (20-ms quota).
 * Core 1 is not active in Phase 3.3 (single-core only).
 */

#include    <stdint.h>

#include    "Registers/rv32_csr.h"
#include    "Registers/soc_vectors.h"
#include    "core.h"
#include    "kern/kern.h"
#include    "macros_core.h"
#include    "macros_soc.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define TIMER_C0                        REG(TIMER0)
#define TIMER_C1                        REG(TIMER1)
#define TIMER_ALA0_VECTOR_NUMBER_C0     TIMER0_IRQ_0_C0_IRQn
#define TIMER_ALA0_VECTOR_NUMBER_C1     TIMER0_IRQ_0_C1_IRQn
#define TIMER_ALA1_VECTOR_NUMBER_C0     TIMER0_IRQ_1_C0_IRQn
#define TIMER_ALA1_VECTOR_NUMBER_C1     TIMER0_IRQ_1_C1_IRQn

#include    "model_kernel_tim0_ecall_C0.c_inc"
#include    "model_kernel_tim1_ecall_C1.c_inc"

void    stub_kern_init(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    if (core == KCORE_0) { model_kernel_init_C0(); }
}

void    stub_kern_runKernel(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    if (core == KCORE_0) { model_kernel_runKernel_C0(); }
}

void    stub_kern_setLowPower(uint8_t mode) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    if (core == KCORE_0) { model_kernel_setLowPower_C0(mode); }
}

void    stub_kern_readTickCount(uint64_t *tickCount) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    if (core == KCORE_0) { model_kernel_readTickCount_C0(tickCount); }
}

void    stub_kern_newProcessTimeout(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    if (core == KCORE_0) { model_kernel_newProcessTimeout_C0(); }
}

void    stub_kern_stopProcessTimeout(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    if (core == KCORE_0) { model_kernel_stopProcessTimeout_C0(); }
}
