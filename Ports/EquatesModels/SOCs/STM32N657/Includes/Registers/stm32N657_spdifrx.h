/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_spdifrx equates.
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
    volatile    uint32_t    FMT0_DR;
    volatile    uint32_t    FMT1_DR;
    volatile    uint32_t    FMT2_DR;
        };
    volatile    uint32_t    CSR;
    volatile    uint32_t    DIR;
} SPDIFRX_TypeDef;

#ifdef __cplusplus
#define SPDIFRX_NS  reinterpret_cast<SPDIFRX_TypeDef *>(0x40004000U)
#define SPDIFRX_S   reinterpret_cast<SPDIFRX_TypeDef *>(0x50004000U)

#else
#define SPDIFRX_NS  ((SPDIFRX_TypeDef *)0x40004000U)
#define SPDIFRX_S   ((SPDIFRX_TypeDef *)0x50004000U)
#endif

// CR Configuration

#define SPDIFRX_CR_CKSBKPEN             (0x1U<<21U)
#define SPDIFRX_CR_CKSEN                (0x1U<<20U)
#define SPDIFRX_CR_INSEL                (0x7U<<16U)
#define SPDIFRX_CR_INSEL_0              (0x1U<<16U)
#define SPDIFRX_CR_WFA                  (0x1U<<14U)
#define SPDIFRX_CR_NBTR                 (0x3U<<12U)
#define SPDIFRX_CR_NBTR_0               (0x1U<<12U)
#define SPDIFRX_CR_CHSEL                (0x1U<<11U)
#define SPDIFRX_CR_CBDMAEN              (0x1U<<10U)
#define SPDIFRX_CR_PTMSK                (0x1U<<9U)
#define SPDIFRX_CR_CUMSK                (0x1U<<8U)
#define SPDIFRX_CR_VMSK                 (0x1U<<7U)
#define SPDIFRX_CR_PMSK                 (0x1U<<6U)
#define SPDIFRX_CR_DRFMT                (0x3U<<4U)
#define SPDIFRX_CR_DRFMT_0              (0x1U<<4U)
#define SPDIFRX_CR_RXSTEO               (0x1U<<3U)
#define SPDIFRX_CR_RXDMAEN              (0x1U<<2U)
#define SPDIFRX_CR_SPDIFRXEN            (0x3U<<0U)
#define SPDIFRX_CR_SPDIFRXEN_0          (0x1U<<0U)

#define SPDIFRX_CR_CKSBKPEN_B_0X1       (0x1U<<21U)
#define SPDIFRX_CR_CKSBKPEN_B_0X0       (0x0U<<21U)
#define SPDIFRX_CR_CKSEN_B_0X1          (0x1U<<20U)
#define SPDIFRX_CR_CKSEN_B_0X0          (0x0U<<20U)
#define SPDIFRX_CR_INSEL_B_0X0          (0x0U<<16U)
#define SPDIFRX_CR_INSEL_B_0X1          (0x1U<<16U)
#define SPDIFRX_CR_INSEL_B_0X2          (0x2U<<16U)
#define SPDIFRX_CR_INSEL_B_0X3          (0x3U<<16U)
#define SPDIFRX_CR_WFA_B_0X1            (0x1U<<14U)
#define SPDIFRX_CR_WFA_B_0X0            (0x0U<<14U)
#define SPDIFRX_CR_NBTR_B_0X0           (0x0U<<12U)
#define SPDIFRX_CR_NBTR_B_0X1           (0x1U<<12U)
#define SPDIFRX_CR_NBTR_B_0X2           (0x2U<<12U)
#define SPDIFRX_CR_NBTR_B_0X3           (0x3U<<12U)
#define SPDIFRX_CR_CHSEL_B_0X1          (0x1U<<11U)
#define SPDIFRX_CR_CHSEL_B_0X0          (0x0U<<11U)
#define SPDIFRX_CR_CBDMAEN_B_0X1        (0x1U<<10U)
#define SPDIFRX_CR_CBDMAEN_B_0X0        (0x0U<<10U)
#define SPDIFRX_CR_PTMSK_B_0X1          (0x1U<<9U)
#define SPDIFRX_CR_PTMSK_B_0X0          (0x0U<<9U)
#define SPDIFRX_CR_CUMSK_B_0X1          (0x1U<<8U)
#define SPDIFRX_CR_CUMSK_B_0X0          (0x0U<<8U)
#define SPDIFRX_CR_VMSK_B_0X1           (0x1U<<7U)
#define SPDIFRX_CR_VMSK_B_0X0           (0x0U<<7U)
#define SPDIFRX_CR_PMSK_B_0X1           (0x1U<<6U)
#define SPDIFRX_CR_PMSK_B_0X0           (0x0U<<6U)
#define SPDIFRX_CR_DRFMT_B_0X2          (0x2U<<4U)
#define SPDIFRX_CR_DRFMT_B_0X1          (0x1U<<4U)
#define SPDIFRX_CR_DRFMT_B_0X0          (0x0U<<4U)
#define SPDIFRX_CR_RXSTEO_B_0X1         (0x1U<<3U)
#define SPDIFRX_CR_RXSTEO_B_0X0         (0x0U<<3U)
#define SPDIFRX_CR_RXDMAEN_B_0X1        (0x1U<<2U)
#define SPDIFRX_CR_RXDMAEN_B_0X0        (0x0U<<2U)
#define SPDIFRX_CR_SPDIFRXEN_B_0X0      (0x0U<<0U)
#define SPDIFRX_CR_SPDIFRXEN_B_0X1      (0x1U<<0U)
#define SPDIFRX_CR_SPDIFRXEN_B_0X3      (0x3U<<0U)

