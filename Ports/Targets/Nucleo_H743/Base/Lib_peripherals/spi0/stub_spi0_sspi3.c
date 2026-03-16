/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_H743 – Connect the spi0 manager to the sspi3 device.
 */

#include    "clockTree.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                            "SPI3"
#define SPI                             SPI3
#define SPI_VECTOR_NUMBER               SPI3_C0_IRQn
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

    RCC->APB1LENR |= RCC_APB1LENR_SPI3EN;
}

#include    "model_spi.c_inc"
