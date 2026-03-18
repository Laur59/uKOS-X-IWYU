/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_twis equates.
 */

#pragma once

#include    <stdint.h>

// TWIS address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[5];
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    TASKS_SUSPEND;
    volatile    uint32_t    TASKS_RESUME;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    TASKS_PREPARERX;
    volatile    uint32_t    TASKS_PREPARETX;
    volatile    uint32_t    RESERVED3[23];
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    SUBSCRIBE_SUSPEND;
    volatile    uint32_t    SUBSCRIBE_RESUME;
    volatile    uint32_t    RESERVED5[3];
    volatile    uint32_t    SUBSCRIBE_PREPARERX;
    volatile    uint32_t    SUBSCRIBE_PREPARETX;
    volatile    uint32_t    RESERVED6[19];
    volatile    uint32_t    EVENTS_STOPPED;
    volatile    uint32_t    RESERVED7[7];
    volatile    uint32_t    EVENTS_ERROR;
    volatile    uint32_t    RESERVED8[9];
    volatile    uint32_t    EVENTS_RXSTARTED;
    volatile    uint32_t    EVENTS_TXSTARTED;
    volatile    uint32_t    RESERVED9[4];
    volatile    uint32_t    EVENTS_WRITE;
    volatile    uint32_t    EVENTS_READ;
    volatile    uint32_t    RESERVED10[6];
    volatile    uint32_t    PUBLISH_STOPPED;
    volatile    uint32_t    RESERVED11[7];
    volatile    uint32_t    PUBLISH_ERROR;
    volatile    uint32_t    RESERVED12[9];
    volatile    uint32_t    PUBLISH_RXSTARTED;
    volatile    uint32_t    PUBLISH_TXSTARTED;
    volatile    uint32_t    RESERVED13[4];
    volatile    uint32_t    PUBLISH_WRITE;
    volatile    uint32_t    PUBLISH_READ;
    volatile    uint32_t    RESERVED14[5];
    volatile    uint32_t    SHORTS;
    volatile    uint32_t    RESERVED15[63];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED16[113];
    volatile    uint32_t    ERRORSRC;
    volatile    uint32_t    MATCH;
    volatile    uint32_t    RESERVED17[10];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    RESERVED18;
    volatile    uint32_t    PSEL_SCL;
    volatile    uint32_t    PSEL_SDA;
    volatile    uint32_t    RESERVED19[9];
    volatile    uint32_t    RXD_PTR;
    volatile    uint32_t    RXD_MAXCNT;
    volatile    uint32_t    RXD_AMOUNT;
    volatile    uint32_t    RXD_LIST;
    volatile    uint32_t    TXD_PTR;
    volatile    uint32_t    TXD_MAXCNT;
    volatile    uint32_t    TXD_AMOUNT;
    volatile    uint32_t    TXD_LIST;
    volatile    uint32_t    RESERVED20[13];
    volatile    uint32_t    ADDRESS[2];
    volatile    uint32_t    RESERVED21;
    volatile    uint32_t    CONFIG;
    volatile    uint32_t    RESERVED22[10];
    volatile    uint32_t    ORC;
} TWIS_TypeDef;

#ifdef __cplusplus
#define TWIS0_NS    reinterpret_cast<TWIS_TypeDef *>(0x41013000U)

#else
#define TWIS0_NS    ((TWIS_TypeDef *)0x41013000U)
#endif

// TASKS_STOP Configuration

#define TWIS_TASKS_STOP_TASKS_STOP                          (0x1U<<0)
#define TWIS_TASKS_STOP_TASKS_STOP_TRIGGER                  (0x1U<<0)

// TASKS_SUSPEND Configuration

#define TWIS_TASKS_SUSPEND_TASKS_SUSPEND                    (0x1U<<0)
#define TWIS_TASKS_SUSPEND_TASKS_SUSPEND_TRIGGER            (0x1U<<0)

// TASKS_RESUME Configuration

#define TWIS_TASKS_RESUME_TASKS_RESUME                      (0x1U<<0)
#define TWIS_TASKS_RESUME_TASKS_RESUME_TRIGGER              (0x1U<<0)

