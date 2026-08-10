/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_sai equates.
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
#define SAI1_NS reinterpret_cast<SAI_TypeDef *>(0x42005800U)
#define SAI1_S  reinterpret_cast<SAI_TypeDef *>(0x52005800U)
#define SAI2_NS reinterpret_cast<SAI_TypeDef *>(0x42005C00U)
#define SAI2_S  reinterpret_cast<SAI_TypeDef *>(0x52005C00U)

#else
#define SAI1_NS ((SAI_TypeDef *)0x42005800U)
#define SAI1_S  ((SAI_TypeDef *)0x52005800U)
#define SAI2_NS ((SAI_TypeDef *)0x42005C00U)
#define SAI2_S  ((SAI_TypeDef *)0x52005C00U)
#endif

// GCR Configuration

#define SAI_GCR_SYNCOUT             (0x3U<<4U)
#define SAI_GCR_SYNCOUT_0           (0x1U<<4U)
#define SAI_GCR_SYNCIN              (0x3U<<0U)
#define SAI_GCR_SYNCIN_0            (0x1U<<0U)

#define SAI_GCR_SYNCOUT_B_0X0       (0x0U<<4U)
#define SAI_GCR_SYNCOUT_B_0X1       (0x1U<<4U)
#define SAI_GCR_SYNCOUT_B_0X2       (0x2U<<4U)

// ACR1 Configuration

#define SAI_ACR1_MCKEN              (0x1U<<27U)
#define SAI_ACR1_OSR                (0x1U<<26U)
#define SAI_ACR1_MCKDIV             (0x3FU<<20U)
#define SAI_ACR1_MCKDIV_0           (0x1U<<20U)
#define SAI_ACR1_NODIV              (0x1U<<19U)
#define SAI_ACR1_DMAEN              (0x1U<<17U)
#define SAI_ACR1_SAIEN              (0x1U<<16U)
#define SAI_ACR1_OUTDRIV            (0x1U<<13U)
#define SAI_ACR1_MONO               (0x1U<<12U)
#define SAI_ACR1_SYNCEN             (0x3U<<10U)
#define SAI_ACR1_SYNCEN_0           (0x1U<<10U)
#define SAI_ACR1_CKSTR              (0x1U<<9U)
#define SAI_ACR1_LSBFIRST           (0x1U<<8U)
#define SAI_ACR1_DS                 (0x7U<<5U)
#define SAI_ACR1_DS_0               (0x1U<<5U)
#define SAI_ACR1_PRTCFG             (0x3U<<2U)
#define SAI_ACR1_PRTCFG_0           (0x1U<<2U)
#define SAI_ACR1_MODE               (0x3U<<0U)
#define SAI_ACR1_MODE_0             (0x1U<<0U)

#define SAI_ACR1_MCKEN_B_0X0        (0x0U<<27U)
#define SAI_ACR1_MCKEN_B_0X1        (0x1U<<27U)
#define SAI_ACR1_OSR_B_0X0          (0x0U<<26U)
#define SAI_ACR1_OSR_B_0X1          (0x1U<<26U)
#define SAI_ACR1_MCKDIV_B_0X0       (0x0U<<20U)
#define SAI_ACR1_NODIV_B_0X0        (0x0U<<19U)
#define SAI_ACR1_NODIV_B_0X1        (0x1U<<19U)
#define SAI_ACR1_DMAEN_B_0X0        (0x0U<<17U)
#define SAI_ACR1_DMAEN_B_0X1        (0x1U<<17U)
#define SAI_ACR1_SAIEN_B_0X0        (0x0U<<16U)
#define SAI_ACR1_SAIEN_B_0X1        (0x1U<<16U)
#define SAI_ACR1_OUTDRIV_B_0X0      (0x0U<<13U)
#define SAI_ACR1_OUTDRIV_B_0X1      (0x1U<<13U)
#define SAI_ACR1_MONO_B_0X0         (0x0U<<12U)
#define SAI_ACR1_MONO_B_0X1         (0x1U<<12U)
#define SAI_ACR1_SYNCEN_B_0X0       (0x0U<<10U)
#define SAI_ACR1_SYNCEN_B_0X1       (0x1U<<10U)
#define SAI_ACR1_SYNCEN_B_0X2       (0x2U<<10U)
#define SAI_ACR1_CKSTR_B_0X0        (0x0U<<9U)
#define SAI_ACR1_CKSTR_B_0X1        (0x1U<<9U)
#define SAI_ACR1_LSBFIRST_B_0X0     (0x0U<<8U)
#define SAI_ACR1_LSBFIRST_B_0X1     (0x1U<<8U)
#define SAI_ACR1_DS_B_0X2           (0x2U<<5U)
#define SAI_ACR1_DS_B_0X3           (0x3U<<5U)
#define SAI_ACR1_DS_B_0X4           (0x4U<<5U)
#define SAI_ACR1_DS_B_0X5           (0x5U<<5U)
#define SAI_ACR1_DS_B_0X6           (0x6U<<5U)
#define SAI_ACR1_DS_B_0X7           (0x7U<<5U)
#define SAI_ACR1_PRTCFG_B_0X0       (0x0U<<2U)
#define SAI_ACR1_PRTCFG_B_0X1       (0x1U<<2U)
#define SAI_ACR1_PRTCFG_B_0X2       (0x2U<<2U)
#define SAI_ACR1_MODE_B_0X0         (0x0U<<0U)
#define SAI_ACR1_MODE_B_0X1         (0x1U<<0U)
#define SAI_ACR1_MODE_B_0X2         (0x2U<<0U)
#define SAI_ACR1_MODE_B_0X3         (0x3U<<0U)

