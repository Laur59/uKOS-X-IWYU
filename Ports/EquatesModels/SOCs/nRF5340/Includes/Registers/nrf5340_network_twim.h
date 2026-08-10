/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_twim equates.
 */

#pragma once

#include    <stdint.h>

// TWIM address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    TASKS_STARTRX;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    TASKS_STARTTX;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    TASKS_SUSPEND;
    volatile    uint32_t    TASKS_RESUME;
    volatile    uint32_t    RESERVED3[23];
    volatile    uint32_t    SUBSCRIBE_STARTRX;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    SUBSCRIBE_STARTTX;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    SUBSCRIBE_SUSPEND;
    volatile    uint32_t    SUBSCRIBE_RESUME;
    volatile    uint32_t    RESERVED7[24];
    volatile    uint32_t    EVENTS_STOPPED;
    volatile    uint32_t    RESERVED8[7];
    volatile    uint32_t    EVENTS_ERROR;
    volatile    uint32_t    RESERVED9[8];
    volatile    uint32_t    EVENTS_SUSPENDED;
    volatile    uint32_t    EVENTS_RXSTARTED;
    volatile    uint32_t    EVENTS_TXSTARTED;
    volatile    uint32_t    RESERVED10[2];
    volatile    uint32_t    EVENTS_LASTRX;
    volatile    uint32_t    EVENTS_LASTTX;
    volatile    uint32_t    RESERVED11[8];
    volatile    uint32_t    PUBLISH_STOPPED;
    volatile    uint32_t    RESERVED12[7];
    volatile    uint32_t    PUBLISH_ERROR;
    volatile    uint32_t    RESERVED13[8];
    volatile    uint32_t    PUBLISH_SUSPENDED;
    volatile    uint32_t    PUBLISH_RXSTARTED;
    volatile    uint32_t    PUBLISH_TXSTARTED;
    volatile    uint32_t    RESERVED14[2];
    volatile    uint32_t    PUBLISH_LASTRX;
    volatile    uint32_t    PUBLISH_LASTTX;
    volatile    uint32_t    RESERVED15[7];
    volatile    uint32_t    SHORTS;
    volatile    uint32_t    RESERVED16[63];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED17[110];
    volatile    uint32_t    ERRORSRC;
    volatile    uint32_t    RESERVED18[14];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    RESERVED19;
    volatile    uint32_t    PSEL_SCL;
    volatile    uint32_t    PSEL_SDA;
    volatile    uint32_t    RESERVED20[5];
    volatile    uint32_t    FREQUENCY;
    volatile    uint32_t    RESERVED21[3];
    volatile    uint32_t    RXD_PTR;
    volatile    uint32_t    RXD_MAXCNT;
    volatile    uint32_t    RXD_AMOUNT;
    volatile    uint32_t    RXD_LIST;
    volatile    uint32_t    TXD_PTR;
    volatile    uint32_t    TXD_MAXCNT;
    volatile    uint32_t    TXD_AMOUNT;
    volatile    uint32_t    TXD_LIST;
    volatile    uint32_t    RESERVED22[13];
    volatile    uint32_t    ADDRESS;
} TWIM_TypeDef;

#ifdef __cplusplus
#define TWIM0_NS    reinterpret_cast<TWIM_TypeDef *>(0x41013000U)

#else
#define TWIM0_NS    ((TWIM_TypeDef *)0x41013000U)
#endif

// TASKS_STARTRX Configuration

#define TWIM_TASKS_STARTRX_TASKS_STARTRX                    (0x1U<<0U)
#define TWIM_TASKS_STARTRX_TASKS_STARTRX_TRIGGER            (0x1U<<0U)

// TASKS_STARTTX Configuration

#define TWIM_TASKS_STARTTX_TASKS_STARTTX                    (0x1U<<0U)
#define TWIM_TASKS_STARTTX_TASKS_STARTTX_TRIGGER            (0x1U<<0U)

// TASKS_STOP Configuration