// TASKS_PREPARERX Configuration

#define TWIS_TASKS_PREPARERX_TASKS_PREPARERX                (0x1U<<0)
#define TWIS_TASKS_PREPARERX_TASKS_PREPARERX_TRIGGER        (0x1U<<0)

// TASKS_PREPARETX Configuration

#define TWIS_TASKS_PREPARETX_TASKS_PREPARETX                (0x1U<<0)
#define TWIS_TASKS_PREPARETX_TASKS_PREPARETX_TRIGGER        (0x1U<<0)

// SUBSCRIBE_STOP Configuration

#define TWIS_SUBSCRIBE_STOP_EN                              (0x1U<<31)
#define TWIS_SUBSCRIBE_STOP_CHIDX                           (0xFFU<<0)
#define TWIS_SUBSCRIBE_STOP_CHIDX_0                         (0x1U<<0)
#define TWIS_SUBSCRIBE_STOP_EN_DISABLED                     (0x0U<<31)
#define TWIS_SUBSCRIBE_STOP_EN_ENABLED                      (0x1U<<31)

// SUBSCRIBE_SUSPEND Configuration

#define TWIS_SUBSCRIBE_SUSPEND_EN                           (0x1U<<31)
#define TWIS_SUBSCRIBE_SUSPEND_CHIDX                        (0xFFU<<0)
#define TWIS_SUBSCRIBE_SUSPEND_CHIDX_0                      (0x1U<<0)
#define TWIS_SUBSCRIBE_SUSPEND_EN_DISABLED                  (0x0U<<31)
#define TWIS_SUBSCRIBE_SUSPEND_EN_ENABLED                   (0x1U<<31)

// SUBSCRIBE_RESUME Configuration

#define TWIS_SUBSCRIBE_RESUME_EN                            (0x1U<<31)
#define TWIS_SUBSCRIBE_RESUME_CHIDX                         (0xFFU<<0)
#define TWIS_SUBSCRIBE_RESUME_CHIDX_0                       (0x1U<<0)
#define TWIS_SUBSCRIBE_RESUME_EN_DISABLED                   (0x0U<<31)
#define TWIS_SUBSCRIBE_RESUME_EN_ENABLED                    (0x1U<<31)

// SUBSCRIBE_PREPARERX Configuration

#define TWIS_SUBSCRIBE_PREPARERX_EN                         (0x1U<<31)
#define TWIS_SUBSCRIBE_PREPARERX_CHIDX                      (0xFFU<<0)
#define TWIS_SUBSCRIBE_PREPARERX_CHIDX_0                    (0x1U<<0)
#define TWIS_SUBSCRIBE_PREPARERX_EN_DISABLED                (0x0U<<31)
#define TWIS_SUBSCRIBE_PREPARERX_EN_ENABLED                 (0x1U<<31)

// SUBSCRIBE_PREPARETX Configuration

#define TWIS_SUBSCRIBE_PREPARETX_EN                         (0x1U<<31)
#define TWIS_SUBSCRIBE_PREPARETX_CHIDX                      (0xFFU<<0)
#define TWIS_SUBSCRIBE_PREPARETX_CHIDX_0                    (0x1U<<0)
#define TWIS_SUBSCRIBE_PREPARETX_EN_DISABLED                (0x0U<<31)
#define TWIS_SUBSCRIBE_PREPARETX_EN_ENABLED                 (0x1U<<31)

// EVENTS_STOPPED Configuration

#define TWIS_EVENTS_STOPPED_EVENTS_STOPPED                  (0x1U<<0)
#define TWIS_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED     (0x0U<<0)
#define TWIS_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED        (0x1U<<0)

// EVENTS_ERROR Configuration

#define TWIS_EVENTS_ERROR_EVENTS_ERROR                      (0x1U<<0)
#define TWIS_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED         (0x0U<<0)
#define TWIS_EVENTS_ERROR_EVENTS_ERROR_GENERATED            (0x1U<<0)

// EVENTS_RXSTARTED Configuration

