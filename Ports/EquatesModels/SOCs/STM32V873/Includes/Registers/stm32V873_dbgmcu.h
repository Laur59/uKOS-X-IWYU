/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_dbgmcu equates.
 */
#pragma once

#include    <stdint.h>

// DBGMCU address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    IDC;
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0[6];
    volatile    uint32_t    APB5FZR;
    volatile    uint32_t    AHB1FZR;
    volatile    uint32_t    AHB5FZR;
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    APB1FZR;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    APB2FZR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    APB4FZR;
    volatile    uint32_t    RESERVED4[41];
    volatile    uint32_t    SR;
    volatile    uint32_t    DBG_AUTH_HOST;
    volatile    uint32_t    DBG_AUTH_DEVICE;
    volatile    uint32_t    DBG_AUTH_ACK;
    volatile    uint32_t    RESERVED5[945];
    volatile    uint32_t    PIDR4;
    volatile    uint32_t    RESERVED6[3];
    volatile    uint32_t    PIDR0;
    volatile    uint32_t    PIDR1;
    volatile    uint32_t    PIDR2;
    volatile    uint32_t    PIDR3;
    volatile    uint32_t    CIDR0;
    volatile    uint32_t    CIDR1;
    volatile    uint32_t    CIDR2;
    volatile    uint32_t    CIDR3;
} DBGMCU_TypeDef;

#if (defined(__cplusplus))
#define DBGMCU_NS   reinterpret_cast<DBGMCU_TypeDef *>(0x4E004000u)

#else
#define DBGMCU_NS   ((DBGMCU_TypeDef *)0x4E004000u)
#endif

// IDC Configuration

#define DBGMCU_IDC_REV_ID                       (0xFFFFu<<16)
#define DBGMCU_IDC_REV_ID_0                     (0x1u<<16)
#define DBGMCU_IDC_DEV_ID                       (0xFFFu<<0)
#define DBGMCU_IDC_DEV_ID_0                     (0x1u<<0)

#define DBGMCU_IDC_DEV_ID_B_0X499               (0x499u<<0)

// CR Configuration

#define DBGMCU_CR_TRGOEN                        (0x1u<<28)
#define DBGMCU_CR_DCRT                          (0x1u<<16)
#define DBGMCU_CR_CPUWAIT                       (0x1u<<14)
#define DBGMCU_CR_DBGSTBY                       (0x1u<<2)
#define DBGMCU_CR_DBGSTOP                       (0x1u<<1)
#define DBGMCU_CR_DBGSLEEP                      (0x1u<<0)

#define DBGMCU_CR_TRGOEN_B_0X0                  (0x0u<<28)
#define DBGMCU_CR_TRGOEN_B_0X1                  (0x1u<<28)
#define DBGMCU_CR_DCRT_B_0X0                    (0x0u<<16)
#define DBGMCU_CR_DCRT_B_0X1                    (0x1u<<16)
#define DBGMCU_CR_CPUWAIT_B_0X0                 (0x0u<<14)
#define DBGMCU_CR_CPUWAIT_B_0X1                 (0x1u<<14)
#define DBGMCU_CR_DBGSTBY_B_0X0                 (0x0u<<2)
#define DBGMCU_CR_DBGSTBY_B_0X1                 (0x1u<<2)
#define DBGMCU_CR_DBGSTOP_B_0X0                 (0x0u<<1)
#define DBGMCU_CR_DBGSTOP_B_0X1                 (0x1u<<1)
#define DBGMCU_CR_DBGSLEEP_B_0X0                (0x0u<<0)
#define DBGMCU_CR_DBGSLEEP_B_0X1                (0x1u<<0)

// APB5FZR Configuration

#define DBGMCU_APB5FZR_DBG_GFXTIM_STOP          (0x1u<<4)

#define DBGMCU_APB5FZR_DBG_GFXTIM_STOP_B_0X0    (0x0u<<4)
#define DBGMCU_APB5FZR_DBG_GFXTIM_STOP_B_0X1    (0x1u<<4)

// AHB1FZR Configuration

