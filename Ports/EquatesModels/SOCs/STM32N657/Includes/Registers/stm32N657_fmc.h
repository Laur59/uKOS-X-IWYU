/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_fmc.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_fmc equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
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
    volatile    uint32_t    CFGR;
    volatile    uint32_t    RESERVED0[23];
    volatile    uint32_t    PCR;
    volatile    uint32_t    SR;
    volatile    uint32_t    PMEM;
    volatile    uint32_t    PATT;
    volatile    uint32_t    HPR;
    volatile    uint32_t    HECCR;
    volatile    uint32_t    RESERVED1[27];
    volatile    uint32_t    BWTR1;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    BWTR2;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    BWTR3;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    BWTR4;
    volatile    uint32_t    RESERVED5[8];
    volatile    uint32_t    SDCR1;
    volatile    uint32_t    SDCR2;
    volatile    uint32_t    SDTR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    SDCMR;
    volatile    uint32_t    SDRTR;
    volatile    uint32_t    SDSR;
    volatile    uint32_t    RESERVED7[9];
    volatile    uint32_t    IER;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    RESERVED8[29];
    volatile    uint32_t    CSQCR;
    volatile    uint32_t    CSQCFGR1;
    volatile    uint32_t    CSQCFGR2;
    volatile    uint32_t    CSQCFGR3;
    volatile    uint32_t    CSQAR1;
    volatile    uint32_t    CSQAR2;
    volatile    uint32_t    RESERVED9[2];
    volatile    uint32_t    CSQIER;
    volatile    uint32_t    CSQISR;
    volatile    uint32_t    CSQICR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    CSQEMSR;
    volatile    uint32_t    RESERVED11[7];
    volatile    uint32_t    BCHIER;
    volatile    uint32_t    BCHISR;
    volatile    uint32_t    BCHICR;
    volatile    uint32_t    RESERVED12;
    volatile    uint32_t    BCHPBR1;
    volatile    uint32_t    BCHPBR2;
    volatile    uint32_t    BCHPBR3;
    volatile    uint32_t    BCHPBR4;
    volatile    uint32_t    RESERVED13[3];
    volatile    uint32_t    BCHDSR0;
    volatile    uint32_t    BCHDSR1;
    volatile    uint32_t    BCHDSR2;
    volatile    uint32_t    BCHDSR3;
    volatile    uint32_t    BCHDSR4;
} FMC_TypeDef;

#ifdef __cplusplus
#define FMC1_NS reinterpret_cast<FMC_TypeDef *>(0x48024000U)
#define FMC1_S  reinterpret_cast<FMC_TypeDef *>(0x58024000U)

#else
#define FMC1_NS ((FMC_TypeDef *)0x48024000U)
#define FMC1_S  ((FMC_TypeDef *)0x58024000U)
#endif

// BCR1 Configuration

#define FMC_BCR1_NBLSET             (0x3U<<22)
#define FMC_BCR1_NBLSET_0           (0x1U<<22)
#define FMC_BCR1_CSCOUNT0           (0x3U<<20)
#define FMC_BCR1_CSCOUNT0_0         (0x1U<<20)
#define FMC_BCR1_CBURSTRW           (0x1U<<19)
#define FMC_BCR1_CPSIZE             (0x7U<<16)
#define FMC_BCR1_CPSIZE_0           (0x1U<<16)
#define FMC_BCR1_ASYNCWAIT          (0x1U<<15)
#define FMC_BCR1_EXTMOD             (0x1U<<14)
#define FMC_BCR1_WAITEN             (0x1U<<13)
#define FMC_BCR1_WREN               (0x1U<<12)
#define FMC_BCR1_WAITCFG            (0x1U<<11)
#define FMC_BCR1_WAITPOL            (0x1U<<9)
#define FMC_BCR1_BURSTEN            (0x1U<<8)
#define FMC_BCR1_FACCEN             (0x1U<<6)
#define FMC_BCR1_MWID               (0x3U<<4)
#define FMC_BCR1_MWID_0             (0x1U<<4)
#define FMC_BCR1_MTYP               (0x3U<<2)
#define FMC_BCR1_MTYP_0             (0x1U<<2)
#define FMC_BCR1_MUXEN              (0x1U<<1)
#define FMC_BCR1_MBKEN              (0x1U<<0)

#define FMC_BCR1_NBLSET_B_0X0       (0x0U<<22)
#define FMC_BCR1_NBLSET_B_0X1       (0x1U<<22)
#define FMC_BCR1_NBLSET_B_0X2       (0x2U<<22)
#define FMC_BCR1_NBLSET_B_0X3       (0x3U<<22)
#define FMC_BCR1_CSCOUNT0_B_0X0     (0x0U<<20)
#define FMC_BCR1_CSCOUNT0_B_0X1     (0x1U<<20)
#define FMC_BCR1_CSCOUNT0_B_0X2     (0x2U<<20)
#define FMC_BCR1_CSCOUNT0_B_0X3     (0x3U<<20)
#define FMC_BCR1_CBURSTRW_B_0X0     (0x0U<<19)
#define FMC_BCR1_CBURSTRW_B_0X1     (0x1U<<19)
#define FMC_BCR1_CPSIZE_B_0X0       (0x0U<<16)
#define FMC_BCR1_CPSIZE_B_0X1       (0x1U<<16)
#define FMC_BCR1_CPSIZE_B_0X2       (0x2U<<16)
#define FMC_BCR1_CPSIZE_B_0X3       (0x3U<<16)
#define FMC_BCR1_CPSIZE_B_0X4       (0x4U<<16)
#define FMC_BCR1_ASYNCWAIT_B_0X0    (0x0U<<15)
#define FMC_BCR1_ASYNCWAIT_B_0X1    (0x1U<<15)
#define FMC_BCR1_EXTMOD_B_0X0       (0x0U<<14)
#define FMC_BCR1_EXTMOD_B_0X1       (0x1U<<14)
#define FMC_BCR1_WAITEN_B_0X0       (0x0U<<13)
#define FMC_BCR1_WAITEN_B_0X1       (0x1U<<13)
#define FMC_BCR1_WREN_B_0X0         (0x0U<<12)
#define FMC_BCR1_WREN_B_0X1         (0x1U<<12)
#define FMC_BCR1_WAITCFG_B_0X0      (0x0U<<11)
#define FMC_BCR1_WAITCFG_B_0X1      (0x1U<<11)
#define FMC_BCR1_WAITPOL_B_0X0      (0x0U<<9)
#define FMC_BCR1_WAITPOL_B_0X1      (0x1U<<9)
#define FMC_BCR1_BURSTEN_B_0X0      (0x0U<<8)
#define FMC_BCR1_BURSTEN_B_0X1      (0x1U<<8)
#define FMC_BCR1_FACCEN_B_0X0       (0x0U<<6)
#define FMC_BCR1_FACCEN_B_0X1       (0x1U<<6)
#define FMC_BCR1_MWID_B_0X0         (0x0U<<4)
#define FMC_BCR1_MWID_B_0X1         (0x1U<<4)
#define FMC_BCR1_MWID_B_0X2         (0x2U<<4)
#define FMC_BCR1_MTYP_B_0X0         (0x0U<<2)
#define FMC_BCR1_MTYP_B_0X1         (0x1U<<2)
#define FMC_BCR1_MTYP_B_0X2         (0x2U<<2)
#define FMC_BCR1_MUXEN_B_0X0        (0x0U<<1)
#define FMC_BCR1_MUXEN_B_0X1        (0x1U<<1)
#define FMC_BCR1_MBKEN_B_0X0        (0x0U<<0)
#define FMC_BCR1_MBKEN_B_0X1        (0x1U<<0)

// BTR1 Configuration

#define FMC_BTR1_DATAHLD            (0x3U<<30)
#define FMC_BTR1_DATAHLD_0          (0x1U<<30)
#define FMC_BTR1_ACCMOD             (0x3U<<28)
#define FMC_BTR1_ACCMOD_0           (0x1U<<28)
#define FMC_BTR1_DATLAT             (0xFU<<24)
#define FMC_BTR1_DATLAT_0           (0x1U<<24)
#define FMC_BTR1_CLKDIV             (0xFU<<20)
#define FMC_BTR1_CLKDIV_0           (0x1U<<20)
#define FMC_BTR1_BUSTURN            (0xFU<<16)
#define FMC_BTR1_BUSTURN_0          (0x1U<<16)
#define FMC_BTR1_DATAST             (0xFFU<<8)
#define FMC_BTR1_DATAST_0           (0x1U<<8)
#define FMC_BTR1_ADDHLD             (0xFU<<4)
#define FMC_BTR1_ADDHLD_0           (0x1U<<4)
#define FMC_BTR1_ADDSET             (0xFU<<0)
#define FMC_BTR1_ADDSET_0           (0x1U<<0)

#define FMC_BTR1_DATAHLD_B_0X0      (0x0U<<30)
#define FMC_BTR1_DATAHLD_B_0X1      (0x1U<<30)
#define FMC_BTR1_DATAHLD_B_0X2      (0x2U<<30)
#define FMC_BTR1_DATAHLD_B_0X3      (0x3U<<30)
#define FMC_BTR1_ACCMOD_B_0X0       (0x0U<<28)
#define FMC_BTR1_ACCMOD_B_0X1       (0x1U<<28)
#define FMC_BTR1_ACCMOD_B_0X2       (0x2U<<28)
#define FMC_BTR1_ACCMOD_B_0X3       (0x3U<<28)
#define FMC_BTR1_DATLAT_B_0X0       (0x0U<<24)
#define FMC_BTR1_DATLAT_B_0XF       (0xFU<<24)
#define FMC_BTR1_CLKDIV_B_0X0       (0x0U<<20)
#define FMC_BTR1_CLKDIV_B_0X1       (0x1U<<20)
#define FMC_BTR1_CLKDIV_B_0X2       (0x2U<<20)
#define FMC_BTR1_CLKDIV_B_0XF       (0xFU<<20)
#define FMC_BTR1_BUSTURN_B_0X0      (0x0U<<16)
#define FMC_BTR1_BUSTURN_B_0XF      (0xFU<<16)
#define FMC_BTR1_DATAST_B_0X1       (0x1U<<8)
#define FMC_BTR1_DATAST_B_0X2       (0x2U<<8)
#define FMC_BTR1_DATAST_B_0XFF      (0xFFU<<8)
#define FMC_BTR1_ADDHLD_B_0X1       (0x1U<<4)
#define FMC_BTR1_ADDHLD_B_0X2       (0x2U<<4)
#define FMC_BTR1_ADDHLD_B_0XF       (0xFU<<4)
#define FMC_BTR1_ADDSET_B_0X0       (0x0U<<0)
#define FMC_BTR1_ADDSET_B_0XF       (0xFU<<0)

