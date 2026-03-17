/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_tim10.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_tim10 equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// TIM10 address definitions
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
} TIM10_TypeDef;

#ifdef __cplusplus
#define TIM10_NS    reinterpret_cast<TIM10_TypeDef *>(0x40003000U)
#define TIM10_S     reinterpret_cast<TIM10_TypeDef *>(0x50003000U)

#else
#define TIM10_NS    ((TIM10_TypeDef *)0x40003000U)
#define TIM10_S     ((TIM10_TypeDef *)0x50003000U)
#endif

// CR1 Configuration

#define TIM10_CR1_DITHEN            (0x1U<<12)
#define TIM10_CR1_UIFREMAP          (0x1U<<11)
#define TIM10_CR1_CKD               (0x3U<<8)
#define TIM10_CR1_CKD_0             (0x1U<<8)
#define TIM10_CR1_ARPE              (0x1U<<7)
#define TIM10_CR1_OPM               (0x1U<<3)
#define TIM10_CR1_URS               (0x1U<<2)
#define TIM10_CR1_UDIS              (0x1U<<1)
#define TIM10_CR1_CEN               (0x1U<<0)

#define TIM10_CR1_DITHEN_B_0X0      (0x0U<<12)
#define TIM10_CR1_DITHEN_B_0X1      (0x1U<<12)
#define TIM10_CR1_UIFREMAP_B_0X0    (0x0U<<11)
#define TIM10_CR1_UIFREMAP_B_0X1    (0x1U<<11)
#define TIM10_CR1_CKD_B_0X0         (0x0U<<8)
#define TIM10_CR1_CKD_B_0X1         (0x1U<<8)
#define TIM10_CR1_CKD_B_0X2         (0x2U<<8)
#define TIM10_CR1_ARPE_B_0X0        (0x0U<<7)
#define TIM10_CR1_ARPE_B_0X1        (0x1U<<7)
#define TIM10_CR1_OPM_B_0X0         (0x0U<<3)
#define TIM10_CR1_OPM_B_0X1         (0x1U<<3)
#define TIM10_CR1_URS_B_0X0         (0x0U<<2)
#define TIM10_CR1_URS_B_0X1         (0x1U<<2)
#define TIM10_CR1_UDIS_B_0X0        (0x0U<<1)
#define TIM10_CR1_UDIS_B_0X1        (0x1U<<1)
#define TIM10_CR1_CEN_B_0X0         (0x0U<<0)
#define TIM10_CR1_CEN_B_0X1         (0x1U<<0)

// DIER Configuration

#define TIM10_DIER_CC1IE            (0x1U<<1)
#define TIM10_DIER_UIE              (0x1U<<0)

#define TIM10_DIER_CC1IE_B_0X0      (0x0U<<1)
#define TIM10_DIER_CC1IE_B_0X1      (0x1U<<1)
#define TIM10_DIER_UIE_B_0X0        (0x0U<<0)
#define TIM10_DIER_UIE_B_0X1        (0x1U<<0)

// SR Configuration

#define TIM10_SR_CC1OF              (0x1U<<9)
#define TIM10_SR_CC1IF              (0x1U<<1)
#define TIM10_SR_UIF                (0x1U<<0)

#define TIM10_SR_CC1OF_B_0X0        (0x0U<<9)
#define TIM10_SR_CC1OF_B_0X1        (0x1U<<9)
#define TIM10_SR_CC1IF_B_0X0        (0x0U<<1)
#define TIM10_SR_CC1IF_B_0X1        (0x1U<<1)
#define TIM10_SR_UIF_B_0X0          (0x0U<<0)
#define TIM10_SR_UIF_B_0X1          (0x1U<<0)

// EGR Configuration

#define TIM10_EGR_CC1G              (0x1U<<1)
#define TIM10_EGR_UG                (0x1U<<0)

#define TIM10_EGR_CC1G_B_0X0        (0x0U<<1)
#define TIM10_EGR_CC1G_B_0X1        (0x1U<<1)
#define TIM10_EGR_UG_B_0X0          (0x0U<<0)
#define TIM10_EGR_UG_B_0X1          (0x1U<<0)