#define DBGMCU_AHB1FZR_DBG_GPDMA2_11_STOP       (0x1u<<27)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_10_STOP       (0x1u<<26)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_9_STOP        (0x1u<<25)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_8_STOP        (0x1u<<24)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_7_STOP        (0x1u<<23)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_6_STOP        (0x1u<<22)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_5_STOP        (0x1u<<21)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_4_STOP        (0x1u<<20)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_3_STOP        (0x1u<<19)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_2_STOP        (0x1u<<18)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_1_STOP        (0x1u<<17)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_0_STOP        (0x1u<<16)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_11_STOP       (0x1u<<11)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_10_STOP       (0x1u<<10)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_9_STOP        (0x1u<<9)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_8_STOP        (0x1u<<8)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_7_STOP        (0x1u<<7)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_6_STOP        (0x1u<<6)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_5_STOP        (0x1u<<5)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_4_STOP        (0x1u<<4)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_3_STOP        (0x1u<<3)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_2_STOP        (0x1u<<2)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_1_STOP        (0x1u<<1)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_0_STOP        (0x1u<<0)

#define DBGMCU_AHB1FZR_DBG_GPDMA2_11_STOP_B_0X0 (0x0u<<27)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_11_STOP_B_0X1 (0x1u<<27)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_10_STOP_B_0X0 (0x0u<<26)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_10_STOP_B_0X1 (0x1u<<26)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_9_STOP_B_0X0  (0x0u<<25)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_9_STOP_B_0X1  (0x1u<<25)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_8_STOP_B_0X0  (0x0u<<24)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_8_STOP_B_0X1  (0x1u<<24)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_7_STOP_B_0X0  (0x0u<<23)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_7_STOP_B_0X1  (0x1u<<23)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_6_STOP_B_0X0  (0x0u<<22)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_6_STOP_B_0X1  (0x1u<<22)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_5_STOP_B_0X0  (0x0u<<21)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_5_STOP_B_0X1  (0x1u<<21)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_4_STOP_B_0X0  (0x0u<<20)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_4_STOP_B_0X1  (0x1u<<20)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_3_STOP_B_0X0  (0x0u<<19)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_3_STOP_B_0X1  (0x1u<<19)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_2_STOP_B_0X0  (0x0u<<18)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_2_STOP_B_0X1  (0x1u<<18)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_1_STOP_B_0X0  (0x0u<<17)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_1_STOP_B_0X1  (0x1u<<17)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_0_STOP_B_0X0  (0x0u<<16)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_0_STOP_B_0X1  (0x1u<<16)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_11_STOP_B_0X0 (0x0u<<11)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_11_STOP_B_0X1 (0x1u<<11)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_10_STOP_B_0X0 (0x0u<<10)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_10_STOP_B_0X1 (0x1u<<10)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_9_STOP_B_0X0  (0x0u<<9)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_9_STOP_B_0X1  (0x1u<<9)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_8_STOP_B_0X0  (0x0u<<8)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_8_STOP_B_0X1  (0x1u<<8)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_7_STOP_B_0X0  (0x0u<<7)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_7_STOP_B_0X1  (0x1u<<7)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_6_STOP_B_0X0  (0x0u<<6)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_6_STOP_B_0X1  (0x1u<<6)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_5_STOP_B_0X0  (0x0u<<5)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_5_STOP_B_0X1  (0x1u<<5)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_4_STOP_B_0X0  (0x0u<<4)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_4_STOP_B_0X1  (0x1u<<4)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_3_STOP_B_0X0  (0x0u<<3)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_3_STOP_B_0X1  (0x1u<<3)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_2_STOP_B_0X0  (0x0u<<2)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_2_STOP_B_0X1  (0x1u<<2)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_1_STOP_B_0X0  (0x0u<<1)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_1_STOP_B_0X1  (0x1u<<1)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_0_STOP_B_0X0  (0x0u<<0)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_0_STOP_B_0X1  (0x1u<<0)

// AHB5FZR Configuration

