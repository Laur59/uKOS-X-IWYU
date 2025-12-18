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

// This header contains only board-specific compile-time macros.
// It is not meant to contain function or variable declarations.
#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wempty-translation-unit"
#endif

// System identifiers
// ------------------

#define	KCPU				"ARM-Cortex m7 H"
#define	KCONTROLLER			"STM32H747"
#define	KBOARD				"Asmodee H747 (Variant_Test_CM4)"
#define	KTARGET				"Asmodee_H747"

// GPIO settings
// -------------

#define KNB_LED				(8U + 3U)							// Number of LEDs

// PORTs

#define	BLED_0				9U									// PORT I 9, LED
#define	BLED_1				10U									// PORT I 10, LED
#define	BLED_2				13U									// PORT I 13, LED
#define	BLED_3				14U									// PORT I 14, LED
#define	BLED_4				15U									// PORT I 15, LED
#define	BLED_5				13U									// PORT H 13, LED
#define	BLED_6				6U									// PORT D 6, LED
#define	BLED_7				2U									// PORT E 2, LED
#define	BLED_RED			5U									// PORT K 5, LED Red
#define	BLED_GREEN			6U									// PORT K 6, LED Green
#define	BLED_BLUE			7U									// PORT K 7, LED Blue

#define	BPUSH_0				0U									// PORT A 0, PUSH0

#define	BSW_0				8U									// PORT B 8, SW0
#define	BSW_1				14U									// PORT B 14, SW1
#define	BSW_2				15U									// PORT B 15, SW2
#define	BSW_3				2U									// PORT B 2, SW3

#define	BLOGIC_0			15U									// PORT I 15, LOGIC0
#define	BLOGIC_1			13U									// PORT H 13, LOGIC1
