/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_octospi.
; ==================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_octospi equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// OCTOSPI address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    DCR1;
    volatile    uint32_t    DCR2;
    volatile    uint32_t    DCR3;
    volatile    uint32_t    DCR4;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    SR;
    volatile    uint32_t    FCR;
    volatile    uint32_t    RESERVED2[6];
    volatile    uint32_t    DLR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    AR;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    DR;
    volatile    uint32_t    RESERVED5[11];
    volatile    uint32_t    PSMKR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    PSMAR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    PIR;
    volatile    uint32_t    RESERVED8[27];
    volatile    uint32_t    CCR;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    TCR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    IR;
    volatile    uint32_t    RESERVED11[3];
    volatile    uint32_t    ABR;
    volatile    uint32_t    RESERVED12[3];
    volatile    uint32_t    LPTR;
    volatile    uint32_t    RESERVED13[19];
    volatile    uint32_t    WCCR;
    volatile    uint32_t    RESERVED14;
    volatile    uint32_t    WTCR;
    volatile    uint32_t    RESERVED15;
    volatile    uint32_t    WIR;
    volatile    uint32_t    RESERVED16[3];
    volatile    uint32_t    WABR;
    volatile    uint32_t    RESERVED17[23];
    volatile    uint32_t    HLCR;
} OCTOSPI_TypeDef;

#ifdef __cplusplus
#define OCTOSPI1    reinterpret_cast<OCTOSPI_TypeDef *>(0xA0001000U)
#define OCTOSPI2    reinterpret_cast<OCTOSPI_TypeDef *>(0xA0001400U)

#else
#define OCTOSPI1    ((OCTOSPI_TypeDef *)0xA0001000U)
#define OCTOSPI2    ((OCTOSPI_TypeDef *)0xA0001400U)
#endif

// CR Configuration

#define OCTOSPI_CR_EN               (0x1U<<0)
#define OCTOSPI_CR_ABORT            (0x1U<<1)
#define OCTOSPI_CR_DMAEN            (0x1U<<2)
#define OCTOSPI_CR_TCEN             (0x1U<<3)
#define OCTOSPI_CR_DQM              (0x1U<<6)
#define OCTOSPI_CR_FSEL             (0x1U<<7)
#define OCTOSPI_CR_FTHRES           (0x1FU<<8)
#define OCTOSPI_CR_FTHRES_0         (0x1U<<8)
#define OCTOSPI_CR_TEIE             (0x1U<<16)
#define OCTOSPI_CR_TCIE             (0x1U<<17)
#define OCTOSPI_CR_FTIE             (0x1U<<18)
#define OCTOSPI_CR_SMIE             (0x1U<<19)
#define OCTOSPI_CR_TOIE             (0x1U<<20)
#define OCTOSPI_CR_APMS             (0x1U<<22)
#define OCTOSPI_CR_PMM              (0x1U<<23)
#define OCTOSPI_CR_FMODE            (0x3U<<28)
#define OCTOSPI_CR_FMODE_0          (0x1U<<28)

// DCR1 Configuration

#define OCTOSPI_DCR1_MTYP           (0x7U<<24)
#define OCTOSPI_DCR1_MTYP_0         (0x1U<<24)
#define OCTOSPI_DCR1_DEVSIZE        (0x1FU<<16)
#define OCTOSPI_DCR1_DEVSIZE_0      (0x1U<<16)
#define OCTOSPI_DCR1_CSHT           (0x3FU<<8)
#define OCTOSPI_DCR1_CSHT_0         (0x1U<<8)
#define OCTOSPI_DCR1_DLYBYP         (0x1U<<3)
#define OCTOSPI_DCR1_FRCK           (0x1U<<1)
#define OCTOSPI_DCR1_CKMODE         (0x1U<<0)

// DCR2 Configuration

#define OCTOSPI_DCR2_PRESCALER      (0xFFU<<0)
#define OCTOSPI_DCR2_PRESCALER_0    (0x1U<<0)

