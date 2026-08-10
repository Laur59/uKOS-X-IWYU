/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_fpu equates.
 */

#pragma once

#include    <stdint.h>

// FPU address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0[64];
    volatile    uint32_t    EVENTS_INVALIDOPERATION;
    volatile    uint32_t    EVENTS_DIVIDEBYZERO;
    volatile    uint32_t    EVENTS_OVERFLOW;
    volatile    uint32_t    EVENTS_UNDERFLOW;
    volatile    uint32_t    EVENTS_INEXACT;
    volatile    uint32_t    EVENTS_DENORMALINPUT;
    volatile    uint32_t    RESERVED1[122];
    volatile    uint32_t    INTEN;
    volatile    uint32_t    INTENSET;
    volatile    uint32_t    INTENCLR;
} FPU_TypeDef;

#ifdef __cplusplus
#define FPU_NS  reinterpret_cast<FPU_TypeDef *>(0x40000000U)
#define FPU_S   reinterpret_cast<FPU_TypeDef *>(0x50000000U)

#else
#define FPU_NS  ((FPU_TypeDef *)0x40000000U)
#define FPU_S   ((FPU_TypeDef *)0x50000000U)
#endif

// EVENTS_INVALIDOPERATION Configuration

#define FPU_EVENTS_INVALIDOPERATION_EVENTS_INVALIDOPERATION                 (0x1U<<0U)
#define FPU_EVENTS_INVALIDOPERATION_EVENTS_INVALIDOPERATION_NOTGENERATED    (0x0U<<0U)
#define FPU_EVENTS_INVALIDOPERATION_EVENTS_INVALIDOPERATION_GENERATED       (0x1U<<0U)

// EVENTS_DIVIDEBYZERO Configuration

#define FPU_EVENTS_DIVIDEBYZERO_EVENTS_DIVIDEBYZERO                         (0x1U<<0U)
#define FPU_EVENTS_DIVIDEBYZERO_EVENTS_DIVIDEBYZERO_NOTGENERATED            (0x0U<<0U)
#define FPU_EVENTS_DIVIDEBYZERO_EVENTS_DIVIDEBYZERO_GENERATED               (0x1U<<0U)

// EVENTS_OVERFLOW Configuration

#define FPU_EVENTS_OVERFLOW_EVENTS_OVERFLOW                                 (0x1U<<0U)
#define FPU_EVENTS_OVERFLOW_EVENTS_OVERFLOW_NOTGENERATED                    (0x0U<<0U)
#define FPU_EVENTS_OVERFLOW_EVENTS_OVERFLOW_GENERATED                       (0x1U<<0U)

// EVENTS_UNDERFLOW Configuration

#define FPU_EVENTS_UNDERFLOW_EVENTS_UNDERFLOW                               (0x1U<<0U)
#define FPU_EVENTS_UNDERFLOW_EVENTS_UNDERFLOW_NOTGENERATED                  (0x0U<<0U)
#define FPU_EVENTS_UNDERFLOW_EVENTS_UNDERFLOW_GENERATED                     (0x1U<<0U)

// EVENTS_INEXACT Configuration

#define FPU_EVENTS_INEXACT_EVENTS_INEXACT                                   (0x1U<<0U)
#define FPU_EVENTS_INEXACT_EVENTS_INEXACT_NOTGENERATED                      (0x0U<<0U)
#define FPU_EVENTS_INEXACT_EVENTS_INEXACT_GENERATED                         (0x1U<<0U)

// EVENTS_DENORMALINPUT Configuration

#define FPU_EVENTS_DENORMALINPUT_EVENTS_DENORMALINPUT                       (0x1U<<0U)
#define FPU_EVENTS_DENORMALINPUT_EVENTS_DENORMALINPUT_NOTGENERATED          (0x0U<<0U)
#define FPU_EVENTS_DENORMALINPUT_EVENTS_DENORMALINPUT_GENERATED             (0x1U<<0U)

// INTEN Configuration

#define FPU_INTEN_DENORMALINPUT                                             (0x1U<<5U)
#define FPU_INTEN_INEXACT                                                   (0x1U<<4U)
#define FPU_INTEN_UNDERFLOW                                                 (0x1U<<3U)
#define FPU_INTEN_OVERFLOW                                                  (0x1U<<2U)
#define FPU_INTEN_DIVIDEBYZERO                                              (0x1U<<1U)
#define FPU_INTEN_INVALIDOPERATION                                          (0x1U<<0U)
#define FPU_INTEN_DENORMALINPUT_DISABLED                                    (0x0U<<5U)
#define FPU_INTEN_DENORMALINPUT_ENABLED                                     (0x1U<<5U)
#define FPU_INTEN_INEXACT_DISABLED                                          (0x0U<<4U)
#define FPU_INTEN_INEXACT_ENABLED                                           (0x1U<<4U)
#define FPU_INTEN_UNDERFLOW_DISABLED                                        (0x0U<<3U)
#define FPU_INTEN_UNDERFLOW_ENABLED                                         (0x1U<<3U)
#define FPU_INTEN_OVERFLOW_DISABLED                                         (0x0U<<2U)
#define FPU_INTEN_OVERFLOW_ENABLED                                          (0x1U<<2U)
#define FPU_INTEN_DIVIDEBYZERO_DISABLED                                     (0x0U<<1U)
#define FPU_INTEN_DIVIDEBYZERO_ENABLED                                      (0x1U<<1U)
#define FPU_INTEN_INVALIDOPERATION_DISABLED                                 (0x0U<<0U)
#define FPU_INTEN_INVALIDOPERATION_ENABLED                                  (0x1U<<0U)

