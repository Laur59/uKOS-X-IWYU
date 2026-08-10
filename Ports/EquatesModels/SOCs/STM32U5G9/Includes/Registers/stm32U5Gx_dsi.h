/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_dsi equates.
 */

#pragma once

#include    <stdint.h>

// DSI address definitions
// -----------------------

#ifndef ADDITIONAL_DSI_S
typedef struct {
    volatile    uint32_t    VR;
    volatile    uint32_t    CR;
    volatile    uint32_t    CCR;
    volatile    uint32_t    LVCIDR;
    volatile    uint32_t    LCOLCR;
    volatile    uint32_t    LPCR;
    volatile    uint32_t    LPMCR;
    volatile    uint32_t    RESERVED0[4];
    volatile    uint32_t    PCR;
    volatile    uint32_t    GVCIDR;
    volatile    uint32_t    MCR;
    volatile    uint32_t    VMCR;
    volatile    uint32_t    VPCR;
    volatile    uint32_t    VCCR;
    volatile    uint32_t    VNPCR;
    volatile    uint32_t    VHSACR;
    volatile    uint32_t    VHBPCR;
    volatile    uint32_t    VLCR;
    volatile    uint32_t    VVSACR;
    volatile    uint32_t    VVBPCR;
    volatile    uint32_t    VVFPCR;
    volatile    uint32_t    VVACR;
    volatile    uint32_t    LCCR;
    volatile    uint32_t    CMCR;
    volatile    uint32_t    GHCR;
    volatile    uint32_t    GPDR;
    volatile    uint32_t    GPSR;
    volatile    uint32_t    TCCR0;
    volatile    uint32_t    TCCR1;
    volatile    uint32_t    TCCR2;
    volatile    uint32_t    TCCR3;
    volatile    uint32_t    TCCR4;
    volatile    uint32_t    TCCR5;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CLCR;
    volatile    uint32_t    CLTCR;
    volatile    uint32_t    DLTCR;
    volatile    uint32_t    PCTLR;
    volatile    uint32_t    PCONFR;
    volatile    uint32_t    PUCR;
    volatile    uint32_t    PTTCR;
    volatile    uint32_t    PSR;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    ISR0;
    volatile    uint32_t    ISR1;
    volatile    uint32_t    IER0;
    volatile    uint32_t    IER1;
    volatile    uint32_t    RESERVED3[3];
    volatile    uint32_t    FIR0;
    volatile    uint32_t    FIR1;
    volatile    uint32_t    RESERVED4[5];
    volatile    uint32_t    DLTRCR;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    VSCR;
    volatile    uint32_t    RESERVED6[2];
    volatile    uint32_t    LCVCIDR;
    volatile    uint32_t    LCCCR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    LPMCCR;
    volatile    uint32_t    RESERVED8[7];
    volatile    uint32_t    VMCCR;
    volatile    uint32_t    VPCCR;
    volatile    uint32_t    VCCCR;
    volatile    uint32_t    VNPCCR;
    volatile    uint32_t    VHSACCR;
    volatile    uint32_t    VHBPCCR;
    volatile    uint32_t    VLCCR;
    volatile    uint32_t    VVSACCR;
    volatile    uint32_t    VVBPCCR;
    volatile    uint32_t    VVFPCCR;
    volatile    uint32_t    VVACCR;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    FBSR;
    volatile    uint32_t    RESERVED10[165];
    volatile    uint32_t    WCFGR;
    volatile    uint32_t    WCR;
    volatile    uint32_t    WIER;
    volatile    uint32_t    WISR;
    volatile    uint32_t    WIFCR;
    volatile    uint32_t    RESERVED11;
    volatile    uint32_t    WPCR0;
    volatile    uint32_t    RESERVED12[5];
    volatile    uint32_t    WRPCR;
    volatile    uint32_t    RESERVED13[245];
    volatile    uint32_t    BCFGR;
    volatile    uint32_t    RESERVED14[254];
    volatile    uint32_t    DPCBCR;
    volatile    uint32_t    RESERVED15[11];
    volatile    uint32_t    DPCSRCR;
    volatile    uint32_t    RESERVED16[14];
    volatile    uint32_t    DPDL0BCR;
    volatile    uint32_t    RESERVED17[11];
    volatile    uint32_t    DPDL0SRCR;
    volatile    uint32_t    RESERVED18[25];
    volatile    uint32_t    DPDL1BCR;
    volatile    uint32_t    RESERVED19[11];
    volatile    uint32_t    DPDL1SRCR;
} DSI_TypeDef;

#ifdef __cplusplus
#define DSI_NS  reinterpret_cast<DSI_TypeDef *>(0x40016C00U)
#define DSI_S   reinterpret_cast<DSI_TypeDef *>(0x50016C00U)

#else
#define DSI_NS  ((DSI_TypeDef *)0x40016C00U)
#define DSI_S   ((DSI_TypeDef *)0x50016C00U)
#endif
#endif

// VR Configuration

#define DSI_VR_VERSION              (0xFFFFFFFFU<<0U)
#define DSI_VR_VERSION_0            (0x1U<<0U)

// CR Configuration

#define DSI_CR_EN                   (0x1U<<0U)
#define DSI_CR_EN_B_0X0             (0x0U<<0U)
#define DSI_CR_EN_B_0X1             (0x1U<<0U)

// CCR Configuration

#define DSI_CCR_TOCKDIV             (0xFFU<<8U)
#define DSI_CCR_TOCKDIV_0           (0x1U<<8U)
#define DSI_CCR_TXECKDIV            (0xFFU<<0U)
#define DSI_CCR_TXECKDIV_0          (0x1U<<0U)

// LVCIDR Configuration

#define DSI_LVCIDR_VCID             (0x3U<<0U)
#define DSI_LVCIDR_VCID_0           (0x1U<<0U)

// LCOLCR Configuration

#define DSI_LCOLCR_LPE              (0x1U<<8U)
#define DSI_LCOLCR_COLC             (0xFU<<0U)
#define DSI_LCOLCR_COLC_0           (0x1U<<0U)
#define DSI_LCOLCR_LPE_B_0X0        (0x0U<<8U)
#define DSI_LCOLCR_LPE_B_0X1        (0x1U<<8U)
#define DSI_LCOLCR_COLC_B_0X0       (0x0U<<0U)
#define DSI_LCOLCR_COLC_B_0X1       (0x1U<<0U)
#define DSI_LCOLCR_COLC_B_0X2       (0x2U<<0U)
#define DSI_LCOLCR_COLC_B_0X3       (0x3U<<0U)
#define DSI_LCOLCR_COLC_B_0X4       (0x4U<<0U)
#define DSI_LCOLCR_COLC_B_0X5       (0x5U<<0U)

// LPCR Configuration

#define DSI_LPCR_HSP                (0x1U<<2U)
#define DSI_LPCR_VSP                (0x1U<<1U)
#define DSI_LPCR_DEP                (0x1U<<0U)
#define DSI_LPCR_HSP_B_0X0          (0x0U<<2U)
#define DSI_LPCR_HSP_B_0X1          (0x1U<<2U)
#define DSI_LPCR_VSP_B_0X0          (0x0U<<1U)
#define DSI_LPCR_VSP_B_0X1          (0x1U<<1U)
#define DSI_LPCR_DEP_B_0X0          (0x0U<<0U)
#define DSI_LPCR_DEP_B_0X1          (0x1U<<0U)

// LPMCR Configuration

#define DSI_LPMCR_LPSIZE            (0xFFU<<16U)
#define DSI_LPMCR_LPSIZE_0          (0x1U<<16U)
#define DSI_LPMCR_VLPSIZE           (0xFFU<<0U)
#define DSI_LPMCR_VLPSIZE_0         (0x1U<<0U)