#define TWIM_TASKS_STOP_TASKS_STOP                          (0x1U<<0U)
#define TWIM_TASKS_STOP_TASKS_STOP_TRIGGER                  (0x1U<<0U)

// TASKS_SUSPEND Configuration

#define TWIM_TASKS_SUSPEND_TASKS_SUSPEND                    (0x1U<<0U)
#define TWIM_TASKS_SUSPEND_TASKS_SUSPEND_TRIGGER            (0x1U<<0U)

// TASKS_RESUME Configuration

#define TWIM_TASKS_RESUME_TASKS_RESUME                      (0x1U<<0U)
#define TWIM_TASKS_RESUME_TASKS_RESUME_TRIGGER              (0x1U<<0U)

// SUBSCRIBE_STARTRX Configuration

#define TWIM_SUBSCRIBE_STARTRX_EN                           (0x1U<<31U)
#define TWIM_SUBSCRIBE_STARTRX_CHIDX                        (0xFFU<<0U)
#define TWIM_SUBSCRIBE_STARTRX_CHIDX_0                      (0x1U<<0U)
#define TWIM_SUBSCRIBE_STARTRX_EN_DISABLED                  (0x0U<<31U)
#define TWIM_SUBSCRIBE_STARTRX_EN_ENABLED                   (0x1U<<31U)

// SUBSCRIBE_STARTTX Configuration

#define TWIM_SUBSCRIBE_STARTTX_EN                           (0x1U<<31U)
#define TWIM_SUBSCRIBE_STARTTX_CHIDX                        (0xFFU<<0U)
#define TWIM_SUBSCRIBE_STARTTX_CHIDX_0                      (0x1U<<0U)
#define TWIM_SUBSCRIBE_STARTTX_EN_DISABLED                  (0x0U<<31U)
#define TWIM_SUBSCRIBE_STARTTX_EN_ENABLED                   (0x1U<<31U)

// SUBSCRIBE_STOP Configuration

#define TWIM_SUBSCRIBE_STOP_EN                              (0x1U<<31U)
#define TWIM_SUBSCRIBE_STOP_CHIDX                           (0xFFU<<0U)
#define TWIM_SUBSCRIBE_STOP_CHIDX_0                         (0x1U<<0U)
#define TWIM_SUBSCRIBE_STOP_EN_DISABLED                     (0x0U<<31U)
#define TWIM_SUBSCRIBE_STOP_EN_ENABLED                      (0x1U<<31U)

// SUBSCRIBE_SUSPEND Configuration

#define TWIM_SUBSCRIBE_SUSPEND_EN                           (0x1U<<31U)
#define TWIM_SUBSCRIBE_SUSPEND_CHIDX                        (0xFFU<<0U)
#define TWIM_SUBSCRIBE_SUSPEND_CHIDX_0                      (0x1U<<0U)
#define TWIM_SUBSCRIBE_SUSPEND_EN_DISABLED                  (0x0U<<31U)
#define TWIM_SUBSCRIBE_SUSPEND_EN_ENABLED                   (0x1U<<31U)

// SUBSCRIBE_RESUME Configuration

#define TWIM_SUBSCRIBE_RESUME_EN                            (0x1U<<31U)
#define TWIM_SUBSCRIBE_RESUME_CHIDX                         (0xFFU<<0U)
#define TWIM_SUBSCRIBE_RESUME_CHIDX_0                       (0x1U<<0U)
#define TWIM_SUBSCRIBE_RESUME_EN_DISABLED                   (0x0U<<31U)
#define TWIM_SUBSCRIBE_RESUME_EN_ENABLED                    (0x1U<<31U)

// EVENTS_STOPPED Configuration

#define TWIM_EVENTS_STOPPED_EVENTS_STOPPED                  (0x1U<<0U)
#define TWIM_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED     (0x0U<<0U)
#define TWIM_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED        (0x1U<<0U)

// EVENTS_ERROR Configuration

#define TWIM_EVENTS_ERROR_EVENTS_ERROR                      (0x1U<<0U)
#define TWIM_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED         (0x0U<<0U)
#define TWIM_EVENTS_ERROR_EVENTS_ERROR_GENERATED            (0x1U<<0U)