#define TWIS_EVENTS_RXSTARTED_EVENTS_RXSTARTED              (0x1U<<0)
#define TWIS_EVENTS_RXSTARTED_EVENTS_RXSTARTED_NOTGENERATED (0x0U<<0)
#define TWIS_EVENTS_RXSTARTED_EVENTS_RXSTARTED_GENERATED    (0x1U<<0)

// EVENTS_TXSTARTED Configuration

#define TWIS_EVENTS_TXSTARTED_EVENTS_TXSTARTED              (0x1U<<0)
#define TWIS_EVENTS_TXSTARTED_EVENTS_TXSTARTED_NOTGENERATED (0x0U<<0)
#define TWIS_EVENTS_TXSTARTED_EVENTS_TXSTARTED_GENERATED    (0x1U<<0)

// EVENTS_WRITE Configuration

#define TWIS_EVENTS_WRITE_EVENTS_WRITE                      (0x1U<<0)
#define TWIS_EVENTS_WRITE_EVENTS_WRITE_NOTGENERATED         (0x0U<<0)
#define TWIS_EVENTS_WRITE_EVENTS_WRITE_GENERATED            (0x1U<<0)

// EVENTS_READ Configuration

#define TWIS_EVENTS_READ_EVENTS_READ                        (0x1U<<0)
#define TWIS_EVENTS_READ_EVENTS_READ_NOTGENERATED           (0x0U<<0)
#define TWIS_EVENTS_READ_EVENTS_READ_GENERATED              (0x1U<<0)

// PUBLISH_STOPPED Configuration

#define TWIS_PUBLISH_STOPPED_EN                             (0x1U<<31)
#define TWIS_PUBLISH_STOPPED_CHIDX                          (0xFFU<<0)
#define TWIS_PUBLISH_STOPPED_CHIDX_0                        (0x1U<<0)
#define TWIS_PUBLISH_STOPPED_EN_DISABLED                    (0x0U<<31)
#define TWIS_PUBLISH_STOPPED_EN_ENABLED                     (0x1U<<31)

// PUBLISH_ERROR Configuration

#define TWIS_PUBLISH_ERROR_EN                               (0x1U<<31)
#define TWIS_PUBLISH_ERROR_CHIDX                            (0xFFU<<0)
#define TWIS_PUBLISH_ERROR_CHIDX_0                          (0x1U<<0)
#define TWIS_PUBLISH_ERROR_EN_DISABLED                      (0x0U<<31)
#define TWIS_PUBLISH_ERROR_EN_ENABLED                       (0x1U<<31)

// PUBLISH_RXSTARTED Configuration

#define TWIS_PUBLISH_RXSTARTED_EN                           (0x1U<<31)
#define TWIS_PUBLISH_RXSTARTED_CHIDX                        (0xFFU<<0)
#define TWIS_PUBLISH_RXSTARTED_CHIDX_0                      (0x1U<<0)
#define TWIS_PUBLISH_RXSTARTED_EN_DISABLED                  (0x0U<<31)
#define TWIS_PUBLISH_RXSTARTED_EN_ENABLED                   (0x1U<<31)

// PUBLISH_TXSTARTED Configuration

#define TWIS_PUBLISH_TXSTARTED_EN                           (0x1U<<31)
#define TWIS_PUBLISH_TXSTARTED_CHIDX                        (0xFFU<<0)
#define TWIS_PUBLISH_TXSTARTED_CHIDX_0                      (0x1U<<0)
#define TWIS_PUBLISH_TXSTARTED_EN_DISABLED                  (0x0U<<31)
#define TWIS_PUBLISH_TXSTARTED_EN_ENABLED                   (0x1U<<31)

// PUBLISH_WRITE Configuration

#define TWIS_PUBLISH_WRITE_EN                               (0x1U<<31)
#define TWIS_PUBLISH_WRITE_CHIDX                            (0xFFU<<0)
#define TWIS_PUBLISH_WRITE_CHIDX_0                          (0x1U<<0)
#define TWIS_PUBLISH_WRITE_EN_DISABLED                      (0x0U<<31)
#define TWIS_PUBLISH_WRITE_EN_ENABLED                       (0x1U<<31)

