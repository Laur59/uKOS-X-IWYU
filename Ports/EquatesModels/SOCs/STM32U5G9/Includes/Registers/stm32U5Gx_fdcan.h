/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_fdcan equates.
 */

#pragma once

#include    <stdint.h>

// FDCAN address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CREL;
    volatile    uint32_t    ENDN;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    DBTP;
    volatile    uint32_t    TEST;
    volatile    uint32_t    RWD;
    volatile    uint32_t    CCCR;
    volatile    uint32_t    NBTP;
    volatile    uint32_t    TSCC;
    volatile    uint32_t    TSCV;
    volatile    uint32_t    TOCC;
    volatile    uint32_t    TOCV;
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    ECR;
    volatile    uint32_t    PSR;
    volatile    uint32_t    TDCR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    IR;
    volatile    uint32_t    IE;
    volatile    uint32_t    ILS;
    volatile    uint32_t    ILE;
    volatile    uint32_t    RESERVED3[8];
    volatile    uint32_t    RXGFC;
    volatile    uint32_t    XIDAM;
    volatile    uint32_t    HPMS;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    RXF0S;
    volatile    uint32_t    RXF0A;
    volatile    uint32_t    RXF1S;
    volatile    uint32_t    RXF1A;
    volatile    uint32_t    RESERVED5[8];
    volatile    uint32_t    TXBC;
    volatile    uint32_t    TXFQS;
    volatile    uint32_t    TXBRP;
    volatile    uint32_t    TXBAR;
    volatile    uint32_t    TXBCR;
    volatile    uint32_t    TXBTO;
    volatile    uint32_t    TXBCF;
    volatile    uint32_t    TXBTIE;
    volatile    uint32_t    TXBCIE;
    volatile    uint32_t    TXEFS;
    volatile    uint32_t    TXEFA;
    volatile    uint32_t    RESERVED6[5];
    volatile    uint32_t    CKDIV;
} FDCAN_TypeDef;

#ifdef __cplusplus
#define FDCAN1_RAM_NS   reinterpret_cast<FDCAN_TypeDef *>(0x4000AC00U)
#define FDCAN1_RAM_S    reinterpret_cast<FDCAN_TypeDef *>(0x5000AC00U)
#define FDCAN1_NS       reinterpret_cast<FDCAN_TypeDef *>(0x4000A400U)
#define FDCAN1_S        reinterpret_cast<FDCAN_TypeDef *>(0x5000A400U)

#else
#define FDCAN1_RAM_NS   ((FDCAN_TypeDef *)0x4000AC00U)
#define FDCAN1_RAM_S    ((FDCAN_TypeDef *)0x5000AC00U)
#define FDCAN1_NS       ((FDCAN_TypeDef *)0x4000A400U)
#define FDCAN1_S        ((FDCAN_TypeDef *)0x5000A400U)
#endif

// CREL Configuration

#define FDCAN_CREL_DAY          (0xFFU<<0U)
#define FDCAN_CREL_DAY_0        (0x1U<<0U)
#define FDCAN_CREL_MON          (0xFFU<<8U)
#define FDCAN_CREL_MON_0        (0x1U<<8U)
#define FDCAN_CREL_YEAR         (0xFU<<16U)
#define FDCAN_CREL_YEAR_0       (0x1U<<16U)
#define FDCAN_CREL_SUBSTEP      (0xFU<<20U)
#define FDCAN_CREL_SUBSTEP_0    (0x1U<<20U)
#define FDCAN_CREL_STEP         (0xFU<<24U)
#define FDCAN_CREL_STEP_0       (0x1U<<24U)
#define FDCAN_CREL_REL          (0xFU<<28U)
#define FDCAN_CREL_REL_0        (0x1U<<28U)

// ENDN Configuration

#define FDCAN_ENDN_ETV          (0xFFFFFFFFU<<0U)
#define FDCAN_ENDN_ETV_0        (0x1U<<0U)

// DBTP Configuration

