/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal: Hardware specific stub.
 */

#include    "stub.h"

#include <stdint.h>

#include "core_reg.h"
#include "exce.h"
#include "soc_reg.h"
#include "macros.h"
#include "macros_soc.h"
#include "macros_core.h"
#include "kern/kern.h"

#define BPA08   8u

// Prototypes

static  void    stub_intr_io_interruption(void);

/*
 * \brief stub_intr_io_init
 *
 */
void    stub_intr_io_init(void) {

    RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN;

    SYSCFG->EXTICR3 = (0U * SYSCFG_EXTICR3_EXTI8_0);

    INTERRUPT_VECTOR(EXTI9_5_C0_IRQn, stub_intr_io_interruption);
    NVIC_SetPriority(EXTI9_5_C0_IRQn, KHW_PRIORITY_HIGH);
    NVIC_EnableIRQ(EXTI9_5_C0_IRQn);

    EXTI->RTSR1   &= ~(1U<<BPA08);
    EXTI->FTSR1   |=  (1U<<BPA08);
    EXTI->CPUPR1   =  (1U<<BPA08);
    EXTI->CPUIMR1 |=  (1U<<BPA08);
}

/*
 * \brief stub_intr_io_interruption
 *
 */
static  void    stub_intr_io_interruption(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    EXTI->CPUPR1 = (1U<<BPA08);
    vCounter++;

    PREEMPTION_THRESHOLD(core);
}
