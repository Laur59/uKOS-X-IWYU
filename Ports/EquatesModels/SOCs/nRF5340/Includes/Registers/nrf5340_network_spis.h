/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_spis equates.
 */

#pragma once

#include    <stdint.h>

// SPIS address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[9];
    volatile    uint32_t    TASKS_ACQUIRE;
    volatile    uint32_t    TASKS_RELEASE;
    volatile    uint32_t    RESERVED1[30];
    volatile    uint32_t    SUBSCRIBE_ACQUIRE;
    volatile    uint32_t    SUBSCRIBE_RELEASE;
    volatile    uint32_t    RESERVED2[22];
    volatile    uint32_t    EVENTS_END;
    volatile    uint32_t    RESERVED3[2];
    volatile    uint32_t    EVENTS_ENDRX;
    volatile    uint32_t    RESERVED4[5];
    volatile    uint32_t    EVENTS_ACQUIRED;
    volatile    uint32_t    RESERVED5[22];
    volatile    uint32_t    PUBLISH_END;
    volatile    uint32_t    RESERVED6[2];
    volatile    uint32_t    PUBLISH_ENDRX;
    volatile    uint32_t    RESERVED7[5];
    volatile    uint32_t    PUBLISH_ACQUIRED;
    volatile    uint32_t    RESERVED8[21];
    volatile    uint32_t    SHORTS;
    volatile    uint32_t    RESERVED9[64];
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED10[61];
    volatile    uint32_t    SEMSTAT;
    volatile    uint32_t    RESERVED11[15];
    volatile    uint32_t    STATUS;
    volatile    uint32_t    RESERVED12[47];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    RESERVED13;
    volatile    uint32_t    PSEL_SCK;
    volatile    uint32_t    PSEL_MISO;
    volatile    uint32_t    PSEL_MOSI;
    volatile    uint32_t    PSEL_CSN;
    volatile    uint32_t    RESERVED14[7];
    volatile    uint32_t    RXD_PTR;
    volatile    uint32_t    RXD_MAXCNT;
    volatile    uint32_t    RXD_AMOUNT;
    volatile    uint32_t    RXD_LIST;
    volatile    uint32_t    TXD_PTR;
    volatile    uint32_t    TXD_MAXCNT;
    volatile    uint32_t    TXD_AMOUNT;
    volatile    uint32_t    TXD_LIST;
    volatile    uint32_t    CONFIG;
    volatile    uint32_t    RESERVED15;
    volatile    uint32_t    DEF;
    volatile    uint32_t    RESERVED16[24];
    volatile    uint32_t    ORC;
} SPIS_TypeDef;

#ifdef __cplusplus
#define SPIS0_NS    reinterpret_cast<SPIS_TypeDef *>(0x41013000U)

#else
#define SPIS0_NS    ((SPIS_TypeDef *)0x41013000U)
#endif

// TASKS_ACQUIRE Configuration

#define SPIS_TASKS_ACQUIRE_TASKS_ACQUIRE                    (0x1U<<0)
#define SPIS_TASKS_ACQUIRE_TASKS_ACQUIRE_TRIGGER            (0x1U<<0)

// TASKS_RELEASE Configuration

#define SPIS_TASKS_RELEASE_TASKS_RELEASE                    (0x1U<<0)
#define SPIS_TASKS_RELEASE_TASKS_RELEASE_TRIGGER            (0x1U<<0)

// SUBSCRIBE_ACQUIRE Configuration

#define SPIS_SUBSCRIBE_ACQUIRE_EN                           (0x1U<<31)
#define SPIS_SUBSCRIBE_ACQUIRE_CHIDX                        (0xFFU<<0)
#define SPIS_SUBSCRIBE_ACQUIRE_CHIDX_0                      (0x1U<<0)
#define SPIS_SUBSCRIBE_ACQUIRE_EN_DISABLED                  (0x0U<<31)
#define SPIS_SUBSCRIBE_ACQUIRE_EN_ENABLED                   (0x1U<<31)

// SUBSCRIBE_RELEASE Configuration

