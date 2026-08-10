/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_tim15 equates.
 */

#pragma once

#include    <stdint.h>

// TIM15 address definitions
// -------------------------

typedef struct {
    volatile    uint16_t    CR1;
    volatile    uint16_t    RESERVED0;
    volatile    uint16_t    CR2;
    volatile    uint16_t    RESERVED1;
    volatile    uint32_t    SMCR;
    volatile    uint16_t    DIER;
    volatile    uint16_t    RESERVED2;
    volatile    uint16_t    SR;
    volatile    uint16_t    RESERVED3;
    volatile    uint16_t    EGR;
    volatile    uint16_t    RESERVED4;
        union {
    volatile    uint32_t    CCMR1;
    volatile    uint32_t    CCMR1_ALTERNATE;
        };
    volatile    uint32_t    RESERVED5;
    volatile    uint16_t    CCER;
    volatile    uint16_t    RESERVED6;
    volatile    uint32_t    CNT;
    volatile    uint16_t    PSC;
    volatile    uint16_t    RESERVED7;
    volatile    uint16_t    ARR;
    volatile    uint16_t    RESERVED8;
    volatile    uint16_t    RCR;
    volatile    uint16_t    RESERVED9;
    volatile    uint16_t    CCR1;
    volatile    uint16_t    RESERVED10;
    volatile    uint16_t    CCR2;
    volatile    uint16_t    RESERVED11[5];
    volatile    uint32_t    BDTR;
    volatile    uint16_t    DCR;
    volatile    uint16_t    RESERVED12;
    volatile    uint16_t    DMAR;
    volatile    uint16_t    RESERVED13[9];
    volatile    uint32_t    AF1;
    volatile    uint32_t    RESERVED14;
    volatile    uint32_t    TISEL;
} TIM15_TypeDef;

#ifdef __cplusplus
#define TIM15   reinterpret_cast<TIM15_TypeDef *>(0x40014000U)

#else
#define TIM15   ((TIM15_TypeDef *)0x40014000U)
#endif

// CR1 Configuration

#define TIM15_CR1_UIFREMAP                  (0x1U<<11U)
#define TIM15_CR1_CKD                       (0x3U<<8U)
#define TIM15_CR1_CKD_0                     (0x1U<<8U)
#define TIM15_CR1_ARPE                      (0x1U<<7U)
#define TIM15_CR1_OPM                       (0x1U<<3U)
#define TIM15_CR1_URS                       (0x1U<<2U)
#define TIM15_CR1_UDIS                      (0x1U<<1U)
#define TIM15_CR1_CEN                       (0x1U<<0U)
#define TIM15_CR1_UIFREMAP_B_0X0            (0x0U<<11U)
#define TIM15_CR1_UIFREMAP_B_0X1            (0x1U<<11U)
#define TIM15_CR1_CKD_B_0X0                 (0x0U<<8U)
#define TIM15_CR1_CKD_B_0X1                 (0x1U<<8U)
#define TIM15_CR1_CKD_B_0X2                 (0x2U<<8U)
#define TIM15_CR1_CKD_B_0X3                 (0x3U<<8U)
#define TIM15_CR1_ARPE_B_0X0                (0x0U<<7U)
#define TIM15_CR1_ARPE_B_0X1                (0x1U<<7U)
#define TIM15_CR1_OPM_B_0X0                 (0x0U<<3U)
#define TIM15_CR1_OPM_B_0X1                 (0x1U<<3U)
#define TIM15_CR1_URS_B_0X0                 (0x0U<<2U)
#define TIM15_CR1_URS_B_0X1                 (0x1U<<2U)
#define TIM15_CR1_UDIS_B_0X0                (0x0U<<1U)
#define TIM15_CR1_UDIS_B_0X1                (0x1U<<1U)
#define TIM15_CR1_CEN_B_0X0                 (0x0U<<0U)
#define TIM15_CR1_CEN_B_0X1                 (0x1U<<0U)

// CR2 Configuration

