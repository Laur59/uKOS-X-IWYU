/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_i2s equates.
 */

#pragma once

#include    <stdint.h>

// I2S address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TASKS_START;
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    RESERVED0[30];
    volatile    uint32_t    SUBSCRIBE_START;
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    RESERVED1[31];
    volatile    uint32_t    EVENTS_RXPTRUPD;
    volatile    uint32_t    EVENTS_STOPPED;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    EVENTS_TXPTRUPD;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    EVENTS_FRAMESTART;
    volatile    uint32_t    RESERVED4[25];
    volatile    uint32_t    PUBLISH_RXPTRUPD;
    volatile    uint32_t    PUBLISH_STOPPED;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    PUBLISH_TXPTRUPD;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    PUBLISH_FRAMESTART;
    volatile    uint32_t    RESERVED7[88];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED8[125];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    CONFIG_MODE;
    volatile    uint32_t    CONFIG_RXEN;
    volatile    uint32_t    CONFIG_TXEN;
    volatile    uint32_t    CONFIG_MCKEN;
    volatile    uint32_t    CONFIG_MCKFREQ;
    volatile    uint32_t    CONFIG_RATIO;
    volatile    uint32_t    CONFIG_SWIDTH;
    volatile    uint32_t    CONFIG_ALIGN;
    volatile    uint32_t    CONFIG_FORMAT;
    volatile    uint32_t    CONFIG_CHANNELS;
    volatile    uint32_t    CONFIG_CLKCONFIG;
    volatile    uint32_t    RESERVED9[2];
    volatile    uint32_t    RXD_PTR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    TXD_PTR;
    volatile    uint32_t    RESERVED11[3];
    volatile    uint32_t    RXTXD_MAXCNT;
    volatile    uint32_t    RESERVED12[3];
    volatile    uint32_t    PSEL_MCK;
    volatile    uint32_t    PSEL_SCK;
    volatile    uint32_t    PSEL_LRCK;
    volatile    uint32_t    PSEL_SDIN;
    volatile    uint32_t    PSEL_SDOUT;
} I2S_TypeDef;

#ifdef __cplusplus
#define I2S0_NS reinterpret_cast<I2S_TypeDef *>(0x40028000U)
#define I2S0_S  reinterpret_cast<I2S_TypeDef *>(0x50028000U)

#else
#define I2S0_NS ((I2S_TypeDef *)0x40028000U)
#define I2S0_S  ((I2S_TypeDef *)0x50028000U)
#endif

// TASKS_START Configuration

#define I2S_TASKS_START_TASKS_START                                 (0x1U<<0U)
#define I2S_TASKS_START_TASKS_START_TRIGGER                         (0x1U<<0U)

// TASKS_STOP Configuration

#define I2S_TASKS_STOP_TASKS_STOP                                   (0x1U<<0U)
#define I2S_TASKS_STOP_TASKS_STOP_TRIGGER                           (0x1U<<0U)

// SUBSCRIBE_START Configuration

#define I2S_SUBSCRIBE_START_EN                                      (0x1U<<31U)
#define I2S_SUBSCRIBE_START_CHIDX                                   (0xFFU<<0U)
#define I2S_SUBSCRIBE_START_CHIDX_0                                 (0x1U<<0U)
#define I2S_SUBSCRIBE_START_EN_DISABLED                             (0x0U<<31U)
#define I2S_SUBSCRIBE_START_EN_ENABLED                              (0x1U<<31U)

// SUBSCRIBE_STOP Configuration

#define I2S_SUBSCRIBE_STOP_EN                                       (0x1U<<31U)
#define I2S_SUBSCRIBE_STOP_CHIDX                                    (0xFFU<<0U)
#define I2S_SUBSCRIBE_STOP_CHIDX_0                                  (0x1U<<0U)
#define I2S_SUBSCRIBE_STOP_EN_DISABLED                              (0x0U<<31U)
#define I2S_SUBSCRIBE_STOP_EN_ENABLED                               (0x1U<<31U)

// EVENTS_RXPTRUPD Configuration

#define I2S_EVENTS_RXPTRUPD_EVENTS_RXPTRUPD                         (0x1U<<0U)
#define I2S_EVENTS_RXPTRUPD_EVENTS_RXPTRUPD_NOTGENERATED            (0x0U<<0U)
#define I2S_EVENTS_RXPTRUPD_EVENTS_RXPTRUPD_GENERATED               (0x1U<<0U)

