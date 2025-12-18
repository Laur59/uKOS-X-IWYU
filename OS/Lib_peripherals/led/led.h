/*
; led.
; ===

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		led manager.
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

#pragma	once

#include	<stdint.h>

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

enum {
		KLED_0 = (uint8_t)0U,
		KLED_1 = (uint8_t)1U,
		KLED_2 = (uint8_t)2U,
		KLED_3 = (uint8_t)3U,
		KLED_4 = (uint8_t)4U,
		KLED_5 = (uint8_t)5U,
		KLED_6 = (uint8_t)6U,
		KLED_7 = (uint8_t)7U,
		KLED_8 = (uint8_t)8U,
		KLED_9 = (uint8_t)9U
};

/*!
 * \defgroup led Led
 *
 * \brief Led
 *
 * Led management
 *
 * @{
 */

#ifdef __cplusplus
extern	"C" {
#endif

/*!
 * \brief Turn on a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *     status = led_on(ledNb);
 * \endcode
 *
 * \param[in]	ledNb			LED number
 * \return		KERR_LED_NOERR	OK
 * \return		KERR_LED_NODEV	The selected LED does not exist
 *
 */
extern	int32_t	led_on(uint8_t ledNb);

/*!
 * \brief Turn off a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *    status = led_off(ledNb);
 * \endcode
 *
 * \param[in]	ledNb			LED number
 * \return		KERR_LED_NOERR	OK
 * \return		KERR_LED_NODEV	The selected LED does not exist
 *
 */
extern	int32_t	led_off(uint8_t ledNb);

/*!
 * \brief Change the state of a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *    status = led_toggle(ledNb);
 * \endcode
 *
 * \param[in]	ledNb			LED number
 * \return		KERR_LED_NOERR	OK
 * \return		KERR_LED_NODEV	The selected LED does not exist
 *
 */
extern	int32_t	led_toggle(uint8_t ledNb);

/*!
 * \brief General control of the LEDs
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = led_mute(true);  //
 *                              //
 *                              //
 *    status = led_mute(false); // Portion of code without any LED activity
 * \endcode
 *
 * \param[in]	mute			true -> turn off all the LEDs, false -> normal mode
 * \return		KERR_LED_NOERR	OK
 *
 */
extern	int32_t	led_mute(bool mute);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
