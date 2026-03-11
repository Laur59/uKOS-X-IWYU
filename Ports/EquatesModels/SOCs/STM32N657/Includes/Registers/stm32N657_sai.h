/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_sai.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_sai equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
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

#define SAI_GCR_SYNCOUT             (0x3U<<4)
#define SAI_GCR_SYNCOUT_0           (0x1U<<4)
#define SAI_GCR_SYNCIN              (0x3U<<0)
#define SAI_GCR_SYNCIN_0            (0x1U<<0)

#define SAI_GCR_SYNCOUT_B_0X0       (0x0U<<4)
#define SAI_GCR_SYNCOUT_B_0X1       (0x1U<<4)
#define SAI_GCR_SYNCOUT_B_0X2       (0x2U<<4)

// ACR1 Configuration

#define SAI_ACR1_MCKEN              (0x1U<<27)
#define SAI_ACR1_OSR                (0x1U<<26)
#define SAI_ACR1_MCKDIV             (0x3FU<<20)
#define SAI_ACR1_MCKDIV_0           (0x1U<<20)
#define SAI_ACR1_NODIV              (0x1U<<19)
#define SAI_ACR1_DMAEN              (0x1U<<17)
#define SAI_ACR1_SAIEN              (0x1U<<16)
#define SAI_ACR1_OUTDRIV            (0x1U<<13)
#define SAI_ACR1_MONO               (0x1U<<12)
#define SAI_ACR1_SYNCEN             (0x3U<<10)
#define SAI_ACR1_SYNCEN_0           (0x1U<<10)
#define SAI_ACR1_CKSTR              (0x1U<<9)
#define SAI_ACR1_LSBFIRST           (0x1U<<8)
#define SAI_ACR1_DS                 (0x7U<<5)
#define SAI_ACR1_DS_0               (0x1U<<5)
#define SAI_ACR1_PRTCFG             (0x3U<<2)
#define SAI_ACR1_PRTCFG_0           (0x1U<<2)
#define SAI_ACR1_MODE               (0x3U<<0)
#define SAI_ACR1_MODE_0             (0x1U<<0)

#define SAI_ACR1_MCKEN_B_0X0        (0x0U<<27)
#define SAI_ACR1_MCKEN_B_0X1        (0x1U<<27)
#define SAI_ACR1_OSR_B_0X0          (0x0U<<26)
#define SAI_ACR1_OSR_B_0X1          (0x1U<<26)
#define SAI_ACR1_MCKDIV_B_0X0       (0x0U<<20)
#define SAI_ACR1_NODIV_B_0X0        (0x0U<<19)
#define SAI_ACR1_NODIV_B_0X1        (0x1U<<19)
#define SAI_ACR1_DMAEN_B_0X0        (0x0U<<17)
#define SAI_ACR1_DMAEN_B_0X1        (0x1U<<17)
#define SAI_ACR1_SAIEN_B_0X0        (0x0U<<16)
#define SAI_ACR1_SAIEN_B_0X1        (0x1U<<16)
#define SAI_ACR1_OUTDRIV_B_0X0      (0x0U<<13)
#define SAI_ACR1_OUTDRIV_B_0X1      (0x1U<<13)
#define SAI_ACR1_MONO_B_0X0         (0x0U<<12)
#define SAI_ACR1_MONO_B_0X1         (0x1U<<12)
#define SAI_ACR1_SYNCEN_B_0X0       (0x0U<<10)
#define SAI_ACR1_SYNCEN_B_0X1       (0x1U<<10)
#define SAI_ACR1_SYNCEN_B_0X2       (0x2U<<10)
#define SAI_ACR1_CKSTR_B_0X0        (0x0U<<9)
#define SAI_ACR1_CKSTR_B_0X1        (0x1U<<9)
#define SAI_ACR1_LSBFIRST_B_0X0     (0x0U<<8)
#define SAI_ACR1_LSBFIRST_B_0X1     (0x1U<<8)
#define SAI_ACR1_DS_B_0X2           (0x2U<<5)
#define SAI_ACR1_DS_B_0X3           (0x3U<<5)
#define SAI_ACR1_DS_B_0X4           (0x4U<<5)
#define SAI_ACR1_DS_B_0X5           (0x5U<<5)
#define SAI_ACR1_DS_B_0X6           (0x6U<<5)
#define SAI_ACR1_DS_B_0X7           (0x7U<<5)
#define SAI_ACR1_PRTCFG_B_0X0       (0x0U<<2)
#define SAI_ACR1_PRTCFG_B_0X1       (0x1U<<2)
#define SAI_ACR1_PRTCFG_B_0X2       (0x2U<<2)
#define SAI_ACR1_MODE_B_0X0         (0x0U<<0)
#define SAI_ACR1_MODE_B_0X1         (0x1U<<0)
#define SAI_ACR1_MODE_B_0X2         (0x2U<<0)
#define SAI_ACR1_MODE_B_0X3         (0x3U<<0)