// EVENTS_STOPPED Configuration

#define I2S_EVENTS_STOPPED_EVENTS_STOPPED                           (0x1U<<0U)
#define I2S_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED              (0x0U<<0U)
#define I2S_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED                 (0x1U<<0U)

// EVENTS_TXPTRUPD Configuration

#define I2S_EVENTS_TXPTRUPD_EVENTS_TXPTRUPD                         (0x1U<<0U)
#define I2S_EVENTS_TXPTRUPD_EVENTS_TXPTRUPD_NOTGENERATED            (0x0U<<0U)
#define I2S_EVENTS_TXPTRUPD_EVENTS_TXPTRUPD_GENERATED               (0x1U<<0U)

// EVENTS_FRAMESTART Configuration

#define I2S_EVENTS_FRAMESTART_EVENTS_FRAMESTART                     (0x1U<<0U)
#define I2S_EVENTS_FRAMESTART_EVENTS_FRAMESTART_NOTGENERATED        (0x0U<<0U)
#define I2S_EVENTS_FRAMESTART_EVENTS_FRAMESTART_GENERATED           (0x1U<<0U)

// PUBLISH_RXPTRUPD Configuration

#define I2S_PUBLISH_RXPTRUPD_EN                                     (0x1U<<31U)
#define I2S_PUBLISH_RXPTRUPD_CHIDX                                  (0xFFU<<0U)
#define I2S_PUBLISH_RXPTRUPD_CHIDX_0                                (0x1U<<0U)
#define I2S_PUBLISH_RXPTRUPD_EN_DISABLED                            (0x0U<<31U)
#define I2S_PUBLISH_RXPTRUPD_EN_ENABLED                             (0x1U<<31U)

// PUBLISH_STOPPED Configuration

#define I2S_PUBLISH_STOPPED_EN                                      (0x1U<<31U)
#define I2S_PUBLISH_STOPPED_CHIDX                                   (0xFFU<<0U)
#define I2S_PUBLISH_STOPPED_CHIDX_0                                 (0x1U<<0U)
#define I2S_PUBLISH_STOPPED_EN_DISABLED                             (0x0U<<31U)
#define I2S_PUBLISH_STOPPED_EN_ENABLED                              (0x1U<<31U)

// PUBLISH_TXPTRUPD Configuration

#define I2S_PUBLISH_TXPTRUPD_EN                                     (0x1U<<31U)
#define I2S_PUBLISH_TXPTRUPD_CHIDX                                  (0xFFU<<0U)
#define I2S_PUBLISH_TXPTRUPD_CHIDX_0                                (0x1U<<0U)
#define I2S_PUBLISH_TXPTRUPD_EN_DISABLED                            (0x0U<<31U)
#define I2S_PUBLISH_TXPTRUPD_EN_ENABLED                             (0x1U<<31U)

// PUBLISH_FRAMESTART Configuration

#define I2S_PUBLISH_FRAMESTART_EN                                   (0x1U<<31U)
#define I2S_PUBLISH_FRAMESTART_CHIDX                                (0xFFU<<0U)
#define I2S_PUBLISH_FRAMESTART_CHIDX_0                              (0x1U<<0U)
#define I2S_PUBLISH_FRAMESTART_EN_DISABLED                          (0x0U<<31U)
#define I2S_PUBLISH_FRAMESTART_EN_ENABLED                           (0x1U<<31U)

// INTEN Configuration

#define I2S_INTEN_FRAMESTART                                        (0x1U<<7U)
#define I2S_INTEN_TXPTRUPD                                          (0x1U<<5U)
#define I2S_INTEN_STOPPED                                           (0x1U<<2U)
#define I2S_INTEN_RXPTRUPD                                          (0x1U<<1U)
#define I2S_INTEN_FRAMESTART_DISABLED                               (0x0U<<7U)
#define I2S_INTEN_FRAMESTART_ENABLED                                (0x1U<<7U)
#define I2S_INTEN_TXPTRUPD_DISABLED                                 (0x0U<<5U)
#define I2S_INTEN_TXPTRUPD_ENABLED                                  (0x1U<<5U)
#define I2S_INTEN_STOPPED_DISABLED                                  (0x0U<<2U)
#define I2S_INTEN_STOPPED_ENABLED                                   (0x1U<<2U)
#define I2S_INTEN_RXPTRUPD_DISABLED                                 (0x0U<<1U)
#define I2S_INTEN_RXPTRUPD_ENABLED                                  (0x1U<<1U)

