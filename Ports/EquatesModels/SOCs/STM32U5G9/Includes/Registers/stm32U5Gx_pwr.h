/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_pwr equates.
 */

#pragma once

#include    <stdint.h>

// PWR address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
    volatile    uint32_t    VOSR;
    volatile    uint32_t    SVMCR;
    volatile    uint32_t    WUCR1;
    volatile    uint32_t    WUCR2;
    volatile    uint32_t    WUCR3;
    volatile    uint32_t    BDCR1;
    volatile    uint32_t    BDCR2;
    volatile    uint32_t    DBPR;
    volatile    uint32_t    UCPDR;
    volatile    uint32_t    SECCFGR;
    volatile    uint32_t    PRIVCFGR;
    volatile    uint32_t    SR;
    volatile    uint32_t    SVMSR;
    volatile    uint32_t    BDSR;
    volatile    uint32_t    WUSR;
    volatile    uint32_t    WUSCR;
    volatile    uint32_t    APCR;
    volatile    uint32_t    PUCRA;
    volatile    uint32_t    PDCRA;
    volatile    uint32_t    PUCRB;
    volatile    uint32_t    PDCRB;
    volatile    uint32_t    PUCRC;
    volatile    uint32_t    PDCRC;
    volatile    uint32_t    PUCRD;
    volatile    uint32_t    PDCRD;
    volatile    uint32_t    PUCRE;
    volatile    uint32_t    PDCRE;
    volatile    uint32_t    PUCRF;
    volatile    uint32_t    PDCRF;
    volatile    uint32_t    PUCRG;
    volatile    uint32_t    PDCRG;
    volatile    uint32_t    PUCRH;
    volatile    uint32_t    PDCRH;
    volatile    uint32_t    PUCRI;
    volatile    uint32_t    PDCRI;
    volatile    uint32_t    PUCRJ;
    volatile    uint32_t    PDCRJ;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    CR4;
} PWR_TypeDef;

#ifdef __cplusplus
#define PWR_NS  reinterpret_cast<PWR_TypeDef *>(0x46020800U)
#define PWR_S   reinterpret_cast<PWR_TypeDef *>(0x56020800U)

#else
#define PWR_NS  ((PWR_TypeDef *)0x46020800U)
#define PWR_S   ((PWR_TypeDef *)0x56020800U)
#endif

// CR1 Configuration

#define PWR_CR1_SRAM5PD             (0x1U<<12U)
#define PWR_CR1_SRAM4PD             (0x1U<<11U)
#define PWR_CR1_SRAM3PD             (0x1U<<10U)
#define PWR_CR1_SRAM2PD             (0x1U<<9U)
#define PWR_CR1_SRAM1PD             (0x1U<<8U)
#define PWR_CR1_ULPMEN              (0x1U<<7U)
#define PWR_CR1_RRSB2               (0x1U<<6U)
#define PWR_CR1_RRSB1               (0x1U<<5U)
#define PWR_CR1_LPMS                (0x7U<<0U)
#define PWR_CR1_LPMS_0              (0x1U<<0U)
#define PWR_CR1_SRAM5PD_B_0X0       (0x0U<<12U)
#define PWR_CR1_SRAM5PD_B_0X1       (0x1U<<12U)
#define PWR_CR1_SRAM4PD_B_0X0       (0x0U<<11U)
#define PWR_CR1_SRAM4PD_B_0X1       (0x1U<<11U)
#define PWR_CR1_SRAM3PD_B_0X0       (0x0U<<10U)
#define PWR_CR1_SRAM3PD_B_0X1       (0x1U<<10U)
#define PWR_CR1_SRAM2PD_B_0X0       (0x0U<<9U)
#define PWR_CR1_SRAM2PD_B_0X1       (0x1U<<9U)
#define PWR_CR1_SRAM1PD_B_0X0       (0x0U<<8U)
#define PWR_CR1_SRAM1PD_B_0X1       (0x1U<<8U)
#define PWR_CR1_ULPMEN_B_0X0        (0x0U<<7U)
#define PWR_CR1_ULPMEN_B_0X1        (0x1U<<7U)
#define PWR_CR1_RRSB2_B_0X0         (0x0U<<6U)
#define PWR_CR1_RRSB2_B_0X1         (0x1U<<6U)
#define PWR_CR1_RRSB1_B_0X0         (0x0U<<5U)
#define PWR_CR1_RRSB1_B_0X1         (0x1U<<5U)
#define PWR_CR1_LPMS_B_0X0          (0x0U<<0U)
#define PWR_CR1_LPMS_B_0X1          (0x1U<<0U)
#define PWR_CR1_LPMS_B_0X2          (0x2U<<0U)
#define PWR_CR1_LPMS_B_0X3          (0x3U<<0U)

// CR2 Configuration

