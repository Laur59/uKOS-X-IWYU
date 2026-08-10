/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_usb_dpram equates.
 */

#pragma once

#include    <stdint.h>

// USB_DPRAM address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    SETUP_PACKET_LOW;
    volatile    uint32_t    SETUP_PACKET_HIGH;
    volatile    uint32_t    EP1_IN_CONTROL;
    volatile    uint32_t    EP1_OUT_CONTROL;
    volatile    uint32_t    EP2_IN_CONTROL;
    volatile    uint32_t    EP2_OUT_CONTROL;
    volatile    uint32_t    EP3_IN_CONTROL;
    volatile    uint32_t    EP3_OUT_CONTROL;
    volatile    uint32_t    EP4_IN_CONTROL;
    volatile    uint32_t    EP4_OUT_CONTROL;
    volatile    uint32_t    EP5_IN_CONTROL;
    volatile    uint32_t    EP5_OUT_CONTROL;
    volatile    uint32_t    EP6_IN_CONTROL;
    volatile    uint32_t    EP6_OUT_CONTROL;
    volatile    uint32_t    EP7_IN_CONTROL;
    volatile    uint32_t    EP7_OUT_CONTROL;
    volatile    uint32_t    EP8_IN_CONTROL;
    volatile    uint32_t    EP8_OUT_CONTROL;
    volatile    uint32_t    EP9_IN_CONTROL;
    volatile    uint32_t    EP9_OUT_CONTROL;
    volatile    uint32_t    EP10_IN_CONTROL;
    volatile    uint32_t    EP10_OUT_CONTROL;
    volatile    uint32_t    EP11_IN_CONTROL;
    volatile    uint32_t    EP11_OUT_CONTROL;
    volatile    uint32_t    EP12_IN_CONTROL;
    volatile    uint32_t    EP12_OUT_CONTROL;
    volatile    uint32_t    EP13_IN_CONTROL;
    volatile    uint32_t    EP13_OUT_CONTROL;
    volatile    uint32_t    EP14_IN_CONTROL;
    volatile    uint32_t    EP14_OUT_CONTROL;
    volatile    uint32_t    EP15_IN_CONTROL;
    volatile    uint32_t    EP15_OUT_CONTROL;
    volatile    uint32_t    EP0_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP0_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP1_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP1_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP2_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP2_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP3_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP3_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP4_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP4_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP5_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP5_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP6_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP6_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP7_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP7_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP8_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP8_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP9_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP9_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP10_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP10_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP11_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP11_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP12_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP12_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP13_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP13_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP14_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP14_OUT_BUFFER_CONTROL;
    volatile    uint32_t    EP15_IN_BUFFER_CONTROL;
    volatile    uint32_t    EP15_OUT_BUFFER_CONTROL;
} USB_DPRAM_TypeDef;

#ifdef __cplusplus
#define USB_DPRAM_NS    reinterpret_cast<USB_DPRAM_TypeDef *>(0x50100000U)
#define USB_DPRAM_S     reinterpret_cast<USB_DPRAM_TypeDef *>(0x50100000U)
#else
#define USB_DPRAM_NS    ((USB_DPRAM_TypeDef *)0x50100000U)
#define USB_DPRAM_S     ((USB_DPRAM_TypeDef *)0x50100000U)
#endif

// SETUP_PACKET_LOW Configuration

#define USB_DPRAM_SETUP_PACKET_LOW_BMREQUESTTYPE                            (0xFFU<<0U)
#define USB_DPRAM_SETUP_PACKET_LOW_BMREQUESTTYPE_0                          (0x1U<<0U)
#define USB_DPRAM_SETUP_PACKET_LOW_BREQUEST                                 (0xFFU<<8U)
#define USB_DPRAM_SETUP_PACKET_LOW_BREQUEST_0                               (0x1U<<8U)
#define USB_DPRAM_SETUP_PACKET_LOW_WVALUE                                   (0xFFFFU<<16U)
#define USB_DPRAM_SETUP_PACKET_LOW_WVALUE_0                                 (0x1U<<16U)

