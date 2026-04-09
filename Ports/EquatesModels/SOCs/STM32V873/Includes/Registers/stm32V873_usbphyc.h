/*
; stm32V873_usbphyc.
; ==================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32V873_usbphyc equates.
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

// USBPHYC address definitions
// ---------------------------

typedef struct {
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    TXTRIM1;
    volatile    uint32_t    TXTRIM2;
    volatile    uint32_t    RESERVED1[9];
    volatile    uint32_t    TXTRIM3;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    RXTRIM;
    volatile    uint32_t    RESERVED3[168];
    volatile    uint32_t    HSZTRIM;
    volatile    uint32_t    FSZTRIM;
} USBPHYC_TypeDef;

#if (defined(__cplusplus))
#define USBPHYC_NS  reinterpret_cast<USBPHYC_TypeDef *>(0x480C0000u)
#define USBPHYC_S   reinterpret_cast<USBPHYC_TypeDef *>(0x580C0000u)

#else
#define USBPHYC_NS  ((USBPHYC_TypeDef *)0x480C0000u)
#define USBPHYC_S   ((USBPHYC_TypeDef *)0x580C0000u)
#endif

// TXTRIM1 Configuration

#define USBPHYC_TXTRIM1_IBOOSTCURR              (0x1u<<7)
#define USBPHYC_TXTRIM1_IBOOSTVAL               (0x3Fu<<1)
#define USBPHYC_TXTRIM1_IBOOSTVAL_0             (0x1u<<1)
#define USBPHYC_TXTRIM1_IBOOSTMODE              (0x1u<<0)

#define USBPHYC_TXTRIM1_IBOOSTCURR_B_0X0        (0x0u<<7)
#define USBPHYC_TXTRIM1_IBOOSTCURR_B_0X1        (0x1u<<7)
#define USBPHYC_TXTRIM1_IBOOSTVAL_B_0X0         (0x0u<<1)
#define USBPHYC_TXTRIM1_IBOOSTVAL_B_0X3F        (0x3Fu<<1)
#define USBPHYC_TXTRIM1_IBOOSTMODE_B_0X0        (0x0u<<0)
#define USBPHYC_TXTRIM1_IBOOSTMODE_B_0X1        (0x1u<<0)

// TXTRIM2 Configuration

#define USBPHYC_TXTRIM2_DEVHOSTCHIRP            (0x1u<<7)
#define USBPHYC_TXTRIM2_HOSTDEVTEST             (0x1u<<6)
#define USBPHYC_TXTRIM2_DEEMPVAL                (0x1Fu<<1)
#define USBPHYC_TXTRIM2_DEEMPVAL_0              (0x1u<<1)
#define USBPHYC_TXTRIM2_DEEMPMODE               (0x1u<<0)

#define USBPHYC_TXTRIM2_DEVHOSTCHIRP_B_0X0      (0x0u<<7)
#define USBPHYC_TXTRIM2_DEVHOSTCHIRP_B_0X1      (0x1u<<7)
#define USBPHYC_TXTRIM2_HOSTDEVTEST_B_0X0       (0x0u<<6)
#define USBPHYC_TXTRIM2_HOSTDEVTEST_B_0X1       (0x1u<<6)
#define USBPHYC_TXTRIM2_DEEMPVAL_B_0X0          (0x0u<<1)
#define USBPHYC_TXTRIM2_DEEMPVAL_B_0XF          (0xFu<<1)
#define USBPHYC_TXTRIM2_DEEMPVAL_B_0X10         (0x10u<<1)
#define USBPHYC_TXTRIM2_DEEMPVAL_B_0X1F         (0x1Fu<<1)
#define USBPHYC_TXTRIM2_DEEMPMODE_B_0X0         (0x0u<<0)
#define USBPHYC_TXTRIM2_DEEMPMODE_B_0X1         (0x1u<<0)

// TXTRIM3 Configuration

#define USBPHYC_TXTRIM3_CURRADD                 (0x3u<<0)
#define USBPHYC_TXTRIM3_CURRADD_0               (0x1u<<0)

#define USBPHYC_TXTRIM3_CURRADD_B_0X0           (0x0u<<0)
#define USBPHYC_TXTRIM3_CURRADD_B_0X1           (0x1u<<0)
#define USBPHYC_TXTRIM3_CURRADD_B_0X2           (0x2u<<0)
#define USBPHYC_TXTRIM3_CURRADD_B_0X3           (0x3u<<0)

// RXTRIM Configuration

#define USBPHYC_RXTRIM_HSRXSQADD2               (0x1u<<6)
#define USBPHYC_RXTRIM_HSRXSQADD1               (0x1u<<5)
#define USBPHYC_RXTRIM_HSRXSQADD0               (0x1u<<4)
#define USBPHYC_RXTRIM_HSRXSQSUB2               (0x1u<<2)
#define USBPHYC_RXTRIM_HSRXSQSUB1               (0x1u<<1)
#define USBPHYC_RXTRIM_HSRXSQSUB0               (0x1u<<0)

#define USBPHYC_RXTRIM_HSRXSQADD2_B_0X0         (0x0u<<6)
#define USBPHYC_RXTRIM_HSRXSQADD2_B_0X1         (0x1u<<6)
#define USBPHYC_RXTRIM_HSRXSQADD1_B_0X0         (0x0u<<5)
#define USBPHYC_RXTRIM_HSRXSQADD1_B_0X1         (0x1u<<5)
#define USBPHYC_RXTRIM_HSRXSQADD0_B_0X0         (0x0u<<4)
#define USBPHYC_RXTRIM_HSRXSQADD0_B_0X1         (0x1u<<4)
#define USBPHYC_RXTRIM_HSRXSQSUB2_B_0X0         (0x0u<<2)
#define USBPHYC_RXTRIM_HSRXSQSUB2_B_0X1         (0x1u<<2)
#define USBPHYC_RXTRIM_HSRXSQSUB1_B_0X0         (0x0u<<1)
#define USBPHYC_RXTRIM_HSRXSQSUB1_B_0X1         (0x1u<<1)
#define USBPHYC_RXTRIM_HSRXSQSUB0_B_0X0         (0x0u<<0)
#define USBPHYC_RXTRIM_HSRXSQSUB0_B_0X1         (0x1u<<0)

// HSZTRIM Configuration

#define USBPHYC_HSZTRIM_HSZTRMOFFVAL            (0x1Fu<<2)
#define USBPHYC_HSZTRIM_HSZTRMOFFVAL_0          (0x1u<<2)
#define USBPHYC_HSZTRIM_HSZTRMADDSUB            (0x1u<<1)
#define USBPHYC_HSZTRIM_HSZTRMEN                (0x1u<<0)

#define USBPHYC_HSZTRIM_HSZTRMOFFVAL_B_0X0      (0x0u<<2)
#define USBPHYC_HSZTRIM_HSZTRMOFFVAL_B_0X1F     (0x1Fu<<2)
#define USBPHYC_HSZTRIM_HSZTRMADDSUB_B_0X0      (0x0u<<1)
#define USBPHYC_HSZTRIM_HSZTRMADDSUB_B_0X1      (0x1u<<1)
#define USBPHYC_HSZTRIM_HSZTRMEN_B_0X0          (0x0u<<0)
#define USBPHYC_HSZTRIM_HSZTRMEN_B_0X1          (0x1u<<0)

// FSZTRIM Configuration

#define USBPHYC_FSZTRIM_FSZTRMOFFVAL            (0x1Fu<<2)
#define USBPHYC_FSZTRIM_FSZTRMOFFVAL_0          (0x1u<<2)
#define USBPHYC_FSZTRIM_FSZTRMADDSUB            (0x1u<<1)
#define USBPHYC_FSZTRIM_FSZTRMEN                (0x1u<<0)

#define USBPHYC_FSZTRIM_FSZTRMOFFVAL_B_0X0      (0x0u<<2)
#define USBPHYC_FSZTRIM_FSZTRMOFFVAL_B_0X1F     (0x1Fu<<2)
#define USBPHYC_FSZTRIM_FSZTRMADDSUB_B_0X0      (0x0u<<1)
#define USBPHYC_FSZTRIM_FSZTRMADDSUB_B_0X1      (0x1u<<1)
#define USBPHYC_FSZTRIM_FSZTRMEN_B_0X0          (0x0u<<0)
#define USBPHYC_FSZTRIM_FSZTRMEN_B_0X1          (0x1u<<0)
