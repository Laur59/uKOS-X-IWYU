/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_i2c equates.
 */

#pragma once

#include    <stdint.h>

// I2C address definitions
// -----------------------

typedef struct {
    volatile    uint16_t    CTL0;
    volatile    uint16_t    RESERVED0;
    volatile    uint16_t    CTL1;
    volatile    uint16_t    RESERVED1;
    volatile    uint16_t    SADDR0;
    volatile    uint16_t    RESERVED2;
    volatile    uint16_t    SADDR1;
    volatile    uint16_t    RESERVED3;
    volatile    uint16_t    DATA;
    volatile    uint16_t    RESERVED4;
    volatile    uint16_t    STAT0;
    volatile    uint16_t    RESERVED5;
    volatile    uint16_t    STAT1;
    volatile    uint16_t    RESERVED6;
    volatile    uint16_t    CKCFG;
    volatile    uint16_t    RESERVED7;
    volatile    uint16_t    RT;
} I2C_TypeDef;

#ifdef __cplusplus
#define I2C0    reinterpret_cast<I2C_TypeDef *>(0x40005400U)
#define I2C1    reinterpret_cast<I2C_TypeDef *>(0x40005800U)

#else
#define I2C0    ((I2C_TypeDef *)0x40005400U)
#define I2C1    ((I2C_TypeDef *)0x40005800U)
#endif

// CTL0 Configuration

#define I2C_CTL0_I2CEN          (0x1U<<0U)
#define I2C_CTL0_SMBEN          (0x1U<<1U)
#define I2C_CTL0_SMBSEL         (0x1U<<3U)
#define I2C_CTL0_ARPEN          (0x1U<<4U)
#define I2C_CTL0_PECEN          (0x1U<<5U)
#define I2C_CTL0_GCEN           (0x1U<<6U)
#define I2C_CTL0_SS             (0x1U<<7U)
#define I2C_CTL0_START          (0x1U<<8U)
#define I2C_CTL0_STOP           (0x1U<<9U)
#define I2C_CTL0_ACKEN          (0x1U<<10U)
#define I2C_CTL0_POAP           (0x1U<<11U)
#define I2C_CTL0_PECTRANS       (0x1U<<12U)
#define I2C_CTL0_SALT           (0x1U<<13U)
#define I2C_CTL0_SRESET         (0x1U<<15U)

// CTL1 Configuration

#define I2C_CTL1_I2CCLK         (0x3FU<<0U)
#define I2C_CTL1_I2CCLK_0       (0x1U<<0U)
#define I2C_CTL1_ERRIE          (0x1U<<8U)
#define I2C_CTL1_EVIE           (0x1U<<9U)
#define I2C_CTL1_BUFIE          (0x1U<<10U)
#define I2C_CTL1_DMAON          (0x1U<<11U)
#define I2C_CTL1_DMALST         (0x1U<<12U)

// SADDR0 Configuration

#define I2C_SADDR0_ADDRESS0     (0x1U<<0U)
#define I2C_SADDR0_ADDRESS7_1   (0x7FU<<1U)
#define I2C_SADDR0_ADDRESS7_1_0 (0x1U<<1U)
#define I2C_SADDR0_ADDRESS9_8   (0x3U<<8U)
#define I2C_SADDR0_ADDRESS9_8_0 (0x1U<<8U)
#define I2C_SADDR0_ADDFORMAT    (0x1U<<15U)

// SADDR1 Configuration

#define I2C_SADDR1_DUADEN       (0x1U<<0U)
#define I2C_SADDR1_ADDRESS2     (0x7FU<<1U)
#define I2C_SADDR1_ADDRESS2_0   (0x1U<<1U)

// DATA Configuration

#define I2C_DATA_TRB            (0xFFU<<0U)
#define I2C_DATA_TRB_0          (0x1U<<0U)

// STAT0 Configuration

#define I2C_STAT0_SBSEND        (0x1U<<0U)
#define I2C_STAT0_ADDSEND       (0x1U<<1U)
#define I2C_STAT0_BTC           (0x1U<<2U)
#define I2C_STAT0_ADD10SEND     (0x1U<<3U)
#define I2C_STAT0_STPDET        (0x1U<<4U)
#define I2C_STAT0_RBNE          (0x1U<<6U)
#define I2C_STAT0_TBE           (0x1U<<7U)
#define I2C_STAT0_BERR          (0x1U<<8U)
#define I2C_STAT0_LOSTARB       (0x1U<<9U)
#define I2C_STAT0_AERR          (0x1U<<10U)
#define I2C_STAT0_OUERR         (0x1U<<11U)
#define I2C_STAT0_PECERR        (0x1U<<12U)
#define I2C_STAT0_SMBTO         (0x1U<<14U)
#define I2C_STAT0_SMBALT        (0x1U<<15U)

// STAT1 Configuration

#define I2C_STAT1_MASTER        (0x1U<<0U)
#define I2C_STAT1_I2CBSY        (0x1U<<1U)
#define I2C_STAT1_TR            (0x1U<<2U)
#define I2C_STAT1_RXGC          (0x1U<<4U)
#define I2C_STAT1_DEFSMB        (0x1U<<5U)
#define I2C_STAT1_HSTSMB        (0x1U<<6U)
#define I2C_STAT1_DUMODF        (0x1U<<7U)
#define I2C_STAT1_PECV          (0xFFU<<8U)
#define I2C_STAT1_PECV_0        (0x1U<<8U)

// CKCFG Configuration

#define I2C_CKCFG_CLKC          (0xFFFU<<0U)
#define I2C_CKCFG_CLKC_0        (0x1U<<0U)
#define I2C_CKCFG_DTCY          (0x1U<<14U)
#define I2C_CKCFG_FAST          (0x1U<<15U)

// RT Configuration

#define I2C_RT_RISETIME         (0x3FU<<0U)
#define I2C_RT_RISETIME_0       (0x1U<<0U)
