/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_saadc equates.
 */

#pragma once

#include    <stdint.h>

// SAADC address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    TASKS_START;
    volatile    uint32_t    TASKS_SAMPLE;
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    TASKS_CALIBRATEOFFSET;
    volatile    uint32_t    RESERVED0[28];
    volatile    uint32_t    SUBSCRIBE_START;
    volatile    uint32_t    SUBSCRIBE_SAMPLE;
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    SUBSCRIBE_CALIBRATEOFFSET;
    volatile    uint32_t    RESERVED1[28];
    volatile    uint32_t    EVENTS_STARTED;
    volatile    uint32_t    EVENTS_END;
    volatile    uint32_t    EVENTS_DONE;
    volatile    uint32_t    EVENTS_RESULTDONE;
    volatile    uint32_t    EVENTS_CALIBRATEDONE;
    volatile    uint32_t    EVENTS_STOPPED;
    volatile    uint32_t    EVENTS_CH0_LIMITH;
    volatile    uint32_t    EVENTS_CH0_LIMITL;
    volatile    uint32_t    EVENTS_CH1_LIMITH;
    volatile    uint32_t    EVENTS_CH1_LIMITL;
    volatile    uint32_t    EVENTS_CH2_LIMITH;
    volatile    uint32_t    EVENTS_CH2_LIMITL;
    volatile    uint32_t    EVENTS_CH3_LIMITH;
    volatile    uint32_t    EVENTS_CH3_LIMITL;
    volatile    uint32_t    EVENTS_CH4_LIMITH;
    volatile    uint32_t    EVENTS_CH4_LIMITL;
    volatile    uint32_t    EVENTS_CH5_LIMITH;
    volatile    uint32_t    EVENTS_CH5_LIMITL;
    volatile    uint32_t    EVENTS_CH6_LIMITH;
    volatile    uint32_t    EVENTS_CH6_LIMITL;
    volatile    uint32_t    EVENTS_CH7_LIMITH;
    volatile    uint32_t    EVENTS_CH7_LIMITL;
    volatile    uint32_t    RESERVED2[10];
    volatile    uint32_t    PUBLISH_STARTED;
    volatile    uint32_t    PUBLISH_END;
    volatile    uint32_t    PUBLISH_DONE;
    volatile    uint32_t    PUBLISH_RESULTDONE;
    volatile    uint32_t    PUBLISH_CALIBRATEDONE;
    volatile    uint32_t    PUBLISH_STOPPED;
    volatile    uint32_t    PUBLISH_CH0_LIMITH;
    volatile    uint32_t    PUBLISH_CH0_LIMITL;
    volatile    uint32_t    PUBLISH_CH1_LIMITH;
    volatile    uint32_t    PUBLISH_CH1_LIMITL;
    volatile    uint32_t    PUBLISH_CH2_LIMITH;
    volatile    uint32_t    PUBLISH_CH2_LIMITL;
    volatile    uint32_t    PUBLISH_CH3_LIMITH;
    volatile    uint32_t    PUBLISH_CH3_LIMITL;
    volatile    uint32_t    PUBLISH_CH4_LIMITH;
    volatile    uint32_t    PUBLISH_CH4_LIMITL;
    volatile    uint32_t    PUBLISH_CH5_LIMITH;
    volatile    uint32_t    PUBLISH_CH5_LIMITL;
    volatile    uint32_t    PUBLISH_CH6_LIMITH;
    volatile    uint32_t    PUBLISH_CH6_LIMITL;
    volatile    uint32_t    PUBLISH_CH7_LIMITH;
    volatile    uint32_t    PUBLISH_CH7_LIMITL;
    volatile    uint32_t    RESERVED3[74];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED4[61];
    volatile    uint32_t    STATUS;
    volatile    uint32_t    RESERVED5[63];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    RESERVED6[3];
    volatile    uint32_t    CH0_PSELP;
    volatile    uint32_t    CH0_PSELN;
    volatile    uint32_t    CH0_CONFIG;
    volatile    uint32_t    CH0_LIMIT;
    volatile    uint32_t    CH1_PSELP;
    volatile    uint32_t    CH1_PSELN;
    volatile    uint32_t    CH1_CONFIG;
    volatile    uint32_t    CH1_LIMIT;
    volatile    uint32_t    CH2_PSELP;
    volatile    uint32_t    CH2_PSELN;
    volatile    uint32_t    CH2_CONFIG;
    volatile    uint32_t    CH2_LIMIT;
    volatile    uint32_t    CH3_PSELP;
    volatile    uint32_t    CH3_PSELN;
    volatile    uint32_t    CH3_CONFIG;
    volatile    uint32_t    CH3_LIMIT;
    volatile    uint32_t    CH4_PSELP;
    volatile    uint32_t    CH4_PSELN;
    volatile    uint32_t    CH4_CONFIG;
    volatile    uint32_t    CH4_LIMIT;
    volatile    uint32_t    CH5_PSELP;
    volatile    uint32_t    CH5_PSELN;
    volatile    uint32_t    CH5_CONFIG;
    volatile    uint32_t    CH5_LIMIT;
    volatile    uint32_t    CH6_PSELP;
    volatile    uint32_t    CH6_PSELN;
    volatile    uint32_t    CH6_CONFIG;
    volatile    uint32_t    CH6_LIMIT;
    volatile    uint32_t    CH7_PSELP;
    volatile    uint32_t    CH7_PSELN;
    volatile    uint32_t    CH7_CONFIG;
    volatile    uint32_t    CH7_LIMIT;
    volatile    uint32_t    RESERVED7[24];
    volatile    uint32_t    RESOLUTION;
    volatile    uint32_t    OVERSAMPLE;
    volatile    uint32_t    SAMPLERATE;
    volatile    uint32_t    RESERVED8[12];
    volatile    uint32_t    RESULT_PTR;
    volatile    uint32_t    RESULT_MAXCNT;
    volatile    uint32_t    RESULT_AMOUNT;
} SAADC_TypeDef;

#ifdef __cplusplus
#define SAADC_NS    reinterpret_cast<SAADC_TypeDef *>(0x4000E000U)
#define SAADC_S     reinterpret_cast<SAADC_TypeDef *>(0x5000E000U)

