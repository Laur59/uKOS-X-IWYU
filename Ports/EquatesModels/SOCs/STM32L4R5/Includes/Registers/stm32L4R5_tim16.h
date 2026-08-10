/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_tim16 equates.
 */

#pragma once

#include    <stdint.h>

// TIM16 address definitions
// -------------------------

typedef struct {
    volatile    uint16_t    CR1;
    volatile    uint16_t    RESERVED0;
    volatile    uint16_t    CR2;
    volatile    uint16_t    RESERVED1[3];
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
    volatile    uint16_t    RESERVED10[7];
    volatile    uint32_t    BDTR;
    volatile    uint16_t    DCR;
    volatile    uint16_t    RESERVED11;
    volatile    uint16_t    DMAR;
    volatile    uint16_t    RESERVED12[9];
    volatile    uint32_t    AF1;
    volatile    uint32_t    RESERVED13;
    volatile    uint32_t    TISEL;
} TIM16_TypeDef;

#ifdef __cplusplus
#define TIM16   reinterpret_cast<TIM16_TypeDef *>(0x40014400U)

#else
#define TIM16   ((TIM16_TypeDef *)0x40014400U)
#endif

// CR1 Configuration

#define TIM16_CR1_UIFREMAP                  (0x1U<<11U)
#define TIM16_CR1_CKD                       (0x3U<<8U)
#define TIM16_CR1_CKD_0                     (0x1U<<8U)
#define TIM16_CR1_ARPE                      (0x1U<<7U)
#define TIM16_CR1_OPM                       (0x1U<<3U)
#define TIM16_CR1_URS                       (0x1U<<2U)
#define TIM16_CR1_UDIS                      (0x1U<<1U)
#define TIM16_CR1_CEN                       (0x1U<<0U)
#define TIM16_CR1_UIFREMAP_B_0X0            (0x0U<<11U)
#define TIM16_CR1_UIFREMAP_B_0X1            (0x1U<<11U)
#define TIM16_CR1_CKD_B_0X0                 (0x0U<<8U)
#define TIM16_CR1_CKD_B_0X1                 (0x1U<<8U)
#define TIM16_CR1_CKD_B_0X2                 (0x2U<<8U)
#define TIM16_CR1_CKD_B_0X3                 (0x3U<<8U)
#define TIM16_CR1_ARPE_B_0X0                (0x0U<<7U)
#define TIM16_CR1_ARPE_B_0X1                (0x1U<<7U)
#define TIM16_CR1_OPM_B_0X0                 (0x0U<<3U)
#define TIM16_CR1_OPM_B_0X1                 (0x1U<<3U)
#define TIM16_CR1_URS_B_0X0                 (0x0U<<2U)
#define TIM16_CR1_URS_B_0X1                 (0x1U<<2U)
#define TIM16_CR1_UDIS_B_0X0                (0x0U<<1U)
#define TIM16_CR1_UDIS_B_0X1                (0x1U<<1U)
#define TIM16_CR1_CEN_B_0X0                 (0x0U<<0U)
#define TIM16_CR1_CEN_B_0X1                 (0x1U<<0U)

// CR2 Configuration

#define TIM16_CR2_OIS1N                     (0x1U<<9U)
#define TIM16_CR2_OIS1                      (0x1U<<8U)
#define TIM16_CR2_CCDS                      (0x1U<<3U)
#define TIM16_CR2_CCUS                      (0x1U<<2U)
#define TIM16_CR2_CCPC                      (0x1U<<0U)
#define TIM16_CR2_OIS1N_B_0X0               (0x0U<<9U)
#define TIM16_CR2_OIS1N_B_0X1               (0x1U<<9U)
#define TIM16_CR2_OIS1_B_0X0                (0x0U<<8U)
#define TIM16_CR2_OIS1_B_0X1                (0x1U<<8U)
#define TIM16_CR2_CCDS_B_0X0                (0x0U<<3U)
#define TIM16_CR2_CCDS_B_0X1                (0x1U<<3U)
#define TIM16_CR2_CCUS_B_0X0                (0x0U<<2U)
#define TIM16_CR2_CCUS_B_0X1                (0x1U<<2U)
#define TIM16_CR2_CCPC_B_0X0                (0x0U<<0U)
#define TIM16_CR2_CCPC_B_0X1                (0x1U<<0U)