// BCR2 Configuration

#define FMC_BCR2_NBLSET             (0x3U<<22)
#define FMC_BCR2_NBLSET_0           (0x1U<<22)
#define FMC_BCR2_CSCOUNT1           (0x1U<<21)
#define FMC_BCR2_CSCOUNT0           (0x1U<<20)
#define FMC_BCR2_CBURSTRW           (0x1U<<19)
#define FMC_BCR2_CPSIZE             (0x7U<<16)
#define FMC_BCR2_CPSIZE_0           (0x1U<<16)
#define FMC_BCR2_ASYNCWAIT          (0x1U<<15)
#define FMC_BCR2_EXTMOD             (0x1U<<14)
#define FMC_BCR2_WAITEN             (0x1U<<13)
#define FMC_BCR2_WREN               (0x1U<<12)
#define FMC_BCR2_WAITCFG            (0x1U<<11)
#define FMC_BCR2_WAITPOL            (0x1U<<9)
#define FMC_BCR2_BURSTEN            (0x1U<<8)
#define FMC_BCR2_FACCEN             (0x1U<<6)
#define FMC_BCR2_MWID               (0x3U<<4)
#define FMC_BCR2_MWID_0             (0x1U<<4)
#define FMC_BCR2_MTYP               (0x3U<<2)
#define FMC_BCR2_MTYP_0             (0x1U<<2)
#define FMC_BCR2_MUXEN              (0x1U<<1)
#define FMC_BCR2_MBKEN              (0x1U<<0)

#define FMC_BCR2_NBLSET_B_0X0       (0x0U<<22)
#define FMC_BCR2_NBLSET_B_0X1       (0x1U<<22)
#define FMC_BCR2_NBLSET_B_0X2       (0x2U<<22)
#define FMC_BCR2_NBLSET_B_0X3       (0x3U<<22)
#define FMC_BCR2_CSCOUNT1_B_0X0     (0x0U<<21)
#define FMC_BCR2_CSCOUNT1_B_0X1     (0x1U<<21)
#define FMC_BCR2_CSCOUNT0_B_0X0     (0x0U<<20)
#define FMC_BCR2_CSCOUNT0_B_0X1     (0x1U<<20)
#define FMC_BCR2_CBURSTRW_B_0X0     (0x0U<<19)
#define FMC_BCR2_CBURSTRW_B_0X1     (0x1U<<19)
#define FMC_BCR2_CPSIZE_B_0X0       (0x0U<<16)
#define FMC_BCR2_CPSIZE_B_0X1       (0x1U<<16)
#define FMC_BCR2_CPSIZE_B_0X2       (0x2U<<16)
#define FMC_BCR2_CPSIZE_B_0X3       (0x3U<<16)
#define FMC_BCR2_CPSIZE_B_0X4       (0x4U<<16)
#define FMC_BCR2_ASYNCWAIT_B_0X0    (0x0U<<15)
#define FMC_BCR2_ASYNCWAIT_B_0X1    (0x1U<<15)
#define FMC_BCR2_EXTMOD_B_0X0       (0x0U<<14)
#define FMC_BCR2_EXTMOD_B_0X1       (0x1U<<14)
#define FMC_BCR2_WAITEN_B_0X0       (0x0U<<13)
#define FMC_BCR2_WAITEN_B_0X1       (0x1U<<13)
#define FMC_BCR2_WREN_B_0X0         (0x0U<<12)
#define FMC_BCR2_WREN_B_0X1         (0x1U<<12)
#define FMC_BCR2_WAITCFG_B_0X0      (0x0U<<11)
#define FMC_BCR2_WAITCFG_B_0X1      (0x1U<<11)
#define FMC_BCR2_WAITPOL_B_0X0      (0x0U<<9)
#define FMC_BCR2_WAITPOL_B_0X1      (0x1U<<9)
#define FMC_BCR2_BURSTEN_B_0X0      (0x0U<<8)
#define FMC_BCR2_BURSTEN_B_0X1      (0x1U<<8)
#define FMC_BCR2_FACCEN_B_0X0       (0x0U<<6)
#define FMC_BCR2_FACCEN_B_0X1       (0x1U<<6)
#define FMC_BCR2_MWID_B_0X0         (0x0U<<4)
#define FMC_BCR2_MWID_B_0X1         (0x1U<<4)
#define FMC_BCR2_MWID_B_0X2         (0x2U<<4)
#define FMC_BCR2_MTYP_B_0X0         (0x0U<<2)
#define FMC_BCR2_MTYP_B_0X1         (0x1U<<2)
#define FMC_BCR2_MTYP_B_0X2         (0x2U<<2)
#define FMC_BCR2_MUXEN_B_0X0        (0x0U<<1)
#define FMC_BCR2_MUXEN_B_0X1        (0x1U<<1)
#define FMC_BCR2_MBKEN_B_0X0        (0x0U<<0)
#define FMC_BCR2_MBKEN_B_0X1        (0x1U<<0)

// BTR2 Configuration

#define FMC_BTR2_DATAHLD            (0x3U<<30)
#define FMC_BTR2_DATAHLD_0          (0x1U<<30)
#define FMC_BTR2_ACCMOD             (0x3U<<28)
#define FMC_BTR2_ACCMOD_0           (0x1U<<28)
#define FMC_BTR2_DATLAT             (0xFU<<24)
#define FMC_BTR2_DATLAT_0           (0x1U<<24)
#define FMC_BTR2_CLKDIV             (0xFU<<20)
#define FMC_BTR2_CLKDIV_0           (0x1U<<20)
#define FMC_BTR2_BUSTURN            (0xFU<<16)
#define FMC_BTR2_BUSTURN_0          (0x1U<<16)
#define FMC_BTR2_DATAST             (0xFFU<<8)
#define FMC_BTR2_DATAST_0           (0x1U<<8)
#define FMC_BTR2_ADDHLD             (0xFU<<4)
#define FMC_BTR2_ADDHLD_0           (0x1U<<4)
#define FMC_BTR2_ADDSET             (0xFU<<0)
#define FMC_BTR2_ADDSET_0           (0x1U<<0)

#define FMC_BTR2_DATAHLD_B_0X0      (0x0U<<30)
#define FMC_BTR2_DATAHLD_B_0X1      (0x1U<<30)
#define FMC_BTR2_DATAHLD_B_0X2      (0x2U<<30)
#define FMC_BTR2_DATAHLD_B_0X3      (0x3U<<30)
#define FMC_BTR2_ACCMOD_B_0X0       (0x0U<<28)
#define FMC_BTR2_ACCMOD_B_0X1       (0x1U<<28)
#define FMC_BTR2_ACCMOD_B_0X2       (0x2U<<28)
#define FMC_BTR2_ACCMOD_B_0X3       (0x3U<<28)
#define FMC_BTR2_DATLAT_B_0X0       (0x0U<<24)
#define FMC_BTR2_DATLAT_B_0XF       (0xFU<<24)
#define FMC_BTR2_CLKDIV_B_0X0       (0x0U<<20)
#define FMC_BTR2_CLKDIV_B_0X1       (0x1U<<20)
#define FMC_BTR2_CLKDIV_B_0X2       (0x2U<<20)
#define FMC_BTR2_CLKDIV_B_0XF       (0xFU<<20)
#define FMC_BTR2_BUSTURN_B_0X0      (0x0U<<16)
#define FMC_BTR2_BUSTURN_B_0XF      (0xFU<<16)
#define FMC_BTR2_DATAST_B_0X1       (0x1U<<8)
#define FMC_BTR2_DATAST_B_0X2       (0x2U<<8)
#define FMC_BTR2_DATAST_B_0XFF      (0xFFU<<8)
#define FMC_BTR2_ADDHLD_B_0X1       (0x1U<<4)
#define FMC_BTR2_ADDHLD_B_0X2       (0x2U<<4)
#define FMC_BTR2_ADDHLD_B_0XF       (0xFU<<4)
#define FMC_BTR2_ADDSET_B_0X0       (0x0U<<0)
#define FMC_BTR2_ADDSET_B_0XF       (0xFU<<0)

// BCR3 Configuration

#define FMC_BCR3_NBLSET             (0x3U<<22)
#define FMC_BCR3_NBLSET_0           (0x1U<<22)
#define FMC_BCR3_CSCOUNT1           (0x1U<<21)
#define FMC_BCR3_CSCOUNT0           (0x1U<<20)
#define FMC_BCR3_CBURSTRW           (0x1U<<19)
#define FMC_BCR3_CPSIZE             (0x7U<<16)
#define FMC_BCR3_CPSIZE_0           (0x1U<<16)
#define FMC_BCR3_ASYNCWAIT          (0x1U<<15)
#define FMC_BCR3_EXTMOD             (0x1U<<14)
#define FMC_BCR3_WAITEN             (0x1U<<13)
#define FMC_BCR3_WREN               (0x1U<<12)
#define FMC_BCR3_WAITCFG            (0x1U<<11)
#define FMC_BCR3_WAITPOL            (0x1U<<9)
#define FMC_BCR3_BURSTEN            (0x1U<<8)
#define FMC_BCR3_FACCEN             (0x1U<<6)
#define FMC_BCR3_MWID               (0x3U<<4)
#define FMC_BCR3_MWID_0             (0x1U<<4)
#define FMC_BCR3_MTYP               (0x3U<<2)
#define FMC_BCR3_MTYP_0             (0x1U<<2)
#define FMC_BCR3_MUXEN              (0x1U<<1)
#define FMC_BCR3_MBKEN              (0x1U<<0)