#else
#define SAADC_NS    ((SAADC_TypeDef *)0x4000E000U)
#define SAADC_S     ((SAADC_TypeDef *)0x5000E000U)
#endif

// TASKS_START Configuration

#define SAADC_TASKS_START_TASKS_START                                   (0x1U<<0U)
#define SAADC_TASKS_START_TASKS_START_TRIGGER                           (0x1U<<0U)

// TASKS_SAMPLE Configuration

#define SAADC_TASKS_SAMPLE_TASKS_SAMPLE                                 (0x1U<<0U)
#define SAADC_TASKS_SAMPLE_TASKS_SAMPLE_TRIGGER                         (0x1U<<0U)

// TASKS_STOP Configuration

#define SAADC_TASKS_STOP_TASKS_STOP                                     (0x1U<<0U)
#define SAADC_TASKS_STOP_TASKS_STOP_TRIGGER                             (0x1U<<0U)

// TASKS_CALIBRATEOFFSET Configuration

#define SAADC_TASKS_CALIBRATEOFFSET_TASKS_CALIBRATEOFFSET               (0x1U<<0U)
#define SAADC_TASKS_CALIBRATEOFFSET_TASKS_CALIBRATEOFFSET_TRIGGER       (0x1U<<0U)

// SUBSCRIBE_START Configuration

#define SAADC_SUBSCRIBE_START_EN                                        (0x1U<<31U)
#define SAADC_SUBSCRIBE_START_CHIDX                                     (0xFFU<<0U)
#define SAADC_SUBSCRIBE_START_CHIDX_0                                   (0x1U<<0U)
#define SAADC_SUBSCRIBE_START_EN_DISABLED                               (0x0U<<31U)
#define SAADC_SUBSCRIBE_START_EN_ENABLED                                (0x1U<<31U)

// SUBSCRIBE_SAMPLE Configuration

#define SAADC_SUBSCRIBE_SAMPLE_EN                                       (0x1U<<31U)
#define SAADC_SUBSCRIBE_SAMPLE_CHIDX                                    (0xFFU<<0U)
#define SAADC_SUBSCRIBE_SAMPLE_CHIDX_0                                  (0x1U<<0U)
#define SAADC_SUBSCRIBE_SAMPLE_EN_DISABLED                              (0x0U<<31U)
#define SAADC_SUBSCRIBE_SAMPLE_EN_ENABLED                               (0x1U<<31U)

// SUBSCRIBE_STOP Configuration

#define SAADC_SUBSCRIBE_STOP_EN                                         (0x1U<<31U)
#define SAADC_SUBSCRIBE_STOP_CHIDX                                      (0xFFU<<0U)
#define SAADC_SUBSCRIBE_STOP_CHIDX_0                                    (0x1U<<0U)
#define SAADC_SUBSCRIBE_STOP_EN_DISABLED                                (0x0U<<31U)
#define SAADC_SUBSCRIBE_STOP_EN_ENABLED                                 (0x1U<<31U)

// SUBSCRIBE_CALIBRATEOFFSET Configuration

#define SAADC_SUBSCRIBE_CALIBRATEOFFSET_EN                              (0x1U<<31U)
#define SAADC_SUBSCRIBE_CALIBRATEOFFSET_CHIDX                           (0xFFU<<0U)
#define SAADC_SUBSCRIBE_CALIBRATEOFFSET_CHIDX_0                         (0x1U<<0U)
#define SAADC_SUBSCRIBE_CALIBRATEOFFSET_EN_DISABLED                     (0x0U<<31U)
#define SAADC_SUBSCRIBE_CALIBRATEOFFSET_EN_ENABLED                      (0x1U<<31U)

// EVENTS_STARTED Configuration

#define SAADC_EVENTS_STARTED_EVENTS_STARTED                             (0x1U<<0U)
#define SAADC_EVENTS_STARTED_EVENTS_STARTED_NOTGENERATED                (0x0U<<0U)
#define SAADC_EVENTS_STARTED_EVENTS_STARTED_GENERATED                   (0x1U<<0U)

// EVENTS_END Configuration

#define SAADC_EVENTS_END_EVENTS_END                                     (0x1U<<0U)
#define SAADC_EVENTS_END_EVENTS_END_NOTGENERATED                        (0x0U<<0U)
#define SAADC_EVENTS_END_EVENTS_END_GENERATED                           (0x1U<<0U)

// EVENTS_DONE Configuration

#define SAADC_EVENTS_DONE_EVENTS_DONE                                   (0x1U<<0U)
#define SAADC_EVENTS_DONE_EVENTS_DONE_NOTGENERATED                      (0x0U<<0U)
#define SAADC_EVENTS_DONE_EVENTS_DONE_GENERATED                         (0x1U<<0U)

// EVENTS_RESULTDONE Configuration

#define SAADC_EVENTS_RESULTDONE_EVENTS_RESULTDONE                       (0x1U<<0U)
#define SAADC_EVENTS_RESULTDONE_EVENTS_RESULTDONE_NOTGENERATED          (0x0U<<0U)
#define SAADC_EVENTS_RESULTDONE_EVENTS_RESULTDONE_GENERATED             (0x1U<<0U)

// EVENTS_CALIBRATEDONE Configuration

#define SAADC_EVENTS_CALIBRATEDONE_EVENTS_CALIBRATEDONE                 (0x1U<<0U)
#define SAADC_EVENTS_CALIBRATEDONE_EVENTS_CALIBRATEDONE_NOTGENERATED    (0x0U<<0U)
#define SAADC_EVENTS_CALIBRATEDONE_EVENTS_CALIBRATEDONE_GENERATED       (0x1U<<0U)

// EVENTS_STOPPED Configuration

#define SAADC_EVENTS_STOPPED_EVENTS_STOPPED                             (0x1U<<0U)
#define SAADC_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED                (0x0U<<0U)
#define SAADC_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED                   (0x1U<<0U)

// LIMITH Configuration

