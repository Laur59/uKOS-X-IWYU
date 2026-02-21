/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; link_pu.
; ========

;------------------------------------------------------------------------
; Project: uKOS-X
; Purpose:
;    Linker description for the uKOS-X system.
;    Privileged / user support
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
;						+-----------------+ ........... +-----------------+ linker_stDATA_p
; linker_stINDATA_p		|                 |				|                 |
;						| .data_p         |				| .data_p         |
;						|                 |				|                 | linker_enDATA_p
; linker_stINDATA_u		|                 |				|                 | linker_stDATA_u
;						| .data_u         |				| .data_u         |
;						|                 |				|                 | linker_enDATA_u
;						+-----------------+ ........... +-----------------+
;														|                 | linker_stBSS_p
;														| .bss_p          |
;														| COMMON          |
;														|                 | linker_enBSS_p
;														|                 | linker_stBSS_u
;														| .bss_u          |
;														|                 | linker_enBSS_u
;														+-----------------+
;------------------------------------------------------------------------
*/

ENTRY(Reset_C0_Handler)

INCLUDE		STM32U5G9xJ.ld

/* Mapping:													*/
/*															*/
/* RAM1:	Protected			0x30000000					*/
/*			  Stack System		0x30000000					*/
/*			  4K											*/
/*			  Program Data (P)	0x30001000					*/
/*			  124K											*/
/*			Unprotected			0x30020000					*/
/*			  Stack First		0x30020000					*/
/*			  2K											*/
/*			  Program Data (U)	0x30020800					*/
/*			  126K											*/
/*			  Heap				0x30040000					*/
/*			2048K											*/
/*			  User Memory		0x30240000					*/
/*			704K											*/

linker_sizeStackSystem_C0	= (4K);													/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (2K);													/* Length of the First stack  								*/
config_sizeData_p			= (124K);
config_sizeData_u			= (126K);

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_lowStackSystem_C0	= stm_stSRAM1;											/* 0x30000000: start of the System stack					*/
linker_topStackSystem_C0	= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;

linker_lowStackFirst_C0		= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0
							+ config_sizeData_p;									/* 0x30020000: start of the First stack						*/
linker_topStackFirst_C0		= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0;													/* 0x00000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (0);													/* Length of the external memory	  						*/

linker_stUMemo				= (linker_stHeap + linker_lnHeap);						/* 0x30240000: UMemo, start of the user memory 				*/
linker_lnUMemo				= (704K);												/* Length of the user memory	  							*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (linker_stPrgmData_u + linker_lnPrgmData_u);			/* 0x30040000: start of the heap							*/
linker_lnHeap				= (2048K);												/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= stm_stINTFLASH;										/* 0x0C000000: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= stm_lnINTFLASH;										/* Length of the the Flash									*/

linker_stPrgmData_p			= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;	/* 0x30001000: start of protected program data				*/
linker_lnPrgmData_p			= config_sizeData_p;									/* Length of protected program data							*/

linker_stPrgmData_u			= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;	/* 0x30020800: start of unprotected program data			*/
linker_lnPrgmData_u			= config_sizeData_u;									/* Length of unprotected program data						*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v8 MPU regions				*/
/* for the arm_v8 MPU the regions have to be 32-B aligned	*/

linker_ST_FLASH_INT_0		= stm_stINTFLASH;										/* 0x0C000000: Privileged/User FLASH						*/
linker_EN_FLASH_INT_0		= (stm_stINTFLASH + stm_lnINTFLASH - 1);				/* 0x0C3FFFFF: 4-M											*/

linker_ST_RAM_INT_0_OS		= stm_stSRAM1;											/* 0x30000000: Privileged RAM								*/
linker_EN_RAM_INT_0_OS		= (stm_stSRAM1 + 128K - 1);								/* 0x3001FFFF: 128-K										*/

linker_ST_RAM_INT_0			= (linker_stPrgmData_u);								/* 0x30020000: Privileged/User RAM							*/
linker_EN_RAM_INT_0			= (linker_stPrgmData_u + 2176K + 704K - 1);				/* 0x302EFFFF: 2176-K + 704-K								*/

linker_ST_PERIPH_SOC		= stm_stPERIPH_NS;										/* 0x40000000: Privileged PERIPHERALS						*/
linker_EN_PERIPH_SOC		= (stm_stPERIPH_NS + 524288K - 1);						/* 0x5FFFFFFF: 2 x 256-M (_S & _NS)							*/

linker_ST_PERIPH_CORE		= stm_stCORE;											/* 0xE0000000: Privileged core PERIPHERALS					*/
linker_EN_PERIPH_CORE		= (stm_stCORE + 262144K - 1);							/* 0xEFFFFFFF: 256-M										*/

MEMORY {
	prgm_code (rx)		: ORIGIN = linker_stPrgmCode,   LENGTH = linker_lnPrgmCode
	prgm_data_p (rwx)	: ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
	prgm_data_u (rwx)	: ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

INCLUDE		system_pu.ld
