/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_exti equates.
 */

#pragma once

#include    <stdint.h>

// EXTI address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    RTSR1;
    volatile    uint32_t    FTSR1;
    volatile    uint32_t    SWIER1;
    volatile    uint32_t    D3PMR1;
    volatile    uint32_t    D3PCR1L;
    volatile    uint32_t    D3PCR1H;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    RTSR2;
    volatile    uint32_t    FTSR2;
    volatile    uint32_t    SWIER2;
    volatile    uint32_t    D3PMR2;
    volatile    uint32_t    D3PCR2L;
    volatile    uint32_t    D3PCR2H;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    RTSR3;
    volatile    uint32_t    FTSR3;
    volatile    uint32_t    SWIER3;
    volatile    uint32_t    D3PMR3;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    D3PCR3H;
    volatile    uint32_t    RESERVED3[10];
    volatile    uint32_t    CPUIMR1;
    volatile    uint32_t    CPUEMR1;
    volatile    uint32_t    CPUPR1;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    CPUIMR2;
    volatile    uint32_t    CPUEMR2;
    volatile    uint32_t    CPUPR2;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    CPUIMR3;
    volatile    uint32_t    CPUEMR3;
    volatile    uint32_t    CPUPR3;
} EXTI_TypeDef;

#ifdef __cplusplus
#define EXTI    reinterpret_cast<EXTI_TypeDef *>(0x58000000U)

#else
#define EXTI    ((EXTI_TypeDef *)0x58000000U)
#endif

// RTSR1 Configuration

#define EXTI_RTSR1_TR21         (0x1U<<21)
#define EXTI_RTSR1_TR20         (0x1U<<20)
#define EXTI_RTSR1_TR19         (0x1U<<19)
#define EXTI_RTSR1_TR18         (0x1U<<18)
#define EXTI_RTSR1_TR17         (0x1U<<17)
#define EXTI_RTSR1_TR16         (0x1U<<16)
#define EXTI_RTSR1_TR15         (0x1U<<15)
#define EXTI_RTSR1_TR14         (0x1U<<14)
#define EXTI_RTSR1_TR13         (0x1U<<13)
#define EXTI_RTSR1_TR12         (0x1U<<12)
#define EXTI_RTSR1_TR11         (0x1U<<11)
#define EXTI_RTSR1_TR10         (0x1U<<10)
#define EXTI_RTSR1_TR9          (0x1U<<9)
#define EXTI_RTSR1_TR8          (0x1U<<8)
#define EXTI_RTSR1_TR7          (0x1U<<7)
#define EXTI_RTSR1_TR6          (0x1U<<6)
#define EXTI_RTSR1_TR5          (0x1U<<5)
#define EXTI_RTSR1_TR4          (0x1U<<4)
#define EXTI_RTSR1_TR3          (0x1U<<3)
#define EXTI_RTSR1_TR2          (0x1U<<2)
#define EXTI_RTSR1_TR1          (0x1U<<1)
#define EXTI_RTSR1_TR0          (0x1U<<0)

// FTSR1 Configuration

#define EXTI_FTSR1_TR21         (0x1U<<21)
#define EXTI_FTSR1_TR20         (0x1U<<20)
#define EXTI_FTSR1_TR19         (0x1U<<19)
#define EXTI_FTSR1_TR18         (0x1U<<18)
#define EXTI_FTSR1_TR17         (0x1U<<17)
#define EXTI_FTSR1_TR16         (0x1U<<16)
#define EXTI_FTSR1_TR15         (0x1U<<15)
#define EXTI_FTSR1_TR14         (0x1U<<14)
#define EXTI_FTSR1_TR13         (0x1U<<13)
#define EXTI_FTSR1_TR12         (0x1U<<12)
#define EXTI_FTSR1_TR11         (0x1U<<11)
#define EXTI_FTSR1_TR10         (0x1U<<10)
#define EXTI_FTSR1_TR9          (0x1U<<9)
#define EXTI_FTSR1_TR8          (0x1U<<8)
#define EXTI_FTSR1_TR7          (0x1U<<7)
#define EXTI_FTSR1_TR6          (0x1U<<6)
#define EXTI_FTSR1_TR5          (0x1U<<5)
#define EXTI_FTSR1_TR4          (0x1U<<4)
#define EXTI_FTSR1_TR3          (0x1U<<3)
#define EXTI_FTSR1_TR2          (0x1U<<2)
#define EXTI_FTSR1_TR1          (0x1U<<1)
#define EXTI_FTSR1_TR0          (0x1U<<0)

