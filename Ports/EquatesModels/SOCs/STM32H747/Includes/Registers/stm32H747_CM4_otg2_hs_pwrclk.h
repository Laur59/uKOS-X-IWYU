/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_otg2_hs_pwrclk equates.
 */

#pragma once

#include    <stdint.h>

// OTG2_HS_PWRCLK address definitions
// ----------------------------------

typedef struct {
    volatile    uint32_t    OTG_HS_PCGCR;
} OTG2_HS_PWRCLK_TypeDef;

#ifdef __cplusplus
#define OTG2_HS_PWRCLK  reinterpret_cast<OTG2_HS_PWRCLK_TypeDef *>(0x40080E00U)

#else
#define OTG2_HS_PWRCLK  ((OTG2_HS_PWRCLK_TypeDef *)0x40080E00U)
#endif

// OTG_HS_PCGCR Configuration

#define OTG2_HS_PWRCLK_OTG_HS_PCGCR_PHYSUSP     (0x1U<<4U)
#define OTG2_HS_PWRCLK_OTG_HS_PCGCR_GATEHCLK    (0x1U<<1U)
#define OTG2_HS_PWRCLK_OTG_HS_PCGCR_STPPCLK     (0x1U<<0U)
