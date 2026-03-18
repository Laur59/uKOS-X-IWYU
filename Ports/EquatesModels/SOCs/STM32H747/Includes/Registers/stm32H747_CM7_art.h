/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_art equates.
 */

#pragma once

#include    <stdint.h>

// ART address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CTR;
} ART_TypeDef;

#ifdef __cplusplus
#define ART reinterpret_cast<ART_TypeDef *>(0x40024400U)

#else
#define ART ((ART_TypeDef *)0x40024400U)
#endif

// CTR Configuration

#define ART_CTR_PCACHEADDR      (0xFFFU<<8)
#define ART_CTR_PCACHEADDR_0    (0x1U<<8)
#define ART_CTR_EN              (0x1U<<0)
