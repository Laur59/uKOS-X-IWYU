/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_rcc equates.
 */

#pragma once

#include    <stdint.h>

// RCC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    ICSCR;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    PLLCFGR;
    volatile    uint32_t    PLLSAI1CFGR;
    volatile    uint32_t    PLLSAI2CFGR;
    volatile    uint32_t    CIER;
    volatile    uint32_t    CIFR;
    volatile    uint32_t    CICR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    AHB1RSTR;
    volatile    uint32_t    AHB2RSTR;
    volatile    uint32_t    AHB3RSTR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    APB1RSTR1;
    volatile    uint32_t    APB1RSTR2;
    volatile    uint32_t    APB2RSTR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    AHB1ENR;
    volatile    uint32_t    AHB2ENR;
    volatile    uint32_t    AHB3ENR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    APB1ENR1;
    volatile    uint32_t    APB1ENR2;
    volatile    uint32_t    APB2ENR;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    AHB1SMENR;
    volatile    uint32_t    AHB2SMENR;
    volatile    uint32_t    AHB3SMENR;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    APB1SMENR1;
    volatile    uint32_t    APB1SMENR2;
    volatile    uint32_t    APB2SMENR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    CCIPR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    BDCR;
    volatile    uint32_t    CSR;
    volatile    uint32_t    CRRCR;
    volatile    uint32_t    CCIPR2;
} RCC_TypeDef;

#ifdef __cplusplus
#define RCC reinterpret_cast<RCC_TypeDef *>(0x40021000U)

#else
#define RCC ((RCC_TypeDef *)0x40021000U)
#endif

// CR Configuration

#define RCC_CR_MSION                    (0x1U<<0)
#define RCC_CR_MSIRDY                   (0x1U<<1)
#define RCC_CR_MSIPLLEN                 (0x1U<<2)
#define RCC_CR_MSIRGSEL                 (0x1U<<3)
#define RCC_CR_MSIRANGE                 (0xFU<<4)
#define RCC_CR_MSIRANGE_0               (0x1U<<4)
#define RCC_CR_HSION                    (0x1U<<8)
#define RCC_CR_HSIKERON                 (0x1U<<9)
#define RCC_CR_HSIRDY                   (0x1U<<10)
#define RCC_CR_HSIASFS                  (0x1U<<11)
#define RCC_CR_HSEON                    (0x1U<<16)
#define RCC_CR_HSERDY                   (0x1U<<17)
#define RCC_CR_HSEBYP                   (0x1U<<18)
#define RCC_CR_CSSON                    (0x1U<<19)
#define RCC_CR_PLLON                    (0x1U<<24)
#define RCC_CR_PLLRDY                   (0x1U<<25)
#define RCC_CR_PLLSAI1ON                (0x1U<<26)
#define RCC_CR_PLLSAI1RDY               (0x1U<<27)
#define RCC_CR_PLLSAI2ON                (0x1U<<28)
#define RCC_CR_PLLSAI2RDY               (0x1U<<29)

// ICSCR Configuration

#define RCC_ICSCR_MSICAL                (0xFFU<<0)
#define RCC_ICSCR_MSICAL_0              (0x1U<<0)
#define RCC_ICSCR_MSITRIM               (0xFFU<<8)
#define RCC_ICSCR_MSITRIM_0             (0x1U<<8)
#define RCC_ICSCR_HSICAL                (0xFFU<<16)
#define RCC_ICSCR_HSICAL_0              (0x1U<<16)
#define RCC_ICSCR_HSITRIM               (0x7FU<<24)
#define RCC_ICSCR_HSITRIM_0             (0x1U<<24)

// CFGR Configuration

#define RCC_CFGR_SW                     (0x3U<<0)
#define RCC_CFGR_SW_0                   (0x1U<<0)
#define RCC_CFGR_SWS                    (0x3U<<2)
#define RCC_CFGR_SWS_0                  (0x1U<<2)
#define RCC_CFGR_HPRE                   (0xFU<<4)
#define RCC_CFGR_HPRE_0                 (0x1U<<4)
#define RCC_CFGR_PPRE1                  (0x7U<<8)
#define RCC_CFGR_PPRE1_0                (0x1U<<8)
#define RCC_CFGR_PPRE2                  (0x7U<<11)
#define RCC_CFGR_PPRE2_0                (0x1U<<11)
#define RCC_CFGR_STOPWUCK               (0x1U<<15)
#define RCC_CFGR_MCOSEL                 (0x7U<<24)
#define RCC_CFGR_MCOSEL_0               (0x1U<<24)
#define RCC_CFGR_MCOPRE                 (0x7U<<28)
#define RCC_CFGR_MCOPRE_0               (0x1U<<28)

