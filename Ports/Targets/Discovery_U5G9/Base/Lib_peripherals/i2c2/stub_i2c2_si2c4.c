/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "i2c2" manager to the si2c4 device.
 */

#include    "clockTree.h"
#include    "macros_core.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                    "I2C4"
#define I2C                     REG(I2C4)
#define I2C_VECTOR_NUMBER       I2C4_EV_C0_IRQn
#define I2C_FREQUENCY           KFREQUENCY_APB1

#define model_i2c_init          stub_i2c2_init
#define model_i2c_configure     stub_i2c2_configure
#define model_i2c_write         stub_i2c2_write
#define model_i2c_read          stub_i2c2_read

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    REG(RCC)->APB1ENR2 |= RCC_APB1ENR2_I2C4EN;
}

#include    "model_i2c.c_inc"
