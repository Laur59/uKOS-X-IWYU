/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_tim11 equates.
 */

#pragma once

#include    <stdint.h>

// TIM11 address definitions
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
} TIM11_TypeDef;

#ifdef __cplusplus
#define TIM11   reinterpret_cast<TIM11_TypeDef *>(0x40014800U)

#else
#define TIM11   ((TIM11_TypeDef *)0x40014800U)
#endif

// CR1 Configuration

#define TIM11_CR1_CEN       (0x1U<<0U)
#define TIM11_CR1_UDIS      (0x1U<<1U)
#define TIM11_CR1_URS       (0x1U<<2U)
#define TIM11_CR1_ARPE      (0x1U<<7U)
#define TIM11_CR1_CKD       (0x3U<<8U)
#define TIM11_CR1_CKD_0     (0x1U<<8U)

// DIER Configuration

#define TIM11_DIER_UIE      (0x1U<<0U)
#define TIM11_DIER_CC1IE    (0x1U<<1U)

// SR Configuration

#define TIM11_SR_UIF        (0x1U<<0U)
#define TIM11_SR_CC1IF      (0x1U<<1U)
#define TIM11_SR_CC1OF      (0x1U<<9U)

// EGR Configuration

#define TIM11_EGR_UG        (0x1U<<0U)
#define TIM11_EGR_CC1G      (0x1U<<1U)

// CCMR1 Configuration

#define TIM11_CCMR1_OC1M    (0x7U<<4U)
#define TIM11_CCMR1_OC1M_0  (0x1U<<4U)
#define TIM11_CCMR1_OC1PE   (0x1U<<3U)
#define TIM11_CCMR1_OC1FE   (0x1U<<2U)
#define TIM11_CCMR1_CC1S    (0x3U<<0U)
#define TIM11_CCMR1_CC1S_0  (0x1U<<0U)

// CCER Configuration

#define TIM11_CCER_CC1E     (0x1U<<0U)
#define TIM11_CCER_CC1P     (0x1U<<1U)
#define TIM11_CCER_CC1NP    (0x1U<<3U)

// CNT Configuration

#define TIM11_CNT_CNT       (0xFFFFU<<0U)
#define TIM11_CNT_CNT_0     (0x1U<<0U)

// PSC Configuration

#define TIM11_PSC_PSC       (0xFFFFU<<0U)
#define TIM11_PSC_PSC_0     (0x1U<<0U)

// ARR Configuration

#define TIM11_ARR_ARR       (0xFFFFU<<0U)
#define TIM11_ARR_ARR_0     (0x1U<<0U)

// CCR1 Configuration

#define TIM11_CCR1_CCR1     (0xFFFFU<<0U)
#define TIM11_CCR1_CCR1_0   (0x1U<<0U)

// OR Configuration

#define TIM11_OR_RMP        (0x3U<<0U)
#define TIM11_OR_RMP_0      (0x1U<<0U)