// ACR2 Configuration

#define SAI_ACR2_COMP               (0x3U<<14)
#define SAI_ACR2_COMP_0             (0x1U<<14)
#define SAI_ACR2_CPL                (0x1U<<13)
#define SAI_ACR2_MUTECNT            (0x3FU<<7)
#define SAI_ACR2_MUTECNT_0          (0x1U<<7)
#define SAI_ACR2_MUTEVAL            (0x1U<<6)
#define SAI_ACR2_MUTE               (0x1U<<5)
#define SAI_ACR2_TRIS               (0x1U<<4)
#define SAI_ACR2_FFLUSH             (0x1U<<3)
#define SAI_ACR2_FTH                (0x7U<<0)
#define SAI_ACR2_FTH_0              (0x1U<<0)

#define SAI_ACR2_COMP_B_0X0         (0x0U<<14)
#define SAI_ACR2_COMP_B_0X2         (0x2U<<14)
#define SAI_ACR2_COMP_B_0X3         (0x3U<<14)
#define SAI_ACR2_CPL_B_0X0          (0x0U<<13)
#define SAI_ACR2_CPL_B_0X1          (0x1U<<13)
#define SAI_ACR2_MUTEVAL_B_0X0      (0x0U<<6)
#define SAI_ACR2_MUTEVAL_B_0X1      (0x1U<<6)
#define SAI_ACR2_MUTE_B_0X0         (0x0U<<5)
#define SAI_ACR2_MUTE_B_0X1         (0x1U<<5)
#define SAI_ACR2_TRIS_B_0X0         (0x0U<<4)
#define SAI_ACR2_TRIS_B_0X1         (0x1U<<4)
#define SAI_ACR2_FFLUSH_B_0X0       (0x0U<<3)
#define SAI_ACR2_FFLUSH_B_0X1       (0x1U<<3)
#define SAI_ACR2_FTH_B_0X0          (0x0U<<0)
#define SAI_ACR2_FTH_B_0X1          (0x1U<<0)
#define SAI_ACR2_FTH_B_0X2          (0x2U<<0)
#define SAI_ACR2_FTH_B_0X3          (0x3U<<0)
#define SAI_ACR2_FTH_B_0X4          (0x4U<<0)

// AFRCR Configuration

#define SAI_AFRCR_FSOFF             (0x1U<<18)
#define SAI_AFRCR_FSPOL             (0x1U<<17)
#define SAI_AFRCR_FSDEF             (0x1U<<16)
#define SAI_AFRCR_FSALL             (0x7FU<<8)
#define SAI_AFRCR_FSALL_0           (0x1U<<8)
#define SAI_AFRCR_FRL               (0xFFU<<0)
#define SAI_AFRCR_FRL_0             (0x1U<<0)

#define SAI_AFRCR_FSOFF_B_0X0       (0x0U<<18)
#define SAI_AFRCR_FSOFF_B_0X1       (0x1U<<18)
#define SAI_AFRCR_FSPOL_B_0X0       (0x0U<<17)
#define SAI_AFRCR_FSPOL_B_0X1       (0x1U<<17)
#define SAI_AFRCR_FSDEF_B_0X0       (0x0U<<16)
#define SAI_AFRCR_FSDEF_B_0X1       (0x1U<<16)