#define DBGMCU_AHB5FZR_DBG_HPDMA1_15_STOP       (0x1u<<15)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_14_STOP       (0x1u<<14)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_13_STOP       (0x1u<<13)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_12_STOP       (0x1u<<12)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_11_STOP       (0x1u<<11)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_10_STOP       (0x1u<<10)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_9_STOP        (0x1u<<9)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_8_STOP        (0x1u<<8)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_7_STOP        (0x1u<<7)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_6_STOP        (0x1u<<6)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_5_STOP        (0x1u<<5)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_4_STOP        (0x1u<<4)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_3_STOP        (0x1u<<3)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_2_STOP        (0x1u<<2)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_1_STOP        (0x1u<<1)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_0_STOP        (0x1u<<0)

#define DBGMCU_AHB5FZR_DBG_HPDMA1_15_STOP_B_0X0 (0x0u<<15)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_15_STOP_B_0X1 (0x1u<<15)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_14_STOP_B_0X0 (0x0u<<14)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_14_STOP_B_0X1 (0x1u<<14)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_13_STOP_B_0X0 (0x0u<<13)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_13_STOP_B_0X1 (0x1u<<13)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_12_STOP_B_0X0 (0x0u<<12)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_12_STOP_B_0X1 (0x1u<<12)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_11_STOP_B_0X0 (0x0u<<11)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_11_STOP_B_0X1 (0x1u<<11)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_10_STOP_B_0X0 (0x0u<<10)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_10_STOP_B_0X1 (0x1u<<10)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_9_STOP_B_0X0  (0x0u<<9)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_9_STOP_B_0X1  (0x1u<<9)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_8_STOP_B_0X0  (0x0u<<8)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_8_STOP_B_0X1  (0x1u<<8)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_7_STOP_B_0X0  (0x0u<<7)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_7_STOP_B_0X1  (0x1u<<7)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_6_STOP_B_0X0  (0x0u<<6)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_6_STOP_B_0X1  (0x1u<<6)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_5_STOP_B_0X0  (0x0u<<5)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_5_STOP_B_0X1  (0x1u<<5)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_4_STOP_B_0X0  (0x0u<<4)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_4_STOP_B_0X1  (0x1u<<4)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_3_STOP_B_0X0  (0x0u<<3)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_3_STOP_B_0X1  (0x1u<<3)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_2_STOP_B_0X0  (0x0u<<2)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_2_STOP_B_0X1  (0x1u<<2)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_1_STOP_B_0X0  (0x0u<<1)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_1_STOP_B_0X1  (0x1u<<1)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_0_STOP_B_0X0  (0x0u<<0)
#define DBGMCU_AHB5FZR_DBG_HPDMA1_0_STOP_B_0X1  (0x1u<<0)

// APB1FZR Configuration

#define DBGMCU_APB1FZR_I3C2                     (0x1u<<25)
#define DBGMCU_APB1FZR_I3C1                     (0x1u<<24)
#define DBGMCU_APB1FZR_I2C3                     (0x1u<<23)
#define DBGMCU_APB1FZR_I2C2                     (0x1u<<22)
#define DBGMCU_APB1FZR_I2C1                     (0x1u<<21)
#define DBGMCU_APB1FZR_TIM10                    (0x1u<<12)
#define DBGMCU_APB1FZR_WWDG                     (0x1u<<11)
#define DBGMCU_APB1FZR_LPTIM1                   (0x1u<<9)
#define DBGMCU_APB1FZR_TIM14                    (0x1u<<8)
#define DBGMCU_APB1FZR_TIM13                    (0x1u<<7)
#define DBGMCU_APB1FZR_TIM12                    (0x1u<<6)
#define DBGMCU_APB1FZR_TIM7                     (0x1u<<5)
#define DBGMCU_APB1FZR_TIM6                     (0x1u<<4)
#define DBGMCU_APB1FZR_TIM5                     (0x1u<<3)
#define DBGMCU_APB1FZR_TIM4                     (0x1u<<2)
#define DBGMCU_APB1FZR_TIM3                     (0x1u<<1)
#define DBGMCU_APB1FZR_TIM2                     (0x1u<<0)

