/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_adf.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_adf equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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
#define ADF_NS  reinterpret_cast<ADF_TypeDef *>(0x42026000U)
#define ADF_S   reinterpret_cast<ADF_TypeDef *>(0x52026000U)

#else
#define ADF_NS  ((ADF_TypeDef *)0x42026000U)
#define ADF_S   ((ADF_TypeDef *)0x52026000U)
#endif

// GCR Configuration

#define ADF_GCR_TRGO                    (0x1U<<0)

#define ADF_GCR_TRGO_B_0X0              (0x0U<<0)
#define ADF_GCR_TRGO_B_0X1              (0x1U<<0)

// CKGCR Configuration

#define ADF_CKGCR_CKGACTIVE             (0x1U<<31)
#define ADF_CKGCR_PROCDIV               (0x7FU<<24)
#define ADF_CKGCR_PROCDIV_0             (0x1U<<24)
#define ADF_CKGCR_CCKDIV                (0xFU<<16)
#define ADF_CKGCR_CCKDIV_0              (0x1U<<16)
#define ADF_CKGCR_TRGSRC                (0xFU<<12)
#define ADF_CKGCR_TRGSRC_0              (0x1U<<12)
#define ADF_CKGCR_TRGSENS               (0x1U<<8)
#define ADF_CKGCR_CCK1DIR               (0x1U<<6)
#define ADF_CKGCR_CCK0DIR               (0x1U<<5)
#define ADF_CKGCR_CKGMOD                (0x1U<<4)
#define ADF_CKGCR_CCK1EN                (0x1U<<2)
#define ADF_CKGCR_CCK0EN                (0x1U<<1)
#define ADF_CKGCR_CKGDEN                (0x1U<<0)

#define ADF_CKGCR_CKGACTIVE_B_0X0       (0x0U<<31)
#define ADF_CKGCR_CKGACTIVE_B_0X1       (0x1U<<31)
#define ADF_CKGCR_PROCDIV_B_0X0         (0x0U<<24)
#define ADF_CKGCR_PROCDIV_B_0X1         (0x1U<<24)
#define ADF_CKGCR_CCKDIV_B_0X0          (0x0U<<16)
#define ADF_CKGCR_CCKDIV_B_0X1          (0x1U<<16)
#define ADF_CKGCR_CCKDIV_B_0X2          (0x2U<<16)
#define ADF_CKGCR_CCKDIV_B_0XF          (0xFU<<16)
#define ADF_CKGCR_TRGSRC_B_0X2          (0x2U<<12)
#define ADF_CKGCR_TRGSENS_B_0X0         (0x0U<<8)
#define ADF_CKGCR_TRGSENS_B_0X1         (0x1U<<8)
#define ADF_CKGCR_CCK1DIR_B_0X0         (0x0U<<6)
#define ADF_CKGCR_CCK1DIR_B_0X1         (0x1U<<6)
#define ADF_CKGCR_CCK0DIR_B_0X0         (0x0U<<5)
#define ADF_CKGCR_CCK0DIR_B_0X1         (0x1U<<5)
#define ADF_CKGCR_CKGMOD_B_0X0          (0x0U<<4)
#define ADF_CKGCR_CKGMOD_B_0X1          (0x1U<<4)
#define ADF_CKGCR_CCK1EN_B_0X0          (0x0U<<2)
#define ADF_CKGCR_CCK1EN_B_0X1          (0x1U<<2)
#define ADF_CKGCR_CCK0EN_B_0X0          (0x0U<<1)
#define ADF_CKGCR_CCK0EN_B_0X1          (0x1U<<1)
#define ADF_CKGCR_CKGDEN_B_0X0          (0x0U<<0)
#define ADF_CKGCR_CKGDEN_B_0X1          (0x1U<<0)

// SITF0CR Configuration

#define ADF_SITF0CR_SITFACTIVE          (0x1U<<31)
#define ADF_SITF0CR_STH                 (0x1FU<<8)
#define ADF_SITF0CR_STH_0               (0x1U<<8)
#define ADF_SITF0CR_SITFMOD             (0x3U<<4)
#define ADF_SITF0CR_SITFMOD_0           (0x1U<<4)
#define ADF_SITF0CR_SCKSRC              (0x3U<<1)
#define ADF_SITF0CR_SCKSRC_0            (0x1U<<1)
#define ADF_SITF0CR_SITFEN              (0x1U<<0)

