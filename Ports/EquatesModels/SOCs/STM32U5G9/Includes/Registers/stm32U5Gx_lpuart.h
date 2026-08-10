/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_lpuart equates.
 */

#pragma once

#include    <stdint.h>

// LPUART address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
    volatile    uint32_t    BRR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    RQR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    RDR;
    volatile    uint32_t    TDR;
    volatile    uint32_t    PRESC;
    volatile    uint32_t    AUTOCR;
} LPUART_TypeDef;

#ifdef __cplusplus
#define LPUART1_NS  reinterpret_cast<LPUART_TypeDef *>(0x46002400U)
#define LPUART1_S   reinterpret_cast<LPUART_TypeDef *>(0x56002400U)

#else
#define LPUART1_NS  ((LPUART_TypeDef *)0x46002400U)
#define LPUART1_S   ((LPUART_TypeDef *)0x56002400U)
#endif

// CR1 Configuration

#define LPUART_CR1_UE               (0x1U<<0U)
#define LPUART_CR1_UESM             (0x1U<<1U)
#define LPUART_CR1_RE               (0x1U<<2U)
#define LPUART_CR1_TE               (0x1U<<3U)
#define LPUART_CR1_IDLEIE           (0x1U<<4U)
#define LPUART_CR1_RXFNEIE          (0x1U<<5U)
#define LPUART_CR1_TCIE             (0x1U<<6U)
#define LPUART_CR1_TXFNFIE          (0x1U<<7U)
#define LPUART_CR1_PEIE             (0x1U<<8U)
#define LPUART_CR1_PS               (0x1U<<9U)
#define LPUART_CR1_PCE              (0x1U<<10U)
#define LPUART_CR1_WAKE             (0x1U<<11U)
#define LPUART_CR1_M0               (0x1U<<12U)
#define LPUART_CR1_MME              (0x1U<<13U)
#define LPUART_CR1_CMIE             (0x1U<<14U)
#define LPUART_CR1_DEDT             (0x1FU<<16U)
#define LPUART_CR1_DEDT_0           (0x1U<<16U)
#define LPUART_CR1_DEAT             (0x1FU<<21U)
#define LPUART_CR1_DEAT_0           (0x1U<<21U)
#define LPUART_CR1_M1               (0x1U<<28U)
#define LPUART_CR1_FIFOEN           (0x1U<<29U)
#define LPUART_CR1_TXFEIE           (0x1U<<30U)
#define LPUART_CR1_RXFFIE           (0x1U<<31U)

// CR2 Configuration

#define LPUART_CR2_ADDM7            (0x1U<<4U)
#define LPUART_CR2_STOP             (0x3U<<12U)
#define LPUART_CR2_STOP_0           (0x1U<<12U)
#define LPUART_CR2_SWAP             (0x1U<<15U)
#define LPUART_CR2_RXINV            (0x1U<<16U)
#define LPUART_CR2_TXINV            (0x1U<<17U)
#define LPUART_CR2_DATAINV          (0x1U<<18U)
#define LPUART_CR2_MSBFIRST         (0x1U<<19U)
#define LPUART_CR2_ADD              (0xFFU<<24U)
#define LPUART_CR2_ADD_0            (0x1U<<24U)

// CR3 Configuration

#define LPUART_CR3_EIE              (0x1U<<0U)
#define LPUART_CR3_HDSEL            (0x1U<<3U)
#define LPUART_CR3_DMAR             (0x1U<<6U)
#define LPUART_CR3_DMAT             (0x1U<<7U)
#define LPUART_CR3_RTSE             (0x1U<<8U)
#define LPUART_CR3_CTSE             (0x1U<<9U)
#define LPUART_CR3_CTSIE            (0x1U<<10U)
#define LPUART_CR3_OVRDIS           (0x1U<<12U)
#define LPUART_CR3_DDRE             (0x1U<<13U)
#define LPUART_CR3_DEM              (0x1U<<14U)
#define LPUART_CR3_DEP              (0x1U<<15U)
#define LPUART_CR3_TXFTIE           (0x1U<<23U)
#define LPUART_CR3_RXFTCFG          (0x7U<<25U)
#define LPUART_CR3_RXFTCFG_0        (0x1U<<25U)
#define LPUART_CR3_RXFTIE           (0x1U<<28U)
#define LPUART_CR3_TXFTCFG          (0x7U<<29U)
#define LPUART_CR3_TXFTCFG_0        (0x1U<<29U)

