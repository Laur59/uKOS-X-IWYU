/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_cacheaxi equates.
 */

#pragma once

#include    <stdint.h>

// CACHEAXI address definitions
// ----------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    SR;
    volatile    uint32_t    IER;
    volatile    uint32_t    FCR;
    volatile    uint32_t    RHMONR;
    volatile    uint32_t    RMMONR;
    volatile    uint32_t    RAMMONR;
    volatile    uint32_t    EVIMONR;
    volatile    uint32_t    WHMONR;
    volatile    uint32_t    WMMONR;
    volatile    uint32_t    WAMMONR;
    volatile    uint32_t    WTMONR;
    volatile    uint32_t    RESERVED0[52];
    volatile    uint32_t    CR2;
    volatile    uint32_t    CMDRSADDRR;
    volatile    uint32_t    CMDREADDRR;
} CACHEAXI_TypeDef;

#ifdef __cplusplus
#define CACHEAXI_NS reinterpret_cast<CACHEAXI_TypeDef *>(0x480DFC00U)
#define CACHEAXI_S  reinterpret_cast<CACHEAXI_TypeDef *>(0x580DFC00U)

#else
#define CACHEAXI_NS ((CACHEAXI_TypeDef *)0x480DFC00U)
#define CACHEAXI_S  ((CACHEAXI_TypeDef *)0x580DFC00U)
#endif

// CR1 Configuration

#define CACHEAXI_CR1_EVIMRST                (0x1U<<31)
#define CACHEAXI_CR1_WTMRST                 (0x1U<<30)
#define CACHEAXI_CR1_EVIMEN                 (0x1U<<29)
#define CACHEAXI_CR1_WTMEN                  (0x1U<<28)
#define CACHEAXI_CR1_WAMMRST                (0x1U<<27)
#define CACHEAXI_CR1_RAMMRST                (0x1U<<26)
#define CACHEAXI_CR1_WAMMEN                 (0x1U<<25)
#define CACHEAXI_CR1_RAMMEN                 (0x1U<<24)
#define CACHEAXI_CR1_WMISSMRST              (0x1U<<23)
#define CACHEAXI_CR1_WHITMRST               (0x1U<<22)
#define CACHEAXI_CR1_WMISSMEN               (0x1U<<21)
#define CACHEAXI_CR1_WHITMEN                (0x1U<<20)
#define CACHEAXI_CR1_RMISSMRST              (0x1U<<19)
#define CACHEAXI_CR1_RHITMRST               (0x1U<<18)
#define CACHEAXI_CR1_RMISSMEN               (0x1U<<17)
#define CACHEAXI_CR1_RHITMEN                (0x1U<<16)
#define CACHEAXI_CR1_CACHEINV               (0x1U<<1)
#define CACHEAXI_CR1_EN                     (0x1U<<0)

