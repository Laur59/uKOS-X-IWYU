/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_tbman equates.
 */

#pragma once

#include    <stdint.h>

// TBMAN address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    PLATFORM;
} TBMAN_TypeDef;

#ifdef __cplusplus
#define TBMAN_NS    reinterpret_cast<TBMAN_TypeDef *>(0x40160000U)
#define TBMAN_S     reinterpret_cast<TBMAN_TypeDef *>(0x40160000U)
#else
#define TBMAN_NS    ((TBMAN_TypeDef *)0x40160000U)
#define TBMAN_S     ((TBMAN_TypeDef *)0x40160000U)
#endif

// PLATFORM Configuration

#define TBMAN_PLATFORM_ASIC     (0x1U<<0U)
#define TBMAN_PLATFORM_FPGA     (0x1U<<1U)
#define TBMAN_PLATFORM_HDLSIM   (0x1U<<2U)
