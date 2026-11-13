/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal: OctoFlash MX66UW1G45GXDI00 equates.
 */

#pragma once

// Memory structure

#define KMX66_xSPI_SZ_FLASH                 (128U * 1024U * 1024U)                          // Flash size (128-MBytes)
#define KMX66_DEV_SIZE_VALUE                26U                                             // 128-MB = 2^(26 + 1)

// XSPI timings (assumed 300-MHz kernel clock; validate on the board)

#define KMX66_PRESCALER                     (8U - 1U)                                       // 37.5-MHz XSPI clock
#define KMX66_DUMMY_CYCLES                  20U                                             // Read latency: validate against CR2
#define KMX66_TIMEOUT                       10000000U                                       // Polling limit, not a timebase

// Commands for the chip MX66UW1G45GXDI00 (SPI STR)

#define KMX66_OP_RESET_ENABLE               0x66U                                           // Reset enable
#define KMX66_OP_RESET                      0x99U                                           // Reset memory
#define KMX66_OP_WRITE_ENABLE               0x06U                                           // Write enable
#define KMX66_OP_READ_STATUS                0x05U                                           // Read status register
#define KMX66_OP_READ_CFG2                  0x71U                                           // Read configuration register 2
#define KMX66_OP_WRITE_CFG2                 0x72U                                           // Write configuration register 2

// Commands for the chip MX66UW1G45GXDI00 (Octal DTR)

#define KMX66_OP_OCTAL_READ                 0xEE11U                                         // Octal DDR read, opcode + complement

// Configuration register 2 addresses and fields

#define KMX66_CFG2_PROTOCOL                 0x00000000U                                     // Protocol selection
#define KMX66_CFG2_DUMMY                    0x00000300U                                     // Dummy cycle selection
#define KMX66_CFG2_DTR                      0x02U                                           // Octal DTR selection
#define KMX66_CFG2_DC20                     0x00U                                           // 20 dummy cycles: verify datasheet encoding

// Register selectors used by local_OctoFlashRead/WriteRegister (uint8_t API)

#define KMX66_REG_PROTOCOL                  0U                                              // CR2 at 0x00000000
#define KMX66_REG_DUMMY                     3U                                              // CR2 at 0x00000300
