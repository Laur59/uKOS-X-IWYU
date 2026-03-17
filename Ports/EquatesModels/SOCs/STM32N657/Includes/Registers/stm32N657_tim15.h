/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_tim15.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_tim15 equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// TIM15 address definitions
// -------------------------

typedef struct {
    volatile    uint16_t    CR1;
    volatile    uint16_t    RESERVED0;
    volatile    uint32_t    CR2;
    volatile    uint32_t    SMCR;
    volatile    uint16_t    DIER;
    volatile    uint16_t    RESERVED1;
    volatile    uint16_t    SR;
    volatile    uint16_t    RESERVED2;
    volatile    uint16_t    EGR;
    volatile    uint16_t    RESERVED3;
    volatile    uint32_t    CCMR1;
    volatile    uint32_t    RESERVED4;
    volatile    uint16_t    CCER;
    volatile    uint16_t    RESERVED5;
    volatile    uint32_t    CNT;
    volatile    uint16_t    PSC;
    volatile    uint16_t    RESERVED6;
    volatile    uint32_t    ARR;
    volatile    uint16_t    RCR;
    volatile    uint16_t    RESERVED7;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    CCR2;
    volatile    uint32_t    RESERVED8[2];
    volatile    uint32_t    BDTR;
    volatile    uint32_t    RESERVED9[3];
    volatile    uint32_t    DTR2;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    TISEL;
    volatile    uint32_t    AF1;
    volatile    uint32_t    AF2;
    volatile    uint32_t    RESERVED11[221];
    volatile    uint32_t    DCR;
    volatile    uint32_t    DMAR;
} TIM15_TypeDef;

#ifdef __cplusplus
#define TIM15_S reinterpret_cast<TIM15_TypeDef *>(0x52004000U)

#else
#define TIM15_S ((TIM15_TypeDef *)0x52004000U)
#endif

// CR1 Configuration

#define TIM15_CR1_DITHEN            (0x1U<<12)
#define TIM15_CR1_UIFREMAP          (0x1U<<11)
#define TIM15_CR1_CKD               (0x3U<<8)
#define TIM15_CR1_CKD_0             (0x1U<<8)
#define TIM15_CR1_ARPE              (0x1U<<7)
#define TIM15_CR1_OPM               (0x1U<<3)
#define TIM15_CR1_URS               (0x1U<<2)
#define TIM15_CR1_UDIS              (0x1U<<1)
#define TIM15_CR1_CEN               (0x1U<<0)

#define TIM15_CR1_DITHEN_B_0X0      (0x0U<<12)
#define TIM15_CR1_DITHEN_B_0X1      (0x1U<<12)
#define TIM15_CR1_UIFREMAP_B_0X0    (0x0U<<11)
#define TIM15_CR1_UIFREMAP_B_0X1    (0x1U<<11)
#define TIM15_CR1_CKD_B_0X0         (0x0U<<8)
#define TIM15_CR1_CKD_B_0X1         (0x1U<<8)
#define TIM15_CR1_CKD_B_0X2         (0x2U<<8)
#define TIM15_CR1_ARPE_B_0X0        (0x0U<<7)
#define TIM15_CR1_ARPE_B_0X1        (0x1U<<7)
#define TIM15_CR1_OPM_B_0X0         (0x0U<<3)
#define TIM15_CR1_OPM_B_0X1         (0x1U<<3)
#define TIM15_CR1_URS_B_0X0         (0x0U<<2)
#define TIM15_CR1_URS_B_0X1         (0x1U<<2)
#define TIM15_CR1_UDIS_B_0X0        (0x0U<<1)
#define TIM15_CR1_UDIS_B_0X1        (0x1U<<1)
#define TIM15_CR1_CEN_B_0X0         (0x0U<<0)
#define TIM15_CR1_CEN_B_0X1         (0x1U<<0)

// CR2 Configuration

#define TIM15_CR2_ADSYNC            (0x1U<<28)
#define TIM15_CR2_OIS2              (0x1U<<10)
#define TIM15_CR2_OIS1N             (0x1U<<9)
#define TIM15_CR2_OIS1              (0x1U<<8)
#define TIM15_CR2_TI1S              (0x1U<<7)
#define TIM15_CR2_MMS               (0x7U<<4)
#define TIM15_CR2_MMS_0             (0x1U<<4)
#define TIM15_CR2_CCDS              (0x1U<<3)
#define TIM15_CR2_CCUS              (0x1U<<2)
#define TIM15_CR2_CCPC              (0x1U<<0)

