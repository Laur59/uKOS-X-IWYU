/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_usart3 equates.
 */

#pragma once

#include    <stdint.h>

// USART3 address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    SR;
    volatile    uint32_t    DR;
    volatile    uint32_t    BRR;
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
    volatile    uint32_t    GTPR;
} USART3_TypeDef;

#ifdef __cplusplus
#define USART3  reinterpret_cast<USART3_TypeDef *>(0x40004800U)

#else
#define USART3  ((USART3_TypeDef *)0x40004800U)
#endif

// SR Configuration

#define USART3_SR_PE                (0x1U<<0)
#define USART3_SR_FE                (0x1U<<1)
#define USART3_SR_NF                (0x1U<<2)
#define USART3_SR_ORE               (0x1U<<3)
#define USART3_SR_IDLE              (0x1U<<4)
#define USART3_SR_RXNE              (0x1U<<5)
#define USART3_SR_TC                (0x1U<<6)
#define USART3_SR_TXE               (0x1U<<7)
#define USART3_SR_LBD               (0x1U<<8)
#define USART3_SR_CTS               (0x1U<<9)

// DR Configuration

#define USART3_DR_DR                (0x1FFU<<0)
#define USART3_DR_DR_0              (0x1U<<0)

// BRR Configuration

#define USART3_BRR_DIV_FRACTION     (0xFU<<0)
#define USART3_BRR_DIV_FRACTION_0   (0x1U<<0)
#define USART3_BRR_DIV_MANTISSA     (0xFFFU<<4)
#define USART3_BRR_DIV_MANTISSA_0   (0x1U<<4)

// CR1 Configuration

#define USART3_CR1_SBK              (0x1U<<0)
#define USART3_CR1_RWU              (0x1U<<1)
#define USART3_CR1_RE               (0x1U<<2)
#define USART3_CR1_TE               (0x1U<<3)
#define USART3_CR1_IDLEIE           (0x1U<<4)
#define USART3_CR1_RXNEIE           (0x1U<<5)
#define USART3_CR1_TCIE             (0x1U<<6)
#define USART3_CR1_TXEIE            (0x1U<<7)
#define USART3_CR1_PEIE             (0x1U<<8)
#define USART3_CR1_PS               (0x1U<<9)
#define USART3_CR1_PCE              (0x1U<<10)
#define USART3_CR1_WAKE             (0x1U<<11)
#define USART3_CR1_M                (0x1U<<12)
#define USART3_CR1_UE               (0x1U<<13)
#define USART3_CR1_OVER8            (0x1U<<15)

// CR2 Configuration

#define USART3_CR2_ADD              (0xFU<<0)
#define USART3_CR2_ADD_0            (0x1U<<0)
#define USART3_CR2_LBDL             (0x1U<<5)
#define USART3_CR2_LBDIE            (0x1U<<6)
#define USART3_CR2_LBCL             (0x1U<<8)
#define USART3_CR2_CPHA             (0x1U<<9)
#define USART3_CR2_CPOL             (0x1U<<10)
#define USART3_CR2_CLKEN            (0x1U<<11)
#define USART3_CR2_STOP             (0x3U<<12)
#define USART3_CR2_STOP_0           (0x1U<<12)
#define USART3_CR2_LINEN            (0x1U<<14)

// CR3 Configuration

#define USART3_CR3_EIE              (0x1U<<0)
#define USART3_CR3_IREN             (0x1U<<1)
#define USART3_CR3_IRLP             (0x1U<<2)
#define USART3_CR3_HDSEL            (0x1U<<3)
#define USART3_CR3_NACK             (0x1U<<4)
#define USART3_CR3_SCEN             (0x1U<<5)
#define USART3_CR3_DMAR             (0x1U<<6)
#define USART3_CR3_DMAT             (0x1U<<7)
#define USART3_CR3_RTSE             (0x1U<<8)
#define USART3_CR3_CTSE             (0x1U<<9)
#define USART3_CR3_CTSIE            (0x1U<<10)
#define USART3_CR3_ONEBIT           (0x1U<<11)

// GTPR Configuration

#define USART3_GTPR_PSC             (0xFFU<<0)
#define USART3_GTPR_PSC_0           (0x1U<<0)
#define USART3_GTPR_GT              (0xFFU<<8)
#define USART3_GTPR_GT_0            (0x1U<<8)
