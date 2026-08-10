/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_hsem equates.
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
    volatile    uint32_t    RESERVED0[12];
    volatile    uint32_t    CR;
    volatile    uint32_t    KEYR;
} HSEM_TypeDef;

#ifdef __cplusplus
#define HSEM    reinterpret_cast<HSEM_TypeDef *>(0x58026400U)

#else
#define HSEM    ((HSEM_TypeDef *)0x58026400U)
#endif

// R0 Configuration

#define HSEM_R0_LOCK            (0x1U<<31U)
#define HSEM_R0_MASTERID        (0xFFU<<8U)
#define HSEM_R0_MASTERID_0      (0x1U<<8U)
#define HSEM_R0_PROCID          (0xFFU<<0U)
#define HSEM_R0_PROCID_0        (0x1U<<0U)

// R1 Configuration

#define HSEM_R1_LOCK            (0x1U<<31U)
#define HSEM_R1_MASTERID        (0xFFU<<8U)
#define HSEM_R1_MASTERID_0      (0x1U<<8U)
#define HSEM_R1_PROCID          (0xFFU<<0U)
#define HSEM_R1_PROCID_0        (0x1U<<0U)

// R2 Configuration

#define HSEM_R2_LOCK            (0x1U<<31U)
#define HSEM_R2_MASTERID        (0xFFU<<8U)
#define HSEM_R2_MASTERID_0      (0x1U<<8U)
#define HSEM_R2_PROCID          (0xFFU<<0U)
#define HSEM_R2_PROCID_0        (0x1U<<0U)

// R3 Configuration

#define HSEM_R3_LOCK            (0x1U<<31U)
#define HSEM_R3_MASTERID        (0xFFU<<8U)
#define HSEM_R3_MASTERID_0      (0x1U<<8U)
#define HSEM_R3_PROCID          (0xFFU<<0U)
#define HSEM_R3_PROCID_0        (0x1U<<0U)

// R4 Configuration

#define HSEM_R4_LOCK            (0x1U<<31U)
#define HSEM_R4_MASTERID        (0xFFU<<8U)
#define HSEM_R4_MASTERID_0      (0x1U<<8U)
#define HSEM_R4_PROCID          (0xFFU<<0U)
#define HSEM_R4_PROCID_0        (0x1U<<0U)

// R5 Configuration

#define HSEM_R5_LOCK            (0x1U<<31U)
#define HSEM_R5_MASTERID        (0xFFU<<8U)
#define HSEM_R5_MASTERID_0      (0x1U<<8U)
#define HSEM_R5_PROCID          (0xFFU<<0U)
#define HSEM_R5_PROCID_0        (0x1U<<0U)

// R6 Configuration

#define HSEM_R6_LOCK            (0x1U<<31U)
#define HSEM_R6_MASTERID        (0xFFU<<8U)
#define HSEM_R6_MASTERID_0      (0x1U<<8U)
#define HSEM_R6_PROCID          (0xFFU<<0U)
#define HSEM_R6_PROCID_0        (0x1U<<0U)

// R7 Configuration

#define HSEM_R7_LOCK            (0x1U<<31U)
#define HSEM_R7_MASTERID        (0xFFU<<8U)
#define HSEM_R7_MASTERID_0      (0x1U<<8U)
#define HSEM_R7_PROCID          (0xFFU<<0U)
#define HSEM_R7_PROCID_0        (0x1U<<0U)

// R8 Configuration

#define HSEM_R8_LOCK            (0x1U<<31U)
#define HSEM_R8_MASTERID        (0xFFU<<8U)
#define HSEM_R8_MASTERID_0      (0x1U<<8U)
#define HSEM_R8_PROCID          (0xFFU<<0U)
#define HSEM_R8_PROCID_0        (0x1U<<0U)

// R9 Configuration

#define HSEM_R9_LOCK            (0x1U<<31U)
#define HSEM_R9_MASTERID        (0xFFU<<8U)
#define HSEM_R9_MASTERID_0      (0x1U<<8U)
#define HSEM_R9_PROCID          (0xFFU<<0U)
#define HSEM_R9_PROCID_0        (0x1U<<0U)

