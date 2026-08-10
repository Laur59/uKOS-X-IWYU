/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_sdmmc equates.
 */

#pragma once

#include    <stdint.h>

// SDMMC address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    POWER;
    volatile    uint32_t    CLKCR;
    volatile    uint32_t    ARGR;
    volatile    uint32_t    CMDR;
    volatile    uint32_t    RESPCMDR;
    volatile    uint32_t    RESP1R;
    volatile    uint32_t    RESP2R;
    volatile    uint32_t    RESP3R;
    volatile    uint32_t    RESP4R;
    volatile    uint32_t    DTIMER;
    volatile    uint32_t    DLENR;
    volatile    uint32_t    DCTRL;
    volatile    uint32_t    DCNTR;
    volatile    uint32_t    STAR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    MASKR;
    volatile    uint32_t    ACKTIMER;
    volatile    uint32_t    RESERVED0[3];
    volatile    uint32_t    IDMACTRLR;
    volatile    uint32_t    IDMABSIZER;
    volatile    uint32_t    IDMABASE0R;
    volatile    uint32_t    IDMABASE1R;
    volatile    uint32_t    RESERVED1[8];
    volatile    uint32_t    FIFOR;
    volatile    uint32_t    RESERVED2[220];
    volatile    uint32_t    VER;
    volatile    uint32_t    ID;
} SDMMC_TypeDef;

#ifdef __cplusplus
#define SDMMC1  reinterpret_cast<SDMMC_TypeDef *>(0x52007000U)
#define SDMMC2  reinterpret_cast<SDMMC_TypeDef *>(0x48022400U)

#else
#define SDMMC1  ((SDMMC_TypeDef *)0x52007000U)
#define SDMMC2  ((SDMMC_TypeDef *)0x48022400U)
#endif

// POWER Configuration

#define SDMMC_POWER_DIRPOL              (0x1U<<4U)
#define SDMMC_POWER_VSWITCHEN           (0x1U<<3U)
#define SDMMC_POWER_VSWITCH             (0x1U<<2U)
#define SDMMC_POWER_PWRCTRL             (0x3U<<0U)
#define SDMMC_POWER_PWRCTRL_0           (0x1U<<0U)

// CLKCR Configuration

#define SDMMC_CLKCR_SELCLKRX            (0x3U<<20U)
#define SDMMC_CLKCR_SELCLKRX_0          (0x1U<<20U)
#define SDMMC_CLKCR_BUSSPEED            (0x1U<<19U)
#define SDMMC_CLKCR_DDR                 (0x1U<<18U)
#define SDMMC_CLKCR_HWFC_EN             (0x1U<<17U)
#define SDMMC_CLKCR_NEGEDGE             (0x1U<<16U)
#define SDMMC_CLKCR_WIDBUS              (0x3U<<14U)
#define SDMMC_CLKCR_WIDBUS_0            (0x1U<<14U)
#define SDMMC_CLKCR_PWRSAV              (0x1U<<12U)
#define SDMMC_CLKCR_CLKDIV              (0x3FFU<<0U)
#define SDMMC_CLKCR_CLKDIV_0            (0x1U<<0U)

// ARGR Configuration

#define SDMMC_ARGR_CMDARG               (0xFFFFFFFFU<<0U)
#define SDMMC_ARGR_CMDARG_0             (0x1U<<0U)

// CMDR Configuration

#define SDMMC_CMDR_CMDSUSPEND           (0x1U<<16U)
#define SDMMC_CMDR_BOOTEN               (0x1U<<15U)
#define SDMMC_CMDR_BOOTMODE             (0x1U<<14U)
#define SDMMC_CMDR_DTHOLD               (0x1U<<13U)
#define SDMMC_CMDR_CPSMEN               (0x1U<<12U)
#define SDMMC_CMDR_WAITPEND             (0x1U<<11U)
#define SDMMC_CMDR_WAITINT              (0x1U<<10U)
#define SDMMC_CMDR_WAITRESP             (0x3U<<8U)
#define SDMMC_CMDR_WAITRESP_0           (0x1U<<8U)
#define SDMMC_CMDR_CMDSTOP              (0x1U<<7U)
#define SDMMC_CMDR_CMDTRANS             (0x1U<<6U)
#define SDMMC_CMDR_CMDINDEX             (0x3FU<<0U)
#define SDMMC_CMDR_CMDINDEX_0           (0x1U<<0U)

// RESPCMDR Configuration

#define SDMMC_RESPCMDR_RESPCMD          (0x3FU<<0U)
#define SDMMC_RESPCMDR_RESPCMD_0        (0x1U<<0U)

// RESP1R Configuration

#define SDMMC_RESP1R_CARDSTATUS1        (0xFFFFFFFFU<<0U)
#define SDMMC_RESP1R_CARDSTATUS1_0      (0x1U<<0U)

// RESP2R Configuration

#define SDMMC_RESP2R_CARDSTATUS2        (0xFFFFFFFFU<<0U)
#define SDMMC_RESP2R_CARDSTATUS2_0      (0x1U<<0U)

