/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_xspi equates.
 */

#pragma once

#include    <stdint.h>

// XSPI address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    DCR1;
    volatile    uint32_t    DCR2;
    volatile    uint32_t    DCR3;
    volatile    uint32_t    DCR4;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    SR;
    volatile    uint32_t    FCR;
    volatile    uint32_t    RESERVED2[6];
    volatile    uint32_t    DLR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    AR;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    DR;
    volatile    uint32_t    RESERVED5[11];
    volatile    uint32_t    PSMKR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    PSMAR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    PIR;
    volatile    uint32_t    RESERVED8[27];
    volatile    uint32_t    CCR;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    TCR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    IR;
    volatile    uint32_t    RESERVED11[3];
    volatile    uint32_t    ABR;
    volatile    uint32_t    RESERVED12[3];
    volatile    uint32_t    LPTR;
    volatile    uint32_t    RESERVED13[3];
    volatile    uint32_t    WPCCR;
    volatile    uint32_t    RESERVED14;
    volatile    uint32_t    WPTCR;
    volatile    uint32_t    RESERVED15;
    volatile    uint32_t    WPIR;
    volatile    uint32_t    RESERVED16[3];
    volatile    uint32_t    WPABR;
    volatile    uint32_t    RESERVED17[7];
    volatile    uint32_t    WCCR;
    volatile    uint32_t    RESERVED18;
    volatile    uint32_t    WTCR;
    volatile    uint32_t    RESERVED19;
    volatile    uint32_t    WIR;
    volatile    uint32_t    RESERVED20[3];
    volatile    uint32_t    WABR;
    volatile    uint32_t    RESERVED21[23];
    volatile    uint32_t    HLCR;
    volatile    uint32_t    RESERVED22[3];
    volatile    uint32_t    CALFCR;
    volatile    uint32_t    RESERVED23;
    volatile    uint32_t    CALMR;
    volatile    uint32_t    RESERVED24;
    volatile    uint32_t    CALSOR;
    volatile    uint32_t    RESERVED25;
    volatile    uint32_t    CALSIR;
} XSPI_TypeDef;

#ifdef __cplusplus
#define XSPI1_NS    reinterpret_cast<XSPI_TypeDef *>(0x48025000U)
#define XSPI1_S     reinterpret_cast<XSPI_TypeDef *>(0x58025000U)
#define XSPI2_NS    reinterpret_cast<XSPI_TypeDef *>(0x4802A000U)
#define XSPI2_S     reinterpret_cast<XSPI_TypeDef *>(0x5802A000U)
#define XSPI3_NS    reinterpret_cast<XSPI_TypeDef *>(0x4802D000U)
#define XSPI3_S     reinterpret_cast<XSPI_TypeDef *>(0x5802D000U)

#else
#define XSPI1_NS    ((XSPI_TypeDef *)0x48025000U)
#define XSPI1_S     ((XSPI_TypeDef *)0x58025000U)
#define XSPI2_NS    ((XSPI_TypeDef *)0x4802A000U)
#define XSPI2_S     ((XSPI_TypeDef *)0x5802A000U)
#define XSPI3_NS    ((XSPI_TypeDef *)0x4802D000U)
#define XSPI3_S     ((XSPI_TypeDef *)0x5802D000U)
#endif

// CR Configuration

#define XSPI_CR_MSEL                (0x3U<<30U)
#define XSPI_CR_MSEL_0              (0x1U<<30U)
#define XSPI_CR_FMODE               (0x3U<<28U)
#define XSPI_CR_FMODE_0             (0x1U<<28U)
#define XSPI_CR_NOPREF_AXI          (0x1U<<26U)
#define XSPI_CR_NOPREF              (0x1U<<25U)
#define XSPI_CR_CSSEL               (0x1U<<24U)
#define XSPI_CR_PMM                 (0x1U<<23U)
#define XSPI_CR_APMS                (0x1U<<22U)
#define XSPI_CR_TOIE                (0x1U<<20U)
#define XSPI_CR_SMIE                (0x1U<<19U)
#define XSPI_CR_FTIE                (0x1U<<18U)
#define XSPI_CR_TCIE                (0x1U<<17U)
#define XSPI_CR_TEIE                (0x1U<<16U)
#define XSPI_CR_FTHRES              (0x3FU<<8U)
#define XSPI_CR_FTHRES_0            (0x1U<<8U)
#define XSPI_CR_DMM                 (0x1U<<6U)
#define XSPI_CR_TCEN                (0x1U<<3U)
#define XSPI_CR_DMAEN               (0x1U<<2U)
#define XSPI_CR_ABORT               (0x1U<<1U)
#define XSPI_CR_EN                  (0x1U<<0U)