#define FDCAN_DBTP_TDC          (0x1U<<23U)
#define FDCAN_DBTP_DBRP         (0x1FU<<16U)
#define FDCAN_DBTP_DBRP_0       (0x1U<<16U)
#define FDCAN_DBTP_DTSEG1       (0x1FU<<8U)
#define FDCAN_DBTP_DTSEG1_0     (0x1U<<8U)
#define FDCAN_DBTP_DTSEG2       (0xFU<<4U)
#define FDCAN_DBTP_DTSEG2_0     (0x1U<<4U)
#define FDCAN_DBTP_DSJW         (0xFU<<0U)
#define FDCAN_DBTP_DSJW_0       (0x1U<<0U)

// TEST Configuration

#define FDCAN_TEST_RX           (0x1U<<7U)
#define FDCAN_TEST_TX           (0x3U<<5U)
#define FDCAN_TEST_TX_0         (0x1U<<5U)
#define FDCAN_TEST_LBCK         (0x1U<<4U)

// RWD Configuration

#define FDCAN_RWD_WDC           (0xFFU<<0U)
#define FDCAN_RWD_WDC_0         (0x1U<<0U)
#define FDCAN_RWD_WDV           (0xFFU<<8U)
#define FDCAN_RWD_WDV_0         (0x1U<<8U)

// CCCR Configuration

#define FDCAN_CCCR_NISO         (0x1U<<15U)
#define FDCAN_CCCR_TXP          (0x1U<<14U)
#define FDCAN_CCCR_EFBI         (0x1U<<13U)
#define FDCAN_CCCR_PXHD         (0x1U<<12U)
#define FDCAN_CCCR_BRSE         (0x1U<<9U)
#define FDCAN_CCCR_FDOE         (0x1U<<8U)
#define FDCAN_CCCR_TEST         (0x1U<<7U)
#define FDCAN_CCCR_DAR          (0x1U<<6U)
#define FDCAN_CCCR_MON          (0x1U<<5U)
#define FDCAN_CCCR_CSR          (0x1U<<4U)
#define FDCAN_CCCR_CSA          (0x1U<<3U)
#define FDCAN_CCCR_ASM          (0x1U<<2U)
#define FDCAN_CCCR_CCE          (0x1U<<1U)
#define FDCAN_CCCR_INIT         (0x1U<<0U)

// NBTP Configuration

#define FDCAN_NBTP_NTSEG2       (0x7FU<<0U)
#define FDCAN_NBTP_NTSEG2_0     (0x1U<<0U)
#define FDCAN_NBTP_NTSEG1       (0xFFU<<8U)
#define FDCAN_NBTP_NTSEG1_0     (0x1U<<8U)
#define FDCAN_NBTP_NBRP         (0x1FFU<<16U)
#define FDCAN_NBTP_NBRP_0       (0x1U<<16U)
#define FDCAN_NBTP_NSJW         (0x7FU<<25U)
#define FDCAN_NBTP_NSJW_0       (0x1U<<25U)

// TSCC Configuration

#define FDCAN_TSCC_TSS          (0x3U<<0U)
#define FDCAN_TSCC_TSS_0        (0x1U<<0U)
#define FDCAN_TSCC_TCP          (0xFU<<16U)
#define FDCAN_TSCC_TCP_0        (0x1U<<16U)

// TSCV Configuration

#define FDCAN_TSCV_TSC          (0xFFFFU<<0U)
#define FDCAN_TSCV_TSC_0        (0x1U<<0U)

// TOCC Configuration

#define FDCAN_TOCC_TOP          (0xFFFFU<<16U)
#define FDCAN_TOCC_TOP_0        (0x1U<<16U)
#define FDCAN_TOCC_TOS          (0x3U<<1U)
#define FDCAN_TOCC_TOS_0        (0x1U<<1U)
#define FDCAN_TOCC_ETOC         (0x1U<<0U)

// TOCV Configuration

#define FDCAN_TOCV_TOC          (0xFFFFU<<0U)
#define FDCAN_TOCV_TOC_0        (0x1U<<0U)

// ECR Configuration

