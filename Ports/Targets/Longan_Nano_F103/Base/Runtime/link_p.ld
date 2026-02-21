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
;						| .restart        |
;						| .vectors        |
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

OUTPUT_ARCH( "riscv" )
ENTRY(Reset_C0_Handler)

INCLUDE		GD32VF103CBT.ld

/* Mapping:													*/
/*															*/
/* RAM:		Stacks				0x20000000					*/
/*			1.75K											*/
/*			Program Data		0x20000700					*/
/*			14.25K											*/
/*			Heap				0x20004000					*/
/*			13K												*/
/*			User Memory			0x20007400					*/
/*			3K												*/

linker_sizeStackSystem_C0	= (0);														/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (1792);													/* Length of the First stack  								*/
config_sizeData				= (14592);
config_sizeHeap				= (13K);

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 16-bytes								*/

linker_lowStackFirst_C0		= gd_stSRAM;												/* 0x20000000												*/
linker_topStackFirst_C0		= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 16;
linker_lowStackSystem_C0	= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;		/* 0x20000700												*/
linker_topStackSystem_C0	= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 16;
ASSERT((linker_lowStackSystem_C0 & 15) == 0, "Stack system must be 16-byte aligned")
ASSERT((linker_topStackSystem_C0 & 15) == 0, "Stack system must be 16-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 15)  == 0, "Stack user must be 16-byte aligned")
ASSERT((linker_topStackFirst_C0 & 15)  == 0, "Stack user must be 16-byte aligned")

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0;													/* 0x00000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (0);													/* Length of the external memory	  						*/

linker_stUMemo				= (linker_stHeap + linker_lnHeap);						/* 0x20007400: UMemo, start of the user memory 				*/
linker_lnUMemo				= gd_lnSRAM - linker_sizeStackFirst_C0
								- config_sizeData - config_sizeHeap;					/* Length of the user memory	  							*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (linker_stPrgmData + linker_lnPrgmData);				/* 0x20004000: start of the heap							*/
linker_lnHeap				= config_sizeHeap;											/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= gd_stINTFLASH;										/* 0x08000000: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= gd_lnINTFLASH;										/* Length of the the Flash									*/

linker_stPrgmData			= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;		/* 0x20000700: start of program data						*/
linker_lnPrgmData			= config_sizeData;											/* Length of program data									*/

MEMORY {
	prgm_code (rx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE		system_p.ld
