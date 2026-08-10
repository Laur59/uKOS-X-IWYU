/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_comp equates.
 */

#pragma once

#include    <stdint.h>

// COMP address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    TASKS_START;
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    TASKS_SAMPLE;
    volatile    uint32_t    RESERVED0[29];
    volatile    uint32_t    SUBSCRIBE_START;
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    SUBSCRIBE_SAMPLE;
    volatile    uint32_t    RESERVED1[29];
    volatile    uint32_t    EVENTS_READY;
    volatile    uint32_t    EVENTS_DOWN;
    volatile    uint32_t    EVENTS_UP;
    volatile    uint32_t    EVENTS_CROSS;
    volatile    uint32_t    RESERVED2[28];
    volatile    uint32_t    PUBLISH_READY;
    volatile    uint32_t    PUBLISH_DOWN;
    volatile    uint32_t    PUBLISH_UP;
    volatile    uint32_t    PUBLISH_CROSS;
    volatile    uint32_t    RESERVED3[28];
    volatile    uint32_t    SHORTS;
    volatile    uint32_t    RESERVED4[63];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED5[61];
    volatile    uint32_t    RESULT;
    volatile    uint32_t    RESERVED6[63];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    PSEL;
    volatile    uint32_t    REFSEL;
    volatile    uint32_t    EXTREFSEL;
    volatile    uint32_t    RESERVED7[8];
    volatile    uint32_t    TH;
    volatile    uint32_t    MODE;
    volatile    uint32_t    HYST;
    volatile    uint32_t    ISOURCE;
} COMP_TypeDef;

#ifdef __cplusplus
#define COMP_NS reinterpret_cast<COMP_TypeDef *>(0x4001A000U)
#define COMP_S  reinterpret_cast<COMP_TypeDef *>(0x5001A000U)

#else
#define COMP_NS ((COMP_TypeDef *)0x4001A000U)
#define COMP_S  ((COMP_TypeDef *)0x5001A000U)
#endif

// TASKS_START Configuration

#define COMP_TASKS_START_TASKS_START                (0x1U<<0U)
#define COMP_TASKS_START_TASKS_START_TRIGGER        (0x1U<<0U)

// TASKS_STOP Configuration

#define COMP_TASKS_STOP_TASKS_STOP                  (0x1U<<0U)
#define COMP_TASKS_STOP_TASKS_STOP_TRIGGER          (0x1U<<0U)

// TASKS_SAMPLE Configuration

#define COMP_TASKS_SAMPLE_TASKS_SAMPLE              (0x1U<<0U)
#define COMP_TASKS_SAMPLE_TASKS_SAMPLE_TRIGGER      (0x1U<<0U)

// SUBSCRIBE_START Configuration

#define COMP_SUBSCRIBE_START_EN                     (0x1U<<31U)
#define COMP_SUBSCRIBE_START_CHIDX                  (0xFFU<<0U)
#define COMP_SUBSCRIBE_START_CHIDX_0                (0x1U<<0U)
#define COMP_SUBSCRIBE_START_EN_DISABLED            (0x0U<<31U)
#define COMP_SUBSCRIBE_START_EN_ENABLED             (0x1U<<31U)

// SUBSCRIBE_STOP Configuration

#define COMP_SUBSCRIBE_STOP_EN                      (0x1U<<31U)
#define COMP_SUBSCRIBE_STOP_CHIDX                   (0xFFU<<0U)
#define COMP_SUBSCRIBE_STOP_CHIDX_0                 (0x1U<<0U)
#define COMP_SUBSCRIBE_STOP_EN_DISABLED             (0x0U<<31U)
#define COMP_SUBSCRIBE_STOP_EN_ENABLED              (0x1U<<31U)

// SUBSCRIBE_SAMPLE Configuration

#define COMP_SUBSCRIBE_SAMPLE_EN                    (0x1U<<31U)
#define COMP_SUBSCRIBE_SAMPLE_CHIDX                 (0xFFU<<0U)
#define COMP_SUBSCRIBE_SAMPLE_CHIDX_0               (0x1U<<0U)
#define COMP_SUBSCRIBE_SAMPLE_EN_DISABLED           (0x0U<<31U)
#define COMP_SUBSCRIBE_SAMPLE_EN_ENABLED            (0x1U<<31U)