#define FDCAN_ECR_TEC           (0xFFU<<0U)
#define FDCAN_ECR_TEC_0         (0x1U<<0U)
#define FDCAN_ECR_REC           (0x7FU<<8U)
#define FDCAN_ECR_REC_0         (0x1U<<8U)
#define FDCAN_ECR_RP            (0x1U<<15U)
#define FDCAN_ECR_CEL           (0xFFU<<16U)
#define FDCAN_ECR_CEL_0         (0x1U<<16U)

// PSR Configuration

#define FDCAN_PSR_TDCV          (0x7FU<<16U)
#define FDCAN_PSR_TDCV_0        (0x1U<<16U)
#define FDCAN_PSR_PXE           (0x1U<<14U)
#define FDCAN_PSR_REDL          (0x1U<<13U)
#define FDCAN_PSR_RBRS          (0x1U<<12U)
#define FDCAN_PSR_RESI          (0x1U<<11U)
#define FDCAN_PSR_DLEC          (0x7U<<8U)
#define FDCAN_PSR_DLEC_0        (0x1U<<8U)
#define FDCAN_PSR_BO            (0x1U<<7U)
#define FDCAN_PSR_EW            (0x1U<<6U)
#define FDCAN_PSR_EP            (0x1U<<5U)
#define FDCAN_PSR_ACT           (0x3U<<3U)
#define FDCAN_PSR_ACT_0         (0x1U<<3U)
#define FDCAN_PSR_LEC           (0x7U<<0U)
#define FDCAN_PSR_LEC_0         (0x1U<<0U)

// TDCR Configuration

#define FDCAN_TDCR_TDCO         (0x7FU<<8U)
#define FDCAN_TDCR_TDCO_0       (0x1U<<8U)
#define FDCAN_TDCR_TDCF         (0x7FU<<0U)
#define FDCAN_TDCR_TDCF_0       (0x1U<<0U)

// IR Configuration

#define FDCAN_IR_ARA            (0x1U<<23U)
#define FDCAN_IR_PED            (0x1U<<22U)
#define FDCAN_IR_PEA            (0x1U<<21U)
#define FDCAN_IR_WDI            (0x1U<<20U)
#define FDCAN_IR_BO             (0x1U<<19U)
#define FDCAN_IR_EW             (0x1U<<18U)
#define FDCAN_IR_EP             (0x1U<<17U)
#define FDCAN_IR_ELO            (0x1U<<16U)
#define FDCAN_IR_TOO            (0x1U<<15U)
#define FDCAN_IR_MRAF           (0x1U<<14U)
#define FDCAN_IR_TSW            (0x1U<<13U)
#define FDCAN_IR_TEFL           (0x1U<<12U)
#define FDCAN_IR_TEFF           (0x1U<<11U)
#define FDCAN_IR_TEFN           (0x1U<<10U)
#define FDCAN_IR_TFE            (0x1U<<9U)
#define FDCAN_IR_TCF            (0x1U<<8U)
#define FDCAN_IR_TC             (0x1U<<7U)
#define FDCAN_IR_HPM            (0x1U<<6U)
#define FDCAN_IR_RF1L           (0x1U<<5U)
#define FDCAN_IR_RF1F           (0x1U<<4U)
#define FDCAN_IR_RF1N           (0x1U<<3U)
#define FDCAN_IR_RF0L           (0x1U<<2U)
#define FDCAN_IR_RF0F           (0x1U<<1U)
#define FDCAN_IR_RF0N           (0x1U<<0U)

// IE Configuration

