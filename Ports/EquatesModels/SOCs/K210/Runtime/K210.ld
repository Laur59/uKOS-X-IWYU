/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Specs of K210.
 *           References:
 *           - K210 Technical Reference Manual Rev 1.x, p. 67
 */

k210_stSRAM_Cache           = 0x80000000;                                           /* 0x80000000: Starting address of SRAM                     */
k210_lnSRAM_Cache           = (6M);                                                 /* Length of internal memory SRAM1                          */

k210_stSRAM_AI_Cache        = 0x80600000;                                           /* 0x80600000: Starting address of SRAM                     */
k210_lnSRAM_AI_Cache        = (2M);                                                 /* Length of internal memory SRAM1                          */

k210_stSRAM                 = 0x40000000;                                           /* 0x40000000: Starting address of SRAM                     */
k210_lnSRAM                 = (6M);                                                 /* Length of internal memory SRAM1                          */

k210_stSRAM_AI              = 0x40600000;                                           /* 0x80400000: Starting address of SRAM                     */
k210_lnSRAM                 = (2M);                                                 /* Length of internal memory SRAM1                          */