// ACR2 Configuration

#define SAI_ACR2_COMP               (0x3U<<14U)
#define SAI_ACR2_COMP_0             (0x1U<<14U)
#define SAI_ACR2_CPL                (0x1U<<13U)
#define SAI_ACR2_MUTECNT            (0x3FU<<7U)
#define SAI_ACR2_MUTECNT_0          (0x1U<<7U)
#define SAI_ACR2_MUTEVAL            (0x1U<<6U)
#define SAI_ACR2_MUTE               (0x1U<<5U)
#define SAI_ACR2_TRIS               (0x1U<<4U)
#define SAI_ACR2_FFLUSH             (0x1U<<3U)
#define SAI_ACR2_FTH                (0x7U<<0U)
#define SAI_ACR2_FTH_0              (0x1U<<0U)

#define SAI_ACR2_COMP_B_0X0         (0x0U<<14U)
#define SAI_ACR2_COMP_B_0X2         (0x2U<<14U)
#define SAI_ACR2_COMP_B_0X3         (0x3U<<14U)
#define SAI_ACR2_CPL_B_0X0          (0x0U<<13U)
#define SAI_ACR2_CPL_B_0X1          (0x1U<<13U)
#define SAI_ACR2_MUTEVAL_B_0X0      (0x0U<<6U)
#define SAI_ACR2_MUTEVAL_B_0X1      (0x1U<<6U)
#define SAI_ACR2_MUTE_B_0X0         (0x0U<<5U)
#define SAI_ACR2_MUTE_B_0X1         (0x1U<<5U)
#define SAI_ACR2_TRIS_B_0X0         (0x0U<<4U)
#define SAI_ACR2_TRIS_B_0X1         (0x1U<<4U)
#define SAI_ACR2_FFLUSH_B_0X0       (0x0U<<3U)
#define SAI_ACR2_FFLUSH_B_0X1       (0x1U<<3U)
#define SAI_ACR2_FTH_B_0X0          (0x0U<<0U)
#define SAI_ACR2_FTH_B_0X1          (0x1U<<0U)
#define SAI_ACR2_FTH_B_0X2          (0x2U<<0U)
#define SAI_ACR2_FTH_B_0X3          (0x3U<<0U)
#define SAI_ACR2_FTH_B_0X4          (0x4U<<0U)

// AFRCR Configuration

#define SAI_AFRCR_FSOFF             (0x1U<<18U)
#define SAI_AFRCR_FSPOL             (0x1U<<17U)
#define SAI_AFRCR_FSDEF             (0x1U<<16U)
#define SAI_AFRCR_FSALL             (0x7FU<<8U)
#define SAI_AFRCR_FSALL_0           (0x1U<<8U)
#define SAI_AFRCR_FRL               (0xFFU<<0U)
#define SAI_AFRCR_FRL_0             (0x1U<<0U)