#define XSPI_CR_MSEL_B_0X0          (0x0U<<30U)
#define XSPI_CR_MSEL_B_0X1          (0x1U<<30U)
#define XSPI_CR_MSEL_B_0X2          (0x2U<<30U)
#define XSPI_CR_MSEL_B_0X3          (0x3U<<30U)
#define XSPI_CR_FMODE_B_0X0         (0x0U<<28U)
#define XSPI_CR_FMODE_B_0X1         (0x1U<<28U)
#define XSPI_CR_FMODE_B_0X2         (0x2U<<28U)
#define XSPI_CR_FMODE_B_0X3         (0x3U<<28U)
#define XSPI_CR_NOPREF_AXI_B_0X0    (0x0U<<26U)
#define XSPI_CR_NOPREF_AXI_B_0X1    (0x1U<<26U)
#define XSPI_CR_NOPREF_B_0X0        (0x0U<<25U)
#define XSPI_CR_NOPREF_B_0X1        (0x1U<<25U)
#define XSPI_CR_CSSEL_B_0X0         (0x0U<<24U)
#define XSPI_CR_CSSEL_B_0X1         (0x1U<<24U)
#define XSPI_CR_PMM_B_0X0           (0x0U<<23U)
#define XSPI_CR_PMM_B_0X1           (0x1U<<23U)
#define XSPI_CR_APMS_B_0X0          (0x0U<<22U)
#define XSPI_CR_APMS_B_0X1          (0x1U<<22U)
#define XSPI_CR_TOIE_B_0X0          (0x0U<<20U)
#define XSPI_CR_TOIE_B_0X1          (0x1U<<20U)
#define XSPI_CR_SMIE_B_0X0          (0x0U<<19U)
#define XSPI_CR_SMIE_B_0X1          (0x1U<<19U)
#define XSPI_CR_FTIE_B_0X0          (0x0U<<18U)
#define XSPI_CR_FTIE_B_0X1          (0x1U<<18U)
#define XSPI_CR_TCIE_B_0X0          (0x0U<<17U)
#define XSPI_CR_TCIE_B_0X1          (0x1U<<17U)
#define XSPI_CR_TEIE_B_0X0          (0x0U<<16U)
#define XSPI_CR_TEIE_B_0X1          (0x1U<<16U)
#define XSPI_CR_FTHRES_B_0X0        (0x0U<<8U)
#define XSPI_CR_FTHRES_B_0X1        (0x1U<<8U)
#define XSPI_CR_FTHRES_B_0X3F       (0x3FU<<8U)
#define XSPI_CR_DMM_B_0X0           (0x0U<<6U)
#define XSPI_CR_DMM_B_0X1           (0x1U<<6U)
#define XSPI_CR_TCEN_B_0X0          (0x0U<<3U)
#define XSPI_CR_TCEN_B_0X1          (0x1U<<3U)
#define XSPI_CR_DMAEN_B_0X0         (0x0U<<2U)
#define XSPI_CR_DMAEN_B_0X1         (0x1U<<2U)
#define XSPI_CR_ABORT_B_0X0         (0x0U<<1U)
#define XSPI_CR_ABORT_B_0X1         (0x1U<<1U)
#define XSPI_CR_EN_B_0X0            (0x0U<<0U)
#define XSPI_CR_EN_B_0X1            (0x1U<<0U)

// DCR1 Configuration

#define XSPI_DCR1_MTYP              (0x7U<<24U)
#define XSPI_DCR1_MTYP_0            (0x1U<<24U)
#define XSPI_DCR1_EXTENDMEM         (0x1U<<21U)
#define XSPI_DCR1_DEVSIZE           (0x1FU<<16U)
#define XSPI_DCR1_DEVSIZE_0         (0x1U<<16U)
#define XSPI_DCR1_CSHT              (0x3FU<<8U)
#define XSPI_DCR1_CSHT_0            (0x1U<<8U)
#define XSPI_DCR1_FRCK              (0x1U<<1U)
#define XSPI_DCR1_CKMODE            (0x1U<<0U)