// DIER Configuration

#define TIM16_DIER_CC1DE                    (0x1U<<9U)
#define TIM16_DIER_UDE                      (0x1U<<8U)
#define TIM16_DIER_BIE                      (0x1U<<7U)
#define TIM16_DIER_COMIE                    (0x1U<<5U)
#define TIM16_DIER_CC1IE                    (0x1U<<1U)
#define TIM16_DIER_UIE                      (0x1U<<0U)
#define TIM16_DIER_CC1DE_B_0X0              (0x0U<<9U)
#define TIM16_DIER_CC1DE_B_0X1              (0x1U<<9U)
#define TIM16_DIER_UDE_B_0X0                (0x0U<<8U)
#define TIM16_DIER_UDE_B_0X1                (0x1U<<8U)
#define TIM16_DIER_BIE_B_0X0                (0x0U<<7U)
#define TIM16_DIER_BIE_B_0X1                (0x1U<<7U)
#define TIM16_DIER_COMIE_B_0X0              (0x0U<<5U)
#define TIM16_DIER_COMIE_B_0X1              (0x1U<<5U)
#define TIM16_DIER_CC1IE_B_0X0              (0x0U<<1U)
#define TIM16_DIER_CC1IE_B_0X1              (0x1U<<1U)
#define TIM16_DIER_UIE_B_0X0                (0x0U<<0U)
#define TIM16_DIER_UIE_B_0X1                (0x1U<<0U)

// SR Configuration

#define TIM16_SR_CC1OF                      (0x1U<<9U)
#define TIM16_SR_BIF                        (0x1U<<7U)
#define TIM16_SR_COMIF                      (0x1U<<5U)
#define TIM16_SR_CC1IF                      (0x1U<<1U)
#define TIM16_SR_UIF                        (0x1U<<0U)
#define TIM16_SR_CC1OF_B_0X0                (0x0U<<9U)
#define TIM16_SR_CC1OF_B_0X1                (0x1U<<9U)
#define TIM16_SR_BIF_B_0X0                  (0x0U<<7U)
#define TIM16_SR_BIF_B_0X1                  (0x1U<<7U)
#define TIM16_SR_COMIF_B_0X0                (0x0U<<5U)
#define TIM16_SR_COMIF_B_0X1                (0x1U<<5U)
#define TIM16_SR_CC1IF_B_0X0                (0x0U<<1U)
#define TIM16_SR_CC1IF_B_0X1                (0x1U<<1U)
#define TIM16_SR_UIF_B_0X0                  (0x0U<<0U)
#define TIM16_SR_UIF_B_0X1                  (0x1U<<0U)

// EGR Configuration

#define TIM16_EGR_BG                        (0x1U<<7U)
#define TIM16_EGR_COMG                      (0x1U<<5U)
#define TIM16_EGR_CC1G                      (0x1U<<1U)
#define TIM16_EGR_UG                        (0x1U<<0U)
#define TIM16_EGR_BG_B_0X0                  (0x0U<<7U)
#define TIM16_EGR_BG_B_0X1                  (0x1U<<7U)
#define TIM16_EGR_COMG_B_0X0                (0x0U<<5U)
#define TIM16_EGR_COMG_B_0X1                (0x1U<<5U)
#define TIM16_EGR_CC1G_B_0X0                (0x0U<<1U)
#define TIM16_EGR_CC1G_B_0X1                (0x1U<<1U)
#define TIM16_EGR_UG_B_0X0                  (0x0U<<0U)
#define TIM16_EGR_UG_B_0X1                  (0x1U<<0U)

// CCMR1 Configuration

