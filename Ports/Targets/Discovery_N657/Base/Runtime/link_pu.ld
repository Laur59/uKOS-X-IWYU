/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Linker description for the uKOS-X system.
 *          Privileged / user support
 *
 *                     CODE
 * linker_stTEXT       +-----------------+
 *                     |                 |
 *                     | .isr_vector     |
 *                     | .text           |
 *                     | .rodata         |
 *                     |                 |
 * linker_enRODATA     +-----------------+
 * linker_stSignature  |                 |             DATA
 *                     +-----------------+ ........... +-----------------+ linker_stDATA_p
 *                     |                 |             |                 |
 *                     | .data_p         |             | .data_p         |
 *                     |                 |             |                 | linker_enDATA_p
 *                     |                 |             |                 | linker_stDATA_u
 *                     | .data_u         |             | .data_u         |
 *                     |                 |             |                 | linker_enDATA_u
 *                     +-----------------+ ........... +-----------------+
 *                                                     |                 | linker_stBSS_p
 *                                                     | .bss_p          |
 *                                                     | COMMON          |
 *                                                     |                 | linker_enBSS_p
 *                                                     |                 | linker_stBSS_u
 *                                                     | .bss_u          |
 *                                                     |                 | linker_enBSS_u
 *                                                     +-----------------+
 */

ENTRY(Reset_C0_Handler)

INCLUDE     STM32N657xD.ld

/* Mapping:                                                    */
/*                                                             */
/* SRAM2:    First Stage BootLoader 0x34100400 (400 signature) */
/*            └ 64K                                            */
/* SRAM1:    Signature           0x34000000                    */
/*            └ 1K                                             */
/*           Program Code        0x34000400                    */
/*            ├ (1024K - 1K)                                   */
/* SRAM2:     └ 776K             0x34100000                    */
/*           Stack System        0x341C2000  (Protected)       */
/*            └ 8K                                             */
/*           Program Data        0x341C4000  (Protected)       */
/*            └ 88K                                            */
/*           Stack First         0x341DA000  (User)            */
/*            └ 8K                                             */
/*           Program Data        0x341DC000  (User)            */
/*            ├ 144K                                           */
/* SRAM3:     └ 8K               0x34200000                    */
/*           Heap                0x34202000  (User)            */
/*            └ 256K                                           */
/*           Frame buffer        0x34242000  (User)            */
/*            ├ 184K                                           */
/* SRAM4:     ├ 448K             0x34270000                    */
/* SRAM5:     ├ 448K             0x342E0000                    */
/* SRAM6:     └ 448K             0x34350000                    */
/* APSRAM:   User Memory         0x90000000                    */
/*            └ 32M                                            */

linker_sizeStackSystem_C0   = (8K);                                                         /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (8K);                                                         /* Length of the First stack                                */
config_sizeData_p           = (88K);
config_sizeData_u           = (152K);
config_sizeUserMemory       = (32768K);
config_sizeHeap             = (256K);

stm_lnAXISRAM3_6            = (stm_lnAXISRAM3 + stm_lnAXISRAM4
                                + stm_lnAXISRAM5 + stm_lnAXISRAM6);                         /* Length of internal memory SRAM3 to SRAM6                 */

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackSystem_C0    = stm_stAXISRAM2;                                               /* 0x341C2000:                                              */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;     /* 0x341c3ff8                                               */

linker_lowStackFirst_C0     = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0
                                + config_sizeData_p;                                        /* 0x341DA000:                                              */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;       /* 0x341DBFF8                                               */

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0x90000000;                                                   /* 0x90000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (32 * 1024K);                                                 /* Length of the external memory                            */

linker_stUMemo              = 0x90000000;                                                   /* 0x90000000: UMemo, start of the user memory              */
linker_lnUMemo              = config_sizeUserMemory;                                        /* Length of the user memory                                */

linker_stExtFlash           = 0x70000000;                                                           /* 0x70000000: ExtFlash, start of the external flash memory */
linker_lnExtFlash           = (128 * 1024K);                                                        /* Length of the external flash memory                      */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = (linker_stPrgmData_u + linker_lnPrgmData_u);                  /* 0x34202000: start of the heap                            */
linker_lnHeap               = config_sizeHeap;                                              /* Length of the heap                                       */