// RESP3R Configuration

#define SDMMC_RESP3R_CARDSTATUS3        (0xFFFFFFFFU<<0U)
#define SDMMC_RESP3R_CARDSTATUS3_0      (0x1U<<0U)

// RESP4R Configuration

#define SDMMC_RESP4R_CARDSTATUS4        (0xFFFFFFFFU<<0U)
#define SDMMC_RESP4R_CARDSTATUS4_0      (0x1U<<0U)

// DTIMER Configuration

#define SDMMC_DTIMER_DATATIME           (0xFFFFFFFFU<<0U)
#define SDMMC_DTIMER_DATATIME_0         (0x1U<<0U)

// DLENR Configuration

#define SDMMC_DLENR_DATALENGTH          (0x1FFFFFFU<<0U)
#define SDMMC_DLENR_DATALENGTH_0        (0x1U<<0U)

// DCTRL Configuration

#define SDMMC_DCTRL_FIFORST             (0x1U<<13U)
#define SDMMC_DCTRL_BOOTACKEN           (0x1U<<12U)
#define SDMMC_DCTRL_SDIOEN              (0x1U<<11U)
#define SDMMC_DCTRL_RWMOD               (0x1U<<10U)
#define SDMMC_DCTRL_RWSTOP              (0x1U<<9U)
#define SDMMC_DCTRL_RWSTART             (0x1U<<8U)
#define SDMMC_DCTRL_DBLOCKSIZE          (0xFU<<4U)
#define SDMMC_DCTRL_DBLOCKSIZE_0        (0x1U<<4U)
#define SDMMC_DCTRL_DTMODE              (0x3U<<2U)
#define SDMMC_DCTRL_DTMODE_0            (0x1U<<2U)
#define SDMMC_DCTRL_DTDIR               (0x1U<<1U)
#define SDMMC_DCTRL_DTEN                (0x1U<<0U)

// DCNTR Configuration

#define SDMMC_DCNTR_DATACOUNT           (0x1FFFFFFU<<0U)
#define SDMMC_DCNTR_DATACOUNT_0         (0x1U<<0U)

// STAR Configuration

#define SDMMC_STAR_IDMABTC              (0x1U<<28U)
#define SDMMC_STAR_IDMATE               (0x1U<<27U)
#define SDMMC_STAR_CKSTOP               (0x1U<<26U)
#define SDMMC_STAR_VSWEND               (0x1U<<25U)
#define SDMMC_STAR_ACKTIMEOUT           (0x1U<<24U)
#define SDMMC_STAR_ACKFAIL              (0x1U<<23U)
#define SDMMC_STAR_SDIOIT               (0x1U<<22U)
#define SDMMC_STAR_BUSYD0END            (0x1U<<21U)
#define SDMMC_STAR_BUSYD0               (0x1U<<20U)
#define SDMMC_STAR_RXFIFOE              (0x1U<<19U)
#define SDMMC_STAR_TXFIFOE              (0x1U<<18U)
#define SDMMC_STAR_RXFIFOF              (0x1U<<17U)
#define SDMMC_STAR_TXFIFOF              (0x1U<<16U)
#define SDMMC_STAR_RXFIFOHF             (0x1U<<15U)
#define SDMMC_STAR_TXFIFOHE             (0x1U<<14U)
#define SDMMC_STAR_CPSMACT              (0x1U<<13U)
#define SDMMC_STAR_DPSMACT              (0x1U<<12U)
#define SDMMC_STAR_DABORT               (0x1U<<11U)
#define SDMMC_STAR_DBCKEND              (0x1U<<10U)
#define SDMMC_STAR_DHOLD                (0x1U<<9U)
#define SDMMC_STAR_DATAEND              (0x1U<<8U)
#define SDMMC_STAR_CMDSENT              (0x1U<<7U)
#define SDMMC_STAR_CMDREND              (0x1U<<6U)
#define SDMMC_STAR_RXOVERR              (0x1U<<5U)
#define SDMMC_STAR_TXUNDERR             (0x1U<<4U)
#define SDMMC_STAR_DTIMEOUT             (0x1U<<3U)
#define SDMMC_STAR_CTIMEOUT             (0x1U<<2U)
#define SDMMC_STAR_DCRCFAIL             (0x1U<<1U)
#define SDMMC_STAR_CCRCFAIL             (0x1U<<0U)

// ICR Configuration

