/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_tim9 equates.
 */

#pragma once

#include    <stdint.h>

// TIM9 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    SMCR;
    volatile    uint32_t    DIER;
    volatile    uint32_t    SR;
    volatile    uint32_t    EGR;
    volatile    uint32_t    CCMR1;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CCER;
    volatile    uint32_t    CNT;
    volatile    uint32_t    PSC;
    volatile    uint32_t    ARR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    CCR2;
} TIM9_TypeDef;

#ifdef __cplusplus
#define TIM9    reinterpret_cast<TIM9_TypeDef *>(0x40014000U)

#else
#define TIM9    ((TIM9_TypeDef *)0x40014000U)
#endif

// CR1 Configuration

#define TIM9_CR1_CEN        (0x1U<<0U)
#define TIM9_CR1_UDIS       (0x1U<<1U)
#define TIM9_CR1_URS        (0x1U<<2U)
#define TIM9_CR1_OPM        (0x1U<<3U)
#define TIM9_CR1_ARPE       (0x1U<<7U)
#define TIM9_CR1_CKD        (0x3U<<8U)
#define TIM9_CR1_CKD_0      (0x1U<<8U)

// CR2 Configuration

#define TIM9_CR2_MMS        (0x7U<<4U)
#define TIM9_CR2_MMS_0      (0x1U<<4U)

// SMCR Configuration

#define TIM9_SMCR_SMS       (0x7U<<0U)
#define TIM9_SMCR_SMS_0     (0x1U<<0U)
#define TIM9_SMCR_TS        (0x7U<<4U)
#define TIM9_SMCR_TS_0      (0x1U<<4U)
#define TIM9_SMCR_MSM       (0x1U<<7U)

// DIER Configuration

#define TIM9_DIER_UIE       (0x1U<<0U)
#define TIM9_DIER_CC1IE     (0x1U<<1U)
#define TIM9_DIER_CC2IE     (0x1U<<2U)
#define TIM9_DIER_TIE       (0x1U<<6U)

// SR Configuration

#define TIM9_SR_UIF         (0x1U<<0U)
#define TIM9_SR_CC1IF       (0x1U<<1U)
#define TIM9_SR_CC2IF       (0x1U<<2U)
#define TIM9_SR_TIF         (0x1U<<6U)
#define TIM9_SR_CC1OF       (0x1U<<9U)
#define TIM9_SR_CC2OF       (0x1U<<10U)

// EGR Configuration

#define TIM9_EGR_UG         (0x1U<<0U)
#define TIM9_EGR_CC1G       (0x1U<<1U)
#define TIM9_EGR_CC2G       (0x1U<<2U)
#define TIM9_EGR_TG         (0x1U<<6U)

// CCMR1 Configuration

#define TIM9_CCMR1_CC1S     (0x3U<<0U)
#define TIM9_CCMR1_CC1S_0   (0x1U<<0U)
#define TIM9_CCMR1_OC1FE    (0x1U<<2U)
#define TIM9_CCMR1_OC1PE    (0x1U<<3U)
#define TIM9_CCMR1_OC1M     (0x7U<<4U)
#define TIM9_CCMR1_OC1M_0   (0x1U<<4U)
#define TIM9_CCMR1_CC2S     (0x3U<<8U)
#define TIM9_CCMR1_CC2S_0   (0x1U<<8U)
#define TIM9_CCMR1_OC2FE    (0x1U<<10U)
#define TIM9_CCMR1_OC2PE    (0x1U<<11U)
#define TIM9_CCMR1_OC2M     (0x7U<<12U)
#define TIM9_CCMR1_OC2M_0   (0x1U<<12U)

// CCER Configuration

#define TIM9_CCER_CC1E      (0x1U<<0U)
#define TIM9_CCER_CC1P      (0x1U<<1U)
#define TIM9_CCER_CC1NP     (0x1U<<3U)
#define TIM9_CCER_CC2E      (0x1U<<4U)
#define TIM9_CCER_CC2P      (0x1U<<5U)
#define TIM9_CCER_CC2NP     (0x1U<<7U)

// CNT Configuration

#define TIM9_CNT_CNT        (0xFFFFU<<0U)
#define TIM9_CNT_CNT_0      (0x1U<<0U)

// PSC Configuration

#define TIM9_PSC_PSC        (0xFFFFU<<0U)
#define TIM9_PSC_PSC_0      (0x1U<<0U)

// ARR Configuration

#define TIM9_ARR_ARR        (0xFFFFU<<0U)
#define TIM9_ARR_ARR_0      (0x1U<<0U)

// CCR1 Configuration

#define TIM9_CCR1_CCR1      (0xFFFFU<<0U)
#define TIM9_CCR1_CCR1_0    (0x1U<<0U)

// CCR2 Configuration

#define TIM9_CCR2_CCR2      (0xFFFFU<<0U)
#define TIM9_CCR2_CCR2_0    (0x1U<<0U)
