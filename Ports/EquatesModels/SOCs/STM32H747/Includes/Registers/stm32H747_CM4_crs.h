/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H747_CM4_crs.
; ==================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H747_CM4_crs equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// CRS address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
} CRS_TypeDef;

#ifdef __cplusplus
#define CRS reinterpret_cast<CRS_TypeDef *>(0x40008400U)

#else
#define CRS ((CRS_TypeDef *)0x40008400U)
#endif

// CR Configuration

#define CRS_CR_TRIM         (0x3FU<<8)
#define CRS_CR_TRIM_0       (0x1U<<8)
#define CRS_CR_SWSYNC       (0x1U<<7)
#define CRS_CR_AUTOTRIMEN   (0x1U<<6)
#define CRS_CR_CEN          (0x1U<<5)
#define CRS_CR_ESYNCIE      (0x1U<<3)
#define CRS_CR_ERRIE        (0x1U<<2)
#define CRS_CR_SYNCWARNIE   (0x1U<<1)
#define CRS_CR_SYNCOKIE     (0x1U<<0)

// CFGR Configuration

#define CRS_CFGR_SYNCPOL    (0x1U<<31)
#define CRS_CFGR_SYNCSRC    (0x3U<<28)
#define CRS_CFGR_SYNCSRC_0  (0x1U<<28)
#define CRS_CFGR_SYNCDIV    (0x7U<<24)
#define CRS_CFGR_SYNCDIV_0  (0x1U<<24)
#define CRS_CFGR_FELIM      (0xFFU<<16)
#define CRS_CFGR_FELIM_0    (0x1U<<16)
#define CRS_CFGR_RELOAD     (0xFFFFU<<0)
#define CRS_CFGR_RELOAD_0   (0x1U<<0)

// ISR Configuration

#define CRS_ISR_FECAP       (0xFFFFU<<16)
#define CRS_ISR_FECAP_0     (0x1U<<16)
#define CRS_ISR_FEDIR       (0x1U<<15)
#define CRS_ISR_TRIMOVF     (0x1U<<10)
#define CRS_ISR_SYNCMISS    (0x1U<<9)
#define CRS_ISR_SYNCERR     (0x1U<<8)
#define CRS_ISR_ESYNCF      (0x1U<<3)
#define CRS_ISR_ERRF        (0x1U<<2)
#define CRS_ISR_SYNCWARNF   (0x1U<<1)
#define CRS_ISR_SYNCOKF     (0x1U<<0)

// ICR Configuration

#define CRS_ICR_ESYNCC      (0x1U<<3)
#define CRS_ICR_ERRC        (0x1U<<2)
#define CRS_ICR_SYNCWARNC   (0x1U<<1)
#define CRS_ICR_SYNCOKC     (0x1U<<0)
