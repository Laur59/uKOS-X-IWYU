/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; link_p.
; =======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Linker description for the uKOS-X system.
;           Privileged only support
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

INCLUDE     STM32U5G9xJ.ld

/* Mapping:                                                 */
/*                                                          */
/* RAM1:    Stacks              0x30000000                  */
/*          6K                                              */
/*          Program Data        0x30001800                  */
/*          250K                                            */
/*          Heap                0x30040000                  */
/*          2048K                                           */
/*          User Memory         0x30240000                  */
/*          704K                                            */

linker_sizeStackSystem_C0   = (4K);                                                 /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                 /* Length of the First stack                                */
config_sizeData             = (250K);

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackFirst_C0     = stm_stSRAM1;                                          /* 0x30000000: start of the First stack                     */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

linker_lowStackSystem_C0    = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;   /* 0x30000800: start of the System stack                    */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0;                                                    /* 0x00000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (0);                                                  /* Length of the external memory                            */

linker_stUMemo              = (linker_stHeap + linker_lnHeap);                      /* 0x30240000: UMemo, start of the user memory              */
linker_lnUMemo              = (704K);                                               /* Length of the user memory                                */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = (linker_stPrgmData + linker_lnPrgmData);              /* 0x30040000: start of the heap                            */
linker_lnHeap               = (2048K);                                              /* Length of the heap                                       */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = stm_stINTFLASH;                                       /* 0x0C000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = stm_lnINTFLASH;                                       /* Length of the the Flash                                  */

linker_stPrgmData           = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0; /* 0x30001800: start of program data                        */
linker_lnPrgmData           = config_sizeData;                                      /* Length of program data                                   */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v8 MPU regions             */
/* for the arm_v8 MPU the regions have to be 32-B aligned   */

linker_ST_FLASH_INT_0       = stm_stINTFLASH;                                       /* 0x0C000000: Privileged/User FLASH                        */
linker_EN_FLASH_INT_0       = (stm_stINTFLASH + stm_lnINTFLASH - 1);                /* 0x0C3FFFFF: 4-M                                          */

linker_ST_RAM_INT_0         = stm_stSRAM1;                                          /* 0x30000000: Privileged/User RAM                          */
linker_EN_RAM_INT_0         = (stm_stSRAM1 + 2368K - 1);                            /* 0x3024FFFF: 2368-K                                       */

MEMORY {
    prgm_code (rx)  : ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
    prgm_data (rwx) : ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE     system_p.ld
