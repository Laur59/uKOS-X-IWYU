/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_uart4 equates.
 */

#pragma once

#include    <stdint.h>

// UART4 address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    SR;
    volatile    uint32_t    DR;
    volatile    uint32_t    BRR;
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
} UART4_TypeDef;

#ifdef __cplusplus
#define UART4   reinterpret_cast<UART4_TypeDef *>(0x40004C00U)

#else
#define UART4   ((UART4_TypeDef *)0x40004C00U)
#endif

// SR Configuration

#define UART4_SR_PE                 (0x1U<<0)
#define UART4_SR_FE                 (0x1U<<1)
#define UART4_SR_NF                 (0x1U<<2)
#define UART4_SR_ORE                (0x1U<<3)
#define UART4_SR_IDLE               (0x1U<<4)
#define UART4_SR_RXNE               (0x1U<<5)
#define UART4_SR_TC                 (0x1U<<6)
#define UART4_SR_TXE                (0x1U<<7)
#define UART4_SR_LBD                (0x1U<<8)

// DR Configuration

#define UART4_DR_DR                 (0x1FFU<<0)
#define UART4_DR_DR_0               (0x1U<<0)

// BRR Configuration

#define UART4_BRR_DIV_FRACTION      (0xFU<<0)
#define UART4_BRR_DIV_FRACTION_0    (0x1U<<0)
#define UART4_BRR_DIV_MANTISSA      (0xFFFU<<4)
#define UART4_BRR_DIV_MANTISSA_0    (0x1U<<4)

// CR1 Configuration

#define UART4_CR1_SBK               (0x1U<<0)
#define UART4_CR1_RWU               (0x1U<<1)
#define UART4_CR1_RE                (0x1U<<2)
#define UART4_CR1_TE                (0x1U<<3)
#define UART4_CR1_IDLEIE            (0x1U<<4)
#define UART4_CR1_RXNEIE            (0x1U<<5)
#define UART4_CR1_TCIE              (0x1U<<6)
#define UART4_CR1_TXEIE             (0x1U<<7)
#define UART4_CR1_PEIE              (0x1U<<8)
#define UART4_CR1_PS                (0x1U<<9)
#define UART4_CR1_PCE               (0x1U<<10)
#define UART4_CR1_WAKE              (0x1U<<11)
#define UART4_CR1_M                 (0x1U<<12)
#define UART4_CR1_UE                (0x1U<<13)
#define UART4_CR1_OVER8             (0x1U<<15)

// CR2 Configuration

#define UART4_CR2_ADD               (0xFU<<0)
#define UART4_CR2_ADD_0             (0x1U<<0)
#define UART4_CR2_LBDL              (0x1U<<5)
#define UART4_CR2_LBDIE             (0x1U<<6)
#define UART4_CR2_STOP              (0x3U<<12)
#define UART4_CR2_STOP_0            (0x1U<<12)
#define UART4_CR2_LINEN             (0x1U<<14)

// CR3 Configuration

#define UART4_CR3_EIE               (0x1U<<0)
#define UART4_CR3_IREN              (0x1U<<1)
#define UART4_CR3_IRLP              (0x1U<<2)
#define UART4_CR3_HDSEL             (0x1U<<3)
#define UART4_CR3_DMAR              (0x1U<<6)
#define UART4_CR3_DMAT              (0x1U<<7)
#define UART4_CR3_ONEBIT            (0x1U<<11)
