/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_dbgmcu.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_dbgmcu equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// DBGMCU address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    IDCODE;
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    APB1LFZ1;
    volatile    uint32_t    APB1HFZ1;
    volatile    uint32_t    APB2FZ1;
    volatile    uint32_t    APB4FZ1;
    volatile    uint32_t    APB5FZ1;
    volatile    uint32_t    AHB1FZ1;
    volatile    uint32_t    AHB5FZ1;
    volatile    uint32_t    RESERVED1[52];
    volatile    uint32_t    SR;
    volatile    uint32_t    DBG_AUTH_HOST;
    volatile    uint32_t    DBG_AUTH_DEV;
    volatile    uint32_t    DBG_AUTH_ACK;
} DBGMCU_TypeDef;

#ifdef __cplusplus
#define DBGMCU_NS   reinterpret_cast<DBGMCU_TypeDef *>(0x44001000U)
#define DBGMCU_S    reinterpret_cast<DBGMCU_TypeDef *>(0x54001000U)

#else
#define DBGMCU_NS   ((DBGMCU_TypeDef *)0x44001000U)
#define DBGMCU_S    ((DBGMCU_TypeDef *)0x54001000U)
#endif

// IDCODE Configuration

#define DBGMCU_IDCODE_REV_ID                        (0xFFFFU<<16)
#define DBGMCU_IDCODE_REV_ID_0                      (0x1U<<16)
#define DBGMCU_IDCODE_DEV_ID                        (0xFFFU<<0)
#define DBGMCU_IDCODE_DEV_ID_0                      (0x1U<<0)

#define DBGMCU_IDCODE_DEV_ID_B_0X486                (0x486U<<0)

// CR Configuration

#define DBGMCU_CR_HLT_TSGEN_EN                      (0x1U<<31)
#define DBGMCU_CR_DBTRGOEN                          (0x1U<<28)
#define DBGMCU_CR_TRACECLKEN                        (0x1U<<21)
#define DBGMCU_CR_DBGCLKEN                          (0x1U<<20)
#define DBGMCU_CR_DBG_STANDBY                       (0x1U<<2)
#define DBGMCU_CR_DBG_STOP                          (0x1U<<1)
#define DBGMCU_CR_DBG_SLEEP                         (0x1U<<0)

#define DBGMCU_CR_HLT_TSGEN_EN_B_0X1                (0x1U<<31)
#define DBGMCU_CR_HLT_TSGEN_EN_B_0X0                (0x0U<<31)
#define DBGMCU_CR_DBTRGOEN_B_0X0                    (0x0U<<28)
#define DBGMCU_CR_DBTRGOEN_B_0X1                    (0x1U<<28)
#define DBGMCU_CR_TRACECLKEN_B_0X0                  (0x0U<<21)
#define DBGMCU_CR_TRACECLKEN_B_0X1                  (0x1U<<21)
#define DBGMCU_CR_DBGCLKEN_B_0X0                    (0x0U<<20)
#define DBGMCU_CR_DBGCLKEN_B_0X1                    (0x1U<<20)
#define DBGMCU_CR_DBG_STANDBY_B_0X0                 (0x0U<<2)
#define DBGMCU_CR_DBG_STANDBY_B_0X1                 (0x1U<<2)
#define DBGMCU_CR_DBG_STOP_B_0X0                    (0x0U<<1)
#define DBGMCU_CR_DBG_STOP_B_0X1                    (0x1U<<1)
#define DBGMCU_CR_DBG_SLEEP_B_0X0                   (0x0U<<0)
#define DBGMCU_CR_DBG_SLEEP_B_0X1                   (0x1U<<0)

// APB1LFZ1 Configuration

#define DBGMCU_APB1LFZ1_DBG_I3C2_STOP               (0x1U<<25)
#define DBGMCU_APB1LFZ1_DBG_I3C1_STOP               (0x1U<<24)
#define DBGMCU_APB1LFZ1_DBG_I2C3_STOP               (0x1U<<23)
#define DBGMCU_APB1LFZ1_DBG_I2C2_STOP               (0x1U<<22)
#define DBGMCU_APB1LFZ1_DBG_I2C1_STOP               (0x1U<<21)
#define DBGMCU_APB1LFZ1_DBG_TIM11_STOP              (0x1U<<13)
#define DBGMCU_APB1LFZ1_DBG_TIM10_STOP              (0x1U<<12)
#define DBGMCU_APB1LFZ1_DBG_WWDG1_STOP              (0x1U<<11)
#define DBGMCU_APB1LFZ1_DBG_LPTIM1_STOP             (0x1U<<9)
#define DBGMCU_APB1LFZ1_DBG_TIM14_STOP              (0x1U<<8)
#define DBGMCU_APB1LFZ1_DBG_TIM13_STOP              (0x1U<<7)
#define DBGMCU_APB1LFZ1_DBG_TIM12_STOP              (0x1U<<6)
#define DBGMCU_APB1LFZ1_DBG_TIM7_STOP               (0x1U<<5)
#define DBGMCU_APB1LFZ1_DBG_TIM6_STOP               (0x1U<<4)
#define DBGMCU_APB1LFZ1_DBG_TIM5_STOP               (0x1U<<3)
#define DBGMCU_APB1LFZ1_DBG_TIM4_STOP               (0x1U<<2)
#define DBGMCU_APB1LFZ1_DBG_TIM3_STOP               (0x1U<<1)
#define DBGMCU_APB1LFZ1_DBG_TIM2_STOP               (0x1U<<0)

