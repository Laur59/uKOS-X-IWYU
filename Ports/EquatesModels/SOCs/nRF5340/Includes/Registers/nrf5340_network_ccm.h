/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_ccm equates.
 */

#pragma once

#include    <stdint.h>

// CCM address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TASKS_KSGEN;
    volatile    uint32_t    TASKS_CRYPT;
    volatile    uint32_t    TASKS_STOP;
    volatile    uint32_t    TASKS_RATEOVERRIDE;
    volatile    uint32_t    RESERVED0[28];
    volatile    uint32_t    SUBSCRIBE_KSGEN;
    volatile    uint32_t    SUBSCRIBE_CRYPT;
    volatile    uint32_t    SUBSCRIBE_STOP;
    volatile    uint32_t    SUBSCRIBE_RATEOVERRIDE;
    volatile    uint32_t    RESERVED1[28];
    volatile    uint32_t    EVENTS_ENDKSGEN;
    volatile    uint32_t    EVENTS_ENDCRYPT;
    volatile    uint32_t    EVENTS_ERROR;
    volatile    uint32_t    RESERVED2[29];
    volatile    uint32_t    PUBLISH_ENDKSGEN;
    volatile    uint32_t    PUBLISH_ENDCRYPT;
    volatile    uint32_t    PUBLISH_ERROR;
    volatile    uint32_t    RESERVED3[29];
    volatile    uint32_t    SHORTS;
    volatile    uint32_t    RESERVED4[64];
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED5[61];
    volatile    uint32_t    MICSTATUS;
    volatile    uint32_t    RESERVED6[63];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    MODE;
    volatile    uint32_t    CNFPTR;
    volatile    uint32_t    INPTR;
    volatile    uint32_t    OUTPTR;
    volatile    uint32_t    SCRATCHPTR;
    volatile    uint32_t    MAXPACKETSIZE;
    volatile    uint32_t    RATEOVERRIDE;
    volatile    uint32_t    HEADERMASK;
} CCM_TypeDef;

#ifdef __cplusplus
#define CCM_NS  reinterpret_cast<CCM_TypeDef *>(0x4100E000U)

#else
#define CCM_NS  ((CCM_TypeDef *)0x4100E000U)
#endif

// TASKS_KSGEN Configuration

#define CCM_TASKS_KSGEN_TASKS_KSGEN                         (0x1U<<0U)
#define CCM_TASKS_KSGEN_TASKS_KSGEN_TRIGGER                 (0x1U<<0U)

// TASKS_CRYPT Configuration

#define CCM_TASKS_CRYPT_TASKS_CRYPT                         (0x1U<<0U)
#define CCM_TASKS_CRYPT_TASKS_CRYPT_TRIGGER                 (0x1U<<0U)

// TASKS_STOP Configuration

#define CCM_TASKS_STOP_TASKS_STOP                           (0x1U<<0U)
#define CCM_TASKS_STOP_TASKS_STOP_TRIGGER                   (0x1U<<0U)

// TASKS_RATEOVERRIDE Configuration

#define CCM_TASKS_RATEOVERRIDE_TASKS_RATEOVERRIDE           (0x1U<<0U)
#define CCM_TASKS_RATEOVERRIDE_TASKS_RATEOVERRIDE_TRIGGER   (0x1U<<0U)

// SUBSCRIBE_KSGEN Configuration

#define CCM_SUBSCRIBE_KSGEN_EN                              (0x1U<<31U)
#define CCM_SUBSCRIBE_KSGEN_CHIDX                           (0xFFU<<0U)
#define CCM_SUBSCRIBE_KSGEN_CHIDX_0                         (0x1U<<0U)
#define CCM_SUBSCRIBE_KSGEN_EN_DISABLED                     (0x0U<<31U)
#define CCM_SUBSCRIBE_KSGEN_EN_ENABLED                      (0x1U<<31U)

// SUBSCRIBE_CRYPT Configuration

#define CCM_SUBSCRIBE_CRYPT_EN                              (0x1U<<31U)
#define CCM_SUBSCRIBE_CRYPT_CHIDX                           (0xFFU<<0U)
#define CCM_SUBSCRIBE_CRYPT_CHIDX_0                         (0x1U<<0U)
#define CCM_SUBSCRIBE_CRYPT_EN_DISABLED                     (0x0U<<31U)
#define CCM_SUBSCRIBE_CRYPT_EN_ENABLED                      (0x1U<<31U)

// SUBSCRIBE_STOP Configuration

#define CCM_SUBSCRIBE_STOP_EN                               (0x1U<<31U)
#define CCM_SUBSCRIBE_STOP_CHIDX                            (0xFFU<<0U)
#define CCM_SUBSCRIBE_STOP_CHIDX_0                          (0x1U<<0U)
#define CCM_SUBSCRIBE_STOP_EN_DISABLED                      (0x0U<<31U)
#define CCM_SUBSCRIBE_STOP_EN_ENABLED                       (0x1U<<31U)