// INTENSET Configuration

#define I2S_INTENSET_FRAMESTART                                     (0x1U<<7U)
#define I2S_INTENSET_TXPTRUPD                                       (0x1U<<5U)
#define I2S_INTENSET_STOPPED                                        (0x1U<<2U)
#define I2S_INTENSET_RXPTRUPD                                       (0x1U<<1U)
#define I2S_INTENSET_FRAMESTART_DISABLED                            (0x0U<<7U)
#define I2S_INTENSET_FRAMESTART_ENABLED                             (0x1U<<7U)
#define I2S_INTENSET_FRAMESTART_SET                                 (0x1U<<7U)
#define I2S_INTENSET_TXPTRUPD_DISABLED                              (0x0U<<5U)
#define I2S_INTENSET_TXPTRUPD_ENABLED                               (0x1U<<5U)
#define I2S_INTENSET_TXPTRUPD_SET                                   (0x1U<<5U)
#define I2S_INTENSET_STOPPED_DISABLED                               (0x0U<<2U)
#define I2S_INTENSET_STOPPED_ENABLED                                (0x1U<<2U)
#define I2S_INTENSET_STOPPED_SET                                    (0x1U<<2U)
#define I2S_INTENSET_RXPTRUPD_DISABLED                              (0x0U<<1U)
#define I2S_INTENSET_RXPTRUPD_ENABLED                               (0x1U<<1U)
#define I2S_INTENSET_RXPTRUPD_SET                                   (0x1U<<1U)

// INTENCLR Configuration

#define I2S_INTENCLR_FRAMESTART                                     (0x1U<<7U)
#define I2S_INTENCLR_TXPTRUPD                                       (0x1U<<5U)
#define I2S_INTENCLR_STOPPED                                        (0x1U<<2U)
#define I2S_INTENCLR_RXPTRUPD                                       (0x1U<<1U)
#define I2S_INTENCLR_FRAMESTART_DISABLED                            (0x0U<<7U)
#define I2S_INTENCLR_FRAMESTART_ENABLED                             (0x1U<<7U)
#define I2S_INTENCLR_FRAMESTART_CLEAR                               (0x1U<<7U)
#define I2S_INTENCLR_TXPTRUPD_DISABLED                              (0x0U<<5U)
#define I2S_INTENCLR_TXPTRUPD_ENABLED                               (0x1U<<5U)
#define I2S_INTENCLR_TXPTRUPD_CLEAR                                 (0x1U<<5U)
#define I2S_INTENCLR_STOPPED_DISABLED                               (0x0U<<2U)
#define I2S_INTENCLR_STOPPED_ENABLED                                (0x1U<<2U)
#define I2S_INTENCLR_STOPPED_CLEAR                                  (0x1U<<2U)
#define I2S_INTENCLR_RXPTRUPD_DISABLED                              (0x0U<<1U)
#define I2S_INTENCLR_RXPTRUPD_ENABLED                               (0x1U<<1U)
#define I2S_INTENCLR_RXPTRUPD_CLEAR                                 (0x1U<<1U)

// ENABLE Configuration

#define I2S_ENABLE_ENABLE                                           (0x1U<<0U)
#define I2S_ENABLE_ENABLE_DISABLED                                  (0x0U<<0U)
#define I2S_ENABLE_ENABLE_ENABLED                                   (0x1U<<0U)

// MODE Configuration

#define I2S_CONFIG_MODE_MODE                                        (0x1U<<0U)
#define I2S_CONFIG_MODE_MODE_MASTER                                 (0x0U<<0U)
#define I2S_CONFIG_MODE_MODE_SLAVE                                  (0x1U<<0U)

// RXEN Configuration

#define I2S_CONFIG_RXEN_RXEN                                        (0x1U<<0U)
#define I2S_CONFIG_RXEN_RXEN_DISABLED                               (0x0U<<0U)
#define I2S_CONFIG_RXEN_RXEN_ENABLED                                (0x1U<<0U)

