/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub_spi0_sspi2.
; ================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     stub for the connection of the "spi0" manager to the sspi2 device.
;
;-----
;------------------------------------------------------------------------
*/

#include    "clockTree.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                            "SPI2"
#define SPI                             SPI2
#define SPI_VECTOR_NUMBER               SPI2_C0_IRQn
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

    RCC->APB1LENR |= RCC_APB1LENR_SPI2EN;
}

#include    "model_spi.c_inc"
