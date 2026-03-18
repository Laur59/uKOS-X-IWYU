/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Specs of STM32N657xx.
 *           References:
 *           - RM0486 Rev 1, p. 162 * STM32N647/657xx Arm®-based 32-bit MCUs
 */

/* Six SRAMs are embedded, each with specific features.     */
/* AXISRAM1-6, are the main SRAMs.                          */
/* AXISRAM2 is in the SRAM used for the first boot          */

stm_stAXISRAM1          = 0x34000000;                                               /* 0x34000000: Starting address of SRAM1                    */
stm_lnAXISRAM1          = (1M);                                                     /* Length of internal memory SRAM1                          */

stm_stAXISRAM2          = 0x34100000;                                               /* 0x34100000: Starting address of SRAM1                    */
stm_lnAXISRAM2          = (1M);                                                     /* Length of internal memory SRAM1                          */

stm_stAXISRAM3          = 0x34200000;                                               /* 0x34200000: Starting address of SRAM1                    */
stm_lnAXISRAM3          = (448K);                                                   /* Length of internal memory SRAM1                          */

stm_stAXISRAM4          = 0x34270000;                                               /* 0x34270000: Starting address of SRAM1                    */
stm_lnAXISRAM4          = (448K);                                                   /* Length of internal memory SRAM1                          */

stm_stAXISRAM5          = 0x342E0000;                                               /* 0x342E0000: Starting address of SRAM1                    */
stm_lnAXISRAM5          = (448K);                                                   /* Length of internal memory SRAM1                          */

stm_stAXISRAM6          = 0x34350000;                                               /* 0x34350000: Starting address of SRAM1                    */
stm_lnAXISRAM6          = (448K);                                                   /* Length of internal memory SRAM1                          */

stm_stCACHEAXI          = 0x343C0000;                                               /* 0x343C0000: Starting address of SRAM1                    */
stm_lnCACHEAXI          = (256K);                                                   /* Length of internal memory SRAM1                          */

stm_stVENCRAM           = 0x34400000;                                               /* 0x34400000: Starting address of SRAM1                    */
stm_lnVENCRAM           = (256K);                                                   /* Length of internal memory SRAM1                          */

stm_stPERIPH_NS         = 0x40000000;                                               /*                                                          */
stm_stPERIPH_S          = 0x50000000;                                               /*                                                          */
stm_lnPERIPH            = 0x10000000;                                               /*                                                          */
stm_stCORE              = 0xE0000000;                                               /*                                                          */
stm_lnCORE              = 0x20000000;                                               /* Defined by the ARM cortex-M specification                */
