/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_lpgpio equates.
 */

#pragma once

#include    <stdint.h>

// LPGPIO address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    MODER;
    volatile    uint32_t    RESERVED0[3];
    volatile    uint32_t    IDR;
    volatile    uint32_t    ODR;
    volatile    uint32_t    BSRR;
    volatile    uint32_t    RESERVED1[3];
    volatile    uint32_t    BRR;
} LPGPIO_TypeDef;

#ifdef __cplusplus
#define LPGPIO1_NS  reinterpret_cast<LPGPIO_TypeDef *>(0x46020000U)
#define LPGPIO1_S   reinterpret_cast<LPGPIO_TypeDef *>(0x56020000U)

#else
#define LPGPIO1_NS  ((LPGPIO_TypeDef *)0x46020000U)
#define LPGPIO1_S   ((LPGPIO_TypeDef *)0x56020000U)
#endif

// MODER Configuration

#define LPGPIO_MODER_MODE0  (0x1U<<0U)
#define LPGPIO_MODER_MODE1  (0x1U<<1U)
#define LPGPIO_MODER_MODE2  (0x1U<<2U)
#define LPGPIO_MODER_MODE3  (0x1U<<3U)
#define LPGPIO_MODER_MODE4  (0x1U<<4U)
#define LPGPIO_MODER_MODE5  (0x1U<<5U)
#define LPGPIO_MODER_MODE6  (0x1U<<6U)
#define LPGPIO_MODER_MODE7  (0x1U<<7U)
#define LPGPIO_MODER_MODE8  (0x1U<<8U)
#define LPGPIO_MODER_MODE9  (0x1U<<9U)
#define LPGPIO_MODER_MODE10 (0x1U<<10U)
#define LPGPIO_MODER_MODE11 (0x1U<<11U)
#define LPGPIO_MODER_MODE12 (0x1U<<12U)
#define LPGPIO_MODER_MODE13 (0x1U<<13U)
#define LPGPIO_MODER_MODE14 (0x1U<<14U)
#define LPGPIO_MODER_MODE15 (0x1U<<15U)

// IDR Configuration

#define LPGPIO_IDR_ID0      (0x1U<<0U)
#define LPGPIO_IDR_ID1      (0x1U<<1U)
#define LPGPIO_IDR_ID2      (0x1U<<2U)
#define LPGPIO_IDR_ID3      (0x1U<<3U)
#define LPGPIO_IDR_ID4      (0x1U<<4U)
#define LPGPIO_IDR_ID5      (0x1U<<5U)
#define LPGPIO_IDR_ID6      (0x1U<<6U)
#define LPGPIO_IDR_ID7      (0x1U<<7U)
#define LPGPIO_IDR_ID8      (0x1U<<8U)
#define LPGPIO_IDR_ID9      (0x1U<<9U)
#define LPGPIO_IDR_ID10     (0x1U<<10U)
#define LPGPIO_IDR_ID11     (0x1U<<11U)
#define LPGPIO_IDR_ID12     (0x1U<<12U)
#define LPGPIO_IDR_ID13     (0x1U<<13U)
#define LPGPIO_IDR_ID14     (0x1U<<14U)
#define LPGPIO_IDR_ID15     (0x1U<<15U)

// ODR Configuration

#define LPGPIO_ODR_OD0      (0x1U<<0U)
#define LPGPIO_ODR_OD1      (0x1U<<1U)
#define LPGPIO_ODR_OD2      (0x1U<<2U)
#define LPGPIO_ODR_OD3      (0x1U<<3U)
#define LPGPIO_ODR_OD4      (0x1U<<4U)
#define LPGPIO_ODR_OD5      (0x1U<<5U)
#define LPGPIO_ODR_OD6      (0x1U<<6U)
#define LPGPIO_ODR_OD7      (0x1U<<7U)
#define LPGPIO_ODR_OD8      (0x1U<<8U)
#define LPGPIO_ODR_OD9      (0x1U<<9U)
#define LPGPIO_ODR_OD10     (0x1U<<10U)
#define LPGPIO_ODR_OD11     (0x1U<<11U)
#define LPGPIO_ODR_OD12     (0x1U<<12U)
#define LPGPIO_ODR_OD13     (0x1U<<13U)
#define LPGPIO_ODR_OD14     (0x1U<<14U)
#define LPGPIO_ODR_OD15     (0x1U<<15U)

