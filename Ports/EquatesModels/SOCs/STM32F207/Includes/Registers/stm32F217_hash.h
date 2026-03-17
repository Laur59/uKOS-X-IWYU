/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32F217_hash.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32F217_hash equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// HASH address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    DIN;
    volatile    uint32_t    STR;
    volatile    uint32_t    HR0;
    volatile    uint32_t    HR1;
    volatile    uint32_t    HR2;
    volatile    uint32_t    HR3;
    volatile    uint32_t    HR4;
    volatile    uint32_t    IMR;
    volatile    uint32_t    SR;
    volatile    uint32_t    RESERVED0[52];
    volatile    uint32_t    CSR0;
    volatile    uint32_t    CSR1;
    volatile    uint32_t    CSR2;
    volatile    uint32_t    CSR3;
    volatile    uint32_t    CSR4;
    volatile    uint32_t    CSR5;
    volatile    uint32_t    CSR6;
    volatile    uint32_t    CSR7;
    volatile    uint32_t    CSR8;
    volatile    uint32_t    CSR9;
    volatile    uint32_t    CSR10;
    volatile    uint32_t    CSR11;
    volatile    uint32_t    CSR12;
    volatile    uint32_t    CSR13;
    volatile    uint32_t    CSR14;
    volatile    uint32_t    CSR15;
    volatile    uint32_t    CSR16;
    volatile    uint32_t    CSR17;
    volatile    uint32_t    CSR18;
    volatile    uint32_t    CSR19;
    volatile    uint32_t    CSR20;
    volatile    uint32_t    CSR21;
    volatile    uint32_t    CSR22;
    volatile    uint32_t    CSR23;
    volatile    uint32_t    CSR24;
    volatile    uint32_t    CSR25;
    volatile    uint32_t    CSR26;
    volatile    uint32_t    CSR27;
    volatile    uint32_t    CSR28;
    volatile    uint32_t    CSR29;
    volatile    uint32_t    CSR30;
    volatile    uint32_t    CSR31;
    volatile    uint32_t    CSR32;
    volatile    uint32_t    CSR33;
    volatile    uint32_t    CSR34;
    volatile    uint32_t    CSR35;
    volatile    uint32_t    CSR36;
    volatile    uint32_t    CSR37;
    volatile    uint32_t    CSR38;
    volatile    uint32_t    CSR39;
    volatile    uint32_t    CSR40;
    volatile    uint32_t    CSR41;
    volatile    uint32_t    CSR42;
    volatile    uint32_t    CSR43;
    volatile    uint32_t    CSR44;
    volatile    uint32_t    CSR45;
    volatile    uint32_t    CSR46;
    volatile    uint32_t    CSR47;
    volatile    uint32_t    CSR48;
    volatile    uint32_t    CSR49;
    volatile    uint32_t    CSR50;
} HASH_TypeDef;

#ifdef __cplusplus
#define HASH    reinterpret_cast<HASH_TypeDef *>(0x50060400U)

#else
#define HASH    ((HASH_TypeDef *)0x50060400U)
#endif

// CR Configuration

#define HASH_CR_INIT        (0x1U<<2)
#define HASH_CR_DMAE        (0x1U<<3)
#define HASH_CR_DATATYPE    (0x3U<<4)
#define HASH_CR_DATATYPE_0  (0x1U<<4)
#define HASH_CR_MODE        (0x1U<<6)
#define HASH_CR_ALGO        (0x1U<<7)
#define HASH_CR_NBW         (0xFU<<8)
#define HASH_CR_NBW_0       (0x1U<<8)
#define HASH_CR_DINNE       (0x1U<<12)
#define HASH_CR_LKEY        (0x1U<<16)

// DIN Configuration

#define HASH_DIN_DATAIN     (0xFFFFFFFFU<<0)
#define HASH_DIN_DATAIN_0   (0x1U<<0)

// STR Configuration

#define HASH_STR_NBLW       (0x1FU<<0)
#define HASH_STR_NBLW_0     (0x1U<<0)
#define HASH_STR_DCAL       (0x1U<<8)

// HR0 Configuration

#define HASH_HR0_H0         (0xFFFFFFFFU<<0)
#define HASH_HR0_H0_0       (0x1U<<0)

// HR1 Configuration

#define HASH_HR1_H1         (0xFFFFFFFFU<<0)
#define HASH_HR1_H1_0       (0x1U<<0)

// HR2 Configuration

#define HASH_HR2_H2         (0xFFFFFFFFU<<0)
#define HASH_HR2_H2_0       (0x1U<<0)

// HR3 Configuration

#define HASH_HR3_H3         (0xFFFFFFFFU<<0)
#define HASH_HR3_H3_0       (0x1U<<0)

// HR4 Configuration

#define HASH_HR4_H4         (0xFFFFFFFFU<<0)
#define HASH_HR4_H4_0       (0x1U<<0)