// ASLOTR Configuration

#define SAI_ASLOTR_SLOTEN           (0xFFFFU<<16)
#define SAI_ASLOTR_SLOTEN_0         (0x1U<<16)
#define SAI_ASLOTR_NBSLOT           (0xFU<<8)
#define SAI_ASLOTR_NBSLOT_0         (0x1U<<8)
#define SAI_ASLOTR_SLOTSZ           (0x3U<<6)
#define SAI_ASLOTR_SLOTSZ_0         (0x1U<<6)
#define SAI_ASLOTR_FBOFF            (0x1FU<<0)
#define SAI_ASLOTR_FBOFF_0          (0x1U<<0)

#define SAI_ASLOTR_SLOTEN_B_0X0     (0x0U<<16)
#define SAI_ASLOTR_SLOTEN_B_0X1     (0x1U<<16)
#define SAI_ASLOTR_SLOTSZ_B_0X0     (0x0U<<6)
#define SAI_ASLOTR_SLOTSZ_B_0X1     (0x1U<<6)
#define SAI_ASLOTR_SLOTSZ_B_0X2     (0x2U<<6)

// AIM Configuration

#define SAI_AIM_LFSDETIE            (0x1U<<6)
#define SAI_AIM_AFSDETIE            (0x1U<<5)
#define SAI_AIM_CNRDYIE             (0x1U<<4)
#define SAI_AIM_FREQIE              (0x1U<<3)
#define SAI_AIM_WCKCFGIE            (0x1U<<2)
#define SAI_AIM_MUTEDETIE           (0x1U<<1)
#define SAI_AIM_OVRUDRIE            (0x1U<<0)

#define SAI_AIM_LFSDETIE_B_0X0      (0x0U<<6)
#define SAI_AIM_LFSDETIE_B_0X1      (0x1U<<6)
#define SAI_AIM_AFSDETIE_B_0X0      (0x0U<<5)
#define SAI_AIM_AFSDETIE_B_0X1      (0x1U<<5)
#define SAI_AIM_CNRDYIE_B_0X0       (0x0U<<4)
#define SAI_AIM_CNRDYIE_B_0X1       (0x1U<<4)
#define SAI_AIM_FREQIE_B_0X0        (0x0U<<3)
#define SAI_AIM_FREQIE_B_0X1        (0x1U<<3)
#define SAI_AIM_WCKCFGIE_B_0X0      (0x0U<<2)
#define SAI_AIM_WCKCFGIE_B_0X1      (0x1U<<2)
#define SAI_AIM_MUTEDETIE_B_0X0     (0x0U<<1)
#define SAI_AIM_MUTEDETIE_B_0X1     (0x1U<<1)
#define SAI_AIM_OVRUDRIE_B_0X0      (0x0U<<0)
#define SAI_AIM_OVRUDRIE_B_0X1      (0x1U<<0)

// ASR Configuration

#define SAI_ASR_FLVL                (0x7U<<16)
#define SAI_ASR_FLVL_0              (0x1U<<16)
#define SAI_ASR_LFSDET              (0x1U<<6)
#define SAI_ASR_AFSDET              (0x1U<<5)
#define SAI_ASR_CNRDY               (0x1U<<4)
#define SAI_ASR_FREQ                (0x1U<<3)
#define SAI_ASR_WCKCFG              (0x1U<<2)
#define SAI_ASR_MUTEDET             (0x1U<<1)
#define SAI_ASR_OVRUDR              (0x1U<<0)

