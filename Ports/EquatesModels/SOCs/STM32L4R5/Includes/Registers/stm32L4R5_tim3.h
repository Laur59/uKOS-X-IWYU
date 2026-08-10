/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_tim3 equates.
 */

#pragma once

#include    <stdint.h>

// TIM3 address definitions
// ------------------------

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
        union {
    volatile    uint32_t    CCMR2;
    volatile    uint32_t    CCMR2_ALTERNATE;
        };
    volatile    uint16_t    CCER;
    volatile    uint16_t    RESERVED5;
        union {
    volatile    uint32_t    CNT;
    volatile    uint32_t    CNT_ALTERNATE;
        };
    volatile    uint16_t    PSC;
    volatile    uint16_t    RESERVED6;
    volatile    uint32_t    ARR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    CCR2;
    volatile    uint32_t    CCR3;
    volatile    uint32_t    CCR4;
    volatile    uint32_t    RESERVED8;
    volatile    uint16_t    DCR;
    volatile    uint16_t    RESERVED9;
    volatile    uint16_t    DMAR;
    volatile    uint16_t    RESERVED10[9];
    volatile    uint32_t    AF1;
    volatile    uint32_t    RESERVED11;
    volatile    uint32_t    TISEL;
} TIM3_TypeDef;

#ifdef __cplusplus
#define TIM3    reinterpret_cast<TIM3_TypeDef *>(0x40000400U)

#else
#define TIM3    ((TIM3_TypeDef *)0x40000400U)
#endif

// CR1 Configuration

#define TIM3_CR1_UIFREMAP                   (0x1U<<11U)
#define TIM3_CR1_CKD                        (0x3U<<8U)
#define TIM3_CR1_CKD_0                      (0x1U<<8U)
#define TIM3_CR1_ARPE                       (0x1U<<7U)
#define TIM3_CR1_CMS                        (0x3U<<5U)
#define TIM3_CR1_CMS_0                      (0x1U<<5U)
#define TIM3_CR1_DIR                        (0x1U<<4U)
#define TIM3_CR1_OPM                        (0x1U<<3U)
#define TIM3_CR1_URS                        (0x1U<<2U)
#define TIM3_CR1_UDIS                       (0x1U<<1U)
#define TIM3_CR1_CEN                        (0x1U<<0U)
#define TIM3_CR1_UIFREMAP_B_0X0             (0x0U<<11U)
#define TIM3_CR1_UIFREMAP_B_0X1             (0x1U<<11U)
#define TIM3_CR1_CKD_B_0X0                  (0x0U<<8U)
#define TIM3_CR1_CKD_B_0X1                  (0x1U<<8U)
#define TIM3_CR1_CKD_B_0X2                  (0x2U<<8U)
#define TIM3_CR1_ARPE_B_0X0                 (0x0U<<7U)
#define TIM3_CR1_ARPE_B_0X1                 (0x1U<<7U)
#define TIM3_CR1_CMS_B_0X0                  (0x0U<<5U)
#define TIM3_CR1_CMS_B_0X1                  (0x1U<<5U)
#define TIM3_CR1_CMS_B_0X2                  (0x2U<<5U)
#define TIM3_CR1_CMS_B_0X3                  (0x3U<<5U)
#define TIM3_CR1_DIR_B_0X0                  (0x0U<<4U)
#define TIM3_CR1_DIR_B_0X1                  (0x1U<<4U)
#define TIM3_CR1_OPM_B_0X0                  (0x0U<<3U)
#define TIM3_CR1_OPM_B_0X1                  (0x1U<<3U)
#define TIM3_CR1_URS_B_0X0                  (0x0U<<2U)
#define TIM3_CR1_URS_B_0X1                  (0x1U<<2U)
#define TIM3_CR1_UDIS_B_0X0                 (0x0U<<1U)
#define TIM3_CR1_UDIS_B_0X1                 (0x1U<<1U)
#define TIM3_CR1_CEN_B_0X0                  (0x0U<<0U)
#define TIM3_CR1_CEN_B_0X1                  (0x1U<<0U)

