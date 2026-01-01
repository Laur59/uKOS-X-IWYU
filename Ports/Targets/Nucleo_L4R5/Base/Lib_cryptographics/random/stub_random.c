/*
; stub_random.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		stub for the "random" manager module.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
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

#include	"os_errors.h"
#include	"random/random.h"

// Prototypes

void	model_random_soft_init(void);
void	model_random_soft_read(uint32_t *number);
void	model_random_hard_init(void);
void	model_random_hard_read(uint32_t *number);

/*
 * \brief stub_random_init
 *
 * - Initialise some specific CPU parts
 *
 */
void	stub_random_init(void) {

	model_random_soft_init();
	model_random_hard_init();
}

/*
 * \brief stub_rand_read
 *
 * - Return the random number
 *
 */
int32_t	stub_rand_read(randomGenerator_t generator, uint32_t *number) {

	if (generator == KRANDOM_SOFT) { model_random_soft_read(number); return (KERR_RANDOM_NOERR); }
	if (generator == KRANDOM_HARD) { model_random_hard_read(number); return (KERR_RANDOM_NOERR); }
	return (KERR_RANDOM_GEERR);
}

// Local routines
// ==============

#include	"model_random_soft.c_inc"	// IWYU pragma: keep (workaround for app)
// #include	"model_random_hard.c_inc"

#include	"Registers/nvic.h"
#include	"kern/kern.h"
#include	"macros_core.h"
#include	"macros_soc.h"
#include	"soc_reg.h"

			bool		vTerminated = false;
volatile	uint32_t	*vNumber;

// Prototypes

static	void	local_RNG_IRQHandler(void);

/*
 * \brief model_random_hard_init
 *
 * - Initialise the hardware
 *
 */
void	model_random_hard_init(void) {

	RCC->AHB2ENR |= RCC_AHB2ENR_RNGEN;

	INTERRUPT_VECTOR(RNG_HASH_IRQn, local_RNG_IRQHandler);
	NVIC_SetPriority(RNG_HASH_C0_IRQn, KINT_LEVEL_PERIPHERALS);
	NVIC_EnableIRQ(RNG_HASH_C0_IRQn);
}

/*
 * \brief model_random_hard_read
 *
 * - Get a random number
 *
 */
void	model_random_hard_read(uint32_t *number) {

	vNumber = number;

// Turn on the RNG
// The RNG delivers a new random number every 16 x (120-MHz / 48-MHz) = 333-ns
// Configuration proposed by ST to comply with NIST SP800-90B

	vTerminated = false;
	RNG->CR |= (RNG_CR_RNGEN | RNG_CR_IE);

	while (vTerminated) {
		kern_switchFast();
	}
}

// Local routines
// ==============

/*
 * \brief local_RNG_IRQHandler
 *
 * - Interruption new number
 *
 */
static	void	local_RNG_IRQHandler(void) {
	uint8_t		i;

// Is data ready, no seed error, no clock error

	if (((RNG->SR & RNG_SR_DRDY) != 0U) && ((RNG->SR & RNG_SR_SEIS) == 0U) && ((RNG->SR & RNG_SR_CEIS) == 0U)) {
		*vNumber = RNG->DR;
		vTerminated = true;
		RNG->CR &= ~(RNG_CR_RNGEN | RNG_CR_IE);
		return;
	}

// Seed error
// Read 12 time to clear seed error

	if ((RNG->SR & RNG_SR_SEIS) == RNG_SR_SEIS) {
		RNG->SR &= (uint32_t)~RNG_SR_SEIS;
		for (i = 0U; i < 12U; i++) {
			RNG->DR;
		}
	}

// Clock error
// !!! Wrong clock configurtion, please fix your code

	if ((RNG->SR & RNG_SR_CEIS) == RNG_SR_CEIS) {
		RNG->SR &= (uint32_t)~RNG_SR_CEIS;
	}
}
