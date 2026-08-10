/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_tim5 equates.
 */

#pragma once

#include    <stdint.h>

// TIM5 address definitions
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
    volatile    uint32_t    RESERVED2[4];
    volatile    uint32_t    AF1;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    TISEL;
} TIM5_TypeDef;

#ifdef __cplusplus
#define TIM5    reinterpret_cast<TIM5_TypeDef *>(0x40000C00U)

#else
#define TIM5    ((TIM5_TypeDef *)0x40000C00U)
#endif

// CR1 Configuration

#define TIM5_CR1_CEN        (0x1U<<0U)
#define TIM5_CR1_UDIS       (0x1U<<1U)
#define TIM5_CR1_URS        (0x1U<<2U)
#define TIM5_CR1_OPM        (0x1U<<3U)
#define TIM5_CR1_DIR        (0x1U<<4U)
#define TIM5_CR1_CMS        (0x3U<<5U)
#define TIM5_CR1_CMS_0      (0x1U<<5U)
#define TIM5_CR1_ARPE       (0x1U<<7U)
#define TIM5_CR1_CKD        (0x3U<<8U)
#define TIM5_CR1_CKD_0      (0x1U<<8U)
#define TIM5_CR1_UIFREMAP   (0x1U<<11U)

// CR2 Configuration

#define TIM5_CR2_CCDS       (0x1U<<3U)
#define TIM5_CR2_MMS        (0x7U<<4U)
#define TIM5_CR2_MMS_0      (0x1U<<4U)
#define TIM5_CR2_TI1S       (0x1U<<7U)

// SMCR Configuration

#define TIM5_SMCR_SMS       (0x7U<<0U)
#define TIM5_SMCR_SMS_0     (0x1U<<0U)
#define TIM5_SMCR_TS        (0x7U<<4U)
#define TIM5_SMCR_TS_0      (0x1U<<4U)
#define TIM5_SMCR_MSM       (0x1U<<7U)
#define TIM5_SMCR_ETF       (0xFU<<8U)
#define TIM5_SMCR_ETF_0     (0x1U<<8U)
#define TIM5_SMCR_ETPS      (0x3U<<12U)
#define TIM5_SMCR_ETPS_0    (0x1U<<12U)
#define TIM5_SMCR_ECE       (0x1U<<14U)
#define TIM5_SMCR_ETP       (0x1U<<15U)
#define TIM5_SMCR_SMS_3     (0x1U<<16U)
#define TIM5_SMCR_TS_4_3    (0x3U<<20U)
#define TIM5_SMCR_TS_4_3_0  (0x1U<<20U)

// DIER Configuration

#define TIM5_DIER_UIE       (0x1U<<0U)
#define TIM5_DIER_CC1IE     (0x1U<<1U)
#define TIM5_DIER_CC2IE     (0x1U<<2U)
#define TIM5_DIER_CC3IE     (0x1U<<3U)
#define TIM5_DIER_CC4IE     (0x1U<<4U)
#define TIM5_DIER_TIE       (0x1U<<6U)
#define TIM5_DIER_UDE       (0x1U<<8U)
#define TIM5_DIER_CC1DE     (0x1U<<9U)
#define TIM5_DIER_CC2DE     (0x1U<<10U)
#define TIM5_DIER_CC3DE     (0x1U<<11U)
#define TIM5_DIER_CC4DE     (0x1U<<12U)
#define TIM5_DIER_TDE       (0x1U<<14U)

// SR Configuration

#define TIM5_SR_UIF         (0x1U<<0U)
#define TIM5_SR_CC1IF       (0x1U<<1U)
#define TIM5_SR_CC2IF       (0x1U<<2U)
#define TIM5_SR_CC3IF       (0x1U<<3U)
#define TIM5_SR_CC4IF       (0x1U<<4U)
#define TIM5_SR_TIF         (0x1U<<6U)
#define TIM5_SR_CC1OF       (0x1U<<9U)
#define TIM5_SR_CC2OF       (0x1U<<10U)
#define TIM5_SR_CC3OF       (0x1U<<11U)
#define TIM5_SR_CC4OF       (0x1U<<12U)

// EGR Configuration

#define TIM5_EGR_UG         (0x1U<<0U)
#define TIM5_EGR_CC1G       (0x1U<<1U)
#define TIM5_EGR_CC2G       (0x1U<<2U)
#define TIM5_EGR_CC3G       (0x1U<<3U)
#define TIM5_EGR_CC4G       (0x1U<<4U)
#define TIM5_EGR_TG         (0x1U<<6U)

// CCMR1 Configuration

#define TIM5_CCMR1_OC2M_3   (0x1U<<24U)
#define TIM5_CCMR1_OC1M_3   (0x1U<<16U)
#define TIM5_CCMR1_OC2CE    (0x1U<<15U)
#define TIM5_CCMR1_OC2M     (0x7U<<12U)
#define TIM5_CCMR1_OC2M_0   (0x1U<<12U)
#define TIM5_CCMR1_OC2PE    (0x1U<<11U)
#define TIM5_CCMR1_OC2FE    (0x1U<<10U)
#define TIM5_CCMR1_CC2S     (0x3U<<8U)
#define TIM5_CCMR1_CC2S_0   (0x1U<<8U)
#define TIM5_CCMR1_OC1CE    (0x1U<<7U)
#define TIM5_CCMR1_OC1M     (0x7U<<4U)
#define TIM5_CCMR1_OC1M_0   (0x1U<<4U)
#define TIM5_CCMR1_OC1PE    (0x1U<<3U)
#define TIM5_CCMR1_OC1FE    (0x1U<<2U)
#define TIM5_CCMR1_CC1S     (0x3U<<0U)
#define TIM5_CCMR1_CC1S_0   (0x1U<<0U)