// EVENTS_SUSPENDED Configuration

#define TWIM_EVENTS_SUSPENDED_EVENTS_SUSPENDED              (0x1U<<0U)
#define TWIM_EVENTS_SUSPENDED_EVENTS_SUSPENDED_NOTGENERATED (0x0U<<0U)
#define TWIM_EVENTS_SUSPENDED_EVENTS_SUSPENDED_GENERATED    (0x1U<<0U)

// EVENTS_RXSTARTED Configuration

#define TWIM_EVENTS_RXSTARTED_EVENTS_RXSTARTED              (0x1U<<0U)
#define TWIM_EVENTS_RXSTARTED_EVENTS_RXSTARTED_NOTGENERATED (0x0U<<0U)
#define TWIM_EVENTS_RXSTARTED_EVENTS_RXSTARTED_GENERATED    (0x1U<<0U)

// EVENTS_TXSTARTED Configuration

#define TWIM_EVENTS_TXSTARTED_EVENTS_TXSTARTED              (0x1U<<0U)
#define TWIM_EVENTS_TXSTARTED_EVENTS_TXSTARTED_NOTGENERATED (0x0U<<0U)
#define TWIM_EVENTS_TXSTARTED_EVENTS_TXSTARTED_GENERATED    (0x1U<<0U)

// EVENTS_LASTRX Configuration

#define TWIM_EVENTS_LASTRX_EVENTS_LASTRX                    (0x1U<<0U)
#define TWIM_EVENTS_LASTRX_EVENTS_LASTRX_NOTGENERATED       (0x0U<<0U)
#define TWIM_EVENTS_LASTRX_EVENTS_LASTRX_GENERATED          (0x1U<<0U)

// EVENTS_LASTTX Configuration

#define TWIM_EVENTS_LASTTX_EVENTS_LASTTX                    (0x1U<<0U)
#define TWIM_EVENTS_LASTTX_EVENTS_LASTTX_NOTGENERATED       (0x0U<<0U)
#define TWIM_EVENTS_LASTTX_EVENTS_LASTTX_GENERATED          (0x1U<<0U)

// PUBLISH_STOPPED Configuration

#define TWIM_PUBLISH_STOPPED_EN                             (0x1U<<31U)
#define TWIM_PUBLISH_STOPPED_CHIDX                          (0xFFU<<0U)
#define TWIM_PUBLISH_STOPPED_CHIDX_0                        (0x1U<<0U)
#define TWIM_PUBLISH_STOPPED_EN_DISABLED                    (0x0U<<31U)
#define TWIM_PUBLISH_STOPPED_EN_ENABLED                     (0x1U<<31U)

// PUBLISH_ERROR Configuration

#define TWIM_PUBLISH_ERROR_EN                               (0x1U<<31U)
#define TWIM_PUBLISH_ERROR_CHIDX                            (0xFFU<<0U)
#define TWIM_PUBLISH_ERROR_CHIDX_0                          (0x1U<<0U)
#define TWIM_PUBLISH_ERROR_EN_DISABLED                      (0x0U<<31U)
#define TWIM_PUBLISH_ERROR_EN_ENABLED                       (0x1U<<31U)

// PUBLISH_SUSPENDED Configuration

#define TWIM_PUBLISH_SUSPENDED_EN                           (0x1U<<31U)
#define TWIM_PUBLISH_SUSPENDED_CHIDX                        (0xFFU<<0U)
#define TWIM_PUBLISH_SUSPENDED_CHIDX_0                      (0x1U<<0U)
#define TWIM_PUBLISH_SUSPENDED_EN_DISABLED                  (0x0U<<31U)
#define TWIM_PUBLISH_SUSPENDED_EN_ENABLED                   (0x1U<<31U)

// PUBLISH_RXSTARTED Configuration

