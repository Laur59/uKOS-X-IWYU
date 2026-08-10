/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_iwdg equates.
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
    volatile    uint32_t    EWCR;
} IWDG_TypeDef;

#ifdef __cplusplus
#define IWDG_NS reinterpret_cast<IWDG_TypeDef *>(0x40003000U)
#define IWDG_S  reinterpret_cast<IWDG_TypeDef *>(0x50003000U)

#else
#define IWDG_NS ((IWDG_TypeDef *)0x40003000U)
#define IWDG_S  ((IWDG_TypeDef *)0x50003000U)
#endif

// KR Configuration

#define IWDG_KR_KEY         (0xFFFFU<<0U)
#define IWDG_KR_KEY_0       (0x1U<<0U)

// PR Configuration

#define IWDG_PR_PR          (0xFU<<0U)
#define IWDG_PR_PR_0        (0x1U<<0U)

// RLR Configuration

#define IWDG_RLR_RL         (0xFFFU<<0U)
#define IWDG_RLR_RL_0       (0x1U<<0U)

// SR Configuration

#define IWDG_SR_PVU         (0x1U<<0U)
#define IWDG_SR_RVU         (0x1U<<1U)
#define IWDG_SR_WVU         (0x1U<<2U)
#define IWDG_SR_EWU         (0x1U<<3U)
#define IWDG_SR_EWIF        (0x1U<<14U)

// WINR Configuration

#define IWDG_WINR_WIN       (0xFFFU<<0U)
#define IWDG_WINR_WIN_0     (0x1U<<0U)

// EWCR Configuration

#define IWDG_EWCR_EWIE      (0x1U<<15U)
#define IWDG_EWCR_EWIC      (0x1U<<14U)
#define IWDG_EWCR_EWIT      (0xFFFU<<0U)
#define IWDG_EWCR_EWIT_0    (0x1U<<0U)
