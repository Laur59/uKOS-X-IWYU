/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_opamp equates.
 */

#pragma once

#include    <stdint.h>

// OPAMP address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    OPAMP1_CSR;
    volatile    uint32_t    OPAMP1_OTR;
    volatile    uint32_t    OPAMP1_LPOTR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    OPAMP2_CSR;
    volatile    uint32_t    OPAMP2_OTR;
    volatile    uint32_t    OPAMP2_LPOTR;
} OPAMP_TypeDef;

#ifdef __cplusplus
#define OPAMP   reinterpret_cast<OPAMP_TypeDef *>(0x40007800U)

#else
#define OPAMP   ((OPAMP_TypeDef *)0x40007800U)
#endif

// OPAMP1_CSR Configuration

#define OPAMP_OPAMP1_CSR_OPA_RANGE          (0x1U<<31U)
#define OPAMP_OPAMP1_CSR_CALOUT             (0x1U<<15U)
#define OPAMP_OPAMP1_CSR_USERTRIM           (0x1U<<14U)
#define OPAMP_OPAMP1_CSR_CALSEL             (0x1U<<13U)
#define OPAMP_OPAMP1_CSR_CALON              (0x1U<<12U)
#define OPAMP_OPAMP1_CSR_VP_SEL             (0x1U<<10U)
#define OPAMP_OPAMP1_CSR_VM_SEL             (0x3U<<8U)
#define OPAMP_OPAMP1_CSR_VM_SEL_0           (0x1U<<8U)
#define OPAMP_OPAMP1_CSR_PGA_GAIN           (0x3U<<4U)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_0         (0x1U<<4U)
#define OPAMP_OPAMP1_CSR_OPAMODE            (0x3U<<2U)
#define OPAMP_OPAMP1_CSR_OPAMODE_0          (0x1U<<2U)
#define OPAMP_OPAMP1_CSR_OPALPM             (0x1U<<1U)
#define OPAMP_OPAMP1_CSR_OPAEN              (0x1U<<0U)

// OPAMP1_OTR Configuration

#define OPAMP_OPAMP1_OTR_TRIMOFFSETP        (0x1FU<<8U)
#define OPAMP_OPAMP1_OTR_TRIMOFFSETP_0      (0x1U<<8U)
#define OPAMP_OPAMP1_OTR_TRIMOFFSETN        (0x1FU<<0U)
#define OPAMP_OPAMP1_OTR_TRIMOFFSETN_0      (0x1U<<0U)

// OPAMP1_LPOTR Configuration

#define OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETP    (0x1FU<<8U)
#define OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETP_0  (0x1U<<8U)
#define OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETN    (0x1FU<<0U)
#define OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETN_0  (0x1U<<0U)

// OPAMP2_CSR Configuration

#define OPAMP_OPAMP2_CSR_CALOUT             (0x1U<<15U)
#define OPAMP_OPAMP2_CSR_USERTRIM           (0x1U<<14U)
#define OPAMP_OPAMP2_CSR_CALSEL             (0x1U<<13U)
#define OPAMP_OPAMP2_CSR_CALON              (0x1U<<12U)
#define OPAMP_OPAMP2_CSR_VP_SEL             (0x1U<<10U)
#define OPAMP_OPAMP2_CSR_VM_SEL             (0x3U<<8U)
#define OPAMP_OPAMP2_CSR_VM_SEL_0           (0x1U<<8U)
#define OPAMP_OPAMP2_CSR_PGA_GAIN           (0x3U<<4U)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_0         (0x1U<<4U)
#define OPAMP_OPAMP2_CSR_OPAMODE            (0x3U<<2U)
#define OPAMP_OPAMP2_CSR_OPAMODE_0          (0x1U<<2U)
#define OPAMP_OPAMP2_CSR_OPALPM             (0x1U<<1U)
#define OPAMP_OPAMP2_CSR_OPAEN              (0x1U<<0U)

// OPAMP2_OTR Configuration

#define OPAMP_OPAMP2_OTR_TRIMOFFSETP        (0x1FU<<8U)
#define OPAMP_OPAMP2_OTR_TRIMOFFSETP_0      (0x1U<<8U)
#define OPAMP_OPAMP2_OTR_TRIMOFFSETN        (0x1FU<<0U)
#define OPAMP_OPAMP2_OTR_TRIMOFFSETN_0      (0x1U<<0U)

// OPAMP2_LPOTR Configuration

#define OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETP    (0x1FU<<8U)
#define OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETP_0  (0x1U<<8U)
#define OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETN    (0x1FU<<0U)
#define OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETN_0  (0x1U<<0U)
