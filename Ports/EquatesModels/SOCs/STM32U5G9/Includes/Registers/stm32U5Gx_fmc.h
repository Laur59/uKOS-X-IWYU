/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_fmc equates.
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
    volatile    uint32_t    PCSCNTR;
    volatile    uint32_t    RESERVED0[23];
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
} FMC_TypeDef;

#ifdef __cplusplus
#define FMC_NS  reinterpret_cast<FMC_TypeDef *>(0x420D0400U)
#define FMC_S   reinterpret_cast<FMC_TypeDef *>(0x520D0400U)

#else
#define FMC_NS  ((FMC_TypeDef *)0x420D0400U)
#define FMC_S   ((FMC_TypeDef *)0x520D0400U)
#endif

// BCR1 Configuration

#define FMC_BCR1_FMCEN          (0x1U<<31U)
#define FMC_BCR1_NBLSET         (0x3U<<22U)
#define FMC_BCR1_NBLSET_0       (0x1U<<22U)
#define FMC_BCR1_WFDIS          (0x1U<<21U)
#define FMC_BCR1_CCLKEN         (0x1U<<20U)
#define FMC_BCR1_CBURSTRW       (0x1U<<19U)
#define FMC_BCR1_CPSIZE         (0x7U<<16U)
#define FMC_BCR1_CPSIZE_0       (0x1U<<16U)
#define FMC_BCR1_ASYNCWAIT      (0x1U<<15U)
#define FMC_BCR1_EXTMOD         (0x1U<<14U)
#define FMC_BCR1_WAITEN         (0x1U<<13U)
#define FMC_BCR1_WREN           (0x1U<<12U)
#define FMC_BCR1_WAITCFG        (0x1U<<11U)
#define FMC_BCR1_WAITPOL        (0x1U<<9U)
#define FMC_BCR1_BURSTEN        (0x1U<<8U)
#define FMC_BCR1_FACCEN         (0x1U<<6U)
#define FMC_BCR1_MWID           (0x3U<<4U)
#define FMC_BCR1_MWID_0         (0x1U<<4U)
#define FMC_BCR1_MTYP           (0x3U<<2U)
#define FMC_BCR1_MTYP_0         (0x1U<<2U)
#define FMC_BCR1_MUXEN          (0x1U<<1U)
#define FMC_BCR1_MBKEN          (0x1U<<0U)

// BTR1 Configuration

#define FMC_BTR1_DATAHLD        (0x3U<<30U)
#define FMC_BTR1_DATAHLD_0      (0x1U<<30U)
#define FMC_BTR1_ACCMOD         (0x3U<<28U)
#define FMC_BTR1_ACCMOD_0       (0x1U<<28U)
#define FMC_BTR1_DATLAT         (0xFU<<24U)
#define FMC_BTR1_DATLAT_0       (0x1U<<24U)
#define FMC_BTR1_CLKDIV         (0xFU<<20U)
#define FMC_BTR1_CLKDIV_0       (0x1U<<20U)
#define FMC_BTR1_BUSTURN        (0xFU<<16U)
#define FMC_BTR1_BUSTURN_0      (0x1U<<16U)
#define FMC_BTR1_DATAST         (0xFFU<<8U)
#define FMC_BTR1_DATAST_0       (0x1U<<8U)
#define FMC_BTR1_ADDHLD         (0xFU<<4U)
#define FMC_BTR1_ADDHLD_0       (0x1U<<4U)
#define FMC_BTR1_ADDSET         (0xFU<<0U)
#define FMC_BTR1_ADDSET_0       (0x1U<<0U)

// BCR2 Configuration

#define FMC_BCR2_FMCEN          (0x1U<<31U)
#define FMC_BCR2_NBLSET         (0x3U<<22U)
#define FMC_BCR2_NBLSET_0       (0x1U<<22U)
#define FMC_BCR2_WFDIS          (0x1U<<21U)
#define FMC_BCR2_CCLKEN         (0x1U<<20U)
#define FMC_BCR2_CBURSTRW       (0x1U<<19U)
#define FMC_BCR2_CPSIZE         (0x7U<<16U)
#define FMC_BCR2_CPSIZE_0       (0x1U<<16U)
#define FMC_BCR2_ASYNCWAIT      (0x1U<<15U)
#define FMC_BCR2_EXTMOD         (0x1U<<14U)
#define FMC_BCR2_WAITEN         (0x1U<<13U)
#define FMC_BCR2_WREN           (0x1U<<12U)
#define FMC_BCR2_WAITCFG        (0x1U<<11U)
#define FMC_BCR2_WAITPOL        (0x1U<<9U)
#define FMC_BCR2_BURSTEN        (0x1U<<8U)
#define FMC_BCR2_FACCEN         (0x1U<<6U)
#define FMC_BCR2_MWID           (0x3U<<4U)
#define FMC_BCR2_MWID_0         (0x1U<<4U)
#define FMC_BCR2_MTYP           (0x3U<<2U)
#define FMC_BCR2_MTYP_0         (0x1U<<2U)
#define FMC_BCR2_MUXEN          (0x1U<<1U)
#define FMC_BCR2_MBKEN          (0x1U<<0U)

