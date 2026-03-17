/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_network_gpiote.
; =======================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_network_gpiote equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// GPIOTE address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    TASKS_OUT[8];
    volatile    uint32_t    RESERVED0[4];
    volatile    uint32_t    TASKS_SET[8];
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    TASKS_CLR[8];
    volatile    uint32_t    SUBSCRIBE_OUT[8];
    volatile    uint32_t    RESERVED2[4];
    volatile    uint32_t    SUBSCRIBE_SET[8];
    volatile    uint32_t    RESERVED3[4];
    volatile    uint32_t    SUBSCRIBE_CLR[8];
    volatile    uint32_t    EVENTS_IN[8];
    volatile    uint32_t    RESERVED4[23];
    volatile    uint32_t    EVENTS_PORT;
    volatile    uint32_t    PUBLISH_IN[8];
    volatile    uint32_t    RESERVED5[23];
    volatile    uint32_t    PUBLISH_PORT;
    volatile    uint32_t    RESERVED6[65];
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED7[126];
    volatile    uint32_t    LATENCY;
    volatile    uint32_t    RESERVED8[2];
    volatile    uint32_t    CONFIG[8];
} GPIOTE_TypeDef;

#ifdef __cplusplus
#define GPIOTE_NS   reinterpret_cast<GPIOTE_TypeDef *>(0x4100A000U)

#else
#define GPIOTE_NS   ((GPIOTE_TypeDef *)0x4100A000U)
#endif

// TASKS_OUT Configuration

#define GPIOTE_TASKS_OUT_TASKS_OUT                  (0x1U<<0)
#define GPIOTE_TASKS_OUT_TASKS_OUT_TRIGGER          (0x1U<<0)

// TASKS_SET Configuration

#define GPIOTE_TASKS_SET_TASKS_SET                  (0x1U<<0)
#define GPIOTE_TASKS_SET_TASKS_SET_TRIGGER          (0x1U<<0)

// TASKS_CLR Configuration

#define GPIOTE_TASKS_CLR_TASKS_CLR                  (0x1U<<0)
#define GPIOTE_TASKS_CLR_TASKS_CLR_TRIGGER          (0x1U<<0)

// SUBSCRIBE_OUT Configuration

#define GPIOTE_SUBSCRIBE_OUT_EN                     (0x1U<<31)
#define GPIOTE_SUBSCRIBE_OUT_CHIDX                  (0xFFU<<0)
#define GPIOTE_SUBSCRIBE_OUT_CHIDX_0                (0x1U<<0)
#define GPIOTE_SUBSCRIBE_OUT_EN_DISABLED            (0x0U<<31)
#define GPIOTE_SUBSCRIBE_OUT_EN_ENABLED             (0x1U<<31)

// SUBSCRIBE_SET Configuration

#define GPIOTE_SUBSCRIBE_SET_EN                     (0x1U<<31)
#define GPIOTE_SUBSCRIBE_SET_CHIDX                  (0xFFU<<0)
#define GPIOTE_SUBSCRIBE_SET_CHIDX_0                (0x1U<<0)
#define GPIOTE_SUBSCRIBE_SET_EN_DISABLED            (0x0U<<31)
#define GPIOTE_SUBSCRIBE_SET_EN_ENABLED             (0x1U<<31)

// SUBSCRIBE_CLR Configuration

#define GPIOTE_SUBSCRIBE_CLR_EN                     (0x1U<<31)
#define GPIOTE_SUBSCRIBE_CLR_CHIDX                  (0xFFU<<0)
#define GPIOTE_SUBSCRIBE_CLR_CHIDX_0                (0x1U<<0)
#define GPIOTE_SUBSCRIBE_CLR_EN_DISABLED            (0x0U<<31)
#define GPIOTE_SUBSCRIBE_CLR_EN_ENABLED             (0x1U<<31)

// EVENTS_IN Configuration

#define GPIOTE_EVENTS_IN_EVENTS_IN                  (0x1U<<0)
#define GPIOTE_EVENTS_IN_EVENTS_IN_NOTGENERATED     (0x0U<<0)
#define GPIOTE_EVENTS_IN_EVENTS_IN_GENERATED        (0x1U<<0)

// EVENTS_PORT Configuration

#define GPIOTE_EVENTS_PORT_EVENTS_PORT              (0x1U<<0)
#define GPIOTE_EVENTS_PORT_EVENTS_PORT_NOTGENERATED (0x0U<<0)
#define GPIOTE_EVENTS_PORT_EVENTS_PORT_GENERATED    (0x1U<<0)

