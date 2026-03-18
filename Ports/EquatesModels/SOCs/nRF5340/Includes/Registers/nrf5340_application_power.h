/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_power equates.
 */

#pragma once

#include    <stdint.h>

// POWER address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[30];
    volatile    uint32_t    TASKS_CONSTLAT;
    volatile    uint32_t    TASKS_LOWPWR;
    volatile    uint32_t    RESERVED1[30];
    volatile    uint32_t    SUBSCRIBE_CONSTLAT;
    volatile    uint32_t    SUBSCRIBE_LOWPWR;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    EVENTS_POFWARN;
    volatile    uint32_t    RESERVED3[2];
    volatile    uint32_t    EVENTS_SLEEPENTER;
    volatile    uint32_t    EVENTS_SLEEPEXIT;
    volatile    uint32_t    RESERVED4[27];
    volatile    uint32_t    PUBLISH_POFWARN;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    PUBLISH_SLEEPENTER;
    volatile    uint32_t    PUBLISH_SLEEPEXIT;
    volatile    uint32_t    RESERVED6[89];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED7[132];
    volatile    uint32_t    GPREGRET[2];
} POWER_TypeDef;

#ifdef __cplusplus
#define POWER_NS    reinterpret_cast<POWER_TypeDef *>(0x40005000U)
#define POWER_S     reinterpret_cast<POWER_TypeDef *>(0x50005000U)

#else
#define POWER_NS    ((POWER_TypeDef *)0x40005000U)
#define POWER_S     ((POWER_TypeDef *)0x50005000U)
#endif

// TASKS_CONSTLAT Configuration

#define POWER_TASKS_CONSTLAT_TASKS_CONSTLAT                     (0x1U<<0)
#define POWER_TASKS_CONSTLAT_TASKS_CONSTLAT_TRIGGER             (0x1U<<0)

// TASKS_LOWPWR Configuration

#define POWER_TASKS_LOWPWR_TASKS_LOWPWR                         (0x1U<<0)
#define POWER_TASKS_LOWPWR_TASKS_LOWPWR_TRIGGER                 (0x1U<<0)

// SUBSCRIBE_CONSTLAT Configuration

#define POWER_SUBSCRIBE_CONSTLAT_EN                             (0x1U<<31)
#define POWER_SUBSCRIBE_CONSTLAT_CHIDX                          (0xFFU<<0)
#define POWER_SUBSCRIBE_CONSTLAT_CHIDX_0                        (0x1U<<0)
#define POWER_SUBSCRIBE_CONSTLAT_EN_DISABLED                    (0x0U<<31)
#define POWER_SUBSCRIBE_CONSTLAT_EN_ENABLED                     (0x1U<<31)

// SUBSCRIBE_LOWPWR Configuration

#define POWER_SUBSCRIBE_LOWPWR_EN                               (0x1U<<31)
#define POWER_SUBSCRIBE_LOWPWR_CHIDX                            (0xFFU<<0)
#define POWER_SUBSCRIBE_LOWPWR_CHIDX_0                          (0x1U<<0)
#define POWER_SUBSCRIBE_LOWPWR_EN_DISABLED                      (0x0U<<31)
#define POWER_SUBSCRIBE_LOWPWR_EN_ENABLED                       (0x1U<<31)

// EVENTS_POFWARN Configuration

#define POWER_EVENTS_POFWARN_EVENTS_POFWARN                     (0x1U<<0)
#define POWER_EVENTS_POFWARN_EVENTS_POFWARN_NOTGENERATED        (0x0U<<0)
#define POWER_EVENTS_POFWARN_EVENTS_POFWARN_GENERATED           (0x1U<<0)

// EVENTS_SLEEPENTER Configuration

#define POWER_EVENTS_SLEEPENTER_EVENTS_SLEEPENTER               (0x1U<<0)
#define POWER_EVENTS_SLEEPENTER_EVENTS_SLEEPENTER_NOTGENERATED  (0x0U<<0)
#define POWER_EVENTS_SLEEPENTER_EVENTS_SLEEPENTER_GENERATED     (0x1U<<0)

// EVENTS_SLEEPEXIT Configuration

#define POWER_EVENTS_SLEEPEXIT_EVENTS_SLEEPEXIT                 (0x1U<<0)
#define POWER_EVENTS_SLEEPEXIT_EVENTS_SLEEPEXIT_NOTGENERATED    (0x0U<<0)
#define POWER_EVENTS_SLEEPEXIT_EVENTS_SLEEPEXIT_GENERATED       (0x1U<<0)

// PUBLISH_POFWARN Configuration

