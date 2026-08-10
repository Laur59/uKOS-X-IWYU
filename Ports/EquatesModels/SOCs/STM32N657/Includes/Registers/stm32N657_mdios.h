/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_mdios equates.
 */

#pragma once

#include    <stdint.h>

// MDIOS address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    WRFR;
    volatile    uint32_t    CWRFR;
    volatile    uint32_t    RDFR;
    volatile    uint32_t    CRDFR;
    volatile    uint32_t    SR;
    volatile    uint32_t    CLRFR;
    volatile    uint32_t    RESERVED0[57];
    volatile    uint32_t    DINR0;
    volatile    uint32_t    DINR1;
    volatile    uint32_t    DINR2;
    volatile    uint32_t    DINR3;
    volatile    uint32_t    DINR4;
    volatile    uint32_t    DINR5;
    volatile    uint32_t    DINR6;
    volatile    uint32_t    DINR7;
    volatile    uint32_t    DINR8;
    volatile    uint32_t    DINR9;
    volatile    uint32_t    DINR10;
    volatile    uint32_t    DINR11;
    volatile    uint32_t    DINR12;
    volatile    uint32_t    DINR13;
    volatile    uint32_t    DINR14;
    volatile    uint32_t    DINR15;
    volatile    uint32_t    DINR16;
    volatile    uint32_t    DINR17;
    volatile    uint32_t    DINR18;
    volatile    uint32_t    DINR19;
    volatile    uint32_t    DINR20;
    volatile    uint32_t    DINR21;
    volatile    uint32_t    DINR22;
    volatile    uint32_t    DINR23;
    volatile    uint32_t    DINR24;
    volatile    uint32_t    DINR25;
    volatile    uint32_t    DINR26;
    volatile    uint32_t    DINR27;
    volatile    uint32_t    DINR28;
    volatile    uint32_t    DINR29;
    volatile    uint32_t    DINR30;
    volatile    uint32_t    DINR31;
    volatile    uint32_t    DOUTR0;
    volatile    uint32_t    DOUTR1;
    volatile    uint32_t    DOUTR2;
    volatile    uint32_t    DOUTR3;
    volatile    uint32_t    DOUTR4;
    volatile    uint32_t    DOUTR5;
    volatile    uint32_t    DOUTR6;
    volatile    uint32_t    DOUTR7;
    volatile    uint32_t    DOUTR8;
    volatile    uint32_t    DOUTR9;
    volatile    uint32_t    DOUTR10;
    volatile    uint32_t    DOUTR11;
    volatile    uint32_t    DOUTR12;
    volatile    uint32_t    DOUTR13;
    volatile    uint32_t    DOUTR14;
    volatile    uint32_t    DOUTR15;
    volatile    uint32_t    DOUTR16;
    volatile    uint32_t    DOUTR17;
    volatile    uint32_t    DOUTR18;
    volatile    uint32_t    DOUTR19;
    volatile    uint32_t    DOUTR20;
    volatile    uint32_t    DOUTR21;
    volatile    uint32_t    DOUTR22;
    volatile    uint32_t    DOUTR23;
    volatile    uint32_t    DOUTR24;
    volatile    uint32_t    DOUTR25;
    volatile    uint32_t    DOUTR26;
    volatile    uint32_t    DOUTR27;
    volatile    uint32_t    DOUTR28;
    volatile    uint32_t    DOUTR29;
    volatile    uint32_t    DOUTR30;
    volatile    uint32_t    DOUTR31;
} MDIOS_TypeDef;

#ifdef __cplusplus
#define MDIOS_NS    reinterpret_cast<MDIOS_TypeDef *>(0x40009400U)
#define MDIOS_S     reinterpret_cast<MDIOS_TypeDef *>(0x50009400U)

#else
#define MDIOS_NS    ((MDIOS_TypeDef *)0x40009400U)
#define MDIOS_S     ((MDIOS_TypeDef *)0x50009400U)
#endif

// CR Configuration

#define MDIOS_CR_PORT_ADDRESS   (0x1FU<<8U)
#define MDIOS_CR_PORT_ADDRESS_0 (0x1U<<8U)
#define MDIOS_CR_DPC            (0x1U<<7U)
#define MDIOS_CR_EIE            (0x1U<<3U)
#define MDIOS_CR_RDIE           (0x1U<<2U)
#define MDIOS_CR_WRIE           (0x1U<<1U)
#define MDIOS_CR_EN             (0x1U<<0U)

#define MDIOS_CR_DPC_B_0X0      (0x0U<<7U)
#define MDIOS_CR_DPC_B_0X1      (0x1U<<7U)
#define MDIOS_CR_EIE_B_0X0      (0x0U<<3U)
#define MDIOS_CR_EIE_B_0X1      (0x1U<<3U)
#define MDIOS_CR_RDIE_B_0X0     (0x0U<<2U)
#define MDIOS_CR_RDIE_B_0X1     (0x1U<<2U)
#define MDIOS_CR_WRIE_B_0X0     (0x0U<<1U)
#define MDIOS_CR_WRIE_B_0X1     (0x1U<<1U)
#define MDIOS_CR_EN_B_0X0       (0x0U<<0U)
#define MDIOS_CR_EN_B_0X1       (0x1U<<0U)

