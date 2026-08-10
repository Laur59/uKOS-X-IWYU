/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_tim11 equates.
 */

#pragma once

#include    <stdint.h>

// TIM11 address definitions
// -------------------------

typedef struct {
    volatile    uint16_t    CR1;
    volatile    uint16_t    RESERVED0[5];
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
    volatile    uint32_t    RESERVED8[9];
    volatile    uint16_t    TISEL;
} TIM11_TypeDef;

#ifdef __cplusplus
#define TIM11_NS    reinterpret_cast<TIM11_TypeDef *>(0x40003400U)
#define TIM11_S     reinterpret_cast<TIM11_TypeDef *>(0x50003400U)

#else
#define TIM11_NS    ((TIM11_TypeDef *)0x40003400U)
#define TIM11_S     ((TIM11_TypeDef *)0x50003400U)
#endif

// CR1 Configuration

#define TIM11_CR1_DITHEN            (0x1U<<12U)
#define TIM11_CR1_UIFREMAP          (0x1U<<11U)
#define TIM11_CR1_CKD               (0x3U<<8U)
#define TIM11_CR1_CKD_0             (0x1U<<8U)
#define TIM11_CR1_ARPE              (0x1U<<7U)
#define TIM11_CR1_OPM               (0x1U<<3U)
#define TIM11_CR1_URS               (0x1U<<2U)
#define TIM11_CR1_UDIS              (0x1U<<1U)
#define TIM11_CR1_CEN               (0x1U<<0U)

#define TIM11_CR1_DITHEN_B_0X0      (0x0U<<12U)
#define TIM11_CR1_DITHEN_B_0X1      (0x1U<<12U)
#define TIM11_CR1_UIFREMAP_B_0X0    (0x0U<<11U)
#define TIM11_CR1_UIFREMAP_B_0X1    (0x1U<<11U)
#define TIM11_CR1_CKD_B_0X0         (0x0U<<8U)
#define TIM11_CR1_CKD_B_0X1         (0x1U<<8U)
#define TIM11_CR1_CKD_B_0X2         (0x2U<<8U)
#define TIM11_CR1_ARPE_B_0X0        (0x0U<<7U)
#define TIM11_CR1_ARPE_B_0X1        (0x1U<<7U)
#define TIM11_CR1_OPM_B_0X0         (0x0U<<3U)
#define TIM11_CR1_OPM_B_0X1         (0x1U<<3U)
#define TIM11_CR1_URS_B_0X0         (0x0U<<2U)
#define TIM11_CR1_URS_B_0X1         (0x1U<<2U)
#define TIM11_CR1_UDIS_B_0X0        (0x0U<<1U)
#define TIM11_CR1_UDIS_B_0X1        (0x1U<<1U)
#define TIM11_CR1_CEN_B_0X0         (0x0U<<0U)
#define TIM11_CR1_CEN_B_0X1         (0x1U<<0U)

// DIER Configuration

#define TIM11_DIER_CC1IE            (0x1U<<1U)
#define TIM11_DIER_UIE              (0x1U<<0U)

#define TIM11_DIER_CC1IE_B_0X0      (0x0U<<1U)
#define TIM11_DIER_CC1IE_B_0X1      (0x1U<<1U)
#define TIM11_DIER_UIE_B_0X0        (0x0U<<0U)
#define TIM11_DIER_UIE_B_0X1        (0x1U<<0U)

// SR Configuration

#define TIM11_SR_CC1OF              (0x1U<<9U)
#define TIM11_SR_CC1IF              (0x1U<<1U)
#define TIM11_SR_UIF                (0x1U<<0U)

#define TIM11_SR_CC1OF_B_0X0        (0x0U<<9U)
#define TIM11_SR_CC1OF_B_0X1        (0x1U<<9U)
#define TIM11_SR_CC1IF_B_0X0        (0x0U<<1U)
#define TIM11_SR_CC1IF_B_0X1        (0x1U<<1U)
#define TIM11_SR_UIF_B_0X0          (0x0U<<0U)
#define TIM11_SR_UIF_B_0X1          (0x1U<<0U)

// EGR Configuration

#define TIM11_EGR_CC1G              (0x1U<<1U)
#define TIM11_EGR_UG                (0x1U<<0U)