#define ADF_SITF0CR_SITFACTIVE_B_0X0    (0x0U<<31)
#define ADF_SITF0CR_SITFACTIVE_B_0X1    (0x1U<<31)
#define ADF_SITF0CR_SITFMOD_B_0X0       (0x0U<<4)
#define ADF_SITF0CR_SITFMOD_B_0X1       (0x1U<<4)
#define ADF_SITF0CR_SITFMOD_B_0X2       (0x2U<<4)
#define ADF_SITF0CR_SITFMOD_B_0X3       (0x3U<<4)
#define ADF_SITF0CR_SCKSRC_B_0X0        (0x0U<<1)
#define ADF_SITF0CR_SCKSRC_B_0X1        (0x1U<<1)
#define ADF_SITF0CR_SITFEN_B_0X0        (0x0U<<0)
#define ADF_SITF0CR_SITFEN_B_0X1        (0x1U<<0)

// BSMX0CR Configuration

#define ADF_BSMX0CR_BSMXACTIVE          (0x1U<<31)
#define ADF_BSMX0CR_BSSEL               (0x1FU<<0)
#define ADF_BSMX0CR_BSSEL_0             (0x1U<<0)

#define ADF_BSMX0CR_BSMXACTIVE_B_0X0    (0x0U<<31)
#define ADF_BSMX0CR_BSMXACTIVE_B_0X1    (0x1U<<31)
#define ADF_BSMX0CR_BSSEL_B_0X0         (0x0U<<0)
#define ADF_BSMX0CR_BSSEL_B_0X1         (0x1U<<0)

// DFLT0CR Configuration

#define ADF_DFLT0CR_DFLTACTIVE          (0x1U<<31)
#define ADF_DFLT0CR_DFLTRUN             (0x1U<<30)
#define ADF_DFLT0CR_NBDIS               (0xFFU<<20)
#define ADF_DFLT0CR_NBDIS_0             (0x1U<<20)
#define ADF_DFLT0CR_TRGSRC              (0xFU<<12)
#define ADF_DFLT0CR_TRGSRC_0            (0x1U<<12)
#define ADF_DFLT0CR_TRGSENS             (0x1U<<8)
#define ADF_DFLT0CR_ACQMOD              (0x7U<<4)
#define ADF_DFLT0CR_ACQMOD_0            (0x1U<<4)
#define ADF_DFLT0CR_FTH                 (0x1U<<2)
#define ADF_DFLT0CR_DMAEN               (0x1U<<1)
#define ADF_DFLT0CR_DFLTEN              (0x1U<<0)

#define ADF_DFLT0CR_DFLTACTIVE_B_0X0    (0x0U<<31)
#define ADF_DFLT0CR_DFLTACTIVE_B_0X1    (0x1U<<31)
#define ADF_DFLT0CR_DFLTRUN_B_0X0       (0x0U<<30)
#define ADF_DFLT0CR_DFLTRUN_B_0X1       (0x1U<<30)
#define ADF_DFLT0CR_NBDIS_B_0X0         (0x0U<<20)
#define ADF_DFLT0CR_NBDIS_B_0X1         (0x1U<<20)
#define ADF_DFLT0CR_TRGSRC_B_0X0        (0x0U<<12)
#define ADF_DFLT0CR_TRGSRC_B_0X2        (0x2U<<12)
#define ADF_DFLT0CR_TRGSENS_B_0X0       (0x0U<<8)
#define ADF_DFLT0CR_TRGSENS_B_0X1       (0x1U<<8)
#define ADF_DFLT0CR_ACQMOD_B_0X0        (0x0U<<4)
#define ADF_DFLT0CR_ACQMOD_B_0X1        (0x1U<<4)
#define ADF_DFLT0CR_ACQMOD_B_0X2        (0x2U<<4)
#define ADF_DFLT0CR_ACQMOD_B_0X3        (0x3U<<4)
#define ADF_DFLT0CR_ACQMOD_B_0X4        (0x4U<<4)
#define ADF_DFLT0CR_FTH_B_0X0           (0x0U<<2)
#define ADF_DFLT0CR_FTH_B_0X1           (0x1U<<2)
#define ADF_DFLT0CR_DMAEN_B_0X0         (0x0U<<1)
#define ADF_DFLT0CR_DMAEN_B_0X1         (0x1U<<1)
#define ADF_DFLT0CR_DFLTEN_B_0X0        (0x0U<<0)
#define ADF_DFLT0CR_DFLTEN_B_0X1        (0x1U<<0)

// DFLT0CICR Configuration

