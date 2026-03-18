/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_tad equates.
 */

#pragma once

#include    <stdint.h>

// TAD address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CLOCKSTART;
    volatile    uint32_t    CLOCKSTOP;
    volatile    uint32_t    RESERVED1[317];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    PSEL_TRACECLK;
    volatile    uint32_t    PSEL_TRACEDATA0;
    volatile    uint32_t    PSEL_TRACEDATA1;
    volatile    uint32_t    PSEL_TRACEDATA2;
    volatile    uint32_t    PSEL_TRACEDATA3;
    volatile    uint32_t    TRACEPORTSPEED;
} TAD_TypeDef;

#ifdef __cplusplus
#define TAD_S   reinterpret_cast<TAD_TypeDef *>(0xE0080000U)

#else
#define TAD_S   ((TAD_TypeDef *)0xE0080000U)
#endif

// CLOCKSTART Configuration

#define TAD_CLOCKSTART_START                            (0x1U<<0)
#define TAD_CLOCKSTART_START_START                      (0x1U<<0)

// CLOCKSTOP Configuration

#define TAD_CLOCKSTOP_STOP                              (0x1U<<0)
#define TAD_CLOCKSTOP_STOP_STOP                         (0x1U<<0)

// ENABLE Configuration

#define TAD_ENABLE_ENABLE                               (0x1U<<0)
#define TAD_ENABLE_ENABLE_DISABLED                      (0x0U<<0)
#define TAD_ENABLE_ENABLE_ENABLED                       (0x1U<<0)

// TRACECLK Configuration

#define TAD_PSEL_TRACECLK_CONNECT                       (0x1U<<31)
#define TAD_PSEL_TRACECLK_PIN                           (0x1FU<<0)
#define TAD_PSEL_TRACECLK_PIN_0                         (0x1U<<0)
#define TAD_PSEL_TRACECLK_CONNECT_DISCONNECTED          (0x1U<<31)
#define TAD_PSEL_TRACECLK_CONNECT_CONNECTED             (0x0U<<31)
#define TAD_PSEL_TRACECLK_PIN_TRACECLK                  (0xCU<<0)

// TRACEDATA0 Configuration

#define TAD_PSEL_TRACEDATA0_CONNECT                     (0x1U<<31)
#define TAD_PSEL_TRACEDATA0_PIN                         (0x1FU<<0)
#define TAD_PSEL_TRACEDATA0_PIN_0                       (0x1U<<0)
#define TAD_PSEL_TRACEDATA0_CONNECT_DISCONNECTED        (0x1U<<31)
#define TAD_PSEL_TRACEDATA0_CONNECT_CONNECTED           (0x0U<<31)
#define TAD_PSEL_TRACEDATA0_PIN_TRACEDATA0              (0xBU<<0)

// TRACEDATA1 Configuration

#define TAD_PSEL_TRACEDATA1_CONNECT                     (0x1U<<31)
#define TAD_PSEL_TRACEDATA1_PIN                         (0x1FU<<0)
#define TAD_PSEL_TRACEDATA1_PIN_0                       (0x1U<<0)
#define TAD_PSEL_TRACEDATA1_CONNECT_DISCONNECTED        (0x1U<<31)
#define TAD_PSEL_TRACEDATA1_CONNECT_CONNECTED           (0x0U<<31)
#define TAD_PSEL_TRACEDATA1_PIN_TRACEDATA1              (0xAU<<0)

// TRACEDATA2 Configuration

#define TAD_PSEL_TRACEDATA2_CONNECT                     (0x1U<<31)
#define TAD_PSEL_TRACEDATA2_PIN                         (0x1FU<<0)
#define TAD_PSEL_TRACEDATA2_PIN_0                       (0x1U<<0)
#define TAD_PSEL_TRACEDATA2_CONNECT_DISCONNECTED        (0x1U<<31)
#define TAD_PSEL_TRACEDATA2_CONNECT_CONNECTED           (0x0U<<31)
#define TAD_PSEL_TRACEDATA2_PIN_TRACEDATA2              (0x9U<<0)

// TRACEDATA3 Configuration

#define TAD_PSEL_TRACEDATA3_CONNECT                     (0x1U<<31)
#define TAD_PSEL_TRACEDATA3_PIN                         (0x1FU<<0)
#define TAD_PSEL_TRACEDATA3_PIN_0                       (0x1U<<0)
#define TAD_PSEL_TRACEDATA3_CONNECT_DISCONNECTED        (0x1U<<31)
#define TAD_PSEL_TRACEDATA3_CONNECT_CONNECTED           (0x0U<<31)
#define TAD_PSEL_TRACEDATA3_PIN_TRACEDATA3              (0x8U<<0)

// TRACEPORTSPEED Configuration

#define TAD_TRACEPORTSPEED_TRACEPORTSPEED               (0x3U<<0)
#define TAD_TRACEPORTSPEED_TRACEPORTSPEED_0             (0x1U<<0)
#define TAD_TRACEPORTSPEED_TRACEPORTSPEED_64MHZ         (0x0U<<0)
#define TAD_TRACEPORTSPEED_TRACEPORTSPEED_32MHZ         (0x1U<<0)
#define TAD_TRACEPORTSPEED_TRACEPORTSPEED_16MHZ         (0x2U<<0)
#define TAD_TRACEPORTSPEED_TRACEPORTSPEED_8MHZ          (0x3U<<0)