#define TIM15_CR2_OIS2                      (0x1U<<10U)
#define TIM15_CR2_OIS1N                     (0x1U<<9U)
#define TIM15_CR2_OIS1                      (0x1U<<8U)
#define TIM15_CR2_TI1S                      (0x1U<<7U)
#define TIM15_CR2_MMS                       (0x7U<<4U)
#define TIM15_CR2_MMS_0                     (0x1U<<4U)
#define TIM15_CR2_CCDS                      (0x1U<<3U)
#define TIM15_CR2_CCUS                      (0x1U<<2U)
#define TIM15_CR2_CCPC                      (0x1U<<0U)
#define TIM15_CR2_OIS2_B_0X0                (0x0U<<10U)
#define TIM15_CR2_OIS2_B_0X1                (0x1U<<10U)
#define TIM15_CR2_OIS1N_B_0X0               (0x0U<<9U)
#define TIM15_CR2_OIS1N_B_0X1               (0x1U<<9U)
#define TIM15_CR2_OIS1_B_0X0                (0x0U<<8U)
#define TIM15_CR2_OIS1_B_0X1                (0x1U<<8U)
#define TIM15_CR2_TI1S_B_0X0                (0x0U<<7U)
#define TIM15_CR2_TI1S_B_0X1                (0x1U<<7U)
#define TIM15_CR2_MMS_B_0X0                 (0x0U<<4U)
#define TIM15_CR2_MMS_B_0X1                 (0x1U<<4U)
#define TIM15_CR2_MMS_B_0X2                 (0x2U<<4U)
#define TIM15_CR2_MMS_B_0X3                 (0x3U<<4U)
#define TIM15_CR2_MMS_B_0X4                 (0x4U<<4U)
#define TIM15_CR2_MMS_B_0X5                 (0x5U<<4U)
#define TIM15_CR2_CCDS_B_0X0                (0x0U<<3U)
#define TIM15_CR2_CCDS_B_0X1                (0x1U<<3U)
#define TIM15_CR2_CCUS_B_0X0                (0x0U<<2U)
#define TIM15_CR2_CCUS_B_0X1                (0x1U<<2U)
#define TIM15_CR2_CCPC_B_0X0                (0x0U<<0U)
#define TIM15_CR2_CCPC_B_0X1                (0x1U<<0U)

// SMCR Configuration

#define TIM15_SMCR_TS_1                     (0x3U<<20U)
#define TIM15_SMCR_TS_1_0                   (0x1U<<20U)
#define TIM15_SMCR_SMS_1                    (0x1U<<16U)
#define TIM15_SMCR_MSM                      (0x1U<<7U)
#define TIM15_SMCR_TS                       (0x7U<<4U)
#define TIM15_SMCR_TS_0                     (0x1U<<4U)
#define TIM15_SMCR_SMS                      (0x7U<<0U)
#define TIM15_SMCR_SMS_0                    (0x1U<<0U)
#define TIM15_SMCR_MSM_B_0X0                (0x0U<<7U)
#define TIM15_SMCR_MSM_B_0X1                (0x1U<<7U)
#define TIM15_SMCR_TS_B_0X0                 (0x0U<<4U)
#define TIM15_SMCR_TS_B_0X1                 (0x1U<<4U)
#define TIM15_SMCR_TS_B_0X2                 (0x2U<<4U)
#define TIM15_SMCR_TS_B_0X3                 (0x3U<<4U)
#define TIM15_SMCR_TS_B_0X4                 (0x4U<<4U)
#define TIM15_SMCR_TS_B_0X5                 (0x5U<<4U)
#define TIM15_SMCR_TS_B_0X6                 (0x6U<<4U)
#define TIM15_SMCR_SMS_B_0X0                (0x0U<<0U)
#define TIM15_SMCR_SMS_B_0X4                (0x4U<<0U)
#define TIM15_SMCR_SMS_B_0X5                (0x5U<<0U)
#define TIM15_SMCR_SMS_B_0X6                (0x6U<<0U)
#define TIM15_SMCR_SMS_B_0X7                (0x7U<<0U)

// DIER Configuration