// DCR3 Configuration

#define OCTOSPI_DCR3_MAXTRAN        (0xFFU<<0)
#define OCTOSPI_DCR3_MAXTRAN_0      (0x1U<<0)
#define OCTOSPI_DCR3_CSBOUND        (0x1FU<<16)
#define OCTOSPI_DCR3_CSBOUND_0      (0x1U<<16)

// DCR4 Configuration

#define OCTOSPI_DCR4_REFRESH        (0xFFFFFFFFU<<0)
#define OCTOSPI_DCR4_REFRESH_0      (0x1U<<0)

// SR Configuration

#define OCTOSPI_SR_FLEVEL           (0x3FU<<8)
#define OCTOSPI_SR_FLEVEL_0         (0x1U<<8)
#define OCTOSPI_SR_BUSY             (0x1U<<5)
#define OCTOSPI_SR_TOF              (0x1U<<4)
#define OCTOSPI_SR_SMF              (0x1U<<3)
#define OCTOSPI_SR_FTF              (0x1U<<2)
#define OCTOSPI_SR_TCF              (0x1U<<1)
#define OCTOSPI_SR_TEF              (0x1U<<0)

// FCR Configuration

#define OCTOSPI_FCR_CTOF            (0x1U<<4)
#define OCTOSPI_FCR_CSMF            (0x1U<<3)
#define OCTOSPI_FCR_CTCF            (0x1U<<1)
#define OCTOSPI_FCR_CTEF            (0x1U<<0)

// DLR Configuration

#define OCTOSPI_DLR_DL              (0xFFFFFFFFU<<0)
#define OCTOSPI_DLR_DL_0            (0x1U<<0)

// AR Configuration

#define OCTOSPI_AR_ADDRESS          (0xFFFFFFFFU<<0)
#define OCTOSPI_AR_ADDRESS_0        (0x1U<<0)

// DR Configuration

#define OCTOSPI_DR_DATA             (0xFFFFFFFFU<<0)
#define OCTOSPI_DR_DATA_0           (0x1U<<0)

// PSMKR Configuration

#define OCTOSPI_PSMKR_MASK          (0xFFFFFFFFU<<0)
#define OCTOSPI_PSMKR_MASK_0        (0x1U<<0)

// PSMAR Configuration

#define OCTOSPI_PSMAR_MATCH         (0xFFFFFFFFU<<0)
#define OCTOSPI_PSMAR_MATCH_0       (0x1U<<0)

// PIR Configuration

#define OCTOSPI_PIR_INTERVAL        (0xFFFFU<<0)
#define OCTOSPI_PIR_INTERVAL_0      (0x1U<<0)

// CCR Configuration

#define OCTOSPI_CCR_SIOO            (0x1U<<31)
#define OCTOSPI_CCR_DQSE            (0x1U<<29)
#define OCTOSPI_CCR_DDTR            (0x1U<<27)
#define OCTOSPI_CCR_DMODE           (0x7U<<24)
#define OCTOSPI_CCR_DMODE_0         (0x1U<<24)
#define OCTOSPI_CCR_ABSIZE          (0x3U<<20)
#define OCTOSPI_CCR_ABSIZE_0        (0x1U<<20)
#define OCTOSPI_CCR_ABDTR           (0x1U<<19)
#define OCTOSPI_CCR_ABMODE          (0x7U<<16)
#define OCTOSPI_CCR_ABMODE_0        (0x1U<<16)
#define OCTOSPI_CCR_ADSIZE          (0x3U<<12)
#define OCTOSPI_CCR_ADSIZE_0        (0x1U<<12)
#define OCTOSPI_CCR_ADDTR           (0x1U<<11)
#define OCTOSPI_CCR_ADMODE          (0x7U<<8)
#define OCTOSPI_CCR_ADMODE_0        (0x1U<<8)
#define OCTOSPI_CCR_ISIZE           (0x3U<<4)
#define OCTOSPI_CCR_ISIZE_0         (0x1U<<4)
#define OCTOSPI_CCR_IDTR            (0x1U<<3)
#define OCTOSPI_CCR_IMODE           (0x7U<<0)
#define OCTOSPI_CCR_IMODE_0         (0x1U<<0)