// R10 Configuration

#define HSEM_R10_LOCK           (0x1U<<31U)
#define HSEM_R10_MASTERID       (0xFFU<<8U)
#define HSEM_R10_MASTERID_0     (0x1U<<8U)
#define HSEM_R10_PROCID         (0xFFU<<0U)
#define HSEM_R10_PROCID_0       (0x1U<<0U)

// R11 Configuration

#define HSEM_R11_LOCK           (0x1U<<31U)
#define HSEM_R11_MASTERID       (0xFFU<<8U)
#define HSEM_R11_MASTERID_0     (0x1U<<8U)
#define HSEM_R11_PROCID         (0xFFU<<0U)
#define HSEM_R11_PROCID_0       (0x1U<<0U)

// R12 Configuration

#define HSEM_R12_LOCK           (0x1U<<31U)
#define HSEM_R12_MASTERID       (0xFFU<<8U)
#define HSEM_R12_MASTERID_0     (0x1U<<8U)
#define HSEM_R12_PROCID         (0xFFU<<0U)
#define HSEM_R12_PROCID_0       (0x1U<<0U)

// R13 Configuration

#define HSEM_R13_LOCK           (0x1U<<31U)
#define HSEM_R13_MASTERID       (0xFFU<<8U)
#define HSEM_R13_MASTERID_0     (0x1U<<8U)
#define HSEM_R13_PROCID         (0xFFU<<0U)
#define HSEM_R13_PROCID_0       (0x1U<<0U)

// R14 Configuration

#define HSEM_R14_LOCK           (0x1U<<31U)
#define HSEM_R14_MASTERID       (0xFFU<<8U)
#define HSEM_R14_MASTERID_0     (0x1U<<8U)
#define HSEM_R14_PROCID         (0xFFU<<0U)
#define HSEM_R14_PROCID_0       (0x1U<<0U)

// R15 Configuration

#define HSEM_R15_LOCK           (0x1U<<31U)
#define HSEM_R15_MASTERID       (0xFFU<<8U)
#define HSEM_R15_MASTERID_0     (0x1U<<8U)
#define HSEM_R15_PROCID         (0xFFU<<0U)
#define HSEM_R15_PROCID_0       (0x1U<<0U)

// R16 Configuration

#define HSEM_R16_LOCK           (0x1U<<31U)
#define HSEM_R16_MASTERID       (0xFFU<<8U)
#define HSEM_R16_MASTERID_0     (0x1U<<8U)
#define HSEM_R16_PROCID         (0xFFU<<0U)
#define HSEM_R16_PROCID_0       (0x1U<<0U)

// R17 Configuration

#define HSEM_R17_LOCK           (0x1U<<31U)
#define HSEM_R17_MASTERID       (0xFFU<<8U)
#define HSEM_R17_MASTERID_0     (0x1U<<8U)
#define HSEM_R17_PROCID         (0xFFU<<0U)
#define HSEM_R17_PROCID_0       (0x1U<<0U)

// R18 Configuration

#define HSEM_R18_LOCK           (0x1U<<31U)
#define HSEM_R18_MASTERID       (0xFFU<<8U)
#define HSEM_R18_MASTERID_0     (0x1U<<8U)
#define HSEM_R18_PROCID         (0xFFU<<0U)
#define HSEM_R18_PROCID_0       (0x1U<<0U)

// R19 Configuration

#define HSEM_R19_LOCK           (0x1U<<31U)
#define HSEM_R19_MASTERID       (0xFFU<<8U)
#define HSEM_R19_MASTERID_0     (0x1U<<8U)
#define HSEM_R19_PROCID         (0xFFU<<0U)
#define HSEM_R19_PROCID_0       (0x1U<<0U)

// R20 Configuration

#define HSEM_R20_LOCK           (0x1U<<31U)
#define HSEM_R20_MASTERID       (0xFFU<<8U)
#define HSEM_R20_MASTERID_0     (0x1U<<8U)
#define HSEM_R20_PROCID         (0xFFU<<0U)
#define HSEM_R20_PROCID_0       (0x1U<<0U)

