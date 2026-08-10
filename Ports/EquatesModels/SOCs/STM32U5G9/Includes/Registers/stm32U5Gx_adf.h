/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_adf equates.
 */

#pragma once

#include    <stdint.h>

// ADF address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    GCR;
    volatile    uint32_t    CKGCR;
    volatile    uint32_t    RESERVED0[30];
    volatile    uint32_t    SITF0CR;
    volatile    uint32_t    BSMX0CR;
    volatile    uint32_t    DFLT0CR;
    volatile    uint32_t    DFLT0CICR;
    volatile    uint32_t    DFLT0RSFR;
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    DLY0CR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    DFLT0IER;
    volatile    uint32_t    DFLT0ISR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    SADCR;
    volatile    uint32_t    SADCFGR;
    volatile    uint32_t    SADSDLVR;
    volatile    uint32_t    SADANLVR;
    volatile    uint32_t    RESERVED4[10];
    volatile    uint32_t    DFLT0DR;
} ADF_TypeDef;

#ifdef __cplusplus
#define ADF1_NS reinterpret_cast<ADF_TypeDef *>(0x46024000U)
#define ADF1_S  reinterpret_cast<ADF_TypeDef *>(0x56024000U)

#else
#define ADF1_NS ((ADF_TypeDef *)0x46024000U)
#define ADF1_S  ((ADF_TypeDef *)0x56024000U)
#endif

// GCR Configuration

#define ADF_GCR_TRGO            (0x1U<<0U)

// CKGCR Configuration

#define ADF_CKGCR_CKGDEN        (0x1U<<0U)
#define ADF_CKGCR_CCK0EN        (0x1U<<1U)
#define ADF_CKGCR_CCK1EN        (0x1U<<2U)
#define ADF_CKGCR_CKGMOD        (0x1U<<4U)
#define ADF_CKGCR_CCK0DIR       (0x1U<<5U)
#define ADF_CKGCR_CCK1DIR       (0x1U<<6U)
#define ADF_CKGCR_TRGSENS       (0x1U<<8U)
#define ADF_CKGCR_TRGSRC        (0xFU<<12U)
#define ADF_CKGCR_TRGSRC_0      (0x1U<<12U)
#define ADF_CKGCR_CCKDIV        (0xFU<<16U)
#define ADF_CKGCR_CCKDIV_0      (0x1U<<16U)
#define ADF_CKGCR_PROCDIV       (0x7FU<<24U)
#define ADF_CKGCR_PROCDIV_0     (0x1U<<24U)
#define ADF_CKGCR_CKGACTIVE     (0x1U<<31U)

// SITF0CR Configuration

#define ADF_SITF0CR_SITFEN      (0x1U<<0U)
#define ADF_SITF0CR_SCKSRC      (0x3U<<1U)
#define ADF_SITF0CR_SCKSRC_0    (0x1U<<1U)
#define ADF_SITF0CR_SITFMOD     (0x3U<<4U)
#define ADF_SITF0CR_SITFMOD_0   (0x1U<<4U)
#define ADF_SITF0CR_STH         (0x1FU<<8U)
#define ADF_SITF0CR_STH_0       (0x1U<<8U)
#define ADF_SITF0CR_SITFACTIVE  (0x1U<<31U)

// BSMX0CR Configuration

#define ADF_BSMX0CR_BSSEL       (0x1FU<<0U)
#define ADF_BSMX0CR_BSSEL_0     (0x1U<<0U)
#define ADF_BSMX0CR_BSMXACTIVE  (0x1U<<31U)

// DFLT0CR Configuration

#define ADF_DFLT0CR_DFLTEN      (0x1U<<0U)
#define ADF_DFLT0CR_DMAEN       (0x1U<<1U)
#define ADF_DFLT0CR_FTH         (0x1U<<2U)
#define ADF_DFLT0CR_ACQMOD      (0x7U<<4U)
#define ADF_DFLT0CR_ACQMOD_0    (0x1U<<4U)
#define ADF_DFLT0CR_TRGSRC      (0xFU<<12U)
#define ADF_DFLT0CR_TRGSRC_0    (0x1U<<12U)
#define ADF_DFLT0CR_NBDIS       (0xFFU<<20U)
#define ADF_DFLT0CR_NBDIS_0     (0x1U<<20U)
#define ADF_DFLT0CR_DFLTRUN     (0x1U<<30U)
#define ADF_DFLT0CR_DFLTACTIVE  (0x1U<<31U)

// DFLT0CICR Configuration