#define TIM15_CR2_ADSYNC_B_0X0      (0x0U<<28)
#define TIM15_CR2_ADSYNC_B_0X1      (0x1U<<28)
#define TIM15_CR2_OIS2_B_0X0        (0x0U<<10)
#define TIM15_CR2_OIS2_B_0X1        (0x1U<<10)
#define TIM15_CR2_OIS1N_B_0X0       (0x0U<<9)
#define TIM15_CR2_OIS1N_B_0X1       (0x1U<<9)
#define TIM15_CR2_OIS1_B_0X0        (0x0U<<8)
#define TIM15_CR2_OIS1_B_0X1        (0x1U<<8)
#define TIM15_CR2_TI1S_B_0X0        (0x0U<<7)
#define TIM15_CR2_TI1S_B_0X1        (0x1U<<7)
#define TIM15_CR2_MMS_B_0X0         (0x0U<<4)
#define TIM15_CR2_MMS_B_0X1         (0x1U<<4)
#define TIM15_CR2_MMS_B_0X2         (0x2U<<4)
#define TIM15_CR2_MMS_B_0X3         (0x3U<<4)
#define TIM15_CR2_MMS_B_0X4         (0x4U<<4)
#define TIM15_CR2_MMS_B_0X5         (0x5U<<4)
#define TIM15_CR2_CCDS_B_0X0        (0x0U<<3)
#define TIM15_CR2_CCDS_B_0X1        (0x1U<<3)
#define TIM15_CR2_CCUS_B_0X0        (0x0U<<2)
#define TIM15_CR2_CCUS_B_0X1        (0x1U<<2)
#define TIM15_CR2_CCPC_B_0X0        (0x0U<<0)
#define TIM15_CR2_CCPC_B_0X1        (0x1U<<0)

// SMCR Configuration

#define TIM15_SMCR_SMSPE            (0x1U<<24)
#define TIM15_SMCR_TS_1             (0x3U<<20)
#define TIM15_SMCR_TS_1_0           (0x1U<<20)
#define TIM15_SMCR_SMS_1            (0x1U<<16)
#define TIM15_SMCR_MSM              (0x1U<<7)
#define TIM15_SMCR_TS               (0x7U<<4)
#define TIM15_SMCR_TS_0             (0x1U<<4)
#define TIM15_SMCR_SMS              (0x7U<<0)
#define TIM15_SMCR_SMS_0            (0x1U<<0)

#define TIM15_SMCR_SMSPE_B_0X0      (0x0U<<24)
#define TIM15_SMCR_SMSPE_B_0X1      (0x1U<<24)
#define TIM15_SMCR_MSM_B_0X0        (0x0U<<7)
#define TIM15_SMCR_MSM_B_0X1        (0x1U<<7)
#define TIM15_SMCR_TS_B_0X0         (0x0U<<4)
#define TIM15_SMCR_TS_B_0X1         (0x1U<<4)
#define TIM15_SMCR_TS_B_0X2         (0x2U<<4)
#define TIM15_SMCR_TS_B_0X3         (0x3U<<4)
#define TIM15_SMCR_TS_B_0X4         (0x4U<<4)
#define TIM15_SMCR_TS_B_0X5         (0x5U<<4)
#define TIM15_SMCR_TS_B_0X6         (0x6U<<4)
#define TIM15_SMCR_SMS_B_0X0        (0x0U<<0)
#define TIM15_SMCR_SMS_B_0X4        (0x4U<<0)
#define TIM15_SMCR_SMS_B_0X5        (0x5U<<0)
#define TIM15_SMCR_SMS_B_0X6        (0x6U<<0)
#define TIM15_SMCR_SMS_B_0X7        (0x7U<<0)

// DIER Configuration