// BTR2 Configuration

#define FMC_BTR2_DATAHLD        (0x3U<<30U)
#define FMC_BTR2_DATAHLD_0      (0x1U<<30U)
#define FMC_BTR2_ACCMOD         (0x3U<<28U)
#define FMC_BTR2_ACCMOD_0       (0x1U<<28U)
#define FMC_BTR2_DATLAT         (0xFU<<24U)
#define FMC_BTR2_DATLAT_0       (0x1U<<24U)
#define FMC_BTR2_CLKDIV         (0xFU<<20U)
#define FMC_BTR2_CLKDIV_0       (0x1U<<20U)
#define FMC_BTR2_BUSTURN        (0xFU<<16U)
#define FMC_BTR2_BUSTURN_0      (0x1U<<16U)
#define FMC_BTR2_DATAST         (0xFFU<<8U)
#define FMC_BTR2_DATAST_0       (0x1U<<8U)
#define FMC_BTR2_ADDHLD         (0xFU<<4U)
#define FMC_BTR2_ADDHLD_0       (0x1U<<4U)
#define FMC_BTR2_ADDSET         (0xFU<<0U)
#define FMC_BTR2_ADDSET_0       (0x1U<<0U)

// BCR3 Configuration

#define FMC_BCR3_FMCEN          (0x1U<<31U)
#define FMC_BCR3_NBLSET         (0x3U<<22U)
#define FMC_BCR3_NBLSET_0       (0x1U<<22U)
#define FMC_BCR3_WFDIS          (0x1U<<21U)
#define FMC_BCR3_CCLKEN         (0x1U<<20U)
#define FMC_BCR3_CBURSTRW       (0x1U<<19U)
#define FMC_BCR3_CPSIZE         (0x7U<<16U)
#define FMC_BCR3_CPSIZE_0       (0x1U<<16U)
#define FMC_BCR3_ASYNCWAIT      (0x1U<<15U)
#define FMC_BCR3_EXTMOD         (0x1U<<14U)
#define FMC_BCR3_WAITEN         (0x1U<<13U)
#define FMC_BCR3_WREN           (0x1U<<12U)
#define FMC_BCR3_WAITCFG        (0x1U<<11U)
#define FMC_BCR3_WAITPOL        (0x1U<<9U)
#define FMC_BCR3_BURSTEN        (0x1U<<8U)
#define FMC_BCR3_FACCEN         (0x1U<<6U)
#define FMC_BCR3_MWID           (0x3U<<4U)
#define FMC_BCR3_MWID_0         (0x1U<<4U)
#define FMC_BCR3_MTYP           (0x3U<<2U)
#define FMC_BCR3_MTYP_0         (0x1U<<2U)
#define FMC_BCR3_MUXEN          (0x1U<<1U)
#define FMC_BCR3_MBKEN          (0x1U<<0U)

// BTR3 Configuration

#define FMC_BTR3_DATAHLD        (0x3U<<30U)
#define FMC_BTR3_DATAHLD_0      (0x1U<<30U)
#define FMC_BTR3_ACCMOD         (0x3U<<28U)
#define FMC_BTR3_ACCMOD_0       (0x1U<<28U)
#define FMC_BTR3_DATLAT         (0xFU<<24U)
#define FMC_BTR3_DATLAT_0       (0x1U<<24U)
#define FMC_BTR3_CLKDIV         (0xFU<<20U)
#define FMC_BTR3_CLKDIV_0       (0x1U<<20U)
#define FMC_BTR3_BUSTURN        (0xFU<<16U)
#define FMC_BTR3_BUSTURN_0      (0x1U<<16U)
#define FMC_BTR3_DATAST         (0xFFU<<8U)
#define FMC_BTR3_DATAST_0       (0x1U<<8U)
#define FMC_BTR3_ADDHLD         (0xFU<<4U)
#define FMC_BTR3_ADDHLD_0       (0x1U<<4U)
#define FMC_BTR3_ADDSET         (0xFU<<0U)
#define FMC_BTR3_ADDSET_0       (0x1U<<0U)

// BCR4 Configuration