// INTENSET Configuration

#define FPU_INTENSET_DENORMALINPUT                                          (0x1U<<5U)
#define FPU_INTENSET_INEXACT                                                (0x1U<<4U)
#define FPU_INTENSET_UNDERFLOW                                              (0x1U<<3U)
#define FPU_INTENSET_OVERFLOW                                               (0x1U<<2U)
#define FPU_INTENSET_DIVIDEBYZERO                                           (0x1U<<1U)
#define FPU_INTENSET_INVALIDOPERATION                                       (0x1U<<0U)
#define FPU_INTENSET_DENORMALINPUT_DISABLED                                 (0x0U<<5U)
#define FPU_INTENSET_DENORMALINPUT_ENABLED                                  (0x1U<<5U)
#define FPU_INTENSET_DENORMALINPUT_SET                                      (0x1U<<5U)
#define FPU_INTENSET_INEXACT_DISABLED                                       (0x0U<<4U)
#define FPU_INTENSET_INEXACT_ENABLED                                        (0x1U<<4U)
#define FPU_INTENSET_INEXACT_SET                                            (0x1U<<4U)
#define FPU_INTENSET_UNDERFLOW_DISABLED                                     (0x0U<<3U)
#define FPU_INTENSET_UNDERFLOW_ENABLED                                      (0x1U<<3U)
#define FPU_INTENSET_UNDERFLOW_SET                                          (0x1U<<3U)
#define FPU_INTENSET_OVERFLOW_DISABLED                                      (0x0U<<2U)
#define FPU_INTENSET_OVERFLOW_ENABLED                                       (0x1U<<2U)
#define FPU_INTENSET_OVERFLOW_SET                                           (0x1U<<2U)
#define FPU_INTENSET_DIVIDEBYZERO_DISABLED                                  (0x0U<<1U)
#define FPU_INTENSET_DIVIDEBYZERO_ENABLED                                   (0x1U<<1U)
#define FPU_INTENSET_DIVIDEBYZERO_SET                                       (0x1U<<1U)
#define FPU_INTENSET_INVALIDOPERATION_DISABLED                              (0x0U<<0U)
#define FPU_INTENSET_INVALIDOPERATION_ENABLED                               (0x1U<<0U)
#define FPU_INTENSET_INVALIDOPERATION_SET                                   (0x1U<<0U)

// INTENCLR Configuration

#define FPU_INTENCLR_DENORMALINPUT                                          (0x1U<<5U)
#define FPU_INTENCLR_INEXACT                                                (0x1U<<4U)
#define FPU_INTENCLR_UNDERFLOW                                              (0x1U<<3U)
#define FPU_INTENCLR_OVERFLOW                                               (0x1U<<2U)
#define FPU_INTENCLR_DIVIDEBYZERO                                           (0x1U<<1U)
#define FPU_INTENCLR_INVALIDOPERATION                                       (0x1U<<0U)
#define FPU_INTENCLR_DENORMALINPUT_DISABLED                                 (0x0U<<5U)
#define FPU_INTENCLR_DENORMALINPUT_ENABLED                                  (0x1U<<5U)
#define FPU_INTENCLR_DENORMALINPUT_CLEAR                                    (0x1U<<5U)
#define FPU_INTENCLR_INEXACT_DISABLED                                       (0x0U<<4U)
#define FPU_INTENCLR_INEXACT_ENABLED                                        (0x1U<<4U)
#define FPU_INTENCLR_INEXACT_CLEAR                                          (0x1U<<4U)
#define FPU_INTENCLR_UNDERFLOW_DISABLED                                     (0x0U<<3U)
#define FPU_INTENCLR_UNDERFLOW_ENABLED                                      (0x1U<<3U)
#define FPU_INTENCLR_UNDERFLOW_CLEAR                                        (0x1U<<3U)
#define FPU_INTENCLR_OVERFLOW_DISABLED                                      (0x0U<<2U)
#define FPU_INTENCLR_OVERFLOW_ENABLED                                       (0x1U<<2U)
#define FPU_INTENCLR_OVERFLOW_CLEAR                                         (0x1U<<2U)
#define FPU_INTENCLR_DIVIDEBYZERO_DISABLED                                  (0x0U<<1U)
#define FPU_INTENCLR_DIVIDEBYZERO_ENABLED                                   (0x1U<<1U)
#define FPU_INTENCLR_DIVIDEBYZERO_CLEAR                                     (0x1U<<1U)
#define FPU_INTENCLR_INVALIDOPERATION_DISABLED                              (0x0U<<0U)
#define FPU_INTENCLR_INVALIDOPERATION_ENABLED                               (0x1U<<0U)
#define FPU_INTENCLR_INVALIDOPERATION_CLEAR                                 (0x1U<<0U)
