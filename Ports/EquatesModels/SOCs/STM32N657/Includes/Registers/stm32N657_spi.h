/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_spi equates.
 */

#pragma once

#include    <stdint.h>

// SPI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CFG1;
    volatile    uint32_t    CFG2;
    volatile    uint32_t    IER;
    volatile    uint32_t    SR;
    volatile    uint32_t    IFCR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    TXDR;
    volatile    uint32_t    RESERVED1[3];
    volatile    uint32_t    RXDR;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    CRCPOLY;
    volatile    uint32_t    TXCRC;
    volatile    uint32_t    RXCRC;
    volatile    uint32_t    UDRDR;
    volatile    uint32_t    I2SCFGR;
} SPI_TypeDef;

#ifdef __cplusplus
#define SPI1_NS reinterpret_cast<SPI_TypeDef *>(0x42003000U)
#define SPI1_S  reinterpret_cast<SPI_TypeDef *>(0x52003000U)
#define SPI2_NS reinterpret_cast<SPI_TypeDef *>(0x40003800U)
#define SPI2_S  reinterpret_cast<SPI_TypeDef *>(0x50003800U)
#define SPI3_NS reinterpret_cast<SPI_TypeDef *>(0x40003C00U)
#define SPI3_S  reinterpret_cast<SPI_TypeDef *>(0x50003C00U)
#define SPI4_NS reinterpret_cast<SPI_TypeDef *>(0x42003400U)
#define SPI4_S  reinterpret_cast<SPI_TypeDef *>(0x52003400U)
#define SPI5_NS reinterpret_cast<SPI_TypeDef *>(0x42005000U)
#define SPI5_S  reinterpret_cast<SPI_TypeDef *>(0x52005000U)
#define SPI6_NS reinterpret_cast<SPI_TypeDef *>(0x46001400U)
#define SPI6_S  reinterpret_cast<SPI_TypeDef *>(0x56001400U)

#else
#define SPI1_NS ((SPI_TypeDef *)0x42003000U)
#define SPI1_S  ((SPI_TypeDef *)0x52003000U)
#define SPI2_NS ((SPI_TypeDef *)0x40003800U)
#define SPI2_S  ((SPI_TypeDef *)0x50003800U)
#define SPI3_NS ((SPI_TypeDef *)0x40003C00U)
#define SPI3_S  ((SPI_TypeDef *)0x50003C00U)
#define SPI4_NS ((SPI_TypeDef *)0x42003400U)
#define SPI4_S  ((SPI_TypeDef *)0x52003400U)
#define SPI5_NS ((SPI_TypeDef *)0x42005000U)
#define SPI5_S  ((SPI_TypeDef *)0x52005000U)
#define SPI6_NS ((SPI_TypeDef *)0x46001400U)
#define SPI6_S  ((SPI_TypeDef *)0x56001400U)
#endif

// CR1 Configuration

#define SPI_CR1_IOLOCK              (0x1U<<16U)
#define SPI_CR1_TCRCINI             (0x1U<<15U)
#define SPI_CR1_RCRCINI             (0x1U<<14U)
#define SPI_CR1_CRC33_17            (0x1U<<13U)
#define SPI_CR1_SSI                 (0x1U<<12U)
#define SPI_CR1_HDDIR               (0x1U<<11U)
#define SPI_CR1_CSUSP               (0x1U<<10U)
#define SPI_CR1_CSTART              (0x1U<<9U)
#define SPI_CR1_MASRX               (0x1U<<8U)
#define SPI_CR1_SPE                 (0x1U<<0U)

#define SPI_CR1_IOLOCK_B_0X0        (0x0U<<16U)
#define SPI_CR1_IOLOCK_B_0X1        (0x1U<<16U)
#define SPI_CR1_TCRCINI_B_0X0       (0x0U<<15U)
#define SPI_CR1_TCRCINI_B_0X1       (0x1U<<15U)
#define SPI_CR1_RCRCINI_B_0X0       (0x0U<<14U)
#define SPI_CR1_RCRCINI_B_0X1       (0x1U<<14U)
#define SPI_CR1_CRC33_17_B_0X0      (0x0U<<13U)
#define SPI_CR1_CRC33_17_B_0X1      (0x1U<<13U)
#define SPI_CR1_HDDIR_B_0X0         (0x0U<<11U)
#define SPI_CR1_HDDIR_B_0X1         (0x1U<<11U)
#define SPI_CR1_CSTART_B_0X0        (0x0U<<9U)
#define SPI_CR1_CSTART_B_0X1        (0x1U<<9U)
#define SPI_CR1_MASRX_B_0X0         (0x0U<<8U)
#define SPI_CR1_MASRX_B_0X1         (0x1U<<8U)
#define SPI_CR1_SPE_B_0X0           (0x0U<<0U)
#define SPI_CR1_SPE_B_0X1           (0x1U<<0U)

