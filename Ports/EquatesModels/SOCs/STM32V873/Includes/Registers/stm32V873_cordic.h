/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_cordic equates.
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

#if (defined(__cplusplus))
#define CORDIC_NS   reinterpret_cast<CORDIC_TypeDef *>(0x42024400u)
#define CORDIC_S    reinterpret_cast<CORDIC_TypeDef *>(0x52024400u)

#else
#define CORDIC_NS   ((CORDIC_TypeDef *)0x42024400u)
#define CORDIC_S    ((CORDIC_TypeDef *)0x52024400u)
#endif

// CSR Configuration

#define CORDIC_CSR_RRDY             (0x1u<<31)
#define CORDIC_CSR_ARGSIZE          (0x1u<<22)
#define CORDIC_CSR_RESSIZE          (0x1u<<21)
#define CORDIC_CSR_NARGS            (0x1u<<20)
#define CORDIC_CSR_NRES             (0x1u<<19)
#define CORDIC_CSR_DMAWEN           (0x1u<<18)
#define CORDIC_CSR_DMAREN           (0x1u<<17)
#define CORDIC_CSR_IEN              (0x1u<<16)
#define CORDIC_CSR_SCALE            (0x7u<<8)
#define CORDIC_CSR_SCALE_0          (0x1u<<8)
#define CORDIC_CSR_PRECISION        (0xFu<<4)
#define CORDIC_CSR_PRECISION_0      (0x1u<<4)
#define CORDIC_CSR_FUNC             (0xFu<<0)
#define CORDIC_CSR_FUNC_0           (0x1u<<0)

#define CORDIC_CSR_RRDY_B_0X0       (0x0u<<31)
#define CORDIC_CSR_RRDY_B_0X1       (0x1u<<31)
#define CORDIC_CSR_ARGSIZE_B_0X0    (0x0u<<22)
#define CORDIC_CSR_ARGSIZE_B_0X1    (0x1u<<22)
#define CORDIC_CSR_RESSIZE_B_0X0    (0x0u<<21)
#define CORDIC_CSR_RESSIZE_B_0X1    (0x1u<<21)
#define CORDIC_CSR_NARGS_B_0X0      (0x0u<<20)
#define CORDIC_CSR_NARGS_B_0X1      (0x1u<<20)
#define CORDIC_CSR_NRES_B_0X0       (0x0u<<19)
#define CORDIC_CSR_NRES_B_0X1       (0x1u<<19)
#define CORDIC_CSR_DMAWEN_B_0X0     (0x0u<<18)
#define CORDIC_CSR_DMAWEN_B_0X1     (0x1u<<18)
#define CORDIC_CSR_DMAREN_B_0X0     (0x0u<<17)
#define CORDIC_CSR_DMAREN_B_0X1     (0x1u<<17)
#define CORDIC_CSR_IEN_B_0X0        (0x0u<<16)
#define CORDIC_CSR_IEN_B_0X1        (0x1u<<16)
#define CORDIC_CSR_FUNC_B_0X0       (0x0u<<0)
#define CORDIC_CSR_FUNC_B_0X1       (0x1u<<0)

// WDATA Configuration

#define CORDIC_WDATA_ARG            (0xFFFFFFFFu<<0)
#define CORDIC_WDATA_ARG_0          (0x1u<<0)

// RDATA Configuration

#define CORDIC_RDATA_RES            (0xFFFFFFFFu<<0)
#define CORDIC_RDATA_RES_0          (0x1u<<0)