// CR2 Configuration

#define TIM3_CR2_TI1S                       (0x1U<<7U)
#define TIM3_CR2_MMS                        (0x7U<<4U)
#define TIM3_CR2_MMS_0                      (0x1U<<4U)
#define TIM3_CR2_CCDS                       (0x1U<<3U)
#define TIM3_CR2_TI1S_B_0X0                 (0x0U<<7U)
#define TIM3_CR2_TI1S_B_0X1                 (0x1U<<7U)
#define TIM3_CR2_MMS_B_0X0                  (0x0U<<4U)
#define TIM3_CR2_MMS_B_0X1                  (0x1U<<4U)
#define TIM3_CR2_MMS_B_0X2                  (0x2U<<4U)
#define TIM3_CR2_MMS_B_0X3                  (0x3U<<4U)
#define TIM3_CR2_MMS_B_0X4                  (0x4U<<4U)
#define TIM3_CR2_MMS_B_0X5                  (0x5U<<4U)
#define TIM3_CR2_MMS_B_0X6                  (0x6U<<4U)
#define TIM3_CR2_MMS_B_0X7                  (0x7U<<4U)
#define TIM3_CR2_CCDS_B_0X0                 (0x0U<<3U)
#define TIM3_CR2_CCDS_B_0X1                 (0x1U<<3U)

// SMCR Configuration

#define TIM3_SMCR_TS_1                      (0x3U<<20U)
#define TIM3_SMCR_TS_1_0                    (0x1U<<20U)
#define TIM3_SMCR_SMS_1                     (0x1U<<16U)
#define TIM3_SMCR_ETP                       (0x1U<<15U)
#define TIM3_SMCR_ECE                       (0x1U<<14U)
#define TIM3_SMCR_ETPS                      (0x3U<<12U)
#define TIM3_SMCR_ETPS_0                    (0x1U<<12U)
#define TIM3_SMCR_ETF                       (0xFU<<8U)
#define TIM3_SMCR_ETF_0                     (0x1U<<8U)
#define TIM3_SMCR_MSM                       (0x1U<<7U)
#define TIM3_SMCR_TS                        (0x7U<<4U)
#define TIM3_SMCR_TS_0                      (0x1U<<4U)
#define TIM3_SMCR_SMS                       (0x7U<<0U)
#define TIM3_SMCR_SMS_0                     (0x1U<<0U)
#define TIM3_SMCR_ETP_B_0X0                 (0x0U<<15U)
#define TIM3_SMCR_ETP_B_0X1                 (0x1U<<15U)
#define TIM3_SMCR_ECE_B_0X0                 (0x0U<<14U)
#define TIM3_SMCR_ECE_B_0X1                 (0x1U<<14U)
#define TIM3_SMCR_ETPS_B_0X0                (0x0U<<12U)
#define TIM3_SMCR_ETPS_B_0X1                (0x1U<<12U)
#define TIM3_SMCR_ETPS_B_0X2                (0x2U<<12U)
#define TIM3_SMCR_ETPS_B_0X3                (0x3U<<12U)
#define TIM3_SMCR_ETF_B_0X0                 (0x0U<<8U)
#define TIM3_SMCR_ETF_B_0X1                 (0x1U<<8U)
#define TIM3_SMCR_ETF_B_0X2                 (0x2U<<8U)
#define TIM3_SMCR_ETF_B_0X3                 (0x3U<<8U)
#define TIM3_SMCR_ETF_B_0X4                 (0x4U<<8U)
#define TIM3_SMCR_ETF_B_0X5                 (0x5U<<8U)
#define TIM3_SMCR_ETF_B_0X6                 (0x6U<<8U)
#define TIM3_SMCR_ETF_B_0X7                 (0x7U<<8U)
#define TIM3_SMCR_ETF_B_0X8                 (0x8U<<8U)
#define TIM3_SMCR_ETF_B_0X9                 (0x9U<<8U)
#define TIM3_SMCR_ETF_B_0XA                 (0xAU<<8U)
#define TIM3_SMCR_ETF_B_0XB                 (0xBU<<8U)
#define TIM3_SMCR_ETF_B_0XC                 (0xCU<<8U)
#define TIM3_SMCR_ETF_B_0XD                 (0xDU<<8U)
#define TIM3_SMCR_ETF_B_0XE                 (0xEU<<8U)
#define TIM3_SMCR_ETF_B_0XF                 (0xFU<<8U)
#define TIM3_SMCR_MSM_B_0X0                 (0x0U<<7U)
#define TIM3_SMCR_MSM_B_0X1                 (0x1U<<7U)
#define TIM3_SMCR_TS_B_0X0                  (0x0U<<4U)
#define TIM3_SMCR_TS_B_0X1                  (0x1U<<4U)
#define TIM3_SMCR_TS_B_0X2                  (0x2U<<4U)
#define TIM3_SMCR_TS_B_0X3                  (0x3U<<4U)
#define TIM3_SMCR_TS_B_0X4                  (0x4U<<4U)
#define TIM3_SMCR_TS_B_0X5                  (0x5U<<4U)
#define TIM3_SMCR_TS_B_0X6                  (0x6U<<4U)
#define TIM3_SMCR_TS_B_0X7                  (0x7U<<4U)
#define TIM3_SMCR_SMS_B_0X0                 (0x0U<<0U)
#define TIM3_SMCR_SMS_B_0X1                 (0x1U<<0U)
#define TIM3_SMCR_SMS_B_0X2                 (0x2U<<0U)
#define TIM3_SMCR_SMS_B_0X3                 (0x3U<<0U)
#define TIM3_SMCR_SMS_B_0X4                 (0x4U<<0U)
#define TIM3_SMCR_SMS_B_0X5                 (0x5U<<0U)
#define TIM3_SMCR_SMS_B_0X6                 (0x6U<<0U)
#define TIM3_SMCR_SMS_B_0X7                 (0x7U<<0U)

