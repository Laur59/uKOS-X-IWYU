/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_dmamux2 equates.
 */

#pragma once

#include    <stdint.h>

// DMAMUX2 address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    C0CR;
    volatile    uint32_t    C1CR;
    volatile    uint32_t    C2CR;
    volatile    uint32_t    C3CR;
    volatile    uint32_t    C4CR;
    volatile    uint32_t    C5CR;
    volatile    uint32_t    C6CR;
    volatile    uint32_t    C7CR;
    volatile    uint32_t    RESERVED0[24];
    volatile    uint32_t    CSR;
    volatile    uint32_t    CFR;
    volatile    uint32_t    RESERVED1[30];
    volatile    uint32_t    RG0CR;
    volatile    uint32_t    RG1CR;
    volatile    uint32_t    RG2CR;
    volatile    uint32_t    RG3CR;
    volatile    uint32_t    RG4CR;
    volatile    uint32_t    RG5CR;
    volatile    uint32_t    RG6CR;
    volatile    uint32_t    RG7CR;
    volatile    uint32_t    RESERVED2[8];
    volatile    uint32_t    RGSR;
    volatile    uint32_t    RGCFR;
} DMAMUX2_TypeDef;

#ifdef __cplusplus
#define DMAMUX2 reinterpret_cast<DMAMUX2_TypeDef *>(0x58025800U)

#else
#define DMAMUX2 ((DMAMUX2_TypeDef *)0x58025800U)
#endif

// C0CR Configuration

#define DMAMUX2_C0CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C0CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C0CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C0CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C0CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C0CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C0CR_SE             (0x1U<<16U)
#define DMAMUX2_C0CR_EGE            (0x1U<<9U)
#define DMAMUX2_C0CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C0CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C0CR_DMAREQ_ID_0    (0x1U<<0U)

// C1CR Configuration

#define DMAMUX2_C1CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C1CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C1CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C1CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C1CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C1CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C1CR_SE             (0x1U<<16U)
#define DMAMUX2_C1CR_EGE            (0x1U<<9U)
#define DMAMUX2_C1CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C1CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C1CR_DMAREQ_ID_0    (0x1U<<0U)

// C2CR Configuration

#define DMAMUX2_C2CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C2CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C2CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C2CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C2CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C2CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C2CR_SE             (0x1U<<16U)
#define DMAMUX2_C2CR_EGE            (0x1U<<9U)
#define DMAMUX2_C2CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C2CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C2CR_DMAREQ_ID_0    (0x1U<<0U)

// C3CR Configuration

#define DMAMUX2_C3CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C3CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C3CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C3CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C3CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C3CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C3CR_SE             (0x1U<<16U)
#define DMAMUX2_C3CR_EGE            (0x1U<<9U)
#define DMAMUX2_C3CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C3CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C3CR_DMAREQ_ID_0    (0x1U<<0U)

// C4CR Configuration

#define DMAMUX2_C4CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C4CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C4CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C4CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C4CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C4CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C4CR_SE             (0x1U<<16U)
#define DMAMUX2_C4CR_EGE            (0x1U<<9U)
#define DMAMUX2_C4CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C4CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C4CR_DMAREQ_ID_0    (0x1U<<0U)

// C5CR Configuration

#define DMAMUX2_C5CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C5CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C5CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C5CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C5CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C5CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C5CR_SE             (0x1U<<16U)
#define DMAMUX2_C5CR_EGE            (0x1U<<9U)
#define DMAMUX2_C5CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C5CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C5CR_DMAREQ_ID_0    (0x1U<<0U)

// C6CR Configuration

#define DMAMUX2_C6CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C6CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C6CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C6CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C6CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C6CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C6CR_SE             (0x1U<<16U)
#define DMAMUX2_C6CR_EGE            (0x1U<<9U)
#define DMAMUX2_C6CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C6CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C6CR_DMAREQ_ID_0    (0x1U<<0U)

// C7CR Configuration

