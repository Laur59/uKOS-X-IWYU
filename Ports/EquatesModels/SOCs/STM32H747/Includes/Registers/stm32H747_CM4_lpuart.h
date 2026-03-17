/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H747_CM4_lpuart.
; =====================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H747_CM4_lpuart equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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
    volatile    uint32_t    GTPR;
    volatile    uint32_t    RTOR;
    volatile    uint32_t    RQR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    RDR;
    volatile    uint32_t    TDR;
    volatile    uint32_t    PRESC;
} LPUART_TypeDef;

#ifdef __cplusplus
#define LPUART1 reinterpret_cast<LPUART_TypeDef *>(0x58000C00U)

#else
#define LPUART1 ((LPUART_TypeDef *)0x58000C00U)
#endif

// CR1 Configuration

#define LPUART_CR1_UE               (0x1U<<0)
#define LPUART_CR1_UESM             (0x1U<<1)
#define LPUART_CR1_RE               (0x1U<<2)
#define LPUART_CR1_TE               (0x1U<<3)
#define LPUART_CR1_IDLEIE           (0x1U<<4)
#define LPUART_CR1_RXNEIE           (0x1U<<5)
#define LPUART_CR1_TCIE             (0x1U<<6)
#define LPUART_CR1_TXEIE            (0x1U<<7)
#define LPUART_CR1_PEIE             (0x1U<<8)
#define LPUART_CR1_PS               (0x1U<<9)
#define LPUART_CR1_PCE              (0x1U<<10)
#define LPUART_CR1_WAKE             (0x1U<<11)
#define LPUART_CR1_M0               (0x1U<<12)
#define LPUART_CR1_MME              (0x1U<<13)
#define LPUART_CR1_CMIE             (0x1U<<14)
#define LPUART_CR1_DEDT             (0x1FU<<16)
#define LPUART_CR1_DEDT_0           (0x1U<<16)
#define LPUART_CR1_DEAT             (0x1FU<<21)
#define LPUART_CR1_DEAT_0           (0x1U<<21)
#define LPUART_CR1_M1               (0x1U<<28)
#define LPUART_CR1_FIFOEN           (0x1U<<29)
#define LPUART_CR1_TXFEIE           (0x1U<<30)
#define LPUART_CR1_RXFFIE           (0x1U<<31)

// CR2 Configuration

#define LPUART_CR2_ADDM7            (0x1U<<4)
#define LPUART_CR2_STOP             (0x3U<<12)
#define LPUART_CR2_STOP_0           (0x1U<<12)
#define LPUART_CR2_SWAP             (0x1U<<15)
#define LPUART_CR2_RXINV            (0x1U<<16)
#define LPUART_CR2_TXINV            (0x1U<<17)
#define LPUART_CR2_DATAINV          (0x1U<<18)
#define LPUART_CR2_MSBFIRST         (0x1U<<19)
#define LPUART_CR2_ADD              (0xFFU<<24)
#define LPUART_CR2_ADD_0            (0x1U<<24)

// CR3 Configuration

#define LPUART_CR3_EIE              (0x1U<<0)
#define LPUART_CR3_HDSEL            (0x1U<<3)
#define LPUART_CR3_DMAR             (0x1U<<6)
#define LPUART_CR3_DMAT             (0x1U<<7)
#define LPUART_CR3_RTSE             (0x1U<<8)
#define LPUART_CR3_CTSE             (0x1U<<9)
#define LPUART_CR3_CTSIE            (0x1U<<10)
#define LPUART_CR3_OVRDIS           (0x1U<<12)
#define LPUART_CR3_DDRE             (0x1U<<13)
#define LPUART_CR3_DEM              (0x1U<<14)
#define LPUART_CR3_DEP              (0x1U<<15)
#define LPUART_CR3_WUS              (0x3U<<20)
#define LPUART_CR3_WUS_0            (0x1U<<20)
#define LPUART_CR3_WUFIE            (0x1U<<22)
#define LPUART_CR3_TXFTIE           (0x1U<<23)
#define LPUART_CR3_RXFTCFG          (0x7U<<25)
#define LPUART_CR3_RXFTCFG_0        (0x1U<<25)
#define LPUART_CR3_RXFTIE           (0x1U<<28)
#define LPUART_CR3_TXFTCFG          (0x7U<<29)
#define LPUART_CR3_TXFTCFG_0        (0x1U<<29)