#define PWR_CR2_SRDRUN              (0x1U<<31U)
#define PWR_CR2_DSIRAMPDS           (0x1U<<25U)
#define PWR_CR2_GPRAMPDS            (0x1U<<24U)
#define PWR_CR2_SRAM3PDS8           (0x1U<<23U)
#define PWR_CR2_SRAM3PDS7           (0x1U<<22U)
#define PWR_CR2_SRAM3PDS6           (0x1U<<21U)
#define PWR_CR2_SRAM3PDS5           (0x1U<<20U)
#define PWR_CR2_SRAM3PDS4           (0x1U<<19U)
#define PWR_CR2_SRAM3PDS3           (0x1U<<18U)
#define PWR_CR2_SRAM3PDS2           (0x1U<<17U)
#define PWR_CR2_SRAM3PDS1           (0x1U<<16U)
#define PWR_CR2_FLASHFWU            (0x1U<<14U)
#define PWR_CR2_SRAM4FWU            (0x1U<<13U)
#define PWR_CR2_PKARAMPDS           (0x1U<<12U)
#define PWR_CR2_PRAMPDS             (0x1U<<11U)
#define PWR_CR2_DMA2DRAMPDS         (0x1U<<10U)
#define PWR_CR2_DC1RAMPDS           (0x1U<<9U)
#define PWR_CR2_ICRAMPDS            (0x1U<<8U)
#define PWR_CR2_DC2RAMPDS           (0x1U<<7U)
#define PWR_CR2_SRAM4PDS            (0x1U<<6U)
#define PWR_CR2_SRAM2PDS2           (0x1U<<5U)
#define PWR_CR2_SRAM2PDS1           (0x1U<<4U)
#define PWR_CR2_SRAM1PDS3           (0x1U<<2U)
#define PWR_CR2_SRAM1PDS2           (0x1U<<1U)
#define PWR_CR2_SRAM1PDS1           (0x1U<<0U)
#define PWR_CR2_SRDRUN_B_0X0        (0x0U<<31U)
#define PWR_CR2_SRDRUN_B_0X1        (0x1U<<31U)
#define PWR_CR2_DSIRAMPDS_B_0X0     (0x0U<<25U)
#define PWR_CR2_DSIRAMPDS_B_0X1     (0x1U<<25U)
#define PWR_CR2_GPRAMPDS_B_0X0      (0x0U<<24U)
#define PWR_CR2_GPRAMPDS_B_0X1      (0x1U<<24U)
#define PWR_CR2_SRAM3PDS8_B_0X0     (0x0U<<23U)
#define PWR_CR2_SRAM3PDS8_B_0X1     (0x1U<<23U)
#define PWR_CR2_SRAM3PDS7_B_0X0     (0x0U<<22U)
#define PWR_CR2_SRAM3PDS7_B_0X1     (0x1U<<22U)
#define PWR_CR2_SRAM3PDS6_B_0X0     (0x0U<<21U)
#define PWR_CR2_SRAM3PDS6_B_0X1     (0x1U<<21U)
#define PWR_CR2_SRAM3PDS5_B_0X0     (0x0U<<20U)
#define PWR_CR2_SRAM3PDS5_B_0X1     (0x1U<<20U)
#define PWR_CR2_SRAM3PDS4_B_0X0     (0x0U<<19U)
#define PWR_CR2_SRAM3PDS4_B_0X1     (0x1U<<19U)
#define PWR_CR2_SRAM3PDS3_B_0X0     (0x0U<<18U)
#define PWR_CR2_SRAM3PDS3_B_0X1     (0x1U<<18U)
#define PWR_CR2_SRAM3PDS2_B_0X0     (0x0U<<17U)
#define PWR_CR2_SRAM3PDS2_B_0X1     (0x1U<<17U)
#define PWR_CR2_SRAM3PDS1_B_0X0     (0x0U<<16U)
#define PWR_CR2_SRAM3PDS1_B_0X1     (0x1U<<16U)
#define PWR_CR2_FLASHFWU_B_0X0      (0x0U<<14U)
#define PWR_CR2_FLASHFWU_B_0X1      (0x1U<<14U)
#define PWR_CR2_SRAM4FWU_B_0X0      (0x0U<<13U)
#define PWR_CR2_SRAM4FWU_B_0X1      (0x1U<<13U)
#define PWR_CR2_PKARAMPDS_B_0X0     (0x0U<<12U)
#define PWR_CR2_PKARAMPDS_B_0X1     (0x1U<<12U)
#define PWR_CR2_PRAMPDS_B_0X0       (0x0U<<11U)
#define PWR_CR2_PRAMPDS_B_0X1       (0x1U<<11U)
#define PWR_CR2_DMA2DRAMPDS_B_0X0   (0x0U<<10U)
#define PWR_CR2_DMA2DRAMPDS_B_0X1   (0x1U<<10U)
#define PWR_CR2_DC1RAMPDS_B_0X0     (0x0U<<9U)
#define PWR_CR2_DC1RAMPDS_B_0X1     (0x1U<<9U)
#define PWR_CR2_ICRAMPDS_B_0X0      (0x0U<<8U)
#define PWR_CR2_ICRAMPDS_B_0X1      (0x1U<<8U)
#define PWR_CR2_DC2RAMPDS_B_0X0     (0x0U<<7U)
#define PWR_CR2_DC2RAMPDS_B_0X1     (0x1U<<7U)
#define PWR_CR2_SRAM4PDS_B_0X0      (0x0U<<6U)
#define PWR_CR2_SRAM4PDS_B_0X1      (0x1U<<6U)
#define PWR_CR2_SRAM2PDS2_B_0X0     (0x0U<<5U)
#define PWR_CR2_SRAM2PDS2_B_0X1     (0x1U<<5U)
#define PWR_CR2_SRAM2PDS1_B_0X0     (0x0U<<4U)
#define PWR_CR2_SRAM2PDS1_B_0X1     (0x1U<<4U)
#define PWR_CR2_SRAM1PDS3_B_0X0     (0x0U<<2U)
#define PWR_CR2_SRAM1PDS3_B_0X1     (0x1U<<2U)
#define PWR_CR2_SRAM1PDS2_B_0X0     (0x0U<<1U)
#define PWR_CR2_SRAM1PDS2_B_0X1     (0x1U<<1U)
#define PWR_CR2_SRAM1PDS1_B_0X0     (0x0U<<0U)
#define PWR_CR2_SRAM1PDS1_B_0X1     (0x1U<<0U)

// CR3 Configuration

#define PWR_CR3_FSTEN               (0x1U<<2U)
#define PWR_CR3_REGSEL              (0x1U<<1U)
#define PWR_CR3_FSTEN_B_0X0         (0x0U<<2U)
#define PWR_CR3_FSTEN_B_0X1         (0x1U<<2U)
#define PWR_CR3_REGSEL_B_0X0        (0x0U<<1U)
#define PWR_CR3_REGSEL_B_0X1        (0x1U<<1U)

// VOSR Configuration

#define PWR_VOSR_USBBOOSTEN         (0x1U<<20U)
#define PWR_VOSR_USBPWREN           (0x1U<<19U)
#define PWR_VOSR_BOOSTEN            (0x1U<<18U)
#define PWR_VOSR_VOS                (0x3U<<16U)
#define PWR_VOSR_VOS_0              (0x1U<<16U)
#define PWR_VOSR_VOSRDY             (0x1U<<15U)
#define PWR_VOSR_BOOSTRDY           (0x1U<<14U)
#define PWR_VOSR_USBBOOSTRDY        (0x1U<<13U)
#define PWR_VOSR_USBBOOSTEN_B_0X0   (0x0U<<20U)
#define PWR_VOSR_USBBOOSTEN_B_0X1   (0x1U<<20U)
#define PWR_VOSR_USBPWREN_B_0X0     (0x0U<<19U)
#define PWR_VOSR_USBPWREN_B_0X1     (0x1U<<19U)
#define PWR_VOSR_BOOSTEN_B_0X0      (0x0U<<18U)
#define PWR_VOSR_BOOSTEN_B_0X1      (0x1U<<18U)
#define PWR_VOSR_VOS_B_0X0          (0x0U<<16U)
#define PWR_VOSR_VOS_B_0X1          (0x1U<<16U)
#define PWR_VOSR_VOS_B_0X2          (0x2U<<16U)
#define PWR_VOSR_VOS_B_0X3          (0x3U<<16U)
#define PWR_VOSR_VOSRDY_B_0X0       (0x0U<<15U)
#define PWR_VOSR_VOSRDY_B_0X1       (0x1U<<15U)
#define PWR_VOSR_BOOSTRDY_B_0X0     (0x0U<<14U)
#define PWR_VOSR_BOOSTRDY_B_0X1     (0x1U<<14U)
#define PWR_VOSR_USBBOOSTRDY_B_0X0  (0x0U<<13U)
#define PWR_VOSR_USBBOOSTRDY_B_0X1  (0x1U<<13U)

// SVMCR Configuration

