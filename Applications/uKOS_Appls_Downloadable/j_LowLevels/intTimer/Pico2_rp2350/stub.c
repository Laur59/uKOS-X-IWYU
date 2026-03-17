/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stub.
; =====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Hardware specific stub.
;
;-----
;------------------------------------------------------------------------
*/

#include    <stdint.h>

#include    "clockTree.h"
#include    "core_reg.h"
#include    "soc_reg.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "macros_core.h"
#include    "kern/kern.h"

#define KTIM_ESAMPLING_0    ((float64_t)(0.001))                                // 1-ms
#define KDELTA_TIME_0       ((uint32_t)(KFREQUENCY_TIM * KTIM_ESAMPLING_0))     // Delta time

extern  volatile    uint32_t    vTimer;

// Prototypes

static  void    stub_intr_timer_interruption(void);
extern  void    aTimer_callBack(void);

/*
 * \brief stub_intr_timer_init
 *
 */
void    stub_intr_timer_init(void) {

// Alarme 3 (100-us)

    REG(TIMER0)->INTE   = REG(TIMER0)->INTE | TIMER_INTE_ALARM_3;
    REG(TIMER0)->ALARM3 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;

    INTERRUPT_VECTOR(TIMER0_IRQ_3_C0_IRQn, stub_intr_timer_interruption);
    NVIC_SetPriority(TIMER0_IRQ_3_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
    NVIC_EnableIRQ(TIMER0_IRQ_3_C0_IRQn);
}

/*
 * \brief stub_intr_timer_interruption
 *
 */
static  void    stub_intr_timer_interruption(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

// INT acknowledge

    if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_3) != 0U) {
        REG(TIMER0)->INTR = TIMER_INTR_ALARM_3;

        REG(TIMER0)->ALARM3 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;
    }
    if ((++vTimer % 100U) == 0U) { aTimer_callBack(); }

    PREEMPTION_THRESHOLD(core);
}