// SWIER1 Configuration

#define EXTI_SWIER1_SWIER21     (0x1U<<21)
#define EXTI_SWIER1_SWIER20     (0x1U<<20)
#define EXTI_SWIER1_SWIER19     (0x1U<<19)
#define EXTI_SWIER1_SWIER18     (0x1U<<18)
#define EXTI_SWIER1_SWIER17     (0x1U<<17)
#define EXTI_SWIER1_SWIER16     (0x1U<<16)
#define EXTI_SWIER1_SWIER15     (0x1U<<15)
#define EXTI_SWIER1_SWIER14     (0x1U<<14)
#define EXTI_SWIER1_SWIER13     (0x1U<<13)
#define EXTI_SWIER1_SWIER12     (0x1U<<12)
#define EXTI_SWIER1_SWIER11     (0x1U<<11)
#define EXTI_SWIER1_SWIER10     (0x1U<<10)
#define EXTI_SWIER1_SWIER9      (0x1U<<9)
#define EXTI_SWIER1_SWIER8      (0x1U<<8)
#define EXTI_SWIER1_SWIER7      (0x1U<<7)
#define EXTI_SWIER1_SWIER6      (0x1U<<6)
#define EXTI_SWIER1_SWIER5      (0x1U<<5)
#define EXTI_SWIER1_SWIER4      (0x1U<<4)
#define EXTI_SWIER1_SWIER3      (0x1U<<3)
#define EXTI_SWIER1_SWIER2      (0x1U<<2)
#define EXTI_SWIER1_SWIER1      (0x1U<<1)
#define EXTI_SWIER1_SWIER0      (0x1U<<0)

// D3PMR1 Configuration

#define EXTI_D3PMR1_MR25        (0x1U<<25)
#define EXTI_D3PMR1_MR21        (0x1U<<21)
#define EXTI_D3PMR1_MR20        (0x1U<<20)
#define EXTI_D3PMR1_MR19        (0x1U<<19)
#define EXTI_D3PMR1_MR15        (0x1U<<15)
#define EXTI_D3PMR1_MR14        (0x1U<<14)
#define EXTI_D3PMR1_MR13        (0x1U<<13)
#define EXTI_D3PMR1_MR12        (0x1U<<12)
#define EXTI_D3PMR1_MR11        (0x1U<<11)
#define EXTI_D3PMR1_MR10        (0x1U<<10)
#define EXTI_D3PMR1_MR9         (0x1U<<9)
#define EXTI_D3PMR1_MR8         (0x1U<<8)
#define EXTI_D3PMR1_MR7         (0x1U<<7)
#define EXTI_D3PMR1_MR6         (0x1U<<6)
#define EXTI_D3PMR1_MR5         (0x1U<<5)
#define EXTI_D3PMR1_MR4         (0x1U<<4)
#define EXTI_D3PMR1_MR3         (0x1U<<3)
#define EXTI_D3PMR1_MR2         (0x1U<<2)
#define EXTI_D3PMR1_MR1         (0x1U<<1)
#define EXTI_D3PMR1_MR0         (0x1U<<0)

// D3PCR1L Configuration