#define SAI_AFRCR_FSOFF_B_0X0       (0x0U<<18U)
#define SAI_AFRCR_FSOFF_B_0X1       (0x1U<<18U)
#define SAI_AFRCR_FSPOL_B_0X0       (0x0U<<17U)
#define SAI_AFRCR_FSPOL_B_0X1       (0x1U<<17U)
#define SAI_AFRCR_FSDEF_B_0X0       (0x0U<<16U)
#define SAI_AFRCR_FSDEF_B_0X1       (0x1U<<16U)

// ASLOTR Configuration

#define SAI_ASLOTR_SLOTEN           (0xFFFFU<<16U)
#define SAI_ASLOTR_SLOTEN_0         (0x1U<<16U)
#define SAI_ASLOTR_NBSLOT           (0xFU<<8U)
#define SAI_ASLOTR_NBSLOT_0         (0x1U<<8U)
#define SAI_ASLOTR_SLOTSZ           (0x3U<<6U)
#define SAI_ASLOTR_SLOTSZ_0         (0x1U<<6U)
#define SAI_ASLOTR_FBOFF            (0x1FU<<0U)
#define SAI_ASLOTR_FBOFF_0          (0x1U<<0U)

#define SAI_ASLOTR_SLOTEN_B_0X0     (0x0U<<16U)
#define SAI_ASLOTR_SLOTEN_B_0X1     (0x1U<<16U)
#define SAI_ASLOTR_SLOTSZ_B_0X0     (0x0U<<6U)
#define SAI_ASLOTR_SLOTSZ_B_0X1     (0x1U<<6U)
#define SAI_ASLOTR_SLOTSZ_B_0X2     (0x2U<<6U)

// AIM Configuration

#define SAI_AIM_LFSDETIE            (0x1U<<6U)
#define SAI_AIM_AFSDETIE            (0x1U<<5U)
#define SAI_AIM_CNRDYIE             (0x1U<<4U)
#define SAI_AIM_FREQIE              (0x1U<<3U)
#define SAI_AIM_WCKCFGIE            (0x1U<<2U)
#define SAI_AIM_MUTEDETIE           (0x1U<<1U)
#define SAI_AIM_OVRUDRIE            (0x1U<<0U)

#define SAI_AIM_LFSDETIE_B_0X0      (0x0U<<6U)
#define SAI_AIM_LFSDETIE_B_0X1      (0x1U<<6U)
#define SAI_AIM_AFSDETIE_B_0X0      (0x0U<<5U)
#define SAI_AIM_AFSDETIE_B_0X1      (0x1U<<5U)
#define SAI_AIM_CNRDYIE_B_0X0       (0x0U<<4U)
#define SAI_AIM_CNRDYIE_B_0X1       (0x1U<<4U)
#define SAI_AIM_FREQIE_B_0X0        (0x0U<<3U)
#define SAI_AIM_FREQIE_B_0X1        (0x1U<<3U)
#define SAI_AIM_WCKCFGIE_B_0X0      (0x0U<<2U)
#define SAI_AIM_WCKCFGIE_B_0X1      (0x1U<<2U)
#define SAI_AIM_MUTEDETIE_B_0X0     (0x0U<<1U)
#define SAI_AIM_MUTEDETIE_B_0X1     (0x1U<<1U)
#define SAI_AIM_OVRUDRIE_B_0X0      (0x0U<<0U)
#define SAI_AIM_OVRUDRIE_B_0X1      (0x1U<<0U)

// ASR Configuration

#define SAI_ASR_FLVL                (0x7U<<16U)
#define SAI_ASR_FLVL_0              (0x1U<<16U)
#define SAI_ASR_LFSDET              (0x1U<<6U)
#define SAI_ASR_AFSDET              (0x1U<<5U)
#define SAI_ASR_CNRDY               (0x1U<<4U)
#define SAI_ASR_FREQ                (0x1U<<3U)
#define SAI_ASR_WCKCFG              (0x1U<<2U)
#define SAI_ASR_MUTEDET             (0x1U<<1U)
#define SAI_ASR_OVRUDR              (0x1U<<0U)

