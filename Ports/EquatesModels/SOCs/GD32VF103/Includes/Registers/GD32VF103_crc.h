/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_crc equates.
 */

#pragma once

#include    <stdint.h>

// CRC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    DATA;
    volatile    uint32_t    FDATA;
    volatile    uint32_t    CTL;
} CRC_TypeDef;

#ifdef __cplusplus
#define CRC reinterpret_cast<CRC_TypeDef *>(0x40023000U)

#else
#define CRC ((CRC_TypeDef *)0x40023000U)
#endif

// DATA Configuration

#define CRC_DATA_DATA       (0xFFFFFFFFU<<0U)
#define CRC_DATA_DATA_0     (0x1U<<0U)

// FDATA Configuration

#define CRC_FDATA_FDATA     (0xFFU<<0U)
#define CRC_FDATA_FDATA_0   (0x1U<<0U)

// CTL Configuration

#define CRC_CTL_RST         (0x1U<<0U)