#define DBGMCU_APB1FZR_I3C2_B_0X0               (0x0u<<25)
#define DBGMCU_APB1FZR_I3C2_B_0X1               (0x1u<<25)
#define DBGMCU_APB1FZR_I3C1_B_0X0               (0x0u<<24)
#define DBGMCU_APB1FZR_I3C1_B_0X1               (0x1u<<24)
#define DBGMCU_APB1FZR_I2C3_B_0X0               (0x0u<<23)
#define DBGMCU_APB1FZR_I2C3_B_0X1               (0x1u<<23)
#define DBGMCU_APB1FZR_I2C2_B_0X0               (0x0u<<22)
#define DBGMCU_APB1FZR_I2C2_B_0X1               (0x1u<<22)
#define DBGMCU_APB1FZR_I2C1_B_0X0               (0x0u<<21)
#define DBGMCU_APB1FZR_I2C1_B_0X1               (0x1u<<21)
#define DBGMCU_APB1FZR_TIM10_B_0X0              (0x0u<<12)
#define DBGMCU_APB1FZR_TIM10_B_0X1              (0x1u<<12)
#define DBGMCU_APB1FZR_WWDG_B_0X0               (0x0u<<11)
#define DBGMCU_APB1FZR_WWDG_B_0X1               (0x1u<<11)
#define DBGMCU_APB1FZR_LPTIM1_B_0X0             (0x0u<<9)
#define DBGMCU_APB1FZR_LPTIM1_B_0X1             (0x1u<<9)
#define DBGMCU_APB1FZR_TIM14_B_0X0              (0x0u<<8)
#define DBGMCU_APB1FZR_TIM14_B_0X1              (0x1u<<8)
#define DBGMCU_APB1FZR_TIM13_B_0X0              (0x0u<<7)
#define DBGMCU_APB1FZR_TIM13_B_0X1              (0x1u<<7)
#define DBGMCU_APB1FZR_TIM12_B_0X0              (0x0u<<6)
#define DBGMCU_APB1FZR_TIM12_B_0X1              (0x1u<<6)
#define DBGMCU_APB1FZR_TIM7_B_0X0               (0x0u<<5)
#define DBGMCU_APB1FZR_TIM7_B_0X1               (0x1u<<5)
#define DBGMCU_APB1FZR_TIM6_B_0X0               (0x0u<<4)
#define DBGMCU_APB1FZR_TIM6_B_0X1               (0x1u<<4)
#define DBGMCU_APB1FZR_TIM5_B_0X0               (0x0u<<3)
#define DBGMCU_APB1FZR_TIM5_B_0X1               (0x1u<<3)
#define DBGMCU_APB1FZR_TIM4_B_0X0               (0x0u<<2)
#define DBGMCU_APB1FZR_TIM4_B_0X1               (0x1u<<2)
#define DBGMCU_APB1FZR_TIM3_B_0X0               (0x0u<<1)
#define DBGMCU_APB1FZR_TIM3_B_0X1               (0x1u<<1)
#define DBGMCU_APB1FZR_TIM2_B_0X0               (0x0u<<0)
#define DBGMCU_APB1FZR_TIM2_B_0X1               (0x1u<<0)

// APB2FZR Configuration

#define DBGMCU_APB2FZR_HRTIM1                   (0x1u<<28)
#define DBGMCU_APB2FZR_TIM9                     (0x1u<<19)
#define DBGMCU_APB2FZR_TIM17                    (0x1u<<18)
#define DBGMCU_APB2FZR_TIM16                    (0x1u<<17)
#define DBGMCU_APB2FZR_TIM15                    (0x1u<<16)
#define DBGMCU_APB2FZR_TIM20                    (0x1u<<2)
#define DBGMCU_APB2FZR_TIM8                     (0x1u<<1)
#define DBGMCU_APB2FZR_TIM1                     (0x1u<<0)

