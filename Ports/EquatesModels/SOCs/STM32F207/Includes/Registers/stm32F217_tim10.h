/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_tim10 equates.
 */

#pragma once

#include    <stdint.h>

// TIM10 address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    DIER;
    volatile    uint32_t    SR;
    volatile    uint32_t    EGR;
    volatile    uint32_t    CCMR1;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CCER;
    volatile    uint32_t    CNT;
    volatile    uint32_t    PSC;
    volatile    uint32_t    ARR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    RESERVED3[6];
    volatile    uint32_t    OR;
} TIM10_TypeDef;

#ifdef __cplusplus
#define TIM10   reinterpret_cast<TIM10_TypeDef *>(0x40014400U)

#else
#define TIM10   ((TIM10_TypeDef *)0x40014400U)
#endif

// CR1 Configuration

#define TIM10_CR1_CEN       (0x1U<<0)
#define TIM10_CR1_UDIS      (0x1U<<1)
#define TIM10_CR1_URS       (0x1U<<2)
#define TIM10_CR1_ARPE      (0x1U<<7)
#define TIM10_CR1_CKD       (0x3U<<8)
#define TIM10_CR1_CKD_0     (0x1U<<8)

// DIER Configuration

#define TIM10_DIER_UIE      (0x1U<<0)
#define TIM10_DIER_CC1IE    (0x1U<<1)

// SR Configuration

#define TIM10_SR_UIF        (0x1U<<0)
#define TIM10_SR_CC1IF      (0x1U<<1)
#define TIM10_SR_CC1OF      (0x1U<<9)

// EGR Configuration

#define TIM10_EGR_UG        (0x1U<<0)
#define TIM10_EGR_CC1G      (0x1U<<1)

// CCMR1 Configuration

#define TIM10_CCMR1_OC1M    (0x7U<<4)
#define TIM10_CCMR1_OC1M_0  (0x1U<<4)
#define TIM10_CCMR1_OC1PE   (0x1U<<3)
#define TIM10_CCMR1_OC1FE   (0x1U<<2)
#define TIM10_CCMR1_CC1S    (0x3U<<0)
#define TIM10_CCMR1_CC1S_0  (0x1U<<0)

// CCER Configuration

#define TIM10_CCER_CC1E     (0x1U<<0)
#define TIM10_CCER_CC1P     (0x1U<<1)
#define TIM10_CCER_CC1NP    (0x1U<<3)

// CNT Configuration

#define TIM10_CNT_CNT       (0xFFFFU<<0)
#define TIM10_CNT_CNT_0     (0x1U<<0)

// PSC Configuration

#define TIM10_PSC_PSC       (0xFFFFU<<0)
#define TIM10_PSC_PSC_0     (0x1U<<0)

// ARR Configuration

#define TIM10_ARR_ARR       (0xFFFFU<<0)
#define TIM10_ARR_ARR_0     (0x1U<<0)

// CCR1 Configuration

#define TIM10_CCR1_CCR1     (0xFFFFU<<0)
#define TIM10_CCR1_CCR1_0   (0x1U<<0)

// OR Configuration

#define TIM10_OR_RMP        (0x3U<<0)
#define TIM10_OR_RMP_0      (0x1U<<0)
