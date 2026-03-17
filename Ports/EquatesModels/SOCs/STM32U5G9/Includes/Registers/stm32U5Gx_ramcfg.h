/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_ramcfg.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_ramcfg equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// RAMCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    M1CR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    M1ISR;
    volatile    uint32_t    RESERVED1[7];
    volatile    uint32_t    RAM1ERKEYR;
    volatile    uint32_t    RESERVED2[5];
    volatile    uint32_t    M2CR;
    volatile    uint32_t    M2IER;
    volatile    uint32_t    M2ISR;
    volatile    uint32_t    M2SEAR;
    volatile    uint32_t    M2DEAR;
    volatile    uint32_t    M2ICR;
    volatile    uint32_t    M2WPR1;
    volatile    uint32_t    M2WPR2;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    M2ECCKEYR;
    volatile    uint32_t    M2ERKEYR;
    volatile    uint32_t    RESERVED4[5];
    volatile    uint32_t    M3CR;
    volatile    uint32_t    M3IER;
    volatile    uint32_t    M3ISR;
    volatile    uint32_t    M3SEAR;
    volatile    uint32_t    M3DEAR;
    volatile    uint32_t    M3ICR;
    volatile    uint32_t    RESERVED5[3];
    volatile    uint32_t    M3ECCKEYR;
    volatile    uint32_t    M3ERKEYR;
    volatile    uint32_t    RESERVED6[5];
    volatile    uint32_t    M4CR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    M4ISR;
    volatile    uint32_t    RESERVED8[7];
    volatile    uint32_t    M4ERKEYR;
    volatile    uint32_t    RESERVED9[5];
    volatile    uint32_t    M5CR;
    volatile    uint32_t    M5IER;
    volatile    uint32_t    M5ISR;
    volatile    uint32_t    M5SEAR;
    volatile    uint32_t    M5DEAR;
    volatile    uint32_t    M5ICR;
    volatile    uint32_t    RESERVED10[3];
    volatile    uint32_t    M5ECCKEYR;
    volatile    uint32_t    M5ERKEYR;
    volatile    uint32_t    RESERVED11[5];
    volatile    uint32_t    M6CR;
    volatile    uint32_t    RESERVED12;
    volatile    uint32_t    M6ISR;
    volatile    uint32_t    RESERVED13[7];
    volatile    uint32_t    M6ERKEYR;
} RAMCFG_TypeDef;

#ifdef __cplusplus
#define RAMCFG_NS   reinterpret_cast<RAMCFG_TypeDef *>(0x40026000U)
#define RAMCFG_S    reinterpret_cast<RAMCFG_TypeDef *>(0x50026000U)

#else
#define RAMCFG_NS   ((RAMCFG_TypeDef *)0x40026000U)
#define RAMCFG_S    ((RAMCFG_TypeDef *)0x50026000U)
#endif

// M1CR Configuration

#define RAMCFG_M1CR_WSC                 (0x7U<<16)
#define RAMCFG_M1CR_WSC_0               (0x1U<<16)
#define RAMCFG_M1CR_SRAMER              (0x1U<<8)
#define RAMCFG_M1CR_ALE                 (0x1U<<4)
#define RAMCFG_M1CR_ECCE                (0x1U<<0)

// M1ISR Configuration

#define RAMCFG_M1ISR_SRAMBUSY           (0x1U<<8)
#define RAMCFG_M1ISR_DED                (0x1U<<1)
#define RAMCFG_M1ISR_SEDC               (0x1U<<0)

// RAM1ERKEYR Configuration

#define RAMCFG_RAM1ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_RAM1ERKEYR_ERASEKEY_0    (0x1U<<0)

// M2CR Configuration

#define RAMCFG_M2CR_WSC                 (0x7U<<16)
#define RAMCFG_M2CR_WSC_0               (0x1U<<16)
#define RAMCFG_M2CR_SRAMER              (0x1U<<8)
#define RAMCFG_M2CR_ALE                 (0x1U<<4)
#define RAMCFG_M2CR_ECCE                (0x1U<<0)

// M2IER Configuration

#define RAMCFG_M2IER_ECCNMI             (0x1U<<3)
#define RAMCFG_M2IER_DEIE               (0x1U<<1)
#define RAMCFG_M2IER_SEIE               (0x1U<<0)