// SETUP_PACKET_HIGH Configuration

#define USB_DPRAM_SETUP_PACKET_HIGH_WINDEX                                  (0xFFFFU<<0U)
#define USB_DPRAM_SETUP_PACKET_HIGH_WINDEX_0                                (0x1U<<0U)
#define USB_DPRAM_SETUP_PACKET_HIGH_WLENGTH                                 (0xFFFFU<<16U)
#define USB_DPRAM_SETUP_PACKET_HIGH_WLENGTH_0                               (0x1U<<16U)

// EP1_IN_CONTROL Configuration

#define USB_DPRAM_EP1_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP1_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP1_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP1_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP1_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP1_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP1_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP1_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP1_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP1_OUT_CONTROL Configuration

#define USB_DPRAM_EP1_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP1_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP1_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP1_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP1_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP1_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP1_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP1_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP1_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP2_IN_CONTROL Configuration

#define USB_DPRAM_EP2_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP2_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP2_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP2_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP2_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP2_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP2_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP2_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP2_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP2_OUT_CONTROL Configuration

#define USB_DPRAM_EP2_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP2_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP2_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP2_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP2_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP2_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP2_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP2_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP2_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP3_IN_CONTROL Configuration

#define USB_DPRAM_EP3_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP3_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP3_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP3_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP3_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP3_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP3_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP3_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP3_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP3_OUT_CONTROL Configuration

#define USB_DPRAM_EP3_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP3_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP3_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP3_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP3_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP3_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP3_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP3_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP3_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP4_IN_CONTROL Configuration

#define USB_DPRAM_EP4_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP4_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP4_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP4_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP4_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP4_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP4_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP4_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP4_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP4_OUT_CONTROL Configuration

#define USB_DPRAM_EP4_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP4_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP4_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP4_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP4_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP4_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP4_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP4_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP4_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP5_IN_CONTROL Configuration

#define USB_DPRAM_EP5_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP5_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP5_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP5_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP5_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP5_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP5_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP5_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP5_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP5_OUT_CONTROL Configuration

#define USB_DPRAM_EP5_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP5_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP5_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP5_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP5_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP5_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP5_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP5_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP5_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP6_IN_CONTROL Configuration

#define USB_DPRAM_EP6_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP6_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP6_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP6_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP6_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP6_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP6_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP6_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP6_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP6_OUT_CONTROL Configuration

#define USB_DPRAM_EP6_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP6_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP6_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP6_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP6_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP6_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP6_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP6_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP6_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP7_IN_CONTROL Configuration

#define USB_DPRAM_EP7_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP7_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP7_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP7_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP7_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP7_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP7_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP7_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP7_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP7_OUT_CONTROL Configuration

#define USB_DPRAM_EP7_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP7_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP7_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP7_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP7_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP7_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP7_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP7_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP7_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP8_IN_CONTROL Configuration

#define USB_DPRAM_EP8_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP8_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP8_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP8_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP8_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP8_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP8_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP8_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP8_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP8_OUT_CONTROL Configuration

#define USB_DPRAM_EP8_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP8_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP8_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP8_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP8_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP8_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP8_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP8_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP8_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP9_IN_CONTROL Configuration