#define TIM11_EGR_CC1G_B_0X0        (0x0U<<1U)
#define TIM11_EGR_CC1G_B_0X1        (0x1U<<1U)
#define TIM11_EGR_UG_B_0X0          (0x0U<<0U)
#define TIM11_EGR_UG_B_0X1          (0x1U<<0U)

// CCMR1 Configuration

#define TIM11_CCMR1_IC1F            (0xFU<<4U)
#define TIM11_CCMR1_IC1F_0          (0x1U<<4U)
#define TIM11_CCMR1_IC1PSC          (0x3U<<2U)
#define TIM11_CCMR1_IC1PSC_0        (0x1U<<2U)
#define TIM11_CCMR1_CC1S            (0x3U<<0U)
#define TIM11_CCMR1_CC1S_0          (0x1U<<0U)

#define TIM11_CCMR1_IC1F_B_0X0      (0x0U<<4U)
#define TIM11_CCMR1_IC1F_B_0X1      (0x1U<<4U)
#define TIM11_CCMR1_IC1F_B_0X2      (0x2U<<4U)
#define TIM11_CCMR1_IC1F_B_0X3      (0x3U<<4U)
#define TIM11_CCMR1_IC1F_B_0X4      (0x4U<<4U)
#define TIM11_CCMR1_IC1F_B_0X5      (0x5U<<4U)
#define TIM11_CCMR1_IC1F_B_0X6      (0x6U<<4U)
#define TIM11_CCMR1_IC1F_B_0X7      (0x7U<<4U)
#define TIM11_CCMR1_IC1F_B_0X8      (0x8U<<4U)
#define TIM11_CCMR1_IC1F_B_0X9      (0x9U<<4U)
#define TIM11_CCMR1_IC1F_B_0XA      (0xAU<<4U)
#define TIM11_CCMR1_IC1F_B_0XB      (0xBU<<4U)
#define TIM11_CCMR1_IC1F_B_0XC      (0xCU<<4U)
#define TIM11_CCMR1_IC1F_B_0XD      (0xDU<<4U)
#define TIM11_CCMR1_IC1F_B_0XE      (0xEU<<4U)
#define TIM11_CCMR1_IC1F_B_0XF      (0xFU<<4U)
#define TIM11_CCMR1_IC1PSC_B_0X0    (0x0U<<2U)
#define TIM11_CCMR1_IC1PSC_B_0X1    (0x1U<<2U)
#define TIM11_CCMR1_IC1PSC_B_0X2    (0x2U<<2U)
#define TIM11_CCMR1_IC1PSC_B_0X3    (0x3U<<2U)
#define TIM11_CCMR1_CC1S_B_0X0      (0x0U<<0U)
#define TIM11_CCMR1_CC1S_B_0X1      (0x1U<<0U)

// CCER Configuration

#define TIM11_CCER_CC1NP            (0x1U<<3U)
#define TIM11_CCER_CC1P             (0x1U<<1U)
#define TIM11_CCER_CC1E             (0x1U<<0U)

#define TIM11_CCER_CC1P_B_0X0       (0x0U<<1U)
#define TIM11_CCER_CC1P_B_0X1       (0x1U<<1U)
#define TIM11_CCER_CC1E_B_0X0       (0x0U<<0U)
#define TIM11_CCER_CC1E_B_0X1       (0x1U<<0U)

// CNT Configuration

#define TIM11_CNT_UIFCPY            (0x1U<<31U)
#define TIM11_CNT_CNT               (0xFFFFU<<0U)
#define TIM11_CNT_CNT_0             (0x1U<<0U)

// PSC Configuration

#define TIM11_PSC_PSC               (0xFFFFU<<0U)
#define TIM11_PSC_PSC_0             (0x1U<<0U)

// ARR Configuration

#define TIM11_ARR_ARR               (0xFFFFFU<<0U)
#define TIM11_ARR_ARR_0             (0x1U<<0U)

// CCR1 Configuration

#define TIM11_CCR1_CCR1             (0xFFFFFU<<0U)
#define TIM11_CCR1_CCR1_0           (0x1U<<0U)

// TISEL Configuration

#define TIM11_TISEL_TI1SEL          (0xFU<<0U)
#define TIM11_TISEL_TI1SEL_0        (0x1U<<0U)

#define TIM11_TISEL_TI1SEL_B_0X0    (0x0U<<0U)
#define TIM11_TISEL_TI1SEL_B_0X1    (0x1U<<0U)
#define TIM11_TISEL_TI1SEL_B_0XF    (0xFU<<0U)
