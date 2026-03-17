/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_application_regulators.
; ===============================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_application_regulators equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// REGULATORS address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[266];
    volatile    uint32_t    MAINREGSTATUS;
    volatile    uint32_t    RESERVED1[53];
    volatile    uint32_t    SYSTEMOFF;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    POFCON;
    volatile    uint32_t    RESERVED3[124];
    volatile    uint32_t    VREGMAIN_DCDCEN;
    volatile    uint32_t    RESERVED4[126];
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    VREGRADIO_DCDCEN;
    volatile    uint32_t    RESERVED6[126];
    volatile    uint32_t    VREGH_DCDCEN;
} REGULATORS_TypeDef;

#ifdef __cplusplus
#define REGULATORS_NS   reinterpret_cast<REGULATORS_TypeDef *>(0x40004000U)
#define REGULATORS_S    reinterpret_cast<REGULATORS_TypeDef *>(0x50004000U)

#else
#define REGULATORS_NS   ((REGULATORS_TypeDef *)0x40004000U)
#define REGULATORS_S    ((REGULATORS_TypeDef *)0x50004000U)
#endif

// MAINREGSTATUS Configuration

#define REGULATORS_MAINREGSTATUS_VREGH                  (0x1U<<0)
#define REGULATORS_MAINREGSTATUS_VREGH_INACTIVE         (0x0U<<0)
#define REGULATORS_MAINREGSTATUS_VREGH_ACTIVE           (0x1U<<0)

// SYSTEMOFF Configuration

#define REGULATORS_SYSTEMOFF_SYSTEMOFF                  (0x1U<<0)
#define REGULATORS_SYSTEMOFF_SYSTEMOFF_ENTER            (0x1U<<0)

// POFCON Configuration

#define REGULATORS_POFCON_THRESHOLDVDDH                 (0xFU<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_0               (0x1U<<8)
#define REGULATORS_POFCON_THRESHOLD                     (0xFU<<1)
#define REGULATORS_POFCON_THRESHOLD_0                   (0x1U<<1)
#define REGULATORS_POFCON_POF                           (0x1U<<0)
#define REGULATORS_POFCON_THRESHOLDVDDH_V27             (0x0U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V28             (0x1U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V29             (0x2U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V30             (0x3U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V31             (0x4U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V32             (0x5U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V33             (0x6U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V34             (0x7U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V35             (0x8U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V36             (0x9U<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V37             (0xAU<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V38             (0xBU<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V39             (0xCU<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V40             (0xDU<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V41             (0xEU<<8)
#define REGULATORS_POFCON_THRESHOLDVDDH_V42             (0xFU<<8)
#define REGULATORS_POFCON_THRESHOLD_V19                 (0x6U<<1)
#define REGULATORS_POFCON_THRESHOLD_V20                 (0x7U<<1)
#define REGULATORS_POFCON_THRESHOLD_V21                 (0x8U<<1)
#define REGULATORS_POFCON_THRESHOLD_V22                 (0x9U<<1)
#define REGULATORS_POFCON_THRESHOLD_V23                 (0xAU<<1)
#define REGULATORS_POFCON_THRESHOLD_V24                 (0xBU<<1)
#define REGULATORS_POFCON_THRESHOLD_V25                 (0xCU<<1)
#define REGULATORS_POFCON_THRESHOLD_V26                 (0xDU<<1)
#define REGULATORS_POFCON_THRESHOLD_V27                 (0xEU<<1)
#define REGULATORS_POFCON_THRESHOLD_V28                 (0xFU<<1)
#define REGULATORS_POFCON_POF_DISABLED                  (0x0U<<0)
#define REGULATORS_POFCON_POF_ENABLED                   (0x1U<<0)

// DCDCEN Configuration

#define REGULATORS_VREGMAIN_DCDCEN_DCDCEN               (0x1U<<0)
#define REGULATORS_VREGMAIN_DCDCEN_DCDCEN_DISABLED      (0x0U<<0)
#define REGULATORS_VREGMAIN_DCDCEN_DCDCEN_ENABLED       (0x1U<<0)

// DCDCEN Configuration

#define REGULATORS_VREGRADIO_DCDCEN_DCDCEN              (0x1U<<0)
#define REGULATORS_VREGRADIO_DCDCEN_DCDCEN_DISABLED     (0x0U<<0)
#define REGULATORS_VREGRADIO_DCDCEN_DCDCEN_ENABLED      (0x1U<<0)

// DCDCEN Configuration

#define REGULATORS_VREGH_DCDCEN_DCDCEN                  (0x1U<<0)
#define REGULATORS_VREGH_DCDCEN_DCDCEN_DISABLED         (0x0U<<0)
#define REGULATORS_VREGH_DCDCEN_DCDCEN_ENABLED          (0x1U<<0)