// CCMR1 Configuration

#define TIM10_CCMR1_IC1F            (0xFU<<4)
#define TIM10_CCMR1_IC1F_0          (0x1U<<4)
#define TIM10_CCMR1_IC1PSC          (0x3U<<2)
#define TIM10_CCMR1_IC1PSC_0        (0x1U<<2)
#define TIM10_CCMR1_CC1S            (0x3U<<0)
#define TIM10_CCMR1_CC1S_0          (0x1U<<0)

#define TIM10_CCMR1_IC1F_B_0X0      (0x0U<<4)
#define TIM10_CCMR1_IC1F_B_0X1      (0x1U<<4)
#define TIM10_CCMR1_IC1F_B_0X2      (0x2U<<4)
#define TIM10_CCMR1_IC1F_B_0X3      (0x3U<<4)
#define TIM10_CCMR1_IC1F_B_0X4      (0x4U<<4)
#define TIM10_CCMR1_IC1F_B_0X5      (0x5U<<4)
#define TIM10_CCMR1_IC1F_B_0X6      (0x6U<<4)
#define TIM10_CCMR1_IC1F_B_0X7      (0x7U<<4)
#define TIM10_CCMR1_IC1F_B_0X8      (0x8U<<4)
#define TIM10_CCMR1_IC1F_B_0X9      (0x9U<<4)
#define TIM10_CCMR1_IC1F_B_0XA      (0xAU<<4)
#define TIM10_CCMR1_IC1F_B_0XB      (0xBU<<4)
#define TIM10_CCMR1_IC1F_B_0XC      (0xCU<<4)
#define TIM10_CCMR1_IC1F_B_0XD      (0xDU<<4)
#define TIM10_CCMR1_IC1F_B_0XE      (0xEU<<4)
#define TIM10_CCMR1_IC1F_B_0XF      (0xFU<<4)
#define TIM10_CCMR1_IC1PSC_B_0X0    (0x0U<<2)
#define TIM10_CCMR1_IC1PSC_B_0X1    (0x1U<<2)
#define TIM10_CCMR1_IC1PSC_B_0X2    (0x2U<<2)
#define TIM10_CCMR1_IC1PSC_B_0X3    (0x3U<<2)
#define TIM10_CCMR1_CC1S_B_0X0      (0x0U<<0)
#define TIM10_CCMR1_CC1S_B_0X1      (0x1U<<0)

// CCER Configuration

#define TIM10_CCER_CC1NP            (0x1U<<3)
#define TIM10_CCER_CC1P             (0x1U<<1)
#define TIM10_CCER_CC1E             (0x1U<<0)

#define TIM10_CCER_CC1P_B_0X0       (0x0U<<1)
#define TIM10_CCER_CC1P_B_0X1       (0x1U<<1)
#define TIM10_CCER_CC1E_B_0X0       (0x0U<<0)
#define TIM10_CCER_CC1E_B_0X1       (0x1U<<0)

// CNT Configuration

#define TIM10_CNT_UIFCPY            (0x1U<<31)
#define TIM10_CNT_CNT               (0xFFFFU<<0)
#define TIM10_CNT_CNT_0             (0x1U<<0)

// PSC Configuration

#define TIM10_PSC_PSC               (0xFFFFU<<0)
#define TIM10_PSC_PSC_0             (0x1U<<0)

// ARR Configuration

#define TIM10_ARR_ARR               (0xFFFFFU<<0)
#define TIM10_ARR_ARR_0             (0x1U<<0)

// CCR1 Configuration

#define TIM10_CCR1_CCR1             (0xFFFFFU<<0)
#define TIM10_CCR1_CCR1_0           (0x1U<<0)

// TISEL Configuration

#define TIM10_TISEL_TI1SEL          (0xFU<<0)
#define TIM10_TISEL_TI1SEL_0        (0x1U<<0)

#define TIM10_TISEL_TI1SEL_B_0X0    (0x0U<<0)
#define TIM10_TISEL_TI1SEL_B_0X1    (0x1U<<0)
#define TIM10_TISEL_TI1SEL_B_0XF    (0xFU<<0)
