/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_otg_fs_pwrclk equates.
 */

#pragma once

#include    <stdint.h>

// OTG_FS_PWRCLK address definitions
// ---------------------------------

typedef struct {
    volatile    uint32_t    FS_PCGCCTL;
} OTG_FS_PWRCLK_TypeDef;

#ifdef __cplusplus
#define OTG_FS_PWRCLK   reinterpret_cast<OTG_FS_PWRCLK_TypeDef *>(0x50000E00U)

#else
#define OTG_FS_PWRCLK   ((OTG_FS_PWRCLK_TypeDef *)0x50000E00U)
#endif

// FS_PCGCCTL Configuration

#define OTG_FS_PWRCLK_FS_PCGCCTL_PHYSUSP    (0x1U<<4U)
#define OTG_FS_PWRCLK_FS_PCGCCTL_GATEHCLK   (0x1U<<1U)
#define OTG_FS_PWRCLK_FS_PCGCCTL_STPPCLK    (0x1U<<0U)
