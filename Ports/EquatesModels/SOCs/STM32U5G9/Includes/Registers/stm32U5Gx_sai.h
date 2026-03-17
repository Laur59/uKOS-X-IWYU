/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_sai.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_sai equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// SAI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    GCR;
    volatile    uint32_t    ACR1;
    volatile    uint32_t    ACR2;
    volatile    uint32_t    AFRCR;
    volatile    uint32_t    ASLOTR;
    volatile    uint32_t    AIM;
    volatile    uint32_t    ASR;
    volatile    uint32_t    ACLRFR;
    volatile    uint32_t    ADR;
    volatile    uint32_t    BCR1;
    volatile    uint32_t    BCR2;
    volatile    uint32_t    BFRCR;
    volatile    uint32_t    BSLOTR;
    volatile    uint32_t    BIM;
    volatile    uint32_t    BSR;
    volatile    uint32_t    BCLRFR;
    volatile    uint32_t    BDR;
    volatile    uint32_t    PDMCR;
    volatile    uint32_t    PDMDLY;
} SAI_TypeDef;

#ifdef __cplusplus
#define SAI1_NS reinterpret_cast<SAI_TypeDef *>(0x40015400U)
#define SAI1_S  reinterpret_cast<SAI_TypeDef *>(0x50015400U)
#define SAI2_NS reinterpret_cast<SAI_TypeDef *>(0x40015800U)
#define SAI2_S  reinterpret_cast<SAI_TypeDef *>(0x50015800U)

#else
#define SAI1_NS ((SAI_TypeDef *)0x40015400U)
#define SAI1_S  ((SAI_TypeDef *)0x50015400U)
#define SAI2_NS ((SAI_TypeDef *)0x40015800U)
#define SAI2_S  ((SAI_TypeDef *)0x50015800U)
#endif

// GCR Configuration

#define SAI_GCR_SYNCOUT     (0x3U<<4)
#define SAI_GCR_SYNCOUT_0   (0x1U<<4)
#define SAI_GCR_SYNCIN      (0x3U<<0)
#define SAI_GCR_SYNCIN_0    (0x1U<<0)

// ACR1 Configuration

#define SAI_ACR1_MODE       (0x3U<<0)
#define SAI_ACR1_MODE_0     (0x1U<<0)
#define SAI_ACR1_PRTCFG     (0x3U<<2)
#define SAI_ACR1_PRTCFG_0   (0x1U<<2)
#define SAI_ACR1_DS         (0x7U<<5)
#define SAI_ACR1_DS_0       (0x1U<<5)
#define SAI_ACR1_LSBFIRST   (0x1U<<8)
#define SAI_ACR1_CKSTR      (0x1U<<9)
#define SAI_ACR1_SYNCEN     (0x3U<<10)
#define SAI_ACR1_SYNCEN_0   (0x1U<<10)
#define SAI_ACR1_MONO       (0x1U<<12)
#define SAI_ACR1_OUTDRIV    (0x1U<<13)
#define SAI_ACR1_SAIAEN     (0x1U<<16)
#define SAI_ACR1_DMAEN      (0x1U<<17)
#define SAI_ACR1_NODIV      (0x1U<<19)
#define SAI_ACR1_MCKDIV     (0x3FU<<20)
#define SAI_ACR1_MCKDIV_0   (0x1U<<20)
#define SAI_ACR1_OSR        (0x1U<<26)
#define SAI_ACR1_MCKEN      (0x1U<<27)

// ACR2 Configuration

#define SAI_ACR2_FTH        (0x7U<<0)
#define SAI_ACR2_FTH_0      (0x1U<<0)
#define SAI_ACR2_FFLUSH     (0x1U<<3)
#define SAI_ACR2_TRIS       (0x1U<<4)
#define SAI_ACR2_MUTE       (0x1U<<5)
#define SAI_ACR2_MUTEVAL    (0x1U<<6)
#define SAI_ACR2_MUTECN     (0x3FU<<7)
#define SAI_ACR2_MUTECN_0   (0x1U<<7)
#define SAI_ACR2_CPL        (0x1U<<13)
#define SAI_ACR2_COMP       (0x3U<<14)
#define SAI_ACR2_COMP_0     (0x1U<<14)

// AFRCR Configuration

#define SAI_AFRCR_FRL       (0xFFU<<0)
#define SAI_AFRCR_FRL_0     (0x1U<<0)
#define SAI_AFRCR_FSALL     (0x7FU<<8)
#define SAI_AFRCR_FSALL_0   (0x1U<<8)
#define SAI_AFRCR_FSDEF     (0x1U<<16)
#define SAI_AFRCR_FSPOL     (0x1U<<17)
#define SAI_AFRCR_FSOFF     (0x1U<<18)