#define XSPI_DCR1_MTYP_B_0X0        (0x0U<<24U)
#define XSPI_DCR1_MTYP_B_0X1        (0x1U<<24U)
#define XSPI_DCR1_MTYP_B_0X2        (0x2U<<24U)
#define XSPI_DCR1_MTYP_B_0X3        (0x3U<<24U)
#define XSPI_DCR1_MTYP_B_0X4        (0x4U<<24U)
#define XSPI_DCR1_MTYP_B_0X5        (0x5U<<24U)
#define XSPI_DCR1_EXTENDMEM_B_0X0   (0x0U<<21U)
#define XSPI_DCR1_EXTENDMEM_B_0X1   (0x1U<<21U)
#define XSPI_DCR1_CSHT_B_0X0        (0x0U<<8U)
#define XSPI_DCR1_CSHT_B_0X1        (0x1U<<8U)
#define XSPI_DCR1_CSHT_B_0X3F       (0x3FU<<8U)
#define XSPI_DCR1_FRCK_B_0X0        (0x0U<<1U)
#define XSPI_DCR1_FRCK_B_0X1        (0x1U<<1U)

// DCR2 Configuration

#define XSPI_DCR2_WRAPSIZE          (0x7U<<16U)
#define XSPI_DCR2_WRAPSIZE_0        (0x1U<<16U)
#define XSPI_DCR2_PRESCALER         (0xFFU<<0U)
#define XSPI_DCR2_PRESCALER_0       (0x1U<<0U)

#define XSPI_DCR2_WRAPSIZE_B_0X0    (0x0U<<16U)
#define XSPI_DCR2_WRAPSIZE_B_0X2    (0x2U<<16U)
#define XSPI_DCR2_WRAPSIZE_B_0X3    (0x3U<<16U)
#define XSPI_DCR2_WRAPSIZE_B_0X4    (0x4U<<16U)
#define XSPI_DCR2_WRAPSIZE_B_0X5    (0x5U<<16U)
#define XSPI_DCR2_PRESCALER_B_0X0   (0x0U<<0U)
#define XSPI_DCR2_PRESCALER_B_0X1   (0x1U<<0U)

// DCR3 Configuration

#define XSPI_DCR3_CSBOUND           (0x1FU<<16U)
#define XSPI_DCR3_CSBOUND_0         (0x1U<<16U)
#define XSPI_DCR3_MAXTRAN           (0xFFU<<0U)
#define XSPI_DCR3_MAXTRAN_0         (0x1U<<0U)

#define XSPI_DCR3_CSBOUND_B_0X0     (0x0U<<16U)
#define XSPI_DCR3_MAXTRAN_B_0X0     (0x0U<<0U)

// DCR4 Configuration

#define XSPI_DCR4_REFRESH           (0xFFFFFFFFU<<0U)
#define XSPI_DCR4_REFRESH_0         (0x1U<<0U)

#define XSPI_DCR4_REFRESH_B_0X0     (0x0U<<0U)

// SR Configuration

#define XSPI_SR_FLEVEL              (0x7FU<<8U)
#define XSPI_SR_FLEVEL_0            (0x1U<<8U)
#define XSPI_SR_BUSY                (0x1U<<5U)
#define XSPI_SR_TOF                 (0x1U<<4U)
#define XSPI_SR_SMF                 (0x1U<<3U)
#define XSPI_SR_FTF                 (0x1U<<2U)
#define XSPI_SR_TCF                 (0x1U<<1U)
#define XSPI_SR_TEF                 (0x1U<<0U)

// FCR Configuration

#define XSPI_FCR_CTOF               (0x1U<<4U)
#define XSPI_FCR_CSMF               (0x1U<<3U)
#define XSPI_FCR_CTCF               (0x1U<<1U)
#define XSPI_FCR_CTEF               (0x1U<<0U)

// DLR Configuration

#define XSPI_DLR_DL                 (0xFFFFFFFFU<<0U)
#define XSPI_DLR_DL_0               (0x1U<<0U)

// AR Configuration

#define XSPI_AR_ADDRESS             (0xFFFFFFFFU<<0U)
#define XSPI_AR_ADDRESS_0           (0x1U<<0U)

