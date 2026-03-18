/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Specs of GD32VF103CBT.
 *           References:
 *           - GD32VF103 RISC-V 32-bit MCU Rev 1.2, p. 28 * User Manual
 */

gd_stINTFLASH           = 0x08000000;                                               /* 0x08000000: starting address of internal flash of SOC    */
gd_lnINTFLASH           = (128K);                                                   /* Size of internal flash                                   */

gd_stSRAM               = 0x20000000;                                               /* 0x20000000: Starting address of SRAM1                    */
gd_lnSRAM               = (32K);                                                    /* Length of internal memory SRAM1                          */
