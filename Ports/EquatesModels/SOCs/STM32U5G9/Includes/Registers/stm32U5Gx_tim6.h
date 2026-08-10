/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_tim6 equates.
 */

#pragma once

#include    <stdint.h>

// TIM6 address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    DIER;
    volatile    uint32_t    SR;
    volatile    uint32_t    EGR;
    volatile    uint32_t    RESERVED1[3];
    volatile    uint32_t    CNT;
    volatile    uint32_t    PSC;
    volatile    uint32_t    ARR;
} TIM6_TypeDef;

#ifdef __cplusplus
#define TIM6_NS reinterpret_cast<TIM6_TypeDef *>(0x40001000U)
#define TIM6_S  reinterpret_cast<TIM6_TypeDef *>(0x50001000U)

#else
#define TIM6_NS ((TIM6_TypeDef *)0x40001000U)
#define TIM6_S  ((TIM6_TypeDef *)0x50001000U)
#endif

// CR1 Configuration

#define TIM6_CR1_CEN        (0x1U<<0U)
#define TIM6_CR1_UDIS       (0x1U<<1U)
#define TIM6_CR1_URS        (0x1U<<2U)
#define TIM6_CR1_OPM        (0x1U<<3U)
#define TIM6_CR1_ARPE       (0x1U<<7U)
#define TIM6_CR1_UIFREMAP   (0x1U<<11U)
#define TIM6_CR1_DITHEN     (0x1U<<12U)

// CR2 Configuration

#define TIM6_CR2_MMS        (0x7U<<4U)
#define TIM6_CR2_MMS_0      (0x1U<<4U)

// DIER Configuration

#define TIM6_DIER_UIE       (0x1U<<0U)
#define TIM6_DIER_UDE       (0x1U<<8U)

// SR Configuration

#define TIM6_SR_UIF         (0x1U<<0U)

// EGR Configuration

#define TIM6_EGR_UG         (0x1U<<0U)

// CNT Configuration

#define TIM6_CNT_CNT        (0xFFFFU<<0U)
#define TIM6_CNT_CNT_0      (0x1U<<0U)
#define TIM6_CNT_UIFCPY     (0x1U<<31U)

// PSC Configuration

#define TIM6_PSC_PSC        (0xFFFFU<<0U)
#define TIM6_PSC_PSC_0      (0x1U<<0U)

// ARR Configuration

#define TIM6_ARR_ARR        (0xFFFFFU<<0U)
#define TIM6_ARR_ARR_0      (0x1U<<0U)