// DR Configuration

#define XSPI_DR_DATA                (0xFFFFFFFFU<<0U)
#define XSPI_DR_DATA_0              (0x1U<<0U)

// PSMKR Configuration

#define XSPI_PSMKR_MASK             (0xFFFFFFFFU<<0U)
#define XSPI_PSMKR_MASK_0           (0x1U<<0U)

#define XSPI_PSMKR_MASK_B_0X0       (0x0U<<0U)
#define XSPI_PSMKR_MASK_B_0X1       (0x1U<<0U)

// PSMAR Configuration

#define XSPI_PSMAR_MATCH            (0xFFFFFFFFU<<0U)
#define XSPI_PSMAR_MATCH_0          (0x1U<<0U)

// PIR Configuration

#define XSPI_PIR_INTERVAL           (0xFFFFU<<0U)
#define XSPI_PIR_INTERVAL_0         (0x1U<<0U)

// CCR Configuration

#define XSPI_CCR_DQSE               (0x1U<<29U)
#define XSPI_CCR_DDTR               (0x1U<<27U)
#define XSPI_CCR_DMODE              (0x7U<<24U)
#define XSPI_CCR_DMODE_0            (0x1U<<24U)
#define XSPI_CCR_ABSIZE             (0x3U<<20U)
#define XSPI_CCR_ABSIZE_0           (0x1U<<20U)
#define XSPI_CCR_ABDTR              (0x1U<<19U)
#define XSPI_CCR_ABMODE             (0x7U<<16U)
#define XSPI_CCR_ABMODE_0           (0x1U<<16U)
#define XSPI_CCR_ADSIZE             (0x3U<<12U)
#define XSPI_CCR_ADSIZE_0           (0x1U<<12U)
#define XSPI_CCR_ADDTR              (0x1U<<11U)
#define XSPI_CCR_ADMODE             (0x7U<<8U)
#define XSPI_CCR_ADMODE_0           (0x1U<<8U)
#define XSPI_CCR_ISIZE              (0x3U<<4U)
#define XSPI_CCR_ISIZE_0            (0x1U<<4U)
#define XSPI_CCR_IDTR               (0x1U<<3U)
#define XSPI_CCR_IMODE              (0x7U<<0U)
#define XSPI_CCR_IMODE_0            (0x1U<<0U)

#define XSPI_CCR_DQSE_B_0X0         (0x0U<<29U)
#define XSPI_CCR_DQSE_B_0X1         (0x1U<<29U)
#define XSPI_CCR_DDTR_B_0X0         (0x0U<<27U)
#define XSPI_CCR_DDTR_B_0X1         (0x1U<<27U)
#define XSPI_CCR_DMODE_B_0X0        (0x0U<<24U)
#define XSPI_CCR_DMODE_B_0X1        (0x1U<<24U)
#define XSPI_CCR_DMODE_B_0X2        (0x2U<<24U)
#define XSPI_CCR_DMODE_B_0X3        (0x3U<<24U)
#define XSPI_CCR_DMODE_B_0X4        (0x4U<<24U)
#define XSPI_CCR_DMODE_B_0X5        (0x5U<<24U)
#define XSPI_CCR_ABSIZE_B_0X0       (0x0U<<20U)
#define XSPI_CCR_ABSIZE_B_0X1       (0x1U<<20U)
#define XSPI_CCR_ABSIZE_B_0X2       (0x2U<<20U)
#define XSPI_CCR_ABSIZE_B_0X3       (0x3U<<20U)
#define XSPI_CCR_ABDTR_B_0X0        (0x0U<<19U)
#define XSPI_CCR_ABDTR_B_0X1        (0x1U<<19U)
#define XSPI_CCR_ABMODE_B_0X0       (0x0U<<16U)
#define XSPI_CCR_ABMODE_B_0X1       (0x1U<<16U)
#define XSPI_CCR_ABMODE_B_0X2       (0x2U<<16U)
#define XSPI_CCR_ABMODE_B_0X3       (0x3U<<16U)
#define XSPI_CCR_ADSIZE_B_0X0       (0x0U<<12U)
#define XSPI_CCR_ADSIZE_B_0X1       (0x1U<<12U)
#define XSPI_CCR_ADSIZE_B_0X2       (0x2U<<12U)
#define XSPI_CCR_ADSIZE_B_0X3       (0x3U<<12U)
#define XSPI_CCR_ADDTR_B_0X0        (0x0U<<11U)
#define XSPI_CCR_ADDTR_B_0X1        (0x1U<<11U)
#define XSPI_CCR_ADMODE_B_0X0       (0x0U<<8U)
#define XSPI_CCR_ADMODE_B_0X1       (0x1U<<8U)
#define XSPI_CCR_ADMODE_B_0X2       (0x2U<<8U)
#define XSPI_CCR_ADMODE_B_0X3       (0x3U<<8U)
#define XSPI_CCR_ADMODE_B_0X4       (0x4U<<8U)
#define XSPI_CCR_ISIZE_B_0X0        (0x0U<<4U)
#define XSPI_CCR_ISIZE_B_0X1        (0x1U<<4U)
#define XSPI_CCR_ISIZE_B_0X2        (0x2U<<4U)
#define XSPI_CCR_ISIZE_B_0X3        (0x3U<<4U)
#define XSPI_CCR_IDTR_B_0X0         (0x0U<<3U)
#define XSPI_CCR_IDTR_B_0X1         (0x1U<<3U)
#define XSPI_CCR_IMODE_B_0X0        (0x0U<<0U)
#define XSPI_CCR_IMODE_B_0X1        (0x1U<<0U)
#define XSPI_CCR_IMODE_B_0X2        (0x2U<<0U)
#define XSPI_CCR_IMODE_B_0X3        (0x3U<<0U)
#define XSPI_CCR_IMODE_B_0X4        (0x4U<<0U)

