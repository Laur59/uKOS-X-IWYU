/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_sai equates.
 */

#pragma once

#include    <stdint.h>

// SAI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0;
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
} SAI_TypeDef;

#ifdef __cplusplus
#define SAI1    reinterpret_cast<SAI_TypeDef *>(0x40015400U)
#define SAI2    reinterpret_cast<SAI_TypeDef *>(0x40015800U)

#else
#define SAI1    ((SAI_TypeDef *)0x40015400U)
#define SAI2    ((SAI_TypeDef *)0x40015800U)
#endif

// ACR1 Configuration

#define SAI_ACR1_MODE       (0x3U<<0U)
#define SAI_ACR1_MODE_0     (0x1U<<0U)
#define SAI_ACR1_PRTCFG     (0x3U<<2U)
#define SAI_ACR1_PRTCFG_0   (0x1U<<2U)
#define SAI_ACR1_DS         (0x7U<<5U)
#define SAI_ACR1_DS_0       (0x1U<<5U)
#define SAI_ACR1_LSBFIRST   (0x1U<<8U)
#define SAI_ACR1_CKSTR      (0x1U<<9U)
#define SAI_ACR1_SYNCEN     (0x3U<<10U)
#define SAI_ACR1_SYNCEN_0   (0x1U<<10U)
#define SAI_ACR1_MONO       (0x1U<<12U)
#define SAI_ACR1_OUTDRI     (0x1U<<13U)
#define SAI_ACR1_SAIAEN     (0x1U<<16U)
#define SAI_ACR1_DMAEN      (0x1U<<17U)
#define SAI_ACR1_NODIV      (0x1U<<19U)
#define SAI_ACR1_MCJDIV     (0xFU<<20U)
#define SAI_ACR1_MCJDIV_0   (0x1U<<20U)

// ACR2 Configuration

#define SAI_ACR2_FTH        (0x7U<<0U)
#define SAI_ACR2_FTH_0      (0x1U<<0U)
#define SAI_ACR2_FFLUS      (0x1U<<3U)
#define SAI_ACR2_TRIS       (0x1U<<4U)
#define SAI_ACR2_MUTE       (0x1U<<5U)
#define SAI_ACR2_MUTEVAL    (0x1U<<6U)
#define SAI_ACR2_MUTECN     (0x3FU<<7U)
#define SAI_ACR2_MUTECN_0   (0x1U<<7U)
#define SAI_ACR2_CPL        (0x1U<<13U)
#define SAI_ACR2_COMP       (0x3U<<14U)
#define SAI_ACR2_COMP_0     (0x1U<<14U)

// AFRCR Configuration

#define SAI_AFRCR_FRL       (0xFFU<<0U)
#define SAI_AFRCR_FRL_0     (0x1U<<0U)
#define SAI_AFRCR_FSALL     (0x7FU<<8U)
#define SAI_AFRCR_FSALL_0   (0x1U<<8U)
#define SAI_AFRCR_FSDEF     (0x1U<<16U)
#define SAI_AFRCR_FSPOL     (0x1U<<17U)
#define SAI_AFRCR_FSOFF     (0x1U<<18U)

// ASLOTR Configuration

#define SAI_ASLOTR_FBOFF    (0x1FU<<0U)
#define SAI_ASLOTR_FBOFF_0  (0x1U<<0U)
#define SAI_ASLOTR_SLOTSZ   (0x3U<<6U)
#define SAI_ASLOTR_SLOTSZ_0 (0x1U<<6U)
#define SAI_ASLOTR_NBSLOT   (0xFU<<8U)
#define SAI_ASLOTR_NBSLOT_0 (0x1U<<8U)
#define SAI_ASLOTR_SLOTEN   (0xFFFFU<<16U)
#define SAI_ASLOTR_SLOTEN_0 (0x1U<<16U)

// AIM Configuration

#define SAI_AIM_OVRUDRIE    (0x1U<<0U)
#define SAI_AIM_MUTEDET     (0x1U<<1U)
#define SAI_AIM_WCKCFG      (0x1U<<2U)
#define SAI_AIM_FREQIE      (0x1U<<3U)
#define SAI_AIM_CNRDYIE     (0x1U<<4U)
#define SAI_AIM_AFSDETIE    (0x1U<<5U)
#define SAI_AIM_LFSDET      (0x1U<<6U)

// ASR Configuration

#define SAI_ASR_OVRUDR      (0x1U<<0U)
#define SAI_ASR_MUTEDET     (0x1U<<1U)
#define SAI_ASR_WCKCFG      (0x1U<<2U)
#define SAI_ASR_FREQ        (0x1U<<3U)
#define SAI_ASR_CNRDY       (0x1U<<4U)
#define SAI_ASR_AFSDET      (0x1U<<5U)
#define SAI_ASR_LFSDET      (0x1U<<6U)
#define SAI_ASR_FLVL        (0x7U<<16U)
#define SAI_ASR_FLVL_0      (0x1U<<16U)

// ACLRFR Configuration

#define SAI_ACLRFR_OVRUDR   (0x1U<<0U)
#define SAI_ACLRFR_MUTEDET  (0x1U<<1U)
#define SAI_ACLRFR_WCKCFG   (0x1U<<2U)
#define SAI_ACLRFR_CNRDY    (0x1U<<4U)
#define SAI_ACLRFR_CAFSDET  (0x1U<<5U)
#define SAI_ACLRFR_LFSDET   (0x1U<<6U)

