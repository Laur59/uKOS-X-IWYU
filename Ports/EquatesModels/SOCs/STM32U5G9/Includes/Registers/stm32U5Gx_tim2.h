/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_tim2 equates.
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
    volatile    uint32_t    RESERVED1[5];
    volatile    uint32_t    ECR;
    volatile    uint32_t    TISEL;
    volatile    uint32_t    AF1;
    volatile    uint32_t    AF2;
    volatile    uint32_t    RESERVED2[221];
    volatile    uint32_t    DCR;
    volatile    uint32_t    DMAR;
} TIM2_TypeDef;

#ifdef __cplusplus
#define TIM2_NS reinterpret_cast<TIM2_TypeDef *>(0x40000000U)
#define TIM2_S  reinterpret_cast<TIM2_TypeDef *>(0x50000000U)

#else
#define TIM2_NS ((TIM2_TypeDef *)0x40000000U)
#define TIM2_S  ((TIM2_TypeDef *)0x50000000U)
#endif

// CR1 Configuration

#define TIM2_CR1_CEN            (0x1U<<0U)
#define TIM2_CR1_UDIS           (0x1U<<1U)
#define TIM2_CR1_URS            (0x1U<<2U)
#define TIM2_CR1_OPM            (0x1U<<3U)
#define TIM2_CR1_DIR            (0x1U<<4U)
#define TIM2_CR1_CMS            (0x3U<<5U)
#define TIM2_CR1_CMS_0          (0x1U<<5U)
#define TIM2_CR1_ARPE           (0x1U<<7U)
#define TIM2_CR1_CKD            (0x3U<<8U)
#define TIM2_CR1_CKD_0          (0x1U<<8U)
#define TIM2_CR1_UIFREMAP       (0x1U<<11U)
#define TIM2_CR1_DITHEN         (0x1U<<12U)

// CR2 Configuration

#define TIM2_CR2_CCDS           (0x1U<<3U)
#define TIM2_CR2_MMS            (0x7U<<4U)
#define TIM2_CR2_MMS_0          (0x1U<<4U)
#define TIM2_CR2_TI1S           (0x1U<<7U)
#define TIM2_CR2_MMS_3          (0x1U<<25U)

// SMCR Configuration

#define TIM2_SMCR_SMS           (0x7U<<0U)
#define TIM2_SMCR_SMS_0         (0x1U<<0U)
#define TIM2_SMCR_OCCS          (0x1U<<3U)
#define TIM2_SMCR_TS_2_0        (0x7U<<4U)
#define TIM2_SMCR_TS_2_0_0      (0x1U<<4U)
#define TIM2_SMCR_MSM           (0x1U<<7U)
#define TIM2_SMCR_ETF           (0xFU<<8U)
#define TIM2_SMCR_ETF_0         (0x1U<<8U)
#define TIM2_SMCR_ETPS          (0x3U<<12U)
#define TIM2_SMCR_ETPS_0        (0x1U<<12U)
#define TIM2_SMCR_ECE           (0x1U<<14U)
#define TIM2_SMCR_ETP           (0x1U<<15U)
#define TIM2_SMCR_SMS_BIT3      (0x1U<<16U)
#define TIM2_SMCR_TS_4_3        (0x3U<<20U)
#define TIM2_SMCR_TS_4_3_0      (0x1U<<20U)
#define TIM2_SMCR_SMSPE         (0x1U<<24U)
#define TIM2_SMCR_SMSPS         (0x1U<<25U)

// DIER Configuration

#define TIM2_DIER_UIE           (0x1U<<0U)
#define TIM2_DIER_CC1IE         (0x1U<<1U)
#define TIM2_DIER_CC2IE         (0x1U<<2U)
#define TIM2_DIER_CC3IE         (0x1U<<3U)
#define TIM2_DIER_CC4IE         (0x1U<<4U)
#define TIM2_DIER_TIE           (0x1U<<6U)
#define TIM2_DIER_UDE           (0x1U<<8U)
#define TIM2_DIER_CC1DE         (0x1U<<9U)
#define TIM2_DIER_CC2DE         (0x1U<<10U)
#define TIM2_DIER_CC3DE         (0x1U<<11U)
#define TIM2_DIER_CC4DE         (0x1U<<12U)
#define TIM2_DIER_TDE           (0x1U<<14U)
#define TIM2_DIER_IDXIE         (0x1U<<20U)
#define TIM2_DIER_DIRIE         (0x1U<<21U)
#define TIM2_DIER_IERRIE        (0x1U<<22U)
#define TIM2_DIER_TERRIE        (0x1U<<23U)

// SR Configuration