#define SAI_ASR_FLVL_B_0X0          (0x0U<<16)
#define SAI_ASR_FLVL_B_0X1          (0x1U<<16)
#define SAI_ASR_FLVL_B_0X2          (0x2U<<16)
#define SAI_ASR_FLVL_B_0X3          (0x3U<<16)
#define SAI_ASR_FLVL_B_0X4          (0x4U<<16)
#define SAI_ASR_FLVL_B_0X5          (0x5U<<16)
#define SAI_ASR_LFSDET_B_0X0        (0x0U<<6)
#define SAI_ASR_LFSDET_B_0X1        (0x1U<<6)
#define SAI_ASR_AFSDET_B_0X0        (0x0U<<5)
#define SAI_ASR_AFSDET_B_0X1        (0x1U<<5)
#define SAI_ASR_CNRDY_B_0X0         (0x0U<<4)
#define SAI_ASR_CNRDY_B_0X1         (0x1U<<4)
#define SAI_ASR_FREQ_B_0X0          (0x0U<<3)
#define SAI_ASR_FREQ_B_0X1          (0x1U<<3)
#define SAI_ASR_WCKCFG_B_0X0        (0x0U<<2)
#define SAI_ASR_WCKCFG_B_0X1        (0x1U<<2)
#define SAI_ASR_MUTEDET_B_0X0       (0x0U<<1)
#define SAI_ASR_MUTEDET_B_0X1       (0x1U<<1)
#define SAI_ASR_OVRUDR_B_0X0        (0x0U<<0)
#define SAI_ASR_OVRUDR_B_0X1        (0x1U<<0)

// ACLRFR Configuration

#define SAI_ACLRFR_CLFSDET          (0x1U<<6)
#define SAI_ACLRFR_CAFSDET          (0x1U<<5)
#define SAI_ACLRFR_CCNRDY           (0x1U<<4)
#define SAI_ACLRFR_CWCKCFG          (0x1U<<2)
#define SAI_ACLRFR_CMUTEDET         (0x1U<<1)
#define SAI_ACLRFR_COVRUDR          (0x1U<<0)

// ADR Configuration

#define SAI_ADR_DATA                (0xFFFFFFFFU<<0)
#define SAI_ADR_DATA_0              (0x1U<<0)

// BCR1 Configuration

#define SAI_BCR1_MCKEN              (0x1U<<27)
#define SAI_BCR1_OSR                (0x1U<<26)
#define SAI_BCR1_MCKDIV             (0x3FU<<20)
#define SAI_BCR1_MCKDIV_0           (0x1U<<20)
#define SAI_BCR1_NODIV              (0x1U<<19)
#define SAI_BCR1_DMAEN              (0x1U<<17)
#define SAI_BCR1_SAIEN              (0x1U<<16)
#define SAI_BCR1_OUTDRIV            (0x1U<<13)
#define SAI_BCR1_MONO               (0x1U<<12)
#define SAI_BCR1_SYNCEN             (0x3U<<10)
#define SAI_BCR1_SYNCEN_0           (0x1U<<10)
#define SAI_BCR1_CKSTR              (0x1U<<9)
#define SAI_BCR1_LSBFIRST           (0x1U<<8)
#define SAI_BCR1_DS                 (0x7U<<5)
#define SAI_BCR1_DS_0               (0x1U<<5)
#define SAI_BCR1_PRTCFG             (0x3U<<2)
#define SAI_BCR1_PRTCFG_0           (0x1U<<2)
#define SAI_BCR1_MODE               (0x3U<<0)
#define SAI_BCR1_MODE_0             (0x1U<<0)

