/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; RP2350_adc.
; ===========

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     RP2350_adc equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define ADC_CS_EN           (0x1U<<0)
#define ADC_CS_TS_EN        (0x1U<<1)
#define ADC_CS_START_ONCE   (0x1U<<2)
#define ADC_CS_START_MANY   (0x1U<<3)
#define ADC_CS_READY        (0x1U<<8)
#define ADC_CS_ERR          (0x1U<<9)
#define ADC_CS_ERR_STICKY   (0x1U<<10)
#define ADC_CS_AINSEL       (0xFU<<12)
#define ADC_CS_AINSEL_0     (0x1U<<12)
#define ADC_CS_RROBIN       (0x1FFU<<16)
#define ADC_CS_RROBIN_0     (0x1U<<16)

// RESULT Configuration

#define ADC_RESULT_RESULT   (0xFFFU<<0)
#define ADC_RESULT_RESULT_0 (0x1U<<0)

// FCS Configuration

#define ADC_FCS_EN          (0x1U<<0)
#define ADC_FCS_SHIFT       (0x1U<<1)
#define ADC_FCS_ERR         (0x1U<<2)
#define ADC_FCS_DREQ_EN     (0x1U<<3)
#define ADC_FCS_EMPTY       (0x1U<<8)
#define ADC_FCS_FULL        (0x1U<<9)
#define ADC_FCS_UNDER       (0x1U<<10)
#define ADC_FCS_OVER        (0x1U<<11)
#define ADC_FCS_LEVEL       (0xFU<<16)
#define ADC_FCS_LEVEL_0     (0x1U<<16)
#define ADC_FCS_THRESH      (0xFU<<24)
#define ADC_FCS_THRESH_0    (0x1U<<24)

// FIFO Configuration

#define ADC_FIFO_VAL        (0xFFFU<<0)
#define ADC_FIFO_VAL_0      (0x1U<<0)
#define ADC_FIFO_ERR        (0x1U<<15)

// DIV Configuration

#define ADC_DIV_FRAC        (0xFFU<<0)
#define ADC_DIV_FRAC_0      (0x1U<<0)
#define ADC_DIV_INT         (0xFFFFU<<8)
#define ADC_DIV_INT_0       (0x1U<<8)

// INTR Configuration

#define ADC_INTR_FIFO       (0x1U<<0)

// INTE Configuration

#define ADC_INTE_FIFO       (0x1U<<0)

// INTF Configuration

#define ADC_INTF_FIFO       (0x1U<<0)

// INTS Configuration

#define ADC_INTS_FIFO       (0x1U<<0)