#define SAADC_EVENTS_CH_LIMITH_LIMITH                                   (0x1U<<0U)
#define SAADC_EVENTS_CH_LIMITH_LIMITH_NOTGENERATED                      (0x0U<<0U)
#define SAADC_EVENTS_CH_LIMITH_LIMITH_GENERATED                         (0x1U<<0U)

// LIMITL Configuration

#define SAADC_EVENTS_CH_LIMITL_LIMITL                                   (0x1U<<0U)
#define SAADC_EVENTS_CH_LIMITL_LIMITL_NOTGENERATED                      (0x0U<<0U)
#define SAADC_EVENTS_CH_LIMITL_LIMITL_GENERATED                         (0x1U<<0U)

// PUBLISH_STARTED Configuration

#define SAADC_PUBLISH_STARTED_EN                                        (0x1U<<31U)
#define SAADC_PUBLISH_STARTED_CHIDX                                     (0xFFU<<0U)
#define SAADC_PUBLISH_STARTED_CHIDX_0                                   (0x1U<<0U)
#define SAADC_PUBLISH_STARTED_EN_DISABLED                               (0x0U<<31U)
#define SAADC_PUBLISH_STARTED_EN_ENABLED                                (0x1U<<31U)

// PUBLISH_END Configuration

#define SAADC_PUBLISH_END_EN                                            (0x1U<<31U)
#define SAADC_PUBLISH_END_CHIDX                                         (0xFFU<<0U)
#define SAADC_PUBLISH_END_CHIDX_0                                       (0x1U<<0U)
#define SAADC_PUBLISH_END_EN_DISABLED                                   (0x0U<<31U)
#define SAADC_PUBLISH_END_EN_ENABLED                                    (0x1U<<31U)

// PUBLISH_DONE Configuration

#define SAADC_PUBLISH_DONE_EN                                           (0x1U<<31U)
#define SAADC_PUBLISH_DONE_CHIDX                                        (0xFFU<<0U)
#define SAADC_PUBLISH_DONE_CHIDX_0                                      (0x1U<<0U)
#define SAADC_PUBLISH_DONE_EN_DISABLED                                  (0x0U<<31U)
#define SAADC_PUBLISH_DONE_EN_ENABLED                                   (0x1U<<31U)

// PUBLISH_RESULTDONE Configuration

#define SAADC_PUBLISH_RESULTDONE_EN                                     (0x1U<<31U)
#define SAADC_PUBLISH_RESULTDONE_CHIDX                                  (0xFFU<<0U)
#define SAADC_PUBLISH_RESULTDONE_CHIDX_0                                (0x1U<<0U)
#define SAADC_PUBLISH_RESULTDONE_EN_DISABLED                            (0x0U<<31U)
#define SAADC_PUBLISH_RESULTDONE_EN_ENABLED                             (0x1U<<31U)

// PUBLISH_CALIBRATEDONE Configuration

#define SAADC_PUBLISH_CALIBRATEDONE_EN                                  (0x1U<<31U)
#define SAADC_PUBLISH_CALIBRATEDONE_CHIDX                               (0xFFU<<0U)
#define SAADC_PUBLISH_CALIBRATEDONE_CHIDX_0                             (0x1U<<0U)
#define SAADC_PUBLISH_CALIBRATEDONE_EN_DISABLED                         (0x0U<<31U)
#define SAADC_PUBLISH_CALIBRATEDONE_EN_ENABLED                          (0x1U<<31U)

// PUBLISH_STOPPED Configuration

#define SAADC_PUBLISH_STOPPED_EN                                        (0x1U<<31U)
#define SAADC_PUBLISH_STOPPED_CHIDX                                     (0xFFU<<0U)
#define SAADC_PUBLISH_STOPPED_CHIDX_0                                   (0x1U<<0U)
#define SAADC_PUBLISH_STOPPED_EN_DISABLED                               (0x0U<<31U)
#define SAADC_PUBLISH_STOPPED_EN_ENABLED                                (0x1U<<31U)

// LIMITH Configuration

#define SAADC_PUBLISH_CH_LIMITH_EN                                      (0x1U<<31U)
#define SAADC_PUBLISH_CH_LIMITH_CHIDX                                   (0xFFU<<0U)
#define SAADC_PUBLISH_CH_LIMITH_CHIDX_0                                 (0x1U<<0U)
#define SAADC_PUBLISH_CH_LIMITH_EN_DISABLED                             (0x0U<<31U)
#define SAADC_PUBLISH_CH_LIMITH_EN_ENABLED                              (0x1U<<31U)

// LIMITL Configuration

#define SAADC_PUBLISH_CH_LIMITL_EN                                      (0x1U<<31U)
#define SAADC_PUBLISH_CH_LIMITL_CHIDX                                   (0xFFU<<0U)
#define SAADC_PUBLISH_CH_LIMITL_CHIDX_0                                 (0x1U<<0U)
#define SAADC_PUBLISH_CH_LIMITL_EN_DISABLED                             (0x0U<<31U)
#define SAADC_PUBLISH_CH_LIMITL_EN_ENABLED                              (0x1U<<31U)

// INTEN Configuration