#define ADF_DFLT0CICR_SCALE             (0x3FU<<20)
#define ADF_DFLT0CICR_SCALE_0           (0x1U<<20)
#define ADF_DFLT0CICR_MCICD8            (0x1U<<16)
#define ADF_DFLT0CICR_MCICD             (0xFFU<<8)
#define ADF_DFLT0CICR_MCICD_0           (0x1U<<8)
#define ADF_DFLT0CICR_CICMOD            (0x7U<<4)
#define ADF_DFLT0CICR_CICMOD_0          (0x1U<<4)
#define ADF_DFLT0CICR_DATSRC            (0x3U<<0)
#define ADF_DFLT0CICR_DATSRC_0          (0x1U<<0)

#define ADF_DFLT0CICR_SCALE_B_0X0       (0x0U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X1       (0x1U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X2       (0x2U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X18      (0x18U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X20      (0x20U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X21      (0x21U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X22      (0x22U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X23      (0x23U<<20)
#define ADF_DFLT0CICR_SCALE_B_0X2E      (0x2EU<<20)
#define ADF_DFLT0CICR_SCALE_B_0X2F      (0x2FU<<20)
#define ADF_DFLT0CICR_MCICD8_B_0X0      (0x0U<<16)
#define ADF_DFLT0CICR_MCICD8_B_0X1      (0x1U<<16)
#define ADF_DFLT0CICR_MCICD_B_0X0       (0x0U<<8)
#define ADF_DFLT0CICR_MCICD_B_0X1       (0x1U<<8)
#define ADF_DFLT0CICR_CICMOD_B_0X4      (0x4U<<4)
#define ADF_DFLT0CICR_CICMOD_B_0X5      (0x5U<<4)
#define ADF_DFLT0CICR_DATSRC_B_0X2      (0x2U<<0)
#define ADF_DFLT0CICR_DATSRC_B_0X3      (0x3U<<0)

// DFLT0RSFR Configuration

#define ADF_DFLT0RSFR_HPFC              (0x3U<<8)
#define ADF_DFLT0RSFR_HPFC_0            (0x1U<<8)
#define ADF_DFLT0RSFR_HPFBYP            (0x1U<<7)
#define ADF_DFLT0RSFR_RSFLTD            (0x1U<<4)
#define ADF_DFLT0RSFR_RSFLTBYP          (0x1U<<0)

#define ADF_DFLT0RSFR_HPFC_B_0X0        (0x0U<<8)
#define ADF_DFLT0RSFR_HPFC_B_0X1        (0x1U<<8)
#define ADF_DFLT0RSFR_HPFC_B_0X2        (0x2U<<8)
#define ADF_DFLT0RSFR_HPFC_B_0X3        (0x3U<<8)
#define ADF_DFLT0RSFR_HPFBYP_B_0X0      (0x0U<<7)
#define ADF_DFLT0RSFR_HPFBYP_B_0X1      (0x1U<<7)
#define ADF_DFLT0RSFR_RSFLTD_B_0X0      (0x0U<<4)
#define ADF_DFLT0RSFR_RSFLTD_B_0X1      (0x1U<<4)
#define ADF_DFLT0RSFR_RSFLTBYP_B_0X0    (0x0U<<0)
#define ADF_DFLT0RSFR_RSFLTBYP_B_0X1    (0x1U<<0)

// DLY0CR Configuration

#define ADF_DLY0CR_SKPBF                (0x1U<<31)
#define ADF_DLY0CR_SKPDLY               (0x7FU<<0)
#define ADF_DLY0CR_SKPDLY_0             (0x1U<<0)

#define ADF_DLY0CR_SKPBF_B_0X0          (0x0U<<31)
#define ADF_DLY0CR_SKPBF_B_0X1          (0x1U<<31)
#define ADF_DLY0CR_SKPDLY_B_0X0         (0x0U<<0)
#define ADF_DLY0CR_SKPDLY_B_0X1         (0x1U<<0)

// DFLT0IER Configuration

#define ADF_DFLT0IER_SDLVLIE            (0x1U<<13)
#define ADF_DFLT0IER_SDDETIE            (0x1U<<12)
#define ADF_DFLT0IER_RFOVRIE            (0x1U<<11)
#define ADF_DFLT0IER_CKABIE             (0x1U<<10)
#define ADF_DFLT0IER_SATIE              (0x1U<<9)
#define ADF_DFLT0IER_DOVRIE             (0x1U<<1)
#define ADF_DFLT0IER_FTHIE              (0x1U<<0)