// PUBLISH_IN Configuration

#define GPIOTE_PUBLISH_IN_EN                        (0x1U<<31)
#define GPIOTE_PUBLISH_IN_CHIDX                     (0xFFU<<0)
#define GPIOTE_PUBLISH_IN_CHIDX_0                   (0x1U<<0)
#define GPIOTE_PUBLISH_IN_EN_DISABLED               (0x0U<<31)
#define GPIOTE_PUBLISH_IN_EN_ENABLED                (0x1U<<31)

// PUBLISH_PORT Configuration

#define GPIOTE_PUBLISH_PORT_EN                      (0x1U<<31)
#define GPIOTE_PUBLISH_PORT_CHIDX                   (0xFFU<<0)
#define GPIOTE_PUBLISH_PORT_CHIDX_0                 (0x1U<<0)
#define GPIOTE_PUBLISH_PORT_EN_DISABLED             (0x0U<<31)
#define GPIOTE_PUBLISH_PORT_EN_ENABLED              (0x1U<<31)

// INTENSET Configuration

#define GPIOTE_INTENSET_PORT                        (0x1U<<31)
#define GPIOTE_INTENSET_IN7                         (0x1U<<7)
#define GPIOTE_INTENSET_IN6                         (0x1U<<6)
#define GPIOTE_INTENSET_IN5                         (0x1U<<5)
#define GPIOTE_INTENSET_IN4                         (0x1U<<4)
#define GPIOTE_INTENSET_IN3                         (0x1U<<3)
#define GPIOTE_INTENSET_IN2                         (0x1U<<2)
#define GPIOTE_INTENSET_IN1                         (0x1U<<1)
#define GPIOTE_INTENSET_IN0                         (0x1U<<0)
#define GPIOTE_INTENSET_PORT_DISABLED               (0x0U<<31)
#define GPIOTE_INTENSET_PORT_ENABLED                (0x1U<<31)
#define GPIOTE_INTENSET_PORT_SET                    (0x1U<<31)
#define GPIOTE_INTENSET_IN7_DISABLED                (0x0U<<7)
#define GPIOTE_INTENSET_IN7_ENABLED                 (0x1U<<7)
#define GPIOTE_INTENSET_IN7_SET                     (0x1U<<7)
#define GPIOTE_INTENSET_IN6_DISABLED                (0x0U<<6)
#define GPIOTE_INTENSET_IN6_ENABLED                 (0x1U<<6)
#define GPIOTE_INTENSET_IN6_SET                     (0x1U<<6)
#define GPIOTE_INTENSET_IN5_DISABLED                (0x0U<<5)
#define GPIOTE_INTENSET_IN5_ENABLED                 (0x1U<<5)
#define GPIOTE_INTENSET_IN5_SET                     (0x1U<<5)
#define GPIOTE_INTENSET_IN4_DISABLED                (0x0U<<4)
#define GPIOTE_INTENSET_IN4_ENABLED                 (0x1U<<4)
#define GPIOTE_INTENSET_IN4_SET                     (0x1U<<4)
#define GPIOTE_INTENSET_IN3_DISABLED                (0x0U<<3)
#define GPIOTE_INTENSET_IN3_ENABLED                 (0x1U<<3)
#define GPIOTE_INTENSET_IN3_SET                     (0x1U<<3)
#define GPIOTE_INTENSET_IN2_DISABLED                (0x0U<<2)
#define GPIOTE_INTENSET_IN2_ENABLED                 (0x1U<<2)
#define GPIOTE_INTENSET_IN2_SET                     (0x1U<<2)
#define GPIOTE_INTENSET_IN1_DISABLED                (0x0U<<1)
#define GPIOTE_INTENSET_IN1_ENABLED                 (0x1U<<1)
#define GPIOTE_INTENSET_IN1_SET                     (0x1U<<1)
#define GPIOTE_INTENSET_IN0_DISABLED                (0x0U<<0)
#define GPIOTE_INTENSET_IN0_ENABLED                 (0x1U<<0)
#define GPIOTE_INTENSET_IN0_SET                     (0x1U<<0)

// INTENCLR Configuration

