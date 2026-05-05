/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_pka equates.
 */
#pragma once

#include    <stdint.h>

// PKA address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    CLRFR;
} PKA_TypeDef;

#if (defined(__cplusplus))
#define PKA_NS  reinterpret_cast<PKA_TypeDef *>(0x44022000u)
#define PKA_S   reinterpret_cast<PKA_TypeDef *>(0x54022000u)

#else
#define PKA_NS  ((PKA_TypeDef *)0x44022000u)
#define PKA_S   ((PKA_TypeDef *)0x54022000u)
#endif

// CR Configuration

#define PKA_CR_CMFIE                (0x1u<<22)
#define PKA_CR_OPERRIE              (0x1u<<21)
#define PKA_CR_ADDRERRIE            (0x1u<<20)
#define PKA_CR_RAMERRIE             (0x1u<<19)
#define PKA_CR_PROCENDIE            (0x1u<<17)
#define PKA_CR_MODE                 (0x3Fu<<8)
#define PKA_CR_MODE_0               (0x1u<<8)
#define PKA_CR_START                (0x1u<<1)
#define PKA_CR_EN                   (0x1u<<0)

#define PKA_CR_CMFIE_B_0X0          (0x0u<<22)
#define PKA_CR_CMFIE_B_0X1          (0x1u<<22)
#define PKA_CR_OPERRIE_B_0X0        (0x0u<<21)
#define PKA_CR_OPERRIE_B_0X1        (0x1u<<21)
#define PKA_CR_ADDRERRIE_B_0X0      (0x0u<<20)
#define PKA_CR_ADDRERRIE_B_0X1      (0x1u<<20)
#define PKA_CR_RAMERRIE_B_0X0       (0x0u<<19)
#define PKA_CR_RAMERRIE_B_0X1       (0x1u<<19)
#define PKA_CR_PROCENDIE_B_0X0      (0x0u<<17)
#define PKA_CR_PROCENDIE_B_0X1      (0x1u<<17)
#define PKA_CR_MODE_B_0X0           (0x0u<<8)
#define PKA_CR_MODE_B_0X1           (0x1u<<8)
#define PKA_CR_MODE_B_0X2           (0x2u<<8)
#define PKA_CR_MODE_B_0X3           (0x3u<<8)
#define PKA_CR_MODE_B_0X20          (0x20u<<8)
#define PKA_CR_MODE_B_0X24          (0x24u<<8)
#define PKA_CR_MODE_B_0X26          (0x26u<<8)
#define PKA_CR_MODE_B_0X28          (0x28u<<8)
#define PKA_CR_MODE_B_0X7           (0x7u<<8)
#define PKA_CR_MODE_B_0X8           (0x8u<<8)
#define PKA_CR_MODE_B_0X9           (0x9u<<8)
#define PKA_CR_MODE_B_0XA           (0xAu<<8)
#define PKA_CR_MODE_B_0XB           (0xBu<<8)
#define PKA_CR_MODE_B_0XC           (0xCu<<8)
#define PKA_CR_MODE_B_0XD           (0xDu<<8)
#define PKA_CR_MODE_B_0XE           (0xEu<<8)
#define PKA_CR_MODE_B_0XF           (0xFu<<8)
#define PKA_CR_MODE_B_0X10          (0x10u<<8)
#define PKA_CR_MODE_B_0X23          (0x23u<<8)
#define PKA_CR_MODE_B_0X27          (0x27u<<8)
#define PKA_CR_MODE_B_0X2F          (0x2Fu<<8)
#define PKA_CR_EN_B_0X0             (0x0u<<0)
#define PKA_CR_EN_B_0X1             (0x1u<<0)

// SR Configuration

#define PKA_SR_CMF                  (0x1u<<22)
#define PKA_SR_OPERRF               (0x1u<<21)
#define PKA_SR_ADDRERRF             (0x1u<<20)
#define PKA_SR_RAMERRF              (0x1u<<19)
#define PKA_SR_PROCENDF             (0x1u<<17)
#define PKA_SR_BUSY                 (0x1u<<16)
#define PKA_SR_CCBERRF              (0x1u<<15)
#define PKA_SR_RNGERRF              (0x1u<<14)
#define PKA_SR_MDERRF               (0x1u<<13)
#define PKA_SR_TRZERRF              (0x1u<<12)
#define PKA_SR_DATAZF               (0x1u<<11)
#define PKA_SR_INCRERRF             (0x1u<<10)
#define PKA_SR_DATAOKF              (0x1u<<9)
#define PKA_SR_RNGOKF               (0x1u<<8)
#define PKA_SR_CCEN                 (0x1u<<2)
#define PKA_SR_LMF                  (0x1u<<1)
#define PKA_SR_INITOK               (0x1u<<0)