// IMR Configuration

#define HASH_IMR_DINIE      (0x1U<<0)
#define HASH_IMR_DCIE       (0x1U<<1)

// SR Configuration

#define HASH_SR_DINIS       (0x1U<<0)
#define HASH_SR_DCIS        (0x1U<<1)
#define HASH_SR_DMAS        (0x1U<<2)
#define HASH_SR_BUSY        (0x1U<<3)

// CSR0 Configuration

#define HASH_CSR0_CSR0      (0xFFFFFFFFU<<0)
#define HASH_CSR0_CSR0_0    (0x1U<<0)

// CSR1 Configuration

#define HASH_CSR1_CSR1      (0xFFFFFFFFU<<0)
#define HASH_CSR1_CSR1_0    (0x1U<<0)

// CSR2 Configuration

#define HASH_CSR2_CSR2      (0xFFFFFFFFU<<0)
#define HASH_CSR2_CSR2_0    (0x1U<<0)

// CSR3 Configuration

#define HASH_CSR3_CSR3      (0xFFFFFFFFU<<0)
#define HASH_CSR3_CSR3_0    (0x1U<<0)

// CSR4 Configuration

#define HASH_CSR4_CSR4      (0xFFFFFFFFU<<0)
#define HASH_CSR4_CSR4_0    (0x1U<<0)

// CSR5 Configuration

#define HASH_CSR5_CSR5      (0xFFFFFFFFU<<0)
#define HASH_CSR5_CSR5_0    (0x1U<<0)

// CSR6 Configuration

#define HASH_CSR6_CSR6      (0xFFFFFFFFU<<0)
#define HASH_CSR6_CSR6_0    (0x1U<<0)

// CSR7 Configuration

#define HASH_CSR7_CSR7      (0xFFFFFFFFU<<0)
#define HASH_CSR7_CSR7_0    (0x1U<<0)

// CSR8 Configuration

#define HASH_CSR8_CSR8      (0xFFFFFFFFU<<0)
#define HASH_CSR8_CSR8_0    (0x1U<<0)

// CSR9 Configuration

#define HASH_CSR9_CSR9      (0xFFFFFFFFU<<0)
#define HASH_CSR9_CSR9_0    (0x1U<<0)

// CSR10 Configuration

#define HASH_CSR10_CSR10    (0xFFFFFFFFU<<0)
#define HASH_CSR10_CSR10_0  (0x1U<<0)

// CSR11 Configuration

#define HASH_CSR11_CSR11    (0xFFFFFFFFU<<0)
#define HASH_CSR11_CSR11_0  (0x1U<<0)

// CSR12 Configuration

#define HASH_CSR12_CSR12    (0xFFFFFFFFU<<0)
#define HASH_CSR12_CSR12_0  (0x1U<<0)

// CSR13 Configuration

#define HASH_CSR13_CSR13    (0xFFFFFFFFU<<0)
#define HASH_CSR13_CSR13_0  (0x1U<<0)

// CSR14 Configuration

#define HASH_CSR14_CSR14    (0xFFFFFFFFU<<0)
#define HASH_CSR14_CSR14_0  (0x1U<<0)

// CSR15 Configuration

#define HASH_CSR15_CSR15    (0xFFFFFFFFU<<0)
#define HASH_CSR15_CSR15_0  (0x1U<<0)

// CSR16 Configuration

#define HASH_CSR16_CSR16    (0xFFFFFFFFU<<0)
#define HASH_CSR16_CSR16_0  (0x1U<<0)

// CSR17 Configuration

#define HASH_CSR17_CSR17    (0xFFFFFFFFU<<0)
#define HASH_CSR17_CSR17_0  (0x1U<<0)

// CSR18 Configuration

#define HASH_CSR18_CSR18    (0xFFFFFFFFU<<0)
#define HASH_CSR18_CSR18_0  (0x1U<<0)

// CSR19 Configuration

#define HASH_CSR19_CSR19    (0xFFFFFFFFU<<0)
#define HASH_CSR19_CSR19_0  (0x1U<<0)

// CSR20 Configuration

#define HASH_CSR20_CSR20    (0xFFFFFFFFU<<0)
#define HASH_CSR20_CSR20_0  (0x1U<<0)

// CSR21 Configuration

#define HASH_CSR21_CSR21    (0xFFFFFFFFU<<0)
#define HASH_CSR21_CSR21_0  (0x1U<<0)

// CSR22 Configuration

#define HASH_CSR22_CSR22    (0xFFFFFFFFU<<0)
#define HASH_CSR22_CSR22_0  (0x1U<<0)

// CSR23 Configuration

#define HASH_CSR23_CSR23    (0xFFFFFFFFU<<0)
#define HASH_CSR23_CSR23_0  (0x1U<<0)

// CSR24 Configuration