// PLLCFGR Configuration

#define RCC_PLLCFGR_PLLSRC              (0x3U<<0)
#define RCC_PLLCFGR_PLLSRC_0            (0x1U<<0)
#define RCC_PLLCFGR_PLLM                (0xFU<<4)
#define RCC_PLLCFGR_PLLM_0              (0x1U<<4)
#define RCC_PLLCFGR_PLLN                (0x7FU<<8)
#define RCC_PLLCFGR_PLLN_0              (0x1U<<8)
#define RCC_PLLCFGR_PLLPEN              (0x1U<<16)
#define RCC_PLLCFGR_PLLP                (0x1U<<17)
#define RCC_PLLCFGR_PLLQEN              (0x1U<<20)
#define RCC_PLLCFGR_PLLQ                (0x3U<<21)
#define RCC_PLLCFGR_PLLQ_0              (0x1U<<21)
#define RCC_PLLCFGR_PLLREN              (0x1U<<24)
#define RCC_PLLCFGR_PLLR                (0x3U<<25)
#define RCC_PLLCFGR_PLLR_0              (0x1U<<25)
#define RCC_PLLCFGR_PLLPDIV             (0x1FU<<27)
#define RCC_PLLCFGR_PLLPDIV_0           (0x1U<<27)

// PLLSAI1CFGR Configuration

#define RCC_PLLSAI1CFGR_PLLSAI1M        (0xFU<<4)
#define RCC_PLLSAI1CFGR_PLLSAI1M_0      (0x1U<<4)
#define RCC_PLLSAI1CFGR_PLLSAI1N        (0x7FU<<8)
#define RCC_PLLSAI1CFGR_PLLSAI1N_0      (0x1U<<8)
#define RCC_PLLSAI1CFGR_PLLSAI1PEN      (0x1U<<16)
#define RCC_PLLSAI1CFGR_PLLSAI1P        (0x1U<<17)
#define RCC_PLLSAI1CFGR_PLLSAI1QEN      (0x1U<<20)
#define RCC_PLLSAI1CFGR_PLLSAI1Q        (0x3U<<21)
#define RCC_PLLSAI1CFGR_PLLSAI1Q_0      (0x1U<<21)
#define RCC_PLLSAI1CFGR_PLLSAI1REN      (0x1U<<24)
#define RCC_PLLSAI1CFGR_PLLSAI1R        (0x3U<<25)
#define RCC_PLLSAI1CFGR_PLLSAI1R_0      (0x1U<<25)
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV     (0x1FU<<27)
#define RCC_PLLSAI1CFGR_PLLSAI1PDIV_0   (0x1U<<27)

// PLLSAI2CFGR Configuration

#define RCC_PLLSAI2CFGR_PLLSAI2M        (0xFU<<4)
#define RCC_PLLSAI2CFGR_PLLSAI2M_0      (0x1U<<4)
#define RCC_PLLSAI2CFGR_PLLSAI2N        (0x7FU<<8)
#define RCC_PLLSAI2CFGR_PLLSAI2N_0      (0x1U<<8)
#define RCC_PLLSAI2CFGR_PLLSAI2PEN      (0x1U<<16)
#define RCC_PLLSAI2CFGR_PLLSAI2P        (0x1U<<17)
#define RCC_PLLSAI2CFGR_PLLSAI2QEN      (0x1U<<20)
#define RCC_PLLSAI2CFGR_PLLSAI2Q        (0x3U<<21)
#define RCC_PLLSAI2CFGR_PLLSAI2Q_0      (0x1U<<21)
#define RCC_PLLSAI2CFGR_PLLSAI2REN      (0x1U<<24)
#define RCC_PLLSAI2CFGR_PLLSAI2R        (0x3U<<25)
#define RCC_PLLSAI2CFGR_PLLSAI2R_0      (0x1U<<25)
#define RCC_PLLSAI2CFGR_PLLSAI2PDIV     (0x1FU<<27)
#define RCC_PLLSAI2CFGR_PLLSAI2PDIV_0   (0x1U<<27)

