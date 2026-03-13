/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32F217_i2c.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32F217_i2c equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
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

#define I2C_CR1_PE          (0x1U<<0)
#define I2C_CR1_SMBUS       (0x1U<<1)
#define I2C_CR1_SMBTYPE     (0x1U<<3)
#define I2C_CR1_ENARP       (0x1U<<4)
#define I2C_CR1_ENPEC       (0x1U<<5)
#define I2C_CR1_ENGC        (0x1U<<6)
#define I2C_CR1_NOSTRETCH   (0x1U<<7)
#define I2C_CR1_START       (0x1U<<8)
#define I2C_CR1_STOP        (0x1U<<9)
#define I2C_CR1_ACK         (0x1U<<10)
#define I2C_CR1_POS         (0x1U<<11)
#define I2C_CR1_PEC         (0x1U<<12)
#define I2C_CR1_ALERT       (0x1U<<13)
#define I2C_CR1_SWRST       (0x1U<<15)

// CR2 Configuration

#define I2C_CR2_FREQ        (0x3FU<<0)
#define I2C_CR2_FREQ_0      (0x1U<<0)
#define I2C_CR2_ITERREN     (0x1U<<8)
#define I2C_CR2_ITEVTEN     (0x1U<<9)
#define I2C_CR2_ITBUFEN     (0x1U<<10)
#define I2C_CR2_DMAEN       (0x1U<<11)
#define I2C_CR2_LAST        (0x1U<<12)

// OAR1 Configuration

#define I2C_OAR1_ADD0       (0x1U<<0)
#define I2C_OAR1_ADD7       (0x7FU<<1)
#define I2C_OAR1_ADD7_0     (0x1U<<1)
#define I2C_OAR1_ADD10      (0x3U<<8)
#define I2C_OAR1_ADD10_0    (0x1U<<8)
#define I2C_OAR1_ADDMODE    (0x1U<<15)

// OAR2 Configuration

#define I2C_OAR2_ENDUAL     (0x1U<<0)
#define I2C_OAR2_ADD2       (0x7FU<<1)
#define I2C_OAR2_ADD2_0     (0x1U<<1)

// DR Configuration

#define I2C_DR_DR           (0xFFU<<0)
#define I2C_DR_DR_0         (0x1U<<0)

// SR1 Configuration

#define I2C_SR1_SB          (0x1U<<0)
#define I2C_SR1_ADDR        (0x1U<<1)
#define I2C_SR1_BTF         (0x1U<<2)
#define I2C_SR1_ADD10       (0x1U<<3)
#define I2C_SR1_STOPF       (0x1U<<4)
#define I2C_SR1_RXNE        (0x1U<<6)
#define I2C_SR1_TXE         (0x1U<<7)
#define I2C_SR1_BERR        (0x1U<<8)
#define I2C_SR1_ARLO        (0x1U<<9)
#define I2C_SR1_AF          (0x1U<<10)
#define I2C_SR1_OVR         (0x1U<<11)
#define I2C_SR1_PECERR      (0x1U<<12)
#define I2C_SR1_TIMEOUT     (0x1U<<14)
#define I2C_SR1_SMBALERT    (0x1U<<15)

// SR2 Configuration

#define I2C_SR2_MSL         (0x1U<<0)
#define I2C_SR2_BUSY        (0x1U<<1)
#define I2C_SR2_TRA         (0x1U<<2)
#define I2C_SR2_GENCALL     (0x1U<<4)
#define I2C_SR2_SMBDEFAULT  (0x1U<<5)
#define I2C_SR2_SMBHOST     (0x1U<<6)
#define I2C_SR2_DUALF       (0x1U<<7)
#define I2C_SR2_PEC         (0xFFU<<8)
#define I2C_SR2_PEC_0       (0x1U<<8)

// CCR Configuration

#define I2C_CCR_CCR         (0xFFFU<<0)
#define I2C_CCR_CCR_0       (0x1U<<0)
#define I2C_CCR_DUTY        (0x1U<<14)
#define I2C_CCR_F_S         (0x1U<<15)

// TRISE Configuration

#define I2C_TRISE_TRISE     (0x3FU<<0)
#define I2C_TRISE_TRISE_0   (0x1U<<0)
