/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_fpu_cpacr equates.
 */

#pragma once

#include    <stdint.h>

// FPU_CPACR address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    CPACR;
} FPU_CPACR_TypeDef;

#ifdef __cplusplus
#define FPU_CPACR   reinterpret_cast<FPU_CPACR_TypeDef *>(0xE000ED88U)

#else
#define FPU_CPACR   ((FPU_CPACR_TypeDef *)0xE000ED88U)
#endif

// CPACR Configuration

#define FPU_CPACR_CPACR_CP      (0xFU<<20)
#define FPU_CPACR_CPACR_CP_0    (0x1U<<20)