// IMR Configuration

#define SPDIFRX_IMR_IFEIE               (0x1U<<6U)
#define SPDIFRX_IMR_SYNCDIE             (0x1U<<5U)
#define SPDIFRX_IMR_SBLKIE              (0x1U<<4U)
#define SPDIFRX_IMR_OVRIE               (0x1U<<3U)
#define SPDIFRX_IMR_PERRIE              (0x1U<<2U)
#define SPDIFRX_IMR_CSRNEIE             (0x1U<<1U)
#define SPDIFRX_IMR_RXNEIE              (0x1U<<0U)

#define SPDIFRX_IMR_IFEIE_B_0X0         (0x0U<<6U)
#define SPDIFRX_IMR_IFEIE_B_0X1         (0x1U<<6U)
#define SPDIFRX_IMR_SYNCDIE_B_0X0       (0x0U<<5U)
#define SPDIFRX_IMR_SYNCDIE_B_0X1       (0x1U<<5U)
#define SPDIFRX_IMR_SBLKIE_B_0X0        (0x0U<<4U)
#define SPDIFRX_IMR_SBLKIE_B_0X1        (0x1U<<4U)
#define SPDIFRX_IMR_OVRIE_B_0X0         (0x0U<<3U)
#define SPDIFRX_IMR_OVRIE_B_0X1         (0x1U<<3U)
#define SPDIFRX_IMR_PERRIE_B_0X0        (0x0U<<2U)
#define SPDIFRX_IMR_PERRIE_B_0X1        (0x1U<<2U)
#define SPDIFRX_IMR_CSRNEIE_B_0X0       (0x0U<<1U)
#define SPDIFRX_IMR_CSRNEIE_B_0X1       (0x1U<<1U)
#define SPDIFRX_IMR_RXNEIE_B_0X0        (0x0U<<0U)
#define SPDIFRX_IMR_RXNEIE_B_0X1        (0x1U<<0U)

// SR Configuration

#define SPDIFRX_SR_WIDTH5               (0x7FFFU<<16U)
#define SPDIFRX_SR_WIDTH5_0             (0x1U<<16U)
#define SPDIFRX_SR_TERR                 (0x1U<<8U)
#define SPDIFRX_SR_SERR                 (0x1U<<7U)
#define SPDIFRX_SR_FERR                 (0x1U<<6U)
#define SPDIFRX_SR_SYNCD                (0x1U<<5U)
#define SPDIFRX_SR_SBD                  (0x1U<<4U)
#define SPDIFRX_SR_OVR                  (0x1U<<3U)
#define SPDIFRX_SR_PERR                 (0x1U<<2U)
#define SPDIFRX_SR_CSRNE                (0x1U<<1U)
#define SPDIFRX_SR_RXNE                 (0x1U<<0U)

