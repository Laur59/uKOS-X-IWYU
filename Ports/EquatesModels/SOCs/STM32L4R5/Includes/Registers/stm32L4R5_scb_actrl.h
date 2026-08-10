/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_scb_actrl equates.
 */

#pragma once

#include    <stdint.h>

// SCB_ACTRL address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    ACTRL;
} SCB_ACTRL_TypeDef;

#ifdef __cplusplus
#define SCB_ACTRL   reinterpret_cast<SCB_ACTRL_TypeDef *>(0xE000E008U)

#else
#define SCB_ACTRL   ((SCB_ACTRL_TypeDef *)0xE000E008U)
#endif

// ACTRL Configuration

#define SCB_ACTRL_ACTRL_DISOOFP     (0x1U<<9U)
#define SCB_ACTRL_ACTRL_DISFPCA     (0x1U<<8U)
#define SCB_ACTRL_ACTRL_DISFOLD     (0x1U<<2U)
#define SCB_ACTRL_ACTRL_DISDEFWBUF  (0x1U<<1U)
#define SCB_ACTRL_ACTRL_DISMCYCINT  (0x1U<<0U)
