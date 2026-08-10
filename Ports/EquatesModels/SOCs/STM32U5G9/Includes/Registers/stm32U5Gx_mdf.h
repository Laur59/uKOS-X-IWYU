/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_mdf equates.
 */

#pragma once

#include    <stdint.h>

// MDF address definitions
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
    volatile    uint32_t    DFLT0INTR;
    volatile    uint32_t    OLD0CR;
    volatile    uint32_t    OLD0THLR;
    volatile    uint32_t    OLD0THHR;
    volatile    uint32_t    DLY0CR;
    volatile    uint32_t    SCD0CR;
    volatile    uint32_t    DFLT0IER;
    volatile    uint32_t    DFLT0ISR;
    volatile    uint32_t    OEC0CR;
    volatile    uint32_t    RESERVED1[13];
    volatile    uint32_t    SNPS0DR;
    volatile    uint32_t    DFLT0DR;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    SITF1CR;
    volatile    uint32_t    BSMX1CR;
    volatile    uint32_t    DFLT1CR;
    volatile    uint32_t    DFLT1CICR;
    volatile    uint32_t    DFLT1RSFR;
    volatile    uint32_t    DFLT1INTR;
    volatile    uint32_t    OLD1CR;
    volatile    uint32_t    OLD1THLR;
    volatile    uint32_t    OLD1THHR;
    volatile    uint32_t    DLY1CR;
    volatile    uint32_t    SCD1CR;
    volatile    uint32_t    DFLT1IER;
    volatile    uint32_t    DFLT1ISR;
    volatile    uint32_t    OEC1CR;
    volatile    uint32_t    RESERVED3[13];
    volatile    uint32_t    SNPS1DR;
    volatile    uint32_t    DFLT1DR;
    volatile    uint32_t    RESERVED4[3];
    volatile    uint32_t    SITF2CR;
    volatile    uint32_t    BSMX2CR;
    volatile    uint32_t    DFLT2CR;
    volatile    uint32_t    DFLT2CICR;
    volatile    uint32_t    DFLT2RSFR;
    volatile    uint32_t    DFLT2INTR;
    volatile    uint32_t    OLD2CR;
    volatile    uint32_t    OLD2THLR;
    volatile    uint32_t    OLD2THHR;
    volatile    uint32_t    DLY2CR;
    volatile    uint32_t    SCD2CR;
    volatile    uint32_t    DFLT2IER;
    volatile    uint32_t    DFLT2ISR;
    volatile    uint32_t    OEC2CR;
    volatile    uint32_t    RESERVED5[13];
    volatile    uint32_t    SNPS2DR;
    volatile    uint32_t    DFLT2DR;
    volatile    uint32_t    RESERVED6[3];
    volatile    uint32_t    SITF3CR;
    volatile    uint32_t    BSMX3CR;
    volatile    uint32_t    DFLT3CR;
    volatile    uint32_t    DFLT3CICR;
    volatile    uint32_t    DFLT3RSFR;
    volatile    uint32_t    DFLT3INTR;
    volatile    uint32_t    OLD3CR;
    volatile    uint32_t    OLD3THLR;
    volatile    uint32_t    OLD3THHR;
    volatile    uint32_t    DLY3CR;
    volatile    uint32_t    SCD3CR;
    volatile    uint32_t    DFLT3IER;
    volatile    uint32_t    DFLT3ISR;
    volatile    uint32_t    OEC3CR;
    volatile    uint32_t    RESERVED7[13];
    volatile    uint32_t    SNPS3DR;
    volatile    uint32_t    DFLT3DR;
    volatile    uint32_t    RESERVED8[3];
    volatile    uint32_t    SITF4CR;
    volatile    uint32_t    BSMX4CR;
    volatile    uint32_t    DFLT4CR;
    volatile    uint32_t    DFLT4CICR;
    volatile    uint32_t    DFLT4RSFR;
    volatile    uint32_t    DFLT4INTR;
    volatile    uint32_t    OLD4CR;
    volatile    uint32_t    OLD4THLR;
    volatile    uint32_t    OLD4THHR;
    volatile    uint32_t    DLY4CR;
    volatile    uint32_t    SCD4CR;
    volatile    uint32_t    DFLT4IER;
    volatile    uint32_t    DFLT4ISR;
    volatile    uint32_t    OEC4CR;
    volatile    uint32_t    RESERVED9[13];
    volatile    uint32_t    SNPS4DR;
    volatile    uint32_t    DFLT4DR;
    volatile    uint32_t    RESERVED10[3];
    volatile    uint32_t    SITF5CR;
    volatile    uint32_t    BSMX5CR;
    volatile    uint32_t    DFLT5CR;
    volatile    uint32_t    DFLT5CICR;
    volatile    uint32_t    DFLT5RSFR;
    volatile    uint32_t    DFLT5INTR;
    volatile    uint32_t    OLD5CR;
    volatile    uint32_t    OLD5THLR;
    volatile    uint32_t    OLD5THHR;
    volatile    uint32_t    DLY5CR;
    volatile    uint32_t    SCD5CR;
    volatile    uint32_t    DFLT5IER;
    volatile    uint32_t    DFLT5ISR;
    volatile    uint32_t    OEC5CR;
    volatile    uint32_t    RESERVED11[13];
    volatile    uint32_t    SNPS5DR;
    volatile    uint32_t    DFLT5DR;
} MDF_TypeDef;

#ifdef __cplusplus
#define MDF1_NS reinterpret_cast<MDF_TypeDef *>(0x40025000U)
#define MDF1_S  reinterpret_cast<MDF_TypeDef *>(0x50025000U)

#else
#define MDF1_NS ((MDF_TypeDef *)0x40025000U)
#define MDF1_S  ((MDF_TypeDef *)0x50025000U)
#endif

// GCR Configuration

#define MDF_GCR_ILVNB           (0xFU<<4U)
#define MDF_GCR_ILVNB_0         (0x1U<<4U)
#define MDF_GCR_TRGO            (0x1U<<0U)

// CKGCR Configuration

#define MDF_CKGCR_CKGACTIVE     (0x1U<<31U)
#define MDF_CKGCR_PROCDIV       (0x7FU<<24U)
#define MDF_CKGCR_PROCDIV_0     (0x1U<<24U)
#define MDF_CKGCR_CCKDIV        (0xFU<<16U)
#define MDF_CKGCR_CCKDIV_0      (0x1U<<16U)
#define MDF_CKGCR_TRGSRC        (0xFU<<12U)
#define MDF_CKGCR_TRGSRC_0      (0x1U<<12U)
#define MDF_CKGCR_TRGSENS       (0x1U<<8U)
#define MDF_CKGCR_CCK1DIR       (0x1U<<6U)
#define MDF_CKGCR_CCK0DIR       (0x1U<<5U)
#define MDF_CKGCR_CKGMOD        (0x1U<<4U)
#define MDF_CKGCR_CCK1EN        (0x1U<<2U)
#define MDF_CKGCR_CCK0EN        (0x1U<<1U)
#define MDF_CKGCR_CKGDEN        (0x1U<<0U)

