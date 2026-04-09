/*
; STM32V873xJ.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Edo. Franzi     The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     Specs of STM32N657xx.
;           References:
;           - RM0499 Rev 1, p. 173; STM32V873xx Arm®-based 32-bit MCUs
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

stm_stINTFLASH          = 0x08000000;                                               /* 0x08000000: Starting address of internal flash of SOC    */
stm_lnINTFLASH          = (4096K);                                                  /* Size of internal flash                                   */

/* Eight SRAMs are embedded, each with specific features.                   */
/* SRAM1 to SRAM6 are the main SRAMs in the AXI domain.                     */
/* 192 Kbytes of AXI SRAM1, named AXI SRAM1 FLEX, can be shared with ITCM   */
/* Remaining 64 Kbytes of AXI SRAM1 is named AXI SRAM1 FIX                  */
/* 128 Kbytes of AXI SRAM6, named AXI SRAM6 FLEX, can be shared with DTCM   */
/* Remaining 128 Kbytes of AXI SRAM6 is named AXI SRAM6 FIX                 */
/* AHB SRAM1 and SRAM2 are SRAMs in the AHB domain                          */

stm_stSRAM1             = 0x38000000;                                               /* 0x38000000: Starting address of SRAM1                    */
stm_lnSRAM1             = (16K);                                                    /* Length of internal memory SRAM1                          */

stm_stSRAM2             = 0x38004000;                                               /* 0x38004000: Starting address of SRAM2                    */
stm_lnSRAM2             = (16K);                                                    /* Length of internal memory SRAM1                          */

stm_stAXISRAM1_FLEX     = 0x34000000;                                               /* 0x34000000: Starting address of SRAM1_FLEX               */
stm_lnAXISRAM1_FLEX     = (192K);                                                   /* Length of internal memory SRAM1_FLEX                     */

stm_stAXISRAM1_FIX      = 0x34030000;                                               /* 0x34030000: Starting address of SRAM1_FIX                */
stm_lnAXISRAM1_FIX      = (64K);                                                    /* Length of internal memory SRAM1_FIX                      */

stm_stAXISRAM2          = 0x34040000;                                               /* 0x34040000: Starting address of SRAM2                    */
stm_lnAXISRAM2          = (256K);                                                   /* Length of internal memory SRAM2                          */

stm_stAXISRAM3          = 0x34080000;                                               /* 0x34080000: Starting address of SRAM3                    */
stm_lnAXISRAM3          = (256K);                                                   /* Length of internal memory SRAM3                          */

stm_stAXISRAM4          = 0x340C0000;                                               /* 0x340C0000: Starting address of SRAM4                    */
stm_lnAXISRAM4          = (256K);                                                   /* Length of internal memory SRAM4                          */

stm_stAXISRAM5          = 0x34100000;                                               /* 0x34100000: Starting address of SRAM5                    */
stm_lnAXISRAM5          = (256K);                                                   /* Length of internal memory SRAM5                          */

stm_stAXISRAM6_FIX      = 0x34140000;                                               /* 0x34140000: Starting address of SRAM6_FIX                */
stm_lnAXISRAM6_FIX      = (128K);                                                   /* Length of internal memory SRAM6_FIX                      */

stm_stAXISRAM6_FLEX     = 0x34160000;                                               /* 0x34160000: Starting address of SRAM6_FLEX               */
stm_lnAXISRAM6_FLEX     = (128K);                                                   /* Length of internal memory SRAM6_FLEX                     */

stm_stPERIPH_NS         = 0x40000000;                                               /*                                                          */
stm_stPERIPH_S          = 0x50000000;                                               /*                                                          */
stm_lnPERIPH            = 0x10000000;                                               /*                                                          */
stm_stCORE              = 0xE0000000;                                               /*                                                          */
stm_lnCORE              = 0x20000000;                                               /* Defined by the ARM cortex-M specification                */
