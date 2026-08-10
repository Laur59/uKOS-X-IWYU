/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_uart5 equates.
 */

#pragma once

#include    <stdint.h>

// UART5 address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    SR;
    volatile    uint32_t    DR;
    volatile    uint32_t    BRR;
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
} UART5_TypeDef;

#ifdef __cplusplus
#define UART5   reinterpret_cast<UART5_TypeDef *>(0x40005000U)

#else
#define UART5   ((UART5_TypeDef *)0x40005000U)
#endif

// SR Configuration

#define UART5_SR_PE                 (0x1U<<0U)
#define UART5_SR_FE                 (0x1U<<1U)
#define UART5_SR_NF                 (0x1U<<2U)
#define UART5_SR_ORE                (0x1U<<3U)
#define UART5_SR_IDLE               (0x1U<<4U)
#define UART5_SR_RXNE               (0x1U<<5U)
#define UART5_SR_TC                 (0x1U<<6U)
#define UART5_SR_TXE                (0x1U<<7U)
#define UART5_SR_LBD                (0x1U<<8U)

// DR Configuration

#define UART5_DR_DR                 (0x1FFU<<0U)
#define UART5_DR_DR_0               (0x1U<<0U)

// BRR Configuration

#define UART5_BRR_DIV_FRACTION      (0xFU<<0U)
#define UART5_BRR_DIV_FRACTION_0    (0x1U<<0U)
#define UART5_BRR_DIV_MANTISSA      (0xFFFU<<4U)
#define UART5_BRR_DIV_MANTISSA_0    (0x1U<<4U)

// CR1 Configuration

#define UART5_CR1_SBK               (0x1U<<0U)
#define UART5_CR1_RWU               (0x1U<<1U)
#define UART5_CR1_RE                (0x1U<<2U)
#define UART5_CR1_TE                (0x1U<<3U)
#define UART5_CR1_IDLEIE            (0x1U<<4U)
#define UART5_CR1_RXNEIE            (0x1U<<5U)
#define UART5_CR1_TCIE              (0x1U<<6U)
#define UART5_CR1_TXEIE             (0x1U<<7U)
#define UART5_CR1_PEIE              (0x1U<<8U)
#define UART5_CR1_PS                (0x1U<<9U)
#define UART5_CR1_PCE               (0x1U<<10U)
#define UART5_CR1_WAKE              (0x1U<<11U)
#define UART5_CR1_M                 (0x1U<<12U)
#define UART5_CR1_UE                (0x1U<<13U)
#define UART5_CR1_OVER8             (0x1U<<15U)

// CR2 Configuration

#define UART5_CR2_ADD               (0xFU<<0U)
#define UART5_CR2_ADD_0             (0x1U<<0U)
#define UART5_CR2_LBDL              (0x1U<<5U)
#define UART5_CR2_LBDIE             (0x1U<<6U)
#define UART5_CR2_STOP              (0x3U<<12U)
#define UART5_CR2_STOP_0            (0x1U<<12U)
#define UART5_CR2_LINEN             (0x1U<<14U)

// CR3 Configuration

#define UART5_CR3_EIE               (0x1U<<0U)
#define UART5_CR3_IREN              (0x1U<<1U)
#define UART5_CR3_IRLP              (0x1U<<2U)
#define UART5_CR3_HDSEL             (0x1U<<3U)
#define UART5_CR3_DMAR              (0x1U<<6U)
#define UART5_CR3_DMAT              (0x1U<<7U)
#define UART5_CR3_ONEBIT            (0x1U<<11U)