// SITF0CR Configuration

#define MDF_SITF0CR_SITFACTIVE  (0x1U<<31U)
#define MDF_SITF0CR_STH         (0x1FU<<8U)
#define MDF_SITF0CR_STH_0       (0x1U<<8U)
#define MDF_SITF0CR_SITFMOD     (0x3U<<4U)
#define MDF_SITF0CR_SITFMOD_0   (0x1U<<4U)
#define MDF_SITF0CR_SCKSRC      (0x3U<<1U)
#define MDF_SITF0CR_SCKSRC_0    (0x1U<<1U)
#define MDF_SITF0CR_SITFEN      (0x1U<<0U)

// BSMX0CR Configuration

#define MDF_BSMX0CR_BSMXACTIVE  (0x1U<<31U)
#define MDF_BSMX0CR_BSSEL       (0x1FU<<0U)
#define MDF_BSMX0CR_BSSEL_0     (0x1U<<0U)

// DFLT0CR Configuration

#define MDF_DFLT0CR_DFLTACTIVE  (0x1U<<31U)
#define MDF_DFLT0CR_DFLTRUN     (0x1U<<30U)
#define MDF_DFLT0CR_NBDIS       (0xFFU<<20U)
#define MDF_DFLT0CR_NBDIS_0     (0x1U<<20U)
#define MDF_DFLT0CR_SNPSFMT     (0x1U<<16U)
#define MDF_DFLT0CR_TRGSRC      (0xFU<<12U)
#define MDF_DFLT0CR_TRGSRC_0    (0x1U<<12U)
#define MDF_DFLT0CR_TRGSENS     (0x1U<<8U)
#define MDF_DFLT0CR_ACQMOD      (0x7U<<4U)
#define MDF_DFLT0CR_ACQMOD_0    (0x1U<<4U)
#define MDF_DFLT0CR_FTH         (0x1U<<2U)
#define MDF_DFLT0CR_DMAEN       (0x1U<<1U)
#define MDF_DFLT0CR_DFLTEN      (0x1U<<0U)

// DFLT0CICR Configuration

#define MDF_DFLT0CICR_SCALE     (0x3FU<<20U)
#define MDF_DFLT0CICR_SCALE_0   (0x1U<<20U)
#define MDF_DFLT0CICR_MCICD     (0x1FFU<<8U)
#define MDF_DFLT0CICR_MCICD_0   (0x1U<<8U)
#define MDF_DFLT0CICR_CICMOD    (0x7U<<4U)
#define MDF_DFLT0CICR_CICMOD_0  (0x1U<<4U)
#define MDF_DFLT0CICR_DATSRC    (0x3U<<0U)
#define MDF_DFLT0CICR_DATSRC_0  (0x1U<<0U)

// DFLT0RSFR Configuration

#define MDF_DFLT0RSFR_HPFC      (0x3U<<8U)
#define MDF_DFLT0RSFR_HPFC_0    (0x1U<<8U)
#define MDF_DFLT0RSFR_HPFBYP    (0x1U<<7U)
#define MDF_DFLT0RSFR_RSFLTD    (0x1U<<4U)
#define MDF_DFLT0RSFR_RSFLTBYP  (0x1U<<0U)

// DFLT0INTR Configuration

#define MDF_DFLT0INTR_INTVAL    (0x7FU<<4U)
#define MDF_DFLT0INTR_INTVAL_0  (0x1U<<4U)
#define MDF_DFLT0INTR_INTDIV    (0x3U<<0U)
#define MDF_DFLT0INTR_INTDIV_0  (0x1U<<0U)

// OLD0CR Configuration

#define MDF_OLD0CR_OLDACTIVE    (0x1U<<31U)
#define MDF_OLD0CR_ACICD        (0x1FU<<17U)
#define MDF_OLD0CR_ACICD_0      (0x1U<<17U)
#define MDF_OLD0CR_ACICN        (0x3U<<12U)
#define MDF_OLD0CR_ACICN_0      (0x1U<<12U)
#define MDF_OLD0CR_BKOLD        (0xFU<<4U)
#define MDF_OLD0CR_BKOLD_0      (0x1U<<4U)
#define MDF_OLD0CR_THINB        (0x1U<<1U)
#define MDF_OLD0CR_OLDEN        (0x1U<<0U)

// OLD0THLR Configuration

#define MDF_OLD0THLR_OLDTHL     (0x3FFFFFFU<<0U)
#define MDF_OLD0THLR_OLDTHL_0   (0x1U<<0U)

// OLD0THHR Configuration

#define MDF_OLD0THHR_OLDTHH     (0x3FFFFFFU<<0U)
#define MDF_OLD0THHR_OLDTHH_0   (0x1U<<0U)

// DLY0CR Configuration

#define MDF_DLY0CR_SKPBF        (0x1U<<31U)
#define MDF_DLY0CR_SKPDLY       (0x7FU<<0U)
#define MDF_DLY0CR_SKPDLY_0     (0x1U<<0U)

// SCD0CR Configuration

#define MDF_SCD0CR_SCDACTIVE    (0x1U<<31U)
#define MDF_SCD0CR_SCDT         (0xFFU<<12U)
#define MDF_SCD0CR_SCDT_0       (0x1U<<12U)
#define MDF_SCD0CR_BKSCD        (0xFU<<4U)
#define MDF_SCD0CR_BKSCD_0      (0x1U<<4U)
#define MDF_SCD0CR_SCDEN        (0x1U<<0U)

// DFLT0IER Configuration

#define MDF_DFLT0IER_RFOVRIE    (0x1U<<11U)
#define MDF_DFLT0IER_CKABIE     (0x1U<<10U)
#define MDF_DFLT0IER_SATIE      (0x1U<<9U)
#define MDF_DFLT0IER_SCDIE      (0x1U<<8U)
#define MDF_DFLT0IER_SSOVRIE    (0x1U<<7U)
#define MDF_DFLT0IER_OLDIE      (0x1U<<4U)
#define MDF_DFLT0IER_SSDRIE     (0x1U<<2U)
#define MDF_DFLT0IER_DOVRIE     (0x1U<<1U)
#define MDF_DFLT0IER_FTHIE      (0x1U<<0U)

// DFLT0ISR Configuration

#define MDF_DFLT0ISR_RFOVRF     (0x1U<<11U)
#define MDF_DFLT0ISR_CKABF      (0x1U<<10U)
#define MDF_DFLT0ISR_SATF       (0x1U<<9U)
#define MDF_DFLT0ISR_SCDF       (0x1U<<8U)
#define MDF_DFLT0ISR_SSOVRF     (0x1U<<7U)
#define MDF_DFLT0ISR_THHF       (0x1U<<6U)
#define MDF_DFLT0ISR_THLF       (0x1U<<5U)
#define MDF_DFLT0ISR_OLDF       (0x1U<<4U)
#define MDF_DFLT0ISR_RXNEF      (0x1U<<3U)
#define MDF_DFLT0ISR_SSDRF      (0x1U<<2U)
#define MDF_DFLT0ISR_DOVRF      (0x1U<<1U)
#define MDF_DFLT0ISR_FTHF       (0x1U<<0U)