// SUBSCRIBE_RATEOVERRIDE Configuration

#define CCM_SUBSCRIBE_RATEOVERRIDE_EN                       (0x1U<<31U)
#define CCM_SUBSCRIBE_RATEOVERRIDE_CHIDX                    (0xFFU<<0U)
#define CCM_SUBSCRIBE_RATEOVERRIDE_CHIDX_0                  (0x1U<<0U)
#define CCM_SUBSCRIBE_RATEOVERRIDE_EN_DISABLED              (0x0U<<31U)
#define CCM_SUBSCRIBE_RATEOVERRIDE_EN_ENABLED               (0x1U<<31U)

// EVENTS_ENDKSGEN Configuration

#define CCM_EVENTS_ENDKSGEN_EVENTS_ENDKSGEN                 (0x1U<<0U)
#define CCM_EVENTS_ENDKSGEN_EVENTS_ENDKSGEN_NOTGENERATED    (0x0U<<0U)
#define CCM_EVENTS_ENDKSGEN_EVENTS_ENDKSGEN_GENERATED       (0x1U<<0U)

// EVENTS_ENDCRYPT Configuration

#define CCM_EVENTS_ENDCRYPT_EVENTS_ENDCRYPT                 (0x1U<<0U)
#define CCM_EVENTS_ENDCRYPT_EVENTS_ENDCRYPT_NOTGENERATED    (0x0U<<0U)
#define CCM_EVENTS_ENDCRYPT_EVENTS_ENDCRYPT_GENERATED       (0x1U<<0U)

// EVENTS_ERROR Configuration

#define CCM_EVENTS_ERROR_EVENTS_ERROR                       (0x1U<<0U)
#define CCM_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED          (0x0U<<0U)
#define CCM_EVENTS_ERROR_EVENTS_ERROR_GENERATED             (0x1U<<0U)

// PUBLISH_ENDKSGEN Configuration

#define CCM_PUBLISH_ENDKSGEN_EN                             (0x1U<<31U)
#define CCM_PUBLISH_ENDKSGEN_CHIDX                          (0xFFU<<0U)
#define CCM_PUBLISH_ENDKSGEN_CHIDX_0                        (0x1U<<0U)
#define CCM_PUBLISH_ENDKSGEN_EN_DISABLED                    (0x0U<<31U)
#define CCM_PUBLISH_ENDKSGEN_EN_ENABLED                     (0x1U<<31U)

// PUBLISH_ENDCRYPT Configuration

#define CCM_PUBLISH_ENDCRYPT_EN                             (0x1U<<31U)
#define CCM_PUBLISH_ENDCRYPT_CHIDX                          (0xFFU<<0U)
#define CCM_PUBLISH_ENDCRYPT_CHIDX_0                        (0x1U<<0U)
#define CCM_PUBLISH_ENDCRYPT_EN_DISABLED                    (0x0U<<31U)
#define CCM_PUBLISH_ENDCRYPT_EN_ENABLED                     (0x1U<<31U)

// PUBLISH_ERROR Configuration

#define CCM_PUBLISH_ERROR_EN                                (0x1U<<31U)
#define CCM_PUBLISH_ERROR_CHIDX                             (0xFFU<<0U)
#define CCM_PUBLISH_ERROR_CHIDX_0                           (0x1U<<0U)
#define CCM_PUBLISH_ERROR_EN_DISABLED                       (0x0U<<31U)
#define CCM_PUBLISH_ERROR_EN_ENABLED                        (0x1U<<31U)

// SHORTS Configuration

#define CCM_SHORTS_ENDKSGEN_CRYPT                           (0x1U<<0U)
#define CCM_SHORTS_ENDKSGEN_CRYPT_DISABLED                  (0x0U<<0U)
#define CCM_SHORTS_ENDKSGEN_CRYPT_ENABLED                   (0x1U<<0U)

// INTENSET Configuration

#define CCM_INTENSET_ERROR                                  (0x1U<<2U)
#define CCM_INTENSET_ENDCRYPT                               (0x1U<<1U)
#define CCM_INTENSET_ENDKSGEN                               (0x1U<<0U)
#define CCM_INTENSET_ERROR_DISABLED                         (0x0U<<2U)
#define CCM_INTENSET_ERROR_ENABLED                          (0x1U<<2U)
#define CCM_INTENSET_ERROR_SET                              (0x1U<<2U)
#define CCM_INTENSET_ENDCRYPT_DISABLED                      (0x0U<<1U)
#define CCM_INTENSET_ENDCRYPT_ENABLED                       (0x1U<<1U)
#define CCM_INTENSET_ENDCRYPT_SET                           (0x1U<<1U)
#define CCM_INTENSET_ENDKSGEN_DISABLED                      (0x0U<<0U)
#define CCM_INTENSET_ENDKSGEN_ENABLED                       (0x1U<<0U)
#define CCM_INTENSET_ENDKSGEN_SET                           (0x1U<<0U)