#define CACHEAXI_CR1_EVIMRST_B_0X0          (0x0U<<31)
#define CACHEAXI_CR1_EVIMRST_B_0X1          (0x1U<<31)
#define CACHEAXI_CR1_WTMRST_B_0X0           (0x0U<<30)
#define CACHEAXI_CR1_WTMRST_B_0X1           (0x1U<<30)
#define CACHEAXI_CR1_EVIMEN_B_0X0           (0x0U<<29)
#define CACHEAXI_CR1_EVIMEN_B_0X1           (0x1U<<29)
#define CACHEAXI_CR1_WTMEN_B_0X0            (0x0U<<28)
#define CACHEAXI_CR1_WTMEN_B_0X1            (0x1U<<28)
#define CACHEAXI_CR1_WAMMRST_B_0X0          (0x0U<<27)
#define CACHEAXI_CR1_WAMMRST_B_0X1          (0x1U<<27)
#define CACHEAXI_CR1_RAMMRST_B_0X0          (0x0U<<26)
#define CACHEAXI_CR1_RAMMRST_B_0X1          (0x1U<<26)
#define CACHEAXI_CR1_WAMMEN_B_0X0           (0x0U<<25)
#define CACHEAXI_CR1_WAMMEN_B_0X1           (0x1U<<25)
#define CACHEAXI_CR1_RAMMEN_B_0X0           (0x0U<<24)
#define CACHEAXI_CR1_RAMMEN_B_0X1           (0x1U<<24)
#define CACHEAXI_CR1_WMISSMRST_B_0X0        (0x0U<<23)
#define CACHEAXI_CR1_WMISSMRST_B_0X1        (0x1U<<23)
#define CACHEAXI_CR1_WHITMRST_B_0X0         (0x0U<<22)
#define CACHEAXI_CR1_WHITMRST_B_0X1         (0x1U<<22)
#define CACHEAXI_CR1_WMISSMEN_B_0X0         (0x0U<<21)
#define CACHEAXI_CR1_WMISSMEN_B_0X1         (0x1U<<21)
#define CACHEAXI_CR1_WHITMEN_B_0X0          (0x0U<<20)
#define CACHEAXI_CR1_WHITMEN_B_0X1          (0x1U<<20)
#define CACHEAXI_CR1_RMISSMRST_B_0X0        (0x0U<<19)
#define CACHEAXI_CR1_RMISSMRST_B_0X1        (0x1U<<19)
#define CACHEAXI_CR1_RHITMRST_B_0X0         (0x0U<<18)
#define CACHEAXI_CR1_RHITMRST_B_0X1         (0x1U<<18)
#define CACHEAXI_CR1_RMISSMEN_B_0X0         (0x0U<<17)
#define CACHEAXI_CR1_RMISSMEN_B_0X1         (0x1U<<17)
#define CACHEAXI_CR1_RHITMEN_B_0X0          (0x0U<<16)
#define CACHEAXI_CR1_RHITMEN_B_0X1          (0x1U<<16)
#define CACHEAXI_CR1_CACHEINV_B_0X0         (0x0U<<1)
#define CACHEAXI_CR1_CACHEINV_B_0X1         (0x1U<<1)
#define CACHEAXI_CR1_EN_B_0X0               (0x0U<<0)
#define CACHEAXI_CR1_EN_B_0X1               (0x1U<<0)

// SR Configuration

#define CACHEAXI_SR_CMDENDF                 (0x1U<<4)
#define CACHEAXI_SR_BUSYCMDF                (0x1U<<3)
#define CACHEAXI_SR_ERRF                    (0x1U<<2)
#define CACHEAXI_SR_BSYENDF                 (0x1U<<1)
#define CACHEAXI_SR_BUSYF                   (0x1U<<0)

#define CACHEAXI_SR_CMDENDF_B_0X0           (0x0U<<4)
#define CACHEAXI_SR_CMDENDF_B_0X1           (0x1U<<4)
#define CACHEAXI_SR_BUSYCMDF_B_0X0          (0x0U<<3)
#define CACHEAXI_SR_BUSYCMDF_B_0X1          (0x1U<<3)
#define CACHEAXI_SR_ERRF_B_0X0              (0x0U<<2)
#define CACHEAXI_SR_ERRF_B_0X1              (0x1U<<2)
#define CACHEAXI_SR_BSYENDF_B_0X0           (0x0U<<1)
#define CACHEAXI_SR_BSYENDF_B_0X1           (0x1U<<1)
#define CACHEAXI_SR_BUSYF_B_0X0             (0x0U<<0)
#define CACHEAXI_SR_BUSYF_B_0X1             (0x1U<<0)

// IER Configuration

#define CACHEAXI_IER_CMDENDIE               (0x1U<<4)
#define CACHEAXI_IER_ERRIE                  (0x1U<<2)
#define CACHEAXI_IER_BSYENDIE               (0x1U<<1)

#define CACHEAXI_IER_CMDENDIE_B_0X0         (0x0U<<4)
#define CACHEAXI_IER_CMDENDIE_B_0X1         (0x1U<<4)
#define CACHEAXI_IER_ERRIE_B_0X0            (0x0U<<2)
#define CACHEAXI_IER_ERRIE_B_0X1            (0x1U<<2)
#define CACHEAXI_IER_BSYENDIE_B_0X0         (0x0U<<1)
#define CACHEAXI_IER_BSYENDIE_B_0X1         (0x1U<<1)