#define SDMMC_ICR_IDMABTCC              (0x1U<<28U)
#define SDMMC_ICR_IDMATEC               (0x1U<<27U)
#define SDMMC_ICR_CKSTOPC               (0x1U<<26U)
#define SDMMC_ICR_VSWENDC               (0x1U<<25U)
#define SDMMC_ICR_ACKTIMEOUTC           (0x1U<<24U)
#define SDMMC_ICR_ACKFAILC              (0x1U<<23U)
#define SDMMC_ICR_SDIOITC               (0x1U<<22U)
#define SDMMC_ICR_BUSYD0ENDC            (0x1U<<21U)
#define SDMMC_ICR_DABORTC               (0x1U<<11U)
#define SDMMC_ICR_DBCKENDC              (0x1U<<10U)
#define SDMMC_ICR_DHOLDC                (0x1U<<9U)
#define SDMMC_ICR_DATAENDC              (0x1U<<8U)
#define SDMMC_ICR_CMDSENTC              (0x1U<<7U)
#define SDMMC_ICR_CMDRENDC              (0x1U<<6U)
#define SDMMC_ICR_RXOVERRC              (0x1U<<5U)
#define SDMMC_ICR_TXUNDERRC             (0x1U<<4U)
#define SDMMC_ICR_DTIMEOUTC             (0x1U<<3U)
#define SDMMC_ICR_CTIMEOUTC             (0x1U<<2U)
#define SDMMC_ICR_DCRCFAILC             (0x1U<<1U)
#define SDMMC_ICR_CCRCFAILC             (0x1U<<0U)

// MASKR Configuration

#define SDMMC_MASKR_IDMABTCIE           (0x1U<<28U)
#define SDMMC_MASKR_CKSTOPIE            (0x1U<<26U)
#define SDMMC_MASKR_VSWENDIE            (0x1U<<25U)
#define SDMMC_MASKR_ACKTIMEOUTIE        (0x1U<<24U)
#define SDMMC_MASKR_ACKFAILIE           (0x1U<<23U)
#define SDMMC_MASKR_SDIOITIE            (0x1U<<22U)
#define SDMMC_MASKR_BUSYD0ENDIE         (0x1U<<21U)
#define SDMMC_MASKR_TXFIFOEIE           (0x1U<<18U)
#define SDMMC_MASKR_RXFIFOFIE           (0x1U<<17U)
#define SDMMC_MASKR_RXFIFOHFIE          (0x1U<<15U)
#define SDMMC_MASKR_TXFIFOHEIE          (0x1U<<14U)
#define SDMMC_MASKR_DABORTIE            (0x1U<<11U)
#define SDMMC_MASKR_DBCKENDIE           (0x1U<<10U)
#define SDMMC_MASKR_DHOLDIE             (0x1U<<9U)
#define SDMMC_MASKR_DATAENDIE           (0x1U<<8U)
#define SDMMC_MASKR_CMDSENTIE           (0x1U<<7U)
#define SDMMC_MASKR_CMDRENDIE           (0x1U<<6U)
#define SDMMC_MASKR_RXOVERRIE           (0x1U<<5U)
#define SDMMC_MASKR_TXUNDERRIE          (0x1U<<4U)
#define SDMMC_MASKR_DTIMEOUTIE          (0x1U<<3U)
#define SDMMC_MASKR_CTIMEOUTIE          (0x1U<<2U)
#define SDMMC_MASKR_DCRCFAILIE          (0x1U<<1U)
#define SDMMC_MASKR_CCRCFAILIE          (0x1U<<0U)

// ACKTIMER Configuration

#define SDMMC_ACKTIMER_ACKTIME          (0x1FFFFFFU<<0U)
#define SDMMC_ACKTIMER_ACKTIME_0        (0x1U<<0U)

// IDMACTRLR Configuration

#define SDMMC_IDMACTRLR_IDMABACT        (0x1U<<2U)
#define SDMMC_IDMACTRLR_IDMABMODE       (0x1U<<1U)
#define SDMMC_IDMACTRLR_IDMAEN          (0x1U<<0U)

// IDMABSIZER Configuration

#define SDMMC_IDMABSIZER_IDMABNDT       (0xFFU<<5U)
#define SDMMC_IDMABSIZER_IDMABNDT_0     (0x1U<<5U)

// IDMABASE0R Configuration

#define SDMMC_IDMABASE0R_IDMABASE0      (0xFFFFFFFFU<<0U)
#define SDMMC_IDMABASE0R_IDMABASE0_0    (0x1U<<0U)

// IDMABASE1R Configuration

#define SDMMC_IDMABASE1R_IDMABASE1      (0xFFFFFFFFU<<0U)
#define SDMMC_IDMABASE1R_IDMABASE1_0    (0x1U<<0U)

// FIFOR Configuration

#define SDMMC_FIFOR_FIFODATA            (0xFFFFFFFFU<<0U)
#define SDMMC_FIFOR_FIFODATA_0          (0x1U<<0U)

// VER Configuration

#define SDMMC_VER_MAJREV                (0xFU<<4U)
#define SDMMC_VER_MAJREV_0              (0x1U<<4U)
#define SDMMC_VER_MINREV                (0xFU<<0U)
#define SDMMC_VER_MINREV_0              (0x1U<<0U)

// ID Configuration

#define SDMMC_ID_IP_ID                  (0xFFFFFFFFU<<0U)
#define SDMMC_ID_IP_ID_0                (0x1U<<0U)