#define DBGMCU_APB2FZR_HRTIM1_B_0X0             (0x0u<<28)
#define DBGMCU_APB2FZR_HRTIM1_B_0X1             (0x1u<<28)
#define DBGMCU_APB2FZR_TIM9_B_0X0               (0x0u<<19)
#define DBGMCU_APB2FZR_TIM9_B_0X1               (0x1u<<19)
#define DBGMCU_APB2FZR_TIM17_B_0X0              (0x0u<<18)
#define DBGMCU_APB2FZR_TIM17_B_0X1              (0x1u<<18)
#define DBGMCU_APB2FZR_TIM16_B_0X0              (0x0u<<17)
#define DBGMCU_APB2FZR_TIM16_B_0X1              (0x1u<<17)
#define DBGMCU_APB2FZR_TIM15_B_0X0              (0x0u<<16)
#define DBGMCU_APB2FZR_TIM15_B_0X1              (0x1u<<16)
#define DBGMCU_APB2FZR_TIM20_B_0X0              (0x0u<<2)
#define DBGMCU_APB2FZR_TIM20_B_0X1              (0x1u<<2)
#define DBGMCU_APB2FZR_TIM8_B_0X0               (0x0u<<1)
#define DBGMCU_APB2FZR_TIM8_B_0X1               (0x1u<<1)
#define DBGMCU_APB2FZR_TIM1_B_0X0               (0x0u<<0)
#define DBGMCU_APB2FZR_TIM1_B_0X1               (0x1u<<0)

// APB4FZR Configuration

#define DBGMCU_APB4FZR_IWDG                     (0x1u<<18)
#define DBGMCU_APB4FZR_RTC                      (0x1u<<16)
#define DBGMCU_APB4FZR_LPTIM5                   (0x1u<<12)
#define DBGMCU_APB4FZR_LPTIM4                   (0x1u<<11)
#define DBGMCU_APB4FZR_LPTIM3                   (0x1u<<10)
#define DBGMCU_APB4FZR_LPTIM2                   (0x1u<<9)

#define DBGMCU_APB4FZR_IWDG_B_0X0               (0x0u<<18)
#define DBGMCU_APB4FZR_IWDG_B_0X1               (0x1u<<18)
#define DBGMCU_APB4FZR_RTC_B_0X0                (0x0u<<16)
#define DBGMCU_APB4FZR_RTC_B_0X1                (0x1u<<16)
#define DBGMCU_APB4FZR_LPTIM5_B_0X0             (0x0u<<12)
#define DBGMCU_APB4FZR_LPTIM5_B_0X1             (0x1u<<12)
#define DBGMCU_APB4FZR_LPTIM4_B_0X0             (0x0u<<11)
#define DBGMCU_APB4FZR_LPTIM4_B_0X1             (0x1u<<11)
#define DBGMCU_APB4FZR_LPTIM3_B_0X0             (0x0u<<10)
#define DBGMCU_APB4FZR_LPTIM3_B_0X1             (0x1u<<10)
#define DBGMCU_APB4FZR_LPTIM2_B_0X0             (0x0u<<9)
#define DBGMCU_APB4FZR_LPTIM2_B_0X1             (0x1u<<9)

// SR Configuration

#define DBGMCU_SR_AP_ENABLED                    (0xFFFFu<<16)
#define DBGMCU_SR_AP_ENABLED_0                  (0x1u<<16)
#define DBGMCU_SR_AP_PRESENT                    (0xFFFFu<<0)
#define DBGMCU_SR_AP_PRESENT_0                  (0x1u<<0)

// DBG_AUTH_HOST Configuration

#define DBGMCU_DBG_AUTH_HOST_MESSAGE            (0xFFFFFFFFu<<0)
#define DBGMCU_DBG_AUTH_HOST_MESSAGE_0          (0x1u<<0)

// DBG_AUTH_DEVICE Configuration

#define DBGMCU_DBG_AUTH_DEVICE_MESSAGE          (0xFFFFFFFFu<<0)
#define DBGMCU_DBG_AUTH_DEVICE_MESSAGE_0        (0x1u<<0)

// DBG_AUTH_ACK Configuration

#define DBGMCU_DBG_AUTH_ACK_DEV_ACK             (0x1u<<1)
#define DBGMCU_DBG_AUTH_ACK_HOST_ACK            (0x1u<<0)

#define DBGMCU_DBG_AUTH_ACK_DEV_ACK_B_0X0       (0x0u<<1)
#define DBGMCU_DBG_AUTH_ACK_HOST_ACK_B_0X0      (0x0u<<0)

// PIDR4 Configuration

