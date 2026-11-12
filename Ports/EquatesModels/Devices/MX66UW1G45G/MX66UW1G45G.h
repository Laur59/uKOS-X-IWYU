/*
; MX66UW1G45G.
; ============
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-11-09
; Modifs:
;
; Project:	uKOS-X
; Goal:		OctoFlash MX66UW1G45GXDI00 equates.
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

#pragma	once

// Memory structure

#define	KMX66_xSPI_SZ_FLASH					(128u * 1024u * 1024u)							// Flash size (128-MBytes)
#define	KMX66_DEV_SIZE_VALUE				26u												// 128-MB = 2^(26 + 1)

// XSPI timings (assumed 300-MHz kernel clock; validate on the board)

#define	KMX66_PRESCALER						(8u - 1u)										// 37.5-MHz XSPI clock
#define	KMX66_DUMMY_CYCLES					20u												// Read latency: validate against CR2
#define	KMX66_TIMEOUT						10000000u										// Polling limit, not a timebase

// Commands for the chip MX66UW1G45GXDI00 (SPI STR)

#define	KMX66_OP_RESET_ENABLE				0x66u											// Reset enable
#define	KMX66_OP_RESET						0x99u											// Reset memory
#define	KMX66_OP_WRITE_ENABLE				0x06u											// Write enable
#define	KMX66_OP_READ_STATUS				0x05u											// Read status register
#define	KMX66_OP_READ_CFG2					0x71u											// Read configuration register 2
#define	KMX66_OP_WRITE_CFG2					0x72u											// Write configuration register 2

// Commands for the chip MX66UW1G45GXDI00 (Octal DTR)

#define	KMX66_OP_OCTAL_READ					0xEE11u											// Octal DDR read, opcode + complement

// Configuration register 2 addresses and fields

#define	KMX66_CFG2_PROTOCOL					0x00000000u										// Protocol selection
#define	KMX66_CFG2_DUMMY					0x00000300u										// Dummy cycle selection
#define	KMX66_CFG2_DTR						0x02u											// Octal DTR selection
#define	KMX66_CFG2_DC20						0x00u											// 20 dummy cycles: verify datasheet encoding

// Register selectors used by local_OctoFlashRead/WriteRegister (uint8_t API)

#define	KMX66_REG_PROTOCOL					0u												// CR2 at 0x00000000
#define	KMX66_REG_DUMMY						3u												// CR2 at 0x00000300
