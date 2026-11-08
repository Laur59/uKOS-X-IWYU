/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "serialFlash" manager 1-Wire device by spi1 device.
 */

#include <stdint.h>

#include "MX25R6435/MX25R6435.h"         // IWYU pragma: export
#include "Registers/stm32H7x3_gpio.h"
#include "board.h"
#include "kern/kern.h"
#include "shared_spi0/shared_spi0.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define model_flash_spi_init        stub_flash_init
#define model_flash_spi_initialise  stub_flash_initialise
#define model_flash_spi_isPresent   stub_flash_isPresent
#define model_flash_spi_read        stub_flash_read
#define model_flash_spi_write       stub_flash_write
#define model_flash_spi_ioctl       stub_flash_ioctl

enum {
        KFLASH_INIT = 0U,
        KFLASH_RESERVE_SPI,
        KFLASH_RELEASE_SPI,
        KFLASH_SELECT,
        KFLASH_DESELECT,
};

// Model callbacks
// ---------------

/*
 * \brief cb_control
 *
 * - Control of the SPI interface
 *   - Initialise
 *   - Select
 *   - Deselect
 *
 */
static  void    cb_control(uint8_t mode) {

    switch (mode) {
        case KFLASH_INIT: {
            GPIOB->ODR |= (1U<<BSEL_FLASH);

            GPIOA->ODR |= (1U<<BRZ_FLASH);
            kern_suspendProcess(1U);
            GPIOA->ODR &= (uint32_t)~(1U<<BRZ_FLASH);
            kern_suspendProcess(1U);

            GPIOA->ODR |= (1U<<BRZ_FLASH);
            break;
        }
        case KFLASH_RESERVE_SPI: {
            RESERVE_SHARED_SPI0(KMEMORY);
            break;
        }
        case KFLASH_RELEASE_SPI: {
            RELEASE_SHARED_SPI0;
            break;
        }
        case KFLASH_SELECT: {
            shared_spi0_select(KMEMORY);
            break;
        }
        default:
        case KFLASH_DESELECT: {
            shared_spi0_deselect(KMEMORY);
            break;
        }
    }
}

/*
 * \brief cb_writeRead
 *
 * - Write / read
 *
 */
static  uint8_t     cb_writeRead(uint8_t data) {
    uint8_t     wRData;

    wRData = data;
    shared_spi0_writeRead(&wRData);
    return wRData;
}

#include "model_flash_spi.c_inc"
