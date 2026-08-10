/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_kmu equates.
 */

#pragma once

#include    <stdint.h>

// KMU address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TASKS_PUSH_KEYSLOT;
    volatile    uint32_t    RESERVED0[63];
    volatile    uint32_t    EVENTS_KEYSLOT_PUSHED;
    volatile    uint32_t    EVENTS_KEYSLOT_REVOKED;
    volatile    uint32_t    EVENTS_KEYSLOT_ERROR;
    volatile    uint32_t    RESERVED1[125];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    INTPEND;
    volatile    uint32_t    RESERVED2[63];
    volatile    uint32_t    STATUS;
    volatile    uint32_t    RESERVED3[60];
    volatile    uint32_t    SELECTKEYSLOT;
} KMU_TypeDef;

#ifdef __cplusplus
#define KMU_NS  reinterpret_cast<KMU_TypeDef *>(0x40039000U)
#define KMU_S   reinterpret_cast<KMU_TypeDef *>(0x50039000U)

#else
#define KMU_NS  ((KMU_TypeDef *)0x40039000U)
#define KMU_S   ((KMU_TypeDef *)0x50039000U)
#endif

// TASKS_PUSH_KEYSLOT Configuration

#define KMU_TASKS_PUSH_KEYSLOT_TASKS_PUSH_KEYSLOT                       (0x1U<<0U)
#define KMU_TASKS_PUSH_KEYSLOT_TASKS_PUSH_KEYSLOT_TRIGGER               (0x1U<<0U)

// EVENTS_KEYSLOT_PUSHED Configuration

#define KMU_EVENTS_KEYSLOT_PUSHED_EVENTS_KEYSLOT_PUSHED                 (0x1U<<0U)
#define KMU_EVENTS_KEYSLOT_PUSHED_EVENTS_KEYSLOT_PUSHED_NOTGENERATED    (0x0U<<0U)
#define KMU_EVENTS_KEYSLOT_PUSHED_EVENTS_KEYSLOT_PUSHED_GENERATED       (0x1U<<0U)

// EVENTS_KEYSLOT_REVOKED Configuration

#define KMU_EVENTS_KEYSLOT_REVOKED_EVENTS_KEYSLOT_REVOKED               (0x1U<<0U)
#define KMU_EVENTS_KEYSLOT_REVOKED_EVENTS_KEYSLOT_REVOKED_NOTGENERATED  (0x0U<<0U)
#define KMU_EVENTS_KEYSLOT_REVOKED_EVENTS_KEYSLOT_REVOKED_GENERATED     (0x1U<<0U)

// EVENTS_KEYSLOT_ERROR Configuration

#define KMU_EVENTS_KEYSLOT_ERROR_EVENTS_KEYSLOT_ERROR                   (0x1U<<0U)
#define KMU_EVENTS_KEYSLOT_ERROR_EVENTS_KEYSLOT_ERROR_NOTGENERATED      (0x0U<<0U)
#define KMU_EVENTS_KEYSLOT_ERROR_EVENTS_KEYSLOT_ERROR_GENERATED         (0x1U<<0U)

// INTEN Configuration

#define KMU_INTEN_KEYSLOT_ERROR                                         (0x1U<<2U)
#define KMU_INTEN_KEYSLOT_REVOKED                                       (0x1U<<1U)
#define KMU_INTEN_KEYSLOT_PUSHED                                        (0x1U<<0U)
#define KMU_INTEN_KEYSLOT_ERROR_DISABLED                                (0x0U<<2U)
#define KMU_INTEN_KEYSLOT_ERROR_ENABLED                                 (0x1U<<2U)
#define KMU_INTEN_KEYSLOT_REVOKED_DISABLED                              (0x0U<<1U)
#define KMU_INTEN_KEYSLOT_REVOKED_ENABLED                               (0x1U<<1U)
#define KMU_INTEN_KEYSLOT_PUSHED_DISABLED                               (0x0U<<0U)
#define KMU_INTEN_KEYSLOT_PUSHED_ENABLED                                (0x1U<<0U)

// INTENSET Configuration