// DIER Configuration

#define TIM3_DIER_TDE                       (0x1U<<14U)
#define TIM3_DIER_CC4DE                     (0x1U<<12U)
#define TIM3_DIER_CC3DE                     (0x1U<<11U)
#define TIM3_DIER_CC2DE                     (0x1U<<10U)
#define TIM3_DIER_CC1DE                     (0x1U<<9U)
#define TIM3_DIER_UDE                       (0x1U<<8U)
#define TIM3_DIER_TIE                       (0x1U<<6U)
#define TIM3_DIER_CC4IE                     (0x1U<<4U)
#define TIM3_DIER_CC3IE                     (0x1U<<3U)
#define TIM3_DIER_CC2IE                     (0x1U<<2U)
#define TIM3_DIER_CC1IE                     (0x1U<<1U)
#define TIM3_DIER_UIE                       (0x1U<<0U)
#define TIM3_DIER_TDE_B_0X0                 (0x0U<<14U)
#define TIM3_DIER_TDE_B_0X1                 (0x1U<<14U)
#define TIM3_DIER_CC4DE_B_0X0               (0x0U<<12U)
#define TIM3_DIER_CC4DE_B_0X1               (0x1U<<12U)
#define TIM3_DIER_CC3DE_B_0X0               (0x0U<<11U)
#define TIM3_DIER_CC3DE_B_0X1               (0x1U<<11U)
#define TIM3_DIER_CC2DE_B_0X0               (0x0U<<10U)
#define TIM3_DIER_CC2DE_B_0X1               (0x1U<<10U)
#define TIM3_DIER_CC1DE_B_0X0               (0x0U<<9U)
#define TIM3_DIER_CC1DE_B_0X1               (0x1U<<9U)
#define TIM3_DIER_UDE_B_0X0                 (0x0U<<8U)
#define TIM3_DIER_UDE_B_0X1                 (0x1U<<8U)
#define TIM3_DIER_TIE_B_0X0                 (0x0U<<6U)
#define TIM3_DIER_TIE_B_0X1                 (0x1U<<6U)
#define TIM3_DIER_CC4IE_B_0X0               (0x0U<<4U)
#define TIM3_DIER_CC4IE_B_0X1               (0x1U<<4U)
#define TIM3_DIER_CC3IE_B_0X0               (0x0U<<3U)
#define TIM3_DIER_CC3IE_B_0X1               (0x1U<<3U)
#define TIM3_DIER_CC2IE_B_0X0               (0x0U<<2U)
#define TIM3_DIER_CC2IE_B_0X1               (0x1U<<2U)
#define TIM3_DIER_CC1IE_B_0X0               (0x0U<<1U)
#define TIM3_DIER_CC1IE_B_0X1               (0x1U<<1U)
#define TIM3_DIER_UIE_B_0X0                 (0x0U<<0U)
#define TIM3_DIER_UIE_B_0X1                 (0x1U<<0U)