#define EXTI_D3PCR1L_PCS15      (0x3U<<30)
#define EXTI_D3PCR1L_PCS15_0    (0x1U<<30)
#define EXTI_D3PCR1L_PCS14      (0x3U<<28)
#define EXTI_D3PCR1L_PCS14_0    (0x1U<<28)
#define EXTI_D3PCR1L_PCS13      (0x3U<<26)
#define EXTI_D3PCR1L_PCS13_0    (0x1U<<26)
#define EXTI_D3PCR1L_PCS12      (0x3U<<24)
#define EXTI_D3PCR1L_PCS12_0    (0x1U<<24)
#define EXTI_D3PCR1L_PCS11      (0x3U<<22)
#define EXTI_D3PCR1L_PCS11_0    (0x1U<<22)
#define EXTI_D3PCR1L_PCS10      (0x3U<<20)
#define EXTI_D3PCR1L_PCS10_0    (0x1U<<20)
#define EXTI_D3PCR1L_PCS9       (0x3U<<18)
#define EXTI_D3PCR1L_PCS9_0     (0x1U<<18)
#define EXTI_D3PCR1L_PCS8       (0x3U<<16)
#define EXTI_D3PCR1L_PCS8_0     (0x1U<<16)
#define EXTI_D3PCR1L_PCS7       (0x3U<<14)
#define EXTI_D3PCR1L_PCS7_0     (0x1U<<14)
#define EXTI_D3PCR1L_PCS6       (0x3U<<12)
#define EXTI_D3PCR1L_PCS6_0     (0x1U<<12)
#define EXTI_D3PCR1L_PCS5       (0x3U<<10)
#define EXTI_D3PCR1L_PCS5_0     (0x1U<<10)
#define EXTI_D3PCR1L_PCS4       (0x3U<<8)
#define EXTI_D3PCR1L_PCS4_0     (0x1U<<8)
#define EXTI_D3PCR1L_PCS3       (0x3U<<6)
#define EXTI_D3PCR1L_PCS3_0     (0x1U<<6)
#define EXTI_D3PCR1L_PCS2       (0x3U<<4)
#define EXTI_D3PCR1L_PCS2_0     (0x1U<<4)
#define EXTI_D3PCR1L_PCS1       (0x3U<<2)
#define EXTI_D3PCR1L_PCS1_0     (0x1U<<2)
#define EXTI_D3PCR1L_PCS0       (0x3U<<0)
#define EXTI_D3PCR1L_PCS0_0     (0x1U<<0)

// D3PCR1H Configuration

#define EXTI_D3PCR1H_PCS25      (0x3U<<18)
#define EXTI_D3PCR1H_PCS25_0    (0x1U<<18)
#define EXTI_D3PCR1H_PCS21      (0x3U<<10)
#define EXTI_D3PCR1H_PCS21_0    (0x1U<<10)
#define EXTI_D3PCR1H_PCS20      (0x3U<<8)
#define EXTI_D3PCR1H_PCS20_0    (0x1U<<8)
#define EXTI_D3PCR1H_PCS19      (0x3U<<6)
#define EXTI_D3PCR1H_PCS19_0    (0x1U<<6)

// RTSR2 Configuration

#define EXTI_RTSR2_TR51         (0x1U<<19)
#define EXTI_RTSR2_TR49         (0x1U<<17)

// FTSR2 Configuration

#define EXTI_FTSR2_TR51         (0x1U<<19)
#define EXTI_FTSR2_TR49         (0x1U<<17)

// SWIER2 Configuration

#define EXTI_SWIER2_SWIER51     (0x1U<<19)
#define EXTI_SWIER2_SWIER49     (0x1U<<17)

// D3PMR2 Configuration

#define EXTI_D3PMR2_MR53        (0x1U<<21)
#define EXTI_D3PMR2_MR52        (0x1U<<20)
#define EXTI_D3PMR2_MR51        (0x1U<<19)
#define EXTI_D3PMR2_MR50        (0x1U<<18)
#define EXTI_D3PMR2_MR49        (0x1U<<17)
#define EXTI_D3PMR2_MR48        (0x1U<<16)
#define EXTI_D3PMR2_MR41        (0x1U<<9)
#define EXTI_D3PMR2_MR35        (0x1U<<3)
#define EXTI_D3PMR2_MR34        (0x1U<<2)

// D3PCR2L Configuration

#define EXTI_D3PCR2L_PCS41      (0x3U<<18)
#define EXTI_D3PCR2L_PCS41_0    (0x1U<<18)
#define EXTI_D3PCR2L_PCS34      (0x3U<<4)
#define EXTI_D3PCR2L_PCS34_0    (0x1U<<4)
#define EXTI_D3PCR2L_PCS35      (0x3U<<6)
#define EXTI_D3PCR2L_PCS35_0    (0x1U<<6)

// D3PCR2H Configuration