// TXEN Configuration

#define I2S_CONFIG_TXEN_TXEN                                        (0x1U<<0U)
#define I2S_CONFIG_TXEN_TXEN_DISABLED                               (0x0U<<0U)
#define I2S_CONFIG_TXEN_TXEN_ENABLED                                (0x1U<<0U)

// MCKEN Configuration

#define I2S_CONFIG_MCKEN_MCKEN                                      (0x1U<<0U)
#define I2S_CONFIG_MCKEN_MCKEN_DISABLED                             (0x0U<<0U)
#define I2S_CONFIG_MCKEN_MCKEN_ENABLED                              (0x1U<<0U)

// MCKFREQ Configuration

#define I2S_CONFIG_MCKFREQ_MCKFREQ                                  (0xFFFFFFFFU<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_0                                (0x1U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV2                          (0x80000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV3                          (0x50000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV4                          (0x40000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV5                          (0x30000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV6                          (0x28000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV8                          (0x20000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV10                         (0x18000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV11                         (0x16000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV15                         (0x11000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV16                         (0x10000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV21                         (0xC000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV23                         (0xB000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV30                         (0x8800000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV31                         (0x8400000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV32                         (0x8000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV42                         (0x6000000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV63                         (0x4100000U<<0U)
#define I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV125                        (0x20C0000U<<0U)

// RATIO Configuration

#define I2S_CONFIG_RATIO_RATIO                                      (0xFU<<0U)
#define I2S_CONFIG_RATIO_RATIO_0                                    (0x1U<<0U)
#define I2S_CONFIG_RATIO_RATIO_32X                                  (0x0U<<0U)
#define I2S_CONFIG_RATIO_RATIO_48X                                  (0x1U<<0U)
#define I2S_CONFIG_RATIO_RATIO_64X                                  (0x2U<<0U)
#define I2S_CONFIG_RATIO_RATIO_96X                                  (0x3U<<0U)
#define I2S_CONFIG_RATIO_RATIO_128X                                 (0x4U<<0U)
#define I2S_CONFIG_RATIO_RATIO_192X                                 (0x5U<<0U)
#define I2S_CONFIG_RATIO_RATIO_256X                                 (0x6U<<0U)
#define I2S_CONFIG_RATIO_RATIO_384X                                 (0x7U<<0U)
#define I2S_CONFIG_RATIO_RATIO_512X                                 (0x8U<<0U)

// SWIDTH Configuration

#define I2S_CONFIG_SWIDTH_SWIDTH                                    (0x7U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_0                                  (0x1U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_8BIT                               (0x0U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_16BIT                              (0x1U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_24BIT                              (0x2U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_32BIT                              (0x3U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_8BITIN16                           (0x4U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_8BITIN32                           (0x5U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_16BITIN32                          (0x6U<<0U)
#define I2S_CONFIG_SWIDTH_SWIDTH_24BITIN32                          (0x7U<<0U)

// ALIGN Configuration

#define I2S_CONFIG_ALIGN_ALIGN                                      (0x1U<<0U)
#define I2S_CONFIG_ALIGN_ALIGN_LEFT                                 (0x0U<<0U)
#define I2S_CONFIG_ALIGN_ALIGN_RIGHT                                (0x1U<<0U)

// FORMAT Configuration

#define I2S_CONFIG_FORMAT_FORMAT                                    (0x1U<<0U)
#define I2S_CONFIG_FORMAT_FORMAT_I2S                                (0x0U<<0U)
#define I2S_CONFIG_FORMAT_FORMAT_ALIGNED                            (0x1U<<0U)

// CHANNELS Configuration

#define I2S_CONFIG_CHANNELS_CHANNELS                                (0x3U<<0U)
#define I2S_CONFIG_CHANNELS_CHANNELS_0                              (0x1U<<0U)
#define I2S_CONFIG_CHANNELS_CHANNELS_STEREO                         (0x0U<<0U)
#define I2S_CONFIG_CHANNELS_CHANNELS_LEFT                           (0x1U<<0U)
#define I2S_CONFIG_CHANNELS_CHANNELS_RIGHT                          (0x2U<<0U)

