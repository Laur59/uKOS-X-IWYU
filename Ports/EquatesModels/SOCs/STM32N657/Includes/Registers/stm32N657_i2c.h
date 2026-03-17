/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_i2c.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_i2c equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
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
    volatile    uint32_t    TIMINGR;
    volatile    uint32_t    TIMEOUTR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    PECR;
    volatile    uint32_t    RXDR;
    volatile    uint32_t    TXDR;
} I2C_TypeDef;

#ifdef __cplusplus
#define I2C1_NS reinterpret_cast<I2C_TypeDef *>(0x40005400U)
#define I2C1_S  reinterpret_cast<I2C_TypeDef *>(0x50005400U)
#define I2C2_NS reinterpret_cast<I2C_TypeDef *>(0x40005800U)
#define I2C2_S  reinterpret_cast<I2C_TypeDef *>(0x50005800U)
#define I2C3_NS reinterpret_cast<I2C_TypeDef *>(0x40005C00U)
#define I2C3_S  reinterpret_cast<I2C_TypeDef *>(0x50005C00U)
#define I2C4_NS reinterpret_cast<I2C_TypeDef *>(0x46001C00U)
#define I2C4_S  reinterpret_cast<I2C_TypeDef *>(0x56001C00U)

#else
#define I2C1_NS ((I2C_TypeDef *)0x40005400U)
#define I2C1_S  ((I2C_TypeDef *)0x50005400U)
#define I2C2_NS ((I2C_TypeDef *)0x40005800U)
#define I2C2_S  ((I2C_TypeDef *)0x50005800U)
#define I2C3_NS ((I2C_TypeDef *)0x40005C00U)
#define I2C3_S  ((I2C_TypeDef *)0x50005C00U)
#define I2C4_NS ((I2C_TypeDef *)0x46001C00U)
#define I2C4_S  ((I2C_TypeDef *)0x56001C00U)
#endif

// CR1 Configuration

#define I2C_CR1_STOPFACLR           (0x1U<<31)
#define I2C_CR1_ADDRACLR            (0x1U<<30)
#define I2C_CR1_FMP                 (0x1U<<24)
#define I2C_CR1_PECEN               (0x1U<<23)
#define I2C_CR1_ALERTEN             (0x1U<<22)
#define I2C_CR1_SMBDEN              (0x1U<<21)
#define I2C_CR1_SMBHEN              (0x1U<<20)
#define I2C_CR1_GCEN                (0x1U<<19)
#define I2C_CR1_WUPEN               (0x1U<<18)
#define I2C_CR1_NOSTRETCH           (0x1U<<17)
#define I2C_CR1_SBC                 (0x1U<<16)
#define I2C_CR1_RXDMAEN             (0x1U<<15)
#define I2C_CR1_TXDMAEN             (0x1U<<14)
#define I2C_CR1_ANFOFF              (0x1U<<12)
#define I2C_CR1_DNF                 (0xFU<<8)
#define I2C_CR1_DNF_0               (0x1U<<8)
#define I2C_CR1_ERRIE               (0x1U<<7)
#define I2C_CR1_TCIE                (0x1U<<6)
#define I2C_CR1_STOPIE              (0x1U<<5)
#define I2C_CR1_NACKIE              (0x1U<<4)
#define I2C_CR1_ADDRIE              (0x1U<<3)
#define I2C_CR1_RXIE                (0x1U<<2)
#define I2C_CR1_TXIE                (0x1U<<1)
#define I2C_CR1_PE                  (0x1U<<0)