#define FMC_BCR3_NBLSET_B_0X0       (0x0U<<22)
#define FMC_BCR3_NBLSET_B_0X1       (0x1U<<22)
#define FMC_BCR3_NBLSET_B_0X2       (0x2U<<22)
#define FMC_BCR3_NBLSET_B_0X3       (0x3U<<22)
#define FMC_BCR3_CSCOUNT1_B_0X0     (0x0U<<21)
#define FMC_BCR3_CSCOUNT1_B_0X1     (0x1U<<21)
#define FMC_BCR3_CSCOUNT0_B_0X0     (0x0U<<20)
#define FMC_BCR3_CSCOUNT0_B_0X1     (0x1U<<20)
#define FMC_BCR3_CBURSTRW_B_0X0     (0x0U<<19)
#define FMC_BCR3_CBURSTRW_B_0X1     (0x1U<<19)
#define FMC_BCR3_CPSIZE_B_0X0       (0x0U<<16)
#define FMC_BCR3_CPSIZE_B_0X1       (0x1U<<16)
#define FMC_BCR3_CPSIZE_B_0X2       (0x2U<<16)
#define FMC_BCR3_CPSIZE_B_0X3       (0x3U<<16)
#define FMC_BCR3_CPSIZE_B_0X4       (0x4U<<16)
#define FMC_BCR3_ASYNCWAIT_B_0X0    (0x0U<<15)
#define FMC_BCR3_ASYNCWAIT_B_0X1    (0x1U<<15)
#define FMC_BCR3_EXTMOD_B_0X0       (0x0U<<14)
#define FMC_BCR3_EXTMOD_B_0X1       (0x1U<<14)
#define FMC_BCR3_WAITEN_B_0X0       (0x0U<<13)
#define FMC_BCR3_WAITEN_B_0X1       (0x1U<<13)
#define FMC_BCR3_WREN_B_0X0         (0x0U<<12)
#define FMC_BCR3_WREN_B_0X1         (0x1U<<12)
#define FMC_BCR3_WAITCFG_B_0X0      (0x0U<<11)
#define FMC_BCR3_WAITCFG_B_0X1      (0x1U<<11)
#define FMC_BCR3_WAITPOL_B_0X0      (0x0U<<9)
#define FMC_BCR3_WAITPOL_B_0X1      (0x1U<<9)
#define FMC_BCR3_BURSTEN_B_0X0      (0x0U<<8)
#define FMC_BCR3_BURSTEN_B_0X1      (0x1U<<8)
#define FMC_BCR3_FACCEN_B_0X0       (0x0U<<6)
#define FMC_BCR3_FACCEN_B_0X1       (0x1U<<6)
#define FMC_BCR3_MWID_B_0X0         (0x0U<<4)
#define FMC_BCR3_MWID_B_0X1         (0x1U<<4)
#define FMC_BCR3_MWID_B_0X2         (0x2U<<4)
#define FMC_BCR3_MTYP_B_0X0         (0x0U<<2)
#define FMC_BCR3_MTYP_B_0X1         (0x1U<<2)
#define FMC_BCR3_MTYP_B_0X2         (0x2U<<2)
#define FMC_BCR3_MUXEN_B_0X0        (0x0U<<1)
#define FMC_BCR3_MUXEN_B_0X1        (0x1U<<1)
#define FMC_BCR3_MBKEN_B_0X0        (0x0U<<0)
#define FMC_BCR3_MBKEN_B_0X1        (0x1U<<0)

// BTR3 Configuration

#define FMC_BTR3_DATAHLD            (0x3U<<30)
#define FMC_BTR3_DATAHLD_0          (0x1U<<30)
#define FMC_BTR3_ACCMOD             (0x3U<<28)
#define FMC_BTR3_ACCMOD_0           (0x1U<<28)
#define FMC_BTR3_DATLAT             (0xFU<<24)
#define FMC_BTR3_DATLAT_0           (0x1U<<24)
#define FMC_BTR3_CLKDIV             (0xFU<<20)
#define FMC_BTR3_CLKDIV_0           (0x1U<<20)
#define FMC_BTR3_BUSTURN            (0xFU<<16)
#define FMC_BTR3_BUSTURN_0          (0x1U<<16)
#define FMC_BTR3_DATAST             (0xFFU<<8)
#define FMC_BTR3_DATAST_0           (0x1U<<8)
#define FMC_BTR3_ADDHLD             (0xFU<<4)
#define FMC_BTR3_ADDHLD_0           (0x1U<<4)
#define FMC_BTR3_ADDSET             (0xFU<<0)
#define FMC_BTR3_ADDSET_0           (0x1U<<0)

#define FMC_BTR3_DATAHLD_B_0X0      (0x0U<<30)
#define FMC_BTR3_DATAHLD_B_0X1      (0x1U<<30)
#define FMC_BTR3_DATAHLD_B_0X2      (0x2U<<30)
#define FMC_BTR3_DATAHLD_B_0X3      (0x3U<<30)
#define FMC_BTR3_ACCMOD_B_0X0       (0x0U<<28)
#define FMC_BTR3_ACCMOD_B_0X1       (0x1U<<28)
#define FMC_BTR3_ACCMOD_B_0X2       (0x2U<<28)
#define FMC_BTR3_ACCMOD_B_0X3       (0x3U<<28)
#define FMC_BTR3_DATLAT_B_0X0       (0x0U<<24)
#define FMC_BTR3_DATLAT_B_0XF       (0xFU<<24)
#define FMC_BTR3_CLKDIV_B_0X0       (0x0U<<20)
#define FMC_BTR3_CLKDIV_B_0X1       (0x1U<<20)
#define FMC_BTR3_CLKDIV_B_0X2       (0x2U<<20)
#define FMC_BTR3_CLKDIV_B_0XF       (0xFU<<20)
#define FMC_BTR3_BUSTURN_B_0X0      (0x0U<<16)
#define FMC_BTR3_BUSTURN_B_0XF      (0xFU<<16)
#define FMC_BTR3_DATAST_B_0X1       (0x1U<<8)
#define FMC_BTR3_DATAST_B_0X2       (0x2U<<8)
#define FMC_BTR3_DATAST_B_0XFF      (0xFFU<<8)
#define FMC_BTR3_ADDHLD_B_0X1       (0x1U<<4)
#define FMC_BTR3_ADDHLD_B_0X2       (0x2U<<4)
#define FMC_BTR3_ADDHLD_B_0XF       (0xFU<<4)
#define FMC_BTR3_ADDSET_B_0X0       (0x0U<<0)
#define FMC_BTR3_ADDSET_B_0XF       (0xFU<<0)

// BCR4 Configuration

#define FMC_BCR4_NBLSET             (0x3U<<22)
#define FMC_BCR4_NBLSET_0           (0x1U<<22)
#define FMC_BCR4_CSCOUNT1           (0x1U<<21)
#define FMC_BCR4_CSCOUNT0           (0x1U<<20)
#define FMC_BCR4_CBURSTRW           (0x1U<<19)
#define FMC_BCR4_CPSIZE             (0x7U<<16)
#define FMC_BCR4_CPSIZE_0           (0x1U<<16)
#define FMC_BCR4_ASYNCWAIT          (0x1U<<15)
#define FMC_BCR4_EXTMOD             (0x1U<<14)
#define FMC_BCR4_WAITEN             (0x1U<<13)
#define FMC_BCR4_WREN               (0x1U<<12)
#define FMC_BCR4_WAITCFG            (0x1U<<11)
#define FMC_BCR4_WAITPOL            (0x1U<<9)
#define FMC_BCR4_BURSTEN            (0x1U<<8)
#define FMC_BCR4_FACCEN             (0x1U<<6)
#define FMC_BCR4_MWID               (0x3U<<4)
#define FMC_BCR4_MWID_0             (0x1U<<4)
#define FMC_BCR4_MTYP               (0x3U<<2)
#define FMC_BCR4_MTYP_0             (0x1U<<2)
#define FMC_BCR4_MUXEN              (0x1U<<1)
#define FMC_BCR4_MBKEN              (0x1U<<0)

#define FMC_BCR4_NBLSET_B_0X0       (0x0U<<22)
#define FMC_BCR4_NBLSET_B_0X1       (0x1U<<22)
#define FMC_BCR4_NBLSET_B_0X2       (0x2U<<22)
#define FMC_BCR4_NBLSET_B_0X3       (0x3U<<22)
#define FMC_BCR4_CSCOUNT1_B_0X0     (0x0U<<21)
#define FMC_BCR4_CSCOUNT1_B_0X1     (0x1U<<21)
#define FMC_BCR4_CSCOUNT0_B_0X0     (0x0U<<20)
#define FMC_BCR4_CSCOUNT0_B_0X1     (0x1U<<20)
#define FMC_BCR4_CBURSTRW_B_0X0     (0x0U<<19)
#define FMC_BCR4_CBURSTRW_B_0X1     (0x1U<<19)
#define FMC_BCR4_CPSIZE_B_0X0       (0x0U<<16)
#define FMC_BCR4_CPSIZE_B_0X1       (0x1U<<16)
#define FMC_BCR4_CPSIZE_B_0X2       (0x2U<<16)
#define FMC_BCR4_CPSIZE_B_0X3       (0x3U<<16)
#define FMC_BCR4_CPSIZE_B_0X4       (0x4U<<16)
#define FMC_BCR4_ASYNCWAIT_B_0X0    (0x0U<<15)
#define FMC_BCR4_ASYNCWAIT_B_0X1    (0x1U<<15)
#define FMC_BCR4_EXTMOD_B_0X0       (0x0U<<14)
#define FMC_BCR4_EXTMOD_B_0X1       (0x1U<<14)
#define FMC_BCR4_WAITEN_B_0X0       (0x0U<<13)
#define FMC_BCR4_WAITEN_B_0X1       (0x1U<<13)
#define FMC_BCR4_WREN_B_0X0         (0x0U<<12)
#define FMC_BCR4_WREN_B_0X1         (0x1U<<12)
#define FMC_BCR4_WAITCFG_B_0X0      (0x0U<<11)
#define FMC_BCR4_WAITCFG_B_0X1      (0x1U<<11)
#define FMC_BCR4_WAITPOL_B_0X0      (0x0U<<9)
#define FMC_BCR4_WAITPOL_B_0X1      (0x1U<<9)
#define FMC_BCR4_BURSTEN_B_0X0      (0x0U<<8)
#define FMC_BCR4_BURSTEN_B_0X1      (0x1U<<8)
#define FMC_BCR4_FACCEN_B_0X0       (0x0U<<6)
#define FMC_BCR4_FACCEN_B_0X1       (0x1U<<6)
#define FMC_BCR4_MWID_B_0X0         (0x0U<<4)
#define FMC_BCR4_MWID_B_0X1         (0x1U<<4)
#define FMC_BCR4_MWID_B_0X2         (0x2U<<4)
#define FMC_BCR4_MTYP_B_0X0         (0x0U<<2)
#define FMC_BCR4_MTYP_B_0X1         (0x1U<<2)
#define FMC_BCR4_MTYP_B_0X2         (0x2U<<2)
#define FMC_BCR4_MUXEN_B_0X0        (0x0U<<1)
#define FMC_BCR4_MUXEN_B_0X1        (0x1U<<1)
#define FMC_BCR4_MBKEN_B_0X0        (0x0U<<0)
#define FMC_BCR4_MBKEN_B_0X1        (0x1U<<0)

