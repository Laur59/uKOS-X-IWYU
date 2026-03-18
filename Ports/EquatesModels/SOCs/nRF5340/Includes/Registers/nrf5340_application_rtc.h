/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_rtc equates.
 */

#pragma once

#include    <stdint.h>

// RTC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TASKS_START;
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    TASKS_CLEAR;
    volatile    uint32_t    TASKS_TRIGOVRFLW;
    volatile    uint32_t    RESERVED0[12];
    volatile    uint32_t    TASKS_CAPTURE[4];
    volatile    uint32_t    RESERVED1[12];
    volatile    uint32_t    SUBSCRIBE_START;
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    SUBSCRIBE_CLEAR;
    volatile    uint32_t    SUBSCRIBE_TRIGOVRFLW;
    volatile    uint32_t    RESERVED2[12];
    volatile    uint32_t    SUBSCRIBE_CAPTURE[4];
    volatile    uint32_t    RESERVED3[12];
    volatile    uint32_t    EVENTS_TICK;
    volatile    uint32_t    EVENTS_OVRFLW;
    volatile    uint32_t    RESERVED4[14];
    volatile    uint32_t    EVENTS_COMPARE[4];
    volatile    uint32_t    RESERVED5[12];
    volatile    uint32_t    PUBLISH_TICK;
    volatile    uint32_t    PUBLISH_OVRFLW;
    volatile    uint32_t    RESERVED6[14];
    volatile    uint32_t    PUBLISH_COMPARE[4];
    volatile    uint32_t    RESERVED7[12];
    volatile    uint32_t    SHORTS;
    volatile    uint32_t    RESERVED8[64];
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED9[13];
    volatile    uint32_t    EVTEN;
    volatile    uint32_t    EVTENSET;
    volatile    uint32_t    EVTENCLR;
    volatile    uint32_t    RESERVED10[110];
    volatile    uint32_t    COUNTER;
    volatile    uint32_t    PRESCALER;
    volatile    uint32_t    RESERVED11[13];
    volatile    uint32_t    CC[4];
} RTC_TypeDef;

#ifdef __cplusplus
#define RTC0_NS reinterpret_cast<RTC_TypeDef *>(0x40014000U)
#define RTC0_S  reinterpret_cast<RTC_TypeDef *>(0x50014000U)
#define RTC1_NS reinterpret_cast<RTC_TypeDef *>(0x40015000U)
#define RTC1_S  reinterpret_cast<RTC_TypeDef *>(0x50015000U)

#else
#define RTC0_NS ((RTC_TypeDef *)0x40014000U)
#define RTC0_S  ((RTC_TypeDef *)0x50014000U)
#define RTC1_NS ((RTC_TypeDef *)0x40015000U)
#define RTC1_S  ((RTC_TypeDef *)0x50015000U)
#endif

// TASKS_START Configuration

#define RTC_TASKS_START_TASKS_START                     (0x1U<<0)
#define RTC_TASKS_START_TASKS_START_TRIGGER             (0x1U<<0)

// TASKS_STOP Configuration

#define RTC_TASKS_STOP_TASKS_STOP                       (0x1U<<0)
#define RTC_TASKS_STOP_TASKS_STOP_TRIGGER               (0x1U<<0)

// TASKS_CLEAR Configuration

#define RTC_TASKS_CLEAR_TASKS_CLEAR                     (0x1U<<0)
#define RTC_TASKS_CLEAR_TASKS_CLEAR_TRIGGER             (0x1U<<0)

// TASKS_TRIGOVRFLW Configuration

#define RTC_TASKS_TRIGOVRFLW_TASKS_TRIGOVRFLW           (0x1U<<0)
#define RTC_TASKS_TRIGOVRFLW_TASKS_TRIGOVRFLW_TRIGGER   (0x1U<<0)

// TASKS_CAPTURE Configuration

#define RTC_TASKS_CAPTURE_TASKS_CAPTURE                 (0x1U<<0)
#define RTC_TASKS_CAPTURE_TASKS_CAPTURE_TRIGGER         (0x1U<<0)

// SUBSCRIBE_START Configuration