// M2ISR Configuration

#define RAMCFG_M2ISR_SRAMBUSY           (0x1U<<8)
#define RAMCFG_M2ISR_DED                (0x1U<<1)
#define RAMCFG_M2ISR_SEDC               (0x1U<<0)

// M2SEAR Configuration

#define RAMCFG_M2SEAR_ESEA              (0xFFFFFFFFU<<0)
#define RAMCFG_M2SEAR_ESEA_0            (0x1U<<0)

// M2DEAR Configuration

#define RAMCFG_M2DEAR_EDEA              (0xFFFFFFFFU<<0)
#define RAMCFG_M2DEAR_EDEA_0            (0x1U<<0)

// M2ICR Configuration

#define RAMCFG_M2ICR_CDED               (0x1U<<1)
#define RAMCFG_M2ICR_CSEDC              (0x1U<<0)

// M2WPR1 Configuration

#define RAMCFG_M2WPR1_P31WP             (0x1U<<31)
#define RAMCFG_M2WPR1_P30WP             (0x1U<<30)
#define RAMCFG_M2WPR1_P29WP             (0x1U<<29)
#define RAMCFG_M2WPR1_P28WP             (0x1U<<28)
#define RAMCFG_M2WPR1_P27WP             (0x1U<<27)
#define RAMCFG_M2WPR1_P26WP             (0x1U<<26)
#define RAMCFG_M2WPR1_P25WP             (0x1U<<25)
#define RAMCFG_M2WPR1_P24WP             (0x1U<<24)
#define RAMCFG_M2WPR1_P23WP             (0x1U<<23)
#define RAMCFG_M2WPR1_P22WP             (0x1U<<22)
#define RAMCFG_M2WPR1_P21WP             (0x1U<<21)
#define RAMCFG_M2WPR1_P20WP             (0x1U<<20)
#define RAMCFG_M2WPR1_P19WP             (0x1U<<19)
#define RAMCFG_M2WPR1_P18WP             (0x1U<<18)
#define RAMCFG_M2WPR1_P17WP             (0x1U<<17)
#define RAMCFG_M2WPR1_P16WP             (0x1U<<16)
#define RAMCFG_M2WPR1_P15WP             (0x1U<<15)
#define RAMCFG_M2WPR1_P14WP             (0x1U<<14)
#define RAMCFG_M2WPR1_P13WP             (0x1U<<13)
#define RAMCFG_M2WPR1_P12WP             (0x1U<<12)
#define RAMCFG_M2WPR1_P11WP             (0x1U<<11)
#define RAMCFG_M2WPR1_P10WP             (0x1U<<10)
#define RAMCFG_M2WPR1_P9WP              (0x1U<<9)
#define RAMCFG_M2WPR1_P8WP              (0x1U<<8)
#define RAMCFG_M2WPR1_P7WP              (0x1U<<7)
#define RAMCFG_M2WPR1_P6WP              (0x1U<<6)
#define RAMCFG_M2WPR1_P5WP              (0x1U<<5)
#define RAMCFG_M2WPR1_P4WP              (0x1U<<4)
#define RAMCFG_M2WPR1_P3WP              (0x1U<<3)
#define RAMCFG_M2WPR1_P2WP              (0x1U<<2)
#define RAMCFG_M2WPR1_P1WP              (0x1U<<1)
#define RAMCFG_M2WPR1_P0WP              (0x1U<<0)

// M2WPR2 Configuration

