/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_N657 – Linker memory regions, privileged-only mode.
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

INCLUDE     STM32N657xD.ld

/* Mapping:                                                 */
/*                                                          */
/* SRAM2:    First Stage BootLoader 0x34100400 (400 signature) */
/*            └ 64K                                         */
/* SRAM1:    Signature           0x34000000                 */
/*            └ 1K                                          */
/*           Program Code        0x34000400                 */
/*            └ (1024K - 1K)                                */
/* SRAM2:    Stack System        0x34100000                 */
/*            └ 8K                                          */
/*           Stack First         0x34102000                 */
/*            └ 8K                                          */
/*           Program Data        0x34104000                 */
/*            └ 240K                                        */
/*           User Memory         0x34140000                 */
/*            └ 512K                                        */
/*           Heap                0x341C0000                 */
/*            ├ 256K                                        */
/* SRAM3:     ├ 448K             0x34200000                 */
/* SRAM4:     ├ 448K             0x34270000                 */
/* SRAM5:     ├ 448K             0x342E0000                 */
/* SRAM6:     └ 448K             0x34350000                 */

linker_sizeStackSystem_C0   = (8K);                                                         /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (8K);                                                         /* Length of the First stack                                */
config_sizeData             = (240K);
config_sizeUserMemory       = (512K);
config_sizeHeapS2           = stm_lnAXISRAM2 - linker_sizeStackSystem_C0 - linker_sizeStackFirst_C0
                                - config_sizeData - config_sizeUserMemory;

stm_lnAXISRAM3_6            = (stm_lnAXISRAM3 + stm_lnAXISRAM4 + stm_lnAXISRAM5 + stm_lnAXISRAM6);  /* Length of internal memory SRAM3 to SRAM6                 */

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackFirst_C0     = stm_stAXISRAM2;                                               /* 0x34100000:                                              */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;       /* 0x34103FF8:                                              */

linker_lowStackSystem_C0    = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x34100000:                                              */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;     /* 0x34101FF8:                                              */

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0;                                                            /* 0x00000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (0);                                                          /* Length of the external memory                            */

linker_stUMemo              = (linker_stPrgmData + linker_lnPrgmData);                      /* 0x34140000: UMemo, start of the user memory              */
linker_lnUMemo              = config_sizeUserMemory;                                        /* Length of the user memory                                */

linker_stExtFlash           = 0x70000000;                                                   /* 0x70000000: ExtFlash, start of the external flash memory */
linker_lnExtFlash           = (128 * 1024K);                                                /* Length of the external flash memory                      */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = (linker_stUMemo + linker_lnUMemo);                            /* 0x341C0000: start of the heap                            */
linker_lnHeap               = (config_sizeHeapS2 + stm_lnAXISRAM3_6);                       /* Length of the heap                                       */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = (stm_stAXISRAM1 + 1K);                                        /* 0x34000400: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = (stm_lnAXISRAM1 - 1K);                                        /* Length of the the Flash                                  */

linker_stPrgmData           = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x34104000: start of program data                        */
linker_lnPrgmData           = config_sizeData;                                              /* Length of program data                                   */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v8 MPU regions             */
/* for the arm_v8 MPU the regions have to be 32-B aligned   */

linker_ST_RAM_INT_1         = (stm_stAXISRAM1);                                             /* 0x34000000: Privileged/User RAM                          */
linker_EN_RAM_INT_1         = (stm_stAXISRAM1 + stm_lnAXISRAM1 - 1);                        /* 0x340FFFFF: 1-M                                          */

linker_ST_RAM_INT_2         = (stm_stAXISRAM2);                                             /* 0x34100000: Privileged/User RAM                          */
linker_EN_RAM_INT_2         = (stm_stAXISRAM2 + stm_lnAXISRAM2 + stm_lnAXISRAM3_6 - 1);     /* 0x343BFFFF: 2816-K                                       */

linker_ST_OCTOFLASH         = linker_stExtFlash;                                            /* 0x70000000: Privileged/User RAM                          */
linker_EN_OCTOFLASH         = (linker_stExtFlash + linker_lnExtFlash - 1);                  /* 0x77FFFFFF: 128-M                                        */

MEMORY {
    prgm_code (rwx) : ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
    prgm_data (rwx) : ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE     system_p.ld
