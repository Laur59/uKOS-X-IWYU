/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * DevKit_nRF5340 – Linker memory regions, privileged-only mode.
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

INCLUDE     nRF5340xx.ld

/* Mapping:                                                 */
/*                                                          */
/* RAM:      Stacks              0x20000000                 */
/*            └ 6K                                          */
/*           Program Data        0x20001800                 */
/*            └ 122K                                        */
/*           Heap                0x20020000                 */
/*            └ 256K                                        */
/*           User Memory         0x20060000                 */
/*            └ 64K                                         */
/*           For NET cpu         0x20070000                 */
/*            └ 32K                                         */
/*           Share               0x20078000                 */
/*            └ 32K                                         */

linker_sizeStackSystem_C0   = (4K);                                                             /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                             /* Length of the First stack                                */
config_sizeData             = (122K);
config_sizeUserMemory       = (64K);

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackFirst_C0     = nrf_stSRAM;                                                       /* 0x20000000:                                              */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

linker_lowStackSystem_C0    = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;               /* 0x20000800:                                              */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0;                                                                /* 0x00000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (0);                                                              /* Length of the external memory                            */

linker_stUMemo              = (linker_stHeap + linker_lnHeap);                                  /* 0x20060000: UMemo, start of the user memory              */
linker_lnUMemo              = config_sizeUserMemory;                                            /* Length of the user memory                                */

linker_stFoNet              = (linker_stUMemo + linker_lnUMemo);                                /* 0x20070000: Share, start of the multicore shared memory  */
linker_lnFNet               = (32K);                                                            /* Length of the user multicore shared memory               */

linker_stShare              = (linker_stFoNet + linker_lnFNet);                                 /* 0x20078000: Share, start of the multicore shared memory  */
linker_lnShare              = (32K);                                                            /* Length of the user multicore shared memory               */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = (linker_stPrgmData + linker_lnPrgmData);                          /* 0x20020000: start of the heap                            */
linker_lnHeap               = (256K);                                                           /* Length of the heap                                       */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = nrf_stINTFLASH_APP;                                               /* 0x00000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = nrf_lnINTFLASH_APP;                                               /* Length of the the Flash                                  */

linker_stPrgmData           = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;             /* 0x20001800: start of program data                        */
linker_lnPrgmData           = config_sizeData;                                                  /* Length of program data                                   */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v8 MPU regions             */
/* for the arm_v8 MPU the regions have to be 32-B aligned   */

linker_ST_FLASH_INT_0       = nrf_stINTFLASH_APP;                                               /* 0x00000000: Privileged/User FLASH                        */
linker_EN_FLASH_INT_0       = ((nrf_stINTFLASH_APP + nrf_lnINTFLASH_APP) - 1);                  /* 0x000FFFFF: 1-M                                          */

linker_ST_RAM_INT_0         = nrf_stSRAM;                                                       /* 0x20000000: Privileged/User RAM                          */
linker_EN_RAM_INT_0         = (nrf_stSRAM + nrf_lnSRAM - linker_lnFNet - linker_lnShare - 1);   /* 0x2006FFFF: 448-K                                        */

linker_ST_RAM_INT_0_SHARED  = linker_stShare;                                                   /* 0x20078000: Privileged/User RAM                          */
linker_EN_RAM_INT_0_SHARED  = (linker_stShare + linker_lnShare - 1);                            /* 0x2007FFFF: 32-K                                         */

MEMORY {
    prgm_code (rx)  : ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
    prgm_data (rwx) : ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE     system_p.ld
