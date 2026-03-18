/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "i2c0" manager to the si2c2 device.
 */

#include    "clockTree.h"
#include    "soc_reg.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define UNIT                    "I2C2"
#define I2C                     I2C2
#define I2C_VECTOR_NUMBER       I2C2_EV_C0_IRQn
#define I2C_FREQUENCY           KFREQUENCY_APB1

#define model_i2c_init          stub_i2c0_init
#define model_i2c_configure     stub_i2c0_configure
#define model_i2c_write         stub_i2c0_write
#define model_i2c_read          stub_i2c0_read

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    RCC->APB1LENR |= RCC_APB1LENR_I2C2EN;
}

#include    "model_i2c.c_inc"