// BTR4 Configuration

#define FMC_BTR4_DATAHLD            (0x3U<<30)
#define FMC_BTR4_DATAHLD_0          (0x1U<<30)
#define FMC_BTR4_ACCMOD             (0x3U<<28)
#define FMC_BTR4_ACCMOD_0           (0x1U<<28)
#define FMC_BTR4_DATLAT             (0xFU<<24)
#define FMC_BTR4_DATLAT_0           (0x1U<<24)
#define FMC_BTR4_CLKDIV             (0xFU<<20)
#define FMC_BTR4_CLKDIV_0           (0x1U<<20)
#define FMC_BTR4_BUSTURN            (0xFU<<16)
#define FMC_BTR4_BUSTURN_0          (0x1U<<16)
#define FMC_BTR4_DATAST             (0xFFU<<8)
#define FMC_BTR4_DATAST_0           (0x1U<<8)
#define FMC_BTR4_ADDHLD             (0xFU<<4)
#define FMC_BTR4_ADDHLD_0           (0x1U<<4)
#define FMC_BTR4_ADDSET             (0xFU<<0)
#define FMC_BTR4_ADDSET_0           (0x1U<<0)

#define FMC_BTR4_DATAHLD_B_0X0      (0x0U<<30)
#define FMC_BTR4_DATAHLD_B_0X1      (0x1U<<30)
#define FMC_BTR4_DATAHLD_B_0X2      (0x2U<<30)
#define FMC_BTR4_DATAHLD_B_0X3      (0x3U<<30)
#define FMC_BTR4_ACCMOD_B_0X0       (0x0U<<28)
#define FMC_BTR4_ACCMOD_B_0X1       (0x1U<<28)
#define FMC_BTR4_ACCMOD_B_0X2       (0x2U<<28)
#define FMC_BTR4_ACCMOD_B_0X3       (0x3U<<28)
#define FMC_BTR4_DATLAT_B_0X0       (0x0U<<24)
#define FMC_BTR4_DATLAT_B_0XF       (0xFU<<24)
#define FMC_BTR4_CLKDIV_B_0X0       (0x0U<<20)
#define FMC_BTR4_CLKDIV_B_0X1       (0x1U<<20)
#define FMC_BTR4_CLKDIV_B_0X2       (0x2U<<20)
#define FMC_BTR4_CLKDIV_B_0XF       (0xFU<<20)
#define FMC_BTR4_BUSTURN_B_0X0      (0x0U<<16)
#define FMC_BTR4_BUSTURN_B_0XF      (0xFU<<16)
#define FMC_BTR4_DATAST_B_0X1       (0x1U<<8)
#define FMC_BTR4_DATAST_B_0X2       (0x2U<<8)
#define FMC_BTR4_DATAST_B_0XFF      (0xFFU<<8)
#define FMC_BTR4_ADDHLD_B_0X1       (0x1U<<4)
#define FMC_BTR4_ADDHLD_B_0X2       (0x2U<<4)
#define FMC_BTR4_ADDHLD_B_0XF       (0xFU<<4)
#define FMC_BTR4_ADDSET_B_0X0       (0x0U<<0)
#define FMC_BTR4_ADDSET_B_0XF       (0xFU<<0)

// CFGR Configuration

#define FMC_CFGR_FMCEN              (0x1U<<31)
#define FMC_CFGR_BMAP1              (0x1U<<25)
#define FMC_CFGR_BMAP0              (0x1U<<24)
#define FMC_CFGR_CCLKEN             (0x1U<<20)
#define FMC_CFGR_CLKDIV             (0xFU<<16)
#define FMC_CFGR_CLKDIV_0           (0x1U<<16)

#define FMC_CFGR_FMCEN_B_0X0        (0x0U<<31)
#define FMC_CFGR_FMCEN_B_0X1        (0x1U<<31)
#define FMC_CFGR_BMAP1_B_0X0        (0x0U<<25)
#define FMC_CFGR_BMAP1_B_0X1        (0x1U<<25)
#define FMC_CFGR_BMAP0_B_0X0        (0x0U<<24)
#define FMC_CFGR_BMAP0_B_0X1        (0x1U<<24)
#define FMC_CFGR_CCLKEN_B_0X0       (0x0U<<20)
#define FMC_CFGR_CCLKEN_B_0X1       (0x1U<<20)
#define FMC_CFGR_CLKDIV_B_0X0       (0x0U<<16)
#define FMC_CFGR_CLKDIV_B_0X1       (0x1U<<16)
#define FMC_CFGR_CLKDIV_B_0X2       (0x2U<<16)
#define FMC_CFGR_CLKDIV_B_0XF       (0xFU<<16)

// PCR Configuration

#define FMC_PCR_WEN                 (0x1U<<25)
#define FMC_PCR_BCHECC              (0x1U<<24)
#define FMC_PCR_ECCSS               (0x7U<<17)
#define FMC_PCR_ECCSS_0             (0x1U<<17)
#define FMC_PCR_TAR                 (0xFU<<13)
#define FMC_PCR_TAR_0               (0x1U<<13)
#define FMC_PCR_TCLR                (0xFU<<9)
#define FMC_PCR_TCLR_0              (0x1U<<9)
#define FMC_PCR_ECCALG              (0x1U<<8)
#define FMC_PCR_ECCEN               (0x1U<<6)
#define FMC_PCR_PWID                (0x3U<<4)
#define FMC_PCR_PWID_0              (0x1U<<4)
#define FMC_PCR_PBKEN               (0x1U<<2)
#define FMC_PCR_PWAITEN             (0x1U<<1)

#define FMC_PCR_WEN_B_0X0           (0x0U<<25)
#define FMC_PCR_WEN_B_0X1           (0x1U<<25)
#define FMC_PCR_BCHECC_B_0X0        (0x0U<<24)
#define FMC_PCR_BCHECC_B_0X1        (0x1U<<24)
#define FMC_PCR_ECCSS_B_0X0         (0x0U<<17)
#define FMC_PCR_ECCSS_B_0X1         (0x1U<<17)
#define FMC_PCR_ECCSS_B_0X2         (0x2U<<17)
#define FMC_PCR_ECCSS_B_0X3         (0x3U<<17)
#define FMC_PCR_ECCSS_B_0X4         (0x4U<<17)
#define FMC_PCR_TAR_B_0X0           (0x0U<<13)
#define FMC_PCR_TAR_B_0XF           (0xFU<<13)
#define FMC_PCR_TCLR_B_0X0          (0x0U<<9)
#define FMC_PCR_TCLR_B_0XF          (0xFU<<9)
#define FMC_PCR_ECCALG_B_0X0        (0x0U<<8)
#define FMC_PCR_ECCALG_B_0X1        (0x1U<<8)
#define FMC_PCR_ECCEN_B_0X0         (0x0U<<6)
#define FMC_PCR_ECCEN_B_0X1         (0x1U<<6)
#define FMC_PCR_PWID_B_0X0          (0x0U<<4)
#define FMC_PCR_PWID_B_0X1          (0x1U<<4)
#define FMC_PCR_PBKEN_B_0X0         (0x0U<<2)
#define FMC_PCR_PBKEN_B_0X1         (0x1U<<2)
#define FMC_PCR_PWAITEN_B_0X0       (0x0U<<1)
#define FMC_PCR_PWAITEN_B_0X1       (0x1U<<1)

// SR Configuration

#define FMC_SR_NWRF                 (0x1U<<6)
#define FMC_SR_PEF                  (0x1U<<4)
#define FMC_SR_ISOST                (0x3U<<0)
#define FMC_SR_ISOST_0              (0x1U<<0)

#define FMC_SR_NWRF_B_0X0           (0x0U<<6)
#define FMC_SR_NWRF_B_0X1           (0x1U<<6)
#define FMC_SR_ISOST_B_0X0          (0x0U<<0)
#define FMC_SR_ISOST_B_0X1          (0x1U<<0)
#define FMC_SR_ISOST_B_0X2          (0x2U<<0)
#define FMC_SR_ISOST_B_0X3          (0x3U<<0)

// PMEM Configuration

#define FMC_PMEM_MEMHIZ             (0xFFU<<24)
#define FMC_PMEM_MEMHIZ_0           (0x1U<<24)
#define FMC_PMEM_MEMHOLD            (0xFFU<<16)
#define FMC_PMEM_MEMHOLD_0          (0x1U<<16)
#define FMC_PMEM_MEMWAIT            (0xFFU<<8)
#define FMC_PMEM_MEMWAIT_0          (0x1U<<8)
#define FMC_PMEM_MEMSET             (0xFFU<<0)
#define FMC_PMEM_MEMSET_0           (0x1U<<0)

