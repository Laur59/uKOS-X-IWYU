/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_quadspi equates.
 */

#pragma once

#include    <stdint.h>

// QUADSPI address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    DCR;
    volatile    uint32_t    SR;
    volatile    uint32_t    FCR;
    volatile    uint32_t    DLR;
    volatile    uint32_t    CCR;
    volatile    uint32_t    AR;
    volatile    uint32_t    ABR;
    volatile    uint32_t    DR;
    volatile    uint32_t    PSMKR;
    volatile    uint32_t    PSMAR;
    volatile    uint32_t    PIR;
    volatile    uint32_t    LPTR;
} QUADSPI_TypeDef;

#ifdef __cplusplus
#define QUADSPI reinterpret_cast<QUADSPI_TypeDef *>(0x52005000U)

#else
#define QUADSPI ((QUADSPI_TypeDef *)0x52005000U)
#endif

// CR Configuration

#define QUADSPI_CR_PRESCALER        (0xFFU<<24U)
#define QUADSPI_CR_PRESCALER_0      (0x1U<<24U)
#define QUADSPI_CR_PMM              (0x1U<<23U)
#define QUADSPI_CR_APMS             (0x1U<<22U)
#define QUADSPI_CR_TOIE             (0x1U<<20U)
#define QUADSPI_CR_SMIE             (0x1U<<19U)
#define QUADSPI_CR_FTIE             (0x1U<<18U)
#define QUADSPI_CR_TCIE             (0x1U<<17U)
#define QUADSPI_CR_TEIE             (0x1U<<16U)
#define QUADSPI_CR_FTHRES           (0x1FU<<8U)
#define QUADSPI_CR_FTHRES_0         (0x1U<<8U)
#define QUADSPI_CR_FSEL             (0x1U<<7U)
#define QUADSPI_CR_DFM              (0x1U<<6U)
#define QUADSPI_CR_SSHIFT           (0x1U<<4U)
#define QUADSPI_CR_TCEN             (0x1U<<3U)
#define QUADSPI_CR_DMAEN            (0x1U<<2U)
#define QUADSPI_CR_ABORT            (0x1U<<1U)
#define QUADSPI_CR_EN               (0x1U<<0U)

// DCR Configuration

#define QUADSPI_DCR_FSIZE           (0x1FU<<16U)
#define QUADSPI_DCR_FSIZE_0         (0x1U<<16U)
#define QUADSPI_DCR_CSHT            (0x7U<<8U)
#define QUADSPI_DCR_CSHT_0          (0x1U<<8U)
#define QUADSPI_DCR_CKMODE          (0x1U<<0U)

// SR Configuration

#define QUADSPI_SR_FLEVEL           (0x3FU<<8U)
#define QUADSPI_SR_FLEVEL_0         (0x1U<<8U)
#define QUADSPI_SR_BUSY             (0x1U<<5U)
#define QUADSPI_SR_TOF              (0x1U<<4U)
#define QUADSPI_SR_SMF              (0x1U<<3U)
#define QUADSPI_SR_FTF              (0x1U<<2U)
#define QUADSPI_SR_TCF              (0x1U<<1U)
#define QUADSPI_SR_TEF              (0x1U<<0U)

// FCR Configuration

#define QUADSPI_FCR_CTOF            (0x1U<<4U)
#define QUADSPI_FCR_CSMF            (0x1U<<3U)
#define QUADSPI_FCR_CTCF            (0x1U<<1U)
#define QUADSPI_FCR_CTEF            (0x1U<<0U)

// DLR Configuration

#define QUADSPI_DLR_DL              (0xFFFFFFFFU<<0U)
#define QUADSPI_DLR_DL_0            (0x1U<<0U)

// CCR Configuration

#define QUADSPI_CCR_DDRM            (0x1U<<31U)
#define QUADSPI_CCR_DHHC            (0x1U<<30U)
#define QUADSPI_CCR_SIOO            (0x1U<<28U)
#define QUADSPI_CCR_FMODE           (0x3U<<26U)
#define QUADSPI_CCR_FMODE_0         (0x1U<<26U)
#define QUADSPI_CCR_DMODE           (0x3U<<24U)
#define QUADSPI_CCR_DMODE_0         (0x1U<<24U)
#define QUADSPI_CCR_DCYC            (0x1FU<<18U)
#define QUADSPI_CCR_DCYC_0          (0x1U<<18U)
#define QUADSPI_CCR_ABSIZE          (0x3U<<16U)
#define QUADSPI_CCR_ABSIZE_0        (0x1U<<16U)
#define QUADSPI_CCR_ABMODE          (0x3U<<14U)
#define QUADSPI_CCR_ABMODE_0        (0x1U<<14U)
#define QUADSPI_CCR_ADSIZE          (0x3U<<12U)
#define QUADSPI_CCR_ADSIZE_0        (0x1U<<12U)
#define QUADSPI_CCR_ADMODE          (0x3U<<10U)
#define QUADSPI_CCR_ADMODE_0        (0x1U<<10U)
#define QUADSPI_CCR_IMODE           (0x3U<<8U)
#define QUADSPI_CCR_IMODE_0         (0x1U<<8U)
#define QUADSPI_CCR_INSTRUCTION     (0xFFU<<0U)
#define QUADSPI_CCR_INSTRUCTION_0   (0x1U<<0U)

// AR Configuration

#define QUADSPI_AR_ADDRESS          (0xFFFFFFFFU<<0U)
#define QUADSPI_AR_ADDRESS_0        (0x1U<<0U)

// ABR Configuration

#define QUADSPI_ABR_ALTERNATE       (0xFFFFFFFFU<<0U)
#define QUADSPI_ABR_ALTERNATE_0     (0x1U<<0U)

// DR Configuration

#define QUADSPI_DR_DATA             (0xFFFFFFFFU<<0U)
#define QUADSPI_DR_DATA_0           (0x1U<<0U)

// PSMKR Configuration

#define QUADSPI_PSMKR_MASK          (0xFFFFFFFFU<<0U)
#define QUADSPI_PSMKR_MASK_0        (0x1U<<0U)

// PSMAR Configuration

#define QUADSPI_PSMAR_MATCH         (0xFFFFFFFFU<<0U)
#define QUADSPI_PSMAR_MATCH_0       (0x1U<<0U)

// PIR Configuration

#define QUADSPI_PIR_INTERVAL        (0xFFFFU<<0U)
#define QUADSPI_PIR_INTERVAL_0      (0x1U<<0U)

// LPTR Configuration

#define QUADSPI_LPTR_TIMEOUT        (0xFFFFU<<0U)
#define QUADSPI_LPTR_TIMEOUT_0      (0x1U<<0U)