#define I2C_CR1_STOPFACLR_B_0X0     (0x0U<<31)
#define I2C_CR1_STOPFACLR_B_0X1     (0x1U<<31)
#define I2C_CR1_ADDRACLR_B_0X0      (0x0U<<30)
#define I2C_CR1_ADDRACLR_B_0X1      (0x1U<<30)
#define I2C_CR1_FMP_B_0X0           (0x0U<<24)
#define I2C_CR1_FMP_B_0X1           (0x1U<<24)
#define I2C_CR1_PECEN_B_0X0         (0x0U<<23)
#define I2C_CR1_PECEN_B_0X1         (0x1U<<23)
#define I2C_CR1_ALERTEN_B_0X0       (0x0U<<22)
#define I2C_CR1_ALERTEN_B_0X1       (0x1U<<22)
#define I2C_CR1_SMBDEN_B_0X0        (0x0U<<21)
#define I2C_CR1_SMBDEN_B_0X1        (0x1U<<21)
#define I2C_CR1_SMBHEN_B_0X0        (0x0U<<20)
#define I2C_CR1_SMBHEN_B_0X1        (0x1U<<20)
#define I2C_CR1_GCEN_B_0X0          (0x0U<<19)
#define I2C_CR1_GCEN_B_0X1          (0x1U<<19)
#define I2C_CR1_WUPEN_B_0X0         (0x0U<<18)
#define I2C_CR1_WUPEN_B_0X1         (0x1U<<18)
#define I2C_CR1_NOSTRETCH_B_0X0     (0x0U<<17)
#define I2C_CR1_NOSTRETCH_B_0X1     (0x1U<<17)
#define I2C_CR1_SBC_B_0X0           (0x0U<<16)
#define I2C_CR1_SBC_B_0X1           (0x1U<<16)
#define I2C_CR1_RXDMAEN_B_0X0       (0x0U<<15)
#define I2C_CR1_RXDMAEN_B_0X1       (0x1U<<15)
#define I2C_CR1_TXDMAEN_B_0X0       (0x0U<<14)
#define I2C_CR1_TXDMAEN_B_0X1       (0x1U<<14)
#define I2C_CR1_ANFOFF_B_0X0        (0x0U<<12)
#define I2C_CR1_ANFOFF_B_0X1        (0x1U<<12)
#define I2C_CR1_DNF_B_0X0           (0x0U<<8)
#define I2C_CR1_DNF_B_0X1           (0x1U<<8)
#define I2C_CR1_DNF_B_0XF           (0xFU<<8)
#define I2C_CR1_ERRIE_B_0X0         (0x0U<<7)
#define I2C_CR1_ERRIE_B_0X1         (0x1U<<7)
#define I2C_CR1_TCIE_B_0X0          (0x0U<<6)
#define I2C_CR1_TCIE_B_0X1          (0x1U<<6)
#define I2C_CR1_STOPIE_B_0X0        (0x0U<<5)
#define I2C_CR1_STOPIE_B_0X1        (0x1U<<5)
#define I2C_CR1_NACKIE_B_0X0        (0x0U<<4)
#define I2C_CR1_NACKIE_B_0X1        (0x1U<<4)
#define I2C_CR1_ADDRIE_B_0X0        (0x0U<<3)
#define I2C_CR1_ADDRIE_B_0X1        (0x1U<<3)
#define I2C_CR1_RXIE_B_0X0          (0x0U<<2)
#define I2C_CR1_RXIE_B_0X1          (0x1U<<2)
#define I2C_CR1_TXIE_B_0X0          (0x0U<<1)
#define I2C_CR1_TXIE_B_0X1          (0x1U<<1)
#define I2C_CR1_PE_B_0X0            (0x0U<<0)
#define I2C_CR1_PE_B_0X1            (0x1U<<0)

// CR2 Configuration

#define I2C_CR2_PECBYTE             (0x1U<<26)
#define I2C_CR2_AUTOEND             (0x1U<<25)
#define I2C_CR2_RELOAD              (0x1U<<24)
#define I2C_CR2_NBYTES              (0xFFU<<16)
#define I2C_CR2_NBYTES_0            (0x1U<<16)
#define I2C_CR2_NACK                (0x1U<<15)
#define I2C_CR2_STOP                (0x1U<<14)
#define I2C_CR2_START               (0x1U<<13)
#define I2C_CR2_HEAD10R             (0x1U<<12)
#define I2C_CR2_ADD10               (0x1U<<11)
#define I2C_CR2_RD_WRN              (0x1U<<10)
#define I2C_CR2_SADD                (0x3FFU<<0)
#define I2C_CR2_SADD_0              (0x1U<<0)