linker_stLCD_F_BUFFER       = (linker_stHeap + linker_lnHeap);                              /* 0x34242000: Privileged/User LCD Frame Buffer             */
linker_lnLCD_F_BUFFER       = (1500K);                                                      /* 0x00177000: Length of the RAM                                        */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = (stm_stAXISRAM1 + 1K);                                        /* 0x34000400: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = (stm_lnAXISRAM1 - 1K);                                        /* Length of the the Flash                                  */

linker_stPrgmData_p         = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;         /* 0x341C2000: start of protected program data              */
linker_lnPrgmData_p         = config_sizeData_p;                                            /* Length of protected program data                         */

linker_stPrgmData_u         = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x341DA000: start of unprotected program data            */
linker_lnPrgmData_u         = config_sizeData_u;                                            /* Length of unprotected program data                       */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v8 MPU regions             */
/* for the arm_v8 MPU the regions have to be 32-B aligned   */

linker_ST_RAM_INT_1         = (stm_stAXISRAM1);                                             /* 0x34000000: Privileged/User RAM                          */
linker_EN_RAM_INT_1         = (stm_stAXISRAM1 + stm_lnAXISRAM1 - 1);                        /* 0x340FFFFF: 1-M                                          */

linker_ST_RAM_INT_2_OS      = stm_stAXISRAM2;                                               /* 0x341C2000: Privileged/User RAM                          */
linker_EN_RAM_INT_2_OS      = (stm_stAXISRAM2 + linker_sizeStackSystem_C0
                                + config_sizeData_p - 1);                                   /* 0x341D9FFF: 96-K                                         */

linker_ST_RAM_INT_2         = linker_lowStackFirst_C0;                                      /* 0x341DA000: Privileged/User RAM                          */
linker_EN_RAM_INT_2         = (linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 + config_sizeData_u
                                + config_sizeUserMemory + linker_lnHeap - 1);               /* 0x34241FFF: 2720-K                                       */

linker_ST_RAM_INT_3         = linker_stLCD_F_BUFFER;                                        /* 0x34242000: Privileged/User RAM                          */
linker_EN_RAM_INT_3         = (linker_stLCD_F_BUFFER + 1500K - 1);                          /* 0x343B8FFF: 1500-K                                       */

linker_ST_APSRAM            = linker_stUMemo;                                               /* 0x90000000: Privileged/User RAM                          */
linker_EN_APSRAM            = (linker_stUMemo + linker_lnUMemo - 1);                        /* 0x91FFFFFF: 32-M                                         */

linker_ST_OCTOFLASH         = linker_stExtFlash;                                            /* 0x70000000: Privileged/User RAM                          */
linker_EN_OCTOFLASH         = (linker_stExtFlash + linker_lnExtFlash - 1);                  /* 0x77FFFFFF: 128-M                                        */

linker_ST_PERIPH_SOC        = stm_stPERIPH_NS;                                              /* 0x40000000: Privileged PERIPHERALS                       */
linker_EN_PERIPH_SOC        = (stm_stPERIPH_NS + 524288K - 1);                              /* 0x5FFFFFFF: 2 x 256-M (_S & _NS)                         */

linker_ST_PERIPH_CORE       = stm_stCORE;                                                   /* 0xE0000000: Privileged core PERIPHERALS                  */
linker_EN_PERIPH_CORE       = (stm_stCORE + 262144K - 1);                                   /* 0xEFFFFFFF: 256-M                                        */

MEMORY {
    prgm_code (rwx)     : ORIGIN = linker_stPrgmCode,   LENGTH = linker_lnPrgmCode
    prgm_data_p (rwx)   : ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
    prgm_data_u (rwx)   : ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

ASSERT((linker_stPrgmData_p) >= (linker_ST_RAM_INT_2_OS), "Start address of data outside (below) protected region")
ASSERT((linker_stPrgmData_p) < (linker_EN_RAM_INT_2_OS), "Start address of data outside (above) protected region")
ASSERT((linker_stPrgmData_p + linker_lnPrgmData_p - 1) <= (linker_EN_RAM_INT_2_OS), "End address of data outside protected region")

INCLUDE     system_pu.ld
