/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_vrefbuf equates.
 */
#pragma once

#include    <stdint.h>

// VREFBUF address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    CCR;
} VREFBUF_TypeDef;

#if (defined(__cplusplus))
#define VREFBUF_NS  reinterpret_cast<VREFBUF_TypeDef *>(0x46003C00u)
#define VREFBUF_S   reinterpret_cast<VREFBUF_TypeDef *>(0x56003C00u)

#else
#define VREFBUF_NS  ((VREFBUF_TypeDef *)0x46003C00u)
#define VREFBUF_S   ((VREFBUF_TypeDef *)0x56003C00u)
#endif

// CSR Configuration

#define VREFBUF_CSR_VRS         (0x7u<<4)
#define VREFBUF_CSR_VRS_0       (0x1u<<4)
#define VREFBUF_CSR_VRR         (0x1u<<3)
#define VREFBUF_CSR_HIZ         (0x1u<<1)
#define VREFBUF_CSR_ENVR        (0x1u<<0)

#define VREFBUF_CSR_VRR_B_0X0   (0x0u<<3)
#define VREFBUF_CSR_VRR_B_0X1   (0x1u<<3)
#define VREFBUF_CSR_HIZ_B_0X0   (0x0u<<1)
#define VREFBUF_CSR_HIZ_B_0X1   (0x1u<<1)
#define VREFBUF_CSR_ENVR_B_0X0  (0x0u<<0)
#define VREFBUF_CSR_ENVR_B_0X1  (0x1u<<0)

// CCR Configuration

#define VREFBUF_CCR_TRIM        (0x3Fu<<0)
#define VREFBUF_CCR_TRIM_0      (0x1u<<0)
