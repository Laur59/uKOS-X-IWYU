/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_tim15 equates.
 */

#pragma once

#include    <stdint.h>

// TIM15 address definitions
// -------------------------

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
    volatile    uint32_t    RCR;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    CCR2;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    BDTR;
    volatile    uint32_t    DCR;
    volatile    uint32_t    DMAR;
    volatile    uint32_t    RESERVED2[4];
    volatile    uint32_t    AF1;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    TISEL;
} TIM15_TypeDef;

#ifdef __cplusplus
#define TIM15   reinterpret_cast<TIM15_TypeDef *>(0x40014000U)

#else
#define TIM15   ((TIM15_TypeDef *)0x40014000U)
#endif

// CR1 Configuration

#define TIM15_CR1_UIFREMAP      (0x1U<<11U)
#define TIM15_CR1_CKD           (0x3U<<8U)
#define TIM15_CR1_CKD_0         (0x1U<<8U)
#define TIM15_CR1_ARPE          (0x1U<<7U)
#define TIM15_CR1_OPM           (0x1U<<3U)
#define TIM15_CR1_URS           (0x1U<<2U)
#define TIM15_CR1_UDIS          (0x1U<<1U)
#define TIM15_CR1_CEN           (0x1U<<0U)

// CR2 Configuration

#define TIM15_CR2_OIS2          (0x1U<<10U)
#define TIM15_CR2_OIS1N         (0x1U<<9U)
#define TIM15_CR2_OIS1          (0x1U<<8U)
#define TIM15_CR2_TI1S          (0x1U<<7U)
#define TIM15_CR2_MMS           (0x7U<<4U)
#define TIM15_CR2_MMS_0         (0x1U<<4U)
#define TIM15_CR2_CCDS          (0x1U<<3U)
#define TIM15_CR2_CCUS          (0x1U<<2U)
#define TIM15_CR2_CCPC          (0x1U<<0U)

// SMCR Configuration

#define TIM15_SMCR_TS_4_3       (0x3U<<20U)
#define TIM15_SMCR_TS_4_3_0     (0x1U<<20U)
#define TIM15_SMCR_SMS_3        (0x1U<<16U)
#define TIM15_SMCR_MSM          (0x1U<<7U)
#define TIM15_SMCR_TS_2_0       (0x7U<<4U)
#define TIM15_SMCR_TS_2_0_0     (0x1U<<4U)
#define TIM15_SMCR_SMS          (0x7U<<0U)
#define TIM15_SMCR_SMS_0        (0x1U<<0U)

// DIER Configuration

#define TIM15_DIER_TDE          (0x1U<<14U)
#define TIM15_DIER_COMDE        (0x1U<<13U)
#define TIM15_DIER_CC2DE        (0x1U<<10U)
#define TIM15_DIER_CC1DE        (0x1U<<9U)
#define TIM15_DIER_UDE          (0x1U<<8U)
#define TIM15_DIER_BIE          (0x1U<<7U)
#define TIM15_DIER_TIE          (0x1U<<6U)
#define TIM15_DIER_COMIE        (0x1U<<5U)
#define TIM15_DIER_CC2IE        (0x1U<<2U)
#define TIM15_DIER_CC1IE        (0x1U<<1U)
#define TIM15_DIER_UIE          (0x1U<<0U)

// SR Configuration

#define TIM15_SR_UIF            (0x1U<<0U)
#define TIM15_SR_CC1IF          (0x1U<<1U)
#define TIM15_SR_CC2IF          (0x1U<<2U)
#define TIM15_SR_COMIF          (0x1U<<5U)
#define TIM15_SR_TIF            (0x1U<<6U)
#define TIM15_SR_BIF            (0x1U<<7U)
#define TIM15_SR_CC1OF          (0x1U<<9U)
#define TIM15_SR_CC2OF          (0x1U<<10U)

// EGR Configuration

#define TIM15_EGR_UG            (0x1U<<0U)
#define TIM15_EGR_CC1G          (0x1U<<1U)
#define TIM15_EGR_CC2G          (0x1U<<2U)
#define TIM15_EGR_COMG          (0x1U<<5U)
#define TIM15_EGR_TG            (0x1U<<6U)
#define TIM15_EGR_BG            (0x1U<<7U)

// CCMR1 Configuration

