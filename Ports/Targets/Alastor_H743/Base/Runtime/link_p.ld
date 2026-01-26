/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; link_p.
; =======

;------------------------------------------------------------------------
; Project:	uKOS-X
; Goal:		Linker description for the uKOS-X system.
;			Privileged only support
;
;                       CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .isr_vector     |
;						| .text           |
;						| .rodata         |
; linker_enRODATA		|                 |
;						+-----------------+
; linker_stSignature	|				  |             DATA
;						+-----------------+ ........... +-----------------+ linker_stDATA
; linker_stINDATA		|                 |				|                 |
;						| .data           |				| .data           |
;						|                 |				|                 | linker_enDATA
;						+-----------------+ ........... +-----------------+
;														|                 | linker_stBSS
;														| .bss            |
;														| COMMON          |
;														|                 | linker_enBSS
;														+-----------------+
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

ENTRY(Reset_C0_Handler)

INCLUDE		STM32H743xI.ld

/* Mapping:													*/
/*															*/
/* RAM1:	Stacks				0x30000000					*/
/*			6K												*/
/*			Program Data		0x30001800					*/
/*			122K											*/
/* RAM2:	128K				0x30020000					*/
/* RAM3:	32K					0x30040000					*/
/* EXT:		Heap				0x70000000					*/
/*			2048K											*/
/*			User Memory			0x70200000					*/
/*			6144K											*/

config_sizeStacks			= (6k);
config_sizeData				= stm_lnSRAM123 - config_sizeStacks;
config_sizeHeap				= (2048K);
config_sizeUMemory			= (6144K);

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_sizeStackSystem_C0	= (4K);															/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (2K);															/* Length of the First stack  								*/
linker_lowStackFirst_C0		= stm_stSRAM1;													/* 0x30000000:												*/
linker_topStackFirst_C0		= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;
linker_lowStackSystem_C0	= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;			/* 0x30000800:												*/
linker_topStackSystem_C0	= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;
ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_sizeStackSystem_C0 + linker_sizeStackFirst_C0)  == config_sizeStacks, "Error in size of stacks")

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0x70000000;													/* 0x70000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= config_sizeUMemory + config_sizeHeap;							/* Length of the external memory	  						*/

linker_stUMemo				= 0x70200000;													/* 0x70200000: UMemo, start of the user memory 				*/
linker_lnUMemo				= config_sizeUMemory;											/* Length of the user memory	  							*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= 0x70000000;													/* 0x70000000: start of the heap							*/
linker_lnHeap				= config_sizeHeap;												/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= stm_stINTFLASH;												/* 0x08000000: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= stm_lnINTFLASH;												/* Length of the the Flash									*/

linker_stPrgmData			= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;			/* 0x30001800: PrgmData, start of the RAM					*/
linker_lnPrgmData			= config_sizeData;												/* Length of the RAM										*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v7 MPU regions				*/
/* for the arm_v7 MPU the regions have to be 32-B aligned	*/

linker_ST_FLASH_INT_0		= stm_stINTFLASH;												/* 0x08000000: Privileged/User FLASH						*/
linker_SZ_FLASH_INT_0		= 20;															/* 2-M = 2^(SZ + 1), SZ = log2(2-M) - 1						*/

linker_ST_RAM_INT_0			= stm_stAXISRAM;												/* 0x24000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_0			= 18;															/* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1					*/

linker_ST_RAM_INT_1			= stm_stSRAM1;													/* 0x30000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_1			= 18;															/* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1					*/

linker_ST_RAM_INT_2			= stm_stSRAM4;													/* 0x38000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_2			= 15;															/* 64-K = 2^(SZ + 1), SZ = log2(64-K) - 1					*/

linker_ST_RAM_EXT_0			= linker_stEXRAM;												/* 0x70000000: Privileged/User RAM							*/
linker_SZ_RAM_EXT_0			= 22;															/* 8-M = 2^(SZ + 1), SZ = log2(8-M) - 1						*/

MEMORY {
	prgm_code (rx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

ASSERT((linker_sizeStackSystem_C0 + linker_sizeStackFirst_C0 + linker_lnPrgmData) == stm_lnSRAM123, "Check RAM1 mapping: over/under usage")

INCLUDE		system_p.ld
