/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H747_CM4_fmc.
; ==================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H747_CM4_fmc equates.
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

// FMC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    BCR1;
    volatile    uint32_t    BTR1;
    volatile    uint32_t    BCR2;
    volatile    uint32_t    BTR2;
    volatile    uint32_t    BCR3;
    volatile    uint32_t    BTR3;
    volatile    uint32_t    BCR4;
    volatile    uint32_t    BTR4;
    volatile    uint32_t    RESERVED0[24];
    volatile    uint32_t    PCR;
    volatile    uint32_t    SR;
    volatile    uint32_t    PMEM;
    volatile    uint32_t    PATT;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    ECCR;
    volatile    uint32_t    RESERVED2[27];
    volatile    uint32_t    BWTR1;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    BWTR2;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    BWTR3;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    BWTR4;
    volatile    uint32_t    RESERVED6[8];
    volatile    uint32_t    SDCR1;
    volatile    uint32_t    SDCR2;
    volatile    uint32_t    SDTR1;
    volatile    uint32_t    SDTR2;
    volatile    uint32_t    SDCMR;
    volatile    uint32_t    SDRTR;
    volatile    uint32_t    SDSR;
} FMC_TypeDef;

#ifdef __cplusplus
#define FMC reinterpret_cast<FMC_TypeDef *>(0x52004000U)

#else
#define FMC ((FMC_TypeDef *)0x52004000U)
#endif

// BCR1 Configuration

#define FMC_BCR1_FMCEN      (0x1U<<31)
#define FMC_BCR1_BMAP       (0x3U<<24)
#define FMC_BCR1_BMAP_0     (0x1U<<24)
#define FMC_BCR1_WFDIS      (0x1U<<21)
#define FMC_BCR1_CCLKEN     (0x1U<<20)
#define FMC_BCR1_CBURSTRW   (0x1U<<19)
#define FMC_BCR1_CPSIZE     (0x7U<<16)
#define FMC_BCR1_CPSIZE_0   (0x1U<<16)
#define FMC_BCR1_ASYNCWAIT  (0x1U<<15)
#define FMC_BCR1_EXTMOD     (0x1U<<14)
#define FMC_BCR1_WAITEN     (0x1U<<13)
#define FMC_BCR1_WREN       (0x1U<<12)
#define FMC_BCR1_WAITCFG    (0x1U<<11)
#define FMC_BCR1_WAITPOL    (0x1U<<9)
#define FMC_BCR1_BURSTEN    (0x1U<<8)
#define FMC_BCR1_FACCEN     (0x1U<<6)
#define FMC_BCR1_MWID       (0x3U<<4)
#define FMC_BCR1_MWID_0     (0x1U<<4)
#define FMC_BCR1_MTYP       (0x3U<<2)
#define FMC_BCR1_MTYP_0     (0x1U<<2)
#define FMC_BCR1_MUXEN      (0x1U<<1)
#define FMC_BCR1_MBKEN      (0x1U<<0)

// BTR1 Configuration

#define FMC_BTR1_ACCMOD     (0x3U<<28)
#define FMC_BTR1_ACCMOD_0   (0x1U<<28)
#define FMC_BTR1_DATLAT     (0xFU<<24)
#define FMC_BTR1_DATLAT_0   (0x1U<<24)
#define FMC_BTR1_CLKDIV     (0xFU<<20)
#define FMC_BTR1_CLKDIV_0   (0x1U<<20)
#define FMC_BTR1_BUSTURN    (0xFU<<16)
#define FMC_BTR1_BUSTURN_0  (0x1U<<16)
#define FMC_BTR1_DATAST     (0xFFU<<8)
#define FMC_BTR1_DATAST_0   (0x1U<<8)
#define FMC_BTR1_ADDHLD     (0xFU<<4)
#define FMC_BTR1_ADDHLD_0   (0x1U<<4)
#define FMC_BTR1_ADDSET     (0xFU<<0)
#define FMC_BTR1_ADDSET_0   (0x1U<<0)

// BCR2 Configuration