// ADR Configuration

#define SAI_ADR_DATA        (0xFFFFFFFFU<<0U)
#define SAI_ADR_DATA_0      (0x1U<<0U)

// BCR1 Configuration

#define SAI_BCR1_MODE       (0x3U<<0U)
#define SAI_BCR1_MODE_0     (0x1U<<0U)
#define SAI_BCR1_PRTCFG     (0x3U<<2U)
#define SAI_BCR1_PRTCFG_0   (0x1U<<2U)
#define SAI_BCR1_DS         (0x7U<<5U)
#define SAI_BCR1_DS_0       (0x1U<<5U)
#define SAI_BCR1_LSBFIRST   (0x1U<<8U)
#define SAI_BCR1_CKSTR      (0x1U<<9U)
#define SAI_BCR1_SYNCEN     (0x3U<<10U)
#define SAI_BCR1_SYNCEN_0   (0x1U<<10U)
#define SAI_BCR1_MONO       (0x1U<<12U)
#define SAI_BCR1_OUTDRI     (0x1U<<13U)
#define SAI_BCR1_SAIBEN     (0x1U<<16U)
#define SAI_BCR1_DMAEN      (0x1U<<17U)
#define SAI_BCR1_NODIV      (0x1U<<19U)
#define SAI_BCR1_MCJDIV     (0xFU<<20U)
#define SAI_BCR1_MCJDIV_0   (0x1U<<20U)

// BCR2 Configuration

#define SAI_BCR2_FTH        (0x7U<<0U)
#define SAI_BCR2_FTH_0      (0x1U<<0U)
#define SAI_BCR2_FFLUS      (0x1U<<3U)
#define SAI_BCR2_TRIS       (0x1U<<4U)
#define SAI_BCR2_MUTE       (0x1U<<5U)
#define SAI_BCR2_MUTEVAL    (0x1U<<6U)
#define SAI_BCR2_MUTECN     (0x3FU<<7U)
#define SAI_BCR2_MUTECN_0   (0x1U<<7U)
#define SAI_BCR2_CPL        (0x1U<<13U)
#define SAI_BCR2_COMP       (0x3U<<14U)
#define SAI_BCR2_COMP_0     (0x1U<<14U)

// BFRCR Configuration

#define SAI_BFRCR_FRL       (0xFFU<<0U)
#define SAI_BFRCR_FRL_0     (0x1U<<0U)
#define SAI_BFRCR_FSALL     (0x7FU<<8U)
#define SAI_BFRCR_FSALL_0   (0x1U<<8U)
#define SAI_BFRCR_FSDEF     (0x1U<<16U)
#define SAI_BFRCR_FSPOL     (0x1U<<17U)
#define SAI_BFRCR_FSOFF     (0x1U<<18U)

// BSLOTR Configuration

#define SAI_BSLOTR_FBOFF    (0x1FU<<0U)
#define SAI_BSLOTR_FBOFF_0  (0x1U<<0U)
#define SAI_BSLOTR_SLOTSZ   (0x3U<<6U)
#define SAI_BSLOTR_SLOTSZ_0 (0x1U<<6U)
#define SAI_BSLOTR_NBSLOT   (0xFU<<8U)
#define SAI_BSLOTR_NBSLOT_0 (0x1U<<8U)
#define SAI_BSLOTR_SLOTEN   (0xFFFFU<<16U)
#define SAI_BSLOTR_SLOTEN_0 (0x1U<<16U)

// BIM Configuration

#define SAI_BIM_OVRUDRIE    (0x1U<<0U)
#define SAI_BIM_MUTEDET     (0x1U<<1U)
#define SAI_BIM_WCKCFG      (0x1U<<2U)
#define SAI_BIM_FREQIE      (0x1U<<3U)
#define SAI_BIM_CNRDYIE     (0x1U<<4U)
#define SAI_BIM_AFSDETIE    (0x1U<<5U)
#define SAI_BIM_LFSDETIE    (0x1U<<6U)

// BSR Configuration

#define SAI_BSR_OVRUDR      (0x1U<<0U)
#define SAI_BSR_MUTEDET     (0x1U<<1U)
#define SAI_BSR_WCKCFG      (0x1U<<2U)
#define SAI_BSR_FREQ        (0x1U<<3U)
#define SAI_BSR_CNRDY       (0x1U<<4U)
#define SAI_BSR_AFSDET      (0x1U<<5U)
#define SAI_BSR_LFSDET      (0x1U<<6U)
#define SAI_BSR_FLVL        (0x7U<<16U)
#define SAI_BSR_FLVL_0      (0x1U<<16U)

// BCLRFR Configuration

#define SAI_BCLRFR_OVRUDR   (0x1U<<0U)
#define SAI_BCLRFR_MUTEDET  (0x1U<<1U)
#define SAI_BCLRFR_WCKCFG   (0x1U<<2U)
#define SAI_BCLRFR_CNRDY    (0x1U<<4U)
#define SAI_BCLRFR_CAFSDET  (0x1U<<5U)
#define SAI_BCLRFR_LFSDET   (0x1U<<6U)

// BDR Configuration

#define SAI_BDR_DATA        (0xFFFFFFFFU<<0U)
#define SAI_BDR_DATA_0      (0x1U<<0U)
