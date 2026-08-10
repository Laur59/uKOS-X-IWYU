/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_crc equates.
 */

#pragma once

#include    <stdint.h>

// CRC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    DR;
    volatile    uint32_t    IDR;
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    INIT;
    volatile    uint32_t    POL;
} CRC_TypeDef;

#ifdef __cplusplus
#define CRC reinterpret_cast<CRC_TypeDef *>(0x40023000U)

#else
#define CRC ((CRC_TypeDef *)0x40023000U)
#endif

// DR Configuration

#define CRC_DR_DR                           (0xFFFFFFFFU<<0U)
#define CRC_DR_DR_0                         (0x1U<<0U)

// IDR Configuration

#define CRC_IDR_IDR                         (0xFFU<<0U)
#define CRC_IDR_IDR_0                       (0x1U<<0U)

// CR Configuration

#define CRC_CR_RESET                        (0x1U<<0U)
#define CRC_CR_POLYSIZE                     (0x3U<<3U)
#define CRC_CR_POLYSIZE_0                   (0x1U<<3U)
#define CRC_CR_REV_IN                       (0x3U<<5U)
#define CRC_CR_REV_IN_0                     (0x1U<<5U)
#define CRC_CR_REV_OUT                      (0x1U<<7U)

// INIT Configuration

#define CRC_INIT_CRC_INIT                   (0xFFFFFFFFU<<0U)
#define CRC_INIT_CRC_INIT_0                 (0x1U<<0U)

// POL Configuration

#define CRC_POL_POLYNOMIALCOEFFICIENTS      (0xFFFFFFFFU<<0U)
#define CRC_POL_POLYNOMIALCOEFFICIENTS_0    (0x1U<<0U)