// OEC0CR Configuration

#define MDF_OEC0CR_OFFSET       (0x3FFFFFFU<<0U)
#define MDF_OEC0CR_OFFSET_0     (0x1U<<0U)

// SNPS0DR Configuration

#define MDF_SNPS0DR_SDR         (0xFFFFU<<16U)
#define MDF_SNPS0DR_SDR_0       (0x1U<<16U)
#define MDF_SNPS0DR_EXTSDR      (0x7FU<<9U)
#define MDF_SNPS0DR_EXTSDR_0    (0x1U<<9U)
#define MDF_SNPS0DR_MCICDC      (0x1FFU<<0U)
#define MDF_SNPS0DR_MCICDC_0    (0x1U<<0U)

// DFLT0DR Configuration

#define MDF_DFLT0DR_DR          (0xFFFFFFU<<8U)
#define MDF_DFLT0DR_DR_0        (0x1U<<8U)

// SITF1CR Configuration

#define MDF_SITF1CR_SITFACTIVE  (0x1U<<31U)
#define MDF_SITF1CR_STH         (0x1FU<<8U)
#define MDF_SITF1CR_STH_0       (0x1U<<8U)
#define MDF_SITF1CR_SITFMOD     (0x3U<<4U)
#define MDF_SITF1CR_SITFMOD_0   (0x1U<<4U)
#define MDF_SITF1CR_SCKSRC      (0x3U<<1U)
#define MDF_SITF1CR_SCKSRC_0    (0x1U<<1U)
#define MDF_SITF1CR_SITFEN      (0x1U<<0U)

// BSMX1CR Configuration

#define MDF_BSMX1CR_BSMXACTIVE  (0x1U<<31U)
#define MDF_BSMX1CR_BSSEL       (0x1FU<<0U)
#define MDF_BSMX1CR_BSSEL_0     (0x1U<<0U)

// DFLT1CR Configuration

#define MDF_DFLT1CR_DFLTACTIVE  (0x1U<<31U)
#define MDF_DFLT1CR_DFLTRUN     (0x1U<<30U)
#define MDF_DFLT1CR_NBDIS       (0xFFU<<20U)
#define MDF_DFLT1CR_NBDIS_0     (0x1U<<20U)
#define MDF_DFLT1CR_SNPSFMT     (0x1U<<16U)
#define MDF_DFLT1CR_TRGSRC      (0xFU<<12U)
#define MDF_DFLT1CR_TRGSRC_0    (0x1U<<12U)
#define MDF_DFLT1CR_TRGSENS     (0x1U<<8U)
#define MDF_DFLT1CR_ACQMOD      (0x7U<<4U)
#define MDF_DFLT1CR_ACQMOD_0    (0x1U<<4U)
#define MDF_DFLT1CR_FTH         (0x1U<<2U)
#define MDF_DFLT1CR_DMAEN       (0x1U<<1U)
#define MDF_DFLT1CR_DFLTEN      (0x1U<<0U)

// DFLT1CICR Configuration

#define MDF_DFLT1CICR_SCALE     (0x3FU<<20U)
#define MDF_DFLT1CICR_SCALE_0   (0x1U<<20U)
#define MDF_DFLT1CICR_MCICD     (0x1FFU<<8U)
#define MDF_DFLT1CICR_MCICD_0   (0x1U<<8U)
#define MDF_DFLT1CICR_CICMOD    (0x7U<<4U)
#define MDF_DFLT1CICR_CICMOD_0  (0x1U<<4U)
#define MDF_DFLT1CICR_DATSRC    (0x3U<<0U)
#define MDF_DFLT1CICR_DATSRC_0  (0x1U<<0U)

// DFLT1RSFR Configuration

#define MDF_DFLT1RSFR_HPFC      (0x3U<<8U)
#define MDF_DFLT1RSFR_HPFC_0    (0x1U<<8U)
#define MDF_DFLT1RSFR_HPFBYP    (0x1U<<7U)
#define MDF_DFLT1RSFR_RSFLTD    (0x1U<<4U)
#define MDF_DFLT1RSFR_RSFLTBYP  (0x1U<<0U)

// DFLT1INTR Configuration

#define MDF_DFLT1INTR_INTVAL    (0x7FU<<4U)
#define MDF_DFLT1INTR_INTVAL_0  (0x1U<<4U)
#define MDF_DFLT1INTR_INTDIV    (0x3U<<0U)
#define MDF_DFLT1INTR_INTDIV_0  (0x1U<<0U)

// OLD1CR Configuration

#define MDF_OLD1CR_OLDACTIVE    (0x1U<<31U)
#define MDF_OLD1CR_ACICD        (0x1FU<<17U)
#define MDF_OLD1CR_ACICD_0      (0x1U<<17U)
#define MDF_OLD1CR_ACICN        (0x3U<<12U)
#define MDF_OLD1CR_ACICN_0      (0x1U<<12U)
#define MDF_OLD1CR_BKOLD        (0xFU<<4U)
#define MDF_OLD1CR_BKOLD_0      (0x1U<<4U)
#define MDF_OLD1CR_THINB        (0x1U<<1U)
#define MDF_OLD1CR_OLDEN        (0x1U<<0U)

// OLD1THLR Configuration

#define MDF_OLD1THLR_OLDTHL     (0x3FFFFFFU<<0U)
#define MDF_OLD1THLR_OLDTHL_0   (0x1U<<0U)

// OLD1THHR Configuration

#define MDF_OLD1THHR_OLDTHH     (0x3FFFFFFU<<0U)
#define MDF_OLD1THHR_OLDTHH_0   (0x1U<<0U)

// DLY1CR Configuration

#define MDF_DLY1CR_SKPBF        (0x1U<<31U)
#define MDF_DLY1CR_SKPDLY       (0x7FU<<0U)
#define MDF_DLY1CR_SKPDLY_0     (0x1U<<0U)

// SCD1CR Configuration

#define MDF_SCD1CR_SCDACTIVE    (0x1U<<31U)
#define MDF_SCD1CR_SCDT         (0xFFU<<12U)
#define MDF_SCD1CR_SCDT_0       (0x1U<<12U)
#define MDF_SCD1CR_BKSCD        (0xFU<<4U)
#define MDF_SCD1CR_BKSCD_0      (0x1U<<4U)
#define MDF_SCD1CR_SCDEN        (0x1U<<0U)

// DFLT1IER Configuration