#define SAADC_INTEN_CH7LIMITL                                           (0x1U<<21U)
#define SAADC_INTEN_CH7LIMITH                                           (0x1U<<20U)
#define SAADC_INTEN_CH6LIMITL                                           (0x1U<<19U)
#define SAADC_INTEN_CH6LIMITH                                           (0x1U<<18U)
#define SAADC_INTEN_CH5LIMITL                                           (0x1U<<17U)
#define SAADC_INTEN_CH5LIMITH                                           (0x1U<<16U)
#define SAADC_INTEN_CH4LIMITL                                           (0x1U<<15U)
#define SAADC_INTEN_CH4LIMITH                                           (0x1U<<14U)
#define SAADC_INTEN_CH3LIMITL                                           (0x1U<<13U)
#define SAADC_INTEN_CH3LIMITH                                           (0x1U<<12U)
#define SAADC_INTEN_CH2LIMITL                                           (0x1U<<11U)
#define SAADC_INTEN_CH2LIMITH                                           (0x1U<<10U)
#define SAADC_INTEN_CH1LIMITL                                           (0x1U<<9U)
#define SAADC_INTEN_CH1LIMITH                                           (0x1U<<8U)
#define SAADC_INTEN_CH0LIMITL                                           (0x1U<<7U)
#define SAADC_INTEN_CH0LIMITH                                           (0x1U<<6U)
#define SAADC_INTEN_STOPPED                                             (0x1U<<5U)
#define SAADC_INTEN_CALIBRATEDONE                                       (0x1U<<4U)
#define SAADC_INTEN_RESULTDONE                                          (0x1U<<3U)
#define SAADC_INTEN_DONE                                                (0x1U<<2U)
#define SAADC_INTEN_END                                                 (0x1U<<1U)
#define SAADC_INTEN_STARTED                                             (0x1U<<0U)
#define SAADC_INTEN_CH7LIMITL_DISABLED                                  (0x0U<<21U)
#define SAADC_INTEN_CH7LIMITL_ENABLED                                   (0x1U<<21U)
#define SAADC_INTEN_CH7LIMITH_DISABLED                                  (0x0U<<20U)
#define SAADC_INTEN_CH7LIMITH_ENABLED                                   (0x1U<<20U)
#define SAADC_INTEN_CH6LIMITL_DISABLED                                  (0x0U<<19U)
#define SAADC_INTEN_CH6LIMITL_ENABLED                                   (0x1U<<19U)
#define SAADC_INTEN_CH6LIMITH_DISABLED                                  (0x0U<<18U)
#define SAADC_INTEN_CH6LIMITH_ENABLED                                   (0x1U<<18U)
#define SAADC_INTEN_CH5LIMITL_DISABLED                                  (0x0U<<17U)
#define SAADC_INTEN_CH5LIMITL_ENABLED                                   (0x1U<<17U)
#define SAADC_INTEN_CH5LIMITH_DISABLED                                  (0x0U<<16U)
#define SAADC_INTEN_CH5LIMITH_ENABLED                                   (0x1U<<16U)
#define SAADC_INTEN_CH4LIMITL_DISABLED                                  (0x0U<<15U)
#define SAADC_INTEN_CH4LIMITL_ENABLED                                   (0x1U<<15U)
#define SAADC_INTEN_CH4LIMITH_DISABLED                                  (0x0U<<14U)
#define SAADC_INTEN_CH4LIMITH_ENABLED                                   (0x1U<<14U)
#define SAADC_INTEN_CH3LIMITL_DISABLED                                  (0x0U<<13U)
#define SAADC_INTEN_CH3LIMITL_ENABLED                                   (0x1U<<13U)
#define SAADC_INTEN_CH3LIMITH_DISABLED                                  (0x0U<<12U)
#define SAADC_INTEN_CH3LIMITH_ENABLED                                   (0x1U<<12U)
#define SAADC_INTEN_CH2LIMITL_DISABLED                                  (0x0U<<11U)
#define SAADC_INTEN_CH2LIMITL_ENABLED                                   (0x1U<<11U)
#define SAADC_INTEN_CH2LIMITH_DISABLED                                  (0x0U<<10U)
#define SAADC_INTEN_CH2LIMITH_ENABLED                                   (0x1U<<10U)
#define SAADC_INTEN_CH1LIMITL_DISABLED                                  (0x0U<<9U)
#define SAADC_INTEN_CH1LIMITL_ENABLED                                   (0x1U<<9U)
#define SAADC_INTEN_CH1LIMITH_DISABLED                                  (0x0U<<8U)
#define SAADC_INTEN_CH1LIMITH_ENABLED                                   (0x1U<<8U)
#define SAADC_INTEN_CH0LIMITL_DISABLED                                  (0x0U<<7U)
#define SAADC_INTEN_CH0LIMITL_ENABLED                                   (0x1U<<7U)
#define SAADC_INTEN_CH0LIMITH_DISABLED                                  (0x0U<<6U)
#define SAADC_INTEN_CH0LIMITH_ENABLED                                   (0x1U<<6U)
#define SAADC_INTEN_STOPPED_DISABLED                                    (0x0U<<5U)
#define SAADC_INTEN_STOPPED_ENABLED                                     (0x1U<<5U)
#define SAADC_INTEN_CALIBRATEDONE_DISABLED                              (0x0U<<4U)
#define SAADC_INTEN_CALIBRATEDONE_ENABLED                               (0x1U<<4U)
#define SAADC_INTEN_RESULTDONE_DISABLED                                 (0x0U<<3U)
#define SAADC_INTEN_RESULTDONE_ENABLED                                  (0x1U<<3U)
#define SAADC_INTEN_DONE_DISABLED                                       (0x0U<<2U)
#define SAADC_INTEN_DONE_ENABLED                                        (0x1U<<2U)
#define SAADC_INTEN_END_DISABLED                                        (0x0U<<1U)
#define SAADC_INTEN_END_ENABLED                                         (0x1U<<1U)
#define SAADC_INTEN_STARTED_DISABLED                                    (0x0U<<0U)
#define SAADC_INTEN_STARTED_ENABLED                                     (0x1U<<0U)

// INTENSET Configuration