// R21 Configuration

#define HSEM_R21_LOCK           (0x1U<<31U)
#define HSEM_R21_MASTERID       (0xFFU<<8U)
#define HSEM_R21_MASTERID_0     (0x1U<<8U)
#define HSEM_R21_PROCID         (0xFFU<<0U)
#define HSEM_R21_PROCID_0       (0x1U<<0U)

// R22 Configuration

#define HSEM_R22_LOCK           (0x1U<<31U)
#define HSEM_R22_MASTERID       (0xFFU<<8U)
#define HSEM_R22_MASTERID_0     (0x1U<<8U)
#define HSEM_R22_PROCID         (0xFFU<<0U)
#define HSEM_R22_PROCID_0       (0x1U<<0U)

// R23 Configuration

#define HSEM_R23_LOCK           (0x1U<<31U)
#define HSEM_R23_MASTERID       (0xFFU<<8U)
#define HSEM_R23_MASTERID_0     (0x1U<<8U)
#define HSEM_R23_PROCID         (0xFFU<<0U)
#define HSEM_R23_PROCID_0       (0x1U<<0U)

// R24 Configuration

#define HSEM_R24_LOCK           (0x1U<<31U)
#define HSEM_R24_MASTERID       (0xFFU<<8U)
#define HSEM_R24_MASTERID_0     (0x1U<<8U)
#define HSEM_R24_PROCID         (0xFFU<<0U)
#define HSEM_R24_PROCID_0       (0x1U<<0U)

// R25 Configuration

#define HSEM_R25_LOCK           (0x1U<<31U)
#define HSEM_R25_MASTERID       (0xFFU<<8U)
#define HSEM_R25_MASTERID_0     (0x1U<<8U)
#define HSEM_R25_PROCID         (0xFFU<<0U)
#define HSEM_R25_PROCID_0       (0x1U<<0U)

// R26 Configuration

#define HSEM_R26_LOCK           (0x1U<<31U)
#define HSEM_R26_MASTERID       (0xFFU<<8U)
#define HSEM_R26_MASTERID_0     (0x1U<<8U)
#define HSEM_R26_PROCID         (0xFFU<<0U)
#define HSEM_R26_PROCID_0       (0x1U<<0U)

// R27 Configuration

#define HSEM_R27_LOCK           (0x1U<<31U)
#define HSEM_R27_MASTERID       (0xFFU<<8U)
#define HSEM_R27_MASTERID_0     (0x1U<<8U)
#define HSEM_R27_PROCID         (0xFFU<<0U)
#define HSEM_R27_PROCID_0       (0x1U<<0U)

// R28 Configuration

#define HSEM_R28_LOCK           (0x1U<<31U)
#define HSEM_R28_MASTERID       (0xFFU<<8U)
#define HSEM_R28_MASTERID_0     (0x1U<<8U)
#define HSEM_R28_PROCID         (0xFFU<<0U)
#define HSEM_R28_PROCID_0       (0x1U<<0U)

// R29 Configuration

#define HSEM_R29_LOCK           (0x1U<<31U)
#define HSEM_R29_MASTERID       (0xFFU<<8U)
#define HSEM_R29_MASTERID_0     (0x1U<<8U)
#define HSEM_R29_PROCID         (0xFFU<<0U)
#define HSEM_R29_PROCID_0       (0x1U<<0U)

// R30 Configuration

#define HSEM_R30_LOCK           (0x1U<<31U)
#define HSEM_R30_MASTERID       (0xFFU<<8U)
#define HSEM_R30_MASTERID_0     (0x1U<<8U)
#define HSEM_R30_PROCID         (0xFFU<<0U)
#define HSEM_R30_PROCID_0       (0x1U<<0U)

// R31 Configuration

#define HSEM_R31_LOCK           (0x1U<<31U)
#define HSEM_R31_MASTERID       (0xFFU<<8U)
#define HSEM_R31_MASTERID_0     (0x1U<<8U)
#define HSEM_R31_PROCID         (0xFFU<<0U)
#define HSEM_R31_PROCID_0       (0x1U<<0U)

