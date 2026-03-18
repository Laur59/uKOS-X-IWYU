/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Specs of STM32F207xx.
 *           References:
 *           - DS6329 Rev 17, p. 67 * Datasheet
 *           - RM0433 Rev 8, p. 59 * STM32F205xx, STM32F207x, STM32F215xx and STM32F217xx advanced Arm®-based 32-bit MCUs
 */

stm_stINTFLASH          = 0x08000000;                                               /* 0x08000000: starting address of internal flash of SOC    */
stm_lnINTFLASH          = (1024K);                                                  /* Size of internal flash                                   */

stm_stSRAM1             = 0x20000000;                                               /* 0x20000000: Starting address of SRAM1                    */
stm_lnSRAM1             = (112K);                                                   /* Length of internal memory SRAM1                          */

stm_stSRAM2             = 0x2001C000;                                               /* 0x2001C000: Starting address of SRAM2                    */
stm_lnSRAM2             = (16K);                                                    /* Length of internal memory SRAM2                          */
stm_lnSRAM12            = (stm_lnSRAM1 + stm_lnSRAM2);

stm_stPERIPH            = 0x40000000;                                               /*                                                          */
stm_lnPERIPH            = 0x20000000;                                               /*                                                          */
stm_stCORE              = 0xE0000000;                                               /*                                                          */
stm_lnCORE              = 0x20000000;                                               /* Defined by the ARM cortex-M specification                */