#define FMC_BCR4_FMCEN          (0x1U<<31U)
#define FMC_BCR4_NBLSET         (0x3U<<22U)
#define FMC_BCR4_NBLSET_0       (0x1U<<22U)
#define FMC_BCR4_WFDIS          (0x1U<<21U)
#define FMC_BCR4_CCLKEN         (0x1U<<20U)
#define FMC_BCR4_CBURSTRW       (0x1U<<19U)
#define FMC_BCR4_CPSIZE         (0x7U<<16U)
#define FMC_BCR4_CPSIZE_0       (0x1U<<16U)
#define FMC_BCR4_ASYNCWAIT      (0x1U<<15U)
#define FMC_BCR4_EXTMOD         (0x1U<<14U)
#define FMC_BCR4_WAITEN         (0x1U<<13U)
#define FMC_BCR4_WREN           (0x1U<<12U)
#define FMC_BCR4_WAITCFG        (0x1U<<11U)
#define FMC_BCR4_WAITPOL        (0x1U<<9U)
#define FMC_BCR4_BURSTEN        (0x1U<<8U)
#define FMC_BCR4_FACCEN         (0x1U<<6U)
#define FMC_BCR4_MWID           (0x3U<<4U)
#define FMC_BCR4_MWID_0         (0x1U<<4U)
#define FMC_BCR4_MTYP           (0x3U<<2U)
#define FMC_BCR4_MTYP_0         (0x1U<<2U)
#define FMC_BCR4_MUXEN          (0x1U<<1U)
#define FMC_BCR4_MBKEN          (0x1U<<0U)

// BTR4 Configuration

#define FMC_BTR4_DATAHLD        (0x3U<<30U)
#define FMC_BTR4_DATAHLD_0      (0x1U<<30U)
#define FMC_BTR4_ACCMOD         (0x3U<<28U)
#define FMC_BTR4_ACCMOD_0       (0x1U<<28U)
#define FMC_BTR4_DATLAT         (0xFU<<24U)
#define FMC_BTR4_DATLAT_0       (0x1U<<24U)
#define FMC_BTR4_CLKDIV         (0xFU<<20U)
#define FMC_BTR4_CLKDIV_0       (0x1U<<20U)
#define FMC_BTR4_BUSTURN        (0xFU<<16U)
#define FMC_BTR4_BUSTURN_0      (0x1U<<16U)
#define FMC_BTR4_DATAST         (0xFFU<<8U)
#define FMC_BTR4_DATAST_0       (0x1U<<8U)
#define FMC_BTR4_ADDHLD         (0xFU<<4U)
#define FMC_BTR4_ADDHLD_0       (0x1U<<4U)
#define FMC_BTR4_ADDSET         (0xFU<<0U)
#define FMC_BTR4_ADDSET_0       (0x1U<<0U)

// PCSCNTR Configuration

#define FMC_PCSCNTR_CNTB4EN     (0x1U<<19U)
#define FMC_PCSCNTR_CNTB3EN     (0x1U<<18U)
#define FMC_PCSCNTR_CNTB2EN     (0x1U<<17U)
#define FMC_PCSCNTR_CNTB1EN     (0x1U<<16U)
#define FMC_PCSCNTR_CSCOUNT     (0xFFFFU<<0U)
#define FMC_PCSCNTR_CSCOUNT_0   (0x1U<<0U)

// PCR Configuration

#define FMC_PCR_ECCPS           (0x7U<<17U)
#define FMC_PCR_ECCPS_0         (0x1U<<17U)
#define FMC_PCR_TAR             (0x7U<<13U)
#define FMC_PCR_TAR_0           (0x1U<<13U)
#define FMC_PCR_TCLR            (0xFU<<9U)
#define FMC_PCR_TCLR_0          (0x1U<<9U)
#define FMC_PCR_ECCEN           (0x1U<<6U)
#define FMC_PCR_PWID            (0x3U<<4U)
#define FMC_PCR_PWID_0          (0x1U<<4U)
#define FMC_PCR_PTYP            (0x1U<<3U)
#define FMC_PCR_PBKEN           (0x1U<<2U)
#define FMC_PCR_PWAITEN         (0x1U<<1U)

// SR Configuration

#define FMC_SR_FEMPT            (0x1U<<6U)
#define FMC_SR_IFEN             (0x1U<<5U)
#define FMC_SR_ILEN             (0x1U<<4U)
#define FMC_SR_IREN             (0x1U<<3U)
#define FMC_SR_IFS              (0x1U<<2U)
#define FMC_SR_ILS              (0x1U<<1U)
#define FMC_SR_IRS              (0x1U<<0U)

// PMEM Configuration

#define FMC_PMEM_MEMHIZ         (0xFFU<<24U)
#define FMC_PMEM_MEMHIZ_0       (0x1U<<24U)
#define FMC_PMEM_MEMHOLD        (0xFFU<<16U)
#define FMC_PMEM_MEMHOLD_0      (0x1U<<16U)
#define FMC_PMEM_MEMWAIT        (0xFFU<<8U)
#define FMC_PMEM_MEMWAIT_0      (0x1U<<8U)
#define FMC_PMEM_MEMSET         (0xFFU<<0U)
#define FMC_PMEM_MEMSET_0       (0x1U<<0U)

