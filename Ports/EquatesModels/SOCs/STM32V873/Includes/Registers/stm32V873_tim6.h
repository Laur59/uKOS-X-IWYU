/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_tim6 equates.
 */
#pragma once

#include    <stdint.h>

// TIM6 address definitions
// ------------------------

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
} TIM6_TypeDef;

#if (defined(__cplusplus))
#define TIM6_S  reinterpret_cast<TIM6_TypeDef *>(0x50001000u)

#else
#define TIM6_S  ((TIM6_TypeDef *)0x50001000u)
#endif

// CR1 Configuration

#define TIM6_CR1_DITHEN         (0x1u<<12)
#define TIM6_CR1_UIFREMAP       (0x1u<<11)
#define TIM6_CR1_ARPE           (0x1u<<7)
#define TIM6_CR1_OPM            (0x1u<<3)
#define TIM6_CR1_URS            (0x1u<<2)
#define TIM6_CR1_UDIS           (0x1u<<1)
#define TIM6_CR1_CEN            (0x1u<<0)

#define TIM6_CR1_DITHEN_B_0X0   (0x0u<<12)
#define TIM6_CR1_DITHEN_B_0X1   (0x1u<<12)
#define TIM6_CR1_UIFREMAP_B_0X0 (0x0u<<11)
#define TIM6_CR1_UIFREMAP_B_0X1 (0x1u<<11)
#define TIM6_CR1_ARPE_B_0X0     (0x0u<<7)
#define TIM6_CR1_ARPE_B_0X1     (0x1u<<7)
#define TIM6_CR1_OPM_B_0X0      (0x0u<<3)
#define TIM6_CR1_OPM_B_0X1      (0x1u<<3)
#define TIM6_CR1_URS_B_0X0      (0x0u<<2)
#define TIM6_CR1_URS_B_0X1      (0x1u<<2)
#define TIM6_CR1_UDIS_B_0X0     (0x0u<<1)
#define TIM6_CR1_UDIS_B_0X1     (0x1u<<1)
#define TIM6_CR1_CEN_B_0X0      (0x0u<<0)
#define TIM6_CR1_CEN_B_0X1      (0x1u<<0)

// CR2 Configuration

#define TIM6_CR2_ADSYNC         (0x1u<<28)
#define TIM6_CR2_MMS            (0x7u<<4)
#define TIM6_CR2_MMS_0          (0x1u<<4)

#define TIM6_CR2_ADSYNC_B_0X0   (0x0u<<28)
#define TIM6_CR2_ADSYNC_B_0X1   (0x1u<<28)
#define TIM6_CR2_MMS_B_0X0      (0x0u<<4)
#define TIM6_CR2_MMS_B_0X1      (0x1u<<4)
#define TIM6_CR2_MMS_B_0X2      (0x2u<<4)

// DIER Configuration

#define TIM6_DIER_UDE           (0x1u<<8)
#define TIM6_DIER_UIE           (0x1u<<0)

#define TIM6_DIER_UDE_B_0X0     (0x0u<<8)
#define TIM6_DIER_UDE_B_0X1     (0x1u<<8)
#define TIM6_DIER_UIE_B_0X0     (0x0u<<0)
#define TIM6_DIER_UIE_B_0X1     (0x1u<<0)

// SR Configuration

#define TIM6_SR_UIF             (0x1u<<0)

#define TIM6_SR_UIF_B_0X0       (0x0u<<0)
#define TIM6_SR_UIF_B_0X1       (0x1u<<0)

// EGR Configuration

#define TIM6_EGR_UG             (0x1u<<0)

#define TIM6_EGR_UG_B_0X0       (0x0u<<0)
#define TIM6_EGR_UG_B_0X1       (0x1u<<0)

// CNT Configuration

#define TIM6_CNT_UIFCPY         (0x1u<<31)
#define TIM6_CNT_CNT            (0xFFFFu<<0)
#define TIM6_CNT_CNT_0          (0x1u<<0)

// PSC Configuration

#define TIM6_PSC_PSC            (0xFFFFu<<0)
#define TIM6_PSC_PSC_0          (0x1u<<0)

// ARR Configuration

#define TIM6_ARR_ARR            (0xFFFFFu<<0)
#define TIM6_ARR_ARR_0          (0x1u<<0)
