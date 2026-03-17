/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_dbg.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_dbg equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// DBG address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    ID;
    volatile    uint32_t    CTL;
} DBG_TypeDef;

#ifdef __cplusplus
#define DBG reinterpret_cast<DBG_TypeDef *>(0xE0042000U)

#else
#define DBG ((DBG_TypeDef *)0xE0042000U)
#endif

// ID Configuration

#define DBG_ID_ID_CODE      (0xFFFFFFFFU<<0)
#define DBG_ID_ID_CODE_0    (0x1U<<0)

// CTL Configuration

#define DBG_CTL_CAN1_HOLD   (0x1U<<21)
#define DBG_CTL_TIMER6_HOLD (0x1U<<20)
#define DBG_CTL_TIMER5_HOLD (0x1U<<19)
#define DBG_CTL_TIMER4_HOLD (0x1U<<18)
#define DBG_CTL_I2C1_HOLD   (0x1U<<16)
#define DBG_CTL_I2C0_HOLD   (0x1U<<15)
#define DBG_CTL_CAN0_HOLD   (0x1U<<14)
#define DBG_CTL_TIMER3_HOLD (0x1U<<13)
#define DBG_CTL_TIMER2_HOLD (0x1U<<12)
#define DBG_CTL_TIMER1_HOLD (0x1U<<11)
#define DBG_CTL_TIMER0_HOLD (0x1U<<10)
#define DBG_CTL_WWDGT_HOLD  (0x1U<<9)
#define DBG_CTL_FWDGT_HOLD  (0x1U<<8)
#define DBG_CTL_STB_HOLD    (0x1U<<2)
#define DBG_CTL_DSLP_HOLD   (0x1U<<1)
#define DBG_CTL_SLP_HOLD    (0x1U<<0)
