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
; linker_stTEXT         +-----------------+
;                       |                 |
;                       | .isr_vector     |
;                       | .text           |
;                       | .rodata         |
; linker_enRODATA       |                 |
;                       +-----------------+
; linker_stSignature    |                 |             DATA
;                       +-----------------+ ........... +-----------------+ linker_stDATA
; linker_stINDATA       |                 |             |                 |
;                       | .data           |             | .data           |
;                       |                 |             |                 | linker_enDATA
;                       +-----------------+ ........... +-----------------+
;                                                       |                 | linker_stBSS
;                                                       | .bss            |
;                                                       | COMMON          |
;                                                       |                 | linker_enBSS
;                                                       +-----------------+
;------------------------------------------------------------------------
*/

ENTRY(Reset_C0_Handler)

INCLUDE     STM32H747xI.ld

/* Mapping:                                                 */
/*                                                          */
/* RAM1:    Stacks              0x30000000                  */
/*          6K                                              */
/*          Program Data        0x30001800                  */
/*          122K                                            */
/* RAM2:    Heap                0x30020000                  */
/*          128K                                            */
/* RAM3:    Heap                0x30040000                  */
/*          32K                                             */
/* RAM4:    Share               0x38000000                  */
/*          64K                                             */

config_sizeStacks           = (6k);
config_sizeData             = stm_lnSRAM1 - config_sizeStacks;

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_sizeStackSystem_C0   = (4K);                                                                 /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                                 /* Length of the First stack                                */
linker_lowStackFirst_C0     = stm_stSRAM1;                                                          /* 0x30000000                                               */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;
linker_lowStackSystem_C0    = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;                   /* 0x30000800                                               */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;
ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_sizeStackSystem_C0 + linker_sizeStackFirst_C0)  == config_sizeStacks, "Error in size of stacks")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0;                                                                    /* 0x00000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (0);                                                                  /* Length of the external memory                            */

linker_stUMemo              = 0;                                                                    /* 0x00000000: UMemo, start of the user memory              */
linker_lnUMemo              = (0);                                                                  /* Length of the user memory                                */

linker_stShare              = stm_stSRAM4;                                                          /* 0x38000000: Share, start of the multicore shared memory  */
linker_lnShare              = stm_lnSRAM4;                                                          /* 0x00010000: Length of the user multicore shared memory   */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = stm_stSRAM2;                                                          /* 0x30020000: start of the heap                            */
linker_lnHeap               = (stm_lnSRAM2 + stm_lnSRAM3);                                          /* 0x00028000: Length of the heap                           */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = stm_stINTFLASH_CM4;                                                   /* 0x08100000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = stm_lnINTFLASH_CM4;                                                   /* 0x00100000: Length of the the Flash                      */

linker_stPrgmData           = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;                 /* 0x30001800: PrgmData, start of the RAM                   */
linker_lnPrgmData           = config_sizeData;                                                      /* 0x0001E800: Length of the RAM            */

/* IMPORTANT: equates necessary for the arm_v7 MPU regions                          */
/* IMPORTANT: for the arm_v7 MPU the regions have to be carefully defined           */

linker_ST_FLASH_INT_0       = stm_stINTFLASH_CM4;                                                   /* 0x08100000: Privileged/User FLASH                        */
linker_SZ_FLASH_INT_0       = 19;                                                                   /* 1-M = 2^(SZ + 1), SZ = log2(1-M) - 1                     */

linker_ST_RAM_INT_0         = stm_stSRAM1;                                                          /* 0x30000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_0         = 16;                                                                   /* 128-K = 2^(SZ + 1), SZ = log2(128-K) - 1                 */

linker_ST_RAM_INT_1         = stm_stSRAM2;                                                          /* 0x30020000: Privileged/User RAM                          */
linker_SZ_RAM_INT_1         = 17;                                                                   /* 256-K = 2^(SZ + 1), SZ = log2(256-K) - 1                 */

linker_ST_RAM_INT_2_SHARED  = stm_stSRAM4;                                                          /* 0x38000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_2_SHARED  = 15;                                                                   /* 64-K = 2^(SZ + 1), SZ = log2(64-K) - 1                   */

MEMORY {
    prgm_code (rx)  : ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
    prgm_data (rwx) : ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

ASSERT((linker_sizeStackFirst_C0 + linker_sizeStackSystem_C0 + linker_lnPrgmData + linker_lnHeap + linker_lnUMemo + linker_lnShare) == (stm_lnSRAM123 + stm_lnSRAM4), "Check RAM mapping: over/under usage")

INCLUDE     system_p.ld
