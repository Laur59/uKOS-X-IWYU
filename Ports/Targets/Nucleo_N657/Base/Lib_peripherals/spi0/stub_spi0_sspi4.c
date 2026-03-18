/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "spi0" manager to the sspi4 device.
 */

#include    "clockTree.h"
#include    "macros_core.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                            "SPI4"
#define SPI                             REG(SPI4)
#define SPI_VECTOR_NUMBER               SPI4_IRQn
#define SPI_FREQUENCY                   KFREQUENCY_APB2

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

    REG(RCC)->APB2ENR   |= RCC_APB2ENR_SPI4EN;
    REG(RCC)->APB2LPENR |= RCC_APB2LPENR_SPI4LPEN;
}

#include    "model_spi.c_inc"