// TCR Configuration

#define XSPI_TCR_SSHIFT             (0x1U<<30U)
#define XSPI_TCR_DHQC               (0x1U<<28U)
#define XSPI_TCR_DCYC               (0x1FU<<0U)
#define XSPI_TCR_DCYC_0             (0x1U<<0U)

#define XSPI_TCR_SSHIFT_B_0X0       (0x0U<<30U)
#define XSPI_TCR_SSHIFT_B_0X1       (0x1U<<30U)
#define XSPI_TCR_DHQC_B_0X0         (0x0U<<28U)
#define XSPI_TCR_DHQC_B_0X1         (0x1U<<28U)

// IR Configuration

#define XSPI_IR_INSTRUCTION         (0xFFFFFFFFU<<0U)
#define XSPI_IR_INSTRUCTION_0       (0x1U<<0U)

// ABR Configuration

#define XSPI_ABR_ALTERNATE          (0xFFFFFFFFU<<0U)
#define XSPI_ABR_ALTERNATE_0        (0x1U<<0U)

// LPTR Configuration

#define XSPI_LPTR_TIMEOUT           (0xFFFFU<<0U)
#define XSPI_LPTR_TIMEOUT_0         (0x1U<<0U)

// WPCCR Configuration

#define XSPI_WPCCR_DQSE             (0x1U<<29U)
#define XSPI_WPCCR_DDTR             (0x1U<<27U)
#define XSPI_WPCCR_DMODE            (0x7U<<24U)
#define XSPI_WPCCR_DMODE_0          (0x1U<<24U)
#define XSPI_WPCCR_ABSIZE           (0x3U<<20U)
#define XSPI_WPCCR_ABSIZE_0         (0x1U<<20U)
#define XSPI_WPCCR_ABDTR            (0x1U<<19U)
#define XSPI_WPCCR_ABMODE           (0x7U<<16U)
#define XSPI_WPCCR_ABMODE_0         (0x1U<<16U)
#define XSPI_WPCCR_ADSIZE           (0x3U<<12U)
#define XSPI_WPCCR_ADSIZE_0         (0x1U<<12U)
#define XSPI_WPCCR_ADDTR            (0x1U<<11U)
#define XSPI_WPCCR_ADMODE           (0x7U<<8U)
#define XSPI_WPCCR_ADMODE_0         (0x1U<<8U)
#define XSPI_WPCCR_ISIZE            (0x3U<<4U)
#define XSPI_WPCCR_ISIZE_0          (0x1U<<4U)
#define XSPI_WPCCR_IDTR             (0x1U<<3U)
#define XSPI_WPCCR_IMODE            (0x7U<<0U)
#define XSPI_WPCCR_IMODE_0          (0x1U<<0U)

