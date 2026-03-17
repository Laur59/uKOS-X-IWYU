/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub_i2c3_si2c6.
; ================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     stub for the connection of the "i2c3" manager to the si2c6 device.
;
;-----
;------------------------------------------------------------------------
*/

#include    "clockTree.h"
#include    "macros_core.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                    "I2C6"
#define I2C                     REG(I2C6)
#define I2C_VECTOR_NUMBER       I2C6_EV_C0_IRQn
#define I2C_FREQUENCY           KFREQUENCY_APB1

#define model_i2c_init          stub_i2c3_init
#define model_i2c_configure     stub_i2c3_configure
#define model_i2c_write         stub_i2c3_write
#define model_i2c_read          stub_i2c3_read

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    REG(RCC)->APB1ENR2 |= RCC_APB1ENR2_I2C6EN;
}

#include    "model_i2c.c_inc"
