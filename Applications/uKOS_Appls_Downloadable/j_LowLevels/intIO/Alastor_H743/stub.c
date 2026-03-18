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

#define BPC10   10U

// Prototypes

extern  void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

static  void    stub_intr_io_interruption(void);

/*
 * \brief stub_intr_io_init
 *
 */
void    stub_intr_io_init(void) {

    RCC->APB4ENR |= RCC_APB4ENR_SYSCFGEN;

    SYSCFG->EXTICR3 = (2U * SYSCFG_EXTICR3_EXTI10_0);

    INTERRUPT_VECTOR(EXTI15_10_C0_IRQn, stub_intr_io_interruption);
    NVIC_SetPriority(EXTI15_10_C0_IRQn, KHW_PRIORITY_HIGH);
    NVIC_EnableIRQ(EXTI15_10_C0_IRQn);

    EXTI->FTSR1   |= (1U<<BPC10);
    EXTI->D3PMR1  |= (1U<<BPC10);
    EXTI->CPUIMR1 |= (1U<<BPC10);
}

/*
 * \brief stub_intr_io_interruption
 *
 */
static  void    stub_intr_io_interruption(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    EXTI->CPUPR1 |= (1U<<BPC10);
    vCounter++;

    PREEMPTION_THRESHOLD(core);
}
