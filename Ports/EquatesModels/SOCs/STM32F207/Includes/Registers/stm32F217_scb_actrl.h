/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_scb_actrl equates.
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

#define SCB_ACTRL_ACTRL_DISITMATBFLUSH  (0x1U<<12U)
#define SCB_ACTRL_ACTRL_DISRAMODE       (0x1U<<11U)
#define SCB_ACTRL_ACTRL_FPEXCODIS       (0x1U<<10U)
#define SCB_ACTRL_ACTRL_DISFOLD         (0x1U<<2U)