#define SPIS_SUBSCRIBE_RELEASE_EN                           (0x1U<<31)
#define SPIS_SUBSCRIBE_RELEASE_CHIDX                        (0xFFU<<0)
#define SPIS_SUBSCRIBE_RELEASE_CHIDX_0                      (0x1U<<0)
#define SPIS_SUBSCRIBE_RELEASE_EN_DISABLED                  (0x0U<<31)
#define SPIS_SUBSCRIBE_RELEASE_EN_ENABLED                   (0x1U<<31)

// EVENTS_END Configuration

#define SPIS_EVENTS_END_EVENTS_END                          (0x1U<<0)
#define SPIS_EVENTS_END_EVENTS_END_NOTGENERATED             (0x0U<<0)
#define SPIS_EVENTS_END_EVENTS_END_GENERATED                (0x1U<<0)

// EVENTS_ENDRX Configuration

#define SPIS_EVENTS_ENDRX_EVENTS_ENDRX                      (0x1U<<0)
#define SPIS_EVENTS_ENDRX_EVENTS_ENDRX_NOTGENERATED         (0x0U<<0)
#define SPIS_EVENTS_ENDRX_EVENTS_ENDRX_GENERATED            (0x1U<<0)

// EVENTS_ACQUIRED Configuration

#define SPIS_EVENTS_ACQUIRED_EVENTS_ACQUIRED                (0x1U<<0)
#define SPIS_EVENTS_ACQUIRED_EVENTS_ACQUIRED_NOTGENERATED   (0x0U<<0)
#define SPIS_EVENTS_ACQUIRED_EVENTS_ACQUIRED_GENERATED      (0x1U<<0)

// PUBLISH_END Configuration

#define SPIS_PUBLISH_END_EN                                 (0x1U<<31)
#define SPIS_PUBLISH_END_CHIDX                              (0xFFU<<0)
#define SPIS_PUBLISH_END_CHIDX_0                            (0x1U<<0)
#define SPIS_PUBLISH_END_EN_DISABLED                        (0x0U<<31)
#define SPIS_PUBLISH_END_EN_ENABLED                         (0x1U<<31)

// PUBLISH_ENDRX Configuration

#define SPIS_PUBLISH_ENDRX_EN                               (0x1U<<31)
#define SPIS_PUBLISH_ENDRX_CHIDX                            (0xFFU<<0)
#define SPIS_PUBLISH_ENDRX_CHIDX_0                          (0x1U<<0)
#define SPIS_PUBLISH_ENDRX_EN_DISABLED                      (0x0U<<31)
#define SPIS_PUBLISH_ENDRX_EN_ENABLED                       (0x1U<<31)

// PUBLISH_ACQUIRED Configuration

#define SPIS_PUBLISH_ACQUIRED_EN                            (0x1U<<31)
#define SPIS_PUBLISH_ACQUIRED_CHIDX                         (0xFFU<<0)
#define SPIS_PUBLISH_ACQUIRED_CHIDX_0                       (0x1U<<0)
#define SPIS_PUBLISH_ACQUIRED_EN_DISABLED                   (0x0U<<31)
#define SPIS_PUBLISH_ACQUIRED_EN_ENABLED                    (0x1U<<31)

// SHORTS Configuration

#define SPIS_SHORTS_END_ACQUIRE                             (0x1U<<2)
#define SPIS_SHORTS_END_ACQUIRE_DISABLED                    (0x0U<<2)
#define SPIS_SHORTS_END_ACQUIRE_ENABLED                     (0x1U<<2)

// INTENSET Configuration

#define SPIS_INTENSET_ACQUIRED                              (0x1U<<10)
#define SPIS_INTENSET_ENDRX                                 (0x1U<<4)
#define SPIS_INTENSET_END                                   (0x1U<<1)
#define SPIS_INTENSET_ACQUIRED_DISABLED                     (0x0U<<10)
#define SPIS_INTENSET_ACQUIRED_ENABLED                      (0x1U<<10)
#define SPIS_INTENSET_ACQUIRED_SET                          (0x1U<<10)
#define SPIS_INTENSET_ENDRX_DISABLED                        (0x0U<<4)
#define SPIS_INTENSET_ENDRX_ENABLED                         (0x1U<<4)
#define SPIS_INTENSET_ENDRX_SET                             (0x1U<<4)
#define SPIS_INTENSET_END_DISABLED                          (0x0U<<1)
#define SPIS_INTENSET_END_ENABLED                           (0x1U<<1)
#define SPIS_INTENSET_END_SET                               (0x1U<<1)