// PUBLISH_READ Configuration

#define TWIS_PUBLISH_READ_EN                                (0x1U<<31)
#define TWIS_PUBLISH_READ_CHIDX                             (0xFFU<<0)
#define TWIS_PUBLISH_READ_CHIDX_0                           (0x1U<<0)
#define TWIS_PUBLISH_READ_EN_DISABLED                       (0x0U<<31)
#define TWIS_PUBLISH_READ_EN_ENABLED                        (0x1U<<31)

// SHORTS Configuration

#define TWIS_SHORTS_READ_SUSPEND                            (0x1U<<14)
#define TWIS_SHORTS_WRITE_SUSPEND                           (0x1U<<13)
#define TWIS_SHORTS_READ_SUSPEND_DISABLED                   (0x0U<<14)
#define TWIS_SHORTS_READ_SUSPEND_ENABLED                    (0x1U<<14)
#define TWIS_SHORTS_WRITE_SUSPEND_DISABLED                  (0x0U<<13)
#define TWIS_SHORTS_WRITE_SUSPEND_ENABLED                   (0x1U<<13)

// INTEN Configuration

#define TWIS_INTEN_READ                                     (0x1U<<26)
#define TWIS_INTEN_WRITE                                    (0x1U<<25)
#define TWIS_INTEN_TXSTARTED                                (0x1U<<20)
#define TWIS_INTEN_RXSTARTED                                (0x1U<<19)
#define TWIS_INTEN_ERROR                                    (0x1U<<9)
#define TWIS_INTEN_STOPPED                                  (0x1U<<1)
#define TWIS_INTEN_READ_DISABLED                            (0x0U<<26)
#define TWIS_INTEN_READ_ENABLED                             (0x1U<<26)
#define TWIS_INTEN_WRITE_DISABLED                           (0x0U<<25)
#define TWIS_INTEN_WRITE_ENABLED                            (0x1U<<25)
#define TWIS_INTEN_TXSTARTED_DISABLED                       (0x0U<<20)
#define TWIS_INTEN_TXSTARTED_ENABLED                        (0x1U<<20)
#define TWIS_INTEN_RXSTARTED_DISABLED                       (0x0U<<19)
#define TWIS_INTEN_RXSTARTED_ENABLED                        (0x1U<<19)
#define TWIS_INTEN_ERROR_DISABLED                           (0x0U<<9)
#define TWIS_INTEN_ERROR_ENABLED                            (0x1U<<9)
#define TWIS_INTEN_STOPPED_DISABLED                         (0x0U<<1)
#define TWIS_INTEN_STOPPED_ENABLED                          (0x1U<<1)

// INTENSET Configuration

#define TWIS_INTENSET_READ                                  (0x1U<<26)
#define TWIS_INTENSET_WRITE                                 (0x1U<<25)
#define TWIS_INTENSET_TXSTARTED                             (0x1U<<20)
#define TWIS_INTENSET_RXSTARTED                             (0x1U<<19)
#define TWIS_INTENSET_ERROR                                 (0x1U<<9)
#define TWIS_INTENSET_STOPPED                               (0x1U<<1)
#define TWIS_INTENSET_READ_DISABLED                         (0x0U<<26)
#define TWIS_INTENSET_READ_ENABLED                          (0x1U<<26)
#define TWIS_INTENSET_READ_SET                              (0x1U<<26)
#define TWIS_INTENSET_WRITE_DISABLED                        (0x0U<<25)
#define TWIS_INTENSET_WRITE_ENABLED                         (0x1U<<25)
#define TWIS_INTENSET_WRITE_SET                             (0x1U<<25)
#define TWIS_INTENSET_TXSTARTED_DISABLED                    (0x0U<<20)
#define TWIS_INTENSET_TXSTARTED_ENABLED                     (0x1U<<20)
#define TWIS_INTENSET_TXSTARTED_SET                         (0x1U<<20)
#define TWIS_INTENSET_RXSTARTED_DISABLED                    (0x0U<<19)
#define TWIS_INTENSET_RXSTARTED_ENABLED                     (0x1U<<19)
#define TWIS_INTENSET_RXSTARTED_SET                         (0x1U<<19)
#define TWIS_INTENSET_ERROR_DISABLED                        (0x0U<<9)
#define TWIS_INTENSET_ERROR_ENABLED                         (0x1U<<9)
#define TWIS_INTENSET_ERROR_SET                             (0x1U<<9)
#define TWIS_INTENSET_STOPPED_DISABLED                      (0x0U<<1)
#define TWIS_INTENSET_STOPPED_ENABLED                       (0x1U<<1)
#define TWIS_INTENSET_STOPPED_SET                           (0x1U<<1)