#define SAI_ASR_FLVL_B_0X0          (0x0U<<16U)
#define SAI_ASR_FLVL_B_0X1          (0x1U<<16U)
#define SAI_ASR_FLVL_B_0X2          (0x2U<<16U)
#define SAI_ASR_FLVL_B_0X3          (0x3U<<16U)
#define SAI_ASR_FLVL_B_0X4          (0x4U<<16U)
#define SAI_ASR_FLVL_B_0X5          (0x5U<<16U)
#define SAI_ASR_LFSDET_B_0X0        (0x0U<<6U)
#define SAI_ASR_LFSDET_B_0X1        (0x1U<<6U)
#define SAI_ASR_AFSDET_B_0X0        (0x0U<<5U)
#define SAI_ASR_AFSDET_B_0X1        (0x1U<<5U)
#define SAI_ASR_CNRDY_B_0X0         (0x0U<<4U)
#define SAI_ASR_CNRDY_B_0X1         (0x1U<<4U)
#define SAI_ASR_FREQ_B_0X0          (0x0U<<3U)
#define SAI_ASR_FREQ_B_0X1          (0x1U<<3U)
#define SAI_ASR_WCKCFG_B_0X0        (0x0U<<2U)
#define SAI_ASR_WCKCFG_B_0X1        (0x1U<<2U)
#define SAI_ASR_MUTEDET_B_0X0       (0x0U<<1U)
#define SAI_ASR_MUTEDET_B_0X1       (0x1U<<1U)
#define SAI_ASR_OVRUDR_B_0X0        (0x0U<<0U)
#define SAI_ASR_OVRUDR_B_0X1        (0x1U<<0U)

// ACLRFR Configuration

#define SAI_ACLRFR_CLFSDET          (0x1U<<6U)
#define SAI_ACLRFR_CAFSDET          (0x1U<<5U)
#define SAI_ACLRFR_CCNRDY           (0x1U<<4U)
#define SAI_ACLRFR_CWCKCFG          (0x1U<<2U)
#define SAI_ACLRFR_CMUTEDET         (0x1U<<1U)
#define SAI_ACLRFR_COVRUDR          (0x1U<<0U)

// ADR Configuration

#define SAI_ADR_DATA                (0xFFFFFFFFU<<0U)
#define SAI_ADR_DATA_0              (0x1U<<0U)

// BCR1 Configuration

#define SAI_BCR1_MCKEN              (0x1U<<27U)
#define SAI_BCR1_OSR                (0x1U<<26U)
#define SAI_BCR1_MCKDIV             (0x3FU<<20U)
#define SAI_BCR1_MCKDIV_0           (0x1U<<20U)
#define SAI_BCR1_NODIV              (0x1U<<19U)
#define SAI_BCR1_DMAEN              (0x1U<<17U)
#define SAI_BCR1_SAIEN              (0x1U<<16U)
#define SAI_BCR1_OUTDRIV            (0x1U<<13U)
#define SAI_BCR1_MONO               (0x1U<<12U)
#define SAI_BCR1_SYNCEN             (0x3U<<10U)
#define SAI_BCR1_SYNCEN_0           (0x1U<<10U)
#define SAI_BCR1_CKSTR              (0x1U<<9U)
#define SAI_BCR1_LSBFIRST           (0x1U<<8U)
#define SAI_BCR1_DS                 (0x7U<<5U)
#define SAI_BCR1_DS_0               (0x1U<<5U)
#define SAI_BCR1_PRTCFG             (0x3U<<2U)
#define SAI_BCR1_PRTCFG_0           (0x1U<<2U)
#define SAI_BCR1_MODE               (0x3U<<0U)
#define SAI_BCR1_MODE_0             (0x1U<<0U)