// SR Configuration

#define TIM3_SR_CC4OF                       (0x1U<<12U)
#define TIM3_SR_CC3OF                       (0x1U<<11U)
#define TIM3_SR_CC2OF                       (0x1U<<10U)
#define TIM3_SR_CC1OF                       (0x1U<<9U)
#define TIM3_SR_TIF                         (0x1U<<6U)
#define TIM3_SR_CC4IF                       (0x1U<<4U)
#define TIM3_SR_CC3IF                       (0x1U<<3U)
#define TIM3_SR_CC2IF                       (0x1U<<2U)
#define TIM3_SR_CC1IF                       (0x1U<<1U)
#define TIM3_SR_UIF                         (0x1U<<0U)
#define TIM3_SR_CC1OF_B_0X0                 (0x0U<<9U)
#define TIM3_SR_CC1OF_B_0X1                 (0x1U<<9U)
#define TIM3_SR_TIF_B_0X0                   (0x0U<<6U)
#define TIM3_SR_TIF_B_0X1                   (0x1U<<6U)
#define TIM3_SR_CC1IF_B_0X0                 (0x0U<<1U)
#define TIM3_SR_CC1IF_B_0X1                 (0x1U<<1U)
#define TIM3_SR_UIF_B_0X0                   (0x0U<<0U)
#define TIM3_SR_UIF_B_0X1                   (0x1U<<0U)

// EGR Configuration

#define TIM3_EGR_TG                         (0x1U<<6U)
#define TIM3_EGR_CC4G                       (0x1U<<4U)
#define TIM3_EGR_CC3G                       (0x1U<<3U)
#define TIM3_EGR_CC2G                       (0x1U<<2U)
#define TIM3_EGR_CC1G                       (0x1U<<1U)
#define TIM3_EGR_UG                         (0x1U<<0U)
#define TIM3_EGR_TG_B_0X0                   (0x0U<<6U)
#define TIM3_EGR_TG_B_0X1                   (0x1U<<6U)
#define TIM3_EGR_CC1G_B_0X0                 (0x0U<<1U)
#define TIM3_EGR_CC1G_B_0X1                 (0x1U<<1U)
#define TIM3_EGR_UG_B_0X0                   (0x0U<<0U)
#define TIM3_EGR_UG_B_0X1                   (0x1U<<0U)

// CCMR1 Configuration

