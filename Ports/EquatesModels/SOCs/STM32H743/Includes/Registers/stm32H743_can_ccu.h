/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H743_can_ccu.
; ==================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H743_can_ccu equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// CAN_CCU address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CREL;
    volatile    uint32_t    CCFG;
    volatile    uint32_t    CSTAT;
    volatile    uint32_t    CWD;
    volatile    uint32_t    IR;
    volatile    uint32_t    IE;
} CAN_CCU_TypeDef;

#ifdef __cplusplus
#define CAN_CCU reinterpret_cast<CAN_CCU_TypeDef *>(0x4000A800U)

#else
#define CAN_CCU ((CAN_CCU_TypeDef *)0x4000A800U)
#endif

// CREL Configuration

#define CAN_CCU_CREL_REL        (0xFU<<28)
#define CAN_CCU_CREL_REL_0      (0x1U<<28)
#define CAN_CCU_CREL_STEP       (0xFU<<24)
#define CAN_CCU_CREL_STEP_0     (0x1U<<24)
#define CAN_CCU_CREL_SUBSTEP    (0xFU<<20)
#define CAN_CCU_CREL_SUBSTEP_0  (0x1U<<20)
#define CAN_CCU_CREL_YEAR       (0xFU<<16)
#define CAN_CCU_CREL_YEAR_0     (0x1U<<16)
#define CAN_CCU_CREL_MON        (0xFFU<<8)
#define CAN_CCU_CREL_MON_0      (0x1U<<8)
#define CAN_CCU_CREL_DAY        (0xFFU<<0)
#define CAN_CCU_CREL_DAY_0      (0x1U<<0)

// CCFG Configuration

#define CAN_CCU_CCFG_SWR        (0x1U<<31)
#define CAN_CCU_CCFG_CDIV       (0xFU<<16)
#define CAN_CCU_CCFG_CDIV_0     (0x1U<<16)
#define CAN_CCU_CCFG_OCPM       (0xFFU<<8)
#define CAN_CCU_CCFG_OCPM_0     (0x1U<<8)
#define CAN_CCU_CCFG_CFL        (0x1U<<7)
#define CAN_CCU_CCFG_BCC        (0x1U<<6)
#define CAN_CCU_CCFG_TQBT       (0x1FU<<0)
#define CAN_CCU_CCFG_TQBT_0     (0x1U<<0)

// CSTAT Configuration

#define CAN_CCU_CSTAT_CALS      (0x3U<<30)
#define CAN_CCU_CSTAT_CALS_0    (0x1U<<30)
#define CAN_CCU_CSTAT_TQC       (0x7FFU<<18)
#define CAN_CCU_CSTAT_TQC_0     (0x1U<<18)
#define CAN_CCU_CSTAT_OCPC      (0x3FFFFU<<0)
#define CAN_CCU_CSTAT_OCPC_0    (0x1U<<0)

// CWD Configuration

#define CAN_CCU_CWD_WDV         (0xFFFFU<<16)
#define CAN_CCU_CWD_WDV_0       (0x1U<<16)
#define CAN_CCU_CWD_WDC         (0xFFFFU<<0)
#define CAN_CCU_CWD_WDC_0       (0x1U<<0)

// IR Configuration

#define CAN_CCU_IR_CSC          (0x1U<<1)
#define CAN_CCU_IR_CWE          (0x1U<<0)

// IE Configuration

#define CAN_CCU_IE_CSCE         (0x1U<<1)
#define CAN_CCU_IE_CWEE         (0x1U<<0)
