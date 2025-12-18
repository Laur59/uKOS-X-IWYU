/*
; stub_led.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		stub for the "led" manager module.
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

#include	"board.h"
#include	"macros_core.h"
#include	"os_errors.h"
#include	"soc_reg.h"

static	bool	vMute;

/*
 * \brief stub_led_init
 *
 * - Initialise some specific hardware parts:
 *   - The LEDs state
 *
 */
void	stub_led_init(void) {

}

/*
 * \brief stub_led_on
 *
 * - Turn on a LED
 *
 */
int32_t	stub_led_on(uint8_t ledNb) {

	INTERRUPTION_OFF;
	if (vMute) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
	switch (ledNb) {
		case 0U:  { GPIOI->ODR |= (1U<<BLED_0);					break; }
		case 1U:  { GPIOI->ODR |= (1U<<BLED_1);					break; }
		case 2U:  { GPIOI->ODR |= (1U<<BLED_2);					break; }
		case 3U:  { GPIOI->ODR |= (1U<<BLED_3);					break; }
		case 4U:  { GPIOI->ODR |= (1U<<BLED_4);					break; }
		case 5U:  { GPIOH->ODR |= (1U<<BLED_5);					break; }
		case 6U:  { GPIOD->ODR |= (1U<<BLED_6);					break; }
		case 7U:  { GPIOE->ODR |= (1U<<BLED_7);					break; }
		case 8U:  { GPIOK->ODR &= (uint32_t)~(1U<<BLED_RED);	break; }
		case 9U:  { GPIOK->ODR &= (uint32_t)~(1U<<BLED_GREEN);	break; }
		case 10U: { GPIOK->ODR &= (uint32_t)~(1U<<BLED_BLUE);	break; }
		default:  { RETURN_INT_RESTORE(KERR_LED_NODEV);				   }
	}

	RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_off
 *
 * - Turn off a LED
 *
 */
int32_t	stub_led_off(uint8_t ledNb) {

	INTERRUPTION_OFF;
	if (vMute) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
	switch (ledNb) {
		case 0U:  { GPIOI->ODR &= (uint32_t)~(1U<<BLED_0);	break; }
		case 1U:  { GPIOI->ODR &= (uint32_t)~(1U<<BLED_1);	break; }
		case 2U:  { GPIOI->ODR &= (uint32_t)~(1U<<BLED_2);	break; }
		case 3U:  { GPIOI->ODR &= (uint32_t)~(1U<<BLED_3);	break; }
		case 4U:  { GPIOI->ODR &= (uint32_t)~(1U<<BLED_4);	break; }
		case 5U:  { GPIOH->ODR &= (uint32_t)~(1U<<BLED_5);	break; }
		case 6U:  { GPIOD->ODR &= (uint32_t)~(1U<<BLED_6);	break; }
		case 7U:  { GPIOE->ODR &= (uint32_t)~(1U<<BLED_7);	break; }
		case 8U:  { GPIOK->ODR |= (1U<<BLED_RED);			break; }
		case 9U:  { GPIOK->ODR |= (1U<<BLED_GREEN);			break; }
		case 10U: { GPIOK->ODR |= (1U<<BLED_BLUE);			break; }
		default:  { RETURN_INT_RESTORE(KERR_LED_NODEV);			   }
	}

	RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_toggle
 *
 * - Change the state of a LED
 *
 */
int32_t	stub_led_toggle(uint8_t ledNb) {

	INTERRUPTION_OFF;
	if (vMute) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
	switch (ledNb) {
		case 0U:  { GPIOI->ODR ^= (1U<<BLED_0);		break; }
		case 1U:  { GPIOI->ODR ^= (1U<<BLED_1);		break; }
		case 2U:  { GPIOI->ODR ^= (1U<<BLED_2);		break; }
		case 3U:  { GPIOI->ODR ^= (1U<<BLED_3);		break; }
		case 4U:  { GPIOI->ODR ^= (1U<<BLED_4);		break; }
		case 5U:  { GPIOH->ODR ^= (1U<<BLED_5);		break; }
		case 6U:  { GPIOD->ODR ^= (1U<<BLED_6);		break; }
		case 7U:  { GPIOE->ODR ^= (1U<<BLED_7);		break; }
		case 8U:  { GPIOK->ODR ^= (1U<<BLED_RED);	break; }
		case 9U:  { GPIOK->ODR ^= (1U<<BLED_GREEN);	break; }
		case 10U: { GPIOK->ODR ^= (1U<<BLED_BLUE);	break; }
		default:  { RETURN_INT_RESTORE(KERR_LED_NODEV);	   }
	}

	RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_mute
 *
 * - Control (general) of the LEDs
 *
 */
int32_t	stub_led_mute(bool mute) {

	if (!mute) { vMute = false; return (KERR_LED_NOERR); }

	INTERRUPTION_OFF;
	vMute = true;

	GPIOI->ODR &= (uint32_t)~(1U<<BLED_0);
	GPIOI->ODR &= (uint32_t)~(1U<<BLED_1);
	GPIOI->ODR &= (uint32_t)~(1U<<BLED_2);
	GPIOI->ODR &= (uint32_t)~(1U<<BLED_3);
	GPIOI->ODR &= (uint32_t)~(1U<<BLED_4);
	GPIOH->ODR &= (uint32_t)~(1U<<BLED_5);
	GPIOD->ODR &= (uint32_t)~(1U<<BLED_6);
	GPIOE->ODR &= (uint32_t)~(1U<<BLED_7);
	GPIOK->ODR |= (1U<<BLED_RED);
	GPIOK->ODR |= (1U<<BLED_GREEN);
	GPIOK->ODR |= (1U<<BLED_BLUE);
	RETURN_INT_RESTORE(KERR_LED_NOERR);
}