#define PWR_SVMCR_ASV               (0x1U<<30U)
#define PWR_SVMCR_IO2SV             (0x1U<<29U)
#define PWR_SVMCR_USV               (0x1U<<28U)
#define PWR_SVMCR_AVM2EN            (0x1U<<27U)
#define PWR_SVMCR_AVM1EN            (0x1U<<26U)
#define PWR_SVMCR_IO2VMEN           (0x1U<<25U)
#define PWR_SVMCR_UVMEN             (0x1U<<24U)
#define PWR_SVMCR_PVDLS             (0x7U<<5U)
#define PWR_SVMCR_PVDLS_0           (0x1U<<5U)
#define PWR_SVMCR_PVDE              (0x1U<<4U)
#define PWR_SVMCR_ASV_B_0X0         (0x0U<<30U)
#define PWR_SVMCR_ASV_B_0X1         (0x1U<<30U)
#define PWR_SVMCR_IO2SV_B_0X0       (0x0U<<29U)
#define PWR_SVMCR_IO2SV_B_0X1       (0x1U<<29U)
#define PWR_SVMCR_USV_B_0X0         (0x0U<<28U)
#define PWR_SVMCR_USV_B_0X1         (0x1U<<28U)
#define PWR_SVMCR_AVM2EN_B_0X0      (0x0U<<27U)
#define PWR_SVMCR_AVM2EN_B_0X1      (0x1U<<27U)
#define PWR_SVMCR_AVM1EN_B_0X0      (0x0U<<26U)
#define PWR_SVMCR_AVM1EN_B_0X1      (0x1U<<26U)
#define PWR_SVMCR_IO2VMEN_B_0X0     (0x0U<<25U)
#define PWR_SVMCR_IO2VMEN_B_0X1     (0x1U<<25U)
#define PWR_SVMCR_UVMEN_B_0X0       (0x0U<<24U)
#define PWR_SVMCR_UVMEN_B_0X1       (0x1U<<24U)
#define PWR_SVMCR_PVDLS_B_0X0       (0x0U<<5U)
#define PWR_SVMCR_PVDLS_B_0X1       (0x1U<<5U)
#define PWR_SVMCR_PVDLS_B_0X2       (0x2U<<5U)
#define PWR_SVMCR_PVDLS_B_0X3       (0x3U<<5U)
#define PWR_SVMCR_PVDLS_B_0X4       (0x4U<<5U)
#define PWR_SVMCR_PVDLS_B_0X5       (0x5U<<5U)
#define PWR_SVMCR_PVDLS_B_0X6       (0x6U<<5U)
#define PWR_SVMCR_PVDLS_B_0X7       (0x7U<<5U)
#define PWR_SVMCR_PVDE_B_0X0        (0x0U<<4U)
#define PWR_SVMCR_PVDE_B_0X1        (0x1U<<4U)

// WUCR1 Configuration

#define PWR_WUCR1_WUPEN8            (0x1U<<7U)
#define PWR_WUCR1_WUPEN7            (0x1U<<6U)
#define PWR_WUCR1_WUPEN6            (0x1U<<5U)
#define PWR_WUCR1_WUPEN5            (0x1U<<4U)
#define PWR_WUCR1_WUPEN4            (0x1U<<3U)
#define PWR_WUCR1_WUPEN3            (0x1U<<2U)
#define PWR_WUCR1_WUPEN2            (0x1U<<1U)
#define PWR_WUCR1_WUPEN1            (0x1U<<0U)
#define PWR_WUCR1_WUPEN8_B_0X0      (0x0U<<7U)
#define PWR_WUCR1_WUPEN8_B_0X1      (0x1U<<7U)
#define PWR_WUCR1_WUPEN7_B_0X0      (0x0U<<6U)
#define PWR_WUCR1_WUPEN7_B_0X1      (0x1U<<6U)
#define PWR_WUCR1_WUPEN6_B_0X0      (0x0U<<5U)
#define PWR_WUCR1_WUPEN6_B_0X1      (0x1U<<5U)
#define PWR_WUCR1_WUPEN5_B_0X0      (0x0U<<4U)
#define PWR_WUCR1_WUPEN5_B_0X1      (0x1U<<4U)
#define PWR_WUCR1_WUPEN4_B_0X0      (0x0U<<3U)
#define PWR_WUCR1_WUPEN4_B_0X1      (0x1U<<3U)
#define PWR_WUCR1_WUPEN3_B_0X0      (0x0U<<2U)
#define PWR_WUCR1_WUPEN3_B_0X1      (0x1U<<2U)
#define PWR_WUCR1_WUPEN2_B_0X0      (0x0U<<1U)
#define PWR_WUCR1_WUPEN2_B_0X1      (0x1U<<1U)
#define PWR_WUCR1_WUPEN1_B_0X0      (0x0U<<0U)
#define PWR_WUCR1_WUPEN1_B_0X1      (0x1U<<0U)

// WUCR2 Configuration

#define PWR_WUCR2_WUPP8             (0x1U<<7U)
#define PWR_WUCR2_WUPP7             (0x1U<<6U)
#define PWR_WUCR2_WUPP6             (0x1U<<5U)
#define PWR_WUCR2_WUPP5             (0x1U<<4U)
#define PWR_WUCR2_WUPP4             (0x1U<<3U)
#define PWR_WUCR2_WUPP3             (0x1U<<2U)
#define PWR_WUCR2_WUPP2             (0x1U<<1U)
#define PWR_WUCR2_WUPP1             (0x1U<<0U)
#define PWR_WUCR2_WUPP8_B_0X0       (0x0U<<7U)
#define PWR_WUCR2_WUPP8_B_0X1       (0x1U<<7U)
#define PWR_WUCR2_WUPP7_B_0X0       (0x0U<<6U)
#define PWR_WUCR2_WUPP7_B_0X1       (0x1U<<6U)
#define PWR_WUCR2_WUPP6_B_0X0       (0x0U<<5U)
#define PWR_WUCR2_WUPP6_B_0X1       (0x1U<<5U)
#define PWR_WUCR2_WUPP5_B_0X0       (0x0U<<4U)
#define PWR_WUCR2_WUPP5_B_0X1       (0x1U<<4U)
#define PWR_WUCR2_WUPP4_B_0X0       (0x0U<<3U)
#define PWR_WUCR2_WUPP4_B_0X1       (0x1U<<3U)
#define PWR_WUCR2_WUPP3_B_0X0       (0x0U<<2U)
#define PWR_WUCR2_WUPP3_B_0X1       (0x1U<<2U)
#define PWR_WUCR2_WUPP2_B_0X0       (0x0U<<1U)
#define PWR_WUCR2_WUPP2_B_0X1       (0x1U<<1U)
#define PWR_WUCR2_WUPP1_B_0X0       (0x0U<<0U)
#define PWR_WUCR2_WUPP1_B_0X1       (0x1U<<0U)

// WUCR3 Configuration

