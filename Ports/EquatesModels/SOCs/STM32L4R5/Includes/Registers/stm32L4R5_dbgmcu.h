/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_dbgmcu equates.
 */

#pragma once

#include    <stdint.h>

// DBGMCU address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    IDCODE;
    volatile    uint32_t    CR;
    volatile    uint32_t    APB1_FZR1;
    volatile    uint32_t    APB1_FZR2;
    volatile    uint32_t    APB2_FZR;
} DBGMCU_TypeDef;

#ifdef __cplusplus
#define DBGMCU  reinterpret_cast<DBGMCU_TypeDef *>(0xE0042000U)

#else
#define DBGMCU  ((DBGMCU_TypeDef *)0xE0042000U)
#endif

// IDCODE Configuration

#define DBGMCU_IDCODE_REV_ID                (0xFFFFU<<16)
#define DBGMCU_IDCODE_REV_ID_0              (0x1U<<16)
#define DBGMCU_IDCODE_DEV_ID                (0xFFFFU<<0)
#define DBGMCU_IDCODE_DEV_ID_0              (0x1U<<0)

// CR Configuration

#define DBGMCU_CR_TRACE_MODE                (0x3U<<6)
#define DBGMCU_CR_TRACE_MODE_0              (0x1U<<6)
#define DBGMCU_CR_TRACE_IOEN                (0x1U<<5)
#define DBGMCU_CR_DBG_STANDBY               (0x1U<<2)
#define DBGMCU_CR_DBG_STOP                  (0x1U<<1)
#define DBGMCU_CR_DBG_SLEEP                 (0x1U<<0)

// APB1_FZR1 Configuration

#define DBGMCU_APB1_FZR1_DBG_LPTIMER_STOP   (0x1U<<31)
#define DBGMCU_APB1_FZR1_DBG_CAN_STOP       (0x1U<<25)
#define DBGMCU_APB1_FZR1_DBG_I2C3_STOP      (0x1U<<23)
#define DBGMCU_APB1_FZR1_DBG_I2C2_STOP      (0x1U<<22)
#define DBGMCU_APB1_FZR1_DBG_I2C1_STOP      (0x1U<<21)
#define DBGMCU_APB1_FZR1_DBG_IWDG_STOP      (0x1U<<12)
#define DBGMCU_APB1_FZR1_DBG_WWDG_STOP      (0x1U<<11)
#define DBGMCU_APB1_FZR1_DBG_RTC_STOP       (0x1U<<10)
#define DBGMCU_APB1_FZR1_DBG_TIM7_STOP      (0x1U<<5)
#define DBGMCU_APB1_FZR1_DBG_TIMER6_STOP    (0x1U<<4)
#define DBGMCU_APB1_FZR1_DBG_TIM5_STOP      (0x1U<<3)
#define DBGMCU_APB1_FZR1_DBG_TIM4_STOP      (0x1U<<2)
#define DBGMCU_APB1_FZR1_DBG_TIM3_STOP      (0x1U<<1)
#define DBGMCU_APB1_FZR1_DBG_TIMER2_STOP    (0x1U<<0)

// APB1_FZR2 Configuration

#define DBGMCU_APB1_FZR2_DBG_LPTIM2_STOP    (0x1U<<5)

// APB2_FZR Configuration

#define DBGMCU_APB2_FZR_DBG_TIM17_STOP      (0x1U<<18)
#define DBGMCU_APB2_FZR_DBG_TIM16_STOP      (0x1U<<17)
#define DBGMCU_APB2_FZR_DBG_TIM15_STOP      (0x1U<<16)
#define DBGMCU_APB2_FZR_DBG_TIM8_STOP       (0x1U<<13)
#define DBGMCU_APB2_FZR_DBG_TIM1_STOP       (0x1U<<11)
