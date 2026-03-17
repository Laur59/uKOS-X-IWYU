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

#define KTTIM100US      100U                                    // For 100-us (10000-Hz)
#define KFPRET7         1000000U                                // 1'000'000-Hz
#define KFINTT7         KTTIM100US                              // 10'000-Hz
#define KPSCT7          ((KFREQUENCY_APB2 / KFPRET7) - 1U)      // Prescaler for 1'000'000-Hz
#define KARRT7          ((KFPRET7 / KFINTT7) - 1U)              // Autoreload

// Prototypes

extern  void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

static  void    stub_intr_timer_interruption(void);

/*
 * \brief stub_intr_timer_init
 *
 */
void    stub_intr_timer_init(void) {

    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM7EN;

// Timer 7 (100-us)

    INTERRUPT_VECTOR(TIM7_C0_IRQn, stub_intr_timer_interruption);
    NVIC_SetPriority(TIM7_C0_IRQn, KHW_PRIORITY_MODERATE);
    NVIC_EnableIRQ(TIM7_C0_IRQn);

    TIM7->PSC  = KPSCT7;
    TIM7->ARR  = KARRT7;
    TIM7->DIER = TIM7_DIER_UIE;
    TIM7->CR1 |= TIM7_CR1_CEN;
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

    if ((TIM7->SR & TIM7_SR_UIF) != 0U) {
        TIM7->SR &= (uint16_t)~TIM7_SR_UIF;
    }

    status = kern_writeQueue(vQueue, vCounter, 0U);
    if (status == KERR_KERN_NOERR) {
        vCounter++;
    }

    PREEMPTION_THRESHOLD(core);
}