#define I2C_CR2_PECBYTE_B_0X0       (0x0U<<26)
#define I2C_CR2_PECBYTE_B_0X1       (0x1U<<26)
#define I2C_CR2_AUTOEND_B_0X0       (0x0U<<25)
#define I2C_CR2_AUTOEND_B_0X1       (0x1U<<25)
#define I2C_CR2_RELOAD_B_0X0        (0x0U<<24)
#define I2C_CR2_RELOAD_B_0X1        (0x1U<<24)
#define I2C_CR2_NACK_B_0X0          (0x0U<<15)
#define I2C_CR2_NACK_B_0X1          (0x1U<<15)
#define I2C_CR2_STOP_B_0X0          (0x0U<<14)
#define I2C_CR2_STOP_B_0X1          (0x1U<<14)
#define I2C_CR2_START_B_0X0         (0x0U<<13)
#define I2C_CR2_START_B_0X1         (0x1U<<13)
#define I2C_CR2_HEAD10R_B_0X0       (0x0U<<12)
#define I2C_CR2_HEAD10R_B_0X1       (0x1U<<12)
#define I2C_CR2_ADD10_B_0X0         (0x0U<<11)
#define I2C_CR2_ADD10_B_0X1         (0x1U<<11)
#define I2C_CR2_RD_WRN_B_0X0        (0x0U<<10)
#define I2C_CR2_RD_WRN_B_0X1        (0x1U<<10)

// OAR1 Configuration

#define I2C_OAR1_OA1EN              (0x1U<<15)
#define I2C_OAR1_OA1MODE            (0x1U<<10)
#define I2C_OAR1_OA1                (0x3FFU<<0)
#define I2C_OAR1_OA1_0              (0x1U<<0)

#define I2C_OAR1_OA1EN_B_0X0        (0x0U<<15)
#define I2C_OAR1_OA1EN_B_0X1        (0x1U<<15)
#define I2C_OAR1_OA1MODE_B_0X0      (0x0U<<10)
#define I2C_OAR1_OA1MODE_B_0X1      (0x1U<<10)

// OAR2 Configuration

#define I2C_OAR2_OA2EN              (0x1U<<15)
#define I2C_OAR2_OA2MSK             (0x7U<<8)
#define I2C_OAR2_OA2MSK_0           (0x1U<<8)
#define I2C_OAR2_OA2                (0x7FU<<1)
#define I2C_OAR2_OA2_0              (0x1U<<1)

#define I2C_OAR2_OA2EN_B_0X0        (0x0U<<15)
#define I2C_OAR2_OA2EN_B_0X1        (0x1U<<15)
#define I2C_OAR2_OA2MSK_B_0X0       (0x0U<<8)
#define I2C_OAR2_OA2MSK_B_0X1       (0x1U<<8)
#define I2C_OAR2_OA2MSK_B_0X2       (0x2U<<8)
#define I2C_OAR2_OA2MSK_B_0X3       (0x3U<<8)
#define I2C_OAR2_OA2MSK_B_0X4       (0x4U<<8)
#define I2C_OAR2_OA2MSK_B_0X5       (0x5U<<8)
#define I2C_OAR2_OA2MSK_B_0X6       (0x6U<<8)
#define I2C_OAR2_OA2MSK_B_0X7       (0x7U<<8)

// TIMINGR Configuration

#define I2C_TIMINGR_PRESC           (0xFU<<28)
#define I2C_TIMINGR_PRESC_0         (0x1U<<28)
#define I2C_TIMINGR_SCLDEL          (0xFU<<20)
#define I2C_TIMINGR_SCLDEL_0        (0x1U<<20)
#define I2C_TIMINGR_SDADEL          (0xFU<<16)
#define I2C_TIMINGR_SDADEL_0        (0x1U<<16)
#define I2C_TIMINGR_SCLH            (0xFFU<<8)
#define I2C_TIMINGR_SCLH_0          (0x1U<<8)
#define I2C_TIMINGR_SCLL            (0xFFU<<0)
#define I2C_TIMINGR_SCLL_0          (0x1U<<0)