#define TIM3_CCMR1_IC2F                     (0xFU<<12U)
#define TIM3_CCMR1_IC2F_0                   (0x1U<<12U)
#define TIM3_CCMR1_IC2PSC                   (0x3U<<10U)
#define TIM3_CCMR1_IC2PSC_0                 (0x1U<<10U)
#define TIM3_CCMR1_CC2S                     (0x3U<<8U)
#define TIM3_CCMR1_CC2S_0                   (0x1U<<8U)
#define TIM3_CCMR1_IC1F                     (0xFU<<4U)
#define TIM3_CCMR1_IC1F_0                   (0x1U<<4U)
#define TIM3_CCMR1_IC1PSC                   (0x3U<<2U)
#define TIM3_CCMR1_IC1PSC_0                 (0x1U<<2U)
#define TIM3_CCMR1_CC1S                     (0x3U<<0U)
#define TIM3_CCMR1_CC1S_0                   (0x1U<<0U)
#define TIM3_CCMR1_CC2S_B_0X0               (0x0U<<8U)
#define TIM3_CCMR1_CC2S_B_0X1               (0x1U<<8U)
#define TIM3_CCMR1_CC2S_B_0X2               (0x2U<<8U)
#define TIM3_CCMR1_CC2S_B_0X3               (0x3U<<8U)
#define TIM3_CCMR1_IC1F_B_0X0               (0x0U<<4U)
#define TIM3_CCMR1_IC1F_B_0X1               (0x1U<<4U)
#define TIM3_CCMR1_IC1F_B_0X2               (0x2U<<4U)
#define TIM3_CCMR1_IC1F_B_0X3               (0x3U<<4U)
#define TIM3_CCMR1_IC1F_B_0X4               (0x4U<<4U)
#define TIM3_CCMR1_IC1F_B_0X5               (0x5U<<4U)
#define TIM3_CCMR1_IC1F_B_0X6               (0x6U<<4U)
#define TIM3_CCMR1_IC1F_B_0X7               (0x7U<<4U)
#define TIM3_CCMR1_IC1F_B_0X8               (0x8U<<4U)
#define TIM3_CCMR1_IC1F_B_0X9               (0x9U<<4U)
#define TIM3_CCMR1_IC1F_B_0XA               (0xAU<<4U)
#define TIM3_CCMR1_IC1F_B_0XB               (0xBU<<4U)
#define TIM3_CCMR1_IC1F_B_0XC               (0xCU<<4U)
#define TIM3_CCMR1_IC1F_B_0XD               (0xDU<<4U)
#define TIM3_CCMR1_IC1F_B_0XE               (0xEU<<4U)
#define TIM3_CCMR1_IC1F_B_0XF               (0xFU<<4U)
#define TIM3_CCMR1_IC1PSC_B_0X0             (0x0U<<2U)
#define TIM3_CCMR1_IC1PSC_B_0X1             (0x1U<<2U)
#define TIM3_CCMR1_IC1PSC_B_0X2             (0x2U<<2U)
#define TIM3_CCMR1_IC1PSC_B_0X3             (0x3U<<2U)
#define TIM3_CCMR1_CC1S_B_0X0               (0x0U<<0U)
#define TIM3_CCMR1_CC1S_B_0X1               (0x1U<<0U)
#define TIM3_CCMR1_CC1S_B_0X2               (0x2U<<0U)
#define TIM3_CCMR1_CC1S_B_0X3               (0x3U<<0U)

// CCMR1_ALTERNATE Configuration

