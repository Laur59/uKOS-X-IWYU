/*
; stub.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Hardware specific stub.
;
;   © 2025-2026, Edo. Franzi
;   ------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#include	<stdint.h>

#include	"types.h"
#include	"os_errors.h"
#include	"clockTree.h"
#include	"core_reg.h"
#include	"soc_reg.h"
#include	"macros.h"
#include	"macros_soc.h"
#include	"macros_core.h"
#include	"kern/kern.h"

#define KTTIM100US		100U									// For 100-us (10000-Hz)
#define	KFPRET8			1000000U								// 1'000'000-Hz
#define	KFINTT8			KTTIM100US								// 10'000-Hz
#define KPSCT8			((KFREQUENCY_APB2 / KFPRET8) - 1U)		// Prescaler for 1'000'000-Hz
#define KARRT8			((KFPRET8 / KFINTT8) - 1U)				// Autoreload

// Prototypes

extern	void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

static	void	stub_intr_timer_interruption(void);

/*
 * \brief stub_intr_timer_init
 *
 */
void	stub_intr_timer_init(void) {

	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;

// Timer 8 (100-us)

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
static	void	stub_intr_timer_interruption(void) {
			uint32_t	core;
			int32_t		status;
	static	mbox_t		*vQueue;
	static	bool		vInit = false;
	static	uintptr_t	vCounter = 0U;

	core = GET_RUNNING_CORE;

	if (!vInit) {
		if (kern_getMailboxById("Queue tim", &vQueue) == KERR_KERN_NOERR) {
			vInit = true;
		}
	}

// INT acknowledge

	if ((TIM8->SR & TIM8_SR_UIF) != 0U) {
		TIM8->SR &= (uint16_t)~TIM8_SR_UIF;
	}

	status = kern_writeQueue(vQueue, vCounter, 0U);
	if (status == KERR_KERN_NOERR) {
		vCounter++;
	}

	PREEMPTION_THRESHOLD(core);
}
