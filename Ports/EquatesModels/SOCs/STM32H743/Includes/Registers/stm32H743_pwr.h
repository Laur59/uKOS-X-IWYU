/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_pwr equates.
 */

#pragma once

#include    <stdint.h>

// PWR address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CSR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
    volatile    uint32_t    CPUCR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    D3CR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    WKUPCR;
    volatile    uint32_t    WKUPFR;
    volatile    uint32_t    WKUPEPR;
} PWR_TypeDef;

#ifdef __cplusplus
#define PWR reinterpret_cast<PWR_TypeDef *>(0x58024800U)

#else
#define PWR ((PWR_TypeDef *)0x58024800U)
#endif

// CR1 Configuration

#define PWR_CR1_ALS             (0x3U<<17U)
#define PWR_CR1_ALS_0           (0x1U<<17U)
#define PWR_CR1_AVDEN           (0x1U<<16U)
#define PWR_CR1_SVOS            (0x3U<<14U)
#define PWR_CR1_SVOS_0          (0x1U<<14U)
#define PWR_CR1_FLPS            (0x1U<<9U)
#define PWR_CR1_DBP             (0x1U<<8U)
#define PWR_CR1_PLS             (0x7U<<5U)
#define PWR_CR1_PLS_0           (0x1U<<5U)
#define PWR_CR1_PVDE            (0x1U<<4U)
#define PWR_CR1_LPDS            (0x1U<<0U)

// CSR1 Configuration

#define PWR_CSR1_AVDO           (0x1U<<16U)
#define PWR_CSR1_ACTVOS         (0x3U<<14U)
#define PWR_CSR1_ACTVOS_0       (0x1U<<14U)
#define PWR_CSR1_ACTVOSRDY      (0x1U<<13U)
#define PWR_CSR1_PVDO           (0x1U<<4U)

// CR2 Configuration

#define PWR_CR2_TEMPH           (0x1U<<23U)
#define PWR_CR2_TEMPL           (0x1U<<22U)
#define PWR_CR2_VBATH           (0x1U<<21U)
#define PWR_CR2_VBATL           (0x1U<<20U)
#define PWR_CR2_BRRDY           (0x1U<<16U)
#define PWR_CR2_MONEN           (0x1U<<4U)
#define PWR_CR2_BREN            (0x1U<<0U)

// CR3 Configuration

#define PWR_CR3_USB33RDY        (0x1U<<26U)
#define PWR_CR3_USBREGEN        (0x1U<<25U)
#define PWR_CR3_USB33DEN        (0x1U<<24U)
#define PWR_CR3_VBRS            (0x1U<<9U)
#define PWR_CR3_VBE             (0x1U<<8U)
#define PWR_CR3_SCUEN           (0x1U<<2U)
#define PWR_CR3_LDOEN           (0x1U<<1U)
#define PWR_CR3_BYPASS          (0x1U<<0U)

// CPUCR Configuration

#define PWR_CPUCR_RUN_D3        (0x1U<<11U)
#define PWR_CPUCR_CSSF          (0x1U<<9U)
#define PWR_CPUCR_SBF_D2        (0x1U<<8U)
#define PWR_CPUCR_SBF_D1        (0x1U<<7U)
#define PWR_CPUCR_SBF           (0x1U<<6U)
#define PWR_CPUCR_STOPF         (0x1U<<5U)
#define PWR_CPUCR_PDDS_D3       (0x1U<<2U)
#define PWR_CPUCR_PDDS_D2       (0x1U<<1U)
#define PWR_CPUCR_PDDS_D1       (0x1U<<0U)

// D3CR Configuration

#define PWR_D3CR_VOS            (0x3U<<14U)
#define PWR_D3CR_VOS_0          (0x1U<<14U)
#define PWR_D3CR_VOSRDY         (0x1U<<13U)

// WKUPCR Configuration

#define PWR_WKUPCR_WKUPC        (0x3FU<<0U)
#define PWR_WKUPCR_WKUPC_0      (0x1U<<0U)

// WKUPFR Configuration

#define PWR_WKUPFR_WKUPF6       (0x1U<<5U)
#define PWR_WKUPFR_WKUPF5       (0x1U<<4U)
#define PWR_WKUPFR_WKUPF4       (0x1U<<3U)
#define PWR_WKUPFR_WKUPF3       (0x1U<<2U)
#define PWR_WKUPFR_WKUPF2       (0x1U<<1U)
#define PWR_WKUPFR_WKUPF1       (0x1U<<0U)

// WKUPEPR Configuration

#define PWR_WKUPEPR_WKUPPUPD6   (0x3U<<26U)
#define PWR_WKUPEPR_WKUPPUPD6_0 (0x1U<<26U)
#define PWR_WKUPEPR_WKUPPUPD5   (0x3U<<24U)
#define PWR_WKUPEPR_WKUPPUPD5_0 (0x1U<<24U)
#define PWR_WKUPEPR_WKUPPUPD4   (0x3U<<22U)
#define PWR_WKUPEPR_WKUPPUPD4_0 (0x1U<<22U)
#define PWR_WKUPEPR_WKUPPUPD3   (0x3U<<20U)
#define PWR_WKUPEPR_WKUPPUPD3_0 (0x1U<<20U)
#define PWR_WKUPEPR_WKUPPUPD2   (0x3U<<18U)
#define PWR_WKUPEPR_WKUPPUPD2_0 (0x1U<<18U)
#define PWR_WKUPEPR_WKUPPUPD1   (0x3U<<16U)
#define PWR_WKUPEPR_WKUPPUPD1_0 (0x1U<<16U)
#define PWR_WKUPEPR_WKUPP6      (0x1U<<13U)
#define PWR_WKUPEPR_WKUPP5      (0x1U<<12U)
#define PWR_WKUPEPR_WKUPP4      (0x1U<<11U)
#define PWR_WKUPEPR_WKUPP3      (0x1U<<10U)
#define PWR_WKUPEPR_WKUPP2      (0x1U<<9U)
#define PWR_WKUPEPR_WKUPP1      (0x1U<<8U)
#define PWR_WKUPEPR_WKUPEN6     (0x1U<<5U)
#define PWR_WKUPEPR_WKUPEN5     (0x1U<<4U)
#define PWR_WKUPEPR_WKUPEN4     (0x1U<<3U)
#define PWR_WKUPEPR_WKUPEN3     (0x1U<<2U)
#define PWR_WKUPEPR_WKUPEN2     (0x1U<<1U)
#define PWR_WKUPEPR_WKUPEN1     (0x1U<<0U)