// PCR Configuration

#define DSI_PCR_ETTXLPE             (0x1U<<5U)
#define DSI_PCR_CRCRXE              (0x1U<<4U)
#define DSI_PCR_ECCRXE              (0x1U<<3U)
#define DSI_PCR_BTAE                (0x1U<<2U)
#define DSI_PCR_ETRXE               (0x1U<<1U)
#define DSI_PCR_ETTXE               (0x1U<<0U)
#define DSI_PCR_ETTXLPE_B_0X0       (0x0U<<5U)
#define DSI_PCR_ETTXLPE_B_0X1       (0x1U<<5U)
#define DSI_PCR_CRCRXE_B_0X0        (0x0U<<4U)
#define DSI_PCR_CRCRXE_B_0X1        (0x1U<<4U)
#define DSI_PCR_ECCRXE_B_0X0        (0x0U<<3U)
#define DSI_PCR_ECCRXE_B_0X1        (0x1U<<3U)
#define DSI_PCR_BTAE_B_0X0          (0x0U<<2U)
#define DSI_PCR_BTAE_B_0X1          (0x1U<<2U)
#define DSI_PCR_ETRXE_B_0X0         (0x0U<<1U)
#define DSI_PCR_ETRXE_B_0X1         (0x1U<<1U)
#define DSI_PCR_ETTXE_B_0X0         (0x0U<<0U)
#define DSI_PCR_ETTXE_B_0X1         (0x1U<<0U)

// GVCIDR Configuration

#define DSI_GVCIDR_VCIDTX           (0x3U<<16U)
#define DSI_GVCIDR_VCIDTX_0         (0x1U<<16U)
#define DSI_GVCIDR_VCIDRX           (0x3U<<0U)
#define DSI_GVCIDR_VCIDRX_0         (0x1U<<0U)

// MCR Configuration

#define DSI_MCR_CMDM                (0x1U<<0U)
#define DSI_MCR_CMDM_B_0X0          (0x0U<<0U)
#define DSI_MCR_CMDM_B_0X1          (0x1U<<0U)

// VMCR Configuration

#define DSI_VMCR_PGO                (0x1U<<24U)
#define DSI_VMCR_PGM                (0x1U<<20U)
#define DSI_VMCR_PGE                (0x1U<<16U)
#define DSI_VMCR_LPCE               (0x1U<<15U)
#define DSI_VMCR_FBTAAE             (0x1U<<14U)
#define DSI_VMCR_LPHFPE             (0x1U<<13U)
#define DSI_VMCR_LPHBPE             (0x1U<<12U)
#define DSI_VMCR_LPVAE              (0x1U<<11U)
#define DSI_VMCR_LPVFPE             (0x1U<<10U)
#define DSI_VMCR_LPVBPE             (0x1U<<9U)
#define DSI_VMCR_LPVSAE             (0x1U<<8U)
#define DSI_VMCR_VMT                (0x3U<<0U)
#define DSI_VMCR_VMT_0              (0x1U<<0U)
#define DSI_VMCR_PGO_B_0X0          (0x0U<<24U)
#define DSI_VMCR_PGO_B_0X1          (0x1U<<24U)
#define DSI_VMCR_PGM_B_0X0          (0x0U<<20U)
#define DSI_VMCR_PGM_B_0X1          (0x1U<<20U)
#define DSI_VMCR_PGE_B_0X0          (0x0U<<16U)
#define DSI_VMCR_PGE_B_0X1          (0x1U<<16U)
#define DSI_VMCR_LPCE_B_0X0         (0x0U<<15U)
#define DSI_VMCR_LPCE_B_0X1         (0x1U<<15U)
#define DSI_VMCR_FBTAAE_B_0X0       (0x0U<<14U)
#define DSI_VMCR_FBTAAE_B_0X1       (0x1U<<14U)
#define DSI_VMCR_LPHFPE_B_0X0       (0x0U<<13U)
#define DSI_VMCR_LPHFPE_B_0X1       (0x1U<<13U)
#define DSI_VMCR_LPHBPE_B_0X0       (0x0U<<12U)
#define DSI_VMCR_LPHBPE_B_0X1       (0x1U<<12U)
#define DSI_VMCR_LPVAE_B_0X0        (0x0U<<11U)
#define DSI_VMCR_LPVAE_B_0X1        (0x1U<<11U)
#define DSI_VMCR_LPVFPE_B_0X0       (0x0U<<10U)
#define DSI_VMCR_LPVFPE_B_0X1       (0x1U<<10U)
#define DSI_VMCR_LPVBPE_B_0X0       (0x0U<<9U)
#define DSI_VMCR_LPVBPE_B_0X1       (0x1U<<9U)
#define DSI_VMCR_LPVSAE_B_0X0       (0x0U<<8U)
#define DSI_VMCR_LPVSAE_B_0X1       (0x1U<<8U)
#define DSI_VMCR_VMT_B_0X0          (0x0U<<0U)
#define DSI_VMCR_VMT_B_0X1          (0x1U<<0U)

// VPCR Configuration

#define DSI_VPCR_VPSIZE             (0x3FFFU<<0U)
#define DSI_VPCR_VPSIZE_0           (0x1U<<0U)

// VCCR Configuration

#define DSI_VCCR_NUMC               (0x1FFFU<<0U)
#define DSI_VCCR_NUMC_0             (0x1U<<0U)

// VNPCR Configuration

#define DSI_VNPCR_NPSIZE            (0x1FFFU<<0U)
#define DSI_VNPCR_NPSIZE_0          (0x1U<<0U)

// VHSACR Configuration

#define DSI_VHSACR_HSA              (0xFFFU<<0U)
#define DSI_VHSACR_HSA_0            (0x1U<<0U)

// VHBPCR Configuration

#define DSI_VHBPCR_HBP              (0xFFFU<<0U)
#define DSI_VHBPCR_HBP_0            (0x1U<<0U)

// VLCR Configuration

#define DSI_VLCR_HLINE              (0x7FFFU<<0U)
#define DSI_VLCR_HLINE_0            (0x1U<<0U)

// VVSACR Configuration

#define DSI_VVSACR_VSA              (0x3FFU<<0U)
#define DSI_VVSACR_VSA_0            (0x1U<<0U)

// VVBPCR Configuration

#define DSI_VVBPCR_VBP              (0x3FFU<<0U)
#define DSI_VVBPCR_VBP_0            (0x1U<<0U)

// VVFPCR Configuration

#define DSI_VVFPCR_VFP              (0x3FFU<<0U)
#define DSI_VVFPCR_VFP_0            (0x1U<<0U)

// VVACR Configuration

#define DSI_VVACR_VA                (0x3FFFU<<0U)
#define DSI_VVACR_VA_0              (0x1U<<0U)

// LCCR Configuration

#define DSI_LCCR_CMDSIZE            (0xFFFFU<<0U)
#define DSI_LCCR_CMDSIZE_0          (0x1U<<0U)

// CMCR Configuration