#define PWR_WUCR3_WUSEL8            (0x3U<<14U)
#define PWR_WUCR3_WUSEL8_0          (0x1U<<14U)
#define PWR_WUCR3_WUSEL7            (0x3U<<12U)
#define PWR_WUCR3_WUSEL7_0          (0x1U<<12U)
#define PWR_WUCR3_WUSEL6            (0x3U<<10U)
#define PWR_WUCR3_WUSEL6_0          (0x1U<<10U)
#define PWR_WUCR3_WUSEL5            (0x3U<<8U)
#define PWR_WUCR3_WUSEL5_0          (0x1U<<8U)
#define PWR_WUCR3_WUSEL4            (0x3U<<6U)
#define PWR_WUCR3_WUSEL4_0          (0x1U<<6U)
#define PWR_WUCR3_WUSEL3            (0x3U<<4U)
#define PWR_WUCR3_WUSEL3_0          (0x1U<<4U)
#define PWR_WUCR3_WUSEL2            (0x3U<<2U)
#define PWR_WUCR3_WUSEL2_0          (0x1U<<2U)
#define PWR_WUCR3_WUSEL1            (0x3U<<0U)
#define PWR_WUCR3_WUSEL1_0          (0x1U<<0U)
#define PWR_WUCR3_WUSEL8_B_0X0      (0x0U<<14U)
#define PWR_WUCR3_WUSEL8_B_0X1      (0x1U<<14U)
#define PWR_WUCR3_WUSEL8_B_0X2      (0x2U<<14U)
#define PWR_WUCR3_WUSEL8_B_0X3      (0x3U<<14U)
#define PWR_WUCR3_WUSEL7_B_0X0      (0x0U<<12U)
#define PWR_WUCR3_WUSEL7_B_0X1      (0x1U<<12U)
#define PWR_WUCR3_WUSEL7_B_0X2      (0x2U<<12U)
#define PWR_WUCR3_WUSEL7_B_0X3      (0x3U<<12U)
#define PWR_WUCR3_WUSEL6_B_0X0      (0x0U<<10U)
#define PWR_WUCR3_WUSEL6_B_0X1      (0x1U<<10U)
#define PWR_WUCR3_WUSEL6_B_0X2      (0x2U<<10U)
#define PWR_WUCR3_WUSEL6_B_0X3      (0x3U<<10U)
#define PWR_WUCR3_WUSEL5_B_0X0      (0x0U<<8U)
#define PWR_WUCR3_WUSEL5_B_0X1      (0x1U<<8U)
#define PWR_WUCR3_WUSEL5_B_0X2      (0x2U<<8U)
#define PWR_WUCR3_WUSEL5_B_0X3      (0x3U<<8U)
#define PWR_WUCR3_WUSEL4_B_0X0      (0x0U<<6U)
#define PWR_WUCR3_WUSEL4_B_0X1      (0x1U<<6U)
#define PWR_WUCR3_WUSEL4_B_0X2      (0x2U<<6U)
#define PWR_WUCR3_WUSEL4_B_0X3      (0x3U<<6U)
#define PWR_WUCR3_WUSEL3_B_0X0      (0x0U<<4U)
#define PWR_WUCR3_WUSEL3_B_0X1      (0x1U<<4U)
#define PWR_WUCR3_WUSEL3_B_0X2      (0x2U<<4U)
#define PWR_WUCR3_WUSEL3_B_0X3      (0x3U<<4U)
#define PWR_WUCR3_WUSEL2_B_0X0      (0x0U<<2U)
#define PWR_WUCR3_WUSEL2_B_0X1      (0x1U<<2U)
#define PWR_WUCR3_WUSEL2_B_0X2      (0x2U<<2U)
#define PWR_WUCR3_WUSEL2_B_0X3      (0x3U<<2U)
#define PWR_WUCR3_WUSEL1_B_0X0      (0x0U<<0U)
#define PWR_WUCR3_WUSEL1_B_0X1      (0x1U<<0U)
#define PWR_WUCR3_WUSEL1_B_0X2      (0x2U<<0U)
#define PWR_WUCR3_WUSEL1_B_0X3      (0x3U<<0U)

// BDCR1 Configuration

#define PWR_BDCR1_MONEN             (0x1U<<4U)
#define PWR_BDCR1_BREN              (0x1U<<0U)
#define PWR_BDCR1_MONEN_B_0X0       (0x0U<<4U)
#define PWR_BDCR1_MONEN_B_0X1       (0x1U<<4U)
#define PWR_BDCR1_BREN_B_0X0        (0x0U<<0U)
#define PWR_BDCR1_BREN_B_0X1        (0x1U<<0U)

// BDCR2 Configuration

#define PWR_BDCR2_VBRS              (0x1U<<1U)
#define PWR_BDCR2_VBE               (0x1U<<0U)
#define PWR_BDCR2_VBRS_B_0X0        (0x0U<<1U)
#define PWR_BDCR2_VBRS_B_0X1        (0x1U<<1U)
#define PWR_BDCR2_VBE_B_0X0         (0x0U<<0U)
#define PWR_BDCR2_VBE_B_0X1         (0x1U<<0U)

// DBPR Configuration

#define PWR_DBPR_DBP                (0x1U<<0U)
#define PWR_DBPR_DBP_B_0X0          (0x0U<<0U)
#define PWR_DBPR_DBP_B_0X1          (0x1U<<0U)

// UCPDR Configuration

#define PWR_UCPDR_UCPD_STBY         (0x1U<<1U)
#define PWR_UCPDR_UCPD_DBDIS        (0x1U<<0U)
#define PWR_UCPDR_UCPD_DBDIS_B_0X0  (0x0U<<0U)
#define PWR_UCPDR_UCPD_DBDIS_B_0X1  (0x1U<<0U)

// SECCFGR Configuration

#define PWR_SECCFGR_APCSEC          (0x1U<<15U)
#define PWR_SECCFGR_VBSEC           (0x1U<<14U)
#define PWR_SECCFGR_VDMSEC          (0x1U<<13U)
#define PWR_SECCFGR_LPMSEC          (0x1U<<12U)
#define PWR_SECCFGR_WUP8SEC         (0x1U<<7U)
#define PWR_SECCFGR_WUP7SEC         (0x1U<<6U)
#define PWR_SECCFGR_WUP6SEC         (0x1U<<5U)
#define PWR_SECCFGR_WUP5SEC         (0x1U<<4U)
#define PWR_SECCFGR_WUP4SEC         (0x1U<<3U)
#define PWR_SECCFGR_WUP3SEC         (0x1U<<2U)
#define PWR_SECCFGR_WUP2SEC         (0x1U<<1U)
#define PWR_SECCFGR_WUP1SEC         (0x1U<<0U)
#define PWR_SECCFGR_APCSEC_B_0X0    (0x0U<<15U)
#define PWR_SECCFGR_APCSEC_B_0X1    (0x1U<<15U)
#define PWR_SECCFGR_VBSEC_B_0X0     (0x0U<<14U)
#define PWR_SECCFGR_VBSEC_B_0X1     (0x1U<<14U)
#define PWR_SECCFGR_VDMSEC_B_0X0    (0x0U<<13U)
#define PWR_SECCFGR_VDMSEC_B_0X1    (0x1U<<13U)
#define PWR_SECCFGR_LPMSEC_B_0X0    (0x0U<<12U)
#define PWR_SECCFGR_LPMSEC_B_0X1    (0x1U<<12U)
#define PWR_SECCFGR_WUP8SEC_B_0X0   (0x0U<<7U)
#define PWR_SECCFGR_WUP8SEC_B_0X1   (0x1U<<7U)
#define PWR_SECCFGR_WUP7SEC_B_0X0   (0x0U<<6U)
#define PWR_SECCFGR_WUP7SEC_B_0X1   (0x1U<<6U)
#define PWR_SECCFGR_WUP6SEC_B_0X0   (0x0U<<5U)
#define PWR_SECCFGR_WUP6SEC_B_0X1   (0x1U<<5U)
#define PWR_SECCFGR_WUP5SEC_B_0X0   (0x0U<<4U)
#define PWR_SECCFGR_WUP5SEC_B_0X1   (0x1U<<4U)
#define PWR_SECCFGR_WUP4SEC_B_0X0   (0x0U<<3U)
#define PWR_SECCFGR_WUP4SEC_B_0X1   (0x1U<<3U)
#define PWR_SECCFGR_WUP3SEC_B_0X0   (0x0U<<2U)
#define PWR_SECCFGR_WUP3SEC_B_0X1   (0x1U<<2U)
#define PWR_SECCFGR_WUP2SEC_B_0X0   (0x0U<<1U)
#define PWR_SECCFGR_WUP2SEC_B_0X1   (0x1U<<1U)
#define PWR_SECCFGR_WUP1SEC_B_0X0   (0x0U<<0U)
#define PWR_SECCFGR_WUP1SEC_B_0X1   (0x1U<<0U)