#define RAMCFG_M2WPR2_P63WP             (0x1U<<31)
#define RAMCFG_M2WPR2_P62WP             (0x1U<<30)
#define RAMCFG_M2WPR2_P61WP             (0x1U<<29)
#define RAMCFG_M2WPR2_P60WP             (0x1U<<28)
#define RAMCFG_M2WPR2_P59WP             (0x1U<<27)
#define RAMCFG_M2WPR2_P58WP             (0x1U<<26)
#define RAMCFG_M2WPR2_P57WP             (0x1U<<25)
#define RAMCFG_M2WPR2_P56WP             (0x1U<<24)
#define RAMCFG_M2WPR2_P55WP             (0x1U<<23)
#define RAMCFG_M2WPR2_P54WP             (0x1U<<22)
#define RAMCFG_M2WPR2_P53WP             (0x1U<<21)
#define RAMCFG_M2WPR2_P52WP             (0x1U<<20)
#define RAMCFG_M2WPR2_P51WP             (0x1U<<19)
#define RAMCFG_M2WPR2_P50WP             (0x1U<<18)
#define RAMCFG_M2WPR2_P49WP             (0x1U<<17)
#define RAMCFG_M2WPR2_P48WP             (0x1U<<16)
#define RAMCFG_M2WPR2_P47WP             (0x1U<<15)
#define RAMCFG_M2WPR2_P46WP             (0x1U<<14)
#define RAMCFG_M2WPR2_P45WP             (0x1U<<13)
#define RAMCFG_M2WPR2_P44WP             (0x1U<<12)
#define RAMCFG_M2WPR2_P43WP             (0x1U<<11)
#define RAMCFG_M2WPR2_P42WP             (0x1U<<10)
#define RAMCFG_M2WPR2_P41WP             (0x1U<<9)
#define RAMCFG_M2WPR2_P40WP             (0x1U<<8)
#define RAMCFG_M2WPR2_P39WP             (0x1U<<7)
#define RAMCFG_M2WPR2_P38WP             (0x1U<<6)
#define RAMCFG_M2WPR2_P37WP             (0x1U<<5)
#define RAMCFG_M2WPR2_P36WP             (0x1U<<4)
#define RAMCFG_M2WPR2_P35WP             (0x1U<<3)
#define RAMCFG_M2WPR2_P34WP             (0x1U<<2)
#define RAMCFG_M2WPR2_P33WP             (0x1U<<1)
#define RAMCFG_M2WPR2_P32WP             (0x1U<<0)

// M2ECCKEYR Configuration

#define RAMCFG_M2ECCKEYR_ECCKEY         (0xFFU<<0)
#define RAMCFG_M2ECCKEYR_ECCKEY_0       (0x1U<<0)

// M2ERKEYR Configuration

#define RAMCFG_M2ERKEYR_ERASEKEY        (0xFFU<<0)
#define RAMCFG_M2ERKEYR_ERASEKEY_0      (0x1U<<0)

// M3CR Configuration

#define RAMCFG_M3CR_WSC                 (0x7U<<16)
#define RAMCFG_M3CR_WSC_0               (0x1U<<16)
#define RAMCFG_M3CR_SRAMER              (0x1U<<8)
#define RAMCFG_M3CR_ALE                 (0x1U<<4)
#define RAMCFG_M3CR_ECCE                (0x1U<<0)

// M3IER Configuration

#define RAMCFG_M3IER_ECCNMI             (0x1U<<3)
#define RAMCFG_M3IER_DEIE               (0x1U<<1)
#define RAMCFG_M3IER_SEIE               (0x1U<<0)

// M3ISR Configuration

#define RAMCFG_M3ISR_SRAMBUSY           (0x1U<<8)
#define RAMCFG_M3ISR_DED                (0x1U<<1)
#define RAMCFG_M3ISR_SEDC               (0x1U<<0)

// M3SEAR Configuration

#define RAMCFG_M3SEAR_ESEA              (0xFFFFFFFFU<<0)
#define RAMCFG_M3SEAR_ESEA_0            (0x1U<<0)

// M3DEAR Configuration

#define RAMCFG_M3DEAR_EDEA              (0xFFFFFFFFU<<0)
#define RAMCFG_M3DEAR_EDEA_0            (0x1U<<0)

// M3ICR Configuration

#define RAMCFG_M3ICR_CDED               (0x1U<<1)
#define RAMCFG_M3ICR_CSEDC              (0x1U<<0)

// M3ECCKEYR Configuration

#define RAMCFG_M3ECCKEYR_ECCKEY         (0xFFU<<0)
#define RAMCFG_M3ECCKEYR_ECCKEY_0       (0x1U<<0)

// M3ERKEYR Configuration

#define RAMCFG_M3ERKEYR_ERASEKEY        (0xFFU<<0)
#define RAMCFG_M3ERKEYR_ERASEKEY_0      (0x1U<<0)

// M4CR Configuration