#define DBGMCU_APB1LFZ1_DBG_I3C2_STOP_B_0X0         (0x0U<<25)
#define DBGMCU_APB1LFZ1_DBG_I3C2_STOP_B_0X1         (0x1U<<25)
#define DBGMCU_APB1LFZ1_DBG_I3C1_STOP_B_0X0         (0x0U<<24)
#define DBGMCU_APB1LFZ1_DBG_I3C1_STOP_B_0X1         (0x1U<<24)
#define DBGMCU_APB1LFZ1_DBG_I2C3_STOP_B_0X0         (0x0U<<23)
#define DBGMCU_APB1LFZ1_DBG_I2C3_STOP_B_0X1         (0x1U<<23)
#define DBGMCU_APB1LFZ1_DBG_I2C2_STOP_B_0X0         (0x0U<<22)
#define DBGMCU_APB1LFZ1_DBG_I2C2_STOP_B_0X1         (0x1U<<22)
#define DBGMCU_APB1LFZ1_DBG_I2C1_STOP_B_0X0         (0x0U<<21)
#define DBGMCU_APB1LFZ1_DBG_I2C1_STOP_B_0X1         (0x1U<<21)
#define DBGMCU_APB1LFZ1_DBG_TIM11_STOP_B_0X0        (0x0U<<13)
#define DBGMCU_APB1LFZ1_DBG_TIM11_STOP_B_0X1        (0x1U<<13)
#define DBGMCU_APB1LFZ1_DBG_TIM10_STOP_B_0X0        (0x0U<<12)
#define DBGMCU_APB1LFZ1_DBG_TIM10_STOP_B_0X1        (0x1U<<12)
#define DBGMCU_APB1LFZ1_DBG_WWDG1_STOP_B_0X0        (0x0U<<11)
#define DBGMCU_APB1LFZ1_DBG_WWDG1_STOP_B_0X1        (0x1U<<11)
#define DBGMCU_APB1LFZ1_DBG_LPTIM1_STOP_B_0X0       (0x0U<<9)
#define DBGMCU_APB1LFZ1_DBG_LPTIM1_STOP_B_0X1       (0x1U<<9)
#define DBGMCU_APB1LFZ1_DBG_TIM14_STOP_B_0X0        (0x0U<<8)
#define DBGMCU_APB1LFZ1_DBG_TIM14_STOP_B_0X1        (0x1U<<8)
#define DBGMCU_APB1LFZ1_DBG_TIM13_STOP_B_0X0        (0x0U<<7)
#define DBGMCU_APB1LFZ1_DBG_TIM13_STOP_B_0X1        (0x1U<<7)
#define DBGMCU_APB1LFZ1_DBG_TIM12_STOP_B_0X0        (0x0U<<6)
#define DBGMCU_APB1LFZ1_DBG_TIM12_STOP_B_0X1        (0x1U<<6)
#define DBGMCU_APB1LFZ1_DBG_TIM7_STOP_B_0X0         (0x0U<<5)
#define DBGMCU_APB1LFZ1_DBG_TIM7_STOP_B_0X1         (0x1U<<5)
#define DBGMCU_APB1LFZ1_DBG_TIM6_STOP_B_0X0         (0x0U<<4)
#define DBGMCU_APB1LFZ1_DBG_TIM6_STOP_B_0X1         (0x1U<<4)
#define DBGMCU_APB1LFZ1_DBG_TIM5_STOP_B_0X0         (0x0U<<3)
#define DBGMCU_APB1LFZ1_DBG_TIM5_STOP_B_0X1         (0x1U<<3)
#define DBGMCU_APB1LFZ1_DBG_TIM4_STOP_B_0X0         (0x0U<<2)
#define DBGMCU_APB1LFZ1_DBG_TIM4_STOP_B_0X1         (0x1U<<2)
#define DBGMCU_APB1LFZ1_DBG_TIM3_STOP_B_0X0         (0x0U<<1)
#define DBGMCU_APB1LFZ1_DBG_TIM3_STOP_B_0X1         (0x1U<<1)
#define DBGMCU_APB1LFZ1_DBG_TIM2_STOP_B_0X0         (0x0U<<0)
#define DBGMCU_APB1LFZ1_DBG_TIM2_STOP_B_0X1         (0x1U<<0)