// RLR0 Configuration

#define HSEM_RLR0_LOCK          (0x1U<<31U)
#define HSEM_RLR0_MASTERID      (0xFFU<<8U)
#define HSEM_RLR0_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR0_PROCID        (0xFFU<<0U)
#define HSEM_RLR0_PROCID_0      (0x1U<<0U)

// RLR1 Configuration

#define HSEM_RLR1_LOCK          (0x1U<<31U)
#define HSEM_RLR1_MASTERID      (0xFFU<<8U)
#define HSEM_RLR1_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR1_PROCID        (0xFFU<<0U)
#define HSEM_RLR1_PROCID_0      (0x1U<<0U)

// RLR2 Configuration

#define HSEM_RLR2_LOCK          (0x1U<<31U)
#define HSEM_RLR2_MASTERID      (0xFFU<<8U)
#define HSEM_RLR2_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR2_PROCID        (0xFFU<<0U)
#define HSEM_RLR2_PROCID_0      (0x1U<<0U)

// RLR3 Configuration

#define HSEM_RLR3_LOCK          (0x1U<<31U)
#define HSEM_RLR3_MASTERID      (0xFFU<<8U)
#define HSEM_RLR3_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR3_PROCID        (0xFFU<<0U)
#define HSEM_RLR3_PROCID_0      (0x1U<<0U)

// RLR4 Configuration

#define HSEM_RLR4_LOCK          (0x1U<<31U)
#define HSEM_RLR4_MASTERID      (0xFFU<<8U)
#define HSEM_RLR4_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR4_PROCID        (0xFFU<<0U)
#define HSEM_RLR4_PROCID_0      (0x1U<<0U)

// RLR5 Configuration

#define HSEM_RLR5_LOCK          (0x1U<<31U)
#define HSEM_RLR5_MASTERID      (0xFFU<<8U)
#define HSEM_RLR5_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR5_PROCID        (0xFFU<<0U)
#define HSEM_RLR5_PROCID_0      (0x1U<<0U)

// RLR6 Configuration

#define HSEM_RLR6_LOCK          (0x1U<<31U)
#define HSEM_RLR6_MASTERID      (0xFFU<<8U)
#define HSEM_RLR6_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR6_PROCID        (0xFFU<<0U)
#define HSEM_RLR6_PROCID_0      (0x1U<<0U)

// RLR7 Configuration

#define HSEM_RLR7_LOCK          (0x1U<<31U)
#define HSEM_RLR7_MASTERID      (0xFFU<<8U)
#define HSEM_RLR7_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR7_PROCID        (0xFFU<<0U)
#define HSEM_RLR7_PROCID_0      (0x1U<<0U)

// RLR8 Configuration

#define HSEM_RLR8_LOCK          (0x1U<<31U)
#define HSEM_RLR8_MASTERID      (0xFFU<<8U)
#define HSEM_RLR8_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR8_PROCID        (0xFFU<<0U)
#define HSEM_RLR8_PROCID_0      (0x1U<<0U)

// RLR9 Configuration

#define HSEM_RLR9_LOCK          (0x1U<<31U)
#define HSEM_RLR9_MASTERID      (0xFFU<<8U)
#define HSEM_RLR9_MASTERID_0    (0x1U<<8U)
#define HSEM_RLR9_PROCID        (0xFFU<<0U)
#define HSEM_RLR9_PROCID_0      (0x1U<<0U)

// RLR10 Configuration

#define HSEM_RLR10_LOCK         (0x1U<<31U)
#define HSEM_RLR10_MASTERID     (0xFFU<<8U)
#define HSEM_RLR10_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR10_PROCID       (0xFFU<<0U)
#define HSEM_RLR10_PROCID_0     (0x1U<<0U)

// RLR11 Configuration

#define HSEM_RLR11_LOCK         (0x1U<<31U)
#define HSEM_RLR11_MASTERID     (0xFFU<<8U)
#define HSEM_RLR11_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR11_PROCID       (0xFFU<<0U)
#define HSEM_RLR11_PROCID_0     (0x1U<<0U)