#define TIM2_SR_UIF             (0x1U<<0U)
#define TIM2_SR_CC1IF           (0x1U<<1U)
#define TIM2_SR_CC2IF           (0x1U<<2U)
#define TIM2_SR_CC3IF           (0x1U<<3U)
#define TIM2_SR_CC4IF           (0x1U<<4U)
#define TIM2_SR_TIF             (0x1U<<6U)
#define TIM2_SR_CC1OF           (0x1U<<9U)
#define TIM2_SR_CC2OF           (0x1U<<10U)
#define TIM2_SR_CC3OF           (0x1U<<11U)
#define TIM2_SR_CC4OF           (0x1U<<12U)
#define TIM2_SR_IDXF            (0x1U<<20U)
#define TIM2_SR_DIRF            (0x1U<<21U)
#define TIM2_SR_IERRF           (0x1U<<22U)
#define TIM2_SR_TERRF           (0x1U<<23U)

// EGR Configuration

#define TIM2_EGR_UG             (0x1U<<0U)
#define TIM2_EGR_CC1G           (0x1U<<1U)
#define TIM2_EGR_CC2G           (0x1U<<2U)
#define TIM2_EGR_CC3G           (0x1U<<3U)
#define TIM2_EGR_CC4G           (0x1U<<4U)
#define TIM2_EGR_TG             (0x1U<<6U)

// CCMR1 Configuration

#define TIM2_CCMR1_CC1S         (0x3U<<0U)
#define TIM2_CCMR1_CC1S_0       (0x1U<<0U)
#define TIM2_CCMR1_OC1FE        (0x1U<<2U)
#define TIM2_CCMR1_OC1PE        (0x1U<<3U)
#define TIM2_CCMR1_OC1M         (0x7U<<4U)
#define TIM2_CCMR1_OC1M_0       (0x1U<<4U)
#define TIM2_CCMR1_OC1CE        (0x1U<<7U)
#define TIM2_CCMR1_CC2S         (0x3U<<8U)
#define TIM2_CCMR1_CC2S_0       (0x1U<<8U)
#define TIM2_CCMR1_OC2FE        (0x1U<<10U)
#define TIM2_CCMR1_OC2PE        (0x1U<<11U)
#define TIM2_CCMR1_OC2M         (0x7U<<12U)
#define TIM2_CCMR1_OC2M_0       (0x1U<<12U)
#define TIM2_CCMR1_OC2CE        (0x1U<<15U)
#define TIM2_CCMR1_OC1M_BIT3    (0x1U<<16U)
#define TIM2_CCMR1_OC2M_BIT3    (0x1U<<24U)

// CCMR2 Configuration

#define TIM2_CCMR2_CC3S         (0x3U<<0U)
#define TIM2_CCMR2_CC3S_0       (0x1U<<0U)
#define TIM2_CCMR2_OC3FE        (0x1U<<2U)
#define TIM2_CCMR2_OC3PE        (0x1U<<3U)
#define TIM2_CCMR2_OC3M         (0x7U<<4U)
#define TIM2_CCMR2_OC3M_0       (0x1U<<4U)
#define TIM2_CCMR2_OC3CE        (0x1U<<7U)
#define TIM2_CCMR2_CC4S         (0x3U<<8U)
#define TIM2_CCMR2_CC4S_0       (0x1U<<8U)
#define TIM2_CCMR2_OC4FE        (0x1U<<10U)
#define TIM2_CCMR2_OC4PE        (0x1U<<11U)
#define TIM2_CCMR2_OC4M         (0x7U<<12U)
#define TIM2_CCMR2_OC4M_0       (0x1U<<12U)
#define TIM2_CCMR2_OC4CE        (0x1U<<15U)
#define TIM2_CCMR2_OC3M_BIT3    (0x1U<<16U)
#define TIM2_CCMR2_OC4M_BIT3    (0x1U<<24U)

// CCER Configuration

#define TIM2_CCER_CC1E          (0x1U<<0U)
#define TIM2_CCER_CC1P          (0x1U<<1U)
#define TIM2_CCER_CC1NP         (0x1U<<3U)
#define TIM2_CCER_CC2E          (0x1U<<4U)
#define TIM2_CCER_CC2P          (0x1U<<5U)
#define TIM2_CCER_CC2NP         (0x1U<<7U)
#define TIM2_CCER_CC3E          (0x1U<<8U)
#define TIM2_CCER_CC3P          (0x1U<<9U)
#define TIM2_CCER_CC3NP         (0x1U<<11U)
#define TIM2_CCER_CC4E          (0x1U<<12U)
#define TIM2_CCER_CC4P          (0x1U<<13U)
#define TIM2_CCER_CC4NP         (0x1U<<15U)

// CNT Configuration