#define SAI_BCR1_MCKEN_B_0X0        (0x0U<<27U)
#define SAI_BCR1_MCKEN_B_0X1        (0x1U<<27U)
#define SAI_BCR1_OSR_B_0X0          (0x0U<<26U)
#define SAI_BCR1_OSR_B_0X1          (0x1U<<26U)
#define SAI_BCR1_MCKDIV_B_0X0       (0x0U<<20U)
#define SAI_BCR1_NODIV_B_0X0        (0x0U<<19U)
#define SAI_BCR1_NODIV_B_0X1        (0x1U<<19U)
#define SAI_BCR1_DMAEN_B_0X0        (0x0U<<17U)
#define SAI_BCR1_DMAEN_B_0X1        (0x1U<<17U)
#define SAI_BCR1_SAIEN_B_0X0        (0x0U<<16U)
#define SAI_BCR1_SAIEN_B_0X1        (0x1U<<16U)
#define SAI_BCR1_OUTDRIV_B_0X0      (0x0U<<13U)
#define SAI_BCR1_OUTDRIV_B_0X1      (0x1U<<13U)
#define SAI_BCR1_MONO_B_0X0         (0x0U<<12U)
#define SAI_BCR1_MONO_B_0X1         (0x1U<<12U)
#define SAI_BCR1_SYNCEN_B_0X0       (0x0U<<10U)
#define SAI_BCR1_SYNCEN_B_0X1       (0x1U<<10U)
#define SAI_BCR1_SYNCEN_B_0X2       (0x2U<<10U)
#define SAI_BCR1_CKSTR_B_0X0        (0x0U<<9U)
#define SAI_BCR1_CKSTR_B_0X1        (0x1U<<9U)
#define SAI_BCR1_LSBFIRST_B_0X0     (0x0U<<8U)
#define SAI_BCR1_LSBFIRST_B_0X1     (0x1U<<8U)
#define SAI_BCR1_DS_B_0X2           (0x2U<<5U)
#define SAI_BCR1_DS_B_0X3           (0x3U<<5U)
#define SAI_BCR1_DS_B_0X4           (0x4U<<5U)
#define SAI_BCR1_DS_B_0X5           (0x5U<<5U)
#define SAI_BCR1_DS_B_0X6           (0x6U<<5U)
#define SAI_BCR1_DS_B_0X7           (0x7U<<5U)
#define SAI_BCR1_PRTCFG_B_0X0       (0x0U<<2U)
#define SAI_BCR1_PRTCFG_B_0X1       (0x1U<<2U)
#define SAI_BCR1_PRTCFG_B_0X2       (0x2U<<2U)
#define SAI_BCR1_MODE_B_0X0         (0x0U<<0U)
#define SAI_BCR1_MODE_B_0X1         (0x1U<<0U)
#define SAI_BCR1_MODE_B_0X2         (0x2U<<0U)
#define SAI_BCR1_MODE_B_0X3         (0x3U<<0U)

// BCR2 Configuration

#define SAI_BCR2_COMP               (0x3U<<14U)
#define SAI_BCR2_COMP_0             (0x1U<<14U)
#define SAI_BCR2_CPL                (0x1U<<13U)
#define SAI_BCR2_MUTECNT            (0x3FU<<7U)
#define SAI_BCR2_MUTECNT_0          (0x1U<<7U)
#define SAI_BCR2_MUTEVAL            (0x1U<<6U)
#define SAI_BCR2_MUTE               (0x1U<<5U)
#define SAI_BCR2_TRIS               (0x1U<<4U)
#define SAI_BCR2_FFLUSH             (0x1U<<3U)
#define SAI_BCR2_FTH                (0x7U<<0U)
#define SAI_BCR2_FTH_0              (0x1U<<0U)

#define SAI_BCR2_COMP_B_0X0         (0x0U<<14U)
#define SAI_BCR2_COMP_B_0X2         (0x2U<<14U)
#define SAI_BCR2_COMP_B_0X3         (0x3U<<14U)
#define SAI_BCR2_CPL_B_0X0          (0x0U<<13U)
#define SAI_BCR2_CPL_B_0X1          (0x1U<<13U)
#define SAI_BCR2_MUTEVAL_B_0X0      (0x0U<<6U)
#define SAI_BCR2_MUTEVAL_B_0X1      (0x1U<<6U)
#define SAI_BCR2_MUTE_B_0X0         (0x0U<<5U)
#define SAI_BCR2_MUTE_B_0X1         (0x1U<<5U)
#define SAI_BCR2_TRIS_B_0X0         (0x0U<<4U)
#define SAI_BCR2_TRIS_B_0X1         (0x1U<<4U)
#define SAI_BCR2_FFLUSH_B_0X0       (0x0U<<3U)
#define SAI_BCR2_FFLUSH_B_0X1       (0x1U<<3U)
#define SAI_BCR2_FTH_B_0X0          (0x0U<<0U)
#define SAI_BCR2_FTH_B_0X1          (0x1U<<0U)
#define SAI_BCR2_FTH_B_0X2          (0x2U<<0U)
#define SAI_BCR2_FTH_B_0X3          (0x3U<<0U)
#define SAI_BCR2_FTH_B_0X4          (0x4U<<0U)