#define RTC_SUBSCRIBE_START_EN                          (0x1U<<31)
#define RTC_SUBSCRIBE_START_CHIDX                       (0xFFU<<0)
#define RTC_SUBSCRIBE_START_CHIDX_0                     (0x1U<<0)
#define RTC_SUBSCRIBE_START_EN_DISABLED                 (0x0U<<31)
#define RTC_SUBSCRIBE_START_EN_ENABLED                  (0x1U<<31)

// SUBSCRIBE_STOP Configuration

#define RTC_SUBSCRIBE_STOP_EN                           (0x1U<<31)
#define RTC_SUBSCRIBE_STOP_CHIDX                        (0xFFU<<0)
#define RTC_SUBSCRIBE_STOP_CHIDX_0                      (0x1U<<0)
#define RTC_SUBSCRIBE_STOP_EN_DISABLED                  (0x0U<<31)
#define RTC_SUBSCRIBE_STOP_EN_ENABLED                   (0x1U<<31)

// SUBSCRIBE_CLEAR Configuration

#define RTC_SUBSCRIBE_CLEAR_EN                          (0x1U<<31)
#define RTC_SUBSCRIBE_CLEAR_CHIDX                       (0xFFU<<0)
#define RTC_SUBSCRIBE_CLEAR_CHIDX_0                     (0x1U<<0)
#define RTC_SUBSCRIBE_CLEAR_EN_DISABLED                 (0x0U<<31)
#define RTC_SUBSCRIBE_CLEAR_EN_ENABLED                  (0x1U<<31)

// SUBSCRIBE_TRIGOVRFLW Configuration

#define RTC_SUBSCRIBE_TRIGOVRFLW_EN                     (0x1U<<31)
#define RTC_SUBSCRIBE_TRIGOVRFLW_CHIDX                  (0xFFU<<0)
#define RTC_SUBSCRIBE_TRIGOVRFLW_CHIDX_0                (0x1U<<0)
#define RTC_SUBSCRIBE_TRIGOVRFLW_EN_DISABLED            (0x0U<<31)
#define RTC_SUBSCRIBE_TRIGOVRFLW_EN_ENABLED             (0x1U<<31)

// SUBSCRIBE_CAPTURE Configuration

#define RTC_SUBSCRIBE_CAPTURE_EN                        (0x1U<<31)
#define RTC_SUBSCRIBE_CAPTURE_CHIDX                     (0xFFU<<0)
#define RTC_SUBSCRIBE_CAPTURE_CHIDX_0                   (0x1U<<0)
#define RTC_SUBSCRIBE_CAPTURE_EN_DISABLED               (0x0U<<31)
#define RTC_SUBSCRIBE_CAPTURE_EN_ENABLED                (0x1U<<31)

// EVENTS_TICK Configuration

#define RTC_EVENTS_TICK_EVENTS_TICK                     (0x1U<<0)
#define RTC_EVENTS_TICK_EVENTS_TICK_NOTGENERATED        (0x0U<<0)
#define RTC_EVENTS_TICK_EVENTS_TICK_GENERATED           (0x1U<<0)

// EVENTS_OVRFLW Configuration

#define RTC_EVENTS_OVRFLW_EVENTS_OVRFLW                 (0x1U<<0)
#define RTC_EVENTS_OVRFLW_EVENTS_OVRFLW_NOTGENERATED    (0x0U<<0)
#define RTC_EVENTS_OVRFLW_EVENTS_OVRFLW_GENERATED       (0x1U<<0)

// EVENTS_COMPARE Configuration

#define RTC_EVENTS_COMPARE_EVENTS_COMPARE               (0x1U<<0)
#define RTC_EVENTS_COMPARE_EVENTS_COMPARE_NOTGENERATED  (0x0U<<0)
#define RTC_EVENTS_COMPARE_EVENTS_COMPARE_GENERATED     (0x1U<<0)

// PUBLISH_TICK Configuration

#define RTC_PUBLISH_TICK_EN                             (0x1U<<31)
#define RTC_PUBLISH_TICK_CHIDX                          (0xFFU<<0)
#define RTC_PUBLISH_TICK_CHIDX_0                        (0x1U<<0)
#define RTC_PUBLISH_TICK_EN_DISABLED                    (0x0U<<31)
#define RTC_PUBLISH_TICK_EN_ENABLED                     (0x1U<<31)

// PUBLISH_OVRFLW Configuration

