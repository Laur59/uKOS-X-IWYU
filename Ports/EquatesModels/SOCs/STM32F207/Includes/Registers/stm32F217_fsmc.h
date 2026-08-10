/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_fsmc equates.
 */

#pragma once

#include    <stdint.h>

// FSMC address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    BCR1;
    volatile    uint32_t    BTR1;
    volatile    uint32_t    BCR2;
    volatile    uint32_t    BTR2;
    volatile    uint32_t    BCR3;
    volatile    uint32_t    BTR3;
    volatile    uint32_t    BCR4;
    volatile    uint32_t    BTR4;
    volatile    uint32_t    RESERVED0[16];
    volatile    uint32_t    PCR2;
    volatile    uint32_t    SR2;
    volatile    uint32_t    PMEM2;
    volatile    uint32_t    PATT2;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    ECCR2;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    PCR3;
    volatile    uint32_t    SR3;
    volatile    uint32_t    PMEM3;
    volatile    uint32_t    PATT3;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    ECCR3;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    PCR4;
    volatile    uint32_t    SR4;
    volatile    uint32_t    PMEM4;
    volatile    uint32_t    PATT4;
    volatile    uint32_t    PIO4;
    volatile    uint32_t    RESERVED5[20];
    volatile    uint32_t    BWTR1;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    BWTR2;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    BWTR3;
    volatile    uint32_t    RESERVED8;
    volatile    uint32_t    BWTR4;
} FSMC_TypeDef;

#ifdef __cplusplus
#define FSMC    reinterpret_cast<FSMC_TypeDef *>(0xA0000000U)

#else
#define FSMC    ((FSMC_TypeDef *)0xA0000000U)
#endif

// BCR1 Configuration

#define FSMC_BCR1_MBKEN         (0x1U<<0U)
#define FSMC_BCR1_MUXEN         (0x1U<<1U)
#define FSMC_BCR1_MTYP          (0x3U<<2U)
#define FSMC_BCR1_MTYP_0        (0x1U<<2U)
#define FSMC_BCR1_MWID          (0x3U<<4U)
#define FSMC_BCR1_MWID_0        (0x1U<<4U)
#define FSMC_BCR1_FACCEN        (0x1U<<6U)
#define FSMC_BCR1_BURSTEN       (0x1U<<8U)
#define FSMC_BCR1_WAITPOL       (0x1U<<9U)
#define FSMC_BCR1_WAITCFG       (0x1U<<11U)
#define FSMC_BCR1_WREN          (0x1U<<12U)
#define FSMC_BCR1_WAITEN        (0x1U<<13U)
#define FSMC_BCR1_EXTMOD        (0x1U<<14U)
#define FSMC_BCR1_ASYNCWAIT     (0x1U<<15U)
#define FSMC_BCR1_CBURSTRW      (0x1U<<19U)

// BTR1 Configuration

#define FSMC_BTR1_ADDSET        (0xFU<<0U)
#define FSMC_BTR1_ADDSET_0      (0x1U<<0U)
#define FSMC_BTR1_ADDHLD        (0xFU<<4U)
#define FSMC_BTR1_ADDHLD_0      (0x1U<<4U)
#define FSMC_BTR1_DATAST        (0xFFU<<8U)
#define FSMC_BTR1_DATAST_0      (0x1U<<8U)
#define FSMC_BTR1_BUSTURN       (0xFU<<16U)
#define FSMC_BTR1_BUSTURN_0     (0x1U<<16U)
#define FSMC_BTR1_CLKDIV        (0xFU<<20U)
#define FSMC_BTR1_CLKDIV_0      (0x1U<<20U)
#define FSMC_BTR1_DATLAT        (0xFU<<24U)
#define FSMC_BTR1_DATLAT_0      (0x1U<<24U)
#define FSMC_BTR1_ACCMOD        (0x3U<<28U)
#define FSMC_BTR1_ACCMOD_0      (0x1U<<28U)

// BCR2 Configuration