// TCR Configuration

#define OCTOSPI_TCR_SSHIFT          (0x1U<<30)
#define OCTOSPI_TCR_DHQC            (0x1U<<28)
#define OCTOSPI_TCR_DCYC            (0x1FU<<0)
#define OCTOSPI_TCR_DCYC_0          (0x1U<<0)

// IR Configuration

#define OCTOSPI_IR_INSTRUCTION      (0xFFFFFFFFU<<0)
#define OCTOSPI_IR_INSTRUCTION_0    (0x1U<<0)

// ABR Configuration

#define OCTOSPI_ABR_ALTERNATE       (0xFFFFFFFFU<<0)
#define OCTOSPI_ABR_ALTERNATE_0     (0x1U<<0)

// LPTR Configuration

#define OCTOSPI_LPTR_TIMEOUT        (0xFFFFU<<0)
#define OCTOSPI_LPTR_TIMEOUT_0      (0x1U<<0)

// WCCR Configuration

#define OCTOSPI_WCCR_DQSE           (0x1U<<29)
#define OCTOSPI_WCCR_DDTR           (0x1U<<27)
#define OCTOSPI_WCCR_DMODE          (0x7U<<24)
#define OCTOSPI_WCCR_DMODE_0        (0x1U<<24)
#define OCTOSPI_WCCR_ABSIZE         (0x3U<<20)
#define OCTOSPI_WCCR_ABSIZE_0       (0x1U<<20)
#define OCTOSPI_WCCR_ABDTR          (0x1U<<19)
#define OCTOSPI_WCCR_ABMODE         (0x7U<<16)
#define OCTOSPI_WCCR_ABMODE_0       (0x1U<<16)
#define OCTOSPI_WCCR_ADSIZE         (0x3U<<12)
#define OCTOSPI_WCCR_ADSIZE_0       (0x1U<<12)
#define OCTOSPI_WCCR_ADDTR          (0x1U<<11)
#define OCTOSPI_WCCR_ADMODE         (0x7U<<8)
#define OCTOSPI_WCCR_ADMODE_0       (0x1U<<8)
#define OCTOSPI_WCCR_ISIZE          (0x3U<<4)
#define OCTOSPI_WCCR_ISIZE_0        (0x1U<<4)
#define OCTOSPI_WCCR_IDTR           (0x1U<<3)
#define OCTOSPI_WCCR_IMODE          (0x7U<<0)
#define OCTOSPI_WCCR_IMODE_0        (0x1U<<0)

// WTCR Configuration

#define OCTOSPI_WTCR_DCYC           (0x1FU<<0)
#define OCTOSPI_WTCR_DCYC_0         (0x1U<<0)

// WIR Configuration

#define OCTOSPI_WIR_INSTRUCTION     (0xFFFFFFFFU<<0)
#define OCTOSPI_WIR_INSTRUCTION_0   (0x1U<<0)

// WABR Configuration

#define OCTOSPI_WABR_ALTERNATE      (0xFFFFFFFFU<<0)
#define OCTOSPI_WABR_ALTERNATE_0    (0x1U<<0)

// HLCR Configuration

#define OCTOSPI_HLCR_TRWR           (0xFFU<<16)
#define OCTOSPI_HLCR_TRWR_0         (0x1U<<16)
#define OCTOSPI_HLCR_TACC           (0xFFU<<8)
#define OCTOSPI_HLCR_TACC_0         (0x1U<<8)
#define OCTOSPI_HLCR_WZL            (0x1U<<1)
#define OCTOSPI_HLCR_LM             (0x1U<<0)