#define DSI_CMCR_MRDPS              (0x1U<<24U)
#define DSI_CMCR_DLWTX              (0x1U<<19U)
#define DSI_CMCR_DSR0TX             (0x1U<<18U)
#define DSI_CMCR_DSW1TX             (0x1U<<17U)
#define DSI_CMCR_DSW0TX             (0x1U<<16U)
#define DSI_CMCR_GLWTX              (0x1U<<14U)
#define DSI_CMCR_GSR2TX             (0x1U<<13U)
#define DSI_CMCR_GSR1TX             (0x1U<<12U)
#define DSI_CMCR_GSR0TX             (0x1U<<11U)
#define DSI_CMCR_GSW2TX             (0x1U<<10U)
#define DSI_CMCR_GSW1TX             (0x1U<<9U)
#define DSI_CMCR_GSW0TX             (0x1U<<8U)
#define DSI_CMCR_ARE                (0x1U<<1U)
#define DSI_CMCR_TEARE              (0x1U<<0U)
#define DSI_CMCR_MRDPS_B_0X0        (0x0U<<24U)
#define DSI_CMCR_MRDPS_B_0X1        (0x1U<<24U)
#define DSI_CMCR_DLWTX_B_0X0        (0x0U<<19U)
#define DSI_CMCR_DLWTX_B_0X1        (0x1U<<19U)
#define DSI_CMCR_DSR0TX_B_0X0       (0x0U<<18U)
#define DSI_CMCR_DSR0TX_B_0X1       (0x1U<<18U)
#define DSI_CMCR_DSW1TX_B_0X0       (0x0U<<17U)
#define DSI_CMCR_DSW1TX_B_0X1       (0x1U<<17U)
#define DSI_CMCR_DSW0TX_B_0X0       (0x0U<<16U)
#define DSI_CMCR_DSW0TX_B_0X1       (0x1U<<16U)
#define DSI_CMCR_GLWTX_B_0X0        (0x0U<<14U)
#define DSI_CMCR_GLWTX_B_0X1        (0x1U<<14U)
#define DSI_CMCR_GSR2TX_B_0X0       (0x0U<<13U)
#define DSI_CMCR_GSR2TX_B_0X1       (0x1U<<13U)
#define DSI_CMCR_GSR1TX_B_0X0       (0x0U<<12U)
#define DSI_CMCR_GSR1TX_B_0X1       (0x1U<<12U)
#define DSI_CMCR_GSR0TX_B_0X0       (0x0U<<11U)
#define DSI_CMCR_GSR0TX_B_0X1       (0x1U<<11U)
#define DSI_CMCR_GSW2TX_B_0X0       (0x0U<<10U)
#define DSI_CMCR_GSW2TX_B_0X1       (0x1U<<10U)
#define DSI_CMCR_GSW1TX_B_0X0       (0x0U<<9U)
#define DSI_CMCR_GSW1TX_B_0X1       (0x1U<<9U)
#define DSI_CMCR_GSW0TX_B_0X0       (0x0U<<8U)
#define DSI_CMCR_GSW0TX_B_0X1       (0x1U<<8U)
#define DSI_CMCR_ARE_B_0X0          (0x0U<<1U)
#define DSI_CMCR_ARE_B_0X1          (0x1U<<1U)
#define DSI_CMCR_TEARE_B_0X0        (0x0U<<0U)
#define DSI_CMCR_TEARE_B_0X1        (0x1U<<0U)

// GHCR Configuration

#define DSI_GHCR_WCMSB              (0xFFU<<16U)
#define DSI_GHCR_WCMSB_0            (0x1U<<16U)
#define DSI_GHCR_WCLSB              (0xFFU<<8U)
#define DSI_GHCR_WCLSB_0            (0x1U<<8U)
#define DSI_GHCR_VCID               (0x3U<<6U)
#define DSI_GHCR_VCID_0             (0x1U<<6U)
#define DSI_GHCR_DT                 (0x3FU<<0U)
#define DSI_GHCR_DT_0               (0x1U<<0U)

// GPDR Configuration

#define DSI_GPDR_DATA4              (0xFFU<<24U)
#define DSI_GPDR_DATA4_0            (0x1U<<24U)
#define DSI_GPDR_DATA3              (0xFFU<<16U)
#define DSI_GPDR_DATA3_0            (0x1U<<16U)
#define DSI_GPDR_DATA2              (0xFFU<<8U)
#define DSI_GPDR_DATA2_0            (0x1U<<8U)
#define DSI_GPDR_DATA1              (0xFFU<<0U)
#define DSI_GPDR_DATA1_0            (0x1U<<0U)

// GPSR Configuration

#define DSI_GPSR_PBF                (0x1U<<19U)
#define DSI_GPSR_PBE                (0x1U<<18U)
#define DSI_GPSR_CMDBF              (0x1U<<17U)
#define DSI_GPSR_CMDBE              (0x1U<<16U)
#define DSI_GPSR_RCB                (0x1U<<6U)
#define DSI_GPSR_PRDFF              (0x1U<<5U)
#define DSI_GPSR_PRDFE              (0x1U<<4U)
#define DSI_GPSR_PWRFF              (0x1U<<3U)
#define DSI_GPSR_PWRFE              (0x1U<<2U)
#define DSI_GPSR_CMDFF              (0x1U<<1U)
#define DSI_GPSR_CMDFE              (0x1U<<0U)
#define DSI_GPSR_PBF_B_0X0          (0x0U<<19U)
#define DSI_GPSR_PBF_B_0X1          (0x1U<<19U)
#define DSI_GPSR_PBE_B_0X0          (0x0U<<18U)
#define DSI_GPSR_PBE_B_0X1          (0x1U<<18U)
#define DSI_GPSR_CMDBF_B_0X0        (0x0U<<17U)
#define DSI_GPSR_CMDBF_B_0X1        (0x1U<<17U)
#define DSI_GPSR_CMDBE_B_0X0        (0x0U<<16U)
#define DSI_GPSR_CMDBE_B_0X1        (0x1U<<16U)
#define DSI_GPSR_RCB_B_0X0          (0x0U<<6U)
#define DSI_GPSR_RCB_B_0X1          (0x1U<<6U)
#define DSI_GPSR_PRDFF_B_0X0        (0x0U<<5U)
#define DSI_GPSR_PRDFF_B_0X1        (0x1U<<5U)
#define DSI_GPSR_PRDFE_B_0X0        (0x0U<<4U)
#define DSI_GPSR_PRDFE_B_0X1        (0x1U<<4U)
#define DSI_GPSR_PWRFF_B_0X0        (0x0U<<3U)
#define DSI_GPSR_PWRFF_B_0X1        (0x1U<<3U)
#define DSI_GPSR_PWRFE_B_0X0        (0x0U<<2U)
#define DSI_GPSR_PWRFE_B_0X1        (0x1U<<2U)
#define DSI_GPSR_CMDFF_B_0X0        (0x0U<<1U)
#define DSI_GPSR_CMDFF_B_0X1        (0x1U<<1U)
#define DSI_GPSR_CMDFE_B_0X0        (0x0U<<0U)
#define DSI_GPSR_CMDFE_B_0X1        (0x1U<<0U)

// TCCR0 Configuration

#define DSI_TCCR0_HSTX_TOCNT        (0xFFFFU<<16U)
#define DSI_TCCR0_HSTX_TOCNT_0      (0x1U<<16U)
#define DSI_TCCR0_LPRX_TOCNT        (0xFFFFU<<0U)
#define DSI_TCCR0_LPRX_TOCNT_0      (0x1U<<0U)

// TCCR1 Configuration

#define DSI_TCCR1_HSRD_TOCNT        (0xFFFFU<<0U)
#define DSI_TCCR1_HSRD_TOCNT_0      (0x1U<<0U)

// TCCR2 Configuration

#define DSI_TCCR2_LPRD_TOCNT        (0xFFFFU<<0U)
#define DSI_TCCR2_LPRD_TOCNT_0      (0x1U<<0U)

// TCCR3 Configuration

#define DSI_TCCR3_PM                (0x1U<<24U)
#define DSI_TCCR3_HSWR_TOCNT        (0xFFFFU<<0U)
#define DSI_TCCR3_HSWR_TOCNT_0      (0x1U<<0U)

// TCCR4 Configuration

#define DSI_TCCR4_LPWR_TOCNT        (0xFFFFU<<0U)
#define DSI_TCCR4_LPWR_TOCNT_0      (0x1U<<0U)

// TCCR5 Configuration