// CIER Configuration

#define RCC_CIER_HSI48RDYIE             (0x1U<<10)
#define RCC_CIER_LSECSSIE               (0x1U<<9)
#define RCC_CIER_PLLSAI2RDYIE           (0x1U<<7)
#define RCC_CIER_PLLSAI1RDYIE           (0x1U<<6)
#define RCC_CIER_PLLRDYIE               (0x1U<<5)
#define RCC_CIER_HSERDYIE               (0x1U<<4)
#define RCC_CIER_HSIRDYIE               (0x1U<<3)
#define RCC_CIER_MSIRDYIE               (0x1U<<2)
#define RCC_CIER_LSERDYIE               (0x1U<<1)
#define RCC_CIER_LSIRDYIE               (0x1U<<0)

// CIFR Configuration

#define RCC_CIFR_HSI48RDYF              (0x1U<<10)
#define RCC_CIFR_LSECSSF                (0x1U<<9)
#define RCC_CIFR_CSSF                   (0x1U<<8)
#define RCC_CIFR_PLLSAI2RDYF            (0x1U<<7)
#define RCC_CIFR_PLLSAI1RDYF            (0x1U<<6)
#define RCC_CIFR_PLLRDYF                (0x1U<<5)
#define RCC_CIFR_HSERDYF                (0x1U<<4)
#define RCC_CIFR_HSIRDYF                (0x1U<<3)
#define RCC_CIFR_MSIRDYF                (0x1U<<2)
#define RCC_CIFR_LSERDYF                (0x1U<<1)
#define RCC_CIFR_LSIRDYF                (0x1U<<0)

// CICR Configuration

#define RCC_CICR_HSI48RDYC              (0x1U<<10)
#define RCC_CICR_LSECSSC                (0x1U<<9)
#define RCC_CICR_CSSC                   (0x1U<<8)
#define RCC_CICR_PLLSAI2RDYC            (0x1U<<7)
#define RCC_CICR_PLLSAI1RDYC            (0x1U<<6)
#define RCC_CICR_PLLRDYC                (0x1U<<5)
#define RCC_CICR_HSERDYC                (0x1U<<4)
#define RCC_CICR_HSIRDYC                (0x1U<<3)
#define RCC_CICR_MSIRDYC                (0x1U<<2)
#define RCC_CICR_LSERDYC                (0x1U<<1)
#define RCC_CICR_LSIRDYC                (0x1U<<0)

// AHB1RSTR Configuration

#define RCC_AHB1RSTR_GFXMMURST          (0x1U<<18)
#define RCC_AHB1RSTR_DMA2DRST           (0x1U<<17)
#define RCC_AHB1RSTR_TSCRST             (0x1U<<16)
#define RCC_AHB1RSTR_CRCRST             (0x1U<<12)
#define RCC_AHB1RSTR_FLASHRST           (0x1U<<8)
#define RCC_AHB1RSTR_DMAMUX1RST         (0x1U<<2)
#define RCC_AHB1RSTR_DMA2RST            (0x1U<<1)
#define RCC_AHB1RSTR_DMA1RST            (0x1U<<0)

// AHB2RSTR Configuration

#define RCC_AHB2RSTR_SDMMC1RST          (0x1U<<22)
#define RCC_AHB2RSTR_OSPIMRST           (0x1U<<20)
#define RCC_AHB2RSTR_RNGRST             (0x1U<<18)
#define RCC_AHB2RSTR_HASHRST            (0x1U<<17)
#define RCC_AHB2RSTR_AESRST             (0x1U<<16)
#define RCC_AHB2RSTR_DCMIRST            (0x1U<<14)
#define RCC_AHB2RSTR_ADCRST             (0x1U<<13)
#define RCC_AHB2RSTR_OTGFSRST           (0x1U<<12)
#define RCC_AHB2RSTR_GPIOIRST           (0x1U<<8)
#define RCC_AHB2RSTR_GPIOHRST           (0x1U<<7)
#define RCC_AHB2RSTR_GPIOGRST           (0x1U<<6)
#define RCC_AHB2RSTR_GPIOFRST           (0x1U<<5)
#define RCC_AHB2RSTR_GPIOERST           (0x1U<<4)
#define RCC_AHB2RSTR_GPIODRST           (0x1U<<3)
#define RCC_AHB2RSTR_GPIOCRST           (0x1U<<2)
#define RCC_AHB2RSTR_GPIOBRST           (0x1U<<1)
#define RCC_AHB2RSTR_GPIOARST           (0x1U<<0)

