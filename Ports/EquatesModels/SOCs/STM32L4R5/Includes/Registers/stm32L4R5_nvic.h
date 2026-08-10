/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_nvic equates.
 */

#pragma once

#include    <stdint.h>

// NVIC address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    ISER0;
    volatile    uint32_t    ISER1;
    volatile    uint32_t    ISER2;
    volatile    uint32_t    RESERVED0[29];
    volatile    uint32_t    ICER0;
    volatile    uint32_t    ICER1;
    volatile    uint32_t    ICER2;
    volatile    uint32_t    RESERVED1[29];
    volatile    uint32_t    ISPR0;
    volatile    uint32_t    ISPR1;
    volatile    uint32_t    ISPR2;
    volatile    uint32_t    RESERVED2[29];
    volatile    uint32_t    ICPR0;
    volatile    uint32_t    ICPR1;
    volatile    uint32_t    ICPR2;
    volatile    uint32_t    RESERVED3[29];
    volatile    uint32_t    IABR0;
    volatile    uint32_t    IABR1;
    volatile    uint32_t    IABR2;
    volatile    uint32_t    RESERVED4[61];
    volatile    uint32_t    IPR0;
    volatile    uint32_t    IPR1;
    volatile    uint32_t    IPR2;
    volatile    uint32_t    IPR3;
    volatile    uint32_t    IPR4;
    volatile    uint32_t    IPR5;
    volatile    uint32_t    IPR6;
    volatile    uint32_t    IPR7;
    volatile    uint32_t    IPR8;
    volatile    uint32_t    IPR9;
    volatile    uint32_t    IPR10;
    volatile    uint32_t    IPR11;
    volatile    uint32_t    IPR12;
    volatile    uint32_t    IPR13;
    volatile    uint32_t    IPR14;
    volatile    uint32_t    IPR15;
    volatile    uint32_t    IPR16;
    volatile    uint32_t    IPR17;
    volatile    uint32_t    IPR18;
    volatile    uint32_t    IPR19;
    volatile    uint32_t    IPR20;
    volatile    uint32_t    IPR21;
    volatile    uint32_t    IPR22;
    volatile    uint32_t    IPR23;
    volatile    uint32_t    IPR24;
    volatile    uint32_t    IPR25;
} NVIC_TypeDef;

#ifdef __cplusplus
#define NVIC    reinterpret_cast<NVIC_TypeDef *>(0xE000E100U)

#else
#define NVIC    ((NVIC_TypeDef *)0xE000E100U)
#endif

// ISER0 Configuration

#define NVIC_ISER0_SETENA       (0xFFFFFFFFU<<0U)
#define NVIC_ISER0_SETENA_0     (0x1U<<0U)

// ISER1 Configuration

#define NVIC_ISER1_SETENA       (0xFFFFFFFFU<<0U)
#define NVIC_ISER1_SETENA_0     (0x1U<<0U)

// ISER2 Configuration

#define NVIC_ISER2_SETENA       (0xFFFFFFFFU<<0U)
#define NVIC_ISER2_SETENA_0     (0x1U<<0U)

// ICER0 Configuration

#define NVIC_ICER0_CLRENA       (0xFFFFFFFFU<<0U)
#define NVIC_ICER0_CLRENA_0     (0x1U<<0U)

// ICER1 Configuration

#define NVIC_ICER1_CLRENA       (0xFFFFFFFFU<<0U)
#define NVIC_ICER1_CLRENA_0     (0x1U<<0U)

// ICER2 Configuration

#define NVIC_ICER2_CLRENA       (0xFFFFFFFFU<<0U)
#define NVIC_ICER2_CLRENA_0     (0x1U<<0U)

// ISPR0 Configuration

#define NVIC_ISPR0_SETPEND      (0xFFFFFFFFU<<0U)
#define NVIC_ISPR0_SETPEND_0    (0x1U<<0U)

// ISPR1 Configuration

#define NVIC_ISPR1_SETPEND      (0xFFFFFFFFU<<0U)
#define NVIC_ISPR1_SETPEND_0    (0x1U<<0U)

// ISPR2 Configuration

#define NVIC_ISPR2_SETPEND      (0xFFFFFFFFU<<0U)
#define NVIC_ISPR2_SETPEND_0    (0x1U<<0U)

// ICPR0 Configuration

#define NVIC_ICPR0_CLRPEND      (0xFFFFFFFFU<<0U)
#define NVIC_ICPR0_CLRPEND_0    (0x1U<<0U)

// ICPR1 Configuration

#define NVIC_ICPR1_CLRPEND      (0xFFFFFFFFU<<0U)
#define NVIC_ICPR1_CLRPEND_0    (0x1U<<0U)

// ICPR2 Configuration

#define NVIC_ICPR2_CLRPEND      (0xFFFFFFFFU<<0U)
#define NVIC_ICPR2_CLRPEND_0    (0x1U<<0U)

// IABR0 Configuration

#define NVIC_IABR0_ACTIVE       (0xFFFFFFFFU<<0U)
#define NVIC_IABR0_ACTIVE_0     (0x1U<<0U)

// IABR1 Configuration

#define NVIC_IABR1_ACTIVE       (0xFFFFFFFFU<<0U)
#define NVIC_IABR1_ACTIVE_0     (0x1U<<0U)

// IABR2 Configuration

#define NVIC_IABR2_ACTIVE       (0xFFFFFFFFU<<0U)
#define NVIC_IABR2_ACTIVE_0     (0x1U<<0U)

// IPR0 Configuration

