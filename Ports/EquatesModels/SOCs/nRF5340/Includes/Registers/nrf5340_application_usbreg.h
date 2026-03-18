/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_usbreg equates.
 */

#pragma once

#include    <stdint.h>

// USBREG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[64];
    volatile    uint32_t    EVENTS_USBDETECTED;
    volatile    uint32_t    EVENTS_USBREMOVED;
    volatile    uint32_t    EVENTS_USBPWRRDY;
    volatile    uint32_t    RESERVED1[29];
    volatile    uint32_t    PUBLISH_USBDETECTED;
    volatile    uint32_t    PUBLISH_USBREMOVED;
    volatile    uint32_t    PUBLISH_USBPWRRDY;
    volatile    uint32_t    RESERVED2[93];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
    volatile    uint32_t    RESERVED3[61];
    volatile    uint32_t    USBREGSTATUS;
} USBREG_TypeDef;

#ifdef __cplusplus
#define USBREGULATOR_NS reinterpret_cast<USBREG_TypeDef *>(0x40037000U)
#define USBREGULATOR_S  reinterpret_cast<USBREG_TypeDef *>(0x50037000U)

#else
#define USBREGULATOR_NS ((USBREG_TypeDef *)0x40037000U)
#define USBREGULATOR_S  ((USBREG_TypeDef *)0x50037000U)
#endif

// EVENTS_USBDETECTED Configuration

#define USBREG_EVENTS_USBDETECTED_EVENTS_USBDETECTED                (0x1U<<0)
#define USBREG_EVENTS_USBDETECTED_EVENTS_USBDETECTED_NOTGENERATED   (0x0U<<0)
#define USBREG_EVENTS_USBDETECTED_EVENTS_USBDETECTED_GENERATED      (0x1U<<0)

// EVENTS_USBREMOVED Configuration

#define USBREG_EVENTS_USBREMOVED_EVENTS_USBREMOVED                  (0x1U<<0)
#define USBREG_EVENTS_USBREMOVED_EVENTS_USBREMOVED_NOTGENERATED     (0x0U<<0)
#define USBREG_EVENTS_USBREMOVED_EVENTS_USBREMOVED_GENERATED        (0x1U<<0)

// EVENTS_USBPWRRDY Configuration

#define USBREG_EVENTS_USBPWRRDY_EVENTS_USBPWRRDY                    (0x1U<<0)
#define USBREG_EVENTS_USBPWRRDY_EVENTS_USBPWRRDY_NOTGENERATED       (0x0U<<0)
#define USBREG_EVENTS_USBPWRRDY_EVENTS_USBPWRRDY_GENERATED          (0x1U<<0)

// PUBLISH_USBDETECTED Configuration

#define USBREG_PUBLISH_USBDETECTED_EN                               (0x1U<<31)
#define USBREG_PUBLISH_USBDETECTED_CHIDX                            (0xFFU<<0)
#define USBREG_PUBLISH_USBDETECTED_CHIDX_0                          (0x1U<<0)
#define USBREG_PUBLISH_USBDETECTED_EN_DISABLED                      (0x0U<<31)
#define USBREG_PUBLISH_USBDETECTED_EN_ENABLED                       (0x1U<<31)

// PUBLISH_USBREMOVED Configuration

#define USBREG_PUBLISH_USBREMOVED_EN                                (0x1U<<31)
#define USBREG_PUBLISH_USBREMOVED_CHIDX                             (0xFFU<<0)
#define USBREG_PUBLISH_USBREMOVED_CHIDX_0                           (0x1U<<0)
#define USBREG_PUBLISH_USBREMOVED_EN_DISABLED                       (0x0U<<31)
#define USBREG_PUBLISH_USBREMOVED_EN_ENABLED                        (0x1U<<31)

// PUBLISH_USBPWRRDY Configuration

#define USBREG_PUBLISH_USBPWRRDY_EN                                 (0x1U<<31)
#define USBREG_PUBLISH_USBPWRRDY_CHIDX                              (0xFFU<<0)
#define USBREG_PUBLISH_USBPWRRDY_CHIDX_0                            (0x1U<<0)
#define USBREG_PUBLISH_USBPWRRDY_EN_DISABLED                        (0x0U<<31)
#define USBREG_PUBLISH_USBPWRRDY_EN_ENABLED                         (0x1U<<31)