#define SAI_BCR1_MCKEN_B_0X0        (0x0U<<27)
#define SAI_BCR1_MCKEN_B_0X1        (0x1U<<27)
#define SAI_BCR1_OSR_B_0X0          (0x0U<<26)
#define SAI_BCR1_OSR_B_0X1          (0x1U<<26)
#define SAI_BCR1_MCKDIV_B_0X0       (0x0U<<20)
#define SAI_BCR1_NODIV_B_0X0        (0x0U<<19)
#define SAI_BCR1_NODIV_B_0X1        (0x1U<<19)
#define SAI_BCR1_DMAEN_B_0X0        (0x0U<<17)
#define SAI_BCR1_DMAEN_B_0X1        (0x1U<<17)
#define SAI_BCR1_SAIEN_B_0X0        (0x0U<<16)
#define SAI_BCR1_SAIEN_B_0X1        (0x1U<<16)
#define SAI_BCR1_OUTDRIV_B_0X0      (0x0U<<13)
#define SAI_BCR1_OUTDRIV_B_0X1      (0x1U<<13)
#define SAI_BCR1_MONO_B_0X0         (0x0U<<12)
#define SAI_BCR1_MONO_B_0X1         (0x1U<<12)
#define SAI_BCR1_SYNCEN_B_0X0       (0x0U<<10)
#define SAI_BCR1_SYNCEN_B_0X1       (0x1U<<10)
#define SAI_BCR1_SYNCEN_B_0X2       (0x2U<<10)
#define SAI_BCR1_CKSTR_B_0X0        (0x0U<<9)
#define SAI_BCR1_CKSTR_B_0X1        (0x1U<<9)
#define SAI_BCR1_LSBFIRST_B_0X0     (0x0U<<8)
#define SAI_BCR1_LSBFIRST_B_0X1     (0x1U<<8)
#define SAI_BCR1_DS_B_0X2           (0x2U<<5)
#define SAI_BCR1_DS_B_0X3           (0x3U<<5)
#define SAI_BCR1_DS_B_0X4           (0x4U<<5)
#define SAI_BCR1_DS_B_0X5           (0x5U<<5)
#define SAI_BCR1_DS_B_0X6           (0x6U<<5)
#define SAI_BCR1_DS_B_0X7           (0x7U<<5)
#define SAI_BCR1_PRTCFG_B_0X0       (0x0U<<2)
#define SAI_BCR1_PRTCFG_B_0X1       (0x1U<<2)
#define SAI_BCR1_PRTCFG_B_0X2       (0x2U<<2)
#define SAI_BCR1_MODE_B_0X0         (0x0U<<0)
#define SAI_BCR1_MODE_B_0X1         (0x1U<<0)
#define SAI_BCR1_MODE_B_0X2         (0x2U<<0)
#define SAI_BCR1_MODE_B_0X3         (0x3U<<0)

// BCR2 Configuration

#define SAI_BCR2_COMP               (0x3U<<14)
#define SAI_BCR2_COMP_0             (0x1U<<14)
#define SAI_BCR2_CPL                (0x1U<<13)
#define SAI_BCR2_MUTECNT            (0x3FU<<7)
#define SAI_BCR2_MUTECNT_0          (0x1U<<7)
#define SAI_BCR2_MUTEVAL            (0x1U<<6)
#define SAI_BCR2_MUTE               (0x1U<<5)
#define SAI_BCR2_TRIS               (0x1U<<4)
#define SAI_BCR2_FFLUSH             (0x1U<<3)
#define SAI_BCR2_FTH                (0x7U<<0)
#define SAI_BCR2_FTH_0              (0x1U<<0)

#define SAI_BCR2_COMP_B_0X0         (0x0U<<14)
#define SAI_BCR2_COMP_B_0X2         (0x2U<<14)
#define SAI_BCR2_COMP_B_0X3         (0x3U<<14)
#define SAI_BCR2_CPL_B_0X0          (0x0U<<13)
#define SAI_BCR2_CPL_B_0X1          (0x1U<<13)
#define SAI_BCR2_MUTEVAL_B_0X0      (0x0U<<6)
#define SAI_BCR2_MUTEVAL_B_0X1      (0x1U<<6)
#define SAI_BCR2_MUTE_B_0X0         (0x0U<<5)
#define SAI_BCR2_MUTE_B_0X1         (0x1U<<5)
#define SAI_BCR2_TRIS_B_0X0         (0x0U<<4)
#define SAI_BCR2_TRIS_B_0X1         (0x1U<<4)
#define SAI_BCR2_FFLUSH_B_0X0       (0x0U<<3)
#define SAI_BCR2_FFLUSH_B_0X1       (0x1U<<3)
#define SAI_BCR2_FTH_B_0X0          (0x0U<<0)
#define SAI_BCR2_FTH_B_0X1          (0x1U<<0)
#define SAI_BCR2_FTH_B_0X2          (0x2U<<0)
#define SAI_BCR2_FTH_B_0X3          (0x3U<<0)
#define SAI_BCR2_FTH_B_0X4          (0x4U<<0)