// AHB3RSTR Configuration

#define RCC_AHB3RSTR_OSPI2RST           (0x1U<<9)
#define RCC_AHB3RSTR_FMCRST             (0x1U<<0)

// APB1RSTR1 Configuration

#define RCC_APB1RSTR1_TIM2RST           (0x1U<<0)
#define RCC_APB1RSTR1_TIM3RST           (0x1U<<1)
#define RCC_APB1RSTR1_TIM4RST           (0x1U<<2)
#define RCC_APB1RSTR1_TIM5RST           (0x1U<<3)
#define RCC_APB1RSTR1_TIM6RST           (0x1U<<4)
#define RCC_APB1RSTR1_TIM7RST           (0x1U<<5)
#define RCC_APB1RSTR1_SPI2RST           (0x1U<<14)
#define RCC_APB1RSTR1_SPI3RST           (0x1U<<15)
#define RCC_APB1RSTR1_USART2RST         (0x1U<<17)
#define RCC_APB1RSTR1_USART3RST         (0x1U<<18)
#define RCC_APB1RSTR1_UART4RST          (0x1U<<19)
#define RCC_APB1RSTR1_UART5RST          (0x1U<<20)
#define RCC_APB1RSTR1_I2C1RST           (0x1U<<21)
#define RCC_APB1RSTR1_I2C2RST           (0x1U<<22)
#define RCC_APB1RSTR1_I2C3RST           (0x1U<<23)
#define RCC_APB1RSTR1_CRSRST            (0x1U<<24)
#define RCC_APB1RSTR1_CAN1RST           (0x1U<<25)
#define RCC_APB1RSTR1_PWRRST            (0x1U<<28)
#define RCC_APB1RSTR1_DAC1RST           (0x1U<<29)
#define RCC_APB1RSTR1_OPAMPRST          (0x1U<<30)
#define RCC_APB1RSTR1_LPTIM1RST         (0x1U<<31)

// APB1RSTR2 Configuration

#define RCC_APB1RSTR2_LPTIM2RST         (0x1U<<5)
#define RCC_APB1RSTR2_I2C4RST           (0x1U<<1)
#define RCC_APB1RSTR2_LPUART1RST        (0x1U<<0)

// APB2RSTR Configuration

#define RCC_APB2RSTR_DSIRST             (0x1U<<27)
#define RCC_APB2RSTR_LTDCRST            (0x1U<<26)
#define RCC_APB2RSTR_DFSDM1RST          (0x1U<<24)
#define RCC_APB2RSTR_SAI2RST            (0x1U<<22)
#define RCC_APB2RSTR_SAI1RST            (0x1U<<21)
#define RCC_APB2RSTR_TIM17RST           (0x1U<<18)
#define RCC_APB2RSTR_TIM16RST           (0x1U<<17)
#define RCC_APB2RSTR_TIM15RST           (0x1U<<16)
#define RCC_APB2RSTR_USART1RST          (0x1U<<14)
#define RCC_APB2RSTR_TIM8RST            (0x1U<<13)
#define RCC_APB2RSTR_SPI1RST            (0x1U<<12)
#define RCC_APB2RSTR_TIM1RST            (0x1U<<11)
#define RCC_APB2RSTR_SYSCFGRST          (0x1U<<0)

// AHB1ENR Configuration

#define RCC_AHB1ENR_GFXMMUEN            (0x1U<<18)
#define RCC_AHB1ENR_DMA2DEN             (0x1U<<17)
#define RCC_AHB1ENR_TSCEN               (0x1U<<16)
#define RCC_AHB1ENR_CRCEN               (0x1U<<12)
#define RCC_AHB1ENR_FLASHEN             (0x1U<<8)
#define RCC_AHB1ENR_DMAMUX1EN           (0x1U<<2)
#define RCC_AHB1ENR_DMA2EN              (0x1U<<1)
#define RCC_AHB1ENR_DMA1EN              (0x1U<<0)