#define TIM3_CCMR1_ALTERNATE_OC2M_1         (0x1U<<24U)
#define TIM3_CCMR1_ALTERNATE_OC1M_1         (0x1U<<16U)
#define TIM3_CCMR1_ALTERNATE_OC2CE          (0x1U<<15U)
#define TIM3_CCMR1_ALTERNATE_OC2M           (0x7U<<12U)
#define TIM3_CCMR1_ALTERNATE_OC2M_0         (0x1U<<12U)
#define TIM3_CCMR1_ALTERNATE_OC2PE          (0x1U<<11U)
#define TIM3_CCMR1_ALTERNATE_OC2FE          (0x1U<<10U)
#define TIM3_CCMR1_ALTERNATE_CC2S           (0x3U<<8U)
#define TIM3_CCMR1_ALTERNATE_CC2S_0         (0x1U<<8U)
#define TIM3_CCMR1_ALTERNATE_OC1CE          (0x1U<<7U)
#define TIM3_CCMR1_ALTERNATE_OC1M           (0x7U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_0         (0x1U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1PE          (0x1U<<3U)
#define TIM3_CCMR1_ALTERNATE_OC1FE          (0x1U<<2U)
#define TIM3_CCMR1_ALTERNATE_CC1S           (0x3U<<0U)
#define TIM3_CCMR1_ALTERNATE_CC1S_0         (0x1U<<0U)
#define TIM3_CCMR1_ALTERNATE_CC2S_B_0X0     (0x0U<<8U)
#define TIM3_CCMR1_ALTERNATE_CC2S_B_0X1     (0x1U<<8U)
#define TIM3_CCMR1_ALTERNATE_CC2S_B_0X2     (0x2U<<8U)
#define TIM3_CCMR1_ALTERNATE_CC2S_B_0X3     (0x3U<<8U)
#define TIM3_CCMR1_ALTERNATE_OC1CE_B_0X0    (0x0U<<7U)
#define TIM3_CCMR1_ALTERNATE_OC1CE_B_0X1    (0x1U<<7U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X0     (0x0U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X1     (0x1U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X2     (0x2U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X3     (0x3U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X4     (0x4U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X5     (0x5U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X6     (0x6U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1M_B_0X7     (0x7U<<4U)
#define TIM3_CCMR1_ALTERNATE_OC1PE_B_0X0    (0x0U<<3U)
#define TIM3_CCMR1_ALTERNATE_OC1PE_B_0X1    (0x1U<<3U)
#define TIM3_CCMR1_ALTERNATE_OC1FE_B_0X0    (0x0U<<2U)
#define TIM3_CCMR1_ALTERNATE_OC1FE_B_0X1    (0x1U<<2U)
#define TIM3_CCMR1_ALTERNATE_CC1S_B_0X0     (0x0U<<0U)
#define TIM3_CCMR1_ALTERNATE_CC1S_B_0X1     (0x1U<<0U)
#define TIM3_CCMR1_ALTERNATE_CC1S_B_0X2     (0x2U<<0U)
#define TIM3_CCMR1_ALTERNATE_CC1S_B_0X3     (0x3U<<0U)

// CCMR2 Configuration

#define TIM3_CCMR2_IC4F                     (0xFU<<12U)
#define TIM3_CCMR2_IC4F_0                   (0x1U<<12U)
#define TIM3_CCMR2_IC4PSC                   (0x3U<<10U)
#define TIM3_CCMR2_IC4PSC_0                 (0x1U<<10U)
#define TIM3_CCMR2_CC4S                     (0x3U<<8U)
#define TIM3_CCMR2_CC4S_0                   (0x1U<<8U)
#define TIM3_CCMR2_IC3F                     (0xFU<<4U)
#define TIM3_CCMR2_IC3F_0                   (0x1U<<4U)
#define TIM3_CCMR2_IC3PSC                   (0x3U<<2U)
#define TIM3_CCMR2_IC3PSC_0                 (0x1U<<2U)
#define TIM3_CCMR2_CC3S                     (0x3U<<0U)
#define TIM3_CCMR2_CC3S_0                   (0x1U<<0U)
#define TIM3_CCMR2_CC4S_B_0X0               (0x0U<<8U)
#define TIM3_CCMR2_CC4S_B_0X1               (0x1U<<8U)
#define TIM3_CCMR2_CC4S_B_0X2               (0x2U<<8U)
#define TIM3_CCMR2_CC4S_B_0X3               (0x3U<<8U)
#define TIM3_CCMR2_CC3S_B_0X0               (0x0U<<0U)
#define TIM3_CCMR2_CC3S_B_0X1               (0x1U<<0U)
#define TIM3_CCMR2_CC3S_B_0X2               (0x2U<<0U)
#define TIM3_CCMR2_CC3S_B_0X3               (0x3U<<0U)

// CCMR2_ALTERNATE Configuration

