/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Specs of STM32H747xI.
 *           References:
 *           - DS12930 Rev 2, p. 23 * Datasheet
 *           - RM0399 Rev 4, p. 136 * STM32H745/755 and STM32H747/757 advanced Arm®-based 32-bit MCUs
 */

stm_stINTFLASH_CM7      = 0x08000000;                                               /* 0x08000000: Starting address of internal flash CM7       */
stm_lnINTFLASH_CM7      = (1024K);                                                  /* Size of memory bank CM7                                  */
stm_stINTFLASH_CM4      = 0x08100000;                                               /* 0x08100000: Starting address of internal flash CM4       */
stm_lnINTFLASH_CM4      = (1024K);                                                  /* Size of memory bank CM4                                  */

stm_stAXISRAM           = 0x24000000;                                               /* 0x24000000: Starting address of AXI SRAM                 */
stm_lnAXISRAM           = (512K);                                                   /* Length of internal memory AXI SRAM                       */

stm_stSRAM1             = 0x30000000;                                               /* 0x30000000: Starting address of SRAM1                    */
stm_lnSRAM1             = (128K);                                                   /* Length of internal memory SRAM1                          */

stm_stSRAM2             = 0x30020000;                                               /* 0x30020000: Starting address of SRAM2                    */
stm_lnSRAM2             = (128K);                                                   /* Length of internal memory SRAM2                          */
stm_lnSRAM12            = (stm_lnSRAM1 + stm_lnSRAM2);

stm_stSRAM3             = 0x30040000;                                               /* 0x30040000: Starting address of SRAM3                    */
stm_lnSRAM3             = (32K);                                                    /* Length of internal memory SRAM3                          */
stm_lnSRAM123           = (stm_lnSRAM12 + stm_lnSRAM3);

stm_stSRAM4             = 0x38000000;                                               /* 0x38000000: Starting address of SRAM4                    */
stm_lnSRAM4             = (64K);                                                    /* Length of internal memory SRAM4                          */

stm_stDTCMRAM           = 0x20000000;                                               /* 0x20000000: Starting address of DTCM-RAM                 */
stm_lnDTCMRAM           = (128K);                                                   /* Length of internal memory DTCM-RAM                       */

stm_stPERIPH            = 0x40000000;                                               /*                                                          */
stm_lnPERIPH            = 0x20000000;                                               /*                                                          */
stm_stCORE              = 0xE0000000;                                               /*                                                          */
stm_lnCORE              = 0x20000000;                                               /* Defined by the ARM cortex-M specification                */
