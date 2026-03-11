/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_syscfg.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_syscfg equates.
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

#pragma once

#include    <stdint.h>

// SYSCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    SECCFGR;
    volatile    uint32_t    CFGR1;
    volatile    uint32_t    FPUIMR;
    volatile    uint32_t    CNSLCKR;
    volatile    uint32_t    CSLOCKR;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    MESR;
    volatile    uint32_t    CCCSR;
    volatile    uint32_t    CCVR;
    volatile    uint32_t    CCCR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    RSSCMDR;
    volatile    uint32_t    RESERVED1[17];
    volatile    uint32_t    OTGHSPHYCR;
} SYSCFG_TypeDef;

#ifdef __cplusplus
#define SYSCFG_NS   reinterpret_cast<SYSCFG_TypeDef *>(0x46000400U)
#define SYSCFG_S    reinterpret_cast<SYSCFG_TypeDef *>(0x56000400U)

#else
#define SYSCFG_NS   ((SYSCFG_TypeDef *)0x46000400U)
#define SYSCFG_S    ((SYSCFG_TypeDef *)0x56000400U)
#endif

// SECCFGR Configuration

#define SYSCFG_SECCFGR_FPUSEC       (0x1U<<3)
#define SYSCFG_SECCFGR_CLASSBSEC    (0x1U<<1)
#define SYSCFG_SECCFGR_SYSCFGSEC    (0x1U<<0)

// CFGR1 Configuration

#define SYSCFG_CFGR1_BOOSTEN        (0x1U<<8)
#define SYSCFG_CFGR1_ANASWVDD       (0x1U<<9)
#define SYSCFG_CFGR1_PB6_FMP        (0x1U<<16)
#define SYSCFG_CFGR1_PB7_FMP        (0x1U<<17)
#define SYSCFG_CFGR1_PB8_FMP        (0x1U<<18)
#define SYSCFG_CFGR1_PB9_FMP        (0x1U<<19)
#define SYSCFG_CFGR1_ENDCAP         (0x3U<<24)
#define SYSCFG_CFGR1_ENDCAP_0       (0x1U<<24)

// FPUIMR Configuration

#define SYSCFG_FPUIMR_FPU_IE        (0x3FU<<0)
#define SYSCFG_FPUIMR_FPU_IE_0      (0x1U<<0)

// CNSLCKR Configuration

#define SYSCFG_CNSLCKR_LOCKNSMPU    (0x1U<<1)
#define SYSCFG_CNSLCKR_LOCKNSVTOR   (0x1U<<0)

// CSLOCKR Configuration

#define SYSCFG_CSLOCKR_LOCKSAU      (0x1U<<2)
#define SYSCFG_CSLOCKR_LOCKSMPU     (0x1U<<1)
#define SYSCFG_CSLOCKR_LOCKSVTAIRCR (0x1U<<0)

// CFGR2 Configuration

#define SYSCFG_CFGR2_CLL            (0x1U<<0)
#define SYSCFG_CFGR2_SPL            (0x1U<<1)
#define SYSCFG_CFGR2_PVDL           (0x1U<<2)
#define SYSCFG_CFGR2_ECCL           (0x1U<<3)

// MESR Configuration

#define SYSCFG_MESR_MCLR            (0x1U<<0)
#define SYSCFG_MESR_IPMEE           (0x1U<<16)

// CCCSR Configuration

#define SYSCFG_CCCSR_RDY3           (0x1U<<10)
#define SYSCFG_CCCSR_RDY2           (0x1U<<9)
#define SYSCFG_CCCSR_RDY1           (0x1U<<8)
#define SYSCFG_CCCSR_CS3            (0x1U<<5)
#define SYSCFG_CCCSR_EN3            (0x1U<<4)
#define SYSCFG_CCCSR_CS2            (0x1U<<3)
#define SYSCFG_CCCSR_EN2            (0x1U<<2)
#define SYSCFG_CCCSR_CS1            (0x1U<<1)
#define SYSCFG_CCCSR_EN1            (0x1U<<0)

// CCVR Configuration

#define SYSCFG_CCVR_PCV3            (0xFU<<20)
#define SYSCFG_CCVR_PCV3_0          (0x1U<<20)
#define SYSCFG_CCVR_NCV3            (0xFU<<16)
#define SYSCFG_CCVR_NCV3_0          (0x1U<<16)
#define SYSCFG_CCVR_PCV2            (0xFU<<12)
#define SYSCFG_CCVR_PCV2_0          (0x1U<<12)
#define SYSCFG_CCVR_NCV2            (0xFU<<8)
#define SYSCFG_CCVR_NCV2_0          (0x1U<<8)
#define SYSCFG_CCVR_PCV1            (0xFU<<4)
#define SYSCFG_CCVR_PCV1_0          (0x1U<<4)
#define SYSCFG_CCVR_NCV1            (0xFU<<0)
#define SYSCFG_CCVR_NCV1_0          (0x1U<<0)

// CCCR Configuration

#define SYSCFG_CCCR_PCC3            (0xFU<<20)
#define SYSCFG_CCCR_PCC3_0          (0x1U<<20)
#define SYSCFG_CCCR_NCC3            (0xFU<<16)
#define SYSCFG_CCCR_NCC3_0          (0x1U<<16)
#define SYSCFG_CCCR_PCC2            (0xFU<<12)
#define SYSCFG_CCCR_PCC2_0          (0x1U<<12)
#define SYSCFG_CCCR_NCC2            (0xFU<<8)
#define SYSCFG_CCCR_NCC2_0          (0x1U<<8)
#define SYSCFG_CCCR_PCC1            (0xFU<<4)
#define SYSCFG_CCCR_PCC1_0          (0x1U<<4)
#define SYSCFG_CCCR_NCC1            (0xFU<<0)
#define SYSCFG_CCCR_NCC1_0          (0x1U<<0)

// RSSCMDR Configuration

#define SYSCFG_RSSCMDR_RSSCMD       (0xFFFFU<<0)
#define SYSCFG_RSSCMDR_RSSCMD_0     (0x1U<<0)

// OTGHSPHYCR Configuration

#define SYSCFG_OTGHSPHYCR_CLKSEL    (0xFU<<2)
#define SYSCFG_OTGHSPHYCR_CLKSEL_0  (0x1U<<2)
#define SYSCFG_OTGHSPHYCR_PDCTRL    (0x1U<<1)
#define SYSCFG_OTGHSPHYCR_EN        (0x1U<<0)