// FCR Configuration

#define CACHEAXI_FCR_CCMDENDF               (0x1U<<4)
#define CACHEAXI_FCR_CERRF                  (0x1U<<2)
#define CACHEAXI_FCR_CBSYENDF               (0x1U<<1)

#define CACHEAXI_FCR_CCMDENDF_B_0X0         (0x0U<<4)
#define CACHEAXI_FCR_CCMDENDF_B_0X1         (0x1U<<4)
#define CACHEAXI_FCR_CERRF_B_0X0            (0x0U<<2)
#define CACHEAXI_FCR_CERRF_B_0X1            (0x1U<<2)
#define CACHEAXI_FCR_CBSYENDF_B_0X0         (0x0U<<1)
#define CACHEAXI_FCR_CBSYENDF_B_0X1         (0x1U<<1)

// RHMONR Configuration

#define CACHEAXI_RHMONR_RHITMON             (0xFFFFFFFFU<<0)
#define CACHEAXI_RHMONR_RHITMON_0           (0x1U<<0)

// RMMONR Configuration

#define CACHEAXI_RMMONR_RMISSMON            (0xFFFFFFFFU<<0)
#define CACHEAXI_RMMONR_RMISSMON_0          (0x1U<<0)

// RAMMONR Configuration

#define CACHEAXI_RAMMONR_RAMMON             (0xFFFFFFFFU<<0)
#define CACHEAXI_RAMMONR_RAMMON_0           (0x1U<<0)

// EVIMONR Configuration

#define CACHEAXI_EVIMONR_EVIMON             (0xFFFFFFFFU<<0)
#define CACHEAXI_EVIMONR_EVIMON_0           (0x1U<<0)

// WHMONR Configuration

#define CACHEAXI_WHMONR_WHITMON             (0xFFFFFFFFU<<0)
#define CACHEAXI_WHMONR_WHITMON_0           (0x1U<<0)

// WMMONR Configuration

#define CACHEAXI_WMMONR_WMISSMON            (0xFFFFFFFFU<<0)
#define CACHEAXI_WMMONR_WMISSMON_0          (0x1U<<0)

// WAMMONR Configuration

#define CACHEAXI_WAMMONR_WAMMON             (0xFFFFFFFFU<<0)
#define CACHEAXI_WAMMONR_WAMMON_0           (0x1U<<0)

// WTMONR Configuration

#define CACHEAXI_WTMONR_WTMON               (0xFFFFFFFFU<<0)
#define CACHEAXI_WTMONR_WTMON_0             (0x1U<<0)

// CR2 Configuration

#define CACHEAXI_CR2_CACHECMD               (0x3U<<1)
#define CACHEAXI_CR2_CACHECMD_0             (0x1U<<1)
#define CACHEAXI_CR2_STARTCMD               (0x1U<<0)

#define CACHEAXI_CR2_CACHECMD_B_0X0         (0x0U<<1)
#define CACHEAXI_CR2_CACHECMD_B_0X1         (0x1U<<1)
#define CACHEAXI_CR2_CACHECMD_B_0X3         (0x3U<<1)
#define CACHEAXI_CR2_STARTCMD_B_0X0         (0x0U<<0)
#define CACHEAXI_CR2_STARTCMD_B_0X1         (0x1U<<0)

// CMDRSADDRR Configuration

#define CACHEAXI_CMDRSADDRR_CMDSTARTADDR    (0x3FFFFFFU<<6)
#define CACHEAXI_CMDRSADDRR_CMDSTARTADDR_0  (0x1U<<6)

// CMDREADDRR Configuration

#define CACHEAXI_CMDREADDRR_CMDENDADDR      (0x3FFFFFFU<<6)
#define CACHEAXI_CMDREADDRR_CMDENDADDR_0    (0x1U<<6)