// RLR12 Configuration

#define HSEM_RLR12_LOCK         (0x1U<<31U)
#define HSEM_RLR12_MASTERID     (0xFFU<<8U)
#define HSEM_RLR12_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR12_PROCID       (0xFFU<<0U)
#define HSEM_RLR12_PROCID_0     (0x1U<<0U)

// RLR13 Configuration

#define HSEM_RLR13_LOCK         (0x1U<<31U)
#define HSEM_RLR13_MASTERID     (0xFFU<<8U)
#define HSEM_RLR13_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR13_PROCID       (0xFFU<<0U)
#define HSEM_RLR13_PROCID_0     (0x1U<<0U)

// RLR14 Configuration

#define HSEM_RLR14_LOCK         (0x1U<<31U)
#define HSEM_RLR14_MASTERID     (0xFFU<<8U)
#define HSEM_RLR14_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR14_PROCID       (0xFFU<<0U)
#define HSEM_RLR14_PROCID_0     (0x1U<<0U)

// RLR15 Configuration

#define HSEM_RLR15_LOCK         (0x1U<<31U)
#define HSEM_RLR15_MASTERID     (0xFFU<<8U)
#define HSEM_RLR15_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR15_PROCID       (0xFFU<<0U)
#define HSEM_RLR15_PROCID_0     (0x1U<<0U)

// RLR16 Configuration

#define HSEM_RLR16_LOCK         (0x1U<<31U)
#define HSEM_RLR16_MASTERID     (0xFFU<<8U)
#define HSEM_RLR16_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR16_PROCID       (0xFFU<<0U)
#define HSEM_RLR16_PROCID_0     (0x1U<<0U)

// RLR17 Configuration

#define HSEM_RLR17_LOCK         (0x1U<<31U)
#define HSEM_RLR17_MASTERID     (0xFFU<<8U)
#define HSEM_RLR17_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR17_PROCID       (0xFFU<<0U)
#define HSEM_RLR17_PROCID_0     (0x1U<<0U)

// RLR18 Configuration

#define HSEM_RLR18_LOCK         (0x1U<<31U)
#define HSEM_RLR18_MASTERID     (0xFFU<<8U)
#define HSEM_RLR18_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR18_PROCID       (0xFFU<<0U)
#define HSEM_RLR18_PROCID_0     (0x1U<<0U)

// RLR19 Configuration

#define HSEM_RLR19_LOCK         (0x1U<<31U)
#define HSEM_RLR19_MASTERID     (0xFFU<<8U)
#define HSEM_RLR19_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR19_PROCID       (0xFFU<<0U)
#define HSEM_RLR19_PROCID_0     (0x1U<<0U)

// RLR20 Configuration

#define HSEM_RLR20_LOCK         (0x1U<<31U)
#define HSEM_RLR20_MASTERID     (0xFFU<<8U)
#define HSEM_RLR20_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR20_PROCID       (0xFFU<<0U)
#define HSEM_RLR20_PROCID_0     (0x1U<<0U)

// RLR21 Configuration

#define HSEM_RLR21_LOCK         (0x1U<<31U)
#define HSEM_RLR21_MASTERID     (0xFFU<<8U)
#define HSEM_RLR21_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR21_PROCID       (0xFFU<<0U)
#define HSEM_RLR21_PROCID_0     (0x1U<<0U)

// RLR22 Configuration

#define HSEM_RLR22_LOCK         (0x1U<<31U)
#define HSEM_RLR22_MASTERID     (0xFFU<<8U)
#define HSEM_RLR22_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR22_PROCID       (0xFFU<<0U)
#define HSEM_RLR22_PROCID_0     (0x1U<<0U)

// RLR23 Configuration

#define HSEM_RLR23_LOCK         (0x1U<<31U)
#define HSEM_RLR23_MASTERID     (0xFFU<<8U)
#define HSEM_RLR23_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR23_PROCID       (0xFFU<<0U)
#define HSEM_RLR23_PROCID_0     (0x1U<<0U)

// RLR24 Configuration

