/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_dbg equates.
 */

#pragma once

#include    <stdint.h>

// DBG address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    DBGMCU_IDCODE;
    volatile    uint32_t    DBGMCU_CR;
    volatile    uint32_t    DBGMCU_APB1_FZ;
    volatile    uint32_t    DBGMCU_APB2_FZ;
} DBG_TypeDef;

#ifdef __cplusplus
#define DBG reinterpret_cast<DBG_TypeDef *>(0xE0042000U)

#else
#define DBG ((DBG_TypeDef *)0xE0042000U)
#endif

// DBGMCU_IDCODE Configuration

#define DBG_DBGMCU_IDCODE_REV_ID                    (0xFFFFU<<16)
#define DBG_DBGMCU_IDCODE_REV_ID_0                  (0x1U<<16)
#define DBG_DBGMCU_IDCODE_DEV_ID                    (0xFFFU<<0)
#define DBG_DBGMCU_IDCODE_DEV_ID_0                  (0x1U<<0)

// DBGMCU_CR Configuration

#define DBG_DBGMCU_CR_TRACE_MODE                    (0x3U<<6)
#define DBG_DBGMCU_CR_TRACE_MODE_0                  (0x1U<<6)
#define DBG_DBGMCU_CR_TRACE_IOEN                    (0x1U<<5)
#define DBG_DBGMCU_CR_DBG_STANDBY                   (0x1U<<2)
#define DBG_DBGMCU_CR_DBG_STOP                      (0x1U<<1)
#define DBG_DBGMCU_CR_DBG_SLEEP                     (0x1U<<0)

// DBGMCU_APB1_FZ Configuration

#define DBG_DBGMCU_APB1_FZ_DBG_CAN2_STOP            (0x1U<<26)
#define DBG_DBGMCU_APB1_FZ_DBG_CAN1_STOP            (0x1U<<25)
#define DBG_DBGMCU_APB1_FZ_DBG_J2C3SMBUS_TIMEOUT    (0x1U<<23)
#define DBG_DBGMCU_APB1_FZ_DBG_J2C2_SMBUS_TIMEOUT   (0x1U<<22)
#define DBG_DBGMCU_APB1_FZ_DBG_J2C1_SMBUS_TIMEOUT   (0x1U<<21)
#define DBG_DBGMCU_APB1_FZ_DBG_IWDEG_STOP           (0x1U<<12)
#define DBG_DBGMCU_APB1_FZ_DBG_WWDG_STOP            (0x1U<<11)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM14_STOP           (0x1U<<8)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM13_STOP           (0x1U<<7)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM12_STOP           (0x1U<<6)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM7_STOP            (0x1U<<5)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM6_STOP            (0x1U<<4)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM5_STOP            (0x1U<<3)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM4_STOP            (0x1U<<2)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM3_STOP            (0x1U<<1)
#define DBG_DBGMCU_APB1_FZ_DBG_TIM2_STOP            (0x1U<<0)

// DBGMCU_APB2_FZ Configuration

#define DBG_DBGMCU_APB2_FZ_DBG_TIM11_STOP           (0x1U<<18)
#define DBG_DBGMCU_APB2_FZ_DBG_TIM10_STOP           (0x1U<<17)
#define DBG_DBGMCU_APB2_FZ_DBG_TIM9_STOP            (0x1U<<16)
#define DBG_DBGMCU_APB2_FZ_DBG_TIM8_STOP            (0x1U<<1)
#define DBG_DBGMCU_APB2_FZ_DBG_TIM1_STOP            (0x1U<<0)