#define SPDIFRX_SR_TERR_B_0X0           (0x0U<<8U)
#define SPDIFRX_SR_TERR_B_0X1           (0x1U<<8U)
#define SPDIFRX_SR_SERR_B_0X0           (0x0U<<7U)
#define SPDIFRX_SR_SERR_B_0X1           (0x1U<<7U)
#define SPDIFRX_SR_FERR_B_0X0           (0x0U<<6U)
#define SPDIFRX_SR_FERR_B_0X1           (0x1U<<6U)
#define SPDIFRX_SR_SYNCD_B_0X0          (0x0U<<5U)
#define SPDIFRX_SR_SYNCD_B_0X1          (0x1U<<5U)
#define SPDIFRX_SR_SBD_B_0X0            (0x0U<<4U)
#define SPDIFRX_SR_SBD_B_0X1            (0x1U<<4U)
#define SPDIFRX_SR_OVR_B_0X0            (0x0U<<3U)
#define SPDIFRX_SR_OVR_B_0X1            (0x1U<<3U)
#define SPDIFRX_SR_PERR_B_0X0           (0x0U<<2U)
#define SPDIFRX_SR_PERR_B_0X1           (0x1U<<2U)
#define SPDIFRX_SR_CSRNE_B_0X0          (0x0U<<1U)
#define SPDIFRX_SR_CSRNE_B_0X1          (0x1U<<1U)
#define SPDIFRX_SR_RXNE_B_0X0           (0x0U<<0U)
#define SPDIFRX_SR_RXNE_B_0X1           (0x1U<<0U)

// IFCR Configuration

#define SPDIFRX_IFCR_SYNCDCF            (0x1U<<5U)
#define SPDIFRX_IFCR_SBDCF              (0x1U<<4U)
#define SPDIFRX_IFCR_OVRCF              (0x1U<<3U)
#define SPDIFRX_IFCR_PERRCF             (0x1U<<2U)

// FMT0_DR Configuration

#define SPDIFRX_FMT0_DR_PT              (0x3U<<28U)
#define SPDIFRX_FMT0_DR_PT_0            (0x1U<<28U)
#define SPDIFRX_FMT0_DR_C               (0x1U<<27U)
#define SPDIFRX_FMT0_DR_U               (0x1U<<26U)
#define SPDIFRX_FMT0_DR_V               (0x1U<<25U)
#define SPDIFRX_FMT0_DR_PE              (0x1U<<24U)
#define SPDIFRX_FMT0_DR_DR              (0xFFFFFFU<<0U)
#define SPDIFRX_FMT0_DR_DR_0            (0x1U<<0U)

#define SPDIFRX_FMT0_DR_PT_B_0X0        (0x0U<<28U)
#define SPDIFRX_FMT0_DR_PT_B_0X1        (0x1U<<28U)
#define SPDIFRX_FMT0_DR_PT_B_0X2        (0x2U<<28U)
#define SPDIFRX_FMT0_DR_PT_B_0X3        (0x3U<<28U)

// FMT1_DR Configuration

#define SPDIFRX_FMT1_DR_DR              (0xFFFFFFU<<8U)
#define SPDIFRX_FMT1_DR_DR_0            (0x1U<<8U)
#define SPDIFRX_FMT1_DR_PT              (0x3U<<4U)
#define SPDIFRX_FMT1_DR_PT_0            (0x1U<<4U)
#define SPDIFRX_FMT1_DR_C               (0x1U<<3U)
#define SPDIFRX_FMT1_DR_U               (0x1U<<2U)
#define SPDIFRX_FMT1_DR_V               (0x1U<<1U)
#define SPDIFRX_FMT1_DR_PE              (0x1U<<0U)

#define SPDIFRX_FMT1_DR_PT_B_0X0        (0x0U<<4U)
#define SPDIFRX_FMT1_DR_PT_B_0X1        (0x1U<<4U)
#define SPDIFRX_FMT1_DR_PT_B_0X2        (0x2U<<4U)
#define SPDIFRX_FMT1_DR_PT_B_0X3        (0x3U<<4U)

// FMT2_DR Configuration

#define SPDIFRX_FMT2_DR_DRNL2           (0xFFFFU<<16U)
#define SPDIFRX_FMT2_DR_DRNL2_0         (0x1U<<16U)
#define SPDIFRX_FMT2_DR_DRNL1           (0xFFFFU<<0U)
#define SPDIFRX_FMT2_DR_DRNL1_0         (0x1U<<0U)

// CSR Configuration

#define SPDIFRX_CSR_SOB                 (0x1U<<24U)
#define SPDIFRX_CSR_CS                  (0xFFU<<16U)
#define SPDIFRX_CSR_CS_0                (0x1U<<16U)
#define SPDIFRX_CSR_USR                 (0xFFFFU<<0U)
#define SPDIFRX_CSR_USR_0               (0x1U<<0U)

#define SPDIFRX_CSR_SOB_B_0X0           (0x0U<<24U)
#define SPDIFRX_CSR_SOB_B_0X1           (0x1U<<24U)

// DIR Configuration

#define SPDIFRX_DIR_TLO                 (0x1FFFU<<16U)
#define SPDIFRX_DIR_TLO_0               (0x1U<<16U)
#define SPDIFRX_DIR_THI                 (0x1FFFU<<0U)
#define SPDIFRX_DIR_THI_0               (0x1U<<0U)