// ASLOTR Configuration

#define SAI_ASLOTR_FBOFF    (0x1FU<<0)
#define SAI_ASLOTR_FBOFF_0  (0x1U<<0)
#define SAI_ASLOTR_SLOTSZ   (0x3U<<6)
#define SAI_ASLOTR_SLOTSZ_0 (0x1U<<6)
#define SAI_ASLOTR_NBSLOT   (0xFU<<8)
#define SAI_ASLOTR_NBSLOT_0 (0x1U<<8)
#define SAI_ASLOTR_SLOTEN   (0xFFFFU<<16)
#define SAI_ASLOTR_SLOTEN_0 (0x1U<<16)

// AIM Configuration

#define SAI_AIM_OVRUDRIE    (0x1U<<0)
#define SAI_AIM_MUTEDETIE   (0x1U<<1)
#define SAI_AIM_WCKCFGIE    (0x1U<<2)
#define SAI_AIM_FREQIE      (0x1U<<3)
#define SAI_AIM_CNRDYIE     (0x1U<<4)
#define SAI_AIM_AFSDETIE    (0x1U<<5)
#define SAI_AIM_LFSDETIE    (0x1U<<6)

// ASR Configuration

#define SAI_ASR_OVRUDR      (0x1U<<0)
#define SAI_ASR_MUTEDET     (0x1U<<1)
#define SAI_ASR_WCKCFG      (0x1U<<2)
#define SAI_ASR_FREQ        (0x1U<<3)
#define SAI_ASR_CNRDY       (0x1U<<4)
#define SAI_ASR_AFSDET      (0x1U<<5)
#define SAI_ASR_LFSDET      (0x1U<<6)
#define SAI_ASR_FLVL        (0x7U<<16)
#define SAI_ASR_FLVL_0      (0x1U<<16)

// ACLRFR Configuration

#define SAI_ACLRFR_COVRUDR  (0x1U<<0)
#define SAI_ACLRFR_CMUTEDET (0x1U<<1)
#define SAI_ACLRFR_CWCKCFG  (0x1U<<2)
#define SAI_ACLRFR_CCNRDY   (0x1U<<4)
#define SAI_ACLRFR_CAFSDET  (0x1U<<5)
#define SAI_ACLRFR_CLFSDET  (0x1U<<6)

// ADR Configuration

#define SAI_ADR_DATA        (0xFFFFFFFFU<<0)
#define SAI_ADR_DATA_0      (0x1U<<0)

// BCR1 Configuration

#define SAI_BCR1_MODE       (0x3U<<0)
#define SAI_BCR1_MODE_0     (0x1U<<0)
#define SAI_BCR1_PRTCFG     (0x3U<<2)
#define SAI_BCR1_PRTCFG_0   (0x1U<<2)
#define SAI_BCR1_DS         (0x7U<<5)
#define SAI_BCR1_DS_0       (0x1U<<5)
#define SAI_BCR1_LSBFIRST   (0x1U<<8)
#define SAI_BCR1_CKSTR      (0x1U<<9)
#define SAI_BCR1_SYNCEN     (0x3U<<10)
#define SAI_BCR1_SYNCEN_0   (0x1U<<10)
#define SAI_BCR1_MONO       (0x1U<<12)
#define SAI_BCR1_OUTDRIV    (0x1U<<13)
#define SAI_BCR1_SAIAEN     (0x1U<<16)
#define SAI_BCR1_DMAEN      (0x1U<<17)
#define SAI_BCR1_NODIV      (0x1U<<19)
#define SAI_BCR1_MCKDIV     (0x3FU<<20)
#define SAI_BCR1_MCKDIV_0   (0x1U<<20)
#define SAI_BCR1_OSR        (0x1U<<26)
#define SAI_BCR1_MCKEN      (0x1U<<27)

// BCR2 Configuration

#define SAI_BCR2_FTH        (0x7U<<0)
#define SAI_BCR2_FTH_0      (0x1U<<0)
#define SAI_BCR2_FFLUSH     (0x1U<<3)
#define SAI_BCR2_TRIS       (0x1U<<4)
#define SAI_BCR2_MUTE       (0x1U<<5)
#define SAI_BCR2_MUTEVAL    (0x1U<<6)
#define SAI_BCR2_MUTECN     (0x3FU<<7)
#define SAI_BCR2_MUTECN_0   (0x1U<<7)
#define SAI_BCR2_CPL        (0x1U<<13)
#define SAI_BCR2_COMP       (0x3U<<14)
#define SAI_BCR2_COMP_0     (0x1U<<14)

// BFRCR Configuration