// INTENCLR Configuration

#define SPIS_INTENCLR_ACQUIRED                              (0x1U<<10)
#define SPIS_INTENCLR_ENDRX                                 (0x1U<<4)
#define SPIS_INTENCLR_END                                   (0x1U<<1)
#define SPIS_INTENCLR_ACQUIRED_DISABLED                     (0x0U<<10)
#define SPIS_INTENCLR_ACQUIRED_ENABLED                      (0x1U<<10)
#define SPIS_INTENCLR_ACQUIRED_CLEAR                        (0x1U<<10)
#define SPIS_INTENCLR_ENDRX_DISABLED                        (0x0U<<4)
#define SPIS_INTENCLR_ENDRX_ENABLED                         (0x1U<<4)
#define SPIS_INTENCLR_ENDRX_CLEAR                           (0x1U<<4)
#define SPIS_INTENCLR_END_DISABLED                          (0x0U<<1)
#define SPIS_INTENCLR_END_ENABLED                           (0x1U<<1)
#define SPIS_INTENCLR_END_CLEAR                             (0x1U<<1)

// SEMSTAT Configuration

#define SPIS_SEMSTAT_SEMSTAT                                (0x3U<<0)
#define SPIS_SEMSTAT_SEMSTAT_0                              (0x1U<<0)
#define SPIS_SEMSTAT_SEMSTAT_FREE                           (0x0U<<0)
#define SPIS_SEMSTAT_SEMSTAT_CPU                            (0x1U<<0)
#define SPIS_SEMSTAT_SEMSTAT_SPIS                           (0x2U<<0)
#define SPIS_SEMSTAT_SEMSTAT_CPUPENDING                     (0x3U<<0)

// STATUS Configuration

#define SPIS_STATUS_OVERFLOW                                (0x1U<<1)
#define SPIS_STATUS_OVERREAD                                (0x1U<<0)
#define SPIS_STATUS_OVERFLOW_NOTPRESENT                     (0x0U<<1)
#define SPIS_STATUS_OVERFLOW_PRESENT                        (0x1U<<1)
#define SPIS_STATUS_OVERFLOW_CLEAR                          (0x1U<<1)
#define SPIS_STATUS_OVERREAD_NOTPRESENT                     (0x0U<<0)
#define SPIS_STATUS_OVERREAD_PRESENT                        (0x1U<<0)
#define SPIS_STATUS_OVERREAD_CLEAR                          (0x1U<<0)

// ENABLE Configuration

#define SPIS_ENABLE_ENABLE                                  (0xFU<<0)
#define SPIS_ENABLE_ENABLE_0                                (0x1U<<0)
#define SPIS_ENABLE_ENABLE_DISABLED                         (0x0U<<0)
#define SPIS_ENABLE_ENABLE_ENABLED                          (0x2U<<0)

// SCK Configuration

#define SPIS_PSEL_SCK_CONNECT                               (0x1U<<31)
#define SPIS_PSEL_SCK_PORT                                  (0x1U<<5)
#define SPIS_PSEL_SCK_PIN                                   (0x1FU<<0)
#define SPIS_PSEL_SCK_PIN_0                                 (0x1U<<0)
#define SPIS_PSEL_SCK_CONNECT_DISCONNECTED                  (0x1U<<31)
#define SPIS_PSEL_SCK_CONNECT_CONNECTED                     (0x0U<<31)

// MISO Configuration

#define SPIS_PSEL_MISO_CONNECT                              (0x1U<<31)
#define SPIS_PSEL_MISO_PORT                                 (0x1U<<5)
#define SPIS_PSEL_MISO_PIN                                  (0x1FU<<0)
#define SPIS_PSEL_MISO_PIN_0                                (0x1U<<0)
#define SPIS_PSEL_MISO_CONNECT_DISCONNECTED                 (0x1U<<31)
#define SPIS_PSEL_MISO_CONNECT_CONNECTED                    (0x0U<<31)

// MOSI Configuration