#define DBGMCU_PIDR4_SIZE                       (0xFu<<4)
#define DBGMCU_PIDR4_SIZE_0                     (0x1u<<4)
#define DBGMCU_PIDR4_JEP106CON                  (0xFu<<0)
#define DBGMCU_PIDR4_JEP106CON_0                (0x1u<<0)

#define DBGMCU_PIDR4_SIZE_B_0X0                 (0x0u<<4)
#define DBGMCU_PIDR4_JEP106CON_B_0X0            (0x0u<<0)

// PIDR0 Configuration

#define DBGMCU_PIDR0_PARTNUM                    (0xFFu<<0)
#define DBGMCU_PIDR0_PARTNUM_0                  (0x1u<<0)

#define DBGMCU_PIDR0_PARTNUM_B_0X0              (0x0u<<0)

// PIDR1 Configuration

#define DBGMCU_PIDR1_JEP106ID                   (0xFu<<4)
#define DBGMCU_PIDR1_JEP106ID_0                 (0x1u<<4)
#define DBGMCU_PIDR1_PARTNUM                    (0xFu<<0)
#define DBGMCU_PIDR1_PARTNUM_0                  (0x1u<<0)

#define DBGMCU_PIDR1_JEP106ID_B_0X0             (0x0u<<4)
#define DBGMCU_PIDR1_PARTNUM_B_0X0              (0x0u<<0)

// PIDR2 Configuration

#define DBGMCU_PIDR2_REVISION                   (0xFu<<4)
#define DBGMCU_PIDR2_REVISION_0                 (0x1u<<4)
#define DBGMCU_PIDR2_JEDEC                      (0x1u<<3)
#define DBGMCU_PIDR2_JEP106ID                   (0x7u<<0)
#define DBGMCU_PIDR2_JEP106ID_0                 (0x1u<<0)

#define DBGMCU_PIDR2_REVISION_B_0X0             (0x0u<<4)
#define DBGMCU_PIDR2_JEDEC_B_0X1                (0x1u<<3)
#define DBGMCU_PIDR2_JEP106ID_B_0X2             (0x2u<<0)

// PIDR3 Configuration

#define DBGMCU_PIDR3_REVAND                     (0xFu<<4)
#define DBGMCU_PIDR3_REVAND_0                   (0x1u<<4)
#define DBGMCU_PIDR3_CMOD                       (0xFu<<0)
#define DBGMCU_PIDR3_CMOD_0                     (0x1u<<0)

#define DBGMCU_PIDR3_REVAND_B_0X0               (0x0u<<4)
#define DBGMCU_PIDR3_CMOD_B_0X0                 (0x0u<<0)

// CIDR0 Configuration

#define DBGMCU_CIDR0_PREAMBLE                   (0xFFu<<0)
#define DBGMCU_CIDR0_PREAMBLE_0                 (0x1u<<0)

#define DBGMCU_CIDR0_PREAMBLE_B_0X0D            (0xDu<<0)

// CIDR1 Configuration

#define DBGMCU_CIDR1_CLASS                      (0xFu<<4)
#define DBGMCU_CIDR1_CLASS_0                    (0x1u<<4)
#define DBGMCU_CIDR1_PREAMBLE                   (0xFu<<0)
#define DBGMCU_CIDR1_PREAMBLE_0                 (0x1u<<0)

#define DBGMCU_CIDR1_CLASS_B_0XF                (0xFu<<4)
#define DBGMCU_CIDR1_PREAMBLE_B_0X0             (0x0u<<0)

// CIDR2 Configuration

#define DBGMCU_CIDR2_PREAMBLE                   (0xFFu<<0)
#define DBGMCU_CIDR2_PREAMBLE_0                 (0x1u<<0)

#define DBGMCU_CIDR2_PREAMBLE_B_0X05            (0x5u<<0)

// CIDR3 Configuration

#define DBGMCU_CIDR3_PREAMBLE                   (0xFFu<<0)
#define DBGMCU_CIDR3_PREAMBLE_0                 (0x1u<<0)

#define DBGMCU_CIDR3_PREAMBLE_B_0XB1            (0xB1u<<0)
