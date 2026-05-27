/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Connect the "kern" manager to the hardware.
 *
 * Core 0 uses TIMER0 (ALARM0 = 1-ms tick, ALARM1 = 20-ms quota).
 * Core 1 uses TIMER1 (ALARM0 = 1-ms tick, ALARM1 = 20-ms quota).
 */

#include    <stdint.h>

#include    "Registers/soc_vectors.h"
#include    "kern/kern.h"
#include    "macros_core.h"
#include    "macros_soc.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define TIMER_C0                        REG(TIMER0)
#define TIMER_C1                        REG(TIMER1)
#define TIMER_ALA0_VECTOR_NUMBER_C0     TIMER0_IRQ_0_C0_IRQn
#define TIMER_ALA0_VECTOR_NUMBER_C1     TIMER1_IRQ_0_C1_IRQn
#define TIMER_ALA1_VECTOR_NUMBER_C0     TIMER0_IRQ_1_C0_IRQn
#define TIMER_ALA1_VECTOR_NUMBER_C1     TIMER1_IRQ_1_C1_IRQn

#ifdef __riscv

#include    "Registers/rv32_csr.h"
#include    "core.h"
#include    "model_kernel_tim0_ecall_C0.c_inc"
#include    "model_kernel_tim1_ecall_C1.c_inc"

#else
#define PendSV_VECTOR_NUMBER_C0         PendSV_C0_IRQn
#define PendSV_VECTOR_NUMBER_C1         PendSV_C1_IRQn

#include    "model_kernel_tim_0_a0_a1_svc_C0.c_inc"
#include    "model_kernel_tim_1_a0_a1_svc_C1.c_inc"
#endif

void    stub_kern_init(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    if (core == KCORE_0) { model_kernel_init_C0(); }
    else                 { model_kernel_init_C1(); }
}

void    stub_kern_runKernel(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { model_kernel_runKernel_C0(); }
    else                 { model_kernel_runKernel_C1(); }
}

void    stub_kern_setLowPower(uint8_t mode) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { model_kernel_setLowPower_C0(mode); }
    else                 { model_kernel_setLowPower_C1(mode); }
}

void    stub_kern_readTickCount(uint64_t *tickCount) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { model_kernel_readTickCount_C0(tickCount); }
    else                 { model_kernel_readTickCount_C1(tickCount); }
}

void    stub_kern_newProcessTimeout(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { model_kernel_newProcessTimeout_C0(); }
    else                 { model_kernel_newProcessTimeout_C1(); }
}

void    stub_kern_stopProcessTimeout(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { model_kernel_stopProcessTimeout_C0(); }
    else                 { model_kernel_stopProcessTimeout_C1(); }
}