#define FMC_PMEM_MEMHIZ_B_0X0       (0x0U<<24)
#define FMC_PMEM_MEMHIZ_B_0X1       (0x1U<<24)
#define FMC_PMEM_MEMHIZ_B_0XFF      (0xFFU<<24)
#define FMC_PMEM_MEMHOLD_B_0X0      (0x0U<<16)
#define FMC_PMEM_MEMHOLD_B_0X1      (0x1U<<16)
#define FMC_PMEM_MEMHOLD_B_0XFF     (0xFFU<<16)
#define FMC_PMEM_MEMWAIT_B_0X0      (0x0U<<8)
#define FMC_PMEM_MEMWAIT_B_0X1      (0x1U<<8)
#define FMC_PMEM_MEMWAIT_B_0XFF     (0xFFU<<8)
#define FMC_PMEM_MEMSET_B_0X0       (0x0U<<0)
#define FMC_PMEM_MEMSET_B_0X1       (0x1U<<0)
#define FMC_PMEM_MEMSET_B_0XFF      (0xFFU<<0)

// PATT Configuration

#define FMC_PATT_ATTHIZ             (0xFFU<<24)
#define FMC_PATT_ATTHIZ_0           (0x1U<<24)
#define FMC_PATT_ATTHOLD            (0xFFU<<16)
#define FMC_PATT_ATTHOLD_0          (0x1U<<16)
#define FMC_PATT_ATTWAIT            (0xFFU<<8)
#define FMC_PATT_ATTWAIT_0          (0x1U<<8)
#define FMC_PATT_ATTSET             (0xFFU<<0)
#define FMC_PATT_ATTSET_0           (0x1U<<0)

#define FMC_PATT_ATTHIZ_B_0X0       (0x0U<<24)
#define FMC_PATT_ATTHIZ_B_0X1       (0x1U<<24)
#define FMC_PATT_ATTHIZ_B_0XFF      (0xFFU<<24)
#define FMC_PATT_ATTHOLD_B_0X0      (0x0U<<16)
#define FMC_PATT_ATTHOLD_B_0X1      (0x1U<<16)
#define FMC_PATT_ATTHOLD_B_0XFF     (0xFFU<<16)
#define FMC_PATT_ATTWAIT_B_0X0      (0x0U<<8)
#define FMC_PATT_ATTWAIT_B_0X1      (0x1U<<8)
#define FMC_PATT_ATTWAIT_B_0XFF     (0xFFU<<8)
#define FMC_PATT_ATTSET_B_0X0       (0x0U<<0)
#define FMC_PATT_ATTSET_B_0X1       (0x1U<<0)
#define FMC_PATT_ATTSET_B_0XFF      (0xFFU<<0)

// HPR Configuration

#define FMC_HPR_HPR                 (0xFFFFFFFFU<<0)
#define FMC_HPR_HPR_0               (0x1U<<0)

// HECCR Configuration

#define FMC_HECCR_HECC              (0xFFFFFFFFU<<0)
#define FMC_HECCR_HECC_0            (0x1U<<0)

// BWTR1 Configuration

#define FMC_BWTR1_DATAHLD           (0x3U<<30)
#define FMC_BWTR1_DATAHLD_0         (0x1U<<30)
#define FMC_BWTR1_ACCMOD            (0x3U<<28)
#define FMC_BWTR1_ACCMOD_0          (0x1U<<28)
#define FMC_BWTR1_BUSTURN           (0xFU<<16)
#define FMC_BWTR1_BUSTURN_0         (0x1U<<16)
#define FMC_BWTR1_DATAST            (0xFFU<<8)
#define FMC_BWTR1_DATAST_0          (0x1U<<8)
#define FMC_BWTR1_ADDHLD            (0xFU<<4)
#define FMC_BWTR1_ADDHLD_0          (0x1U<<4)
#define FMC_BWTR1_ADDSET            (0xFU<<0)
#define FMC_BWTR1_ADDSET_0          (0x1U<<0)

#define FMC_BWTR1_DATAHLD_B_0X0     (0x0U<<30)
#define FMC_BWTR1_DATAHLD_B_0X1     (0x1U<<30)
#define FMC_BWTR1_DATAHLD_B_0X2     (0x2U<<30)
#define FMC_BWTR1_DATAHLD_B_0X3     (0x3U<<30)
#define FMC_BWTR1_ACCMOD_B_0X0      (0x0U<<28)
#define FMC_BWTR1_ACCMOD_B_0X1      (0x1U<<28)
#define FMC_BWTR1_ACCMOD_B_0X2      (0x2U<<28)
#define FMC_BWTR1_ACCMOD_B_0X3      (0x3U<<28)
#define FMC_BWTR1_BUSTURN_B_0X0     (0x0U<<16)
#define FMC_BWTR1_BUSTURN_B_0XF     (0xFU<<16)
#define FMC_BWTR1_DATAST_B_0X1      (0x1U<<8)
#define FMC_BWTR1_DATAST_B_0X2      (0x2U<<8)
#define FMC_BWTR1_DATAST_B_0XFF     (0xFFU<<8)
#define FMC_BWTR1_ADDHLD_B_0X1      (0x1U<<4)
#define FMC_BWTR1_ADDHLD_B_0X2      (0x2U<<4)
#define FMC_BWTR1_ADDHLD_B_0XF      (0xFU<<4)
#define FMC_BWTR1_ADDSET_B_0X0      (0x0U<<0)
#define FMC_BWTR1_ADDSET_B_0XF      (0xFU<<0)

// BWTR2 Configuration

#define FMC_BWTR2_DATAHLD           (0x3U<<30)
#define FMC_BWTR2_DATAHLD_0         (0x1U<<30)
#define FMC_BWTR2_ACCMOD            (0x3U<<28)
#define FMC_BWTR2_ACCMOD_0          (0x1U<<28)
#define FMC_BWTR2_BUSTURN           (0xFU<<16)
#define FMC_BWTR2_BUSTURN_0         (0x1U<<16)
#define FMC_BWTR2_DATAST            (0xFFU<<8)
#define FMC_BWTR2_DATAST_0          (0x1U<<8)
#define FMC_BWTR2_ADDHLD            (0xFU<<4)
#define FMC_BWTR2_ADDHLD_0          (0x1U<<4)
#define FMC_BWTR2_ADDSET            (0xFU<<0)
#define FMC_BWTR2_ADDSET_0          (0x1U<<0)

#define FMC_BWTR2_DATAHLD_B_0X0     (0x0U<<30)
#define FMC_BWTR2_DATAHLD_B_0X1     (0x1U<<30)
#define FMC_BWTR2_DATAHLD_B_0X2     (0x2U<<30)
#define FMC_BWTR2_DATAHLD_B_0X3     (0x3U<<30)
#define FMC_BWTR2_ACCMOD_B_0X0      (0x0U<<28)
#define FMC_BWTR2_ACCMOD_B_0X1      (0x1U<<28)
#define FMC_BWTR2_ACCMOD_B_0X2      (0x2U<<28)
#define FMC_BWTR2_ACCMOD_B_0X3      (0x3U<<28)
#define FMC_BWTR2_BUSTURN_B_0X0     (0x0U<<16)
#define FMC_BWTR2_BUSTURN_B_0XF     (0xFU<<16)
#define FMC_BWTR2_DATAST_B_0X1      (0x1U<<8)
#define FMC_BWTR2_DATAST_B_0X2      (0x2U<<8)
#define FMC_BWTR2_DATAST_B_0XFF     (0xFFU<<8)
#define FMC_BWTR2_ADDHLD_B_0X1      (0x1U<<4)
#define FMC_BWTR2_ADDHLD_B_0X2      (0x2U<<4)
#define FMC_BWTR2_ADDHLD_B_0XF      (0xFU<<4)
#define FMC_BWTR2_ADDSET_B_0X0      (0x0U<<0)
#define FMC_BWTR2_ADDSET_B_0XF      (0xFU<<0)

// BWTR3 Configuration

#define FMC_BWTR3_DATAHLD           (0x3U<<30)
#define FMC_BWTR3_DATAHLD_0         (0x1U<<30)
#define FMC_BWTR3_ACCMOD            (0x3U<<28)
#define FMC_BWTR3_ACCMOD_0          (0x1U<<28)
#define FMC_BWTR3_BUSTURN           (0xFU<<16)
#define FMC_BWTR3_BUSTURN_0         (0x1U<<16)
#define FMC_BWTR3_DATAST            (0xFFU<<8)
#define FMC_BWTR3_DATAST_0          (0x1U<<8)
#define FMC_BWTR3_ADDHLD            (0xFU<<4)
#define FMC_BWTR3_ADDHLD_0          (0x1U<<4)
#define FMC_BWTR3_ADDSET            (0xFU<<0)
#define FMC_BWTR3_ADDSET_0          (0x1U<<0)

#define FMC_BWTR3_DATAHLD_B_0X0     (0x0U<<30)
#define FMC_BWTR3_DATAHLD_B_0X1     (0x1U<<30)
#define FMC_BWTR3_DATAHLD_B_0X2     (0x2U<<30)
#define FMC_BWTR3_DATAHLD_B_0X3     (0x3U<<30)
#define FMC_BWTR3_ACCMOD_B_0X0      (0x0U<<28)
#define FMC_BWTR3_ACCMOD_B_0X1      (0x1U<<28)
#define FMC_BWTR3_ACCMOD_B_0X2      (0x2U<<28)
#define FMC_BWTR3_ACCMOD_B_0X3      (0x3U<<28)
#define FMC_BWTR3_BUSTURN_B_0X0     (0x0U<<16)
#define FMC_BWTR3_BUSTURN_B_0XF     (0xFU<<16)
#define FMC_BWTR3_DATAST_B_0X1      (0x1U<<8)
#define FMC_BWTR3_DATAST_B_0X2      (0x2U<<8)
#define FMC_BWTR3_DATAST_B_0XFF     (0xFFU<<8)
#define FMC_BWTR3_ADDHLD_B_0X1      (0x1U<<4)
#define FMC_BWTR3_ADDHLD_B_0X2      (0x2U<<4)
#define FMC_BWTR3_ADDHLD_B_0XF      (0xFU<<4)
#define FMC_BWTR3_ADDSET_B_0X0      (0x0U<<0)
#define FMC_BWTR3_ADDSET_B_0XF      (0xFU<<0)

