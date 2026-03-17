/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32F217_spi.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32F217_spi equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// SPI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    SR;
    volatile    uint32_t    DR;
    volatile    uint32_t    CRCPR;
    volatile    uint32_t    RXCRCR;
    volatile    uint32_t    TXCRCR;
    volatile    uint32_t    I2SCFGR;
    volatile    uint32_t    I2SPR;
} SPI_TypeDef;

#ifdef __cplusplus
#define SPI1    reinterpret_cast<SPI_TypeDef *>(0x40013000U)
#define SPI3    reinterpret_cast<SPI_TypeDef *>(0x40003C00U)
#define SPI2    reinterpret_cast<SPI_TypeDef *>(0x40003800U)

#else
#define SPI1    ((SPI_TypeDef *)0x40013000U)
#define SPI3    ((SPI_TypeDef *)0x40003C00U)
#define SPI2    ((SPI_TypeDef *)0x40003800U)
#endif

// CR1 Configuration

#define SPI_CR1_CPHA            (0x1U<<0)
#define SPI_CR1_CPOL            (0x1U<<1)
#define SPI_CR1_MSTR            (0x1U<<2)
#define SPI_CR1_BR              (0x7U<<3)
#define SPI_CR1_BR_0            (0x1U<<3)
#define SPI_CR1_SPE             (0x1U<<6)
#define SPI_CR1_LSBFIRST        (0x1U<<7)
#define SPI_CR1_SSI             (0x1U<<8)
#define SPI_CR1_SSM             (0x1U<<9)
#define SPI_CR1_RXONLY          (0x1U<<10)
#define SPI_CR1_DFF             (0x1U<<11)
#define SPI_CR1_CRCNEXT         (0x1U<<12)
#define SPI_CR1_CRCEN           (0x1U<<13)
#define SPI_CR1_BIDIOE          (0x1U<<14)
#define SPI_CR1_BIDIMODE        (0x1U<<15)

// CR2 Configuration

#define SPI_CR2_RXDMAEN         (0x1U<<0)
#define SPI_CR2_TXDMAEN         (0x1U<<1)
#define SPI_CR2_SSOE            (0x1U<<2)
#define SPI_CR2_FRF             (0x1U<<4)
#define SPI_CR2_ERRIE           (0x1U<<5)
#define SPI_CR2_RXNEIE          (0x1U<<6)
#define SPI_CR2_TXEIE           (0x1U<<7)

// SR Configuration

#define SPI_SR_RXNE             (0x1U<<0)
#define SPI_SR_TXE              (0x1U<<1)
#define SPI_SR_CHSIDE           (0x1U<<2)
#define SPI_SR_UDR              (0x1U<<3)
#define SPI_SR_CRCERR           (0x1U<<4)
#define SPI_SR_MODF             (0x1U<<5)
#define SPI_SR_OVR              (0x1U<<6)
#define SPI_SR_BSY              (0x1U<<7)
#define SPI_SR_TIFRFE           (0x1U<<8)

// DR Configuration

#define SPI_DR_DR               (0xFFFFU<<0)
#define SPI_DR_DR_0             (0x1U<<0)

// CRCPR Configuration

#define SPI_CRCPR_CRCPOLY       (0xFFFFU<<0)
#define SPI_CRCPR_CRCPOLY_0     (0x1U<<0)

// RXCRCR Configuration

#define SPI_RXCRCR_RXCRC        (0xFFFFU<<0)
#define SPI_RXCRCR_RXCRC_0      (0x1U<<0)

// TXCRCR Configuration

#define SPI_TXCRCR_TXCRC        (0xFFFFU<<0)
#define SPI_TXCRCR_TXCRC_0      (0x1U<<0)

// I2SCFGR Configuration

#define SPI_I2SCFGR_CHLEN       (0x1U<<0)
#define SPI_I2SCFGR_DATLEN      (0x3U<<1)
#define SPI_I2SCFGR_DATLEN_0    (0x1U<<1)
#define SPI_I2SCFGR_CKPOL       (0x1U<<3)
#define SPI_I2SCFGR_I2SSTD      (0x3U<<4)
#define SPI_I2SCFGR_I2SSTD_0    (0x1U<<4)
#define SPI_I2SCFGR_PCMSYNC     (0x1U<<7)
#define SPI_I2SCFGR_I2SCFG      (0x3U<<8)
#define SPI_I2SCFGR_I2SCFG_0    (0x1U<<8)
#define SPI_I2SCFGR_I2SE        (0x1U<<10)
#define SPI_I2SCFGR_I2SMOD      (0x1U<<11)

// I2SPR Configuration

#define SPI_I2SPR_I2SDIV        (0xFFU<<0)
#define SPI_I2SPR_I2SDIV_0      (0x1U<<0)
#define SPI_I2SPR_ODD           (0x1U<<8)
#define SPI_I2SPR_MCKOE         (0x1U<<9)