#define EXTI_D3PCR2H_PCS53      (0x3U<<10)
#define EXTI_D3PCR2H_PCS53_0    (0x1U<<10)
#define EXTI_D3PCR2H_PCS52      (0x3U<<8)
#define EXTI_D3PCR2H_PCS52_0    (0x1U<<8)
#define EXTI_D3PCR2H_PCS51      (0x3U<<6)
#define EXTI_D3PCR2H_PCS51_0    (0x1U<<6)
#define EXTI_D3PCR2H_PCS50      (0x3U<<4)
#define EXTI_D3PCR2H_PCS50_0    (0x1U<<4)
#define EXTI_D3PCR2H_PCS49      (0x3U<<2)
#define EXTI_D3PCR2H_PCS49_0    (0x1U<<2)
#define EXTI_D3PCR2H_PCS48      (0x3U<<0)
#define EXTI_D3PCR2H_PCS48_0    (0x1U<<0)

// RTSR3 Configuration

#define EXTI_RTSR3_TR86         (0x1U<<22)
#define EXTI_RTSR3_TR85         (0x1U<<21)
#define EXTI_RTSR3_TR84         (0x1U<<20)
#define EXTI_RTSR3_TR82         (0x1U<<18)

// FTSR3 Configuration

#define EXTI_FTSR3_TR86         (0x1U<<22)
#define EXTI_FTSR3_TR85         (0x1U<<21)
#define EXTI_FTSR3_TR84         (0x1U<<20)
#define EXTI_FTSR3_TR82         (0x1U<<18)

// SWIER3 Configuration

#define EXTI_SWIER3_SWIER86     (0x1U<<22)
#define EXTI_SWIER3_SWIER85     (0x1U<<21)
#define EXTI_SWIER3_SWIER84     (0x1U<<20)
#define EXTI_SWIER3_SWIER82     (0x1U<<18)

// D3PMR3 Configuration

#define EXTI_D3PMR3_MR88        (0x1U<<24)

// D3PCR3H Configuration

#define EXTI_D3PCR3H_PCS88      (0x3U<<18)
#define EXTI_D3PCR3H_PCS88_0    (0x1U<<18)

// CPUIMR1 Configuration

#define EXTI_CPUIMR1_MR31       (0x1U<<31)
#define EXTI_CPUIMR1_MR30       (0x1U<<30)
#define EXTI_CPUIMR1_MR29       (0x1U<<29)
#define EXTI_CPUIMR1_MR28       (0x1U<<28)
#define EXTI_CPUIMR1_MR27       (0x1U<<27)
#define EXTI_CPUIMR1_MR26       (0x1U<<26)
#define EXTI_CPUIMR1_MR25       (0x1U<<25)
#define EXTI_CPUIMR1_MR24       (0x1U<<24)
#define EXTI_CPUIMR1_MR23       (0x1U<<23)
#define EXTI_CPUIMR1_MR22       (0x1U<<22)
#define EXTI_CPUIMR1_MR21       (0x1U<<21)
#define EXTI_CPUIMR1_MR20       (0x1U<<20)
#define EXTI_CPUIMR1_MR19       (0x1U<<19)
#define EXTI_CPUIMR1_MR18       (0x1U<<18)
#define EXTI_CPUIMR1_MR17       (0x1U<<17)
#define EXTI_CPUIMR1_MR16       (0x1U<<16)
#define EXTI_CPUIMR1_MR15       (0x1U<<15)
#define EXTI_CPUIMR1_MR14       (0x1U<<14)
#define EXTI_CPUIMR1_MR13       (0x1U<<13)
#define EXTI_CPUIMR1_MR12       (0x1U<<12)
#define EXTI_CPUIMR1_MR11       (0x1U<<11)
#define EXTI_CPUIMR1_MR10       (0x1U<<10)
#define EXTI_CPUIMR1_MR9        (0x1U<<9)
#define EXTI_CPUIMR1_MR8        (0x1U<<8)
#define EXTI_CPUIMR1_MR7        (0x1U<<7)
#define EXTI_CPUIMR1_MR6        (0x1U<<6)
#define EXTI_CPUIMR1_MR5        (0x1U<<5)
#define EXTI_CPUIMR1_MR4        (0x1U<<4)
#define EXTI_CPUIMR1_MR3        (0x1U<<3)
#define EXTI_CPUIMR1_MR2        (0x1U<<2)
#define EXTI_CPUIMR1_MR1        (0x1U<<1)
#define EXTI_CPUIMR1_MR0        (0x1U<<0)