#define TWIM_PUBLISH_RXSTARTED_EN                           (0x1U<<31U)
#define TWIM_PUBLISH_RXSTARTED_CHIDX                        (0xFFU<<0U)
#define TWIM_PUBLISH_RXSTARTED_CHIDX_0                      (0x1U<<0U)
#define TWIM_PUBLISH_RXSTARTED_EN_DISABLED                  (0x0U<<31U)
#define TWIM_PUBLISH_RXSTARTED_EN_ENABLED                   (0x1U<<31U)

// PUBLISH_TXSTARTED Configuration

#define TWIM_PUBLISH_TXSTARTED_EN                           (0x1U<<31U)
#define TWIM_PUBLISH_TXSTARTED_CHIDX                        (0xFFU<<0U)
#define TWIM_PUBLISH_TXSTARTED_CHIDX_0                      (0x1U<<0U)
#define TWIM_PUBLISH_TXSTARTED_EN_DISABLED                  (0x0U<<31U)
#define TWIM_PUBLISH_TXSTARTED_EN_ENABLED                   (0x1U<<31U)

// PUBLISH_LASTRX Configuration

#define TWIM_PUBLISH_LASTRX_EN                              (0x1U<<31U)
#define TWIM_PUBLISH_LASTRX_CHIDX                           (0xFFU<<0U)
#define TWIM_PUBLISH_LASTRX_CHIDX_0                         (0x1U<<0U)
#define TWIM_PUBLISH_LASTRX_EN_DISABLED                     (0x0U<<31U)
#define TWIM_PUBLISH_LASTRX_EN_ENABLED                      (0x1U<<31U)

// PUBLISH_LASTTX Configuration

#define TWIM_PUBLISH_LASTTX_EN                              (0x1U<<31U)
#define TWIM_PUBLISH_LASTTX_CHIDX                           (0xFFU<<0U)
#define TWIM_PUBLISH_LASTTX_CHIDX_0                         (0x1U<<0U)
#define TWIM_PUBLISH_LASTTX_EN_DISABLED                     (0x0U<<31U)
#define TWIM_PUBLISH_LASTTX_EN_ENABLED                      (0x1U<<31U)

// SHORTS Configuration

#define TWIM_SHORTS_LASTRX_STOP                             (0x1U<<12U)
#define TWIM_SHORTS_LASTRX_STARTTX                          (0x1U<<10U)
#define TWIM_SHORTS_LASTTX_STOP                             (0x1U<<9U)
#define TWIM_SHORTS_LASTTX_SUSPEND                          (0x1U<<8U)
#define TWIM_SHORTS_LASTTX_STARTRX                          (0x1U<<7U)
#define TWIM_SHORTS_LASTRX_STOP_DISABLED                    (0x0U<<12U)
#define TWIM_SHORTS_LASTRX_STOP_ENABLED                     (0x1U<<12U)
#define TWIM_SHORTS_LASTRX_STARTTX_DISABLED                 (0x0U<<10U)
#define TWIM_SHORTS_LASTRX_STARTTX_ENABLED                  (0x1U<<10U)
#define TWIM_SHORTS_LASTTX_STOP_DISABLED                    (0x0U<<9U)
#define TWIM_SHORTS_LASTTX_STOP_ENABLED                     (0x1U<<9U)
#define TWIM_SHORTS_LASTTX_SUSPEND_DISABLED                 (0x0U<<8U)
#define TWIM_SHORTS_LASTTX_SUSPEND_ENABLED                  (0x1U<<8U)
#define TWIM_SHORTS_LASTTX_STARTRX_DISABLED                 (0x0U<<7U)
#define TWIM_SHORTS_LASTTX_STARTRX_ENABLED                  (0x1U<<7U)

// INTEN Configuration