#define TIM16_CCMR1_IC1F                    (0xFU<<4U)
#define TIM16_CCMR1_IC1F_0                  (0x1U<<4U)
#define TIM16_CCMR1_IC1PSC                  (0x3U<<2U)
#define TIM16_CCMR1_IC1PSC_0                (0x1U<<2U)
#define TIM16_CCMR1_CC1S                    (0x3U<<0U)
#define TIM16_CCMR1_CC1S_0                  (0x1U<<0U)
#define TIM16_CCMR1_IC1F_B_0X0              (0x0U<<4U)
#define TIM16_CCMR1_IC1F_B_0X1              (0x1U<<4U)
#define TIM16_CCMR1_IC1F_B_0X2              (0x2U<<4U)
#define TIM16_CCMR1_IC1F_B_0X3              (0x3U<<4U)
#define TIM16_CCMR1_IC1F_B_0X4              (0x4U<<4U)
#define TIM16_CCMR1_IC1F_B_0X5              (0x5U<<4U)
#define TIM16_CCMR1_IC1F_B_0X6              (0x6U<<4U)
#define TIM16_CCMR1_IC1F_B_0X7              (0x7U<<4U)
#define TIM16_CCMR1_IC1F_B_0X8              (0x8U<<4U)
#define TIM16_CCMR1_IC1F_B_0X9              (0x9U<<4U)
#define TIM16_CCMR1_IC1F_B_0XA              (0xAU<<4U)
#define TIM16_CCMR1_IC1F_B_0XB              (0xBU<<4U)
#define TIM16_CCMR1_IC1F_B_0XC              (0xCU<<4U)
#define TIM16_CCMR1_IC1F_B_0XD              (0xDU<<4U)
#define TIM16_CCMR1_IC1F_B_0XE              (0xEU<<4U)
#define TIM16_CCMR1_IC1F_B_0XF              (0xFU<<4U)
#define TIM16_CCMR1_IC1PSC_B_0X0            (0x0U<<2U)
#define TIM16_CCMR1_IC1PSC_B_0X1            (0x1U<<2U)
#define TIM16_CCMR1_IC1PSC_B_0X2            (0x2U<<2U)
#define TIM16_CCMR1_IC1PSC_B_0X3            (0x3U<<2U)
#define TIM16_CCMR1_CC1S_B_0X0              (0x0U<<0U)
#define TIM16_CCMR1_CC1S_B_0X1              (0x1U<<0U)

// CCMR1_ALTERNATE Configuration

#define TIM16_CCMR1_ALTERNATE_OC1M_1        (0x1U<<16U)
#define TIM16_CCMR1_ALTERNATE_OC1M          (0x7U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_0        (0x1U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1PE         (0x1U<<3U)
#define TIM16_CCMR1_ALTERNATE_OC1FE         (0x1U<<2U)
#define TIM16_CCMR1_ALTERNATE_CC1S          (0x3U<<0U)
#define TIM16_CCMR1_ALTERNATE_CC1S_0        (0x1U<<0U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X0    (0x0U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X1    (0x1U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X2    (0x2U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X3    (0x3U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X4    (0x4U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X5    (0x5U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X6    (0x6U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1M_B_0X7    (0x7U<<4U)
#define TIM16_CCMR1_ALTERNATE_OC1PE_B_0X0   (0x0U<<3U)
#define TIM16_CCMR1_ALTERNATE_OC1PE_B_0X1   (0x1U<<3U)
#define TIM16_CCMR1_ALTERNATE_OC1FE_B_0X0   (0x0U<<2U)
#define TIM16_CCMR1_ALTERNATE_OC1FE_B_0X1   (0x1U<<2U)
#define TIM16_CCMR1_ALTERNATE_CC1S_B_0X0    (0x0U<<0U)
#define TIM16_CCMR1_ALTERNATE_CC1S_B_0X1    (0x1U<<0U)

// CCER Configuration

#define TIM16_CCER_CC1NP                    (0x1U<<3U)
#define TIM16_CCER_CC1NE                    (0x1U<<2U)
#define TIM16_CCER_CC1P                     (0x1U<<1U)
#define TIM16_CCER_CC1E                     (0x1U<<0U)
#define TIM16_CCER_CC1NP_B_0X0              (0x0U<<3U)
#define TIM16_CCER_CC1NP_B_0X1              (0x1U<<3U)
#define TIM16_CCER_CC1NE_B_0X0              (0x0U<<2U)
#define TIM16_CCER_CC1NE_B_0X1              (0x1U<<2U)
#define TIM16_CCER_CC1P_B_0X0               (0x0U<<1U)
#define TIM16_CCER_CC1P_B_0X1               (0x1U<<1U)
#define TIM16_CCER_CC1E_B_0X0               (0x0U<<0U)
#define TIM16_CCER_CC1E_B_0X1               (0x1U<<0U)

