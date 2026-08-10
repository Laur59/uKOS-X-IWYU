/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_dlybsd equates.
 */

#pragma once

#include    <stdint.h>

// DLYBSD address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CFG;
    volatile    uint32_t    STATUS;
} DLYBSD_TypeDef;

#ifdef __cplusplus
#define DLYBSD_NS   reinterpret_cast<DLYBSD_TypeDef *>(0x48028000U)
#define DLYBSD_S    reinterpret_cast<DLYBSD_TypeDef *>(0x58028000U)
#define DLYBSD2_NS  reinterpret_cast<DLYBSD_TypeDef *>(0x48026C00U)
#define DLYBSD2_S   reinterpret_cast<DLYBSD_TypeDef *>(0x58026C00U)

#else
#define DLYBSD_NS   ((DLYBSD_TypeDef *)0x48028000U)
#define DLYBSD_S    ((DLYBSD_TypeDef *)0x58028000U)
#define DLYBSD2_NS  ((DLYBSD_TypeDef *)0x48026C00U)
#define DLYBSD2_S   ((DLYBSD_TypeDef *)0x58026C00U)
#endif

// CFG Configuration

#define DLYBSD_CFG_SDMMC_DLL_ANTIGLITCH_EN  (0x1U<<22U)
#define DLYBSD_CFG_SDMMC_DLL_BYP_CMD        (0x1FU<<17U)
#define DLYBSD_CFG_SDMMC_DLL_BYP_CMD_0      (0x1U<<17U)
#define DLYBSD_CFG_SDMMC_DLL_BYP_EN         (0x1U<<16U)
#define DLYBSD_CFG_SDMMC_RX_TAP_SEL         (0x3FU<<1U)
#define DLYBSD_CFG_SDMMC_RX_TAP_SEL_0       (0x1U<<1U)
#define DLYBSD_CFG_SDMMC_DLL_EN             (0x1U<<0U)

#define DLYBSD_CFG_SDMMC_DLL_BYP_EN_B_0X0   (0x0U<<16U)
#define DLYBSD_CFG_SDMMC_DLL_BYP_EN_B_0X1   (0x1U<<16U)

// STATUS Configuration

#define DLYBSD_STATUS_SDMMC_RX_TAP_SEL_ACK  (0x1U<<1U)
#define DLYBSD_STATUS_SDMMC_DLL_LOCK        (0x1U<<0U)
