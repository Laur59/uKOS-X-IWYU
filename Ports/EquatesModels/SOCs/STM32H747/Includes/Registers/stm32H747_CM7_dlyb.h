/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H747_CM7_dlyb.
; ===================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H747_CM7_dlyb equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// DLYB address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR;
} DLYB_TypeDef;

#ifdef __cplusplus
#define DELAY_BLOCK_SDMMC1  reinterpret_cast<DLYB_TypeDef *>(0x52008000U)
#define DELAY_BLOCK_QUADSPI reinterpret_cast<DLYB_TypeDef *>(0x52006000U)
#define DELAY_BLOCK_SDMMC2  reinterpret_cast<DLYB_TypeDef *>(0x48022800U)

#else
#define DELAY_BLOCK_SDMMC1  ((DLYB_TypeDef *)0x52008000U)
#define DELAY_BLOCK_QUADSPI ((DLYB_TypeDef *)0x52006000U)
#define DELAY_BLOCK_SDMMC2  ((DLYB_TypeDef *)0x48022800U)
#endif

// CR Configuration

#define DLYB_CR_SEN         (0x1U<<1)
#define DLYB_CR_DEN         (0x1U<<0)

// CFGR Configuration

#define DLYB_CFGR_LNGF      (0x1U<<31)
#define DLYB_CFGR_LNG       (0xFFFU<<16)
#define DLYB_CFGR_LNG_0     (0x1U<<16)
#define DLYB_CFGR_UNIT      (0x7FU<<8)
#define DLYB_CFGR_UNIT_0    (0x1U<<8)
#define DLYB_CFGR_SEL       (0xFU<<0)
#define DLYB_CFGR_SEL_0     (0x1U<<0)
