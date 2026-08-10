/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_otfdec equates.
 */

#pragma once

#include    <stdint.h>

// OTFDEC address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0[3];
    volatile    uint32_t    PRIVCFGR;
    volatile    uint32_t    RESERVED1[3];
    volatile    uint32_t    R1CFGR;
    volatile    uint32_t    R1STARTADDR;
    volatile    uint32_t    R1ENDADDR;
    volatile    uint32_t    R1NONCER0;
    volatile    uint32_t    R1NONCER1;
    volatile    uint32_t    R1KEYR0;
    volatile    uint32_t    R1KEYR1;
    volatile    uint32_t    R1KEYR2;
    volatile    uint32_t    R1KEYR3;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    R2CFGR;
    volatile    uint32_t    R2STARTADDR;
    volatile    uint32_t    R2ENDADDR;
    volatile    uint32_t    R2NONCER0;
    volatile    uint32_t    R2NONCER1;
    volatile    uint32_t    R2KEYR0;
    volatile    uint32_t    R2KEYR1;
    volatile    uint32_t    R2KEYR2;
    volatile    uint32_t    R2KEYR3;
    volatile    uint32_t    RESERVED3[3];
    volatile    uint32_t    R3CFGR;
    volatile    uint32_t    R3STARTADDR;
    volatile    uint32_t    R3ENDADDR;
    volatile    uint32_t    R3NONCER0;
    volatile    uint32_t    R3NONCER1;
    volatile    uint32_t    R3KEYR0;
    volatile    uint32_t    R3KEYR1;
    volatile    uint32_t    R3KEYR2;
    volatile    uint32_t    R3KEYR3;
    volatile    uint32_t    RESERVED4[3];
    volatile    uint32_t    R4CFGR;
    volatile    uint32_t    R4STARTADDR;
    volatile    uint32_t    R4ENDADDR;
    volatile    uint32_t    R4NONCER0;
    volatile    uint32_t    R4NONCER1;
    volatile    uint32_t    R4KEYR0;
    volatile    uint32_t    R4KEYR1;
    volatile    uint32_t    R4KEYR2;
    volatile    uint32_t    R4KEYR3;
    volatile    uint32_t    RESERVED5[139];
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    IER;
} OTFDEC_TypeDef;

#ifdef __cplusplus
#define OTFDEC1_NS  reinterpret_cast<OTFDEC_TypeDef *>(0x420C5000U)
#define OTFDEC1_S   reinterpret_cast<OTFDEC_TypeDef *>(0x520C5000U)
#define OTFDEC2_NS  reinterpret_cast<OTFDEC_TypeDef *>(0x420C5400U)
#define OTFDEC2_S   reinterpret_cast<OTFDEC_TypeDef *>(0x520C5400U)

#else
#define OTFDEC1_NS  ((OTFDEC_TypeDef *)0x420C5000U)
#define OTFDEC1_S   ((OTFDEC_TypeDef *)0x520C5000U)
#define OTFDEC2_NS  ((OTFDEC_TypeDef *)0x420C5400U)
#define OTFDEC2_S   ((OTFDEC_TypeDef *)0x520C5400U)
#endif

// CR Configuration

#define OTFDEC_CR_ENC                           (0x1U<<0U)

// PRIVCFGR Configuration

#define OTFDEC_PRIVCFGR_PRIV                    (0x1U<<0U)

// R1CFGR Configuration

#define OTFDEC_R1CFGR_REG1_VERSION              (0xFFFFU<<16U)
#define OTFDEC_R1CFGR_REG1_VERSION_0            (0x1U<<16U)
#define OTFDEC_R1CFGR_KEYCRC                    (0xFFU<<8U)
#define OTFDEC_R1CFGR_KEYCRC_0                  (0x1U<<8U)
#define OTFDEC_R1CFGR_MODE                      (0x3U<<4U)
#define OTFDEC_R1CFGR_MODE_0                    (0x1U<<4U)
#define OTFDEC_R1CFGR_KEYLOCK                   (0x1U<<2U)
#define OTFDEC_R1CFGR_CONFIGLOCK                (0x1U<<1U)
#define OTFDEC_R1CFGR_REG_EN                    (0x1U<<0U)

// R1STARTADDR Configuration

#define OTFDEC_R1STARTADDR_REG1_START_ADDR      (0xFFFFFFFFU<<0U)
#define OTFDEC_R1STARTADDR_REG1_START_ADDR_0    (0x1U<<0U)

// R1ENDADDR Configuration

