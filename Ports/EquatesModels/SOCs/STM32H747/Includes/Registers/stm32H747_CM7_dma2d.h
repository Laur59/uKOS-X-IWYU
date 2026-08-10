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

#define DMA2D_CR_MODE           (0x3U<<16U)
#define DMA2D_CR_MODE_0         (0x1U<<16U)
#define DMA2D_CR_CEIE           (0x1U<<13U)
#define DMA2D_CR_CTCIE          (0x1U<<12U)
#define DMA2D_CR_CAEIE          (0x1U<<11U)
#define DMA2D_CR_TWIE           (0x1U<<10U)
#define DMA2D_CR_TCIE           (0x1U<<9U)
#define DMA2D_CR_TEIE           (0x1U<<8U)
#define DMA2D_CR_ABORT          (0x1U<<2U)
#define DMA2D_CR_SUSP           (0x1U<<1U)
#define DMA2D_CR_START          (0x1U<<0U)

// ISR Configuration

#define DMA2D_ISR_CEIF          (0x1U<<5U)
#define DMA2D_ISR_CTCIF         (0x1U<<4U)
#define DMA2D_ISR_CAEIF         (0x1U<<3U)
#define DMA2D_ISR_TWIF          (0x1U<<2U)
#define DMA2D_ISR_TCIF          (0x1U<<1U)
#define DMA2D_ISR_TEIF          (0x1U<<0U)

// IFCR Configuration

#define DMA2D_IFCR_CCEIF        (0x1U<<5U)
#define DMA2D_IFCR_CCTCIF       (0x1U<<4U)
#define DMA2D_IFCR_CAECIF       (0x1U<<3U)
#define DMA2D_IFCR_CTWIF        (0x1U<<2U)
#define DMA2D_IFCR_CTCIF        (0x1U<<1U)
#define DMA2D_IFCR_CTEIF        (0x1U<<0U)

// FGMAR Configuration

#define DMA2D_FGMAR_MA          (0xFFFFFFFFU<<0U)
#define DMA2D_FGMAR_MA_0        (0x1U<<0U)

// FGOR Configuration

#define DMA2D_FGOR_LO           (0x3FFFU<<0U)
#define DMA2D_FGOR_LO_0         (0x1U<<0U)

// BGMAR Configuration

#define DMA2D_BGMAR_MA          (0xFFFFFFFFU<<0U)
#define DMA2D_BGMAR_MA_0        (0x1U<<0U)

// BGOR Configuration

#define DMA2D_BGOR_LO           (0x3FFFU<<0U)
#define DMA2D_BGOR_LO_0         (0x1U<<0U)

// FGPFCCR Configuration

#define DMA2D_FGPFCCR_ALPHA     (0xFFU<<24U)
#define DMA2D_FGPFCCR_ALPHA_0   (0x1U<<24U)
#define DMA2D_FGPFCCR_RBS       (0x1U<<21U)
#define DMA2D_FGPFCCR_AI        (0x1U<<20U)
#define DMA2D_FGPFCCR_CSS       (0x3U<<18U)
#define DMA2D_FGPFCCR_CSS_0     (0x1U<<18U)
#define DMA2D_FGPFCCR_AM        (0x3U<<16U)
#define DMA2D_FGPFCCR_AM_0      (0x1U<<16U)
#define DMA2D_FGPFCCR_CS        (0xFFU<<8U)
#define DMA2D_FGPFCCR_CS_0      (0x1U<<8U)
#define DMA2D_FGPFCCR_START     (0x1U<<5U)
#define DMA2D_FGPFCCR_CCM       (0x1U<<4U)
#define DMA2D_FGPFCCR_CM        (0xFU<<0U)
#define DMA2D_FGPFCCR_CM_0      (0x1U<<0U)

// FGCOLR Configuration

#define DMA2D_FGCOLR_RED        (0xFFU<<16U)
#define DMA2D_FGCOLR_RED_0      (0x1U<<16U)
#define DMA2D_FGCOLR_GREEN      (0xFFU<<8U)
#define DMA2D_FGCOLR_GREEN_0    (0x1U<<8U)
#define DMA2D_FGCOLR_BLUE       (0xFFU<<0U)
#define DMA2D_FGCOLR_BLUE_0     (0x1U<<0U)

