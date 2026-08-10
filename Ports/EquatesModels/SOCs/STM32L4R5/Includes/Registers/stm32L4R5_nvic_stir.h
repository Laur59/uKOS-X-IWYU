/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_nvic_stir equates.
 */

#pragma once

#include    <stdint.h>

// NVIC_STIR address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    STIR;
} NVIC_STIR_TypeDef;

#ifdef __cplusplus
#define NVIC_STIR   reinterpret_cast<NVIC_STIR_TypeDef *>(0xE000EF00U)

#else
#define NVIC_STIR   ((NVIC_STIR_TypeDef *)0xE000EF00U)
#endif

// STIR Configuration

#define NVIC_STIR_STIR_INTID    (0x1FFU<<0U)
#define NVIC_STIR_STIR_INTID_0  (0x1U<<0U)
