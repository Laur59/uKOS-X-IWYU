/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Hardware specific stub.
 */

#include    <stdint.h>

#include    "core_reg.h"
#include    "exce.h"
#include    "soc_reg.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "macros_core.h"
#include    "kern/kern.h"

extern  volatile    uint32_t    vCounter;

#define BPC13   13U

// Prototypes

static  void    stub_intr_io_interruption(void);

/*
 * \brief stub_intr_io_init
 *
 */
void    stub_intr_io_init(void) {

    REG(EXTI)->EXTICR4 = (2U * EXTI_EXTICR4_EXTI13_0);

    INTERRUPT_VECTOR(EXTI13_C0_IRQn, stub_intr_io_interruption);
    NVIC_SetPriority(EXTI13_C0_IRQn, KHW_PRIORITY_HIGH);
    NVIC_EnableIRQ(EXTI13_C0_IRQn);

    REG(EXTI)->FTSR1 |= (1U<<BPC13);
    REG(EXTI)->RPR1  |= (1U<<BPC13);
    REG(EXTI)->IMR1  |= (1U<<BPC13);
}

/*
 * \brief stub_intr_io_interruption
 *
 */
static  void    stub_intr_io_interruption(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    REG(EXTI)->FPR1 |= (1U<<BPC13);
    vCounter++;

    PREEMPTION_THRESHOLD(core);
}
