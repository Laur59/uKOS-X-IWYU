/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Specs of STM32H743xI.
 *           References:
 *           - DS12110 Rev 10, p. 36 * Datasheet
 *           - RM0433 Rev 8, p. 131 * STM32H742, STM32H743/753 and STM32H750 Value line advanced Arm®-based 32-bit MCUs
 */

stm_stINTFLASH          = 0x08000000;                                               /* 0x08000000: starting address of internal flash of SOC    */
stm_lnINTFLASH          = (2048K);                                                  /* Size of internal flash                                   */

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
