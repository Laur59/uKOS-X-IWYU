/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_tim18 equates.
 */

#pragma once

#include    <stdint.h>

// TIM18 address definitions
// -------------------------

typedef struct {
    volatile    uint16_t    CR1;
    volatile    uint16_t    RESERVED0;
    volatile    uint32_t    CR2;
    volatile    uint32_t    RESERVED1;
    volatile    uint16_t    DIER;
    volatile    uint16_t    RESERVED2;
    volatile    uint16_t    SR;
    volatile    uint16_t    RESERVED3;
    volatile    uint16_t    EGR;
    volatile    uint16_t    RESERVED4[7];
    volatile    uint32_t    CNT;
    volatile    uint16_t    PSC;
    volatile    uint16_t    RESERVED5;
    volatile    uint32_t    ARR;
} TIM18_TypeDef;

#ifdef __cplusplus
#define TIM18_S reinterpret_cast<TIM18_TypeDef *>(0x52003C00U)

#else
#define TIM18_S ((TIM18_TypeDef *)0x52003C00U)
#endif

// CR1 Configuration

#define TIM18_CR1_DITHEN            (0x1U<<12)
#define TIM18_CR1_UIFREMAP          (0x1U<<11)
#define TIM18_CR1_ARPE              (0x1U<<7)
#define TIM18_CR1_OPM               (0x1U<<3)
#define TIM18_CR1_URS               (0x1U<<2)
#define TIM18_CR1_UDIS              (0x1U<<1)
#define TIM18_CR1_CEN               (0x1U<<0)

#define TIM18_CR1_DITHEN_B_0X0      (0x0U<<12)
#define TIM18_CR1_DITHEN_B_0X1      (0x1U<<12)
#define TIM18_CR1_UIFREMAP_B_0X0    (0x0U<<11)
#define TIM18_CR1_UIFREMAP_B_0X1    (0x1U<<11)
#define TIM18_CR1_ARPE_B_0X0        (0x0U<<7)
#define TIM18_CR1_ARPE_B_0X1        (0x1U<<7)
#define TIM18_CR1_OPM_B_0X0         (0x0U<<3)
#define TIM18_CR1_OPM_B_0X1         (0x1U<<3)
#define TIM18_CR1_URS_B_0X0         (0x0U<<2)
#define TIM18_CR1_URS_B_0X1         (0x1U<<2)
#define TIM18_CR1_UDIS_B_0X0        (0x0U<<1)
#define TIM18_CR1_UDIS_B_0X1        (0x1U<<1)
#define TIM18_CR1_CEN_B_0X0         (0x0U<<0)
#define TIM18_CR1_CEN_B_0X1         (0x1U<<0)

// CR2 Configuration

#define TIM18_CR2_ADSYNC            (0x1U<<28)
#define TIM18_CR2_MMS               (0x7U<<4)
#define TIM18_CR2_MMS_0             (0x1U<<4)

#define TIM18_CR2_ADSYNC_B_0X0      (0x0U<<28)
#define TIM18_CR2_ADSYNC_B_0X1      (0x1U<<28)
#define TIM18_CR2_MMS_B_0X0         (0x0U<<4)
#define TIM18_CR2_MMS_B_0X1         (0x1U<<4)
#define TIM18_CR2_MMS_B_0X2         (0x2U<<4)

// DIER Configuration

#define TIM18_DIER_UDE              (0x1U<<8)
#define TIM18_DIER_UIE              (0x1U<<0)

#define TIM18_DIER_UDE_B_0X0        (0x0U<<8)
#define TIM18_DIER_UDE_B_0X1        (0x1U<<8)
#define TIM18_DIER_UIE_B_0X0        (0x0U<<0)
#define TIM18_DIER_UIE_B_0X1        (0x1U<<0)

// SR Configuration

#define TIM18_SR_UIF                (0x1U<<0)

#define TIM18_SR_UIF_B_0X0          (0x0U<<0)
#define TIM18_SR_UIF_B_0X1          (0x1U<<0)

// EGR Configuration

#define TIM18_EGR_UG                (0x1U<<0)

#define TIM18_EGR_UG_B_0X0          (0x0U<<0)
#define TIM18_EGR_UG_B_0X1          (0x1U<<0)

// CNT Configuration

#define TIM18_CNT_UIFCPY            (0x1U<<31)
#define TIM18_CNT_CNT               (0xFFFFU<<0)
#define TIM18_CNT_CNT_0             (0x1U<<0)

// PSC Configuration

#define TIM18_PSC_PSC               (0xFFFFU<<0)
#define TIM18_PSC_PSC_0             (0x1U<<0)

// ARR Configuration

#define TIM18_ARR_ARR               (0xFFFFFU<<0)
#define TIM18_ARR_ARR_0             (0x1U<<0)
