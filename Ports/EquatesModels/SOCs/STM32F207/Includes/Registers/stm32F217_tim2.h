/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_tim2 equates.
 */

#pragma once

#include    <stdint.h>

// TIM2 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    SMCR;
    volatile    uint32_t    DIER;
    volatile    uint32_t    SR;
    volatile    uint32_t    EGR;
    volatile    uint32_t    CCMR1;
    volatile    uint32_t    CCMR2;
    volatile    uint32_t    CCER;
    volatile    uint32_t    CNT;
    volatile    uint32_t    PSC;
    volatile    uint32_t    ARR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    CCR2;
    volatile    uint32_t    CCR3;
    volatile    uint32_t    CCR4;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    DCR;
    volatile    uint32_t    DMAR;
    volatile    uint32_t    OR;
} TIM2_TypeDef;

#ifdef __cplusplus
#define TIM2    reinterpret_cast<TIM2_TypeDef *>(0x40000000U)

#else
#define TIM2    ((TIM2_TypeDef *)0x40000000U)
#endif

// CR1 Configuration

#define TIM2_CR1_CEN        (0x1U<<0)
#define TIM2_CR1_UDIS       (0x1U<<1)
#define TIM2_CR1_URS        (0x1U<<2)
#define TIM2_CR1_OPM        (0x1U<<3)
#define TIM2_CR1_DIR        (0x1U<<4)
#define TIM2_CR1_CMS        (0x3U<<5)
#define TIM2_CR1_CMS_0      (0x1U<<5)
#define TIM2_CR1_ARPE       (0x1U<<7)
#define TIM2_CR1_CKD        (0x3U<<8)
#define TIM2_CR1_CKD_0      (0x1U<<8)

// CR2 Configuration

#define TIM2_CR2_CCDS       (0x1U<<3)
#define TIM2_CR2_MMS        (0x7U<<4)
#define TIM2_CR2_MMS_0      (0x1U<<4)
#define TIM2_CR2_TI1S       (0x1U<<7)

// SMCR Configuration

#define TIM2_SMCR_SMS       (0x7U<<0)
#define TIM2_SMCR_SMS_0     (0x1U<<0)
#define TIM2_SMCR_TS        (0x7U<<4)
#define TIM2_SMCR_TS_0      (0x1U<<4)
#define TIM2_SMCR_MSM       (0x1U<<7)
#define TIM2_SMCR_ETF       (0xFU<<8)
#define TIM2_SMCR_ETF_0     (0x1U<<8)
#define TIM2_SMCR_ETPS      (0x3U<<12)
#define TIM2_SMCR_ETPS_0    (0x1U<<12)
#define TIM2_SMCR_ECE       (0x1U<<14)
#define TIM2_SMCR_ETP       (0x1U<<15)

// DIER Configuration

#define TIM2_DIER_UIE       (0x1U<<0)
#define TIM2_DIER_CC1IE     (0x1U<<1)
#define TIM2_DIER_CC2IE     (0x1U<<2)
#define TIM2_DIER_CC3IE     (0x1U<<3)
#define TIM2_DIER_CC4IE     (0x1U<<4)
#define TIM2_DIER_TIE       (0x1U<<6)
#define TIM2_DIER_UDE       (0x1U<<8)
#define TIM2_DIER_CC1DE     (0x1U<<9)
#define TIM2_DIER_CC2DE     (0x1U<<10)
#define TIM2_DIER_CC3DE     (0x1U<<11)
#define TIM2_DIER_CC4DE     (0x1U<<12)
#define TIM2_DIER_TDE       (0x1U<<14)

// SR Configuration

#define TIM2_SR_UIF         (0x1U<<0)
#define TIM2_SR_CC1IF       (0x1U<<1)
#define TIM2_SR_CC2IF       (0x1U<<2)
#define TIM2_SR_CC3IF       (0x1U<<3)
#define TIM2_SR_CC4IF       (0x1U<<4)
#define TIM2_SR_TIF         (0x1U<<6)
#define TIM2_SR_CC1OF       (0x1U<<9)
#define TIM2_SR_CC2OF       (0x1U<<10)
#define TIM2_SR_CC3OF       (0x1U<<11)
#define TIM2_SR_CC4OF       (0x1U<<12)

// EGR Configuration

#define TIM2_EGR_UG         (0x1U<<0)
#define TIM2_EGR_CC1G       (0x1U<<1)
#define TIM2_EGR_CC2G       (0x1U<<2)
#define TIM2_EGR_CC3G       (0x1U<<3)
#define TIM2_EGR_CC4G       (0x1U<<4)
#define TIM2_EGR_TG         (0x1U<<6)

// CCMR1 Configuration

#define TIM2_CCMR1_CC1S     (0x3U<<0)
#define TIM2_CCMR1_CC1S_0   (0x1U<<0)
#define TIM2_CCMR1_OC1FE    (0x1U<<2)
#define TIM2_CCMR1_OC1PE    (0x1U<<3)
#define TIM2_CCMR1_OC1M     (0x7U<<4)
#define TIM2_CCMR1_OC1M_0   (0x1U<<4)
#define TIM2_CCMR1_OC1CE    (0x1U<<7)
#define TIM2_CCMR1_CC2S     (0x3U<<8)
#define TIM2_CCMR1_CC2S_0   (0x1U<<8)
#define TIM2_CCMR1_OC2FE    (0x1U<<10)
#define TIM2_CCMR1_OC2PE    (0x1U<<11)
#define TIM2_CCMR1_OC2M     (0x7U<<12)
#define TIM2_CCMR1_OC2M_0   (0x1U<<12)
#define TIM2_CCMR1_OC2CE    (0x1U<<15)

