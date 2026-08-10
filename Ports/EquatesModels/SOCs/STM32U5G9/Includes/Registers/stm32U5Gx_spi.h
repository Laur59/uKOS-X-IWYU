/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_spi equates.
 */

#pragma once

#include    <stdint.h>

// SPI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CFG1;
    volatile    uint32_t    CFG2;
    volatile    uint32_t    IER;
    volatile    uint32_t    SR;
    volatile    uint32_t    IFCR;
    volatile    uint32_t    AUTOCR;
    volatile    uint32_t    TXDR;
    volatile    uint32_t    RESERVED0[3];
    volatile    uint32_t    RXDR;
    volatile    uint32_t    RESERVED1[3];
    volatile    uint32_t    CRCPOLY;
    volatile    uint32_t    TXCRC;
    volatile    uint32_t    RXCRC;
    volatile    uint32_t    UDRDR;
} SPI_TypeDef;

#ifdef __cplusplus
#define SPI1_NS reinterpret_cast<SPI_TypeDef *>(0x40013000U)
#define SPI1_S  reinterpret_cast<SPI_TypeDef *>(0x50013000U)
#define SPI2_NS reinterpret_cast<SPI_TypeDef *>(0x40003800U)
#define SPI2_S  reinterpret_cast<SPI_TypeDef *>(0x50003800U)
#define SPI3_NS reinterpret_cast<SPI_TypeDef *>(0x46002000U)
#define SPI3_S  reinterpret_cast<SPI_TypeDef *>(0x56002000U)

#else
#define SPI1_NS ((SPI_TypeDef *)0x40013000U)
#define SPI1_S  ((SPI_TypeDef *)0x50013000U)
#define SPI2_NS ((SPI_TypeDef *)0x40003800U)
#define SPI2_S  ((SPI_TypeDef *)0x50003800U)
#define SPI3_NS ((SPI_TypeDef *)0x46002000U)
#define SPI3_S  ((SPI_TypeDef *)0x56002000U)
#endif

// CR1 Configuration

#define SPI_CR1_SPE             (0x1U<<0U)
#define SPI_CR1_MASRX           (0x1U<<8U)
#define SPI_CR1_CSTART          (0x1U<<9U)
#define SPI_CR1_CSUSP           (0x1U<<10U)
#define SPI_CR1_HDDIR           (0x1U<<11U)
#define SPI_CR1_SSI             (0x1U<<12U)
#define SPI_CR1_CRC33_17        (0x1U<<13U)
#define SPI_CR1_RCRCINI         (0x1U<<14U)
#define SPI_CR1_TCRCINI         (0x1U<<15U)
#define SPI_CR1_IOLOCK          (0x1U<<16U)

// CR2 Configuration

#define SPI_CR2_TSIZE           (0xFFFFU<<0U)
#define SPI_CR2_TSIZE_0         (0x1U<<0U)

// CFG1 Configuration

#define SPI_CFG1_DSIZE          (0x1FU<<0U)
#define SPI_CFG1_DSIZE_0        (0x1U<<0U)
#define SPI_CFG1_FTHVL          (0xFU<<5U)
#define SPI_CFG1_FTHVL_0        (0x1U<<5U)
#define SPI_CFG1_UDRCFG         (0x1U<<9U)
#define SPI_CFG1_RXDMAEN        (0x1U<<14U)
#define SPI_CFG1_TXDMAEN        (0x1U<<15U)
#define SPI_CFG1_CRCSIZE        (0x1FU<<16U)
#define SPI_CFG1_CRCSIZE_0      (0x1U<<16U)
#define SPI_CFG1_CRCEN          (0x1U<<22U)
#define SPI_CFG1_MBR            (0x7U<<28U)
#define SPI_CFG1_MBR_0          (0x1U<<28U)
#define SPI_CFG1_BPASS          (0x1U<<31U)

// CFG2 Configuration

#define SPI_CFG2_MSSI           (0xFU<<0U)
#define SPI_CFG2_MSSI_0         (0x1U<<0U)
#define SPI_CFG2_MIDI           (0xFU<<4U)
#define SPI_CFG2_MIDI_0         (0x1U<<4U)
#define SPI_CFG2_RDIMM          (0x1U<<13U)
#define SPI_CFG2_RDIOP          (0x1U<<14U)
#define SPI_CFG2_IOSWP          (0x1U<<15U)
#define SPI_CFG2_COMM           (0x3U<<17U)
#define SPI_CFG2_COMM_0         (0x1U<<17U)
#define SPI_CFG2_SP             (0x7U<<19U)
#define SPI_CFG2_SP_0           (0x1U<<19U)
#define SPI_CFG2_MASTER         (0x1U<<22U)
#define SPI_CFG2_LSBFRST        (0x1U<<23U)
#define SPI_CFG2_CPHA           (0x1U<<24U)
#define SPI_CFG2_CPOL           (0x1U<<25U)
#define SPI_CFG2_SSM            (0x1U<<26U)
#define SPI_CFG2_SSIOP          (0x1U<<28U)
#define SPI_CFG2_SSOE           (0x1U<<29U)
#define SPI_CFG2_SSOM           (0x1U<<30U)
#define SPI_CFG2_AFCNTR         (0x1U<<31U)

