/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_i2c equates.
 */

#pragma once

#include    <stdint.h>

// I2C address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    OAR1;
    volatile    uint32_t    OAR2;
    volatile    uint32_t    DR;
    volatile    uint32_t    SR1;
    volatile    uint32_t    SR2;
    volatile    uint32_t    CCR;
    volatile    uint32_t    TRISE;
} I2C_TypeDef;

#ifdef __cplusplus
#define I2C3    reinterpret_cast<I2C_TypeDef *>(0x40005C00U)
#define I2C2    reinterpret_cast<I2C_TypeDef *>(0x40005800U)
#define I2C1    reinterpret_cast<I2C_TypeDef *>(0x40005400U)

#else
#define I2C3    ((I2C_TypeDef *)0x40005C00U)
#define I2C2    ((I2C_TypeDef *)0x40005800U)
#define I2C1    ((I2C_TypeDef *)0x40005400U)
#endif

// CR1 Configuration

#define I2C_CR1_PE          (0x1U<<0U)
#define I2C_CR1_SMBUS       (0x1U<<1U)
#define I2C_CR1_SMBTYPE     (0x1U<<3U)
#define I2C_CR1_ENARP       (0x1U<<4U)
#define I2C_CR1_ENPEC       (0x1U<<5U)
#define I2C_CR1_ENGC        (0x1U<<6U)
#define I2C_CR1_NOSTRETCH   (0x1U<<7U)
#define I2C_CR1_START       (0x1U<<8U)
#define I2C_CR1_STOP        (0x1U<<9U)
#define I2C_CR1_ACK         (0x1U<<10U)
#define I2C_CR1_POS         (0x1U<<11U)
#define I2C_CR1_PEC         (0x1U<<12U)
#define I2C_CR1_ALERT       (0x1U<<13U)
#define I2C_CR1_SWRST       (0x1U<<15U)

// CR2 Configuration

#define I2C_CR2_FREQ        (0x3FU<<0U)
#define I2C_CR2_FREQ_0      (0x1U<<0U)
#define I2C_CR2_ITERREN     (0x1U<<8U)
#define I2C_CR2_ITEVTEN     (0x1U<<9U)
#define I2C_CR2_ITBUFEN     (0x1U<<10U)
#define I2C_CR2_DMAEN       (0x1U<<11U)
#define I2C_CR2_LAST        (0x1U<<12U)

// OAR1 Configuration

#define I2C_OAR1_ADD0       (0x1U<<0U)
#define I2C_OAR1_ADD7       (0x7FU<<1U)
#define I2C_OAR1_ADD7_0     (0x1U<<1U)
#define I2C_OAR1_ADD10      (0x3U<<8U)
#define I2C_OAR1_ADD10_0    (0x1U<<8U)
#define I2C_OAR1_ADDMODE    (0x1U<<15U)

// OAR2 Configuration

#define I2C_OAR2_ENDUAL     (0x1U<<0U)
#define I2C_OAR2_ADD2       (0x7FU<<1U)
#define I2C_OAR2_ADD2_0     (0x1U<<1U)

// DR Configuration

#define I2C_DR_DR           (0xFFU<<0U)
#define I2C_DR_DR_0         (0x1U<<0U)

// SR1 Configuration

#define I2C_SR1_SB          (0x1U<<0U)
#define I2C_SR1_ADDR        (0x1U<<1U)
#define I2C_SR1_BTF         (0x1U<<2U)
#define I2C_SR1_ADD10       (0x1U<<3U)
#define I2C_SR1_STOPF       (0x1U<<4U)
#define I2C_SR1_RXNE        (0x1U<<6U)
#define I2C_SR1_TXE         (0x1U<<7U)
#define I2C_SR1_BERR        (0x1U<<8U)
#define I2C_SR1_ARLO        (0x1U<<9U)
#define I2C_SR1_AF          (0x1U<<10U)
#define I2C_SR1_OVR         (0x1U<<11U)
#define I2C_SR1_PECERR      (0x1U<<12U)
#define I2C_SR1_TIMEOUT     (0x1U<<14U)
#define I2C_SR1_SMBALERT    (0x1U<<15U)

// SR2 Configuration

#define I2C_SR2_MSL         (0x1U<<0U)
#define I2C_SR2_BUSY        (0x1U<<1U)
#define I2C_SR2_TRA         (0x1U<<2U)
#define I2C_SR2_GENCALL     (0x1U<<4U)
#define I2C_SR2_SMBDEFAULT  (0x1U<<5U)
#define I2C_SR2_SMBHOST     (0x1U<<6U)
#define I2C_SR2_DUALF       (0x1U<<7U)
#define I2C_SR2_PEC         (0xFFU<<8U)
#define I2C_SR2_PEC_0       (0x1U<<8U)

// CCR Configuration

#define I2C_CCR_CCR         (0xFFFU<<0U)
#define I2C_CCR_CCR_0       (0x1U<<0U)
#define I2C_CCR_DUTY        (0x1U<<14U)
#define I2C_CCR_F_S         (0x1U<<15U)

// TRISE Configuration

#define I2C_TRISE_TRISE     (0x3FU<<0U)
#define I2C_TRISE_TRISE_0   (0x1U<<0U)
