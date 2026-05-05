/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_cec equates.
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

#if (defined(__cplusplus))
#define CEC_NS  reinterpret_cast<CEC_TypeDef *>(0x40006C00u)
#define CEC_S   reinterpret_cast<CEC_TypeDef *>(0x50006C00u)

#else
#define CEC_NS  ((CEC_TypeDef *)0x40006C00u)
#define CEC_S   ((CEC_TypeDef *)0x50006C00u)
#endif

// CR Configuration

#define CEC_CR_TXEOM            (0x1u<<2)
#define CEC_CR_TXSOM            (0x1u<<1)
#define CEC_CR_CECEN            (0x1u<<0)

#define CEC_CR_TXEOM_B_0X0      (0x0u<<2)
#define CEC_CR_TXEOM_B_0X1      (0x1u<<2)
#define CEC_CR_TXSOM_B_0X0      (0x0u<<1)
#define CEC_CR_TXSOM_B_0X1      (0x1u<<1)
#define CEC_CR_CECEN_B_0X0      (0x0u<<0)
#define CEC_CR_CECEN_B_0X1      (0x1u<<0)

// CFGR Configuration

#define CEC_CFGR_LSTN           (0x1u<<31)
#define CEC_CFGR_OAR            (0x7FFFu<<16)
#define CEC_CFGR_OAR_0          (0x1u<<16)
#define CEC_CFGR_SFTOP          (0x1u<<8)
#define CEC_CFGR_BRDNOGEN       (0x1u<<7)
#define CEC_CFGR_LBPEGEN        (0x1u<<6)
#define CEC_CFGR_BREGEN         (0x1u<<5)
#define CEC_CFGR_BRESTP         (0x1u<<4)
#define CEC_CFGR_RXTOL          (0x1u<<3)
#define CEC_CFGR_SFT            (0x7u<<0)
#define CEC_CFGR_SFT_0          (0x1u<<0)

#define CEC_CFGR_LSTN_B_0X0     (0x0u<<31)
#define CEC_CFGR_LSTN_B_0X1     (0x1u<<31)
#define CEC_CFGR_SFTOP_B_0X0    (0x0u<<8)
#define CEC_CFGR_SFTOP_B_0X1    (0x1u<<8)
#define CEC_CFGR_BRDNOGEN_B_0X0 (0x0u<<7)
#define CEC_CFGR_BRDNOGEN_B_0X1 (0x1u<<7)
#define CEC_CFGR_LBPEGEN_B_0X0  (0x0u<<6)
#define CEC_CFGR_LBPEGEN_B_0X1  (0x1u<<6)
#define CEC_CFGR_BREGEN_B_0X0   (0x0u<<5)
#define CEC_CFGR_BREGEN_B_0X1   (0x1u<<5)
#define CEC_CFGR_BRESTP_B_0X0   (0x0u<<4)
#define CEC_CFGR_BRESTP_B_0X1   (0x1u<<4)
#define CEC_CFGR_RXTOL_B_0X0    (0x0u<<3)
#define CEC_CFGR_RXTOL_B_0X1    (0x1u<<3)
#define CEC_CFGR_SFT_B_0X1      (0x1u<<0)
#define CEC_CFGR_SFT_B_0X2      (0x2u<<0)
#define CEC_CFGR_SFT_B_0X3      (0x3u<<0)
#define CEC_CFGR_SFT_B_0X4      (0x4u<<0)
#define CEC_CFGR_SFT_B_0X5      (0x5u<<0)
#define CEC_CFGR_SFT_B_0X6      (0x6u<<0)
#define CEC_CFGR_SFT_B_0X7      (0x7u<<0)

// TXDR Configuration

#define CEC_TXDR_TXD            (0xFFu<<0)
#define CEC_TXDR_TXD_0          (0x1u<<0)

// RXDR Configuration

#define CEC_RXDR_RXD            (0xFFu<<0)
#define CEC_RXDR_RXD_0          (0x1u<<0)

