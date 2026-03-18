/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_vref equates.
 */

#pragma once

#include    <stdint.h>

// VREF address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    CCR;
} VREF_TypeDef;

#ifdef __cplusplus
#define VREFBUF reinterpret_cast<VREF_TypeDef *>(0x40010030U)

#else
#define VREFBUF ((VREF_TypeDef *)0x40010030U)
#endif

// CSR Configuration

#define VREF_CSR_VRR    (0x1U<<3)
#define VREF_CSR_VRS    (0x1U<<2)
#define VREF_CSR_HIZ    (0x1U<<1)
#define VREF_CSR_ENVR   (0x1U<<0)

// CCR Configuration

#define VREF_CCR_TRIM   (0x3FU<<0)
#define VREF_CCR_TRIM_0 (0x1U<<0)
