/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_cordic equates.
 */

#pragma once

#include    <stdint.h>

// CORDIC address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    WDATA;
    volatile    uint32_t    RDATA;
} CORDIC_TypeDef;

#ifdef __cplusplus
#define CORDIC_NS   reinterpret_cast<CORDIC_TypeDef *>(0x40021000U)
#define CORDIC_S    reinterpret_cast<CORDIC_TypeDef *>(0x50021000U)

#else
#define CORDIC_NS   ((CORDIC_TypeDef *)0x40021000U)
#define CORDIC_S    ((CORDIC_TypeDef *)0x50021000U)
#endif

// CSR Configuration

#define CORDIC_CSR_RRDY         (0x1U<<31U)
#define CORDIC_CSR_ARGSIZE      (0x1U<<22U)
#define CORDIC_CSR_RESSIZE      (0x1U<<21U)
#define CORDIC_CSR_NARGS        (0x1U<<20U)
#define CORDIC_CSR_NRES         (0x1U<<19U)
#define CORDIC_CSR_DMAWEN       (0x1U<<18U)
#define CORDIC_CSR_DMAREN       (0x1U<<17U)
#define CORDIC_CSR_IEN          (0x1U<<16U)
#define CORDIC_CSR_SCALE        (0x7U<<8U)
#define CORDIC_CSR_SCALE_0      (0x1U<<8U)
#define CORDIC_CSR_PRECISION    (0xFU<<4U)
#define CORDIC_CSR_PRECISION_0  (0x1U<<4U)
#define CORDIC_CSR_FUNC         (0xFU<<0U)
#define CORDIC_CSR_FUNC_0       (0x1U<<0U)

// WDATA Configuration

#define CORDIC_WDATA_ARG        (0xFFFFFFFFU<<0U)
#define CORDIC_WDATA_ARG_0      (0x1U<<0U)

// RDATA Configuration

#define CORDIC_RDATA_RES        (0xFFFFFFFFU<<0U)
#define CORDIC_RDATA_RES_0      (0x1U<<0U)
