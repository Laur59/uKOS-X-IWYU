/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_ctrlapperi equates.
 */

#pragma once

#include    <stdint.h>

// CTRLAPPERI address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[256];
    volatile    uint32_t    MAILBOX_RXDATA;
    volatile    uint32_t    MAILBOX_RXSTATUS;
    volatile    uint32_t    RESERVED1[30];
    volatile    uint32_t    MAILBOX_TXDATA;
    volatile    uint32_t    MAILBOX_TXSTATUS;
    volatile    uint32_t    RESERVED2[30];
    volatile    uint32_t    ERASEPROTECT_LOCK;
    volatile    uint32_t    ERASEPROTECT_DISABLE;
    volatile    uint32_t    RESERVED3[14];
    volatile    uint32_t    APPROTECT_LOCK;
    volatile    uint32_t    APPROTECT_DISABLE;
    volatile    uint32_t    RESERVED4[46];
    volatile    uint32_t    STATUS;
} CTRLAPPERI_TypeDef;

#ifdef __cplusplus
#define CTRLAP_NS   reinterpret_cast<CTRLAPPERI_TypeDef *>(0x41006000U)

#else
#define CTRLAP_NS   ((CTRLAPPERI_TypeDef *)0x41006000U)
#endif

// RXDATA Configuration

#define CTRLAPPERI_MAILBOX_RXDATA_RXDATA                    (0xFFFFFFFFU<<0U)
#define CTRLAPPERI_MAILBOX_RXDATA_RXDATA_0                  (0x1U<<0U)

// RXSTATUS Configuration

#define CTRLAPPERI_MAILBOX_RXSTATUS_RXSTATUS                (0x1U<<0U)
#define CTRLAPPERI_MAILBOX_RXSTATUS_RXSTATUS_NODATAPENDING  (0x0U<<0U)
#define CTRLAPPERI_MAILBOX_RXSTATUS_RXSTATUS_DATAPENDING    (0x1U<<0U)

// TXDATA Configuration

#define CTRLAPPERI_MAILBOX_TXDATA_TXDATA                    (0xFFFFFFFFU<<0U)
#define CTRLAPPERI_MAILBOX_TXDATA_TXDATA_0                  (0x1U<<0U)

// TXSTATUS Configuration

#define CTRLAPPERI_MAILBOX_TXSTATUS_TXSTATUS                (0x1U<<0U)
#define CTRLAPPERI_MAILBOX_TXSTATUS_TXSTATUS_NODATAPENDING  (0x0U<<0U)
#define CTRLAPPERI_MAILBOX_TXSTATUS_TXSTATUS_DATAPENDING    (0x1U<<0U)

// LOCK Configuration

#define CTRLAPPERI_ERASEPROTECT_LOCK_LOCK                   (0x1U<<0U)
#define CTRLAPPERI_ERASEPROTECT_LOCK_LOCK_UNLOCKED          (0x0U<<0U)
#define CTRLAPPERI_ERASEPROTECT_LOCK_LOCK_LOCKED            (0x1U<<0U)

// DISABLE Configuration

#define CTRLAPPERI_ERASEPROTECT_DISABLE_KEY                 (0xFFFFFFFFU<<0U)
#define CTRLAPPERI_ERASEPROTECT_DISABLE_KEY_0               (0x1U<<0U)

// LOCK Configuration

#define CTRLAPPERI_APPROTECT_LOCK_LOCK                      (0x1U<<0U)
#define CTRLAPPERI_APPROTECT_LOCK_LOCK_UNLOCKED             (0x0U<<0U)
#define CTRLAPPERI_APPROTECT_LOCK_LOCK_LOCKED               (0x1U<<0U)

// DISABLE Configuration

#define CTRLAPPERI_APPROTECT_DISABLE_KEY                    (0xFFFFFFFFU<<0U)
#define CTRLAPPERI_APPROTECT_DISABLE_KEY_0                  (0x1U<<0U)

// STATUS Configuration

#define CTRLAPPERI_STATUS_DBGIFACEMODE                      (0x1U<<2U)
#define CTRLAPPERI_STATUS_UICRAPPROTECT                     (0x1U<<0U)
#define CTRLAPPERI_STATUS_DBGIFACEMODE_DISABLED             (0x0U<<2U)
#define CTRLAPPERI_STATUS_DBGIFACEMODE_ENABLED              (0x1U<<2U)
#define CTRLAPPERI_STATUS_UICRAPPROTECT_ENABLED             (0x0U<<0U)
#define CTRLAPPERI_STATUS_UICRAPPROTECT_DISABLED            (0x1U<<0U)
