/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H743_tim16.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H743_tim16 equates.
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

// TIM16 address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    DIER;
    volatile    uint32_t    SR;
    volatile    uint32_t    EGR;
    volatile    uint32_t    CCMR1;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CCER;
    volatile    uint32_t    CNT;
    volatile    uint32_t    PSC;
    volatile    uint32_t    ARR;
    volatile    uint32_t    RCR;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    BDTR;
    volatile    uint32_t    DCR;
    volatile    uint32_t    DMAR;
    volatile    uint32_t    RESERVED3[4];
    volatile    uint32_t    AF1;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    TISEL;
} TIM16_TypeDef;

#ifdef __cplusplus
#define TIM16   reinterpret_cast<TIM16_TypeDef *>(0x40014400U)

#else
#define TIM16   ((TIM16_TypeDef *)0x40014400U)
#endif

// CR1 Configuration

#define TIM16_CR1_UIFREMAP      (0x1U<<11)
#define TIM16_CR1_CKD           (0x3U<<8)
#define TIM16_CR1_CKD_0         (0x1U<<8)
#define TIM16_CR1_ARPE          (0x1U<<7)
#define TIM16_CR1_OPM           (0x1U<<3)
#define TIM16_CR1_URS           (0x1U<<2)
#define TIM16_CR1_UDIS          (0x1U<<1)
#define TIM16_CR1_CEN           (0x1U<<0)

// CR2 Configuration

#define TIM16_CR2_CCPC          (0x1U<<0)
#define TIM16_CR2_CCUS          (0x1U<<2)
#define TIM16_CR2_CCDS          (0x1U<<3)
#define TIM16_CR2_OIS1          (0x1U<<8)
#define TIM16_CR2_OIS1N         (0x1U<<9)

// DIER Configuration

#define TIM16_DIER_COMDE        (0x1U<<13)
#define TIM16_DIER_CC1DE        (0x1U<<9)
#define TIM16_DIER_UDE          (0x1U<<8)
#define TIM16_DIER_BIE          (0x1U<<7)
#define TIM16_DIER_COMIE        (0x1U<<5)
#define TIM16_DIER_CC1IE        (0x1U<<1)
#define TIM16_DIER_UIE          (0x1U<<0)

// SR Configuration

#define TIM16_SR_UIF            (0x1U<<0)
#define TIM16_SR_CC1IF          (0x1U<<1)
#define TIM16_SR_COMIF          (0x1U<<5)
#define TIM16_SR_BIF            (0x1U<<7)
#define TIM16_SR_CC1OF          (0x1U<<9)

// EGR Configuration

#define TIM16_EGR_UG            (0x1U<<0)
#define TIM16_EGR_CC1G          (0x1U<<1)
#define TIM16_EGR_COMG          (0x1U<<5)
#define TIM16_EGR_BG            (0x1U<<7)

// CCMR1 Configuration

#define TIM16_CCMR1_OC1M_3      (0x1U<<16)
#define TIM16_CCMR1_OC1M        (0x7U<<4)
#define TIM16_CCMR1_OC1M_0      (0x1U<<4)
#define TIM16_CCMR1_OC1PE       (0x1U<<3)
#define TIM16_CCMR1_OC1FE       (0x1U<<2)
#define TIM16_CCMR1_CC1S        (0x3U<<0)
#define TIM16_CCMR1_CC1S_0      (0x1U<<0)

// CCER Configuration

#define TIM16_CCER_CC1E         (0x1U<<0)
#define TIM16_CCER_CC1P         (0x1U<<1)
#define TIM16_CCER_CC1NE        (0x1U<<2)
#define TIM16_CCER_CC1NP        (0x1U<<3)

// CNT Configuration

#define TIM16_CNT_UIFCPY        (0x1U<<31)
#define TIM16_CNT_CNT           (0xFFFFU<<0)
#define TIM16_CNT_CNT_0         (0x1U<<0)

// PSC Configuration

#define TIM16_PSC_PSC           (0xFFFFU<<0)
#define TIM16_PSC_PSC_0         (0x1U<<0)

// ARR Configuration

#define TIM16_ARR_ARR           (0xFFFFU<<0)
#define TIM16_ARR_ARR_0         (0x1U<<0)

// RCR Configuration

#define TIM16_RCR_REP           (0xFFU<<0)
#define TIM16_RCR_REP_0         (0x1U<<0)

// CCR1 Configuration

#define TIM16_CCR1_CCR1         (0xFFFFU<<0)
#define TIM16_CCR1_CCR1_0       (0x1U<<0)

// BDTR Configuration

#define TIM16_BDTR_BKF          (0xFU<<16)
#define TIM16_BDTR_BKF_0        (0x1U<<16)
#define TIM16_BDTR_MOE          (0x1U<<15)
#define TIM16_BDTR_AOE          (0x1U<<14)
#define TIM16_BDTR_BKP          (0x1U<<13)
#define TIM16_BDTR_BKE          (0x1U<<12)
#define TIM16_BDTR_OSSR         (0x1U<<11)
#define TIM16_BDTR_OSSI         (0x1U<<10)
#define TIM16_BDTR_LOCK         (0x3U<<8)
#define TIM16_BDTR_LOCK_0       (0x1U<<8)
#define TIM16_BDTR_DTG          (0xFFU<<0)
#define TIM16_BDTR_DTG_0        (0x1U<<0)

// DCR Configuration

#define TIM16_DCR_DBA           (0x1FU<<0)
#define TIM16_DCR_DBA_0         (0x1U<<0)
#define TIM16_DCR_DBL           (0x1FU<<8)
#define TIM16_DCR_DBL_0         (0x1U<<8)

// DMAR Configuration

#define TIM16_DMAR_DMAB         (0xFFFFU<<0)
#define TIM16_DMAR_DMAB_0       (0x1U<<0)

// AF1 Configuration

#define TIM16_AF1_BKCMP2P       (0x1U<<11)
#define TIM16_AF1_BKCMP1P       (0x1U<<10)
#define TIM16_AF1_BKINP         (0x1U<<9)
#define TIM16_AF1_BKDFBK1E      (0x1U<<8)
#define TIM16_AF1_BKCMP2E       (0x1U<<2)
#define TIM16_AF1_BKCMP1E       (0x1U<<1)
#define TIM16_AF1_BKINE         (0x1U<<0)

// TISEL Configuration

#define TIM16_TISEL_TI1SEL      (0xFU<<0)
#define TIM16_TISEL_TI1SEL_0    (0x1U<<0)