#define DSI_TCCR5_BTA_TOCNT         (0xFFFFU<<0U)
#define DSI_TCCR5_BTA_TOCNT_0       (0x1U<<0U)

// CLCR Configuration

#define DSI_CLCR_ACR                (0x1U<<1U)
#define DSI_CLCR_DPCC               (0x1U<<0U)
#define DSI_CLCR_ACR_B_0X0          (0x0U<<1U)
#define DSI_CLCR_ACR_B_0X1          (0x1U<<1U)
#define DSI_CLCR_DPCC_B_0X0         (0x0U<<0U)
#define DSI_CLCR_DPCC_B_0X1         (0x1U<<0U)

// CLTCR Configuration

#define DSI_CLTCR_HS2LP_TIME        (0x3FFU<<16U)
#define DSI_CLTCR_HS2LP_TIME_0      (0x1U<<16U)
#define DSI_CLTCR_LP2HS_TIME        (0x3FFU<<0U)
#define DSI_CLTCR_LP2HS_TIME_0      (0x1U<<0U)

// DLTCR Configuration

#define DSI_DLTCR_HS2LP_TIME        (0x3FFU<<16U)
#define DSI_DLTCR_HS2LP_TIME_0      (0x1U<<16U)
#define DSI_DLTCR_LP2HS_TIME        (0x3FFU<<0U)
#define DSI_DLTCR_LP2HS_TIME_0      (0x1U<<0U)

// PCTLR Configuration

#define DSI_PCTLR_CKE               (0x1U<<2U)
#define DSI_PCTLR_DEN               (0x1U<<1U)
#define DSI_PCTLR_CKE_B_0X0         (0x0U<<2U)
#define DSI_PCTLR_CKE_B_0X1         (0x1U<<2U)
#define DSI_PCTLR_DEN_B_0X0         (0x0U<<1U)
#define DSI_PCTLR_DEN_B_0X1         (0x1U<<1U)

// PCONFR Configuration

#define DSI_PCONFR_SW_TIME          (0xFFU<<8U)
#define DSI_PCONFR_SW_TIME_0        (0x1U<<8U)
#define DSI_PCONFR_NL               (0x3U<<0U)
#define DSI_PCONFR_NL_0             (0x1U<<0U)
#define DSI_PCONFR_NL_B_0X0         (0x0U<<0U)
#define DSI_PCONFR_NL_B_0X1         (0x1U<<0U)

// PUCR Configuration

#define DSI_PUCR_UEDL               (0x1U<<3U)
#define DSI_PUCR_URDL               (0x1U<<2U)
#define DSI_PUCR_UECL               (0x1U<<1U)
#define DSI_PUCR_URCL               (0x1U<<0U)
#define DSI_PUCR_UEDL_B_0X0         (0x0U<<3U)
#define DSI_PUCR_UEDL_B_0X1         (0x1U<<3U)
#define DSI_PUCR_URDL_B_0X0         (0x0U<<2U)
#define DSI_PUCR_URDL_B_0X1         (0x1U<<2U)
#define DSI_PUCR_UECL_B_0X0         (0x0U<<1U)
#define DSI_PUCR_UECL_B_0X1         (0x1U<<1U)
#define DSI_PUCR_URCL_B_0X0         (0x0U<<0U)
#define DSI_PUCR_URCL_B_0X1         (0x1U<<0U)

// PTTCR Configuration

#define DSI_PTTCR_TX_TRIG           (0xFU<<0U)
#define DSI_PTTCR_TX_TRIG_0         (0x1U<<0U)

// PSR Configuration

#define DSI_PSR_UAN1                (0x1U<<8U)
#define DSI_PSR_PSS1                (0x1U<<7U)
#define DSI_PSR_RUE0                (0x1U<<6U)
#define DSI_PSR_UAN0                (0x1U<<5U)
#define DSI_PSR_PSS0                (0x1U<<4U)
#define DSI_PSR_UANC                (0x1U<<3U)
#define DSI_PSR_PSSC                (0x1U<<2U)
#define DSI_PSR_PD                  (0x1U<<1U)

// ISR0 Configuration

#define DSI_ISR0_PE4                (0x1U<<20U)
#define DSI_ISR0_PE3                (0x1U<<19U)
#define DSI_ISR0_PE2                (0x1U<<18U)
#define DSI_ISR0_PE1                (0x1U<<17U)
#define DSI_ISR0_PE0                (0x1U<<16U)
#define DSI_ISR0_AE15               (0x1U<<15U)
#define DSI_ISR0_AE14               (0x1U<<14U)
#define DSI_ISR0_AE13               (0x1U<<13U)
#define DSI_ISR0_AE12               (0x1U<<12U)
#define DSI_ISR0_AE11               (0x1U<<11U)
#define DSI_ISR0_AE10               (0x1U<<10U)
#define DSI_ISR0_AE9                (0x1U<<9U)
#define DSI_ISR0_AE8                (0x1U<<8U)
#define DSI_ISR0_AE7                (0x1U<<7U)
#define DSI_ISR0_AE6                (0x1U<<6U)
#define DSI_ISR0_AE5                (0x1U<<5U)
#define DSI_ISR0_AE4                (0x1U<<4U)
#define DSI_ISR0_AE3                (0x1U<<3U)
#define DSI_ISR0_AE2                (0x1U<<2U)
#define DSI_ISR0_AE1                (0x1U<<1U)
#define DSI_ISR0_AE0                (0x1U<<0U)

// ISR1 Configuration

#define DSI_ISR1_PBUE               (0x1U<<19U)
#define DSI_ISR1_GPRXE              (0x1U<<12U)
#define DSI_ISR1_GPRDE              (0x1U<<11U)
#define DSI_ISR1_GPTXE              (0x1U<<10U)
#define DSI_ISR1_GPWRE              (0x1U<<9U)
#define DSI_ISR1_GCWRE              (0x1U<<8U)
#define DSI_ISR1_LPWRE              (0x1U<<7U)
#define DSI_ISR1_EOTPE              (0x1U<<6U)
#define DSI_ISR1_PSE                (0x1U<<5U)
#define DSI_ISR1_CRCE               (0x1U<<4U)
#define DSI_ISR1_ECCME              (0x1U<<3U)
#define DSI_ISR1_ECCSE              (0x1U<<2U)
#define DSI_ISR1_TOLPRX             (0x1U<<1U)
#define DSI_ISR1_TOHSTX             (0x1U<<0U)

// IER0 Configuration

