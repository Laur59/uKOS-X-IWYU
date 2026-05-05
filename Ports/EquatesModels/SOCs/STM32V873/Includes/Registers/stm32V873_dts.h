/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_dts equates.
 */
#pragma once

#include    <stdint.h>

// DTS address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CFGR1;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    T0VALR1;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    RAMPVALR;
    volatile    uint32_t    ITR1;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    DR;
    volatile    uint32_t    SR;
    volatile    uint32_t    ITENR;
    volatile    uint32_t    ICIFR;
    volatile    uint32_t    OR;
} DTS_TypeDef;

#if (defined(__cplusplus))
#define DTS_NS  reinterpret_cast<DTS_TypeDef *>(0x46006800u)
#define DTS_S   reinterpret_cast<DTS_TypeDef *>(0x56006800u)

#else
#define DTS_NS  ((DTS_TypeDef *)0x46006800u)
#define DTS_S   ((DTS_TypeDef *)0x56006800u)
#endif

// CFGR1 Configuration

#define DTS_CFGR1_REFCLK_SEL            (0x1u<<20)
#define DTS_CFGR1_TS1_SMP_TIME          (0xFu<<16)
#define DTS_CFGR1_TS1_SMP_TIME_0        (0x1u<<16)
#define DTS_CFGR1_TS1_INTRIG_SEL        (0xFu<<8)
#define DTS_CFGR1_TS1_INTRIG_SEL_0      (0x1u<<8)
#define DTS_CFGR1_TS1_START             (0x1u<<4)
#define DTS_CFGR1_TS1_EN                (0x1u<<0)

#define DTS_CFGR1_REFCLK_SEL_B_0X0      (0x0u<<20)
#define DTS_CFGR1_REFCLK_SEL_B_0X1      (0x1u<<20)
#define DTS_CFGR1_TS1_START_B_0X0       (0x0u<<4)
#define DTS_CFGR1_TS1_START_B_0X1       (0x1u<<4)
#define DTS_CFGR1_TS1_EN_B_0X0          (0x0u<<0)
#define DTS_CFGR1_TS1_EN_B_0X1          (0x1u<<0)

// T0VALR1 Configuration

#define DTS_T0VALR1_TS1_T0              (0x3u<<16)
#define DTS_T0VALR1_TS1_T0_0            (0x1u<<16)
#define DTS_T0VALR1_TS1_FMT0            (0xFFFFu<<0)
#define DTS_T0VALR1_TS1_FMT0_0          (0x1u<<0)

#define DTS_T0VALR1_TS1_T0_B_0X0        (0x0u<<16)
#define DTS_T0VALR1_TS1_T0_B_0X1        (0x1u<<16)

// RAMPVALR Configuration

#define DTS_RAMPVALR_TS1_RAMP_COEFF     (0xFFFFu<<0)
#define DTS_RAMPVALR_TS1_RAMP_COEFF_0   (0x1u<<0)

// ITR1 Configuration

#define DTS_ITR1_TS1_HITTHD             (0xFFFFu<<16)
#define DTS_ITR1_TS1_HITTHD_0           (0x1u<<16)
#define DTS_ITR1_TS1_LITTHD             (0xFFFFu<<0)
#define DTS_ITR1_TS1_LITTHD_0           (0x1u<<0)

// DR Configuration

#define DTS_DR_TS1_MFREQ                (0xFFFFu<<0)
#define DTS_DR_TS1_MFREQ_0              (0x1u<<0)

// SR Configuration

#define DTS_SR_TS1_RDY                  (0x1u<<15)
#define DTS_SR_TS1_AITHF                (0x1u<<6)
#define DTS_SR_TS1_AITLF                (0x1u<<5)
#define DTS_SR_TS1_AITEF                (0x1u<<4)
#define DTS_SR_TS1_ITHF                 (0x1u<<2)
#define DTS_SR_TS1_ITLF                 (0x1u<<1)
#define DTS_SR_TS1_ITEF                 (0x1u<<0)

#define DTS_SR_TS1_RDY_B_0X0            (0x0u<<15)
#define DTS_SR_TS1_RDY_B_0X1            (0x1u<<15)
#define DTS_SR_TS1_AITHF_B_0X0          (0x0u<<6)
#define DTS_SR_TS1_AITHF_B_0X1          (0x1u<<6)
#define DTS_SR_TS1_AITLF_B_0X0          (0x0u<<5)
#define DTS_SR_TS1_AITLF_B_0X1          (0x1u<<5)
#define DTS_SR_TS1_AITEF_B_0X0          (0x0u<<4)
#define DTS_SR_TS1_AITEF_B_0X1          (0x1u<<4)
#define DTS_SR_TS1_ITHF_B_0X0           (0x0u<<2)
#define DTS_SR_TS1_ITHF_B_0X1           (0x1u<<2)
#define DTS_SR_TS1_ITLF_B_0X0           (0x0u<<1)
#define DTS_SR_TS1_ITLF_B_0X1           (0x1u<<1)
#define DTS_SR_TS1_ITEF_B_0X0           (0x0u<<0)
#define DTS_SR_TS1_ITEF_B_0X1           (0x1u<<0)