// AHB2ENR Configuration

#define RCC_AHB2ENR_SDMMC1EN            (0x1U<<22)
#define RCC_AHB2ENR_OSPIMEN             (0x1U<<20)
#define RCC_AHB2ENR_RNGEN               (0x1U<<18)
#define RCC_AHB2ENR_HASHEN              (0x1U<<17)
#define RCC_AHB2ENR_AESEN               (0x1U<<16)
#define RCC_AHB2ENR_DCMIEN              (0x1U<<14)
#define RCC_AHB2ENR_ADCEN               (0x1U<<13)
#define RCC_AHB2ENR_OTGFSEN             (0x1U<<12)
#define RCC_AHB2ENR_GPIOIEN             (0x1U<<8)
#define RCC_AHB2ENR_GPIOHEN             (0x1U<<7)
#define RCC_AHB2ENR_GPIOGEN             (0x1U<<6)
#define RCC_AHB2ENR_GPIOFEN             (0x1U<<5)
#define RCC_AHB2ENR_GPIOEEN             (0x1U<<4)
#define RCC_AHB2ENR_GPIODEN             (0x1U<<3)
#define RCC_AHB2ENR_GPIOCEN             (0x1U<<2)
#define RCC_AHB2ENR_GPIOBEN             (0x1U<<1)
#define RCC_AHB2ENR_GPIOAEN             (0x1U<<0)

// AHB3ENR Configuration

#define RCC_AHB3ENR_OSPI2EN             (0x1U<<9)
#define RCC_AHB3ENR_FMCEN               (0x1U<<0)

// APB1ENR1 Configuration

#define RCC_APB1ENR1_LPTIM1EN           (0x1U<<31)
#define RCC_APB1ENR1_OPAMPEN            (0x1U<<30)
#define RCC_APB1ENR1_DAC1EN             (0x1U<<29)
#define RCC_APB1ENR1_PWREN              (0x1U<<28)
#define RCC_APB1ENR1_CAN1EN             (0x1U<<25)
#define RCC_APB1ENR1_CRSEN              (0x1U<<24)
#define RCC_APB1ENR1_I2C3EN             (0x1U<<23)
#define RCC_APB1ENR1_I2C2EN             (0x1U<<22)
#define RCC_APB1ENR1_I2C1EN             (0x1U<<21)
#define RCC_APB1ENR1_UART5EN            (0x1U<<20)
#define RCC_APB1ENR1_UART4EN            (0x1U<<19)
#define RCC_APB1ENR1_USART3EN           (0x1U<<18)
#define RCC_APB1ENR1_USART2EN           (0x1U<<17)
#define RCC_APB1ENR1_SP3EN              (0x1U<<15)
#define RCC_APB1ENR1_SPI2EN             (0x1U<<14)
#define RCC_APB1ENR1_WWDGEN             (0x1U<<11)
#define RCC_APB1ENR1_RTCAPBEN           (0x1U<<10)
#define RCC_APB1ENR1_TIM7EN             (0x1U<<5)
#define RCC_APB1ENR1_TIM6EN             (0x1U<<4)
#define RCC_APB1ENR1_TIM5EN             (0x1U<<3)
#define RCC_APB1ENR1_TIM4EN             (0x1U<<2)
#define RCC_APB1ENR1_TIM3EN             (0x1U<<1)
#define RCC_APB1ENR1_TIM2EN             (0x1U<<0)

// APB1ENR2 Configuration

#define RCC_APB1ENR2_LPTIM2EN           (0x1U<<5)
#define RCC_APB1ENR2_I2C4EN             (0x1U<<1)
#define RCC_APB1ENR2_LPUART1EN          (0x1U<<0)

// APB2ENR Configuration

