/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_tim9 equates.
 */

#pragma once

#include    <stdint.h>

// TIM9 address definitions
// ------------------------

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
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    CCR2;
    volatile    uint32_t    RESERVED8[8];
    volatile    uint16_t    TISEL;
} TIM9_TypeDef;

#ifdef __cplusplus
#define TIM9_NS reinterpret_cast<TIM9_TypeDef *>(0x42004C00U)
#define TIM9_S  reinterpret_cast<TIM9_TypeDef *>(0x52004C00U)

#else
#define TIM9_NS ((TIM9_TypeDef *)0x42004C00U)
#define TIM9_S  ((TIM9_TypeDef *)0x52004C00U)
#endif

// CR1 Configuration

#define TIM9_CR1_DITHEN             (0x1U<<12U)
#define TIM9_CR1_UIFREMAP           (0x1U<<11U)
#define TIM9_CR1_CKD                (0x3U<<8U)
#define TIM9_CR1_CKD_0              (0x1U<<8U)
#define TIM9_CR1_ARPE               (0x1U<<7U)
#define TIM9_CR1_OPM                (0x1U<<3U)
#define TIM9_CR1_URS                (0x1U<<2U)
#define TIM9_CR1_UDIS               (0x1U<<1U)
#define TIM9_CR1_CEN                (0x1U<<0U)

#define TIM9_CR1_DITHEN_B_0X0       (0x0U<<12U)
#define TIM9_CR1_DITHEN_B_0X1       (0x1U<<12U)
#define TIM9_CR1_UIFREMAP_B_0X0     (0x0U<<11U)
#define TIM9_CR1_UIFREMAP_B_0X1     (0x1U<<11U)
#define TIM9_CR1_CKD_B_0X0          (0x0U<<8U)
#define TIM9_CR1_CKD_B_0X1          (0x1U<<8U)
#define TIM9_CR1_CKD_B_0X2          (0x2U<<8U)
#define TIM9_CR1_ARPE_B_0X0         (0x0U<<7U)
#define TIM9_CR1_ARPE_B_0X1         (0x1U<<7U)
#define TIM9_CR1_OPM_B_0X0          (0x0U<<3U)
#define TIM9_CR1_OPM_B_0X1          (0x1U<<3U)
#define TIM9_CR1_URS_B_0X0          (0x0U<<2U)
#define TIM9_CR1_URS_B_0X1          (0x1U<<2U)
#define TIM9_CR1_UDIS_B_0X0         (0x0U<<1U)
#define TIM9_CR1_UDIS_B_0X1         (0x1U<<1U)
#define TIM9_CR1_CEN_B_0X0          (0x0U<<0U)
#define TIM9_CR1_CEN_B_0X1          (0x1U<<0U)

// CR2 Configuration

#define TIM9_CR2_ADSYNC             (0x1U<<28U)
#define TIM9_CR2_TI1S               (0x1U<<7U)
#define TIM9_CR2_MMS                (0x7U<<4U)
#define TIM9_CR2_MMS_0              (0x1U<<4U)

#define TIM9_CR2_ADSYNC_B_0X0       (0x0U<<28U)
#define TIM9_CR2_ADSYNC_B_0X1       (0x1U<<28U)
#define TIM9_CR2_TI1S_B_0X0         (0x0U<<7U)
#define TIM9_CR2_TI1S_B_0X1         (0x1U<<7U)
#define TIM9_CR2_MMS_B_0X0          (0x0U<<4U)
#define TIM9_CR2_MMS_B_0X1          (0x1U<<4U)
#define TIM9_CR2_MMS_B_0X2          (0x2U<<4U)
#define TIM9_CR2_MMS_B_0X3          (0x3U<<4U)
#define TIM9_CR2_MMS_B_0X4          (0x4U<<4U)
#define TIM9_CR2_MMS_B_0X5          (0x5U<<4U)

// SMCR Configuration

#define TIM9_SMCR_TS_1              (0x3U<<20U)
#define TIM9_SMCR_TS_1_0            (0x1U<<20U)
#define TIM9_SMCR_SMS_1             (0x1U<<16U)
#define TIM9_SMCR_MSM               (0x1U<<7U)
#define TIM9_SMCR_TS                (0x7U<<4U)
#define TIM9_SMCR_TS_0              (0x1U<<4U)
#define TIM9_SMCR_SMS               (0x7U<<0U)
#define TIM9_SMCR_SMS_0             (0x1U<<0U)

