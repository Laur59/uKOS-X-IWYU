/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_application_dcnf.
; =========================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_application_dcnf equates.
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

// DCNF address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[264];
    volatile    uint32_t    CPUID;
    volatile    uint32_t    RESERVED1[7];
    volatile    uint32_t    EXTPERI0_PROTECT;
    volatile    uint32_t    RESERVED2[7];
    volatile    uint32_t    EXTRAM0_PROTECT;
    volatile    uint32_t    RESERVED3[7];
    volatile    uint32_t    EXTCODE0_PROTECT;
} DCNF_TypeDef;

#ifdef __cplusplus
#define DCNF_NS reinterpret_cast<DCNF_TypeDef *>(0x40000000U)
#define DCNF_S  reinterpret_cast<DCNF_TypeDef *>(0x50000000U)

#else
#define DCNF_NS ((DCNF_TypeDef *)0x40000000U)
#define DCNF_S  ((DCNF_TypeDef *)0x50000000U)
#endif

// CPUID Configuration

#define DCNF_CPUID_CPUID                        (0xFFU<<0)
#define DCNF_CPUID_CPUID_0                      (0x1U<<0)

// PROTECT Configuration

#define DCNF_EXTPERI_PROTECT_SLAVE0             (0x1U<<0)
#define DCNF_EXTPERI_PROTECT_SLAVE0_ALLOWED     (0x0U<<0)
#define DCNF_EXTPERI_PROTECT_SLAVE0_BLOCKED     (0x1U<<0)

// PROTECT Configuration

#define DCNF_EXTRAM_PROTECT_SLAVE7              (0x1U<<7)
#define DCNF_EXTRAM_PROTECT_SLAVE6              (0x1U<<6)
#define DCNF_EXTRAM_PROTECT_SLAVE5              (0x1U<<5)
#define DCNF_EXTRAM_PROTECT_SLAVE4              (0x1U<<4)
#define DCNF_EXTRAM_PROTECT_SLAVE3              (0x1U<<3)
#define DCNF_EXTRAM_PROTECT_SLAVE2              (0x1U<<2)
#define DCNF_EXTRAM_PROTECT_SLAVE1              (0x1U<<1)
#define DCNF_EXTRAM_PROTECT_SLAVE0              (0x1U<<0)
#define DCNF_EXTRAM_PROTECT_SLAVE7_ALLOWED      (0x0U<<7)
#define DCNF_EXTRAM_PROTECT_SLAVE7_BLOCKED      (0x1U<<7)
#define DCNF_EXTRAM_PROTECT_SLAVE6_ALLOWED      (0x0U<<6)
#define DCNF_EXTRAM_PROTECT_SLAVE6_BLOCKED      (0x1U<<6)
#define DCNF_EXTRAM_PROTECT_SLAVE5_ALLOWED      (0x0U<<5)
#define DCNF_EXTRAM_PROTECT_SLAVE5_BLOCKED      (0x1U<<5)
#define DCNF_EXTRAM_PROTECT_SLAVE4_ALLOWED      (0x0U<<4)
#define DCNF_EXTRAM_PROTECT_SLAVE4_BLOCKED      (0x1U<<4)
#define DCNF_EXTRAM_PROTECT_SLAVE3_ALLOWED      (0x0U<<3)
#define DCNF_EXTRAM_PROTECT_SLAVE3_BLOCKED      (0x1U<<3)
#define DCNF_EXTRAM_PROTECT_SLAVE2_ALLOWED      (0x0U<<2)
#define DCNF_EXTRAM_PROTECT_SLAVE2_BLOCKED      (0x1U<<2)
#define DCNF_EXTRAM_PROTECT_SLAVE1_ALLOWED      (0x0U<<1)
#define DCNF_EXTRAM_PROTECT_SLAVE1_BLOCKED      (0x1U<<1)
#define DCNF_EXTRAM_PROTECT_SLAVE0_ALLOWED      (0x0U<<0)
#define DCNF_EXTRAM_PROTECT_SLAVE0_BLOCKED      (0x1U<<0)

// PROTECT Configuration

#define DCNF_EXTCODE_PROTECT_SLAVE0             (0x1U<<0)
#define DCNF_EXTCODE_PROTECT_SLAVE0_ALLOWED     (0x0U<<0)
#define DCNF_EXTCODE_PROTECT_SLAVE0_BLOCKED     (0x1U<<0)
