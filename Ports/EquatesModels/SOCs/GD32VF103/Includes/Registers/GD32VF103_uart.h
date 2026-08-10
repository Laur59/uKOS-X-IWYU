/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_uart equates.
 */

#pragma once

#include    <stdint.h>

// UART address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    STAT;
    volatile    uint32_t    DATA;
    volatile    uint32_t    BAUD;
    volatile    uint32_t    CTL0;
    volatile    uint32_t    CTL1;
    volatile    uint32_t    CTL2;
    volatile    uint32_t    GP;
} UART_TypeDef;

#ifdef __cplusplus
#define UART3   reinterpret_cast<UART_TypeDef *>(0x40004C00U)
#define UART4   reinterpret_cast<UART_TypeDef *>(0x40005000U)

#else
#define UART3   ((UART_TypeDef *)0x40004C00U)
#define UART4   ((UART_TypeDef *)0x40005000U)
#endif

// STAT Configuration

#define UART_STAT_PERR      (0x1U<<0U)
#define UART_STAT_FERR      (0x1U<<1U)
#define UART_STAT_NERR      (0x1U<<2U)
#define UART_STAT_ORERR     (0x1U<<3U)
#define UART_STAT_IDLEF     (0x1U<<4U)
#define UART_STAT_RBNE      (0x1U<<5U)
#define UART_STAT_TC        (0x1U<<6U)
#define UART_STAT_TBE       (0x1U<<7U)
#define UART_STAT_LBDF      (0x1U<<8U)

// DATA Configuration

#define UART_DATA_DATA      (0x1FFU<<0U)
#define UART_DATA_DATA_0    (0x1U<<0U)

// BAUD Configuration

#define UART_BAUD_FRADIV    (0xFU<<0U)
#define UART_BAUD_FRADIV_0  (0x1U<<0U)
#define UART_BAUD_INTDIV    (0xFFFU<<4U)
#define UART_BAUD_INTDIV_0  (0x1U<<4U)

// CTL0 Configuration

#define UART_CTL0_SBKCMD    (0x1U<<0U)
#define UART_CTL0_RWU       (0x1U<<1U)
#define UART_CTL0_REN       (0x1U<<2U)
#define UART_CTL0_TEN       (0x1U<<3U)
#define UART_CTL0_IDLEIE    (0x1U<<4U)
#define UART_CTL0_RBNEIE    (0x1U<<5U)
#define UART_CTL0_TCIE      (0x1U<<6U)
#define UART_CTL0_TBEIE     (0x1U<<7U)
#define UART_CTL0_PERRIE    (0x1U<<8U)
#define UART_CTL0_PM        (0x1U<<9U)
#define UART_CTL0_PCEN      (0x1U<<10U)
#define UART_CTL0_WM        (0x1U<<11U)
#define UART_CTL0_WL        (0x1U<<12U)
#define UART_CTL0_UEN       (0x1U<<13U)

// CTL1 Configuration

#define UART_CTL1_ADDR      (0xFU<<0U)
#define UART_CTL1_ADDR_0    (0x1U<<0U)
#define UART_CTL1_LBLEN     (0x1U<<5U)
#define UART_CTL1_LBDIE     (0x1U<<6U)
#define UART_CTL1_STB       (0x3U<<12U)
#define UART_CTL1_STB_0     (0x1U<<12U)
#define UART_CTL1_LMEN      (0x1U<<14U)

// CTL2 Configuration

#define UART_CTL2_ERRIE     (0x1U<<0U)
#define UART_CTL2_IREN      (0x1U<<1U)
#define UART_CTL2_IRLP      (0x1U<<2U)
#define UART_CTL2_HDEN      (0x1U<<3U)
#define UART_CTL2_DENR      (0x1U<<6U)
#define UART_CTL2_DENT      (0x1U<<7U)

// GP Configuration

#define UART_GP_PSC         (0xFFU<<0U)
#define UART_GP_PSC_0       (0x1U<<0U)
