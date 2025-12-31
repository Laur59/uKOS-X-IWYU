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

#ifndef Alastor_H743_S
#define	Alastor_H743_S
#endif

// System identifiers
// ------------------

#define	KCPU				"ARM-Cortex m7 H"
#define	KCONTROLLER			"STM32H743"
#define	KBOARD				"Alastor H743 (Variant_Test)"
#define	KTARGET				"Alastor_H743"

// GPIO settings
// -------------

#define KNB_LED				(8U + 2U)							// Number of LEDs (LEDs + BLOGICx)

// PORTs

#define	BSEL_DEBUG			4U									// PORT A 4, /CS Debug
#define	BRZ_FLASH			8U									// PORT A 8, /Rz FLASH

#define	BSEL_WROOM			0U									// PORT B 0, /CS Wroom
#define	BLED_0				1U									// PORT B 1, BLED_0
#define	BLED_1				5U									// PORT B 5, BLED_1
#define	BLED_2				7U									// PORT B 7, BLED_2
#define	BSEL_FLASH			12U									// PORT B 12, /CS FLASH

#define	BLED_3				3U									// PORT C 3, BLED_3
#define	BLED_4				4U									// PORT C 4, BLED_4
#define	BLED_5				5U									// PORT C 5, BLED_5
#define	BSEL_ACCELERO		6U									// PORT C 6, /CS accelerometer/gyroscope
#define	BLED_6				8U									// PORT C 8, BLED_6
#define	BLED_7				9U									// PORT C 9, BLED_7
#define	BSW_0				10U									// PORT C 10, SW0
#define	BSW_1				11U									// PORT C 11, SW1
#define	BSW_2				12U									// PORT C 12, SW2
#define	BSW_3				13U									// PORT C 13, SW3

#define	BESP32_X1			2U									//
#define	BESP32_RTS			BESP32_X1							// PORT D 2, ESP32_X1, GPIO14, AT.RTS
#define	BIO_W_0				2U									// PORT D 2, IO_W_0 (Wroom status)
#define	BIO_W_1				3U									// PORT D 3, IO_W_1
#define	BCTS				BIO_W_1								// PORT D 3, IO_W_1 (Wroom /CTS)
#define	BIO_W_2				4U									// PORT D 4, IO_W_2
#define	BIO_W_3				5U									// PORT D 5, IO_W_3
#define	BIO_W_4				6U									// PORT D 6, IO_W_4
#define	BIO_W_5				7U									// PORT D 7, IO_W_5
#define	BIO_W_6				11U									// PORT D 11, IO_W_6
#define	BIO_W_7				12U									// PORT D 12, IO_W_7
#define	BESP32_NDOWNLOAD	13U									// PORT D 13, ESP32_DOWNLOAD, GPIO0, low=download

#define	BESP32_ENABLE		3U									// PORT E 3, ESP32_ENABLE, CHIP_PU, low=power off
#define	BSEL_SDCARD			4U									// PORT E 4, /CS of the device

#define	BSEL_MAGNETO		10U									// PORT F 10, /CS magnetometer

#define	BESP32_X0			3U									// PORT G 3, OI_W_0, GPIO15, AT.CTX
#define	BESP32_CTS			BESP32_X0
#define	BOI_W_0				BESP32_X0							// PORT G 3, OI_W_0
#define	BRTS				BOI_W_0								// PORT G 3, OI_W_0 (Wroom /RTS)
#define	BOI_W_1				6U									// PORT G 6, OI_W_1
#define	BBOOT				BOI_W_1								// PORT G 6, OI_W_1 (Wroom /Boot)
#define	BOI_W_2				7U									// PORT G 7, OI_W_2
#define	BE					BOI_W_2								// PORT G 7, OI_W_2 (Wroom E)
#define	BOI_W_3				9U									// PORT G 9, OI_W_3
#define	BOI_W_4				10U									// PORT G 10, OI_W_4
#define	BOI_W_5				11U									// PORT G 11, OI_W_5
#define	BDBG_COM_REQ		13U									// PORT G 13, DBGCOMREQ
#define	BNO_SDCARD			14U									// PORT G 14, sdcard inside the slot

#define	BEN_CLK				2U									// PORT H 2, Enable the Aptina clock
#define	BDEN_AG				3U									// PORT H 3, BDEN_AG IMU
#define	BDBG_REQ			13U									// PORT H 13, DBGREQ

#define	BOI_W_6				0U									// PORT I 0, OI_W_6
#define	BOI_W_7				3U									// PORT I 3, OI_W_7
#define	BLOGIC_0			8U									// PORT I 8, LOGIC0
#define	BLOGIC_1			9U									// PORT I 9, LOGIC1
#define	BSTANDBY			10U									// PORT I 10, Standby imager
#define	BEXPOSURE			11U									// PORT I 11, Exposure imager
