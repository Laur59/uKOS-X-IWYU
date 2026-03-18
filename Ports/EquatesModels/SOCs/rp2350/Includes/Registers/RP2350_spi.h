/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_spi equates.
 */

#pragma once

#include    <stdint.h>

// SPI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    SSPCR0;
    volatile    uint32_t    SSPCR1;
    volatile    uint32_t    SSPDR;
    volatile    uint32_t    SSPSR;
    volatile    uint32_t    SSPCPSR;
    volatile    uint32_t    SSPIMSC;
    volatile    uint32_t    SSPRIS;
    volatile    uint32_t    SSPMIS;
    volatile    uint32_t    SSPICR;
    volatile    uint32_t    SSPDMACR;
    volatile    uint32_t    RESERVED0[1006];
    volatile    uint32_t    SSPPERIPHID0;
    volatile    uint32_t    SSPPERIPHID1;
    volatile    uint32_t    SSPPERIPHID2;
    volatile    uint32_t    SSPPERIPHID3;
    volatile    uint32_t    SSPPCELLID0;
    volatile    uint32_t    SSPPCELLID1;
    volatile    uint32_t    SSPPCELLID2;
    volatile    uint32_t    SSPPCELLID3;
} SPI_TypeDef;

#ifdef __cplusplus
#define SPI0_NS reinterpret_cast<SPI_TypeDef *>(0x40080000U)
#define SPI0_S  reinterpret_cast<SPI_TypeDef *>(0x40080000U)
#define SPI1_NS reinterpret_cast<SPI_TypeDef *>(0x40088000U)
#define SPI1_S  reinterpret_cast<SPI_TypeDef *>(0x40088000U)
#else
#define SPI0_NS ((SPI_TypeDef *)0x40080000U)
#define SPI0_S  ((SPI_TypeDef *)0x40080000U)
#define SPI1_NS ((SPI_TypeDef *)0x40088000U)
#define SPI1_S  ((SPI_TypeDef *)0x40088000U)
#endif

// SSPCR0 Configuration

#define SPI_SSPCR0_DSS                      (0xFU<<0)
#define SPI_SSPCR0_DSS_0                    (0x1U<<0)
#define SPI_SSPCR0_FRF                      (0x3U<<4)
#define SPI_SSPCR0_FRF_0                    (0x1U<<4)
#define SPI_SSPCR0_SPO                      (0x1U<<6)
#define SPI_SSPCR0_SPH                      (0x1U<<7)
#define SPI_SSPCR0_SCR                      (0xFFU<<8)
#define SPI_SSPCR0_SCR_0                    (0x1U<<8)

// SSPCR1 Configuration

#define SPI_SSPCR1_LBM                      (0x1U<<0)
#define SPI_SSPCR1_SSE                      (0x1U<<1)
#define SPI_SSPCR1_MS                       (0x1U<<2)
#define SPI_SSPCR1_SOD                      (0x1U<<3)

// SSPDR Configuration

#define SPI_SSPDR_DATA                      (0xFFFFU<<0)
#define SPI_SSPDR_DATA_0                    (0x1U<<0)

// SSPSR Configuration

#define SPI_SSPSR_TFE                       (0x1U<<0)
#define SPI_SSPSR_TNF                       (0x1U<<1)
#define SPI_SSPSR_RNE                       (0x1U<<2)
#define SPI_SSPSR_RFF                       (0x1U<<3)
#define SPI_SSPSR_BSY                       (0x1U<<4)

// SSPCPSR Configuration

#define SPI_SSPCPSR_CPSDVSR                 (0xFFU<<0)
#define SPI_SSPCPSR_CPSDVSR_0               (0x1U<<0)

// SSPIMSC Configuration

#define SPI_SSPIMSC_RORIM                   (0x1U<<0)
#define SPI_SSPIMSC_RTIM                    (0x1U<<1)
#define SPI_SSPIMSC_RXIM                    (0x1U<<2)
#define SPI_SSPIMSC_TXIM                    (0x1U<<3)

// SSPRIS Configuration

#define SPI_SSPRIS_RORRIS                   (0x1U<<0)
#define SPI_SSPRIS_RTRIS                    (0x1U<<1)
#define SPI_SSPRIS_RXRIS                    (0x1U<<2)
#define SPI_SSPRIS_TXRIS                    (0x1U<<3)

// SSPMIS Configuration

#define SPI_SSPMIS_RORMIS                   (0x1U<<0)
#define SPI_SSPMIS_RTMIS                    (0x1U<<1)
#define SPI_SSPMIS_RXMIS                    (0x1U<<2)
#define SPI_SSPMIS_TXMIS                    (0x1U<<3)

// SSPICR Configuration

#define SPI_SSPICR_RORIC                    (0x1U<<0)
#define SPI_SSPICR_RTIC                     (0x1U<<1)

// SSPDMACR Configuration

#define SPI_SSPDMACR_RXDMAE                 (0x1U<<0)
#define SPI_SSPDMACR_TXDMAE                 (0x1U<<1)

// SSPPERIPHID0 Configuration

#define SPI_SSPPERIPHID0_PARTNUMBER0        (0xFFU<<0)
#define SPI_SSPPERIPHID0_PARTNUMBER0_0      (0x1U<<0)

// SSPPERIPHID1 Configuration

#define SPI_SSPPERIPHID1_PARTNUMBER1        (0xFU<<0)
#define SPI_SSPPERIPHID1_PARTNUMBER1_0      (0x1U<<0)
#define SPI_SSPPERIPHID1_DESIGNER0          (0xFU<<4)
#define SPI_SSPPERIPHID1_DESIGNER0_0        (0x1U<<4)

// SSPPERIPHID2 Configuration

#define SPI_SSPPERIPHID2_DESIGNER1          (0xFU<<0)
#define SPI_SSPPERIPHID2_DESIGNER1_0        (0x1U<<0)
#define SPI_SSPPERIPHID2_REVISION           (0xFU<<4)
#define SPI_SSPPERIPHID2_REVISION_0         (0x1U<<4)

// SSPPERIPHID3 Configuration

#define SPI_SSPPERIPHID3_CONFIGURATION      (0xFFU<<0)
#define SPI_SSPPERIPHID3_CONFIGURATION_0    (0x1U<<0)

// SSPPCELLID0 Configuration

#define SPI_SSPPCELLID0_SSPPCELLID0         (0xFFU<<0)
#define SPI_SSPPCELLID0_SSPPCELLID0_0       (0x1U<<0)

// SSPPCELLID1 Configuration

#define SPI_SSPPCELLID1_SSPPCELLID1         (0xFFU<<0)
#define SPI_SSPPCELLID1_SSPPCELLID1_0       (0x1U<<0)

// SSPPCELLID2 Configuration

#define SPI_SSPPCELLID2_SSPPCELLID2         (0xFFU<<0)
#define SPI_SSPPCELLID2_SSPPCELLID2_0       (0x1U<<0)

// SSPPCELLID3 Configuration

#define SPI_SSPPCELLID3_SSPPCELLID3         (0xFFU<<0)
#define SPI_SSPPCELLID3_SSPPCELLID3_0       (0x1U<<0)