// BGPFCCR Configuration

#define DMA2D_BGPFCCR_ALPHA     (0xFFU<<24U)
#define DMA2D_BGPFCCR_ALPHA_0   (0x1U<<24U)
#define DMA2D_BGPFCCR_RBS       (0x1U<<21U)
#define DMA2D_BGPFCCR_AI        (0x1U<<20U)
#define DMA2D_BGPFCCR_AM        (0x3U<<16U)
#define DMA2D_BGPFCCR_AM_0      (0x1U<<16U)
#define DMA2D_BGPFCCR_CS        (0xFFU<<8U)
#define DMA2D_BGPFCCR_CS_0      (0x1U<<8U)
#define DMA2D_BGPFCCR_START     (0x1U<<5U)
#define DMA2D_BGPFCCR_CCM       (0x1U<<4U)
#define DMA2D_BGPFCCR_CM        (0xFU<<0U)
#define DMA2D_BGPFCCR_CM_0      (0x1U<<0U)

// BGCOLR Configuration

#define DMA2D_BGCOLR_RED        (0xFFU<<16U)
#define DMA2D_BGCOLR_RED_0      (0x1U<<16U)
#define DMA2D_BGCOLR_GREEN      (0xFFU<<8U)
#define DMA2D_BGCOLR_GREEN_0    (0x1U<<8U)
#define DMA2D_BGCOLR_BLUE       (0xFFU<<0U)
#define DMA2D_BGCOLR_BLUE_0     (0x1U<<0U)

// FGCMAR Configuration

#define DMA2D_FGCMAR_MA         (0xFFFFFFFFU<<0U)
#define DMA2D_FGCMAR_MA_0       (0x1U<<0U)

// BGCMAR Configuration

#define DMA2D_BGCMAR_MA         (0xFFFFFFFFU<<0U)
#define DMA2D_BGCMAR_MA_0       (0x1U<<0U)

// OPFCCR Configuration

#define DMA2D_OPFCCR_RBS        (0x1U<<21U)
#define DMA2D_OPFCCR_AI         (0x1U<<20U)
#define DMA2D_OPFCCR_CM         (0x7U<<0U)
#define DMA2D_OPFCCR_CM_0       (0x1U<<0U)

// OCOLR Configuration

#define DMA2D_OCOLR_ALPHA       (0xFFU<<24U)
#define DMA2D_OCOLR_ALPHA_0     (0x1U<<24U)
#define DMA2D_OCOLR_RED         (0xFFU<<16U)
#define DMA2D_OCOLR_RED_0       (0x1U<<16U)
#define DMA2D_OCOLR_GREEN       (0xFFU<<8U)
#define DMA2D_OCOLR_GREEN_0     (0x1U<<8U)
#define DMA2D_OCOLR_BLUE        (0xFFU<<0U)
#define DMA2D_OCOLR_BLUE_0      (0x1U<<0U)

// OMAR Configuration

#define DMA2D_OMAR_MA           (0xFFFFFFFFU<<0U)
#define DMA2D_OMAR_MA_0         (0x1U<<0U)

// OOR Configuration

#define DMA2D_OOR_LO            (0x3FFFU<<0U)
#define DMA2D_OOR_LO_0          (0x1U<<0U)

// NLR Configuration

#define DMA2D_NLR_PL            (0x3FFFU<<16U)
#define DMA2D_NLR_PL_0          (0x1U<<16U)
#define DMA2D_NLR_NL            (0xFFFFU<<0U)
#define DMA2D_NLR_NL_0          (0x1U<<0U)

// LWR Configuration

#define DMA2D_LWR_LW            (0xFFFFU<<0U)
#define DMA2D_LWR_LW_0          (0x1U<<0U)

// AMTCR Configuration

#define DMA2D_AMTCR_DT          (0xFFU<<8U)
#define DMA2D_AMTCR_DT_0        (0x1U<<8U)
#define DMA2D_AMTCR_EN          (0x1U<<0U)
