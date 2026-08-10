/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_aar equates.
 */

#pragma once

#include    <stdint.h>

// AAR address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TASKS_START;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    RESERVED1[29];
    volatile    uint32_t    SUBSCRIBE_START;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    RESERVED3[29];
    volatile    uint32_t    EVENTS_END;
    volatile    uint32_t    EVENTS_RESOLVED;
    volatile    uint32_t    EVENTS_NOTRESOLVED;
    volatile    uint32_t    RESERVED4[29];
    volatile    uint32_t    PUBLISH_END;
    volatile    uint32_t    PUBLISH_RESOLVED;
    volatile    uint32_t    PUBLISH_NOTRESOLVED;
    volatile    uint32_t    RESERVED5[94];
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED6[61];
    volatile    uint32_t    STATUS;
    volatile    uint32_t    RESERVED7[63];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    NIRK;
    volatile    uint32_t    IRKPTR;
    volatile    uint32_t    RESERVED8;
    volatile    uint32_t    ADDRPTR;
    volatile    uint32_t    SCRATCHPTR;
} AAR_TypeDef;

#ifdef __cplusplus
#define AAR_NS  reinterpret_cast<AAR_TypeDef *>(0x4100E000U)

#else
#define AAR_NS  ((AAR_TypeDef *)0x4100E000U)
#endif

// TASKS_START Configuration

#define AAR_TASKS_START_TASKS_START                             (0x1U<<0U)
#define AAR_TASKS_START_TASKS_START_TRIGGER                     (0x1U<<0U)

// TASKS_STOP Configuration

#define AAR_TASKS_STOP_TASKS_STOP                               (0x1U<<0U)
#define AAR_TASKS_STOP_TASKS_STOP_TRIGGER                       (0x1U<<0U)

// SUBSCRIBE_START Configuration

#define AAR_SUBSCRIBE_START_EN                                  (0x1U<<31U)
#define AAR_SUBSCRIBE_START_CHIDX                               (0xFFU<<0U)
#define AAR_SUBSCRIBE_START_CHIDX_0                             (0x1U<<0U)
#define AAR_SUBSCRIBE_START_EN_DISABLED                         (0x0U<<31U)
#define AAR_SUBSCRIBE_START_EN_ENABLED                          (0x1U<<31U)

// SUBSCRIBE_STOP Configuration

#define AAR_SUBSCRIBE_STOP_EN                                   (0x1U<<31U)
#define AAR_SUBSCRIBE_STOP_CHIDX                                (0xFFU<<0U)
#define AAR_SUBSCRIBE_STOP_CHIDX_0                              (0x1U<<0U)
#define AAR_SUBSCRIBE_STOP_EN_DISABLED                          (0x0U<<31U)
#define AAR_SUBSCRIBE_STOP_EN_ENABLED                           (0x1U<<31U)

// EVENTS_END Configuration

#define AAR_EVENTS_END_EVENTS_END                               (0x1U<<0U)
#define AAR_EVENTS_END_EVENTS_END_NOTGENERATED                  (0x0U<<0U)
#define AAR_EVENTS_END_EVENTS_END_GENERATED                     (0x1U<<0U)

// EVENTS_RESOLVED Configuration

#define AAR_EVENTS_RESOLVED_EVENTS_RESOLVED                     (0x1U<<0U)
#define AAR_EVENTS_RESOLVED_EVENTS_RESOLVED_NOTGENERATED        (0x0U<<0U)
#define AAR_EVENTS_RESOLVED_EVENTS_RESOLVED_GENERATED           (0x1U<<0U)

// EVENTS_NOTRESOLVED Configuration

#define AAR_EVENTS_NOTRESOLVED_EVENTS_NOTRESOLVED               (0x1U<<0U)
#define AAR_EVENTS_NOTRESOLVED_EVENTS_NOTRESOLVED_NOTGENERATED  (0x0U<<0U)
#define AAR_EVENTS_NOTRESOLVED_EVENTS_NOTRESOLVED_GENERATED     (0x1U<<0U)

// PUBLISH_END Configuration

#define AAR_PUBLISH_END_EN                                      (0x1U<<31U)
#define AAR_PUBLISH_END_CHIDX                                   (0xFFU<<0U)
#define AAR_PUBLISH_END_CHIDX_0                                 (0x1U<<0U)
#define AAR_PUBLISH_END_EN_DISABLED                             (0x0U<<31U)
#define AAR_PUBLISH_END_EN_ENABLED                              (0x1U<<31U)

// PUBLISH_RESOLVED Configuration