#define RCC_APB2ENR_DSIEN               (0x1U<<27)
#define RCC_APB2ENR_LTDCEN              (0x1U<<26)
#define RCC_APB2ENR_DFSDM1EN            (0x1U<<24)
#define RCC_APB2ENR_SAI2EN              (0x1U<<22)
#define RCC_APB2ENR_SAI1EN              (0x1U<<21)
#define RCC_APB2ENR_TIM17EN             (0x1U<<18)
#define RCC_APB2ENR_TIM16EN             (0x1U<<17)
#define RCC_APB2ENR_TIM15EN             (0x1U<<16)
#define RCC_APB2ENR_USART1EN            (0x1U<<14)
#define RCC_APB2ENR_TIM8EN              (0x1U<<13)
#define RCC_APB2ENR_SPI1EN              (0x1U<<12)
#define RCC_APB2ENR_TIM1EN              (0x1U<<11)
#define RCC_APB2ENR_FWEN                (0x1U<<7)
#define RCC_APB2ENR_SYSCFGEN            (0x1U<<0)

// AHB1SMENR Configuration

#define RCC_AHB1SMENR_GFXMMUSMEN        (0x1U<<18)
#define RCC_AHB1SMENR_DMA2DSMEN         (0x1U<<17)
#define RCC_AHB1SMENR_TSCSMEN           (0x1U<<16)
#define RCC_AHB1SMENR_CRCSMEN           (0x1U<<12)
#define RCC_AHB1SMENR_SRAM1SMEN         (0x1U<<9)
#define RCC_AHB1SMENR_FLASHSMEN         (0x1U<<8)
#define RCC_AHB1SMENR_DMAMUX1SMEN       (0x1U<<2)
#define RCC_AHB1SMENR_DMA2SMEN          (0x1U<<1)
#define RCC_AHB1SMENR_DMA1SMEN          (0x1U<<0)

// AHB2SMENR Configuration

#define RCC_AHB2SMENR_SDMMC1SMEN        (0x1U<<22)
#define RCC_AHB2SMENR_OSPIMSMEN         (0x1U<<20)
#define RCC_AHB2SMENR_RNGSMEN           (0x1U<<18)
#define RCC_AHB2SMENR_HASHSMEN          (0x1U<<17)
#define RCC_AHB2SMENR_AESSMEN           (0x1U<<16)
#define RCC_AHB2SMENR_DCMISMEN          (0x1U<<14)
#define RCC_AHB2SMENR_ADCFSSMEN         (0x1U<<13)
#define RCC_AHB2SMENR_OTGFSSMEN         (0x1U<<12)
#define RCC_AHB2SMENR_SRAM3SMEN         (0x1U<<10)
#define RCC_AHB2SMENR_SRAM2SMEN         (0x1U<<9)
#define RCC_AHB2SMENR_GPIOISMEN         (0x1U<<8)
#define RCC_AHB2SMENR_GPIOHSMEN         (0x1U<<7)
#define RCC_AHB2SMENR_GPIOGSMEN         (0x1U<<6)
#define RCC_AHB2SMENR_GPIOFSMEN         (0x1U<<5)
#define RCC_AHB2SMENR_GPIOESMEN         (0x1U<<4)
#define RCC_AHB2SMENR_GPIODSMEN         (0x1U<<3)
#define RCC_AHB2SMENR_GPIOCSMEN         (0x1U<<2)
#define RCC_AHB2SMENR_GPIOBSMEN         (0x1U<<1)
#define RCC_AHB2SMENR_GPIOASMEN         (0x1U<<0)

// AHB3SMENR Configuration

#define RCC_AHB3SMENR_OCTOSPI2          (0x1U<<9)
#define RCC_AHB3SMENR_FMCSMEN           (0x1U<<0)

// APB1SMENR1 Configuration