// INTEN Configuration

#define USBREG_INTEN_USBPWRRDY                                      (0x1U<<2)
#define USBREG_INTEN_USBREMOVED                                     (0x1U<<1)
#define USBREG_INTEN_USBDETECTED                                    (0x1U<<0)
#define USBREG_INTEN_USBPWRRDY_DISABLED                             (0x0U<<2)
#define USBREG_INTEN_USBPWRRDY_ENABLED                              (0x1U<<2)
#define USBREG_INTEN_USBREMOVED_DISABLED                            (0x0U<<1)
#define USBREG_INTEN_USBREMOVED_ENABLED                             (0x1U<<1)
#define USBREG_INTEN_USBDETECTED_DISABLED                           (0x0U<<0)
#define USBREG_INTEN_USBDETECTED_ENABLED                            (0x1U<<0)

// INTENSET Configuration

#define USBREG_INTENSET_USBPWRRDY                                   (0x1U<<2)
#define USBREG_INTENSET_USBREMOVED                                  (0x1U<<1)
#define USBREG_INTENSET_USBDETECTED                                 (0x1U<<0)
#define USBREG_INTENSET_USBPWRRDY_DISABLED                          (0x0U<<2)
#define USBREG_INTENSET_USBPWRRDY_ENABLED                           (0x1U<<2)
#define USBREG_INTENSET_USBPWRRDY_SET                               (0x1U<<2)
#define USBREG_INTENSET_USBREMOVED_DISABLED                         (0x0U<<1)
#define USBREG_INTENSET_USBREMOVED_ENABLED                          (0x1U<<1)
#define USBREG_INTENSET_USBREMOVED_SET                              (0x1U<<1)
#define USBREG_INTENSET_USBDETECTED_DISABLED                        (0x0U<<0)
#define USBREG_INTENSET_USBDETECTED_ENABLED                         (0x1U<<0)
#define USBREG_INTENSET_USBDETECTED_SET                             (0x1U<<0)

// INTENCLR Configuration

#define USBREG_INTENCLR_USBPWRRDY                                   (0x1U<<2)
#define USBREG_INTENCLR_USBREMOVED                                  (0x1U<<1)
#define USBREG_INTENCLR_USBDETECTED                                 (0x1U<<0)
#define USBREG_INTENCLR_USBPWRRDY_DISABLED                          (0x0U<<2)
#define USBREG_INTENCLR_USBPWRRDY_ENABLED                           (0x1U<<2)
#define USBREG_INTENCLR_USBPWRRDY_CLEAR                             (0x1U<<2)
#define USBREG_INTENCLR_USBREMOVED_DISABLED                         (0x0U<<1)
#define USBREG_INTENCLR_USBREMOVED_ENABLED                          (0x1U<<1)
#define USBREG_INTENCLR_USBREMOVED_CLEAR                            (0x1U<<1)
#define USBREG_INTENCLR_USBDETECTED_DISABLED                        (0x0U<<0)
#define USBREG_INTENCLR_USBDETECTED_ENABLED                         (0x1U<<0)
#define USBREG_INTENCLR_USBDETECTED_CLEAR                           (0x1U<<0)

// USBREGSTATUS Configuration

#define USBREG_USBREGSTATUS_OUTPUTRDY                               (0x1U<<1)
#define USBREG_USBREGSTATUS_VBUSDETECT                              (0x1U<<0)
#define USBREG_USBREGSTATUS_OUTPUTRDY_NOTREADY                      (0x0U<<1)
#define USBREG_USBREGSTATUS_OUTPUTRDY_READY                         (0x1U<<1)
#define USBREG_USBREGSTATUS_VBUSDETECT_NOVBUS                       (0x0U<<0)
#define USBREG_USBREGSTATUS_VBUSDETECT_VBUSPRESENT                  (0x1U<<0)
