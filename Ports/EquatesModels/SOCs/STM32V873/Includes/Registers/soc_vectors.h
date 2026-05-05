/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Indirect Exception Vectors for unknown core.
 *           The "reset" exception is not considered. The indirect table
 *           is reserved in the first.c file.
 */

#pragma once

typedef enum IRQn {

// Cortex_M55 Processor Exceptions Numbers

    NonMaskableInt_IRQn     = -14,  // Non Maskable Interrupt
    HardFault_IRQn          = -13,  // Hard Fault Interrupt
    MemoryManagement_IRQn   = -12,  // Memory Management Interrupt
    BusFault_IRQn           = -11,  // Bus Fault Interrupt
    UsageFault_IRQn         = -10,  // Usage Fault Interrupt
    SecureFault_IRQn        = -9,   // Secure Fault
    SVCall_IRQn             = -5,   // SV Call Interrupt
    DebugMonitor_IRQn       = -4,   // Debug Monitor Interrupt
    PendSV_IRQn             = -2,   // Pend SV Interrupt
    SysTick_IRQn            = -1,   // System Tick Interrupt

// SOC Specific Interrupt Numbers

    PVD_IRQn                = 0,    // PVDOUT through the EXTI line
    DTS_IRQn                = 1,    // Digital temperature sensor interrupt
    LOCKUP_IT_IRQn          = 2,    // LOCKUP interrupt
    CACHE_ECC_IRQn          = 3,    // Cache ECC error
    TCM_ECC_IRQn            = 4,    // TCM ECC error
    RAMCFG_IRQn             = 5,    // RAMCFG global interrupt
    FPU_IRQn                = 6,    // Floating point unit interrupt
    RCC_S_IRQn              = 8,    // RCC global secure interrupt
    RTC_S_IRQn              = 9,    // RTC global secure interrupts
    TAMP_IRQn               = 10,   // TAMPER global secure and non -secure interrupts
    NVM_S_IRQn              = 11,   // NVM secure global interrupt
    RIFSC_TAMPER_IRQn       = 12,   // RIF can generate an interrupt when laser attack detected
    IAC_IRQn                = 13,   // illegal access global interrupt
    RCC_IRQn                = 14,   // RCC global non-secure interrupt
    RTC_IRQn                = 15,   // RTC global non-secure interrupts
    NVM_IRQn                = 16,   // NVM global non-secure interrupt
    IWDG_IRQn               = 17,   // IWDG global interrupt
    WWDG_IRQn               = 18,   // WWDG global interrupt
    EXTI0_IRQn              = 19,   // EXTI Line 0 interrupt through the EXTI line
    EXTI1_IRQn              = 20,   // EXTI Line 1 interrupt through the EXTI line
    EXTI2_IRQn              = 21,   // EXTI Line 2 interrupt through the EXTI line
    EXTI3_IRQn              = 22,   // EXTI Line 3 interrupt through the EXTI line
    EXTI4_IRQn              = 23,   // EXTI Line 4 interrupt through the EXTI line
    EXTI5_IRQn              = 24,   // EXTI Line 5 interrupt through the EXTI line
    EXTI6_IRQn              = 25,   // EXTI Line 6 interrupt through the EXTI line
    EXTI7_IRQn              = 26,   // EXTI Line 7 interrupt through the EXTI line
    EXTI8_IRQn              = 27,   // EXTI Line 8 interrupt through the EXTI line
    EXTI9_IRQn              = 28,   // EXTI Line 9 interrupt through the EXTI line
    EXTI10_IRQn             = 29,   // EXTI Line 10 interrupt through the EXTI line
    EXTI11_IRQn             = 30,   // EXTI Line 11 interrupt through the EXTI line
    EXTI12_IRQn             = 31,   // EXTI Line 12 interrupt through the EXTI line
    EXTI13_IRQn             = 32,   // EXTI Line 13 interrupt through the EXTI line
    EXTI14_IRQn             = 33,   // EXTI Line 14 interrupt through the EXTI line
    EXTI15_IRQn             = 34,   // EXTI Line 15 interrupt through the EXTI line
    SAES_IRQn               = 35,   // SAES interrupt
    CRYP_IRQn               = 36,   // CRYP interrupt
    PKA_IRQn                = 37,   // PKA interrupt
    HASH_IRQn               = 38,   // HASH interrupt
    RNG_IRQn                = 39,   // RNG interrupt
    MCE1_IRQn               = 40,   // MCE1 interrupt
    MCE2_IRQn               = 41,   // MCE2 interrupt
    MCE3_IRQn               = 42,   // MCE3 interrupt
    DCMIPP_IRQn             = 44,   // DCMIPP interrupt
    ADC1_IRQn               = 45,   // ADC1 global interrupt
    ADC2_IRQn               = 46,   // ADC2 global interrupt
    ADC3_IRQn               = 47,   // ADC3 global interrupt
    DAC_IRQn                = 48,   // DAC global interrupt
    LCD_S_IRQn              = 49,   // LCD global secure interrupt
    LCD_ERR_S_IRQn          = 50,   // LCD error secure interrupt
    LCD_IRQn                = 51,   // LCD global non-secure interrupt
    LCD_ERR_IRQn            = 52,   // LCD error non-secure interrupt
    DMA2D_IRQn              = 53,   // DMA2D interrupt
    JPEG_IRQn               = 54,   // JPEG interrupt
    GFXMMU_S_IRQn           = 55,   // GFXMMU secure interrupt
    GFXMMU_IRQn             = 56,   // GFXMMU non-secure interrupt
    GFXTIM_IRQn             = 57,   // GFXTIM interrupt
    HPDMA1_CH0_IRQn         = 61,   // HPDMA1 channel 0 global interrupt
    HPDMA1_CH1_IRQn         = 62,   // HPDMA1 channel 1 global interrupt
    HPDMA1_CH2_IRQn         = 63,   // HPDMA1 channel 2 global interrupt
    HPDMA1_CH3_IRQn         = 64,   // HPDMA1 channel 3 global interrupt
    HPDMA1_CH4_IRQn         = 65,   // HPDMA1 channel 4 global interrupt
    HPDMA1_CH5_IRQn         = 66,   // HPDMA1 channel 5 global interrupt
    HPDMA1_CH6_IRQn         = 67,   // HPDMA1 channel 6 global interrupt
    HPDMA1_CH7_IRQn         = 68,   // HPDMA1 channel 7 global interrupt
    HPDMA1_CH8_IRQn         = 69,   // HPDMA1 channel 8 global interrupt
    HPDMA1_CH9_IRQn         = 70,   // HPDMA1 channel 9 global interrupt
    HPDMA1_CH10_IRQn        = 71,   // HPDMA1 channel 10 global interrupt
    HPDMA1_CH11_IRQn        = 72,   // HPDMA1 channel 11 global interrupt
    HPDMA1_CH12_IRQn        = 73,   // HPDMA1 channel 12 global interrupt
    HPDMA1_CH13_IRQn        = 74,   // HPDMA1 channel 13 global interrupt
    HPDMA1_CH14_IRQn        = 75,   // HPDMA1 channel 14 global interrupt
    HPDMA1_CH15_IRQn        = 76,   // HPDMA1 channel 15 global interrupt
    GPDMA1_CH0_IRQn         = 77,   // GPDMA1 channel 0 global interrupt
    GPDMA1_CH1_IRQn         = 78,   // GPDMA1 channel 1 global interrupt
    GPDMA1_CH2_IRQn         = 79,   // GPDMA1 channel 2 global interrupt
    GPDMA1_CH3_IRQn         = 80,   // GPDMA1 channel 3 global interrupt
    GPDMA1_CH4_IRQn         = 81,   // GPDMA1 channel 4 global interrupt
    GPDMA1_CH5_IRQn         = 82,   // GPDMA1 channel 5 global interrupt
    GPDMA1_CH6_IRQn         = 83,   // GPDMA1 channel 6 global interrupt
    GPDMA1_CH7_IRQn         = 84,   // GPDMA1 channel 7 global interrupt
    GPDMA1_CH8_IRQn         = 85,   // GPDMA1 channel 8 global interrupt
    GPDMA1_CH9_IRQn         = 86,   // GPDMA1 channel 9 global interrupt
    GPDMA1_CH10_IRQn        = 87,   // GPDMA1 channel 10 global interrupt
    GPDMA1_CH11_IRQn        = 88,   // GPDMA1 channel 11 global interrupt
    GPDMA2_CH0_IRQn         = 89,   // GPDMA2 channel 0 global interrupt
    GPDMA2_CH1_IRQn         = 90,   // GPDMA2 channel 1 global interrupt
    GPDMA2_CH2_IRQn         = 91,   // GPDMA2 channel 2 global interrupt
    GPDMA2_CH3_IRQn         = 92,   // GPDMA2 channel 3 global interrupt
    GPDMA2_CH4_IRQn         = 93,   // GPDMA2 channel 4 global interrupt
    GPDMA2_CH5_IRQn         = 94,   // GPDMA2 channel 5 global interrupt
    GPDMA2_CH6_IRQn         = 95,   // GPDMA2 channel 6 global interrupt
    GPDMA2_CH7_IRQn         = 96,   // GPDMA2 channel 7 global interrupt
    GPDMA2_CH8_IRQn         = 97,   // GPDMA2 channel 8 global interrupt
    GPDMA2_CH9_IRQn         = 98,   // GPDMA2 channel 9 global interrupt
    GPDMA2_CH10_IRQn        = 99,   // GPDMA2 channel 10 global interrupt
    GPDMA2_CH11_IRQn        = 100,  // GPDMA2 channel 11 global interrupt
    I2C1_EV_IRQn            = 101,  // I2C1 event interrupt
    I2C1_ER_IRQn            = 102,  // I2C1 error interrupt
    I2C2_EV_IRQn            = 103,  // I2C2 event interrupt
    I2C2_ER_IRQn            = 104,  // I2C2 error interrupt
    I2C3_EV_IRQn            = 105,  // I2C3 event interrupt
    I2C3_ER_IRQn            = 106,  // I2C3 error interrupt
    I3C1_EV_IRQn            = 107,  // I3C1 event interrupt
    I3C1_ER_IRQn            = 108,  // I3C1 error interrupt
    I3C2_EV_IRQn            = 109,  // I3C2 event interrupt
    I3C2_ER_IRQn            = 110,  // I3C2 error interrupt
    TIM1_BRK_IRQn           = 111,  // TIM1 Break interrupt
    TIM1_UP_IRQn            = 112,  // TIM1 Update interrupt (tim_upd_it)
    TIM1_TRG_COM_IRQn       = 113,  // TIM1 Trigger and Commutation interrupts
    TIM1_CC_IRQn            = 114,  // TIM1 Capture Compare interrupt
    TIM2_IRQn               = 115,  // TIM2 global interrupt
    TIM3_IRQn               = 116,  // TIM3 global interrupt
    TIM4_IRQn               = 117,  // TIM4 global interrupt
    TIM5_IRQn               = 118,  // TIM5 global interrupt
    TIM6_IRQn               = 119,  // TIM6 global interrupt
    TIM7_IRQn               = 120,  // TIM7 global interrupt
    TIM8_BRK_IRQn           = 121,  // TIM8 Break interrupt
    TIM8_UP_IRQn            = 122,  // TIM8 Update interrupt (tim_upd_it)
    TIM8_TRG_COM_IRQn       = 123,  // TIM8 Trigger and Commutation interrupts
    TIM8_CC_IRQn            = 124,  // TIM8 Capture Compare interrupt
    TIM9_IRQn               = 125,  // TIM9 global interrupt
    TIM10_IRQn              = 126,  // TIM10 global interrupt
    TIM12_IRQn              = 128,  // TIM12 global interrupt
    TIM13_IRQn              = 129,  // TIM13 global interrupt
    TIM14_IRQn              = 130,  // TIM14 global interrupt
    TIM15_IRQn              = 131,  // TIM15 global interrupt
    TIM16_IRQn              = 132,  // TIM16 global interrupt
    TIM17_IRQn              = 133,  // TIM17 global interrupt
    TIM20_BRK_IRQn          = 134,  // TIM20 Break interrupt
    TIM20_UP_IRQn           = 135,  // TIM20 Update interrupt (tim_upd_it)
    TIM20_TRG_COM_IRQn      = 136,  // TIM20 Trigger and Commutation interrupts
    TIM20_CC_IRQn           = 137,  // TIM20 Capture Compare interrupt
    LPTIM1_IRQn             = 138,  // LPTIM1 global interrupt
    LPTIM2_IRQn             = 139,  // LPTIM2 global interrupt
    LPTIM3_IRQn             = 140,  // LPTIM3 global interrupt
    LPTIM4_IRQn             = 141,  // LPTIM4 global interrupt
    LPTIM5_IRQn             = 142,  // LPTIM5 global interrupt
    HRTIM1_M_IRQn           = 143,  // MHRTIM1 master timer interrupt
    HRTIM1_TIMA_IRQn        = 144,  // MHRTIM1 TIMA interrupt
    HRTIM1_TIMB_IRQn        = 145,  // MHRTIM1 TIMB interrupt
    HRTIM1_TIMC_IRQn        = 146,  // MHRTIM1 TIMC interrupt
    HRTIM1_TIMD_IRQn        = 147,  // MHRTIM1 TIMD interrupt
    HRTIM1_TIME_IRQn        = 148,  // MHRTIM1 TIME interrupt
    HRTIM1_TIMF_IRQn        = 149,  // MHRTIM1 TIMF interrupt
    HRTIM1_FLT_IRQn         = 150,  // MHRTIM1 fault interrupt
    ADF1_FLT0_IRQn          = 151,  // ADF1 interrupt
    MDF1_FLT0_IRQn          = 152,  // MDF1 filter 0 global interrupt0x0000
    MDF1_FLT1_IRQn          = 153,  // MDF1 filter 1 global interrupt0x0000
    MDF1_FLT2_IRQn          = 154,  // MDF1 filter 2 global interrupt0x0000
    MDF1_FLT3_IRQn          = 155,  // MDF1 filter 3 global interrupt0x0000
    MDF1_FLT4_IRQn          = 156,  // MDF1 filter 4 global interrupt0x0000
    MDF1_FLT5_IRQn          = 157,  // MDF1 filter 5 global interrupt0x0000
    SAI1_A_IRQn             = 158,  // SAI1_A interrupt
    SAI1_B_IRQn             = 159,  // SAI1_B interrupt
    SAI2_A_IRQn             = 160,  // SAI2_A interrupt
    SAI2_B_IRQn             = 161,  // SAI2_B interrupt
    SPDIFRX1_IRQn           = 162,  // SPDIFRX interrupt
    SPI1_IRQn               = 163,  // SPI1  interrupt
    SPI2_IRQn               = 164,  // SPI2  interrupt
    SPI3_IRQn               = 165,  // SPI3 interrupt
    SPI4_IRQn               = 166,  // SPI4 interrupt
    SPI5_IRQn               = 167,  // SPI5 interrupt
    SPI6_IRQn               = 168,  // SPI6 interrupt
    USART1_IRQn             = 169,  // USART1 interrupt
    USART2_IRQn             = 170,  // USART2 interrupt
    USART3_IRQn             = 171,  // USART3 global interrupt
    UART4_IRQn              = 172,  // UART4 global interrupt
    UART5_IRQn              = 173,  // UART5 global interrupt
    USART6_IRQn             = 174,  // USART6 global interrupt
    UART7_IRQn              = 175,  // UART7 global interrupt
    UART8_IRQn              = 176,  // UART8 global interrupt
    UART9_IRQn              = 177,  // UART9 global interrupt
    USART10_IRQn            = 178,  // USART10 global interrupt
    LPUART1_IRQn            = 179,  // LPUART1 interrupt
    CEC_IRQn                = 180,  // CEC interrupt
    XSPI1_IRQn              = 181,  // XSPI1 interrupt
    XSPI2_IRQn              = 182,  // XSPI2 interrupt
    FMC_IRQn                = 183,  // FMC interrupt
    SDMMC1_IRQn             = 184,  // SDMMC1 interrupt
    SDMMC2_IRQn             = 185,  // SDMMC2 interrupt
    UCPD1_IRQn              = 186,  // UCPD1 interrupt
    OTG1_IRQn               = 188,  // OTG HS interrupt
    OTG_FS_IRQn             = 189,  // OTG FS interrupt
    ETH1_IRQn               = 190,  // ETH1 interrupt
    FDCAN1_IT0_IRQn         = 192,  // FDCAN1 interrupt 0
    FDCAN1_IT1_IRQn         = 193,  // FDCAN1 interrupt 1
    FDCAN2_IT0_IRQn         = 194,  // FDCAN2 interrupt 0
    FDCAN2_IT1_IRQn         = 195,  // FDCAN2 interrupt 1
    FDCAN3_IT0_IRQn         = 196,  // FDCAN3 interrupt 0
    FDCAN3_IT1_IRQn         = 197,  // FDCAN3 interrupt 1
    FDCAN_CU_IRQn           = 198,  // FDCAN clock calibration unit interrupt
    MDIOS_IRQn              = 199,  // MDIOS interrupt
    PSSI_IRQn               = 200,  // PSSI interrupt
    WKUP_IRQn               = 201,  // WKUP interrupt
    LSECSS_IRQn             = 202,  // LSE CSS interrupt
    CORDIC_IRQn             = 203,  // CORDIC interrupt
    FMAC_IRQn               = 204,  // FMAC interrupt
    HSEM_S_IRQn             = 205,  // HSEM global secure interrupt
    HSEM__IRQn              = 206,  // HSEM global non-secure interrupt
    CTI_IT0_IRQn            = 207,  // CTI_IT0 interrupt
    CTI_IT1_IRQn            = 208,  // CTI_IT1 interrupt
    CRS_IRQn                = 209,  // Clock recovery system global interrupt
    SBS_S_IRQn              = 210,  // SBS (bridge errors) secure interrupt
    SBS_IRQn                = 211,  // SBS (bridge errors) nonsecure interrupt
} IRQn_Type;

