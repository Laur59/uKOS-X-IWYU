/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_usart.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_usart equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// USART address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    STAT;
    volatile    uint32_t    DATA;
    volatile    uint32_t    BAUD;
    volatile    uint32_t    CTL0;
    volatile    uint32_t    CTL1;
    volatile    uint32_t    CTL2;
    volatile    uint32_t    GP;
} USART_TypeDef;

#ifdef __cplusplus
#define USART0  reinterpret_cast<USART_TypeDef *>(0x40013800U)
#define USART1  reinterpret_cast<USART_TypeDef *>(0x40004400U)
#define USART2  reinterpret_cast<USART_TypeDef *>(0x40004800U)

#else
#define USART0  ((USART_TypeDef *)0x40013800U)
#define USART1  ((USART_TypeDef *)0x40004400U)
#define USART2  ((USART_TypeDef *)0x40004800U)
#endif

// STAT Configuration

#define USART_STAT_PERR     (0x1U<<0)
#define USART_STAT_FERR     (0x1U<<1)
#define USART_STAT_NERR     (0x1U<<2)
#define USART_STAT_ORERR    (0x1U<<3)
#define USART_STAT_IDLEF    (0x1U<<4)
#define USART_STAT_RBNE     (0x1U<<5)
#define USART_STAT_TC       (0x1U<<6)
#define USART_STAT_TBE      (0x1U<<7)
#define USART_STAT_LBDF     (0x1U<<8)
#define USART_STAT_CTSF     (0x1U<<9)

// DATA Configuration

#define USART_DATA_DATA     (0x1FFU<<0)
#define USART_DATA_DATA_0   (0x1U<<0)

// BAUD Configuration

#define USART_BAUD_FRADIV   (0xFU<<0)
#define USART_BAUD_FRADIV_0 (0x1U<<0)
#define USART_BAUD_INTDIV   (0xFFFU<<4)
#define USART_BAUD_INTDIV_0 (0x1U<<4)

// CTL0 Configuration

#define USART_CTL0_SBKCMD   (0x1U<<0)
#define USART_CTL0_RWU      (0x1U<<1)
#define USART_CTL0_REN      (0x1U<<2)
#define USART_CTL0_TEN      (0x1U<<3)
#define USART_CTL0_IDLEIE   (0x1U<<4)
#define USART_CTL0_RBNEIE   (0x1U<<5)
#define USART_CTL0_TCIE     (0x1U<<6)
#define USART_CTL0_TBEIE    (0x1U<<7)
#define USART_CTL0_PERRIE   (0x1U<<8)
#define USART_CTL0_PM       (0x1U<<9)
#define USART_CTL0_PCEN     (0x1U<<10)
#define USART_CTL0_WM       (0x1U<<11)
#define USART_CTL0_WL       (0x1U<<12)
#define USART_CTL0_UEN      (0x1U<<13)

// CTL1 Configuration

#define USART_CTL1_ADDR     (0xFU<<0)
#define USART_CTL1_ADDR_0   (0x1U<<0)
#define USART_CTL1_LBLEN    (0x1U<<5)
#define USART_CTL1_LBDIE    (0x1U<<6)
#define USART_CTL1_CLEN     (0x1U<<8)
#define USART_CTL1_CPH      (0x1U<<9)
#define USART_CTL1_CPL      (0x1U<<10)
#define USART_CTL1_CKEN     (0x1U<<11)
#define USART_CTL1_STB      (0x3U<<12)
#define USART_CTL1_STB_0    (0x1U<<12)
#define USART_CTL1_LMEN     (0x1U<<14)

// CTL2 Configuration

#define USART_CTL2_ERRIE    (0x1U<<0)
#define USART_CTL2_IREN     (0x1U<<1)
#define USART_CTL2_IRLP     (0x1U<<2)
#define USART_CTL2_HDEN     (0x1U<<3)
#define USART_CTL2_NKEN     (0x1U<<4)
#define USART_CTL2_SCEN     (0x1U<<5)
#define USART_CTL2_DENR     (0x1U<<6)
#define USART_CTL2_DENT     (0x1U<<7)
#define USART_CTL2_RTSEN    (0x1U<<8)
#define USART_CTL2_CTSEN    (0x1U<<9)
#define USART_CTL2_CTSIE    (0x1U<<10)

// GP Configuration

#define USART_GP_PSC        (0xFFU<<0)
#define USART_GP_PSC_0      (0x1U<<0)
#define USART_GP_GUAT       (0xFFU<<8)
#define USART_GP_GUAT_0     (0x1U<<8)