#define OTFDEC_R1ENDADDR_REG1_END_ADDR          (0xFFFFFFFFU<<0U)
#define OTFDEC_R1ENDADDR_REG1_END_ADDR_0        (0x1U<<0U)

// R1NONCER0 Configuration

#define OTFDEC_R1NONCER0_REG1_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R1NONCER0_REG1_NONCE_0           (0x1U<<0U)

// R1NONCER1 Configuration

#define OTFDEC_R1NONCER1_REG1_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R1NONCER1_REG1_NONCE_0           (0x1U<<0U)

// R1KEYR0 Configuration

#define OTFDEC_R1KEYR0_REG1_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R1KEYR0_REG1_KEY_0               (0x1U<<0U)

// R1KEYR1 Configuration

#define OTFDEC_R1KEYR1_REG1_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R1KEYR1_REG1_KEY_0               (0x1U<<0U)

// R1KEYR2 Configuration

#define OTFDEC_R1KEYR2_REG1_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R1KEYR2_REG1_KEY_0               (0x1U<<0U)

// R1KEYR3 Configuration

#define OTFDEC_R1KEYR3_REG1_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R1KEYR3_REG1_KEY_0               (0x1U<<0U)

// R2CFGR Configuration

#define OTFDEC_R2CFGR_REG2_VERSION              (0xFFFFU<<16U)
#define OTFDEC_R2CFGR_REG2_VERSION_0            (0x1U<<16U)
#define OTFDEC_R2CFGR_KEYCRC                    (0xFFU<<8U)
#define OTFDEC_R2CFGR_KEYCRC_0                  (0x1U<<8U)
#define OTFDEC_R2CFGR_MODE                      (0x3U<<4U)
#define OTFDEC_R2CFGR_MODE_0                    (0x1U<<4U)
#define OTFDEC_R2CFGR_KEYLOCK                   (0x1U<<2U)
#define OTFDEC_R2CFGR_CONFIGLOCK                (0x1U<<1U)
#define OTFDEC_R2CFGR_REG_EN                    (0x1U<<0U)

// R2STARTADDR Configuration

#define OTFDEC_R2STARTADDR_REG2_START_ADDR      (0xFFFFFFFFU<<0U)
#define OTFDEC_R2STARTADDR_REG2_START_ADDR_0    (0x1U<<0U)

// R2ENDADDR Configuration

#define OTFDEC_R2ENDADDR_REG2_END_ADDR          (0xFFFFFFFFU<<0U)
#define OTFDEC_R2ENDADDR_REG2_END_ADDR_0        (0x1U<<0U)

// R2NONCER0 Configuration

#define OTFDEC_R2NONCER0_REG2_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R2NONCER0_REG2_NONCE_0           (0x1U<<0U)

// R2NONCER1 Configuration

#define OTFDEC_R2NONCER1_REG2_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R2NONCER1_REG2_NONCE_0           (0x1U<<0U)

// R2KEYR0 Configuration

#define OTFDEC_R2KEYR0_REG2_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R2KEYR0_REG2_KEY_0               (0x1U<<0U)

// R2KEYR1 Configuration

#define OTFDEC_R2KEYR1_REG2_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R2KEYR1_REG2_KEY_0               (0x1U<<0U)

// R2KEYR2 Configuration

#define OTFDEC_R2KEYR2_REG2_KEY_                (0xFFFFFFFFU<<0U)
#define OTFDEC_R2KEYR2_REG2_KEY__0              (0x1U<<0U)

// R2KEYR3 Configuration

#define OTFDEC_R2KEYR3_REG2_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R2KEYR3_REG2_KEY_0               (0x1U<<0U)

// R3CFGR Configuration

#define OTFDEC_R3CFGR_REG3_VERSION              (0xFFFFU<<16U)
#define OTFDEC_R3CFGR_REG3_VERSION_0            (0x1U<<16U)
#define OTFDEC_R3CFGR_KEYCRC                    (0xFFU<<8U)
#define OTFDEC_R3CFGR_KEYCRC_0                  (0x1U<<8U)
#define OTFDEC_R3CFGR_MODE                      (0x3U<<4U)
#define OTFDEC_R3CFGR_MODE_0                    (0x1U<<4U)
#define OTFDEC_R3CFGR_KEYLOCK                   (0x1U<<2U)
#define OTFDEC_R3CFGR_CONFIGLOCK                (0x1U<<1U)
#define OTFDEC_R3CFGR_REG_EN                    (0x1U<<0U)

// R3STARTADDR Configuration

#define OTFDEC_R3STARTADDR_REG3_START_ADDR      (0xFFFFFFFFU<<0U)
#define OTFDEC_R3STARTADDR_REG3_START_ADDR_0    (0x1U<<0U)