#define TIM9_SMCR_MSM_B_0X0         (0x0U<<7U)
#define TIM9_SMCR_MSM_B_0X1         (0x1U<<7U)
#define TIM9_SMCR_TS_B_0X0          (0x0U<<4U)
#define TIM9_SMCR_TS_B_0X1          (0x1U<<4U)
#define TIM9_SMCR_TS_B_0X2          (0x2U<<4U)
#define TIM9_SMCR_TS_B_0X3          (0x3U<<4U)
#define TIM9_SMCR_TS_B_0X4          (0x4U<<4U)
#define TIM9_SMCR_TS_B_0X5          (0x5U<<4U)
#define TIM9_SMCR_TS_B_0X6          (0x6U<<4U)
#define TIM9_SMCR_SMS_B_0X0         (0x0U<<0U)
#define TIM9_SMCR_SMS_B_0X4         (0x4U<<0U)
#define TIM9_SMCR_SMS_B_0X5         (0x5U<<0U)
#define TIM9_SMCR_SMS_B_0X6         (0x6U<<0U)
#define TIM9_SMCR_SMS_B_0X7         (0x7U<<0U)

// DIER Configuration

#define TIM9_DIER_TIE               (0x1U<<6U)
#define TIM9_DIER_CC2IE             (0x1U<<2U)
#define TIM9_DIER_CC1IE             (0x1U<<1U)
#define TIM9_DIER_UIE               (0x1U<<0U)

#define TIM9_DIER_TIE_B_0X0         (0x0U<<6U)
#define TIM9_DIER_TIE_B_0X1         (0x1U<<6U)
#define TIM9_DIER_CC2IE_B_0X0       (0x0U<<2U)
#define TIM9_DIER_CC2IE_B_0X1       (0x1U<<2U)
#define TIM9_DIER_CC1IE_B_0X0       (0x0U<<1U)
#define TIM9_DIER_CC1IE_B_0X1       (0x1U<<1U)
#define TIM9_DIER_UIE_B_0X0         (0x0U<<0U)
#define TIM9_DIER_UIE_B_0X1         (0x1U<<0U)

// SR Configuration

#define TIM9_SR_CC2OF               (0x1U<<10U)
#define TIM9_SR_CC1OF               (0x1U<<9U)
#define TIM9_SR_TIF                 (0x1U<<6U)
#define TIM9_SR_CC2IF               (0x1U<<2U)
#define TIM9_SR_CC1IF               (0x1U<<1U)
#define TIM9_SR_UIF                 (0x1U<<0U)

#define TIM9_SR_CC1OF_B_0X0         (0x0U<<9U)
#define TIM9_SR_CC1OF_B_0X1         (0x1U<<9U)
#define TIM9_SR_TIF_B_0X0           (0x0U<<6U)
#define TIM9_SR_TIF_B_0X1           (0x1U<<6U)
#define TIM9_SR_CC1IF_B_0X0         (0x0U<<1U)
#define TIM9_SR_CC1IF_B_0X1         (0x1U<<1U)
#define TIM9_SR_UIF_B_0X0           (0x0U<<0U)
#define TIM9_SR_UIF_B_0X1           (0x1U<<0U)

// EGR Configuration

#define TIM9_EGR_TG                 (0x1U<<6U)
#define TIM9_EGR_CC2G               (0x1U<<2U)
#define TIM9_EGR_CC1G               (0x1U<<1U)
#define TIM9_EGR_UG                 (0x1U<<0U)

#define TIM9_EGR_TG_B_0X0           (0x0U<<6U)
#define TIM9_EGR_TG_B_0X1           (0x1U<<6U)
#define TIM9_EGR_CC1G_B_0X0         (0x0U<<1U)
#define TIM9_EGR_CC1G_B_0X1         (0x1U<<1U)
#define TIM9_EGR_UG_B_0X0           (0x0U<<0U)
#define TIM9_EGR_UG_B_0X1           (0x1U<<0U)

// CCMR1 Configuration

#define TIM9_CCMR1_IC2F             (0xFU<<12U)
#define TIM9_CCMR1_IC2F_0           (0x1U<<12U)
#define TIM9_CCMR1_IC2PSC           (0x3U<<10U)
#define TIM9_CCMR1_IC2PSC_0         (0x1U<<10U)
#define TIM9_CCMR1_CC2S             (0x3U<<8U)
#define TIM9_CCMR1_CC2S_0           (0x1U<<8U)
#define TIM9_CCMR1_IC1F             (0xFU<<4U)
#define TIM9_CCMR1_IC1F_0           (0x1U<<4U)
#define TIM9_CCMR1_IC1PSC           (0x3U<<2U)
#define TIM9_CCMR1_IC1PSC_0         (0x1U<<2U)
#define TIM9_CCMR1_CC1S             (0x3U<<0U)
#define TIM9_CCMR1_CC1S_0           (0x1U<<0U)