// WRFR Configuration

#define MDIOS_WRFR_WRF          (0xFFFFFFFFU<<0U)
#define MDIOS_WRFR_WRF_0        (0x1U<<0U)

#define MDIOS_WRFR_WRF_B_0X0    (0x0U<<0U)
#define MDIOS_WRFR_WRF_B_0X1    (0x1U<<0U)

// CWRFR Configuration

#define MDIOS_CWRFR_CWRF        (0xFFFFFFFFU<<0U)
#define MDIOS_CWRFR_CWRF_0      (0x1U<<0U)

// RDFR Configuration

#define MDIOS_RDFR_RDF          (0xFFFFFFFFU<<0U)
#define MDIOS_RDFR_RDF_0        (0x1U<<0U)

#define MDIOS_RDFR_RDF_B_0X0    (0x0U<<0U)
#define MDIOS_RDFR_RDF_B_0X1    (0x1U<<0U)

// CRDFR Configuration

#define MDIOS_CRDFR_CRDF        (0xFFFFFFFFU<<0U)
#define MDIOS_CRDFR_CRDF_0      (0x1U<<0U)

// SR Configuration

#define MDIOS_SR_TERF           (0x1U<<2U)
#define MDIOS_SR_SERF           (0x1U<<1U)
#define MDIOS_SR_PERF           (0x1U<<0U)

#define MDIOS_SR_TERF_B_0X0     (0x0U<<2U)
#define MDIOS_SR_TERF_B_0X1     (0x1U<<2U)
#define MDIOS_SR_SERF_B_0X0     (0x0U<<1U)
#define MDIOS_SR_SERF_B_0X1     (0x1U<<1U)
#define MDIOS_SR_PERF_B_0X0     (0x0U<<0U)
#define MDIOS_SR_PERF_B_0X1     (0x1U<<0U)

// CLRFR Configuration

#define MDIOS_CLRFR_CTERF       (0x1U<<2U)
#define MDIOS_CLRFR_CSERF       (0x1U<<1U)
#define MDIOS_CLRFR_CPERF       (0x1U<<0U)

// DINR0 Configuration

#define MDIOS_DINR0_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR0_DIN_0       (0x1U<<0U)

// DINR1 Configuration

#define MDIOS_DINR1_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR1_DIN_0       (0x1U<<0U)

// DINR2 Configuration

#define MDIOS_DINR2_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR2_DIN_0       (0x1U<<0U)

// DINR3 Configuration

#define MDIOS_DINR3_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR3_DIN_0       (0x1U<<0U)

// DINR4 Configuration

#define MDIOS_DINR4_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR4_DIN_0       (0x1U<<0U)

// DINR5 Configuration

#define MDIOS_DINR5_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR5_DIN_0       (0x1U<<0U)

// DINR6 Configuration

#define MDIOS_DINR6_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR6_DIN_0       (0x1U<<0U)

// DINR7 Configuration

#define MDIOS_DINR7_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR7_DIN_0       (0x1U<<0U)

// DINR8 Configuration

#define MDIOS_DINR8_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR8_DIN_0       (0x1U<<0U)

// DINR9 Configuration

#define MDIOS_DINR9_DIN         (0xFFFFU<<0U)
#define MDIOS_DINR9_DIN_0       (0x1U<<0U)

// DINR10 Configuration

#define MDIOS_DINR10_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR10_DIN_0      (0x1U<<0U)

// DINR11 Configuration

#define MDIOS_DINR11_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR11_DIN_0      (0x1U<<0U)

// DINR12 Configuration

#define MDIOS_DINR12_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR12_DIN_0      (0x1U<<0U)

// DINR13 Configuration

#define MDIOS_DINR13_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR13_DIN_0      (0x1U<<0U)

// DINR14 Configuration

#define MDIOS_DINR14_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR14_DIN_0      (0x1U<<0U)

// DINR15 Configuration

#define MDIOS_DINR15_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR15_DIN_0      (0x1U<<0U)

// DINR16 Configuration

#define MDIOS_DINR16_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR16_DIN_0      (0x1U<<0U)

// DINR17 Configuration

#define MDIOS_DINR17_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR17_DIN_0      (0x1U<<0U)

// DINR18 Configuration

#define MDIOS_DINR18_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR18_DIN_0      (0x1U<<0U)

// DINR19 Configuration

#define MDIOS_DINR19_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR19_DIN_0      (0x1U<<0U)

// DINR20 Configuration

#define MDIOS_DINR20_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR20_DIN_0      (0x1U<<0U)

// DINR21 Configuration

#define MDIOS_DINR21_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR21_DIN_0      (0x1U<<0U)

// DINR22 Configuration

#define MDIOS_DINR22_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR22_DIN_0      (0x1U<<0U)

// DINR23 Configuration

#define MDIOS_DINR23_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR23_DIN_0      (0x1U<<0U)

// DINR24 Configuration