#define MDF_DFLT1IER_RFOVRIE    (0x1U<<11U)
#define MDF_DFLT1IER_CKABIE     (0x1U<<10U)
#define MDF_DFLT1IER_SATIE      (0x1U<<9U)
#define MDF_DFLT1IER_SCDIE      (0x1U<<8U)
#define MDF_DFLT1IER_SSOVRIE    (0x1U<<7U)
#define MDF_DFLT1IER_OLDIE      (0x1U<<4U)
#define MDF_DFLT1IER_SSDRIE     (0x1U<<2U)
#define MDF_DFLT1IER_DOVRIE     (0x1U<<1U)
#define MDF_DFLT1IER_FTHIE      (0x1U<<0U)

// DFLT1ISR Configuration

#define MDF_DFLT1ISR_RFOVRF     (0x1U<<11U)
#define MDF_DFLT1ISR_CKABF      (0x1U<<10U)
#define MDF_DFLT1ISR_SATF       (0x1U<<9U)
#define MDF_DFLT1ISR_SCDF       (0x1U<<8U)
#define MDF_DFLT1ISR_SSOVRF     (0x1U<<7U)
#define MDF_DFLT1ISR_THHF       (0x1U<<6U)
#define MDF_DFLT1ISR_THLF       (0x1U<<5U)
#define MDF_DFLT1ISR_OLDF       (0x1U<<4U)
#define MDF_DFLT1ISR_RXNEF      (0x1U<<3U)
#define MDF_DFLT1ISR_SSDRF      (0x1U<<2U)
#define MDF_DFLT1ISR_DOVRF      (0x1U<<1U)
#define MDF_DFLT1ISR_FTHF       (0x1U<<0U)

// OEC1CR Configuration

#define MDF_OEC1CR_OFFSET       (0x3FFFFFFU<<0U)
#define MDF_OEC1CR_OFFSET_0     (0x1U<<0U)

// SNPS1DR Configuration

#define MDF_SNPS1DR_SDR         (0xFFFFU<<16U)
#define MDF_SNPS1DR_SDR_0       (0x1U<<16U)
#define MDF_SNPS1DR_EXTSDR      (0x7FU<<9U)
#define MDF_SNPS1DR_EXTSDR_0    (0x1U<<9U)
#define MDF_SNPS1DR_MCICDC      (0x1FFU<<0U)
#define MDF_SNPS1DR_MCICDC_0    (0x1U<<0U)

// DFLT1DR Configuration

#define MDF_DFLT1DR_DR          (0xFFFFFFU<<8U)
#define MDF_DFLT1DR_DR_0        (0x1U<<8U)

// SITF2CR Configuration

#define MDF_SITF2CR_SITFACTIVE  (0x1U<<31U)
#define MDF_SITF2CR_STH         (0x1FU<<8U)
#define MDF_SITF2CR_STH_0       (0x1U<<8U)
#define MDF_SITF2CR_SITFMOD     (0x3U<<4U)
#define MDF_SITF2CR_SITFMOD_0   (0x1U<<4U)
#define MDF_SITF2CR_SCKSRC      (0x3U<<1U)
#define MDF_SITF2CR_SCKSRC_0    (0x1U<<1U)
#define MDF_SITF2CR_SITFEN      (0x1U<<0U)

// BSMX2CR Configuration

#define MDF_BSMX2CR_BSMXACTIVE  (0x1U<<31U)
#define MDF_BSMX2CR_BSSEL       (0x1FU<<0U)
#define MDF_BSMX2CR_BSSEL_0     (0x1U<<0U)

// DFLT2CR Configuration

#define MDF_DFLT2CR_DFLTACTIVE  (0x1U<<31U)
#define MDF_DFLT2CR_DFLTRUN     (0x1U<<30U)
#define MDF_DFLT2CR_NBDIS       (0xFFU<<20U)
#define MDF_DFLT2CR_NBDIS_0     (0x1U<<20U)
#define MDF_DFLT2CR_SNPSFMT     (0x1U<<16U)
#define MDF_DFLT2CR_TRGSRC      (0xFU<<12U)
#define MDF_DFLT2CR_TRGSRC_0    (0x1U<<12U)
#define MDF_DFLT2CR_TRGSENS     (0x1U<<8U)
#define MDF_DFLT2CR_ACQMOD      (0x7U<<4U)
#define MDF_DFLT2CR_ACQMOD_0    (0x1U<<4U)
#define MDF_DFLT2CR_FTH         (0x1U<<2U)
#define MDF_DFLT2CR_DMAEN       (0x1U<<1U)
#define MDF_DFLT2CR_DFLTEN      (0x1U<<0U)

// DFLT2CICR Configuration

#define MDF_DFLT2CICR_SCALE     (0x3FU<<20U)
#define MDF_DFLT2CICR_SCALE_0   (0x1U<<20U)
#define MDF_DFLT2CICR_MCICD     (0x1FFU<<8U)
#define MDF_DFLT2CICR_MCICD_0   (0x1U<<8U)
#define MDF_DFLT2CICR_CICMOD    (0x7U<<4U)
#define MDF_DFLT2CICR_CICMOD_0  (0x1U<<4U)
#define MDF_DFLT2CICR_DATSRC    (0x3U<<0U)
#define MDF_DFLT2CICR_DATSRC_0  (0x1U<<0U)

// DFLT2RSFR Configuration

#define MDF_DFLT2RSFR_HPFC      (0x3U<<8U)
#define MDF_DFLT2RSFR_HPFC_0    (0x1U<<8U)
#define MDF_DFLT2RSFR_HPFBYP    (0x1U<<7U)
#define MDF_DFLT2RSFR_RSFLTD    (0x1U<<4U)
#define MDF_DFLT2RSFR_RSFLTBYP  (0x1U<<0U)

// DFLT2INTR Configuration

#define MDF_DFLT2INTR_INTVAL    (0x7FU<<4U)
#define MDF_DFLT2INTR_INTVAL_0  (0x1U<<4U)
#define MDF_DFLT2INTR_INTDIV    (0x3U<<0U)
#define MDF_DFLT2INTR_INTDIV_0  (0x1U<<0U)

// OLD2CR Configuration

#define MDF_OLD2CR_OLDACTIVE    (0x1U<<31U)
#define MDF_OLD2CR_ACICD        (0x1FU<<17U)
#define MDF_OLD2CR_ACICD_0      (0x1U<<17U)
#define MDF_OLD2CR_ACICN        (0x3U<<12U)
#define MDF_OLD2CR_ACICN_0      (0x1U<<12U)
#define MDF_OLD2CR_BKOLD        (0xFU<<4U)
#define MDF_OLD2CR_BKOLD_0      (0x1U<<4U)
#define MDF_OLD2CR_THINB        (0x1U<<1U)
#define MDF_OLD2CR_OLDEN        (0x1U<<0U)

// OLD2THLR Configuration

#define MDF_OLD2THLR_OLDTHL     (0x3FFFFFFU<<0U)
#define MDF_OLD2THLR_OLDTHL_0   (0x1U<<0U)

// OLD2THHR Configuration

