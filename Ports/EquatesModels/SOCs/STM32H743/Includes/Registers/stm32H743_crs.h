/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_crs equates.
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

#define CRS_CR_TRIM         (0x3FU<<8U)
#define CRS_CR_TRIM_0       (0x1U<<8U)
#define CRS_CR_SWSYNC       (0x1U<<7U)
#define CRS_CR_AUTOTRIMEN   (0x1U<<6U)
#define CRS_CR_CEN          (0x1U<<5U)
#define CRS_CR_ESYNCIE      (0x1U<<3U)
#define CRS_CR_ERRIE        (0x1U<<2U)
#define CRS_CR_SYNCWARNIE   (0x1U<<1U)
#define CRS_CR_SYNCOKIE     (0x1U<<0U)

// CFGR Configuration

#define CRS_CFGR_SYNCPOL    (0x1U<<31U)
#define CRS_CFGR_SYNCSRC    (0x3U<<28U)
#define CRS_CFGR_SYNCSRC_0  (0x1U<<28U)
#define CRS_CFGR_SYNCDIV    (0x7U<<24U)
#define CRS_CFGR_SYNCDIV_0  (0x1U<<24U)
#define CRS_CFGR_FELIM      (0xFFU<<16U)
#define CRS_CFGR_FELIM_0    (0x1U<<16U)
#define CRS_CFGR_RELOAD     (0xFFFFU<<0U)
#define CRS_CFGR_RELOAD_0   (0x1U<<0U)

// ISR Configuration

#define CRS_ISR_FECAP       (0xFFFFU<<16U)
#define CRS_ISR_FECAP_0     (0x1U<<16U)
#define CRS_ISR_FEDIR       (0x1U<<15U)
#define CRS_ISR_TRIMOVF     (0x1U<<10U)
#define CRS_ISR_SYNCMISS    (0x1U<<9U)
#define CRS_ISR_SYNCERR     (0x1U<<8U)
#define CRS_ISR_ESYNCF      (0x1U<<3U)
#define CRS_ISR_ERRF        (0x1U<<2U)
#define CRS_ISR_SYNCWARNF   (0x1U<<1U)
#define CRS_ISR_SYNCOKF     (0x1U<<0U)

// ICR Configuration

#define CRS_ICR_ESYNCC      (0x1U<<3U)
#define CRS_ICR_ERRC        (0x1U<<2U)
#define CRS_ICR_SYNCWARNC   (0x1U<<1U)
#define CRS_ICR_SYNCOKC     (0x1U<<0U)