// APB1HFZ1 Configuration

#define DBGMCU_APB1HFZ1_DBG_FDCAN_STOP              (0x1U<<8)

#define DBGMCU_APB1HFZ1_DBG_FDCAN_STOP_B_0X0        (0x0U<<8)
#define DBGMCU_APB1HFZ1_DBG_FDCAN_STOP_B_0X1        (0x1U<<8)

// APB2FZ1 Configuration

#define DBGMCU_APB2FZ1_DBG_TIM9_STOP                (0x1U<<19)
#define DBGMCU_APB2FZ1_DBG_TIM17_STOP               (0x1U<<18)
#define DBGMCU_APB2FZ1_DBG_TIM16_STOP               (0x1U<<17)
#define DBGMCU_APB2FZ1_DBG_TIM15_STOP               (0x1U<<16)
#define DBGMCU_APB2FZ1_DBG_TIM18_STOP               (0x1U<<15)
#define DBGMCU_APB2FZ1_DBG_TIM8_STOP                (0x1U<<1)
#define DBGMCU_APB2FZ1_DBG_TIM1_STOP                (0x1U<<0)

#define DBGMCU_APB2FZ1_DBG_TIM9_STOP_B_0X0          (0x0U<<19)
#define DBGMCU_APB2FZ1_DBG_TIM9_STOP_B_0X1          (0x1U<<19)
#define DBGMCU_APB2FZ1_DBG_TIM17_STOP_B_0X0         (0x0U<<18)
#define DBGMCU_APB2FZ1_DBG_TIM17_STOP_B_0X1         (0x1U<<18)
#define DBGMCU_APB2FZ1_DBG_TIM16_STOP_B_0X0         (0x0U<<17)
#define DBGMCU_APB2FZ1_DBG_TIM16_STOP_B_0X1         (0x1U<<17)
#define DBGMCU_APB2FZ1_DBG_TIM15_STOP_B_0X0         (0x0U<<16)
#define DBGMCU_APB2FZ1_DBG_TIM15_STOP_B_0X1         (0x1U<<16)
#define DBGMCU_APB2FZ1_DBG_TIM18_STOP_B_0X0         (0x0U<<15)
#define DBGMCU_APB2FZ1_DBG_TIM18_STOP_B_0X1         (0x1U<<15)
#define DBGMCU_APB2FZ1_DBG_TIM8_STOP_B_0X0          (0x0U<<1)
#define DBGMCU_APB2FZ1_DBG_TIM8_STOP_B_0X1          (0x1U<<1)
#define DBGMCU_APB2FZ1_DBG_TIM1_STOP_B_0X0          (0x0U<<0)
#define DBGMCU_APB2FZ1_DBG_TIM1_STOP_B_0X1          (0x1U<<0)

// APB4FZ1 Configuration

#define DBGMCU_APB4FZ1_DBG_IWDG_STOP                (0x1U<<18)
#define DBGMCU_APB4FZ1_DBG_RTC_STOP                 (0x1U<<16)
#define DBGMCU_APB4FZ1_DBG_LPTIM5_STOP              (0x1U<<12)
#define DBGMCU_APB4FZ1_DBG_LPTIM4_STOP              (0x1U<<11)
#define DBGMCU_APB4FZ1_DBG_LPTIM3_STOP              (0x1U<<10)
#define DBGMCU_APB4FZ1_DBG_LPTIM2_STOP              (0x1U<<9)
#define DBGMCU_APB4FZ1_DBG_I2C4_STOP                (0x1U<<8)