#define KMU_INTENSET_KEYSLOT_ERROR                                      (0x1U<<2U)
#define KMU_INTENSET_KEYSLOT_REVOKED                                    (0x1U<<1U)
#define KMU_INTENSET_KEYSLOT_PUSHED                                     (0x1U<<0U)
#define KMU_INTENSET_KEYSLOT_ERROR_DISABLED                             (0x0U<<2U)
#define KMU_INTENSET_KEYSLOT_ERROR_ENABLED                              (0x1U<<2U)
#define KMU_INTENSET_KEYSLOT_ERROR_SET                                  (0x1U<<2U)
#define KMU_INTENSET_KEYSLOT_REVOKED_DISABLED                           (0x0U<<1U)
#define KMU_INTENSET_KEYSLOT_REVOKED_ENABLED                            (0x1U<<1U)
#define KMU_INTENSET_KEYSLOT_REVOKED_SET                                (0x1U<<1U)
#define KMU_INTENSET_KEYSLOT_PUSHED_DISABLED                            (0x0U<<0U)
#define KMU_INTENSET_KEYSLOT_PUSHED_ENABLED                             (0x1U<<0U)
#define KMU_INTENSET_KEYSLOT_PUSHED_SET                                 (0x1U<<0U)

// INTENCLR Configuration

#define KMU_INTENCLR_KEYSLOT_ERROR                                      (0x1U<<2U)
#define KMU_INTENCLR_KEYSLOT_REVOKED                                    (0x1U<<1U)
#define KMU_INTENCLR_KEYSLOT_PUSHED                                     (0x1U<<0U)
#define KMU_INTENCLR_KEYSLOT_ERROR_DISABLED                             (0x0U<<2U)
#define KMU_INTENCLR_KEYSLOT_ERROR_ENABLED                              (0x1U<<2U)
#define KMU_INTENCLR_KEYSLOT_ERROR_CLEAR                                (0x1U<<2U)
#define KMU_INTENCLR_KEYSLOT_REVOKED_DISABLED                           (0x0U<<1U)
#define KMU_INTENCLR_KEYSLOT_REVOKED_ENABLED                            (0x1U<<1U)
#define KMU_INTENCLR_KEYSLOT_REVOKED_CLEAR                              (0x1U<<1U)
#define KMU_INTENCLR_KEYSLOT_PUSHED_DISABLED                            (0x0U<<0U)
#define KMU_INTENCLR_KEYSLOT_PUSHED_ENABLED                             (0x1U<<0U)
#define KMU_INTENCLR_KEYSLOT_PUSHED_CLEAR                               (0x1U<<0U)

// INTPEND Configuration

#define KMU_INTPEND_KEYSLOT_ERROR                                       (0x1U<<2U)
#define KMU_INTPEND_KEYSLOT_REVOKED                                     (0x1U<<1U)
#define KMU_INTPEND_KEYSLOT_PUSHED                                      (0x1U<<0U)
#define KMU_INTPEND_KEYSLOT_ERROR_NOTPENDING                            (0x0U<<2U)
#define KMU_INTPEND_KEYSLOT_ERROR_PENDING                               (0x1U<<2U)
#define KMU_INTPEND_KEYSLOT_REVOKED_NOTPENDING                          (0x0U<<1U)
#define KMU_INTPEND_KEYSLOT_REVOKED_PENDING                             (0x1U<<1U)
#define KMU_INTPEND_KEYSLOT_PUSHED_NOTPENDING                           (0x0U<<0U)
#define KMU_INTPEND_KEYSLOT_PUSHED_PENDING                              (0x1U<<0U)

// STATUS Configuration

#define KMU_STATUS_BLOCKED                                              (0x1U<<1U)
#define KMU_STATUS_SELECTED                                             (0x1U<<0U)
#define KMU_STATUS_BLOCKED_DISABLED                                     (0x0U<<1U)
#define KMU_STATUS_BLOCKED_ENABLED                                      (0x1U<<1U)
#define KMU_STATUS_SELECTED_DISABLED                                    (0x0U<<0U)
#define KMU_STATUS_SELECTED_ENABLED                                     (0x1U<<0U)

// SELECTKEYSLOT Configuration

#define KMU_SELECTKEYSLOT_ID                                            (0xFFU<<0U)
#define KMU_SELECTKEYSLOT_ID_0                                          (0x1U<<0U)