// PRIVCFGR Configuration

#define PWR_PRIVCFGR_NSPRIV         (0x1U<<1U)
#define PWR_PRIVCFGR_SPRIV          (0x1U<<0U)
#define PWR_PRIVCFGR_NSPRIV_B_0X0   (0x0U<<1U)
#define PWR_PRIVCFGR_NSPRIV_B_0X1   (0x1U<<1U)
#define PWR_PRIVCFGR_SPRIV_B_0X0    (0x0U<<0U)
#define PWR_PRIVCFGR_SPRIV_B_0X1    (0x1U<<0U)

// SR Configuration

#define PWR_SR_SBF                  (0x1U<<2U)
#define PWR_SR_STOPF                (0x1U<<1U)
#define PWR_SR_CSSF                 (0x1U<<0U)
#define PWR_SR_SBF_B_0X0            (0x0U<<2U)
#define PWR_SR_SBF_B_0X1            (0x1U<<2U)
#define PWR_SR_STOPF_B_0X0          (0x0U<<1U)
#define PWR_SR_STOPF_B_0X1          (0x1U<<1U)

// SVMSR Configuration

#define PWR_SVMSR_VDDA2RDY          (0x1U<<27U)
#define PWR_SVMSR_VDDA1RDY          (0x1U<<26U)
#define PWR_SVMSR_VDDIO2RDY         (0x1U<<25U)
#define PWR_SVMSR_VDDUSBRDY         (0x1U<<24U)
#define PWR_SVMSR_ACTVOS            (0x3U<<16U)
#define PWR_SVMSR_ACTVOS_0          (0x1U<<16U)
#define PWR_SVMSR_ACTVOSRDY         (0x1U<<15U)
#define PWR_SVMSR_PVDO              (0x1U<<4U)
#define PWR_SVMSR_REGS              (0x1U<<1U)
#define PWR_SVMSR_VDDA2RDY_B_0X0    (0x0U<<27U)
#define PWR_SVMSR_VDDA2RDY_B_0X1    (0x1U<<27U)
#define PWR_SVMSR_VDDA1RDY_B_0X0    (0x0U<<26U)
#define PWR_SVMSR_VDDA1RDY_B_0X1    (0x1U<<26U)
#define PWR_SVMSR_VDDIO2RDY_B_0X0   (0x0U<<25U)
#define PWR_SVMSR_VDDIO2RDY_B_0X1   (0x1U<<25U)
#define PWR_SVMSR_VDDUSBRDY_B_0X0   (0x0U<<24U)
#define PWR_SVMSR_VDDUSBRDY_B_0X1   (0x1U<<24U)
#define PWR_SVMSR_ACTVOS_B_0X0      (0x0U<<16U)
#define PWR_SVMSR_ACTVOS_B_0X1      (0x1U<<16U)
#define PWR_SVMSR_ACTVOS_B_0X2      (0x2U<<16U)
#define PWR_SVMSR_ACTVOS_B_0X3      (0x3U<<16U)
#define PWR_SVMSR_ACTVOSRDY_B_0X0   (0x0U<<15U)
#define PWR_SVMSR_ACTVOSRDY_B_0X1   (0x1U<<15U)
#define PWR_SVMSR_PVDO_B_0X0        (0x0U<<4U)
#define PWR_SVMSR_PVDO_B_0X1        (0x1U<<4U)
#define PWR_SVMSR_REGS_B_0X0        (0x0U<<1U)
#define PWR_SVMSR_REGS_B_0X1        (0x1U<<1U)

// BDSR Configuration

#define PWR_BDSR_TEMPH              (0x1U<<3U)
#define PWR_BDSR_TEMPL              (0x1U<<2U)
#define PWR_BDSR_VBATH              (0x1U<<1U)
#define PWR_BDSR_TEMPH_B_0X0        (0x0U<<3U)
#define PWR_BDSR_TEMPH_B_0X1        (0x1U<<3U)
#define PWR_BDSR_TEMPL_B_0X0        (0x0U<<2U)
#define PWR_BDSR_TEMPL_B_0X1        (0x1U<<2U)
#define PWR_BDSR_VBATH_B_0X0        (0x0U<<1U)
#define PWR_BDSR_VBATH_B_0X1        (0x1U<<1U)

// WUSR Configuration

#define PWR_WUSR_WUF8               (0x1U<<7U)
#define PWR_WUSR_WUF7               (0x1U<<6U)
#define PWR_WUSR_WUF6               (0x1U<<5U)
#define PWR_WUSR_WUF5               (0x1U<<4U)
#define PWR_WUSR_WUF4               (0x1U<<3U)
#define PWR_WUSR_WUF3               (0x1U<<2U)
#define PWR_WUSR_WUF2               (0x1U<<1U)
#define PWR_WUSR_WUF1               (0x1U<<0U)

// WUSCR Configuration

#define PWR_WUSCR_CWUF8             (0x1U<<7U)
#define PWR_WUSCR_CWUF7             (0x1U<<6U)
#define PWR_WUSCR_CWUF6             (0x1U<<5U)
#define PWR_WUSCR_CWUF5             (0x1U<<4U)
#define PWR_WUSCR_CWUF4             (0x1U<<3U)
#define PWR_WUSCR_CWUF3             (0x1U<<2U)
#define PWR_WUSCR_CWUF2             (0x1U<<1U)
#define PWR_WUSCR_CWUF1             (0x1U<<0U)

// APCR Configuration

#define PWR_APCR_APC                (0x1U<<0U)

// PUCRA Configuration

#define PWR_PUCRA_PU15              (0x1U<<15U)
#define PWR_PUCRA_PU13              (0x1U<<13U)
#define PWR_PUCRA_PU12              (0x1U<<12U)
#define PWR_PUCRA_PU11              (0x1U<<11U)
#define PWR_PUCRA_PU10              (0x1U<<10U)
#define PWR_PUCRA_PU9               (0x1U<<9U)
#define PWR_PUCRA_PU8               (0x1U<<8U)
#define PWR_PUCRA_PU7               (0x1U<<7U)
#define PWR_PUCRA_PU6               (0x1U<<6U)
#define PWR_PUCRA_PU5               (0x1U<<5U)
#define PWR_PUCRA_PU4               (0x1U<<4U)
#define PWR_PUCRA_PU3               (0x1U<<3U)
#define PWR_PUCRA_PU2               (0x1U<<2U)
#define PWR_PUCRA_PU1               (0x1U<<1U)
#define PWR_PUCRA_PU0               (0x1U<<0U)

// PDCRA Configuration