#define MDF_OLD2THHR_OLDTHH     (0x3FFFFFFU<<0U)
#define MDF_OLD2THHR_OLDTHH_0   (0x1U<<0U)

// DLY2CR Configuration

#define MDF_DLY2CR_SKPBF        (0x1U<<31U)
#define MDF_DLY2CR_SKPDLY       (0x7FU<<0U)
#define MDF_DLY2CR_SKPDLY_0     (0x1U<<0U)

// SCD2CR Configuration

#define MDF_SCD2CR_SCDACTIVE    (0x1U<<31U)
#define MDF_SCD2CR_SCDT         (0xFFU<<12U)
#define MDF_SCD2CR_SCDT_0       (0x1U<<12U)
#define MDF_SCD2CR_BKSCD        (0xFU<<4U)
#define MDF_SCD2CR_BKSCD_0      (0x1U<<4U)
#define MDF_SCD2CR_SCDEN        (0x1U<<0U)

// DFLT2IER Configuration

#define MDF_DFLT2IER_RFOVRIE    (0x1U<<11U)
#define MDF_DFLT2IER_CKABIE     (0x1U<<10U)
#define MDF_DFLT2IER_SATIE      (0x1U<<9U)
#define MDF_DFLT2IER_SCDIE      (0x1U<<8U)
#define MDF_DFLT2IER_SSOVRIE    (0x1U<<7U)
#define MDF_DFLT2IER_OLDIE      (0x1U<<4U)
#define MDF_DFLT2IER_SSDRIE     (0x1U<<2U)
#define MDF_DFLT2IER_DOVRIE     (0x1U<<1U)
#define MDF_DFLT2IER_FTHIE      (0x1U<<0U)

// DFLT2ISR Configuration

#define MDF_DFLT2ISR_RFOVRF     (0x1U<<11U)
#define MDF_DFLT2ISR_CKABF      (0x1U<<10U)
#define MDF_DFLT2ISR_SATF       (0x1U<<9U)
#define MDF_DFLT2ISR_SCDF       (0x1U<<8U)
#define MDF_DFLT2ISR_SSOVRF     (0x1U<<7U)
#define MDF_DFLT2ISR_THHF       (0x1U<<6U)
#define MDF_DFLT2ISR_THLF       (0x1U<<5U)
#define MDF_DFLT2ISR_OLDF       (0x1U<<4U)
#define MDF_DFLT2ISR_RXNEF      (0x1U<<3U)
#define MDF_DFLT2ISR_SSDRF      (0x1U<<2U)
#define MDF_DFLT2ISR_DOVRF      (0x1U<<1U)
#define MDF_DFLT2ISR_FTHF       (0x1U<<0U)

// OEC2CR Configuration

#define MDF_OEC2CR_OFFSET       (0x3FFFFFFU<<0U)
#define MDF_OEC2CR_OFFSET_0     (0x1U<<0U)

// SNPS2DR Configuration

#define MDF_SNPS2DR_SDR         (0xFFFFU<<16U)
#define MDF_SNPS2DR_SDR_0       (0x1U<<16U)
#define MDF_SNPS2DR_EXTSDR      (0x7FU<<9U)
#define MDF_SNPS2DR_EXTSDR_0    (0x1U<<9U)
#define MDF_SNPS2DR_MCICDC      (0x1FFU<<0U)
#define MDF_SNPS2DR_MCICDC_0    (0x1U<<0U)

// DFLT2DR Configuration

#define MDF_DFLT2DR_DR          (0xFFFFFFU<<8U)
#define MDF_DFLT2DR_DR_0        (0x1U<<8U)

// SITF3CR Configuration

#define MDF_SITF3CR_SITFACTIVE  (0x1U<<31U)
#define MDF_SITF3CR_STH         (0x1FU<<8U)
#define MDF_SITF3CR_STH_0       (0x1U<<8U)
#define MDF_SITF3CR_SITFMOD     (0x3U<<4U)
#define MDF_SITF3CR_SITFMOD_0   (0x1U<<4U)
#define MDF_SITF3CR_SCKSRC      (0x3U<<1U)
#define MDF_SITF3CR_SCKSRC_0    (0x1U<<1U)
#define MDF_SITF3CR_SITFEN      (0x1U<<0U)

// BSMX3CR Configuration

#define MDF_BSMX3CR_BSMXACTIVE  (0x1U<<31U)
#define MDF_BSMX3CR_BSSEL       (0x1FU<<0U)
#define MDF_BSMX3CR_BSSEL_0     (0x1U<<0U)

// DFLT3CR Configuration

#define MDF_DFLT3CR_DFLTACTIVE  (0x1U<<31U)
#define MDF_DFLT3CR_DFLTRUN     (0x1U<<30U)
#define MDF_DFLT3CR_NBDIS       (0xFFU<<20U)
#define MDF_DFLT3CR_NBDIS_0     (0x1U<<20U)
#define MDF_DFLT3CR_SNPSFMT     (0x1U<<16U)
#define MDF_DFLT3CR_TRGSRC      (0xFU<<12U)
#define MDF_DFLT3CR_TRGSRC_0    (0x1U<<12U)
#define MDF_DFLT3CR_TRGSENS     (0x1U<<8U)
#define MDF_DFLT3CR_ACQMOD      (0x7U<<4U)
#define MDF_DFLT3CR_ACQMOD_0    (0x1U<<4U)
#define MDF_DFLT3CR_FTH         (0x1U<<2U)
#define MDF_DFLT3CR_DMAEN       (0x1U<<1U)
#define MDF_DFLT3CR_DFLTEN      (0x1U<<0U)

// DFLT3CICR Configuration

#define MDF_DFLT3CICR_SCALE     (0x3FU<<20U)
#define MDF_DFLT3CICR_SCALE_0   (0x1U<<20U)
#define MDF_DFLT3CICR_MCICD     (0x1FFU<<8U)
#define MDF_DFLT3CICR_MCICD_0   (0x1U<<8U)
#define MDF_DFLT3CICR_CICMOD    (0x7U<<4U)
#define MDF_DFLT3CICR_CICMOD_0  (0x1U<<4U)
#define MDF_DFLT3CICR_DATSRC    (0x3U<<0U)
#define MDF_DFLT3CICR_DATSRC_0  (0x1U<<0U)

// DFLT3RSFR Configuration

#define MDF_DFLT3RSFR_HPFC      (0x3U<<8U)
#define MDF_DFLT3RSFR_HPFC_0    (0x1U<<8U)
#define MDF_DFLT3RSFR_HPFBYP    (0x1U<<7U)
#define MDF_DFLT3RSFR_RSFLTD    (0x1U<<4U)
#define MDF_DFLT3RSFR_RSFLTBYP  (0x1U<<0U)

// DFLT3INTR Configuration

#define MDF_DFLT3INTR_INTVAL    (0x7FU<<4U)
#define MDF_DFLT3INTR_INTVAL_0  (0x1U<<4U)
#define MDF_DFLT3INTR_INTDIV    (0x3U<<0U)
#define MDF_DFLT3INTR_INTDIV_0  (0x1U<<0U)

