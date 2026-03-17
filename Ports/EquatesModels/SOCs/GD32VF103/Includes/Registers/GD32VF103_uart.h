/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_uart.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_uart equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define UART_STAT_PERR      (0x1U<<0)
#define UART_STAT_FERR      (0x1U<<1)
#define UART_STAT_NERR      (0x1U<<2)
#define UART_STAT_ORERR     (0x1U<<3)
#define UART_STAT_IDLEF     (0x1U<<4)
#define UART_STAT_RBNE      (0x1U<<5)
#define UART_STAT_TC        (0x1U<<6)
#define UART_STAT_TBE       (0x1U<<7)
#define UART_STAT_LBDF      (0x1U<<8)

// DATA Configuration

#define UART_DATA_DATA      (0x1FFU<<0)
#define UART_DATA_DATA_0    (0x1U<<0)

// BAUD Configuration

#define UART_BAUD_FRADIV    (0xFU<<0)
#define UART_BAUD_FRADIV_0  (0x1U<<0)
#define UART_BAUD_INTDIV    (0xFFFU<<4)
#define UART_BAUD_INTDIV_0  (0x1U<<4)

// CTL0 Configuration

#define UART_CTL0_SBKCMD    (0x1U<<0)
#define UART_CTL0_RWU       (0x1U<<1)
#define UART_CTL0_REN       (0x1U<<2)
#define UART_CTL0_TEN       (0x1U<<3)
#define UART_CTL0_IDLEIE    (0x1U<<4)
#define UART_CTL0_RBNEIE    (0x1U<<5)
#define UART_CTL0_TCIE      (0x1U<<6)
#define UART_CTL0_TBEIE     (0x1U<<7)
#define UART_CTL0_PERRIE    (0x1U<<8)
#define UART_CTL0_PM        (0x1U<<9)
#define UART_CTL0_PCEN      (0x1U<<10)
#define UART_CTL0_WM        (0x1U<<11)
#define UART_CTL0_WL        (0x1U<<12)
#define UART_CTL0_UEN       (0x1U<<13)

// CTL1 Configuration

#define UART_CTL1_ADDR      (0xFU<<0)
#define UART_CTL1_ADDR_0    (0x1U<<0)
#define UART_CTL1_LBLEN     (0x1U<<5)
#define UART_CTL1_LBDIE     (0x1U<<6)
#define UART_CTL1_STB       (0x3U<<12)
#define UART_CTL1_STB_0     (0x1U<<12)
#define UART_CTL1_LMEN      (0x1U<<14)

// CTL2 Configuration

#define UART_CTL2_ERRIE     (0x1U<<0)
#define UART_CTL2_IREN      (0x1U<<1)
#define UART_CTL2_IRLP      (0x1U<<2)
#define UART_CTL2_HDEN      (0x1U<<3)
#define UART_CTL2_DENR      (0x1U<<6)
#define UART_CTL2_DENT      (0x1U<<7)

// GP Configuration

#define UART_GP_PSC         (0xFFU<<0)
#define UART_GP_PSC_0       (0x1U<<0)
