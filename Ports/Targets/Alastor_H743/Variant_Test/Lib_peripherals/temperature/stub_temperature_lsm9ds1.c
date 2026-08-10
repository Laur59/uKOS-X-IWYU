/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "temperature" manager to the lsm9ds1
 *           via the spi2 device.
 */

#include    "temperature/temperature.h"

#include    <stdint.h>

#include    "LSM9DS1/LSM9DS1.h"
#include    "kern/kern.h"
#include    "shared_spi0/shared_spi0.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define model_lsM9ds1tmp_init   stub_temperature_init
#define model_lsM9ds1tmp_read   stub_temperature_read
#define model_lsM9ds1tmp_write  stub_temperature_write

enum {
        KTEMPERATURE_INIT = 0U,
        KTEMPERATURE_RESERVE,
        KTEMPERATURE_RELEASE,
};

// Prototypes

static  uint8_t local_writeReadSPI(uint8_t data);
static  void    cb_writeTemp(uint8_t address, const uint8_t *data, uint8_t number);
static  void    cb_readTemp(uint8_t address, uint8_t *data, uint8_t number);

// Model callbacks
// ---------------

/*
 * \brief cb_control
 *
 * - Control of the SPI
 *   - Initialise
 *   - Reserve
 *   - Release
 *
 */
static  void    cb_control(uint8_t mode) {
            uint8_t     data;
    static  bool        vInit = false;

    switch (mode) {
        case KTEMPERATURE_INIT: {
            if (!vInit) {

// Check if the LSM9DS1 was already initialised by the IMU

                data = 0x00U; cb_readTemp(LSM9DS1_CTRL_REG6_XL, &data, 1U);
                vInit = ((data & 0xE0U) != 0U);
                if (!vInit) {
                    vInit = true;

// Accelerometer, Gyro & Temperature
//    011 11 0 00     = 0x78 - ODR = 119-Hz, 2000-dps, cut-off = 14-Hz
//    0000 00 00      = 0x00 - OUT LPF1
//    00 00 0000      = 0x00 - No high pass
//    00 111 0 00     = 0x38 - Enable Gyro x, y, z axis
//    00 111 000      = 0x38 - Enable Accelerometer x, y, z axis
//    011 10 0 11     = 0x73 - ODR = 119-Hz, 4-g, anti-aliasing = 50-Hz
//    0 00 00 0 0 0   = 0x00 - No high resolution
//    0 0 1 1 0 1 0 0 = 0x34 - Int active low, Open Drain, 4 wire SPI, auto increment
//    0 0 0 0 0 1 1 0 = 0x04 - Disable i2c, FIFO enable
//    110 11111       = 0xDF - FIFO in continuous mode, max threshold

                    data = 0x78U; cb_writeTemp(LSM9DS1_CTRL_REG1_G,  &data, 1U);
                    data = 0x00U; cb_writeTemp(LSM9DS1_CTRL_REG2_G,  &data, 1U);
                    data = 0x00U; cb_writeTemp(LSM9DS1_CTRL_REG3_G,  &data, 1U);
                    data = 0x38U; cb_writeTemp(LSM9DS1_CTRL_REG4_G,  &data, 1U);
                    data = 0x38U; cb_writeTemp(LSM9DS1_CTRL_REG5_XL, &data, 1U);
                    data = 0x73U; cb_writeTemp(LSM9DS1_CTRL_REG6_XL, &data, 1U);
                    data = 0x00U; cb_writeTemp(LSM9DS1_CTRL_REG7_XL, &data, 1U);
                    data = 0x34U; cb_writeTemp(LSM9DS1_CTRL_REG8,    &data, 1U);
                    data = 0x06U; cb_writeTemp(LSM9DS1_CTRL_REG9,    &data, 1U);
                    data = 0xDFU; cb_writeTemp(LSM9DS1_FIFO_CTRL,    &data, 1U);
                    kern_waitAtLeast(10U);
                }
            }
            break;
        }
        case KTEMPERATURE_RESERVE: {
            RESERVE_SHARED_SPI0(KTEMPERATURE);
            break;
        }
        case KTEMPERATURE_RELEASE: {
            RELEASE_SHARED_SPI0;
            break;
        }
        default: {

// Make MISRA happy :-)

            break;
        }
    }
}

/*
 * \brief cb_writeTemp
 *
 * - Write the temperature
 *
 */
static  void    cb_writeTemp(uint8_t address, const uint8_t *data, uint8_t number) {
            uint8_t     i;
    const   uint8_t     *wkData = data;

// Write the register address
// Then, write 1..n data

    shared_spi0_select(KTEMPERATURE);
    local_writeReadSPI(address);
    for (i = 0U; i < number; i++) {
        local_writeReadSPI(*wkData);
        wkData++;
    }
    shared_spi0_deselect(KTEMPERATURE);
    kern_waitAtLeast(1U);
}

/*
 * \brief cb_readTemp
 *
 * - Read the temperature
 *
 */
static  void    cb_readTemp(uint8_t address, uint8_t *data, uint8_t number) {
    uint8_t     i, *wkData = data;

// Write the register address
// Then, Read 1..n data

    shared_spi0_select(KTEMPERATURE);
    local_writeReadSPI(0x80U | address);
    for (i = 0U; i < number; i++) {
        *wkData = local_writeReadSPI(0x00U);
        wkData++;
    }
    shared_spi0_deselect(KTEMPERATURE);
    kern_waitAtLeast(1);
}

// Local routines
// ==============

/*
 * \brief local_writeReadSPI
 *
 * - Write/Read on the SPI
 *
 */
static  uint8_t local_writeReadSPI(uint8_t data) {
    uint8_t     wRData;

    wRData = data;
    shared_spi0_writeRead(&wRData);
    return wRData;
}

#include    "model_lsm9ds1_tmp.c_inc"