#define FDCAN_IE_ARAE           (0x1U<<23U)
#define FDCAN_IE_PEDE           (0x1U<<22U)
#define FDCAN_IE_PEAE           (0x1U<<21U)
#define FDCAN_IE_WDIE           (0x1U<<20U)
#define FDCAN_IE_BOE            (0x1U<<19U)
#define FDCAN_IE_EWE            (0x1U<<18U)
#define FDCAN_IE_EPE            (0x1U<<17U)
#define FDCAN_IE_ELOE           (0x1U<<16U)
#define FDCAN_IE_TOOE           (0x1U<<15U)
#define FDCAN_IE_MRAFE          (0x1U<<14U)
#define FDCAN_IE_TSWE           (0x1U<<13U)
#define FDCAN_IE_TEFLE          (0x1U<<12U)
#define FDCAN_IE_TEFFE          (0x1U<<11U)
#define FDCAN_IE_TEFNE          (0x1U<<10U)
#define FDCAN_IE_TEFE           (0x1U<<9U)
#define FDCAN_IE_TCFE           (0x1U<<8U)
#define FDCAN_IE_TCE            (0x1U<<7U)
#define FDCAN_IE_HPME           (0x1U<<6U)
#define FDCAN_IE_RF1LE          (0x1U<<5U)
#define FDCAN_IE_RF1FE          (0x1U<<4U)
#define FDCAN_IE_RF1NE          (0x1U<<3U)
#define FDCAN_IE_RF0LE          (0x1U<<2U)
#define FDCAN_IE_RF0FE          (0x1U<<1U)
#define FDCAN_IE_RF0NE          (0x1U<<0U)

// ILS Configuration

#define FDCAN_ILS_PERR          (0x1U<<6U)
#define FDCAN_ILS_BERR          (0x1U<<5U)
#define FDCAN_ILS_MISC          (0x1U<<4U)
#define FDCAN_ILS_TFERR         (0x1U<<3U)
#define FDCAN_ILS_SMSG          (0x1U<<2U)
#define FDCAN_ILS_RXFIFO1       (0x1U<<1U)
#define FDCAN_ILS_RXFIFO0       (0x1U<<0U)

// ILE Configuration

#define FDCAN_ILE_EINT1         (0x1U<<1U)
#define FDCAN_ILE_EINT0         (0x1U<<0U)

// RXGFC Configuration

#define FDCAN_RXGFC_LSE         (0xFU<<24U)
#define FDCAN_RXGFC_LSE_0       (0x1U<<24U)
#define FDCAN_RXGFC_LSS         (0x1FU<<16U)
#define FDCAN_RXGFC_LSS_0       (0x1U<<16U)
#define FDCAN_RXGFC_F0OM        (0x1U<<9U)
#define FDCAN_RXGFC_F1OM        (0x1U<<8U)
#define FDCAN_RXGFC_ANFS        (0x3U<<4U)
#define FDCAN_RXGFC_ANFS_0      (0x1U<<4U)
#define FDCAN_RXGFC_ANFE        (0x3U<<2U)
#define FDCAN_RXGFC_ANFE_0      (0x1U<<2U)
#define FDCAN_RXGFC_RRFS        (0x1U<<1U)
#define FDCAN_RXGFC_RRFE        (0x1U<<0U)

// XIDAM Configuration

#define FDCAN_XIDAM_EIDM        (0x1FFFFFFFU<<0U)
#define FDCAN_XIDAM_EIDM_0      (0x1U<<0U)

// HPMS Configuration

#define FDCAN_HPMS_FLST         (0x1U<<15U)
#define FDCAN_HPMS_FIDX         (0x1FU<<8U)
#define FDCAN_HPMS_FIDX_0       (0x1U<<8U)
#define FDCAN_HPMS_MSI          (0x3U<<6U)
#define FDCAN_HPMS_MSI_0        (0x1U<<6U)
#define FDCAN_HPMS_BIDX         (0x7U<<0U)
#define FDCAN_HPMS_BIDX_0       (0x1U<<0U)

// RXF0S Configuration

#define FDCAN_RXF0S_RF0L        (0x1U<<25U)
#define FDCAN_RXF0S_F0F         (0x1U<<24U)
#define FDCAN_RXF0S_F0PI        (0x3U<<16U)
#define FDCAN_RXF0S_F0PI_0      (0x1U<<16U)
#define FDCAN_RXF0S_F0GI        (0x3U<<8U)
#define FDCAN_RXF0S_F0GI_0      (0x1U<<8U)
#define FDCAN_RXF0S_F0FL        (0xFU<<0U)
#define FDCAN_RXF0S_F0FL_0      (0x1U<<0U)

