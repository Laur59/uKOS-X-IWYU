/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_usbfs_pwrclk equates.
 */

#pragma once

#include    <stdint.h>

// USBFS_PWRCLK address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    PWRCLKCTL;
} USBFS_PWRCLK_TypeDef;

#ifdef __cplusplus
#define USBFS_PWRCLK    reinterpret_cast<USBFS_PWRCLK_TypeDef *>(0x50000E00U)

#else
#define USBFS_PWRCLK    ((USBFS_PWRCLK_TypeDef *)0x50000E00U)
#endif

// PWRCLKCTL Configuration

#define USBFS_PWRCLK_PWRCLKCTL_SHCLK    (0x1U<<1U)
#define USBFS_PWRCLK_PWRCLKCTL_SUCLK    (0x1U<<0U)