// CR2 Configuration

#define SPI_CR2_TSIZE               (0xFFFFU<<0U)
#define SPI_CR2_TSIZE_0             (0x1U<<0U)

// CFG1 Configuration

#define SPI_CFG1_BPASS              (0x1U<<31U)
#define SPI_CFG1_MBR                (0x7U<<28U)
#define SPI_CFG1_MBR_0              (0x1U<<28U)
#define SPI_CFG1_CRCEN              (0x1U<<22U)
#define SPI_CFG1_CRCSIZE            (0x1FU<<16U)
#define SPI_CFG1_CRCSIZE_0          (0x1U<<16U)
#define SPI_CFG1_TXDMAEN            (0x1U<<15U)
#define SPI_CFG1_RXDMAEN            (0x1U<<14U)
#define SPI_CFG1_UDRCFG             (0x1U<<9U)
#define SPI_CFG1_FTHLV              (0xFU<<5U)
#define SPI_CFG1_FTHLV_0            (0x1U<<5U)
#define SPI_CFG1_DSIZE              (0x1FU<<0U)
#define SPI_CFG1_DSIZE_0            (0x1U<<0U)

#define SPI_CFG1_BPASS_B_0X0        (0x0U<<31U)
#define SPI_CFG1_BPASS_B_0X1        (0x1U<<31U)
#define SPI_CFG1_MBR_B_0X0          (0x0U<<28U)
#define SPI_CFG1_MBR_B_0X1          (0x1U<<28U)
#define SPI_CFG1_MBR_B_0X2          (0x2U<<28U)
#define SPI_CFG1_MBR_B_0X3          (0x3U<<28U)
#define SPI_CFG1_MBR_B_0X4          (0x4U<<28U)
#define SPI_CFG1_MBR_B_0X5          (0x5U<<28U)
#define SPI_CFG1_MBR_B_0X6          (0x6U<<28U)
#define SPI_CFG1_MBR_B_0X7          (0x7U<<28U)
#define SPI_CFG1_CRCEN_B_0X0        (0x0U<<22U)
#define SPI_CFG1_CRCEN_B_0X1        (0x1U<<22U)
#define SPI_CFG1_CRCSIZE_B_0X3      (0x3U<<16U)
#define SPI_CFG1_CRCSIZE_B_0X4      (0x4U<<16U)
#define SPI_CFG1_CRCSIZE_B_0X5      (0x5U<<16U)
#define SPI_CFG1_CRCSIZE_B_0X6      (0x6U<<16U)
#define SPI_CFG1_CRCSIZE_B_0X7      (0x7U<<16U)
#define SPI_CFG1_CRCSIZE_B_0X1D     (0x1DU<<16U)
#define SPI_CFG1_CRCSIZE_B_0X1E     (0x1EU<<16U)
#define SPI_CFG1_CRCSIZE_B_0X1F     (0x1FU<<16U)
#define SPI_CFG1_TXDMAEN_B_0X0      (0x0U<<15U)
#define SPI_CFG1_TXDMAEN_B_0X1      (0x1U<<15U)
#define SPI_CFG1_RXDMAEN_B_0X0      (0x0U<<14U)
#define SPI_CFG1_RXDMAEN_B_0X1      (0x1U<<14U)
#define SPI_CFG1_UDRCFG_B_0X0       (0x0U<<9U)
#define SPI_CFG1_UDRCFG_B_0X1       (0x1U<<9U)
#define SPI_CFG1_FTHLV_B_0X0        (0x0U<<5U)
#define SPI_CFG1_FTHLV_B_0X1        (0x1U<<5U)
#define SPI_CFG1_FTHLV_B_0X2        (0x2U<<5U)
#define SPI_CFG1_FTHLV_B_0X3        (0x3U<<5U)
#define SPI_CFG1_FTHLV_B_0X4        (0x4U<<5U)
#define SPI_CFG1_FTHLV_B_0X5        (0x5U<<5U)
#define SPI_CFG1_FTHLV_B_0X6        (0x6U<<5U)
#define SPI_CFG1_FTHLV_B_0X7        (0x7U<<5U)
#define SPI_CFG1_FTHLV_B_0X8        (0x8U<<5U)
#define SPI_CFG1_FTHLV_B_0X9        (0x9U<<5U)
#define SPI_CFG1_FTHLV_B_0XA        (0xAU<<5U)
#define SPI_CFG1_FTHLV_B_0XB        (0xBU<<5U)
#define SPI_CFG1_FTHLV_B_0XC        (0xCU<<5U)
#define SPI_CFG1_FTHLV_B_0XD        (0xDU<<5U)
#define SPI_CFG1_FTHLV_B_0XE        (0xEU<<5U)
#define SPI_CFG1_FTHLV_B_0XF        (0xFU<<5U)
#define SPI_CFG1_DSIZE_B_0X0        (0x0U<<0U)
#define SPI_CFG1_DSIZE_B_0X1        (0x1U<<0U)
#define SPI_CFG1_DSIZE_B_0X2        (0x2U<<0U)
#define SPI_CFG1_DSIZE_B_0X3        (0x3U<<0U)
#define SPI_CFG1_DSIZE_B_0X4        (0x4U<<0U)
#define SPI_CFG1_DSIZE_B_0X5        (0x5U<<0U)
#define SPI_CFG1_DSIZE_B_0X6        (0x6U<<0U)
#define SPI_CFG1_DSIZE_B_0X7        (0x7U<<0U)
#define SPI_CFG1_DSIZE_B_0X1D       (0x1DU<<0U)
#define SPI_CFG1_DSIZE_B_0X1E       (0x1EU<<0U)
#define SPI_CFG1_DSIZE_B_0X1F       (0x1FU<<0U)