// BRR Configuration

#define LPUART_BRR_BRR              (0xFFFFFU<<0U)
#define LPUART_BRR_BRR_0            (0x1U<<0U)

// RQR Configuration

#define LPUART_RQR_SBKRQ            (0x1U<<1U)
#define LPUART_RQR_MMRQ             (0x1U<<2U)
#define LPUART_RQR_RXFRQ            (0x1U<<3U)
#define LPUART_RQR_TXFRQ            (0x1U<<4U)

// ISR Configuration

#define LPUART_ISR_PE               (0x1U<<0U)
#define LPUART_ISR_FE               (0x1U<<1U)
#define LPUART_ISR_NE               (0x1U<<2U)
#define LPUART_ISR_ORE              (0x1U<<3U)
#define LPUART_ISR_IDLE             (0x1U<<4U)
#define LPUART_ISR_RXFNE            (0x1U<<5U)
#define LPUART_ISR_TC               (0x1U<<6U)
#define LPUART_ISR_TXFNF            (0x1U<<7U)
#define LPUART_ISR_CTSIF            (0x1U<<9U)
#define LPUART_ISR_CTS              (0x1U<<10U)
#define LPUART_ISR_BUSY             (0x1U<<16U)
#define LPUART_ISR_CMF              (0x1U<<17U)
#define LPUART_ISR_SBKF             (0x1U<<18U)
#define LPUART_ISR_RWU              (0x1U<<19U)
#define LPUART_ISR_TEACK            (0x1U<<21U)
#define LPUART_ISR_REACK            (0x1U<<22U)
#define LPUART_ISR_TXFF             (0x1U<<23U)
#define LPUART_ISR_RXFF             (0x1U<<24U)
#define LPUART_ISR_RXFT             (0x1U<<26U)
#define LPUART_ISR_TXFT             (0x1U<<27U)

// ICR Configuration

#define LPUART_ICR_PECF             (0x1U<<0U)
#define LPUART_ICR_FECF             (0x1U<<1U)
#define LPUART_ICR_NECF             (0x1U<<2U)
#define LPUART_ICR_ORECF            (0x1U<<3U)
#define LPUART_ICR_IDLECF           (0x1U<<4U)
#define LPUART_ICR_TCCF             (0x1U<<6U)
#define LPUART_ICR_CTSCF            (0x1U<<9U)
#define LPUART_ICR_CMCF             (0x1U<<17U)

// RDR Configuration

#define LPUART_RDR_RDR              (0x1FFU<<0U)
#define LPUART_RDR_RDR_0            (0x1U<<0U)

// TDR Configuration

#define LPUART_TDR_TDR              (0x1FFU<<0U)
#define LPUART_TDR_TDR_0            (0x1U<<0U)

// PRESC Configuration

#define LPUART_PRESC_PRESCALER      (0xFU<<0U)
#define LPUART_PRESC_PRESCALER_0    (0x1U<<0U)

// AUTOCR Configuration

#define LPUART_AUTOCR_TRIGSEL       (0xFU<<19U)
#define LPUART_AUTOCR_TRIGSEL_0     (0x1U<<19U)
#define LPUART_AUTOCR_IDLEDIS       (0x1U<<18U)
#define LPUART_AUTOCR_TRIGEN        (0x1U<<17U)
#define LPUART_AUTOCR_TRIGPOL       (0x1U<<16U)
#define LPUART_AUTOCR_TDN           (0xFFFFU<<0U)
#define LPUART_AUTOCR_TDN_0         (0x1U<<0U)
