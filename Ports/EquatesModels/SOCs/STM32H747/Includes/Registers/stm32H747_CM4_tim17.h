/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_tim17 equates.
 */

#pragma once

#include    <stdint.h>

// TIM17 address definitions
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
} TIM17_TypeDef;

#ifdef __cplusplus
#define TIM17   reinterpret_cast<TIM17_TypeDef *>(0x40014800U)

#else
#define TIM17   ((TIM17_TypeDef *)0x40014800U)
#endif

// CR1 Configuration

#define TIM17_CR1_UIFREMAP      (0x1U<<11)
#define TIM17_CR1_CKD           (0x3U<<8)
#define TIM17_CR1_CKD_0         (0x1U<<8)
#define TIM17_CR1_ARPE          (0x1U<<7)
#define TIM17_CR1_OPM           (0x1U<<3)
#define TIM17_CR1_URS           (0x1U<<2)
#define TIM17_CR1_UDIS          (0x1U<<1)
#define TIM17_CR1_CEN           (0x1U<<0)

// CR2 Configuration

#define TIM17_CR2_CCPC          (0x1U<<0)
#define TIM17_CR2_CCUS          (0x1U<<2)
#define TIM17_CR2_CCDS          (0x1U<<3)
#define TIM17_CR2_OIS1          (0x1U<<8)
#define TIM17_CR2_OIS1N         (0x1U<<9)

// DIER Configuration

#define TIM17_DIER_COMDE        (0x1U<<13)
#define TIM17_DIER_CC1DE        (0x1U<<9)
#define TIM17_DIER_UDE          (0x1U<<8)
#define TIM17_DIER_BIE          (0x1U<<7)
#define TIM17_DIER_COMIE        (0x1U<<5)
#define TIM17_DIER_CC1IE        (0x1U<<1)
#define TIM17_DIER_UIE          (0x1U<<0)

// SR Configuration

#define TIM17_SR_UIF            (0x1U<<0)
#define TIM17_SR_CC1IF          (0x1U<<1)
#define TIM17_SR_COMIF          (0x1U<<5)
#define TIM17_SR_BIF            (0x1U<<7)
#define TIM17_SR_CC1OF          (0x1U<<9)

// EGR Configuration

#define TIM17_EGR_UG            (0x1U<<0)
#define TIM17_EGR_CC1G          (0x1U<<1)
#define TIM17_EGR_COMG          (0x1U<<5)
#define TIM17_EGR_BG            (0x1U<<7)

// CCMR1 Configuration

#define TIM17_CCMR1_OC1M_3      (0x1U<<16)
#define TIM17_CCMR1_OC1M        (0x7U<<4)
#define TIM17_CCMR1_OC1M_0      (0x1U<<4)
#define TIM17_CCMR1_OC1PE       (0x1U<<3)
#define TIM17_CCMR1_OC1FE       (0x1U<<2)
#define TIM17_CCMR1_CC1S        (0x3U<<0)
#define TIM17_CCMR1_CC1S_0      (0x1U<<0)

// CCER Configuration

#define TIM17_CCER_CC1E         (0x1U<<0)
#define TIM17_CCER_CC1P         (0x1U<<1)
#define TIM17_CCER_CC1NE        (0x1U<<2)
#define TIM17_CCER_CC1NP        (0x1U<<3)

// CNT Configuration

#define TIM17_CNT_UIFCPY        (0x1U<<31)
#define TIM17_CNT_CNT           (0xFFFFU<<0)
#define TIM17_CNT_CNT_0         (0x1U<<0)

// PSC Configuration

#define TIM17_PSC_PSC           (0xFFFFU<<0)
#define TIM17_PSC_PSC_0         (0x1U<<0)

// ARR Configuration

#define TIM17_ARR_ARR           (0xFFFFU<<0)
#define TIM17_ARR_ARR_0         (0x1U<<0)

// RCR Configuration

#define TIM17_RCR_REP           (0xFFU<<0)
#define TIM17_RCR_REP_0         (0x1U<<0)

// CCR1 Configuration

#define TIM17_CCR1_CCR1         (0xFFFFU<<0)
#define TIM17_CCR1_CCR1_0       (0x1U<<0)

// BDTR Configuration

#define TIM17_BDTR_BKF          (0xFU<<16)
#define TIM17_BDTR_BKF_0        (0x1U<<16)
#define TIM17_BDTR_MOE          (0x1U<<15)
#define TIM17_BDTR_AOE          (0x1U<<14)
#define TIM17_BDTR_BKP          (0x1U<<13)
#define TIM17_BDTR_BKE          (0x1U<<12)
#define TIM17_BDTR_OSSR         (0x1U<<11)
#define TIM17_BDTR_OSSI         (0x1U<<10)
#define TIM17_BDTR_LOCK         (0x3U<<8)
#define TIM17_BDTR_LOCK_0       (0x1U<<8)
#define TIM17_BDTR_DTG          (0xFFU<<0)
#define TIM17_BDTR_DTG_0        (0x1U<<0)

// DCR Configuration

#define TIM17_DCR_DBA           (0x1FU<<0)
#define TIM17_DCR_DBA_0         (0x1U<<0)
#define TIM17_DCR_DBL           (0x1FU<<8)
#define TIM17_DCR_DBL_0         (0x1U<<8)

// DMAR Configuration

#define TIM17_DMAR_DMAB         (0xFFFFU<<0)
#define TIM17_DMAR_DMAB_0       (0x1U<<0)

// AF1 Configuration

#define TIM17_AF1_BKCMP2P       (0x1U<<11)
#define TIM17_AF1_BKCMP1P       (0x1U<<10)
#define TIM17_AF1_BKINP         (0x1U<<9)
#define TIM17_AF1_BKDFBK1E      (0x1U<<8)
#define TIM17_AF1_BKCMP2E       (0x1U<<2)
#define TIM17_AF1_BKCMP1E       (0x1U<<1)
#define TIM17_AF1_BKINE         (0x1U<<0)

// TISEL Configuration

#define TIM17_TISEL_TI1SEL      (0xFU<<0)
#define TIM17_TISEL_TI1SEL_0    (0x1U<<0)