// CNT Configuration

#define TIM16_CNT_UIFCPY                    (0x1U<<31U)
#define TIM16_CNT_CNT                       (0xFFFFU<<0U)
#define TIM16_CNT_CNT_0                     (0x1U<<0U)

// PSC Configuration

#define TIM16_PSC_PSC                       (0xFFFFU<<0U)
#define TIM16_PSC_PSC_0                     (0x1U<<0U)

// ARR Configuration

#define TIM16_ARR_ARR                       (0xFFFFU<<0U)
#define TIM16_ARR_ARR_0                     (0x1U<<0U)

// RCR Configuration

#define TIM16_RCR_REP                       (0xFFU<<0U)
#define TIM16_RCR_REP_0                     (0x1U<<0U)

// CCR1 Configuration

#define TIM16_CCR1_CCR1                     (0xFFFFU<<0U)
#define TIM16_CCR1_CCR1_0                   (0x1U<<0U)

// BDTR Configuration

#define TIM16_BDTR_BKF                      (0xFU<<16U)
#define TIM16_BDTR_BKF_0                    (0x1U<<16U)
#define TIM16_BDTR_MOE                      (0x1U<<15U)
#define TIM16_BDTR_AOE                      (0x1U<<14U)
#define TIM16_BDTR_BKP                      (0x1U<<13U)
#define TIM16_BDTR_BKE                      (0x1U<<12U)
#define TIM16_BDTR_OSSR                     (0x1U<<11U)
#define TIM16_BDTR_OSSI                     (0x1U<<10U)
#define TIM16_BDTR_LOCK                     (0x3U<<8U)
#define TIM16_BDTR_LOCK_0                   (0x1U<<8U)
#define TIM16_BDTR_DTG                      (0xFFU<<0U)
#define TIM16_BDTR_DTG_0                    (0x1U<<0U)
#define TIM16_BDTR_BKF_B_0X0                (0x0U<<16U)
#define TIM16_BDTR_BKF_B_0X1                (0x1U<<16U)
#define TIM16_BDTR_BKF_B_0X2                (0x2U<<16U)
#define TIM16_BDTR_BKF_B_0X3                (0x3U<<16U)
#define TIM16_BDTR_BKF_B_0X4                (0x4U<<16U)
#define TIM16_BDTR_BKF_B_0X5                (0x5U<<16U)
#define TIM16_BDTR_BKF_B_0X6                (0x6U<<16U)
#define TIM16_BDTR_BKF_B_0X7                (0x7U<<16U)
#define TIM16_BDTR_BKF_B_0X8                (0x8U<<16U)
#define TIM16_BDTR_BKF_B_0X9                (0x9U<<16U)
#define TIM16_BDTR_BKF_B_0XA                (0xAU<<16U)
#define TIM16_BDTR_BKF_B_0XB                (0xBU<<16U)
#define TIM16_BDTR_BKF_B_0XC                (0xCU<<16U)
#define TIM16_BDTR_BKF_B_0XD                (0xDU<<16U)
#define TIM16_BDTR_BKF_B_0XE                (0xEU<<16U)
#define TIM16_BDTR_BKF_B_0XF                (0xFU<<16U)
#define TIM16_BDTR_MOE_B_0X0                (0x0U<<15U)
#define TIM16_BDTR_MOE_B_0X1                (0x1U<<15U)
#define TIM16_BDTR_AOE_B_0X0                (0x0U<<14U)
#define TIM16_BDTR_AOE_B_0X1                (0x1U<<14U)
#define TIM16_BDTR_BKP_B_0X0                (0x0U<<13U)
#define TIM16_BDTR_BKP_B_0X1                (0x1U<<13U)
#define TIM16_BDTR_BKE_B_0X0                (0x0U<<12U)
#define TIM16_BDTR_OSSR_B_0X0               (0x0U<<11U)
#define TIM16_BDTR_OSSR_B_0X1               (0x1U<<11U)
#define TIM16_BDTR_OSSI_B_0X0               (0x0U<<10U)
#define TIM16_BDTR_OSSI_B_0X1               (0x1U<<10U)
#define TIM16_BDTR_LOCK_B_0X0               (0x0U<<8U)
#define TIM16_BDTR_LOCK_B_0X1               (0x1U<<8U)
#define TIM16_BDTR_LOCK_B_0X2               (0x2U<<8U)
#define TIM16_BDTR_LOCK_B_0X3               (0x3U<<8U)