#define RCC_APB1SMENR1_LPTIM1SMEN       (0x1U<<31)
#define RCC_APB1SMENR1_OPAMPSMEN        (0x1U<<30)
#define RCC_APB1SMENR1_DAC1SMEN         (0x1U<<29)
#define RCC_APB1SMENR1_PWRSMEN          (0x1U<<28)
#define RCC_APB1SMENR1_CAN1SMEN         (0x1U<<25)
#define RCC_APB1SMENR1_CRSSMEN          (0x1U<<24)
#define RCC_APB1SMENR1_I2C3SMEN         (0x1U<<23)
#define RCC_APB1SMENR1_I2C2SMEN         (0x1U<<22)
#define RCC_APB1SMENR1_I2C1SMEN         (0x1U<<21)
#define RCC_APB1SMENR1_UART5SMEN        (0x1U<<20)
#define RCC_APB1SMENR1_UART4SMEN        (0x1U<<19)
#define RCC_APB1SMENR1_USART3SMEN       (0x1U<<18)
#define RCC_APB1SMENR1_USART2SMEN       (0x1U<<17)
#define RCC_APB1SMENR1_SP3SMEN          (0x1U<<15)
#define RCC_APB1SMENR1_SPI2SMEN         (0x1U<<14)
#define RCC_APB1SMENR1_WWDGSMEN         (0x1U<<11)
#define RCC_APB1SMENR1_RTCAPBSMEN       (0x1U<<10)
#define RCC_APB1SMENR1_TIM7SMEN         (0x1U<<5)
#define RCC_APB1SMENR1_TIM6SMEN         (0x1U<<4)
#define RCC_APB1SMENR1_TIM5SMEN         (0x1U<<3)
#define RCC_APB1SMENR1_TIM4SMEN         (0x1U<<2)
#define RCC_APB1SMENR1_TIM3SMEN         (0x1U<<1)
#define RCC_APB1SMENR1_TIM2SMEN         (0x1U<<0)

// APB1SMENR2 Configuration

#define RCC_APB1SMENR2_LPTIM2SMEN       (0x1U<<5)
#define RCC_APB1SMENR2_I2C4SMEN         (0x1U<<1)
#define RCC_APB1SMENR2_LPUART1SMEN      (0x1U<<0)

// APB2SMENR Configuration

#define RCC_APB2SMENR_DSISMEN           (0x1U<<27)
#define RCC_APB2SMENR_LTDCSMEN          (0x1U<<26)
#define RCC_APB2SMENR_DFSDM1SMEN        (0x1U<<24)
#define RCC_APB2SMENR_SAI2SMEN          (0x1U<<22)
#define RCC_APB2SMENR_SAI1SMEN          (0x1U<<21)
#define RCC_APB2SMENR_TIM17SMEN         (0x1U<<18)
#define RCC_APB2SMENR_TIM16SMEN         (0x1U<<17)
#define RCC_APB2SMENR_TIM15SMEN         (0x1U<<16)
#define RCC_APB2SMENR_USART1SMEN        (0x1U<<14)
#define RCC_APB2SMENR_TIM8SMEN          (0x1U<<13)
#define RCC_APB2SMENR_SPI1SMEN          (0x1U<<12)
#define RCC_APB2SMENR_TIM1SMEN          (0x1U<<11)
#define RCC_APB2SMENR_SYSCFGSMEN        (0x1U<<0)

// CCIPR Configuration

#define RCC_CCIPR_USART1SEL             (0x3U<<0)
#define RCC_CCIPR_USART1SEL_0           (0x1U<<0)
#define RCC_CCIPR_USART2SEL             (0x3U<<2)
#define RCC_CCIPR_USART2SEL_0           (0x1U<<2)
#define RCC_CCIPR_USART3SEL             (0x3U<<4)
#define RCC_CCIPR_USART3SEL_0           (0x1U<<4)
#define RCC_CCIPR_UART4SEL              (0x3U<<6)
#define RCC_CCIPR_UART4SEL_0            (0x1U<<6)
#define RCC_CCIPR_UART5SEL              (0x3U<<8)
#define RCC_CCIPR_UART5SEL_0            (0x1U<<8)
#define RCC_CCIPR_LPUART1SEL            (0x3U<<10)
#define RCC_CCIPR_LPUART1SEL_0          (0x1U<<10)
#define RCC_CCIPR_I2C1SEL               (0x3U<<12)
#define RCC_CCIPR_I2C1SEL_0             (0x1U<<12)
#define RCC_CCIPR_I2C2SEL               (0x3U<<14)
#define RCC_CCIPR_I2C2SEL_0             (0x1U<<14)
#define RCC_CCIPR_I2C3SEL               (0x3U<<16)
#define RCC_CCIPR_I2C3SEL_0             (0x1U<<16)
#define RCC_CCIPR_LPTIM1SEL             (0x3U<<18)
#define RCC_CCIPR_LPTIM1SEL_0           (0x1U<<18)
#define RCC_CCIPR_LPTIM2SEL             (0x3U<<20)
#define RCC_CCIPR_LPTIM2SEL_0           (0x1U<<20)
#define RCC_CCIPR_SAI1SEL               (0x3U<<22)
#define RCC_CCIPR_SAI1SEL_0             (0x1U<<22)
#define RCC_CCIPR_SAI2SEL               (0x3U<<24)
#define RCC_CCIPR_SAI2SEL_0             (0x1U<<24)
#define RCC_CCIPR_CLK48SEL              (0x3U<<26)
#define RCC_CCIPR_CLK48SEL_0            (0x1U<<26)
#define RCC_CCIPR_ADCSEL                (0x3U<<28)
#define RCC_CCIPR_ADCSEL_0              (0x1U<<28)