#define XSPI_WPCCR_DQSE_B_0X0       (0x0U<<29U)
#define XSPI_WPCCR_DQSE_B_0X1       (0x1U<<29U)
#define XSPI_WPCCR_DDTR_B_0X0       (0x0U<<27U)
#define XSPI_WPCCR_DDTR_B_0X1       (0x1U<<27U)
#define XSPI_WPCCR_DMODE_B_0X0      (0x0U<<24U)
#define XSPI_WPCCR_DMODE_B_0X1      (0x1U<<24U)
#define XSPI_WPCCR_DMODE_B_0X2      (0x2U<<24U)
#define XSPI_WPCCR_DMODE_B_0X3      (0x3U<<24U)
#define XSPI_WPCCR_DMODE_B_0X4      (0x4U<<24U)
#define XSPI_WPCCR_ABSIZE_B_0X0     (0x0U<<20U)
#define XSPI_WPCCR_ABSIZE_B_0X1     (0x1U<<20U)
#define XSPI_WPCCR_ABSIZE_B_0X2     (0x2U<<20U)
#define XSPI_WPCCR_ABSIZE_B_0X3     (0x3U<<20U)
#define XSPI_WPCCR_ABDTR_B_0X0      (0x0U<<19U)
#define XSPI_WPCCR_ABDTR_B_0X1      (0x1U<<19U)
#define XSPI_WPCCR_ABMODE_B_0X0     (0x0U<<16U)
#define XSPI_WPCCR_ABMODE_B_0X1     (0x1U<<16U)
#define XSPI_WPCCR_ABMODE_B_0X2     (0x2U<<16U)
#define XSPI_WPCCR_ABMODE_B_0X3     (0x3U<<16U)
#define XSPI_WPCCR_ABMODE_B_0X4     (0x4U<<16U)
#define XSPI_WPCCR_ABMODE_B_0X5     (0x5U<<16U)
#define XSPI_WPCCR_ADSIZE_B_0X0     (0x0U<<12U)
#define XSPI_WPCCR_ADSIZE_B_0X1     (0x1U<<12U)
#define XSPI_WPCCR_ADSIZE_B_0X2     (0x2U<<12U)
#define XSPI_WPCCR_ADSIZE_B_0X3     (0x3U<<12U)
#define XSPI_WPCCR_ADDTR_B_0X0      (0x0U<<11U)
#define XSPI_WPCCR_ADDTR_B_0X1      (0x1U<<11U)
#define XSPI_WPCCR_ADMODE_B_0X0     (0x0U<<8U)
#define XSPI_WPCCR_ADMODE_B_0X1     (0x1U<<8U)
#define XSPI_WPCCR_ADMODE_B_0X2     (0x2U<<8U)
#define XSPI_WPCCR_ADMODE_B_0X3     (0x3U<<8U)
#define XSPI_WPCCR_ADMODE_B_0X4     (0x4U<<8U)
#define XSPI_WPCCR_ISIZE_B_0X0      (0x0U<<4U)
#define XSPI_WPCCR_ISIZE_B_0X1      (0x1U<<4U)
#define XSPI_WPCCR_ISIZE_B_0X2      (0x2U<<4U)
#define XSPI_WPCCR_ISIZE_B_0X3      (0x3U<<4U)
#define XSPI_WPCCR_IDTR_B_0X0       (0x0U<<3U)
#define XSPI_WPCCR_IDTR_B_0X1       (0x1U<<3U)
#define XSPI_WPCCR_IMODE_B_0X0      (0x0U<<0U)
#define XSPI_WPCCR_IMODE_B_0X1      (0x1U<<0U)
#define XSPI_WPCCR_IMODE_B_0X2      (0x2U<<0U)
#define XSPI_WPCCR_IMODE_B_0X3      (0x3U<<0U)
#define XSPI_WPCCR_IMODE_B_0X4      (0x4U<<0U)

// WPTCR Configuration

#define XSPI_WPTCR_SSHIFT           (0x1U<<30U)
#define XSPI_WPTCR_DHQC             (0x1U<<28U)
#define XSPI_WPTCR_DCYC             (0x1FU<<0U)
#define XSPI_WPTCR_DCYC_0           (0x1U<<0U)

