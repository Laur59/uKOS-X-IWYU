/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Alastor_H743 – Linker memory regions, privileged/user mode.
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
 *                       +-----------------+ ........... +-----------------+ linker_stDATA_p
 * linker_stINDATA_p     |                 |             |                 |
 *                       | .data_p         |             | .data_p         |
 *                       |                 |             |                 | linker_enDATA_p
 * linker_stINDATA_u     |                 |             |                 | linker_stDATA_u
 *                       | .data_u         |             | .data_u         |
 *                       |                 |             |                 | linker_enDATA_u
 *                       +-----------------+ ........... +-----------------+
 *                                                       |                 | linker_stBSS_p
 *                                                       | .bss_p          |
 *                                                       | COMMON          |
 *                                                       |                 | linker_enBSS_p
 *                                                       |                 | linker_stBSS_u
 *                                                       | .bss_u          |
 *                                                       |                 | linker_enBSS_u
 *                                                       +-----------------+
 */

ENTRY(Reset_C0_Handler)

INCLUDE     STM32H743xI.ld

/* Mapping:                                                 */
/*                                                          */
/* RAM1:     Stack First         0x30000000  (User)         */
/*            └ 2K                                          */
/*           Program Data        0x30000800  (User)         */
/*            ├ 126K                                        */
/* RAM2:      ├ 128K             0x30020000  (User)         */
/* RAM3:      └  32K             0x30040000  (User)         */
/* RAM4:     Stack System        0x38000000  (Protected)    */
/*            └ 4K                                          */
/*           Program Data        0x38001000  (Protected)    */
/*            └ 60K                                         */
/* External: Heap                0x70000000  (User)         */
/*            └ 32768K                                      */
/*           User Memory         0x72000000  (User)         */
/*            └ 32768K                                      */

linker_sizeStackSystem_C0   = (4K);                                                         /* Length of stack 'System'                                 */
linker_sizeStackFirst_C0    = (2K);                                                         /* Length of stack 'First'                                  */
config_sizeData_u           = stm_lnSRAM123 - linker_sizeStackFirst_C0;
config_sizeData_p           = stm_lnSRAM4 - linker_sizeStackSystem_C0;
config_sizeHeap             = (32768K);

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackSystem_C0    = stm_stSRAM4;                                                  /* 0x38000000: start of stack 'System'                      */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;

linker_lowStackFirst_C0     = stm_stSRAM1;                                                  /* 0x30000000: start of stack 'First'                       */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0x70000000;                                                   /* 0x70000000: EXRAM, start of external memory              */
linker_lnEXRAM              = (65536K);                                                     /* Length of external memory IS42S16320F                    */

linker_stUMemo              = linker_stEXRAM + config_sizeHeap;                             /* 0x72000000: UMemo, start of user memory                  */
linker_lnUMemo              = linker_lnEXRAM - config_sizeHeap;                             /* Length of user memory                                    */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = linker_stEXRAM;                                               /* 0x70000000: start of the heap                            */
linker_lnHeap               = config_sizeHeap;                                              /* Length of the heap                                       */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = stm_stINTFLASH;                                               /* 0x08000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = stm_lnINTFLASH;                                               /* Length of the the Flash                                  */

linker_stPrgmData_p         = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;         /* 0x38001000: start of protected program data              */
linker_lnPrgmData_p         = config_sizeData_p;                                            /* Length of protected program data                         */

linker_stPrgmData_u         = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x30000800: start of unprotected program data            */
linker_lnPrgmData_u         = config_sizeData_u;                                            /* Length of unprotected program data                       */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v7 MPU regions             */
/* for the arm_v7 MPU the regions have to be 32-B aligned   */

linker_ST_FLASH_INT_0       = stm_stINTFLASH;                                               /* 0x08000000: Privileged/User FLASH                        */
linker_SZ_FLASH_INT_0       = 20;                                                           /* 2-M = 2^(SZ + 1), SZ = log2(2-M) - 1                     */

linker_ST_RAM_INT_0         = stm_stAXISRAM;                                                /* 0x24000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_0         = 18;                                                           /* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1                 */

linker_ST_RAM_INT_1         = stm_stSRAM1;                                                  /* 0x30000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_1         = 18;                                                           /* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1                 */
hex_SZ_RAM_INT_1            = (1 << (linker_SZ_RAM_INT_1+1));                               /* 512-K                                                    */

linker_ST_RAM_INT_2_OS      = stm_stSRAM4;                                                  /* 0x38000000: Privileged RAM                               */
linker_SZ_RAM_INT_2_OS      = 15;                                                           /* 64-K = 2^(SZ + 1), SZ = log2(64-K) - 1                   */
hex_SZ_RAM_INT_2_OS         = (1 << (linker_SZ_RAM_INT_2_OS+1));                            /* 64-K                                                     */

linker_ST_RAM_EXT_0         = linker_stEXRAM;                                               /* 0x70000000: Privileged/User RAM                          */
linker_SZ_RAM_EXT_0         = 25;                                                           /* 8-M = 2^(SZ + 1), SZ = log2(8-M) - 1                     */

linker_ST_PERIPH_SOC        = stm_stPERIPH;                                                 /* 0x40000000: Privileged PERIPHERALS                       */
linker_SZ_PERIPH_SOC        = 28;                                                           /* 512-M = 2^(SZ + 1), SZ = log2(512-M) - 1                 */

linker_ST_PERIPH_CORE       = stm_stCORE;                                                   /* 0xE0000000: Privileged PERIPHERALS                       */
linker_SZ_PERIPH_CORE       = 27;                                                           /* 256-M = 2^(SZ + 1), SZ = log2(256-M) - 1                 */

MEMORY {
    prgm_code (rx)      : ORIGIN = linker_stPrgmCode,   LENGTH = linker_lnPrgmCode
    prgm_data_p (rwx)   : ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
    prgm_data_u (rwx)   : ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

ASSERT((linker_sizeStackFirst_C0 + linker_sizeStackSystem_C0 + linker_lnPrgmData_p + linker_lnPrgmData_u) == (stm_lnSRAM123 + stm_lnSRAM4), "Check RAM mapping: over/under usage")
ASSERT((linker_stPrgmData_p) < (linker_ST_RAM_INT_2_OS + hex_SZ_RAM_INT_2_OS), "Start address of data outside protected region")
ASSERT((linker_stPrgmData_p + linker_lnPrgmData_p) <= (linker_ST_RAM_INT_2_OS + hex_SZ_RAM_INT_2_OS), "End address of data outside protected region")
ASSERT((linker_stPrgmData_u) >= (linker_ST_RAM_INT_1), "Start address of user data outside user region")
ASSERT((linker_stPrgmData_u + linker_lnPrgmData_u) <= (linker_ST_RAM_INT_1 + hex_SZ_RAM_INT_1), "End address of user data outside user region")

INCLUDE     system_pu.ld