// CPUEMR1 Configuration

#define EXTI_CPUEMR1_MR31       (0x1U<<31)
#define EXTI_CPUEMR1_MR30       (0x1U<<30)
#define EXTI_CPUEMR1_MR29       (0x1U<<29)
#define EXTI_CPUEMR1_MR28       (0x1U<<28)
#define EXTI_CPUEMR1_MR27       (0x1U<<27)
#define EXTI_CPUEMR1_MR26       (0x1U<<26)
#define EXTI_CPUEMR1_MR25       (0x1U<<25)
#define EXTI_CPUEMR1_MR24       (0x1U<<24)
#define EXTI_CPUEMR1_MR23       (0x1U<<23)
#define EXTI_CPUEMR1_MR22       (0x1U<<22)
#define EXTI_CPUEMR1_MR21       (0x1U<<21)
#define EXTI_CPUEMR1_MR20       (0x1U<<20)
#define EXTI_CPUEMR1_MR19       (0x1U<<19)
#define EXTI_CPUEMR1_MR18       (0x1U<<18)
#define EXTI_CPUEMR1_MR17       (0x1U<<17)
#define EXTI_CPUEMR1_MR16       (0x1U<<16)
#define EXTI_CPUEMR1_MR15       (0x1U<<15)
#define EXTI_CPUEMR1_MR14       (0x1U<<14)
#define EXTI_CPUEMR1_MR13       (0x1U<<13)
#define EXTI_CPUEMR1_MR12       (0x1U<<12)
#define EXTI_CPUEMR1_MR11       (0x1U<<11)
#define EXTI_CPUEMR1_MR10       (0x1U<<10)
#define EXTI_CPUEMR1_MR9        (0x1U<<9)
#define EXTI_CPUEMR1_MR8        (0x1U<<8)
#define EXTI_CPUEMR1_MR7        (0x1U<<7)
#define EXTI_CPUEMR1_MR6        (0x1U<<6)
#define EXTI_CPUEMR1_MR5        (0x1U<<5)
#define EXTI_CPUEMR1_MR4        (0x1U<<4)
#define EXTI_CPUEMR1_MR3        (0x1U<<3)
#define EXTI_CPUEMR1_MR2        (0x1U<<2)
#define EXTI_CPUEMR1_MR1        (0x1U<<1)
#define EXTI_CPUEMR1_MR0        (0x1U<<0)

// CPUPR1 Configuration

#define EXTI_CPUPR1_PR21        (0x1U<<21)
#define EXTI_CPUPR1_PR20        (0x1U<<20)
#define EXTI_CPUPR1_PR19        (0x1U<<19)
#define EXTI_CPUPR1_PR18        (0x1U<<18)
#define EXTI_CPUPR1_PR17        (0x1U<<17)
#define EXTI_CPUPR1_PR16        (0x1U<<16)
#define EXTI_CPUPR1_PR15        (0x1U<<15)
#define EXTI_CPUPR1_PR14        (0x1U<<14)
#define EXTI_CPUPR1_PR13        (0x1U<<13)
#define EXTI_CPUPR1_PR12        (0x1U<<12)
#define EXTI_CPUPR1_PR11        (0x1U<<11)
#define EXTI_CPUPR1_PR10        (0x1U<<10)
#define EXTI_CPUPR1_PR9         (0x1U<<9)
#define EXTI_CPUPR1_PR8         (0x1U<<8)
#define EXTI_CPUPR1_PR7         (0x1U<<7)
#define EXTI_CPUPR1_PR6         (0x1U<<6)
#define EXTI_CPUPR1_PR5         (0x1U<<5)
#define EXTI_CPUPR1_PR4         (0x1U<<4)
#define EXTI_CPUPR1_PR3         (0x1U<<3)
#define EXTI_CPUPR1_PR2         (0x1U<<2)
#define EXTI_CPUPR1_PR1         (0x1U<<1)
#define EXTI_CPUPR1_PR0         (0x1U<<0)

// CPUIMR2 Configuration