// CCMR2 Configuration

#define TIM2_CCMR2_CC3S     (0x3U<<0)
#define TIM2_CCMR2_CC3S_0   (0x1U<<0)
#define TIM2_CCMR2_OC3FE    (0x1U<<2)
#define TIM2_CCMR2_OC3PE    (0x1U<<3)
#define TIM2_CCMR2_OC3M     (0x7U<<4)
#define TIM2_CCMR2_OC3M_0   (0x1U<<4)
#define TIM2_CCMR2_OC3CE    (0x1U<<7)
#define TIM2_CCMR2_CC4S     (0x3U<<8)
#define TIM2_CCMR2_CC4S_0   (0x1U<<8)
#define TIM2_CCMR2_OC4FE    (0x1U<<10)
#define TIM2_CCMR2_OC4PE    (0x1U<<11)
#define TIM2_CCMR2_OC4M     (0x7U<<12)
#define TIM2_CCMR2_OC4M_0   (0x1U<<12)
#define TIM2_CCMR2_OC4CE    (0x1U<<15)

// CCER Configuration

#define TIM2_CCER_CC1E      (0x1U<<0)
#define TIM2_CCER_CC1P      (0x1U<<1)
#define TIM2_CCER_CC1NP     (0x1U<<3)
#define TIM2_CCER_CC2E      (0x1U<<4)
#define TIM2_CCER_CC2P      (0x1U<<5)
#define TIM2_CCER_CC2NP     (0x1U<<7)
#define TIM2_CCER_CC3E      (0x1U<<8)
#define TIM2_CCER_CC3P      (0x1U<<9)
#define TIM2_CCER_CC3NP     (0x1U<<11)
#define TIM2_CCER_CC4E      (0x1U<<12)
#define TIM2_CCER_CC4P      (0x1U<<13)
#define TIM2_CCER_CC4NP     (0x1U<<15)

// CNT Configuration

#define TIM2_CNT_CNT_L      (0xFFFFU<<0)
#define TIM2_CNT_CNT_L_0    (0x1U<<0)
#define TIM2_CNT_CNT_H      (0xFFFFU<<16)
#define TIM2_CNT_CNT_H_0    (0x1U<<16)

// PSC Configuration

#define TIM2_PSC_PSC        (0xFFFFU<<0)
#define TIM2_PSC_PSC_0      (0x1U<<0)

// ARR Configuration

#define TIM2_ARR_ARR_L      (0xFFFFU<<0)
#define TIM2_ARR_ARR_L_0    (0x1U<<0)
#define TIM2_ARR_ARR_H      (0xFFFFU<<16)
#define TIM2_ARR_ARR_H_0    (0x1U<<16)

// CCR1 Configuration

#define TIM2_CCR1_CCR1_L    (0xFFFFU<<0)
#define TIM2_CCR1_CCR1_L_0  (0x1U<<0)
#define TIM2_CCR1_CCR1_H    (0xFFFFU<<16)
#define TIM2_CCR1_CCR1_H_0  (0x1U<<16)

// CCR2 Configuration

#define TIM2_CCR2_CCR2_L    (0xFFFFU<<0)
#define TIM2_CCR2_CCR2_L_0  (0x1U<<0)
#define TIM2_CCR2_CCR2_H    (0xFFFFU<<16)
#define TIM2_CCR2_CCR2_H_0  (0x1U<<16)

// CCR3 Configuration

#define TIM2_CCR3_CCR3_L    (0xFFFFU<<0)
#define TIM2_CCR3_CCR3_L_0  (0x1U<<0)
#define TIM2_CCR3_CCR3_H    (0xFFFFU<<16)
#define TIM2_CCR3_CCR3_H_0  (0x1U<<16)

// CCR4 Configuration

#define TIM2_CCR4_CCR4_L    (0xFFFFU<<0)
#define TIM2_CCR4_CCR4_L_0  (0x1U<<0)
#define TIM2_CCR4_CCR4_H    (0xFFFFU<<16)
#define TIM2_CCR4_CCR4_H_0  (0x1U<<16)

// DCR Configuration

#define TIM2_DCR_DBA        (0x1FU<<0)
#define TIM2_DCR_DBA_0      (0x1U<<0)
#define TIM2_DCR_DBL        (0x1FU<<8)
#define TIM2_DCR_DBL_0      (0x1U<<8)

// DMAR Configuration

#define TIM2_DMAR_DMAB      (0xFFFFU<<0)
#define TIM2_DMAR_DMAB_0    (0x1U<<0)

// OR Configuration

#define TIM2_OR_IT4_RMP     (0x3U<<6)
#define TIM2_OR_IT4_RMP_0   (0x1U<<6)