// OLD3CR Configuration

#define MDF_OLD3CR_OLDACTIVE    (0x1U<<31U)
#define MDF_OLD3CR_ACICD        (0x1FU<<17U)
#define MDF_OLD3CR_ACICD_0      (0x1U<<17U)
#define MDF_OLD3CR_ACICN        (0x3U<<12U)
#define MDF_OLD3CR_ACICN_0      (0x1U<<12U)
#define MDF_OLD3CR_BKOLD        (0xFU<<4U)
#define MDF_OLD3CR_BKOLD_0      (0x1U<<4U)
#define MDF_OLD3CR_THINB        (0x1U<<1U)
#define MDF_OLD3CR_OLDEN        (0x1U<<0U)

// OLD3THLR Configuration

#define MDF_OLD3THLR_OLDTHL     (0x3FFFFFFU<<0U)
#define MDF_OLD3THLR_OLDTHL_0   (0x1U<<0U)

// OLD3THHR Configuration

#define MDF_OLD3THHR_OLDTHH     (0x3FFFFFFU<<0U)
#define MDF_OLD3THHR_OLDTHH_0   (0x1U<<0U)

// DLY3CR Configuration

#define MDF_DLY3CR_SKPBF        (0x1U<<31U)
#define MDF_DLY3CR_SKPDLY       (0x7FU<<0U)
#define MDF_DLY3CR_SKPDLY_0     (0x1U<<0U)

// SCD3CR Configuration

#define MDF_SCD3CR_SCDACTIVE    (0x1U<<31U)
#define MDF_SCD3CR_SCDT         (0xFFU<<12U)
#define MDF_SCD3CR_SCDT_0       (0x1U<<12U)
#define MDF_SCD3CR_BKSCD        (0xFU<<4U)
#define MDF_SCD3CR_BKSCD_0      (0x1U<<4U)
#define MDF_SCD3CR_SCDEN        (0x1U<<0U)

// DFLT3IER Configuration

#define MDF_DFLT3IER_RFOVRIE    (0x1U<<11U)
#define MDF_DFLT3IER_CKABIE     (0x1U<<10U)
#define MDF_DFLT3IER_SATIE      (0x1U<<9U)
#define MDF_DFLT3IER_SCDIE      (0x1U<<8U)
#define MDF_DFLT3IER_SSOVRIE    (0x1U<<7U)
#define MDF_DFLT3IER_OLDIE      (0x1U<<4U)
#define MDF_DFLT3IER_SSDRIE     (0x1U<<2U)
#define MDF_DFLT3IER_DOVRIE     (0x1U<<1U)
#define MDF_DFLT3IER_FTHIE      (0x1U<<0U)

// DFLT3ISR Configuration

#define MDF_DFLT3ISR_RFOVRF     (0x1U<<11U)
#define MDF_DFLT3ISR_CKABF      (0x1U<<10U)
#define MDF_DFLT3ISR_SATF       (0x1U<<9U)
#define MDF_DFLT3ISR_SCDF       (0x1U<<8U)
#define MDF_DFLT3ISR_SSOVRF     (0x1U<<7U)
#define MDF_DFLT3ISR_THHF       (0x1U<<6U)
#define MDF_DFLT3ISR_THLF       (0x1U<<5U)
#define MDF_DFLT3ISR_OLDF       (0x1U<<4U)
#define MDF_DFLT3ISR_RXNEF      (0x1U<<3U)
#define MDF_DFLT3ISR_SSDRF      (0x1U<<2U)
#define MDF_DFLT3ISR_DOVRF      (0x1U<<1U)
#define MDF_DFLT3ISR_FTHF       (0x1U<<0U)

// OEC3CR Configuration

#define MDF_OEC3CR_OFFSET       (0x3FFFFFFU<<0U)
#define MDF_OEC3CR_OFFSET_0     (0x1U<<0U)

// SNPS3DR Configuration

#define MDF_SNPS3DR_SDR         (0xFFFFU<<16U)
#define MDF_SNPS3DR_SDR_0       (0x1U<<16U)
#define MDF_SNPS3DR_EXTSDR      (0x7FU<<9U)
#define MDF_SNPS3DR_EXTSDR_0    (0x1U<<9U)
#define MDF_SNPS3DR_MCICDC      (0x1FFU<<0U)
#define MDF_SNPS3DR_MCICDC_0    (0x1U<<0U)

// DFLT3DR Configuration

#define MDF_DFLT3DR_DR          (0xFFFFFFU<<8U)
#define MDF_DFLT3DR_DR_0        (0x1U<<8U)

// SITF4CR Configuration

#define MDF_SITF4CR_SITFACTIVE  (0x1U<<31U)
#define MDF_SITF4CR_STH         (0x1FU<<8U)
#define MDF_SITF4CR_STH_0       (0x1U<<8U)
#define MDF_SITF4CR_SITFMOD     (0x3U<<4U)
#define MDF_SITF4CR_SITFMOD_0   (0x1U<<4U)
#define MDF_SITF4CR_SCKSRC      (0x3U<<1U)
#define MDF_SITF4CR_SCKSRC_0    (0x1U<<1U)
#define MDF_SITF4CR_SITFEN      (0x1U<<0U)

// BSMX4CR Configuration

#define MDF_BSMX4CR_BSMXACTIVE  (0x1U<<31U)
#define MDF_BSMX4CR_BSSEL       (0x1FU<<0U)
#define MDF_BSMX4CR_BSSEL_0     (0x1U<<0U)

// DFLT4CR Configuration

#define MDF_DFLT4CR_DFLTACTIVE  (0x1U<<31U)
#define MDF_DFLT4CR_DFLTRUN     (0x1U<<30U)
#define MDF_DFLT4CR_NBDIS       (0xFFU<<20U)
#define MDF_DFLT4CR_NBDIS_0     (0x1U<<20U)
#define MDF_DFLT4CR_SNPSFMT     (0x1U<<16U)
#define MDF_DFLT4CR_TRGSRC      (0xFU<<12U)
#define MDF_DFLT4CR_TRGSRC_0    (0x1U<<12U)
#define MDF_DFLT4CR_TRGSENS     (0x1U<<8U)
#define MDF_DFLT4CR_ACQMOD      (0x7U<<4U)
#define MDF_DFLT4CR_ACQMOD_0    (0x1U<<4U)
#define MDF_DFLT4CR_FTH         (0x1U<<2U)
#define MDF_DFLT4CR_DMAEN       (0x1U<<1U)
#define MDF_DFLT4CR_DFLTEN      (0x1U<<0U)

// DFLT4CICR Configuration