#define TIM3_CCMR2_ALTERNATE_OC4M_1         (0x1U<<24U)
#define TIM3_CCMR2_ALTERNATE_OC3M_1         (0x1U<<16U)
#define TIM3_CCMR2_ALTERNATE_OC4CE          (0x1U<<15U)
#define TIM3_CCMR2_ALTERNATE_OC4M           (0x7U<<12U)
#define TIM3_CCMR2_ALTERNATE_OC4M_0         (0x1U<<12U)
#define TIM3_CCMR2_ALTERNATE_OC4PE          (0x1U<<11U)
#define TIM3_CCMR2_ALTERNATE_OC4FE          (0x1U<<10U)
#define TIM3_CCMR2_ALTERNATE_CC4S           (0x3U<<8U)
#define TIM3_CCMR2_ALTERNATE_CC4S_0         (0x1U<<8U)
#define TIM3_CCMR2_ALTERNATE_OC3CE          (0x1U<<7U)
#define TIM3_CCMR2_ALTERNATE_OC3M           (0x7U<<4U)
#define TIM3_CCMR2_ALTERNATE_OC3M_0         (0x1U<<4U)
#define TIM3_CCMR2_ALTERNATE_OC3PE          (0x1U<<3U)
#define TIM3_CCMR2_ALTERNATE_OC3FE          (0x1U<<2U)
#define TIM3_CCMR2_ALTERNATE_CC3S           (0x3U<<0U)
#define TIM3_CCMR2_ALTERNATE_CC3S_0         (0x1U<<0U)
#define TIM3_CCMR2_ALTERNATE_CC4S_B_0X0     (0x0U<<8U)
#define TIM3_CCMR2_ALTERNATE_CC4S_B_0X1     (0x1U<<8U)
#define TIM3_CCMR2_ALTERNATE_CC4S_B_0X2     (0x2U<<8U)
#define TIM3_CCMR2_ALTERNATE_CC4S_B_0X3     (0x3U<<8U)
#define TIM3_CCMR2_ALTERNATE_CC3S_B_0X0     (0x0U<<0U)
#define TIM3_CCMR2_ALTERNATE_CC3S_B_0X1     (0x1U<<0U)
#define TIM3_CCMR2_ALTERNATE_CC3S_B_0X2     (0x2U<<0U)
#define TIM3_CCMR2_ALTERNATE_CC3S_B_0X3     (0x3U<<0U)

// CCER Configuration

#define TIM3_CCER_CC4NP                     (0x1U<<15U)
#define TIM3_CCER_CC4P                      (0x1U<<13U)
#define TIM3_CCER_CC4E                      (0x1U<<12U)
#define TIM3_CCER_CC3NP                     (0x1U<<11U)
#define TIM3_CCER_CC3P                      (0x1U<<9U)
#define TIM3_CCER_CC3E                      (0x1U<<8U)
#define TIM3_CCER_CC2NP                     (0x1U<<7U)
#define TIM3_CCER_CC2P                      (0x1U<<5U)
#define TIM3_CCER_CC2E                      (0x1U<<4U)
#define TIM3_CCER_CC1NP                     (0x1U<<3U)
#define TIM3_CCER_CC1P                      (0x1U<<1U)
#define TIM3_CCER_CC1E                      (0x1U<<0U)
#define TIM3_CCER_CC1P_B_0X0                (0x0U<<1U)
#define TIM3_CCER_CC1P_B_0X1                (0x1U<<1U)
#define TIM3_CCER_CC1E_B_0X0                (0x0U<<0U)
#define TIM3_CCER_CC1E_B_0X1                (0x1U<<0U)

// CNT Configuration

#define TIM3_CNT_CNT                        (0xFFFFFFFFU<<0U)
#define TIM3_CNT_CNT_0                      (0x1U<<0U)

// CNT_ALTERNATE Configuration

#define TIM3_CNT_ALTERNATE_UIFCPY           (0x1U<<31U)
#define TIM3_CNT_ALTERNATE_CNT              (0x7FFFFFFFU<<0U)
#define TIM3_CNT_ALTERNATE_CNT_0            (0x1U<<0U)

// PSC Configuration

#define TIM3_PSC_PSC                        (0xFFFFU<<0U)
#define TIM3_PSC_PSC_0                      (0x1U<<0U)

// ARR Configuration