#define FMC_BCR2_FMCEN      (0x1U<<31)
#define FMC_BCR2_BMAP       (0x3U<<24)
#define FMC_BCR2_BMAP_0     (0x1U<<24)
#define FMC_BCR2_WFDIS      (0x1U<<21)
#define FMC_BCR2_CCLKEN     (0x1U<<20)
#define FMC_BCR2_CBURSTRW   (0x1U<<19)
#define FMC_BCR2_CPSIZE     (0x7U<<16)
#define FMC_BCR2_CPSIZE_0   (0x1U<<16)
#define FMC_BCR2_ASYNCWAIT  (0x1U<<15)
#define FMC_BCR2_EXTMOD     (0x1U<<14)
#define FMC_BCR2_WAITEN     (0x1U<<13)
#define FMC_BCR2_WREN       (0x1U<<12)
#define FMC_BCR2_WAITCFG    (0x1U<<11)
#define FMC_BCR2_WAITPOL    (0x1U<<9)
#define FMC_BCR2_BURSTEN    (0x1U<<8)
#define FMC_BCR2_FACCEN     (0x1U<<6)
#define FMC_BCR2_MWID       (0x3U<<4)
#define FMC_BCR2_MWID_0     (0x1U<<4)
#define FMC_BCR2_MTYP       (0x3U<<2)
#define FMC_BCR2_MTYP_0     (0x1U<<2)
#define FMC_BCR2_MUXEN      (0x1U<<1)
#define FMC_BCR2_MBKEN      (0x1U<<0)

// BTR2 Configuration

#define FMC_BTR2_ACCMOD     (0x3U<<28)
#define FMC_BTR2_ACCMOD_0   (0x1U<<28)
#define FMC_BTR2_DATLAT     (0xFU<<24)
#define FMC_BTR2_DATLAT_0   (0x1U<<24)
#define FMC_BTR2_CLKDIV     (0xFU<<20)
#define FMC_BTR2_CLKDIV_0   (0x1U<<20)
#define FMC_BTR2_BUSTURN    (0xFU<<16)
#define FMC_BTR2_BUSTURN_0  (0x1U<<16)
#define FMC_BTR2_DATAST     (0xFFU<<8)
#define FMC_BTR2_DATAST_0   (0x1U<<8)
#define FMC_BTR2_ADDHLD     (0xFU<<4)
#define FMC_BTR2_ADDHLD_0   (0x1U<<4)
#define FMC_BTR2_ADDSET     (0xFU<<0)
#define FMC_BTR2_ADDSET_0   (0x1U<<0)

// BCR3 Configuration

#define FMC_BCR3_FMCEN      (0x1U<<31)
#define FMC_BCR3_BMAP       (0x3U<<24)
#define FMC_BCR3_BMAP_0     (0x1U<<24)
#define FMC_BCR3_WFDIS      (0x1U<<21)
#define FMC_BCR3_CCLKEN     (0x1U<<20)
#define FMC_BCR3_CBURSTRW   (0x1U<<19)
#define FMC_BCR3_CPSIZE     (0x7U<<16)
#define FMC_BCR3_CPSIZE_0   (0x1U<<16)
#define FMC_BCR3_ASYNCWAIT  (0x1U<<15)
#define FMC_BCR3_EXTMOD     (0x1U<<14)
#define FMC_BCR3_WAITEN     (0x1U<<13)
#define FMC_BCR3_WREN       (0x1U<<12)
#define FMC_BCR3_WAITCFG    (0x1U<<11)
#define FMC_BCR3_WAITPOL    (0x1U<<9)
#define FMC_BCR3_BURSTEN    (0x1U<<8)
#define FMC_BCR3_FACCEN     (0x1U<<6)
#define FMC_BCR3_MWID       (0x3U<<4)
#define FMC_BCR3_MWID_0     (0x1U<<4)
#define FMC_BCR3_MTYP       (0x3U<<2)
#define FMC_BCR3_MTYP_0     (0x1U<<2)
#define FMC_BCR3_MUXEN      (0x1U<<1)
#define FMC_BCR3_MBKEN      (0x1U<<0)

// BTR3 Configuration

#define FMC_BTR3_ACCMOD     (0x3U<<28)
#define FMC_BTR3_ACCMOD_0   (0x1U<<28)
#define FMC_BTR3_DATLAT     (0xFU<<24)
#define FMC_BTR3_DATLAT_0   (0x1U<<24)
#define FMC_BTR3_CLKDIV     (0xFU<<20)
#define FMC_BTR3_CLKDIV_0   (0x1U<<20)
#define FMC_BTR3_BUSTURN    (0xFU<<16)
#define FMC_BTR3_BUSTURN_0  (0x1U<<16)
#define FMC_BTR3_DATAST     (0xFFU<<8)
#define FMC_BTR3_DATAST_0   (0x1U<<8)
#define FMC_BTR3_ADDHLD     (0xFU<<4)
#define FMC_BTR3_ADDHLD_0   (0x1U<<4)
#define FMC_BTR3_ADDSET     (0xFU<<0)
#define FMC_BTR3_ADDSET_0   (0x1U<<0)