#define TIM2_CNT_CNT_BIT31      (0x1U<<31U)
#define TIM2_CNT_CNT_L          (0xFFFFU<<0U)
#define TIM2_CNT_CNT_L_0        (0x1U<<0U)
#define TIM2_CNT_CNT_H          (0x7FFFU<<16U)
#define TIM2_CNT_CNT_H_0        (0x1U<<16U)

// PSC Configuration

#define TIM2_PSC_PSC            (0xFFFFU<<0U)
#define TIM2_PSC_PSC_0          (0x1U<<0U)

// ARR Configuration

#define TIM2_ARR_ARR_L          (0xFFFFU<<0U)
#define TIM2_ARR_ARR_L_0        (0x1U<<0U)
#define TIM2_ARR_ARR_H          (0xFFFFU<<16U)
#define TIM2_ARR_ARR_H_0        (0x1U<<16U)

// CCR1 Configuration

#define TIM2_CCR1_CCR1_L        (0xFFFFU<<0U)
#define TIM2_CCR1_CCR1_L_0      (0x1U<<0U)
#define TIM2_CCR1_CCR1_H        (0xFFFFU<<16U)
#define TIM2_CCR1_CCR1_H_0      (0x1U<<16U)

// CCR2 Configuration

#define TIM2_CCR2_CCR2_L        (0xFFFFU<<0U)
#define TIM2_CCR2_CCR2_L_0      (0x1U<<0U)
#define TIM2_CCR2_CCR2_H        (0xFFFFU<<16U)
#define TIM2_CCR2_CCR2_H_0      (0x1U<<16U)

// CCR3 Configuration

#define TIM2_CCR3_CCR3_L        (0xFFFFU<<0U)
#define TIM2_CCR3_CCR3_L_0      (0x1U<<0U)
#define TIM2_CCR3_CCR3_H        (0xFFFFU<<16U)
#define TIM2_CCR3_CCR3_H_0      (0x1U<<16U)

// CCR4 Configuration

#define TIM2_CCR4_CCR4_L        (0xFFFFU<<0U)
#define TIM2_CCR4_CCR4_L_0      (0x1U<<0U)
#define TIM2_CCR4_CCR4_H        (0xFFFFU<<16U)
#define TIM2_CCR4_CCR4_H_0      (0x1U<<16U)

// ECR Configuration

#define TIM2_ECR_IE             (0x1U<<0U)
#define TIM2_ECR_IDIR           (0x3U<<1U)
#define TIM2_ECR_IDIR_0         (0x1U<<1U)
#define TIM2_ECR_FIDX           (0x1U<<5U)
#define TIM2_ECR_IPOS           (0x3U<<6U)
#define TIM2_ECR_IPOS_0         (0x1U<<6U)
#define TIM2_ECR_PW             (0xFFU<<16U)
#define TIM2_ECR_PW_0           (0x1U<<16U)
#define TIM2_ECR_PWPRSC         (0x7U<<24U)
#define TIM2_ECR_PWPRSC_0       (0x1U<<24U)

// TISEL Configuration

#define TIM2_TISEL_TI1SEL       (0xFU<<0U)
#define TIM2_TISEL_TI1SEL_0     (0x1U<<0U)
#define TIM2_TISEL_TI2SEL       (0xFU<<8U)
#define TIM2_TISEL_TI2SEL_0     (0x1U<<8U)
#define TIM2_TISEL_TI3SEL       (0xFU<<16U)
#define TIM2_TISEL_TI3SEL_0     (0x1U<<16U)
#define TIM2_TISEL_TI4SEL       (0xFU<<24U)
#define TIM2_TISEL_TI4SEL_0     (0x1U<<24U)

// AF1 Configuration

#define TIM2_AF1_ETRSEL         (0xFU<<14U)
#define TIM2_AF1_ETRSEL_0       (0x1U<<14U)

// AF2 Configuration

#define TIM2_AF2_OCRSEL         (0x7U<<16U)
#define TIM2_AF2_OCRSEL_0       (0x1U<<16U)

// DCR Configuration

#define TIM2_DCR_DBA            (0x1FU<<0U)
#define TIM2_DCR_DBA_0          (0x1U<<0U)
#define TIM2_DCR_DBL            (0x1FU<<8U)
#define TIM2_DCR_DBL_0          (0x1U<<8U)
#define TIM2_DCR_DBSS           (0xFU<<16U)
#define TIM2_DCR_DBSS_0         (0x1U<<16U)

// DMAR Configuration

#define TIM2_DMAR_ETRSEL        (0xFFFFFFFFU<<0U)
#define TIM2_DMAR_ETRSEL_0      (0x1U<<0U)
