/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_spdifrx equates.
 */

#pragma once

#include    <stdint.h>

// SPDIFRX address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    IMR;
    volatile    uint32_t    SR;
    volatile    uint32_t    IFCR;
        union {
    volatile    uint32_t    DR_00;
    volatile    uint32_t    DR_01;
    volatile    uint32_t    DR_10;
        };
    volatile    uint32_t    CSR;
    volatile    uint32_t    DIR;
    volatile    uint32_t    RESERVED0[246];
    volatile    uint32_t    VERR;
    volatile    uint32_t    IDR;
    volatile    uint32_t    SIDR;
} SPDIFRX_TypeDef;

#ifdef __cplusplus
#define SPDIFRX reinterpret_cast<SPDIFRX_TypeDef *>(0x40004000U)

#else
#define SPDIFRX ((SPDIFRX_TypeDef *)0x40004000U)
#endif

// CR Configuration

#define SPDIFRX_CR_CKSBKPEN     (0x1U<<21U)
#define SPDIFRX_CR_CKSEN        (0x1U<<20U)
#define SPDIFRX_CR_INSEL        (0x7U<<16U)
#define SPDIFRX_CR_INSEL_0      (0x1U<<16U)
#define SPDIFRX_CR_WFA          (0x1U<<14U)
#define SPDIFRX_CR_NBTR         (0x3U<<12U)
#define SPDIFRX_CR_NBTR_0       (0x1U<<12U)
#define SPDIFRX_CR_CHSEL        (0x1U<<11U)
#define SPDIFRX_CR_CBDMAEN      (0x1U<<10U)
#define SPDIFRX_CR_PTMSK        (0x1U<<9U)
#define SPDIFRX_CR_CUMSK        (0x1U<<8U)
#define SPDIFRX_CR_VMSK         (0x1U<<7U)
#define SPDIFRX_CR_PMSK         (0x1U<<6U)
#define SPDIFRX_CR_DRFMT        (0x3U<<4U)
#define SPDIFRX_CR_DRFMT_0      (0x1U<<4U)
#define SPDIFRX_CR_RXSTEO       (0x1U<<3U)
#define SPDIFRX_CR_RXDMAEN      (0x1U<<2U)
#define SPDIFRX_CR_SPDIFRXEN    (0x3U<<0U)
#define SPDIFRX_CR_SPDIFRXEN_0  (0x1U<<0U)

// IMR Configuration

#define SPDIFRX_IMR_IFEIE       (0x1U<<6U)
#define SPDIFRX_IMR_SYNCDIE     (0x1U<<5U)
#define SPDIFRX_IMR_SBLKIE      (0x1U<<4U)
#define SPDIFRX_IMR_OVRIE       (0x1U<<3U)
#define SPDIFRX_IMR_PERRIE      (0x1U<<2U)
#define SPDIFRX_IMR_CSRNEIE     (0x1U<<1U)
#define SPDIFRX_IMR_RXNEIE      (0x1U<<0U)

// SR Configuration

#define SPDIFRX_SR_WIDTH5       (0x7FFFU<<16U)
#define SPDIFRX_SR_WIDTH5_0     (0x1U<<16U)
#define SPDIFRX_SR_TERR         (0x1U<<8U)
#define SPDIFRX_SR_SERR         (0x1U<<7U)
#define SPDIFRX_SR_FERR         (0x1U<<6U)
#define SPDIFRX_SR_SYNCD        (0x1U<<5U)
#define SPDIFRX_SR_SBD          (0x1U<<4U)
#define SPDIFRX_SR_OVR          (0x1U<<3U)
#define SPDIFRX_SR_PERR         (0x1U<<2U)
#define SPDIFRX_SR_CSRNE        (0x1U<<1U)
#define SPDIFRX_SR_RXNE         (0x1U<<0U)

// IFCR Configuration

#define SPDIFRX_IFCR_SYNCDCF    (0x1U<<5U)
#define SPDIFRX_IFCR_SBDCF      (0x1U<<4U)
#define SPDIFRX_IFCR_OVRCF      (0x1U<<3U)
#define SPDIFRX_IFCR_PERRCF     (0x1U<<2U)

// DR_00 Configuration

#define SPDIFRX_DR_00_PT        (0x3U<<28U)
#define SPDIFRX_DR_00_PT_0      (0x1U<<28U)
#define SPDIFRX_DR_00_C         (0x1U<<27U)
#define SPDIFRX_DR_00_U         (0x1U<<26U)
#define SPDIFRX_DR_00_V         (0x1U<<25U)
#define SPDIFRX_DR_00_PE        (0x1U<<24U)
#define SPDIFRX_DR_00_DR        (0xFFFFFFU<<0U)
#define SPDIFRX_DR_00_DR_0      (0x1U<<0U)

// DR_01 Configuration

#define SPDIFRX_DR_01_DR        (0xFFFFFFU<<8U)
#define SPDIFRX_DR_01_DR_0      (0x1U<<8U)
#define SPDIFRX_DR_01_PT        (0x3U<<4U)
#define SPDIFRX_DR_01_PT_0      (0x1U<<4U)
#define SPDIFRX_DR_01_C         (0x1U<<3U)
#define SPDIFRX_DR_01_U         (0x1U<<2U)
#define SPDIFRX_DR_01_V         (0x1U<<1U)
#define SPDIFRX_DR_01_PE        (0x1U<<0U)

// DR_10 Configuration

#define SPDIFRX_DR_10_DRNL2     (0xFFFFU<<16U)
#define SPDIFRX_DR_10_DRNL2_0   (0x1U<<16U)
#define SPDIFRX_DR_10_DRNL1     (0xFFFFU<<0U)
#define SPDIFRX_DR_10_DRNL1_0   (0x1U<<0U)

// CSR Configuration

#define SPDIFRX_CSR_SOB         (0x1U<<24U)
#define SPDIFRX_CSR_CS          (0xFFU<<16U)
#define SPDIFRX_CSR_CS_0        (0x1U<<16U)
#define SPDIFRX_CSR_USR         (0xFFFFU<<0U)
#define SPDIFRX_CSR_USR_0       (0x1U<<0U)

// DIR Configuration

#define SPDIFRX_DIR_TLO         (0x1FFFU<<16U)
#define SPDIFRX_DIR_TLO_0       (0x1U<<16U)
#define SPDIFRX_DIR_THI         (0x1FFFU<<0U)
#define SPDIFRX_DIR_THI_0       (0x1U<<0U)

// VERR Configuration

#define SPDIFRX_VERR_MAJREV     (0xFU<<4U)
#define SPDIFRX_VERR_MAJREV_0   (0x1U<<4U)
#define SPDIFRX_VERR_MINREV     (0xFU<<0U)
#define SPDIFRX_VERR_MINREV_0   (0x1U<<0U)

// IDR Configuration

#define SPDIFRX_IDR_ID          (0xFFFFFFFFU<<0U)
#define SPDIFRX_IDR_ID_0        (0x1U<<0U)

// SIDR Configuration

#define SPDIFRX_SIDR_SID        (0xFFFFFFFFU<<0U)
#define SPDIFRX_SIDR_SID_0      (0x1U<<0U)