// BFRCR Configuration

#define SAI_BFRCR_FSOFF             (0x1U<<18U)
#define SAI_BFRCR_FSPOL             (0x1U<<17U)
#define SAI_BFRCR_FSDEF             (0x1U<<16U)
#define SAI_BFRCR_FSALL             (0x7FU<<8U)
#define SAI_BFRCR_FSALL_0           (0x1U<<8U)
#define SAI_BFRCR_FRL               (0xFFU<<0U)
#define SAI_BFRCR_FRL_0             (0x1U<<0U)

#define SAI_BFRCR_FSOFF_B_0X0       (0x0U<<18U)
#define SAI_BFRCR_FSOFF_B_0X1       (0x1U<<18U)
#define SAI_BFRCR_FSPOL_B_0X0       (0x0U<<17U)
#define SAI_BFRCR_FSPOL_B_0X1       (0x1U<<17U)
#define SAI_BFRCR_FSDEF_B_0X0       (0x0U<<16U)
#define SAI_BFRCR_FSDEF_B_0X1       (0x1U<<16U)

// BSLOTR Configuration

#define SAI_BSLOTR_SLOTEN           (0xFFFFU<<16U)
#define SAI_BSLOTR_SLOTEN_0         (0x1U<<16U)
#define SAI_BSLOTR_NBSLOT           (0xFU<<8U)
#define SAI_BSLOTR_NBSLOT_0         (0x1U<<8U)
#define SAI_BSLOTR_SLOTSZ           (0x3U<<6U)
#define SAI_BSLOTR_SLOTSZ_0         (0x1U<<6U)
#define SAI_BSLOTR_FBOFF            (0x1FU<<0U)
#define SAI_BSLOTR_FBOFF_0          (0x1U<<0U)

#define SAI_BSLOTR_SLOTEN_B_0X0     (0x0U<<16U)
#define SAI_BSLOTR_SLOTEN_B_0X1     (0x1U<<16U)
#define SAI_BSLOTR_SLOTSZ_B_0X0     (0x0U<<6U)
#define SAI_BSLOTR_SLOTSZ_B_0X1     (0x1U<<6U)
#define SAI_BSLOTR_SLOTSZ_B_0X2     (0x2U<<6U)

// BIM Configuration

#define SAI_BIM_LFSDETIE            (0x1U<<6U)
#define SAI_BIM_AFSDETIE            (0x1U<<5U)
#define SAI_BIM_CNRDYIE             (0x1U<<4U)
#define SAI_BIM_FREQIE              (0x1U<<3U)
#define SAI_BIM_WCKCFGIE            (0x1U<<2U)
#define SAI_BIM_MUTEDETIE           (0x1U<<1U)
#define SAI_BIM_OVRUDRIE            (0x1U<<0U)

#define SAI_BIM_LFSDETIE_B_0X0      (0x0U<<6U)
#define SAI_BIM_LFSDETIE_B_0X1      (0x1U<<6U)
#define SAI_BIM_AFSDETIE_B_0X0      (0x0U<<5U)
#define SAI_BIM_AFSDETIE_B_0X1      (0x1U<<5U)
#define SAI_BIM_CNRDYIE_B_0X0       (0x0U<<4U)
#define SAI_BIM_CNRDYIE_B_0X1       (0x1U<<4U)
#define SAI_BIM_FREQIE_B_0X0        (0x0U<<3U)
#define SAI_BIM_FREQIE_B_0X1        (0x1U<<3U)
#define SAI_BIM_WCKCFGIE_B_0X0      (0x0U<<2U)
#define SAI_BIM_WCKCFGIE_B_0X1      (0x1U<<2U)
#define SAI_BIM_MUTEDETIE_B_0X0     (0x0U<<1U)
#define SAI_BIM_MUTEDETIE_B_0X1     (0x1U<<1U)
#define SAI_BIM_OVRUDRIE_B_0X0      (0x0U<<0U)
#define SAI_BIM_OVRUDRIE_B_0X1      (0x1U<<0U)

// BSR Configuration