#define SPIS_PSEL_MOSI_CONNECT                              (0x1U<<31)
#define SPIS_PSEL_MOSI_PORT                                 (0x1U<<5)
#define SPIS_PSEL_MOSI_PIN                                  (0x1FU<<0)
#define SPIS_PSEL_MOSI_PIN_0                                (0x1U<<0)
#define SPIS_PSEL_MOSI_CONNECT_DISCONNECTED                 (0x1U<<31)
#define SPIS_PSEL_MOSI_CONNECT_CONNECTED                    (0x0U<<31)

// CSN Configuration

#define SPIS_PSEL_CSN_CONNECT                               (0x1U<<31)
#define SPIS_PSEL_CSN_PORT                                  (0x1U<<5)
#define SPIS_PSEL_CSN_PIN                                   (0x1FU<<0)
#define SPIS_PSEL_CSN_PIN_0                                 (0x1U<<0)
#define SPIS_PSEL_CSN_CONNECT_DISCONNECTED                  (0x1U<<31)
#define SPIS_PSEL_CSN_CONNECT_CONNECTED                     (0x0U<<31)

// PTR Configuration

#define SPIS_RXD_PTR_PTR                                    (0xFFFFFFFFU<<0)
#define SPIS_RXD_PTR_PTR_0                                  (0x1U<<0)

// MAXCNT Configuration

#define SPIS_RXD_MAXCNT_MAXCNT                              (0xFFFFU<<0)
#define SPIS_RXD_MAXCNT_MAXCNT_0                            (0x1U<<0)

// AMOUNT Configuration

#define SPIS_RXD_AMOUNT_AMOUNT                              (0xFFFFU<<0)
#define SPIS_RXD_AMOUNT_AMOUNT_0                            (0x1U<<0)

// LIST Configuration

#define SPIS_RXD_LIST_LIST                                  (0x3U<<0)
#define SPIS_RXD_LIST_LIST_0                                (0x1U<<0)
#define SPIS_RXD_LIST_LIST_DISABLED                         (0x0U<<0)
#define SPIS_RXD_LIST_LIST_ARRAYLIST                        (0x1U<<0)

// PTR Configuration

#define SPIS_TXD_PTR_PTR                                    (0xFFFFFFFFU<<0)
#define SPIS_TXD_PTR_PTR_0                                  (0x1U<<0)

// MAXCNT Configuration

#define SPIS_TXD_MAXCNT_MAXCNT                              (0xFFFFU<<0)
#define SPIS_TXD_MAXCNT_MAXCNT_0                            (0x1U<<0)

// AMOUNT Configuration

#define SPIS_TXD_AMOUNT_AMOUNT                              (0xFFFFU<<0)
#define SPIS_TXD_AMOUNT_AMOUNT_0                            (0x1U<<0)

// LIST Configuration

#define SPIS_TXD_LIST_LIST                                  (0x3U<<0)
#define SPIS_TXD_LIST_LIST_0                                (0x1U<<0)
#define SPIS_TXD_LIST_LIST_DISABLED                         (0x0U<<0)
#define SPIS_TXD_LIST_LIST_ARRAYLIST                        (0x1U<<0)

// CONFIG Configuration

#define SPIS_CONFIG_CPOL                                    (0x1U<<2)
#define SPIS_CONFIG_CPHA                                    (0x1U<<1)
#define SPIS_CONFIG_ORDER                                   (0x1U<<0)
#define SPIS_CONFIG_CPOL_ACTIVEHIGH                         (0x0U<<2)
#define SPIS_CONFIG_CPOL_ACTIVELOW                          (0x1U<<2)
#define SPIS_CONFIG_CPHA_LEADING                            (0x0U<<1)
#define SPIS_CONFIG_CPHA_TRAILING                           (0x1U<<1)
#define SPIS_CONFIG_ORDER_MSBFIRST                          (0x0U<<0)
#define SPIS_CONFIG_ORDER_LSBFIRST                          (0x1U<<0)

// DEF Configuration

#define SPIS_DEF_DEF                                        (0xFFU<<0)
#define SPIS_DEF_DEF_0                                      (0x1U<<0)

// ORC Configuration

#define SPIS_ORC_ORC                                        (0xFFU<<0)
#define SPIS_ORC_ORC_0                                      (0x1U<<0)