#define EXTI_CPUIMR2_MR31       (0x1U<<31)
#define EXTI_CPUIMR2_MR30       (0x1U<<30)
#define EXTI_CPUIMR2_MR29       (0x1U<<29)
#define EXTI_CPUIMR2_MR28       (0x1U<<28)
#define EXTI_CPUIMR2_MR27       (0x1U<<27)
#define EXTI_CPUIMR2_MR26       (0x1U<<26)
#define EXTI_CPUIMR2_MR25       (0x1U<<25)
#define EXTI_CPUIMR2_MR24       (0x1U<<24)
#define EXTI_CPUIMR2_MR23       (0x1U<<23)
#define EXTI_CPUIMR2_MR22       (0x1U<<22)
#define EXTI_CPUIMR2_MR21       (0x1U<<21)
#define EXTI_CPUIMR2_MR20       (0x1U<<20)
#define EXTI_CPUIMR2_MR19       (0x1U<<19)
#define EXTI_CPUIMR2_MR18       (0x1U<<18)
#define EXTI_CPUIMR2_MR17       (0x1U<<17)
#define EXTI_CPUIMR2_MR16       (0x1U<<16)
#define EXTI_CPUIMR2_MR15       (0x1U<<15)
#define EXTI_CPUIMR2_MR14       (0x1U<<14)
#define EXTI_CPUIMR2_MR12       (0x1U<<12)
#define EXTI_CPUIMR2_MR11       (0x1U<<11)
#define EXTI_CPUIMR2_MR10       (0x1U<<10)
#define EXTI_CPUIMR2_MR9        (0x1U<<9)
#define EXTI_CPUIMR2_MR8        (0x1U<<8)
#define EXTI_CPUIMR2_MR7        (0x1U<<7)
#define EXTI_CPUIMR2_MR6        (0x1U<<6)
#define EXTI_CPUIMR2_MR5        (0x1U<<5)
#define EXTI_CPUIMR2_MR4        (0x1U<<4)
#define EXTI_CPUIMR2_MR3        (0x1U<<3)
#define EXTI_CPUIMR2_MR2        (0x1U<<2)
#define EXTI_CPUIMR2_MR1        (0x1U<<1)
#define EXTI_CPUIMR2_MR0        (0x1U<<0)

// CPUEMR2 Configuration

#define EXTI_CPUEMR2_MR63       (0x1U<<31)
#define EXTI_CPUEMR2_MR62       (0x1U<<30)
#define EXTI_CPUEMR2_MR61       (0x1U<<29)
#define EXTI_CPUEMR2_MR60       (0x1U<<28)
#define EXTI_CPUEMR2_MR59       (0x1U<<27)
#define EXTI_CPUEMR2_MR58       (0x1U<<26)
#define EXTI_CPUEMR2_MR57       (0x1U<<25)
#define EXTI_CPUEMR2_MR56       (0x1U<<24)
#define EXTI_CPUEMR2_MR55       (0x1U<<23)
#define EXTI_CPUEMR2_MR54       (0x1U<<22)
#define EXTI_CPUEMR2_MR53       (0x1U<<21)
#define EXTI_CPUEMR2_MR52       (0x1U<<20)
#define EXTI_CPUEMR2_MR51       (0x1U<<19)
#define EXTI_CPUEMR2_MR50       (0x1U<<18)
#define EXTI_CPUEMR2_MR49       (0x1U<<17)
#define EXTI_CPUEMR2_MR48       (0x1U<<16)
#define EXTI_CPUEMR2_MR47       (0x1U<<15)
#define EXTI_CPUEMR2_MR46       (0x1U<<14)
#define EXTI_CPUEMR2_MR44       (0x1U<<12)
#define EXTI_CPUEMR2_MR43       (0x1U<<11)
#define EXTI_CPUEMR2_MR42       (0x1U<<10)
#define EXTI_CPUEMR2_MR41       (0x1U<<9)
#define EXTI_CPUEMR2_MR40       (0x1U<<8)
#define EXTI_CPUEMR2_MR39       (0x1U<<7)
#define EXTI_CPUEMR2_MR38       (0x1U<<6)
#define EXTI_CPUEMR2_MR37       (0x1U<<5)
#define EXTI_CPUEMR2_MR36       (0x1U<<4)
#define EXTI_CPUEMR2_MR35       (0x1U<<3)
#define EXTI_CPUEMR2_MR34       (0x1U<<2)
#define EXTI_CPUEMR2_MR33       (0x1U<<1)
#define EXTI_CPUEMR2_MR32       (0x1U<<0)

