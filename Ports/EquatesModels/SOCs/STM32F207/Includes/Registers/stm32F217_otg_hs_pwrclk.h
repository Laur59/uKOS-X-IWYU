/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32F217_otg_hs_pwrclk.
; ========================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32F217_otg_hs_pwrclk equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

// OTG_HS_PWRCLK address definitions
#include    <stdint.h>

// ---------------------------------

typedef struct {
    volatile    uint32_t    OTG_HS_PCGCR;
} OTG_HS_PWRCLK_TypeDef;

#ifdef __cplusplus
#define OTG_HS_PWRCLK   reinterpret_cast<OTG_HS_PWRCLK_TypeDef *>(0x40040E00U)

#else
#define OTG_HS_PWRCLK   ((OTG_HS_PWRCLK_TypeDef *)0x40040E00U)
#endif

// OTG_HS_PCGCR Configuration

#define OTG_HS_PWRCLK_OTG_HS_PCGCR_PHYSUSP  (0x1U<<4)
#define OTG_HS_PWRCLK_OTG_HS_PCGCR_GATEHCLK (0x1U<<1)
#define OTG_HS_PWRCLK_OTG_HS_PCGCR_STPPCLK  (0x1U<<0)