// INTENCLR Configuration

#define TWIS_INTENCLR_READ                                  (0x1U<<26)
#define TWIS_INTENCLR_WRITE                                 (0x1U<<25)
#define TWIS_INTENCLR_TXSTARTED                             (0x1U<<20)
#define TWIS_INTENCLR_RXSTARTED                             (0x1U<<19)
#define TWIS_INTENCLR_ERROR                                 (0x1U<<9)
#define TWIS_INTENCLR_STOPPED                               (0x1U<<1)
#define TWIS_INTENCLR_READ_DISABLED                         (0x0U<<26)
#define TWIS_INTENCLR_READ_ENABLED                          (0x1U<<26)
#define TWIS_INTENCLR_READ_CLEAR                            (0x1U<<26)
#define TWIS_INTENCLR_WRITE_DISABLED                        (0x0U<<25)
#define TWIS_INTENCLR_WRITE_ENABLED                         (0x1U<<25)
#define TWIS_INTENCLR_WRITE_CLEAR                           (0x1U<<25)
#define TWIS_INTENCLR_TXSTARTED_DISABLED                    (0x0U<<20)
#define TWIS_INTENCLR_TXSTARTED_ENABLED                     (0x1U<<20)
#define TWIS_INTENCLR_TXSTARTED_CLEAR                       (0x1U<<20)
#define TWIS_INTENCLR_RXSTARTED_DISABLED                    (0x0U<<19)
#define TWIS_INTENCLR_RXSTARTED_ENABLED                     (0x1U<<19)
#define TWIS_INTENCLR_RXSTARTED_CLEAR                       (0x1U<<19)
#define TWIS_INTENCLR_ERROR_DISABLED                        (0x0U<<9)
#define TWIS_INTENCLR_ERROR_ENABLED                         (0x1U<<9)
#define TWIS_INTENCLR_ERROR_CLEAR                           (0x1U<<9)
#define TWIS_INTENCLR_STOPPED_DISABLED                      (0x0U<<1)
#define TWIS_INTENCLR_STOPPED_ENABLED                       (0x1U<<1)
#define TWIS_INTENCLR_STOPPED_CLEAR                         (0x1U<<1)

// ERRORSRC Configuration

#define TWIS_ERRORSRC_OVERREAD                              (0x1U<<3)
#define TWIS_ERRORSRC_DNACK                                 (0x1U<<2)
#define TWIS_ERRORSRC_OVERFLOW                              (0x1U<<0)
#define TWIS_ERRORSRC_OVERREAD_NOTDETECTED                  (0x0U<<3)
#define TWIS_ERRORSRC_OVERREAD_DETECTED                     (0x1U<<3)
#define TWIS_ERRORSRC_DNACK_NOTRECEIVED                     (0x0U<<2)
#define TWIS_ERRORSRC_DNACK_RECEIVED                        (0x1U<<2)
#define TWIS_ERRORSRC_OVERFLOW_NOTDETECTED                  (0x0U<<0)
#define TWIS_ERRORSRC_OVERFLOW_DETECTED                     (0x1U<<0)

// MATCH Configuration

#define TWIS_MATCH_MATCH                                    (0x1U<<0)

// ENABLE Configuration

#define TWIS_ENABLE_ENABLE                                  (0xFU<<0)
#define TWIS_ENABLE_ENABLE_0                                (0x1U<<0)
#define TWIS_ENABLE_ENABLE_DISABLED                         (0x0U<<0)
#define TWIS_ENABLE_ENABLE_ENABLED                          (0x9U<<0)