#define NVIC_IPR0_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR0_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR0_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR0_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR0_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR0_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR0_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR0_IPR_N0_0      (0x1U<<0U)

// IPR1 Configuration

#define NVIC_IPR1_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR1_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR1_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR1_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR1_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR1_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR1_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR1_IPR_N0_0      (0x1U<<0U)

// IPR2 Configuration

#define NVIC_IPR2_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR2_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR2_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR2_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR2_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR2_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR2_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR2_IPR_N0_0      (0x1U<<0U)

// IPR3 Configuration

#define NVIC_IPR3_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR3_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR3_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR3_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR3_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR3_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR3_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR3_IPR_N0_0      (0x1U<<0U)

// IPR4 Configuration

#define NVIC_IPR4_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR4_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR4_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR4_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR4_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR4_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR4_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR4_IPR_N0_0      (0x1U<<0U)

// IPR5 Configuration

#define NVIC_IPR5_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR5_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR5_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR5_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR5_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR5_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR5_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR5_IPR_N0_0      (0x1U<<0U)

// IPR6 Configuration

#define NVIC_IPR6_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR6_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR6_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR6_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR6_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR6_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR6_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR6_IPR_N0_0      (0x1U<<0U)

// IPR7 Configuration

#define NVIC_IPR7_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR7_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR7_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR7_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR7_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR7_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR7_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR7_IPR_N0_0      (0x1U<<0U)

// IPR8 Configuration

#define NVIC_IPR8_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR8_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR8_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR8_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR8_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR8_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR8_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR8_IPR_N0_0      (0x1U<<0U)

// IPR9 Configuration

#define NVIC_IPR9_IPR_N3        (0xFFU<<24U)
#define NVIC_IPR9_IPR_N3_0      (0x1U<<24U)
#define NVIC_IPR9_IPR_N2        (0xFFU<<16U)
#define NVIC_IPR9_IPR_N2_0      (0x1U<<16U)
#define NVIC_IPR9_IPR_N1        (0xFFU<<8U)
#define NVIC_IPR9_IPR_N1_0      (0x1U<<8U)
#define NVIC_IPR9_IPR_N0        (0xFFU<<0U)
#define NVIC_IPR9_IPR_N0_0      (0x1U<<0U)

// IPR10 Configuration

#define NVIC_IPR10_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR10_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR10_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR10_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR10_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR10_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR10_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR10_IPR_N0_0     (0x1U<<0U)

// IPR11 Configuration

#define NVIC_IPR11_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR11_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR11_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR11_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR11_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR11_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR11_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR11_IPR_N0_0     (0x1U<<0U)

// IPR12 Configuration

#define NVIC_IPR12_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR12_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR12_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR12_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR12_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR12_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR12_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR12_IPR_N0_0     (0x1U<<0U)

// IPR13 Configuration

#define NVIC_IPR13_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR13_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR13_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR13_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR13_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR13_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR13_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR13_IPR_N0_0     (0x1U<<0U)

// IPR14 Configuration

#define NVIC_IPR14_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR14_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR14_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR14_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR14_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR14_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR14_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR14_IPR_N0_0     (0x1U<<0U)

// IPR15 Configuration

#define NVIC_IPR15_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR15_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR15_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR15_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR15_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR15_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR15_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR15_IPR_N0_0     (0x1U<<0U)

// IPR16 Configuration

#define NVIC_IPR16_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR16_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR16_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR16_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR16_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR16_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR16_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR16_IPR_N0_0     (0x1U<<0U)

// IPR17 Configuration

#define NVIC_IPR17_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR17_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR17_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR17_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR17_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR17_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR17_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR17_IPR_N0_0     (0x1U<<0U)

// IPR18 Configuration

#define NVIC_IPR18_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR18_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR18_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR18_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR18_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR18_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR18_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR18_IPR_N0_0     (0x1U<<0U)

// IPR19 Configuration

#define NVIC_IPR19_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR19_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR19_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR19_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR19_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR19_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR19_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR19_IPR_N0_0     (0x1U<<0U)

// IPR20 Configuration

#define NVIC_IPR20_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR20_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR20_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR20_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR20_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR20_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR20_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR20_IPR_N0_0     (0x1U<<0U)

// IPR21 Configuration

#define NVIC_IPR21_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR21_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR21_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR21_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR21_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR21_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR21_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR21_IPR_N0_0     (0x1U<<0U)

// IPR22 Configuration

#define NVIC_IPR22_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR22_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR22_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR22_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR22_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR22_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR22_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR22_IPR_N0_0     (0x1U<<0U)

// IPR23 Configuration

#define NVIC_IPR23_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR23_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR23_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR23_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR23_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR23_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR23_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR23_IPR_N0_0     (0x1U<<0U)

// IPR24 Configuration

#define NVIC_IPR24_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR24_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR24_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR24_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR24_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR24_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR24_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR24_IPR_N0_0     (0x1U<<0U)

// IPR25 Configuration

#define NVIC_IPR25_IPR_N3       (0xFFU<<24U)
#define NVIC_IPR25_IPR_N3_0     (0x1U<<24U)
#define NVIC_IPR25_IPR_N2       (0xFFU<<16U)
#define NVIC_IPR25_IPR_N2_0     (0x1U<<16U)
#define NVIC_IPR25_IPR_N1       (0xFFU<<8U)
#define NVIC_IPR25_IPR_N1_0     (0x1U<<8U)
#define NVIC_IPR25_IPR_N0       (0xFFU<<0U)
#define NVIC_IPR25_IPR_N0_0     (0x1U<<0U)
