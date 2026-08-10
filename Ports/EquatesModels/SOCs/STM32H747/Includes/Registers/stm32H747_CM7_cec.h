/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_cec equates.
 */

#pragma once

#include    <stdint.h>

// CEC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    TXDR;
    volatile    uint32_t    RXDR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    IER;
} CEC_TypeDef;

#ifdef __cplusplus
#define CEC reinterpret_cast<CEC_TypeDef *>(0x40006C00U)

#else
#define CEC ((CEC_TypeDef *)0x40006C00U)
#endif

// CR Configuration

#define CEC_CR_TXEOM        (0x1U<<2U)
#define CEC_CR_TXSOM        (0x1U<<1U)
#define CEC_CR_CECEN        (0x1U<<0U)

// CFGR Configuration

#define CEC_CFGR_LSTN       (0x1U<<31U)
#define CEC_CFGR_OAR        (0x7FFFU<<16U)
#define CEC_CFGR_OAR_0      (0x1U<<16U)
#define CEC_CFGR_SFTOPT     (0x1U<<8U)
#define CEC_CFGR_BRDNOGEN   (0x1U<<7U)
#define CEC_CFGR_LBPEGEN    (0x1U<<6U)
#define CEC_CFGR_BREGEN     (0x1U<<5U)
#define CEC_CFGR_BRESTP     (0x1U<<4U)
#define CEC_CFGR_RXTOL      (0x1U<<3U)
#define CEC_CFGR_SFT        (0x7U<<0U)
#define CEC_CFGR_SFT_0      (0x1U<<0U)

// TXDR Configuration

#define CEC_TXDR_TXD        (0xFFU<<0U)
#define CEC_TXDR_TXD_0      (0x1U<<0U)

// RXDR Configuration

#define CEC_RXDR_RXD        (0xFFU<<0U)
#define CEC_RXDR_RXD_0      (0x1U<<0U)

// ISR Configuration

#define CEC_ISR_TXACKE      (0x1U<<12U)
#define CEC_ISR_TXERR       (0x1U<<11U)
#define CEC_ISR_TXUDR       (0x1U<<10U)
#define CEC_ISR_TXEND       (0x1U<<9U)
#define CEC_ISR_TXBR        (0x1U<<8U)
#define CEC_ISR_ARBLST      (0x1U<<7U)
#define CEC_ISR_RXACKE      (0x1U<<6U)
#define CEC_ISR_LBPE        (0x1U<<5U)
#define CEC_ISR_SBPE        (0x1U<<4U)
#define CEC_ISR_BRE         (0x1U<<3U)
#define CEC_ISR_RXOVR       (0x1U<<2U)
#define CEC_ISR_RXEND       (0x1U<<1U)
#define CEC_ISR_RXBR        (0x1U<<0U)

// IER Configuration

#define CEC_IER_TXACKIE     (0x1U<<12U)
#define CEC_IER_TXERRIE     (0x1U<<11U)
#define CEC_IER_TXUDRIE     (0x1U<<10U)
#define CEC_IER_TXENDIE     (0x1U<<9U)
#define CEC_IER_TXBRIE      (0x1U<<8U)
#define CEC_IER_ARBLSTIE    (0x1U<<7U)
#define CEC_IER_RXACKIE     (0x1U<<6U)
#define CEC_IER_LBPEIE      (0x1U<<5U)
#define CEC_IER_SBPEIE      (0x1U<<4U)
#define CEC_IER_BREIE       (0x1U<<3U)
#define CEC_IER_RXOVRIE     (0x1U<<2U)
#define CEC_IER_RXENDIE     (0x1U<<1U)
#define CEC_IER_RXBRIE      (0x1U<<0U)
