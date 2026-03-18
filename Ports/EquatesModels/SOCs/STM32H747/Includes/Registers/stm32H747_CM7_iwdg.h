/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_iwdg equates.
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
    volatile    uint32_t    WINR;
} IWDG_TypeDef;

#ifdef __cplusplus
#define IWDG1   reinterpret_cast<IWDG_TypeDef *>(0x58004800U)
#define IWDG2   reinterpret_cast<IWDG_TypeDef *>(0x58004C00U)

#else
#define IWDG1   ((IWDG_TypeDef *)0x58004800U)
#define IWDG2   ((IWDG_TypeDef *)0x58004C00U)
#endif

// KR Configuration

#define IWDG_KR_KEY     (0xFFFFU<<0)
#define IWDG_KR_KEY_0   (0x1U<<0)

// PR Configuration

#define IWDG_PR_PR      (0x7U<<0)
#define IWDG_PR_PR_0    (0x1U<<0)

// RLR Configuration

#define IWDG_RLR_RL     (0xFFFU<<0)
#define IWDG_RLR_RL_0   (0x1U<<0)

// SR Configuration

#define IWDG_SR_WVU     (0x1U<<2)
#define IWDG_SR_RVU     (0x1U<<1)
#define IWDG_SR_PVU     (0x1U<<0)

// WINR Configuration

#define IWDG_WINR_WIN   (0xFFFU<<0)
#define IWDG_WINR_WIN_0 (0x1U<<0)