// TIMEOUTR Configuration

#define I2C_TIMEOUTR_TEXTEN         (0x1U<<31)
#define I2C_TIMEOUTR_TIMEOUTB       (0xFFFU<<16)
#define I2C_TIMEOUTR_TIMEOUTB_0     (0x1U<<16)
#define I2C_TIMEOUTR_TIMOUTEN       (0x1U<<15)
#define I2C_TIMEOUTR_TIDLE          (0x1U<<12)
#define I2C_TIMEOUTR_TIMEOUTA       (0xFFFU<<0)
#define I2C_TIMEOUTR_TIMEOUTA_0     (0x1U<<0)

#define I2C_TIMEOUTR_TEXTEN_B_0X0   (0x0U<<31)
#define I2C_TIMEOUTR_TEXTEN_B_0X1   (0x1U<<31)
#define I2C_TIMEOUTR_TIMOUTEN_B_0X0 (0x0U<<15)
#define I2C_TIMEOUTR_TIMOUTEN_B_0X1 (0x1U<<15)
#define I2C_TIMEOUTR_TIDLE_B_0X0    (0x0U<<12)
#define I2C_TIMEOUTR_TIDLE_B_0X1    (0x1U<<12)

// ISR Configuration

#define I2C_ISR_ADDCODE             (0x7FU<<17)
#define I2C_ISR_ADDCODE_0           (0x1U<<17)
#define I2C_ISR_DIR                 (0x1U<<16)
#define I2C_ISR_BUSY                (0x1U<<15)
#define I2C_ISR_ALERT               (0x1U<<13)
#define I2C_ISR_TIMEOUT             (0x1U<<12)
#define I2C_ISR_PECERR              (0x1U<<11)
#define I2C_ISR_OVR                 (0x1U<<10)
#define I2C_ISR_ARLO                (0x1U<<9)
#define I2C_ISR_BERR                (0x1U<<8)
#define I2C_ISR_TCR                 (0x1U<<7)
#define I2C_ISR_TC                  (0x1U<<6)
#define I2C_ISR_STOPF               (0x1U<<5)
#define I2C_ISR_NACKF               (0x1U<<4)
#define I2C_ISR_ADDR                (0x1U<<3)
#define I2C_ISR_RXNE                (0x1U<<2)
#define I2C_ISR_TXIS                (0x1U<<1)
#define I2C_ISR_TXE                 (0x1U<<0)

#define I2C_ISR_DIR_B_0X0           (0x0U<<16)
#define I2C_ISR_DIR_B_0X1           (0x1U<<16)

// ICR Configuration

#define I2C_ICR_ALERTCF             (0x1U<<13)
#define I2C_ICR_TIMOUTCF            (0x1U<<12)
#define I2C_ICR_PECCF               (0x1U<<11)
#define I2C_ICR_OVRCF               (0x1U<<10)
#define I2C_ICR_ARLOCF              (0x1U<<9)
#define I2C_ICR_BERRCF              (0x1U<<8)
#define I2C_ICR_STOPCF              (0x1U<<5)
#define I2C_ICR_NACKCF              (0x1U<<4)
#define I2C_ICR_ADDRCF              (0x1U<<3)

// PECR Configuration

#define I2C_PECR_PEC                (0xFFU<<0)
#define I2C_PECR_PEC_0              (0x1U<<0)

// RXDR Configuration

#define I2C_RXDR_RXDATA             (0xFFU<<0)
#define I2C_RXDR_RXDATA_0           (0x1U<<0)

// TXDR Configuration

#define I2C_TXDR_TXDATA             (0xFFU<<0)
#define I2C_TXDR_TXDATA_0           (0x1U<<0)
