/*
; MX25R6435.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		FLASH MX25R6435 equates.
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

// Memory structure

#define	KFLASH_SPI_SZ_SECTOR				4096U											// Sector size
#define	KFLASH_SPI_NB_SECTOR				2048U											// Number of sectors
#define	KFLASH_SPI_SZ_PAGE					256U											// Page size
#define	KFLASH_SPI_SZ_BLOC					65536U											// Bloc size
#define	KFLASH_SPI_NB_BLOC					128U											// Number of blocs of 64-KBytes
#define	KFLASH_SPI_SZ_FLASH					(KFLASH_SPI_NB_SECTOR * KFLASH_SPI_SZ_SECTOR)	// FLASH size

// Commands for the chip MX25R6435

#define	KFLASH_SPI_CMD_WRITE_STATUS			0x01u											// FLASH write status command
#define	KFLASH_SPI_CMD_WRITE				0x02u											// FLASH write command (pages of 256 bytes)
#define	KFLASH_SPI_CMD_READ					0x03u											// FLASH read command
#define	KFLASH_SPI_CMD_WRITE_DISABLE		0x04u											// FLASH write disable command
#define	KFLASH_SPI_CMD_READ_STATUS			0x05u											// FLASH read status command
#define	KFLASH_SPI_CMD_WRITE_ENABLE			0x06u											// FLASH write enable command
#define	KFLASH_SPI_CMD_ERASE_SECTOR			0x20u											// FLASH erase sector command
#define	KFLASH_SPI_CMD_ERASE_BLOC			0xD8u											// FLASH erase bloc command
#define	KFLASH_SPI_CMD_ERASE_BULK			0xC7u											// FLASH bulk erase command

// Status bits for the chip MX25R6435

#define	BFLASH_SPI_BUSY						0U												// Erase or write in progress
#define	BFLASH_SPI_WEL						1U												// Write enable latch
#define	BFLASH_SPI_BP0						2U												// Block protect block 0
#define	BFLASH_SPI_BP1						3U												// Block protect block 1
#define	BFLASH_SPI_BP2						4U												// Block protect block 2
#define	BFLASH_SPI_BP3						5U												// Block protect block 3
#define	BFLASH_SPI_SRWD						7U												// Status register protect