// EVENTS_READY Configuration

#define COMP_EVENTS_READY_EVENTS_READY              (0x1U<<0U)
#define COMP_EVENTS_READY_EVENTS_READY_NOTGENERATED (0x0U<<0U)
#define COMP_EVENTS_READY_EVENTS_READY_GENERATED    (0x1U<<0U)

// EVENTS_DOWN Configuration

#define COMP_EVENTS_DOWN_EVENTS_DOWN                (0x1U<<0U)
#define COMP_EVENTS_DOWN_EVENTS_DOWN_NOTGENERATED   (0x0U<<0U)
#define COMP_EVENTS_DOWN_EVENTS_DOWN_GENERATED      (0x1U<<0U)

// EVENTS_UP Configuration

#define COMP_EVENTS_UP_EVENTS_UP                    (0x1U<<0U)
#define COMP_EVENTS_UP_EVENTS_UP_NOTGENERATED       (0x0U<<0U)
#define COMP_EVENTS_UP_EVENTS_UP_GENERATED          (0x1U<<0U)

// EVENTS_CROSS Configuration

#define COMP_EVENTS_CROSS_EVENTS_CROSS              (0x1U<<0U)
#define COMP_EVENTS_CROSS_EVENTS_CROSS_NOTGENERATED (0x0U<<0U)
#define COMP_EVENTS_CROSS_EVENTS_CROSS_GENERATED    (0x1U<<0U)

// PUBLISH_READY Configuration

#define COMP_PUBLISH_READY_EN                       (0x1U<<31U)
#define COMP_PUBLISH_READY_CHIDX                    (0xFFU<<0U)
#define COMP_PUBLISH_READY_CHIDX_0                  (0x1U<<0U)
#define COMP_PUBLISH_READY_EN_DISABLED              (0x0U<<31U)
#define COMP_PUBLISH_READY_EN_ENABLED               (0x1U<<31U)

// PUBLISH_DOWN Configuration

#define COMP_PUBLISH_DOWN_EN                        (0x1U<<31U)
#define COMP_PUBLISH_DOWN_CHIDX                     (0xFFU<<0U)
#define COMP_PUBLISH_DOWN_CHIDX_0                   (0x1U<<0U)
#define COMP_PUBLISH_DOWN_EN_DISABLED               (0x0U<<31U)
#define COMP_PUBLISH_DOWN_EN_ENABLED                (0x1U<<31U)

// PUBLISH_UP Configuration

#define COMP_PUBLISH_UP_EN                          (0x1U<<31U)
#define COMP_PUBLISH_UP_CHIDX                       (0xFFU<<0U)
#define COMP_PUBLISH_UP_CHIDX_0                     (0x1U<<0U)
#define COMP_PUBLISH_UP_EN_DISABLED                 (0x0U<<31U)
#define COMP_PUBLISH_UP_EN_ENABLED                  (0x1U<<31U)

// PUBLISH_CROSS Configuration

#define COMP_PUBLISH_CROSS_EN                       (0x1U<<31U)
#define COMP_PUBLISH_CROSS_CHIDX                    (0xFFU<<0U)
#define COMP_PUBLISH_CROSS_CHIDX_0                  (0x1U<<0U)
#define COMP_PUBLISH_CROSS_EN_DISABLED              (0x0U<<31U)
#define COMP_PUBLISH_CROSS_EN_ENABLED               (0x1U<<31U)

// SHORTS Configuration

