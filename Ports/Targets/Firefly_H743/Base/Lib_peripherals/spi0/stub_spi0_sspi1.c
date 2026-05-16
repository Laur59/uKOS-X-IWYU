/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        stub for the connection of the "spi0" manager to the sspi1 device.
 */

#include    "clockTree.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                            "SPI1"
#define SPI                             SPI1
#define SPI_VECTOR_NUMBER               SPI1_C0_IRQn
#define SPI_FREQUENCY                   KFREQUENCY_PLL1Q

#define model_spi_init                  stub_spi0_init
#define model_spi_configure             stub_spi0_configure
#define model_spi_multipleWriteRead     stub_spi0_multipleWriteRead

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
}

#include    "model_spi.c_inc"