#define HASH_CSR24_CSR24    (0xFFFFFFFFU<<0)
#define HASH_CSR24_CSR24_0  (0x1U<<0)

// CSR25 Configuration

#define HASH_CSR25_CSR25    (0xFFFFFFFFU<<0)
#define HASH_CSR25_CSR25_0  (0x1U<<0)

// CSR26 Configuration

#define HASH_CSR26_CSR26    (0xFFFFFFFFU<<0)
#define HASH_CSR26_CSR26_0  (0x1U<<0)

// CSR27 Configuration

#define HASH_CSR27_CSR27    (0xFFFFFFFFU<<0)
#define HASH_CSR27_CSR27_0  (0x1U<<0)

// CSR28 Configuration

#define HASH_CSR28_CSR28    (0xFFFFFFFFU<<0)
#define HASH_CSR28_CSR28_0  (0x1U<<0)

// CSR29 Configuration

#define HASH_CSR29_CSR29    (0xFFFFFFFFU<<0)
#define HASH_CSR29_CSR29_0  (0x1U<<0)

// CSR30 Configuration

#define HASH_CSR30_CSR30    (0xFFFFFFFFU<<0)
#define HASH_CSR30_CSR30_0  (0x1U<<0)

// CSR31 Configuration

#define HASH_CSR31_CSR31    (0xFFFFFFFFU<<0)
#define HASH_CSR31_CSR31_0  (0x1U<<0)

// CSR32 Configuration

#define HASH_CSR32_CSR32    (0xFFFFFFFFU<<0)
#define HASH_CSR32_CSR32_0  (0x1U<<0)

// CSR33 Configuration

#define HASH_CSR33_CSR33    (0xFFFFFFFFU<<0)
#define HASH_CSR33_CSR33_0  (0x1U<<0)

// CSR34 Configuration

#define HASH_CSR34_CSR34    (0xFFFFFFFFU<<0)
#define HASH_CSR34_CSR34_0  (0x1U<<0)

// CSR35 Configuration

#define HASH_CSR35_CSR35    (0xFFFFFFFFU<<0)
#define HASH_CSR35_CSR35_0  (0x1U<<0)

// CSR36 Configuration

#define HASH_CSR36_CSR36    (0xFFFFFFFFU<<0)
#define HASH_CSR36_CSR36_0  (0x1U<<0)

// CSR37 Configuration

#define HASH_CSR37_CSR37    (0xFFFFFFFFU<<0)
#define HASH_CSR37_CSR37_0  (0x1U<<0)

// CSR38 Configuration

#define HASH_CSR38_CSR38    (0xFFFFFFFFU<<0)
#define HASH_CSR38_CSR38_0  (0x1U<<0)

// CSR39 Configuration

#define HASH_CSR39_CSR39    (0xFFFFFFFFU<<0)
#define HASH_CSR39_CSR39_0  (0x1U<<0)

// CSR40 Configuration

#define HASH_CSR40_CSR40    (0xFFFFFFFFU<<0)
#define HASH_CSR40_CSR40_0  (0x1U<<0)

// CSR41 Configuration

#define HASH_CSR41_CSR41    (0xFFFFFFFFU<<0)
#define HASH_CSR41_CSR41_0  (0x1U<<0)

// CSR42 Configuration

#define HASH_CSR42_CSR42    (0xFFFFFFFFU<<0)
#define HASH_CSR42_CSR42_0  (0x1U<<0)

// CSR43 Configuration

#define HASH_CSR43_CSR43    (0xFFFFFFFFU<<0)
#define HASH_CSR43_CSR43_0  (0x1U<<0)

// CSR44 Configuration

#define HASH_CSR44_CSR44    (0xFFFFFFFFU<<0)
#define HASH_CSR44_CSR44_0  (0x1U<<0)

// CSR45 Configuration

#define HASH_CSR45_CSR45    (0xFFFFFFFFU<<0)
#define HASH_CSR45_CSR45_0  (0x1U<<0)

// CSR46 Configuration

#define HASH_CSR46_CSR46    (0xFFFFFFFFU<<0)
#define HASH_CSR46_CSR46_0  (0x1U<<0)

// CSR47 Configuration

#define HASH_CSR47_CSR47    (0xFFFFFFFFU<<0)
#define HASH_CSR47_CSR47_0  (0x1U<<0)

// CSR48 Configuration

#define HASH_CSR48_CSR48    (0xFFFFFFFFU<<0)
#define HASH_CSR48_CSR48_0  (0x1U<<0)

// CSR49 Configuration

#define HASH_CSR49_CSR49    (0xFFFFFFFFU<<0)
#define HASH_CSR49_CSR49_0  (0x1U<<0)

// CSR50 Configuration

#define HASH_CSR50_CSR50    (0xFFFFFFFFU<<0)
#define HASH_CSR50_CSR50_0  (0x1U<<0)