#define FSMC_BCR2_MBKEN         (0x1U<<0U)
#define FSMC_BCR2_MUXEN         (0x1U<<1U)
#define FSMC_BCR2_MTYP          (0x3U<<2U)
#define FSMC_BCR2_MTYP_0        (0x1U<<2U)
#define FSMC_BCR2_MWID          (0x3U<<4U)
#define FSMC_BCR2_MWID_0        (0x1U<<4U)
#define FSMC_BCR2_FACCEN        (0x1U<<6U)
#define FSMC_BCR2_BURSTEN       (0x1U<<8U)
#define FSMC_BCR2_WAITPOL       (0x1U<<9U)
#define FSMC_BCR2_WRAPMOD       (0x1U<<10U)
#define FSMC_BCR2_WAITCFG       (0x1U<<11U)
#define FSMC_BCR2_WREN          (0x1U<<12U)
#define FSMC_BCR2_WAITEN        (0x1U<<13U)
#define FSMC_BCR2_EXTMOD        (0x1U<<14U)
#define FSMC_BCR2_ASYNCWAIT     (0x1U<<15U)
#define FSMC_BCR2_CBURSTRW      (0x1U<<19U)

// BTR2 Configuration

#define FSMC_BTR2_ADDSET        (0xFU<<0U)
#define FSMC_BTR2_ADDSET_0      (0x1U<<0U)
#define FSMC_BTR2_ADDHLD        (0xFU<<4U)
#define FSMC_BTR2_ADDHLD_0      (0x1U<<4U)
#define FSMC_BTR2_DATAST        (0xFFU<<8U)
#define FSMC_BTR2_DATAST_0      (0x1U<<8U)
#define FSMC_BTR2_BUSTURN       (0xFU<<16U)
#define FSMC_BTR2_BUSTURN_0     (0x1U<<16U)
#define FSMC_BTR2_CLKDIV        (0xFU<<20U)
#define FSMC_BTR2_CLKDIV_0      (0x1U<<20U)
#define FSMC_BTR2_DATLAT        (0xFU<<24U)
#define FSMC_BTR2_DATLAT_0      (0x1U<<24U)
#define FSMC_BTR2_ACCMOD        (0x3U<<28U)
#define FSMC_BTR2_ACCMOD_0      (0x1U<<28U)

// BCR3 Configuration

#define FSMC_BCR3_MBKEN         (0x1U<<0U)
#define FSMC_BCR3_MUXEN         (0x1U<<1U)
#define FSMC_BCR3_MTYP          (0x3U<<2U)
#define FSMC_BCR3_MTYP_0        (0x1U<<2U)
#define FSMC_BCR3_MWID          (0x3U<<4U)
#define FSMC_BCR3_MWID_0        (0x1U<<4U)
#define FSMC_BCR3_FACCEN        (0x1U<<6U)
#define FSMC_BCR3_BURSTEN       (0x1U<<8U)
#define FSMC_BCR3_WAITPOL       (0x1U<<9U)
#define FSMC_BCR3_WRAPMOD       (0x1U<<10U)
#define FSMC_BCR3_WAITCFG       (0x1U<<11U)
#define FSMC_BCR3_WREN          (0x1U<<12U)
#define FSMC_BCR3_WAITEN        (0x1U<<13U)
#define FSMC_BCR3_EXTMOD        (0x1U<<14U)
#define FSMC_BCR3_ASYNCWAIT     (0x1U<<15U)
#define FSMC_BCR3_CBURSTRW      (0x1U<<19U)

// BTR3 Configuration

#define FSMC_BTR3_ADDSET        (0xFU<<0U)
#define FSMC_BTR3_ADDSET_0      (0x1U<<0U)
#define FSMC_BTR3_ADDHLD        (0xFU<<4U)
#define FSMC_BTR3_ADDHLD_0      (0x1U<<4U)
#define FSMC_BTR3_DATAST        (0xFFU<<8U)
#define FSMC_BTR3_DATAST_0      (0x1U<<8U)
#define FSMC_BTR3_BUSTURN       (0xFU<<16U)
#define FSMC_BTR3_BUSTURN_0     (0x1U<<16U)
#define FSMC_BTR3_CLKDIV        (0xFU<<20U)
#define FSMC_BTR3_CLKDIV_0      (0x1U<<20U)
#define FSMC_BTR3_DATLAT        (0xFU<<24U)
#define FSMC_BTR3_DATLAT_0      (0x1U<<24U)
#define FSMC_BTR3_ACCMOD        (0x3U<<28U)
#define FSMC_BTR3_ACCMOD_0      (0x1U<<28U)

