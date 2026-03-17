/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H747_CM7_otg1_hs_pwrclk.
; =============================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H747_CM7_otg1_hs_pwrclk equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// OTG1_HS_PWRCLK address definitions
// ----------------------------------

typedef struct {
    volatile    uint32_t    OTG_HS_PCGCR;
} OTG1_HS_PWRCLK_TypeDef;

#ifdef __cplusplus
#define OTG1_HS_PWRCLK  reinterpret_cast<OTG1_HS_PWRCLK_TypeDef *>(0x40040E00U)

#else
#define OTG1_HS_PWRCLK  ((OTG1_HS_PWRCLK_TypeDef *)0x40040E00U)
#endif

// OTG_HS_PCGCR Configuration

#define OTG1_HS_PWRCLK_OTG_HS_PCGCR_PHYSUSP     (0x1U<<4)
#define OTG1_HS_PWRCLK_OTG_HS_PCGCR_GATEHCLK    (0x1U<<1)
#define OTG1_HS_PWRCLK_OTG_HS_PCGCR_STPPCLK     (0x1U<<0)
