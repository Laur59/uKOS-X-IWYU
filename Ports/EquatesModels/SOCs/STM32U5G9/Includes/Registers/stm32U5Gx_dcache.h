/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_dcache.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_dcache equates.
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

// DCACHE address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    IER;
    volatile    uint32_t    FCR;
    volatile    uint32_t    RHMONR;
    volatile    uint32_t    RMMONR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    WHMONR;
    volatile    uint32_t    WMMONR;
    volatile    uint32_t    CMDRSADDRR;
    volatile    uint32_t    CMDREADDRR;
} DCACHE_TypeDef;

#ifdef __cplusplus
#define DCACHE1_NS  reinterpret_cast<DCACHE_TypeDef *>(0x40031400U)
#define DCACHE1_S   reinterpret_cast<DCACHE_TypeDef *>(0x50031400U)
#define DCACHE2_NS  reinterpret_cast<DCACHE_TypeDef *>(0x40031800U)
#define DCACHE2_S   reinterpret_cast<DCACHE_TypeDef *>(0x50031800U)

#else
#define DCACHE1_NS  ((DCACHE_TypeDef *)0x40031400U)
#define DCACHE1_S   ((DCACHE_TypeDef *)0x50031400U)
#define DCACHE2_NS  ((DCACHE_TypeDef *)0x40031800U)
#define DCACHE2_S   ((DCACHE_TypeDef *)0x50031800U)
#endif

// CR Configuration

#define DCACHE_CR_HBURST                    (0x1U<<31)
#define DCACHE_CR_WMISSMRST                 (0x1U<<23)
#define DCACHE_CR_WHITMRST                  (0x1U<<22)
#define DCACHE_CR_WMISSMEN                  (0x1U<<21)
#define DCACHE_CR_WHITMEN                   (0x1U<<20)
#define DCACHE_CR_RMISSMRST                 (0x1U<<19)
#define DCACHE_CR_RHITMRST                  (0x1U<<18)
#define DCACHE_CR_RMISSMEN                  (0x1U<<17)
#define DCACHE_CR_RHITMEN                   (0x1U<<16)
#define DCACHE_CR_STARTCMD                  (0x1U<<11)
#define DCACHE_CR_CACHECMD                  (0x7U<<8)
#define DCACHE_CR_CACHECMD_0                (0x1U<<8)
#define DCACHE_CR_CACHEINV                  (0x1U<<1)
#define DCACHE_CR_EN                        (0x1U<<0)

// SR Configuration

#define DCACHE_SR_CMDENDF                   (0x1U<<4)
#define DCACHE_SR_BUSYCMDF                  (0x1U<<3)
#define DCACHE_SR_ERRF                      (0x1U<<2)
#define DCACHE_SR_BSYENDF                   (0x1U<<1)
#define DCACHE_SR_BUSYF                     (0x1U<<0)

// IER Configuration

#define DCACHE_IER_CMDENDIE                 (0x1U<<4)
#define DCACHE_IER_ERRIE                    (0x1U<<2)
#define DCACHE_IER_BSYENDIE                 (0x1U<<1)

// FCR Configuration

#define DCACHE_FCR_CCMDENDF                 (0x1U<<4)
#define DCACHE_FCR_CERRF                    (0x1U<<2)
#define DCACHE_FCR_CBSYENDF                 (0x1U<<1)

// RHMONR Configuration

#define DCACHE_RHMONR_RHITMON               (0xFFFFFFFFU<<0)
#define DCACHE_RHMONR_RHITMON_0             (0x1U<<0)

// RMMONR Configuration

#define DCACHE_RMMONR_MRISSMON              (0xFFFFU<<0)
#define DCACHE_RMMONR_MRISSMON_0            (0x1U<<0)

// WHMONR Configuration

#define DCACHE_WHMONR_WHITMON               (0xFFFFFFFFU<<0)
#define DCACHE_WHMONR_WHITMON_0             (0x1U<<0)

// WMMONR Configuration

#define DCACHE_WMMONR_WMISSMON              (0xFFFFU<<0)
#define DCACHE_WMMONR_WMISSMON_0            (0x1U<<0)

// CMDRSADDRR Configuration

#define DCACHE_CMDRSADDRR_CMDSTARTADDR      (0xFFFFFFFU<<4)
#define DCACHE_CMDRSADDRR_CMDSTARTADDR_0    (0x1U<<4)

// CMDREADDRR Configuration

#define DCACHE_CMDREADDRR_CMDENDADDR        (0xFFFFFFFU<<4)
#define DCACHE_CMDREADDRR_CMDENDADDR_0      (0x1U<<4)
