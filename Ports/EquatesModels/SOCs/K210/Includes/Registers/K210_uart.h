/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; K210_uart.
; ==========

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;   K210_uart equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// UART FCR Register
// -----------------

#define UART_FCR_SEND_FIFO_0        (0U<<4)         //
#define UART_FCR_SEND_FIFO_2        (1U<<4)         //
#define UART_FCR_SEND_FIFO_4        (2U<<4)         //
#define UART_FCR_SEND_FIFO_8        (3U<<4)         //

#define UART_FCR_RECEIVE_FIFO_1     (0U<<6)         //
#define UART_FCR_RECEIVE_FIFO_4     (1U<<6)         //
#define UART_FCR_RECEIVE_FIFO_8     (2U<<6)         //
#define UART_FCR_RECEIVE_FIFO_14    (3U<<6)         //

// UART LCR Register
// -----------------

#define UART_LCR_NBBITSMSK          (3U<<0)         //
#define UART_LCR_NBBIT8             (3U<<0)         //
#define UART_LCR_NBBIT7             (2U<<0)         //

#define UART_LCR_STBITSMSK          (1U<<2)         //
#define UART_LCR_STBIT1             (0U<<2)         //
#define UART_LCR_STBIT15            (1U<<2)         //

#define UART_LCR_PARITYSMSK         (3U<<3)         //
#define UART_LCR_PARITYNONE         (0U<<3)         //
#define UART_LCR_PARITYODD          (1U<<3)         //
#define UART_LCR_PARITYEVEN         (3U<<3)         //

// UART LSR Register
// -----------------

#define UART_LSR_DATAREADY          (1U<<0)         //
#define UART_LSR_TEMT               (1U<<5)         //

// UART IER Register
// -----------------

#define UART_IER_ERBFI              (1U<<0)         //
#define UART_IER_ETBEI              (1U<<1)         //

// UART IIR Register
// -----------------

#define UART_IIR_ERBFI              (1U<<2)         //
#define UART_IIR_ETBEI              (1U<<1)         //

// The UART address map
// --------------------

typedef struct  _uart {
    union {
        volatile    uint32_t    RBR;                //
        volatile    uint32_t    DLL;                //
        volatile    uint32_t    THR;                //
    };
    union {
        volatile    uint32_t    DLH;                //
        volatile    uint32_t    IER;                //
    };
    union {
        volatile    uint32_t    FCR;                //
        volatile    uint32_t    IIR;                //
    };
    volatile    uint32_t    LCR;                    //
    volatile    uint32_t    MCR;                    //
    volatile    uint32_t    LSR;                    //
    volatile    uint32_t    MSR;                    //
    volatile    uint32_t    SCR;                    //
    volatile    uint32_t    LPDLL;                  //
    volatile    uint32_t    LPDLH;                  //
    volatile    uint32_t    reserved1[2];           //
    union {
        volatile    uint32_t    SRBR[16];           //
        volatile    uint32_t    STHR[16];           //
    };
    volatile    uint32_t    FAR;                    //
    volatile    uint32_t    TFR;                    //
    volatile    uint32_t    RFW;                    //
    volatile    uint32_t    USR;                    //
    volatile    uint32_t    TFL;                    //
    volatile    uint32_t    RFL;                    //
    volatile    uint32_t    SRR;                    //
    volatile    uint32_t    SRTS;                   //
    volatile    uint32_t    SBCR;                   //
    volatile    uint32_t    SDMAM;                  //
    volatile    uint32_t    SFE;                    //
    volatile    uint32_t    SRT;                    //
    volatile    uint32_t    STET;                   //
    volatile    uint32_t    HTX;                    //
    volatile    uint32_t    DMASA;                  //
    volatile    uint32_t    TCR;                    //
    volatile    uint32_t    DE_EN;                  //
    volatile    uint32_t    RE_EN;                  //
    volatile    uint32_t    DET;                    //
    volatile    uint32_t    TAT;                    //
    volatile    uint32_t    DLF;                    //
    volatile    uint32_t    RAR;                    //
    volatile    uint32_t    TAR;                    //
    volatile    uint32_t    LCR_EXT;                //
    volatile    uint32_t    reserved2[9];           //
    volatile    uint32_t    CPR;                    //
    volatile    uint32_t    UCV;                    //
    volatile    uint32_t    CTR;                    //
} uart_t;

#define uart1   ((volatile  uart_t *)0x50210000U)
#define uart2   ((volatile  uart_t *)0x50220000U)
#define uart3   ((volatile  uart_t *)0x50230000U)