// BWTR4 Configuration

#define FMC_BWTR4_DATAHLD           (0x3U<<30)
#define FMC_BWTR4_DATAHLD_0         (0x1U<<30)
#define FMC_BWTR4_ACCMOD            (0x3U<<28)
#define FMC_BWTR4_ACCMOD_0          (0x1U<<28)
#define FMC_BWTR4_BUSTURN           (0xFU<<16)
#define FMC_BWTR4_BUSTURN_0         (0x1U<<16)
#define FMC_BWTR4_DATAST            (0xFFU<<8)
#define FMC_BWTR4_DATAST_0          (0x1U<<8)
#define FMC_BWTR4_ADDHLD            (0xFU<<4)
#define FMC_BWTR4_ADDHLD_0          (0x1U<<4)
#define FMC_BWTR4_ADDSET            (0xFU<<0)
#define FMC_BWTR4_ADDSET_0          (0x1U<<0)

#define FMC_BWTR4_DATAHLD_B_0X0     (0x0U<<30)
#define FMC_BWTR4_DATAHLD_B_0X1     (0x1U<<30)
#define FMC_BWTR4_DATAHLD_B_0X2     (0x2U<<30)
#define FMC_BWTR4_DATAHLD_B_0X3     (0x3U<<30)
#define FMC_BWTR4_ACCMOD_B_0X0      (0x0U<<28)
#define FMC_BWTR4_ACCMOD_B_0X1      (0x1U<<28)
#define FMC_BWTR4_ACCMOD_B_0X2      (0x2U<<28)
#define FMC_BWTR4_ACCMOD_B_0X3      (0x3U<<28)
#define FMC_BWTR4_BUSTURN_B_0X0     (0x0U<<16)
#define FMC_BWTR4_BUSTURN_B_0XF     (0xFU<<16)
#define FMC_BWTR4_DATAST_B_0X1      (0x1U<<8)
#define FMC_BWTR4_DATAST_B_0X2      (0x2U<<8)
#define FMC_BWTR4_DATAST_B_0XFF     (0xFFU<<8)
#define FMC_BWTR4_ADDHLD_B_0X1      (0x1U<<4)
#define FMC_BWTR4_ADDHLD_B_0X2      (0x2U<<4)
#define FMC_BWTR4_ADDHLD_B_0XF      (0xFU<<4)
#define FMC_BWTR4_ADDSET_B_0X0      (0x0U<<0)
#define FMC_BWTR4_ADDSET_B_0XF      (0xFU<<0)

// SDCR1 Configuration

#define FMC_SDCR1_SDINIT            (0x1U<<17)
#define FMC_SDCR1_SDEN              (0x1U<<16)
#define FMC_SDCR1_RPIPE             (0x3U<<13)
#define FMC_SDCR1_RPIPE_0           (0x1U<<13)
#define FMC_SDCR1_SDCLK             (0x3U<<10)
#define FMC_SDCR1_SDCLK_0           (0x1U<<10)
#define FMC_SDCR1_WP                (0x1U<<9)
#define FMC_SDCR1_CAS               (0x3U<<7)
#define FMC_SDCR1_CAS_0             (0x1U<<7)
#define FMC_SDCR1_NB                (0x1U<<6)
#define FMC_SDCR1_MWID              (0x3U<<4)
#define FMC_SDCR1_MWID_0            (0x1U<<4)
#define FMC_SDCR1_NR                (0x3U<<2)
#define FMC_SDCR1_NR_0              (0x1U<<2)
#define FMC_SDCR1_NC                (0x3U<<0)
#define FMC_SDCR1_NC_0              (0x1U<<0)

#define FMC_SDCR1_SDINIT_B_0X1      (0x1U<<17)
#define FMC_SDCR1_SDINIT_B_0X0      (0x0U<<17)
#define FMC_SDCR1_SDEN_B_0X1        (0x1U<<16)
#define FMC_SDCR1_SDEN_B_0X0        (0x0U<<16)
#define FMC_SDCR1_RPIPE_B_0X0       (0x0U<<13)
#define FMC_SDCR1_RPIPE_B_0X1       (0x1U<<13)
#define FMC_SDCR1_RPIPE_B_0X2       (0x2U<<13)
#define FMC_SDCR1_SDCLK_B_0X0       (0x0U<<10)
#define FMC_SDCR1_SDCLK_B_0X1       (0x1U<<10)
#define FMC_SDCR1_SDCLK_B_0X2       (0x2U<<10)
#define FMC_SDCR1_SDCLK_B_0X3       (0x3U<<10)
#define FMC_SDCR1_WP_B_0X0          (0x0U<<9)
#define FMC_SDCR1_WP_B_0X1          (0x1U<<9)
#define FMC_SDCR1_CAS_B_0X1         (0x1U<<7)
#define FMC_SDCR1_CAS_B_0X2         (0x2U<<7)
#define FMC_SDCR1_CAS_B_0X3         (0x3U<<7)
#define FMC_SDCR1_NB_B_0X0          (0x0U<<6)
#define FMC_SDCR1_NB_B_0X1          (0x1U<<6)
#define FMC_SDCR1_MWID_B_0X0        (0x0U<<4)
#define FMC_SDCR1_MWID_B_0X1        (0x1U<<4)
#define FMC_SDCR1_MWID_B_0X2        (0x2U<<4)
#define FMC_SDCR1_NR_B_0X0          (0x0U<<2)
#define FMC_SDCR1_NR_B_0X1          (0x1U<<2)
#define FMC_SDCR1_NR_B_0X2          (0x2U<<2)
#define FMC_SDCR1_NC_B_0X0          (0x0U<<0)
#define FMC_SDCR1_NC_B_0X1          (0x1U<<0)
#define FMC_SDCR1_NC_B_0X2          (0x2U<<0)
#define FMC_SDCR1_NC_B_0X3          (0x3U<<0)

// SDCR2 Configuration

#define FMC_SDCR2_SDINIT            (0x1U<<17)
#define FMC_SDCR2_SDEN              (0x1U<<16)
#define FMC_SDCR2_WP                (0x1U<<9)
#define FMC_SDCR2_CAS               (0x3U<<7)
#define FMC_SDCR2_CAS_0             (0x1U<<7)
#define FMC_SDCR2_NB                (0x1U<<6)
#define FMC_SDCR2_MWID              (0x3U<<4)
#define FMC_SDCR2_MWID_0            (0x1U<<4)
#define FMC_SDCR2_NR                (0x3U<<2)
#define FMC_SDCR2_NR_0              (0x1U<<2)
#define FMC_SDCR2_NC                (0x3U<<0)
#define FMC_SDCR2_NC_0              (0x1U<<0)

#define FMC_SDCR2_SDINIT_B_0X1      (0x1U<<17)
#define FMC_SDCR2_SDINIT_B_0X0      (0x0U<<17)
#define FMC_SDCR2_SDEN_B_0X1        (0x1U<<16)
#define FMC_SDCR2_SDEN_B_0X0        (0x0U<<16)
#define FMC_SDCR2_WP_B_0X0          (0x0U<<9)
#define FMC_SDCR2_WP_B_0X1          (0x1U<<9)
#define FMC_SDCR2_CAS_B_0X1         (0x1U<<7)
#define FMC_SDCR2_CAS_B_0X2         (0x2U<<7)
#define FMC_SDCR2_CAS_B_0X3         (0x3U<<7)
#define FMC_SDCR2_NB_B_0X0          (0x0U<<6)
#define FMC_SDCR2_NB_B_0X1          (0x1U<<6)
#define FMC_SDCR2_MWID_B_0X0        (0x0U<<4)
#define FMC_SDCR2_MWID_B_0X1        (0x1U<<4)
#define FMC_SDCR2_MWID_B_0X2        (0x2U<<4)
#define FMC_SDCR2_NR_B_0X0          (0x0U<<2)
#define FMC_SDCR2_NR_B_0X1          (0x1U<<2)
#define FMC_SDCR2_NR_B_0X2          (0x2U<<2)
#define FMC_SDCR2_NC_B_0X0          (0x0U<<0)
#define FMC_SDCR2_NC_B_0X1          (0x1U<<0)
#define FMC_SDCR2_NC_B_0X2          (0x2U<<0)
#define FMC_SDCR2_NC_B_0X3          (0x3U<<0)

// SDTR Configuration

#define FMC_SDTR_TRCD               (0xFU<<24)
#define FMC_SDTR_TRCD_0             (0x1U<<24)
#define FMC_SDTR_TRP                (0xFU<<20)
#define FMC_SDTR_TRP_0              (0x1U<<20)
#define FMC_SDTR_TWR                (0xFU<<16)
#define FMC_SDTR_TWR_0              (0x1U<<16)
#define FMC_SDTR_TRC                (0xFU<<12)
#define FMC_SDTR_TRC_0              (0x1U<<12)
#define FMC_SDTR_TRAS               (0xFU<<8)
#define FMC_SDTR_TRAS_0             (0x1U<<8)
#define FMC_SDTR_TXSR               (0xFU<<4)
#define FMC_SDTR_TXSR_0             (0x1U<<4)
#define FMC_SDTR_TMRD               (0xFU<<0)
#define FMC_SDTR_TMRD_0             (0x1U<<0)

#define FMC_SDTR_TRCD_B_0X0         (0x0U<<24)
#define FMC_SDTR_TRCD_B_0X1         (0x1U<<24)
#define FMC_SDTR_TRCD_B_0XF         (0xFU<<24)
#define FMC_SDTR_TRP_B_0X0          (0x0U<<20)
#define FMC_SDTR_TRP_B_0X1          (0x1U<<20)
#define FMC_SDTR_TRP_B_0XF          (0xFU<<20)
#define FMC_SDTR_TWR_B_0X0          (0x0U<<16)
#define FMC_SDTR_TWR_B_0X1          (0x1U<<16)
#define FMC_SDTR_TWR_B_0XF          (0xFU<<16)
#define FMC_SDTR_TRC_B_0X0          (0x0U<<12)
#define FMC_SDTR_TRC_B_0X1          (0x1U<<12)
#define FMC_SDTR_TRC_B_0XF          (0xFU<<12)
#define FMC_SDTR_TRAS_B_0X0         (0x0U<<8)
#define FMC_SDTR_TRAS_B_0X1         (0x1U<<8)
#define FMC_SDTR_TRAS_B_0XF         (0xFU<<8)
#define FMC_SDTR_TXSR_B_0X0         (0x0U<<4)
#define FMC_SDTR_TXSR_B_0X1         (0x1U<<4)
#define FMC_SDTR_TXSR_B_0XF         (0xFU<<4)
#define FMC_SDTR_TMRD_B_0X0         (0x0U<<0)
#define FMC_SDTR_TMRD_B_0X1         (0x1U<<0)
#define FMC_SDTR_TMRD_B_0XF         (0xFU<<0)