#define RTC_PUBLISH_OVRFLW_EN                           (0x1U<<31)
#define RTC_PUBLISH_OVRFLW_CHIDX                        (0xFFU<<0)
#define RTC_PUBLISH_OVRFLW_CHIDX_0                      (0x1U<<0)
#define RTC_PUBLISH_OVRFLW_EN_DISABLED                  (0x0U<<31)
#define RTC_PUBLISH_OVRFLW_EN_ENABLED                   (0x1U<<31)

// PUBLISH_COMPARE Configuration

#define RTC_PUBLISH_COMPARE_EN                          (0x1U<<31)
#define RTC_PUBLISH_COMPARE_CHIDX                       (0xFFU<<0)
#define RTC_PUBLISH_COMPARE_CHIDX_0                     (0x1U<<0)
#define RTC_PUBLISH_COMPARE_EN_DISABLED                 (0x0U<<31)
#define RTC_PUBLISH_COMPARE_EN_ENABLED                  (0x1U<<31)

// SHORTS Configuration

#define RTC_SHORTS_COMPARE3_CLEAR                       (0x1U<<3)
#define RTC_SHORTS_COMPARE2_CLEAR                       (0x1U<<2)
#define RTC_SHORTS_COMPARE1_CLEAR                       (0x1U<<1)
#define RTC_SHORTS_COMPARE0_CLEAR                       (0x1U<<0)
#define RTC_SHORTS_COMPARE3_CLEAR_DISABLED              (0x0U<<3)
#define RTC_SHORTS_COMPARE3_CLEAR_ENABLED               (0x1U<<3)
#define RTC_SHORTS_COMPARE2_CLEAR_DISABLED              (0x0U<<2)
#define RTC_SHORTS_COMPARE2_CLEAR_ENABLED               (0x1U<<2)
#define RTC_SHORTS_COMPARE1_CLEAR_DISABLED              (0x0U<<1)
#define RTC_SHORTS_COMPARE1_CLEAR_ENABLED               (0x1U<<1)
#define RTC_SHORTS_COMPARE0_CLEAR_DISABLED              (0x0U<<0)
#define RTC_SHORTS_COMPARE0_CLEAR_ENABLED               (0x1U<<0)

// INTENSET Configuration

#define RTC_INTENSET_COMPARE3                           (0x1U<<19)
#define RTC_INTENSET_COMPARE2                           (0x1U<<18)
#define RTC_INTENSET_COMPARE1                           (0x1U<<17)
#define RTC_INTENSET_COMPARE0                           (0x1U<<16)
#define RTC_INTENSET_OVRFLW                             (0x1U<<1)
#define RTC_INTENSET_TICK                               (0x1U<<0)
#define RTC_INTENSET_COMPARE3_DISABLED                  (0x0U<<19)
#define RTC_INTENSET_COMPARE3_ENABLED                   (0x1U<<19)
#define RTC_INTENSET_COMPARE3_SET                       (0x1U<<19)
#define RTC_INTENSET_COMPARE2_DISABLED                  (0x0U<<18)
#define RTC_INTENSET_COMPARE2_ENABLED                   (0x1U<<18)
#define RTC_INTENSET_COMPARE2_SET                       (0x1U<<18)
#define RTC_INTENSET_COMPARE1_DISABLED                  (0x0U<<17)
#define RTC_INTENSET_COMPARE1_ENABLED                   (0x1U<<17)
#define RTC_INTENSET_COMPARE1_SET                       (0x1U<<17)
#define RTC_INTENSET_COMPARE0_DISABLED                  (0x0U<<16)
#define RTC_INTENSET_COMPARE0_ENABLED                   (0x1U<<16)
#define RTC_INTENSET_COMPARE0_SET                       (0x1U<<16)
#define RTC_INTENSET_OVRFLW_DISABLED                    (0x0U<<1)
#define RTC_INTENSET_OVRFLW_ENABLED                     (0x1U<<1)
#define RTC_INTENSET_OVRFLW_SET                         (0x1U<<1)
#define RTC_INTENSET_TICK_DISABLED                      (0x0U<<0)
#define RTC_INTENSET_TICK_ENABLED                       (0x1U<<0)
#define RTC_INTENSET_TICK_SET                           (0x1U<<0)

// INTENCLR Configuration

