/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_dma2d equates.
 */

#pragma once

#include    <stdint.h>

// DMA2D address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    IFCR;
    volatile    uint32_t    FGMAR;
    volatile    uint32_t    FGOR;
    volatile    uint32_t    BGMAR;
    volatile    uint32_t    BGOR;
    volatile    uint32_t    FGPFCCR;
    volatile    uint32_t    FGCOLR;
    volatile    uint32_t    BGPFCCR;
    volatile    uint32_t    BGCOLR;
    volatile    uint32_t    FGCMAR;
    volatile    uint32_t    BGCMAR;
    volatile    uint32_t    OPFCCR;
    volatile    uint32_t    OCOLR;
    volatile    uint32_t    OMAR;
    volatile    uint32_t    OOR;
    volatile    uint32_t    NLR;
    volatile    uint32_t    LWR;
    volatile    uint32_t    AMTCR;
} DMA2D_TypeDef;

#ifdef __cplusplus
#define DMA2D   reinterpret_cast<DMA2D_TypeDef *>(0x52001000U)

#else
#define DMA2D   ((DMA2D_TypeDef *)0x52001000U)
#endif

// CR Configuration

#define DMA2D_CR_MODE           (0x3U<<16)
#define DMA2D_CR_MODE_0         (0x1U<<16)
#define DMA2D_CR_CEIE           (0x1U<<13)
#define DMA2D_CR_CTCIE          (0x1U<<12)
#define DMA2D_CR_CAEIE          (0x1U<<11)
#define DMA2D_CR_TWIE           (0x1U<<10)
#define DMA2D_CR_TCIE           (0x1U<<9)
#define DMA2D_CR_TEIE           (0x1U<<8)
#define DMA2D_CR_ABORT          (0x1U<<2)
#define DMA2D_CR_SUSP           (0x1U<<1)
#define DMA2D_CR_START          (0x1U<<0)

// ISR Configuration

#define DMA2D_ISR_CEIF          (0x1U<<5)
#define DMA2D_ISR_CTCIF         (0x1U<<4)
#define DMA2D_ISR_CAEIF         (0x1U<<3)
#define DMA2D_ISR_TWIF          (0x1U<<2)
#define DMA2D_ISR_TCIF          (0x1U<<1)
#define DMA2D_ISR_TEIF          (0x1U<<0)

// IFCR Configuration

#define DMA2D_IFCR_CCEIF        (0x1U<<5)
#define DMA2D_IFCR_CCTCIF       (0x1U<<4)
#define DMA2D_IFCR_CAECIF       (0x1U<<3)
#define DMA2D_IFCR_CTWIF        (0x1U<<2)
#define DMA2D_IFCR_CTCIF        (0x1U<<1)
#define DMA2D_IFCR_CTEIF        (0x1U<<0)

// FGMAR Configuration

#define DMA2D_FGMAR_MA          (0xFFFFFFFFU<<0)
#define DMA2D_FGMAR_MA_0        (0x1U<<0)

// FGOR Configuration

#define DMA2D_FGOR_LO           (0x3FFFU<<0)
#define DMA2D_FGOR_LO_0         (0x1U<<0)

// BGMAR Configuration

#define DMA2D_BGMAR_MA          (0xFFFFFFFFU<<0)
#define DMA2D_BGMAR_MA_0        (0x1U<<0)

// BGOR Configuration

#define DMA2D_BGOR_LO           (0x3FFFU<<0)
#define DMA2D_BGOR_LO_0         (0x1U<<0)

// FGPFCCR Configuration

#define DMA2D_FGPFCCR_ALPHA     (0xFFU<<24)
#define DMA2D_FGPFCCR_ALPHA_0   (0x1U<<24)
#define DMA2D_FGPFCCR_RBS       (0x1U<<21)
#define DMA2D_FGPFCCR_AI        (0x1U<<20)
#define DMA2D_FGPFCCR_CSS       (0x3U<<18)
#define DMA2D_FGPFCCR_CSS_0     (0x1U<<18)
#define DMA2D_FGPFCCR_AM        (0x3U<<16)
#define DMA2D_FGPFCCR_AM_0      (0x1U<<16)
#define DMA2D_FGPFCCR_CS        (0xFFU<<8)
#define DMA2D_FGPFCCR_CS_0      (0x1U<<8)
#define DMA2D_FGPFCCR_START     (0x1U<<5)
#define DMA2D_FGPFCCR_CCM       (0x1U<<4)
#define DMA2D_FGPFCCR_CM        (0xFU<<0)
#define DMA2D_FGPFCCR_CM_0      (0x1U<<0)