// BCR4 Configuration

#define FSMC_BCR4_MBKEN         (0x1U<<0U)
#define FSMC_BCR4_MUXEN         (0x1U<<1U)
#define FSMC_BCR4_MTYP          (0x3U<<2U)
#define FSMC_BCR4_MTYP_0        (0x1U<<2U)
#define FSMC_BCR4_MWID          (0x3U<<4U)
#define FSMC_BCR4_MWID_0        (0x1U<<4U)
#define FSMC_BCR4_FACCEN        (0x1U<<6U)
#define FSMC_BCR4_BURSTEN       (0x1U<<8U)
#define FSMC_BCR4_WAITPOL       (0x1U<<9U)
#define FSMC_BCR4_WRAPMOD       (0x1U<<10U)
#define FSMC_BCR4_WAITCFG       (0x1U<<11U)
#define FSMC_BCR4_WREN          (0x1U<<12U)
#define FSMC_BCR4_WAITEN        (0x1U<<13U)
#define FSMC_BCR4_EXTMOD        (0x1U<<14U)
#define FSMC_BCR4_ASYNCWAIT     (0x1U<<15U)
#define FSMC_BCR4_CBURSTRW      (0x1U<<19U)

// BTR4 Configuration

#define FSMC_BTR4_ADDSET        (0xFU<<0U)
#define FSMC_BTR4_ADDSET_0      (0x1U<<0U)
#define FSMC_BTR4_ADDHLD        (0xFU<<4U)
#define FSMC_BTR4_ADDHLD_0      (0x1U<<4U)
#define FSMC_BTR4_DATAST        (0xFFU<<8U)
#define FSMC_BTR4_DATAST_0      (0x1U<<8U)
#define FSMC_BTR4_BUSTURN       (0xFU<<16U)
#define FSMC_BTR4_BUSTURN_0     (0x1U<<16U)
#define FSMC_BTR4_CLKDIV        (0xFU<<20U)
#define FSMC_BTR4_CLKDIV_0      (0x1U<<20U)
#define FSMC_BTR4_DATLAT        (0xFU<<24U)
#define FSMC_BTR4_DATLAT_0      (0x1U<<24U)
#define FSMC_BTR4_ACCMOD        (0x3U<<28U)
#define FSMC_BTR4_ACCMOD_0      (0x1U<<28U)

// PCR2 Configuration

#define FSMC_PCR2_PWAITEN       (0x1U<<1U)
#define FSMC_PCR2_PBKEN         (0x1U<<2U)
#define FSMC_PCR2_PTYP          (0x1U<<3U)
#define FSMC_PCR2_PWID          (0x3U<<4U)
#define FSMC_PCR2_PWID_0        (0x1U<<4U)
#define FSMC_PCR2_ECCEN         (0x1U<<6U)
#define FSMC_PCR2_TCLR          (0xFU<<9U)
#define FSMC_PCR2_TCLR_0        (0x1U<<9U)
#define FSMC_PCR2_TAR           (0xFU<<13U)
#define FSMC_PCR2_TAR_0         (0x1U<<13U)
#define FSMC_PCR2_ECCPS         (0x7U<<17U)
#define FSMC_PCR2_ECCPS_0       (0x1U<<17U)

// SR2 Configuration

#define FSMC_SR2_IRS            (0x1U<<0U)
#define FSMC_SR2_ILS            (0x1U<<1U)
#define FSMC_SR2_IFS            (0x1U<<2U)
#define FSMC_SR2_IREN           (0x1U<<3U)
#define FSMC_SR2_ILEN           (0x1U<<4U)
#define FSMC_SR2_IFEN           (0x1U<<5U)
#define FSMC_SR2_FEMPT          (0x1U<<6U)