#define COMP_SHORTS_CROSS_STOP                      (0x1U<<4U)
#define COMP_SHORTS_UP_STOP                         (0x1U<<3U)
#define COMP_SHORTS_DOWN_STOP                       (0x1U<<2U)
#define COMP_SHORTS_READY_STOP                      (0x1U<<1U)
#define COMP_SHORTS_READY_SAMPLE                    (0x1U<<0U)
#define COMP_SHORTS_CROSS_STOP_DISABLED             (0x0U<<4U)
#define COMP_SHORTS_CROSS_STOP_ENABLED              (0x1U<<4U)
#define COMP_SHORTS_UP_STOP_DISABLED                (0x0U<<3U)
#define COMP_SHORTS_UP_STOP_ENABLED                 (0x1U<<3U)
#define COMP_SHORTS_DOWN_STOP_DISABLED              (0x0U<<2U)
#define COMP_SHORTS_DOWN_STOP_ENABLED               (0x1U<<2U)
#define COMP_SHORTS_READY_STOP_DISABLED             (0x0U<<1U)
#define COMP_SHORTS_READY_STOP_ENABLED              (0x1U<<1U)
#define COMP_SHORTS_READY_SAMPLE_DISABLED           (0x0U<<0U)
#define COMP_SHORTS_READY_SAMPLE_ENABLED            (0x1U<<0U)

// INTEN Configuration

#define COMP_INTEN_CROSS                            (0x1U<<3U)
#define COMP_INTEN_UP                               (0x1U<<2U)
#define COMP_INTEN_DOWN                             (0x1U<<1U)
#define COMP_INTEN_READY                            (0x1U<<0U)
#define COMP_INTEN_CROSS_DISABLED                   (0x0U<<3U)
#define COMP_INTEN_CROSS_ENABLED                    (0x1U<<3U)
#define COMP_INTEN_UP_DISABLED                      (0x0U<<2U)
#define COMP_INTEN_UP_ENABLED                       (0x1U<<2U)
#define COMP_INTEN_DOWN_DISABLED                    (0x0U<<1U)
#define COMP_INTEN_DOWN_ENABLED                     (0x1U<<1U)
#define COMP_INTEN_READY_DISABLED                   (0x0U<<0U)
#define COMP_INTEN_READY_ENABLED                    (0x1U<<0U)

// INTENSET Configuration

#define COMP_INTENSET_CROSS                         (0x1U<<3U)
#define COMP_INTENSET_UP                            (0x1U<<2U)
#define COMP_INTENSET_DOWN                          (0x1U<<1U)
#define COMP_INTENSET_READY                         (0x1U<<0U)
#define COMP_INTENSET_CROSS_DISABLED                (0x0U<<3U)
#define COMP_INTENSET_CROSS_ENABLED                 (0x1U<<3U)
#define COMP_INTENSET_CROSS_SET                     (0x1U<<3U)
#define COMP_INTENSET_UP_DISABLED                   (0x0U<<2U)
#define COMP_INTENSET_UP_ENABLED                    (0x1U<<2U)
#define COMP_INTENSET_UP_SET                        (0x1U<<2U)
#define COMP_INTENSET_DOWN_DISABLED                 (0x0U<<1U)
#define COMP_INTENSET_DOWN_ENABLED                  (0x1U<<1U)
#define COMP_INTENSET_DOWN_SET                      (0x1U<<1U)
#define COMP_INTENSET_READY_DISABLED                (0x0U<<0U)
#define COMP_INTENSET_READY_ENABLED                 (0x1U<<0U)
#define COMP_INTENSET_READY_SET                     (0x1U<<0U)

// INTENCLR Configuration

#define COMP_INTENCLR_CROSS                         (0x1U<<3U)
#define COMP_INTENCLR_UP                            (0x1U<<2U)
#define COMP_INTENCLR_DOWN                          (0x1U<<1U)
#define COMP_INTENCLR_READY                         (0x1U<<0U)
#define COMP_INTENCLR_CROSS_DISABLED                (0x0U<<3U)
#define COMP_INTENCLR_CROSS_ENABLED                 (0x1U<<3U)
#define COMP_INTENCLR_CROSS_CLEAR                   (0x1U<<3U)
#define COMP_INTENCLR_UP_DISABLED                   (0x0U<<2U)
#define COMP_INTENCLR_UP_ENABLED                    (0x1U<<2U)
#define COMP_INTENCLR_UP_CLEAR                      (0x1U<<2U)
#define COMP_INTENCLR_DOWN_DISABLED                 (0x0U<<1U)
#define COMP_INTENCLR_DOWN_ENABLED                  (0x1U<<1U)
#define COMP_INTENCLR_DOWN_CLEAR                    (0x1U<<1U)
#define COMP_INTENCLR_READY_DISABLED                (0x0U<<0U)
#define COMP_INTENCLR_READY_ENABLED                 (0x1U<<0U)
#define COMP_INTENCLR_READY_CLEAR                   (0x1U<<0U)