// BFRCR Configuration

#define SAI_BFRCR_FSOFF             (0x1U<<18)
#define SAI_BFRCR_FSPOL             (0x1U<<17)
#define SAI_BFRCR_FSDEF             (0x1U<<16)
#define SAI_BFRCR_FSALL             (0x7FU<<8)
#define SAI_BFRCR_FSALL_0           (0x1U<<8)
#define SAI_BFRCR_FRL               (0xFFU<<0)
#define SAI_BFRCR_FRL_0             (0x1U<<0)

#define SAI_BFRCR_FSOFF_B_0X0       (0x0U<<18)
#define SAI_BFRCR_FSOFF_B_0X1       (0x1U<<18)
#define SAI_BFRCR_FSPOL_B_0X0       (0x0U<<17)
#define SAI_BFRCR_FSPOL_B_0X1       (0x1U<<17)
#define SAI_BFRCR_FSDEF_B_0X0       (0x0U<<16)
#define SAI_BFRCR_FSDEF_B_0X1       (0x1U<<16)

// BSLOTR Configuration

#define SAI_BSLOTR_SLOTEN           (0xFFFFU<<16)
#define SAI_BSLOTR_SLOTEN_0         (0x1U<<16)
#define SAI_BSLOTR_NBSLOT           (0xFU<<8)
#define SAI_BSLOTR_NBSLOT_0         (0x1U<<8)
#define SAI_BSLOTR_SLOTSZ           (0x3U<<6)
#define SAI_BSLOTR_SLOTSZ_0         (0x1U<<6)
#define SAI_BSLOTR_FBOFF            (0x1FU<<0)
#define SAI_BSLOTR_FBOFF_0          (0x1U<<0)

#define SAI_BSLOTR_SLOTEN_B_0X0     (0x0U<<16)
#define SAI_BSLOTR_SLOTEN_B_0X1     (0x1U<<16)
#define SAI_BSLOTR_SLOTSZ_B_0X0     (0x0U<<6)
#define SAI_BSLOTR_SLOTSZ_B_0X1     (0x1U<<6)
#define SAI_BSLOTR_SLOTSZ_B_0X2     (0x2U<<6)

// BIM Configuration

#define SAI_BIM_LFSDETIE            (0x1U<<6)
#define SAI_BIM_AFSDETIE            (0x1U<<5)
#define SAI_BIM_CNRDYIE             (0x1U<<4)
#define SAI_BIM_FREQIE              (0x1U<<3)
#define SAI_BIM_WCKCFGIE            (0x1U<<2)
#define SAI_BIM_MUTEDETIE           (0x1U<<1)
#define SAI_BIM_OVRUDRIE            (0x1U<<0)

#define SAI_BIM_LFSDETIE_B_0X0      (0x0U<<6)
#define SAI_BIM_LFSDETIE_B_0X1      (0x1U<<6)
#define SAI_BIM_AFSDETIE_B_0X0      (0x0U<<5)
#define SAI_BIM_AFSDETIE_B_0X1      (0x1U<<5)
#define SAI_BIM_CNRDYIE_B_0X0       (0x0U<<4)
#define SAI_BIM_CNRDYIE_B_0X1       (0x1U<<4)
#define SAI_BIM_FREQIE_B_0X0        (0x0U<<3)
#define SAI_BIM_FREQIE_B_0X1        (0x1U<<3)
#define SAI_BIM_WCKCFGIE_B_0X0      (0x0U<<2)
#define SAI_BIM_WCKCFGIE_B_0X1      (0x1U<<2)
#define SAI_BIM_MUTEDETIE_B_0X0     (0x0U<<1)
#define SAI_BIM_MUTEDETIE_B_0X1     (0x1U<<1)
#define SAI_BIM_OVRUDRIE_B_0X0      (0x0U<<0)
#define SAI_BIM_OVRUDRIE_B_0X1      (0x1U<<0)

// BSR Configuration