#define TIM15_DIER_TDE              (0x1U<<14)
#define TIM15_DIER_COMDE            (0x1U<<13)
#define TIM15_DIER_CC2DE            (0x1U<<10)
#define TIM15_DIER_CC1DE            (0x1U<<9)
#define TIM15_DIER_UDE              (0x1U<<8)
#define TIM15_DIER_BIE              (0x1U<<7)
#define TIM15_DIER_TIE              (0x1U<<6)
#define TIM15_DIER_COMIE            (0x1U<<5)
#define TIM15_DIER_CC2IE            (0x1U<<2)
#define TIM15_DIER_CC1IE            (0x1U<<1)
#define TIM15_DIER_UIE              (0x1U<<0)

#define TIM15_DIER_TDE_B_0X0        (0x0U<<14)
#define TIM15_DIER_TDE_B_0X1        (0x1U<<14)
#define TIM15_DIER_COMDE_B_0X0      (0x0U<<13)
#define TIM15_DIER_COMDE_B_0X1      (0x1U<<13)
#define TIM15_DIER_CC2DE_B_0X0      (0x0U<<10)
#define TIM15_DIER_CC2DE_B_0X1      (0x1U<<10)
#define TIM15_DIER_CC1DE_B_0X0      (0x0U<<9)
#define TIM15_DIER_CC1DE_B_0X1      (0x1U<<9)
#define TIM15_DIER_UDE_B_0X0        (0x0U<<8)
#define TIM15_DIER_UDE_B_0X1        (0x1U<<8)
#define TIM15_DIER_BIE_B_0X0        (0x0U<<7)
#define TIM15_DIER_BIE_B_0X1        (0x1U<<7)
#define TIM15_DIER_TIE_B_0X0        (0x0U<<6)
#define TIM15_DIER_TIE_B_0X1        (0x1U<<6)
#define TIM15_DIER_COMIE_B_0X0      (0x0U<<5)
#define TIM15_DIER_COMIE_B_0X1      (0x1U<<5)
#define TIM15_DIER_CC2IE_B_0X0      (0x0U<<2)
#define TIM15_DIER_CC2IE_B_0X1      (0x1U<<2)
#define TIM15_DIER_CC1IE_B_0X0      (0x0U<<1)
#define TIM15_DIER_CC1IE_B_0X1      (0x1U<<1)
#define TIM15_DIER_UIE_B_0X0        (0x0U<<0)
#define TIM15_DIER_UIE_B_0X1        (0x1U<<0)

// SR Configuration

#define TIM15_SR_CC2OF              (0x1U<<10)
#define TIM15_SR_CC1OF              (0x1U<<9)
#define TIM15_SR_BIF                (0x1U<<7)
#define TIM15_SR_TIF                (0x1U<<6)
#define TIM15_SR_COMIF              (0x1U<<5)
#define TIM15_SR_CC2IF              (0x1U<<2)
#define TIM15_SR_CC1IF              (0x1U<<1)
#define TIM15_SR_UIF                (0x1U<<0)

#define TIM15_SR_CC1OF_B_0X0        (0x0U<<9)
#define TIM15_SR_CC1OF_B_0X1        (0x1U<<9)
#define TIM15_SR_BIF_B_0X0          (0x0U<<7)
#define TIM15_SR_BIF_B_0X1          (0x1U<<7)
#define TIM15_SR_TIF_B_0X0          (0x0U<<6)
#define TIM15_SR_TIF_B_0X1          (0x1U<<6)
#define TIM15_SR_COMIF_B_0X0        (0x0U<<5)
#define TIM15_SR_COMIF_B_0X1        (0x1U<<5)
#define TIM15_SR_CC1IF_B_0X0        (0x0U<<1)
#define TIM15_SR_CC1IF_B_0X1        (0x1U<<1)
#define TIM15_SR_UIF_B_0X0          (0x0U<<0)
#define TIM15_SR_UIF_B_0X1          (0x1U<<0)

// EGR Configuration

#define TIM15_EGR_BG                (0x1U<<7)
#define TIM15_EGR_TG                (0x1U<<6)
#define TIM15_EGR_COMG              (0x1U<<5)
#define TIM15_EGR_CC2G              (0x1U<<2)
#define TIM15_EGR_CC1G              (0x1U<<1)
#define TIM15_EGR_UG                (0x1U<<0)