#define MDIOS_DINR24_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR24_DIN_0      (0x1U<<0U)

// DINR25 Configuration

#define MDIOS_DINR25_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR25_DIN_0      (0x1U<<0U)

// DINR26 Configuration

#define MDIOS_DINR26_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR26_DIN_0      (0x1U<<0U)

// DINR27 Configuration

#define MDIOS_DINR27_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR27_DIN_0      (0x1U<<0U)

// DINR28 Configuration

#define MDIOS_DINR28_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR28_DIN_0      (0x1U<<0U)

// DINR29 Configuration

#define MDIOS_DINR29_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR29_DIN_0      (0x1U<<0U)

// DINR30 Configuration

#define MDIOS_DINR30_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR30_DIN_0      (0x1U<<0U)

// DINR31 Configuration

#define MDIOS_DINR31_DIN        (0xFFFFU<<0U)
#define MDIOS_DINR31_DIN_0      (0x1U<<0U)

// DOUTR0 Configuration

#define MDIOS_DOUTR0_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR0_DOUT_0     (0x1U<<0U)

// DOUTR1 Configuration

#define MDIOS_DOUTR1_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR1_DOUT_0     (0x1U<<0U)

// DOUTR2 Configuration

#define MDIOS_DOUTR2_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR2_DOUT_0     (0x1U<<0U)

// DOUTR3 Configuration

#define MDIOS_DOUTR3_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR3_DOUT_0     (0x1U<<0U)

// DOUTR4 Configuration

#define MDIOS_DOUTR4_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR4_DOUT_0     (0x1U<<0U)

// DOUTR5 Configuration

#define MDIOS_DOUTR5_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR5_DOUT_0     (0x1U<<0U)

// DOUTR6 Configuration

#define MDIOS_DOUTR6_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR6_DOUT_0     (0x1U<<0U)

// DOUTR7 Configuration

#define MDIOS_DOUTR7_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR7_DOUT_0     (0x1U<<0U)

// DOUTR8 Configuration

#define MDIOS_DOUTR8_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR8_DOUT_0     (0x1U<<0U)

// DOUTR9 Configuration

#define MDIOS_DOUTR9_DOUT       (0xFFFFU<<0U)
#define MDIOS_DOUTR9_DOUT_0     (0x1U<<0U)

// DOUTR10 Configuration

#define MDIOS_DOUTR10_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR10_DOUT_0    (0x1U<<0U)

// DOUTR11 Configuration

#define MDIOS_DOUTR11_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR11_DOUT_0    (0x1U<<0U)

// DOUTR12 Configuration

#define MDIOS_DOUTR12_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR12_DOUT_0    (0x1U<<0U)

// DOUTR13 Configuration

#define MDIOS_DOUTR13_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR13_DOUT_0    (0x1U<<0U)

// DOUTR14 Configuration

#define MDIOS_DOUTR14_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR14_DOUT_0    (0x1U<<0U)

// DOUTR15 Configuration

#define MDIOS_DOUTR15_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR15_DOUT_0    (0x1U<<0U)

// DOUTR16 Configuration

#define MDIOS_DOUTR16_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR16_DOUT_0    (0x1U<<0U)

// DOUTR17 Configuration

#define MDIOS_DOUTR17_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR17_DOUT_0    (0x1U<<0U)

// DOUTR18 Configuration

#define MDIOS_DOUTR18_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR18_DOUT_0    (0x1U<<0U)

// DOUTR19 Configuration

#define MDIOS_DOUTR19_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR19_DOUT_0    (0x1U<<0U)

// DOUTR20 Configuration

#define MDIOS_DOUTR20_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR20_DOUT_0    (0x1U<<0U)

// DOUTR21 Configuration

#define MDIOS_DOUTR21_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR21_DOUT_0    (0x1U<<0U)

// DOUTR22 Configuration

#define MDIOS_DOUTR22_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR22_DOUT_0    (0x1U<<0U)

// DOUTR23 Configuration

#define MDIOS_DOUTR23_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR23_DOUT_0    (0x1U<<0U)

// DOUTR24 Configuration

#define MDIOS_DOUTR24_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR24_DOUT_0    (0x1U<<0U)

// DOUTR25 Configuration

#define MDIOS_DOUTR25_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR25_DOUT_0    (0x1U<<0U)

// DOUTR26 Configuration

#define MDIOS_DOUTR26_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR26_DOUT_0    (0x1U<<0U)

// DOUTR27 Configuration

#define MDIOS_DOUTR27_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR27_DOUT_0    (0x1U<<0U)

// DOUTR28 Configuration

#define MDIOS_DOUTR28_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR28_DOUT_0    (0x1U<<0U)

// DOUTR29 Configuration

#define MDIOS_DOUTR29_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR29_DOUT_0    (0x1U<<0U)

// DOUTR30 Configuration

#define MDIOS_DOUTR30_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR30_DOUT_0    (0x1U<<0U)

// DOUTR31 Configuration

#define MDIOS_DOUTR31_DOUT      (0xFFFFU<<0U)
#define MDIOS_DOUTR31_DOUT_0    (0x1U<<0U)