#define TIM15_DIER_TDE                      (0x1U<<14U)
#define TIM15_DIER_COMDE                    (0x1U<<13U)
#define TIM15_DIER_CC1DE                    (0x1U<<9U)
#define TIM15_DIER_UDE                      (0x1U<<8U)
#define TIM15_DIER_BIE                      (0x1U<<7U)
#define TIM15_DIER_TIE                      (0x1U<<6U)
#define TIM15_DIER_COMIE                    (0x1U<<5U)
#define TIM15_DIER_CC2IE                    (0x1U<<2U)
#define TIM15_DIER_CC1IE                    (0x1U<<1U)
#define TIM15_DIER_UIE                      (0x1U<<0U)
#define TIM15_DIER_TDE_B_0X0                (0x0U<<14U)
#define TIM15_DIER_TDE_B_0X1                (0x1U<<14U)
#define TIM15_DIER_COMDE_B_0X0              (0x0U<<13U)
#define TIM15_DIER_COMDE_B_0X1              (0x1U<<13U)
#define TIM15_DIER_CC1DE_B_0X0              (0x0U<<9U)
#define TIM15_DIER_CC1DE_B_0X1              (0x1U<<9U)
#define TIM15_DIER_UDE_B_0X0                (0x0U<<8U)
#define TIM15_DIER_UDE_B_0X1                (0x1U<<8U)
#define TIM15_DIER_BIE_B_0X0                (0x0U<<7U)
#define TIM15_DIER_BIE_B_0X1                (0x1U<<7U)
#define TIM15_DIER_TIE_B_0X0                (0x0U<<6U)
#define TIM15_DIER_TIE_B_0X1                (0x1U<<6U)
#define TIM15_DIER_COMIE_B_0X0              (0x0U<<5U)
#define TIM15_DIER_COMIE_B_0X1              (0x1U<<5U)
#define TIM15_DIER_CC2IE_B_0X0              (0x0U<<2U)
#define TIM15_DIER_CC2IE_B_0X1              (0x1U<<2U)
#define TIM15_DIER_CC1IE_B_0X0              (0x0U<<1U)
#define TIM15_DIER_CC1IE_B_0X1              (0x1U<<1U)
#define TIM15_DIER_UIE_B_0X0                (0x0U<<0U)
#define TIM15_DIER_UIE_B_0X1                (0x1U<<0U)

// SR Configuration

#define TIM15_SR_CC2OF                      (0x1U<<10U)
#define TIM15_SR_CC1OF                      (0x1U<<9U)
#define TIM15_SR_BIF                        (0x1U<<7U)
#define TIM15_SR_TIF                        (0x1U<<6U)
#define TIM15_SR_COMIF                      (0x1U<<5U)
#define TIM15_SR_CC2IF                      (0x1U<<2U)
#define TIM15_SR_CC1IF                      (0x1U<<1U)
#define TIM15_SR_UIF                        (0x1U<<0U)
#define TIM15_SR_CC1OF_B_0X0                (0x0U<<9U)
#define TIM15_SR_CC1OF_B_0X1                (0x1U<<9U)
#define TIM15_SR_BIF_B_0X0                  (0x0U<<7U)
#define TIM15_SR_BIF_B_0X1                  (0x1U<<7U)
#define TIM15_SR_TIF_B_0X0                  (0x0U<<6U)
#define TIM15_SR_TIF_B_0X1                  (0x1U<<6U)
#define TIM15_SR_COMIF_B_0X0                (0x0U<<5U)
#define TIM15_SR_COMIF_B_0X1                (0x1U<<5U)
#define TIM15_SR_CC1IF_B_0X0                (0x0U<<1U)
#define TIM15_SR_CC1IF_B_0X1                (0x1U<<1U)
#define TIM15_SR_UIF_B_0X0                  (0x0U<<0U)
#define TIM15_SR_UIF_B_0X1                  (0x1U<<0U)

// EGR Configuration

#define TIM15_EGR_BG                        (0x1U<<7U)
#define TIM15_EGR_TG                        (0x1U<<6U)
#define TIM15_EGR_COMG                      (0x1U<<5U)
#define TIM15_EGR_CC2G                      (0x1U<<2U)
#define TIM15_EGR_CC1G                      (0x1U<<1U)
#define TIM15_EGR_UG                        (0x1U<<0U)
#define TIM15_EGR_BG_B_0X0                  (0x0U<<7U)
#define TIM15_EGR_BG_B_0X1                  (0x1U<<7U)
#define TIM15_EGR_TG_B_0X0                  (0x0U<<6U)
#define TIM15_EGR_TG_B_0X1                  (0x1U<<6U)
#define TIM15_EGR_COMG_B_0X0                (0x0U<<5U)
#define TIM15_EGR_COMG_B_0X1                (0x1U<<5U)
#define TIM15_EGR_CC1G_B_0X0                (0x0U<<1U)
#define TIM15_EGR_CC1G_B_0X1                (0x1U<<1U)
#define TIM15_EGR_UG_B_0X0                  (0x0U<<0U)
#define TIM15_EGR_UG_B_0X1                  (0x1U<<0U)

