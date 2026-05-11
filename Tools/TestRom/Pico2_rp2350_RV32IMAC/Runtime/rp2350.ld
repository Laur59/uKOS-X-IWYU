/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        Specs of rp2350J.
 *          References:
 *          - rp2350 Rev 1, p. 338 * Datasheet
 */

rp_stINTFLASH           = 0x10000000;                                               /* 0x10000000: Starting address of internal flash of SOC    */
rp_lnINTFLASH           = (4096K);                                                  /* Size of internal flash                                   */

/* Six SRAMs are embedded, each with specific features.     */

rp_stSRAM               = 0x20000000;                                               /* 0x20000000: Starting address of SRAM                     */
rp_lnSRAM1              = (520K);                                                   /* Length of internal memory SRAM                           */

rp_stPERIPH_NS          = 0x40000000;                                               /*                                                          */
rp_stPERIPH_S           = 0x50000000;                                               /*                                                          */
rp_lnPERIPH             = 0x20000000;                                               /*                                                          */
rp_stEXTERNAL           = 0x60000000;                                               /*                                                          */
rp_lnEXTERNAL           = 0x80000000;                                               /*                                                          */
rp_stCORE               = 0xE0000000;                                               /*                                                          */
rp_lnCORE               = 0x20000000;                                               /* Defined by the ARM cortex-M specification                */
