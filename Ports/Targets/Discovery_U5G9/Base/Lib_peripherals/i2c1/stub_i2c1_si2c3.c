/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "i2c1" manager to the si2c3 device.
 */

#include    "clockTree.h"
#include    "macros_core.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                    "I2C3"
#define I2C                     REG(I2C3)
#define I2C_VECTOR_NUMBER       I2C3_EV_C0_IRQn
#define I2C_FREQUENCY           KFREQUENCY_APB3

#define model_i2c_init          stub_i2c1_init
#define model_i2c_configure     stub_i2c1_configure
#define model_i2c_write         stub_i2c1_write
#define model_i2c_read          stub_i2c1_read

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    REG(RCC)->APB3ENR |= RCC_APB3ENR_I2C3EN;
}

#include    "model_i2c.c_inc"