#define TWIM_INTEN_LASTTX                                   (0x1U<<24U)
#define TWIM_INTEN_LASTRX                                   (0x1U<<23U)
#define TWIM_INTEN_TXSTARTED                                (0x1U<<20U)
#define TWIM_INTEN_RXSTARTED                                (0x1U<<19U)
#define TWIM_INTEN_SUSPENDED                                (0x1U<<18U)
#define TWIM_INTEN_ERROR                                    (0x1U<<9U)
#define TWIM_INTEN_STOPPED                                  (0x1U<<1U)
#define TWIM_INTEN_LASTTX_DISABLED                          (0x0U<<24U)
#define TWIM_INTEN_LASTTX_ENABLED                           (0x1U<<24U)
#define TWIM_INTEN_LASTRX_DISABLED                          (0x0U<<23U)
#define TWIM_INTEN_LASTRX_ENABLED                           (0x1U<<23U)
#define TWIM_INTEN_TXSTARTED_DISABLED                       (0x0U<<20U)
#define TWIM_INTEN_TXSTARTED_ENABLED                        (0x1U<<20U)
#define TWIM_INTEN_RXSTARTED_DISABLED                       (0x0U<<19U)
#define TWIM_INTEN_RXSTARTED_ENABLED                        (0x1U<<19U)
#define TWIM_INTEN_SUSPENDED_DISABLED                       (0x0U<<18U)
#define TWIM_INTEN_SUSPENDED_ENABLED                        (0x1U<<18U)
#define TWIM_INTEN_ERROR_DISABLED                           (0x0U<<9U)
#define TWIM_INTEN_ERROR_ENABLED                            (0x1U<<9U)
#define TWIM_INTEN_STOPPED_DISABLED                         (0x0U<<1U)
#define TWIM_INTEN_STOPPED_ENABLED                          (0x1U<<1U)

// INTENSET Configuration

#define TWIM_INTENSET_LASTTX                                (0x1U<<24U)
#define TWIM_INTENSET_LASTRX                                (0x1U<<23U)
#define TWIM_INTENSET_TXSTARTED                             (0x1U<<20U)
#define TWIM_INTENSET_RXSTARTED                             (0x1U<<19U)
#define TWIM_INTENSET_SUSPENDED                             (0x1U<<18U)
#define TWIM_INTENSET_ERROR                                 (0x1U<<9U)
#define TWIM_INTENSET_STOPPED                               (0x1U<<1U)
#define TWIM_INTENSET_LASTTX_DISABLED                       (0x0U<<24U)
#define TWIM_INTENSET_LASTTX_ENABLED                        (0x1U<<24U)
#define TWIM_INTENSET_LASTTX_SET                            (0x1U<<24U)
#define TWIM_INTENSET_LASTRX_DISABLED                       (0x0U<<23U)
#define TWIM_INTENSET_LASTRX_ENABLED                        (0x1U<<23U)
#define TWIM_INTENSET_LASTRX_SET                            (0x1U<<23U)
#define TWIM_INTENSET_TXSTARTED_DISABLED                    (0x0U<<20U)
#define TWIM_INTENSET_TXSTARTED_ENABLED                     (0x1U<<20U)
#define TWIM_INTENSET_TXSTARTED_SET                         (0x1U<<20U)
#define TWIM_INTENSET_RXSTARTED_DISABLED                    (0x0U<<19U)
#define TWIM_INTENSET_RXSTARTED_ENABLED                     (0x1U<<19U)
#define TWIM_INTENSET_RXSTARTED_SET                         (0x1U<<19U)
#define TWIM_INTENSET_SUSPENDED_DISABLED                    (0x0U<<18U)
#define TWIM_INTENSET_SUSPENDED_ENABLED                     (0x1U<<18U)
#define TWIM_INTENSET_SUSPENDED_SET                         (0x1U<<18U)
#define TWIM_INTENSET_ERROR_DISABLED                        (0x0U<<9U)
#define TWIM_INTENSET_ERROR_ENABLED                         (0x1U<<9U)
#define TWIM_INTENSET_ERROR_SET                             (0x1U<<9U)
#define TWIM_INTENSET_STOPPED_DISABLED                      (0x0U<<1U)
#define TWIM_INTENSET_STOPPED_ENABLED                       (0x1U<<1U)
#define TWIM_INTENSET_STOPPED_SET                           (0x1U<<1U)