#define HSEM_RLR24_LOCK         (0x1U<<31U)
#define HSEM_RLR24_MASTERID     (0xFFU<<8U)
#define HSEM_RLR24_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR24_PROCID       (0xFFU<<0U)
#define HSEM_RLR24_PROCID_0     (0x1U<<0U)

// RLR25 Configuration

#define HSEM_RLR25_LOCK         (0x1U<<31U)
#define HSEM_RLR25_MASTERID     (0xFFU<<8U)
#define HSEM_RLR25_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR25_PROCID       (0xFFU<<0U)
#define HSEM_RLR25_PROCID_0     (0x1U<<0U)

// RLR26 Configuration

#define HSEM_RLR26_LOCK         (0x1U<<31U)
#define HSEM_RLR26_MASTERID     (0xFFU<<8U)
#define HSEM_RLR26_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR26_PROCID       (0xFFU<<0U)
#define HSEM_RLR26_PROCID_0     (0x1U<<0U)

// RLR27 Configuration

#define HSEM_RLR27_LOCK         (0x1U<<31U)
#define HSEM_RLR27_MASTERID     (0xFFU<<8U)
#define HSEM_RLR27_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR27_PROCID       (0xFFU<<0U)
#define HSEM_RLR27_PROCID_0     (0x1U<<0U)

// RLR28 Configuration

#define HSEM_RLR28_LOCK         (0x1U<<31U)
#define HSEM_RLR28_MASTERID     (0xFFU<<8U)
#define HSEM_RLR28_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR28_PROCID       (0xFFU<<0U)
#define HSEM_RLR28_PROCID_0     (0x1U<<0U)

// RLR29 Configuration

#define HSEM_RLR29_LOCK         (0x1U<<31U)
#define HSEM_RLR29_MASTERID     (0xFFU<<8U)
#define HSEM_RLR29_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR29_PROCID       (0xFFU<<0U)
#define HSEM_RLR29_PROCID_0     (0x1U<<0U)

// RLR30 Configuration

#define HSEM_RLR30_LOCK         (0x1U<<31U)
#define HSEM_RLR30_MASTERID     (0xFFU<<8U)
#define HSEM_RLR30_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR30_PROCID       (0xFFU<<0U)
#define HSEM_RLR30_PROCID_0     (0x1U<<0U)

// RLR31 Configuration

#define HSEM_RLR31_LOCK         (0x1U<<31U)
#define HSEM_RLR31_MASTERID     (0xFFU<<8U)
#define HSEM_RLR31_MASTERID_0   (0x1U<<8U)
#define HSEM_RLR31_PROCID       (0xFFU<<0U)
#define HSEM_RLR31_PROCID_0     (0x1U<<0U)

// IER Configuration

#define HSEM_IER_ISEM31         (0x1U<<31U)
#define HSEM_IER_ISEM30         (0x1U<<30U)
#define HSEM_IER_ISEM29         (0x1U<<29U)
#define HSEM_IER_ISEM28         (0x1U<<28U)
#define HSEM_IER_ISEM27         (0x1U<<27U)
#define HSEM_IER_ISEM26         (0x1U<<26U)
#define HSEM_IER_ISEM25         (0x1U<<25U)
#define HSEM_IER_ISEM24         (0x1U<<24U)
#define HSEM_IER_ISEM23         (0x1U<<23U)
#define HSEM_IER_ISEM22         (0x1U<<22U)
#define HSEM_IER_ISEM21         (0x1U<<21U)
#define HSEM_IER_ISEM20         (0x1U<<20U)
#define HSEM_IER_ISEM19         (0x1U<<19U)
#define HSEM_IER_ISEM18         (0x1U<<18U)
#define HSEM_IER_ISEM17         (0x1U<<17U)
#define HSEM_IER_ISEM16         (0x1U<<16U)
#define HSEM_IER_ISEM15         (0x1U<<15U)
#define HSEM_IER_ISEM14         (0x1U<<14U)
#define HSEM_IER_ISEM13         (0x1U<<13U)
#define HSEM_IER_ISEM12         (0x1U<<12U)
#define HSEM_IER_ISEM11         (0x1U<<11U)
#define HSEM_IER_ISEM10         (0x1U<<10U)
#define HSEM_IER_ISEM9          (0x1U<<9U)
#define HSEM_IER_ISEM8          (0x1U<<8U)
#define HSEM_IER_ISEM7          (0x1U<<7U)
#define HSEM_IER_ISEM6          (0x1U<<6U)
#define HSEM_IER_ISEM5          (0x1U<<5U)
#define HSEM_IER_ISEM4          (0x1U<<4U)
#define HSEM_IER_ISEM3          (0x1U<<3U)
#define HSEM_IER_ISEM2          (0x1U<<2U)
#define HSEM_IER_ISEM1          (0x1U<<1U)
#define HSEM_IER_ISEM0          (0x1U<<0U)

