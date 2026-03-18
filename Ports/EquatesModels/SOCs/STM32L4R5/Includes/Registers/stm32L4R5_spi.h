/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_spi equates.
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
} SPI_TypeDef;

#ifdef __cplusplus
#define SPI1    reinterpret_cast<SPI_TypeDef *>(0x40013000U)
#define SPI2    reinterpret_cast<SPI_TypeDef *>(0x40003800U)
#define SPI3    reinterpret_cast<SPI_TypeDef *>(0x40003C00U)

#else
#define SPI1    ((SPI_TypeDef *)0x40013000U)
#define SPI2    ((SPI_TypeDef *)0x40003800U)
#define SPI3    ((SPI_TypeDef *)0x40003C00U)
#endif

// CR1 Configuration

#define SPI_CR1_CPHA        (0x1U<<0)
#define SPI_CR1_CPOL        (0x1U<<1)
#define SPI_CR1_MSTR        (0x1U<<2)
#define SPI_CR1_BR          (0x7U<<3)
#define SPI_CR1_BR_0        (0x1U<<3)
#define SPI_CR1_SPE         (0x1U<<6)
#define SPI_CR1_LSBFIRST    (0x1U<<7)
#define SPI_CR1_SSI         (0x1U<<8)
#define SPI_CR1_SSM         (0x1U<<9)
#define SPI_CR1_RXONLY      (0x1U<<10)
#define SPI_CR1_DFF         (0x1U<<11)
#define SPI_CR1_CRCNEXT     (0x1U<<12)
#define SPI_CR1_CRCEN       (0x1U<<13)
#define SPI_CR1_BIDIOE      (0x1U<<14)
#define SPI_CR1_BIDIMODE    (0x1U<<15)

// CR2 Configuration

#define SPI_CR2_LDMA_TX     (0x1U<<14)
#define SPI_CR2_LDMA_RX     (0x1U<<13)
#define SPI_CR2_FRXTH       (0x1U<<12)
#define SPI_CR2_DS          (0xFU<<8)
#define SPI_CR2_DS_0        (0x1U<<8)
#define SPI_CR2_TXEIE       (0x1U<<7)
#define SPI_CR2_RXNEIE      (0x1U<<6)
#define SPI_CR2_ERRIE       (0x1U<<5)
#define SPI_CR2_FRF         (0x1U<<4)
#define SPI_CR2_NSSP        (0x1U<<3)
#define SPI_CR2_SSOE        (0x1U<<2)
#define SPI_CR2_TXDMAEN     (0x1U<<1)
#define SPI_CR2_RXDMAEN     (0x1U<<0)

// SR Configuration

#define SPI_SR_FTLVL        (0x3U<<11)
#define SPI_SR_FTLVL_0      (0x1U<<11)
#define SPI_SR_FRLVL        (0x3U<<9)
#define SPI_SR_FRLVL_0      (0x1U<<9)
#define SPI_SR_TIFRFE       (0x1U<<8)
#define SPI_SR_BSY          (0x1U<<7)
#define SPI_SR_OVR          (0x1U<<6)
#define SPI_SR_MODF         (0x1U<<5)
#define SPI_SR_CRCERR       (0x1U<<4)
#define SPI_SR_TXE          (0x1U<<1)
#define SPI_SR_RXNE         (0x1U<<0)

// DR Configuration

#define SPI_DR_DR           (0xFFFFU<<0)
#define SPI_DR_DR_0         (0x1U<<0)

// CRCPR Configuration

#define SPI_CRCPR_CRCPOLY   (0xFFFFU<<0)
#define SPI_CRCPR_CRCPOLY_0 (0x1U<<0)

// RXCRCR Configuration

#define SPI_RXCRCR_RXCRC    (0xFFFFU<<0)
#define SPI_RXCRCR_RXCRC_0  (0x1U<<0)

// TXCRCR Configuration

#define SPI_TXCRCR_TXCRC    (0xFFFFU<<0)
#define SPI_TXCRCR_TXCRC_0  (0x1U<<0)