// PATT Configuration

#define FMC_PATT_ATTHIZ         (0xFFU<<24U)
#define FMC_PATT_ATTHIZ_0       (0x1U<<24U)
#define FMC_PATT_ATTHOLD        (0xFFU<<16U)
#define FMC_PATT_ATTHOLD_0      (0x1U<<16U)
#define FMC_PATT_ATTWAIT        (0xFFU<<8U)
#define FMC_PATT_ATTWAIT_0      (0x1U<<8U)
#define FMC_PATT_ATTSET         (0xFFU<<0U)
#define FMC_PATT_ATTSET_0       (0x1U<<0U)

// ECCR Configuration

#define FMC_ECCR_ECC            (0xFFFFFFFFU<<0U)
#define FMC_ECCR_ECC_0          (0x1U<<0U)

// BWTR1 Configuration

#define FMC_BWTR1_DATAHLD       (0x3U<<30U)
#define FMC_BWTR1_DATAHLD_0     (0x1U<<30U)
#define FMC_BWTR1_ACCMOD        (0x3U<<28U)
#define FMC_BWTR1_ACCMOD_0      (0x1U<<28U)
#define FMC_BWTR1_BUSTURN       (0xFU<<16U)
#define FMC_BWTR1_BUSTURN_0     (0x1U<<16U)
#define FMC_BWTR1_DATAST        (0xFFU<<8U)
#define FMC_BWTR1_DATAST_0      (0x1U<<8U)
#define FMC_BWTR1_ADDHLD        (0xFU<<4U)
#define FMC_BWTR1_ADDHLD_0      (0x1U<<4U)
#define FMC_BWTR1_ADDSET        (0xFU<<0U)
#define FMC_BWTR1_ADDSET_0      (0x1U<<0U)

// BWTR2 Configuration

#define FMC_BWTR2_DATAHLD       (0x3U<<30U)
#define FMC_BWTR2_DATAHLD_0     (0x1U<<30U)
#define FMC_BWTR2_ACCMOD        (0x3U<<28U)
#define FMC_BWTR2_ACCMOD_0      (0x1U<<28U)
#define FMC_BWTR2_BUSTURN       (0xFU<<16U)
#define FMC_BWTR2_BUSTURN_0     (0x1U<<16U)
#define FMC_BWTR2_DATAST        (0xFFU<<8U)
#define FMC_BWTR2_DATAST_0      (0x1U<<8U)
#define FMC_BWTR2_ADDHLD        (0xFU<<4U)
#define FMC_BWTR2_ADDHLD_0      (0x1U<<4U)
#define FMC_BWTR2_ADDSET        (0xFU<<0U)
#define FMC_BWTR2_ADDSET_0      (0x1U<<0U)

// BWTR3 Configuration

#define FMC_BWTR3_DATAHLD       (0x3U<<30U)
#define FMC_BWTR3_DATAHLD_0     (0x1U<<30U)
#define FMC_BWTR3_ACCMOD        (0x3U<<28U)
#define FMC_BWTR3_ACCMOD_0      (0x1U<<28U)
#define FMC_BWTR3_BUSTURN       (0xFU<<16U)
#define FMC_BWTR3_BUSTURN_0     (0x1U<<16U)
#define FMC_BWTR3_DATAST        (0xFFU<<8U)
#define FMC_BWTR3_DATAST_0      (0x1U<<8U)
#define FMC_BWTR3_ADDHLD        (0xFU<<4U)
#define FMC_BWTR3_ADDHLD_0      (0x1U<<4U)
#define FMC_BWTR3_ADDSET        (0xFU<<0U)
#define FMC_BWTR3_ADDSET_0      (0x1U<<0U)

// BWTR4 Configuration

#define FMC_BWTR4_DATAHLD       (0x3U<<30U)
#define FMC_BWTR4_DATAHLD_0     (0x1U<<30U)
#define FMC_BWTR4_ACCMOD        (0x3U<<28U)
#define FMC_BWTR4_ACCMOD_0      (0x1U<<28U)
#define FMC_BWTR4_BUSTURN       (0xFU<<16U)
#define FMC_BWTR4_BUSTURN_0     (0x1U<<16U)
#define FMC_BWTR4_DATAST        (0xFFU<<8U)
#define FMC_BWTR4_DATAST_0      (0x1U<<8U)
#define FMC_BWTR4_ADDHLD        (0xFU<<4U)
#define FMC_BWTR4_ADDHLD_0      (0x1U<<4U)
#define FMC_BWTR4_ADDSET        (0xFU<<0U)
#define FMC_BWTR4_ADDSET_0      (0x1U<<0U)