// INTENCLR Configuration

#define TWIM_INTENCLR_LASTTX                                (0x1U<<24U)
#define TWIM_INTENCLR_LASTRX                                (0x1U<<23U)
#define TWIM_INTENCLR_TXSTARTED                             (0x1U<<20U)
#define TWIM_INTENCLR_RXSTARTED                             (0x1U<<19U)
#define TWIM_INTENCLR_SUSPENDED                             (0x1U<<18U)
#define TWIM_INTENCLR_ERROR                                 (0x1U<<9U)
#define TWIM_INTENCLR_STOPPED                               (0x1U<<1U)
#define TWIM_INTENCLR_LASTTX_DISABLED                       (0x0U<<24U)
#define TWIM_INTENCLR_LASTTX_ENABLED                        (0x1U<<24U)
#define TWIM_INTENCLR_LASTTX_CLEAR                          (0x1U<<24U)
#define TWIM_INTENCLR_LASTRX_DISABLED                       (0x0U<<23U)
#define TWIM_INTENCLR_LASTRX_ENABLED                        (0x1U<<23U)
#define TWIM_INTENCLR_LASTRX_CLEAR                          (0x1U<<23U)
#define TWIM_INTENCLR_TXSTARTED_DISABLED                    (0x0U<<20U)
#define TWIM_INTENCLR_TXSTARTED_ENABLED                     (0x1U<<20U)
#define TWIM_INTENCLR_TXSTARTED_CLEAR                       (0x1U<<20U)
#define TWIM_INTENCLR_RXSTARTED_DISABLED                    (0x0U<<19U)
#define TWIM_INTENCLR_RXSTARTED_ENABLED                     (0x1U<<19U)
#define TWIM_INTENCLR_RXSTARTED_CLEAR                       (0x1U<<19U)
#define TWIM_INTENCLR_SUSPENDED_DISABLED                    (0x0U<<18U)
#define TWIM_INTENCLR_SUSPENDED_ENABLED                     (0x1U<<18U)
#define TWIM_INTENCLR_SUSPENDED_CLEAR                       (0x1U<<18U)
#define TWIM_INTENCLR_ERROR_DISABLED                        (0x0U<<9U)
#define TWIM_INTENCLR_ERROR_ENABLED                         (0x1U<<9U)
#define TWIM_INTENCLR_ERROR_CLEAR                           (0x1U<<9U)
#define TWIM_INTENCLR_STOPPED_DISABLED                      (0x0U<<1U)
#define TWIM_INTENCLR_STOPPED_ENABLED                       (0x1U<<1U)
#define TWIM_INTENCLR_STOPPED_CLEAR                         (0x1U<<1U)

// ERRORSRC Configuration

#define TWIM_ERRORSRC_DNACK                                 (0x1U<<2U)
#define TWIM_ERRORSRC_ANACK                                 (0x1U<<1U)
#define TWIM_ERRORSRC_OVERRUN                               (0x1U<<0U)
#define TWIM_ERRORSRC_DNACK_NOTRECEIVED                     (0x0U<<2U)
#define TWIM_ERRORSRC_DNACK_RECEIVED                        (0x1U<<2U)
#define TWIM_ERRORSRC_ANACK_NOTRECEIVED                     (0x0U<<1U)
#define TWIM_ERRORSRC_ANACK_RECEIVED                        (0x1U<<1U)
#define TWIM_ERRORSRC_OVERRUN_NOTRECEIVED                   (0x0U<<0U)
#define TWIM_ERRORSRC_OVERRUN_RECEIVED                      (0x1U<<0U)

// ENABLE Configuration

#define TWIM_ENABLE_ENABLE                                  (0xFU<<0U)
#define TWIM_ENABLE_ENABLE_0                                (0x1U<<0U)
#define TWIM_ENABLE_ENABLE_DISABLED                         (0x0U<<0U)
#define TWIM_ENABLE_ENABLE_ENABLED                          (0x6U<<0U)

// SCL Configuration