// CCMR1 Configuration

#define TIM15_CCMR1_IC2F                    (0xFU<<12U)
#define TIM15_CCMR1_IC2F_0                  (0x1U<<12U)
#define TIM15_CCMR1_IC2PSC                  (0x3U<<10U)
#define TIM15_CCMR1_IC2PSC_0                (0x1U<<10U)
#define TIM15_CCMR1_CC2S                    (0x3U<<8U)
#define TIM15_CCMR1_CC2S_0                  (0x1U<<8U)
#define TIM15_CCMR1_IC1F                    (0xFU<<4U)
#define TIM15_CCMR1_IC1F_0                  (0x1U<<4U)
#define TIM15_CCMR1_IC1PSC                  (0x3U<<2U)
#define TIM15_CCMR1_IC1PSC_0                (0x1U<<2U)
#define TIM15_CCMR1_CC1S                    (0x3U<<0U)
#define TIM15_CCMR1_CC1S_0                  (0x1U<<0U)
#define TIM15_CCMR1_CC2S_B_0X0              (0x0U<<8U)
#define TIM15_CCMR1_CC2S_B_0X1              (0x1U<<8U)
#define TIM15_CCMR1_CC2S_B_0X2              (0x2U<<8U)
#define TIM15_CCMR1_CC2S_B_0X3              (0x3U<<8U)
#define TIM15_CCMR1_IC1F_B_0X0              (0x0U<<4U)
#define TIM15_CCMR1_IC1F_B_0X1              (0x1U<<4U)
#define TIM15_CCMR1_IC1F_B_0X2              (0x2U<<4U)
#define TIM15_CCMR1_IC1F_B_0X3              (0x3U<<4U)
#define TIM15_CCMR1_IC1F_B_0X4              (0x4U<<4U)
#define TIM15_CCMR1_IC1F_B_0X5              (0x5U<<4U)
#define TIM15_CCMR1_IC1F_B_0X6              (0x6U<<4U)
#define TIM15_CCMR1_IC1F_B_0X7              (0x7U<<4U)
#define TIM15_CCMR1_IC1F_B_0X8              (0x8U<<4U)
#define TIM15_CCMR1_IC1F_B_0X9              (0x9U<<4U)
#define TIM15_CCMR1_IC1F_B_0XA              (0xAU<<4U)
#define TIM15_CCMR1_IC1F_B_0XB              (0xBU<<4U)
#define TIM15_CCMR1_IC1F_B_0XC              (0xCU<<4U)
#define TIM15_CCMR1_IC1F_B_0XD              (0xDU<<4U)
#define TIM15_CCMR1_IC1F_B_0XE              (0xEU<<4U)
#define TIM15_CCMR1_IC1F_B_0XF              (0xFU<<4U)
#define TIM15_CCMR1_IC1PSC_B_0X0            (0x0U<<2U)
#define TIM15_CCMR1_IC1PSC_B_0X1            (0x1U<<2U)
#define TIM15_CCMR1_IC1PSC_B_0X2            (0x2U<<2U)
#define TIM15_CCMR1_IC1PSC_B_0X3            (0x3U<<2U)
#define TIM15_CCMR1_CC1S_B_0X0              (0x0U<<0U)
#define TIM15_CCMR1_CC1S_B_0X1              (0x1U<<0U)
#define TIM15_CCMR1_CC1S_B_0X2              (0x2U<<0U)
#define TIM15_CCMR1_CC1S_B_0X3              (0x3U<<0U)

// CCMR1_ALTERNATE Configuration

