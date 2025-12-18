/*
; board.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Board mapping.
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

// System identifiers
// ------------------

#define	KCPU				"RISC-V RV64IMAFDC"
#define	KCONTROLLER			"K210"
#define	KBOARD				"MAiXDUiNO K210 RISC-V (Variant_Test)"
#define	KTARGET				"MAiXDUiNO_K210"

// GPIOHS settings
// ---------------

#define	LED_GREEN_OFF		(gpiohs->output_val.u32[0] |=			 (1U<<BLED_0))	//
#define	LED_GREEN_ON		(gpiohs->output_val.u32[0] &= (uint32_t)~(1U<<BLED_0))	//
#define	LED_GREEN_TOGGLE	(gpiohs->output_val.u32[0] ^=			 (1U<<BLED_0))	//
#define	LED_RED_OFF			(gpiohs->output_val.u32[0] |=			 (1U<<BLED_1))	//
#define	LED_RED_ON			(gpiohs->output_val.u32[0] &= (uint32_t)~(1U<<BLED_1))	//
#define	LED_RED_TOGGLE		(gpiohs->output_val.u32[0] ^=			 (1U<<BLED_1))	//
#define	LED_BLUE_OFF		(gpiohs->output_val.u32[0] |=			 (1U<<BLED_2))	//
#define	LED_BLUE_ON			(gpiohs->output_val.u32[0] &= (uint32_t)~(1U<<BLED_2))	//
#define	LED_BLUE_TOGGLE		(gpiohs->output_val.u32[0] ^=			 (1U<<BLED_2))	//
#define	LED_1_TOGGLE		LED_RED_TOGGLE											//
#define	LED_1_ON			LED_RED_ON												//
#define	LED_1_OFF			LED_RED_OFF												// Led macros

#define KNB_LED				3U														// Number of LEDs

// LEDs

#define	BLED_0				8U														// GPIO8  - IO12, BLED_0
#define	BLED_1				9U														// GPIO9  - IO13, BLED_1
#define	BLED_2				10U														// GPIO10 - IO14, BLED_2

// LCD

#define	BLCD_DCX			2U														// GPIO02 - IO38, BLCD_DCX
#define	BLCD_RST			3U														// GPIO03 - IO37, BLCD_RST