#define USB_DPRAM_EP9_IN_CONTROL_BUFFER_ADDRESS                             (0xFFFFU<<0U)
#define USB_DPRAM_EP9_IN_CONTROL_BUFFER_ADDRESS_0                           (0x1U<<0U)
#define USB_DPRAM_EP9_IN_CONTROL_INTERRUPT_ON_NAK                           (0x1U<<16U)
#define USB_DPRAM_EP9_IN_CONTROL_INTERRUPT_ON_STALL                         (0x1U<<17U)
#define USB_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE                              (0x3U<<26U)
#define USB_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_0                            (0x1U<<26U)
#define USB_DPRAM_EP9_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                  (0x1U<<28U)
#define USB_DPRAM_EP9_IN_CONTROL_INTERRUPT_PER_BUFF                         (0x1U<<29U)
#define USB_DPRAM_EP9_IN_CONTROL_DOUBLE_BUFFERED                            (0x1U<<30U)
#define USB_DPRAM_EP9_IN_CONTROL_ENABLE                                     (0x1U<<31U)
#define USB_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_CONTROL                      (0x0U<<26U)
#define USB_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                  (0x1U<<26U)
#define USB_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_BULK                         (0x2U<<26U)
#define USB_DPRAM_EP9_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                    (0x3U<<26U)

// EP9_OUT_CONTROL Configuration

#define USB_DPRAM_EP9_OUT_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP9_OUT_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP9_OUT_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP9_OUT_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP9_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP9_OUT_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP9_OUT_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP9_OUT_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP9_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP10_IN_CONTROL Configuration

#define USB_DPRAM_EP10_IN_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP10_IN_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP10_IN_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP10_IN_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP10_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP10_IN_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP10_IN_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP10_IN_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP10_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP10_OUT_CONTROL Configuration

#define USB_DPRAM_EP10_OUT_CONTROL_BUFFER_ADDRESS                           (0xFFFFU<<0U)
#define USB_DPRAM_EP10_OUT_CONTROL_BUFFER_ADDRESS_0                         (0x1U<<0U)
#define USB_DPRAM_EP10_OUT_CONTROL_INTERRUPT_ON_NAK                         (0x1U<<16U)
#define USB_DPRAM_EP10_OUT_CONTROL_INTERRUPT_ON_STALL                       (0x1U<<17U)
#define USB_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE                            (0x3U<<26U)
#define USB_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_0                          (0x1U<<26U)
#define USB_DPRAM_EP10_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                (0x1U<<28U)
#define USB_DPRAM_EP10_OUT_CONTROL_INTERRUPT_PER_BUFF                       (0x1U<<29U)
#define USB_DPRAM_EP10_OUT_CONTROL_DOUBLE_BUFFERED                          (0x1U<<30U)
#define USB_DPRAM_EP10_OUT_CONTROL_ENABLE                                   (0x1U<<31U)
#define USB_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                    (0x0U<<26U)
#define USB_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                (0x1U<<26U)
#define USB_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_BULK                       (0x2U<<26U)
#define USB_DPRAM_EP10_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                  (0x3U<<26U)

// EP11_IN_CONTROL Configuration

#define USB_DPRAM_EP11_IN_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP11_IN_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP11_IN_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP11_IN_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP11_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP11_IN_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP11_IN_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP11_IN_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP11_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP11_OUT_CONTROL Configuration

#define USB_DPRAM_EP11_OUT_CONTROL_BUFFER_ADDRESS                           (0xFFFFU<<0U)
#define USB_DPRAM_EP11_OUT_CONTROL_BUFFER_ADDRESS_0                         (0x1U<<0U)
#define USB_DPRAM_EP11_OUT_CONTROL_INTERRUPT_ON_NAK                         (0x1U<<16U)
#define USB_DPRAM_EP11_OUT_CONTROL_INTERRUPT_ON_STALL                       (0x1U<<17U)
#define USB_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE                            (0x3U<<26U)
#define USB_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_0                          (0x1U<<26U)
#define USB_DPRAM_EP11_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                (0x1U<<28U)
#define USB_DPRAM_EP11_OUT_CONTROL_INTERRUPT_PER_BUFF                       (0x1U<<29U)
#define USB_DPRAM_EP11_OUT_CONTROL_DOUBLE_BUFFERED                          (0x1U<<30U)
#define USB_DPRAM_EP11_OUT_CONTROL_ENABLE                                   (0x1U<<31U)
#define USB_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                    (0x0U<<26U)
#define USB_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                (0x1U<<26U)
#define USB_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_BULK                       (0x2U<<26U)
#define USB_DPRAM_EP11_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                  (0x3U<<26U)

