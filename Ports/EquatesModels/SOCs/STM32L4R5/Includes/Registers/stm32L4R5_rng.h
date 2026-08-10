/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_rng equates.
 */

#pragma once

#include    <stdint.h>

// RNG address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    DR;
} RNG_TypeDef;

#ifdef __cplusplus
#define RNG reinterpret_cast<RNG_TypeDef *>(0x50060800U)

#else
#define RNG ((RNG_TypeDef *)0x50060800U)
#endif

// CR Configuration

#define RNG_CR_RNGEN    (0x1U<<2U)
#define RNG_CR_IE       (0x1U<<3U)

// SR Configuration

#define RNG_SR_DRDY     (0x1U<<0U)
#define RNG_SR_CECS     (0x1U<<1U)
#define RNG_SR_SECS     (0x1U<<2U)
#define RNG_SR_CEIS     (0x1U<<5U)
#define RNG_SR_SEIS     (0x1U<<6U)

// DR Configuration

#define RNG_DR_RNDATA   (0xFFFFFFFFU<<0U)
#define RNG_DR_RNDATA_0 (0x1U<<0U)