#define DSI_IER0_PE4IE              (0x1U<<20U)
#define DSI_IER0_PE3IE              (0x1U<<19U)
#define DSI_IER0_PE2IE              (0x1U<<18U)
#define DSI_IER0_PE1IE              (0x1U<<17U)
#define DSI_IER0_PE0IE              (0x1U<<16U)
#define DSI_IER0_AE15IE             (0x1U<<15U)
#define DSI_IER0_AE14IE             (0x1U<<14U)
#define DSI_IER0_AE13IE             (0x1U<<13U)
#define DSI_IER0_AE12IE             (0x1U<<12U)
#define DSI_IER0_AE11IE             (0x1U<<11U)
#define DSI_IER0_AE10IE             (0x1U<<10U)
#define DSI_IER0_AE9IE              (0x1U<<9U)
#define DSI_IER0_AE8IE              (0x1U<<8U)
#define DSI_IER0_AE7IE              (0x1U<<7U)
#define DSI_IER0_AE6IE              (0x1U<<6U)
#define DSI_IER0_AE5IE              (0x1U<<5U)
#define DSI_IER0_AE4IE              (0x1U<<4U)
#define DSI_IER0_AE3IE              (0x1U<<3U)
#define DSI_IER0_AE2IE              (0x1U<<2U)
#define DSI_IER0_AE1IE              (0x1U<<1U)
#define DSI_IER0_AE0IE              (0x1U<<0U)
#define DSI_IER0_PE4IE_B_0X0        (0x0U<<20U)
#define DSI_IER0_PE4IE_B_0X1        (0x1U<<20U)
#define DSI_IER0_PE3IE_B_0X0        (0x0U<<19U)
#define DSI_IER0_PE3IE_B_0X1        (0x1U<<19U)
#define DSI_IER0_PE2IE_B_0X0        (0x0U<<18U)
#define DSI_IER0_PE2IE_B_0X1        (0x1U<<18U)
#define DSI_IER0_PE1IE_B_0X0        (0x0U<<17U)
#define DSI_IER0_PE1IE_B_0X1        (0x1U<<17U)
#define DSI_IER0_PE0IE_B_0X0        (0x0U<<16U)
#define DSI_IER0_PE0IE_B_0X1        (0x1U<<16U)
#define DSI_IER0_AE15IE_B_0X0       (0x0U<<15U)
#define DSI_IER0_AE15IE_B_0X1       (0x1U<<15U)
#define DSI_IER0_AE14IE_B_0X0       (0x0U<<14U)
#define DSI_IER0_AE14IE_B_0X1       (0x1U<<14U)
#define DSI_IER0_AE13IE_B_0X0       (0x0U<<13U)
#define DSI_IER0_AE13IE_B_0X1       (0x1U<<13U)
#define DSI_IER0_AE12IE_B_0X0       (0x0U<<12U)
#define DSI_IER0_AE12IE_B_0X1       (0x1U<<12U)
#define DSI_IER0_AE11IE_B_0X0       (0x0U<<11U)
#define DSI_IER0_AE11IE_B_0X1       (0x1U<<11U)
#define DSI_IER0_AE10IE_B_0X0       (0x0U<<10U)
#define DSI_IER0_AE10IE_B_0X1       (0x1U<<10U)
#define DSI_IER0_AE9IE_B_0X0        (0x0U<<9U)
#define DSI_IER0_AE9IE_B_0X1        (0x1U<<9U)
#define DSI_IER0_AE8IE_B_0X0        (0x0U<<8U)
#define DSI_IER0_AE8IE_B_0X1        (0x1U<<8U)
#define DSI_IER0_AE7IE_B_0X0        (0x0U<<7U)
#define DSI_IER0_AE7IE_B_0X1        (0x1U<<7U)
#define DSI_IER0_AE6IE_B_0X0        (0x0U<<6U)
#define DSI_IER0_AE6IE_B_0X1        (0x1U<<6U)
#define DSI_IER0_AE5IE_B_0X0        (0x0U<<5U)
#define DSI_IER0_AE5IE_B_0X1        (0x1U<<5U)
#define DSI_IER0_AE4IE_B_0X0        (0x0U<<4U)
#define DSI_IER0_AE4IE_B_0X1        (0x1U<<4U)
#define DSI_IER0_AE3IE_B_0X0        (0x0U<<3U)
#define DSI_IER0_AE3IE_B_0X1        (0x1U<<3U)
#define DSI_IER0_AE2IE_B_0X0        (0x0U<<2U)
#define DSI_IER0_AE2IE_B_0X1        (0x1U<<2U)
#define DSI_IER0_AE1IE_B_0X0        (0x0U<<1U)
#define DSI_IER0_AE1IE_B_0X1        (0x1U<<1U)
#define DSI_IER0_AE0IE_B_0X0        (0x0U<<0U)
#define DSI_IER0_AE0IE_B_0X1        (0x1U<<0U)

// IER1 Configuration

#define DSI_IER1_PBUEIE             (0x1U<<19U)
#define DSI_IER1_GPRXEIE            (0x1U<<12U)
#define DSI_IER1_GPRDEIE            (0x1U<<11U)
#define DSI_IER1_GPTXEIE            (0x1U<<10U)
#define DSI_IER1_GPWREIE            (0x1U<<9U)
#define DSI_IER1_GCWREIE            (0x1U<<8U)
#define DSI_IER1_LPWREIE            (0x1U<<7U)
#define DSI_IER1_EOTPEIE            (0x1U<<6U)
#define DSI_IER1_PSEIE              (0x1U<<5U)
#define DSI_IER1_CRCEIE             (0x1U<<4U)
#define DSI_IER1_ECCMEIE            (0x1U<<3U)
#define DSI_IER1_ECCSEIE            (0x1U<<2U)
#define DSI_IER1_TOLPRXIE           (0x1U<<1U)
#define DSI_IER1_TOHSTXIE           (0x1U<<0U)
#define DSI_IER1_PBUEIE_B_0X0       (0x0U<<19U)
#define DSI_IER1_PBUEIE_B_0X1       (0x1U<<19U)
#define DSI_IER1_GPRXEIE_B_0X0      (0x0U<<12U)
#define DSI_IER1_GPRXEIE_B_0X1      (0x1U<<12U)
#define DSI_IER1_GPRDEIE_B_0X0      (0x0U<<11U)
#define DSI_IER1_GPRDEIE_B_0X1      (0x1U<<11U)
#define DSI_IER1_GPTXEIE_B_0X0      (0x0U<<10U)
#define DSI_IER1_GPTXEIE_B_0X1      (0x1U<<10U)
#define DSI_IER1_GPWREIE_B_0X0      (0x0U<<9U)
#define DSI_IER1_GPWREIE_B_0X1      (0x1U<<9U)
#define DSI_IER1_GCWREIE_B_0X0      (0x0U<<8U)
#define DSI_IER1_GCWREIE_B_0X1      (0x1U<<8U)
#define DSI_IER1_LPWREIE_B_0X0      (0x0U<<7U)
#define DSI_IER1_LPWREIE_B_0X1      (0x1U<<7U)
#define DSI_IER1_EOTPEIE_B_0X0      (0x0U<<6U)
#define DSI_IER1_EOTPEIE_B_0X1      (0x1U<<6U)
#define DSI_IER1_PSEIE_B_0X0        (0x0U<<5U)
#define DSI_IER1_PSEIE_B_0X1        (0x1U<<5U)
#define DSI_IER1_CRCEIE_B_0X0       (0x0U<<4U)
#define DSI_IER1_CRCEIE_B_0X1       (0x1U<<4U)
#define DSI_IER1_ECCMEIE_B_0X0      (0x0U<<3U)
#define DSI_IER1_ECCMEIE_B_0X1      (0x1U<<3U)
#define DSI_IER1_ECCSEIE_B_0X0      (0x0U<<2U)
#define DSI_IER1_ECCSEIE_B_0X1      (0x1U<<2U)
#define DSI_IER1_TOLPRXIE_B_0X0     (0x0U<<1U)
#define DSI_IER1_TOLPRXIE_B_0X1     (0x1U<<1U)
#define DSI_IER1_TOHSTXIE_B_0X0     (0x0U<<0U)
#define DSI_IER1_TOHSTXIE_B_0X1     (0x1U<<0U)

// FIR0 Configuration

#define DSI_FIR0_FPE4               (0x1U<<20U)
#define DSI_FIR0_FPE3               (0x1U<<19U)
#define DSI_FIR0_FPE2               (0x1U<<18U)
#define DSI_FIR0_FPE1               (0x1U<<17U)
#define DSI_FIR0_FPE0               (0x1U<<16U)
#define DSI_FIR0_FAE15              (0x1U<<15U)
#define DSI_FIR0_FAE14              (0x1U<<14U)
#define DSI_FIR0_FAE13              (0x1U<<13U)
#define DSI_FIR0_FAE12              (0x1U<<12U)
#define DSI_FIR0_FAE11              (0x1U<<11U)
#define DSI_FIR0_FAE10              (0x1U<<10U)
#define DSI_FIR0_FAE9               (0x1U<<9U)
#define DSI_FIR0_FAE8               (0x1U<<8U)
#define DSI_FIR0_FAE7               (0x1U<<7U)
#define DSI_FIR0_FAE6               (0x1U<<6U)
#define DSI_FIR0_FAE5               (0x1U<<5U)
#define DSI_FIR0_FAE4               (0x1U<<4U)
#define DSI_FIR0_FAE3               (0x1U<<3U)
#define DSI_FIR0_FAE2               (0x1U<<2U)
#define DSI_FIR0_FAE1               (0x1U<<1U)
#define DSI_FIR0_FAE0               (0x1U<<0U)