// ICR Configuration

#define HSEM_ICR_ISEM31         (0x1U<<31U)
#define HSEM_ICR_ISEM30         (0x1U<<30U)
#define HSEM_ICR_ISEM29         (0x1U<<29U)
#define HSEM_ICR_ISEM28         (0x1U<<28U)
#define HSEM_ICR_ISEM27         (0x1U<<27U)
#define HSEM_ICR_ISEM26         (0x1U<<26U)
#define HSEM_ICR_ISEM25         (0x1U<<25U)
#define HSEM_ICR_ISEM24         (0x1U<<24U)
#define HSEM_ICR_ISEM23         (0x1U<<23U)
#define HSEM_ICR_ISEM22         (0x1U<<22U)
#define HSEM_ICR_ISEM21         (0x1U<<21U)
#define HSEM_ICR_ISEM20         (0x1U<<20U)
#define HSEM_ICR_ISEM19         (0x1U<<19U)
#define HSEM_ICR_ISEM18         (0x1U<<18U)
#define HSEM_ICR_ISEM17         (0x1U<<17U)
#define HSEM_ICR_ISEM16         (0x1U<<16U)
#define HSEM_ICR_ISEM15         (0x1U<<15U)
#define HSEM_ICR_ISEM14         (0x1U<<14U)
#define HSEM_ICR_ISEM13         (0x1U<<13U)
#define HSEM_ICR_ISEM12         (0x1U<<12U)
#define HSEM_ICR_ISEM11         (0x1U<<11U)
#define HSEM_ICR_ISEM10         (0x1U<<10U)
#define HSEM_ICR_ISEM9          (0x1U<<9U)
#define HSEM_ICR_ISEM8          (0x1U<<8U)
#define HSEM_ICR_ISEM7          (0x1U<<7U)
#define HSEM_ICR_ISEM6          (0x1U<<6U)
#define HSEM_ICR_ISEM5          (0x1U<<5U)
#define HSEM_ICR_ISEM4          (0x1U<<4U)
#define HSEM_ICR_ISEM3          (0x1U<<3U)
#define HSEM_ICR_ISEM2          (0x1U<<2U)
#define HSEM_ICR_ISEM1          (0x1U<<1U)
#define HSEM_ICR_ISEM0          (0x1U<<0U)

// ISR Configuration