#define KNB_EXCEPTIONS      14U
#define KNB_INTERRUPTIONS   212U

// For the core 0
// --------------

// Cortex_M55 Processor Exceptions Numbers

#define NonMaskableInt_C0_IRQn      NonMaskableInt_IRQn
#define HardFault_C0_IRQn           HardFault_IRQn
#define MemoryManagement_C0_IRQn    MemoryManagement_IRQn
#define BusFault_C0_IRQn            BusFault_IRQn
#define UsageFault_C0_IRQn          UsageFault_IRQn
#define SecureFault_C0_IRQn         SecureFault_IRQn
#define SVCall_C0_IRQn              SVCall_IRQn
#define DebugMonitor_C0_IRQn        DebugMonitor_IRQn
#define PendSV_C0_IRQn              PendSV_IRQn
#define SysTick_C0_IRQn             SysTick_IRQn

// SOC Specific Interrupt Numbers

#define PVD_C0_IRQn                 PVD_IRQn
#define DTS_C0_IRQn                 DTS_IRQn
#define LOCKUP_IT_C0_IRQn           LOCKUP_IT_IRQn
#define CACHE_ECC_C0_IRQn           CACHE_ECC_IRQn
#define TCM_ECC_C0_IRQn             TCM_ECC_IRQn
#define RAMCFG_C0_IRQn              RAMCFG_IRQn
#define FPU_C0_IRQn                 FPU_IRQn
#define RCC_S_C0_IRQn               RCC_S_IRQn
#define RTC_S_C0_IRQn               RTC_S_IRQn
#define TAMP_C0_IRQn                TAMP_IRQn
#define NVM_S_C0_IRQn               NVM_S_IRQn
#define RIFSC_TAMPER_C0_IRQn        RIFSC_TAMPER_IRQn
#define IAC_C0_IRQn                 IAC_IRQn
#define RCC_C0_IRQn                 RCC_IRQn
#define RTC_C0_IRQn                 RTC_IRQn
#define NVM_C0_IRQn                 NVM_IRQn
#define IWDG_C0_IRQn                IWDG_IRQn
#define WWDG_C0_IRQn                WWDG_IRQn
#define EXTI0_C0_IRQn               EXTI0_IRQn
#define EXTI1_C0_IRQn               EXTI1_IRQn
#define EXTI2_C0_IRQn               EXTI2_IRQn
#define EXTI3_C0_IRQn               EXTI3_IRQn
#define EXTI4_C0_IRQn               EXTI4_IRQn
#define EXTI5_C0_IRQn               EXTI5_IRQn
#define EXTI6_C0_IRQn               EXTI6_IRQn
#define EXTI7_C0_IRQn               EXTI7_IRQn
#define EXTI8_C0_IRQn               EXTI8_IRQn
#define EXTI9_C0_IRQn               EXTI9_IRQn
#define EXTI10_C0_IRQn              EXTI10_IRQn
#define EXTI11_C0_IRQn              EXTI11_IRQn
#define EXTI12_C0_IRQn              EXTI12_IRQn
#define EXTI13_C0_IRQn              EXTI13_IRQn
#define EXTI14_C0_IRQn              EXTI14_IRQn
#define EXTI15_C0_IRQn              EXTI15_IRQn
#define SAES_C0_IRQn                SAES_IRQn
#define CRYP_C0_IRQn                CRYP_IRQn
#define PKA_C0_IRQn                 PKA_IRQn
#define HASH_C0_IRQn                HASH_IRQn
#define RNG_C0_IRQn                 RNG_IRQn
#define MCE1_C0_IRQn                MCE1_IRQn
#define MCE2_C0_IRQn                MCE2_IRQn
#define MCE3_C0_IRQn                MCE3_IRQn
#define DCMIPP_C0_IRQn              DCMIPP_IRQn
#define ADC1_C0_IRQn                ADC1_IRQn
#define ADC2_C0_IRQn                ADC2_IRQn
#define ADC3_C0_IRQn                ADC3_IRQn
#define DAC_C0_IRQn                 DAC_IRQn
#define LCD_S_C0_IRQn               LCD_S_IRQn
#define LCD_ERR_S_C0_IRQn           LCD_ERR_S_IRQn
#define LCD_C0_IRQn                 LCD_IRQn
#define LCD_ERR_C0_IRQn             LCD_ERR_IRQn
#define DMA2D_C0_IRQn               DMA2D_IRQn
#define JPEG_C0_IRQn                JPEG_IRQn
#define GFXMMU_S_C0_IRQn            GFXMMU_S_IRQn
#define GFXMMU_C0_IRQn              GFXMMU_IRQn
#define GFXTIM_C0_IRQn              GFXTIM_IRQn
#define HPDMA1_CH0_C0_IRQn          HPDMA1_CH0_IRQn
#define HPDMA1_CH1_C0_IRQn          HPDMA1_CH1_IRQn
#define HPDMA1_CH2_C0_IRQn          HPDMA1_CH2_IRQn
#define HPDMA1_CH3_C0_IRQn          HPDMA1_CH3_IRQn
#define HPDMA1_CH4_C0_IRQn          HPDMA1_CH4_IRQn
#define HPDMA1_CH5_C0_IRQn          HPDMA1_CH5_IRQn
#define HPDMA1_CH6_C0_IRQn          HPDMA1_CH6_IRQn
#define HPDMA1_CH7_C0_IRQn          HPDMA1_CH7_IRQn
#define HPDMA1_CH8_C0_IRQn          HPDMA1_CH8_IRQn
#define HPDMA1_CH9_C0_IRQn          HPDMA1_CH9_IRQn
#define HPDMA1_CH10_C0_IRQn         HPDMA1_CH10_IRQn
#define HPDMA1_CH11_C0_IRQn         HPDMA1_CH11_IRQn
#define HPDMA1_CH12_C0_IRQn         HPDMA1_CH12_IRQn
#define HPDMA1_CH13_C0_IRQn         HPDMA1_CH13_IRQn
#define HPDMA1_CH14_C0_IRQn         HPDMA1_CH14_IRQn
#define HPDMA1_CH15_C0_IRQn         HPDMA1_CH15_IRQn
#define GPDMA1_CH0_C0_IRQn          GPDMA1_CH0_IRQn
#define GPDMA1_CH1_C0_IRQn          GPDMA1_CH1_IRQn
#define GPDMA1_CH2_C0_IRQn          GPDMA1_CH2_IRQn
#define GPDMA1_CH3_C0_IRQn          GPDMA1_CH3_IRQn
#define GPDMA1_CH4_C0_IRQn          GPDMA1_CH4_IRQn
#define GPDMA1_CH5_C0_IRQn          GPDMA1_CH5_IRQn
#define GPDMA1_CH6_C0_IRQn          GPDMA1_CH6_IRQn
#define GPDMA1_CH7_C0_IRQn          GPDMA1_CH7_IRQn
#define GPDMA1_CH8_C0_IRQn          GPDMA1_CH8_IRQn
#define GPDMA1_CH9_C0_IRQn          GPDMA1_CH9_IRQn
#define GPDMA1_CH10_C0_IRQn         GPDMA1_CH10_IRQn
#define GPDMA1_CH11_C0_IRQn         GPDMA1_CH11_IRQn
#define GPDMA2_CH0_C0_IRQn          GPDMA2_CH0_IRQn
#define GPDMA2_CH1_C0_IRQn          GPDMA2_CH1_IRQn
#define GPDMA2_CH2_C0_IRQn          GPDMA2_CH2_IRQn
#define GPDMA2_CH3_C0_IRQn          GPDMA2_CH3_IRQn
#define GPDMA2_CH4_C0_IRQn          GPDMA2_CH4_IRQn
#define GPDMA2_CH5_C0_IRQn          GPDMA2_CH5_IRQn
#define GPDMA2_CH6_C0_IRQn          GPDMA2_CH6_IRQn
#define GPDMA2_CH7_C0_IRQn          GPDMA2_CH7_IRQn
#define GPDMA2_CH8_C0_IRQn          GPDMA2_CH8_IRQn
#define GPDMA2_CH9_C0_IRQn          GPDMA2_CH9_IRQn
#define GPDMA2_CH10_C0_IRQn         GPDMA2_CH10_IRQn
#define GPDMA2_CH11_C0_IRQn         GPDMA2_CH11_IRQn
#define I2C1_EV_C0_IRQn             I2C1_EV_IRQn
#define I2C1_ER_C0_IRQn             I2C1_ER_IRQn
#define I2C2_EV_C0_IRQn             I2C2_EV_IRQn
#define I2C2_ER_C0_IRQn             I2C2_ER_IRQn
#define I2C3_EV_C0_IRQn             I2C3_EV_IRQn
#define I2C3_ER_C0_IRQn             I2C3_ER_IRQn
#define I3C1_EV_C0_IRQn             I3C1_EV_IRQn
#define I3C1_ER_C0_IRQn             I3C1_ER_IRQn
#define I3C2_EV_C0_IRQn             I3C2_EV_IRQn
#define I3C2_ER_C0_IRQn             I3C2_ER_IRQn
#define TIM1_BRK_C0_IRQn            TIM1_BRK_IRQn
#define TIM1_UP_C0_IRQn             TIM1_UP_IRQn
#define TIM1_TRG_COM_C0_IRQn        TIM1_TRG_COM_IRQn
#define TIM1_CC_C0_IRQn             TIM1_CC_IRQn
#define TIM2_C0_IRQn                TIM2_IRQn
#define TIM3_C0_IRQn                TIM3_IRQn
#define TIM4_C0_IRQn                TIM4_IRQn
#define TIM5_C0_IRQn                TIM5_IRQn
#define TIM6_C0_IRQn                TIM6_IRQn
#define TIM7_C0_IRQn                TIM7_IRQn
#define TIM8_BRK_C0_IRQn            TIM8_BRK_IRQn
#define TIM8_UP_C0_IRQn             TIM8_UP_IRQn
#define TIM8_TRG_COM_C0_IRQn        TIM8_TRG_COM_IRQn
#define TIM8_CC_C0_IRQn             TIM8_CC_IRQn
#define TIM9_C0_IRQn                TIM9_IRQn
#define TIM10_C0_IRQn               TIM10_IRQn
#define TIM12_C0_IRQn               TIM12_IRQn
#define TIM13_C0_IRQn               TIM13_IRQn
#define TIM14_C0_IRQn               TIM14_IRQn
#define TIM15_C0_IRQn               TIM15_IRQn
#define TIM16_C0_IRQn               TIM16_IRQn
#define TIM17_C0_IRQn               TIM17_IRQn
#define TIM20_BRK_C0_IRQn           TIM20_BRK_IRQn
#define TIM20_UP_C0_IRQn            TIM20_UP_IRQn
#define TIM20_TRG_COM_C0_IRQn       TIM20_TRG_COM_IRQn
#define TIM20_CC_C0_IRQn            TIM20_CC_IRQn
#define LPTIM1_C0_IRQn              LPTIM1_IRQn
#define LPTIM2_C0_IRQn              LPTIM2_IRQn
#define LPTIM3_C0_IRQn              LPTIM3_IRQn
#define LPTIM4_C0_IRQn              LPTIM4_IRQn
#define LPTIM5_C0_IRQn              LPTIM5_IRQn
#define HRTIM1_M_C0_IRQn            HRTIM1_M_IRQn
#define HRTIM1_TIMA_C0_IRQn         HRTIM1_TIMA_IRQn
#define HRTIM1_TIMB_C0_IRQn         HRTIM1_TIMB_IRQn
#define HRTIM1_TIMC_C0_IRQn         HRTIM1_TIMC_IRQn
#define HRTIM1_TIMD_C0_IRQn         HRTIM1_TIMD_IRQn
#define HRTIM1_TIME_C0_IRQn         HRTIM1_TIME_IRQn
#define HRTIM1_TIMF_C0_IRQn         HRTIM1_TIMF_IRQn
#define HRTIM1_FLT_C0_IRQn          HRTIM1_FLT_IRQn
#define ADF1_FLT0_C0_IRQn           ADF1_FLT0_IRQn
#define MDF1_FLT0_C0_IRQn           MDF1_FLT0_IRQn
#define MDF1_FLT1_C0_IRQn           MDF1_FLT1_IRQn
#define MDF1_FLT2_C0_IRQn           MDF1_FLT2_IRQn
#define MDF1_FLT3_C0_IRQn           MDF1_FLT3_IRQn
#define MDF1_FLT4_C0_IRQn           MDF1_FLT4_IRQn
#define MDF1_FLT5_C0_IRQn           MDF1_FLT5_IRQn
#define SAI1_A_C0_IRQn              SAI1_A_IRQn
#define SAI1_B_C0_IRQn              SAI1_B_IRQn
#define SAI2_A_C0_IRQn              SAI2_A_IRQn
#define SAI2_B_C0_IRQn              SAI2_B_IRQn
#define SPDIFRX1_C0_IRQn            SPDIFRX1_IRQn
#define SPI1_C0_IRQn                SPI1_IRQn
#define SPI2_C0_IRQn                SPI2_IRQn
#define SPI3_C0_IRQn                SPI3_IRQn
#define SPI4_C0_IRQn                SPI4_IRQn
#define SPI5_C0_IRQn                SPI5_IRQn
#define SPI6_C0_IRQn                SPI6_IRQn
#define USART1_C0_IRQn              USART1_IRQn
#define USART2_C0_IRQn              USART2_IRQn
#define USART3_C0_IRQn              USART3_IRQn
#define UART4_C0_IRQn               UART4_IRQn
#define UART5_C0_IRQn               UART5_IRQn
#define USART6_C0_IRQn              USART6_IRQn
#define UART7_C0_IRQn               UART7_IRQn
#define UART8_C0_IRQn               UART8_IRQn
#define UART9_C0_IRQn               UART9_IRQn
#define USART10_C0_IRQn             USART10_IRQn
#define LPUART1_C0_IRQn             LPUART1_IRQn
#define CEC_C0_IRQn                 CEC_IRQn
#define XSPI1_C0_IRQn               XSPI1_IRQn
#define XSPI2_C0_IRQn               XSPI2_IRQn
#define FMC_C0_IRQn                 FMC_IRQn
#define SDMMC1_C0_IRQn              SDMMC1_IRQn
#define SDMMC2_C0_IRQn              SDMMC2_IRQn
#define UCPD1_C0_IRQn               UCPD1_IRQn
#define OTG1_C0_IRQn                OTG1_IRQn
#define OTG_FS_C0_IRQn              OTG_FS_IRQn
#define ETH1_C0_IRQn                ETH1_IRQn
#define FDCAN1_IT0_C0_IRQn          FDCAN1_IT0_IRQn
#define FDCAN1_IT1_C0_IRQn          FDCAN1_IT1_IRQn
#define FDCAN2_IT0_C0_IRQn          FDCAN2_IT0_IRQn
#define FDCAN2_IT1_C0_IRQn          FDCAN2_IT1_IRQn
#define FDCAN3_IT0_C0_IRQn          FDCAN3_IT0_IRQn
#define FDCAN3_IT1_C0_IRQn          FDCAN3_IT1_IRQn
#define FDCAN_CU_C0_IRQn            FDCAN_CU_IRQn
#define MDIOS_C0_IRQn               MDIOS_IRQn
#define PSSI_C0_IRQn                PSSI_IRQn
#define WKUP_C0_IRQn                WKUP_IRQn
#define LSECSS_C0_IRQn              LSECSS_IRQn
#define CORDIC_C0_IRQn              CORDIC_IRQn
#define FMAC_C0_IRQn                FMAC_IRQn
#define HSEM_S_C0_IRQn              HSEM_S_IRQn
#define HSEM__C0_IRQn               HSEM__IRQn
#define CTI_IT0_C0_IRQn             CTI_IT0_IRQn
#define CTI_IT1_C0_IRQn             CTI_IT1_IRQn
#define CRS_C0_IRQn                 CRS_IRQn
#define SBS_S_C0_IRQn               SBS_S_IRQn
#define SBS_C0_IRQn                 SBS_IRQn