#define SAI_BSR_FLVL                (0x7U<<16)
#define SAI_BSR_FLVL_0              (0x1U<<16)
#define SAI_BSR_LFSDET              (0x1U<<6)
#define SAI_BSR_AFSDET              (0x1U<<5)
#define SAI_BSR_CNRDY               (0x1U<<4)
#define SAI_BSR_FREQ                (0x1U<<3)
#define SAI_BSR_WCKCFG              (0x1U<<2)
#define SAI_BSR_MUTEDET             (0x1U<<1)
#define SAI_BSR_OVRUDR              (0x1U<<0)

#define SAI_BSR_FLVL_B_0X0          (0x0U<<16)
#define SAI_BSR_FLVL_B_0X1          (0x1U<<16)
#define SAI_BSR_FLVL_B_0X2          (0x2U<<16)
#define SAI_BSR_FLVL_B_0X3          (0x3U<<16)
#define SAI_BSR_FLVL_B_0X4          (0x4U<<16)
#define SAI_BSR_FLVL_B_0X5          (0x5U<<16)
#define SAI_BSR_LFSDET_B_0X0        (0x0U<<6)
#define SAI_BSR_LFSDET_B_0X1        (0x1U<<6)
#define SAI_BSR_AFSDET_B_0X0        (0x0U<<5)
#define SAI_BSR_AFSDET_B_0X1        (0x1U<<5)
#define SAI_BSR_CNRDY_B_0X0         (0x0U<<4)
#define SAI_BSR_CNRDY_B_0X1         (0x1U<<4)
#define SAI_BSR_FREQ_B_0X0          (0x0U<<3)
#define SAI_BSR_FREQ_B_0X1          (0x1U<<3)
#define SAI_BSR_WCKCFG_B_0X0        (0x0U<<2)
#define SAI_BSR_WCKCFG_B_0X1        (0x1U<<2)
#define SAI_BSR_MUTEDET_B_0X0       (0x0U<<1)
#define SAI_BSR_MUTEDET_B_0X1       (0x1U<<1)
#define SAI_BSR_OVRUDR_B_0X0        (0x0U<<0)
#define SAI_BSR_OVRUDR_B_0X1        (0x1U<<0)

// BCLRFR Configuration

#define SAI_BCLRFR_CLFSDET          (0x1U<<6)
#define SAI_BCLRFR_CAFSDET          (0x1U<<5)
#define SAI_BCLRFR_CCNRDY           (0x1U<<4)
#define SAI_BCLRFR_CWCKCFG          (0x1U<<2)
#define SAI_BCLRFR_CMUTEDET         (0x1U<<1)
#define SAI_BCLRFR_COVRUDR          (0x1U<<0)

// BDR Configuration

#define SAI_BDR_DATA                (0xFFFFFFFFU<<0)
#define SAI_BDR_DATA_0              (0x1U<<0)

// PDMCR Configuration

#define SAI_PDMCR_CKEN2             (0x1U<<9)
#define SAI_PDMCR_CKEN1             (0x1U<<8)
#define SAI_PDMCR_MICNBR            (0x3U<<4)
#define SAI_PDMCR_MICNBR_0          (0x1U<<4)
#define SAI_PDMCR_PDMEN             (0x1U<<0)

#define SAI_PDMCR_CKEN2_B_0X0       (0x0U<<9)
#define SAI_PDMCR_CKEN2_B_0X1       (0x1U<<9)
#define SAI_PDMCR_CKEN1_B_0X0       (0x0U<<8)
#define SAI_PDMCR_CKEN1_B_0X1       (0x1U<<8)
#define SAI_PDMCR_MICNBR_B_0X0      (0x0U<<4)
#define SAI_PDMCR_MICNBR_B_0X1      (0x1U<<4)
#define SAI_PDMCR_MICNBR_B_0X2      (0x2U<<4)
#define SAI_PDMCR_MICNBR_B_0X3      (0x3U<<4)
#define SAI_PDMCR_PDMEN_B_0X0       (0x0U<<0)
#define SAI_PDMCR_PDMEN_B_0X1       (0x1U<<0)

// PDMDLY Configuration