#define PKA_SR_CMF_B_0X0            (0x0u<<22)
#define PKA_SR_CMF_B_0X1            (0x1u<<22)
#define PKA_SR_OPERRF_B_0X0         (0x0u<<21)
#define PKA_SR_OPERRF_B_0X1         (0x1u<<21)
#define PKA_SR_ADDRERRF_B_0X0       (0x0u<<20)
#define PKA_SR_ADDRERRF_B_0X1       (0x1u<<20)
#define PKA_SR_RAMERRF_B_0X0        (0x0u<<19)
#define PKA_SR_RAMERRF_B_0X1        (0x1u<<19)
#define PKA_SR_PROCENDF_B_0X0       (0x0u<<17)
#define PKA_SR_PROCENDF_B_0X1       (0x1u<<17)
#define PKA_SR_BUSY_B_0X0           (0x0u<<16)
#define PKA_SR_BUSY_B_0X1           (0x1u<<16)
#define PKA_SR_CCBERRF_B_0X0        (0x0u<<15)
#define PKA_SR_CCBERRF_B_0X1        (0x1u<<15)
#define PKA_SR_RNGERRF_B_0X0        (0x0u<<14)
#define PKA_SR_RNGERRF_B_0X1        (0x1u<<14)
#define PKA_SR_MDERRF_B_0X0         (0x0u<<13)
#define PKA_SR_MDERRF_B_0X1         (0x1u<<13)
#define PKA_SR_TRZERRF_B_0X0        (0x0u<<12)
#define PKA_SR_TRZERRF_B_0X1        (0x1u<<12)
#define PKA_SR_DATAZF_B_0X0         (0x0u<<11)
#define PKA_SR_DATAZF_B_0X1         (0x1u<<11)
#define PKA_SR_INCRERRF_B_0X0       (0x0u<<10)
#define PKA_SR_INCRERRF_B_0X1       (0x1u<<10)
#define PKA_SR_DATAOKF_B_0X0        (0x0u<<9)
#define PKA_SR_DATAOKF_B_0X1        (0x1u<<9)
#define PKA_SR_RNGOKF_B_0X0         (0x0u<<8)
#define PKA_SR_RNGOKF_B_0X1         (0x1u<<8)
#define PKA_SR_CCEN_B_0X0           (0x0u<<2)
#define PKA_SR_CCEN_B_0X1           (0x1u<<2)
#define PKA_SR_LMF_B_0X0            (0x0u<<1)
#define PKA_SR_LMF_B_0X1            (0x1u<<1)
#define PKA_SR_INITOK_B_0X0         (0x0u<<0)
#define PKA_SR_INITOK_B_0X1         (0x1u<<0)

// CLRFR Configuration

#define PKA_CLRFR_CMFC              (0x1u<<22)
#define PKA_CLRFR_OPERRFC           (0x1u<<21)
#define PKA_CLRFR_ADDRERRFC         (0x1u<<20)
#define PKA_CLRFR_RAMERRFC          (0x1u<<19)
#define PKA_CLRFR_PROCENDFC         (0x1u<<17)

#define PKA_CLRFR_CMFC_B_0X0        (0x0u<<22)
#define PKA_CLRFR_CMFC_B_0X1        (0x1u<<22)
#define PKA_CLRFR_OPERRFC_B_0X0     (0x0u<<21)
#define PKA_CLRFR_OPERRFC_B_0X1     (0x1u<<21)
#define PKA_CLRFR_ADDRERRFC_B_0X0   (0x0u<<20)
#define PKA_CLRFR_ADDRERRFC_B_0X1   (0x1u<<20)
#define PKA_CLRFR_RAMERRFC_B_0X0    (0x0u<<19)
#define PKA_CLRFR_RAMERRFC_B_0X1    (0x1u<<19)
#define PKA_CLRFR_PROCENDFC_B_0X0   (0x0u<<17)
#define PKA_CLRFR_PROCENDFC_B_0X1   (0x1u<<17)