#define XSPI_WPTCR_SSHIFT_B_0X0     (0x0U<<30U)
#define XSPI_WPTCR_SSHIFT_B_0X1     (0x1U<<30U)
#define XSPI_WPTCR_DHQC_B_0X0       (0x0U<<28U)
#define XSPI_WPTCR_DHQC_B_0X1       (0x1U<<28U)

// WPIR Configuration

#define XSPI_WPIR_INSTRUCTION       (0xFFFFFFFFU<<0U)
#define XSPI_WPIR_INSTRUCTION_0     (0x1U<<0U)

// WPABR Configuration

#define XSPI_WPABR_ALTERNATE        (0xFFFFFFFFU<<0U)
#define XSPI_WPABR_ALTERNATE_0      (0x1U<<0U)

// WCCR Configuration

#define XSPI_WCCR_DQSE              (0x1U<<29U)
#define XSPI_WCCR_DDTR              (0x1U<<27U)
#define XSPI_WCCR_DMODE             (0x7U<<24U)
#define XSPI_WCCR_DMODE_0           (0x1U<<24U)
#define XSPI_WCCR_ABSIZE            (0x3U<<20U)
#define XSPI_WCCR_ABSIZE_0          (0x1U<<20U)
#define XSPI_WCCR_ABDTR             (0x1U<<19U)
#define XSPI_WCCR_ABMODE            (0x7U<<16U)
#define XSPI_WCCR_ABMODE_0          (0x1U<<16U)
#define XSPI_WCCR_ADSIZE            (0x3U<<12U)
#define XSPI_WCCR_ADSIZE_0          (0x1U<<12U)
#define XSPI_WCCR_ADDTR             (0x1U<<11U)
#define XSPI_WCCR_ADMODE            (0x7U<<8U)
#define XSPI_WCCR_ADMODE_0          (0x1U<<8U)
#define XSPI_WCCR_ISIZE             (0x3U<<4U)
#define XSPI_WCCR_ISIZE_0           (0x1U<<4U)
#define XSPI_WCCR_IDTR              (0x1U<<3U)
#define XSPI_WCCR_IMODE             (0x7U<<0U)
#define XSPI_WCCR_IMODE_0           (0x1U<<0U)

#define XSPI_WCCR_DQSE_B_0X0        (0x0U<<29U)
#define XSPI_WCCR_DQSE_B_0X1        (0x1U<<29U)
#define XSPI_WCCR_DDTR_B_0X0        (0x0U<<27U)
#define XSPI_WCCR_DDTR_B_0X1        (0x1U<<27U)
#define XSPI_WCCR_DMODE_B_0X0       (0x0U<<24U)
#define XSPI_WCCR_DMODE_B_0X1       (0x1U<<24U)
#define XSPI_WCCR_DMODE_B_0X2       (0x2U<<24U)
#define XSPI_WCCR_DMODE_B_0X3       (0x3U<<24U)
#define XSPI_WCCR_DMODE_B_0X4       (0x4U<<24U)
#define XSPI_WCCR_DMODE_B_0X5       (0x5U<<24U)
#define XSPI_WCCR_ABSIZE_B_0X0      (0x0U<<20U)
#define XSPI_WCCR_ABSIZE_B_0X1      (0x1U<<20U)
#define XSPI_WCCR_ABSIZE_B_0X2      (0x2U<<20U)
#define XSPI_WCCR_ABSIZE_B_0X3      (0x3U<<20U)
#define XSPI_WCCR_ABDTR_B_0X0       (0x0U<<19U)
#define XSPI_WCCR_ABDTR_B_0X1       (0x1U<<19U)
#define XSPI_WCCR_ABMODE_B_0X0      (0x0U<<16U)
#define XSPI_WCCR_ABMODE_B_0X1      (0x1U<<16U)
#define XSPI_WCCR_ABMODE_B_0X2      (0x2U<<16U)
#define XSPI_WCCR_ABMODE_B_0X3      (0x3U<<16U)
#define XSPI_WCCR_ABMODE_B_0X4      (0x4U<<16U)
#define XSPI_WCCR_ADSIZE_B_0X0      (0x0U<<12U)
#define XSPI_WCCR_ADSIZE_B_0X1      (0x1U<<12U)
#define XSPI_WCCR_ADSIZE_B_0X2      (0x2U<<12U)
#define XSPI_WCCR_ADSIZE_B_0X3      (0x3U<<12U)
#define XSPI_WCCR_ADDTR_B_0X0       (0x0U<<11U)
#define XSPI_WCCR_ADDTR_B_0X1       (0x1U<<11U)
#define XSPI_WCCR_ADMODE_B_0X0      (0x0U<<8U)
#define XSPI_WCCR_ADMODE_B_0X1      (0x1U<<8U)
#define XSPI_WCCR_ADMODE_B_0X2      (0x2U<<8U)
#define XSPI_WCCR_ADMODE_B_0X3      (0x3U<<8U)
#define XSPI_WCCR_ADMODE_B_0X4      (0x4U<<8U)
#define XSPI_WCCR_ISIZE_B_0X0       (0x0U<<4U)
#define XSPI_WCCR_ISIZE_B_0X1       (0x1U<<4U)
#define XSPI_WCCR_ISIZE_B_0X2       (0x2U<<4U)
#define XSPI_WCCR_ISIZE_B_0X3       (0x3U<<4U)
#define XSPI_WCCR_IDTR_B_0X0        (0x0U<<3U)
#define XSPI_WCCR_IDTR_B_0X1        (0x1U<<3U)
#define XSPI_WCCR_IMODE_B_0X0       (0x0U<<0U)
#define XSPI_WCCR_IMODE_B_0X1       (0x1U<<0U)
#define XSPI_WCCR_IMODE_B_0X2       (0x2U<<0U)
#define XSPI_WCCR_IMODE_B_0X3       (0x3U<<0U)
#define XSPI_WCCR_IMODE_B_0X4       (0x4U<<0U)

