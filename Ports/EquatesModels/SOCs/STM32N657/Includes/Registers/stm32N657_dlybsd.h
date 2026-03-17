/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_dlybsd.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_dlybsd equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define DLYBSD_CFG_SDMMC_DLL_ANTIGLITCH_EN  (0x1U<<22)
#define DLYBSD_CFG_SDMMC_DLL_BYP_CMD        (0x1FU<<17)
#define DLYBSD_CFG_SDMMC_DLL_BYP_CMD_0      (0x1U<<17)
#define DLYBSD_CFG_SDMMC_DLL_BYP_EN         (0x1U<<16)
#define DLYBSD_CFG_SDMMC_RX_TAP_SEL         (0x3FU<<1)
#define DLYBSD_CFG_SDMMC_RX_TAP_SEL_0       (0x1U<<1)
#define DLYBSD_CFG_SDMMC_DLL_EN             (0x1U<<0)

#define DLYBSD_CFG_SDMMC_DLL_BYP_EN_B_0X0   (0x0U<<16)
#define DLYBSD_CFG_SDMMC_DLL_BYP_EN_B_0X1   (0x1U<<16)

// STATUS Configuration

#define DLYBSD_STATUS_SDMMC_RX_TAP_SEL_ACK  (0x1U<<1)
#define DLYBSD_STATUS_SDMMC_DLL_LOCK        (0x1U<<0)