// FGCOLR Configuration

#define DMA2D_FGCOLR_RED        (0xFFU<<16)
#define DMA2D_FGCOLR_RED_0      (0x1U<<16)
#define DMA2D_FGCOLR_GREEN      (0xFFU<<8)
#define DMA2D_FGCOLR_GREEN_0    (0x1U<<8)
#define DMA2D_FGCOLR_BLUE       (0xFFU<<0)
#define DMA2D_FGCOLR_BLUE_0     (0x1U<<0)

// BGPFCCR Configuration

#define DMA2D_BGPFCCR_ALPHA     (0xFFU<<24)
#define DMA2D_BGPFCCR_ALPHA_0   (0x1U<<24)
#define DMA2D_BGPFCCR_RBS       (0x1U<<21)
#define DMA2D_BGPFCCR_AI        (0x1U<<20)
#define DMA2D_BGPFCCR_AM        (0x3U<<16)
#define DMA2D_BGPFCCR_AM_0      (0x1U<<16)
#define DMA2D_BGPFCCR_CS        (0xFFU<<8)
#define DMA2D_BGPFCCR_CS_0      (0x1U<<8)
#define DMA2D_BGPFCCR_START     (0x1U<<5)
#define DMA2D_BGPFCCR_CCM       (0x1U<<4)
#define DMA2D_BGPFCCR_CM        (0xFU<<0)
#define DMA2D_BGPFCCR_CM_0      (0x1U<<0)

// BGCOLR Configuration

#define DMA2D_BGCOLR_RED        (0xFFU<<16)
#define DMA2D_BGCOLR_RED_0      (0x1U<<16)
#define DMA2D_BGCOLR_GREEN      (0xFFU<<8)
#define DMA2D_BGCOLR_GREEN_0    (0x1U<<8)
#define DMA2D_BGCOLR_BLUE       (0xFFU<<0)
#define DMA2D_BGCOLR_BLUE_0     (0x1U<<0)

// FGCMAR Configuration

#define DMA2D_FGCMAR_MA         (0xFFFFFFFFU<<0)
#define DMA2D_FGCMAR_MA_0       (0x1U<<0)

// BGCMAR Configuration

#define DMA2D_BGCMAR_MA         (0xFFFFFFFFU<<0)
#define DMA2D_BGCMAR_MA_0       (0x1U<<0)

// OPFCCR Configuration

#define DMA2D_OPFCCR_RBS        (0x1U<<21)
#define DMA2D_OPFCCR_AI         (0x1U<<20)
#define DMA2D_OPFCCR_CM         (0x7U<<0)
#define DMA2D_OPFCCR_CM_0       (0x1U<<0)

// OCOLR Configuration

#define DMA2D_OCOLR_ALPHA       (0xFFU<<24)
#define DMA2D_OCOLR_ALPHA_0     (0x1U<<24)
#define DMA2D_OCOLR_RED         (0xFFU<<16)
#define DMA2D_OCOLR_RED_0       (0x1U<<16)
#define DMA2D_OCOLR_GREEN       (0xFFU<<8)
#define DMA2D_OCOLR_GREEN_0     (0x1U<<8)
#define DMA2D_OCOLR_BLUE        (0xFFU<<0)
#define DMA2D_OCOLR_BLUE_0      (0x1U<<0)

// OMAR Configuration

#define DMA2D_OMAR_MA           (0xFFFFFFFFU<<0)
#define DMA2D_OMAR_MA_0         (0x1U<<0)

// OOR Configuration

#define DMA2D_OOR_LO            (0x3FFFU<<0)
#define DMA2D_OOR_LO_0          (0x1U<<0)

// NLR Configuration

#define DMA2D_NLR_PL            (0x3FFFU<<16)
#define DMA2D_NLR_PL_0          (0x1U<<16)
#define DMA2D_NLR_NL            (0xFFFFU<<0)
#define DMA2D_NLR_NL_0          (0x1U<<0)

// LWR Configuration

#define DMA2D_LWR_LW            (0xFFFFU<<0)
#define DMA2D_LWR_LW_0          (0x1U<<0)

// AMTCR Configuration

#define DMA2D_AMTCR_DT          (0xFFU<<8)
#define DMA2D_AMTCR_DT_0        (0x1U<<8)
#define DMA2D_AMTCR_EN          (0x1U<<0)