// CPUPR2 Configuration

#define EXTI_CPUPR2_PR51        (0x1U<<19)
#define EXTI_CPUPR2_PR49        (0x1U<<17)

// CPUIMR3 Configuration

#define EXTI_CPUIMR3_MR88       (0x1U<<24)
#define EXTI_CPUIMR3_MR87       (0x1U<<23)
#define EXTI_CPUIMR3_MR86       (0x1U<<22)
#define EXTI_CPUIMR3_MR85       (0x1U<<21)
#define EXTI_CPUIMR3_MR84       (0x1U<<20)
#define EXTI_CPUIMR3_MR82       (0x1U<<18)
#define EXTI_CPUIMR3_MR80       (0x1U<<16)
#define EXTI_CPUIMR3_MR79       (0x1U<<15)
#define EXTI_CPUIMR3_MR78       (0x1U<<14)
#define EXTI_CPUIMR3_MR77       (0x1U<<13)
#define EXTI_CPUIMR3_MR76       (0x1U<<12)
#define EXTI_CPUIMR3_MR75       (0x1U<<11)
#define EXTI_CPUIMR3_MR74       (0x1U<<10)
#define EXTI_CPUIMR3_MR73       (0x1U<<9)
#define EXTI_CPUIMR3_MR72       (0x1U<<8)
#define EXTI_CPUIMR3_MR71       (0x1U<<7)
#define EXTI_CPUIMR3_MR70       (0x1U<<6)
#define EXTI_CPUIMR3_MR69       (0x1U<<5)
#define EXTI_CPUIMR3_MR68       (0x1U<<4)
#define EXTI_CPUIMR3_MR67       (0x1U<<3)
#define EXTI_CPUIMR3_MR66       (0x1U<<2)
#define EXTI_CPUIMR3_MR65       (0x1U<<1)
#define EXTI_CPUIMR3_MR64       (0x1U<<0)

// CPUEMR3 Configuration

#define EXTI_CPUEMR3_MR88       (0x1U<<24)
#define EXTI_CPUEMR3_MR87       (0x1U<<23)
#define EXTI_CPUEMR3_MR86       (0x1U<<22)
#define EXTI_CPUEMR3_MR85       (0x1U<<21)
#define EXTI_CPUEMR3_MR84       (0x1U<<20)
#define EXTI_CPUEMR3_MR82       (0x1U<<18)
#define EXTI_CPUEMR3_MR80       (0x1U<<16)
#define EXTI_CPUEMR3_MR79       (0x1U<<15)
#define EXTI_CPUEMR3_MR78       (0x1U<<14)
#define EXTI_CPUEMR3_MR77       (0x1U<<13)
#define EXTI_CPUEMR3_MR76       (0x1U<<12)
#define EXTI_CPUEMR3_MR75       (0x1U<<11)
#define EXTI_CPUEMR3_MR74       (0x1U<<10)
#define EXTI_CPUEMR3_MR73       (0x1U<<9)
#define EXTI_CPUEMR3_MR72       (0x1U<<8)
#define EXTI_CPUEMR3_MR71       (0x1U<<7)
#define EXTI_CPUEMR3_MR70       (0x1U<<6)
#define EXTI_CPUEMR3_MR69       (0x1U<<5)
#define EXTI_CPUEMR3_MR68       (0x1U<<4)
#define EXTI_CPUEMR3_MR67       (0x1U<<3)
#define EXTI_CPUEMR3_MR66       (0x1U<<2)
#define EXTI_CPUEMR3_MR65       (0x1U<<1)
#define EXTI_CPUEMR3_MR64       (0x1U<<0)

// CPUPR3 Configuration

#define EXTI_CPUPR3_PR86        (0x1U<<22)
#define EXTI_CPUPR3_PR85        (0x1U<<21)
#define EXTI_CPUPR3_PR84        (0x1U<<20)
#define EXTI_CPUPR3_PR82        (0x1U<<18)