#define TIM15_CCMR1_ALTERNATE_OC2M_1        (0x1U<<24U)
#define TIM15_CCMR1_ALTERNATE_OC1M_1        (0x1U<<16U)
#define TIM15_CCMR1_ALTERNATE_OC2M          (0x7U<<12U)
#define TIM15_CCMR1_ALTERNATE_OC2M_0        (0x1U<<12U)
#define TIM15_CCMR1_ALTERNATE_OC2PE         (0x1U<<11U)
#define TIM15_CCMR1_ALTERNATE_OC2FE         (0x1U<<10U)
#define TIM15_CCMR1_ALTERNATE_CC2S          (0x3U<<8U)
#define TIM15_CCMR1_ALTERNATE_CC2S_0        (0x1U<<8U)
#define TIM15_CCMR1_ALTERNATE_OC1M          (0x7U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_0        (0x1U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1PE         (0x1U<<3U)
#define TIM15_CCMR1_ALTERNATE_OC1FE         (0x1U<<2U)
#define TIM15_CCMR1_ALTERNATE_CC1S          (0x3U<<0U)
#define TIM15_CCMR1_ALTERNATE_CC1S_0        (0x1U<<0U)
#define TIM15_CCMR1_ALTERNATE_CC2S_B_0X0    (0x0U<<8U)
#define TIM15_CCMR1_ALTERNATE_CC2S_B_0X1    (0x1U<<8U)
#define TIM15_CCMR1_ALTERNATE_CC2S_B_0X2    (0x2U<<8U)
#define TIM15_CCMR1_ALTERNATE_CC2S_B_0X3    (0x3U<<8U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X0    (0x0U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X1    (0x1U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X2    (0x2U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X3    (0x3U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X4    (0x4U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X5    (0x5U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X6    (0x6U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1M_B_0X7    (0x7U<<4U)
#define TIM15_CCMR1_ALTERNATE_OC1PE_B_0X0   (0x0U<<3U)
#define TIM15_CCMR1_ALTERNATE_OC1PE_B_0X1   (0x1U<<3U)
#define TIM15_CCMR1_ALTERNATE_OC1FE_B_0X0   (0x0U<<2U)
#define TIM15_CCMR1_ALTERNATE_OC1FE_B_0X1   (0x1U<<2U)
#define TIM15_CCMR1_ALTERNATE_CC1S_B_0X0    (0x0U<<0U)
#define TIM15_CCMR1_ALTERNATE_CC1S_B_0X1    (0x1U<<0U)
#define TIM15_CCMR1_ALTERNATE_CC1S_B_0X2    (0x2U<<0U)
#define TIM15_CCMR1_ALTERNATE_CC1S_B_0X3    (0x3U<<0U)

// CCER Configuration

#define TIM15_CCER_CC2NP                    (0x1U<<7U)
#define TIM15_CCER_CC2P                     (0x1U<<5U)
#define TIM15_CCER_CC2E                     (0x1U<<4U)
#define TIM15_CCER_CC1NP                    (0x1U<<3U)
#define TIM15_CCER_CC1NE                    (0x1U<<2U)
#define TIM15_CCER_CC1P                     (0x1U<<1U)
#define TIM15_CCER_CC1E                     (0x1U<<0U)
#define TIM15_CCER_CC1NP_B_0X0              (0x0U<<3U)
#define TIM15_CCER_CC1NP_B_0X1              (0x1U<<3U)
#define TIM15_CCER_CC1NE_B_0X0              (0x0U<<2U)
#define TIM15_CCER_CC1NE_B_0X1              (0x1U<<2U)
#define TIM15_CCER_CC1P_B_0X0               (0x0U<<1U)
#define TIM15_CCER_CC1P_B_0X1               (0x1U<<1U)
#define TIM15_CCER_CC1E_B_0X0               (0x0U<<0U)
#define TIM15_CCER_CC1E_B_0X1               (0x1U<<0U)

// CNT Configuration

#define TIM15_CNT_UIFCPY                    (0x1U<<31U)
#define TIM15_CNT_CNT                       (0xFFFFU<<0U)
#define TIM15_CNT_CNT_0                     (0x1U<<0U)

// PSC Configuration

#define TIM15_PSC_PSC                       (0xFFFFU<<0U)
#define TIM15_PSC_PSC_0                     (0x1U<<0U)