// IER Configuration

#define SPI_IER_RXPIE           (0x1U<<0U)
#define SPI_IER_TXPIE           (0x1U<<1U)
#define SPI_IER_DPXPIE          (0x1U<<2U)
#define SPI_IER_EOTIE           (0x1U<<3U)
#define SPI_IER_TXTFIE          (0x1U<<4U)
#define SPI_IER_UDRIE           (0x1U<<5U)
#define SPI_IER_OVRIE           (0x1U<<6U)
#define SPI_IER_CRCEIE          (0x1U<<7U)
#define SPI_IER_TIFREIE         (0x1U<<8U)
#define SPI_IER_MODFIE          (0x1U<<9U)

// SR Configuration

#define SPI_SR_RXP              (0x1U<<0U)
#define SPI_SR_TXP              (0x1U<<1U)
#define SPI_SR_DXP              (0x1U<<2U)
#define SPI_SR_EOT              (0x1U<<3U)
#define SPI_SR_TXTF             (0x1U<<4U)
#define SPI_SR_UDR              (0x1U<<5U)
#define SPI_SR_OVR              (0x1U<<6U)
#define SPI_SR_CRCE             (0x1U<<7U)
#define SPI_SR_TIFRE            (0x1U<<8U)
#define SPI_SR_MODF             (0x1U<<9U)
#define SPI_SR_SUSP             (0x1U<<11U)
#define SPI_SR_TXC              (0x1U<<12U)
#define SPI_SR_RXPLVL           (0x3U<<13U)
#define SPI_SR_RXPLVL_0         (0x1U<<13U)
#define SPI_SR_RXWNE            (0x1U<<15U)
#define SPI_SR_CTSIZE           (0xFFFFU<<16U)
#define SPI_SR_CTSIZE_0         (0x1U<<16U)

// IFCR Configuration

#define SPI_IFCR_EOTC           (0x1U<<3U)
#define SPI_IFCR_TXTFC          (0x1U<<4U)
#define SPI_IFCR_UDRC           (0x1U<<5U)
#define SPI_IFCR_OVRC           (0x1U<<6U)
#define SPI_IFCR_CRCEC          (0x1U<<7U)
#define SPI_IFCR_TIFREC         (0x1U<<8U)
#define SPI_IFCR_MODFC          (0x1U<<9U)
#define SPI_IFCR_SUSPC          (0x1U<<11U)

// AUTOCR Configuration

#define SPI_AUTOCR_TRIGSEL      (0xFU<<16U)
#define SPI_AUTOCR_TRIGSEL_0    (0x1U<<16U)
#define SPI_AUTOCR_TRIGPOL      (0x1U<<20U)
#define SPI_AUTOCR_TRIGEN       (0x1U<<21U)

// TXDR Configuration

#define SPI_TXDR_TXDR           (0xFFFFFFFFU<<0U)
#define SPI_TXDR_TXDR_0         (0x1U<<0U)

// RXDR Configuration

#define SPI_RXDR_RXDR           (0xFFFFFFFFU<<0U)
#define SPI_RXDR_RXDR_0         (0x1U<<0U)

// CRCPOLY Configuration

#define SPI_CRCPOLY_CRCPOLY     (0xFFFFFFFFU<<0U)
#define SPI_CRCPOLY_CRCPOLY_0   (0x1U<<0U)

// TXCRC Configuration

#define SPI_TXCRC_TXCRC         (0xFFFFFFFFU<<0U)
#define SPI_TXCRC_TXCRC_0       (0x1U<<0U)

// RXCRC Configuration

#define SPI_RXCRC_RXCRC         (0xFFFFFFFFU<<0U)
#define SPI_RXCRC_RXCRC_0       (0x1U<<0U)

// UDRDR Configuration

#define SPI_UDRDR_UDRDR         (0xFFFFFFFFU<<0U)
#define SPI_UDRDR_UDRDR_0       (0x1U<<0U)
