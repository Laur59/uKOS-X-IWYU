/*
; stm32V873_hsem.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32V873_hsem equates.
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

// HSEM address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    R0;
    volatile    uint32_t    R1;
    volatile    uint32_t    R2;
    volatile    uint32_t    R3;
    volatile    uint32_t    R4;
    volatile    uint32_t    R5;
    volatile    uint32_t    R6;
    volatile    uint32_t    R7;
    volatile    uint32_t    R8;
    volatile    uint32_t    R9;
    volatile    uint32_t    R10;
    volatile    uint32_t    R11;
    volatile    uint32_t    R12;
    volatile    uint32_t    R13;
    volatile    uint32_t    R14;
    volatile    uint32_t    R15;
    volatile    uint32_t    R16;
    volatile    uint32_t    R17;
    volatile    uint32_t    R18;
    volatile    uint32_t    R19;
    volatile    uint32_t    R20;
    volatile    uint32_t    R21;
    volatile    uint32_t    R22;
    volatile    uint32_t    R23;
    volatile    uint32_t    R24;
    volatile    uint32_t    R25;
    volatile    uint32_t    R26;
    volatile    uint32_t    R27;
    volatile    uint32_t    R28;
    volatile    uint32_t    R29;
    volatile    uint32_t    R30;
    volatile    uint32_t    R31;
    volatile    uint32_t    RLR0;
    volatile    uint32_t    RLR1;
    volatile    uint32_t    RLR2;
    volatile    uint32_t    RLR3;
    volatile    uint32_t    RLR4;
    volatile    uint32_t    RLR5;
    volatile    uint32_t    RLR6;
    volatile    uint32_t    RLR7;
    volatile    uint32_t    RLR8;
    volatile    uint32_t    RLR9;
    volatile    uint32_t    RLR10;
    volatile    uint32_t    RLR11;
    volatile    uint32_t    RLR12;
    volatile    uint32_t    RLR13;
    volatile    uint32_t    RLR14;
    volatile    uint32_t    RLR15;
    volatile    uint32_t    RLR16;
    volatile    uint32_t    RLR17;
    volatile    uint32_t    RLR18;
    volatile    uint32_t    RLR19;
    volatile    uint32_t    RLR20;
    volatile    uint32_t    RLR21;
    volatile    uint32_t    RLR22;
    volatile    uint32_t    RLR23;
    volatile    uint32_t    RLR24;
    volatile    uint32_t    RLR25;
    volatile    uint32_t    RLR26;
    volatile    uint32_t    RLR27;
    volatile    uint32_t    RLR28;
    volatile    uint32_t    RLR29;
    volatile    uint32_t    RLR30;
    volatile    uint32_t    RLR31;
    volatile    uint32_t    IER;
    volatile    uint32_t    ICR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    MISR;
    volatile    uint32_t    RESERVED0[28];
    volatile    uint32_t    SIER;
    volatile    uint32_t    SICR;
    volatile    uint32_t    SISR;
    volatile    uint32_t    MSISR;
    volatile    uint32_t    RESERVED1[28];
    volatile    uint32_t    SECCFGR;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    PRIVCFGR;
    volatile    uint32_t    RESERVED3[7];
    volatile    uint32_t    CR;
    volatile    uint32_t    KEYR;
} HSEM_TypeDef;

#if (defined(__cplusplus))
#define HSEM_NS     reinterpret_cast<HSEM_TypeDef *>(0x46026400u)
#define HSEM_S      reinterpret_cast<HSEM_TypeDef *>(0x56026400u)

#else
#define HSEM_NS     ((HSEM_TypeDef *)0x46026400u)
#define HSEM_S      ((HSEM_TypeDef *)0x56026400u)
#endif

// R0 Configuration

#define HSEM_R0_LOCK                (0x1u<<31)
#define HSEM_R0_PRIV                (0x1u<<13)
#define HSEM_R0_SEC                 (0x1u<<12)
#define HSEM_R0_LOCKID              (0xFu<<8)
#define HSEM_R0_LOCKID_0            (0x1u<<8)
#define HSEM_R0_PROCID              (0xFFu<<0)
#define HSEM_R0_PROCID_0            (0x1u<<0)

#define HSEM_R0_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R0_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R0_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R0_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R0_SEC_B_0X0           (0x0u<<12)
#define HSEM_R0_SEC_B_0X1           (0x1u<<12)

// R1 Configuration

#define HSEM_R1_LOCK                (0x1u<<31)
#define HSEM_R1_PRIV                (0x1u<<13)
#define HSEM_R1_SEC                 (0x1u<<12)
#define HSEM_R1_LOCKID              (0xFu<<8)
#define HSEM_R1_LOCKID_0            (0x1u<<8)
#define HSEM_R1_PROCID              (0xFFu<<0)
#define HSEM_R1_PROCID_0            (0x1u<<0)

#define HSEM_R1_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R1_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R1_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R1_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R1_SEC_B_0X0           (0x0u<<12)
#define HSEM_R1_SEC_B_0X1           (0x1u<<12)

// R2 Configuration

#define HSEM_R2_LOCK                (0x1u<<31)
#define HSEM_R2_PRIV                (0x1u<<13)
#define HSEM_R2_SEC                 (0x1u<<12)
#define HSEM_R2_LOCKID              (0xFu<<8)
#define HSEM_R2_LOCKID_0            (0x1u<<8)
#define HSEM_R2_PROCID              (0xFFu<<0)
#define HSEM_R2_PROCID_0            (0x1u<<0)

#define HSEM_R2_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R2_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R2_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R2_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R2_SEC_B_0X0           (0x0u<<12)
#define HSEM_R2_SEC_B_0X1           (0x1u<<12)

// R3 Configuration

#define HSEM_R3_LOCK                (0x1u<<31)
#define HSEM_R3_PRIV                (0x1u<<13)
#define HSEM_R3_SEC                 (0x1u<<12)
#define HSEM_R3_LOCKID              (0xFu<<8)
#define HSEM_R3_LOCKID_0            (0x1u<<8)
#define HSEM_R3_PROCID              (0xFFu<<0)
#define HSEM_R3_PROCID_0            (0x1u<<0)

#define HSEM_R3_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R3_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R3_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R3_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R3_SEC_B_0X0           (0x0u<<12)
#define HSEM_R3_SEC_B_0X1           (0x1u<<12)

// R4 Configuration

#define HSEM_R4_LOCK                (0x1u<<31)
#define HSEM_R4_PRIV                (0x1u<<13)
#define HSEM_R4_SEC                 (0x1u<<12)
#define HSEM_R4_LOCKID              (0xFu<<8)
#define HSEM_R4_LOCKID_0            (0x1u<<8)
#define HSEM_R4_PROCID              (0xFFu<<0)
#define HSEM_R4_PROCID_0            (0x1u<<0)

#define HSEM_R4_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R4_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R4_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R4_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R4_SEC_B_0X0           (0x0u<<12)
#define HSEM_R4_SEC_B_0X1           (0x1u<<12)

// R5 Configuration

#define HSEM_R5_LOCK                (0x1u<<31)
#define HSEM_R5_PRIV                (0x1u<<13)
#define HSEM_R5_SEC                 (0x1u<<12)
#define HSEM_R5_LOCKID              (0xFu<<8)
#define HSEM_R5_LOCKID_0            (0x1u<<8)
#define HSEM_R5_PROCID              (0xFFu<<0)
#define HSEM_R5_PROCID_0            (0x1u<<0)

#define HSEM_R5_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R5_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R5_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R5_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R5_SEC_B_0X0           (0x0u<<12)
#define HSEM_R5_SEC_B_0X1           (0x1u<<12)

// R6 Configuration

#define HSEM_R6_LOCK                (0x1u<<31)
#define HSEM_R6_PRIV                (0x1u<<13)
#define HSEM_R6_SEC                 (0x1u<<12)
#define HSEM_R6_LOCKID              (0xFu<<8)
#define HSEM_R6_LOCKID_0            (0x1u<<8)
#define HSEM_R6_PROCID              (0xFFu<<0)
#define HSEM_R6_PROCID_0            (0x1u<<0)

#define HSEM_R6_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R6_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R6_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R6_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R6_SEC_B_0X0           (0x0u<<12)
#define HSEM_R6_SEC_B_0X1           (0x1u<<12)

// R7 Configuration

#define HSEM_R7_LOCK                (0x1u<<31)
#define HSEM_R7_PRIV                (0x1u<<13)
#define HSEM_R7_SEC                 (0x1u<<12)
#define HSEM_R7_LOCKID              (0xFu<<8)
#define HSEM_R7_LOCKID_0            (0x1u<<8)
#define HSEM_R7_PROCID              (0xFFu<<0)
#define HSEM_R7_PROCID_0            (0x1u<<0)

#define HSEM_R7_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R7_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R7_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R7_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R7_SEC_B_0X0           (0x0u<<12)
#define HSEM_R7_SEC_B_0X1           (0x1u<<12)

// R8 Configuration

#define HSEM_R8_LOCK                (0x1u<<31)
#define HSEM_R8_PRIV                (0x1u<<13)
#define HSEM_R8_SEC                 (0x1u<<12)
#define HSEM_R8_LOCKID              (0xFu<<8)
#define HSEM_R8_LOCKID_0            (0x1u<<8)
#define HSEM_R8_PROCID              (0xFFu<<0)
#define HSEM_R8_PROCID_0            (0x1u<<0)

#define HSEM_R8_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R8_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R8_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R8_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R8_SEC_B_0X0           (0x0u<<12)
#define HSEM_R8_SEC_B_0X1           (0x1u<<12)

// R9 Configuration

#define HSEM_R9_LOCK                (0x1u<<31)
#define HSEM_R9_PRIV                (0x1u<<13)
#define HSEM_R9_SEC                 (0x1u<<12)
#define HSEM_R9_LOCKID              (0xFu<<8)
#define HSEM_R9_LOCKID_0            (0x1u<<8)
#define HSEM_R9_PROCID              (0xFFu<<0)
#define HSEM_R9_PROCID_0            (0x1u<<0)

#define HSEM_R9_LOCK_B_0X0          (0x0u<<31)
#define HSEM_R9_LOCK_B_0X1          (0x1u<<31)
#define HSEM_R9_PRIV_B_0X0          (0x0u<<13)
#define HSEM_R9_PRIV_B_0X1          (0x1u<<13)
#define HSEM_R9_SEC_B_0X0           (0x0u<<12)
#define HSEM_R9_SEC_B_0X1           (0x1u<<12)

// R10 Configuration

#define HSEM_R10_LOCK               (0x1u<<31)
#define HSEM_R10_PRIV               (0x1u<<13)
#define HSEM_R10_SEC                (0x1u<<12)
#define HSEM_R10_LOCKID             (0xFu<<8)
#define HSEM_R10_LOCKID_0           (0x1u<<8)
#define HSEM_R10_PROCID             (0xFFu<<0)
#define HSEM_R10_PROCID_0           (0x1u<<0)

#define HSEM_R10_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R10_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R10_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R10_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R10_SEC_B_0X0          (0x0u<<12)
#define HSEM_R10_SEC_B_0X1          (0x1u<<12)

// R11 Configuration

#define HSEM_R11_LOCK               (0x1u<<31)
#define HSEM_R11_PRIV               (0x1u<<13)
#define HSEM_R11_SEC                (0x1u<<12)
#define HSEM_R11_LOCKID             (0xFu<<8)
#define HSEM_R11_LOCKID_0           (0x1u<<8)
#define HSEM_R11_PROCID             (0xFFu<<0)
#define HSEM_R11_PROCID_0           (0x1u<<0)

#define HSEM_R11_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R11_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R11_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R11_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R11_SEC_B_0X0          (0x0u<<12)
#define HSEM_R11_SEC_B_0X1          (0x1u<<12)

// R12 Configuration

#define HSEM_R12_LOCK               (0x1u<<31)
#define HSEM_R12_PRIV               (0x1u<<13)
#define HSEM_R12_SEC                (0x1u<<12)
#define HSEM_R12_LOCKID             (0xFu<<8)
#define HSEM_R12_LOCKID_0           (0x1u<<8)
#define HSEM_R12_PROCID             (0xFFu<<0)
#define HSEM_R12_PROCID_0           (0x1u<<0)

#define HSEM_R12_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R12_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R12_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R12_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R12_SEC_B_0X0          (0x0u<<12)
#define HSEM_R12_SEC_B_0X1          (0x1u<<12)

// R13 Configuration

#define HSEM_R13_LOCK               (0x1u<<31)
#define HSEM_R13_PRIV               (0x1u<<13)
#define HSEM_R13_SEC                (0x1u<<12)
#define HSEM_R13_LOCKID             (0xFu<<8)
#define HSEM_R13_LOCKID_0           (0x1u<<8)
#define HSEM_R13_PROCID             (0xFFu<<0)
#define HSEM_R13_PROCID_0           (0x1u<<0)

#define HSEM_R13_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R13_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R13_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R13_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R13_SEC_B_0X0          (0x0u<<12)
#define HSEM_R13_SEC_B_0X1          (0x1u<<12)

// R14 Configuration

#define HSEM_R14_LOCK               (0x1u<<31)
#define HSEM_R14_PRIV               (0x1u<<13)
#define HSEM_R14_SEC                (0x1u<<12)
#define HSEM_R14_LOCKID             (0xFu<<8)
#define HSEM_R14_LOCKID_0           (0x1u<<8)
#define HSEM_R14_PROCID             (0xFFu<<0)
#define HSEM_R14_PROCID_0           (0x1u<<0)

#define HSEM_R14_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R14_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R14_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R14_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R14_SEC_B_0X0          (0x0u<<12)
#define HSEM_R14_SEC_B_0X1          (0x1u<<12)

// R15 Configuration

#define HSEM_R15_LOCK               (0x1u<<31)
#define HSEM_R15_PRIV               (0x1u<<13)
#define HSEM_R15_SEC                (0x1u<<12)
#define HSEM_R15_LOCKID             (0xFu<<8)
#define HSEM_R15_LOCKID_0           (0x1u<<8)
#define HSEM_R15_PROCID             (0xFFu<<0)
#define HSEM_R15_PROCID_0           (0x1u<<0)

#define HSEM_R15_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R15_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R15_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R15_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R15_SEC_B_0X0          (0x0u<<12)
#define HSEM_R15_SEC_B_0X1          (0x1u<<12)

// R16 Configuration

#define HSEM_R16_LOCK               (0x1u<<31)
#define HSEM_R16_PRIV               (0x1u<<13)
#define HSEM_R16_SEC                (0x1u<<12)
#define HSEM_R16_LOCKID             (0xFu<<8)
#define HSEM_R16_LOCKID_0           (0x1u<<8)
#define HSEM_R16_PROCID             (0xFFu<<0)
#define HSEM_R16_PROCID_0           (0x1u<<0)

#define HSEM_R16_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R16_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R16_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R16_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R16_SEC_B_0X0          (0x0u<<12)
#define HSEM_R16_SEC_B_0X1          (0x1u<<12)

// R17 Configuration

#define HSEM_R17_LOCK               (0x1u<<31)
#define HSEM_R17_PRIV               (0x1u<<13)
#define HSEM_R17_SEC                (0x1u<<12)
#define HSEM_R17_LOCKID             (0xFu<<8)
#define HSEM_R17_LOCKID_0           (0x1u<<8)
#define HSEM_R17_PROCID             (0xFFu<<0)
#define HSEM_R17_PROCID_0           (0x1u<<0)

#define HSEM_R17_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R17_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R17_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R17_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R17_SEC_B_0X0          (0x0u<<12)
#define HSEM_R17_SEC_B_0X1          (0x1u<<12)

// R18 Configuration

#define HSEM_R18_LOCK               (0x1u<<31)
#define HSEM_R18_PRIV               (0x1u<<13)
#define HSEM_R18_SEC                (0x1u<<12)
#define HSEM_R18_LOCKID             (0xFu<<8)
#define HSEM_R18_LOCKID_0           (0x1u<<8)
#define HSEM_R18_PROCID             (0xFFu<<0)
#define HSEM_R18_PROCID_0           (0x1u<<0)

#define HSEM_R18_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R18_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R18_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R18_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R18_SEC_B_0X0          (0x0u<<12)
#define HSEM_R18_SEC_B_0X1          (0x1u<<12)

// R19 Configuration

#define HSEM_R19_LOCK               (0x1u<<31)
#define HSEM_R19_PRIV               (0x1u<<13)
#define HSEM_R19_SEC                (0x1u<<12)
#define HSEM_R19_LOCKID             (0xFu<<8)
#define HSEM_R19_LOCKID_0           (0x1u<<8)
#define HSEM_R19_PROCID             (0xFFu<<0)
#define HSEM_R19_PROCID_0           (0x1u<<0)

#define HSEM_R19_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R19_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R19_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R19_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R19_SEC_B_0X0          (0x0u<<12)
#define HSEM_R19_SEC_B_0X1          (0x1u<<12)

// R20 Configuration

#define HSEM_R20_LOCK               (0x1u<<31)
#define HSEM_R20_PRIV               (0x1u<<13)
#define HSEM_R20_SEC                (0x1u<<12)
#define HSEM_R20_LOCKID             (0xFu<<8)
#define HSEM_R20_LOCKID_0           (0x1u<<8)
#define HSEM_R20_PROCID             (0xFFu<<0)
#define HSEM_R20_PROCID_0           (0x1u<<0)

#define HSEM_R20_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R20_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R20_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R20_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R20_SEC_B_0X0          (0x0u<<12)
#define HSEM_R20_SEC_B_0X1          (0x1u<<12)

// R21 Configuration

#define HSEM_R21_LOCK               (0x1u<<31)
#define HSEM_R21_PRIV               (0x1u<<13)
#define HSEM_R21_SEC                (0x1u<<12)
#define HSEM_R21_LOCKID             (0xFu<<8)
#define HSEM_R21_LOCKID_0           (0x1u<<8)
#define HSEM_R21_PROCID             (0xFFu<<0)
#define HSEM_R21_PROCID_0           (0x1u<<0)

#define HSEM_R21_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R21_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R21_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R21_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R21_SEC_B_0X0          (0x0u<<12)
#define HSEM_R21_SEC_B_0X1          (0x1u<<12)

// R22 Configuration

#define HSEM_R22_LOCK               (0x1u<<31)
#define HSEM_R22_PRIV               (0x1u<<13)
#define HSEM_R22_SEC                (0x1u<<12)
#define HSEM_R22_LOCKID             (0xFu<<8)
#define HSEM_R22_LOCKID_0           (0x1u<<8)
#define HSEM_R22_PROCID             (0xFFu<<0)
#define HSEM_R22_PROCID_0           (0x1u<<0)

#define HSEM_R22_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R22_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R22_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R22_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R22_SEC_B_0X0          (0x0u<<12)
#define HSEM_R22_SEC_B_0X1          (0x1u<<12)

// R23 Configuration

#define HSEM_R23_LOCK               (0x1u<<31)
#define HSEM_R23_PRIV               (0x1u<<13)
#define HSEM_R23_SEC                (0x1u<<12)
#define HSEM_R23_LOCKID             (0xFu<<8)
#define HSEM_R23_LOCKID_0           (0x1u<<8)
#define HSEM_R23_PROCID             (0xFFu<<0)
#define HSEM_R23_PROCID_0           (0x1u<<0)

#define HSEM_R23_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R23_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R23_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R23_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R23_SEC_B_0X0          (0x0u<<12)
#define HSEM_R23_SEC_B_0X1          (0x1u<<12)

// R24 Configuration

#define HSEM_R24_LOCK               (0x1u<<31)
#define HSEM_R24_PRIV               (0x1u<<13)
#define HSEM_R24_SEC                (0x1u<<12)
#define HSEM_R24_LOCKID             (0xFu<<8)
#define HSEM_R24_LOCKID_0           (0x1u<<8)
#define HSEM_R24_PROCID             (0xFFu<<0)
#define HSEM_R24_PROCID_0           (0x1u<<0)

#define HSEM_R24_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R24_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R24_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R24_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R24_SEC_B_0X0          (0x0u<<12)
#define HSEM_R24_SEC_B_0X1          (0x1u<<12)

// R25 Configuration

#define HSEM_R25_LOCK               (0x1u<<31)
#define HSEM_R25_PRIV               (0x1u<<13)
#define HSEM_R25_SEC                (0x1u<<12)
#define HSEM_R25_LOCKID             (0xFu<<8)
#define HSEM_R25_LOCKID_0           (0x1u<<8)
#define HSEM_R25_PROCID             (0xFFu<<0)
#define HSEM_R25_PROCID_0           (0x1u<<0)

#define HSEM_R25_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R25_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R25_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R25_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R25_SEC_B_0X0          (0x0u<<12)
#define HSEM_R25_SEC_B_0X1          (0x1u<<12)

// R26 Configuration

#define HSEM_R26_LOCK               (0x1u<<31)
#define HSEM_R26_PRIV               (0x1u<<13)
#define HSEM_R26_SEC                (0x1u<<12)
#define HSEM_R26_LOCKID             (0xFu<<8)
#define HSEM_R26_LOCKID_0           (0x1u<<8)
#define HSEM_R26_PROCID             (0xFFu<<0)
#define HSEM_R26_PROCID_0           (0x1u<<0)

#define HSEM_R26_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R26_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R26_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R26_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R26_SEC_B_0X0          (0x0u<<12)
#define HSEM_R26_SEC_B_0X1          (0x1u<<12)

// R27 Configuration

#define HSEM_R27_LOCK               (0x1u<<31)
#define HSEM_R27_PRIV               (0x1u<<13)
#define HSEM_R27_SEC                (0x1u<<12)
#define HSEM_R27_LOCKID             (0xFu<<8)
#define HSEM_R27_LOCKID_0           (0x1u<<8)
#define HSEM_R27_PROCID             (0xFFu<<0)
#define HSEM_R27_PROCID_0           (0x1u<<0)

#define HSEM_R27_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R27_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R27_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R27_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R27_SEC_B_0X0          (0x0u<<12)
#define HSEM_R27_SEC_B_0X1          (0x1u<<12)

// R28 Configuration

#define HSEM_R28_LOCK               (0x1u<<31)
#define HSEM_R28_PRIV               (0x1u<<13)
#define HSEM_R28_SEC                (0x1u<<12)
#define HSEM_R28_LOCKID             (0xFu<<8)
#define HSEM_R28_LOCKID_0           (0x1u<<8)
#define HSEM_R28_PROCID             (0xFFu<<0)
#define HSEM_R28_PROCID_0           (0x1u<<0)

#define HSEM_R28_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R28_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R28_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R28_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R28_SEC_B_0X0          (0x0u<<12)
#define HSEM_R28_SEC_B_0X1          (0x1u<<12)

// R29 Configuration

#define HSEM_R29_LOCK               (0x1u<<31)
#define HSEM_R29_PRIV               (0x1u<<13)
#define HSEM_R29_SEC                (0x1u<<12)
#define HSEM_R29_LOCKID             (0xFu<<8)
#define HSEM_R29_LOCKID_0           (0x1u<<8)
#define HSEM_R29_PROCID             (0xFFu<<0)
#define HSEM_R29_PROCID_0           (0x1u<<0)

#define HSEM_R29_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R29_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R29_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R29_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R29_SEC_B_0X0          (0x0u<<12)
#define HSEM_R29_SEC_B_0X1          (0x1u<<12)

// R30 Configuration

#define HSEM_R30_LOCK               (0x1u<<31)
#define HSEM_R30_PRIV               (0x1u<<13)
#define HSEM_R30_SEC                (0x1u<<12)
#define HSEM_R30_LOCKID             (0xFu<<8)
#define HSEM_R30_LOCKID_0           (0x1u<<8)
#define HSEM_R30_PROCID             (0xFFu<<0)
#define HSEM_R30_PROCID_0           (0x1u<<0)

#define HSEM_R30_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R30_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R30_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R30_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R30_SEC_B_0X0          (0x0u<<12)
#define HSEM_R30_SEC_B_0X1          (0x1u<<12)

// R31 Configuration

#define HSEM_R31_LOCK               (0x1u<<31)
#define HSEM_R31_PRIV               (0x1u<<13)
#define HSEM_R31_SEC                (0x1u<<12)
#define HSEM_R31_LOCKID             (0xFu<<8)
#define HSEM_R31_LOCKID_0           (0x1u<<8)
#define HSEM_R31_PROCID             (0xFFu<<0)
#define HSEM_R31_PROCID_0           (0x1u<<0)

#define HSEM_R31_LOCK_B_0X0         (0x0u<<31)
#define HSEM_R31_LOCK_B_0X1         (0x1u<<31)
#define HSEM_R31_PRIV_B_0X0         (0x0u<<13)
#define HSEM_R31_PRIV_B_0X1         (0x1u<<13)
#define HSEM_R31_SEC_B_0X0          (0x0u<<12)
#define HSEM_R31_SEC_B_0X1          (0x1u<<12)

// RLR0 Configuration

#define HSEM_RLR0_LOCK              (0x1u<<31)
#define HSEM_RLR0_PRIV              (0x1u<<13)
#define HSEM_RLR0_SEC               (0x1u<<12)
#define HSEM_RLR0_LOCKID            (0xFu<<8)
#define HSEM_RLR0_LOCKID_0          (0x1u<<8)
#define HSEM_RLR0_PROCID            (0xFFu<<0)
#define HSEM_RLR0_PROCID_0          (0x1u<<0)

#define HSEM_RLR0_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR0_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR0_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR0_SEC_B_0X1         (0x1u<<12)

// RLR1 Configuration

#define HSEM_RLR1_LOCK              (0x1u<<31)
#define HSEM_RLR1_PRIV              (0x1u<<13)
#define HSEM_RLR1_SEC               (0x1u<<12)
#define HSEM_RLR1_LOCKID            (0xFu<<8)
#define HSEM_RLR1_LOCKID_0          (0x1u<<8)
#define HSEM_RLR1_PROCID            (0xFFu<<0)
#define HSEM_RLR1_PROCID_0          (0x1u<<0)

#define HSEM_RLR1_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR1_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR1_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR1_SEC_B_0X1         (0x1u<<12)

// RLR2 Configuration

#define HSEM_RLR2_LOCK              (0x1u<<31)
#define HSEM_RLR2_PRIV              (0x1u<<13)
#define HSEM_RLR2_SEC               (0x1u<<12)
#define HSEM_RLR2_LOCKID            (0xFu<<8)
#define HSEM_RLR2_LOCKID_0          (0x1u<<8)
#define HSEM_RLR2_PROCID            (0xFFu<<0)
#define HSEM_RLR2_PROCID_0          (0x1u<<0)

#define HSEM_RLR2_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR2_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR2_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR2_SEC_B_0X1         (0x1u<<12)

// RLR3 Configuration

#define HSEM_RLR3_LOCK              (0x1u<<31)
#define HSEM_RLR3_PRIV              (0x1u<<13)
#define HSEM_RLR3_SEC               (0x1u<<12)
#define HSEM_RLR3_LOCKID            (0xFu<<8)
#define HSEM_RLR3_LOCKID_0          (0x1u<<8)
#define HSEM_RLR3_PROCID            (0xFFu<<0)
#define HSEM_RLR3_PROCID_0          (0x1u<<0)

#define HSEM_RLR3_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR3_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR3_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR3_SEC_B_0X1         (0x1u<<12)

// RLR4 Configuration

#define HSEM_RLR4_LOCK              (0x1u<<31)
#define HSEM_RLR4_PRIV              (0x1u<<13)
#define HSEM_RLR4_SEC               (0x1u<<12)
#define HSEM_RLR4_LOCKID            (0xFu<<8)
#define HSEM_RLR4_LOCKID_0          (0x1u<<8)
#define HSEM_RLR4_PROCID            (0xFFu<<0)
#define HSEM_RLR4_PROCID_0          (0x1u<<0)

#define HSEM_RLR4_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR4_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR4_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR4_SEC_B_0X1         (0x1u<<12)

// RLR5 Configuration

#define HSEM_RLR5_LOCK              (0x1u<<31)
#define HSEM_RLR5_PRIV              (0x1u<<13)
#define HSEM_RLR5_SEC               (0x1u<<12)
#define HSEM_RLR5_LOCKID            (0xFu<<8)
#define HSEM_RLR5_LOCKID_0          (0x1u<<8)
#define HSEM_RLR5_PROCID            (0xFFu<<0)
#define HSEM_RLR5_PROCID_0          (0x1u<<0)

#define HSEM_RLR5_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR5_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR5_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR5_SEC_B_0X1         (0x1u<<12)

// RLR6 Configuration

#define HSEM_RLR6_LOCK              (0x1u<<31)
#define HSEM_RLR6_PRIV              (0x1u<<13)
#define HSEM_RLR6_SEC               (0x1u<<12)
#define HSEM_RLR6_LOCKID            (0xFu<<8)
#define HSEM_RLR6_LOCKID_0          (0x1u<<8)
#define HSEM_RLR6_PROCID            (0xFFu<<0)
#define HSEM_RLR6_PROCID_0          (0x1u<<0)

#define HSEM_RLR6_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR6_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR6_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR6_SEC_B_0X1         (0x1u<<12)

// RLR7 Configuration

#define HSEM_RLR7_LOCK              (0x1u<<31)
#define HSEM_RLR7_PRIV              (0x1u<<13)
#define HSEM_RLR7_SEC               (0x1u<<12)
#define HSEM_RLR7_LOCKID            (0xFu<<8)
#define HSEM_RLR7_LOCKID_0          (0x1u<<8)
#define HSEM_RLR7_PROCID            (0xFFu<<0)
#define HSEM_RLR7_PROCID_0          (0x1u<<0)

#define HSEM_RLR7_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR7_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR7_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR7_SEC_B_0X1         (0x1u<<12)

// RLR8 Configuration

#define HSEM_RLR8_LOCK              (0x1u<<31)
#define HSEM_RLR8_PRIV              (0x1u<<13)
#define HSEM_RLR8_SEC               (0x1u<<12)
#define HSEM_RLR8_LOCKID            (0xFu<<8)
#define HSEM_RLR8_LOCKID_0          (0x1u<<8)
#define HSEM_RLR8_PROCID            (0xFFu<<0)
#define HSEM_RLR8_PROCID_0          (0x1u<<0)

#define HSEM_RLR8_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR8_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR8_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR8_SEC_B_0X1         (0x1u<<12)

// RLR9 Configuration

#define HSEM_RLR9_LOCK              (0x1u<<31)
#define HSEM_RLR9_PRIV              (0x1u<<13)
#define HSEM_RLR9_SEC               (0x1u<<12)
#define HSEM_RLR9_LOCKID            (0xFu<<8)
#define HSEM_RLR9_LOCKID_0          (0x1u<<8)
#define HSEM_RLR9_PROCID            (0xFFu<<0)
#define HSEM_RLR9_PROCID_0          (0x1u<<0)

#define HSEM_RLR9_PRIV_B_0X0        (0x0u<<13)
#define HSEM_RLR9_PRIV_B_0X1        (0x1u<<13)
#define HSEM_RLR9_SEC_B_0X0         (0x0u<<12)
#define HSEM_RLR9_SEC_B_0X1         (0x1u<<12)

// RLR10 Configuration

#define HSEM_RLR10_LOCK             (0x1u<<31)
#define HSEM_RLR10_PRIV             (0x1u<<13)
#define HSEM_RLR10_SEC              (0x1u<<12)
#define HSEM_RLR10_LOCKID           (0xFu<<8)
#define HSEM_RLR10_LOCKID_0         (0x1u<<8)
#define HSEM_RLR10_PROCID           (0xFFu<<0)
#define HSEM_RLR10_PROCID_0         (0x1u<<0)

#define HSEM_RLR10_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR10_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR10_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR10_SEC_B_0X1        (0x1u<<12)

// RLR11 Configuration

#define HSEM_RLR11_LOCK             (0x1u<<31)
#define HSEM_RLR11_PRIV             (0x1u<<13)
#define HSEM_RLR11_SEC              (0x1u<<12)
#define HSEM_RLR11_LOCKID           (0xFu<<8)
#define HSEM_RLR11_LOCKID_0         (0x1u<<8)
#define HSEM_RLR11_PROCID           (0xFFu<<0)
#define HSEM_RLR11_PROCID_0         (0x1u<<0)

#define HSEM_RLR11_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR11_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR11_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR11_SEC_B_0X1        (0x1u<<12)

// RLR12 Configuration

#define HSEM_RLR12_LOCK             (0x1u<<31)
#define HSEM_RLR12_PRIV             (0x1u<<13)
#define HSEM_RLR12_SEC              (0x1u<<12)
#define HSEM_RLR12_LOCKID           (0xFu<<8)
#define HSEM_RLR12_LOCKID_0         (0x1u<<8)
#define HSEM_RLR12_PROCID           (0xFFu<<0)
#define HSEM_RLR12_PROCID_0         (0x1u<<0)

#define HSEM_RLR12_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR12_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR12_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR12_SEC_B_0X1        (0x1u<<12)

// RLR13 Configuration

#define HSEM_RLR13_LOCK             (0x1u<<31)
#define HSEM_RLR13_PRIV             (0x1u<<13)
#define HSEM_RLR13_SEC              (0x1u<<12)
#define HSEM_RLR13_LOCKID           (0xFu<<8)
#define HSEM_RLR13_LOCKID_0         (0x1u<<8)
#define HSEM_RLR13_PROCID           (0xFFu<<0)
#define HSEM_RLR13_PROCID_0         (0x1u<<0)

#define HSEM_RLR13_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR13_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR13_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR13_SEC_B_0X1        (0x1u<<12)

// RLR14 Configuration

#define HSEM_RLR14_LOCK             (0x1u<<31)
#define HSEM_RLR14_PRIV             (0x1u<<13)
#define HSEM_RLR14_SEC              (0x1u<<12)
#define HSEM_RLR14_LOCKID           (0xFu<<8)
#define HSEM_RLR14_LOCKID_0         (0x1u<<8)
#define HSEM_RLR14_PROCID           (0xFFu<<0)
#define HSEM_RLR14_PROCID_0         (0x1u<<0)

#define HSEM_RLR14_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR14_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR14_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR14_SEC_B_0X1        (0x1u<<12)

// RLR15 Configuration

#define HSEM_RLR15_LOCK             (0x1u<<31)
#define HSEM_RLR15_PRIV             (0x1u<<13)
#define HSEM_RLR15_SEC              (0x1u<<12)
#define HSEM_RLR15_LOCKID           (0xFu<<8)
#define HSEM_RLR15_LOCKID_0         (0x1u<<8)
#define HSEM_RLR15_PROCID           (0xFFu<<0)
#define HSEM_RLR15_PROCID_0         (0x1u<<0)

#define HSEM_RLR15_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR15_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR15_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR15_SEC_B_0X1        (0x1u<<12)

// RLR16 Configuration

#define HSEM_RLR16_LOCK             (0x1u<<31)
#define HSEM_RLR16_PRIV             (0x1u<<13)
#define HSEM_RLR16_SEC              (0x1u<<12)
#define HSEM_RLR16_LOCKID           (0xFu<<8)
#define HSEM_RLR16_LOCKID_0         (0x1u<<8)
#define HSEM_RLR16_PROCID           (0xFFu<<0)
#define HSEM_RLR16_PROCID_0         (0x1u<<0)

#define HSEM_RLR16_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR16_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR16_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR16_SEC_B_0X1        (0x1u<<12)

// RLR17 Configuration

#define HSEM_RLR17_LOCK             (0x1u<<31)
#define HSEM_RLR17_PRIV             (0x1u<<13)
#define HSEM_RLR17_SEC              (0x1u<<12)
#define HSEM_RLR17_LOCKID           (0xFu<<8)
#define HSEM_RLR17_LOCKID_0         (0x1u<<8)
#define HSEM_RLR17_PROCID           (0xFFu<<0)
#define HSEM_RLR17_PROCID_0         (0x1u<<0)

#define HSEM_RLR17_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR17_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR17_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR17_SEC_B_0X1        (0x1u<<12)

// RLR18 Configuration

#define HSEM_RLR18_LOCK             (0x1u<<31)
#define HSEM_RLR18_PRIV             (0x1u<<13)
#define HSEM_RLR18_SEC              (0x1u<<12)
#define HSEM_RLR18_LOCKID           (0xFu<<8)
#define HSEM_RLR18_LOCKID_0         (0x1u<<8)
#define HSEM_RLR18_PROCID           (0xFFu<<0)
#define HSEM_RLR18_PROCID_0         (0x1u<<0)

#define HSEM_RLR18_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR18_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR18_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR18_SEC_B_0X1        (0x1u<<12)

// RLR19 Configuration

#define HSEM_RLR19_LOCK             (0x1u<<31)
#define HSEM_RLR19_PRIV             (0x1u<<13)
#define HSEM_RLR19_SEC              (0x1u<<12)
#define HSEM_RLR19_LOCKID           (0xFu<<8)
#define HSEM_RLR19_LOCKID_0         (0x1u<<8)
#define HSEM_RLR19_PROCID           (0xFFu<<0)
#define HSEM_RLR19_PROCID_0         (0x1u<<0)

#define HSEM_RLR19_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR19_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR19_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR19_SEC_B_0X1        (0x1u<<12)

// RLR20 Configuration

#define HSEM_RLR20_LOCK             (0x1u<<31)
#define HSEM_RLR20_PRIV             (0x1u<<13)
#define HSEM_RLR20_SEC              (0x1u<<12)
#define HSEM_RLR20_LOCKID           (0xFu<<8)
#define HSEM_RLR20_LOCKID_0         (0x1u<<8)
#define HSEM_RLR20_PROCID           (0xFFu<<0)
#define HSEM_RLR20_PROCID_0         (0x1u<<0)

#define HSEM_RLR20_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR20_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR20_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR20_SEC_B_0X1        (0x1u<<12)

// RLR21 Configuration

#define HSEM_RLR21_LOCK             (0x1u<<31)
#define HSEM_RLR21_PRIV             (0x1u<<13)
#define HSEM_RLR21_SEC              (0x1u<<12)
#define HSEM_RLR21_LOCKID           (0xFu<<8)
#define HSEM_RLR21_LOCKID_0         (0x1u<<8)
#define HSEM_RLR21_PROCID           (0xFFu<<0)
#define HSEM_RLR21_PROCID_0         (0x1u<<0)

#define HSEM_RLR21_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR21_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR21_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR21_SEC_B_0X1        (0x1u<<12)

// RLR22 Configuration

#define HSEM_RLR22_LOCK             (0x1u<<31)
#define HSEM_RLR22_PRIV             (0x1u<<13)
#define HSEM_RLR22_SEC              (0x1u<<12)
#define HSEM_RLR22_LOCKID           (0xFu<<8)
#define HSEM_RLR22_LOCKID_0         (0x1u<<8)
#define HSEM_RLR22_PROCID           (0xFFu<<0)
#define HSEM_RLR22_PROCID_0         (0x1u<<0)

#define HSEM_RLR22_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR22_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR22_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR22_SEC_B_0X1        (0x1u<<12)

// RLR23 Configuration

#define HSEM_RLR23_LOCK             (0x1u<<31)
#define HSEM_RLR23_PRIV             (0x1u<<13)
#define HSEM_RLR23_SEC              (0x1u<<12)
#define HSEM_RLR23_LOCKID           (0xFu<<8)
#define HSEM_RLR23_LOCKID_0         (0x1u<<8)
#define HSEM_RLR23_PROCID           (0xFFu<<0)
#define HSEM_RLR23_PROCID_0         (0x1u<<0)

#define HSEM_RLR23_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR23_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR23_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR23_SEC_B_0X1        (0x1u<<12)

// RLR24 Configuration

#define HSEM_RLR24_LOCK             (0x1u<<31)
#define HSEM_RLR24_PRIV             (0x1u<<13)
#define HSEM_RLR24_SEC              (0x1u<<12)
#define HSEM_RLR24_LOCKID           (0xFu<<8)
#define HSEM_RLR24_LOCKID_0         (0x1u<<8)
#define HSEM_RLR24_PROCID           (0xFFu<<0)
#define HSEM_RLR24_PROCID_0         (0x1u<<0)

#define HSEM_RLR24_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR24_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR24_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR24_SEC_B_0X1        (0x1u<<12)

// RLR25 Configuration

#define HSEM_RLR25_LOCK             (0x1u<<31)
#define HSEM_RLR25_PRIV             (0x1u<<13)
#define HSEM_RLR25_SEC              (0x1u<<12)
#define HSEM_RLR25_LOCKID           (0xFu<<8)
#define HSEM_RLR25_LOCKID_0         (0x1u<<8)
#define HSEM_RLR25_PROCID           (0xFFu<<0)
#define HSEM_RLR25_PROCID_0         (0x1u<<0)

#define HSEM_RLR25_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR25_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR25_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR25_SEC_B_0X1        (0x1u<<12)

// RLR26 Configuration

#define HSEM_RLR26_LOCK             (0x1u<<31)
#define HSEM_RLR26_PRIV             (0x1u<<13)
#define HSEM_RLR26_SEC              (0x1u<<12)
#define HSEM_RLR26_LOCKID           (0xFu<<8)
#define HSEM_RLR26_LOCKID_0         (0x1u<<8)
#define HSEM_RLR26_PROCID           (0xFFu<<0)
#define HSEM_RLR26_PROCID_0         (0x1u<<0)

#define HSEM_RLR26_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR26_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR26_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR26_SEC_B_0X1        (0x1u<<12)

// RLR27 Configuration

#define HSEM_RLR27_LOCK             (0x1u<<31)
#define HSEM_RLR27_PRIV             (0x1u<<13)
#define HSEM_RLR27_SEC              (0x1u<<12)
#define HSEM_RLR27_LOCKID           (0xFu<<8)
#define HSEM_RLR27_LOCKID_0         (0x1u<<8)
#define HSEM_RLR27_PROCID           (0xFFu<<0)
#define HSEM_RLR27_PROCID_0         (0x1u<<0)

#define HSEM_RLR27_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR27_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR27_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR27_SEC_B_0X1        (0x1u<<12)

// RLR28 Configuration

#define HSEM_RLR28_LOCK             (0x1u<<31)
#define HSEM_RLR28_PRIV             (0x1u<<13)
#define HSEM_RLR28_SEC              (0x1u<<12)
#define HSEM_RLR28_LOCKID           (0xFu<<8)
#define HSEM_RLR28_LOCKID_0         (0x1u<<8)
#define HSEM_RLR28_PROCID           (0xFFu<<0)
#define HSEM_RLR28_PROCID_0         (0x1u<<0)

#define HSEM_RLR28_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR28_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR28_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR28_SEC_B_0X1        (0x1u<<12)

// RLR29 Configuration

#define HSEM_RLR29_LOCK             (0x1u<<31)
#define HSEM_RLR29_PRIV             (0x1u<<13)
#define HSEM_RLR29_SEC              (0x1u<<12)
#define HSEM_RLR29_LOCKID           (0xFu<<8)
#define HSEM_RLR29_LOCKID_0         (0x1u<<8)
#define HSEM_RLR29_PROCID           (0xFFu<<0)
#define HSEM_RLR29_PROCID_0         (0x1u<<0)

#define HSEM_RLR29_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR29_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR29_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR29_SEC_B_0X1        (0x1u<<12)

// RLR30 Configuration

#define HSEM_RLR30_LOCK             (0x1u<<31)
#define HSEM_RLR30_PRIV             (0x1u<<13)
#define HSEM_RLR30_SEC              (0x1u<<12)
#define HSEM_RLR30_LOCKID           (0xFu<<8)
#define HSEM_RLR30_LOCKID_0         (0x1u<<8)
#define HSEM_RLR30_PROCID           (0xFFu<<0)
#define HSEM_RLR30_PROCID_0         (0x1u<<0)

#define HSEM_RLR30_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR30_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR30_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR30_SEC_B_0X1        (0x1u<<12)

// RLR31 Configuration

#define HSEM_RLR31_LOCK             (0x1u<<31)
#define HSEM_RLR31_PRIV             (0x1u<<13)
#define HSEM_RLR31_SEC              (0x1u<<12)
#define HSEM_RLR31_LOCKID           (0xFu<<8)
#define HSEM_RLR31_LOCKID_0         (0x1u<<8)
#define HSEM_RLR31_PROCID           (0xFFu<<0)
#define HSEM_RLR31_PROCID_0         (0x1u<<0)

#define HSEM_RLR31_PRIV_B_0X0       (0x0u<<13)
#define HSEM_RLR31_PRIV_B_0X1       (0x1u<<13)
#define HSEM_RLR31_SEC_B_0X0        (0x0u<<12)
#define HSEM_RLR31_SEC_B_0X1        (0x1u<<12)

// IER Configuration

#define HSEM_IER_ISE                (0xFFFFFFFFu<<0)
#define HSEM_IER_ISE_0              (0x1u<<0)

#define HSEM_IER_ISE_B_0X0          (0x0u<<0)
#define HSEM_IER_ISE_B_0X1          (0x1u<<0)

// ICR Configuration

#define HSEM_ICR_ISC                (0xFFFFFFFFu<<0)
#define HSEM_ICR_ISC_0              (0x1u<<0)

#define HSEM_ICR_ISC_B_0X0          (0x0u<<0)
#define HSEM_ICR_ISC_B_0X1          (0x1u<<0)

// ISR Configuration

#define HSEM_ISR_ISF                (0xFFFFFFFFu<<0)
#define HSEM_ISR_ISF_0              (0x1u<<0)

#define HSEM_ISR_ISF_B_0X0          (0x0u<<0)
#define HSEM_ISR_ISF_B_0X1          (0x1u<<0)

// MISR Configuration

#define HSEM_MISR_MISF              (0xFFFFFFFFu<<0)
#define HSEM_MISR_MISF_0            (0x1u<<0)

#define HSEM_MISR_MISF_B_0X0        (0x0u<<0)
#define HSEM_MISR_MISF_B_0X1        (0x1u<<0)

// SIER Configuration

#define HSEM_SIER_SISE              (0xFFFFFFFFu<<0)
#define HSEM_SIER_SISE_0            (0x1u<<0)

#define HSEM_SIER_SISE_B_0X0        (0x0u<<0)
#define HSEM_SIER_SISE_B_0X1        (0x1u<<0)

// SICR Configuration

#define HSEM_SICR_SISC              (0xFFFFFFFFu<<0)
#define HSEM_SICR_SISC_0            (0x1u<<0)

#define HSEM_SICR_SISC_B_0X0        (0x0u<<0)
#define HSEM_SICR_SISC_B_0X1        (0x1u<<0)

// SISR Configuration

#define HSEM_SISR_SISF              (0xFFFFFFFFu<<0)
#define HSEM_SISR_SISF_0            (0x1u<<0)

#define HSEM_SISR_SISF_B_0X0        (0x0u<<0)
#define HSEM_SISR_SISF_B_0X1        (0x1u<<0)

// MSISR Configuration

#define HSEM_MSISR_SMISF            (0xFFFFFFFFu<<0)
#define HSEM_MSISR_SMISF_0          (0x1u<<0)

#define HSEM_MSISR_SMISF_B_0X0      (0x0u<<0)
#define HSEM_MSISR_SMISF_B_0X1      (0x1u<<0)

// SECCFGR Configuration

#define HSEM_SECCFGR_SEC            (0xFFFFFFFFu<<0)
#define HSEM_SECCFGR_SEC_0          (0x1u<<0)

#define HSEM_SECCFGR_SEC_B_0X0      (0x0u<<0)
#define HSEM_SECCFGR_SEC_B_0X1      (0x1u<<0)

// PRIVCFGR Configuration

#define HSEM_PRIVCFGR_PRIV          (0xFFFFFFFFu<<0)
#define HSEM_PRIVCFGR_PRIV_0        (0x1u<<0)

#define HSEM_PRIVCFGR_PRIV_B_0X0    (0x0u<<0)
#define HSEM_PRIVCFGR_PRIV_B_0X1    (0x1u<<0)

// CR Configuration

#define HSEM_CR_KEY                 (0xFFFFu<<16)
#define HSEM_CR_KEY_0               (0x1u<<16)
#define HSEM_CR_PRIV                (0x1u<<13)
#define HSEM_CR_SEC                 (0x1u<<12)
#define HSEM_CR_LOCKID              (0xFu<<8)
#define HSEM_CR_LOCKID_0            (0x1u<<8)

// KEYR Configuration

#define HSEM_KEYR_KEY               (0xFFFFu<<16)
#define HSEM_KEYR_KEY_0             (0x1u<<16)