#define SAI_PDMDLY_DLYM4R           (0x7U<<28)
#define SAI_PDMDLY_DLYM4R_0         (0x1U<<28)
#define SAI_PDMDLY_DLYM4L           (0x7U<<24)
#define SAI_PDMDLY_DLYM4L_0         (0x1U<<24)
#define SAI_PDMDLY_DLYM3R           (0x7U<<20)
#define SAI_PDMDLY_DLYM3R_0         (0x1U<<20)
#define SAI_PDMDLY_DLYM3L           (0x7U<<16)
#define SAI_PDMDLY_DLYM3L_0         (0x1U<<16)
#define SAI_PDMDLY_DLYM2R           (0x7U<<12)
#define SAI_PDMDLY_DLYM2R_0         (0x1U<<12)
#define SAI_PDMDLY_DLYM2L           (0x7U<<8)
#define SAI_PDMDLY_DLYM2L_0         (0x1U<<8)
#define SAI_PDMDLY_DLYM1R           (0x7U<<4)
#define SAI_PDMDLY_DLYM1R_0         (0x1U<<4)
#define SAI_PDMDLY_DLYM1L           (0x7U<<0)
#define SAI_PDMDLY_DLYM1L_0         (0x1U<<0)

#define SAI_PDMDLY_DLYM4R_B_0X0     (0x0U<<28)
#define SAI_PDMDLY_DLYM4R_B_0X1     (0x1U<<28)
#define SAI_PDMDLY_DLYM4R_B_0X2     (0x2U<<28)
#define SAI_PDMDLY_DLYM4R_B_0X7     (0x7U<<28)
#define SAI_PDMDLY_DLYM4L_B_0X0     (0x0U<<24)
#define SAI_PDMDLY_DLYM4L_B_0X1     (0x1U<<24)
#define SAI_PDMDLY_DLYM4L_B_0X2     (0x2U<<24)
#define SAI_PDMDLY_DLYM4L_B_0X7     (0x7U<<24)
#define SAI_PDMDLY_DLYM3R_B_0X0     (0x0U<<20)
#define SAI_PDMDLY_DLYM3R_B_0X1     (0x1U<<20)
#define SAI_PDMDLY_DLYM3R_B_0X2     (0x2U<<20)
#define SAI_PDMDLY_DLYM3R_B_0X7     (0x7U<<20)
#define SAI_PDMDLY_DLYM3L_B_0X0     (0x0U<<16)
#define SAI_PDMDLY_DLYM3L_B_0X1     (0x1U<<16)
#define SAI_PDMDLY_DLYM3L_B_0X2     (0x2U<<16)
#define SAI_PDMDLY_DLYM3L_B_0X7     (0x7U<<16)
#define SAI_PDMDLY_DLYM2R_B_0X0     (0x0U<<12)
#define SAI_PDMDLY_DLYM2R_B_0X1     (0x1U<<12)
#define SAI_PDMDLY_DLYM2R_B_0X2     (0x2U<<12)
#define SAI_PDMDLY_DLYM2R_B_0X7     (0x7U<<12)
#define SAI_PDMDLY_DLYM2L_B_0X0     (0x0U<<8)
#define SAI_PDMDLY_DLYM2L_B_0X1     (0x1U<<8)
#define SAI_PDMDLY_DLYM2L_B_0X2     (0x2U<<8)
#define SAI_PDMDLY_DLYM2L_B_0X7     (0x7U<<8)
#define SAI_PDMDLY_DLYM1R_B_0X0     (0x0U<<4)
#define SAI_PDMDLY_DLYM1R_B_0X1     (0x1U<<4)
#define SAI_PDMDLY_DLYM1R_B_0X2     (0x2U<<4)
#define SAI_PDMDLY_DLYM1R_B_0X7     (0x7U<<4)
#define SAI_PDMDLY_DLYM1L_B_0X0     (0x0U<<0)
#define SAI_PDMDLY_DLYM1L_B_0X1     (0x1U<<0)
#define SAI_PDMDLY_DLYM1L_B_0X2     (0x2U<<0)
#define SAI_PDMDLY_DLYM1L_B_0X7     (0x7U<<0)