// RESULT Configuration

#define COMP_RESULT_RESULT                          (0x1U<<0U)
#define COMP_RESULT_RESULT_BELOW                    (0x0U<<0U)
#define COMP_RESULT_RESULT_ABOVE                    (0x1U<<0U)

// ENABLE Configuration

#define COMP_ENABLE_ENABLE                          (0x3U<<0U)
#define COMP_ENABLE_ENABLE_0                        (0x1U<<0U)
#define COMP_ENABLE_ENABLE_DISABLED                 (0x0U<<0U)
#define COMP_ENABLE_ENABLE_ENABLED                  (0x2U<<0U)

// PSEL Configuration

#define COMP_PSEL_PSEL                              (0x7U<<0U)
#define COMP_PSEL_PSEL_0                            (0x1U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT0                 (0x0U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT1                 (0x1U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT2                 (0x2U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT3                 (0x3U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT4                 (0x4U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT5                 (0x5U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT6                 (0x6U<<0U)
#define COMP_PSEL_PSEL_ANALOGINPUT7                 (0x7U<<0U)

// REFSEL Configuration

#define COMP_REFSEL_REFSEL                          (0x7U<<0U)
#define COMP_REFSEL_REFSEL_0                        (0x1U<<0U)
#define COMP_REFSEL_REFSEL_INT1V2                   (0x0U<<0U)
#define COMP_REFSEL_REFSEL_INT1V8                   (0x1U<<0U)
#define COMP_REFSEL_REFSEL_INT2V4                   (0x2U<<0U)
#define COMP_REFSEL_REFSEL_VDD                      (0x4U<<0U)
#define COMP_REFSEL_REFSEL_AREF                     (0x5U<<0U)

// EXTREFSEL Configuration

#define COMP_EXTREFSEL_EXTREFSEL                    (0x7U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_0                  (0x1U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE0   (0x0U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE1   (0x1U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE2   (0x2U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE3   (0x3U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE4   (0x4U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE5   (0x5U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE6   (0x6U<<0U)
#define COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE7   (0x7U<<0U)

// TH Configuration

#define COMP_TH_THUP                                (0x3FU<<8U)
#define COMP_TH_THUP_0                              (0x1U<<8U)
#define COMP_TH_THDOWN                              (0x3FU<<0U)
#define COMP_TH_THDOWN_0                            (0x1U<<0U)

// MODE Configuration

#define COMP_MODE_MAIN                              (0x1U<<8U)
#define COMP_MODE_SP                                (0x3U<<0U)
#define COMP_MODE_SP_0                              (0x1U<<0U)
#define COMP_MODE_MAIN_SE                           (0x0U<<8U)
#define COMP_MODE_MAIN_DIFF                         (0x1U<<8U)
#define COMP_MODE_SP_LOW                            (0x0U<<0U)
#define COMP_MODE_SP_NORMAL                         (0x1U<<0U)
#define COMP_MODE_SP_HIGH                           (0x2U<<0U)

// HYST Configuration

#define COMP_HYST_HYST                              (0x1U<<0U)
#define COMP_HYST_HYST_NOHYST                       (0x0U<<0U)
#define COMP_HYST_HYST_HYST50MV                     (0x1U<<0U)

// ISOURCE Configuration

#define COMP_ISOURCE_ISOURCE                        (0x3U<<0U)
#define COMP_ISOURCE_ISOURCE_0                      (0x1U<<0U)
#define COMP_ISOURCE_ISOURCE_OFF                    (0x0U<<0U)
#define COMP_ISOURCE_ISOURCE_IEN2MA5                (0x1U<<0U)
#define COMP_ISOURCE_ISOURCE_IEN5MA                 (0x2U<<0U)
#define COMP_ISOURCE_ISOURCE_IEN10MA                (0x3U<<0U)
