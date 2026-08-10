/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_opamp equates.
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
    volatile    uint32_t    OPAMP2_CRS;
    volatile    uint32_t    OPAMP2_OTR;
    volatile    uint32_t    OPAMP2_LPOTR;
} OPAMP_TypeDef;

#ifdef __cplusplus
#define OPAMP_NS    reinterpret_cast<OPAMP_TypeDef *>(0x46005000U)
#define OPAMP_S     reinterpret_cast<OPAMP_TypeDef *>(0x56005000U)

#else
#define OPAMP_NS    ((OPAMP_TypeDef *)0x46005000U)
#define OPAMP_S     ((OPAMP_TypeDef *)0x56005000U)
#endif

// OPAMP1_CSR Configuration

#define OPAMP_OPAMP1_CSR_OPA_RANGE          (0x1U<<31U)
#define OPAMP_OPAMP1_CSR_OPAHSM             (0x1U<<30U)
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
#define OPAMP_OPAMP1_CSR_OPA_RANGE_B_0X0    (0x0U<<31U)
#define OPAMP_OPAMP1_CSR_OPA_RANGE_B_0X1    (0x1U<<31U)
#define OPAMP_OPAMP1_CSR_OPAHSM_B_0X0       (0x0U<<30U)
#define OPAMP_OPAMP1_CSR_OPAHSM_B_0X1       (0x1U<<30U)
#define OPAMP_OPAMP1_CSR_USERTRIM_B_0X0     (0x0U<<14U)
#define OPAMP_OPAMP1_CSR_USERTRIM_B_0X1     (0x1U<<14U)
#define OPAMP_OPAMP1_CSR_CALSEL_B_0X0       (0x0U<<13U)
#define OPAMP_OPAMP1_CSR_CALSEL_B_0X1       (0x1U<<13U)
#define OPAMP_OPAMP1_CSR_CALON_B_0X0        (0x0U<<12U)
#define OPAMP_OPAMP1_CSR_CALON_B_0X1        (0x1U<<12U)
#define OPAMP_OPAMP1_CSR_VP_SEL_B_0X0       (0x0U<<10U)
#define OPAMP_OPAMP1_CSR_VP_SEL_B_0X1       (0x1U<<10U)
#define OPAMP_OPAMP1_CSR_VM_SEL_B_0X0       (0x0U<<8U)
#define OPAMP_OPAMP1_CSR_VM_SEL_B_0X1       (0x1U<<8U)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X0     (0x0U<<4U)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X1     (0x1U<<4U)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X2     (0x2U<<4U)
#define OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X3     (0x3U<<4U)
#define OPAMP_OPAMP1_CSR_OPAMODE_B_0X2      (0x2U<<2U)
#define OPAMP_OPAMP1_CSR_OPAMODE_B_0X3      (0x3U<<2U)
#define OPAMP_OPAMP1_CSR_OPALPM_B_0X0       (0x0U<<1U)
#define OPAMP_OPAMP1_CSR_OPALPM_B_0X1       (0x1U<<1U)
#define OPAMP_OPAMP1_CSR_OPAEN_B_0X0        (0x0U<<0U)
#define OPAMP_OPAMP1_CSR_OPAEN_B_0X1        (0x1U<<0U)

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

// OPAMP2_CRS Configuration

#define OPAMP_OPAMP2_CRS_OPAHSM             (0x1U<<30U)
#define OPAMP_OPAMP2_CRS_CALOUT             (0x1U<<15U)
#define OPAMP_OPAMP2_CRS_USERTRIM           (0x1U<<14U)
#define OPAMP_OPAMP2_CRS_CALSEL             (0x1U<<13U)
#define OPAMP_OPAMP2_CRS_CALON              (0x1U<<12U)
#define OPAMP_OPAMP2_CRS_VP_SEL             (0x1U<<10U)
#define OPAMP_OPAMP2_CRS_VM_SEL             (0x3U<<8U)
#define OPAMP_OPAMP2_CRS_VM_SEL_0           (0x1U<<8U)
#define OPAMP_OPAMP2_CRS_PGA_GAIN           (0x3U<<4U)
#define OPAMP_OPAMP2_CRS_PGA_GAIN_0         (0x1U<<4U)
#define OPAMP_OPAMP2_CRS_OPAMODE            (0x3U<<2U)
#define OPAMP_OPAMP2_CRS_OPAMODE_0          (0x1U<<2U)
#define OPAMP_OPAMP2_CRS_OPALPM             (0x1U<<1U)
#define OPAMP_OPAMP2_CRS_OPAEN              (0x1U<<0U)
#define OPAMP_OPAMP2_CRS_OPAHSM_B_0X0       (0x0U<<30U)
#define OPAMP_OPAMP2_CRS_OPAHSM_B_0X1       (0x1U<<30U)
#define OPAMP_OPAMP2_CRS_USERTRIM_B_0X0     (0x0U<<14U)
#define OPAMP_OPAMP2_CRS_USERTRIM_B_0X1     (0x1U<<14U)
#define OPAMP_OPAMP2_CRS_CALSEL_B_0X0       (0x0U<<13U)
#define OPAMP_OPAMP2_CRS_CALSEL_B_0X1       (0x1U<<13U)
#define OPAMP_OPAMP2_CRS_CALON_B_0X0        (0x0U<<12U)
#define OPAMP_OPAMP2_CRS_CALON_B_0X1        (0x1U<<12U)
#define OPAMP_OPAMP2_CRS_VP_SEL_B_0X0       (0x0U<<10U)
#define OPAMP_OPAMP2_CRS_VP_SEL_B_0X1       (0x1U<<10U)
#define OPAMP_OPAMP2_CRS_VM_SEL_B_0X0       (0x0U<<8U)
#define OPAMP_OPAMP2_CRS_VM_SEL_B_0X1       (0x1U<<8U)
#define OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X0     (0x0U<<4U)
#define OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X1     (0x1U<<4U)
#define OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X2     (0x2U<<4U)
#define OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X3     (0x3U<<4U)
#define OPAMP_OPAMP2_CRS_OPAMODE_B_0X2      (0x2U<<2U)
#define OPAMP_OPAMP2_CRS_OPAMODE_B_0X3      (0x3U<<2U)
#define OPAMP_OPAMP2_CRS_OPALPM_B_0X0       (0x0U<<1U)
#define OPAMP_OPAMP2_CRS_OPALPM_B_0X1       (0x1U<<1U)
#define OPAMP_OPAMP2_CRS_OPAEN_B_0X0        (0x0U<<0U)
#define OPAMP_OPAMP2_CRS_OPAEN_B_0X1        (0x1U<<0U)

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
