/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_stk equates.
 */

#pragma once

#include    <stdint.h>

// STK address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CTRL;
    volatile    uint32_t    LOAD;
    volatile    uint32_t    VAL;
    volatile    uint32_t    CALIB;
} STK_TypeDef;

#ifdef __cplusplus
#define STK reinterpret_cast<STK_TypeDef *>(0xE000E010U)

#else
#define STK ((STK_TypeDef *)0xE000E010U)
#endif

// CTRL Configuration

#define STK_CTRL_COUNTFLAG  (0x1U<<16U)
#define STK_CTRL_CLKSOURCE  (0x1U<<2U)
#define STK_CTRL_TICKINT    (0x1U<<1U)
#define STK_CTRL_ENABLE     (0x1U<<0U)

// LOAD Configuration

#define STK_LOAD_RELOAD     (0xFFFFFFU<<0U)
#define STK_LOAD_RELOAD_0   (0x1U<<0U)

// VAL Configuration

#define STK_VAL_CURRENT     (0xFFFFFFU<<0U)
#define STK_VAL_CURRENT_0   (0x1U<<0U)

// CALIB Configuration

#define STK_CALIB_NOREF     (0x1U<<31U)
#define STK_CALIB_SKEW      (0x1U<<30U)
#define STK_CALIB_TENMS     (0xFFFFFFU<<0U)
#define STK_CALIB_TENMS_0   (0x1U<<0U)