// CFG2 Configuration

#define SPI_CFG2_AFCNTR             (0x1U<<31U)
#define SPI_CFG2_SSOM               (0x1U<<30U)
#define SPI_CFG2_SSOE               (0x1U<<29U)
#define SPI_CFG2_SSIOP              (0x1U<<28U)
#define SPI_CFG2_SSM                (0x1U<<26U)
#define SPI_CFG2_CPOL               (0x1U<<25U)
#define SPI_CFG2_CPHA               (0x1U<<24U)
#define SPI_CFG2_LSBFRST            (0x1U<<23U)
#define SPI_CFG2_MASTER             (0x1U<<22U)
#define SPI_CFG2_SP                 (0x7U<<19U)
#define SPI_CFG2_SP_0               (0x1U<<19U)
#define SPI_CFG2_COMM               (0x3U<<17U)
#define SPI_CFG2_COMM_0             (0x1U<<17U)
#define SPI_CFG2_IOSWP              (0x1U<<15U)
#define SPI_CFG2_RDIOP              (0x1U<<14U)
#define SPI_CFG2_RDIOM              (0x1U<<13U)
#define SPI_CFG2_MIDI               (0xFU<<4U)
#define SPI_CFG2_MIDI_0             (0x1U<<4U)
#define SPI_CFG2_MSSI               (0xFU<<0U)
#define SPI_CFG2_MSSI_0             (0x1U<<0U)