#define PWR_PDCRA_PD14              (0x1U<<14U)
#define PWR_PDCRA_PD12              (0x1U<<12U)
#define PWR_PDCRA_PD11              (0x1U<<11U)
#define PWR_PDCRA_PD10              (0x1U<<10U)
#define PWR_PDCRA_PD9               (0x1U<<9U)
#define PWR_PDCRA_PD8               (0x1U<<8U)
#define PWR_PDCRA_PD7               (0x1U<<7U)
#define PWR_PDCRA_PD6               (0x1U<<6U)
#define PWR_PDCRA_PD5               (0x1U<<5U)
#define PWR_PDCRA_PD4               (0x1U<<4U)
#define PWR_PDCRA_PD3               (0x1U<<3U)
#define PWR_PDCRA_PD2               (0x1U<<2U)
#define PWR_PDCRA_PD1               (0x1U<<1U)
#define PWR_PDCRA_PD0               (0x1U<<0U)

// PUCRB Configuration

#define PWR_PUCRB_PU15              (0x1U<<15U)
#define PWR_PUCRB_PU14              (0x1U<<14U)
#define PWR_PUCRB_PU13              (0x1U<<13U)
#define PWR_PUCRB_PU12              (0x1U<<12U)
#define PWR_PUCRB_PU11              (0x1U<<11U)
#define PWR_PUCRB_PU10              (0x1U<<10U)
#define PWR_PUCRB_PU9               (0x1U<<9U)
#define PWR_PUCRB_PU8               (0x1U<<8U)
#define PWR_PUCRB_PU7               (0x1U<<7U)
#define PWR_PUCRB_PU6               (0x1U<<6U)
#define PWR_PUCRB_PU5               (0x1U<<5U)
#define PWR_PUCRB_PU4               (0x1U<<4U)
#define PWR_PUCRB_PU3               (0x1U<<3U)
#define PWR_PUCRB_PU2               (0x1U<<2U)
#define PWR_PUCRB_PU1               (0x1U<<1U)
#define PWR_PUCRB_PU0               (0x1U<<0U)

// PDCRB Configuration

#define PWR_PDCRB_PD15              (0x1U<<15U)
#define PWR_PDCRB_PD14              (0x1U<<14U)
#define PWR_PDCRB_PD13              (0x1U<<13U)
#define PWR_PDCRB_PD12              (0x1U<<12U)
#define PWR_PDCRB_PD11              (0x1U<<11U)
#define PWR_PDCRB_PD10              (0x1U<<10U)
#define PWR_PDCRB_PD9               (0x1U<<9U)
#define PWR_PDCRB_PD8               (0x1U<<8U)
#define PWR_PDCRB_PD7               (0x1U<<7U)
#define PWR_PDCRB_PD6               (0x1U<<6U)
#define PWR_PDCRB_PD5               (0x1U<<5U)
#define PWR_PDCRB_PD3               (0x1U<<3U)
#define PWR_PDCRB_PD2               (0x1U<<2U)
#define PWR_PDCRB_PD1               (0x1U<<1U)
#define PWR_PDCRB_PD0               (0x1U<<0U)

// PUCRC Configuration

#define PWR_PUCRC_PU15              (0x1U<<15U)
#define PWR_PUCRC_PU14              (0x1U<<14U)
#define PWR_PUCRC_PU13              (0x1U<<13U)
#define PWR_PUCRC_PU12              (0x1U<<12U)
#define PWR_PUCRC_PU11              (0x1U<<11U)
#define PWR_PUCRC_PU10              (0x1U<<10U)
#define PWR_PUCRC_PU9               (0x1U<<9U)
#define PWR_PUCRC_PU8               (0x1U<<8U)
#define PWR_PUCRC_PU7               (0x1U<<7U)
#define PWR_PUCRC_PU6               (0x1U<<6U)
#define PWR_PUCRC_PU5               (0x1U<<5U)
#define PWR_PUCRC_PU4               (0x1U<<4U)
#define PWR_PUCRC_PU3               (0x1U<<3U)
#define PWR_PUCRC_PU2               (0x1U<<2U)
#define PWR_PUCRC_PU1               (0x1U<<1U)
#define PWR_PUCRC_PU0               (0x1U<<0U)

// PDCRC Configuration

#define PWR_PDCRC_PD15              (0x1U<<15U)
#define PWR_PDCRC_PD14              (0x1U<<14U)
#define PWR_PDCRC_PD13              (0x1U<<13U)
#define PWR_PDCRC_PD12              (0x1U<<12U)
#define PWR_PDCRC_PD11              (0x1U<<11U)
#define PWR_PDCRC_PD10              (0x1U<<10U)
#define PWR_PDCRC_PD9               (0x1U<<9U)
#define PWR_PDCRC_PD8               (0x1U<<8U)
#define PWR_PDCRC_PD7               (0x1U<<7U)
#define PWR_PDCRC_PD6               (0x1U<<6U)
#define PWR_PDCRC_PD5               (0x1U<<5U)
#define PWR_PDCRC_PD4               (0x1U<<4U)
#define PWR_PDCRC_PD3               (0x1U<<3U)
#define PWR_PDCRC_PD2               (0x1U<<2U)
#define PWR_PDCRC_PD1               (0x1U<<1U)
#define PWR_PDCRC_PD0               (0x1U<<0U)

// PUCRD Configuration

#define PWR_PUCRD_PU15              (0x1U<<15U)
#define PWR_PUCRD_PU14              (0x1U<<14U)
#define PWR_PUCRD_PU13              (0x1U<<13U)
#define PWR_PUCRD_PU12              (0x1U<<12U)
#define PWR_PUCRD_PU11              (0x1U<<11U)
#define PWR_PUCRD_PU10              (0x1U<<10U)
#define PWR_PUCRD_PU9               (0x1U<<9U)
#define PWR_PUCRD_PU8               (0x1U<<8U)
#define PWR_PUCRD_PU7               (0x1U<<7U)
#define PWR_PUCRD_PU6               (0x1U<<6U)
#define PWR_PUCRD_PU5               (0x1U<<5U)
#define PWR_PUCRD_PU4               (0x1U<<4U)
#define PWR_PUCRD_PU3               (0x1U<<3U)
#define PWR_PUCRD_PU2               (0x1U<<2U)
#define PWR_PUCRD_PU1               (0x1U<<1U)
#define PWR_PUCRD_PU0               (0x1U<<0U)

// PDCRD Configuration

#define PWR_PDCRD_PD15              (0x1U<<15U)
#define PWR_PDCRD_PD14              (0x1U<<14U)
#define PWR_PDCRD_PD13              (0x1U<<13U)
#define PWR_PDCRD_PD12              (0x1U<<12U)
#define PWR_PDCRD_PD11              (0x1U<<11U)
#define PWR_PDCRD_PD10              (0x1U<<10U)
#define PWR_PDCRD_PD9               (0x1U<<9U)
#define PWR_PDCRD_PD8               (0x1U<<8U)
#define PWR_PDCRD_PD7               (0x1U<<7U)
#define PWR_PDCRD_PD6               (0x1U<<6U)
#define PWR_PDCRD_PD5               (0x1U<<5U)
#define PWR_PDCRD_PD4               (0x1U<<4U)
#define PWR_PDCRD_PD3               (0x1U<<3U)
#define PWR_PDCRD_PD2               (0x1U<<2U)
#define PWR_PDCRD_PD1               (0x1U<<1U)
#define PWR_PDCRD_PD0               (0x1U<<0U)

// PUCRE Configuration