#define DMAMUX2_C7CR_SYNC_ID        (0x1FU<<24U)
#define DMAMUX2_C7CR_SYNC_ID_0      (0x1U<<24U)
#define DMAMUX2_C7CR_NBREQ          (0x1FU<<19U)
#define DMAMUX2_C7CR_NBREQ_0        (0x1U<<19U)
#define DMAMUX2_C7CR_SPOL           (0x3U<<17U)
#define DMAMUX2_C7CR_SPOL_0         (0x1U<<17U)
#define DMAMUX2_C7CR_SE             (0x1U<<16U)
#define DMAMUX2_C7CR_EGE            (0x1U<<9U)
#define DMAMUX2_C7CR_SOIE           (0x1U<<8U)
#define DMAMUX2_C7CR_DMAREQ_ID      (0xFFU<<0U)
#define DMAMUX2_C7CR_DMAREQ_ID_0    (0x1U<<0U)

// CSR Configuration

#define DMAMUX2_CSR_SOF             (0xFFFFU<<0U)
#define DMAMUX2_CSR_SOF_0           (0x1U<<0U)

// CFR Configuration

#define DMAMUX2_CFR_CSOF            (0xFFFFU<<0U)
#define DMAMUX2_CFR_CSOF_0          (0x1U<<0U)

// RG0CR Configuration

#define DMAMUX2_RG0CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG0CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG0CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG0CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG0CR_GE            (0x1U<<16U)
#define DMAMUX2_RG0CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG0CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG0CR_SIG_ID_0      (0x1U<<0U)

// RG1CR Configuration

#define DMAMUX2_RG1CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG1CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG1CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG1CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG1CR_GE            (0x1U<<16U)
#define DMAMUX2_RG1CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG1CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG1CR_SIG_ID_0      (0x1U<<0U)

// RG2CR Configuration

#define DMAMUX2_RG2CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG2CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG2CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG2CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG2CR_GE            (0x1U<<16U)
#define DMAMUX2_RG2CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG2CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG2CR_SIG_ID_0      (0x1U<<0U)

// RG3CR Configuration

#define DMAMUX2_RG3CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG3CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG3CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG3CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG3CR_GE            (0x1U<<16U)
#define DMAMUX2_RG3CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG3CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG3CR_SIG_ID_0      (0x1U<<0U)

// RG4CR Configuration

#define DMAMUX2_RG4CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG4CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG4CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG4CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG4CR_GE            (0x1U<<16U)
#define DMAMUX2_RG4CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG4CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG4CR_SIG_ID_0      (0x1U<<0U)

// RG5CR Configuration

#define DMAMUX2_RG5CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG5CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG5CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG5CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG5CR_GE            (0x1U<<16U)
#define DMAMUX2_RG5CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG5CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG5CR_SIG_ID_0      (0x1U<<0U)

// RG6CR Configuration

#define DMAMUX2_RG6CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG6CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG6CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG6CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG6CR_GE            (0x1U<<16U)
#define DMAMUX2_RG6CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG6CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG6CR_SIG_ID_0      (0x1U<<0U)

// RG7CR Configuration

#define DMAMUX2_RG7CR_GNBREQ        (0x1FU<<19U)
#define DMAMUX2_RG7CR_GNBREQ_0      (0x1U<<19U)
#define DMAMUX2_RG7CR_GPOL          (0x3U<<17U)
#define DMAMUX2_RG7CR_GPOL_0        (0x1U<<17U)
#define DMAMUX2_RG7CR_GE            (0x1U<<16U)
#define DMAMUX2_RG7CR_OIE           (0x1U<<8U)
#define DMAMUX2_RG7CR_SIG_ID        (0x1FU<<0U)
#define DMAMUX2_RG7CR_SIG_ID_0      (0x1U<<0U)

// RGSR Configuration

#define DMAMUX2_RGSR_OF             (0xFFU<<0U)
#define DMAMUX2_RGSR_OF_0           (0x1U<<0U)

// RGCFR Configuration

#define DMAMUX2_RGCFR_COF           (0xFFU<<0U)
#define DMAMUX2_RGCFR_COF_0         (0x1U<<0U)