// PMEM2 Configuration

#define FSMC_PMEM2_MEMSETX      (0xFFU<<0U)
#define FSMC_PMEM2_MEMSETX_0    (0x1U<<0U)
#define FSMC_PMEM2_MEMWAITX     (0xFFU<<8U)
#define FSMC_PMEM2_MEMWAITX_0   (0x1U<<8U)
#define FSMC_PMEM2_MEMHOLDX     (0xFFU<<16U)
#define FSMC_PMEM2_MEMHOLDX_0   (0x1U<<16U)
#define FSMC_PMEM2_MEMHIZX      (0xFFU<<24U)
#define FSMC_PMEM2_MEMHIZX_0    (0x1U<<24U)

// PATT2 Configuration

#define FSMC_PATT2_ATTSETX      (0xFFU<<0U)
#define FSMC_PATT2_ATTSETX_0    (0x1U<<0U)
#define FSMC_PATT2_ATTWAITX     (0xFFU<<8U)
#define FSMC_PATT2_ATTWAITX_0   (0x1U<<8U)
#define FSMC_PATT2_ATTHOLDX     (0xFFU<<16U)
#define FSMC_PATT2_ATTHOLDX_0   (0x1U<<16U)
#define FSMC_PATT2_ATTHIZX      (0xFFU<<24U)
#define FSMC_PATT2_ATTHIZX_0    (0x1U<<24U)

// ECCR2 Configuration

#define FSMC_ECCR2_ECCX         (0xFFFFFFFFU<<0U)
#define FSMC_ECCR2_ECCX_0       (0x1U<<0U)

// PCR3 Configuration

#define FSMC_PCR3_PWAITEN       (0x1U<<1U)
#define FSMC_PCR3_PBKEN         (0x1U<<2U)
#define FSMC_PCR3_PTYP          (0x1U<<3U)
#define FSMC_PCR3_PWID          (0x3U<<4U)
#define FSMC_PCR3_PWID_0        (0x1U<<4U)
#define FSMC_PCR3_ECCEN         (0x1U<<6U)
#define FSMC_PCR3_TCLR          (0xFU<<9U)
#define FSMC_PCR3_TCLR_0        (0x1U<<9U)
#define FSMC_PCR3_TAR           (0xFU<<13U)
#define FSMC_PCR3_TAR_0         (0x1U<<13U)
#define FSMC_PCR3_ECCPS         (0x7U<<17U)
#define FSMC_PCR3_ECCPS_0       (0x1U<<17U)

// SR3 Configuration

#define FSMC_SR3_IRS            (0x1U<<0U)
#define FSMC_SR3_ILS            (0x1U<<1U)
#define FSMC_SR3_IFS            (0x1U<<2U)
#define FSMC_SR3_IREN           (0x1U<<3U)
#define FSMC_SR3_ILEN           (0x1U<<4U)
#define FSMC_SR3_IFEN           (0x1U<<5U)
#define FSMC_SR3_FEMPT          (0x1U<<6U)

// PMEM3 Configuration

#define FSMC_PMEM3_MEMSETX      (0xFFU<<0U)
#define FSMC_PMEM3_MEMSETX_0    (0x1U<<0U)
#define FSMC_PMEM3_MEMWAITX     (0xFFU<<8U)
#define FSMC_PMEM3_MEMWAITX_0   (0x1U<<8U)
#define FSMC_PMEM3_MEMHOLDX     (0xFFU<<16U)
#define FSMC_PMEM3_MEMHOLDX_0   (0x1U<<16U)
#define FSMC_PMEM3_MEMHIZX      (0xFFU<<24U)
#define FSMC_PMEM3_MEMHIZX_0    (0x1U<<24U)

// PATT3 Configuration