#define TIM3_ARR_ARR                        (0xFFFFFFFFU<<0U)
#define TIM3_ARR_ARR_0                      (0x1U<<0U)

// CCR1 Configuration

#define TIM3_CCR1_CCR1                      (0xFFFFFFFFU<<0U)
#define TIM3_CCR1_CCR1_0                    (0x1U<<0U)

// CCR2 Configuration

#define TIM3_CCR2_CCR2                      (0xFFFFFFFFU<<0U)
#define TIM3_CCR2_CCR2_0                    (0x1U<<0U)

// CCR3 Configuration

#define TIM3_CCR3_CCR3                      (0xFFFFFFFFU<<0U)
#define TIM3_CCR3_CCR3_0                    (0x1U<<0U)

// CCR4 Configuration

#define TIM3_CCR4_CCR4                      (0xFFFFFFFFU<<0U)
#define TIM3_CCR4_CCR4_0                    (0x1U<<0U)

// DCR Configuration

#define TIM3_DCR_DBL                        (0x1FU<<8U)
#define TIM3_DCR_DBL_0                      (0x1U<<8U)
#define TIM3_DCR_DBA                        (0x1FU<<0U)
#define TIM3_DCR_DBA_0                      (0x1U<<0U)
#define TIM3_DCR_DBL_B_0X0                  (0x0U<<8U)
#define TIM3_DCR_DBL_B_0X1                  (0x1U<<8U)
#define TIM3_DCR_DBL_B_0X2                  (0x2U<<8U)
#define TIM3_DCR_DBL_B_0X11                 (0x11U<<8U)
#define TIM3_DCR_DBA_B_0X0                  (0x0U<<0U)
#define TIM3_DCR_DBA_B_0X1                  (0x1U<<0U)
#define TIM3_DCR_DBA_B_0X2                  (0x2U<<0U)

// DMAR Configuration

#define TIM3_DMAR_DMAB                      (0xFFFFU<<0U)
#define TIM3_DMAR_DMAB_0                    (0x1U<<0U)

// AF1 Configuration

#define TIM3_AF1_ETRSEL                     (0xFU<<14U)
#define TIM3_AF1_ETRSEL_0                   (0x1U<<14U)
#define TIM3_AF1_ETRSEL_B_0X0               (0x0U<<14U)
#define TIM3_AF1_ETRSEL_B_0X1               (0x1U<<14U)
#define TIM3_AF1_ETRSEL_B_0X2               (0x2U<<14U)
#define TIM3_AF1_ETRSEL_B_0X3               (0x3U<<14U)
#define TIM3_AF1_ETRSEL_B_0X4               (0x4U<<14U)
#define TIM3_AF1_ETRSEL_B_0X5               (0x5U<<14U)

// TISEL Configuration

#define TIM3_TISEL_TI4SEL                   (0xFU<<24U)
#define TIM3_TISEL_TI4SEL_0                 (0x1U<<24U)
#define TIM3_TISEL_TI3SEL                   (0xFU<<16U)
#define TIM3_TISEL_TI3SEL_0                 (0x1U<<16U)
#define TIM3_TISEL_TI2SEL                   (0xFU<<8U)
#define TIM3_TISEL_TI2SEL_0                 (0x1U<<8U)
#define TIM3_TISEL_TI1SEL                   (0xFU<<0U)
#define TIM3_TISEL_TI1SEL_0                 (0x1U<<0U)
#define TIM3_TISEL_TI4SEL_B_0X0             (0x0U<<24U)
#define TIM3_TISEL_TI4SEL_B_0X1             (0x1U<<24U)
#define TIM3_TISEL_TI4SEL_B_0X2             (0x2U<<24U)
#define TIM3_TISEL_TI4SEL_B_0X3             (0x3U<<24U)
#define TIM3_TISEL_TI3SEL_B_0X0             (0x0U<<16U)
#define TIM3_TISEL_TI2SEL_B_0X0             (0x0U<<8U)
#define TIM3_TISEL_TI1SEL_B_0X0             (0x0U<<0U)
