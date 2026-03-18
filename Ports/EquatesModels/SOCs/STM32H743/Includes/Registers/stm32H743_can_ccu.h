/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_can_ccu equates.
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
