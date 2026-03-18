/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "spi1" manager to the sspi4 device.
 */

#include    "clockTree.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                            "SPI4"
#define SPI                             SPI4
#define SPI_VECTOR_NUMBER               SPI4_C0_IRQn
#define SPI_FREQUENCY                   KFREQUENCY_APB2

#define model_spi_init                  stub_spi1_init
#define model_spi_configure             stub_spi1_configure
#define model_spi_multipleWriteRead     stub_spi1_multipleWriteRead

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;
}

#include    "model_spi.c_inc"