#define SPI_CFG2_AFCNTR_B_0X0       (0x0U<<31U)
#define SPI_CFG2_AFCNTR_B_0X1       (0x1U<<31U)
#define SPI_CFG2_SSOM_B_0X0         (0x0U<<30U)
#define SPI_CFG2_SSOM_B_0X1         (0x1U<<30U)
#define SPI_CFG2_SSOE_B_0X0         (0x0U<<29U)
#define SPI_CFG2_SSOE_B_0X1         (0x1U<<29U)
#define SPI_CFG2_SSIOP_B_0X0        (0x0U<<28U)
#define SPI_CFG2_SSIOP_B_0X1        (0x1U<<28U)
#define SPI_CFG2_SSM_B_0X0          (0x0U<<26U)
#define SPI_CFG2_SSM_B_0X1          (0x1U<<26U)
#define SPI_CFG2_CPOL_B_0X0         (0x0U<<25U)
#define SPI_CFG2_CPOL_B_0X1         (0x1U<<25U)
#define SPI_CFG2_CPHA_B_0X0         (0x0U<<24U)
#define SPI_CFG2_CPHA_B_0X1         (0x1U<<24U)
#define SPI_CFG2_LSBFRST_B_0X0      (0x0U<<23U)
#define SPI_CFG2_LSBFRST_B_0X1      (0x1U<<23U)
#define SPI_CFG2_MASTER_B_0X0       (0x0U<<22U)
#define SPI_CFG2_MASTER_B_0X1       (0x1U<<22U)
#define SPI_CFG2_SP_B_0X0           (0x0U<<19U)
#define SPI_CFG2_SP_B_0X1           (0x1U<<19U)
#define SPI_CFG2_COMM_B_0X0         (0x0U<<17U)
#define SPI_CFG2_COMM_B_0X1         (0x1U<<17U)
#define SPI_CFG2_COMM_B_0X2         (0x2U<<17U)
#define SPI_CFG2_COMM_B_0X3         (0x3U<<17U)
#define SPI_CFG2_IOSWP_B_0X0        (0x0U<<15U)
#define SPI_CFG2_IOSWP_B_0X1        (0x1U<<15U)
#define SPI_CFG2_RDIOP_B_0X0        (0x0U<<14U)
#define SPI_CFG2_RDIOP_B_0X1        (0x1U<<14U)
#define SPI_CFG2_RDIOM_B_0X0        (0x0U<<13U)
#define SPI_CFG2_RDIOM_B_0X1        (0x1U<<13U)
#define SPI_CFG2_MIDI_B_0X0         (0x0U<<4U)
#define SPI_CFG2_MIDI_B_0X1         (0x1U<<4U)
#define SPI_CFG2_MIDI_B_0XF         (0xFU<<4U)
#define SPI_CFG2_MSSI_B_0X0         (0x0U<<0U)
#define SPI_CFG2_MSSI_B_0X1         (0x1U<<0U)
#define SPI_CFG2_MSSI_B_0XF         (0xFU<<0U)

// IER Configuration

#define SPI_IER_MODFIE              (0x1U<<9U)
#define SPI_IER_TIFREIE             (0x1U<<8U)
#define SPI_IER_CRCEIE              (0x1U<<7U)
#define SPI_IER_OVRIE               (0x1U<<6U)
#define SPI_IER_UDRIE               (0x1U<<5U)
#define SPI_IER_TXTFIE              (0x1U<<4U)
#define SPI_IER_EOTIE               (0x1U<<3U)
#define SPI_IER_DXPIE               (0x1U<<2U)
#define SPI_IER_TXPIE               (0x1U<<1U)
#define SPI_IER_RXPIE               (0x1U<<0U)

#define SPI_IER_MODFIE_B_0X0        (0x0U<<9U)
#define SPI_IER_MODFIE_B_0X1        (0x1U<<9U)
#define SPI_IER_TIFREIE_B_0X0       (0x0U<<8U)
#define SPI_IER_TIFREIE_B_0X1       (0x1U<<8U)
#define SPI_IER_CRCEIE_B_0X0        (0x0U<<7U)
#define SPI_IER_CRCEIE_B_0X1        (0x1U<<7U)
#define SPI_IER_OVRIE_B_0X0         (0x0U<<6U)
#define SPI_IER_OVRIE_B_0X1         (0x1U<<6U)
#define SPI_IER_UDRIE_B_0X0         (0x0U<<5U)
#define SPI_IER_UDRIE_B_0X1         (0x1U<<5U)
#define SPI_IER_TXTFIE_B_0X0        (0x0U<<4U)
#define SPI_IER_TXTFIE_B_0X1        (0x1U<<4U)
#define SPI_IER_EOTIE_B_0X0         (0x0U<<3U)
#define SPI_IER_EOTIE_B_0X1         (0x1U<<3U)
#define SPI_IER_DXPIE_B_0X0         (0x0U<<2U)
#define SPI_IER_DXPIE_B_0X1         (0x1U<<2U)
#define SPI_IER_TXPIE_B_0X0         (0x0U<<1U)
#define SPI_IER_TXPIE_B_0X1         (0x1U<<1U)
#define SPI_IER_RXPIE_B_0X0         (0x0U<<0U)
#define SPI_IER_RXPIE_B_0X1         (0x1U<<0U)

// SR Configuration

#define SPI_SR_CTSIZE               (0xFFFFU<<16U)
#define SPI_SR_CTSIZE_0             (0x1U<<16U)
#define SPI_SR_RXWNE                (0x1U<<15U)
#define SPI_SR_RXPLVL               (0x3U<<13U)
#define SPI_SR_RXPLVL_0             (0x1U<<13U)
#define SPI_SR_TXC                  (0x1U<<12U)
#define SPI_SR_SUSP                 (0x1U<<11U)
#define SPI_SR_MODF                 (0x1U<<9U)
#define SPI_SR_TIFRE                (0x1U<<8U)
#define SPI_SR_CRCE                 (0x1U<<7U)
#define SPI_SR_OVR                  (0x1U<<6U)
#define SPI_SR_UDR                  (0x1U<<5U)
#define SPI_SR_TXTF                 (0x1U<<4U)
#define SPI_SR_EOT                  (0x1U<<3U)
#define SPI_SR_DXP                  (0x1U<<2U)
#define SPI_SR_TXP                  (0x1U<<1U)
#define SPI_SR_RXP                  (0x1U<<0U)

