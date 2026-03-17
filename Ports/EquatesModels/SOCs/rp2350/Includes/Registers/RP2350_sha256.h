/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; RP2350_sha256.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     RP2350_sha256 equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// SHA256 address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    WDATA;
    volatile    uint32_t    SUM0;
    volatile    uint32_t    SUM1;
    volatile    uint32_t    SUM2;
    volatile    uint32_t    SUM3;
    volatile    uint32_t    SUM4;
    volatile    uint32_t    SUM5;
    volatile    uint32_t    SUM6;
    volatile    uint32_t    SUM7;
} SHA256_TypeDef;

#ifdef __cplusplus
#define SHA256_NS   reinterpret_cast<SHA256_TypeDef *>(0x400F8000U)
#define SHA256_S    reinterpret_cast<SHA256_TypeDef *>(0x400F8000U)
#else
#define SHA256_NS   ((SHA256_TypeDef *)0x400F8000U)
#define SHA256_S    ((SHA256_TypeDef *)0x400F8000U)
#endif

// CSR Configuration

#define SHA256_CSR_START                (0x1U<<0)
#define SHA256_CSR_WDATA_RDY            (0x1U<<1)
#define SHA256_CSR_SUM_VLD              (0x1U<<2)
#define SHA256_CSR_ERR_WDATA_NOT_RDY    (0x1U<<4)
#define SHA256_CSR_DMA_SIZE             (0x3U<<8)
#define SHA256_CSR_DMA_SIZE_0           (0x1U<<8)
#define SHA256_CSR_BSWAP                (0x1U<<12)
#define SHA256_CSR_DMA_SIZE_8BIT        (0x0U<<8)
#define SHA256_CSR_DMA_SIZE_16BIT       (0x1U<<8)
#define SHA256_CSR_DMA_SIZE_32BIT       (0x2U<<8)

// WDATA Configuration

#define SHA256_WDATA_WDATA              (0xFFFFFFFFU<<0)
#define SHA256_WDATA_WDATA_0            (0x1U<<0)

// SUM0 Configuration

#define SHA256_SUM0_SUM0                (0xFFFFFFFFU<<0)
#define SHA256_SUM0_SUM0_0              (0x1U<<0)

// SUM1 Configuration

#define SHA256_SUM1_SUM1                (0xFFFFFFFFU<<0)
#define SHA256_SUM1_SUM1_0              (0x1U<<0)

// SUM2 Configuration

#define SHA256_SUM2_SUM2                (0xFFFFFFFFU<<0)
#define SHA256_SUM2_SUM2_0              (0x1U<<0)

// SUM3 Configuration

#define SHA256_SUM3_SUM3                (0xFFFFFFFFU<<0)
#define SHA256_SUM3_SUM3_0              (0x1U<<0)

// SUM4 Configuration

#define SHA256_SUM4_SUM4                (0xFFFFFFFFU<<0)
#define SHA256_SUM4_SUM4_0              (0x1U<<0)

// SUM5 Configuration

#define SHA256_SUM5_SUM5                (0xFFFFFFFFU<<0)
#define SHA256_SUM5_SUM5_0              (0x1U<<0)

// SUM6 Configuration

#define SHA256_SUM6_SUM6                (0xFFFFFFFFU<<0)
#define SHA256_SUM6_SUM6_0              (0x1U<<0)

// SUM7 Configuration

#define SHA256_SUM7_SUM7                (0xFFFFFFFFU<<0)
#define SHA256_SUM7_SUM7_0              (0x1U<<0)