#define PWR_PUCRE_PU15              (0x1U<<15U)
#define PWR_PUCRE_PU14              (0x1U<<14U)
#define PWR_PUCRE_PU13              (0x1U<<13U)
#define PWR_PUCRE_PU12              (0x1U<<12U)
#define PWR_PUCRE_PU11              (0x1U<<11U)
#define PWR_PUCRE_PU10              (0x1U<<10U)
#define PWR_PUCRE_PU9               (0x1U<<9U)
#define PWR_PUCRE_PU8               (0x1U<<8U)
#define PWR_PUCRE_PU7               (0x1U<<7U)
#define PWR_PUCRE_PU6               (0x1U<<6U)
#define PWR_PUCRE_PU5               (0x1U<<5U)
#define PWR_PUCRE_PU4               (0x1U<<4U)
#define PWR_PUCRE_PU3               (0x1U<<3U)
#define PWR_PUCRE_PU2               (0x1U<<2U)
#define PWR_PUCRE_PU1               (0x1U<<1U)
#define PWR_PUCRE_PU0               (0x1U<<0U)

// PDCRE Configuration

#define PWR_PDCRE_PD15              (0x1U<<15U)
#define PWR_PDCRE_PD14              (0x1U<<14U)
#define PWR_PDCRE_PD13              (0x1U<<13U)
#define PWR_PDCRE_PD12              (0x1U<<12U)
#define PWR_PDCRE_PD11              (0x1U<<11U)
#define PWR_PDCRE_PD10              (0x1U<<10U)
#define PWR_PDCRE_PD9               (0x1U<<9U)
#define PWR_PDCRE_PD8               (0x1U<<8U)
#define PWR_PDCRE_PD7               (0x1U<<7U)
#define PWR_PDCRE_PD6               (0x1U<<6U)
#define PWR_PDCRE_PD5               (0x1U<<5U)
#define PWR_PDCRE_PD4               (0x1U<<4U)
#define PWR_PDCRE_PD3               (0x1U<<3U)
#define PWR_PDCRE_PD2               (0x1U<<2U)
#define PWR_PDCRE_PD1               (0x1U<<1U)
#define PWR_PDCRE_PD0               (0x1U<<0U)

// PUCRF Configuration

#define PWR_PUCRF_PU15              (0x1U<<15U)
#define PWR_PUCRF_PU14              (0x1U<<14U)
#define PWR_PUCRF_PU13              (0x1U<<13U)
#define PWR_PUCRF_PU12              (0x1U<<12U)
#define PWR_PUCRF_PU11              (0x1U<<11U)
#define PWR_PUCRF_PU10              (0x1U<<10U)
#define PWR_PUCRF_PU9               (0x1U<<9U)
#define PWR_PUCRF_PU8               (0x1U<<8U)
#define PWR_PUCRF_PU7               (0x1U<<7U)
#define PWR_PUCRF_PU6               (0x1U<<6U)
#define PWR_PUCRF_PU5               (0x1U<<5U)
#define PWR_PUCRF_PU4               (0x1U<<4U)
#define PWR_PUCRF_PU3               (0x1U<<3U)
#define PWR_PUCRF_PU2               (0x1U<<2U)
#define PWR_PUCRF_PU1               (0x1U<<1U)
#define PWR_PUCRF_PU0               (0x1U<<0U)

// PDCRF Configuration

#define PWR_PDCRF_PD15              (0x1U<<15U)
#define PWR_PDCRF_PD14              (0x1U<<14U)
#define PWR_PDCRF_PD13              (0x1U<<13U)
#define PWR_PDCRF_PD12              (0x1U<<12U)
#define PWR_PDCRF_PD11              (0x1U<<11U)
#define PWR_PDCRF_PD10              (0x1U<<10U)
#define PWR_PDCRF_PD9               (0x1U<<9U)
#define PWR_PDCRF_PD8               (0x1U<<8U)
#define PWR_PDCRF_PD7               (0x1U<<7U)
#define PWR_PDCRF_PD6               (0x1U<<6U)
#define PWR_PDCRF_PD5               (0x1U<<5U)
#define PWR_PDCRF_PD4               (0x1U<<4U)
#define PWR_PDCRF_PD3               (0x1U<<3U)
#define PWR_PDCRF_PD2               (0x1U<<2U)
#define PWR_PDCRF_PD1               (0x1U<<1U)
#define PWR_PDCRF_PD0               (0x1U<<0U)

// PUCRG Configuration

#define PWR_PUCRG_PU15              (0x1U<<15U)
#define PWR_PUCRG_PU14              (0x1U<<14U)
#define PWR_PUCRG_PU13              (0x1U<<13U)
#define PWR_PUCRG_PU12              (0x1U<<12U)
#define PWR_PUCRG_PU11              (0x1U<<11U)
#define PWR_PUCRG_PU10              (0x1U<<10U)
#define PWR_PUCRG_PU9               (0x1U<<9U)
#define PWR_PUCRG_PU8               (0x1U<<8U)
#define PWR_PUCRG_PU7               (0x1U<<7U)
#define PWR_PUCRG_PU6               (0x1U<<6U)
#define PWR_PUCRG_PU5               (0x1U<<5U)
#define PWR_PUCRG_PU4               (0x1U<<4U)
#define PWR_PUCRG_PU3               (0x1U<<3U)
#define PWR_PUCRG_PU2               (0x1U<<2U)
#define PWR_PUCRG_PU1               (0x1U<<1U)
#define PWR_PUCRG_PU0               (0x1U<<0U)

// PDCRG Configuration

#define PWR_PDCRG_PD15              (0x1U<<15U)
#define PWR_PDCRG_PD14              (0x1U<<14U)
#define PWR_PDCRG_PD13              (0x1U<<13U)
#define PWR_PDCRG_PD12              (0x1U<<12U)
#define PWR_PDCRG_PD11              (0x1U<<11U)
#define PWR_PDCRG_PD10              (0x1U<<10U)
#define PWR_PDCRG_PD9               (0x1U<<9U)
#define PWR_PDCRG_PD8               (0x1U<<8U)
#define PWR_PDCRG_PD7               (0x1U<<7U)
#define PWR_PDCRG_PD6               (0x1U<<6U)
#define PWR_PDCRG_PD5               (0x1U<<5U)
#define PWR_PDCRG_PD4               (0x1U<<4U)
#define PWR_PDCRG_PD3               (0x1U<<3U)
#define PWR_PDCRG_PD2               (0x1U<<2U)
#define PWR_PDCRG_PD1               (0x1U<<1U)
#define PWR_PDCRG_PD0               (0x1U<<0U)

// PUCRH Configuration

#define PWR_PUCRH_PU15              (0x1U<<15U)
#define PWR_PUCRH_PU14              (0x1U<<14U)
#define PWR_PUCRH_PU13              (0x1U<<13U)
#define PWR_PUCRH_PU12              (0x1U<<12U)
#define PWR_PUCRH_PU11              (0x1U<<11U)
#define PWR_PUCRH_PU10              (0x1U<<10U)
#define PWR_PUCRH_PU9               (0x1U<<9U)
#define PWR_PUCRH_PU8               (0x1U<<8U)
#define PWR_PUCRH_PU7               (0x1U<<7U)
#define PWR_PUCRH_PU6               (0x1U<<6U)
#define PWR_PUCRH_PU5               (0x1U<<5U)
#define PWR_PUCRH_PU4               (0x1U<<4U)
#define PWR_PUCRH_PU3               (0x1U<<3U)
#define PWR_PUCRH_PU2               (0x1U<<2U)
#define PWR_PUCRH_PU1               (0x1U<<1U)
#define PWR_PUCRH_PU0               (0x1U<<0U)

