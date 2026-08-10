/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_vrefbuf equates.
 */

#pragma once

#include    <stdint.h>

// VREFBUF address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    CCR;
} VREFBUF_TypeDef;

#ifdef __cplusplus
#define VREFBUF_NS  reinterpret_cast<VREFBUF_TypeDef *>(0x46003C00U)
#define VREFBUF_S   reinterpret_cast<VREFBUF_TypeDef *>(0x56003C00U)

#else
#define VREFBUF_NS  ((VREFBUF_TypeDef *)0x46003C00U)
#define VREFBUF_S   ((VREFBUF_TypeDef *)0x56003C00U)
#endif

// CSR Configuration

#define VREFBUF_CSR_VRS         (0x7U<<4U)
#define VREFBUF_CSR_VRS_0       (0x1U<<4U)
#define VREFBUF_CSR_VRR         (0x1U<<3U)
#define VREFBUF_CSR_HIZ         (0x1U<<1U)
#define VREFBUF_CSR_ENVR        (0x1U<<0U)

#define VREFBUF_CSR_VRR_B_0X0   (0x0U<<3U)
#define VREFBUF_CSR_VRR_B_0X1   (0x1U<<3U)
#define VREFBUF_CSR_HIZ_B_0X0   (0x0U<<1U)
#define VREFBUF_CSR_HIZ_B_0X1   (0x1U<<1U)
#define VREFBUF_CSR_ENVR_B_0X0  (0x0U<<0U)
#define VREFBUF_CSR_ENVR_B_0X1  (0x1U<<0U)

// CCR Configuration

#define VREFBUF_CCR_TRIM        (0x3FU<<0U)
#define VREFBUF_CCR_TRIM_0      (0x1U<<0U)