// SDCMR Configuration

#define FMC_SDCMR_MRD               (0x3FFFU<<9)
#define FMC_SDCMR_MRD_0             (0x1U<<9)
#define FMC_SDCMR_NRFS              (0xFU<<5)
#define FMC_SDCMR_NRFS_0            (0x1U<<5)
#define FMC_SDCMR_DS1               (0x1U<<4)
#define FMC_SDCMR_DS2               (0x1U<<3)
#define FMC_SDCMR_MODE              (0x7U<<0)
#define FMC_SDCMR_MODE_0            (0x1U<<0)

#define FMC_SDCMR_NRFS_B_0X0        (0x0U<<5)
#define FMC_SDCMR_NRFS_B_0X1        (0x1U<<5)
#define FMC_SDCMR_NRFS_B_0XE        (0xEU<<5)
#define FMC_SDCMR_NRFS_B_0XF        (0xFU<<5)
#define FMC_SDCMR_DS1_B_0X0         (0x0U<<4)
#define FMC_SDCMR_DS1_B_0X1         (0x1U<<4)
#define FMC_SDCMR_DS2_B_0X0         (0x0U<<3)
#define FMC_SDCMR_DS2_B_0X1         (0x1U<<3)
#define FMC_SDCMR_MODE_B_0X0        (0x0U<<0)
#define FMC_SDCMR_MODE_B_0X2        (0x2U<<0)
#define FMC_SDCMR_MODE_B_0X3        (0x3U<<0)
#define FMC_SDCMR_MODE_B_0X4        (0x4U<<0)
#define FMC_SDCMR_MODE_B_0X5        (0x5U<<0)
#define FMC_SDCMR_MODE_B_0X6        (0x6U<<0)

// SDRTR Configuration

#define FMC_SDRTR_REIE              (0x1U<<14)
#define FMC_SDRTR_RFSCNT            (0x1FFFU<<1)
#define FMC_SDRTR_RFSCNT_0          (0x1U<<1)
#define FMC_SDRTR_CRE               (0x1U<<0)

#define FMC_SDRTR_REIE_B_0X0        (0x0U<<14)
#define FMC_SDRTR_REIE_B_0X1        (0x1U<<14)
#define FMC_SDRTR_CRE_B_0X0         (0x0U<<0)
#define FMC_SDRTR_CRE_B_0X1         (0x1U<<0)

// SDSR Configuration

#define FMC_SDSR_CMDOK              (0x1U<<15)
#define FMC_SDSR_MODES2             (0x3U<<3)
#define FMC_SDSR_MODES2_0           (0x1U<<3)
#define FMC_SDSR_MODES1             (0x3U<<1)
#define FMC_SDSR_MODES1_0           (0x1U<<1)
#define FMC_SDSR_RE                 (0x1U<<0)

#define FMC_SDSR_CMDOK_B_0X0        (0x0U<<15)
#define FMC_SDSR_CMDOK_B_0X1        (0x1U<<15)
#define FMC_SDSR_MODES2_B_0X0       (0x0U<<3)
#define FMC_SDSR_MODES2_B_0X1       (0x1U<<3)
#define FMC_SDSR_MODES2_B_0X2       (0x2U<<3)
#define FMC_SDSR_MODES1_B_0X0       (0x0U<<1)
#define FMC_SDSR_MODES1_B_0X1       (0x1U<<1)
#define FMC_SDSR_MODES1_B_0X2       (0x2U<<1)
#define FMC_SDSR_RE_B_0X0           (0x0U<<0)
#define FMC_SDSR_RE_B_0X1           (0x1U<<0)

// IER Configuration

#define FMC_IER_IFEE                (0x1U<<2)
#define FMC_IER_IHLE                (0x1U<<1)
#define FMC_IER_IREE                (0x1U<<0)

#define FMC_IER_IFEE_B_0X0          (0x0U<<2)
#define FMC_IER_IFEE_B_0X1          (0x1U<<2)
#define FMC_IER_IHLE_B_0X0          (0x0U<<1)
#define FMC_IER_IHLE_B_0X1          (0x1U<<1)
#define FMC_IER_IREE_B_0X0          (0x0U<<0)
#define FMC_IER_IREE_B_0X1          (0x1U<<0)

// ISR Configuration

#define FMC_ISR_IFEF                (0x1U<<2)
#define FMC_ISR_IHLF                (0x1U<<1)
#define FMC_ISR_IREF                (0x1U<<0)

#define FMC_ISR_IFEF_B_0X0          (0x0U<<2)
#define FMC_ISR_IFEF_B_0X1          (0x1U<<2)
#define FMC_ISR_IHLF_B_0X0          (0x0U<<1)
#define FMC_ISR_IHLF_B_0X1          (0x1U<<1)
#define FMC_ISR_IREF_B_0X0          (0x0U<<0)
#define FMC_ISR_IREF_B_0X1          (0x1U<<0)

// ICR Configuration

#define FMC_ICR_CIFEF               (0x1U<<2)
#define FMC_ICR_CIHLF               (0x1U<<1)
#define FMC_ICR_CIREF               (0x1U<<0)

#define FMC_ICR_CIFEF_B_0X0         (0x0U<<2)
#define FMC_ICR_CIFEF_B_0X1         (0x1U<<2)
#define FMC_ICR_CIHLF_B_0X0         (0x0U<<1)
#define FMC_ICR_CIHLF_B_0X1         (0x1U<<1)
#define FMC_ICR_CIREF_B_0X0         (0x0U<<0)
#define FMC_ICR_CIREF_B_0X1         (0x1U<<0)

// CSQCR Configuration

#define FMC_CSQCR_CSQSTART          (0x1U<<0)

// CSQCFGR1 Configuration

#define FMC_CSQCFGR1_CMD2T          (0x1U<<25)
#define FMC_CSQCFGR1_CMD1T          (0x1U<<24)
#define FMC_CSQCFGR1_CMD2           (0xFFU<<16)
#define FMC_CSQCFGR1_CMD2_0         (0x1U<<16)
#define FMC_CSQCFGR1_CMD1           (0xFFU<<8)
#define FMC_CSQCFGR1_CMD1_0         (0x1U<<8)
#define FMC_CSQCFGR1_ACYNBR         (0x7U<<4)
#define FMC_CSQCFGR1_ACYNBR_0       (0x1U<<4)
#define FMC_CSQCFGR1_DMADEN         (0x1U<<2)
#define FMC_CSQCFGR1_CMD2EN         (0x1U<<1)

#define FMC_CSQCFGR1_CMD2T_B_0X0    (0x0U<<25)
#define FMC_CSQCFGR1_CMD2T_B_0X1    (0x1U<<25)
#define FMC_CSQCFGR1_CMD1T_B_0X0    (0x0U<<24)
#define FMC_CSQCFGR1_CMD1T_B_0X1    (0x1U<<24)
#define FMC_CSQCFGR1_ACYNBR_B_0X0   (0x0U<<4)
#define FMC_CSQCFGR1_ACYNBR_B_0X1   (0x1U<<4)
#define FMC_CSQCFGR1_ACYNBR_B_0X2   (0x2U<<4)
#define FMC_CSQCFGR1_ACYNBR_B_0X3   (0x3U<<4)
#define FMC_CSQCFGR1_ACYNBR_B_0X4   (0x4U<<4)
#define FMC_CSQCFGR1_ACYNBR_B_0X5   (0x5U<<4)
#define FMC_CSQCFGR1_DMADEN_B_0X0   (0x0U<<2)
#define FMC_CSQCFGR1_DMADEN_B_0X1   (0x1U<<2)
#define FMC_CSQCFGR1_CMD2EN_B_0X0   (0x0U<<1)
#define FMC_CSQCFGR1_CMD2EN_B_0X1   (0x1U<<1)

// CSQCFGR2 Configuration

#define FMC_CSQCFGR2_RCMD2T         (0x1U<<25)
#define FMC_CSQCFGR2_RCMD1T         (0x1U<<24)
#define FMC_CSQCFGR2_RCMD2          (0xFFU<<16)
#define FMC_CSQCFGR2_RCMD2_0        (0x1U<<16)
#define FMC_CSQCFGR2_RCMD1          (0xFFU<<8)
#define FMC_CSQCFGR2_RCMD1_0        (0x1U<<8)
#define FMC_CSQCFGR2_DMASEN         (0x1U<<2)
#define FMC_CSQCFGR2_RCMD2EN        (0x1U<<1)
#define FMC_CSQCFGR2_SQSDTEN        (0x1U<<0)

#define FMC_CSQCFGR2_RCMD2T_B_0X0   (0x0U<<25)
#define FMC_CSQCFGR2_RCMD2T_B_0X1   (0x1U<<25)
#define FMC_CSQCFGR2_RCMD1T_B_0X0   (0x0U<<24)
#define FMC_CSQCFGR2_RCMD1T_B_0X1   (0x1U<<24)
#define FMC_CSQCFGR2_DMASEN_B_0X0   (0x0U<<2)
#define FMC_CSQCFGR2_DMASEN_B_0X1   (0x1U<<2)
#define FMC_CSQCFGR2_RCMD2EN_B_0X0  (0x0U<<1)
#define FMC_CSQCFGR2_RCMD2EN_B_0X1  (0x1U<<1)
#define FMC_CSQCFGR2_SQSDTEN_B_0X0  (0x0U<<0)
#define FMC_CSQCFGR2_SQSDTEN_B_0X1  (0x1U<<0)

