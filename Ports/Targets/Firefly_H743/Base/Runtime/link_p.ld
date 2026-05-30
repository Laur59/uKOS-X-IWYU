/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:        Linker description for the uKOS-X system.
 *          Privileged only support
 *
 *                       CODE
 * linker_stTEXT        +-----------------+
 *                      |                 |
 *                      | .isr_vector     |
 *                      | .text           |
 *                      | .rodata         |
 * linker_enRODATA      |                 |
 *                      +-----------------+
 * linker_stSignature   |                 |             DATA
 *                      +-----------------+ ........... +-----------------+ linker_stDATA
 * linker_stINDATA      |                 |             |                 |
 *                      | .data           |             | .data           |
 *                      |                 |             |                 | linker_enDATA
 *                      +-----------------+ ........... +-----------------+
 *                                                      |                 | linker_stBSS
 *                                                      | .bss            |
 *                                                      | COMMON          |
 *                                                      |                 | linker_enBSS
 *                                                      +-----------------+
 */

ENTRY(Reset_C0_Handler)

INCLUDE     STM32H743xI.ld

/* Mapping:                                                 */
/*                                                          */
/* RAM1:     Stacks              0x30000000                 */
/*            └ 6K                                          */
/*           Program Data        0x30001800                 */
/*            ├ 122K                                        */
/* RAM2:      ├ 128K             0x30020000                 */
/* RAM3:      └  32K             0x30040000                 */
/* External: Heap                0x70000000                 */
/*            └ 8192K                                       */
/*           User Memory         0x70800000                 */
/*            └ 8192K                                       */
/*           Frame Buffer        0x71000000                 */
/*            └ 16384K                                      */

linker_sizeStackSystem_C0   = (4K);                                                 /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                 /* Length of the First stack                                */
config_sizeData             = stm_lnSRAM123 - linker_sizeStackSystem_C0 - linker_sizeStackFirst_C0;
config_sizeHeap             = (8192K);

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackFirst_C0     = stm_stSRAM1;                                                  /* 0x38000000: start of the First stack                     */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;       /* 0x380007F8                                               */

linker_lowStackSystem_C0    = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x38000800: start of the System stack                    */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;     /* 0x380017F8                                               */

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0x70000000;                                           /* 0x70000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (32768K);                                             /* Length of the external memory                            */

linker_stLCD_F_BUFFER       = 0x71000000;                                           /* 0x71000000: FrameBuffer, start of the graphic memory     */
linker_lnLCD_F_BUFFER       = (16384K);                                             /* Length of the graphic memory                             */

linker_stUMemo              = 0x70800000;                                           /* 0x70800000: UMemo, start of the user memory              */
linker_lnUMemo              = (8192K);                                              /* Length of the user memory                                */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = 0x70000000;                                           /* 0x70000000: start of the heap                            */
linker_lnHeap               = (8192K);                                              /* Length of the heap                                       */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = stm_stINTFLASH;                                       /* 0x08000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = stm_lnINTFLASH;                                       /* Length of the the Flash                                  */

linker_stPrgmData           = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;         /* 0x38001800: start of program data                        */
linker_lnPrgmData           = stm_lnSRAM123 - linker_sizeStackSystem_C0
                                - linker_sizeStackFirst_C0;                                 /* (58K) Length of program data                                 */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v7 MPU regions             */
/* for the arm_v7 MPU the regions have to be 32-B aligned   */

linker_ST_FLASH_INT_0       = stm_stINTFLASH;                                       /* 0x08000000: Privileged/User FLASH                        */
linker_SZ_FLASH_INT_0       = 20;                                                   /* 2-M = 2^(SZ + 1), SZ = log2(2-M) - 1                     */

linker_ST_RAM_INT_0         = stm_stAXISRAM;                                        /* 0x24000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_0         = 18;                                                   /* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1                 */

linker_ST_RAM_INT_1         = stm_stSRAM1;                                          /* 0x30000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_1         = 18;                                                   /* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1                 */

linker_ST_RAM_INT_2         = stm_stSRAM4;                                          /* 0x38000000: Privileged/User RAM                          */
linker_SZ_RAM_INT_2         = 15;                                                   /* 64-K = 2^(SZ + 1), SZ = log2(64-K) - 1                   */

linker_ST_RAM_EXT_0         = linker_stEXRAM;                                       /* 0x70000000: Privileged/User RAM                          */
linker_SZ_RAM_EXT_0         = 23;                                                   /* 32-M = 2^(SZ + 1), SZ = log2(32-M) - 1                   */

linker_ST_RAM_EXT_1         = linker_stLCD_F_BUFFER;                                /* 0x71000000: Privileged/User RAM (no cache)               */
linker_SZ_RAM_EXT_1         = 23;                                                   /* 16-M = 2^(SZ + 1), SZ = log2(16-M) - 1                   */

MEMORY {
    prgm_code (rx)  : ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
    prgm_data (rwx) : ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE     system_p.ld
