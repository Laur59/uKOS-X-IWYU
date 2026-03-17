/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_network_ecb.
; ====================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_network_ecb equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// ECB address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TASKS_STARTECB;
    volatile    uint32_t    TASKS_STOPECB;
    volatile    uint32_t    RESERVED0[30];
    volatile    uint32_t    SUBSCRIBE_STARTECB;
    volatile    uint32_t    SUBSCRIBE_STOPECB;
    volatile    uint32_t    RESERVED1[30];
    volatile    uint32_t    EVENTS_ENDECB;
    volatile    uint32_t    EVENTS_ERRORECB;
    volatile    uint32_t    RESERVED2[30];
    volatile    uint32_t    PUBLISH_ENDECB;
    volatile    uint32_t    PUBLISH_ERRORECB;
    volatile    uint32_t    RESERVED3[95];
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED4[126];
    volatile    uint32_t    ECBDATAPTR;
} ECB_TypeDef;

#ifdef __cplusplus
#define ECB_NS  reinterpret_cast<ECB_TypeDef *>(0x4100D000U)

#else
#define ECB_NS  ((ECB_TypeDef *)0x4100D000U)
#endif

// TASKS_STARTECB Configuration

#define ECB_TASKS_STARTECB_TASKS_STARTECB                   (0x1U<<0)
#define ECB_TASKS_STARTECB_TASKS_STARTECB_TRIGGER           (0x1U<<0)

// TASKS_STOPECB Configuration

#define ECB_TASKS_STOPECB_TASKS_STOPECB                     (0x1U<<0)
#define ECB_TASKS_STOPECB_TASKS_STOPECB_TRIGGER             (0x1U<<0)

// SUBSCRIBE_STARTECB Configuration

#define ECB_SUBSCRIBE_STARTECB_EN                           (0x1U<<31)
#define ECB_SUBSCRIBE_STARTECB_CHIDX                        (0xFFU<<0)
#define ECB_SUBSCRIBE_STARTECB_CHIDX_0                      (0x1U<<0)
#define ECB_SUBSCRIBE_STARTECB_EN_DISABLED                  (0x0U<<31)
#define ECB_SUBSCRIBE_STARTECB_EN_ENABLED                   (0x1U<<31)

// SUBSCRIBE_STOPECB Configuration

#define ECB_SUBSCRIBE_STOPECB_EN                            (0x1U<<31)
#define ECB_SUBSCRIBE_STOPECB_CHIDX                         (0xFFU<<0)
#define ECB_SUBSCRIBE_STOPECB_CHIDX_0                       (0x1U<<0)
#define ECB_SUBSCRIBE_STOPECB_EN_DISABLED                   (0x0U<<31)
#define ECB_SUBSCRIBE_STOPECB_EN_ENABLED                    (0x1U<<31)

// EVENTS_ENDECB Configuration

#define ECB_EVENTS_ENDECB_EVENTS_ENDECB                     (0x1U<<0)
#define ECB_EVENTS_ENDECB_EVENTS_ENDECB_NOTGENERATED        (0x0U<<0)
#define ECB_EVENTS_ENDECB_EVENTS_ENDECB_GENERATED           (0x1U<<0)

// EVENTS_ERRORECB Configuration

#define ECB_EVENTS_ERRORECB_EVENTS_ERRORECB                 (0x1U<<0)
#define ECB_EVENTS_ERRORECB_EVENTS_ERRORECB_NOTGENERATED    (0x0U<<0)
#define ECB_EVENTS_ERRORECB_EVENTS_ERRORECB_GENERATED       (0x1U<<0)

// PUBLISH_ENDECB Configuration

#define ECB_PUBLISH_ENDECB_EN                               (0x1U<<31)
#define ECB_PUBLISH_ENDECB_CHIDX                            (0xFFU<<0)
#define ECB_PUBLISH_ENDECB_CHIDX_0                          (0x1U<<0)
#define ECB_PUBLISH_ENDECB_EN_DISABLED                      (0x0U<<31)
#define ECB_PUBLISH_ENDECB_EN_ENABLED                       (0x1U<<31)

// PUBLISH_ERRORECB Configuration

#define ECB_PUBLISH_ERRORECB_EN                             (0x1U<<31)
#define ECB_PUBLISH_ERRORECB_CHIDX                          (0xFFU<<0)
#define ECB_PUBLISH_ERRORECB_CHIDX_0                        (0x1U<<0)
#define ECB_PUBLISH_ERRORECB_EN_DISABLED                    (0x0U<<31)
#define ECB_PUBLISH_ERRORECB_EN_ENABLED                     (0x1U<<31)

// INTENSET Configuration

#define ECB_INTENSET_ERRORECB                               (0x1U<<1)
#define ECB_INTENSET_ENDECB                                 (0x1U<<0)
#define ECB_INTENSET_ERRORECB_DISABLED                      (0x0U<<1)
#define ECB_INTENSET_ERRORECB_ENABLED                       (0x1U<<1)
#define ECB_INTENSET_ERRORECB_SET                           (0x1U<<1)
#define ECB_INTENSET_ENDECB_DISABLED                        (0x0U<<0)
#define ECB_INTENSET_ENDECB_ENABLED                         (0x1U<<0)
#define ECB_INTENSET_ENDECB_SET                             (0x1U<<0)

// INTENCLR Configuration

#define ECB_INTENCLR_ERRORECB                               (0x1U<<1)
#define ECB_INTENCLR_ENDECB                                 (0x1U<<0)
#define ECB_INTENCLR_ERRORECB_DISABLED                      (0x0U<<1)
#define ECB_INTENCLR_ERRORECB_ENABLED                       (0x1U<<1)
#define ECB_INTENCLR_ERRORECB_CLEAR                         (0x1U<<1)
#define ECB_INTENCLR_ENDECB_DISABLED                        (0x0U<<0)
#define ECB_INTENCLR_ENDECB_ENABLED                         (0x1U<<0)
#define ECB_INTENCLR_ENDECB_CLEAR                           (0x1U<<0)

// ECBDATAPTR Configuration

#define ECB_ECBDATAPTR_ECBDATAPTR                           (0xFFFFFFFFU<<0)
#define ECB_ECBDATAPTR_ECBDATAPTR_0                         (0x1U<<0)