// FIR1 Configuration

#define DSI_FIR1_FPBUE              (0x1U<<19U)
#define DSI_FIR1_FGPRXE             (0x1U<<12U)
#define DSI_FIR1_FGPRDE             (0x1U<<11U)
#define DSI_FIR1_FGPTXE             (0x1U<<10U)
#define DSI_FIR1_FGPWRE             (0x1U<<9U)
#define DSI_FIR1_FGCWRE             (0x1U<<8U)
#define DSI_FIR1_FLPWRE             (0x1U<<7U)
#define DSI_FIR1_FEOTPE             (0x1U<<6U)
#define DSI_FIR1_FPSE               (0x1U<<5U)
#define DSI_FIR1_FCRCE              (0x1U<<4U)
#define DSI_FIR1_FECCME             (0x1U<<3U)
#define DSI_FIR1_FECCSE             (0x1U<<2U)
#define DSI_FIR1_FTOLPRX            (0x1U<<1U)
#define DSI_FIR1_FTOHSTX            (0x1U<<0U)

// DLTRCR Configuration

#define DSI_DLTRCR_MRD_TIME         (0x7FFFU<<0U)
#define DSI_DLTRCR_MRD_TIME_0       (0x1U<<0U)

// VSCR Configuration

#define DSI_VSCR_UR                 (0x1U<<8U)
#define DSI_VSCR_EN                 (0x1U<<0U)
#define DSI_VSCR_UR_B_0X0           (0x0U<<8U)
#define DSI_VSCR_UR_B_0X1           (0x1U<<8U)
#define DSI_VSCR_EN_B_0X0           (0x0U<<0U)
#define DSI_VSCR_EN_B_0X1           (0x1U<<0U)

// LCVCIDR Configuration

#define DSI_LCVCIDR_VCID            (0x3U<<0U)
#define DSI_LCVCIDR_VCID_0          (0x1U<<0U)

// LCCCR Configuration

#define DSI_LCCCR_LPE               (0x1U<<8U)
#define DSI_LCCCR_COLC              (0xFU<<0U)
#define DSI_LCCCR_COLC_0            (0x1U<<0U)
#define DSI_LCCCR_LPE_B_0X0         (0x0U<<8U)
#define DSI_LCCCR_LPE_B_0X1         (0x1U<<8U)
#define DSI_LCCCR_COLC_B_0X0        (0x0U<<0U)
#define DSI_LCCCR_COLC_B_0X1        (0x1U<<0U)
#define DSI_LCCCR_COLC_B_0X2        (0x2U<<0U)
#define DSI_LCCCR_COLC_B_0X3        (0x3U<<0U)
#define DSI_LCCCR_COLC_B_0X4        (0x4U<<0U)
#define DSI_LCCCR_COLC_B_0X5        (0x5U<<0U)

// LPMCCR Configuration

#define DSI_LPMCCR_LPSIZE           (0xFFU<<16U)
#define DSI_LPMCCR_LPSIZE_0         (0x1U<<16U)
#define DSI_LPMCCR_VLPSIZE          (0xFFU<<0U)
#define DSI_LPMCCR_VLPSIZE_0        (0x1U<<0U)

// VMCCR Configuration

#define DSI_VMCCR_LPCE              (0x1U<<9U)
#define DSI_VMCCR_FBTAAE            (0x1U<<8U)
#define DSI_VMCCR_LPHFE             (0x1U<<7U)
#define DSI_VMCCR_LPHBPE            (0x1U<<6U)
#define DSI_VMCCR_LPVAE             (0x1U<<5U)
#define DSI_VMCCR_LPVFPE            (0x1U<<4U)
#define DSI_VMCCR_LPVBPE            (0x1U<<3U)
#define DSI_VMCCR_LPVSAE            (0x1U<<2U)
#define DSI_VMCCR_VMT               (0x3U<<0U)
#define DSI_VMCCR_VMT_0             (0x1U<<0U)
#define DSI_VMCCR_LPCE_B_0X0        (0x0U<<9U)
#define DSI_VMCCR_LPCE_B_0X1        (0x1U<<9U)
#define DSI_VMCCR_FBTAAE_B_0X0      (0x0U<<8U)
#define DSI_VMCCR_FBTAAE_B_0X1      (0x1U<<8U)
#define DSI_VMCCR_LPHFE_B_0X0       (0x0U<<7U)
#define DSI_VMCCR_LPHFE_B_0X1       (0x1U<<7U)
#define DSI_VMCCR_LPHBPE_B_0X0      (0x0U<<6U)
#define DSI_VMCCR_LPHBPE_B_0X1      (0x1U<<6U)
#define DSI_VMCCR_LPVAE_B_0X0       (0x0U<<5U)
#define DSI_VMCCR_LPVAE_B_0X1       (0x1U<<5U)
#define DSI_VMCCR_LPVFPE_B_0X0      (0x0U<<4U)
#define DSI_VMCCR_LPVFPE_B_0X1      (0x1U<<4U)
#define DSI_VMCCR_LPVBPE_B_0X0      (0x0U<<3U)
#define DSI_VMCCR_LPVBPE_B_0X1      (0x1U<<3U)
#define DSI_VMCCR_LPVSAE_B_0X0      (0x0U<<2U)
#define DSI_VMCCR_LPVSAE_B_0X1      (0x1U<<2U)
#define DSI_VMCCR_VMT_B_0X0         (0x0U<<0U)
#define DSI_VMCCR_VMT_B_0X1         (0x1U<<0U)

// VPCCR Configuration

#define DSI_VPCCR_VPSIZE            (0x3FFFU<<0U)
#define DSI_VPCCR_VPSIZE_0          (0x1U<<0U)

// VCCCR Configuration

#define DSI_VCCCR_NUMC              (0x1FFFU<<0U)
#define DSI_VCCCR_NUMC_0            (0x1U<<0U)

// VNPCCR Configuration

#define DSI_VNPCCR_NPSIZE           (0x1FFFU<<0U)
#define DSI_VNPCCR_NPSIZE_0         (0x1U<<0U)

// VHSACCR Configuration

#define DSI_VHSACCR_HSA             (0xFFFU<<0U)
#define DSI_VHSACCR_HSA_0           (0x1U<<0U)

// VHBPCCR Configuration

#define DSI_VHBPCCR_HBP             (0xFFFU<<0U)
#define DSI_VHBPCCR_HBP_0           (0x1U<<0U)

// VLCCR Configuration

#define DSI_VLCCR_HLINE             (0x7FFFU<<0U)
#define DSI_VLCCR_HLINE_0           (0x1U<<0U)

// VVSACCR Configuration

#define DSI_VVSACCR_VSA             (0x3FFU<<0U)
#define DSI_VVSACCR_VSA_0           (0x1U<<0U)

// VVBPCCR Configuration

#define DSI_VVBPCCR_VBP             (0x3FFU<<0U)
#define DSI_VVBPCCR_VBP_0           (0x1U<<0U)

// VVFPCCR Configuration

#define DSI_VVFPCCR_VFP             (0x3FFU<<0U)
#define DSI_VVFPCCR_VFP_0           (0x1U<<0U)