#define SAADC_INTENSET_CH7LIMITL                                        (0x1U<<21U)
#define SAADC_INTENSET_CH7LIMITH                                        (0x1U<<20U)
#define SAADC_INTENSET_CH6LIMITL                                        (0x1U<<19U)
#define SAADC_INTENSET_CH6LIMITH                                        (0x1U<<18U)
#define SAADC_INTENSET_CH5LIMITL                                        (0x1U<<17U)
#define SAADC_INTENSET_CH5LIMITH                                        (0x1U<<16U)
#define SAADC_INTENSET_CH4LIMITL                                        (0x1U<<15U)
#define SAADC_INTENSET_CH4LIMITH                                        (0x1U<<14U)
#define SAADC_INTENSET_CH3LIMITL                                        (0x1U<<13U)
#define SAADC_INTENSET_CH3LIMITH                                        (0x1U<<12U)
#define SAADC_INTENSET_CH2LIMITL                                        (0x1U<<11U)
#define SAADC_INTENSET_CH2LIMITH                                        (0x1U<<10U)
#define SAADC_INTENSET_CH1LIMITL                                        (0x1U<<9U)
#define SAADC_INTENSET_CH1LIMITH                                        (0x1U<<8U)
#define SAADC_INTENSET_CH0LIMITL                                        (0x1U<<7U)
#define SAADC_INTENSET_CH0LIMITH                                        (0x1U<<6U)
#define SAADC_INTENSET_STOPPED                                          (0x1U<<5U)
#define SAADC_INTENSET_CALIBRATEDONE                                    (0x1U<<4U)
#define SAADC_INTENSET_RESULTDONE                                       (0x1U<<3U)
#define SAADC_INTENSET_DONE                                             (0x1U<<2U)
#define SAADC_INTENSET_END                                              (0x1U<<1U)
#define SAADC_INTENSET_STARTED                                          (0x1U<<0U)
#define SAADC_INTENSET_CH7LIMITL_DISABLED                               (0x0U<<21U)
#define SAADC_INTENSET_CH7LIMITL_ENABLED                                (0x1U<<21U)
#define SAADC_INTENSET_CH7LIMITL_SET                                    (0x1U<<21U)
#define SAADC_INTENSET_CH7LIMITH_DISABLED                               (0x0U<<20U)
#define SAADC_INTENSET_CH7LIMITH_ENABLED                                (0x1U<<20U)
#define SAADC_INTENSET_CH7LIMITH_SET                                    (0x1U<<20U)
#define SAADC_INTENSET_CH6LIMITL_DISABLED                               (0x0U<<19U)
#define SAADC_INTENSET_CH6LIMITL_ENABLED                                (0x1U<<19U)
#define SAADC_INTENSET_CH6LIMITL_SET                                    (0x1U<<19U)
#define SAADC_INTENSET_CH6LIMITH_DISABLED                               (0x0U<<18U)
#define SAADC_INTENSET_CH6LIMITH_ENABLED                                (0x1U<<18U)
#define SAADC_INTENSET_CH6LIMITH_SET                                    (0x1U<<18U)
#define SAADC_INTENSET_CH5LIMITL_DISABLED                               (0x0U<<17U)
#define SAADC_INTENSET_CH5LIMITL_ENABLED                                (0x1U<<17U)
#define SAADC_INTENSET_CH5LIMITL_SET                                    (0x1U<<17U)
#define SAADC_INTENSET_CH5LIMITH_DISABLED                               (0x0U<<16U)
#define SAADC_INTENSET_CH5LIMITH_ENABLED                                (0x1U<<16U)
#define SAADC_INTENSET_CH5LIMITH_SET                                    (0x1U<<16U)
#define SAADC_INTENSET_CH4LIMITL_DISABLED                               (0x0U<<15U)
#define SAADC_INTENSET_CH4LIMITL_ENABLED                                (0x1U<<15U)
#define SAADC_INTENSET_CH4LIMITL_SET                                    (0x1U<<15U)
#define SAADC_INTENSET_CH4LIMITH_DISABLED                               (0x0U<<14U)
#define SAADC_INTENSET_CH4LIMITH_ENABLED                                (0x1U<<14U)
#define SAADC_INTENSET_CH4LIMITH_SET                                    (0x1U<<14U)
#define SAADC_INTENSET_CH3LIMITL_DISABLED                               (0x0U<<13U)
#define SAADC_INTENSET_CH3LIMITL_ENABLED                                (0x1U<<13U)
#define SAADC_INTENSET_CH3LIMITL_SET                                    (0x1U<<13U)
#define SAADC_INTENSET_CH3LIMITH_DISABLED                               (0x0U<<12U)
#define SAADC_INTENSET_CH3LIMITH_ENABLED                                (0x1U<<12U)
#define SAADC_INTENSET_CH3LIMITH_SET                                    (0x1U<<12U)
#define SAADC_INTENSET_CH2LIMITL_DISABLED                               (0x0U<<11U)
#define SAADC_INTENSET_CH2LIMITL_ENABLED                                (0x1U<<11U)
#define SAADC_INTENSET_CH2LIMITL_SET                                    (0x1U<<11U)
#define SAADC_INTENSET_CH2LIMITH_DISABLED                               (0x0U<<10U)
#define SAADC_INTENSET_CH2LIMITH_ENABLED                                (0x1U<<10U)
#define SAADC_INTENSET_CH2LIMITH_SET                                    (0x1U<<10U)
#define SAADC_INTENSET_CH1LIMITL_DISABLED                               (0x0U<<9U)
#define SAADC_INTENSET_CH1LIMITL_ENABLED                                (0x1U<<9U)
#define SAADC_INTENSET_CH1LIMITL_SET                                    (0x1U<<9U)
#define SAADC_INTENSET_CH1LIMITH_DISABLED                               (0x0U<<8U)
#define SAADC_INTENSET_CH1LIMITH_ENABLED                                (0x1U<<8U)
#define SAADC_INTENSET_CH1LIMITH_SET                                    (0x1U<<8U)
#define SAADC_INTENSET_CH0LIMITL_DISABLED                               (0x0U<<7U)
#define SAADC_INTENSET_CH0LIMITL_ENABLED                                (0x1U<<7U)
#define SAADC_INTENSET_CH0LIMITL_SET                                    (0x1U<<7U)
#define SAADC_INTENSET_CH0LIMITH_DISABLED                               (0x0U<<6U)
#define SAADC_INTENSET_CH0LIMITH_ENABLED                                (0x1U<<6U)
#define SAADC_INTENSET_CH0LIMITH_SET                                    (0x1U<<6U)
#define SAADC_INTENSET_STOPPED_DISABLED                                 (0x0U<<5U)
#define SAADC_INTENSET_STOPPED_ENABLED                                  (0x1U<<5U)
#define SAADC_INTENSET_STOPPED_SET                                      (0x1U<<5U)
#define SAADC_INTENSET_CALIBRATEDONE_DISABLED                           (0x0U<<4U)
#define SAADC_INTENSET_CALIBRATEDONE_ENABLED                            (0x1U<<4U)
#define SAADC_INTENSET_CALIBRATEDONE_SET                                (0x1U<<4U)
#define SAADC_INTENSET_RESULTDONE_DISABLED                              (0x0U<<3U)
#define SAADC_INTENSET_RESULTDONE_ENABLED                               (0x1U<<3U)
#define SAADC_INTENSET_RESULTDONE_SET                                   (0x1U<<3U)
#define SAADC_INTENSET_DONE_DISABLED                                    (0x0U<<2U)
#define SAADC_INTENSET_DONE_ENABLED                                     (0x1U<<2U)
#define SAADC_INTENSET_DONE_SET                                         (0x1U<<2U)
#define SAADC_INTENSET_END_DISABLED                                     (0x0U<<1U)
#define SAADC_INTENSET_END_ENABLED                                      (0x1U<<1U)
#define SAADC_INTENSET_END_SET                                          (0x1U<<1U)
#define SAADC_INTENSET_STARTED_DISABLED                                 (0x0U<<0U)
#define SAADC_INTENSET_STARTED_ENABLED                                  (0x1U<<0U)
#define SAADC_INTENSET_STARTED_SET                                      (0x1U<<0U)