#define SPI_SR_RXWNE_B_0X0          (0x0U<<15U)
#define SPI_SR_RXWNE_B_0X1          (0x1U<<15U)
#define SPI_SR_RXPLVL_B_0X0         (0x0U<<13U)
#define SPI_SR_RXPLVL_B_0X1         (0x1U<<13U)
#define SPI_SR_RXPLVL_B_0X2         (0x2U<<13U)
#define SPI_SR_RXPLVL_B_0X3         (0x3U<<13U)
#define SPI_SR_TXC_B_0X0            (0x0U<<12U)
#define SPI_SR_TXC_B_0X1            (0x1U<<12U)
#define SPI_SR_SUSP_B_0X0           (0x0U<<11U)
#define SPI_SR_SUSP_B_0X1           (0x1U<<11U)
#define SPI_SR_MODF_B_0X0           (0x0U<<9U)
#define SPI_SR_MODF_B_0X1           (0x1U<<9U)
#define SPI_SR_TIFRE_B_0X0          (0x0U<<8U)
#define SPI_SR_TIFRE_B_0X1          (0x1U<<8U)
#define SPI_SR_CRCE_B_0X0           (0x0U<<7U)
#define SPI_SR_CRCE_B_0X1           (0x1U<<7U)
#define SPI_SR_OVR_B_0X0            (0x0U<<6U)
#define SPI_SR_OVR_B_0X1            (0x1U<<6U)
#define SPI_SR_UDR_B_0X0            (0x0U<<5U)
#define SPI_SR_UDR_B_0X1            (0x1U<<5U)
#define SPI_SR_TXTF_B_0X0           (0x0U<<4U)
#define SPI_SR_TXTF_B_0X1           (0x1U<<4U)
#define SPI_SR_EOT_B_0X0            (0x0U<<3U)
#define SPI_SR_EOT_B_0X1            (0x1U<<3U)
#define SPI_SR_DXP_B_0X0            (0x0U<<2U)
#define SPI_SR_DXP_B_0X1            (0x1U<<2U)
#define SPI_SR_TXP_B_0X0            (0x0U<<1U)
#define SPI_SR_TXP_B_0X1            (0x1U<<1U)
#define SPI_SR_RXP_B_0X0            (0x0U<<0U)
#define SPI_SR_RXP_B_0X1            (0x1U<<0U)

// IFCR Configuration

#define SPI_IFCR_SUSPC              (0x1U<<11U)
#define SPI_IFCR_MODFC              (0x1U<<9U)
#define SPI_IFCR_TIFREC             (0x1U<<8U)
#define SPI_IFCR_CRCEC              (0x1U<<7U)
#define SPI_IFCR_OVRC               (0x1U<<6U)
#define SPI_IFCR_UDRC               (0x1U<<5U)
#define SPI_IFCR_TXTFC              (0x1U<<4U)
#define SPI_IFCR_EOTC               (0x1U<<3U)

// TXDR Configuration

#define SPI_TXDR_TXDR               (0xFFFFFFFFU<<0U)
#define SPI_TXDR_TXDR_0             (0x1U<<0U)

// RXDR Configuration

#define SPI_RXDR_RXDR               (0xFFFFFFFFU<<0U)
#define SPI_RXDR_RXDR_0             (0x1U<<0U)

// CRCPOLY Configuration

#define SPI_CRCPOLY_CRCPOLY         (0xFFFFFFFFU<<0U)
#define SPI_CRCPOLY_CRCPOLY_0       (0x1U<<0U)

// TXCRC Configuration

#define SPI_TXCRC_TXCRC             (0xFFFFFFFFU<<0U)
#define SPI_TXCRC_TXCRC_0           (0x1U<<0U)

// RXCRC Configuration

#define SPI_RXCRC_RXCRC             (0xFFFFFFFFU<<0U)
#define SPI_RXCRC_RXCRC_0           (0x1U<<0U)

// UDRDR Configuration

