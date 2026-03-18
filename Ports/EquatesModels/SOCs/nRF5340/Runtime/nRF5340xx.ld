/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Specs of STM32U5A5xJ.
 *           References:
 *           - nRF5340 Rev 1.3, p. 21 * Product Specification
 */

nrf_stINTFLASH_APP      = 0x00000000;                                               /* 0x00000000: Starting address of internal flash APP       */
nrf_lnINTFLASH_APP      = (1024K);                                                  /* Size of memory bank APP                                  */
nrf_stINTFLASH_NET      = 0x01000000;                                               /* 0x01000000: Starting address of internal flash NET       */
nrf_lnINTFLASH_NET      = (256K);                                                   /* Size of memory bank NET                                  */

nrf_stSRAM              = 0x20000000;                                               /* 0x20000000: Starting address of SRAM (APP + NET)         */
nrf_lnSRAM              = (512K);                                                   /* Length of internal memory SRAM                           */

nrf_stSRAM_NET          = 0x21000000;                                               /* 0x21000000: Starting address of SRAM_NET                 */
nrf_lnSRAM_NET          = (64K);                                                    /* Length of internal memory SRAM_NET                       */

nrf_stPERIPH_NS         = 0x40000000;                                               /*                                                          */
nrf_stPERIPH_S          = 0x50000000;                                               /*                                                          */
nrf_lnPERIPH            = 0x10000000;                                               /*                                                          */
nrf_stCORE              = 0xE0000000;                                               /*                                                          */
nrf_lnCORE              = 0x20000000;                                               /* Defined by the ARM cortex-M specification                */
