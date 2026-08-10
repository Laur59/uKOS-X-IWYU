/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Hardware specific stub.
 */

#include    "stub.h"

#include    <stdint.h>

#include    "core_reg.h"
#include    "exce.h"
#include    "soc_reg.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "macros_core.h"
#include    "kern/kern.h"

#define BPA01   1U

// Prototypes

static  void    stub_intr_io_interruption(void);

/*
 * \brief stub_intr_io_init
 *
 */
void    stub_intr_io_init(void) {

    RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN;

    SYSCFG->EXTICR1 = (0U * SYSCFG_EXTICR1_EXTI1_0);

    INTERRUPT_VECTOR(EXTI1_IRQn, stub_intr_io_interruption);
    NVIC_SetPriority(EXTI1_IRQn, KHW_PRIORITY_HIGH);
    NVIC_EnableIRQ(EXTI1_IRQn);

    EXTI->FTSR1   |= (1U<<BPA01);
    EXTI->D3PMR1  |= (1U<<BPA01);
    EXTI->CPUIMR1 |= (1U<<BPA01);
}

/*
 * \brief stub_intr_io_interruption
 *
 */
static  void    stub_intr_io_interruption(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    EXTI->CPUPR1 |= (1U<<BPA01);
    vCounter++;

    PREEMPTION_THRESHOLD(core);
}