#define RTC_INTENCLR_COMPARE3                           (0x1U<<19)
#define RTC_INTENCLR_COMPARE2                           (0x1U<<18)
#define RTC_INTENCLR_COMPARE1                           (0x1U<<17)
#define RTC_INTENCLR_COMPARE0                           (0x1U<<16)
#define RTC_INTENCLR_OVRFLW                             (0x1U<<1)
#define RTC_INTENCLR_TICK                               (0x1U<<0)
#define RTC_INTENCLR_COMPARE3_DISABLED                  (0x0U<<19)
#define RTC_INTENCLR_COMPARE3_ENABLED                   (0x1U<<19)
#define RTC_INTENCLR_COMPARE3_CLEAR                     (0x1U<<19)
#define RTC_INTENCLR_COMPARE2_DISABLED                  (0x0U<<18)
#define RTC_INTENCLR_COMPARE2_ENABLED                   (0x1U<<18)
#define RTC_INTENCLR_COMPARE2_CLEAR                     (0x1U<<18)
#define RTC_INTENCLR_COMPARE1_DISABLED                  (0x0U<<17)
#define RTC_INTENCLR_COMPARE1_ENABLED                   (0x1U<<17)
#define RTC_INTENCLR_COMPARE1_CLEAR                     (0x1U<<17)
#define RTC_INTENCLR_COMPARE0_DISABLED                  (0x0U<<16)
#define RTC_INTENCLR_COMPARE0_ENABLED                   (0x1U<<16)
#define RTC_INTENCLR_COMPARE0_CLEAR                     (0x1U<<16)
#define RTC_INTENCLR_OVRFLW_DISABLED                    (0x0U<<1)
#define RTC_INTENCLR_OVRFLW_ENABLED                     (0x1U<<1)
#define RTC_INTENCLR_OVRFLW_CLEAR                       (0x1U<<1)
#define RTC_INTENCLR_TICK_DISABLED                      (0x0U<<0)
#define RTC_INTENCLR_TICK_ENABLED                       (0x1U<<0)
#define RTC_INTENCLR_TICK_CLEAR                         (0x1U<<0)

// EVTEN Configuration

#define RTC_EVTEN_COMPARE3                              (0x1U<<19)
#define RTC_EVTEN_COMPARE2                              (0x1U<<18)
#define RTC_EVTEN_COMPARE1                              (0x1U<<17)
#define RTC_EVTEN_COMPARE0                              (0x1U<<16)
#define RTC_EVTEN_OVRFLW                                (0x1U<<1)
#define RTC_EVTEN_TICK                                  (0x1U<<0)
#define RTC_EVTEN_COMPARE3_DISABLED                     (0x0U<<19)
#define RTC_EVTEN_COMPARE3_ENABLED                      (0x1U<<19)
#define RTC_EVTEN_COMPARE2_DISABLED                     (0x0U<<18)
#define RTC_EVTEN_COMPARE2_ENABLED                      (0x1U<<18)
#define RTC_EVTEN_COMPARE1_DISABLED                     (0x0U<<17)
#define RTC_EVTEN_COMPARE1_ENABLED                      (0x1U<<17)
#define RTC_EVTEN_COMPARE0_DISABLED                     (0x0U<<16)
#define RTC_EVTEN_COMPARE0_ENABLED                      (0x1U<<16)
#define RTC_EVTEN_OVRFLW_DISABLED                       (0x0U<<1)
#define RTC_EVTEN_OVRFLW_ENABLED                        (0x1U<<1)
#define RTC_EVTEN_TICK_DISABLED                         (0x0U<<0)
#define RTC_EVTEN_TICK_ENABLED                          (0x1U<<0)

// EVTENSET Configuration