#define ADF_DFLT0CICR_DATSRC    (0x3U<<0U)
#define ADF_DFLT0CICR_DATSRC_0  (0x1U<<0U)
#define ADF_DFLT0CICR_CICMOD    (0x7U<<4U)
#define ADF_DFLT0CICR_CICMOD_0  (0x1U<<4U)
#define ADF_DFLT0CICR_MCICD     (0x1FFU<<8U)
#define ADF_DFLT0CICR_MCICD_0   (0x1U<<8U)
#define ADF_DFLT0CICR_SCALE     (0x3FU<<20U)
#define ADF_DFLT0CICR_SCALE_0   (0x1U<<20U)

// DFLT0RSFR Configuration

#define ADF_DFLT0RSFR_RSFLTBYP  (0x1U<<0U)
#define ADF_DFLT0RSFR_RSFLTD    (0x1U<<4U)
#define ADF_DFLT0RSFR_HPFBYP    (0x1U<<7U)
#define ADF_DFLT0RSFR_HPFC      (0x3U<<8U)
#define ADF_DFLT0RSFR_HPFC_0    (0x1U<<8U)

// DLY0CR Configuration

#define ADF_DLY0CR_SKPDLY       (0x7FU<<0U)
#define ADF_DLY0CR_SKPDLY_0     (0x1U<<0U)
#define ADF_DLY0CR_SKPBF        (0x1U<<31U)

// DFLT0IER Configuration

#define ADF_DFLT0IER_FTHIE      (0x1U<<0U)
#define ADF_DFLT0IER_DOVRIE     (0x1U<<1U)
#define ADF_DFLT0IER_SATIE      (0x1U<<9U)
#define ADF_DFLT0IER_CKABIE     (0x1U<<10U)
#define ADF_DFLT0IER_RFOVRIE    (0x1U<<11U)
#define ADF_DFLT0IER_SDDETIE    (0x1U<<12U)
#define ADF_DFLT0IER_SDLVLIE    (0x1U<<13U)

// DFLT0ISR Configuration

#define ADF_DFLT0ISR_FTHF       (0x1U<<0U)
#define ADF_DFLT0ISR_DOVRF      (0x1U<<1U)
#define ADF_DFLT0ISR_RXNEF      (0x1U<<3U)
#define ADF_DFLT0ISR_SATF       (0x1U<<9U)
#define ADF_DFLT0ISR_CKABF      (0x1U<<10U)
#define ADF_DFLT0ISR_RFOVRF     (0x1U<<11U)
#define ADF_DFLT0ISR_SDDETF     (0x1U<<12U)
#define ADF_DFLT0ISR_SDLVLF     (0x1U<<13U)

// SADCR Configuration

#define ADF_SADCR_SADEN         (0x1U<<0U)
#define ADF_SADCR_DATCAP        (0x3U<<1U)
#define ADF_SADCR_DATCAP_0      (0x1U<<1U)
#define ADF_SADCR_DETCFG        (0x1U<<3U)
#define ADF_SADCR_SADST         (0x3U<<4U)
#define ADF_SADCR_SADST_0       (0x1U<<4U)
#define ADF_SADCR_HYSTEN        (0x1U<<7U)
#define ADF_SADCR_FRSIZE        (0x7U<<8U)
#define ADF_SADCR_FRSIZE_0      (0x1U<<8U)
#define ADF_SADCR_SADMOD        (0x3U<<12U)
#define ADF_SADCR_SADMOD_0      (0x1U<<12U)
#define ADF_SADCR_SADACTIVE     (0x1U<<31U)

// SADCFGR Configuration

#define ADF_SADCFGR_SNTHR       (0xFU<<0U)
#define ADF_SADCFGR_SNTHR_0     (0x1U<<0U)
#define ADF_SADCFGR_ANSLP       (0x7U<<4U)
#define ADF_SADCFGR_ANSLP_0     (0x1U<<4U)
#define ADF_SADCFGR_LFRNB       (0x7U<<8U)
#define ADF_SADCFGR_LFRNB_0     (0x1U<<8U)
#define ADF_SADCFGR_HGOVR       (0x7U<<12U)
#define ADF_SADCFGR_HGOVR_0     (0x1U<<12U)
#define ADF_SADCFGR_ANMIN       (0x1FFFU<<16U)
#define ADF_SADCFGR_ANMIN_0     (0x1U<<16U)

// SADSDLVR Configuration

#define ADF_SADSDLVR_SDLVL      (0x7FFFU<<0U)
#define ADF_SADSDLVR_SDLVL_0    (0x1U<<0U)

// SADANLVR Configuration

#define ADF_SADANLVR_ANLVL      (0x7FFFU<<0U)
#define ADF_SADANLVR_ANLVL_0    (0x1U<<0U)

// DFLT0DR Configuration

#define ADF_DFLT0DR_DR          (0xFFFFFFU<<8U)
#define ADF_DFLT0DR_DR_0        (0x1U<<8U)