#define TIM15_EGR_BG_B_0X0          (0x0U<<7)
#define TIM15_EGR_BG_B_0X1          (0x1U<<7)
#define TIM15_EGR_TG_B_0X0          (0x0U<<6)
#define TIM15_EGR_TG_B_0X1          (0x1U<<6)
#define TIM15_EGR_COMG_B_0X0        (0x0U<<5)
#define TIM15_EGR_COMG_B_0X1        (0x1U<<5)
#define TIM15_EGR_CC1G_B_0X0        (0x0U<<1)
#define TIM15_EGR_UG_B_0X0          (0x0U<<0)
#define TIM15_EGR_UG_B_0X1          (0x1U<<0)

// CCMR1 Configuration

#define TIM15_CCMR1_IC2F            (0xFU<<12)
#define TIM15_CCMR1_IC2F_0          (0x1U<<12)
#define TIM15_CCMR1_IC2PSC          (0x3U<<10)
#define TIM15_CCMR1_IC2PSC_0        (0x1U<<10)
#define TIM15_CCMR1_CC2S            (0x3U<<8)
#define TIM15_CCMR1_CC2S_0          (0x1U<<8)
#define TIM15_CCMR1_IC1F            (0xFU<<4)
#define TIM15_CCMR1_IC1F_0          (0x1U<<4)
#define TIM15_CCMR1_IC1PSC          (0x3U<<2)
#define TIM15_CCMR1_IC1PSC_0        (0x1U<<2)
#define TIM15_CCMR1_CC1S            (0x3U<<0)
#define TIM15_CCMR1_CC1S_0          (0x1U<<0)

#define TIM15_CCMR1_CC2S_B_0X0      (0x0U<<8)
#define TIM15_CCMR1_CC2S_B_0X1      (0x1U<<8)
#define TIM15_CCMR1_CC2S_B_0X2      (0x2U<<8)
#define TIM15_CCMR1_CC2S_B_0X3      (0x3U<<8)
#define TIM15_CCMR1_IC1F_B_0X0      (0x0U<<4)
#define TIM15_CCMR1_IC1F_B_0X1      (0x1U<<4)
#define TIM15_CCMR1_IC1F_B_0X2      (0x2U<<4)
#define TIM15_CCMR1_IC1F_B_0X3      (0x3U<<4)
#define TIM15_CCMR1_IC1F_B_0X4      (0x4U<<4)
#define TIM15_CCMR1_IC1F_B_0X5      (0x5U<<4)
#define TIM15_CCMR1_IC1F_B_0X6      (0x6U<<4)
#define TIM15_CCMR1_IC1F_B_0X7      (0x7U<<4)
#define TIM15_CCMR1_IC1F_B_0X8      (0x8U<<4)
#define TIM15_CCMR1_IC1F_B_0X9      (0x9U<<4)
#define TIM15_CCMR1_IC1F_B_0XA      (0xAU<<4)
#define TIM15_CCMR1_IC1F_B_0XB      (0xBU<<4)
#define TIM15_CCMR1_IC1F_B_0XC      (0xCU<<4)
#define TIM15_CCMR1_IC1F_B_0XD      (0xDU<<4)
#define TIM15_CCMR1_IC1F_B_0XE      (0xEU<<4)
#define TIM15_CCMR1_IC1F_B_0XF      (0xFU<<4)
#define TIM15_CCMR1_IC1PSC_B_0X0    (0x0U<<2)
#define TIM15_CCMR1_IC1PSC_B_0X1    (0x1U<<2)
#define TIM15_CCMR1_IC1PSC_B_0X2    (0x2U<<2)
#define TIM15_CCMR1_IC1PSC_B_0X3    (0x3U<<2)
#define TIM15_CCMR1_CC1S_B_0X0      (0x0U<<0)
#define TIM15_CCMR1_CC1S_B_0X1      (0x1U<<0)
#define TIM15_CCMR1_CC1S_B_0X2      (0x2U<<0)
#define TIM15_CCMR1_CC1S_B_0X3      (0x3U<<0)

// CCER Configuration

#define TIM15_CCER_CC2NP            (0x1U<<7)
#define TIM15_CCER_CC2P             (0x1U<<5)
#define TIM15_CCER_CC2E             (0x1U<<4)
#define TIM15_CCER_CC1NP            (0x1U<<3)
#define TIM15_CCER_CC1NE            (0x1U<<2)
#define TIM15_CCER_CC1P             (0x1U<<1)
#define TIM15_CCER_CC1E             (0x1U<<0)

