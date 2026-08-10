/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_adc equates.
 */

#pragma once

#include    <stdint.h>

// ADC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CS;
    volatile    uint32_t    RESULT;
    volatile    uint32_t    FCS;
    volatile    uint32_t    FIFO;
    volatile    uint32_t    DIV;
    volatile    uint32_t    INTR;
    volatile    uint32_t    INTE;
    volatile    uint32_t    INTF;
    volatile    uint32_t    INTS;
} ADC_TypeDef;

#ifdef __cplusplus
#define ADC_NS  reinterpret_cast<ADC_TypeDef *>(0x400A0000U)
#define ADC_S   reinterpret_cast<ADC_TypeDef *>(0x400A0000U)
#else
#define ADC_NS  ((ADC_TypeDef *)0x400A0000U)
#define ADC_S   ((ADC_TypeDef *)0x400A0000U)
#endif

// CS Configuration

#define ADC_CS_EN           (0x1U<<0U)
#define ADC_CS_TS_EN        (0x1U<<1U)
#define ADC_CS_START_ONCE   (0x1U<<2U)
#define ADC_CS_START_MANY   (0x1U<<3U)
#define ADC_CS_READY        (0x1U<<8U)
#define ADC_CS_ERR          (0x1U<<9U)
#define ADC_CS_ERR_STICKY   (0x1U<<10U)
#define ADC_CS_AINSEL       (0xFU<<12U)
#define ADC_CS_AINSEL_0     (0x1U<<12U)
#define ADC_CS_RROBIN       (0x1FFU<<16U)
#define ADC_CS_RROBIN_0     (0x1U<<16U)

// RESULT Configuration

#define ADC_RESULT_RESULT   (0xFFFU<<0U)
#define ADC_RESULT_RESULT_0 (0x1U<<0U)

// FCS Configuration

#define ADC_FCS_EN          (0x1U<<0U)
#define ADC_FCS_SHIFT       (0x1U<<1U)
#define ADC_FCS_ERR         (0x1U<<2U)
#define ADC_FCS_DREQ_EN     (0x1U<<3U)
#define ADC_FCS_EMPTY       (0x1U<<8U)
#define ADC_FCS_FULL        (0x1U<<9U)
#define ADC_FCS_UNDER       (0x1U<<10U)
#define ADC_FCS_OVER        (0x1U<<11U)
#define ADC_FCS_LEVEL       (0xFU<<16U)
#define ADC_FCS_LEVEL_0     (0x1U<<16U)
#define ADC_FCS_THRESH      (0xFU<<24U)
#define ADC_FCS_THRESH_0    (0x1U<<24U)

// FIFO Configuration

#define ADC_FIFO_VAL        (0xFFFU<<0U)
#define ADC_FIFO_VAL_0      (0x1U<<0U)
#define ADC_FIFO_ERR        (0x1U<<15U)

// DIV Configuration

#define ADC_DIV_FRAC        (0xFFU<<0U)
#define ADC_DIV_FRAC_0      (0x1U<<0U)
#define ADC_DIV_INT         (0xFFFFU<<8U)
#define ADC_DIV_INT_0       (0x1U<<8U)

// INTR Configuration

#define ADC_INTR_FIFO       (0x1U<<0U)

// INTE Configuration

#define ADC_INTE_FIFO       (0x1U<<0U)

// INTF Configuration

#define ADC_INTF_FIFO       (0x1U<<0U)

// INTS Configuration

#define ADC_INTS_FIFO       (0x1U<<0U)