#define FSMC_PATT3_ATTSETX      (0xFFU<<0U)
#define FSMC_PATT3_ATTSETX_0    (0x1U<<0U)
#define FSMC_PATT3_ATTWAITX     (0xFFU<<8U)
#define FSMC_PATT3_ATTWAITX_0   (0x1U<<8U)
#define FSMC_PATT3_ATTHOLDX     (0xFFU<<16U)
#define FSMC_PATT3_ATTHOLDX_0   (0x1U<<16U)
#define FSMC_PATT3_ATTHIZX      (0xFFU<<24U)
#define FSMC_PATT3_ATTHIZX_0    (0x1U<<24U)

// ECCR3 Configuration

#define FSMC_ECCR3_ECCX         (0xFFFFFFFFU<<0U)
#define FSMC_ECCR3_ECCX_0       (0x1U<<0U)

// PCR4 Configuration

#define FSMC_PCR4_PWAITEN       (0x1U<<1U)
#define FSMC_PCR4_PBKEN         (0x1U<<2U)
#define FSMC_PCR4_PTYP          (0x1U<<3U)
#define FSMC_PCR4_PWID          (0x3U<<4U)
#define FSMC_PCR4_PWID_0        (0x1U<<4U)
#define FSMC_PCR4_ECCEN         (0x1U<<6U)
#define FSMC_PCR4_TCLR          (0xFU<<9U)
#define FSMC_PCR4_TCLR_0        (0x1U<<9U)
#define FSMC_PCR4_TAR           (0xFU<<13U)
#define FSMC_PCR4_TAR_0         (0x1U<<13U)
#define FSMC_PCR4_ECCPS         (0x7U<<17U)
#define FSMC_PCR4_ECCPS_0       (0x1U<<17U)

// SR4 Configuration

#define FSMC_SR4_IRS            (0x1U<<0U)
#define FSMC_SR4_ILS            (0x1U<<1U)
#define FSMC_SR4_IFS            (0x1U<<2U)
#define FSMC_SR4_IREN           (0x1U<<3U)
#define FSMC_SR4_ILEN           (0x1U<<4U)
#define FSMC_SR4_IFEN           (0x1U<<5U)
#define FSMC_SR4_FEMPT          (0x1U<<6U)

// PMEM4 Configuration

#define FSMC_PMEM4_MEMSETX      (0xFFU<<0U)
#define FSMC_PMEM4_MEMSETX_0    (0x1U<<0U)
#define FSMC_PMEM4_MEMWAITX     (0xFFU<<8U)
#define FSMC_PMEM4_MEMWAITX_0   (0x1U<<8U)
#define FSMC_PMEM4_MEMHOLDX     (0xFFU<<16U)
#define FSMC_PMEM4_MEMHOLDX_0   (0x1U<<16U)
#define FSMC_PMEM4_MEMHIZX      (0xFFU<<24U)
#define FSMC_PMEM4_MEMHIZX_0    (0x1U<<24U)

// PATT4 Configuration

#define FSMC_PATT4_ATTSETX      (0xFFU<<0U)
#define FSMC_PATT4_ATTSETX_0    (0x1U<<0U)
#define FSMC_PATT4_ATTWAITX     (0xFFU<<8U)
#define FSMC_PATT4_ATTWAITX_0   (0x1U<<8U)
#define FSMC_PATT4_ATTHOLDX     (0xFFU<<16U)
#define FSMC_PATT4_ATTHOLDX_0   (0x1U<<16U)
#define FSMC_PATT4_ATTHIZX      (0xFFU<<24U)
#define FSMC_PATT4_ATTHIZX_0    (0x1U<<24U)

// PIO4 Configuration

#define FSMC_PIO4_IOSETX        (0xFFU<<0U)
#define FSMC_PIO4_IOSETX_0      (0x1U<<0U)
#define FSMC_PIO4_IOWAITX       (0xFFU<<8U)
#define FSMC_PIO4_IOWAITX_0     (0x1U<<8U)
#define FSMC_PIO4_IOHOLDX       (0xFFU<<16U)
#define FSMC_PIO4_IOHOLDX_0     (0x1U<<16U)
#define FSMC_PIO4_IOHIZX        (0xFFU<<24U)
#define FSMC_PIO4_IOHIZX_0      (0x1U<<24U)

