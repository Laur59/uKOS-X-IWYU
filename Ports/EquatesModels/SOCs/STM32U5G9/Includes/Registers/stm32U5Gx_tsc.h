/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_tsc equates.
 */

#pragma once

#include    <stdint.h>

// TSC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    IER;
    volatile    uint32_t    ICR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    IOHCR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    IOASCR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    IOSCR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    IOCCR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    IOGCSR;
    volatile    uint32_t    IOG1CR;
    volatile    uint32_t    IOG2CR;
    volatile    uint32_t    IOG3CR;
    volatile    uint32_t    IOG4CR;
    volatile    uint32_t    IOG5CR;
    volatile    uint32_t    IOG6CR;
    volatile    uint32_t    IOG7CR;
    volatile    uint32_t    IOG8CR;
} TSC_TypeDef;

#ifdef __cplusplus
#define TSC_NS  reinterpret_cast<TSC_TypeDef *>(0x40024000U)
#define TSC_S   reinterpret_cast<TSC_TypeDef *>(0x50024000U)

#else
#define TSC_NS  ((TSC_TypeDef *)0x40024000U)
#define TSC_S   ((TSC_TypeDef *)0x50024000U)
#endif

// CR Configuration

#define TSC_CR_TSCE         (0x1U<<0)
#define TSC_CR_START        (0x1U<<1)
#define TSC_CR_AM           (0x1U<<2)
#define TSC_CR_SYNCPOL      (0x1U<<3)
#define TSC_CR_IODEF        (0x1U<<4)
#define TSC_CR_MCV          (0x7U<<5)
#define TSC_CR_MCV_0        (0x1U<<5)
#define TSC_CR_PGPSC        (0x7U<<12)
#define TSC_CR_PGPSC_0      (0x1U<<12)
#define TSC_CR_SSPSC        (0x1U<<15)
#define TSC_CR_SSE          (0x1U<<16)
#define TSC_CR_SSD          (0x7FU<<17)
#define TSC_CR_SSD_0        (0x1U<<17)
#define TSC_CR_CTPL         (0xFU<<24)
#define TSC_CR_CTPL_0       (0x1U<<24)
#define TSC_CR_CTPH         (0xFU<<28)
#define TSC_CR_CTPH_0       (0x1U<<28)

// IER Configuration

#define TSC_IER_EOAIE       (0x1U<<0)
#define TSC_IER_MCEIE       (0x1U<<1)

// ICR Configuration

#define TSC_ICR_EOAIC       (0x1U<<0)
#define TSC_ICR_MCEIC       (0x1U<<1)

// ISR Configuration

#define TSC_ISR_EOAF        (0x1U<<0)
#define TSC_ISR_MCEF        (0x1U<<1)

// IOHCR Configuration

#define TSC_IOHCR_G1_IO1    (0x1U<<0)
#define TSC_IOHCR_G1_IO2    (0x1U<<1)
#define TSC_IOHCR_G1_IO3    (0x1U<<2)
#define TSC_IOHCR_G1_IO4    (0x1U<<3)
#define TSC_IOHCR_G2_IO1    (0x1U<<4)
#define TSC_IOHCR_G2_IO2    (0x1U<<5)
#define TSC_IOHCR_G2_IO3    (0x1U<<6)
#define TSC_IOHCR_G2_IO4    (0x1U<<7)
#define TSC_IOHCR_G3_IO1    (0x1U<<8)
#define TSC_IOHCR_G3_IO2    (0x1U<<9)
#define TSC_IOHCR_G3_IO3    (0x1U<<10)
#define TSC_IOHCR_G3_IO4    (0x1U<<11)
#define TSC_IOHCR_G4_IO1    (0x1U<<12)
#define TSC_IOHCR_G4_IO2    (0x1U<<13)
#define TSC_IOHCR_G4_IO3    (0x1U<<14)
#define TSC_IOHCR_G4_IO4    (0x1U<<15)
#define TSC_IOHCR_G5_IO1    (0x1U<<16)
#define TSC_IOHCR_G5_IO2    (0x1U<<17)
#define TSC_IOHCR_G5_IO3    (0x1U<<18)
#define TSC_IOHCR_G5_IO4    (0x1U<<19)
#define TSC_IOHCR_G6_IO1    (0x1U<<20)
#define TSC_IOHCR_G6_IO2    (0x1U<<21)
#define TSC_IOHCR_G6_IO3    (0x1U<<22)
#define TSC_IOHCR_G6_IO4    (0x1U<<23)
#define TSC_IOHCR_G7_IO1    (0x1U<<24)
#define TSC_IOHCR_G7_IO2    (0x1U<<25)
#define TSC_IOHCR_G7_IO3    (0x1U<<26)
#define TSC_IOHCR_G7_IO4    (0x1U<<27)
#define TSC_IOHCR_G8_IO1    (0x1U<<28)
#define TSC_IOHCR_G8_IO2    (0x1U<<29)
#define TSC_IOHCR_G8_IO3    (0x1U<<30)
#define TSC_IOHCR_G8_IO4    (0x1U<<31)

