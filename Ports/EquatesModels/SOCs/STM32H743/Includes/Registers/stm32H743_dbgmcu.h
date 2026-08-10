/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_dbgmcu equates.
 */

#pragma once

#include    <stdint.h>

// DBGMCU address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    IDC;
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0[11];
    volatile    uint32_t    APB3FZ1;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    APB1LFZ1;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    APB2FZ1;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    APB4FZ1;
} DBGMCU_TypeDef;

#ifdef __cplusplus
#define DBGMCU  reinterpret_cast<DBGMCU_TypeDef *>(0x5C001000U)

#else
#define DBGMCU  ((DBGMCU_TypeDef *)0x5C001000U)
#endif

// IDC Configuration

#define DBGMCU_IDC_REV_ID           (0xFFFFU<<16U)
#define DBGMCU_IDC_REV_ID_0         (0x1U<<16U)
#define DBGMCU_IDC_DEV_ID           (0xFFFU<<0U)
#define DBGMCU_IDC_DEV_ID_0         (0x1U<<0U)

// CR Configuration

#define DBGMCU_CR_TRGOEN            (0x1U<<28U)
#define DBGMCU_CR_D3DBGCKEN         (0x1U<<22U)
#define DBGMCU_CR_D1DBGCKEN         (0x1U<<21U)
#define DBGMCU_CR_TRACECLKEN        (0x1U<<20U)
#define DBGMCU_CR_DBGSTBY_D3        (0x1U<<8U)
#define DBGMCU_CR_DBGSTOP_D3        (0x1U<<7U)
#define DBGMCU_CR_DBGSTBY_D2        (0x1U<<5U)
#define DBGMCU_CR_DBGSTOP_D2        (0x1U<<4U)
#define DBGMCU_CR_DBGSLEEP_D2       (0x1U<<3U)
#define DBGMCU_CR_DBGSTBY_D1        (0x1U<<2U)
#define DBGMCU_CR_DBGSTOP_D1        (0x1U<<1U)
#define DBGMCU_CR_DBGSLEEP_D1       (0x1U<<0U)

// APB3FZ1 Configuration

#define DBGMCU_APB3FZ1_WWDG1        (0x1U<<6U)

// APB1LFZ1 Configuration

#define DBGMCU_APB1LFZ1_DBG_I2C3    (0x1U<<23U)
#define DBGMCU_APB1LFZ1_DBG_I2C2    (0x1U<<22U)
#define DBGMCU_APB1LFZ1_DBG_I2C1    (0x1U<<21U)
#define DBGMCU_APB1LFZ1_DBG_LPTIM1  (0x1U<<9U)
#define DBGMCU_APB1LFZ1_DBG_TIM14   (0x1U<<8U)
#define DBGMCU_APB1LFZ1_DBG_TIM13   (0x1U<<7U)
#define DBGMCU_APB1LFZ1_DBG_TIM12   (0x1U<<6U)
#define DBGMCU_APB1LFZ1_DBG_TIM7    (0x1U<<5U)
#define DBGMCU_APB1LFZ1_DBG_TIM6    (0x1U<<4U)
#define DBGMCU_APB1LFZ1_DBG_TIM5    (0x1U<<3U)
#define DBGMCU_APB1LFZ1_DBG_TIM4    (0x1U<<2U)
#define DBGMCU_APB1LFZ1_DBG_TIM3    (0x1U<<1U)
#define DBGMCU_APB1LFZ1_DBG_TIM2    (0x1U<<0U)

// APB2FZ1 Configuration

#define DBGMCU_APB2FZ1_DBG_HRTIM    (0x1U<<29U)
#define DBGMCU_APB2FZ1_DBG_TIM17    (0x1U<<18U)
#define DBGMCU_APB2FZ1_DBG_TIM16    (0x1U<<17U)
#define DBGMCU_APB2FZ1_DBG_TIM15    (0x1U<<16U)
#define DBGMCU_APB2FZ1_DBG_TIM8     (0x1U<<1U)
#define DBGMCU_APB2FZ1_DBG_TIM1     (0x1U<<0U)

// APB4FZ1 Configuration

#define DBGMCU_APB4FZ1_DBG_IWDG1    (0x1U<<18U)
#define DBGMCU_APB4FZ1_DBG_RTC      (0x1U<<16U)
#define DBGMCU_APB4FZ1_DBG_LPTIM5   (0x1U<<12U)
#define DBGMCU_APB4FZ1_DBG_LPTIM4   (0x1U<<11U)
#define DBGMCU_APB4FZ1_DBG_LPTIM3   (0x1U<<10U)
#define DBGMCU_APB4FZ1_DBG_LPTIM2   (0x1U<<9U)
#define DBGMCU_APB4FZ1_DBG_I2C4     (0x1U<<7U)