#define SAI_BSR_FLVL                (0x7U<<16U)
#define SAI_BSR_FLVL_0              (0x1U<<16U)
#define SAI_BSR_LFSDET              (0x1U<<6U)
#define SAI_BSR_AFSDET              (0x1U<<5U)
#define SAI_BSR_CNRDY               (0x1U<<4U)
#define SAI_BSR_FREQ                (0x1U<<3U)
#define SAI_BSR_WCKCFG              (0x1U<<2U)
#define SAI_BSR_MUTEDET             (0x1U<<1U)
#define SAI_BSR_OVRUDR              (0x1U<<0U)

#define SAI_BSR_FLVL_B_0X0          (0x0U<<16U)
#define SAI_BSR_FLVL_B_0X1          (0x1U<<16U)
#define SAI_BSR_FLVL_B_0X2          (0x2U<<16U)
#define SAI_BSR_FLVL_B_0X3          (0x3U<<16U)
#define SAI_BSR_FLVL_B_0X4          (0x4U<<16U)
#define SAI_BSR_FLVL_B_0X5          (0x5U<<16U)
#define SAI_BSR_LFSDET_B_0X0        (0x0U<<6U)
#define SAI_BSR_LFSDET_B_0X1        (0x1U<<6U)
#define SAI_BSR_AFSDET_B_0X0        (0x0U<<5U)
#define SAI_BSR_AFSDET_B_0X1        (0x1U<<5U)
#define SAI_BSR_CNRDY_B_0X0         (0x0U<<4U)
#define SAI_BSR_CNRDY_B_0X1         (0x1U<<4U)
#define SAI_BSR_FREQ_B_0X0          (0x0U<<3U)
#define SAI_BSR_FREQ_B_0X1          (0x1U<<3U)
#define SAI_BSR_WCKCFG_B_0X0        (0x0U<<2U)
#define SAI_BSR_WCKCFG_B_0X1        (0x1U<<2U)
#define SAI_BSR_MUTEDET_B_0X0       (0x0U<<1U)
#define SAI_BSR_MUTEDET_B_0X1       (0x1U<<1U)
#define SAI_BSR_OVRUDR_B_0X0        (0x0U<<0U)
#define SAI_BSR_OVRUDR_B_0X1        (0x1U<<0U)

// BCLRFR Configuration

#define SAI_BCLRFR_CLFSDET          (0x1U<<6U)
#define SAI_BCLRFR_CAFSDET          (0x1U<<5U)
#define SAI_BCLRFR_CCNRDY           (0x1U<<4U)
#define SAI_BCLRFR_CWCKCFG          (0x1U<<2U)
#define SAI_BCLRFR_CMUTEDET         (0x1U<<1U)
#define SAI_BCLRFR_COVRUDR          (0x1U<<0U)

// BDR Configuration

#define SAI_BDR_DATA                (0xFFFFFFFFU<<0U)
#define SAI_BDR_DATA_0              (0x1U<<0U)

// PDMCR Configuration

#define SAI_PDMCR_CKEN2             (0x1U<<9U)
#define SAI_PDMCR_CKEN1             (0x1U<<8U)
#define SAI_PDMCR_MICNBR            (0x3U<<4U)
#define SAI_PDMCR_MICNBR_0          (0x1U<<4U)
#define SAI_PDMCR_PDMEN             (0x1U<<0U)

#define SAI_PDMCR_CKEN2_B_0X0       (0x0U<<9U)
#define SAI_PDMCR_CKEN2_B_0X1       (0x1U<<9U)
#define SAI_PDMCR_CKEN1_B_0X0       (0x0U<<8U)
#define SAI_PDMCR_CKEN1_B_0X1       (0x1U<<8U)
#define SAI_PDMCR_MICNBR_B_0X0      (0x0U<<4U)
#define SAI_PDMCR_MICNBR_B_0X1      (0x1U<<4U)
#define SAI_PDMCR_MICNBR_B_0X2      (0x2U<<4U)
#define SAI_PDMCR_MICNBR_B_0X3      (0x3U<<4U)
#define SAI_PDMCR_PDMEN_B_0X0       (0x0U<<0U)
#define SAI_PDMCR_PDMEN_B_0X1       (0x1U<<0U)

// PDMDLY Configuration