#define TIM9_CCMR1_CC2S_B_0X0       (0x0U<<8U)
#define TIM9_CCMR1_CC2S_B_0X1       (0x1U<<8U)
#define TIM9_CCMR1_CC2S_B_0X2       (0x2U<<8U)
#define TIM9_CCMR1_CC2S_B_0X3       (0x3U<<8U)
#define TIM9_CCMR1_IC1F_B_0X0       (0x0U<<4U)
#define TIM9_CCMR1_IC1F_B_0X1       (0x1U<<4U)
#define TIM9_CCMR1_IC1F_B_0X2       (0x2U<<4U)
#define TIM9_CCMR1_IC1F_B_0X3       (0x3U<<4U)
#define TIM9_CCMR1_IC1F_B_0X4       (0x4U<<4U)
#define TIM9_CCMR1_IC1F_B_0X5       (0x5U<<4U)
#define TIM9_CCMR1_IC1F_B_0X6       (0x6U<<4U)
#define TIM9_CCMR1_IC1F_B_0X7       (0x7U<<4U)
#define TIM9_CCMR1_IC1F_B_0X8       (0x8U<<4U)
#define TIM9_CCMR1_IC1F_B_0X9       (0x9U<<4U)
#define TIM9_CCMR1_IC1F_B_0XA       (0xAU<<4U)
#define TIM9_CCMR1_IC1F_B_0XB       (0xBU<<4U)
#define TIM9_CCMR1_IC1F_B_0XC       (0xCU<<4U)
#define TIM9_CCMR1_IC1F_B_0XD       (0xDU<<4U)
#define TIM9_CCMR1_IC1F_B_0XE       (0xEU<<4U)
#define TIM9_CCMR1_IC1F_B_0XF       (0xFU<<4U)
#define TIM9_CCMR1_IC1PSC_B_0X0     (0x0U<<2U)
#define TIM9_CCMR1_IC1PSC_B_0X1     (0x1U<<2U)
#define TIM9_CCMR1_IC1PSC_B_0X2     (0x2U<<2U)
#define TIM9_CCMR1_IC1PSC_B_0X3     (0x3U<<2U)
#define TIM9_CCMR1_CC1S_B_0X0       (0x0U<<0U)
#define TIM9_CCMR1_CC1S_B_0X1       (0x1U<<0U)
#define TIM9_CCMR1_CC1S_B_0X2       (0x2U<<0U)
#define TIM9_CCMR1_CC1S_B_0X3       (0x3U<<0U)

// CCER Configuration

#define TIM9_CCER_CC2NP             (0x1U<<7U)
#define TIM9_CCER_CC2P              (0x1U<<5U)
#define TIM9_CCER_CC2E              (0x1U<<4U)
#define TIM9_CCER_CC1NP             (0x1U<<3U)
#define TIM9_CCER_CC1P              (0x1U<<1U)
#define TIM9_CCER_CC1E              (0x1U<<0U)

#define TIM9_CCER_CC1P_B_0X0        (0x0U<<1U)
#define TIM9_CCER_CC1P_B_0X1        (0x1U<<1U)
#define TIM9_CCER_CC1E_B_0X0        (0x0U<<0U)
#define TIM9_CCER_CC1E_B_0X1        (0x1U<<0U)

// CNT Configuration

#define TIM9_CNT_UIFCPY             (0x1U<<31U)
#define TIM9_CNT_CNT                (0xFFFFU<<0U)
#define TIM9_CNT_CNT_0              (0x1U<<0U)

// PSC Configuration

#define TIM9_PSC_PSC                (0xFFFFU<<0U)
#define TIM9_PSC_PSC_0              (0x1U<<0U)

// ARR Configuration

#define TIM9_ARR_ARR                (0xFFFFFU<<0U)
#define TIM9_ARR_ARR_0              (0x1U<<0U)

// CCR1 Configuration

#define TIM9_CCR1_CCR1              (0xFFFFFU<<0U)
#define TIM9_CCR1_CCR1_0            (0x1U<<0U)

// CCR2 Configuration

#define TIM9_CCR2_CCR2              (0xFFFFFU<<0U)
#define TIM9_CCR2_CCR2_0            (0x1U<<0U)

// TISEL Configuration

#define TIM9_TISEL_TI2SEL           (0xFU<<8U)
#define TIM9_TISEL_TI2SEL_0         (0x1U<<8U)
#define TIM9_TISEL_TI1SEL           (0xFU<<0U)
#define TIM9_TISEL_TI1SEL_0         (0x1U<<0U)

#define TIM9_TISEL_TI2SEL_B_0X0     (0x0U<<8U)
#define TIM9_TISEL_TI2SEL_B_0X1     (0x1U<<8U)
#define TIM9_TISEL_TI2SEL_B_0X4     (0x4U<<8U)
#define TIM9_TISEL_TI1SEL_B_0X0     (0x0U<<0U)
#define TIM9_TISEL_TI1SEL_B_0X1     (0x1U<<0U)
#define TIM9_TISEL_TI1SEL_B_0XF     (0xFU<<0U)