// IOASCR Configuration

#define TSC_IOASCR_G1_IO1   (0x1U<<0)
#define TSC_IOASCR_G1_IO2   (0x1U<<1)
#define TSC_IOASCR_G1_IO3   (0x1U<<2)
#define TSC_IOASCR_G1_IO4   (0x1U<<3)
#define TSC_IOASCR_G2_IO1   (0x1U<<4)
#define TSC_IOASCR_G2_IO2   (0x1U<<5)
#define TSC_IOASCR_G2_IO3   (0x1U<<6)
#define TSC_IOASCR_G2_IO4   (0x1U<<7)
#define TSC_IOASCR_G3_IO1   (0x1U<<8)
#define TSC_IOASCR_G3_IO2   (0x1U<<9)
#define TSC_IOASCR_G3_IO3   (0x1U<<10)
#define TSC_IOASCR_G3_IO4   (0x1U<<11)
#define TSC_IOASCR_G4_IO1   (0x1U<<12)
#define TSC_IOASCR_G4_IO2   (0x1U<<13)
#define TSC_IOASCR_G4_IO3   (0x1U<<14)
#define TSC_IOASCR_G4_IO4   (0x1U<<15)
#define TSC_IOASCR_G5_IO1   (0x1U<<16)
#define TSC_IOASCR_G5_IO2   (0x1U<<17)
#define TSC_IOASCR_G5_IO3   (0x1U<<18)
#define TSC_IOASCR_G5_IO4   (0x1U<<19)
#define TSC_IOASCR_G6_IO1   (0x1U<<20)
#define TSC_IOASCR_G6_IO2   (0x1U<<21)
#define TSC_IOASCR_G6_IO3   (0x1U<<22)
#define TSC_IOASCR_G6_IO4   (0x1U<<23)
#define TSC_IOASCR_G7_IO1   (0x1U<<24)
#define TSC_IOASCR_G7_IO2   (0x1U<<25)
#define TSC_IOASCR_G7_IO3   (0x1U<<26)
#define TSC_IOASCR_G7_IO4   (0x1U<<27)
#define TSC_IOASCR_G8_IO1   (0x1U<<28)
#define TSC_IOASCR_G8_IO2   (0x1U<<29)
#define TSC_IOASCR_G8_IO3   (0x1U<<30)
#define TSC_IOASCR_G8_IO4   (0x1U<<31)

// IOSCR Configuration

#define TSC_IOSCR_G1_IO1    (0x1U<<0)
#define TSC_IOSCR_G1_IO2    (0x1U<<1)
#define TSC_IOSCR_G1_IO3    (0x1U<<2)
#define TSC_IOSCR_G1_IO4    (0x1U<<3)
#define TSC_IOSCR_G2_IO1    (0x1U<<4)
#define TSC_IOSCR_G2_IO2    (0x1U<<5)
#define TSC_IOSCR_G2_IO3    (0x1U<<6)
#define TSC_IOSCR_G2_IO4    (0x1U<<7)
#define TSC_IOSCR_G3_IO1    (0x1U<<8)
#define TSC_IOSCR_G3_IO2    (0x1U<<9)
#define TSC_IOSCR_G3_IO3    (0x1U<<10)
#define TSC_IOSCR_G3_IO4    (0x1U<<11)
#define TSC_IOSCR_G4_IO1    (0x1U<<12)
#define TSC_IOSCR_G4_IO2    (0x1U<<13)
#define TSC_IOSCR_G4_IO3    (0x1U<<14)
#define TSC_IOSCR_G4_IO4    (0x1U<<15)
#define TSC_IOSCR_G5_IO1    (0x1U<<16)
#define TSC_IOSCR_G5_IO2    (0x1U<<17)
#define TSC_IOSCR_G5_IO3    (0x1U<<18)
#define TSC_IOSCR_G5_IO4    (0x1U<<19)
#define TSC_IOSCR_G6_IO1    (0x1U<<20)
#define TSC_IOSCR_G6_IO2    (0x1U<<21)
#define TSC_IOSCR_G6_IO3    (0x1U<<22)
#define TSC_IOSCR_G6_IO4    (0x1U<<23)
#define TSC_IOSCR_G7_IO1    (0x1U<<24)
#define TSC_IOSCR_G7_IO2    (0x1U<<25)
#define TSC_IOSCR_G7_IO3    (0x1U<<26)
#define TSC_IOSCR_G7_IO4    (0x1U<<27)
#define TSC_IOSCR_G8_IO1    (0x1U<<28)
#define TSC_IOSCR_G8_IO2    (0x1U<<29)
#define TSC_IOSCR_G8_IO3    (0x1U<<30)
#define TSC_IOSCR_G8_IO4    (0x1U<<31)