// BSRR Configuration

#define LPGPIO_BSRR_BS0     (0x1U<<0U)
#define LPGPIO_BSRR_BS1     (0x1U<<1U)
#define LPGPIO_BSRR_BS2     (0x1U<<2U)
#define LPGPIO_BSRR_BS3     (0x1U<<3U)
#define LPGPIO_BSRR_BS4     (0x1U<<4U)
#define LPGPIO_BSRR_BS5     (0x1U<<5U)
#define LPGPIO_BSRR_BS6     (0x1U<<6U)
#define LPGPIO_BSRR_BS7     (0x1U<<7U)
#define LPGPIO_BSRR_BS8     (0x1U<<8U)
#define LPGPIO_BSRR_BS9     (0x1U<<9U)
#define LPGPIO_BSRR_BS10    (0x1U<<10U)
#define LPGPIO_BSRR_BS11    (0x1U<<11U)
#define LPGPIO_BSRR_BS12    (0x1U<<12U)
#define LPGPIO_BSRR_BS13    (0x1U<<13U)
#define LPGPIO_BSRR_BS14    (0x1U<<14U)
#define LPGPIO_BSRR_BS15    (0x1U<<15U)
#define LPGPIO_BSRR_BR0     (0x1U<<16U)
#define LPGPIO_BSRR_BR1     (0x1U<<17U)
#define LPGPIO_BSRR_BR2     (0x1U<<18U)
#define LPGPIO_BSRR_BR3     (0x1U<<19U)
#define LPGPIO_BSRR_BR4     (0x1U<<20U)
#define LPGPIO_BSRR_BR5     (0x1U<<21U)
#define LPGPIO_BSRR_BR6     (0x1U<<22U)
#define LPGPIO_BSRR_BR7     (0x1U<<23U)
#define LPGPIO_BSRR_BR8     (0x1U<<24U)
#define LPGPIO_BSRR_BR9     (0x1U<<25U)
#define LPGPIO_BSRR_BR10    (0x1U<<26U)
#define LPGPIO_BSRR_BR11    (0x1U<<27U)
#define LPGPIO_BSRR_BR12    (0x1U<<28U)
#define LPGPIO_BSRR_BR13    (0x1U<<29U)
#define LPGPIO_BSRR_BR14    (0x1U<<30U)
#define LPGPIO_BSRR_BR15    (0x1U<<31U)

// BRR Configuration

#define LPGPIO_BRR_BR0      (0x1U<<0U)
#define LPGPIO_BRR_BR1      (0x1U<<1U)
#define LPGPIO_BRR_BR2      (0x1U<<2U)
#define LPGPIO_BRR_BR3      (0x1U<<3U)
#define LPGPIO_BRR_BR4      (0x1U<<4U)
#define LPGPIO_BRR_BR5      (0x1U<<5U)
#define LPGPIO_BRR_BR6      (0x1U<<6U)
#define LPGPIO_BRR_BR7      (0x1U<<7U)
#define LPGPIO_BRR_BR8      (0x1U<<8U)
#define LPGPIO_BRR_BR9      (0x1U<<9U)
#define LPGPIO_BRR_BR10     (0x1U<<10U)
#define LPGPIO_BRR_BR11     (0x1U<<11U)
#define LPGPIO_BRR_BR12     (0x1U<<12U)
#define LPGPIO_BRR_BR13     (0x1U<<13U)
#define LPGPIO_BRR_BR14     (0x1U<<14U)
#define LPGPIO_BRR_BR15     (0x1U<<15U)