// EP12_IN_CONTROL Configuration

#define USB_DPRAM_EP12_IN_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP12_IN_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP12_IN_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP12_IN_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP12_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP12_IN_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP12_IN_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP12_IN_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP12_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP12_OUT_CONTROL Configuration

#define USB_DPRAM_EP12_OUT_CONTROL_BUFFER_ADDRESS                           (0xFFFFU<<0U)
#define USB_DPRAM_EP12_OUT_CONTROL_BUFFER_ADDRESS_0                         (0x1U<<0U)
#define USB_DPRAM_EP12_OUT_CONTROL_INTERRUPT_ON_NAK                         (0x1U<<16U)
#define USB_DPRAM_EP12_OUT_CONTROL_INTERRUPT_ON_STALL                       (0x1U<<17U)
#define USB_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE                            (0x3U<<26U)
#define USB_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_0                          (0x1U<<26U)
#define USB_DPRAM_EP12_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                (0x1U<<28U)
#define USB_DPRAM_EP12_OUT_CONTROL_INTERRUPT_PER_BUFF                       (0x1U<<29U)
#define USB_DPRAM_EP12_OUT_CONTROL_DOUBLE_BUFFERED                          (0x1U<<30U)
#define USB_DPRAM_EP12_OUT_CONTROL_ENABLE                                   (0x1U<<31U)
#define USB_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                    (0x0U<<26U)
#define USB_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                (0x1U<<26U)
#define USB_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_BULK                       (0x2U<<26U)
#define USB_DPRAM_EP12_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                  (0x3U<<26U)

// EP13_IN_CONTROL Configuration

#define USB_DPRAM_EP13_IN_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP13_IN_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP13_IN_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP13_IN_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP13_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP13_IN_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP13_IN_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP13_IN_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP13_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP13_OUT_CONTROL Configuration

#define USB_DPRAM_EP13_OUT_CONTROL_BUFFER_ADDRESS                           (0xFFFFU<<0U)
#define USB_DPRAM_EP13_OUT_CONTROL_BUFFER_ADDRESS_0                         (0x1U<<0U)
#define USB_DPRAM_EP13_OUT_CONTROL_INTERRUPT_ON_NAK                         (0x1U<<16U)
#define USB_DPRAM_EP13_OUT_CONTROL_INTERRUPT_ON_STALL                       (0x1U<<17U)
#define USB_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE                            (0x3U<<26U)
#define USB_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_0                          (0x1U<<26U)
#define USB_DPRAM_EP13_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                (0x1U<<28U)
#define USB_DPRAM_EP13_OUT_CONTROL_INTERRUPT_PER_BUFF                       (0x1U<<29U)
#define USB_DPRAM_EP13_OUT_CONTROL_DOUBLE_BUFFERED                          (0x1U<<30U)
#define USB_DPRAM_EP13_OUT_CONTROL_ENABLE                                   (0x1U<<31U)
#define USB_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                    (0x0U<<26U)
#define USB_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                (0x1U<<26U)
#define USB_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_BULK                       (0x2U<<26U)
#define USB_DPRAM_EP13_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                  (0x3U<<26U)

// EP14_IN_CONTROL Configuration

#define USB_DPRAM_EP14_IN_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP14_IN_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP14_IN_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP14_IN_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP14_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP14_IN_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP14_IN_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP14_IN_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP14_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP14_OUT_CONTROL Configuration

