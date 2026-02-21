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

INCLUDE		STM32H747xI.ld

/* Mapping:													*/
/*															*/
/* AXI:		Stacks				0x24000000					*/
/*			6K												*/
/*			Program Data		0x24001800					*/
/*			250K											*/
/* RAM4:	Share				0x38000000					*/
/*			64K												*/
/* EXT:		Heap				0x70000000					*/
/*			2048K											*/
/*			User Memory			0x70200000					*/
/*			6144K											*/

linker_sizeStackSystem_C0	= (4K);													/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (2K);													/* Length of the First stack  								*/
config_sizeData				= (250K);

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_lowStackSystem_C0	= stm_stAXISRAM;												/* 0x24000000:												*/
linker_topStackSystem_C0	= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;

linker_lowStackFirst_C0		= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;			/* 0x24001000:												*/
linker_topStackFirst_C0		= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0x70000000;													/* 0x70000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (8192K);												/* Length of the external memory	  						*/

linker_stUMemo				= (linker_stHeap + linker_lnHeap);								/* 0x70200000: UMemo, start of the user memory 				*/
linker_lnUMemo				= (6144K);												/* Length of the user memory	  							*/

linker_stShare				= stm_stSRAM4;													/* 0x38000000: Share, start of the multicore shared memory	*/
linker_lnShare				= stm_lnSRAM4;													/* Length of the user multicore shared memory				*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= linker_stEXRAM;												/* 0x70000000: start of the heap							*/
linker_lnHeap				= (2048K);												/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= stm_stINTFLASH_CM7;											/* 0x08000000: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= stm_lnINTFLASH_CM7;											/* Length of the the Flash									*/

linker_stPrgmData			= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;	/* 0x24001800: start of program data						*/
linker_lnPrgmData			= config_sizeData;										/* Length of program data									*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v7 MPU regions				*/
/* for the arm_v7 MPU the regions have to be 32-B aligned	*/

linker_ST_FLASH_INT_0		= stm_stINTFLASH_CM7;											/* 0x08000000: Privileged/User FLASH						*/
linker_SZ_FLASH_INT_0		= 19;															/* 1-M = 2^(SZ + 1), SZ = log2(2-M) - 1						*/

linker_ST_RAM_INT_0			= stm_stAXISRAM;												/* 0x24000000: Privileged RAM/User RAM						*/
linker_SZ_RAM_INT_0			= 18;															/* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1					*/

linker_ST_RAM_EXT_0			= linker_stEXRAM;												/* 0x70000000: Privileged/User RAM							*/
linker_SZ_RAM_EXT_0			= 22;															/* 8-M = 2^(SZ + 1), SZ = log2(8-M) - 1						*/

linker_ST_RAM_INT_1_SHARED	= linker_stShare;												/* 0x38000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_1_SHARED	= 15;															/* 64-K = 2^(SZ + 1), SZ = log2(64-K) - 1					*/

MEMORY {
	prgm_code (rx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

ASSERT((linker_sizeStackFirst_C0 + linker_sizeStackSystem_C0 + linker_lnPrgmData) <= stm_lnAXISRAM, "Check RAM mapping: over/under usage")

INCLUDE		system_p.ld
