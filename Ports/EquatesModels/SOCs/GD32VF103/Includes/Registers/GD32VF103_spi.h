/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_spi equates.
 */

#pragma once

#include    <stdint.h>

// SPI address definitions
// -----------------------

typedef struct {
    volatile    uint16_t    CTL0;
    volatile    uint16_t    RESERVED0;
    volatile    uint16_t    CTL1;
    volatile    uint16_t    RESERVED1;
    volatile    uint16_t    STAT;
    volatile    uint16_t    RESERVED2;
    volatile    uint16_t    DATA;
    volatile    uint16_t    RESERVED3;
    volatile    uint16_t    CRCPOLY;
    volatile    uint16_t    RESERVED4;
    volatile    uint16_t    RCRC;
    volatile    uint16_t    RESERVED5;
    volatile    uint16_t    TCRC;
    volatile    uint16_t    RESERVED6;
    volatile    uint16_t    I2SCTL;
    volatile    uint16_t    RESERVED7;
    volatile    uint16_t    I2SPSC;
} SPI_TypeDef;

#ifdef __cplusplus
#define SPI0    reinterpret_cast<SPI_TypeDef *>(0x40013000U)
#define SPI1    reinterpret_cast<SPI_TypeDef *>(0x40003800U)
#define SPI2    reinterpret_cast<SPI_TypeDef *>(0x40003C00U)

#else
#define SPI0    ((SPI_TypeDef *)0x40013000U)
#define SPI1    ((SPI_TypeDef *)0x40003800U)
#define SPI2    ((SPI_TypeDef *)0x40003C00U)
#endif

// CTL0 Configuration

#define SPI_CTL0_CKPH           (0x1U<<0)
#define SPI_CTL0_CKPL           (0x1U<<1)
#define SPI_CTL0_MSTMOD         (0x1U<<2)
#define SPI_CTL0_PSC            (0x7U<<3)
#define SPI_CTL0_PSC_0          (0x1U<<3)
#define SPI_CTL0_SPIEN          (0x1U<<6)
#define SPI_CTL0_LF             (0x1U<<7)
#define SPI_CTL0_SWNSS          (0x1U<<8)
#define SPI_CTL0_SWNSSEN        (0x1U<<9)
#define SPI_CTL0_RO             (0x1U<<10)
#define SPI_CTL0_FF16           (0x1U<<11)
#define SPI_CTL0_CRCNT          (0x1U<<12)
#define SPI_CTL0_CRCEN          (0x1U<<13)
#define SPI_CTL0_BDOEN          (0x1U<<14)
#define SPI_CTL0_BDEN           (0x1U<<15)

// CTL1 Configuration

#define SPI_CTL1_DMAREN         (0x1U<<0)
#define SPI_CTL1_DMATEN         (0x1U<<1)
#define SPI_CTL1_NSSDRV         (0x1U<<2)
#define SPI_CTL1_NSSP           (0x1U<<3)
#define SPI_CTL1_TMOD           (0x1U<<4)
#define SPI_CTL1_ERRIE          (0x1U<<5)
#define SPI_CTL1_RBNEIE         (0x1U<<6)
#define SPI_CTL1_TBEIE          (0x1U<<7)

// STAT Configuration

#define SPI_STAT_RBNE           (0x1U<<0)
#define SPI_STAT_TBE            (0x1U<<1)
#define SPI_STAT_I2SCH          (0x1U<<2)
#define SPI_STAT_TXURERR        (0x1U<<3)
#define SPI_STAT_CRCERR         (0x1U<<4)
#define SPI_STAT_CONFERR        (0x1U<<5)
#define SPI_STAT_RXORERR        (0x1U<<6)
#define SPI_STAT_TRANS          (0x1U<<7)
#define SPI_STAT_FERR           (0x1U<<8)

// DATA Configuration

#define SPI_DATA_SPI_DATA       (0xFFFFU<<0)
#define SPI_DATA_SPI_DATA_0     (0x1U<<0)

// CRCPOLY Configuration

#define SPI_CRCPOLY_CRCPOLY     (0xFFFFU<<0)
#define SPI_CRCPOLY_CRCPOLY_0   (0x1U<<0)

// RCRC Configuration

#define SPI_RCRC_RCRC           (0xFFFFU<<0)
#define SPI_RCRC_RCRC_0         (0x1U<<0)

// TCRC Configuration

#define SPI_TCRC_TCRC           (0xFFFFU<<0)
#define SPI_TCRC_TCRC_0         (0x1U<<0)

// I2SCTL Configuration

#define SPI_I2SCTL_CHLEN        (0x1U<<0)
#define SPI_I2SCTL_DTLEN        (0x3U<<1)
#define SPI_I2SCTL_DTLEN_0      (0x1U<<1)
#define SPI_I2SCTL_CKPL         (0x1U<<3)
#define SPI_I2SCTL_I2SSTD       (0x3U<<4)
#define SPI_I2SCTL_I2SSTD_0     (0x1U<<4)
#define SPI_I2SCTL_PCMSMOD      (0x1U<<7)
#define SPI_I2SCTL_I2SOPMOD     (0x3U<<8)
#define SPI_I2SCTL_I2SOPMOD_0   (0x1U<<8)
#define SPI_I2SCTL_I2SEN        (0x1U<<10)
#define SPI_I2SCTL_I2SSEL       (0x1U<<11)

// I2SPSC Configuration

#define SPI_I2SPSC_DIV          (0xFFU<<0)
#define SPI_I2SPSC_DIV_0        (0x1U<<0)
#define SPI_I2SPSC_OF           (0x1U<<8)
#define SPI_I2SPSC_MCKOEN       (0x1U<<9)