#define USB_DPRAM_EP14_OUT_CONTROL_BUFFER_ADDRESS                           (0xFFFFU<<0U)
#define USB_DPRAM_EP14_OUT_CONTROL_BUFFER_ADDRESS_0                         (0x1U<<0U)
#define USB_DPRAM_EP14_OUT_CONTROL_INTERRUPT_ON_NAK                         (0x1U<<16U)
#define USB_DPRAM_EP14_OUT_CONTROL_INTERRUPT_ON_STALL                       (0x1U<<17U)
#define USB_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE                            (0x3U<<26U)
#define USB_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_0                          (0x1U<<26U)
#define USB_DPRAM_EP14_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                (0x1U<<28U)
#define USB_DPRAM_EP14_OUT_CONTROL_INTERRUPT_PER_BUFF                       (0x1U<<29U)
#define USB_DPRAM_EP14_OUT_CONTROL_DOUBLE_BUFFERED                          (0x1U<<30U)
#define USB_DPRAM_EP14_OUT_CONTROL_ENABLE                                   (0x1U<<31U)
#define USB_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                    (0x0U<<26U)
#define USB_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                (0x1U<<26U)
#define USB_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_BULK                       (0x2U<<26U)
#define USB_DPRAM_EP14_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                  (0x3U<<26U)

// EP15_IN_CONTROL Configuration

#define USB_DPRAM_EP15_IN_CONTROL_BUFFER_ADDRESS                            (0xFFFFU<<0U)
#define USB_DPRAM_EP15_IN_CONTROL_BUFFER_ADDRESS_0                          (0x1U<<0U)
#define USB_DPRAM_EP15_IN_CONTROL_INTERRUPT_ON_NAK                          (0x1U<<16U)
#define USB_DPRAM_EP15_IN_CONTROL_INTERRUPT_ON_STALL                        (0x1U<<17U)
#define USB_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE                             (0x3U<<26U)
#define USB_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_0                           (0x1U<<26U)
#define USB_DPRAM_EP15_IN_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                 (0x1U<<28U)
#define USB_DPRAM_EP15_IN_CONTROL_INTERRUPT_PER_BUFF                        (0x1U<<29U)
#define USB_DPRAM_EP15_IN_CONTROL_DOUBLE_BUFFERED                           (0x1U<<30U)
#define USB_DPRAM_EP15_IN_CONTROL_ENABLE                                    (0x1U<<31U)
#define USB_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_CONTROL                     (0x0U<<26U)
#define USB_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                 (0x1U<<26U)
#define USB_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_BULK                        (0x2U<<26U)
#define USB_DPRAM_EP15_IN_CONTROL_ENDPOINT_TYPE_INTERRUPT                   (0x3U<<26U)

// EP15_OUT_CONTROL Configuration

#define USB_DPRAM_EP15_OUT_CONTROL_BUFFER_ADDRESS                           (0xFFFFU<<0U)
#define USB_DPRAM_EP15_OUT_CONTROL_BUFFER_ADDRESS_0                         (0x1U<<0U)
#define USB_DPRAM_EP15_OUT_CONTROL_INTERRUPT_ON_NAK                         (0x1U<<16U)
#define USB_DPRAM_EP15_OUT_CONTROL_INTERRUPT_ON_STALL                       (0x1U<<17U)
#define USB_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE                            (0x3U<<26U)
#define USB_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_0                          (0x1U<<26U)
#define USB_DPRAM_EP15_OUT_CONTROL_INTERRUPT_PER_DOUBLE_BUFF                (0x1U<<28U)
#define USB_DPRAM_EP15_OUT_CONTROL_INTERRUPT_PER_BUFF                       (0x1U<<29U)
#define USB_DPRAM_EP15_OUT_CONTROL_DOUBLE_BUFFERED                          (0x1U<<30U)
#define USB_DPRAM_EP15_OUT_CONTROL_ENABLE                                   (0x1U<<31U)
#define USB_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_CONTROL                    (0x0U<<26U)
#define USB_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_ISOCHRONOUS                (0x1U<<26U)
#define USB_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_BULK                       (0x2U<<26U)
#define USB_DPRAM_EP15_OUT_CONTROL_ENDPOINT_TYPE_INTERRUPT                  (0x3U<<26U)

