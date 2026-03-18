/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_ethernet_mmc equates.
 */

#pragma once

#include    <stdint.h>

// ETHERNET_MMC address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    MMCCR;
    volatile    uint32_t    MMCRIR;
    volatile    uint32_t    MMCTIR;
    volatile    uint32_t    MMCRIMR;
    volatile    uint32_t    MMCTIMR;
    volatile    uint32_t    RESERVED0[14];
    volatile    uint32_t    MMCTGFSCCR;
    volatile    uint32_t    MMCTGFMSCCR;
    volatile    uint32_t    RESERVED1[5];
    volatile    uint32_t    MMCTGFCR;
    volatile    uint32_t    RESERVED2[10];
    volatile    uint32_t    MMCRFCECR;
    volatile    uint32_t    MMCRFAECR;
    volatile    uint32_t    RESERVED3[10];
    volatile    uint32_t    MMCRGUFCR;
} ETHERNET_MMC_TypeDef;

#ifdef __cplusplus
#define ETHERNET_MMC    reinterpret_cast<ETHERNET_MMC_TypeDef *>(0x40028100U)

#else
#define ETHERNET_MMC    ((ETHERNET_MMC_TypeDef *)0x40028100U)
#endif

// MMCCR Configuration

#define ETHERNET_MMC_MMCCR_MCFHP            (0x1U<<5)
#define ETHERNET_MMC_MMCCR_MCP              (0x1U<<4)
#define ETHERNET_MMC_MMCCR_MCF              (0x1U<<3)
#define ETHERNET_MMC_MMCCR_ROR              (0x1U<<2)
#define ETHERNET_MMC_MMCCR_CSR              (0x1U<<1)
#define ETHERNET_MMC_MMCCR_CR               (0x1U<<0)

// MMCRIR Configuration

#define ETHERNET_MMC_MMCRIR_RGUFS           (0x1U<<17)
#define ETHERNET_MMC_MMCRIR_RFAES           (0x1U<<6)
#define ETHERNET_MMC_MMCRIR_RFCES           (0x1U<<5)

// MMCTIR Configuration

#define ETHERNET_MMC_MMCTIR_TGFS            (0x1U<<21)
#define ETHERNET_MMC_MMCTIR_TGFMSCS         (0x1U<<15)
#define ETHERNET_MMC_MMCTIR_TGFSCS          (0x1U<<14)

// MMCRIMR Configuration

#define ETHERNET_MMC_MMCRIMR_RGUFM          (0x1U<<17)
#define ETHERNET_MMC_MMCRIMR_RFAEM          (0x1U<<6)
#define ETHERNET_MMC_MMCRIMR_RFCEM          (0x1U<<5)

// MMCTIMR Configuration

#define ETHERNET_MMC_MMCTIMR_TGFM           (0x1U<<21)
#define ETHERNET_MMC_MMCTIMR_TGFMSCM        (0x1U<<15)
#define ETHERNET_MMC_MMCTIMR_TGFSCM         (0x1U<<14)

// MMCTGFSCCR Configuration

#define ETHERNET_MMC_MMCTGFSCCR_TGFSCC      (0xFFFFFFFFU<<0)
#define ETHERNET_MMC_MMCTGFSCCR_TGFSCC_0    (0x1U<<0)

// MMCTGFMSCCR Configuration

#define ETHERNET_MMC_MMCTGFMSCCR_TGFMSCC    (0xFFFFFFFFU<<0)
#define ETHERNET_MMC_MMCTGFMSCCR_TGFMSCC_0  (0x1U<<0)

// MMCTGFCR Configuration

#define ETHERNET_MMC_MMCTGFCR_TGFC          (0xFFFFFFFFU<<0)
#define ETHERNET_MMC_MMCTGFCR_TGFC_0        (0x1U<<0)

// MMCRFCECR Configuration

#define ETHERNET_MMC_MMCRFCECR_RFCFC        (0xFFFFFFFFU<<0)
#define ETHERNET_MMC_MMCRFCECR_RFCFC_0      (0x1U<<0)

// MMCRFAECR Configuration

#define ETHERNET_MMC_MMCRFAECR_RFAEC        (0xFFFFFFFFU<<0)
#define ETHERNET_MMC_MMCRFAECR_RFAEC_0      (0x1U<<0)

// MMCRGUFCR Configuration

#define ETHERNET_MMC_MMCRGUFCR_RGUFC        (0xFFFFFFFFU<<0)
#define ETHERNET_MMC_MMCRGUFCR_RGUFC_0      (0x1U<<0)