#define ADF_DFLT0IER_SDLVLIE_B_0X0      (0x0U<<13)
#define ADF_DFLT0IER_SDLVLIE_B_0X1      (0x1U<<13)
#define ADF_DFLT0IER_SDDETIE_B_0X0      (0x0U<<12)
#define ADF_DFLT0IER_SDDETIE_B_0X1      (0x1U<<12)
#define ADF_DFLT0IER_RFOVRIE_B_0X0      (0x0U<<11)
#define ADF_DFLT0IER_RFOVRIE_B_0X1      (0x1U<<11)
#define ADF_DFLT0IER_CKABIE_B_0X0       (0x0U<<10)
#define ADF_DFLT0IER_CKABIE_B_0X1       (0x1U<<10)
#define ADF_DFLT0IER_SATIE_B_0X0        (0x0U<<9)
#define ADF_DFLT0IER_SATIE_B_0X1        (0x1U<<9)
#define ADF_DFLT0IER_DOVRIE_B_0X0       (0x0U<<1)
#define ADF_DFLT0IER_DOVRIE_B_0X1       (0x1U<<1)
#define ADF_DFLT0IER_FTHIE_B_0X0        (0x0U<<0)
#define ADF_DFLT0IER_FTHIE_B_0X1        (0x1U<<0)

// DFLT0ISR Configuration

#define ADF_DFLT0ISR_SDLVLF             (0x1U<<13)
#define ADF_DFLT0ISR_SDDETF             (0x1U<<12)
#define ADF_DFLT0ISR_RFOVRF             (0x1U<<11)
#define ADF_DFLT0ISR_CKABF              (0x1U<<10)
#define ADF_DFLT0ISR_SATF               (0x1U<<9)
#define ADF_DFLT0ISR_RXNEF              (0x1U<<3)
#define ADF_DFLT0ISR_DOVRF              (0x1U<<1)
#define ADF_DFLT0ISR_FTHF               (0x1U<<0)

#define ADF_DFLT0ISR_SDLVLF_B_0X0       (0x0U<<13)
#define ADF_DFLT0ISR_SDLVLF_B_0X1       (0x1U<<13)
#define ADF_DFLT0ISR_SDDETF_B_0X0       (0x0U<<12)
#define ADF_DFLT0ISR_SDDETF_B_0X1       (0x1U<<12)
#define ADF_DFLT0ISR_RFOVRF_B_0X0       (0x0U<<11)
#define ADF_DFLT0ISR_RFOVRF_B_0X1       (0x1U<<11)
#define ADF_DFLT0ISR_CKABF_B_0X0        (0x0U<<10)
#define ADF_DFLT0ISR_CKABF_B_0X1        (0x1U<<10)
#define ADF_DFLT0ISR_SATF_B_0X0         (0x0U<<9)
#define ADF_DFLT0ISR_SATF_B_0X1         (0x1U<<9)
#define ADF_DFLT0ISR_RXNEF_B_0X0        (0x0U<<3)
#define ADF_DFLT0ISR_RXNEF_B_0X1        (0x1U<<3)
#define ADF_DFLT0ISR_DOVRF_B_0X0        (0x0U<<1)
#define ADF_DFLT0ISR_DOVRF_B_0X1        (0x1U<<1)
#define ADF_DFLT0ISR_FTHF_B_0X0         (0x0U<<0)
#define ADF_DFLT0ISR_FTHF_B_0X1         (0x1U<<0)

// SADCR Configuration

#define ADF_SADCR_SADACTIVE             (0x1U<<31)
#define ADF_SADCR_SADMOD                (0x3U<<12)
#define ADF_SADCR_SADMOD_0              (0x1U<<12)
#define ADF_SADCR_FRSIZE                (0x7U<<8)
#define ADF_SADCR_FRSIZE_0              (0x1U<<8)
#define ADF_SADCR_HYSTEN                (0x1U<<7)
#define ADF_SADCR_SADST                 (0x3U<<4)
#define ADF_SADCR_SADST_0               (0x1U<<4)
#define ADF_SADCR_DETCFG                (0x1U<<3)
#define ADF_SADCR_DATCAP                (0x3U<<1)
#define ADF_SADCR_DATCAP_0              (0x1U<<1)
#define ADF_SADCR_SADEN                 (0x1U<<0)