#define RTC_EVTENSET_COMPARE3                           (0x1U<<19)
#define RTC_EVTENSET_COMPARE2                           (0x1U<<18)
#define RTC_EVTENSET_COMPARE1                           (0x1U<<17)
#define RTC_EVTENSET_COMPARE0                           (0x1U<<16)
#define RTC_EVTENSET_OVRFLW                             (0x1U<<1)
#define RTC_EVTENSET_TICK                               (0x1U<<0)
#define RTC_EVTENSET_COMPARE3_DISABLED                  (0x0U<<19)
#define RTC_EVTENSET_COMPARE3_ENABLED                   (0x1U<<19)
#define RTC_EVTENSET_COMPARE3_SET                       (0x1U<<19)
#define RTC_EVTENSET_COMPARE2_DISABLED                  (0x0U<<18)
#define RTC_EVTENSET_COMPARE2_ENABLED                   (0x1U<<18)
#define RTC_EVTENSET_COMPARE2_SET                       (0x1U<<18)
#define RTC_EVTENSET_COMPARE1_DISABLED                  (0x0U<<17)
#define RTC_EVTENSET_COMPARE1_ENABLED                   (0x1U<<17)
#define RTC_EVTENSET_COMPARE1_SET                       (0x1U<<17)
#define RTC_EVTENSET_COMPARE0_DISABLED                  (0x0U<<16)
#define RTC_EVTENSET_COMPARE0_ENABLED                   (0x1U<<16)
#define RTC_EVTENSET_COMPARE0_SET                       (0x1U<<16)
#define RTC_EVTENSET_OVRFLW_DISABLED                    (0x0U<<1)
#define RTC_EVTENSET_OVRFLW_ENABLED                     (0x1U<<1)
#define RTC_EVTENSET_OVRFLW_SET                         (0x1U<<1)
#define RTC_EVTENSET_TICK_DISABLED                      (0x0U<<0)
#define RTC_EVTENSET_TICK_ENABLED                       (0x1U<<0)
#define RTC_EVTENSET_TICK_SET                           (0x1U<<0)

// EVTENCLR Configuration

#define RTC_EVTENCLR_COMPARE3                           (0x1U<<19)
#define RTC_EVTENCLR_COMPARE2                           (0x1U<<18)
#define RTC_EVTENCLR_COMPARE1                           (0x1U<<17)
#define RTC_EVTENCLR_COMPARE0                           (0x1U<<16)
#define RTC_EVTENCLR_OVRFLW                             (0x1U<<1)
#define RTC_EVTENCLR_TICK                               (0x1U<<0)
#define RTC_EVTENCLR_COMPARE3_DISABLED                  (0x0U<<19)
#define RTC_EVTENCLR_COMPARE3_ENABLED                   (0x1U<<19)
#define RTC_EVTENCLR_COMPARE3_CLEAR                     (0x1U<<19)
#define RTC_EVTENCLR_COMPARE2_DISABLED                  (0x0U<<18)
#define RTC_EVTENCLR_COMPARE2_ENABLED                   (0x1U<<18)
#define RTC_EVTENCLR_COMPARE2_CLEAR                     (0x1U<<18)
#define RTC_EVTENCLR_COMPARE1_DISABLED                  (0x0U<<17)
#define RTC_EVTENCLR_COMPARE1_ENABLED                   (0x1U<<17)
#define RTC_EVTENCLR_COMPARE1_CLEAR                     (0x1U<<17)
#define RTC_EVTENCLR_COMPARE0_DISABLED                  (0x0U<<16)
#define RTC_EVTENCLR_COMPARE0_ENABLED                   (0x1U<<16)
#define RTC_EVTENCLR_COMPARE0_CLEAR                     (0x1U<<16)
#define RTC_EVTENCLR_OVRFLW_DISABLED                    (0x0U<<1)
#define RTC_EVTENCLR_OVRFLW_ENABLED                     (0x1U<<1)
#define RTC_EVTENCLR_OVRFLW_CLEAR                       (0x1U<<1)
#define RTC_EVTENCLR_TICK_DISABLED                      (0x0U<<0)
#define RTC_EVTENCLR_TICK_ENABLED                       (0x1U<<0)
#define RTC_EVTENCLR_TICK_CLEAR                         (0x1U<<0)

// COUNTER Configuration

#define RTC_COUNTER_COUNTER                             (0xFFFFFFU<<0)
#define RTC_COUNTER_COUNTER_0                           (0x1U<<0)

// PRESCALER Configuration

#define RTC_PRESCALER_PRESCALER                         (0xFFFU<<0)
#define RTC_PRESCALER_PRESCALER_0                       (0x1U<<0)

// CC Configuration

#define RTC_CC_COMPARE                                  (0xFFFFFFU<<0)
#define RTC_CC_COMPARE_0                                (0x1U<<0)