// R3ENDADDR Configuration

#define OTFDEC_R3ENDADDR_REG3_END_ADDR          (0xFFFFFFFFU<<0U)
#define OTFDEC_R3ENDADDR_REG3_END_ADDR_0        (0x1U<<0U)

// R3NONCER0 Configuration

#define OTFDEC_R3NONCER0_REG3_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R3NONCER0_REG3_NONCE_0           (0x1U<<0U)

// R3NONCER1 Configuration

#define OTFDEC_R3NONCER1_REG3_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R3NONCER1_REG3_NONCE_0           (0x1U<<0U)

// R3KEYR0 Configuration

#define OTFDEC_R3KEYR0_REG3_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R3KEYR0_REG3_KEY_0               (0x1U<<0U)

// R3KEYR1 Configuration

#define OTFDEC_R3KEYR1_REG3_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R3KEYR1_REG3_KEY_0               (0x1U<<0U)

// R3KEYR2 Configuration

#define OTFDEC_R3KEYR2_REG3_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R3KEYR2_REG3_KEY_0               (0x1U<<0U)

// R3KEYR3 Configuration

#define OTFDEC_R3KEYR3_REG3_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R3KEYR3_REG3_KEY_0               (0x1U<<0U)

// R4CFGR Configuration

#define OTFDEC_R4CFGR_REG4_VERSION              (0xFFFFU<<16U)
#define OTFDEC_R4CFGR_REG4_VERSION_0            (0x1U<<16U)
#define OTFDEC_R4CFGR_KEYCRC                    (0xFFU<<8U)
#define OTFDEC_R4CFGR_KEYCRC_0                  (0x1U<<8U)
#define OTFDEC_R4CFGR_MODE                      (0x3U<<4U)
#define OTFDEC_R4CFGR_MODE_0                    (0x1U<<4U)
#define OTFDEC_R4CFGR_KEYLOCK                   (0x1U<<2U)
#define OTFDEC_R4CFGR_CONFIGLOCK                (0x1U<<1U)
#define OTFDEC_R4CFGR_REG_EN                    (0x1U<<0U)

// R4STARTADDR Configuration

#define OTFDEC_R4STARTADDR_REG4_START_ADDR      (0xFFFFFFFFU<<0U)
#define OTFDEC_R4STARTADDR_REG4_START_ADDR_0    (0x1U<<0U)

// R4ENDADDR Configuration

#define OTFDEC_R4ENDADDR_REG4_END_ADDR          (0xFFFFFFFFU<<0U)
#define OTFDEC_R4ENDADDR_REG4_END_ADDR_0        (0x1U<<0U)

// R4NONCER0 Configuration

#define OTFDEC_R4NONCER0_REG4_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R4NONCER0_REG4_NONCE_0           (0x1U<<0U)

// R4NONCER1 Configuration

#define OTFDEC_R4NONCER1_REG4_NONCE             (0xFFFFFFFFU<<0U)
#define OTFDEC_R4NONCER1_REG4_NONCE_0           (0x1U<<0U)

// R4KEYR0 Configuration

#define OTFDEC_R4KEYR0_REG4_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R4KEYR0_REG4_KEY_0               (0x1U<<0U)

// R4KEYR1 Configuration

#define OTFDEC_R4KEYR1_REG4_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R4KEYR1_REG4_KEY_0               (0x1U<<0U)

// R4KEYR2 Configuration

#define OTFDEC_R4KEYR2_REG4_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R4KEYR2_REG4_KEY_0               (0x1U<<0U)

// R4KEYR3 Configuration

#define OTFDEC_R4KEYR3_REG4_KEY                 (0xFFFFFFFFU<<0U)
#define OTFDEC_R4KEYR3_REG4_KEY_0               (0x1U<<0U)

// ISR Configuration

#define OTFDEC_ISR_KEIF                         (0x1U<<2U)
#define OTFDEC_ISR_XONEIF                       (0x1U<<1U)
#define OTFDEC_ISR_SEIF                         (0x1U<<0U)

// ICR Configuration

#define OTFDEC_ICR_KEIF                         (0x1U<<2U)
#define OTFDEC_ICR_XONEIF                       (0x1U<<1U)
#define OTFDEC_ICR_SEIF                         (0x1U<<0U)

// IER Configuration

#define OTFDEC_IER_KEIE                         (0x1U<<2U)
#define OTFDEC_IER_XONEIE                       (0x1U<<1U)
#define OTFDEC_IER_SEIE                         (0x1U<<0U)
