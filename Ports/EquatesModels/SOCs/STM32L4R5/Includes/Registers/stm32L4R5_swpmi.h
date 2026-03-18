/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_swpmi equates.
 */

#pragma once

#include    <stdint.h>

// SWPMI address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    BRR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    IER;
    volatile    uint32_t    RFL;
    volatile    uint32_t    TDR;
    volatile    uint32_t    RDR;
} SWPMI_TypeDef;

#ifdef __cplusplus
#define SWPMI1  reinterpret_cast<SWPMI_TypeDef *>(0x40008800U)

#else
#define SWPMI1  ((SWPMI_TypeDef *)0x40008800U)
#endif

// CR Configuration

#define SWPMI_CR_DEACT      (0x1U<<10)
#define SWPMI_CR_SWPME      (0x1U<<5)
#define SWPMI_CR_LPBK       (0x1U<<4)
#define SWPMI_CR_TXMODE     (0x1U<<3)
#define SWPMI_CR_RXMODE     (0x1U<<2)
#define SWPMI_CR_TXDMA      (0x1U<<1)
#define SWPMI_CR_RXDMA      (0x1U<<0)

// BRR Configuration

#define SWPMI_BRR_BR        (0x3FU<<0)
#define SWPMI_BRR_BR_0      (0x1U<<0)

// ISR Configuration

#define SWPMI_ISR_DEACTF    (0x1U<<10)
#define SWPMI_ISR_SUSP      (0x1U<<9)
#define SWPMI_ISR_SRF       (0x1U<<8)
#define SWPMI_ISR_TCF       (0x1U<<7)
#define SWPMI_ISR_TXE       (0x1U<<6)
#define SWPMI_ISR_RXNE      (0x1U<<5)
#define SWPMI_ISR_TXUNRF    (0x1U<<4)
#define SWPMI_ISR_RXOVRF    (0x1U<<3)
#define SWPMI_ISR_RXBERF    (0x1U<<2)
#define SWPMI_ISR_TXBEF     (0x1U<<1)
#define SWPMI_ISR_RXBFF     (0x1U<<0)

// ICR Configuration

#define SWPMI_ICR_CSRF      (0x1U<<8)
#define SWPMI_ICR_CTCF      (0x1U<<7)
#define SWPMI_ICR_CTXUNRF   (0x1U<<4)
#define SWPMI_ICR_CRXOVRF   (0x1U<<3)
#define SWPMI_ICR_CRXBERF   (0x1U<<2)
#define SWPMI_ICR_CTXBEF    (0x1U<<1)
#define SWPMI_ICR_CRXBFF    (0x1U<<0)

// IER Configuration

#define SWPMI_IER_SRIE      (0x1U<<8)
#define SWPMI_IER_TCIE      (0x1U<<7)
#define SWPMI_IER_TIE       (0x1U<<6)
#define SWPMI_IER_RIE       (0x1U<<5)
#define SWPMI_IER_TXUNRIE   (0x1U<<4)
#define SWPMI_IER_RXOVRIE   (0x1U<<3)
#define SWPMI_IER_RXBERIE   (0x1U<<2)
#define SWPMI_IER_TXBEIE    (0x1U<<1)
#define SWPMI_IER_RXBFIE    (0x1U<<0)

// RFL Configuration

#define SWPMI_RFL_RFL       (0x1FU<<0)
#define SWPMI_RFL_RFL_0     (0x1U<<0)

// TDR Configuration

#define SWPMI_TDR_TD        (0xFFFFFFFFU<<0)
#define SWPMI_TDR_TD_0      (0x1U<<0)

// RDR Configuration

#define SWPMI_RDR_RD        (0xFFFFFFFFU<<0)
#define SWPMI_RDR_RD_0      (0x1U<<0)
