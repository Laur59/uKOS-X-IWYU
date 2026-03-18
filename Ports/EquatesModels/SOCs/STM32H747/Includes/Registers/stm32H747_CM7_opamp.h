/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_opamp equates.
 */

#pragma once

#include    <stdint.h>

// OPAMP address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    OPAMP1_CSR;
    volatile    uint32_t    OPAMP1_OTR;
    volatile    uint32_t    OPAMP1_HSOTR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    OPAMP2_CSR;
    volatile    uint32_t    OPAMP2_OTR;
    volatile    uint32_t    OPAMP2_HSOTR;
} OPAMP_TypeDef;

#ifdef __cplusplus
#define OPAMP   reinterpret_cast<OPAMP_TypeDef *>(0x40009000U)

#else
#define OPAMP   ((OPAMP_TypeDef *)0x40009000U)
#endif

// OPAMP1_CSR Configuration

#define OPAMP_OPAMP1_CSR_CALOUT             (0x1U<<30)
#define OPAMP_OPAMP1_CSR_TSTREF             (0x1U<<29)
#define OPAMP_OPAMP1_CSR_USERTRIM           (0x1U<<18)
#define OPAMP_OPAMP1_CSR_PGA_GAIN           (0xFU<<14)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_0         (0x1U<<14)
#define OPAMP_OPAMP1_CSR_CALSEL             (0x3U<<12)
#define OPAMP_OPAMP1_CSR_CALSEL_0           (0x1U<<12)
#define OPAMP_OPAMP1_CSR_CALON              (0x1U<<11)
#define OPAMP_OPAMP1_CSR_OPAHSM             (0x1U<<8)
#define OPAMP_OPAMP1_CSR_VM_SEL             (0x3U<<5)
#define OPAMP_OPAMP1_CSR_VM_SEL_0           (0x1U<<5)
#define OPAMP_OPAMP1_CSR_VP_SEL             (0x3U<<2)
#define OPAMP_OPAMP1_CSR_VP_SEL_0           (0x1U<<2)
#define OPAMP_OPAMP1_CSR_FORCE_VP           (0x1U<<1)
#define OPAMP_OPAMP1_CSR_OPAEN              (0x1U<<0)

// OPAMP1_OTR Configuration

#define OPAMP_OPAMP1_OTR_TRIMOFFSETP        (0x1FU<<8)
#define OPAMP_OPAMP1_OTR_TRIMOFFSETP_0      (0x1U<<8)
#define OPAMP_OPAMP1_OTR_TRIMOFFSETN        (0x1FU<<0)
#define OPAMP_OPAMP1_OTR_TRIMOFFSETN_0      (0x1U<<0)

// OPAMP1_HSOTR Configuration

#define OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETP    (0x1FU<<8)
#define OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETP_0  (0x1U<<8)
#define OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETN    (0x1FU<<0)
#define OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETN_0  (0x1U<<0)

// OPAMP2_CSR Configuration

#define OPAMP_OPAMP2_CSR_CALOUT             (0x1U<<30)
#define OPAMP_OPAMP2_CSR_TSTREF             (0x1U<<29)
#define OPAMP_OPAMP2_CSR_USERTRIM           (0x1U<<18)
#define OPAMP_OPAMP2_CSR_PGA_GAIN           (0xFU<<14)
#define OPAMP_OPAMP2_CSR_PGA_GAIN_0         (0x1U<<14)
#define OPAMP_OPAMP2_CSR_CALSEL             (0x3U<<12)
#define OPAMP_OPAMP2_CSR_CALSEL_0           (0x1U<<12)
#define OPAMP_OPAMP2_CSR_CALON              (0x1U<<11)
#define OPAMP_OPAMP2_CSR_OPAHSM             (0x1U<<8)
#define OPAMP_OPAMP2_CSR_VM_SEL             (0x3U<<5)
#define OPAMP_OPAMP2_CSR_VM_SEL_0           (0x1U<<5)
#define OPAMP_OPAMP2_CSR_FORCE_VP           (0x1U<<1)
#define OPAMP_OPAMP2_CSR_OPAEN              (0x1U<<0)

// OPAMP2_OTR Configuration

#define OPAMP_OPAMP2_OTR_TRIMOFFSETP        (0x1FU<<8)
#define OPAMP_OPAMP2_OTR_TRIMOFFSETP_0      (0x1U<<8)
#define OPAMP_OPAMP2_OTR_TRIMOFFSETN        (0x1FU<<0)
#define OPAMP_OPAMP2_OTR_TRIMOFFSETN_0      (0x1U<<0)

// OPAMP2_HSOTR Configuration

#define OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETP    (0x1FU<<8)
#define OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETP_0  (0x1U<<8)
#define OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETN    (0x1FU<<0)
#define OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETN_0  (0x1U<<0)