// BCR4 Configuration

#define FMC_BCR4_FMCEN      (0x1U<<31)
#define FMC_BCR4_BMAP       (0x3U<<24)
#define FMC_BCR4_BMAP_0     (0x1U<<24)
#define FMC_BCR4_WFDIS      (0x1U<<21)
#define FMC_BCR4_CCLKEN     (0x1U<<20)
#define FMC_BCR4_CBURSTRW   (0x1U<<19)
#define FMC_BCR4_CPSIZE     (0x7U<<16)
#define FMC_BCR4_CPSIZE_0   (0x1U<<16)
#define FMC_BCR4_ASYNCWAIT  (0x1U<<15)
#define FMC_BCR4_EXTMOD     (0x1U<<14)
#define FMC_BCR4_WAITEN     (0x1U<<13)
#define FMC_BCR4_WREN       (0x1U<<12)
#define FMC_BCR4_WAITCFG    (0x1U<<11)
#define FMC_BCR4_WAITPOL    (0x1U<<9)
#define FMC_BCR4_BURSTEN    (0x1U<<8)
#define FMC_BCR4_FACCEN     (0x1U<<6)
#define FMC_BCR4_MWID       (0x3U<<4)
#define FMC_BCR4_MWID_0     (0x1U<<4)
#define FMC_BCR4_MTYP       (0x3U<<2)
#define FMC_BCR4_MTYP_0     (0x1U<<2)
#define FMC_BCR4_MUXEN      (0x1U<<1)
#define FMC_BCR4_MBKEN      (0x1U<<0)

// BTR4 Configuration

#define FMC_BTR4_ACCMOD     (0x3U<<28)
#define FMC_BTR4_ACCMOD_0   (0x1U<<28)
#define FMC_BTR4_DATLAT     (0xFU<<24)
#define FMC_BTR4_DATLAT_0   (0x1U<<24)
#define FMC_BTR4_CLKDIV     (0xFU<<20)
#define FMC_BTR4_CLKDIV_0   (0x1U<<20)
#define FMC_BTR4_BUSTURN    (0xFU<<16)
#define FMC_BTR4_BUSTURN_0  (0x1U<<16)
#define FMC_BTR4_DATAST     (0xFFU<<8)
#define FMC_BTR4_DATAST_0   (0x1U<<8)
#define FMC_BTR4_ADDHLD     (0xFU<<4)
#define FMC_BTR4_ADDHLD_0   (0x1U<<4)
#define FMC_BTR4_ADDSET     (0xFU<<0)
#define FMC_BTR4_ADDSET_0   (0x1U<<0)

// PCR Configuration

#define FMC_PCR_ECCPS       (0x7U<<17)
#define FMC_PCR_ECCPS_0     (0x1U<<17)
#define FMC_PCR_TAR         (0xFU<<13)
#define FMC_PCR_TAR_0       (0x1U<<13)
#define FMC_PCR_TCLR        (0xFU<<9)
#define FMC_PCR_TCLR_0      (0x1U<<9)
#define FMC_PCR_ECCEN       (0x1U<<6)
#define FMC_PCR_PWID        (0x3U<<4)
#define FMC_PCR_PWID_0      (0x1U<<4)
#define FMC_PCR_PBKEN       (0x1U<<2)
#define FMC_PCR_PWAITEN     (0x1U<<1)

// SR Configuration

#define FMC_SR_FEMPT        (0x1U<<6)
#define FMC_SR_IFEN         (0x1U<<5)
#define FMC_SR_ILEN         (0x1U<<4)
#define FMC_SR_IREN         (0x1U<<3)
#define FMC_SR_IFS          (0x1U<<2)
#define FMC_SR_ILS          (0x1U<<1)
#define FMC_SR_IRS          (0x1U<<0)

// PMEM Configuration

#define FMC_PMEM_MEMHIZ     (0xFFU<<24)
#define FMC_PMEM_MEMHIZ_0   (0x1U<<24)
#define FMC_PMEM_MEMHOLD    (0xFFU<<16)
#define FMC_PMEM_MEMHOLD_0  (0x1U<<16)
#define FMC_PMEM_MEMWAIT    (0xFFU<<8)
#define FMC_PMEM_MEMWAIT_0  (0x1U<<8)
#define FMC_PMEM_MEMSET     (0xFFU<<0)
#define FMC_PMEM_MEMSET_0   (0x1U<<0)

// PATT Configuration