#define DBGMCU_APB4FZ1_DBG_IWDG_STOP_B_0X0          (0x0U<<18)
#define DBGMCU_APB4FZ1_DBG_IWDG_STOP_B_0X1          (0x1U<<18)
#define DBGMCU_APB4FZ1_DBG_RTC_STOP_B_0X0           (0x0U<<16)
#define DBGMCU_APB4FZ1_DBG_RTC_STOP_B_0X1           (0x1U<<16)
#define DBGMCU_APB4FZ1_DBG_LPTIM5_STOP_B_0X0        (0x0U<<12)
#define DBGMCU_APB4FZ1_DBG_LPTIM5_STOP_B_0X1        (0x1U<<12)
#define DBGMCU_APB4FZ1_DBG_LPTIM4_STOP_B_0X0        (0x0U<<11)
#define DBGMCU_APB4FZ1_DBG_LPTIM4_STOP_B_0X1        (0x1U<<11)
#define DBGMCU_APB4FZ1_DBG_LPTIM3_STOP_B_0X0        (0x0U<<10)
#define DBGMCU_APB4FZ1_DBG_LPTIM3_STOP_B_0X1        (0x1U<<10)
#define DBGMCU_APB4FZ1_DBG_LPTIM2_STOP_B_0X0        (0x0U<<9)
#define DBGMCU_APB4FZ1_DBG_LPTIM2_STOP_B_0X1        (0x1U<<9)
#define DBGMCU_APB4FZ1_DBG_I2C4_STOP_B_0X0          (0x0U<<8)
#define DBGMCU_APB4FZ1_DBG_I2C4_STOP_B_0X1          (0x1U<<8)

// APB5FZ1 Configuration

#define DBGMCU_APB5FZ1_DBG_GFXTIM_STOP              (0x1U<<4)

#define DBGMCU_APB5FZ1_DBG_GFXTIM_STOP_B_0X0        (0x0U<<4)
#define DBGMCU_APB5FZ1_DBG_GFXTIM_STOP_B_0X1        (0x1U<<4)

// AHB1FZ1 Configuration

#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH15_STOP         (0x1U<<15)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH14_STOP         (0x1U<<14)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH13_STOP         (0x1U<<13)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH12_STOP         (0x1U<<12)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH11_STOP         (0x1U<<11)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH10_STOP         (0x1U<<10)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH9_STOP          (0x1U<<9)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH8_STOP          (0x1U<<8)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH7_STOP          (0x1U<<7)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH6_STOP          (0x1U<<6)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH5_STOP          (0x1U<<5)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH4_STOP          (0x1U<<4)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH3_STOP          (0x1U<<3)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH2_STOP          (0x1U<<2)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH1_STOP          (0x1U<<1)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH0_STOP          (0x1U<<0)

#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH15_STOP_B_0X0   (0x0U<<15)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH15_STOP_B_0X1   (0x1U<<15)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH14_STOP_B_0X0   (0x0U<<14)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH14_STOP_B_0X1   (0x1U<<14)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH13_STOP_B_0X0   (0x0U<<13)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH13_STOP_B_0X1   (0x1U<<13)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH12_STOP_B_0X0   (0x0U<<12)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH12_STOP_B_0X1   (0x1U<<12)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH11_STOP_B_0X0   (0x0U<<11)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH11_STOP_B_0X1   (0x1U<<11)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH10_STOP_B_0X0   (0x0U<<10)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH10_STOP_B_0X1   (0x1U<<10)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH9_STOP_B_0X0    (0x0U<<9)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH9_STOP_B_0X1    (0x1U<<9)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH8_STOP_B_0X0    (0x0U<<8)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH8_STOP_B_0X1    (0x1U<<8)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH7_STOP_B_0X0    (0x0U<<7)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH7_STOP_B_0X1    (0x1U<<7)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH6_STOP_B_0X0    (0x0U<<6)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH6_STOP_B_0X1    (0x1U<<6)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH5_STOP_B_0X0    (0x0U<<5)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH5_STOP_B_0X1    (0x1U<<5)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH4_STOP_B_0X0    (0x0U<<4)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH4_STOP_B_0X1    (0x1U<<4)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH3_STOP_B_0X0    (0x0U<<3)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH3_STOP_B_0X1    (0x1U<<3)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH2_STOP_B_0X0    (0x0U<<2)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH2_STOP_B_0X1    (0x1U<<2)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH1_STOP_B_0X0    (0x0U<<1)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH1_STOP_B_0X1    (0x1U<<1)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH0_STOP_B_0X0    (0x0U<<0)
#define DBGMCU_AHB1FZ1_DBG_GPDMA1_CH0_STOP_B_0X1    (0x1U<<0)

// AHB5FZ1 Configuration

#define DBGMCU_AHB5FZ1_NPU_DBG_FREEZE               (0x1U<<16)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH15_STOP         (0x1U<<15)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH14_STOP         (0x1U<<14)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH13_STOP         (0x1U<<13)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH12_STOP         (0x1U<<12)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH11_STOP         (0x1U<<11)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH10_STOP         (0x1U<<10)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH9_STOP          (0x1U<<9)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH8_STOP          (0x1U<<8)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH7_STOP          (0x1U<<7)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH6_STOP          (0x1U<<6)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH5_STOP          (0x1U<<5)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH4_STOP          (0x1U<<4)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH3_STOP          (0x1U<<3)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH2_STOP          (0x1U<<2)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH1_STOP          (0x1U<<1)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH0_STOP          (0x1U<<0)

