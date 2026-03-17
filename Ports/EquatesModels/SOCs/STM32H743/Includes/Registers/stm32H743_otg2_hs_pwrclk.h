/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H743_otg2_hs_pwrclk.
; =========================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H743_otg2_hs_pwrclk equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define OTG2_HS_PWRCLK_OTG_HS_PCGCR_PHYSUSP     (0x1U<<4)
#define OTG2_HS_PWRCLK_OTG_HS_PCGCR_GATEHCLK    (0x1U<<1)
#define OTG2_HS_PWRCLK_OTG_HS_PCGCR_STPPCLK     (0x1U<<0)