#define RAMCFG_M4CR_WSC                 (0x7U<<16)
#define RAMCFG_M4CR_WSC_0               (0x1U<<16)
#define RAMCFG_M4CR_SRAMER              (0x1U<<8)
#define RAMCFG_M4CR_ALE                 (0x1U<<4)
#define RAMCFG_M4CR_ECCE                (0x1U<<0)

// M4ISR Configuration

#define RAMCFG_M4ISR_SRAMBUSY           (0x1U<<8)
#define RAMCFG_M4ISR_DED                (0x1U<<1)
#define RAMCFG_M4ISR_SEDC               (0x1U<<0)

// M4ERKEYR Configuration

#define RAMCFG_M4ERKEYR_ERASEKEY        (0xFFU<<0)
#define RAMCFG_M4ERKEYR_ERASEKEY_0      (0x1U<<0)

// M5CR Configuration

#define RAMCFG_M5CR_WSC                 (0x7U<<16)
#define RAMCFG_M5CR_WSC_0               (0x1U<<16)
#define RAMCFG_M5CR_SRAMER              (0x1U<<8)
#define RAMCFG_M5CR_ALE                 (0x1U<<4)
#define RAMCFG_M5CR_ECCE                (0x1U<<0)

// M5IER Configuration

#define RAMCFG_M5IER_ECCNMI             (0x1U<<3)
#define RAMCFG_M5IER_DEIE               (0x1U<<1)
#define RAMCFG_M5IER_SEIE               (0x1U<<0)

// M5ISR Configuration

#define RAMCFG_M5ISR_SRAMBUSY           (0x1U<<8)
#define RAMCFG_M5ISR_DED                (0x1U<<1)
#define RAMCFG_M5ISR_SEDC               (0x1U<<0)

// M5SEAR Configuration

#define RAMCFG_M5SEAR_ESEA              (0xFFFFFFFFU<<0)
#define RAMCFG_M5SEAR_ESEA_0            (0x1U<<0)

// M5DEAR Configuration

#define RAMCFG_M5DEAR_EDEA              (0xFFFFFFFFU<<0)
#define RAMCFG_M5DEAR_EDEA_0            (0x1U<<0)

// M5ICR Configuration

#define RAMCFG_M5ICR_CDED               (0x1U<<1)
#define RAMCFG_M5ICR_CSEDC              (0x1U<<0)

// M5ECCKEYR Configuration

#define RAMCFG_M5ECCKEYR_ECCKEY         (0xFFU<<0)
#define RAMCFG_M5ECCKEYR_ECCKEY_0       (0x1U<<0)

// M5ERKEYR Configuration

#define RAMCFG_M5ERKEYR_ERASEKEY        (0xFFU<<0)
#define RAMCFG_M5ERKEYR_ERASEKEY_0      (0x1U<<0)

// M6CR Configuration

#define RAMCFG_M6CR_WSC                 (0x7U<<16)
#define RAMCFG_M6CR_WSC_0               (0x1U<<16)
#define RAMCFG_M6CR_SRAMER              (0x1U<<8)
#define RAMCFG_M6CR_ALE                 (0x1U<<4)
#define RAMCFG_M6CR_ECCE                (0x1U<<0)

// M6ISR Configuration

#define RAMCFG_M6ISR_SRAMBUSY           (0x1U<<8)
#define RAMCFG_M6ISR_DED                (0x1U<<1)
#define RAMCFG_M6ISR_SEDC               (0x1U<<0)
#define RAMCFG_M6ISR_SRAMBUSY_B_0X0     (0x0U<<8)
#define RAMCFG_M6ISR_SRAMBUSY_B_0X1     (0x1U<<8)
#define RAMCFG_M6ISR_DED_B_0X0          (0x0U<<1)
#define RAMCFG_M6ISR_DED_B_0X1          (0x1U<<1)
#define RAMCFG_M6ISR_SEDC_B_0X0         (0x0U<<0)
#define RAMCFG_M6ISR_SEDC_B_0X1         (0x1U<<0)

// M6ERKEYR Configuration

#define RAMCFG_M6ERKEYR_ERASEKEY        (0xFFU<<0)
#define RAMCFG_M6ERKEYR_ERASEKEY_0      (0x1U<<0)