// CSQCFGR3 Configuration

#define FMC_CSQCFGR3_RAC2T          (0x1U<<23)
#define FMC_CSQCFGR3_RAC1T          (0x1U<<22)
#define FMC_CSQCFGR3_SDT            (0x1U<<21)
#define FMC_CSQCFGR3_AC5T           (0x1U<<20)
#define FMC_CSQCFGR3_AC4T           (0x1U<<19)
#define FMC_CSQCFGR3_AC3T           (0x1U<<18)
#define FMC_CSQCFGR3_AC2T           (0x1U<<17)
#define FMC_CSQCFGR3_AC1T           (0x1U<<16)
#define FMC_CSQCFGR3_SNBR           (0x3FU<<8)
#define FMC_CSQCFGR3_SNBR_0         (0x1U<<8)

#define FMC_CSQCFGR3_RAC2T_B_0X0    (0x0U<<23)
#define FMC_CSQCFGR3_RAC2T_B_0X1    (0x1U<<23)
#define FMC_CSQCFGR3_RAC1T_B_0X0    (0x0U<<22)
#define FMC_CSQCFGR3_RAC1T_B_0X1    (0x1U<<22)
#define FMC_CSQCFGR3_SDT_B_0X0      (0x0U<<21)
#define FMC_CSQCFGR3_SDT_B_0X1      (0x1U<<21)
#define FMC_CSQCFGR3_AC5T_B_0X0     (0x0U<<20)
#define FMC_CSQCFGR3_AC5T_B_0X1     (0x1U<<20)
#define FMC_CSQCFGR3_AC4T_B_0X0     (0x0U<<19)
#define FMC_CSQCFGR3_AC4T_B_0X1     (0x1U<<19)
#define FMC_CSQCFGR3_AC3T_B_0X0     (0x0U<<18)
#define FMC_CSQCFGR3_AC3T_B_0X1     (0x1U<<18)
#define FMC_CSQCFGR3_AC2T_B_0X0     (0x0U<<17)
#define FMC_CSQCFGR3_AC2T_B_0X1     (0x1U<<17)
#define FMC_CSQCFGR3_AC1T_B_0X0     (0x0U<<16)
#define FMC_CSQCFGR3_AC1T_B_0X1     (0x1U<<16)
#define FMC_CSQCFGR3_SNBR_B_0X0     (0x0U<<8)
#define FMC_CSQCFGR3_SNBR_B_0X1     (0x1U<<8)
#define FMC_CSQCFGR3_SNBR_B_0X3F    (0x3FU<<8)

// CSQAR1 Configuration

#define FMC_CSQAR1_ADDC4            (0xFFU<<24)
#define FMC_CSQAR1_ADDC4_0          (0x1U<<24)
#define FMC_CSQAR1_ADDC3            (0xFFU<<16)
#define FMC_CSQAR1_ADDC3_0          (0x1U<<16)
#define FMC_CSQAR1_ADDC2            (0xFFU<<8)
#define FMC_CSQAR1_ADDC2_0          (0x1U<<8)
#define FMC_CSQAR1_ADDC1            (0xFFU<<0)
#define FMC_CSQAR1_ADDC1_0          (0x1U<<0)

// CSQAR2 Configuration

#define FMC_CSQAR2_SAO              (0xFFFFU<<16)
#define FMC_CSQAR2_SAO_0            (0x1U<<16)
#define FMC_CSQAR2_ADDC5            (0xFFU<<0)
#define FMC_CSQAR2_ADDC5_0          (0x1U<<0)

// CSQIER Configuration

#define FMC_CSQIER_CMDTCIE          (0x1U<<4)
#define FMC_CSQIER_SUEIE            (0x1U<<3)
#define FMC_CSQIER_SEIE             (0x1U<<2)
#define FMC_CSQIER_SCIE             (0x1U<<1)
#define FMC_CSQIER_TCIE             (0x1U<<0)

#define FMC_CSQIER_CMDTCIE_B_0X0    (0x0U<<4)
#define FMC_CSQIER_CMDTCIE_B_0X1    (0x1U<<4)
#define FMC_CSQIER_SUEIE_B_0X0      (0x0U<<3)
#define FMC_CSQIER_SUEIE_B_0X1      (0x1U<<3)
#define FMC_CSQIER_SEIE_B_0X0       (0x0U<<2)
#define FMC_CSQIER_SEIE_B_0X1       (0x1U<<2)
#define FMC_CSQIER_SCIE_B_0X0       (0x0U<<1)
#define FMC_CSQIER_SCIE_B_0X1       (0x1U<<1)
#define FMC_CSQIER_TCIE_B_0X0       (0x0U<<0)
#define FMC_CSQIER_TCIE_B_0X1       (0x1U<<0)

// CSQISR Configuration

#define FMC_CSQISR_CMDTCF           (0x1U<<4)
#define FMC_CSQISR_SUEF             (0x1U<<3)
#define FMC_CSQISR_SEF              (0x1U<<2)
#define FMC_CSQISR_SCF              (0x1U<<1)
#define FMC_CSQISR_TCF              (0x1U<<0)

// CSQICR Configuration

#define FMC_CSQICR_CCMDTCF          (0x1U<<4)
#define FMC_CSQICR_CSUEF            (0x1U<<3)
#define FMC_CSQICR_CSEF             (0x1U<<2)
#define FMC_CSQICR_CSCF             (0x1U<<1)
#define FMC_CSQICR_CTCF             (0x1U<<0)

// CSQEMSR Configuration

#define FMC_CSQEMSR_SEM             (0xFFFFU<<0)
#define FMC_CSQEMSR_SEM_0           (0x1U<<0)

// BCHIER Configuration

#define FMC_BCHIER_EPBRIE           (0x1U<<4)
#define FMC_BCHIER_DSRIE            (0x1U<<3)
#define FMC_BCHIER_DEFIE            (0x1U<<2)
#define FMC_BCHIER_DERIE            (0x1U<<1)
#define FMC_BCHIER_DUEIE            (0x1U<<0)

#define FMC_BCHIER_EPBRIE_B_0X0     (0x0U<<4)
#define FMC_BCHIER_EPBRIE_B_0X1     (0x1U<<4)
#define FMC_BCHIER_DSRIE_B_0X0      (0x0U<<3)
#define FMC_BCHIER_DSRIE_B_0X1      (0x1U<<3)
#define FMC_BCHIER_DEFIE_B_0X0      (0x0U<<2)
#define FMC_BCHIER_DEFIE_B_0X1      (0x1U<<2)
#define FMC_BCHIER_DERIE_B_0X0      (0x0U<<1)
#define FMC_BCHIER_DERIE_B_0X1      (0x1U<<1)
#define FMC_BCHIER_DUEIE_B_0X0      (0x0U<<0)
#define FMC_BCHIER_DUEIE_B_0X1      (0x1U<<0)

// BCHISR Configuration

#define FMC_BCHISR_EPBRF            (0x1U<<4)
#define FMC_BCHISR_DSRF             (0x1U<<3)
#define FMC_BCHISR_DEFF             (0x1U<<2)
#define FMC_BCHISR_DERF             (0x1U<<1)
#define FMC_BCHISR_DUEF             (0x1U<<0)

// BCHICR Configuration

#define FMC_BCHICR_CEPBRF           (0x1U<<4)
#define FMC_BCHICR_CDSRF            (0x1U<<3)
#define FMC_BCHICR_CDEFF            (0x1U<<2)
#define FMC_BCHICR_CDERF            (0x1U<<1)
#define FMC_BCHICR_CDUEF            (0x1U<<0)

// BCHPBR1 Configuration

#define FMC_BCHPBR1_BCHPB           (0xFFFFFFFFU<<0)
#define FMC_BCHPBR1_BCHPB_0         (0x1U<<0)

// BCHPBR2 Configuration

#define FMC_BCHPBR2_BCHPB           (0xFFFFFFFFU<<0)
#define FMC_BCHPBR2_BCHPB_0         (0x1U<<0)

// BCHPBR3 Configuration

#define FMC_BCHPBR3_BCHPB           (0xFFFFFFFFU<<0)
#define FMC_BCHPBR3_BCHPB_0         (0x1U<<0)

// BCHPBR4 Configuration

#define FMC_BCHPBR4_BCHPB           (0xFFU<<0)
#define FMC_BCHPBR4_BCHPB_0         (0x1U<<0)

// BCHDSR0 Configuration

#define FMC_BCHDSR0_DEN             (0xFU<<4)
#define FMC_BCHDSR0_DEN_0           (0x1U<<4)
#define FMC_BCHDSR0_DEF             (0x1U<<1)
#define FMC_BCHDSR0_DUE             (0x1U<<0)

// BCHDSR1 Configuration

#define FMC_BCHDSR1_EBP2            (0x1FFFU<<16)
#define FMC_BCHDSR1_EBP2_0          (0x1U<<16)
#define FMC_BCHDSR1_EBP1            (0x1FFFU<<0)
#define FMC_BCHDSR1_EBP1_0          (0x1U<<0)

// BCHDSR2 Configuration

#define FMC_BCHDSR2_EBP4            (0x1FFFU<<16)
#define FMC_BCHDSR2_EBP4_0          (0x1U<<16)
#define FMC_BCHDSR2_EBP3            (0x1FFFU<<0)
#define FMC_BCHDSR2_EBP3_0          (0x1U<<0)

// BCHDSR3 Configuration

#define FMC_BCHDSR3_EBP6            (0x1FFFU<<16)
#define FMC_BCHDSR3_EBP6_0          (0x1U<<16)
#define FMC_BCHDSR3_EBP5            (0x1FFFU<<0)
#define FMC_BCHDSR3_EBP5_0          (0x1U<<0)

// BCHDSR4 Configuration

#define FMC_BCHDSR4_EBP8            (0x1FFFU<<16)
#define FMC_BCHDSR4_EBP8_0          (0x1U<<16)
#define FMC_BCHDSR4_EBP7            (0x1FFFU<<0)
#define FMC_BCHDSR4_EBP7_0          (0x1U<<0)
