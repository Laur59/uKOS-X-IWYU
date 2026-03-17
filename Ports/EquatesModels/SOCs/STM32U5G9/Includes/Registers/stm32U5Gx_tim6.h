/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_tim6.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_tim6 equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define TIM6_CR1_CEN        (0x1U<<0)
#define TIM6_CR1_UDIS       (0x1U<<1)
#define TIM6_CR1_URS        (0x1U<<2)
#define TIM6_CR1_OPM        (0x1U<<3)
#define TIM6_CR1_ARPE       (0x1U<<7)
#define TIM6_CR1_UIFREMAP   (0x1U<<11)
#define TIM6_CR1_DITHEN     (0x1U<<12)

// CR2 Configuration

#define TIM6_CR2_MMS        (0x7U<<4)
#define TIM6_CR2_MMS_0      (0x1U<<4)

// DIER Configuration

#define TIM6_DIER_UIE       (0x1U<<0)
#define TIM6_DIER_UDE       (0x1U<<8)

// SR Configuration

#define TIM6_SR_UIF         (0x1U<<0)

// EGR Configuration

#define TIM6_EGR_UG         (0x1U<<0)

// CNT Configuration

#define TIM6_CNT_CNT        (0xFFFFU<<0)
#define TIM6_CNT_CNT_0      (0x1U<<0)
#define TIM6_CNT_UIFCPY     (0x1U<<31)

// PSC Configuration

#define TIM6_PSC_PSC        (0xFFFFU<<0)
#define TIM6_PSC_PSC_0      (0x1U<<0)

// ARR Configuration

#define TIM6_ARR_ARR        (0xFFFFFU<<0)
#define TIM6_ARR_ARR_0      (0x1U<<0)