// PDCRH Configuration

#define PWR_PDCRH_PD15              (0x1U<<15U)
#define PWR_PDCRH_PD14              (0x1U<<14U)
#define PWR_PDCRH_PD13              (0x1U<<13U)
#define PWR_PDCRH_PD12              (0x1U<<12U)
#define PWR_PDCRH_PD11              (0x1U<<11U)
#define PWR_PDCRH_PD10              (0x1U<<10U)
#define PWR_PDCRH_PD9               (0x1U<<9U)
#define PWR_PDCRH_PD8               (0x1U<<8U)
#define PWR_PDCRH_PD7               (0x1U<<7U)
#define PWR_PDCRH_PD6               (0x1U<<6U)
#define PWR_PDCRH_PD5               (0x1U<<5U)
#define PWR_PDCRH_PD4               (0x1U<<4U)
#define PWR_PDCRH_PD3               (0x1U<<3U)
#define PWR_PDCRH_PD2               (0x1U<<2U)
#define PWR_PDCRH_PD1               (0x1U<<1U)
#define PWR_PDCRH_PD0               (0x1U<<0U)

// PUCRI Configuration

#define PWR_PUCRI_PU15              (0x1U<<15U)
#define PWR_PUCRI_PU14              (0x1U<<14U)
#define PWR_PUCRI_PU13              (0x1U<<13U)
#define PWR_PUCRI_PU12              (0x1U<<12U)
#define PWR_PUCRI_PU11              (0x1U<<11U)
#define PWR_PUCRI_PU10              (0x1U<<10U)
#define PWR_PUCRI_PU9               (0x1U<<9U)
#define PWR_PUCRI_PU8               (0x1U<<8U)
#define PWR_PUCRI_PU7               (0x1U<<7U)
#define PWR_PUCRI_PU6               (0x1U<<6U)
#define PWR_PUCRI_PU5               (0x1U<<5U)
#define PWR_PUCRI_PU4               (0x1U<<4U)
#define PWR_PUCRI_PU3               (0x1U<<3U)
#define PWR_PUCRI_PU2               (0x1U<<2U)
#define PWR_PUCRI_PU1               (0x1U<<1U)
#define PWR_PUCRI_PU0               (0x1U<<0U)

// PDCRI Configuration

#define PWR_PDCRI_PD15              (0x1U<<15U)
#define PWR_PDCRI_PD14              (0x1U<<14U)
#define PWR_PDCRI_PD13              (0x1U<<13U)
#define PWR_PDCRI_PD12              (0x1U<<12U)
#define PWR_PDCRI_PD11              (0x1U<<11U)
#define PWR_PDCRI_PD10              (0x1U<<10U)
#define PWR_PDCRI_PD9               (0x1U<<9U)
#define PWR_PDCRI_PD8               (0x1U<<8U)
#define PWR_PDCRI_PD7               (0x1U<<7U)
#define PWR_PDCRI_PD6               (0x1U<<6U)
#define PWR_PDCRI_PD5               (0x1U<<5U)
#define PWR_PDCRI_PD4               (0x1U<<4U)
#define PWR_PDCRI_PD3               (0x1U<<3U)
#define PWR_PDCRI_PD2               (0x1U<<2U)
#define PWR_PDCRI_PD1               (0x1U<<1U)
#define PWR_PDCRI_PD0               (0x1U<<0U)

// PUCRJ Configuration

#define PWR_PUCRJ_PU11              (0x1U<<11U)
#define PWR_PUCRJ_PU10              (0x1U<<10U)
#define PWR_PUCRJ_PU9               (0x1U<<9U)
#define PWR_PUCRJ_PU8               (0x1U<<8U)
#define PWR_PUCRJ_PU7               (0x1U<<7U)
#define PWR_PUCRJ_PU6               (0x1U<<6U)
#define PWR_PUCRJ_PU5               (0x1U<<5U)
#define PWR_PUCRJ_PU4               (0x1U<<4U)
#define PWR_PUCRJ_PU3               (0x1U<<3U)
#define PWR_PUCRJ_PU2               (0x1U<<2U)
#define PWR_PUCRJ_PU1               (0x1U<<1U)
#define PWR_PUCRJ_PU0               (0x1U<<0U)

// PDCRJ Configuration

#define PWR_PDCRJ_PD11              (0x1U<<11U)
#define PWR_PDCRJ_PD10              (0x1U<<10U)
#define PWR_PDCRJ_PD9               (0x1U<<9U)
#define PWR_PDCRJ_PD8               (0x1U<<8U)
#define PWR_PDCRJ_PD7               (0x1U<<7U)
#define PWR_PDCRJ_PD6               (0x1U<<6U)
#define PWR_PDCRJ_PD5               (0x1U<<5U)
#define PWR_PDCRJ_PD4               (0x1U<<4U)
#define PWR_PDCRJ_PD3               (0x1U<<3U)
#define PWR_PDCRJ_PD2               (0x1U<<2U)
#define PWR_PDCRJ_PD1               (0x1U<<1U)
#define PWR_PDCRJ_PD0               (0x1U<<0U)

// CR4 Configuration

#define PWR_CR4_SRAM5PDS13          (0x1U<<28U)
#define PWR_CR4_SRAM5PDS12          (0x1U<<27U)
#define PWR_CR4_SRAM5PDS11          (0x1U<<26U)
#define PWR_CR4_SRAM5PDS10          (0x1U<<25U)
#define PWR_CR4_SRAM5PDS9           (0x1U<<24U)
#define PWR_CR4_SRAM5PDS8           (0x1U<<23U)
#define PWR_CR4_SRAM5PDS7           (0x1U<<22U)
#define PWR_CR4_SRAM5PDS6           (0x1U<<21U)
#define PWR_CR4_SRAM5PDS5           (0x1U<<20U)
#define PWR_CR4_SRAM5PDS4           (0x1U<<19U)
#define PWR_CR4_SRAM5PDS3           (0x1U<<18U)
#define PWR_CR4_SRAM5PDS2           (0x1U<<17U)
#define PWR_CR4_SRAM5PDS1           (0x1U<<16U)
#define PWR_CR4_SRAM3PDS13          (0x1U<<14U)
#define PWR_CR4_SRAM3PDS12          (0x1U<<13U)
#define PWR_CR4_SRAM3PDS11          (0x1U<<12U)
#define PWR_CR4_SRAM3PDS10          (0x1U<<11U)
#define PWR_CR4_SRAM3PDS9           (0x1U<<10U)
#define PWR_CR4_SRAM1PDS12          (0x1U<<8U)
#define PWR_CR4_SRAM1PDS11          (0x1U<<7U)
#define PWR_CR4_SRAM1PDS10          (0x1U<<6U)
#define PWR_CR4_SRAM1PDS9           (0x1U<<5U)
#define PWR_CR4_SRAM1PDS8           (0x1U<<4U)
#define PWR_CR4_SRAM1PDS7           (0x1U<<3U)
#define PWR_CR4_SRAM1PDS6           (0x1U<<2U)
#define PWR_CR4_SRAM1PDS5           (0x1U<<1U)
#define PWR_CR4_SRAM1PDS4           (0x1U<<0U)