// INTENCLR Configuration

#define SAADC_INTENCLR_CH7LIMITL                                        (0x1U<<21U)
#define SAADC_INTENCLR_CH7LIMITH                                        (0x1U<<20U)
#define SAADC_INTENCLR_CH6LIMITL                                        (0x1U<<19U)
#define SAADC_INTENCLR_CH6LIMITH                                        (0x1U<<18U)
#define SAADC_INTENCLR_CH5LIMITL                                        (0x1U<<17U)
#define SAADC_INTENCLR_CH5LIMITH                                        (0x1U<<16U)
#define SAADC_INTENCLR_CH4LIMITL                                        (0x1U<<15U)
#define SAADC_INTENCLR_CH4LIMITH                                        (0x1U<<14U)
#define SAADC_INTENCLR_CH3LIMITL                                        (0x1U<<13U)
#define SAADC_INTENCLR_CH3LIMITH                                        (0x1U<<12U)
#define SAADC_INTENCLR_CH2LIMITL                                        (0x1U<<11U)
#define SAADC_INTENCLR_CH2LIMITH                                        (0x1U<<10U)
#define SAADC_INTENCLR_CH1LIMITL                                        (0x1U<<9U)
#define SAADC_INTENCLR_CH1LIMITH                                        (0x1U<<8U)
#define SAADC_INTENCLR_CH0LIMITL                                        (0x1U<<7U)
#define SAADC_INTENCLR_CH0LIMITH                                        (0x1U<<6U)
#define SAADC_INTENCLR_STOPPED                                          (0x1U<<5U)
#define SAADC_INTENCLR_CALIBRATEDONE                                    (0x1U<<4U)
#define SAADC_INTENCLR_RESULTDONE                                       (0x1U<<3U)
#define SAADC_INTENCLR_DONE                                             (0x1U<<2U)
#define SAADC_INTENCLR_END                                              (0x1U<<1U)
#define SAADC_INTENCLR_STARTED                                          (0x1U<<0U)
#define SAADC_INTENCLR_CH7LIMITL_DISABLED                               (0x0U<<21U)
#define SAADC_INTENCLR_CH7LIMITL_ENABLED                                (0x1U<<21U)
#define SAADC_INTENCLR_CH7LIMITL_CLEAR                                  (0x1U<<21U)
#define SAADC_INTENCLR_CH7LIMITH_DISABLED                               (0x0U<<20U)
#define SAADC_INTENCLR_CH7LIMITH_ENABLED                                (0x1U<<20U)
#define SAADC_INTENCLR_CH7LIMITH_CLEAR                                  (0x1U<<20U)
#define SAADC_INTENCLR_CH6LIMITL_DISABLED                               (0x0U<<19U)
#define SAADC_INTENCLR_CH6LIMITL_ENABLED                                (0x1U<<19U)
#define SAADC_INTENCLR_CH6LIMITL_CLEAR                                  (0x1U<<19U)
#define SAADC_INTENCLR_CH6LIMITH_DISABLED                               (0x0U<<18U)
#define SAADC_INTENCLR_CH6LIMITH_ENABLED                                (0x1U<<18U)
#define SAADC_INTENCLR_CH6LIMITH_CLEAR                                  (0x1U<<18U)
#define SAADC_INTENCLR_CH5LIMITL_DISABLED                               (0x0U<<17U)
#define SAADC_INTENCLR_CH5LIMITL_ENABLED                                (0x1U<<17U)
#define SAADC_INTENCLR_CH5LIMITL_CLEAR                                  (0x1U<<17U)
#define SAADC_INTENCLR_CH5LIMITH_DISABLED                               (0x0U<<16U)
#define SAADC_INTENCLR_CH5LIMITH_ENABLED                                (0x1U<<16U)
#define SAADC_INTENCLR_CH5LIMITH_CLEAR                                  (0x1U<<16U)
#define SAADC_INTENCLR_CH4LIMITL_DISABLED                               (0x0U<<15U)
#define SAADC_INTENCLR_CH4LIMITL_ENABLED                                (0x1U<<15U)
#define SAADC_INTENCLR_CH4LIMITL_CLEAR                                  (0x1U<<15U)
#define SAADC_INTENCLR_CH4LIMITH_DISABLED                               (0x0U<<14U)
#define SAADC_INTENCLR_CH4LIMITH_ENABLED                                (0x1U<<14U)
#define SAADC_INTENCLR_CH4LIMITH_CLEAR                                  (0x1U<<14U)
#define SAADC_INTENCLR_CH3LIMITL_DISABLED                               (0x0U<<13U)
#define SAADC_INTENCLR_CH3LIMITL_ENABLED                                (0x1U<<13U)
#define SAADC_INTENCLR_CH3LIMITL_CLEAR                                  (0x1U<<13U)
#define SAADC_INTENCLR_CH3LIMITH_DISABLED                               (0x0U<<12U)
#define SAADC_INTENCLR_CH3LIMITH_ENABLED                                (0x1U<<12U)
#define SAADC_INTENCLR_CH3LIMITH_CLEAR                                  (0x1U<<12U)
#define SAADC_INTENCLR_CH2LIMITL_DISABLED                               (0x0U<<11U)
#define SAADC_INTENCLR_CH2LIMITL_ENABLED                                (0x1U<<11U)
#define SAADC_INTENCLR_CH2LIMITL_CLEAR                                  (0x1U<<11U)
#define SAADC_INTENCLR_CH2LIMITH_DISABLED                               (0x0U<<10U)
#define SAADC_INTENCLR_CH2LIMITH_ENABLED                                (0x1U<<10U)
#define SAADC_INTENCLR_CH2LIMITH_CLEAR                                  (0x1U<<10U)
#define SAADC_INTENCLR_CH1LIMITL_DISABLED                               (0x0U<<9U)
#define SAADC_INTENCLR_CH1LIMITL_ENABLED                                (0x1U<<9U)
#define SAADC_INTENCLR_CH1LIMITL_CLEAR                                  (0x1U<<9U)
#define SAADC_INTENCLR_CH1LIMITH_DISABLED                               (0x0U<<8U)
#define SAADC_INTENCLR_CH1LIMITH_ENABLED                                (0x1U<<8U)
#define SAADC_INTENCLR_CH1LIMITH_CLEAR                                  (0x1U<<8U)
#define SAADC_INTENCLR_CH0LIMITL_DISABLED                               (0x0U<<7U)
#define SAADC_INTENCLR_CH0LIMITL_ENABLED                                (0x1U<<7U)
#define SAADC_INTENCLR_CH0LIMITL_CLEAR                                  (0x1U<<7U)
#define SAADC_INTENCLR_CH0LIMITH_DISABLED                               (0x0U<<6U)
#define SAADC_INTENCLR_CH0LIMITH_ENABLED                                (0x1U<<6U)
#define SAADC_INTENCLR_CH0LIMITH_CLEAR                                  (0x1U<<6U)
#define SAADC_INTENCLR_STOPPED_DISABLED                                 (0x0U<<5U)
#define SAADC_INTENCLR_STOPPED_ENABLED                                  (0x1U<<5U)
#define SAADC_INTENCLR_STOPPED_CLEAR                                    (0x1U<<5U)
#define SAADC_INTENCLR_CALIBRATEDONE_DISABLED                           (0x0U<<4U)
#define SAADC_INTENCLR_CALIBRATEDONE_ENABLED                            (0x1U<<4U)
#define SAADC_INTENCLR_CALIBRATEDONE_CLEAR                              (0x1U<<4U)
#define SAADC_INTENCLR_RESULTDONE_DISABLED                              (0x0U<<3U)
#define SAADC_INTENCLR_RESULTDONE_ENABLED                               (0x1U<<3U)
#define SAADC_INTENCLR_RESULTDONE_CLEAR                                 (0x1U<<3U)
#define SAADC_INTENCLR_DONE_DISABLED                                    (0x0U<<2U)
#define SAADC_INTENCLR_DONE_ENABLED                                     (0x1U<<2U)
#define SAADC_INTENCLR_DONE_CLEAR                                       (0x1U<<2U)
#define SAADC_INTENCLR_END_DISABLED                                     (0x0U<<1U)
#define SAADC_INTENCLR_END_ENABLED                                      (0x1U<<1U)
#define SAADC_INTENCLR_END_CLEAR                                        (0x1U<<1U)
#define SAADC_INTENCLR_STARTED_DISABLED                                 (0x0U<<0U)
#define SAADC_INTENCLR_STARTED_ENABLED                                  (0x1U<<0U)
#define SAADC_INTENCLR_STARTED_CLEAR                                    (0x1U<<0U)