// BRR Configuration

#define LPUART_BRR_BRR              (0xFFFFFU<<0)
#define LPUART_BRR_BRR_0            (0x1U<<0)

// GTPR Configuration

#define LPUART_GTPR_PSC             (0xFFU<<0)
#define LPUART_GTPR_PSC_0           (0x1U<<0)
#define LPUART_GTPR_GT              (0xFFU<<8)
#define LPUART_GTPR_GT_0            (0x1U<<8)

// RTOR Configuration

#define LPUART_RTOR_RTO             (0xFFFFFFU<<0)
#define LPUART_RTOR_RTO_0           (0x1U<<0)
#define LPUART_RTOR_BLEN            (0xFFU<<24)
#define LPUART_RTOR_BLEN_0          (0x1U<<24)

// RQR Configuration

#define LPUART_RQR_ABRRQ            (0x1U<<0)
#define LPUART_RQR_SBKRQ            (0x1U<<1)
#define LPUART_RQR_MMRQ             (0x1U<<2)
#define LPUART_RQR_RXFRQ            (0x1U<<3)
#define LPUART_RQR_TXFRQ            (0x1U<<4)

// ISR Configuration

#define LPUART_ISR_PE               (0x1U<<0)
#define LPUART_ISR_FE               (0x1U<<1)
#define LPUART_ISR_NE               (0x1U<<2)
#define LPUART_ISR_ORE              (0x1U<<3)
#define LPUART_ISR_IDLE             (0x1U<<4)
#define LPUART_ISR_RXNE             (0x1U<<5)
#define LPUART_ISR_TC               (0x1U<<6)
#define LPUART_ISR_TXE              (0x1U<<7)
#define LPUART_ISR_CTSIF            (0x1U<<9)
#define LPUART_ISR_CTS              (0x1U<<10)
#define LPUART_ISR_BUSY             (0x1U<<16)
#define LPUART_ISR_CMF              (0x1U<<17)
#define LPUART_ISR_SBKF             (0x1U<<18)
#define LPUART_ISR_RWU              (0x1U<<19)
#define LPUART_ISR_WUF              (0x1U<<20)
#define LPUART_ISR_TEACK            (0x1U<<21)
#define LPUART_ISR_REACK            (0x1U<<22)
#define LPUART_ISR_TXFE             (0x1U<<23)
#define LPUART_ISR_RXFF             (0x1U<<24)
#define LPUART_ISR_RXFT             (0x1U<<26)
#define LPUART_ISR_TXFT             (0x1U<<27)

// ICR Configuration

#define LPUART_ICR_PECF             (0x1U<<0)
#define LPUART_ICR_FECF             (0x1U<<1)
#define LPUART_ICR_NCF              (0x1U<<2)
#define LPUART_ICR_ORECF            (0x1U<<3)
#define LPUART_ICR_IDLECF           (0x1U<<4)
#define LPUART_ICR_TCCF             (0x1U<<6)
#define LPUART_ICR_CTSCF            (0x1U<<9)
#define LPUART_ICR_CMCF             (0x1U<<17)
#define LPUART_ICR_WUCF             (0x1U<<20)

// RDR Configuration

#define LPUART_RDR_RDR              (0x1FFU<<0)
#define LPUART_RDR_RDR_0            (0x1U<<0)

// TDR Configuration

#define LPUART_TDR_TDR              (0x1FFU<<0)
#define LPUART_TDR_TDR_0            (0x1U<<0)

// PRESC Configuration

#define LPUART_PRESC_PRESCALER      (0xFU<<0)
#define LPUART_PRESC_PRESCALER_0    (0x1U<<0)