#define TIM15_CCER_CC1NP_B_0X0      (0x0U<<3)
#define TIM15_CCER_CC1NP_B_0X1      (0x1U<<3)
#define TIM15_CCER_CC1NE_B_0X0      (0x0U<<2)
#define TIM15_CCER_CC1NE_B_0X1      (0x1U<<2)
#define TIM15_CCER_CC1P_B_0X0       (0x0U<<1)
#define TIM15_CCER_CC1P_B_0X1       (0x1U<<1)
#define TIM15_CCER_CC1E_B_0X0       (0x0U<<0)
#define TIM15_CCER_CC1E_B_0X1       (0x1U<<0)

// CNT Configuration

#define TIM15_CNT_UIFCPY            (0x1U<<31)
#define TIM15_CNT_CNT               (0xFFFFU<<0)
#define TIM15_CNT_CNT_0             (0x1U<<0)

// PSC Configuration

#define TIM15_PSC_PSC               (0xFFFFU<<0)
#define TIM15_PSC_PSC_0             (0x1U<<0)

// ARR Configuration

#define TIM15_ARR_ARR               (0xFFFFFU<<0)
#define TIM15_ARR_ARR_0             (0x1U<<0)

// RCR Configuration

#define TIM15_RCR_REP               (0xFFU<<0)
#define TIM15_RCR_REP_0             (0x1U<<0)

// CCR1 Configuration

#define TIM15_CCR1_CCR1             (0xFFFFFU<<0)
#define TIM15_CCR1_CCR1_0           (0x1U<<0)

// CCR2 Configuration

#define TIM15_CCR2_CCR2             (0xFFFFFU<<0)
#define TIM15_CCR2_CCR2_0           (0x1U<<0)

// BDTR Configuration

#define TIM15_BDTR_BKBID            (0x1U<<28)
#define TIM15_BDTR_BKDSRM           (0x1U<<26)
#define TIM15_BDTR_BKF              (0xFU<<16)
#define TIM15_BDTR_BKF_0            (0x1U<<16)
#define TIM15_BDTR_MOE              (0x1U<<15)
#define TIM15_BDTR_AOE              (0x1U<<14)
#define TIM15_BDTR_BKP              (0x1U<<13)
#define TIM15_BDTR_BKE              (0x1U<<12)
#define TIM15_BDTR_OSSR             (0x1U<<11)
#define TIM15_BDTR_OSSI             (0x1U<<10)
#define TIM15_BDTR_LOCK             (0x3U<<8)
#define TIM15_BDTR_LOCK_0           (0x1U<<8)
#define TIM15_BDTR_DTG              (0xFFU<<0)
#define TIM15_BDTR_DTG_0            (0x1U<<0)

#define TIM15_BDTR_BKBID_B_0X0      (0x0U<<28)
#define TIM15_BDTR_BKBID_B_0X1      (0x1U<<28)
#define TIM15_BDTR_BKDSRM_B_0X0     (0x0U<<26)
#define TIM15_BDTR_BKDSRM_B_0X1     (0x1U<<26)
#define TIM15_BDTR_BKF_B_0X0        (0x0U<<16)
#define TIM15_BDTR_BKF_B_0X1        (0x1U<<16)
#define TIM15_BDTR_BKF_B_0X2        (0x2U<<16)
#define TIM15_BDTR_BKF_B_0X3        (0x3U<<16)
#define TIM15_BDTR_BKF_B_0X4        (0x4U<<16)
#define TIM15_BDTR_BKF_B_0X5        (0x5U<<16)
#define TIM15_BDTR_BKF_B_0X6        (0x6U<<16)
#define TIM15_BDTR_BKF_B_0X7        (0x7U<<16)
#define TIM15_BDTR_BKF_B_0X8        (0x8U<<16)
#define TIM15_BDTR_BKF_B_0X9        (0x9U<<16)
#define TIM15_BDTR_BKF_B_0XA        (0xAU<<16)
#define TIM15_BDTR_BKF_B_0XB        (0xBU<<16)
#define TIM15_BDTR_BKF_B_0XC        (0xCU<<16)
#define TIM15_BDTR_BKF_B_0XD        (0xDU<<16)
#define TIM15_BDTR_BKF_B_0XE        (0xEU<<16)
#define TIM15_BDTR_BKF_B_0XF        (0xFU<<16)
#define TIM15_BDTR_MOE_B_0X0        (0x0U<<15)
#define TIM15_BDTR_MOE_B_0X1        (0x1U<<15)
#define TIM15_BDTR_AOE_B_0X0        (0x0U<<14)
#define TIM15_BDTR_AOE_B_0X1        (0x1U<<14)
#define TIM15_BDTR_BKP_B_0X0        (0x0U<<13)
#define TIM15_BDTR_BKP_B_0X1        (0x1U<<13)
#define TIM15_BDTR_BKE_B_0X0        (0x0U<<12)
#define TIM15_BDTR_OSSR_B_0X0       (0x0U<<11)
#define TIM15_BDTR_OSSR_B_0X1       (0x1U<<11)
#define TIM15_BDTR_OSSI_B_0X0       (0x0U<<10)
#define TIM15_BDTR_OSSI_B_0X1       (0x1U<<10)
#define TIM15_BDTR_LOCK_B_0X0       (0x0U<<8)
#define TIM15_BDTR_LOCK_B_0X1       (0x1U<<8)
#define TIM15_BDTR_LOCK_B_0X2       (0x2U<<8)
#define TIM15_BDTR_LOCK_B_0X3       (0x3U<<8)