// STATUS Configuration

#define SAADC_STATUS_STATUS                                             (0x1U<<0U)
#define SAADC_STATUS_STATUS_READY                                       (0x0U<<0U)
#define SAADC_STATUS_STATUS_BUSY                                        (0x1U<<0U)

// ENABLE Configuration

#define SAADC_ENABLE_ENABLE                                             (0x1U<<0U)
#define SAADC_ENABLE_ENABLE_DISABLED                                    (0x0U<<0U)
#define SAADC_ENABLE_ENABLE_ENABLED                                     (0x1U<<0U)

// PSELP Configuration

#define SAADC_CH_PSELP_PSELP                                            (0x1FU<<0U)
#define SAADC_CH_PSELP_PSELP_0                                          (0x1U<<0U)
#define SAADC_CH_PSELP_PSELP_NC                                         (0x0U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT0                               (0x1U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT1                               (0x2U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT2                               (0x3U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT3                               (0x4U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT4                               (0x5U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT5                               (0x6U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT6                               (0x7U<<0U)
#define SAADC_CH_PSELP_PSELP_ANALOGINPUT7                               (0x8U<<0U)
#define SAADC_CH_PSELP_PSELP_VDD                                        (0x9U<<0U)
#define SAADC_CH_PSELP_PSELP_VDDHDIV5                                   (0xDU<<0U)

// PSELN Configuration

#define SAADC_CH_PSELN_PSELN                                            (0x1FU<<0U)
#define SAADC_CH_PSELN_PSELN_0                                          (0x1U<<0U)
#define SAADC_CH_PSELN_PSELN_NC                                         (0x0U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT0                               (0x1U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT1                               (0x2U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT2                               (0x3U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT3                               (0x4U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT4                               (0x5U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT5                               (0x6U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT6                               (0x7U<<0U)
#define SAADC_CH_PSELN_PSELN_ANALOGINPUT7                               (0x8U<<0U)
#define SAADC_CH_PSELN_PSELN_VDD                                        (0x9U<<0U)
#define SAADC_CH_PSELN_PSELN_VDDHDIV5                                   (0xDU<<0U)

// CONFIG Configuration

