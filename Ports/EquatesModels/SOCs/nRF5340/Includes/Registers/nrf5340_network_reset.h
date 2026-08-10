/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_reset equates.
 */

#pragma once

#include    <stdint.h>

// RESET address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[256];
    volatile    uint32_t    RESETREAS;
} RESET_TypeDef;

#ifdef __cplusplus
#define RESET_NS    reinterpret_cast<RESET_TypeDef *>(0x41005000U)

#else
#define RESET_NS    ((RESET_TypeDef *)0x41005000U)
#endif

// RESETREAS Configuration

#define RESET_RESETREAS_LCTRLAP                 (0x1U<<27U)
#define RESET_RESETREAS_VBUS                    (0x1U<<26U)
#define RESET_RESETREAS_DOG1                    (0x1U<<25U)
#define RESET_RESETREAS_NFC                     (0x1U<<24U)
#define RESET_RESETREAS_MFORCEOFF               (0x1U<<23U)
#define RESET_RESETREAS_LDOG                    (0x1U<<18U)
#define RESET_RESETREAS_LLOCKUP                 (0x1U<<17U)
#define RESET_RESETREAS_LSREQ                   (0x1U<<16U)
#define RESET_RESETREAS_DIF                     (0x1U<<7U)
#define RESET_RESETREAS_LPCOMP                  (0x1U<<6U)
#define RESET_RESETREAS_OFF                     (0x1U<<5U)
#define RESET_RESETREAS_LOCKUP                  (0x1U<<4U)
#define RESET_RESETREAS_SREQ                    (0x1U<<3U)
#define RESET_RESETREAS_CTRLAP                  (0x1U<<2U)
#define RESET_RESETREAS_DOG0                    (0x1U<<1U)
#define RESET_RESETREAS_RESETPIN                (0x1U<<0U)
#define RESET_RESETREAS_LCTRLAP_NOTDETECTED     (0x0U<<27U)
#define RESET_RESETREAS_LCTRLAP_DETECTED        (0x1U<<27U)
#define RESET_RESETREAS_VBUS_NOTDETECTED        (0x0U<<26U)
#define RESET_RESETREAS_VBUS_DETECTED           (0x1U<<26U)
#define RESET_RESETREAS_DOG1_NOTDETECTED        (0x0U<<25U)
#define RESET_RESETREAS_DOG1_DETECTED           (0x1U<<25U)
#define RESET_RESETREAS_NFC_NOTDETECTED         (0x0U<<24U)
#define RESET_RESETREAS_NFC_DETECTED            (0x1U<<24U)
#define RESET_RESETREAS_MFORCEOFF_NOTDETECTED   (0x0U<<23U)
#define RESET_RESETREAS_MFORCEOFF_DETECTED      (0x1U<<23U)
#define RESET_RESETREAS_LDOG_NOTDETECTED        (0x0U<<18U)
#define RESET_RESETREAS_LDOG_DETECTED           (0x1U<<18U)
#define RESET_RESETREAS_LLOCKUP_NOTDETECTED     (0x0U<<17U)
#define RESET_RESETREAS_LLOCKUP_DETECTED        (0x1U<<17U)
#define RESET_RESETREAS_LSREQ_NOTDETECTED       (0x0U<<16U)
#define RESET_RESETREAS_LSREQ_DETECTED          (0x1U<<16U)
#define RESET_RESETREAS_DIF_NOTDETECTED         (0x0U<<7U)
#define RESET_RESETREAS_DIF_DETECTED            (0x1U<<7U)
#define RESET_RESETREAS_LPCOMP_NOTDETECTED      (0x0U<<6U)
#define RESET_RESETREAS_LPCOMP_DETECTED         (0x1U<<6U)
#define RESET_RESETREAS_OFF_NOTDETECTED         (0x0U<<5U)
#define RESET_RESETREAS_OFF_DETECTED            (0x1U<<5U)
#define RESET_RESETREAS_LOCKUP_NOTDETECTED      (0x0U<<4U)
#define RESET_RESETREAS_LOCKUP_DETECTED         (0x1U<<4U)
#define RESET_RESETREAS_SREQ_NOTDETECTED        (0x0U<<3U)
#define RESET_RESETREAS_SREQ_DETECTED           (0x1U<<3U)
#define RESET_RESETREAS_CTRLAP_NOTDETECTED      (0x0U<<2U)
#define RESET_RESETREAS_CTRLAP_DETECTED         (0x1U<<2U)
#define RESET_RESETREAS_DOG0_NOTDETECTED        (0x0U<<1U)
#define RESET_RESETREAS_DOG0_DETECTED           (0x1U<<1U)
#define RESET_RESETREAS_RESETPIN_NOTDETECTED    (0x0U<<0U)
#define RESET_RESETREAS_RESETPIN_DETECTED       (0x1U<<0U)