// CLKCONFIG Configuration

#define I2S_CONFIG_CLKCONFIG_BYPASS                                 (0x1U<<8U)
#define I2S_CONFIG_CLKCONFIG_CLKSRC                                 (0x1U<<0U)
#define I2S_CONFIG_CLKCONFIG_BYPASS_DISABLE                         (0x0U<<8U)
#define I2S_CONFIG_CLKCONFIG_BYPASS_ENABLE                          (0x1U<<8U)
#define I2S_CONFIG_CLKCONFIG_CLKSRC_PCLK32M                         (0x0U<<0U)
#define I2S_CONFIG_CLKCONFIG_CLKSRC_ACLK                            (0x1U<<0U)

// PTR Configuration

#define I2S_RXD_PTR_PTR                                             (0xFFFFFFFFU<<0U)
#define I2S_RXD_PTR_PTR_0                                           (0x1U<<0U)

// PTR Configuration

#define I2S_TXD_PTR_PTR                                             (0xFFFFFFFFU<<0U)
#define I2S_TXD_PTR_PTR_0                                           (0x1U<<0U)

// MAXCNT Configuration

#define I2S_RXTXD_MAXCNT_MAXCNT                                     (0x3FFFU<<0U)
#define I2S_RXTXD_MAXCNT_MAXCNT_0                                   (0x1U<<0U)

// MCK Configuration

#define I2S_PSEL_MCK_CONNECT                                        (0x1U<<31U)
#define I2S_PSEL_MCK_PORT                                           (0x1U<<5U)
#define I2S_PSEL_MCK_PIN                                            (0x1FU<<0U)
#define I2S_PSEL_MCK_PIN_0                                          (0x1U<<0U)
#define I2S_PSEL_MCK_CONNECT_DISCONNECTED                           (0x1U<<31U)
#define I2S_PSEL_MCK_CONNECT_CONNECTED                              (0x0U<<31U)

// SCK Configuration

#define I2S_PSEL_SCK_CONNECT                                        (0x1U<<31U)
#define I2S_PSEL_SCK_PORT                                           (0x1U<<5U)
#define I2S_PSEL_SCK_PIN                                            (0x1FU<<0U)
#define I2S_PSEL_SCK_PIN_0                                          (0x1U<<0U)
#define I2S_PSEL_SCK_CONNECT_DISCONNECTED                           (0x1U<<31U)
#define I2S_PSEL_SCK_CONNECT_CONNECTED                              (0x0U<<31U)

// LRCK Configuration

#define I2S_PSEL_LRCK_CONNECT                                       (0x1U<<31U)
#define I2S_PSEL_LRCK_PORT                                          (0x1U<<5U)
#define I2S_PSEL_LRCK_PIN                                           (0x1FU<<0U)
#define I2S_PSEL_LRCK_PIN_0                                         (0x1U<<0U)
#define I2S_PSEL_LRCK_CONNECT_DISCONNECTED                          (0x1U<<31U)
#define I2S_PSEL_LRCK_CONNECT_CONNECTED                             (0x0U<<31U)

// SDIN Configuration

#define I2S_PSEL_SDIN_CONNECT                                       (0x1U<<31U)
#define I2S_PSEL_SDIN_PORT                                          (0x1U<<5U)
#define I2S_PSEL_SDIN_PIN                                           (0x1FU<<0U)
#define I2S_PSEL_SDIN_PIN_0                                         (0x1U<<0U)
#define I2S_PSEL_SDIN_CONNECT_DISCONNECTED                          (0x1U<<31U)
#define I2S_PSEL_SDIN_CONNECT_CONNECTED                             (0x0U<<31U)

// SDOUT Configuration

#define I2S_PSEL_SDOUT_CONNECT                                      (0x1U<<31U)
#define I2S_PSEL_SDOUT_PORT                                         (0x1U<<5U)
#define I2S_PSEL_SDOUT_PIN                                          (0x1FU<<0U)
#define I2S_PSEL_SDOUT_PIN_0                                        (0x1U<<0U)
#define I2S_PSEL_SDOUT_CONNECT_DISCONNECTED                         (0x1U<<31U)
#define I2S_PSEL_SDOUT_CONNECT_CONNECTED                            (0x0U<<31U)