// DTR2 Configuration

#define TIM15_DTR2_DTPE             (0x1U<<17)
#define TIM15_DTR2_DTAE             (0x1U<<16)
#define TIM15_DTR2_DTGF             (0xFFU<<0)
#define TIM15_DTR2_DTGF_0           (0x1U<<0)

#define TIM15_DTR2_DTPE_B_0X0       (0x0U<<17)
#define TIM15_DTR2_DTPE_B_0X1       (0x1U<<17)
#define TIM15_DTR2_DTAE_B_0X0       (0x0U<<16)
#define TIM15_DTR2_DTAE_B_0X1       (0x1U<<16)

// TISEL Configuration

#define TIM15_TISEL_TI2SEL          (0xFU<<8)
#define TIM15_TISEL_TI2SEL_0        (0x1U<<8)
#define TIM15_TISEL_TI1SEL          (0xFU<<0)
#define TIM15_TISEL_TI1SEL_0        (0x1U<<0)

#define TIM15_TISEL_TI2SEL_B_0X0    (0x0U<<8)
#define TIM15_TISEL_TI2SEL_B_0X1    (0x1U<<8)
#define TIM15_TISEL_TI2SEL_B_0XF    (0xFU<<8)
#define TIM15_TISEL_TI1SEL_B_0X0    (0x0U<<0)
#define TIM15_TISEL_TI1SEL_B_0X1    (0x1U<<0)
#define TIM15_TISEL_TI1SEL_B_0XF    (0xFU<<0)

// AF1 Configuration

#define TIM15_AF1_BKCMP4P           (0x1U<<13)
#define TIM15_AF1_BKCMP3P           (0x1U<<12)
#define TIM15_AF1_BKCMP2P           (0x1U<<11)
#define TIM15_AF1_BKCMP1P           (0x1U<<10)
#define TIM15_AF1_BKINP             (0x1U<<9)
#define TIM15_AF1_BKCMP8E           (0x1U<<8)
#define TIM15_AF1_BKCMP7E           (0x1U<<7)
#define TIM15_AF1_BKCMP6E           (0x1U<<6)
#define TIM15_AF1_BKCMP5E           (0x1U<<5)
#define TIM15_AF1_BKCMP4E           (0x1U<<4)
#define TIM15_AF1_BKCMP3E           (0x1U<<3)
#define TIM15_AF1_BKCMP2E           (0x1U<<2)
#define TIM15_AF1_BKCMP1E           (0x1U<<1)
#define TIM15_AF1_BKINE             (0x1U<<0)