#define FMC_PATT_ATTHIZ     (0xFFU<<24)
#define FMC_PATT_ATTHIZ_0   (0x1U<<24)
#define FMC_PATT_ATTHOLD    (0xFFU<<16)
#define FMC_PATT_ATTHOLD_0  (0x1U<<16)
#define FMC_PATT_ATTWAIT    (0xFFU<<8)
#define FMC_PATT_ATTWAIT_0  (0x1U<<8)
#define FMC_PATT_ATTSET     (0xFFU<<0)
#define FMC_PATT_ATTSET_0   (0x1U<<0)

// ECCR Configuration

#define FMC_ECCR_ECC        (0xFFFFFFFFU<<0)
#define FMC_ECCR_ECC_0      (0x1U<<0)

// BWTR1 Configuration

#define FMC_BWTR1_ACCMOD    (0x3U<<28)
#define FMC_BWTR1_ACCMOD_0  (0x1U<<28)
#define FMC_BWTR1_BUSTURN   (0xFU<<16)
#define FMC_BWTR1_BUSTURN_0 (0x1U<<16)
#define FMC_BWTR1_DATAST    (0xFFU<<8)
#define FMC_BWTR1_DATAST_0  (0x1U<<8)
#define FMC_BWTR1_ADDHLD    (0xFU<<4)
#define FMC_BWTR1_ADDHLD_0  (0x1U<<4)
#define FMC_BWTR1_ADDSET    (0xFU<<0)
#define FMC_BWTR1_ADDSET_0  (0x1U<<0)

// BWTR2 Configuration

#define FMC_BWTR2_ACCMOD    (0x3U<<28)
#define FMC_BWTR2_ACCMOD_0  (0x1U<<28)
#define FMC_BWTR2_BUSTURN   (0xFU<<16)
#define FMC_BWTR2_BUSTURN_0 (0x1U<<16)
#define FMC_BWTR2_DATAST    (0xFFU<<8)
#define FMC_BWTR2_DATAST_0  (0x1U<<8)
#define FMC_BWTR2_ADDHLD    (0xFU<<4)
#define FMC_BWTR2_ADDHLD_0  (0x1U<<4)
#define FMC_BWTR2_ADDSET    (0xFU<<0)
#define FMC_BWTR2_ADDSET_0  (0x1U<<0)

// BWTR3 Configuration

#define FMC_BWTR3_ACCMOD    (0x3U<<28)
#define FMC_BWTR3_ACCMOD_0  (0x1U<<28)
#define FMC_BWTR3_BUSTURN   (0xFU<<16)
#define FMC_BWTR3_BUSTURN_0 (0x1U<<16)
#define FMC_BWTR3_DATAST    (0xFFU<<8)
#define FMC_BWTR3_DATAST_0  (0x1U<<8)
#define FMC_BWTR3_ADDHLD    (0xFU<<4)
#define FMC_BWTR3_ADDHLD_0  (0x1U<<4)
#define FMC_BWTR3_ADDSET    (0xFU<<0)
#define FMC_BWTR3_ADDSET_0  (0x1U<<0)

// BWTR4 Configuration

#define FMC_BWTR4_ACCMOD    (0x3U<<28)
#define FMC_BWTR4_ACCMOD_0  (0x1U<<28)
#define FMC_BWTR4_BUSTURN   (0xFU<<16)
#define FMC_BWTR4_BUSTURN_0 (0x1U<<16)
#define FMC_BWTR4_DATAST    (0xFFU<<8)
#define FMC_BWTR4_DATAST_0  (0x1U<<8)
#define FMC_BWTR4_ADDHLD    (0xFU<<4)
#define FMC_BWTR4_ADDHLD_0  (0x1U<<4)
#define FMC_BWTR4_ADDSET    (0xFU<<0)
#define FMC_BWTR4_ADDSET_0  (0x1U<<0)

// SDCR1 Configuration

#define FMC_SDCR1_RPIPE     (0x3U<<13)
#define FMC_SDCR1_RPIPE_0   (0x1U<<13)
#define FMC_SDCR1_RBURST    (0x1U<<12)
#define FMC_SDCR1_SDCLK     (0x3U<<10)
#define FMC_SDCR1_SDCLK_0   (0x1U<<10)
#define FMC_SDCR1_WP        (0x1U<<9)
#define FMC_SDCR1_CAS       (0x3U<<7)
#define FMC_SDCR1_CAS_0     (0x1U<<7)
#define FMC_SDCR1_NB        (0x1U<<6)
#define FMC_SDCR1_MWID      (0x3U<<4)
#define FMC_SDCR1_MWID_0    (0x1U<<4)
#define FMC_SDCR1_NR        (0x3U<<2)
#define FMC_SDCR1_NR_0      (0x1U<<2)
#define FMC_SDCR1_NC        (0x3U<<0)
#define FMC_SDCR1_NC_0      (0x1U<<0)