#define SAI_PDMDLY_DLYM4R           (0x7U<<28U)
#define SAI_PDMDLY_DLYM4R_0         (0x1U<<28U)
#define SAI_PDMDLY_DLYM4L           (0x7U<<24U)
#define SAI_PDMDLY_DLYM4L_0         (0x1U<<24U)
#define SAI_PDMDLY_DLYM3R           (0x7U<<20U)
#define SAI_PDMDLY_DLYM3R_0         (0x1U<<20U)
#define SAI_PDMDLY_DLYM3L           (0x7U<<16U)
#define SAI_PDMDLY_DLYM3L_0         (0x1U<<16U)
#define SAI_PDMDLY_DLYM2R           (0x7U<<12U)
#define SAI_PDMDLY_DLYM2R_0         (0x1U<<12U)
#define SAI_PDMDLY_DLYM2L           (0x7U<<8U)
#define SAI_PDMDLY_DLYM2L_0         (0x1U<<8U)
#define SAI_PDMDLY_DLYM1R           (0x7U<<4U)
#define SAI_PDMDLY_DLYM1R_0         (0x1U<<4U)
#define SAI_PDMDLY_DLYM1L           (0x7U<<0U)
#define SAI_PDMDLY_DLYM1L_0         (0x1U<<0U)

#define SAI_PDMDLY_DLYM4R_B_0X0     (0x0U<<28U)
#define SAI_PDMDLY_DLYM4R_B_0X1     (0x1U<<28U)
#define SAI_PDMDLY_DLYM4R_B_0X2     (0x2U<<28U)
#define SAI_PDMDLY_DLYM4R_B_0X7     (0x7U<<28U)
#define SAI_PDMDLY_DLYM4L_B_0X0     (0x0U<<24U)
#define SAI_PDMDLY_DLYM4L_B_0X1     (0x1U<<24U)
#define SAI_PDMDLY_DLYM4L_B_0X2     (0x2U<<24U)
#define SAI_PDMDLY_DLYM4L_B_0X7     (0x7U<<24U)
#define SAI_PDMDLY_DLYM3R_B_0X0     (0x0U<<20U)
#define SAI_PDMDLY_DLYM3R_B_0X1     (0x1U<<20U)
#define SAI_PDMDLY_DLYM3R_B_0X2     (0x2U<<20U)
#define SAI_PDMDLY_DLYM3R_B_0X7     (0x7U<<20U)
#define SAI_PDMDLY_DLYM3L_B_0X0     (0x0U<<16U)
#define SAI_PDMDLY_DLYM3L_B_0X1     (0x1U<<16U)
#define SAI_PDMDLY_DLYM3L_B_0X2     (0x2U<<16U)
#define SAI_PDMDLY_DLYM3L_B_0X7     (0x7U<<16U)
#define SAI_PDMDLY_DLYM2R_B_0X0     (0x0U<<12U)
#define SAI_PDMDLY_DLYM2R_B_0X1     (0x1U<<12U)
#define SAI_PDMDLY_DLYM2R_B_0X2     (0x2U<<12U)
#define SAI_PDMDLY_DLYM2R_B_0X7     (0x7U<<12U)
#define SAI_PDMDLY_DLYM2L_B_0X0     (0x0U<<8U)
#define SAI_PDMDLY_DLYM2L_B_0X1     (0x1U<<8U)
#define SAI_PDMDLY_DLYM2L_B_0X2     (0x2U<<8U)
#define SAI_PDMDLY_DLYM2L_B_0X7     (0x7U<<8U)
#define SAI_PDMDLY_DLYM1R_B_0X0     (0x0U<<4U)
#define SAI_PDMDLY_DLYM1R_B_0X1     (0x1U<<4U)
#define SAI_PDMDLY_DLYM1R_B_0X2     (0x2U<<4U)
#define SAI_PDMDLY_DLYM1R_B_0X7     (0x7U<<4U)
#define SAI_PDMDLY_DLYM1L_B_0X0     (0x0U<<0U)
#define SAI_PDMDLY_DLYM1L_B_0X1     (0x1U<<0U)
#define SAI_PDMDLY_DLYM1L_B_0X2     (0x2U<<0U)
#define SAI_PDMDLY_DLYM1L_B_0X7     (0x7U<<0U)