// SCL Configuration

#define TWIS_PSEL_SCL_CONNECT                               (0x1U<<31)
#define TWIS_PSEL_SCL_PORT                                  (0x1U<<5)
#define TWIS_PSEL_SCL_PIN                                   (0x1FU<<0)
#define TWIS_PSEL_SCL_PIN_0                                 (0x1U<<0)
#define TWIS_PSEL_SCL_CONNECT_DISCONNECTED                  (0x1U<<31)
#define TWIS_PSEL_SCL_CONNECT_CONNECTED                     (0x0U<<31)

// SDA Configuration

#define TWIS_PSEL_SDA_CONNECT                               (0x1U<<31)
#define TWIS_PSEL_SDA_PORT                                  (0x1U<<5)
#define TWIS_PSEL_SDA_PIN                                   (0x1FU<<0)
#define TWIS_PSEL_SDA_PIN_0                                 (0x1U<<0)
#define TWIS_PSEL_SDA_CONNECT_DISCONNECTED                  (0x1U<<31)
#define TWIS_PSEL_SDA_CONNECT_CONNECTED                     (0x0U<<31)

// PTR Configuration

#define TWIS_RXD_PTR_PTR                                    (0xFFFFFFFFU<<0)
#define TWIS_RXD_PTR_PTR_0                                  (0x1U<<0)

// MAXCNT Configuration

#define TWIS_RXD_MAXCNT_MAXCNT                              (0xFFFFU<<0)
#define TWIS_RXD_MAXCNT_MAXCNT_0                            (0x1U<<0)

// AMOUNT Configuration

#define TWIS_RXD_AMOUNT_AMOUNT                              (0xFFFFU<<0)
#define TWIS_RXD_AMOUNT_AMOUNT_0                            (0x1U<<0)

// LIST Configuration

#define TWIS_RXD_LIST_LIST                                  (0x3U<<0)
#define TWIS_RXD_LIST_LIST_0                                (0x1U<<0)
#define TWIS_RXD_LIST_LIST_DISABLED                         (0x0U<<0)
#define TWIS_RXD_LIST_LIST_ARRAYLIST                        (0x1U<<0)

// PTR Configuration

#define TWIS_TXD_PTR_PTR                                    (0xFFFFFFFFU<<0)
#define TWIS_TXD_PTR_PTR_0                                  (0x1U<<0)

// MAXCNT Configuration

#define TWIS_TXD_MAXCNT_MAXCNT                              (0xFFFFU<<0)
#define TWIS_TXD_MAXCNT_MAXCNT_0                            (0x1U<<0)

// AMOUNT Configuration

#define TWIS_TXD_AMOUNT_AMOUNT                              (0xFFFFU<<0)
#define TWIS_TXD_AMOUNT_AMOUNT_0                            (0x1U<<0)

// LIST Configuration

#define TWIS_TXD_LIST_LIST                                  (0x3U<<0)
#define TWIS_TXD_LIST_LIST_0                                (0x1U<<0)
#define TWIS_TXD_LIST_LIST_DISABLED                         (0x0U<<0)
#define TWIS_TXD_LIST_LIST_ARRAYLIST                        (0x1U<<0)

// ADDRESS Configuration

#define TWIS_ADDRESS_ADDRESS                                (0x7FU<<0)
#define TWIS_ADDRESS_ADDRESS_0                              (0x1U<<0)

// CONFIG Configuration

#define TWIS_CONFIG_ADDRESS1                                (0x1U<<1)
#define TWIS_CONFIG_ADDRESS0                                (0x1U<<0)
#define TWIS_CONFIG_ADDRESS1_DISABLED                       (0x0U<<1)
#define TWIS_CONFIG_ADDRESS1_ENABLED                        (0x1U<<1)
#define TWIS_CONFIG_ADDRESS0_DISABLED                       (0x0U<<0)
#define TWIS_CONFIG_ADDRESS0_ENABLED                        (0x1U<<0)

// ORC Configuration

#define TWIS_ORC_ORC                                        (0xFFU<<0)
#define TWIS_ORC_ORC_0                                      (0x1U<<0)