// DCR Configuration

#define TIM16_DCR_DBL                       (0x1FU<<8U)
#define TIM16_DCR_DBL_0                     (0x1U<<8U)
#define TIM16_DCR_DBA                       (0x1FU<<0U)
#define TIM16_DCR_DBA_0                     (0x1U<<0U)
#define TIM16_DCR_DBL_B_0X0                 (0x0U<<8U)
#define TIM16_DCR_DBL_B_0X1                 (0x1U<<8U)
#define TIM16_DCR_DBL_B_0X2                 (0x2U<<8U)
#define TIM16_DCR_DBL_B_0X11                (0x11U<<8U)
#define TIM16_DCR_DBA_B_0X0                 (0x0U<<0U)
#define TIM16_DCR_DBA_B_0X1                 (0x1U<<0U)
#define TIM16_DCR_DBA_B_0X2                 (0x2U<<0U)

// DMAR Configuration

#define TIM16_DMAR_DMAB                     (0xFFFFU<<0U)
#define TIM16_DMAR_DMAB_0                   (0x1U<<0U)

// AF1 Configuration

#define TIM16_AF1_BKCMP2P                   (0x1U<<11U)
#define TIM16_AF1_BKCMP1P                   (0x1U<<10U)
#define TIM16_AF1_BKINP                     (0x1U<<9U)
#define TIM16_AF1_BKDF1BK1E                 (0x1U<<8U)
#define TIM16_AF1_BKCMP2E                   (0x1U<<2U)
#define TIM16_AF1_BKCMP1E                   (0x1U<<1U)
#define TIM16_AF1_BKINE                     (0x1U<<0U)
#define TIM16_AF1_BKCMP2P_B_0X0             (0x0U<<11U)
#define TIM16_AF1_BKCMP2P_B_0X1             (0x1U<<11U)
#define TIM16_AF1_BKCMP1P_B_0X0             (0x0U<<10U)
#define TIM16_AF1_BKCMP1P_B_0X1             (0x1U<<10U)
#define TIM16_AF1_BKINP_B_0X0               (0x0U<<9U)
#define TIM16_AF1_BKINP_B_0X1               (0x1U<<9U)
#define TIM16_AF1_BKDF1BK1E_B_0X0           (0x0U<<8U)
#define TIM16_AF1_BKDF1BK1E_B_0X1           (0x1U<<8U)
#define TIM16_AF1_BKCMP2E_B_0X0             (0x0U<<2U)
#define TIM16_AF1_BKCMP2E_B_0X1             (0x1U<<2U)
#define TIM16_AF1_BKCMP1E_B_0X0             (0x0U<<1U)
#define TIM16_AF1_BKCMP1E_B_0X1             (0x1U<<1U)
#define TIM16_AF1_BKINE_B_0X0               (0x0U<<0U)
#define TIM16_AF1_BKINE_B_0X1               (0x1U<<0U)

// TISEL Configuration

#define TIM16_TISEL_TI1SEL                  (0xFU<<0U)
#define TIM16_TISEL_TI1SEL_0                (0x1U<<0U)
#define TIM16_TISEL_TI1SEL_B_0X0            (0x0U<<0U)
#define TIM16_TISEL_TI1SEL_B_0X1            (0x1U<<0U)
#define TIM16_TISEL_TI1SEL_B_0X2            (0x2U<<0U)
#define TIM16_TISEL_TI1SEL_B_0X3            (0x3U<<0U)