#define ADF_SADCR_SADACTIVE_B_0X0       (0x0U<<31)
#define ADF_SADCR_SADACTIVE_B_0X1       (0x1U<<31)
#define ADF_SADCR_SADMOD_B_0X0          (0x0U<<12)
#define ADF_SADCR_SADMOD_B_0X1          (0x1U<<12)
#define ADF_SADCR_FRSIZE_B_0X0          (0x0U<<8)
#define ADF_SADCR_FRSIZE_B_0X1          (0x1U<<8)
#define ADF_SADCR_FRSIZE_B_0X2          (0x2U<<8)
#define ADF_SADCR_FRSIZE_B_0X3          (0x3U<<8)
#define ADF_SADCR_FRSIZE_B_0X4          (0x4U<<8)
#define ADF_SADCR_FRSIZE_B_0X5          (0x5U<<8)
#define ADF_SADCR_HYSTEN_B_0X0          (0x0U<<7)
#define ADF_SADCR_HYSTEN_B_0X1          (0x1U<<7)
#define ADF_SADCR_SADST_B_0X0           (0x0U<<4)
#define ADF_SADCR_SADST_B_0X1           (0x1U<<4)
#define ADF_SADCR_SADST_B_0X3           (0x3U<<4)
#define ADF_SADCR_DETCFG_B_0X0          (0x0U<<3)
#define ADF_SADCR_DETCFG_B_0X1          (0x1U<<3)
#define ADF_SADCR_DATCAP_B_0X0          (0x0U<<1)
#define ADF_SADCR_DATCAP_B_0X1          (0x1U<<1)
#define ADF_SADCR_SADEN_B_0X0           (0x0U<<0)
#define ADF_SADCR_SADEN_B_0X1           (0x1U<<0)

// SADCFGR Configuration

#define ADF_SADCFGR_ANMIN               (0x1FFFU<<16)
#define ADF_SADCFGR_ANMIN_0             (0x1U<<16)
#define ADF_SADCFGR_HGOVR               (0x7U<<12)
#define ADF_SADCFGR_HGOVR_0             (0x1U<<12)
#define ADF_SADCFGR_LFRNB               (0x7U<<8)
#define ADF_SADCFGR_LFRNB_0             (0x1U<<8)
#define ADF_SADCFGR_ANSLP               (0x7U<<4)
#define ADF_SADCFGR_ANSLP_0             (0x1U<<4)
#define ADF_SADCFGR_SNTHR               (0xFU<<0)
#define ADF_SADCFGR_SNTHR_0             (0x1U<<0)

#define ADF_SADCFGR_HGOVR_B_0X0         (0x0U<<12)
#define ADF_SADCFGR_HGOVR_B_0X1         (0x1U<<12)
#define ADF_SADCFGR_HGOVR_B_0X2         (0x2U<<12)
#define ADF_SADCFGR_HGOVR_B_0X3         (0x3U<<12)
#define ADF_SADCFGR_HGOVR_B_0X4         (0x4U<<12)
#define ADF_SADCFGR_HGOVR_B_0X5         (0x5U<<12)
#define ADF_SADCFGR_HGOVR_B_0X6         (0x6U<<12)
#define ADF_SADCFGR_HGOVR_B_0X7         (0x7U<<12)
#define ADF_SADCFGR_LFRNB_B_0X0         (0x0U<<8)
#define ADF_SADCFGR_LFRNB_B_0X1         (0x1U<<8)
#define ADF_SADCFGR_LFRNB_B_0X2         (0x2U<<8)
#define ADF_SADCFGR_LFRNB_B_0X3         (0x3U<<8)
#define ADF_SADCFGR_SNTHR_B_0X0         (0x0U<<0)
#define ADF_SADCFGR_SNTHR_B_0X1         (0x1U<<0)
#define ADF_SADCFGR_SNTHR_B_0X2         (0x2U<<0)
#define ADF_SADCFGR_SNTHR_B_0X3         (0x3U<<0)
#define ADF_SADCFGR_SNTHR_B_0X4         (0x4U<<0)
#define ADF_SADCFGR_SNTHR_B_0X5         (0x5U<<0)
#define ADF_SADCFGR_SNTHR_B_0X6         (0x6U<<0)
#define ADF_SADCFGR_SNTHR_B_0X7         (0x7U<<0)
#define ADF_SADCFGR_SNTHR_B_0X8         (0x8U<<0)
#define ADF_SADCFGR_SNTHR_B_0X9         (0x9U<<0)

// SADSDLVR Configuration

#define ADF_SADSDLVR_SDLVL              (0x7FFFU<<0)
#define ADF_SADSDLVR_SDLVL_0            (0x1U<<0)

// SADANLVR Configuration

#define ADF_SADANLVR_ANLVL              (0x7FFFU<<0)
#define ADF_SADANLVR_ANLVL_0            (0x1U<<0)

// DFLT0DR Configuration

#define ADF_DFLT0DR_DR                  (0xFFFFFFU<<8)
#define ADF_DFLT0DR_DR_0                (0x1U<<8)
