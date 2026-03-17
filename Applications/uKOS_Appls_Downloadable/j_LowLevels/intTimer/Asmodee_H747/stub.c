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

#define KTTIM1MS        1000U                                   // For 1-ms (1000-Hz)
#define KFPRET8         1000000U                                // 1'000'000-Hz
#define KFINTT8         KTTIM1MS                                // 1'000-Hz
#define KPSCT8          ((KFREQUENCY_APB2 / KFPRET8) - 1U)      // Prescaler for 1'000'000-Hz
#define KARRT8          ((KFPRET8 / KFINTT8) - 1U)              // Autoreload

extern  volatile    uint32_t    vTimer;

// Prototypes

extern  void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

static  void    stub_intr_timer_interruption(void);
extern  void    aTimer_callBack(void);

/*
 * \brief stub_intr_timer_init
 *
 */
void    stub_intr_timer_init(void) {

    RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;

// Timer 8 (1-ms)

    INTERRUPT_VECTOR(TIM8_UP_TIM13_C0_IRQn, stub_intr_timer_interruption);
    NVIC_SetPriority(TIM8_UP_TIM13_C0_IRQn, KHW_PRIORITY_MODERATE);
    NVIC_EnableIRQ(TIM8_UP_TIM13_C0_IRQn);

    TIM8->PSC  = KPSCT8;
    TIM8->ARR  = KARRT8;
    TIM8->DIER = TIM8_DIER_UIE;
    TIM8->CR1 |= TIM8_CR1_CEN;
}

/*
 * \brief stub_intr_timer_interruption
 *
 */
static  void    stub_intr_timer_interruption(void) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

// INT acknowledge

    if ((TIM8->SR & TIM8_SR_UIF) != 0U) {
        TIM8->SR &= (uint16_t)~TIM8_SR_UIF;
    }
    if ((++vTimer % 100U) == 0U) { aTimer_callBack(); }

    PREEMPTION_THRESHOLD(core);
}
