/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Specs of STM32L4R5xx.
 *           References:
 *           - DS12023 Rev 4, p. 20 * Datasheet
 *           - RM0432 Rev 6, p. 92 * STM32L4+ Serie advanced Arm®-based 32-bit MCUs
 */

stm_stINTFLASH          = 0x08000000;                                               /* 0x08000000: starting address of internal flash of SOC    */
stm_lnINTFLASH          = (1024K);                                                  /* Size of internal flash                                   */

stm_stSRAM1             = 0x20000000;                                               /* 0x20000000: Starting address of SRAM1                    */
stm_lnSRAM1             = (192K);                                                   /* Length of internal memory SRAM1                          */

stm_stSRAM2             = 0x20030000;                                               /* 0x20030000: Starting address of SRAM2                    */
stm_lnSRAM2             = (64K);                                                    /* Length of internal memory SRAM2                          */
stm_lnSRAM12            = (stm_lnSRAM1 + stm_lnSRAM2);

stm_stSRAM3             = 0x20040000;                                               /* 0x20040000: Starting address of SRAM3                    */
stm_lnSRAM3             = (384K);                                                   /* Length of internal memory SRAM3                          */
stm_lnSRAM123           = (stm_lnSRAM1 + stm_lnSRAM2 + stm_lnSRAM3);

stm_stPERIPH            = 0x40000000;                                               /*                                                          */
stm_lnPERIPH            = 0x20000000;                                               /*                                                          */
stm_stCORE              = 0xE0000000;                                               /*                                                          */
stm_lnCORE              = 0x20000000;                                               /* Defined by the ARM cortex-M specification                */
