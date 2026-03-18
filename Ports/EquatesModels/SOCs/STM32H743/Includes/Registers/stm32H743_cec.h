/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_cec equates.
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

#define CEC_CR_TXEOM        (0x1U<<2)
#define CEC_CR_TXSOM        (0x1U<<1)
#define CEC_CR_CECEN        (0x1U<<0)

// CFGR Configuration

#define CEC_CFGR_LSTN       (0x1U<<31)
#define CEC_CFGR_OAR        (0x7FFFU<<16)
#define CEC_CFGR_OAR_0      (0x1U<<16)
#define CEC_CFGR_SFTOPT     (0x1U<<8)
#define CEC_CFGR_BRDNOGEN   (0x1U<<7)
#define CEC_CFGR_LBPEGEN    (0x1U<<6)
#define CEC_CFGR_BREGEN     (0x1U<<5)
#define CEC_CFGR_BRESTP     (0x1U<<4)
#define CEC_CFGR_RXTOL      (0x1U<<3)
#define CEC_CFGR_SFT        (0x7U<<0)
#define CEC_CFGR_SFT_0      (0x1U<<0)

// TXDR Configuration

#define CEC_TXDR_TXD        (0xFFU<<0)
#define CEC_TXDR_TXD_0      (0x1U<<0)

// RXDR Configuration

#define CEC_RXDR_RXD        (0xFFU<<0)
#define CEC_RXDR_RXD_0      (0x1U<<0)

// ISR Configuration

#define CEC_ISR_TXACKE      (0x1U<<12)
#define CEC_ISR_TXERR       (0x1U<<11)
#define CEC_ISR_TXUDR       (0x1U<<10)
#define CEC_ISR_TXEND       (0x1U<<9)
#define CEC_ISR_TXBR        (0x1U<<8)
#define CEC_ISR_ARBLST      (0x1U<<7)
#define CEC_ISR_RXACKE      (0x1U<<6)
#define CEC_ISR_LBPE        (0x1U<<5)
#define CEC_ISR_SBPE        (0x1U<<4)
#define CEC_ISR_BRE         (0x1U<<3)
#define CEC_ISR_RXOVR       (0x1U<<2)
#define CEC_ISR_RXEND       (0x1U<<1)
#define CEC_ISR_RXBR        (0x1U<<0)

// IER Configuration

#define CEC_IER_TXACKIE     (0x1U<<12)
#define CEC_IER_TXERRIE     (0x1U<<11)
#define CEC_IER_TXUDRIE     (0x1U<<10)
#define CEC_IER_TXENDIE     (0x1U<<9)
#define CEC_IER_TXBRIE      (0x1U<<8)
#define CEC_IER_ARBLSTIE    (0x1U<<7)
#define CEC_IER_RXACKIE     (0x1U<<6)
#define CEC_IER_LBPEIE      (0x1U<<5)
#define CEC_IER_SBPEIE      (0x1U<<4)
#define CEC_IER_BREIE       (0x1U<<3)
#define CEC_IER_RXOVRIE     (0x1U<<2)
#define CEC_IER_RXENDIE     (0x1U<<1)
#define CEC_IER_RXBRIE      (0x1U<<0)
