/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_rng equates.
 */

#pragma once

#include    <stdint.h>

// RNG address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TASKS_START;
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    RESERVED0[30];
    volatile    uint32_t    SUBSCRIBE_START;
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    RESERVED1[30];
    volatile    uint32_t    EVENTS_VALRDY;
    volatile    uint32_t    RESERVED2[31];
    volatile    uint32_t    PUBLISH_VALRDY;
    volatile    uint32_t    RESERVED3[31];
    volatile    uint32_t    SHORTS;
    volatile    uint32_t    RESERVED4[64];
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED5[126];
    volatile    uint32_t    CONFIG;
    volatile    uint32_t    VALUE;
} RNG_TypeDef;

#ifdef __cplusplus
#define RNG_NS  reinterpret_cast<RNG_TypeDef *>(0x41009000U)

#else
#define RNG_NS  ((RNG_TypeDef *)0x41009000U)
#endif

// TASKS_START Configuration

#define RNG_TASKS_START_TASKS_START                     (0x1U<<0U)
#define RNG_TASKS_START_TASKS_START_TRIGGER             (0x1U<<0U)

// TASKS_STOP Configuration

#define RNG_TASKS_STOP_TASKS_STOP                       (0x1U<<0U)
#define RNG_TASKS_STOP_TASKS_STOP_TRIGGER               (0x1U<<0U)

// SUBSCRIBE_START Configuration

#define RNG_SUBSCRIBE_START_EN                          (0x1U<<31U)
#define RNG_SUBSCRIBE_START_CHIDX                       (0xFFU<<0U)
#define RNG_SUBSCRIBE_START_CHIDX_0                     (0x1U<<0U)
#define RNG_SUBSCRIBE_START_EN_DISABLED                 (0x0U<<31U)
#define RNG_SUBSCRIBE_START_EN_ENABLED                  (0x1U<<31U)

// SUBSCRIBE_STOP Configuration

#define RNG_SUBSCRIBE_STOP_EN                           (0x1U<<31U)
#define RNG_SUBSCRIBE_STOP_CHIDX                        (0xFFU<<0U)
#define RNG_SUBSCRIBE_STOP_CHIDX_0                      (0x1U<<0U)
#define RNG_SUBSCRIBE_STOP_EN_DISABLED                  (0x0U<<31U)
#define RNG_SUBSCRIBE_STOP_EN_ENABLED                   (0x1U<<31U)

// EVENTS_VALRDY Configuration

#define RNG_EVENTS_VALRDY_EVENTS_VALRDY                 (0x1U<<0U)
#define RNG_EVENTS_VALRDY_EVENTS_VALRDY_NOTGENERATED    (0x0U<<0U)
#define RNG_EVENTS_VALRDY_EVENTS_VALRDY_GENERATED       (0x1U<<0U)

// PUBLISH_VALRDY Configuration

#define RNG_PUBLISH_VALRDY_EN                           (0x1U<<31U)
#define RNG_PUBLISH_VALRDY_CHIDX                        (0xFFU<<0U)
#define RNG_PUBLISH_VALRDY_CHIDX_0                      (0x1U<<0U)
#define RNG_PUBLISH_VALRDY_EN_DISABLED                  (0x0U<<31U)
#define RNG_PUBLISH_VALRDY_EN_ENABLED                   (0x1U<<31U)

// SHORTS Configuration

#define RNG_SHORTS_VALRDY_STOP                          (0x1U<<0U)
#define RNG_SHORTS_VALRDY_STOP_DISABLED                 (0x0U<<0U)
#define RNG_SHORTS_VALRDY_STOP_ENABLED                  (0x1U<<0U)

// INTENSET Configuration

#define RNG_INTENSET_VALRDY                             (0x1U<<0U)
#define RNG_INTENSET_VALRDY_DISABLED                    (0x0U<<0U)
#define RNG_INTENSET_VALRDY_ENABLED                     (0x1U<<0U)
#define RNG_INTENSET_VALRDY_SET                         (0x1U<<0U)

// INTENCLR Configuration

#define RNG_INTENCLR_VALRDY                             (0x1U<<0U)
#define RNG_INTENCLR_VALRDY_DISABLED                    (0x0U<<0U)
#define RNG_INTENCLR_VALRDY_ENABLED                     (0x1U<<0U)
#define RNG_INTENCLR_VALRDY_CLEAR                       (0x1U<<0U)

// CONFIG Configuration

#define RNG_CONFIG_DERCEN                               (0x1U<<0U)
#define RNG_CONFIG_DERCEN_DISABLED                      (0x0U<<0U)
#define RNG_CONFIG_DERCEN_ENABLED                       (0x1U<<0U)

// VALUE Configuration

#define RNG_VALUE_VALUE                                 (0xFFU<<0U)
#define RNG_VALUE_VALUE_0                               (0x1U<<0U)