#define TWIM_PSEL_SCL_CONNECT                               (0x1U<<31U)
#define TWIM_PSEL_SCL_PORT                                  (0x1U<<5U)
#define TWIM_PSEL_SCL_PIN                                   (0x1FU<<0U)
#define TWIM_PSEL_SCL_PIN_0                                 (0x1U<<0U)
#define TWIM_PSEL_SCL_CONNECT_DISCONNECTED                  (0x1U<<31U)
#define TWIM_PSEL_SCL_CONNECT_CONNECTED                     (0x0U<<31U)

// SDA Configuration

#define TWIM_PSEL_SDA_CONNECT                               (0x1U<<31U)
#define TWIM_PSEL_SDA_PORT                                  (0x1U<<5U)
#define TWIM_PSEL_SDA_PIN                                   (0x1FU<<0U)
#define TWIM_PSEL_SDA_PIN_0                                 (0x1U<<0U)
#define TWIM_PSEL_SDA_CONNECT_DISCONNECTED                  (0x1U<<31U)
#define TWIM_PSEL_SDA_CONNECT_CONNECTED                     (0x0U<<31U)

// FREQUENCY Configuration

#define TWIM_FREQUENCY_FREQUENCY                            (0xFFFFFFFFU<<0U)
#define TWIM_FREQUENCY_FREQUENCY_0                          (0x1U<<0U)
#define TWIM_FREQUENCY_FREQUENCY_K100                       (0x1980000U<<0U)
#define TWIM_FREQUENCY_FREQUENCY_K250                       (0x4000000U<<0U)
#define TWIM_FREQUENCY_FREQUENCY_K400                       (0x6400000U<<0U)
#define TWIM_FREQUENCY_FREQUENCY_K1000                      (0xFF00000U<<0U)

// PTR Configuration

#define TWIM_RXD_PTR_PTR                                    (0xFFFFFFFFU<<0U)
#define TWIM_RXD_PTR_PTR_0                                  (0x1U<<0U)

// MAXCNT Configuration

#define TWIM_RXD_MAXCNT_MAXCNT                              (0xFFFFU<<0U)
#define TWIM_RXD_MAXCNT_MAXCNT_0                            (0x1U<<0U)

// AMOUNT Configuration

#define TWIM_RXD_AMOUNT_AMOUNT                              (0xFFFFU<<0U)
#define TWIM_RXD_AMOUNT_AMOUNT_0                            (0x1U<<0U)

// LIST Configuration

#define TWIM_RXD_LIST_LIST                                  (0x7U<<0U)
#define TWIM_RXD_LIST_LIST_0                                (0x1U<<0U)
#define TWIM_RXD_LIST_LIST_DISABLED                         (0x0U<<0U)
#define TWIM_RXD_LIST_LIST_ARRAYLIST                        (0x1U<<0U)

// PTR Configuration

#define TWIM_TXD_PTR_PTR                                    (0xFFFFFFFFU<<0U)
#define TWIM_TXD_PTR_PTR_0                                  (0x1U<<0U)

// MAXCNT Configuration

#define TWIM_TXD_MAXCNT_MAXCNT                              (0xFFFFU<<0U)
#define TWIM_TXD_MAXCNT_MAXCNT_0                            (0x1U<<0U)

// AMOUNT Configuration

#define TWIM_TXD_AMOUNT_AMOUNT                              (0xFFFFU<<0U)
#define TWIM_TXD_AMOUNT_AMOUNT_0                            (0x1U<<0U)

// LIST Configuration

#define TWIM_TXD_LIST_LIST                                  (0x7U<<0U)
#define TWIM_TXD_LIST_LIST_0                                (0x1U<<0U)
#define TWIM_TXD_LIST_LIST_DISABLED                         (0x0U<<0U)
#define TWIM_TXD_LIST_LIST_ARRAYLIST                        (0x1U<<0U)

// ADDRESS Configuration

#define TWIM_ADDRESS_ADDRESS                                (0x7FU<<0U)
#define TWIM_ADDRESS_ADDRESS_0                              (0x1U<<0U)
