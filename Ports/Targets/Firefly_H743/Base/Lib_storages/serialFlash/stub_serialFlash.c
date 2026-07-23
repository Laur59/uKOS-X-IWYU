/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        stub for the connection of the "serialFlash" manager device by qspi device.
 */

#include    "Registers/stm32H743_quadspi.h"  // for QUADSPI
#include    "Registers/stm32H743_rcc.h"
#include    "W25Q128J/W25Q128J.h"            // IWYU pragma: export
#include    "clockTree.h"                    // for KFREQUENCY_AHB3

// Connect the physical device to the logical manager
// --------------------------------------------------

#define model_flash_qspi_init                   stub_serialFlash_init
#define model_flash_qspi_readStatus             stub_serialFlash_readStatus
#define model_flash_qspi_initialise             stub_serialFlash_initialise
#define model_flash_qspi_read                   stub_serialFlash_read
#define model_flash_qspi_write                  stub_serialFlash_write
#define model_flash_qspi_ioctl                  stub_serialFlash_ioctl

#define QSPI                                    QUADSPI
#define KQSPI_SPEED                             50000000U
#define KQSPI_FREQUENCY                         KFREQUENCY_AHB3
#define KQSPI_READ_CHUNK                        1024U

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the qspi
 *
 */
static  void    cb_enable(void) {

    RCC->AHB3ENR |= RCC_AHB3ENR_QSPIEN;
}

#include    "model_flash_qspi.c_inc"
