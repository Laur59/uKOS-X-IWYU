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

#include    "types.h"
#include    "os_errors.h"
#include    "clockTree.h"
#include    "core_reg.h"
#include    "soc_reg.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "macros_core.h"
#include    "kern/kern.h"

#define KTIM_ESAMPLING_0    ((float64_t)(0.0001))                               // 100-us
#define KDELTA_TIME_0       ((uint32_t)(KFREQUENCY_TIM * KTIM_ESAMPLING_0))     // Delta time

// Prototypes

static  void    stub_intr_timer_interruption(void);

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
            int32_t     status;
    static  mbox_t      *vQueue;
    static  bool        vInit = false;
    static  uintptr_t   vCounter = 0U;

    core = GET_RUNNING_CORE;

    if (!vInit) {
        if (kern_getMailboxById("Queue tim", &vQueue) == KERR_KERN_NOERR) {
            vInit = true;
        }
    }

// INT acknowledge

    if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_3) != 0U) {
        REG(TIMER0)->INTR = TIMER_INTR_ALARM_3;

        REG(TIMER0)->ALARM3 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;
    }

    status = kern_writeQueue(vQueue, vCounter, 0U);
    if (status == KERR_KERN_NOERR) {
        vCounter++;
    }

    PREEMPTION_THRESHOLD(core);
}