// VVACCR Configuration

#define DSI_VVACCR_VA               (0x3FFFU<<0U)
#define DSI_VVACCR_VA_0             (0x1U<<0U)

// FBSR Configuration

#define DSI_FBSR_APBF               (0x1U<<23U)
#define DSI_FBSR_APBE               (0x1U<<22U)
#define DSI_FBSR_ACBF               (0x1U<<21U)
#define DSI_FBSR_ACBE               (0x1U<<20U)
#define DSI_FBSR_VPBF               (0x1U<<17U)
#define DSI_FBSR_VPBE               (0x1U<<16U)
#define DSI_FBSR_APWFF              (0x1U<<7U)
#define DSI_FBSR_APWFE              (0x1U<<6U)
#define DSI_FBSR_ACWFF              (0x1U<<5U)
#define DSI_FBSR_ACWFE              (0x1U<<4U)
#define DSI_FBSR_VPWFF              (0x1U<<3U)
#define DSI_FBSR_VPWFE              (0x1U<<2U)
#define DSI_FBSR_VCWFF              (0x1U<<1U)
#define DSI_FBSR_VCWFE              (0x1U<<0U)
#define DSI_FBSR_APBF_B_0X0         (0x0U<<23U)
#define DSI_FBSR_APBF_B_0X1         (0x1U<<23U)
#define DSI_FBSR_APBE_B_0X0         (0x0U<<22U)
#define DSI_FBSR_APBE_B_0X1         (0x1U<<22U)
#define DSI_FBSR_ACBF_B_0X0         (0x0U<<21U)
#define DSI_FBSR_ACBF_B_0X1         (0x1U<<21U)
#define DSI_FBSR_ACBE_B_0X0         (0x0U<<20U)
#define DSI_FBSR_ACBE_B_0X1         (0x1U<<20U)
#define DSI_FBSR_VPBF_B_0X0         (0x0U<<17U)
#define DSI_FBSR_VPBF_B_0X1         (0x1U<<17U)
#define DSI_FBSR_VPBE_B_0X0         (0x0U<<16U)
#define DSI_FBSR_VPBE_B_0X1         (0x1U<<16U)
#define DSI_FBSR_APWFF_B_0X0        (0x0U<<7U)
#define DSI_FBSR_APWFF_B_0X1        (0x1U<<7U)
#define DSI_FBSR_APWFE_B_0X0        (0x0U<<6U)
#define DSI_FBSR_APWFE_B_0X1        (0x1U<<6U)
#define DSI_FBSR_ACWFF_B_0X0        (0x0U<<5U)
#define DSI_FBSR_ACWFF_B_0X1        (0x1U<<5U)
#define DSI_FBSR_ACWFE_B_0X0        (0x0U<<4U)
#define DSI_FBSR_ACWFE_B_0X1        (0x1U<<4U)
#define DSI_FBSR_VPWFF_B_0X0        (0x0U<<3U)
#define DSI_FBSR_VPWFF_B_0X1        (0x1U<<3U)
#define DSI_FBSR_VPWFE_B_0X0        (0x0U<<2U)
#define DSI_FBSR_VPWFE_B_0X1        (0x1U<<2U)
#define DSI_FBSR_VCWFF_B_0X0        (0x0U<<1U)
#define DSI_FBSR_VCWFF_B_0X1        (0x1U<<1U)
#define DSI_FBSR_VCWFE_B_0X0        (0x0U<<0U)
#define DSI_FBSR_VCWFE_B_0X1        (0x1U<<0U)

// WCFGR Configuration

#define DSI_WCFGR_VSPOL             (0x1U<<7U)
#define DSI_WCFGR_AR                (0x1U<<6U)
#define DSI_WCFGR_TEPOL             (0x1U<<5U)
#define DSI_WCFGR_TESRC             (0x1U<<4U)
#define DSI_WCFGR_COLMUX            (0x7U<<1U)
#define DSI_WCFGR_COLMUX_0          (0x1U<<1U)
#define DSI_WCFGR_DSIM              (0x1U<<0U)
#define DSI_WCFGR_VSPOL_B_0X0       (0x0U<<7U)
#define DSI_WCFGR_VSPOL_B_0X1       (0x1U<<7U)
#define DSI_WCFGR_AR_B_0X0          (0x0U<<6U)
#define DSI_WCFGR_AR_B_0X1          (0x1U<<6U)
#define DSI_WCFGR_TEPOL_B_0X0       (0x0U<<5U)
#define DSI_WCFGR_TEPOL_B_0X1       (0x1U<<5U)
#define DSI_WCFGR_TESRC_B_0X0       (0x0U<<4U)
#define DSI_WCFGR_TESRC_B_0X1       (0x1U<<4U)
#define DSI_WCFGR_COLMUX_B_0X0      (0x0U<<1U)
#define DSI_WCFGR_COLMUX_B_0X1      (0x1U<<1U)
#define DSI_WCFGR_COLMUX_B_0X2      (0x2U<<1U)
#define DSI_WCFGR_COLMUX_B_0X3      (0x3U<<1U)
#define DSI_WCFGR_COLMUX_B_0X4      (0x4U<<1U)
#define DSI_WCFGR_COLMUX_B_0X5      (0x5U<<1U)
#define DSI_WCFGR_DSIM_B_0X0        (0x0U<<0U)
#define DSI_WCFGR_DSIM_B_0X1        (0x1U<<0U)

// WCR Configuration

#define DSI_WCR_DSIEN               (0x1U<<3U)
#define DSI_WCR_LTDCEN              (0x1U<<2U)
#define DSI_WCR_SHTDN               (0x1U<<1U)
#define DSI_WCR_COLM                (0x1U<<0U)
#define DSI_WCR_DSIEN_B_0X0         (0x0U<<3U)
#define DSI_WCR_DSIEN_B_0X1         (0x1U<<3U)
#define DSI_WCR_LTDCEN_B_0X0        (0x0U<<2U)
#define DSI_WCR_LTDCEN_B_0X1        (0x1U<<2U)
#define DSI_WCR_SHTDN_B_0X0         (0x0U<<1U)
#define DSI_WCR_SHTDN_B_0X1         (0x1U<<1U)
#define DSI_WCR_COLM_B_0X0          (0x0U<<0U)
#define DSI_WCR_COLM_B_0X1          (0x1U<<0U)

// WIER Configuration

#define DSI_WIER_PLLUIE             (0x1U<<10U)
#define DSI_WIER_PLLLIE             (0x1U<<9U)
#define DSI_WIER_ERIE               (0x1U<<1U)
#define DSI_WIER_TEIE               (0x1U<<0U)
#define DSI_WIER_PLLUIE_B_0X0       (0x0U<<10U)
#define DSI_WIER_PLLUIE_B_0X1       (0x1U<<10U)
#define DSI_WIER_PLLLIE_B_0X0       (0x0U<<9U)
#define DSI_WIER_PLLLIE_B_0X1       (0x1U<<9U)
#define DSI_WIER_ERIE_B_0X0         (0x0U<<1U)
#define DSI_WIER_ERIE_B_0X1         (0x1U<<1U)
#define DSI_WIER_TEIE_B_0X0         (0x0U<<0U)
#define DSI_WIER_TEIE_B_0X1         (0x1U<<0U)

// WISR Configuration

