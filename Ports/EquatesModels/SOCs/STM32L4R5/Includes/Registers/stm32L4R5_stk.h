/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_stk.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_stk equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define STK_CTRL_COUNTFLAG  (0x1U<<16)
#define STK_CTRL_CLKSOURCE  (0x1U<<2)
#define STK_CTRL_TICKINT    (0x1U<<1)
#define STK_CTRL_ENABLE     (0x1U<<0)

// LOAD Configuration

#define STK_LOAD_RELOAD     (0xFFFFFFU<<0)
#define STK_LOAD_RELOAD_0   (0x1U<<0)

// VAL Configuration

#define STK_VAL_CURRENT     (0xFFFFFFU<<0)
#define STK_VAL_CURRENT_0   (0x1U<<0)

// CALIB Configuration

#define STK_CALIB_NOREF     (0x1U<<31)
#define STK_CALIB_SKEW      (0x1U<<30)
#define STK_CALIB_TENMS     (0xFFFFFFU<<0)
#define STK_CALIB_TENMS_0   (0x1U<<0)
