/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_iwdg equates.
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
    volatile    uint32_t    ICR;
} IWDG_TypeDef;

#ifdef __cplusplus
#define IWDG_NS reinterpret_cast<IWDG_TypeDef *>(0x46004800U)
#define IWDG_S  reinterpret_cast<IWDG_TypeDef *>(0x56004800U)

#else
#define IWDG_NS ((IWDG_TypeDef *)0x46004800U)
#define IWDG_S  ((IWDG_TypeDef *)0x56004800U)
#endif

// KR Configuration

#define IWDG_KR_KEY             (0xFFFFU<<0)
#define IWDG_KR_KEY_0           (0x1U<<0)

// PR Configuration

#define IWDG_PR_PR              (0xFU<<0)
#define IWDG_PR_PR_0            (0x1U<<0)

#define IWDG_PR_PR_B_0X0        (0x0U<<0)
#define IWDG_PR_PR_B_0X1        (0x1U<<0)
#define IWDG_PR_PR_B_0X2        (0x2U<<0)
#define IWDG_PR_PR_B_0X3        (0x3U<<0)
#define IWDG_PR_PR_B_0X4        (0x4U<<0)
#define IWDG_PR_PR_B_0X5        (0x5U<<0)
#define IWDG_PR_PR_B_0X6        (0x6U<<0)
#define IWDG_PR_PR_B_0X7        (0x7U<<0)

// RLR Configuration

#define IWDG_RLR_RL             (0xFFFU<<0)
#define IWDG_RLR_RL_0           (0x1U<<0)

// SR Configuration

#define IWDG_SR_EWIF            (0x1U<<15)
#define IWDG_SR_ONF             (0x1U<<8)
#define IWDG_SR_EWU             (0x1U<<3)
#define IWDG_SR_WVU             (0x1U<<2)
#define IWDG_SR_RVU             (0x1U<<1)
#define IWDG_SR_PVU             (0x1U<<0)

#define IWDG_SR_ONF_B_0X0       (0x0U<<8)
#define IWDG_SR_ONF_B_0X1       (0x1U<<8)

// WINR Configuration

#define IWDG_WINR_WIN           (0xFFFU<<0)
#define IWDG_WINR_WIN_0         (0x1U<<0)

// EWCR Configuration

#define IWDG_EWCR_EWIE          (0x1U<<15)
#define IWDG_EWCR_EWIT          (0xFFFU<<0)
#define IWDG_EWCR_EWIT_0        (0x1U<<0)

#define IWDG_EWCR_EWIE_B_0X0    (0x0U<<15)
#define IWDG_EWCR_EWIE_B_0X1    (0x1U<<15)

// ICR Configuration

#define IWDG_ICR_EWIC           (0x1U<<15)