#define GPIOTE_INTENCLR_PORT                        (0x1U<<31)
#define GPIOTE_INTENCLR_IN7                         (0x1U<<7)
#define GPIOTE_INTENCLR_IN6                         (0x1U<<6)
#define GPIOTE_INTENCLR_IN5                         (0x1U<<5)
#define GPIOTE_INTENCLR_IN4                         (0x1U<<4)
#define GPIOTE_INTENCLR_IN3                         (0x1U<<3)
#define GPIOTE_INTENCLR_IN2                         (0x1U<<2)
#define GPIOTE_INTENCLR_IN1                         (0x1U<<1)
#define GPIOTE_INTENCLR_IN0                         (0x1U<<0)
#define GPIOTE_INTENCLR_PORT_DISABLED               (0x0U<<31)
#define GPIOTE_INTENCLR_PORT_ENABLED                (0x1U<<31)
#define GPIOTE_INTENCLR_PORT_CLEAR                  (0x1U<<31)
#define GPIOTE_INTENCLR_IN7_DISABLED                (0x0U<<7)
#define GPIOTE_INTENCLR_IN7_ENABLED                 (0x1U<<7)
#define GPIOTE_INTENCLR_IN7_CLEAR                   (0x1U<<7)
#define GPIOTE_INTENCLR_IN6_DISABLED                (0x0U<<6)
#define GPIOTE_INTENCLR_IN6_ENABLED                 (0x1U<<6)
#define GPIOTE_INTENCLR_IN6_CLEAR                   (0x1U<<6)
#define GPIOTE_INTENCLR_IN5_DISABLED                (0x0U<<5)
#define GPIOTE_INTENCLR_IN5_ENABLED                 (0x1U<<5)
#define GPIOTE_INTENCLR_IN5_CLEAR                   (0x1U<<5)
#define GPIOTE_INTENCLR_IN4_DISABLED                (0x0U<<4)
#define GPIOTE_INTENCLR_IN4_ENABLED                 (0x1U<<4)
#define GPIOTE_INTENCLR_IN4_CLEAR                   (0x1U<<4)
#define GPIOTE_INTENCLR_IN3_DISABLED                (0x0U<<3)
#define GPIOTE_INTENCLR_IN3_ENABLED                 (0x1U<<3)
#define GPIOTE_INTENCLR_IN3_CLEAR                   (0x1U<<3)
#define GPIOTE_INTENCLR_IN2_DISABLED                (0x0U<<2)
#define GPIOTE_INTENCLR_IN2_ENABLED                 (0x1U<<2)
#define GPIOTE_INTENCLR_IN2_CLEAR                   (0x1U<<2)
#define GPIOTE_INTENCLR_IN1_DISABLED                (0x0U<<1)
#define GPIOTE_INTENCLR_IN1_ENABLED                 (0x1U<<1)
#define GPIOTE_INTENCLR_IN1_CLEAR                   (0x1U<<1)
#define GPIOTE_INTENCLR_IN0_DISABLED                (0x0U<<0)
#define GPIOTE_INTENCLR_IN0_ENABLED                 (0x1U<<0)
#define GPIOTE_INTENCLR_IN0_CLEAR                   (0x1U<<0)

// LATENCY Configuration

#define GPIOTE_LATENCY_LATENCY                      (0x1U<<0)
#define GPIOTE_LATENCY_LATENCY_LOWPOWER             (0x0U<<0)
#define GPIOTE_LATENCY_LATENCY_LOWLATENCY           (0x1U<<0)

// CONFIG Configuration

#define GPIOTE_CONFIG_OUTINIT                       (0x1U<<20)
#define GPIOTE_CONFIG_POLARITY                      (0x3U<<16)
#define GPIOTE_CONFIG_POLARITY_0                    (0x1U<<16)
#define GPIOTE_CONFIG_PORT                          (0x1U<<13)
#define GPIOTE_CONFIG_PSEL                          (0x1FU<<8)
#define GPIOTE_CONFIG_PSEL_0                        (0x1U<<8)
#define GPIOTE_CONFIG_MODE                          (0x3U<<0)
#define GPIOTE_CONFIG_MODE_0                        (0x1U<<0)
#define GPIOTE_CONFIG_OUTINIT_LOW                   (0x0U<<20)
#define GPIOTE_CONFIG_OUTINIT_HIGH                  (0x1U<<20)
#define GPIOTE_CONFIG_POLARITY_NONE                 (0x0U<<16)
#define GPIOTE_CONFIG_POLARITY_LOTOHI               (0x1U<<16)
#define GPIOTE_CONFIG_POLARITY_HITOLO               (0x2U<<16)
#define GPIOTE_CONFIG_POLARITY_TOGGLE               (0x3U<<16)
#define GPIOTE_CONFIG_MODE_DISABLED                 (0x0U<<0)
#define GPIOTE_CONFIG_MODE_EVENT                    (0x1U<<0)
#define GPIOTE_CONFIG_MODE_TASK                     (0x3U<<0)
