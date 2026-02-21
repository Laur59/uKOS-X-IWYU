/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; link_p.
; =======

;------------------------------------------------------------------------
; Project: uKOS-X
; Purpose:
;    Linker description for the uKOS-X system.
;    Privileged only support
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
;------------------------------------------------------------------------
*/

ENTRY(Reset_C0_Handler)

INCLUDE		STM32N657xD.ld

/* Mapping:													*/
/*															*/
/* RAM2:	Program Code (Boot)	0x34100400 (400 signature)	*/
/*			64K												*/
/* RAM1:	Program Code (Appl)	0x34000400 (400 signature)	*/
/*			(1024K - 1K)									*/
/* RAM2:	Stacks				0x34100000					*/
/*			16K												*/
/*			Program Data		0x34104000					*/
/*			240K											*/
/*			User Memory			0x34140000					*/
/*			512K											*/
/*			Heap				0x341C0000					*/
/*			256K +											*/
/* RAM3-6:	(4 * 448K)										*/

config_sizeStacks			= (16k);
config_sizeData				= (240k);
config_sizeUMemory			= (512K);

stm_lnAXISRAM3_6			= (stm_lnAXISRAM3 + stm_lnAXISRAM4 + stm_lnAXISRAM5 + stm_lnAXISRAM6);	/* Length of internal memory SRAM3 to SRAM6					*/

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_sizeStackSystem_C0	= (8K);																	/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (8K);																	/* Length of the First stack  								*/
linker_lowStackSystem_C0	= stm_stAXISRAM2;														/* 0x34100000:												*/
linker_topStackSystem_C0	= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;				/* 0x34101FF8:												*/
linker_lowStackFirst_C0		= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;					/* 0x34102000:												*/
linker_topStackFirst_C0		= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;				/* 0x34103FF8:												*/
ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_sizeStackSystem_C0 + linker_sizeStackFirst_C0)  == config_sizeStacks, "Error in size of stacks")

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0;																	/* 0x00000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (0);																	/* Length of the external memory	  						*/

linker_stUMemo				= (linker_stPrgmData + linker_lnPrgmData);								/* 0x34140000: UMemo, start of the user memory 				*/
linker_lnUMemo				= config_sizeUMemory;													/* Length of the user memory	  							*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (linker_stUMemo + linker_lnUMemo);									/* 0x341C0000: start of the heap							*/
linker_lnHeap				= (256K + stm_lnAXISRAM3_6);											/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= (stm_stAXISRAM1 + 1K);												/* 0x34000400: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= (1024K - 1K);															/* Length of the the Flash									*/

linker_stPrgmData			= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;					/* 0x34104000: PrgmData, start of the RAM					*/
linker_lnPrgmData			= config_sizeData;														/* Length of the RAM										*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v8 MPU regions				*/
/* for the arm_v8 MPU the regions have to be 32-B aligned	*/

linker_ST_RAM_INT_1			= (stm_stAXISRAM1);														/* 0x34000000: Privileged/User RAM							*/
linker_EN_RAM_INT_1			= (stm_stAXISRAM1 + stm_lnAXISRAM1 - 1);								/* 0x340FFFFF: 1-M											*/

linker_ST_RAM_INT_2			= (stm_stAXISRAM2);														/* 0x34100000: Privileged/User RAM							*/
linker_EN_RAM_INT_2			= (stm_stAXISRAM2 + stm_lnAXISRAM2 + stm_lnAXISRAM3_6 - 1);				/* 0x343BFFFF: 2816-K										*/

MEMORY {
	prgm_code (rwx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE		system_p.ld
