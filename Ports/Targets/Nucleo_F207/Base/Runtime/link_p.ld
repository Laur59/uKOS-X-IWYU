/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_F207 – Linker memory regions, privileged-only mode.
 *
 *                       CODE
 * linker_stTEXT         +-----------------+
 *                       |                 |
 *                       | .isr_vector     |
 *                       | .text           |
 *                       | .rodata         |
 * linker_enRODATA       |                 |
 *                       +-----------------+
 * linker_stSignature    |                 |             DATA
 *                       +-----------------+ ........... +-----------------+ linker_stDATA
 * linker_stINDATA       |                 |             |                 |
 *                       | .data           |             | .data           |
 *                       |                 |             |                 | linker_enDATA
 *                       +-----------------+ ........... +-----------------+
 *                                                       |                 | linker_stBSS
 *                                                       | .bss            |
 *                                                       | COMMON          |
 *                                                       |                 | linker_enBSS
 *                                                       +-----------------+
 */

ENTRY(Reset_C0_Handler)

INCLUDE     STM32F207xx.ld

/* Mapping:                                                 */
/*                                                          */
/* RAM1:    Stacks              0x20000000                  */
/*            Stack First       0x20000000                  */
/*            2K                                                */
/*            Stack System      0x20000800                  */
/*            4K                                                */
/*          Program Data        0x20001800                  */
/*          74K                                             */
/*          stHeap              0x20014000                  */
/*          28K                                             */
/*          stUMemo             0x2001B000                  */
/*          20K                                             */

linker_sizeStackSystem_C0   = (4K);                                                         /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                         /* Length of the First stack                                */

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackFirst_C0     = stm_stSRAM1;                                                  /* 0x20000000:                                              */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

linker_lowStackSystem_C0    = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x20000800:                                              */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0;                                                            /* 0x00000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (0);                                                          /* Length of the external memory                            */

linker_stUMemo              = (linker_stHeap + linker_lnHeap);                              /* 0x2001B000: UMemo, start of the user memory              */
linker_lnUMemo              = (20K);                                                        /* Length of the user memory                                */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = (linker_stPrgmData + linker_lnPrgmData);                      /* 0x20014000: start of the heap                            */
linker_lnHeap               = (28K);                                                        /* Length of the heap                                       */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = stm_stINTFLASH;                                               /* 0x08000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = stm_lnINTFLASH;                                               /* Length of the the Flash                                  */

linker_stPrgmData           = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;         /* 0x20001800: PrgmData, start of the RAM                   */
linker_lnPrgmData           = (74K);                                                        /* Length of the RAM                                        */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v7 MPU regions             */
/* for the arm_v7 MPU the regions have to be 32-B aligned   */

linker_ST_FLASH_INT_0       = stm_stINTFLASH;                                               /* 0x08000000: Privileged/User FLASH                        */
linker_SZ_FLASH_INT_0       = 19;                                                           /* 1-M = 2^(SZ + 1), SZ = log2(1-M) - 1                     */

linker_ST_RAM_INT_0         = stm_stSRAM1;                                                  /* 0x20000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_0         = 16;                                                           /* 128-K = 2^(SZ + 1), SZ = log2(128-K) - 1                 */

MEMORY {
    prgm_code (rx)  : ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
    prgm_data (rwx) : ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE     system_p.ld