// BDCR Configuration

#define RCC_BDCR_LSEON                  (0x1U<<0)
#define RCC_BDCR_LSERDY                 (0x1U<<1)
#define RCC_BDCR_LSEBYP                 (0x1U<<2)
#define RCC_BDCR_LSEDRV                 (0x3U<<3)
#define RCC_BDCR_LSEDRV_0               (0x1U<<3)
#define RCC_BDCR_LSECSSON               (0x1U<<5)
#define RCC_BDCR_LSECSSD                (0x1U<<6)
#define RCC_BDCR_RTCSEL                 (0x3U<<8)
#define RCC_BDCR_RTCSEL_0               (0x1U<<8)
#define RCC_BDCR_RTCEN                  (0x1U<<15)
#define RCC_BDCR_BDRST                  (0x1U<<16)
#define RCC_BDCR_LSCOEN                 (0x1U<<24)
#define RCC_BDCR_LSCOSEL                (0x1U<<25)

// CSR Configuration

#define RCC_CSR_LSION                   (0x1U<<0)
#define RCC_CSR_LSIRDY                  (0x1U<<1)
#define RCC_CSR_MSISRANGE               (0xFU<<8)
#define RCC_CSR_MSISRANGE_0             (0x1U<<8)
#define RCC_CSR_RMVF                    (0x1U<<23)
#define RCC_CSR_FWRSTF                  (0x1U<<24)
#define RCC_CSR_OBLRSTF                 (0x1U<<25)
#define RCC_CSR_PINRSTF                 (0x1U<<26)
#define RCC_CSR_BORRSTF                 (0x1U<<27)
#define RCC_CSR_SFTRSTF                 (0x1U<<28)
#define RCC_CSR_IWDGRSTF                (0x1U<<29)
#define RCC_CSR_WWDGRSTF                (0x1U<<30)
#define RCC_CSR_LPWRSTF                 (0x1U<<31)

// CRRCR Configuration

#define RCC_CRRCR_HSI48CAL              (0x1FFU<<7)
#define RCC_CRRCR_HSI48CAL_0            (0x1U<<7)
#define RCC_CRRCR_HSI48RDY              (0x1U<<1)
#define RCC_CRRCR_HSI48ON               (0x1U<<0)

// CCIPR2 Configuration

#define RCC_CCIPR2_OSPISEL              (0x3U<<20)
#define RCC_CCIPR2_OSPISEL_0            (0x1U<<20)
#define RCC_CCIPR2_PLLSAI2DIVR          (0x3U<<16)
#define RCC_CCIPR2_PLLSAI2DIVR_0        (0x1U<<16)
#define RCC_CCIPR2_SDMMCSEL             (0x1U<<14)
#define RCC_CCIPR2_DSISEL               (0x1U<<12)
#define RCC_CCIPR2_SAI2SEL              (0x7U<<8)
#define RCC_CCIPR2_SAI2SEL_0            (0x1U<<8)
#define RCC_CCIPR2_SAI1SEL              (0x7U<<5)
#define RCC_CCIPR2_SAI1SEL_0            (0x1U<<5)
#define RCC_CCIPR2_ADFSDMSEL            (0x3U<<3)
#define RCC_CCIPR2_ADFSDMSEL_0          (0x1U<<3)
#define RCC_CCIPR2_DFSDMSEL             (0x1U<<2)
#define RCC_CCIPR2_I2C4SEL              (0x3U<<0)
#define RCC_CCIPR2_I2C4SEL_0            (0x1U<<0)