#define AAR_PUBLISH_RESOLVED_EN                                 (0x1U<<31U)
#define AAR_PUBLISH_RESOLVED_CHIDX                              (0xFFU<<0U)
#define AAR_PUBLISH_RESOLVED_CHIDX_0                            (0x1U<<0U)
#define AAR_PUBLISH_RESOLVED_EN_DISABLED                        (0x0U<<31U)
#define AAR_PUBLISH_RESOLVED_EN_ENABLED                         (0x1U<<31U)

// PUBLISH_NOTRESOLVED Configuration

#define AAR_PUBLISH_NOTRESOLVED_EN                              (0x1U<<31U)
#define AAR_PUBLISH_NOTRESOLVED_CHIDX                           (0xFFU<<0U)
#define AAR_PUBLISH_NOTRESOLVED_CHIDX_0                         (0x1U<<0U)
#define AAR_PUBLISH_NOTRESOLVED_EN_DISABLED                     (0x0U<<31U)
#define AAR_PUBLISH_NOTRESOLVED_EN_ENABLED                      (0x1U<<31U)

// INTENSET Configuration

#define AAR_INTENSET_NOTRESOLVED                                (0x1U<<2U)
#define AAR_INTENSET_RESOLVED                                   (0x1U<<1U)
#define AAR_INTENSET_END                                        (0x1U<<0U)
#define AAR_INTENSET_NOTRESOLVED_DISABLED                       (0x0U<<2U)
#define AAR_INTENSET_NOTRESOLVED_ENABLED                        (0x1U<<2U)
#define AAR_INTENSET_NOTRESOLVED_SET                            (0x1U<<2U)
#define AAR_INTENSET_RESOLVED_DISABLED                          (0x0U<<1U)
#define AAR_INTENSET_RESOLVED_ENABLED                           (0x1U<<1U)
#define AAR_INTENSET_RESOLVED_SET                               (0x1U<<1U)
#define AAR_INTENSET_END_DISABLED                               (0x0U<<0U)
#define AAR_INTENSET_END_ENABLED                                (0x1U<<0U)
#define AAR_INTENSET_END_SET                                    (0x1U<<0U)

// INTENCLR Configuration

#define AAR_INTENCLR_NOTRESOLVED                                (0x1U<<2U)
#define AAR_INTENCLR_RESOLVED                                   (0x1U<<1U)
#define AAR_INTENCLR_END                                        (0x1U<<0U)
#define AAR_INTENCLR_NOTRESOLVED_DISABLED                       (0x0U<<2U)
#define AAR_INTENCLR_NOTRESOLVED_ENABLED                        (0x1U<<2U)
#define AAR_INTENCLR_NOTRESOLVED_CLEAR                          (0x1U<<2U)
#define AAR_INTENCLR_RESOLVED_DISABLED                          (0x0U<<1U)
#define AAR_INTENCLR_RESOLVED_ENABLED                           (0x1U<<1U)
#define AAR_INTENCLR_RESOLVED_CLEAR                             (0x1U<<1U)
#define AAR_INTENCLR_END_DISABLED                               (0x0U<<0U)
#define AAR_INTENCLR_END_ENABLED                                (0x1U<<0U)
#define AAR_INTENCLR_END_CLEAR                                  (0x1U<<0U)

// STATUS Configuration

#define AAR_STATUS_STATUS                                       (0xFU<<0U)
#define AAR_STATUS_STATUS_0                                     (0x1U<<0U)

// ENABLE Configuration

#define AAR_ENABLE_ENABLE                                       (0x3U<<0U)
#define AAR_ENABLE_ENABLE_0                                     (0x1U<<0U)
#define AAR_ENABLE_ENABLE_DISABLED                              (0x0U<<0U)
#define AAR_ENABLE_ENABLE_ENABLED                               (0x3U<<0U)

// NIRK Configuration

#define AAR_NIRK_NIRK                                           (0x1FU<<0U)
#define AAR_NIRK_NIRK_0                                         (0x1U<<0U)

// IRKPTR Configuration

#define AAR_IRKPTR_IRKPTR                                       (0xFFFFFFFFU<<0U)
#define AAR_IRKPTR_IRKPTR_0                                     (0x1U<<0U)

// ADDRPTR Configuration

#define AAR_ADDRPTR_ADDRPTR                                     (0xFFFFFFFFU<<0U)
#define AAR_ADDRPTR_ADDRPTR_0                                   (0x1U<<0U)

// SCRATCHPTR Configuration

#define AAR_SCRATCHPTR_SCRATCHPTR                               (0xFFFFFFFFU<<0U)
#define AAR_SCRATCHPTR_SCRATCHPTR_0                             (0x1U<<0U)