// IOCCR Configuration

#define TSC_IOCCR_G1_IO1    (0x1U<<0)
#define TSC_IOCCR_G1_IO2    (0x1U<<1)
#define TSC_IOCCR_G1_IO3    (0x1U<<2)
#define TSC_IOCCR_G1_IO4    (0x1U<<3)
#define TSC_IOCCR_G2_IO1    (0x1U<<4)
#define TSC_IOCCR_G2_IO2    (0x1U<<5)
#define TSC_IOCCR_G2_IO3    (0x1U<<6)
#define TSC_IOCCR_G2_IO4    (0x1U<<7)
#define TSC_IOCCR_G3_IO1    (0x1U<<8)
#define TSC_IOCCR_G3_IO2    (0x1U<<9)
#define TSC_IOCCR_G3_IO3    (0x1U<<10)
#define TSC_IOCCR_G3_IO4    (0x1U<<11)
#define TSC_IOCCR_G4_IO1    (0x1U<<12)
#define TSC_IOCCR_G4_IO2    (0x1U<<13)
#define TSC_IOCCR_G4_IO3    (0x1U<<14)
#define TSC_IOCCR_G4_IO4    (0x1U<<15)
#define TSC_IOCCR_G5_IO1    (0x1U<<16)
#define TSC_IOCCR_G5_IO2    (0x1U<<17)
#define TSC_IOCCR_G5_IO3    (0x1U<<18)
#define TSC_IOCCR_G5_IO4    (0x1U<<19)
#define TSC_IOCCR_G6_IO1    (0x1U<<20)
#define TSC_IOCCR_G6_IO2    (0x1U<<21)
#define TSC_IOCCR_G6_IO3    (0x1U<<22)
#define TSC_IOCCR_G6_IO4    (0x1U<<23)
#define TSC_IOCCR_G7_IO1    (0x1U<<24)
#define TSC_IOCCR_G7_IO2    (0x1U<<25)
#define TSC_IOCCR_G7_IO3    (0x1U<<26)
#define TSC_IOCCR_G7_IO4    (0x1U<<27)
#define TSC_IOCCR_G8_IO1    (0x1U<<28)
#define TSC_IOCCR_G8_IO2    (0x1U<<29)
#define TSC_IOCCR_G8_IO3    (0x1U<<30)
#define TSC_IOCCR_G8_IO4    (0x1U<<31)

// IOGCSR Configuration

#define TSC_IOGCSR_G1E      (0x1U<<0)
#define TSC_IOGCSR_G2E      (0x1U<<1)
#define TSC_IOGCSR_G3E      (0x1U<<2)
#define TSC_IOGCSR_G4E      (0x1U<<3)
#define TSC_IOGCSR_G5E      (0x1U<<4)
#define TSC_IOGCSR_G6E      (0x1U<<5)
#define TSC_IOGCSR_G7E      (0x1U<<6)
#define TSC_IOGCSR_G8E      (0x1U<<7)
#define TSC_IOGCSR_G1S      (0x1U<<16)
#define TSC_IOGCSR_G2S      (0x1U<<17)
#define TSC_IOGCSR_G3S      (0x1U<<18)
#define TSC_IOGCSR_G4S      (0x1U<<19)
#define TSC_IOGCSR_G5S      (0x1U<<20)
#define TSC_IOGCSR_G6S      (0x1U<<21)
#define TSC_IOGCSR_G7S      (0x1U<<22)
#define TSC_IOGCSR_G8S      (0x1U<<23)

// IOG1CR Configuration

#define TSC_IOG1CR_CNT      (0x3FFFU<<0)
#define TSC_IOG1CR_CNT_0    (0x1U<<0)

// IOG2CR Configuration

#define TSC_IOG2CR_CNT      (0x3FFFU<<0)
#define TSC_IOG2CR_CNT_0    (0x1U<<0)

// IOG3CR Configuration

#define TSC_IOG3CR_CNT      (0x3FFFU<<0)
#define TSC_IOG3CR_CNT_0    (0x1U<<0)

// IOG4CR Configuration

#define TSC_IOG4CR_CNT      (0x3FFFU<<0)
#define TSC_IOG4CR_CNT_0    (0x1U<<0)

// IOG5CR Configuration

#define TSC_IOG5CR_CNT      (0x3FFFU<<0)
#define TSC_IOG5CR_CNT_0    (0x1U<<0)

// IOG6CR Configuration

#define TSC_IOG6CR_CNT      (0x3FFFU<<0)
#define TSC_IOG6CR_CNT_0    (0x1U<<0)

// IOG7CR Configuration

#define TSC_IOG7CR_CNT      (0x3FFFU<<0)
#define TSC_IOG7CR_CNT_0    (0x1U<<0)

// IOG8CR Configuration

#define TSC_IOG8CR_CNT      (0x3FFFU<<0)
#define TSC_IOG8CR_CNT_0    (0x1U<<0)