#define MDF_DFLT4CICR_SCALE     (0x3FU<<20U)
#define MDF_DFLT4CICR_SCALE_0   (0x1U<<20U)
#define MDF_DFLT4CICR_MCICD     (0x1FFU<<8U)
#define MDF_DFLT4CICR_MCICD_0   (0x1U<<8U)
#define MDF_DFLT4CICR_CICMOD    (0x7U<<4U)
#define MDF_DFLT4CICR_CICMOD_0  (0x1U<<4U)
#define MDF_DFLT4CICR_DATSRC    (0x3U<<0U)
#define MDF_DFLT4CICR_DATSRC_0  (0x1U<<0U)

// DFLT4RSFR Configuration

#define MDF_DFLT4RSFR_HPFC      (0x3U<<8U)
#define MDF_DFLT4RSFR_HPFC_0    (0x1U<<8U)
#define MDF_DFLT4RSFR_HPFBYP    (0x1U<<7U)
#define MDF_DFLT4RSFR_RSFLTD    (0x1U<<4U)
#define MDF_DFLT4RSFR_RSFLTBYP  (0x1U<<0U)

// DFLT4INTR Configuration

#define MDF_DFLT4INTR_INTVAL    (0x7FU<<4U)
#define MDF_DFLT4INTR_INTVAL_0  (0x1U<<4U)
#define MDF_DFLT4INTR_INTDIV    (0x3U<<0U)
#define MDF_DFLT4INTR_INTDIV_0  (0x1U<<0U)

// OLD4CR Configuration

#define MDF_OLD4CR_OLDACTIVE    (0x1U<<31U)
#define MDF_OLD4CR_ACICD        (0x1FU<<17U)
#define MDF_OLD4CR_ACICD_0      (0x1U<<17U)
#define MDF_OLD4CR_ACICN        (0x3U<<12U)
#define MDF_OLD4CR_ACICN_0      (0x1U<<12U)
#define MDF_OLD4CR_BKOLD        (0xFU<<4U)
#define MDF_OLD4CR_BKOLD_0      (0x1U<<4U)
#define MDF_OLD4CR_THINB        (0x1U<<1U)
#define MDF_OLD4CR_OLDEN        (0x1U<<0U)

// OLD4THLR Configuration

#define MDF_OLD4THLR_OLDTHL     (0x3FFFFFFU<<0U)
#define MDF_OLD4THLR_OLDTHL_0   (0x1U<<0U)

// OLD4THHR Configuration

#define MDF_OLD4THHR_OLDTHH     (0x3FFFFFFU<<0U)
#define MDF_OLD4THHR_OLDTHH_0   (0x1U<<0U)

// DLY4CR Configuration

#define MDF_DLY4CR_SKPBF        (0x1U<<31U)
#define MDF_DLY4CR_SKPDLY       (0x7FU<<0U)
#define MDF_DLY4CR_SKPDLY_0     (0x1U<<0U)

// SCD4CR Configuration

#define MDF_SCD4CR_SCDACTIVE    (0x1U<<31U)
#define MDF_SCD4CR_SCDT         (0xFFU<<12U)
#define MDF_SCD4CR_SCDT_0       (0x1U<<12U)
#define MDF_SCD4CR_BKSCD        (0xFU<<4U)
#define MDF_SCD4CR_BKSCD_0      (0x1U<<4U)
#define MDF_SCD4CR_SCDEN        (0x1U<<0U)

// DFLT4IER Configuration

#define MDF_DFLT4IER_RFOVRIE    (0x1U<<11U)
#define MDF_DFLT4IER_CKABIE     (0x1U<<10U)
#define MDF_DFLT4IER_SATIE      (0x1U<<9U)
#define MDF_DFLT4IER_SCDIE      (0x1U<<8U)
#define MDF_DFLT4IER_SSOVRIE    (0x1U<<7U)
#define MDF_DFLT4IER_OLDIE      (0x1U<<4U)
#define MDF_DFLT4IER_SSDRIE     (0x1U<<2U)
#define MDF_DFLT4IER_DOVRIE     (0x1U<<1U)
#define MDF_DFLT4IER_FTHIE      (0x1U<<0U)

// DFLT4ISR Configuration

#define MDF_DFLT4ISR_RFOVRF     (0x1U<<11U)
#define MDF_DFLT4ISR_CKABF      (0x1U<<10U)
#define MDF_DFLT4ISR_SATF       (0x1U<<9U)
#define MDF_DFLT4ISR_SCDF       (0x1U<<8U)
#define MDF_DFLT4ISR_SSOVRF     (0x1U<<7U)
#define MDF_DFLT4ISR_THHF       (0x1U<<6U)
#define MDF_DFLT4ISR_THLF       (0x1U<<5U)
#define MDF_DFLT4ISR_OLDF       (0x1U<<4U)
#define MDF_DFLT4ISR_RXNEF      (0x1U<<3U)
#define MDF_DFLT4ISR_SSDRF      (0x1U<<2U)
#define MDF_DFLT4ISR_DOVRF      (0x1U<<1U)
#define MDF_DFLT4ISR_FTHF       (0x1U<<0U)

// OEC4CR Configuration

#define MDF_OEC4CR_OFFSET       (0x3FFFFFFU<<0U)
#define MDF_OEC4CR_OFFSET_0     (0x1U<<0U)

// SNPS4DR Configuration

#define MDF_SNPS4DR_SDR         (0xFFFFU<<16U)
#define MDF_SNPS4DR_SDR_0       (0x1U<<16U)
#define MDF_SNPS4DR_EXTSDR      (0x7FU<<9U)
#define MDF_SNPS4DR_EXTSDR_0    (0x1U<<9U)
#define MDF_SNPS4DR_MCICDC      (0x1FFU<<0U)
#define MDF_SNPS4DR_MCICDC_0    (0x1U<<0U)

// DFLT4DR Configuration

#define MDF_DFLT4DR_DR          (0xFFFFFFU<<8U)
#define MDF_DFLT4DR_DR_0        (0x1U<<8U)

// SITF5CR Configuration

#define MDF_SITF5CR_SITFACTIVE  (0x1U<<31U)
#define MDF_SITF5CR_STH         (0x1FU<<8U)
#define MDF_SITF5CR_STH_0       (0x1U<<8U)
#define MDF_SITF5CR_SITFMOD     (0x3U<<4U)
#define MDF_SITF5CR_SITFMOD_0   (0x1U<<4U)
#define MDF_SITF5CR_SCKSRC      (0x3U<<1U)
#define MDF_SITF5CR_SCKSRC_0    (0x1U<<1U)
#define MDF_SITF5CR_SITFEN      (0x1U<<0U)

// BSMX5CR Configuration

#define MDF_BSMX5CR_BSMXACTIVE  (0x1U<<31U)
#define MDF_BSMX5CR_BSSEL       (0x1FU<<0U)
#define MDF_BSMX5CR_BSSEL_0     (0x1U<<0U)

// DFLT5CR Configuration