// WTCR Configuration

#define XSPI_WTCR_DCYC              (0x1FU<<0U)
#define XSPI_WTCR_DCYC_0            (0x1U<<0U)

// WIR Configuration

#define XSPI_WIR_INSTRUCTION        (0xFFFFFFFFU<<0U)
#define XSPI_WIR_INSTRUCTION_0      (0x1U<<0U)

// WABR Configuration

#define XSPI_WABR_ALTERNATE         (0xFFFFFFFFU<<0U)
#define XSPI_WABR_ALTERNATE_0       (0x1U<<0U)

// HLCR Configuration

#define XSPI_HLCR_TRWR              (0xFFU<<16U)
#define XSPI_HLCR_TRWR_0            (0x1U<<16U)
#define XSPI_HLCR_TACC              (0xFFU<<8U)
#define XSPI_HLCR_TACC_0            (0x1U<<8U)
#define XSPI_HLCR_WZL               (0x1U<<1U)
#define XSPI_HLCR_LM                (0x1U<<0U)

#define XSPI_HLCR_WZL_B_0X0         (0x0U<<1U)
#define XSPI_HLCR_WZL_B_0X1         (0x1U<<1U)
#define XSPI_HLCR_LM_B_0X0          (0x0U<<0U)
#define XSPI_HLCR_LM_B_0X1          (0x1U<<0U)

// CALFCR Configuration

#define XSPI_CALFCR_CALMAX          (0x1U<<31U)
#define XSPI_CALFCR_COARSE          (0x1FU<<16U)
#define XSPI_CALFCR_COARSE_0        (0x1U<<16U)
#define XSPI_CALFCR_FINE            (0x7FU<<0U)
#define XSPI_CALFCR_FINE_0          (0x1U<<0U)

// CALMR Configuration

#define XSPI_CALMR_COARSE           (0x1FU<<16U)
#define XSPI_CALMR_COARSE_0         (0x1U<<16U)
#define XSPI_CALMR_FINE             (0x7FU<<0U)
#define XSPI_CALMR_FINE_0           (0x1U<<0U)

// CALSOR Configuration

#define XSPI_CALSOR_COARSE          (0x1FU<<16U)
#define XSPI_CALSOR_COARSE_0        (0x1U<<16U)
#define XSPI_CALSOR_FINE            (0x7FU<<0U)
#define XSPI_CALSOR_FINE_0          (0x1U<<0U)

// CALSIR Configuration

#define XSPI_CALSIR_COARSE          (0x1FU<<16U)
#define XSPI_CALSIR_COARSE_0        (0x1U<<16U)
#define XSPI_CALSIR_FINE            (0x7FU<<0U)
#define XSPI_CALSIR_FINE_0          (0x1U<<0U)
