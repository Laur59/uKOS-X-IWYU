/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_hdp.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_hdp equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// HDP address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CTRL;
    volatile    uint32_t    MUX;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    VAL;
    volatile    uint32_t    GPOSET;
    volatile    uint32_t    GPOCLR;
    volatile    uint32_t    GPOVAL;
} HDP_TypeDef;

#ifdef __cplusplus
#define HDP_NS  reinterpret_cast<HDP_TypeDef *>(0x46000800U)
#define HDP_S   reinterpret_cast<HDP_TypeDef *>(0x56000800U)

#else
#define HDP_NS  ((HDP_TypeDef *)0x46000800U)
#define HDP_S   ((HDP_TypeDef *)0x56000800U)
#endif

// CTRL Configuration

#define HDP_CTRL_EN             (0x1U<<0)

// MUX Configuration

#define HDP_MUX_MUX7            (0xFU<<28)
#define HDP_MUX_MUX7_0          (0x1U<<28)
#define HDP_MUX_MUX6            (0xFU<<24)
#define HDP_MUX_MUX6_0          (0x1U<<24)
#define HDP_MUX_MUX5            (0xFU<<20)
#define HDP_MUX_MUX5_0          (0x1U<<20)
#define HDP_MUX_MUX4            (0xFU<<16)
#define HDP_MUX_MUX4_0          (0x1U<<16)
#define HDP_MUX_MUX3            (0xFU<<12)
#define HDP_MUX_MUX3_0          (0x1U<<12)
#define HDP_MUX_MUX2            (0xFU<<8)
#define HDP_MUX_MUX2_0          (0x1U<<8)
#define HDP_MUX_MUX1            (0xFU<<4)
#define HDP_MUX_MUX1_0          (0x1U<<4)
#define HDP_MUX_MUX0            (0xFU<<0)
#define HDP_MUX_MUX0_0          (0x1U<<0)

// VAL Configuration

#define HDP_VAL_HDPVAL          (0xFFU<<0)
#define HDP_VAL_HDPVAL_0        (0x1U<<0)

// GPOSET Configuration

#define HDP_GPOSET_HDPGPOSET    (0xFFU<<0)
#define HDP_GPOSET_HDPGPOSET_0  (0x1U<<0)

// GPOCLR Configuration

#define HDP_GPOCLR_HDPGPOCLR    (0xFFU<<0)
#define HDP_GPOCLR_HDPGPOCLR_0  (0x1U<<0)

// GPOVAL Configuration

#define HDP_GPOVAL_HDPGPOVAL    (0xFFU<<0)
#define HDP_GPOVAL_HDPGPOVAL_0  (0x1U<<0)