// EP0_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP0_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP0_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP0_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP1_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP1_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP1_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP1_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP2_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP2_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP2_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP2_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP3_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP3_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP3_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP3_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP4_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP4_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP4_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP4_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP5_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP5_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP5_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP5_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP6_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP6_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP6_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP6_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP7_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP7_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP7_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP7_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP8_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP8_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP8_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP8_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP9_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_0                            (0x3FFU<<0U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_0_0                          (0x1U<<0U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_AVAILABLE_0                         (0x1U<<10U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_STALL                               (0x1U<<11U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_RESET                               (0x1U<<12U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_PID_0                               (0x1U<<13U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_LAST_0                              (0x1U<<14U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_FULL_0                              (0x1U<<15U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_1                            (0x3FFU<<16U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_LENGTH_1_0                          (0x1U<<16U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_AVAILABLE_1                         (0x1U<<26U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET            (0x3U<<27U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0          (0x1U<<27U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_PID_1                               (0x1U<<29U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_LAST_1                              (0x1U<<30U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_FULL_1                              (0x1U<<31U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128        (0x0U<<27U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256        (0x1U<<27U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512        (0x2U<<27U)
#define USB_DPRAM_EP9_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024       (0x3U<<27U)

// EP9_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP9_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP10_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP10_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP10_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_0                          (0x3FFU<<0U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_0_0                        (0x1U<<0U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_AVAILABLE_0                       (0x1U<<10U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_STALL                             (0x1U<<11U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_RESET                             (0x1U<<12U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_PID_0                             (0x1U<<13U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_LAST_0                            (0x1U<<14U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_FULL_0                            (0x1U<<15U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_1                          (0x3FFU<<16U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_LENGTH_1_0                        (0x1U<<16U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_AVAILABLE_1                       (0x1U<<26U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET          (0x3U<<27U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0        (0x1U<<27U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_PID_1                             (0x1U<<29U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_LAST_1                            (0x1U<<30U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_FULL_1                            (0x1U<<31U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128      (0x0U<<27U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256      (0x1U<<27U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512      (0x2U<<27U)
#define USB_DPRAM_EP10_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024     (0x3U<<27U)

// EP11_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP11_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP11_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_0                          (0x3FFU<<0U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_0_0                        (0x1U<<0U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_AVAILABLE_0                       (0x1U<<10U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_STALL                             (0x1U<<11U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_RESET                             (0x1U<<12U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_PID_0                             (0x1U<<13U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_LAST_0                            (0x1U<<14U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_FULL_0                            (0x1U<<15U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_1                          (0x3FFU<<16U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_LENGTH_1_0                        (0x1U<<16U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_AVAILABLE_1                       (0x1U<<26U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET          (0x3U<<27U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0        (0x1U<<27U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_PID_1                             (0x1U<<29U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_LAST_1                            (0x1U<<30U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_FULL_1                            (0x1U<<31U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128      (0x0U<<27U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256      (0x1U<<27U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512      (0x2U<<27U)
#define USB_DPRAM_EP11_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024     (0x3U<<27U)

// EP12_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP12_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP12_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_0                          (0x3FFU<<0U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_0_0                        (0x1U<<0U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_AVAILABLE_0                       (0x1U<<10U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_STALL                             (0x1U<<11U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_RESET                             (0x1U<<12U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_PID_0                             (0x1U<<13U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_LAST_0                            (0x1U<<14U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_FULL_0                            (0x1U<<15U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_1                          (0x3FFU<<16U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_LENGTH_1_0                        (0x1U<<16U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_AVAILABLE_1                       (0x1U<<26U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET          (0x3U<<27U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0        (0x1U<<27U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_PID_1                             (0x1U<<29U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_LAST_1                            (0x1U<<30U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_FULL_1                            (0x1U<<31U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128      (0x0U<<27U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256      (0x1U<<27U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512      (0x2U<<27U)
#define USB_DPRAM_EP12_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024     (0x3U<<27U)