// BWTR1 Configuration

#define FSMC_BWTR1_ADDSET       (0xFU<<0U)
#define FSMC_BWTR1_ADDSET_0     (0x1U<<0U)
#define FSMC_BWTR1_ADDHLD       (0xFU<<4U)
#define FSMC_BWTR1_ADDHLD_0     (0x1U<<4U)
#define FSMC_BWTR1_DATAST       (0xFFU<<8U)
#define FSMC_BWTR1_DATAST_0     (0x1U<<8U)
#define FSMC_BWTR1_CLKDIV       (0xFU<<20U)
#define FSMC_BWTR1_CLKDIV_0     (0x1U<<20U)
#define FSMC_BWTR1_DATLAT       (0xFU<<24U)
#define FSMC_BWTR1_DATLAT_0     (0x1U<<24U)
#define FSMC_BWTR1_ACCMOD       (0x3U<<28U)
#define FSMC_BWTR1_ACCMOD_0     (0x1U<<28U)

// BWTR2 Configuration

#define FSMC_BWTR2_ADDSET       (0xFU<<0U)
#define FSMC_BWTR2_ADDSET_0     (0x1U<<0U)
#define FSMC_BWTR2_ADDHLD       (0xFU<<4U)
#define FSMC_BWTR2_ADDHLD_0     (0x1U<<4U)
#define FSMC_BWTR2_DATAST       (0xFFU<<8U)
#define FSMC_BWTR2_DATAST_0     (0x1U<<8U)
#define FSMC_BWTR2_CLKDIV       (0xFU<<20U)
#define FSMC_BWTR2_CLKDIV_0     (0x1U<<20U)
#define FSMC_BWTR2_DATLAT       (0xFU<<24U)
#define FSMC_BWTR2_DATLAT_0     (0x1U<<24U)
#define FSMC_BWTR2_ACCMOD       (0x3U<<28U)
#define FSMC_BWTR2_ACCMOD_0     (0x1U<<28U)

// BWTR3 Configuration

#define FSMC_BWTR3_ADDSET       (0xFU<<0U)
#define FSMC_BWTR3_ADDSET_0     (0x1U<<0U)
#define FSMC_BWTR3_ADDHLD       (0xFU<<4U)
#define FSMC_BWTR3_ADDHLD_0     (0x1U<<4U)
#define FSMC_BWTR3_DATAST       (0xFFU<<8U)
#define FSMC_BWTR3_DATAST_0     (0x1U<<8U)
#define FSMC_BWTR3_CLKDIV       (0xFU<<20U)
#define FSMC_BWTR3_CLKDIV_0     (0x1U<<20U)
#define FSMC_BWTR3_DATLAT       (0xFU<<24U)
#define FSMC_BWTR3_DATLAT_0     (0x1U<<24U)
#define FSMC_BWTR3_ACCMOD       (0x3U<<28U)
#define FSMC_BWTR3_ACCMOD_0     (0x1U<<28U)

// BWTR4 Configuration

#define FSMC_BWTR4_ADDSET       (0xFU<<0U)
#define FSMC_BWTR4_ADDSET_0     (0x1U<<0U)
#define FSMC_BWTR4_ADDHLD       (0xFU<<4U)
#define FSMC_BWTR4_ADDHLD_0     (0x1U<<4U)
#define FSMC_BWTR4_DATAST       (0xFFU<<8U)
#define FSMC_BWTR4_DATAST_0     (0x1U<<8U)
#define FSMC_BWTR4_CLKDIV       (0xFU<<20U)
#define FSMC_BWTR4_CLKDIV_0     (0x1U<<20U)
#define FSMC_BWTR4_DATLAT       (0xFU<<24U)
#define FSMC_BWTR4_DATLAT_0     (0x1U<<24U)
#define FSMC_BWTR4_ACCMOD       (0x3U<<28U)
#define FSMC_BWTR4_ACCMOD_0     (0x1U<<28U)