#define POWER_PUBLISH_POFWARN_EN                                (0x1U<<31)
#define POWER_PUBLISH_POFWARN_CHIDX                             (0xFFU<<0)
#define POWER_PUBLISH_POFWARN_CHIDX_0                           (0x1U<<0)
#define POWER_PUBLISH_POFWARN_EN_DISABLED                       (0x0U<<31)
#define POWER_PUBLISH_POFWARN_EN_ENABLED                        (0x1U<<31)

// PUBLISH_SLEEPENTER Configuration

#define POWER_PUBLISH_SLEEPENTER_EN                             (0x1U<<31)
#define POWER_PUBLISH_SLEEPENTER_CHIDX                          (0xFFU<<0)
#define POWER_PUBLISH_SLEEPENTER_CHIDX_0                        (0x1U<<0)
#define POWER_PUBLISH_SLEEPENTER_EN_DISABLED                    (0x0U<<31)
#define POWER_PUBLISH_SLEEPENTER_EN_ENABLED                     (0x1U<<31)

// PUBLISH_SLEEPEXIT Configuration

#define POWER_PUBLISH_SLEEPEXIT_EN                              (0x1U<<31)
#define POWER_PUBLISH_SLEEPEXIT_CHIDX                           (0xFFU<<0)
#define POWER_PUBLISH_SLEEPEXIT_CHIDX_0                         (0x1U<<0)
#define POWER_PUBLISH_SLEEPEXIT_EN_DISABLED                     (0x0U<<31)
#define POWER_PUBLISH_SLEEPEXIT_EN_ENABLED                      (0x1U<<31)

// INTEN Configuration

#define POWER_INTEN_SLEEPEXIT                                   (0x1U<<6)
#define POWER_INTEN_SLEEPENTER                                  (0x1U<<5)
#define POWER_INTEN_POFWARN                                     (0x1U<<2)
#define POWER_INTEN_SLEEPEXIT_DISABLED                          (0x0U<<6)
#define POWER_INTEN_SLEEPEXIT_ENABLED                           (0x1U<<6)
#define POWER_INTEN_SLEEPENTER_DISABLED                         (0x0U<<5)
#define POWER_INTEN_SLEEPENTER_ENABLED                          (0x1U<<5)
#define POWER_INTEN_POFWARN_DISABLED                            (0x0U<<2)
#define POWER_INTEN_POFWARN_ENABLED                             (0x1U<<2)

// INTENSET Configuration

#define POWER_INTENSET_SLEEPEXIT                                (0x1U<<6)
#define POWER_INTENSET_SLEEPENTER                               (0x1U<<5)
#define POWER_INTENSET_POFWARN                                  (0x1U<<2)
#define POWER_INTENSET_SLEEPEXIT_DISABLED                       (0x0U<<6)
#define POWER_INTENSET_SLEEPEXIT_ENABLED                        (0x1U<<6)
#define POWER_INTENSET_SLEEPEXIT_SET                            (0x1U<<6)
#define POWER_INTENSET_SLEEPENTER_DISABLED                      (0x0U<<5)
#define POWER_INTENSET_SLEEPENTER_ENABLED                       (0x1U<<5)
#define POWER_INTENSET_SLEEPENTER_SET                           (0x1U<<5)
#define POWER_INTENSET_POFWARN_DISABLED                         (0x0U<<2)
#define POWER_INTENSET_POFWARN_ENABLED                          (0x1U<<2)
#define POWER_INTENSET_POFWARN_SET                              (0x1U<<2)

// INTENCLR Configuration

#define POWER_INTENCLR_SLEEPEXIT                                (0x1U<<6)
#define POWER_INTENCLR_SLEEPENTER                               (0x1U<<5)
#define POWER_INTENCLR_POFWARN                                  (0x1U<<2)
#define POWER_INTENCLR_SLEEPEXIT_DISABLED                       (0x0U<<6)
#define POWER_INTENCLR_SLEEPEXIT_ENABLED                        (0x1U<<6)
#define POWER_INTENCLR_SLEEPEXIT_CLEAR                          (0x1U<<6)
#define POWER_INTENCLR_SLEEPENTER_DISABLED                      (0x0U<<5)
#define POWER_INTENCLR_SLEEPENTER_ENABLED                       (0x1U<<5)
#define POWER_INTENCLR_SLEEPENTER_CLEAR                         (0x1U<<5)
#define POWER_INTENCLR_POFWARN_DISABLED                         (0x0U<<2)
#define POWER_INTENCLR_POFWARN_ENABLED                          (0x1U<<2)
#define POWER_INTENCLR_POFWARN_CLEAR                            (0x1U<<2)

// GPREGRET Configuration

#define POWER_GPREGRET_GPREGRET                                 (0xFFU<<0)
#define POWER_GPREGRET_GPREGRET_0                               (0x1U<<0)