// CCMR2 Configuration

#define TIM5_CCMR2_CC3S     (0x3U<<0U)
#define TIM5_CCMR2_CC3S_0   (0x1U<<0U)
#define TIM5_CCMR2_OC3FE    (0x1U<<2U)
#define TIM5_CCMR2_OC3PE    (0x1U<<3U)
#define TIM5_CCMR2_OC3M     (0x7U<<4U)
#define TIM5_CCMR2_OC3M_0   (0x1U<<4U)
#define TIM5_CCMR2_OC3CE    (0x1U<<7U)
#define TIM5_CCMR2_CC4S     (0x3U<<8U)
#define TIM5_CCMR2_CC4S_0   (0x1U<<8U)
#define TIM5_CCMR2_OC4FE    (0x1U<<10U)
#define TIM5_CCMR2_OC4PE    (0x1U<<11U)
#define TIM5_CCMR2_OC4M     (0x7U<<12U)
#define TIM5_CCMR2_OC4M_0   (0x1U<<12U)
#define TIM5_CCMR2_OC4CE    (0x1U<<15U)
#define TIM5_CCMR2_OC3M_3   (0x1U<<16U)
#define TIM5_CCMR2_OC4M_3   (0x1U<<24U)

// CCER Configuration

#define TIM5_CCER_CC1E      (0x1U<<0U)
#define TIM5_CCER_CC1P      (0x1U<<1U)
#define TIM5_CCER_CC1NP     (0x1U<<3U)
#define TIM5_CCER_CC2E      (0x1U<<4U)
#define TIM5_CCER_CC2P      (0x1U<<5U)
#define TIM5_CCER_CC2NP     (0x1U<<7U)
#define TIM5_CCER_CC3E      (0x1U<<8U)
#define TIM5_CCER_CC3P      (0x1U<<9U)
#define TIM5_CCER_CC3NP     (0x1U<<11U)
#define TIM5_CCER_CC4E      (0x1U<<12U)
#define TIM5_CCER_CC4P      (0x1U<<13U)
#define TIM5_CCER_CC4NP     (0x1U<<15U)

// CNT Configuration

#define TIM5_CNT_CNT_H      (0xFFFFU<<16U)
#define TIM5_CNT_CNT_H_0    (0x1U<<16U)
#define TIM5_CNT_CNT_L      (0xFFFFU<<0U)
#define TIM5_CNT_CNT_L_0    (0x1U<<0U)

// PSC Configuration

#define TIM5_PSC_PSC        (0xFFFFU<<0U)
#define TIM5_PSC_PSC_0      (0x1U<<0U)

// ARR Configuration

#define TIM5_ARR_ARR_L      (0xFFFFU<<0U)
#define TIM5_ARR_ARR_L_0    (0x1U<<0U)
#define TIM5_ARR_ARR_H      (0xFFFFU<<16U)
#define TIM5_ARR_ARR_H_0    (0x1U<<16U)

// CCR1 Configuration

#define TIM5_CCR1_CCR1_L    (0xFFFFU<<0U)
#define TIM5_CCR1_CCR1_L_0  (0x1U<<0U)
#define TIM5_CCR1_CCR1_H    (0xFFFFU<<16U)
#define TIM5_CCR1_CCR1_H_0  (0x1U<<16U)

// CCR2 Configuration

#define TIM5_CCR2_CCR2_L    (0xFFFFU<<0U)
#define TIM5_CCR2_CCR2_L_0  (0x1U<<0U)
#define TIM5_CCR2_CCR2_H    (0xFFFFU<<16U)
#define TIM5_CCR2_CCR2_H_0  (0x1U<<16U)

// CCR3 Configuration

#define TIM5_CCR3_CCR3_L    (0xFFFFU<<0U)
#define TIM5_CCR3_CCR3_L_0  (0x1U<<0U)
#define TIM5_CCR3_CCR3_H    (0xFFFFU<<16U)
#define TIM5_CCR3_CCR3_H_0  (0x1U<<16U)

// CCR4 Configuration

#define TIM5_CCR4_CCR4_L    (0xFFFFU<<0U)
#define TIM5_CCR4_CCR4_L_0  (0x1U<<0U)
#define TIM5_CCR4_CCR4_H    (0xFFFFU<<16U)
#define TIM5_CCR4_CCR4_H_0  (0x1U<<16U)

// DCR Configuration

#define TIM5_DCR_DBA        (0x1FU<<0U)
#define TIM5_DCR_DBA_0      (0x1U<<0U)
#define TIM5_DCR_DBL        (0x1FU<<8U)
#define TIM5_DCR_DBL_0      (0x1U<<8U)

// DMAR Configuration

#define TIM5_DMAR_DMAB      (0xFFFFU<<0U)
#define TIM5_DMAR_DMAB_0    (0x1U<<0U)

// AF1 Configuration

#define TIM5_AF1_ETRSEL     (0xFU<<14U)
#define TIM5_AF1_ETRSEL_0   (0x1U<<14U)

// TISEL Configuration

#define TIM5_TISEL_TI4SEL   (0xFU<<24U)
#define TIM5_TISEL_TI4SEL_0 (0x1U<<24U)
#define TIM5_TISEL_TI3SEL   (0xFU<<16U)
#define TIM5_TISEL_TI3SEL_0 (0x1U<<16U)
#define TIM5_TISEL_TI2SEL   (0xFU<<8U)
#define TIM5_TISEL_TI2SEL_0 (0x1U<<8U)
#define TIM5_TISEL_TI1SEL   (0xFU<<0U)
#define TIM5_TISEL_TI1SEL_0 (0x1U<<0U)