#define SPI_UDRDR_UDRDR             (0xFFFFFFFFU<<0U)
#define SPI_UDRDR_UDRDR_0           (0x1U<<0U)

// I2SCFGR Configuration

#define SPI_I2SCFGR_MCKOE           (0x1U<<25U)
#define SPI_I2SCFGR_ODD             (0x1U<<24U)
#define SPI_I2SCFGR_I2SDIV          (0xFFU<<16U)
#define SPI_I2SCFGR_I2SDIV_0        (0x1U<<16U)
#define SPI_I2SCFGR_DATFMT          (0x1U<<14U)
#define SPI_I2SCFGR_WSINV           (0x1U<<13U)
#define SPI_I2SCFGR_FIXCH           (0x1U<<12U)
#define SPI_I2SCFGR_CKPOL           (0x1U<<11U)
#define SPI_I2SCFGR_CHLEN           (0x1U<<10U)
#define SPI_I2SCFGR_DATLEN          (0x3U<<8U)
#define SPI_I2SCFGR_DATLEN_0        (0x1U<<8U)
#define SPI_I2SCFGR_PCMSYNC         (0x1U<<7U)
#define SPI_I2SCFGR_I2SSTD          (0x3U<<4U)
#define SPI_I2SCFGR_I2SSTD_0        (0x1U<<4U)
#define SPI_I2SCFGR_I2SCFG          (0x7U<<1U)
#define SPI_I2SCFGR_I2SCFG_0        (0x1U<<1U)
#define SPI_I2SCFGR_I2SMOD          (0x1U<<0U)

#define SPI_I2SCFGR_MCKOE_B_0X0     (0x0U<<25U)
#define SPI_I2SCFGR_MCKOE_B_0X1     (0x1U<<25U)
#define SPI_I2SCFGR_ODD_B_0X0       (0x0U<<24U)
#define SPI_I2SCFGR_ODD_B_0X1       (0x1U<<24U)
#define SPI_I2SCFGR_DATFMT_B_0X0    (0x0U<<14U)
#define SPI_I2SCFGR_DATFMT_B_0X1    (0x1U<<14U)
#define SPI_I2SCFGR_WSINV_B_0X0     (0x0U<<13U)
#define SPI_I2SCFGR_WSINV_B_0X1     (0x1U<<13U)
#define SPI_I2SCFGR_FIXCH_B_0X0     (0x0U<<12U)
#define SPI_I2SCFGR_FIXCH_B_0X1     (0x1U<<12U)
#define SPI_I2SCFGR_CKPOL_B_0X0     (0x0U<<11U)
#define SPI_I2SCFGR_CKPOL_B_0X1     (0x1U<<11U)
#define SPI_I2SCFGR_CHLEN_B_0X0     (0x0U<<10U)
#define SPI_I2SCFGR_CHLEN_B_0X1     (0x1U<<10U)
#define SPI_I2SCFGR_DATLEN_B_0X0    (0x0U<<8U)
#define SPI_I2SCFGR_DATLEN_B_0X1    (0x1U<<8U)
#define SPI_I2SCFGR_DATLEN_B_0X2    (0x2U<<8U)
#define SPI_I2SCFGR_DATLEN_B_0X3    (0x3U<<8U)
#define SPI_I2SCFGR_PCMSYNC_B_0X0   (0x0U<<7U)
#define SPI_I2SCFGR_PCMSYNC_B_0X1   (0x1U<<7U)
#define SPI_I2SCFGR_I2SSTD_B_0X0    (0x0U<<4U)
#define SPI_I2SCFGR_I2SSTD_B_0X1    (0x1U<<4U)
#define SPI_I2SCFGR_I2SSTD_B_0X2    (0x2U<<4U)
#define SPI_I2SCFGR_I2SSTD_B_0X3    (0x3U<<4U)
#define SPI_I2SCFGR_I2SCFG_B_0X0    (0x0U<<1U)
#define SPI_I2SCFGR_I2SCFG_B_0X1    (0x1U<<1U)
#define SPI_I2SCFGR_I2SCFG_B_0X2    (0x2U<<1U)
#define SPI_I2SCFGR_I2SCFG_B_0X3    (0x3U<<1U)
#define SPI_I2SCFGR_I2SCFG_B_0X4    (0x4U<<1U)
#define SPI_I2SCFGR_I2SCFG_B_0X5    (0x5U<<1U)
#define SPI_I2SCFGR_I2SMOD_B_0X0    (0x0U<<0U)
#define SPI_I2SCFGR_I2SMOD_B_0X1    (0x1U<<0U)