// EP13_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP13_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP13_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_0                          (0x3FFU<<0U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_0_0                        (0x1U<<0U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_AVAILABLE_0                       (0x1U<<10U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_STALL                             (0x1U<<11U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_RESET                             (0x1U<<12U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_PID_0                             (0x1U<<13U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_LAST_0                            (0x1U<<14U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_FULL_0                            (0x1U<<15U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_1                          (0x3FFU<<16U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_LENGTH_1_0                        (0x1U<<16U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_AVAILABLE_1                       (0x1U<<26U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET          (0x3U<<27U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0        (0x1U<<27U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_PID_1                             (0x1U<<29U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_LAST_1                            (0x1U<<30U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_FULL_1                            (0x1U<<31U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128      (0x0U<<27U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256      (0x1U<<27U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512      (0x2U<<27U)
#define USB_DPRAM_EP13_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024     (0x3U<<27U)

// EP14_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP14_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP14_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_0                          (0x3FFU<<0U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_0_0                        (0x1U<<0U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_AVAILABLE_0                       (0x1U<<10U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_STALL                             (0x1U<<11U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_RESET                             (0x1U<<12U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_PID_0                             (0x1U<<13U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_LAST_0                            (0x1U<<14U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_FULL_0                            (0x1U<<15U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_1                          (0x3FFU<<16U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_LENGTH_1_0                        (0x1U<<16U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_AVAILABLE_1                       (0x1U<<26U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET          (0x3U<<27U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0        (0x1U<<27U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_PID_1                             (0x1U<<29U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_LAST_1                            (0x1U<<30U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_FULL_1                            (0x1U<<31U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128      (0x0U<<27U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256      (0x1U<<27U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512      (0x2U<<27U)
#define USB_DPRAM_EP14_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024     (0x3U<<27U)

// EP15_IN_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_0                           (0x3FFU<<0U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_0_0                         (0x1U<<0U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_AVAILABLE_0                        (0x1U<<10U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_STALL                              (0x1U<<11U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_RESET                              (0x1U<<12U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_PID_0                              (0x1U<<13U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_LAST_0                             (0x1U<<14U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_FULL_0                             (0x1U<<15U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_1                           (0x3FFU<<16U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_LENGTH_1_0                         (0x1U<<16U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_AVAILABLE_1                        (0x1U<<26U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET           (0x3U<<27U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0         (0x1U<<27U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_PID_1                              (0x1U<<29U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_LAST_1                             (0x1U<<30U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_FULL_1                             (0x1U<<31U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128       (0x0U<<27U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256       (0x1U<<27U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512       (0x2U<<27U)
#define USB_DPRAM_EP15_IN_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024      (0x3U<<27U)

// EP15_OUT_BUFFER_CONTROL Configuration

#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_0                          (0x3FFU<<0U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_0_0                        (0x1U<<0U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_AVAILABLE_0                       (0x1U<<10U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_STALL                             (0x1U<<11U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_RESET                             (0x1U<<12U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_PID_0                             (0x1U<<13U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_LAST_0                            (0x1U<<14U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_FULL_0                            (0x1U<<15U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_1                          (0x3FFU<<16U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_LENGTH_1_0                        (0x1U<<16U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_AVAILABLE_1                       (0x1U<<26U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET          (0x3U<<27U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_0        (0x1U<<27U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_PID_1                             (0x1U<<29U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_LAST_1                            (0x1U<<30U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_FULL_1                            (0x1U<<31U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_128      (0x0U<<27U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_256      (0x1U<<27U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_512      (0x2U<<27U)
#define USB_DPRAM_EP15_OUT_BUFFER_CONTROL_DOUBLE_BUFFER_ISO_OFFSET_1024     (0x3U<<27U)
