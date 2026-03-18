/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Hardware specific stub.
 */

#include    <stdint.h>

#include    "core_reg.h"
#include    "soc_reg.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "macros_core.h"
#include    "kern/kern.h"

extern  volatile    uint32_t    vCounter;

#define BPA0    0U

// Prototypes

extern  void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

static  void    stub_intr_io_interruption(void);

/*
 * \brief stub_intr_io_init
 *
 */
void    stub_intr_io_init(void) {

    RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN;

    SYSCFG->EXTICR1 = (0U * SYSCFG_EXTICR1_EXTI0_0);

    INTERRUPT_VECTOR(EXTI0_C0_IRQn, stub_intr_io_interruption);
    NVIC_SetPriority(EXTI0_C0_IRQn, KHW_PRIORITY_HIGH);
    NVIC_EnableIRQ(EXTI0_C0_IRQn);

    EXTI->FTSR1   |= (1U<<BPA0);
    EXTI->CPUPR1  |= (1U<<BPA0);
    EXTI->CPUIMR1 |= (1U<<BPA0);
}

/*
 * \brief stub_intr_io_interruption
 *
 */
static  void    stub_intr_io_interruption(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    EXTI->CPUPR1 |= (1U<<BPA0);
    vCounter++;

    PREEMPTION_THRESHOLD(core);
}
