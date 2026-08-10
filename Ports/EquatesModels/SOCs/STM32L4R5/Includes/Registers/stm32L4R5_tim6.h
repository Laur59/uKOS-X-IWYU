/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_tim6 equates.
 */

#pragma once

#include    <stdint.h>

// TIM6 address definitions
// ------------------------

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
    volatile    uint16_t    RESERVED4[7];
    volatile    uint32_t    CNT;
    volatile    uint16_t    PSC;
    volatile    uint16_t    RESERVED5;
    volatile    uint16_t    ARR;
} TIM6_TypeDef;

#ifdef __cplusplus
#define TIM6    reinterpret_cast<TIM6_TypeDef *>(0x40001000U)

#else
#define TIM6    ((TIM6_TypeDef *)0x40001000U)
#endif

// CR1 Configuration

#define TIM6_CR1_UIFREMAP       (0x1U<<11U)
#define TIM6_CR1_ARPE           (0x1U<<7U)
#define TIM6_CR1_OPM            (0x1U<<3U)
#define TIM6_CR1_URS            (0x1U<<2U)
#define TIM6_CR1_UDIS           (0x1U<<1U)
#define TIM6_CR1_CEN            (0x1U<<0U)
#define TIM6_CR1_UIFREMAP_B_0X0 (0x0U<<11U)
#define TIM6_CR1_UIFREMAP_B_0X1 (0x1U<<11U)
#define TIM6_CR1_ARPE_B_0X0     (0x0U<<7U)
#define TIM6_CR1_ARPE_B_0X1     (0x1U<<7U)
#define TIM6_CR1_OPM_B_0X0      (0x0U<<3U)
#define TIM6_CR1_OPM_B_0X1      (0x1U<<3U)
#define TIM6_CR1_URS_B_0X0      (0x0U<<2U)
#define TIM6_CR1_URS_B_0X1      (0x1U<<2U)
#define TIM6_CR1_UDIS_B_0X0     (0x0U<<1U)
#define TIM6_CR1_UDIS_B_0X1     (0x1U<<1U)
#define TIM6_CR1_CEN_B_0X0      (0x0U<<0U)
#define TIM6_CR1_CEN_B_0X1      (0x1U<<0U)

// CR2 Configuration

#define TIM6_CR2_MMS            (0x7U<<4U)
#define TIM6_CR2_MMS_0          (0x1U<<4U)
#define TIM6_CR2_MMS_B_0X0      (0x0U<<4U)
#define TIM6_CR2_MMS_B_0X1      (0x1U<<4U)
#define TIM6_CR2_MMS_B_0X2      (0x2U<<4U)

// DIER Configuration

#define TIM6_DIER_UDE           (0x1U<<8U)
#define TIM6_DIER_UIE           (0x1U<<0U)
#define TIM6_DIER_UDE_B_0X0     (0x0U<<8U)
#define TIM6_DIER_UDE_B_0X1     (0x1U<<8U)
#define TIM6_DIER_UIE_B_0X0     (0x0U<<0U)
#define TIM6_DIER_UIE_B_0X1     (0x1U<<0U)

// SR Configuration

#define TIM6_SR_UIF             (0x1U<<0U)
#define TIM6_SR_UIF_B_0X0       (0x0U<<0U)
#define TIM6_SR_UIF_B_0X1       (0x1U<<0U)

// EGR Configuration

#define TIM6_EGR_UG             (0x1U<<0U)
#define TIM6_EGR_UG_B_0X0       (0x0U<<0U)
#define TIM6_EGR_UG_B_0X1       (0x1U<<0U)

// CNT Configuration

#define TIM6_CNT_UIFCPY         (0x1U<<31U)
#define TIM6_CNT_CNT            (0xFFFFU<<0U)
#define TIM6_CNT_CNT_0          (0x1U<<0U)

// PSC Configuration

#define TIM6_PSC_PSC            (0xFFFFU<<0U)
#define TIM6_PSC_PSC_0          (0x1U<<0U)

// ARR Configuration

#define TIM6_ARR_ARR            (0xFFFFU<<0U)
#define TIM6_ARR_ARR_0          (0x1U<<0U)