// ARR Configuration

#define TIM15_ARR_ARR                       (0xFFFFU<<0U)
#define TIM15_ARR_ARR_0                     (0x1U<<0U)

// RCR Configuration

#define TIM15_RCR_REP                       (0xFFU<<0U)
#define TIM15_RCR_REP_0                     (0x1U<<0U)

// CCR1 Configuration

#define TIM15_CCR1_CCR1                     (0xFFFFU<<0U)
#define TIM15_CCR1_CCR1_0                   (0x1U<<0U)

// CCR2 Configuration

#define TIM15_CCR2_CCR2                     (0xFFFFU<<0U)
#define TIM15_CCR2_CCR2_0                   (0x1U<<0U)

// BDTR Configuration

#define TIM15_BDTR_BKF                      (0xFU<<16U)
#define TIM15_BDTR_BKF_0                    (0x1U<<16U)
#define TIM15_BDTR_MOE                      (0x1U<<15U)
#define TIM15_BDTR_AOE                      (0x1U<<14U)
#define TIM15_BDTR_BKP                      (0x1U<<13U)
#define TIM15_BDTR_BKE                      (0x1U<<12U)
#define TIM15_BDTR_OSSR                     (0x1U<<11U)
#define TIM15_BDTR_OSSI                     (0x1U<<10U)
#define TIM15_BDTR_LOCK                     (0x3U<<8U)
#define TIM15_BDTR_LOCK_0                   (0x1U<<8U)
#define TIM15_BDTR_DTG                      (0xFFU<<0U)
#define TIM15_BDTR_DTG_0                    (0x1U<<0U)
#define TIM15_BDTR_BKF_B_0X0                (0x0U<<16U)
#define TIM15_BDTR_BKF_B_0X1                (0x1U<<16U)
#define TIM15_BDTR_BKF_B_0X2                (0x2U<<16U)
#define TIM15_BDTR_BKF_B_0X3                (0x3U<<16U)
#define TIM15_BDTR_BKF_B_0X4                (0x4U<<16U)
#define TIM15_BDTR_BKF_B_0X5                (0x5U<<16U)
#define TIM15_BDTR_BKF_B_0X6                (0x6U<<16U)
#define TIM15_BDTR_BKF_B_0X7                (0x7U<<16U)
#define TIM15_BDTR_BKF_B_0X8                (0x8U<<16U)
#define TIM15_BDTR_BKF_B_0X9                (0x9U<<16U)
#define TIM15_BDTR_BKF_B_0XA                (0xAU<<16U)
#define TIM15_BDTR_BKF_B_0XB                (0xBU<<16U)
#define TIM15_BDTR_BKF_B_0XC                (0xCU<<16U)
#define TIM15_BDTR_BKF_B_0XD                (0xDU<<16U)
#define TIM15_BDTR_BKF_B_0XE                (0xEU<<16U)
#define TIM15_BDTR_BKF_B_0XF                (0xFU<<16U)
#define TIM15_BDTR_MOE_B_0X0                (0x0U<<15U)
#define TIM15_BDTR_MOE_B_0X1                (0x1U<<15U)
#define TIM15_BDTR_AOE_B_0X0                (0x0U<<14U)
#define TIM15_BDTR_AOE_B_0X1                (0x1U<<14U)
#define TIM15_BDTR_BKP_B_0X0                (0x0U<<13U)
#define TIM15_BDTR_BKP_B_0X1                (0x1U<<13U)
#define TIM15_BDTR_BKE_B_0X0                (0x0U<<12U)
#define TIM15_BDTR_OSSR_B_0X0               (0x0U<<11U)
#define TIM15_BDTR_OSSR_B_0X1               (0x1U<<11U)
#define TIM15_BDTR_OSSI_B_0X0               (0x0U<<10U)
#define TIM15_BDTR_OSSI_B_0X1               (0x1U<<10U)
#define TIM15_BDTR_LOCK_B_0X0               (0x0U<<8U)
#define TIM15_BDTR_LOCK_B_0X1               (0x1U<<8U)
#define TIM15_BDTR_LOCK_B_0X2               (0x2U<<8U)
#define TIM15_BDTR_LOCK_B_0X3               (0x3U<<8U)

// DCR Configuration