// ISR Configuration

#define CEC_ISR_TXACKE          (0x1u<<12)
#define CEC_ISR_TXERR           (0x1u<<11)
#define CEC_ISR_TXUDR           (0x1u<<10)
#define CEC_ISR_TXEND           (0x1u<<9)
#define CEC_ISR_TXBR            (0x1u<<8)
#define CEC_ISR_ARBLST          (0x1u<<7)
#define CEC_ISR_RXACKE          (0x1u<<6)
#define CEC_ISR_LBPE            (0x1u<<5)
#define CEC_ISR_SBPE            (0x1u<<4)
#define CEC_ISR_BRE             (0x1u<<3)
#define CEC_ISR_RXOVR           (0x1u<<2)
#define CEC_ISR_RXEND           (0x1u<<1)
#define CEC_ISR_RXBR            (0x1u<<0)

// IER Configuration

#define CEC_IER_TXACKIE         (0x1u<<12)
#define CEC_IER_TXERRIE         (0x1u<<11)
#define CEC_IER_TXUDRIE         (0x1u<<10)
#define CEC_IER_TXENDIE         (0x1u<<9)
#define CEC_IER_TXBRIE          (0x1u<<8)
#define CEC_IER_ARBLSTIE        (0x1u<<7)
#define CEC_IER_RXACKIE         (0x1u<<6)
#define CEC_IER_LBPEIE          (0x1u<<5)
#define CEC_IER_SBPEIE          (0x1u<<4)
#define CEC_IER_BREIE           (0x1u<<3)
#define CEC_IER_RXOVRIE         (0x1u<<2)
#define CEC_IER_RXENDIE         (0x1u<<1)
#define CEC_IER_RXBRIE          (0x1u<<0)

#define CEC_IER_TXACKIE_B_0X0   (0x0u<<12)
#define CEC_IER_TXACKIE_B_0X1   (0x1u<<12)
#define CEC_IER_TXERRIE_B_0X0   (0x0u<<11)
#define CEC_IER_TXERRIE_B_0X1   (0x1u<<11)
#define CEC_IER_TXUDRIE_B_0X0   (0x0u<<10)
#define CEC_IER_TXUDRIE_B_0X1   (0x1u<<10)
#define CEC_IER_TXENDIE_B_0X0   (0x0u<<9)
#define CEC_IER_TXENDIE_B_0X1   (0x1u<<9)
#define CEC_IER_TXBRIE_B_0X0    (0x0u<<8)
#define CEC_IER_TXBRIE_B_0X1    (0x1u<<8)
#define CEC_IER_ARBLSTIE_B_0X0  (0x0u<<7)
#define CEC_IER_ARBLSTIE_B_0X1  (0x1u<<7)
#define CEC_IER_RXACKIE_B_0X0   (0x0u<<6)
#define CEC_IER_RXACKIE_B_0X1   (0x1u<<6)
#define CEC_IER_LBPEIE_B_0X0    (0x0u<<5)
#define CEC_IER_LBPEIE_B_0X1    (0x1u<<5)
#define CEC_IER_SBPEIE_B_0X0    (0x0u<<4)
#define CEC_IER_SBPEIE_B_0X1    (0x1u<<4)
#define CEC_IER_BREIE_B_0X0     (0x0u<<3)
#define CEC_IER_BREIE_B_0X1     (0x1u<<3)
#define CEC_IER_RXOVRIE_B_0X0   (0x0u<<2)
#define CEC_IER_RXOVRIE_B_0X1   (0x1u<<2)
#define CEC_IER_RXENDIE_B_0X0   (0x0u<<1)
#define CEC_IER_RXENDIE_B_0X1   (0x1u<<1)
#define CEC_IER_RXBRIE_B_0X0    (0x0u<<0)
#define CEC_IER_RXBRIE_B_0X1    (0x1u<<0)