#define DBGMCU_AHB5FZ1_NPU_DBG_FREEZE_B_0X0         (0x0U<<16)
#define DBGMCU_AHB5FZ1_NPU_DBG_FREEZE_B_0X1         (0x1U<<16)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH15_STOP_B_0X0   (0x0U<<15)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH15_STOP_B_0X1   (0x1U<<15)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH14_STOP_B_0X0   (0x0U<<14)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH14_STOP_B_0X1   (0x1U<<14)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH13_STOP_B_0X0   (0x0U<<13)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH13_STOP_B_0X1   (0x1U<<13)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH12_STOP_B_0X0   (0x0U<<12)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH12_STOP_B_0X1   (0x1U<<12)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH11_STOP_B_0X0   (0x0U<<11)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH11_STOP_B_0X1   (0x1U<<11)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH10_STOP_B_0X0   (0x0U<<10)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH10_STOP_B_0X1   (0x1U<<10)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH9_STOP_B_0X0    (0x0U<<9)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH9_STOP_B_0X1    (0x1U<<9)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH8_STOP_B_0X0    (0x0U<<8)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH8_STOP_B_0X1    (0x1U<<8)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH7_STOP_B_0X0    (0x0U<<7)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH7_STOP_B_0X1    (0x1U<<7)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH6_STOP_B_0X0    (0x0U<<6)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH6_STOP_B_0X1    (0x1U<<6)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH5_STOP_B_0X0    (0x0U<<5)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH5_STOP_B_0X1    (0x1U<<5)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH4_STOP_B_0X0    (0x0U<<4)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH4_STOP_B_0X1    (0x1U<<4)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH3_STOP_B_0X0    (0x0U<<3)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH3_STOP_B_0X1    (0x1U<<3)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH2_STOP_B_0X0    (0x0U<<2)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH2_STOP_B_0X1    (0x1U<<2)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH1_STOP_B_0X0    (0x0U<<1)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH1_STOP_B_0X1    (0x1U<<1)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH0_STOP_B_0X0    (0x0U<<0)
#define DBGMCU_AHB5FZ1_DBG_HPDMA1_CH0_STOP_B_0X1    (0x1U<<0)

// SR Configuration

#define DBGMCU_SR_AP1_ENABLE                        (0x1U<<17)
#define DBGMCU_SR_AP0_ENABLE                        (0x1U<<16)
#define DBGMCU_SR_AP1_PRESENT                       (0x1U<<1)
#define DBGMCU_SR_AP0_PRESENT                       (0x1U<<0)

#define DBGMCU_SR_AP1_ENABLE_B_0X0                  (0x0U<<17)
#define DBGMCU_SR_AP1_ENABLE_B_0X1                  (0x1U<<17)
#define DBGMCU_SR_AP0_ENABLE_B_0X1                  (0x1U<<16)
#define DBGMCU_SR_AP1_PRESENT_B_0X1                 (0x1U<<1)
#define DBGMCU_SR_AP0_PRESENT_B_0X1                 (0x1U<<0)

// DBG_AUTH_HOST Configuration

#define DBGMCU_DBG_AUTH_HOST_MESSAGE                (0xFFFFFFFFU<<0)
#define DBGMCU_DBG_AUTH_HOST_MESSAGE_0              (0x1U<<0)

// DBG_AUTH_DEV Configuration

#define DBGMCU_DBG_AUTH_DEV_MESSAGE                 (0xFFFFFFFFU<<0)
#define DBGMCU_DBG_AUTH_DEV_MESSAGE_0               (0x1U<<0)

// DBG_AUTH_ACK Configuration

#define DBGMCU_DBG_AUTH_ACK_DEVICE_ACK              (0x1U<<1)
#define DBGMCU_DBG_AUTH_ACK_HOST_ACK                (0x1U<<0)

#define DBGMCU_DBG_AUTH_ACK_DEVICE_ACK_B_0X1        (0x1U<<1)
#define DBGMCU_DBG_AUTH_ACK_DEVICE_ACK_B_0X0        (0x0U<<1)
#define DBGMCU_DBG_AUTH_ACK_HOST_ACK_B_0X1          (0x1U<<0)
#define DBGMCU_DBG_AUTH_ACK_HOST_ACK_B_0X0          (0x0U<<0)