#define DSI_WISR_PLLUIF             (0x1U<<10U)
#define DSI_WISR_PLLLIF             (0x1U<<9U)
#define DSI_WISR_PLLLS              (0x1U<<8U)
#define DSI_WISR_BUSY               (0x1U<<2U)
#define DSI_WISR_ERIF               (0x1U<<1U)
#define DSI_WISR_TEIF               (0x1U<<0U)
#define DSI_WISR_PLLUIF_B_0X0       (0x0U<<10U)
#define DSI_WISR_PLLUIF_B_0X1       (0x1U<<10U)
#define DSI_WISR_PLLLIF_B_0X0       (0x0U<<9U)
#define DSI_WISR_PLLLIF_B_0X1       (0x1U<<9U)
#define DSI_WISR_PLLLS_B_0X0        (0x0U<<8U)
#define DSI_WISR_PLLLS_B_0X1        (0x1U<<8U)
#define DSI_WISR_BUSY_B_0X0         (0x0U<<2U)
#define DSI_WISR_BUSY_B_0X1         (0x1U<<2U)
#define DSI_WISR_ERIF_B_0X0         (0x0U<<1U)
#define DSI_WISR_ERIF_B_0X1         (0x1U<<1U)
#define DSI_WISR_TEIF_B_0X0         (0x0U<<0U)
#define DSI_WISR_TEIF_B_0X1         (0x1U<<0U)

// WIFCR Configuration

#define DSI_WIFCR_CPLLUIF           (0x1U<<10U)
#define DSI_WIFCR_CPLLLIF           (0x1U<<9U)
#define DSI_WIFCR_CERIF             (0x1U<<1U)
#define DSI_WIFCR_CTEIF             (0x1U<<0U)

// WPCR0 Configuration

#define DSI_WPCR0_FTXSMDL           (0x1U<<13U)
#define DSI_WPCR0_FTXSMCL           (0x1U<<12U)
#define DSI_WPCR0_SWDL1             (0x1U<<8U)
#define DSI_WPCR0_SWDL0             (0x1U<<7U)
#define DSI_WPCR0_SWCL              (0x1U<<6U)
#define DSI_WPCR0_FTXSMDL_B_0X0     (0x0U<<13U)
#define DSI_WPCR0_FTXSMDL_B_0X1     (0x1U<<13U)
#define DSI_WPCR0_FTXSMCL_B_0X0     (0x0U<<12U)
#define DSI_WPCR0_FTXSMCL_B_0X1     (0x1U<<12U)
#define DSI_WPCR0_SWDL1_B_0X0       (0x0U<<8U)
#define DSI_WPCR0_SWDL1_B_0X1       (0x1U<<8U)
#define DSI_WPCR0_SWDL0_B_0X0       (0x0U<<7U)
#define DSI_WPCR0_SWDL0_B_0X1       (0x1U<<7U)
#define DSI_WPCR0_SWCL_B_0X0        (0x0U<<6U)
#define DSI_WPCR0_SWCL_B_0X1        (0x1U<<6U)

// WRPCR Configuration

#define DSI_WRPCR_ODF               (0x1FFU<<20U)
#define DSI_WRPCR_ODF_0             (0x1U<<20U)
#define DSI_WRPCR_IDF               (0x1FFU<<11U)
#define DSI_WRPCR_IDF_0             (0x1U<<11U)
#define DSI_WRPCR_NDIV              (0x1FFU<<2U)
#define DSI_WRPCR_NDIV_0            (0x1U<<2U)
#define DSI_WRPCR_PLLEN             (0x1U<<0U)
#define DSI_WRPCR_ODF_B_0X0         (0x0U<<20U)
#define DSI_WRPCR_ODF_B_0X1         (0x1U<<20U)
#define DSI_WRPCR_IDF_B_0X0         (0x0U<<11U)
#define DSI_WRPCR_IDF_B_0X1         (0x1U<<11U)
#define DSI_WRPCR_NDIV_B_0X0        (0x0U<<2U)
#define DSI_WRPCR_NDIV_B_0X1        (0x1U<<2U)
#define DSI_WRPCR_PLLEN_B_0X0       (0x0U<<0U)
#define DSI_WRPCR_PLLEN_B_0X1       (0x1U<<0U)

// BCFGR Configuration

#define DSI_BCFGR_PWRUP             (0x1U<<6U)
#define DSI_BCFGR_PWRUP_B_0X0       (0x0U<<6U)
#define DSI_BCFGR_PWRUP_B_0X1       (0x1U<<6U)

// DPCBCR Configuration

#define DSI_DPCBCR_BC               (0x1FU<<3U)
#define DSI_DPCBCR_BC_0             (0x1U<<3U)
#define DSI_DPCBCR_BC_B_0X0         (0x0U<<3U)
#define DSI_DPCBCR_BC_B_0X1         (0x1U<<3U)
#define DSI_DPCBCR_BC_B_0X2         (0x2U<<3U)
#define DSI_DPCBCR_BC_B_0X3         (0x3U<<3U)
#define DSI_DPCBCR_BC_B_0X4         (0x4U<<3U)
#define DSI_DPCBCR_BC_B_0X5         (0x5U<<3U)
#define DSI_DPCBCR_BC_B_0X6         (0x6U<<3U)
#define DSI_DPCBCR_BC_B_0X7         (0x7U<<3U)
#define DSI_DPCBCR_BC_B_0X8         (0x8U<<3U)

// DPCSRCR Configuration

#define DSI_DPCSRCR_SRC             (0xFFU<<0U)
#define DSI_DPCSRCR_SRC_0           (0x1U<<0U)
#define DSI_DPCSRCR_SRC_B_0XE       (0xEU<<0U)

// DPDL0BCR Configuration

#define DSI_DPDL0BCR_BC             (0x1FU<<0U)
#define DSI_DPDL0BCR_BC_0           (0x1U<<0U)
#define DSI_DPDL0BCR_BC_B_0X0       (0x0U<<0U)
#define DSI_DPDL0BCR_BC_B_0X1       (0x1U<<0U)
#define DSI_DPDL0BCR_BC_B_0X2       (0x2U<<0U)
#define DSI_DPDL0BCR_BC_B_0X3       (0x3U<<0U)
#define DSI_DPDL0BCR_BC_B_0X4       (0x4U<<0U)
#define DSI_DPDL0BCR_BC_B_0X5       (0x5U<<0U)
#define DSI_DPDL0BCR_BC_B_0X6       (0x6U<<0U)
#define DSI_DPDL0BCR_BC_B_0X7       (0x7U<<0U)
#define DSI_DPDL0BCR_BC_B_0X8       (0x8U<<0U)

// DPDL0SRCR Configuration

#define DSI_DPDL0SRCR_SRC           (0xFFU<<0U)
#define DSI_DPDL0SRCR_SRC_0         (0x1U<<0U)
#define DSI_DPDL0SRCR_SRC_B_0XE     (0xEU<<0U)

// DPDL1BCR Configuration

#define DSI_DPDL1BCR_BC             (0x1FU<<0U)
#define DSI_DPDL1BCR_BC_0           (0x1U<<0U)
#define DSI_DPDL1BCR_BC_B_0X0       (0x0U<<0U)
#define DSI_DPDL1BCR_BC_B_0X1       (0x1U<<0U)
#define DSI_DPDL1BCR_BC_B_0X2       (0x2U<<0U)
#define DSI_DPDL1BCR_BC_B_0X3       (0x3U<<0U)
#define DSI_DPDL1BCR_BC_B_0X4       (0x4U<<0U)
#define DSI_DPDL1BCR_BC_B_0X5       (0x5U<<0U)
#define DSI_DPDL1BCR_BC_B_0X6       (0x6U<<0U)
#define DSI_DPDL1BCR_BC_B_0X7       (0x7U<<0U)
#define DSI_DPDL1BCR_BC_B_0X8       (0x8U<<0U)

// DPDL1SRCR Configuration

#define DSI_DPDL1SRCR_SRC           (0xFFU<<0U)
#define DSI_DPDL1SRCR_SRC_0         (0x1U<<0U)
#define DSI_DPDL1SRCR_SRC_B_0XE     (0xEU<<0U)
