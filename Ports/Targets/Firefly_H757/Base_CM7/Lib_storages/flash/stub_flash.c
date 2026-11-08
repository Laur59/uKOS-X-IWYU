/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal: stub for the connection of the "serialFlash" manager device by qspi device.
 */

#include "Registers/stm32H7x7_CM7_quadspi.h"  // for QUADSPI
#include "Registers/stm32H7x7_CM7_rcc.h"
#include "W25Q128J/W25Q128J.h"            // IWYU pragma: keep (for the model_flash_qspi.c_inc)
#include "clockTree.h"                    // for KFREQUENCY_AHB3

// Connect the physical device to the logical manager
// --------------------------------------------------

#define model_flash_qspi_init           stub_flash_init
#define model_flash_qspi_initialise     stub_flash_initialise
#define model_flash_qspi_isPresent      stub_flash_isPresent
#define model_flash_qspi_read           stub_flash_read
#define model_flash_qspi_write          stub_flash_write
#define model_flash_qspi_ioctl          stub_flash_ioctl

#define QSPI                            QUADSPI
#define KQSPI_SPEED                     50000000u
#define KQSPI_FREQUENCY                 KFREQUENCY_AHB3
#define KQSPI_READ_CHUNK                1024u

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

#include "model_flash_qspi.c_inc"