#define HSEM_ISR_ISEM31         (0x1U<<31U)
#define HSEM_ISR_ISEM30         (0x1U<<30U)
#define HSEM_ISR_ISEM29         (0x1U<<29U)
#define HSEM_ISR_ISEM28         (0x1U<<28U)
#define HSEM_ISR_ISEM27         (0x1U<<27U)
#define HSEM_ISR_ISEM26         (0x1U<<26U)
#define HSEM_ISR_ISEM25         (0x1U<<25U)
#define HSEM_ISR_ISEM24         (0x1U<<24U)
#define HSEM_ISR_ISEM23         (0x1U<<23U)
#define HSEM_ISR_ISEM22         (0x1U<<22U)
#define HSEM_ISR_ISEM21         (0x1U<<21U)
#define HSEM_ISR_ISEM20         (0x1U<<20U)
#define HSEM_ISR_ISEM19         (0x1U<<19U)
#define HSEM_ISR_ISEM18         (0x1U<<18U)
#define HSEM_ISR_ISEM17         (0x1U<<17U)
#define HSEM_ISR_ISEM16         (0x1U<<16U)
#define HSEM_ISR_ISEM15         (0x1U<<15U)
#define HSEM_ISR_ISEM14         (0x1U<<14U)
#define HSEM_ISR_ISEM13         (0x1U<<13U)
#define HSEM_ISR_ISEM12         (0x1U<<12U)
#define HSEM_ISR_ISEM11         (0x1U<<11U)
#define HSEM_ISR_ISEM10         (0x1U<<10U)
#define HSEM_ISR_ISEM9          (0x1U<<9U)
#define HSEM_ISR_ISEM8          (0x1U<<8U)
#define HSEM_ISR_ISEM7          (0x1U<<7U)
#define HSEM_ISR_ISEM6          (0x1U<<6U)
#define HSEM_ISR_ISEM5          (0x1U<<5U)
#define HSEM_ISR_ISEM4          (0x1U<<4U)
#define HSEM_ISR_ISEM3          (0x1U<<3U)
#define HSEM_ISR_ISEM2          (0x1U<<2U)
#define HSEM_ISR_ISEM1          (0x1U<<1U)
#define HSEM_ISR_ISEM0          (0x1U<<0U)

// MISR Configuration

#define HSEM_MISR_ISEM31        (0x1U<<31U)
#define HSEM_MISR_ISEM30        (0x1U<<30U)
#define HSEM_MISR_ISEM29        (0x1U<<29U)
#define HSEM_MISR_ISEM28        (0x1U<<28U)
#define HSEM_MISR_ISEM27        (0x1U<<27U)
#define HSEM_MISR_ISEM26        (0x1U<<26U)
#define HSEM_MISR_ISEM25        (0x1U<<25U)
#define HSEM_MISR_ISEM24        (0x1U<<24U)
#define HSEM_MISR_ISEM23        (0x1U<<23U)
#define HSEM_MISR_ISEM22        (0x1U<<22U)
#define HSEM_MISR_ISEM21        (0x1U<<21U)
#define HSEM_MISR_ISEM20        (0x1U<<20U)
#define HSEM_MISR_ISEM19        (0x1U<<19U)
#define HSEM_MISR_ISEM18        (0x1U<<18U)
#define HSEM_MISR_ISEM17        (0x1U<<17U)
#define HSEM_MISR_ISEM16        (0x1U<<16U)
#define HSEM_MISR_ISEM15        (0x1U<<15U)
#define HSEM_MISR_ISEM14        (0x1U<<14U)
#define HSEM_MISR_ISEM13        (0x1U<<13U)
#define HSEM_MISR_ISEM12        (0x1U<<12U)
#define HSEM_MISR_ISEM11        (0x1U<<11U)
#define HSEM_MISR_ISEM10        (0x1U<<10U)
#define HSEM_MISR_ISEM9         (0x1U<<9U)
#define HSEM_MISR_ISEM8         (0x1U<<8U)
#define HSEM_MISR_ISEM7         (0x1U<<7U)
#define HSEM_MISR_ISEM6         (0x1U<<6U)
#define HSEM_MISR_ISEM5         (0x1U<<5U)
#define HSEM_MISR_ISEM4         (0x1U<<4U)
#define HSEM_MISR_ISEM3         (0x1U<<3U)
#define HSEM_MISR_ISEM2         (0x1U<<2U)
#define HSEM_MISR_ISEM1         (0x1U<<1U)
#define HSEM_MISR_ISEM0         (0x1U<<0U)

// CR Configuration

#define HSEM_CR_KEY             (0xFFFFU<<16U)
#define HSEM_CR_KEY_0           (0x1U<<16U)
#define HSEM_CR_MASTERID        (0xFFU<<8U)
#define HSEM_CR_MASTERID_0      (0x1U<<8U)

// KEYR Configuration

#define HSEM_KEYR_KEY           (0xFFFFU<<16U)
#define HSEM_KEYR_KEY_0         (0x1U<<16U)