#define SAI_BFRCR_FRL       (0xFFU<<0)
#define SAI_BFRCR_FRL_0     (0x1U<<0)
#define SAI_BFRCR_FSALL     (0x7FU<<8)
#define SAI_BFRCR_FSALL_0   (0x1U<<8)
#define SAI_BFRCR_FSDEF     (0x1U<<16)
#define SAI_BFRCR_FSPOL     (0x1U<<17)
#define SAI_BFRCR_FSOFF     (0x1U<<18)

// BSLOTR Configuration

#define SAI_BSLOTR_FBOFF    (0x1FU<<0)
#define SAI_BSLOTR_FBOFF_0  (0x1U<<0)
#define SAI_BSLOTR_SLOTSZ   (0x3U<<6)
#define SAI_BSLOTR_SLOTSZ_0 (0x1U<<6)
#define SAI_BSLOTR_NBSLOT   (0xFU<<8)
#define SAI_BSLOTR_NBSLOT_0 (0x1U<<8)
#define SAI_BSLOTR_SLOTEN   (0xFFFFU<<16)
#define SAI_BSLOTR_SLOTEN_0 (0x1U<<16)

// BIM Configuration

#define SAI_BIM_OVRUDRIE    (0x1U<<0)
#define SAI_BIM_MUTEDETIE   (0x1U<<1)
#define SAI_BIM_WCKCFGIE    (0x1U<<2)
#define SAI_BIM_FREQIE      (0x1U<<3)
#define SAI_BIM_CNRDYIE     (0x1U<<4)
#define SAI_BIM_AFSDETIE    (0x1U<<5)
#define SAI_BIM_LFSDETIE    (0x1U<<6)

// BSR Configuration

#define SAI_BSR_OVRUDR      (0x1U<<0)
#define SAI_BSR_MUTEDET     (0x1U<<1)
#define SAI_BSR_WCKCFG      (0x1U<<2)
#define SAI_BSR_FREQ        (0x1U<<3)
#define SAI_BSR_CNRDY       (0x1U<<4)
#define SAI_BSR_AFSDET      (0x1U<<5)
#define SAI_BSR_LFSDET      (0x1U<<6)
#define SAI_BSR_FLVL        (0x7U<<16)
#define SAI_BSR_FLVL_0      (0x1U<<16)

// BCLRFR Configuration

#define SAI_BCLRFR_COVRUDR  (0x1U<<0)
#define SAI_BCLRFR_CMUTEDET (0x1U<<1)
#define SAI_BCLRFR_CWCKCFG  (0x1U<<2)
#define SAI_BCLRFR_CCNRDY   (0x1U<<4)
#define SAI_BCLRFR_CAFSDET  (0x1U<<5)
#define SAI_BCLRFR_CLFSDET  (0x1U<<6)

// BDR Configuration

#define SAI_BDR_DATA        (0xFFFFFFFFU<<0)
#define SAI_BDR_DATA_0      (0x1U<<0)

// PDMCR Configuration

#define SAI_PDMCR_CKEN4     (0x1U<<11)
#define SAI_PDMCR_CKEN3     (0x1U<<10)
#define SAI_PDMCR_CKEN2     (0x1U<<9)
#define SAI_PDMCR_CKEN1     (0x1U<<8)
#define SAI_PDMCR_MICNBR    (0x3U<<4)
#define SAI_PDMCR_MICNBR_0  (0x1U<<4)
#define SAI_PDMCR_PDMEN     (0x1U<<0)

// PDMDLY Configuration

#define SAI_PDMDLY_DLYM4R   (0x7U<<28)
#define SAI_PDMDLY_DLYM4R_0 (0x1U<<28)
#define SAI_PDMDLY_DLYM4L   (0x7U<<24)
#define SAI_PDMDLY_DLYM4L_0 (0x1U<<24)
#define SAI_PDMDLY_DLYM3R   (0x7U<<20)
#define SAI_PDMDLY_DLYM3R_0 (0x1U<<20)
#define SAI_PDMDLY_DLYM3L   (0x7U<<16)
#define SAI_PDMDLY_DLYM3L_0 (0x1U<<16)
#define SAI_PDMDLY_DLYM2R   (0x7U<<12)
#define SAI_PDMDLY_DLYM2R_0 (0x1U<<12)
#define SAI_PDMDLY_DLYM2L   (0x7U<<8)
#define SAI_PDMDLY_DLYM2L_0 (0x1U<<8)
#define SAI_PDMDLY_DLYM1R   (0x7U<<4)
#define SAI_PDMDLY_DLYM1R_0 (0x1U<<4)
#define SAI_PDMDLY_DLYM1L   (0x7U<<0)
#define SAI_PDMDLY_DLYM1L_0 (0x1U<<0)