#define SAADC_CH_CONFIG_BURST                                           (0x1U<<24U)
#define SAADC_CH_CONFIG_MODE                                            (0x1U<<20U)
#define SAADC_CH_CONFIG_TACQ                                            (0x7U<<16U)
#define SAADC_CH_CONFIG_TACQ_0                                          (0x1U<<16U)
#define SAADC_CH_CONFIG_REFSEL                                          (0x1U<<12U)
#define SAADC_CH_CONFIG_GAIN                                            (0x7U<<8U)
#define SAADC_CH_CONFIG_GAIN_0                                          (0x1U<<8U)
#define SAADC_CH_CONFIG_RESN                                            (0x3U<<4U)
#define SAADC_CH_CONFIG_RESN_0                                          (0x1U<<4U)
#define SAADC_CH_CONFIG_RESP                                            (0x3U<<0U)
#define SAADC_CH_CONFIG_RESP_0                                          (0x1U<<0U)
#define SAADC_CH_CONFIG_BURST_DISABLED                                  (0x0U<<24U)
#define SAADC_CH_CONFIG_BURST_ENABLED                                   (0x1U<<24U)
#define SAADC_CH_CONFIG_MODE_SE                                         (0x0U<<20U)
#define SAADC_CH_CONFIG_MODE_DIFF                                       (0x1U<<20U)
#define SAADC_CH_CONFIG_TACQ_3US                                        (0x0U<<16U)
#define SAADC_CH_CONFIG_TACQ_5US                                        (0x1U<<16U)
#define SAADC_CH_CONFIG_TACQ_10US                                       (0x2U<<16U)
#define SAADC_CH_CONFIG_TACQ_15US                                       (0x3U<<16U)
#define SAADC_CH_CONFIG_TACQ_20US                                       (0x4U<<16U)
#define SAADC_CH_CONFIG_TACQ_40US                                       (0x5U<<16U)
#define SAADC_CH_CONFIG_REFSEL_INTERNAL                                 (0x0U<<12U)
#define SAADC_CH_CONFIG_REFSEL_VDD1_4                                   (0x1U<<12U)
#define SAADC_CH_CONFIG_GAIN_GAIN1_6                                    (0x0U<<8U)
#define SAADC_CH_CONFIG_GAIN_GAIN1_5                                    (0x1U<<8U)
#define SAADC_CH_CONFIG_GAIN_GAIN1_4                                    (0x2U<<8U)
#define SAADC_CH_CONFIG_GAIN_GAIN1_3                                    (0x3U<<8U)
#define SAADC_CH_CONFIG_GAIN_GAIN1_2                                    (0x4U<<8U)
#define SAADC_CH_CONFIG_GAIN_GAIN1                                      (0x5U<<8U)
#define SAADC_CH_CONFIG_GAIN_GAIN2                                      (0x6U<<8U)
#define SAADC_CH_CONFIG_GAIN_GAIN4                                      (0x7U<<8U)
#define SAADC_CH_CONFIG_RESN_BYPASS                                     (0x0U<<4U)
#define SAADC_CH_CONFIG_RESN_PULLDOWN                                   (0x1U<<4U)
#define SAADC_CH_CONFIG_RESN_PULLUP                                     (0x2U<<4U)
#define SAADC_CH_CONFIG_RESN_VDD1_2                                     (0x3U<<4U)
#define SAADC_CH_CONFIG_RESP_BYPASS                                     (0x0U<<0U)
#define SAADC_CH_CONFIG_RESP_PULLDOWN                                   (0x1U<<0U)
#define SAADC_CH_CONFIG_RESP_PULLUP                                     (0x2U<<0U)
#define SAADC_CH_CONFIG_RESP_VDD1_2                                     (0x3U<<0U)

// LIMIT Configuration

#define SAADC_CH_LIMIT_HIGH                                             (0xFFFFU<<16U)
#define SAADC_CH_LIMIT_HIGH_0                                           (0x1U<<16U)
#define SAADC_CH_LIMIT_LOW                                              (0xFFFFU<<0U)
#define SAADC_CH_LIMIT_LOW_0                                            (0x1U<<0U)

// RESOLUTION Configuration

#define SAADC_RESOLUTION_VAL                                            (0x7U<<0U)
#define SAADC_RESOLUTION_VAL_0                                          (0x1U<<0U)
#define SAADC_RESOLUTION_VAL_8BIT                                       (0x0U<<0U)
#define SAADC_RESOLUTION_VAL_10BIT                                      (0x1U<<0U)
#define SAADC_RESOLUTION_VAL_12BIT                                      (0x2U<<0U)
#define SAADC_RESOLUTION_VAL_14BIT                                      (0x3U<<0U)

// OVERSAMPLE Configuration

#define SAADC_OVERSAMPLE_OVERSAMPLE                                     (0xFU<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_0                                   (0x1U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_BYPASS                              (0x0U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER2X                              (0x1U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER4X                              (0x2U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER8X                              (0x3U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER16X                             (0x4U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER32X                             (0x5U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER64X                             (0x6U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER128X                            (0x7U<<0U)
#define SAADC_OVERSAMPLE_OVERSAMPLE_OVER256X                            (0x8U<<0U)

// SAMPLERATE Configuration

#define SAADC_SAMPLERATE_MODE                                           (0x1U<<12U)
#define SAADC_SAMPLERATE_CC                                             (0x7FFU<<0U)
#define SAADC_SAMPLERATE_CC_0                                           (0x1U<<0U)
#define SAADC_SAMPLERATE_MODE_TASK                                      (0x0U<<12U)
#define SAADC_SAMPLERATE_MODE_TIMERS                                    (0x1U<<12U)

// PTR Configuration

#define SAADC_RESULT_PTR_PTR                                            (0xFFFFFFFFU<<0U)
#define SAADC_RESULT_PTR_PTR_0                                          (0x1U<<0U)

// MAXCNT Configuration

#define SAADC_RESULT_MAXCNT_MAXCNT                                      (0x7FFFU<<0U)
#define SAADC_RESULT_MAXCNT_MAXCNT_0                                    (0x1U<<0U)

// AMOUNT Configuration

#define SAADC_RESULT_AMOUNT_AMOUNT                                      (0x7FFFU<<0U)
#define SAADC_RESULT_AMOUNT_AMOUNT_0                                    (0x1U<<0U)
