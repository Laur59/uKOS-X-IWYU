/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub_kern_kernel.
; =================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     stub for the connection of the "kern" manager to the uKernel device.
;
;-----
;------------------------------------------------------------------------
*/

#include    <stdint.h>

#include    "clockTree.h"
#include    "kern/kern.h"
#include    "macros_soc.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define KFREQUENCY_T1   KFREQUENCY_TIM
#define KFREQUENCY_T2   KFREQUENCY_TIM
#define KFREQUENCY_T3   KFREQUENCY_TIM
#define KFREQUENCY_T4   KFREQUENCY_TIM

#include    "model_kernel_tick_tim_0A_1A_2A_ecall_C0.c_inc"
#include    "model_kernel_tick_tim_0B_1B_2B_ecall_C1.c_inc"

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

#if (KKERN_NB_PRECISE_SIGNALS > 0)
void    stub_kern_setPreciseSignal(prcs_t *handle) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { model_kernel_setPreciseSignal_C0(handle); }
    else                 { model_kernel_setPreciseSignal_C1(handle); }
}
#endif

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