#define TIM15_AF1_BKCMP4P_B_0X0     (0x0U<<13)
#define TIM15_AF1_BKCMP4P_B_0X1     (0x1U<<13)
#define TIM15_AF1_BKCMP3P_B_0X0     (0x0U<<12)
#define TIM15_AF1_BKCMP3P_B_0X1     (0x1U<<12)
#define TIM15_AF1_BKCMP2P_B_0X0     (0x0U<<11)
#define TIM15_AF1_BKCMP2P_B_0X1     (0x1U<<11)
#define TIM15_AF1_BKCMP1P_B_0X0     (0x0U<<10)
#define TIM15_AF1_BKCMP1P_B_0X1     (0x1U<<10)
#define TIM15_AF1_BKINP_B_0X0       (0x0U<<9)
#define TIM15_AF1_BKINP_B_0X1       (0x1U<<9)
#define TIM15_AF1_BKCMP8E_B_0X0     (0x0U<<8)
#define TIM15_AF1_BKCMP8E_B_0X1     (0x1U<<8)
#define TIM15_AF1_BKCMP7E_B_0X0     (0x0U<<7)
#define TIM15_AF1_BKCMP7E_B_0X1     (0x1U<<7)
#define TIM15_AF1_BKCMP6E_B_0X0     (0x0U<<6)
#define TIM15_AF1_BKCMP6E_B_0X1     (0x1U<<6)
#define TIM15_AF1_BKCMP5E_B_0X0     (0x0U<<5)
#define TIM15_AF1_BKCMP5E_B_0X1     (0x1U<<5)
#define TIM15_AF1_BKCMP4E_B_0X0     (0x0U<<4)
#define TIM15_AF1_BKCMP4E_B_0X1     (0x1U<<4)
#define TIM15_AF1_BKCMP3E_B_0X0     (0x0U<<3)
#define TIM15_AF1_BKCMP3E_B_0X1     (0x1U<<3)
#define TIM15_AF1_BKCMP2E_B_0X0     (0x0U<<2)
#define TIM15_AF1_BKCMP2E_B_0X1     (0x1U<<2)
#define TIM15_AF1_BKCMP1E_B_0X0     (0x0U<<1)
#define TIM15_AF1_BKCMP1E_B_0X1     (0x1U<<1)
#define TIM15_AF1_BKINE_B_0X0       (0x0U<<0)
#define TIM15_AF1_BKINE_B_0X1       (0x1U<<0)

// AF2 Configuration

#define TIM15_AF2_OCRSEL            (0x7U<<16)
#define TIM15_AF2_OCRSEL_0          (0x1U<<16)

#define TIM15_AF2_OCRSEL_B_0X0      (0x0U<<16)
#define TIM15_AF2_OCRSEL_B_0X1      (0x1U<<16)
#define TIM15_AF2_OCRSEL_B_0X2      (0x2U<<16)
#define TIM15_AF2_OCRSEL_B_0X3      (0x3U<<16)
#define TIM15_AF2_OCRSEL_B_0X4      (0x4U<<16)
#define TIM15_AF2_OCRSEL_B_0X5      (0x5U<<16)
#define TIM15_AF2_OCRSEL_B_0X6      (0x6U<<16)
#define TIM15_AF2_OCRSEL_B_0X7      (0x7U<<16)

// DCR Configuration

#define TIM15_DCR_DBSS              (0xFU<<16)
#define TIM15_DCR_DBSS_0            (0x1U<<16)
#define TIM15_DCR_DBL               (0x1FU<<8)
#define TIM15_DCR_DBL_0             (0x1U<<8)
#define TIM15_DCR_DBA               (0x1FU<<0)
#define TIM15_DCR_DBA_0             (0x1U<<0)

#define TIM15_DCR_DBSS_B_0X1        (0x1U<<16)
#define TIM15_DCR_DBSS_B_0X2        (0x2U<<16)
#define TIM15_DCR_DBSS_B_0X3        (0x3U<<16)
#define TIM15_DCR_DBSS_B_0X6        (0x6U<<16)
#define TIM15_DCR_DBSS_B_0X7        (0x7U<<16)
#define TIM15_DCR_DBL_B_0X0         (0x0U<<8)
#define TIM15_DCR_DBL_B_0X1         (0x1U<<8)
#define TIM15_DCR_DBL_B_0X2         (0x2U<<8)
#define TIM15_DCR_DBL_B_0X11        (0x11U<<8)
#define TIM15_DCR_DBA_B_0X0         (0x0U<<0)
#define TIM15_DCR_DBA_B_0X1         (0x1U<<0)
#define TIM15_DCR_DBA_B_0X2         (0x2U<<0)

// DMAR Configuration

#define TIM15_DMAR_DMAB             (0xFFFFFFFFU<<0)
#define TIM15_DMAR_DMAB_0           (0x1U<<0)