#define MDF_DFLT5CR_DFLTACTIVE  (0x1U<<31U)
#define MDF_DFLT5CR_DFLTRUN     (0x1U<<30U)
#define MDF_DFLT5CR_NBDIS       (0xFFU<<20U)
#define MDF_DFLT5CR_NBDIS_0     (0x1U<<20U)
#define MDF_DFLT5CR_SNPSFMT     (0x1U<<16U)
#define MDF_DFLT5CR_TRGSRC      (0xFU<<12U)
#define MDF_DFLT5CR_TRGSRC_0    (0x1U<<12U)
#define MDF_DFLT5CR_TRGSENS     (0x1U<<8U)
#define MDF_DFLT5CR_ACQMOD      (0x7U<<4U)
#define MDF_DFLT5CR_ACQMOD_0    (0x1U<<4U)
#define MDF_DFLT5CR_FTH         (0x1U<<2U)
#define MDF_DFLT5CR_DMAEN       (0x1U<<1U)
#define MDF_DFLT5CR_DFLTEN      (0x1U<<0U)

// DFLT5CICR Configuration

#define MDF_DFLT5CICR_SCALE     (0x3FU<<20U)
#define MDF_DFLT5CICR_SCALE_0   (0x1U<<20U)
#define MDF_DFLT5CICR_MCICD     (0x1FFU<<8U)
#define MDF_DFLT5CICR_MCICD_0   (0x1U<<8U)
#define MDF_DFLT5CICR_CICMOD    (0x7U<<4U)
#define MDF_DFLT5CICR_CICMOD_0  (0x1U<<4U)
#define MDF_DFLT5CICR_DATSRC    (0x3U<<0U)
#define MDF_DFLT5CICR_DATSRC_0  (0x1U<<0U)

// DFLT5RSFR Configuration

#define MDF_DFLT5RSFR_HPFC      (0x3U<<8U)
#define MDF_DFLT5RSFR_HPFC_0    (0x1U<<8U)
#define MDF_DFLT5RSFR_HPFBYP    (0x1U<<7U)
#define MDF_DFLT5RSFR_RSFLTD    (0x1U<<4U)
#define MDF_DFLT5RSFR_RSFLTBYP  (0x1U<<0U)

// DFLT5INTR Configuration

#define MDF_DFLT5INTR_INTVAL    (0x7FU<<4U)
#define MDF_DFLT5INTR_INTVAL_0  (0x1U<<4U)
#define MDF_DFLT5INTR_INTDIV    (0x3U<<0U)
#define MDF_DFLT5INTR_INTDIV_0  (0x1U<<0U)

// OLD5CR Configuration

#define MDF_OLD5CR_OLDACTIVE    (0x1U<<31U)
#define MDF_OLD5CR_ACICD        (0x1FU<<17U)
#define MDF_OLD5CR_ACICD_0      (0x1U<<17U)
#define MDF_OLD5CR_ACICN        (0x3U<<12U)
#define MDF_OLD5CR_ACICN_0      (0x1U<<12U)
#define MDF_OLD5CR_BKOLD        (0xFU<<4U)
#define MDF_OLD5CR_BKOLD_0      (0x1U<<4U)
#define MDF_OLD5CR_THINB        (0x1U<<1U)
#define MDF_OLD5CR_OLDEN        (0x1U<<0U)

// OLD5THLR Configuration

#define MDF_OLD5THLR_OLDTHL     (0x3FFFFFFU<<0U)
#define MDF_OLD5THLR_OLDTHL_0   (0x1U<<0U)

// OLD5THHR Configuration

#define MDF_OLD5THHR_OLDTHH     (0x3FFFFFFU<<0U)
#define MDF_OLD5THHR_OLDTHH_0   (0x1U<<0U)

// DLY5CR Configuration

#define MDF_DLY5CR_SKPBF        (0x1U<<31U)
#define MDF_DLY5CR_SKPDLY       (0x7FU<<0U)
#define MDF_DLY5CR_SKPDLY_0     (0x1U<<0U)

// SCD5CR Configuration

#define MDF_SCD5CR_SCDACTIVE    (0x1U<<31U)
#define MDF_SCD5CR_SCDT         (0xFFU<<12U)
#define MDF_SCD5CR_SCDT_0       (0x1U<<12U)
#define MDF_SCD5CR_BKSCD        (0xFU<<4U)
#define MDF_SCD5CR_BKSCD_0      (0x1U<<4U)
#define MDF_SCD5CR_SCDEN        (0x1U<<0U)

// DFLT5IER Configuration

#define MDF_DFLT5IER_RFOVRIE    (0x1U<<11U)
#define MDF_DFLT5IER_CKABIE     (0x1U<<10U)
#define MDF_DFLT5IER_SATIE      (0x1U<<9U)
#define MDF_DFLT5IER_SCDIE      (0x1U<<8U)
#define MDF_DFLT5IER_SSOVRIE    (0x1U<<7U)
#define MDF_DFLT5IER_OLDIE      (0x1U<<4U)
#define MDF_DFLT5IER_SSDRIE     (0x1U<<2U)
#define MDF_DFLT5IER_DOVRIE     (0x1U<<1U)
#define MDF_DFLT5IER_FTHIE      (0x1U<<0U)

// DFLT5ISR Configuration

#define MDF_DFLT5ISR_RFOVRF     (0x1U<<11U)
#define MDF_DFLT5ISR_CKABF      (0x1U<<10U)
#define MDF_DFLT5ISR_SATF       (0x1U<<9U)
#define MDF_DFLT5ISR_SCDF       (0x1U<<8U)
#define MDF_DFLT5ISR_SSOVRF     (0x1U<<7U)
#define MDF_DFLT5ISR_THHF       (0x1U<<6U)
#define MDF_DFLT5ISR_THLF       (0x1U<<5U)
#define MDF_DFLT5ISR_OLDF       (0x1U<<4U)
#define MDF_DFLT5ISR_RXNEF      (0x1U<<3U)
#define MDF_DFLT5ISR_SSDRF      (0x1U<<2U)
#define MDF_DFLT5ISR_DOVRF      (0x1U<<1U)
#define MDF_DFLT5ISR_FTHF       (0x1U<<0U)

// OEC5CR Configuration

#define MDF_OEC5CR_OFFSET       (0x3FFFFFFU<<0U)
#define MDF_OEC5CR_OFFSET_0     (0x1U<<0U)

// SNPS5DR Configuration

#define MDF_SNPS5DR_SDR         (0xFFFFU<<16U)
#define MDF_SNPS5DR_SDR_0       (0x1U<<16U)
#define MDF_SNPS5DR_EXTSDR      (0x7FU<<9U)
#define MDF_SNPS5DR_EXTSDR_0    (0x1U<<9U)
#define MDF_SNPS5DR_MCICDC      (0x1FFU<<0U)
#define MDF_SNPS5DR_MCICDC_0    (0x1U<<0U)

// DFLT5DR Configuration

#define MDF_DFLT5DR_DR          (0xFFFFFFU<<8U)
#define MDF_DFLT5DR_DR_0        (0x1U<<8U)