#define TIM15_CCMR1_OC2M_3      (0x1U<<24U)
#define TIM15_CCMR1_OC1M_3      (0x1U<<16U)
#define TIM15_CCMR1_OC2M        (0x7U<<12U)
#define TIM15_CCMR1_OC2M_0      (0x1U<<12U)
#define TIM15_CCMR1_OC2PE       (0x1U<<11U)
#define TIM15_CCMR1_OC2FE       (0x1U<<10U)
#define TIM15_CCMR1_CC2S        (0x3U<<8U)
#define TIM15_CCMR1_CC2S_0      (0x1U<<8U)
#define TIM15_CCMR1_OC1M        (0x7U<<4U)
#define TIM15_CCMR1_OC1M_0      (0x1U<<4U)
#define TIM15_CCMR1_OC1PE       (0x1U<<3U)
#define TIM15_CCMR1_OC1FE       (0x1U<<2U)
#define TIM15_CCMR1_CC1S        (0x3U<<0U)
#define TIM15_CCMR1_CC1S_0      (0x1U<<0U)

// CCER Configuration

#define TIM15_CCER_CC1E         (0x1U<<0U)
#define TIM15_CCER_CC1P         (0x1U<<1U)
#define TIM15_CCER_CC1NE        (0x1U<<2U)
#define TIM15_CCER_CC1NP        (0x1U<<3U)
#define TIM15_CCER_CC2E         (0x1U<<4U)
#define TIM15_CCER_CC2P         (0x1U<<5U)
#define TIM15_CCER_CC2NP        (0x1U<<7U)

// CNT Configuration

#define TIM15_CNT_UIFCPY        (0x1U<<31U)
#define TIM15_CNT_CNT           (0xFFFFU<<0U)
#define TIM15_CNT_CNT_0         (0x1U<<0U)

// PSC Configuration

#define TIM15_PSC_PSC           (0xFFFFU<<0U)
#define TIM15_PSC_PSC_0         (0x1U<<0U)

// ARR Configuration

#define TIM15_ARR_ARR           (0xFFFFU<<0U)
#define TIM15_ARR_ARR_0         (0x1U<<0U)

// RCR Configuration

#define TIM15_RCR_REP           (0xFFU<<0U)
#define TIM15_RCR_REP_0         (0x1U<<0U)

// CCR1 Configuration

#define TIM15_CCR1_CCR1         (0xFFFFU<<0U)
#define TIM15_CCR1_CCR1_0       (0x1U<<0U)

// CCR2 Configuration

#define TIM15_CCR2_CCR2         (0xFFFFU<<0U)
#define TIM15_CCR2_CCR2_0       (0x1U<<0U)

// BDTR Configuration

#define TIM15_BDTR_BKF          (0xFU<<16U)
#define TIM15_BDTR_BKF_0        (0x1U<<16U)
#define TIM15_BDTR_DTG          (0xFFU<<0U)
#define TIM15_BDTR_DTG_0        (0x1U<<0U)
#define TIM15_BDTR_LOCK         (0x3U<<8U)
#define TIM15_BDTR_LOCK_0       (0x1U<<8U)
#define TIM15_BDTR_OSSI         (0x1U<<10U)
#define TIM15_BDTR_OSSR         (0x1U<<11U)
#define TIM15_BDTR_BKE          (0x1U<<12U)
#define TIM15_BDTR_BKP          (0x1U<<13U)
#define TIM15_BDTR_AOE          (0x1U<<14U)
#define TIM15_BDTR_MOE          (0x1U<<15U)

// DCR Configuration

#define TIM15_DCR_DBA           (0x1FU<<0U)
#define TIM15_DCR_DBA_0         (0x1U<<0U)
#define TIM15_DCR_DBL           (0x1FU<<8U)
#define TIM15_DCR_DBL_0         (0x1U<<8U)

// DMAR Configuration

#define TIM15_DMAR_DMAB         (0xFFFFU<<0U)
#define TIM15_DMAR_DMAB_0       (0x1U<<0U)

// AF1 Configuration

#define TIM15_AF1_BKCMP2P       (0x1U<<11U)
#define TIM15_AF1_BKCMP1P       (0x1U<<10U)
#define TIM15_AF1_BKINP         (0x1U<<9U)
#define TIM15_AF1_BKDF1BK0E     (0x1U<<8U)
#define TIM15_AF1_BKCMP2E       (0x1U<<2U)
#define TIM15_AF1_BKCMP1E       (0x1U<<1U)
#define TIM15_AF1_BKINE         (0x1U<<0U)

// TISEL Configuration

#define TIM15_TISEL_TI2SEL      (0xFU<<8U)
#define TIM15_TISEL_TI2SEL_0    (0x1U<<8U)
#define TIM15_TISEL_TI1SEL      (0xFU<<0U)
#define TIM15_TISEL_TI1SEL_0    (0x1U<<0U)