// RXF0A Configuration

#define FDCAN_RXF0A_F0AI        (0x7U<<0U)
#define FDCAN_RXF0A_F0AI_0      (0x1U<<0U)

// RXF1S Configuration

#define FDCAN_RXF1S_RF1L        (0x1U<<25U)
#define FDCAN_RXF1S_F1F         (0x1U<<24U)
#define FDCAN_RXF1S_F1PI        (0x3U<<16U)
#define FDCAN_RXF1S_F1PI_0      (0x1U<<16U)
#define FDCAN_RXF1S_F1GI        (0x3U<<8U)
#define FDCAN_RXF1S_F1GI_0      (0x1U<<8U)
#define FDCAN_RXF1S_F1FL        (0xFU<<0U)
#define FDCAN_RXF1S_F1FL_0      (0x1U<<0U)

// RXF1A Configuration

#define FDCAN_RXF1A_F1AI        (0x7U<<0U)
#define FDCAN_RXF1A_F1AI_0      (0x1U<<0U)

// TXBC Configuration

#define FDCAN_TXBC_TFQM         (0x1U<<24U)

// TXFQS Configuration

#define FDCAN_TXFQS_TFQF        (0x1U<<21U)
#define FDCAN_TXFQS_TFQPI       (0x3U<<16U)
#define FDCAN_TXFQS_TFQPI_0     (0x1U<<16U)
#define FDCAN_TXFQS_TFGI        (0x3U<<8U)
#define FDCAN_TXFQS_TFGI_0      (0x1U<<8U)
#define FDCAN_TXFQS_TFFL        (0x7U<<0U)
#define FDCAN_TXFQS_TFFL_0      (0x1U<<0U)

// TXBRP Configuration

#define FDCAN_TXBRP_TRP         (0x7U<<0U)
#define FDCAN_TXBRP_TRP_0       (0x1U<<0U)

// TXBAR Configuration

#define FDCAN_TXBAR_AR          (0x7U<<0U)
#define FDCAN_TXBAR_AR_0        (0x1U<<0U)

// TXBCR Configuration

#define FDCAN_TXBCR_CR          (0x7U<<0U)
#define FDCAN_TXBCR_CR_0        (0x1U<<0U)

// TXBTO Configuration

#define FDCAN_TXBTO_TO          (0x7U<<0U)
#define FDCAN_TXBTO_TO_0        (0x1U<<0U)

// TXBCF Configuration

#define FDCAN_TXBCF_CF          (0x7U<<0U)
#define FDCAN_TXBCF_CF_0        (0x1U<<0U)

// TXBTIE Configuration

#define FDCAN_TXBTIE_TIE        (0x7U<<0U)
#define FDCAN_TXBTIE_TIE_0      (0x1U<<0U)

// TXBCIE Configuration

#define FDCAN_TXBCIE_CFIE       (0x7U<<0U)
#define FDCAN_TXBCIE_CFIE_0     (0x1U<<0U)

// TXEFS Configuration

#define FDCAN_TXEFS_TEFL        (0x1U<<25U)
#define FDCAN_TXEFS_EFF         (0x1U<<24U)
#define FDCAN_TXEFS_EFPI        (0x3U<<16U)
#define FDCAN_TXEFS_EFPI_0      (0x1U<<16U)
#define FDCAN_TXEFS_EFGI        (0x3U<<8U)
#define FDCAN_TXEFS_EFGI_0      (0x1U<<8U)
#define FDCAN_TXEFS_EFFL        (0x7U<<0U)
#define FDCAN_TXEFS_EFFL_0      (0x1U<<0U)

// TXEFA Configuration

#define FDCAN_TXEFA_EFAI        (0x3U<<0U)
#define FDCAN_TXEFA_EFAI_0      (0x1U<<0U)

// CKDIV Configuration

#define FDCAN_CKDIV_PDIV        (0xFU<<0U)
#define FDCAN_CKDIV_PDIV_0      (0x1U<<0U)
