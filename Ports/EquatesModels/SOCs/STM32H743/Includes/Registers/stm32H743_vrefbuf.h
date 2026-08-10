/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_vrefbuf equates.
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
#define VREFBUF reinterpret_cast<VREFBUF_TypeDef *>(0x58003C00U)

#else
#define VREFBUF ((VREFBUF_TypeDef *)0x58003C00U)
#endif

// CSR Configuration

#define VREFBUF_CSR_VRS     (0x7U<<4U)
#define VREFBUF_CSR_VRS_0   (0x1U<<4U)
#define VREFBUF_CSR_VRR     (0x1U<<3U)
#define VREFBUF_CSR_HIZ     (0x1U<<1U)
#define VREFBUF_CSR_ENVR    (0x1U<<0U)

// CCR Configuration

#define VREFBUF_CCR_TRIM    (0x3FU<<0U)
#define VREFBUF_CCR_TRIM_0  (0x1U<<0U)
