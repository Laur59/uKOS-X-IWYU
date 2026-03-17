/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub_serialFlash.
; =================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     stub for the connection of the "serialFlash" manager 1-Wire device by spi1 device.
;
;-----
;------------------------------------------------------------------------
*/

#include    <stdint.h>

#include    "MX25R6435/MX25R6435.h"
#include    "Registers/stm32H743_gpio.h"
#include    "board.h"
#include    "kern/kern.h"
#include    "shared_spi0/shared_spi0.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define model_flash_1w_init         stub_serialFlash_init
#define model_flash_1w_readStatus   stub_serialFlash_readStatus
#define model_flash_1w_initialise   stub_serialFlash_initialise
#define model_flash_1w_read         stub_serialFlash_read
#define model_flash_1w_write        stub_serialFlash_write
#define model_flash_1w_ioctl        stub_serialFlash_ioctl

enum {
        KFLASH_INIT = 0U,
        KFLASH_RESERVE_SPI,
        KFLASH_RELEASE_SPI,
        KFLASH_SELECT,
        KFLASH_DESELECT
};

// uKOS-X flash MX25R6435 structure
// --------------------------------

// Size of the flash MX25R6435 8-MB
// Size of the flash MX25R6435 sector 4096
// Number of sectors of the flash MX25R6435

#define KFLASH_SZ_MIN               KFLASH_SPI_SZ_FLASH
#define KFLASH_SZ_SECTOR            KFLASH_SPI_SZ_SECTOR
#define KFLASH_NB_SECORS            (KFLASH_SZ_MIN / KFLASH_SZ_SECTOR)

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
            RESERVE_SHARED_SPI0(KFLASH);
            break;
        }
        case KFLASH_RELEASE_SPI: {
            RELEASE_SHARED_SPI0;
            break;
        }
        case KFLASH_SELECT: {
            shared_spi0_select(KFLASH);
            break;
        }
        default:
        case KFLASH_DESELECT: {
            shared_spi0_deselect(KFLASH);
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

#include    "model_flash_1w_spi.c_inc"
