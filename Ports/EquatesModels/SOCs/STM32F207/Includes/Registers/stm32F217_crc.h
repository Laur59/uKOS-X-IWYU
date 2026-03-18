/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_crc equates.
 */

#pragma once

#include    <stdint.h>

// CRC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    DR;
    volatile    uint32_t    IDR;
    volatile    uint32_t    CR;
} CRC_TypeDef;

#ifdef __cplusplus
#define CRC reinterpret_cast<CRC_TypeDef *>(0x40023000U)

#else
#define CRC ((CRC_TypeDef *)0x40023000U)
#endif

// DR Configuration

#define CRC_DR_DR       (0xFFFFFFFFU<<0)
#define CRC_DR_DR_0     (0x1U<<0)

// IDR Configuration

#define CRC_IDR_IDR     (0xFFU<<0)
#define CRC_IDR_IDR_0   (0x1U<<0)

// CR Configuration

#define CRC_CR_RESET    (0x1U<<0)