// INTENCLR Configuration

#define CCM_INTENCLR_ERROR                                  (0x1U<<2U)
#define CCM_INTENCLR_ENDCRYPT                               (0x1U<<1U)
#define CCM_INTENCLR_ENDKSGEN                               (0x1U<<0U)
#define CCM_INTENCLR_ERROR_DISABLED                         (0x0U<<2U)
#define CCM_INTENCLR_ERROR_ENABLED                          (0x1U<<2U)
#define CCM_INTENCLR_ERROR_CLEAR                            (0x1U<<2U)
#define CCM_INTENCLR_ENDCRYPT_DISABLED                      (0x0U<<1U)
#define CCM_INTENCLR_ENDCRYPT_ENABLED                       (0x1U<<1U)
#define CCM_INTENCLR_ENDCRYPT_CLEAR                         (0x1U<<1U)
#define CCM_INTENCLR_ENDKSGEN_DISABLED                      (0x0U<<0U)
#define CCM_INTENCLR_ENDKSGEN_ENABLED                       (0x1U<<0U)
#define CCM_INTENCLR_ENDKSGEN_CLEAR                         (0x1U<<0U)

// MICSTATUS Configuration

#define CCM_MICSTATUS_MICSTATUS                             (0x1U<<0U)
#define CCM_MICSTATUS_MICSTATUS_CHECKFAILED                 (0x0U<<0U)
#define CCM_MICSTATUS_MICSTATUS_CHECKPASSED                 (0x1U<<0U)

// ENABLE Configuration

#define CCM_ENABLE_ENABLE                                   (0x3U<<0U)
#define CCM_ENABLE_ENABLE_0                                 (0x1U<<0U)
#define CCM_ENABLE_ENABLE_DISABLED                          (0x0U<<0U)
#define CCM_ENABLE_ENABLE_ENABLED                           (0x2U<<0U)

// MODE Configuration

#define CCM_MODE_LENGTH                                     (0x1U<<24U)
#define CCM_MODE_DATARATE                                   (0x3U<<16U)
#define CCM_MODE_DATARATE_0                                 (0x1U<<16U)
#define CCM_MODE_MODE                                       (0x1U<<0U)
#define CCM_MODE_LENGTH_DEFAULT                             (0x0U<<24U)
#define CCM_MODE_LENGTH_EXTENDED                            (0x1U<<24U)
#define CCM_MODE_DATARATE_1MBIT                             (0x0U<<16U)
#define CCM_MODE_DATARATE_2MBIT                             (0x1U<<16U)
#define CCM_MODE_DATARATE_125KBPS                           (0x2U<<16U)
#define CCM_MODE_DATARATE_500KBPS                           (0x3U<<16U)
#define CCM_MODE_MODE_ENCRYPTION                            (0x0U<<0U)
#define CCM_MODE_MODE_DECRYPTION                            (0x1U<<0U)

// CNFPTR Configuration

#define CCM_CNFPTR_CNFPTR                                   (0xFFFFFFFFU<<0U)
#define CCM_CNFPTR_CNFPTR_0                                 (0x1U<<0U)

// INPTR Configuration

#define CCM_INPTR_INPTR                                     (0xFFFFFFFFU<<0U)
#define CCM_INPTR_INPTR_0                                   (0x1U<<0U)

// OUTPTR Configuration

#define CCM_OUTPTR_OUTPTR                                   (0xFFFFFFFFU<<0U)
#define CCM_OUTPTR_OUTPTR_0                                 (0x1U<<0U)

// SCRATCHPTR Configuration

#define CCM_SCRATCHPTR_SCRATCHPTR                           (0xFFFFFFFFU<<0U)
#define CCM_SCRATCHPTR_SCRATCHPTR_0                         (0x1U<<0U)

// MAXPACKETSIZE Configuration

#define CCM_MAXPACKETSIZE_MAXPACKETSIZE                     (0xFFU<<0U)
#define CCM_MAXPACKETSIZE_MAXPACKETSIZE_0                   (0x1U<<0U)

// RATEOVERRIDE Configuration

#define CCM_RATEOVERRIDE_RATEOVERRIDE                       (0x3U<<0U)
#define CCM_RATEOVERRIDE_RATEOVERRIDE_0                     (0x1U<<0U)
#define CCM_RATEOVERRIDE_RATEOVERRIDE_1MBIT                 (0x0U<<0U)
#define CCM_RATEOVERRIDE_RATEOVERRIDE_2MBIT                 (0x1U<<0U)
#define CCM_RATEOVERRIDE_RATEOVERRIDE_125KBPS               (0x2U<<0U)
#define CCM_RATEOVERRIDE_RATEOVERRIDE_500KBPS               (0x3U<<0U)

// HEADERMASK Configuration

#define CCM_HEADERMASK_HEADERMASK                           (0xFFU<<0U)
#define CCM_HEADERMASK_HEADERMASK_0                         (0x1U<<0U)
