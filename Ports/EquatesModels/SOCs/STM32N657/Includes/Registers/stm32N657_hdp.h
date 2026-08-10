/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_hdp equates.
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

#define HDP_CTRL_EN             (0x1U<<0U)

// MUX Configuration

#define HDP_MUX_MUX7            (0xFU<<28U)
#define HDP_MUX_MUX7_0          (0x1U<<28U)
#define HDP_MUX_MUX6            (0xFU<<24U)
#define HDP_MUX_MUX6_0          (0x1U<<24U)
#define HDP_MUX_MUX5            (0xFU<<20U)
#define HDP_MUX_MUX5_0          (0x1U<<20U)
#define HDP_MUX_MUX4            (0xFU<<16U)
#define HDP_MUX_MUX4_0          (0x1U<<16U)
#define HDP_MUX_MUX3            (0xFU<<12U)
#define HDP_MUX_MUX3_0          (0x1U<<12U)
#define HDP_MUX_MUX2            (0xFU<<8U)
#define HDP_MUX_MUX2_0          (0x1U<<8U)
#define HDP_MUX_MUX1            (0xFU<<4U)
#define HDP_MUX_MUX1_0          (0x1U<<4U)
#define HDP_MUX_MUX0            (0xFU<<0U)
#define HDP_MUX_MUX0_0          (0x1U<<0U)

// VAL Configuration

#define HDP_VAL_HDPVAL          (0xFFU<<0U)
#define HDP_VAL_HDPVAL_0        (0x1U<<0U)

// GPOSET Configuration

#define HDP_GPOSET_HDPGPOSET    (0xFFU<<0U)
#define HDP_GPOSET_HDPGPOSET_0  (0x1U<<0U)

// GPOCLR Configuration

#define HDP_GPOCLR_HDPGPOCLR    (0xFFU<<0U)
#define HDP_GPOCLR_HDPGPOCLR_0  (0x1U<<0U)

// GPOVAL Configuration

#define HDP_GPOVAL_HDPGPOVAL    (0xFFU<<0U)
#define HDP_GPOVAL_HDPGPOVAL_0  (0x1U<<0U)
