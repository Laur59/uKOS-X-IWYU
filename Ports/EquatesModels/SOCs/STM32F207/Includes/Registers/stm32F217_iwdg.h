/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_iwdg equates.
 */

#pragma once

#include    <stdint.h>

// IWDG address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    KR;
    volatile    uint32_t    PR;
    volatile    uint32_t    RLR;
    volatile    uint32_t    SR;
} IWDG_TypeDef;

#ifdef __cplusplus
#define IWDG    reinterpret_cast<IWDG_TypeDef *>(0x40003000U)

#else
#define IWDG    ((IWDG_TypeDef *)0x40003000U)
#endif

// KR Configuration

#define IWDG_KR_KEY     (0xFFFFU<<0U)
#define IWDG_KR_KEY_0   (0x1U<<0U)

// PR Configuration

#define IWDG_PR_PR      (0x7U<<0U)
#define IWDG_PR_PR_0    (0x1U<<0U)

// RLR Configuration

#define IWDG_RLR_RL     (0xFFFU<<0U)
#define IWDG_RLR_RL_0   (0x1U<<0U)

// SR Configuration

#define IWDG_SR_PVU     (0x1U<<0U)
#define IWDG_SR_RVU     (0x1U<<1U)