// SDCR2 Configuration

#define FMC_SDCR2_RPIPE     (0x3U<<13)
#define FMC_SDCR2_RPIPE_0   (0x1U<<13)
#define FMC_SDCR2_RBURST    (0x1U<<12)
#define FMC_SDCR2_SDCLK     (0x3U<<10)
#define FMC_SDCR2_SDCLK_0   (0x1U<<10)
#define FMC_SDCR2_WP        (0x1U<<9)
#define FMC_SDCR2_CAS       (0x3U<<7)
#define FMC_SDCR2_CAS_0     (0x1U<<7)
#define FMC_SDCR2_NB        (0x1U<<6)
#define FMC_SDCR2_MWID      (0x3U<<4)
#define FMC_SDCR2_MWID_0    (0x1U<<4)
#define FMC_SDCR2_NR        (0x3U<<2)
#define FMC_SDCR2_NR_0      (0x1U<<2)
#define FMC_SDCR2_NC        (0x3U<<0)
#define FMC_SDCR2_NC_0      (0x1U<<0)

// SDTR1 Configuration

#define FMC_SDTR1_TRCD      (0xFU<<24)
#define FMC_SDTR1_TRCD_0    (0x1U<<24)
#define FMC_SDTR1_TRP       (0xFU<<20)
#define FMC_SDTR1_TRP_0     (0x1U<<20)
#define FMC_SDTR1_TWR       (0xFU<<16)
#define FMC_SDTR1_TWR_0     (0x1U<<16)
#define FMC_SDTR1_TRC       (0xFU<<12)
#define FMC_SDTR1_TRC_0     (0x1U<<12)
#define FMC_SDTR1_TRAS      (0xFU<<8)
#define FMC_SDTR1_TRAS_0    (0x1U<<8)
#define FMC_SDTR1_TXSR      (0xFU<<4)
#define FMC_SDTR1_TXSR_0    (0x1U<<4)
#define FMC_SDTR1_TMRD      (0xFU<<0)
#define FMC_SDTR1_TMRD_0    (0x1U<<0)

// SDTR2 Configuration

#define FMC_SDTR2_TRCD      (0xFU<<24)
#define FMC_SDTR2_TRCD_0    (0x1U<<24)
#define FMC_SDTR2_TRP       (0xFU<<20)
#define FMC_SDTR2_TRP_0     (0x1U<<20)
#define FMC_SDTR2_TWR       (0xFU<<16)
#define FMC_SDTR2_TWR_0     (0x1U<<16)
#define FMC_SDTR2_TRC       (0xFU<<12)
#define FMC_SDTR2_TRC_0     (0x1U<<12)
#define FMC_SDTR2_TRAS      (0xFU<<8)
#define FMC_SDTR2_TRAS_0    (0x1U<<8)
#define FMC_SDTR2_TXSR      (0xFU<<4)
#define FMC_SDTR2_TXSR_0    (0x1U<<4)
#define FMC_SDTR2_TMRD      (0xFU<<0)
#define FMC_SDTR2_TMRD_0    (0x1U<<0)

// SDCMR Configuration

#define FMC_SDCMR_MRD       (0x3FFFU<<9)
#define FMC_SDCMR_MRD_0     (0x1U<<9)
#define FMC_SDCMR_NRFS      (0xFU<<5)
#define FMC_SDCMR_NRFS_0    (0x1U<<5)
#define FMC_SDCMR_CTB1      (0x1U<<4)
#define FMC_SDCMR_CTB2      (0x1U<<3)
#define FMC_SDCMR_MODE      (0x7U<<0)
#define FMC_SDCMR_MODE_0    (0x1U<<0)

// SDRTR Configuration

#define FMC_SDRTR_REIE      (0x1U<<14)
#define FMC_SDRTR_COUNT     (0x1FFFU<<1)
#define FMC_SDRTR_COUNT_0   (0x1U<<1)
#define FMC_SDRTR_CRE       (0x1U<<0)

// SDSR Configuration

#define FMC_SDSR_MODES2     (0x3U<<3)
#define FMC_SDSR_MODES2_0   (0x1U<<3)
#define FMC_SDSR_MODES1     (0x3U<<1)
#define FMC_SDSR_MODES1_0   (0x1U<<1)
#define FMC_SDSR_RE         (0x1U<<0)