// Prototypes

#if (defined(__cplusplus))
extern  "C" {
#endif

// Exceptions

void    NonMaskableInt_C0_IRQHandler(void);
void    HardFault_C0_IRQHandler(void);
void    MemoryManagement_C0_IRQHandler(void);
void    BusFault_C0_IRQHandler(void);
void    UsageFault_C0_IRQHandler(void);
void    SecureFault_C0_IRQHandler(void);
void    SVCall_C0_IRQHandler(void);
void    DebugMonitor_C0_IRQHandler(void);
void    PendSV_C0_IRQHandler(void);
void    SysTick_C0_IRQHandler(void);

// IRQHandler

void    PVD_C0_IRQHandler(void);
void    DTS_C0_IRQHandler(void);
void    LOCKUP_IT_C0_IRQHandler(void);
void    CACHE_ECC_C0_IRQHandler(void);
void    TCM_ECC_C0_IRQHandler(void);
void    RAMCFG_C0_IRQHandler(void);
void    FPU_C0_IRQHandler(void);
void    RCC_S_C0_IRQHandler(void);
void    RTC_S_C0_IRQHandler(void);
void    TAMP_C0_IRQHandler(void);
void    NVM_S_C0_IRQHandler(void);
void    RIFSC_TAMPER_C0_IRQHandler(void);
void    IAC_C0_IRQHandler(void);
void    RCC_C0_IRQHandler(void);
void    RTC_C0_IRQHandler(void);
void    NVM_C0_IRQHandler(void);
void    IWDG_C0_IRQHandler(void);
void    WWDG_C0_IRQHandler(void);
void    EXTI0_C0_IRQHandler(void);
void    EXTI1_C0_IRQHandler(void);
void    EXTI2_C0_IRQHandler(void);
void    EXTI3_C0_IRQHandler(void);
void    EXTI4_C0_IRQHandler(void);
void    EXTI5_C0_IRQHandler(void);
void    EXTI6_C0_IRQHandler(void);
void    EXTI7_C0_IRQHandler(void);
void    EXTI8_C0_IRQHandler(void);
void    EXTI9_C0_IRQHandler(void);
void    EXTI10_C0_IRQHandler(void);
void    EXTI11_C0_IRQHandler(void);
void    EXTI12_C0_IRQHandler(void);
void    EXTI13_C0_IRQHandler(void);
void    EXTI14_C0_IRQHandler(void);
void    EXTI15_C0_IRQHandler(void);
void    SAES_C0_IRQHandler(void);
void    CRYP_C0_IRQHandler(void);
void    PKA_C0_IRQHandler(void);
void    HASH_C0_IRQHandler(void);
void    RNG_C0_IRQHandler(void);
void    MCE1_C0_IRQHandler(void);
void    MCE2_C0_IRQHandler(void);
void    MCE3_C0_IRQHandler(void);
void    DCMIPP_C0_IRQHandler(void);
void    ADC1_C0_IRQHandler(void);
void    ADC2_C0_IRQHandler(void);
void    ADC3_C0_IRQHandler(void);
void    DAC_C0_IRQHandler(void);
void    LCD_S_C0_IRQHandler(void);
void    LCD_ERR_S_C0_IRQHandler(void);
void    LCD_C0_IRQHandler(void);
void    LCD_ERR_C0_IRQHandler(void);
void    DMA2D_C0_IRQHandler(void);
void    JPEG_C0_IRQHandler(void);
void    GFXMMU_S_C0_IRQHandler(void);
void    GFXMMU_C0_IRQHandler(void);
void    GFXTIM_C0_IRQHandler(void);
void    HPDMA1_CH0_C0_IRQHandler(void);
void    HPDMA1_CH1_C0_IRQHandler(void);
void    HPDMA1_CH2_C0_IRQHandler(void);
void    HPDMA1_CH3_C0_IRQHandler(void);
void    HPDMA1_CH4_C0_IRQHandler(void);
void    HPDMA1_CH5_C0_IRQHandler(void);
void    HPDMA1_CH6_C0_IRQHandler(void);
void    HPDMA1_CH7_C0_IRQHandler(void);
void    HPDMA1_CH8_C0_IRQHandler(void);
void    HPDMA1_CH9_C0_IRQHandler(void);
void    HPDMA1_CH10_C0_IRQHandler(void);
void    HPDMA1_CH11_C0_IRQHandler(void);
void    HPDMA1_CH12_C0_IRQHandler(void);
void    HPDMA1_CH13_C0_IRQHandler(void);
void    HPDMA1_CH14_C0_IRQHandler(void);
void    HPDMA1_CH15_C0_IRQHandler(void);
void    GPDMA1_CH0_C0_IRQHandler(void);
void    GPDMA1_CH1_C0_IRQHandler(void);
void    GPDMA1_CH2_C0_IRQHandler(void);
void    GPDMA1_CH3_C0_IRQHandler(void);
void    GPDMA1_CH4_C0_IRQHandler(void);
void    GPDMA1_CH5_C0_IRQHandler(void);
void    GPDMA1_CH6_C0_IRQHandler(void);
void    GPDMA1_CH7_C0_IRQHandler(void);
void    GPDMA1_CH8_C0_IRQHandler(void);
void    GPDMA1_CH9_C0_IRQHandler(void);
void    GPDMA1_CH10_C0_IRQHandler(void);
void    GPDMA1_CH11_C0_IRQHandler(void);
void    GPDMA2_CH0_C0_IRQHandler(void);
void    GPDMA2_CH1_C0_IRQHandler(void);
void    GPDMA2_CH2_C0_IRQHandler(void);
void    GPDMA2_CH3_C0_IRQHandler(void);
void    GPDMA2_CH4_C0_IRQHandler(void);
void    GPDMA2_CH5_C0_IRQHandler(void);
void    GPDMA2_CH6_C0_IRQHandler(void);
void    GPDMA2_CH7_C0_IRQHandler(void);
void    GPDMA2_CH8_C0_IRQHandler(void);
void    GPDMA2_CH9_C0_IRQHandler(void);
void    GPDMA2_CH10_C0_IRQHandler(void);
void    GPDMA2_CH11_C0_IRQHandler(void);
void    I2C1_EV_C0_IRQHandler(void);
void    I2C1_ER_C0_IRQHandler(void);
void    I2C2_EV_C0_IRQHandler(void);
void    I2C2_ER_C0_IRQHandler(void);
void    I2C3_EV_C0_IRQHandler(void);
void    I2C3_ER_C0_IRQHandler(void);
void    I3C1_EV_C0_IRQHandler(void);
void    I3C1_ER_C0_IRQHandler(void);
void    I3C2_EV_C0_IRQHandler(void);
void    I3C2_ER_C0_IRQHandler(void);
void    TIM1_BRK_C0_IRQHandler(void);
void    TIM1_UP_C0_IRQHandler(void);
void    TIM1_TRG_COM_C0_IRQHandler(void);
void    TIM1_CC_C0_IRQHandler(void);
void    TIM2_C0_IRQHandler(void);
void    TIM3_C0_IRQHandler(void);
void    TIM4_C0_IRQHandler(void);
void    TIM5_C0_IRQHandler(void);
void    TIM6_C0_IRQHandler(void);
void    TIM7_C0_IRQHandler(void);
void    TIM8_BRK_C0_IRQHandler(void);
void    TIM8_UP_C0_IRQHandler(void);
void    TIM8_TRG_COM_C0_IRQHandler(void);
void    TIM8_CC_C0_IRQHandler(void);
void    TIM9_C0_IRQHandler(void);
void    TIM10_C0_IRQHandler(void);
void    TIM12_C0_IRQHandler(void);
void    TIM13_C0_IRQHandler(void);
void    TIM14_C0_IRQHandler(void);
void    TIM15_C0_IRQHandler(void);
void    TIM16_C0_IRQHandler(void);
void    TIM17_C0_IRQHandler(void);
void    TIM20_BRK_C0_IRQHandler(void);
void    TIM20_UP_C0_IRQHandler(void);
void    TIM20_TRG_COM_C0_IRQHandler(void);
void    TIM20_CC_C0_IRQHandler(void);
void    LPTIM1_C0_IRQHandler(void);
void    LPTIM2_C0_IRQHandler(void);
void    LPTIM3_C0_IRQHandler(void);
void    LPTIM4_C0_IRQHandler(void);
void    LPTIM5_C0_IRQHandler(void);
void    HRTIM1_M_C0_IRQHandler(void);
void    HRTIM1_TIMA_C0_IRQHandler(void);
void    HRTIM1_TIMB_C0_IRQHandler(void);
void    HRTIM1_TIMC_C0_IRQHandler(void);
void    HRTIM1_TIMD_C0_IRQHandler(void);
void    HRTIM1_TIME_C0_IRQHandler(void);
void    HRTIM1_TIMF_C0_IRQHandler(void);
void    HRTIM1_FLT_C0_IRQHandler(void);
void    ADF1_FLT0_C0_IRQHandler(void);
void    MDF1_FLT0_C0_IRQHandler(void);
void    MDF1_FLT1_C0_IRQHandler(void);
void    MDF1_FLT2_C0_IRQHandler(void);
void    MDF1_FLT3_C0_IRQHandler(void);
void    MDF1_FLT4_C0_IRQHandler(void);
void    MDF1_FLT5_C0_IRQHandler(void);
void    SAI1_A_C0_IRQHandler(void);
void    SAI1_B_C0_IRQHandler(void);
void    SAI2_A_C0_IRQHandler(void);
void    SAI2_B_C0_IRQHandler(void);
void    SPDIFRX1_C0_IRQHandler(void);
void    SPI1_C0_IRQHandler(void);
void    SPI2_C0_IRQHandler(void);
void    SPI3_C0_IRQHandler(void);
void    SPI4_C0_IRQHandler(void);
void    SPI5_C0_IRQHandler(void);
void    SPI6_C0_IRQHandler(void);
void    USART1_C0_IRQHandler(void);
void    USART2_C0_IRQHandler(void);
void    USART3_C0_IRQHandler(void);
void    UART4_C0_IRQHandler(void);
void    UART5_C0_IRQHandler(void);
void    USART6_C0_IRQHandler(void);
void    UART7_C0_IRQHandler(void);
void    UART8_C0_IRQHandler(void);
void    UART9_C0_IRQHandler(void);
void    USART10_C0_IRQHandler(void);
void    LPUART1_C0_IRQHandler(void);
void    CEC_C0_IRQHandler(void);
void    XSPI1_C0_IRQHandler(void);
void    XSPI2_C0_IRQHandler(void);
void    FMC_C0_IRQHandler(void);
void    SDMMC1_C0_IRQHandler(void);
void    SDMMC2_C0_IRQHandler(void);
void    UCPD1_C0_IRQHandler(void);
void    OTG1_C0_IRQHandler(void);
void    OTG_FS_C0_IRQHandler(void);
void    ETH1_C0_IRQHandler(void);
void    FDCAN1_IT0_C0_IRQHandler(void);
void    FDCAN1_IT1_C0_IRQHandler(void);
void    FDCAN2_IT0_C0_IRQHandler(void);
void    FDCAN2_IT1_C0_IRQHandler(void);
void    FDCAN3_IT0_C0_IRQHandler(void);
void    FDCAN3_IT1_C0_IRQHandler(void);
void    FDCAN_CU_C0_IRQHandler(void);
void    MDIOS_C0_IRQHandler(void);
void    PSSI_C0_IRQHandler(void);
void    WKUP_C0_IRQHandler(void);
void    LSECSS_C0_IRQHandler(void);
void    CORDIC_C0_IRQHandler(void);
void    FMAC_C0_IRQHandler(void);
void    HSEM_S_C0_IRQHandler(void);
void    HSEM__C0_IRQHandler(void);
void    CTI_IT0_C0_IRQHandler(void);
void    CTI_IT1_C0_IRQHandler(void);
void    CRS_C0_IRQHandler(void);
void    SBS_S_C0_IRQHandler(void);
void    SBS_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