// ITENR Configuration

#define DTS_ITENR_TS1_AITHEN            (0x1u<<6)
#define DTS_ITENR_TS1_AITLEN            (0x1u<<5)
#define DTS_ITENR_TS1_AITEEN            (0x1u<<4)
#define DTS_ITENR_TS1_ITHEN             (0x1u<<2)
#define DTS_ITENR_TS1_ITLEN             (0x1u<<1)
#define DTS_ITENR_TS1_ITEEN             (0x1u<<0)

#define DTS_ITENR_TS1_AITHEN_B_0X0      (0x0u<<6)
#define DTS_ITENR_TS1_AITHEN_B_0X1      (0x1u<<6)
#define DTS_ITENR_TS1_AITLEN_B_0X0      (0x0u<<5)
#define DTS_ITENR_TS1_AITLEN_B_0X1      (0x1u<<5)
#define DTS_ITENR_TS1_AITEEN_B_0X0      (0x0u<<4)
#define DTS_ITENR_TS1_AITEEN_B_0X1      (0x1u<<4)
#define DTS_ITENR_TS1_ITHEN_B_0X0       (0x0u<<2)
#define DTS_ITENR_TS1_ITHEN_B_0X1       (0x1u<<2)
#define DTS_ITENR_TS1_ITLEN_B_0X0       (0x0u<<1)
#define DTS_ITENR_TS1_ITLEN_B_0X1       (0x1u<<1)
#define DTS_ITENR_TS1_ITEEN_B_0X0       (0x0u<<0)
#define DTS_ITENR_TS1_ITEEN_B_0X1       (0x1u<<0)

// ICIFR Configuration

#define DTS_ICIFR_TS1_CAITHF            (0x1u<<6)
#define DTS_ICIFR_TS1_CAITLF            (0x1u<<5)
#define DTS_ICIFR_TS1_CAITEF            (0x1u<<4)
#define DTS_ICIFR_TS1_CITHF             (0x1u<<2)
#define DTS_ICIFR_TS1_CITLF             (0x1u<<1)
#define DTS_ICIFR_TS1_CITEF             (0x1u<<0)

// OR Configuration

#define DTS_OR_TS_OP31                  (0x1u<<31)
#define DTS_OR_TS_OP30                  (0x1u<<30)
#define DTS_OR_TS_OP29                  (0x1u<<29)
#define DTS_OR_TS_OP28                  (0x1u<<28)
#define DTS_OR_TS_OP27                  (0x1u<<27)
#define DTS_OR_TS_OP26                  (0x1u<<26)
#define DTS_OR_TS_OP25                  (0x1u<<25)
#define DTS_OR_TS_OP24                  (0x1u<<24)
#define DTS_OR_TS_OP23                  (0x1u<<23)
#define DTS_OR_TS_OP22                  (0x1u<<22)
#define DTS_OR_TS_OP21                  (0x1u<<21)
#define DTS_OR_TS_OP20                  (0x1u<<20)
#define DTS_OR_TS_OP19                  (0x1u<<19)
#define DTS_OR_TS_OP18                  (0x1u<<18)
#define DTS_OR_TS_OP17                  (0x1u<<17)
#define DTS_OR_TS_OP16                  (0x1u<<16)
#define DTS_OR_TS_OP15                  (0x1u<<15)
#define DTS_OR_TS_OP14                  (0x1u<<14)
#define DTS_OR_TS_OP13                  (0x1u<<13)
#define DTS_OR_TS_OP12                  (0x1u<<12)
#define DTS_OR_TS_OP11                  (0x1u<<11)
#define DTS_OR_TS_OP10                  (0x1u<<10)
#define DTS_OR_TS_OP9                   (0x1u<<9)
#define DTS_OR_TS_OP8                   (0x1u<<8)
#define DTS_OR_TS_OP7                   (0x1u<<7)
#define DTS_OR_TS_OP6                   (0x1u<<6)
#define DTS_OR_TS_OP5                   (0x1u<<5)
#define DTS_OR_TS_OP4                   (0x1u<<4)
#define DTS_OR_TS_OP3                   (0x1u<<3)
#define DTS_OR_TS_OP2                   (0x1u<<2)
#define DTS_OR_TS_OP1                   (0x1u<<1)
#define DTS_OR_TS_OP0                   (0x1u<<0)