#define TIM15_DCR_DBL                       (0x1FU<<8U)
#define TIM15_DCR_DBL_0                     (0x1U<<8U)
#define TIM15_DCR_DBA                       (0x1FU<<0U)
#define TIM15_DCR_DBA_0                     (0x1U<<0U)
#define TIM15_DCR_DBL_B_0X0                 (0x0U<<8U)
#define TIM15_DCR_DBL_B_0X1                 (0x1U<<8U)
#define TIM15_DCR_DBL_B_0X2                 (0x2U<<8U)
#define TIM15_DCR_DBL_B_0X11                (0x11U<<8U)
#define TIM15_DCR_DBA_B_0X0                 (0x0U<<0U)
#define TIM15_DCR_DBA_B_0X1                 (0x1U<<0U)
#define TIM15_DCR_DBA_B_0X2                 (0x2U<<0U)

// DMAR Configuration

#define TIM15_DMAR_DMAB                     (0xFFFFU<<0U)
#define TIM15_DMAR_DMAB_0                   (0x1U<<0U)

// AF1 Configuration

#define TIM15_AF1_BKCMP2P                   (0x1U<<11U)
#define TIM15_AF1_BKCMP1P                   (0x1U<<10U)
#define TIM15_AF1_BKINP                     (0x1U<<9U)
#define TIM15_AF1_BKDF1BK0E                 (0x1U<<8U)
#define TIM15_AF1_BKCMP2E                   (0x1U<<2U)
#define TIM15_AF1_BKCMP1E                   (0x1U<<1U)
#define TIM15_AF1_BKINE                     (0x1U<<0U)
#define TIM15_AF1_BKCMP2P_B_0X0             (0x0U<<11U)
#define TIM15_AF1_BKCMP2P_B_0X1             (0x1U<<11U)
#define TIM15_AF1_BKCMP1P_B_0X0             (0x0U<<10U)
#define TIM15_AF1_BKCMP1P_B_0X1             (0x1U<<10U)
#define TIM15_AF1_BKINP_B_0X0               (0x0U<<9U)
#define TIM15_AF1_BKINP_B_0X1               (0x1U<<9U)
#define TIM15_AF1_BKDF1BK0E_B_0X0           (0x0U<<8U)
#define TIM15_AF1_BKDF1BK0E_B_0X1           (0x1U<<8U)
#define TIM15_AF1_BKCMP2E_B_0X0             (0x0U<<2U)
#define TIM15_AF1_BKCMP2E_B_0X1             (0x1U<<2U)
#define TIM15_AF1_BKCMP1E_B_0X0             (0x0U<<1U)
#define TIM15_AF1_BKCMP1E_B_0X1             (0x1U<<1U)
#define TIM15_AF1_BKINE_B_0X0               (0x0U<<0U)
#define TIM15_AF1_BKINE_B_0X1               (0x1U<<0U)

// TISEL Configuration

#define TIM15_TISEL_TI2SEL                  (0xFU<<8U)
#define TIM15_TISEL_TI2SEL_0                (0x1U<<8U)
#define TIM15_TISEL_TI1SEL                  (0xFU<<0U)
#define TIM15_TISEL_TI1SEL_0                (0x1U<<0U)
#define TIM15_TISEL_TI2SEL_B_0X0            (0x0U<<8U)
#define TIM15_TISEL_TI2SEL_B_0X1            (0x1U<<8U)
#define TIM15_TISEL_TI2SEL_B_0X2            (0x2U<<8U)
#define TIM15_TISEL_TI2SEL_B_0X3            (0x3U<<8U)
#define TIM15_TISEL_TI1SEL_B_0X0            (0x0U<<0U)
#define TIM15_TISEL_TI1SEL_B_0X1            (0x1U<<0U)
#define TIM15_TISEL_TI1SEL_B_0X2            (0x2U<<0U)
#define TIM15_TISEL_TI1SEL_B_0X3            (0x3U<<0U)
#define TIM15_TISEL_TI1SEL_B_0X4            (0x4U<<0U)
#define TIM15_TISEL_TI1SEL_B_0X5            (0x5U<<0U)
#define TIM15_TISEL_TI1SEL_B_0X6            (0x6U<<0U)
