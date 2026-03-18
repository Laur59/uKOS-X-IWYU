/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "sdcard" manager with the spi1 device.
 */

#include    <stddef.h>
#include    <stdint.h>

#include    "board.h"
#include    "kern/kern.h"
#include    "soc_reg.h"
#include    "spi/spi.h"
#include    "spi_common.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define model_sdcard_init           stub_sdcard_init
#define model_sdcard_readStatus     stub_sdcard_readStatus
#define model_sdcard_initialise     stub_sdcard_initialise
#define model_sdcard_read           stub_sdcard_read
#define model_sdcard_write          stub_sdcard_write
#define model_sdcard_ioctl          stub_sdcard_ioctl

enum {
        KSDCARD_INIT = 0U,
        KSDCARD_RELEASE,
        KSDCARD_SELECT,
        KSDCARD_DESELECT
};

// Model callbacks
// ---------------

/*
 * \brief cb_control
 *
 * - Control of the SPI interface
 *   - Initialise
 *   - Reserve
 *   - Release
 *   - Select
 *   - Deselect
 *
 */
static  void    cb_control(uint8_t mode) {
    static  const   spiCnf_t    configure = {
                                    .oSpeed    = 400000U,
                                    .oMode     = (uint8_t)KSPI_MASTER,
                                    .oClock    = 0U
                                };

    switch (mode) {
        case KSDCARD_INIT: {
            GPIOE->ODR |= (1U<<BSEL_SDCARD);

// Master, POL = PHA = 0
// Speed accesses ~400-Kbit/s

            spi_configure(KSPI1, &configure);
            break;
        }
        case KSDCARD_RELEASE: {
            break;
        }
        case KSDCARD_SELECT: {
            GPIOE->ODR &= (uint32_t)~(1U<<BSEL_SDCARD);
            break;
        }
        case KSDCARD_DESELECT:
        default: {
            GPIOE->ODR |= (1U<<BSEL_SDCARD);
            break;
        }
    }
}

/*
 * \brief cb_speed
 *
 * - Control of the SPI speed
 *
 */
static  void    cb_speed(uint32_t speed) {
    static  spiCnf_t    configure = {
                            .oMode     = (uint8_t)KSPI_MASTER,
                            .oClock    = 0U,
                            .oSpeed    = 0U
                        };

    configure.oSpeed = speed;
    spi_configure(KSPI1, &configure);
}

/*
 * \brief cb_cardInserted
 *
 * - Verify if the sdcard is inserted
 *
 */
static  bool    cb_cardInserted(void) {

    return ((GPIOG->IDR & (1U<<BNO_SDCARD)) == 0U);
}

/*
 * \brief cb_writeRead
 *
 * - Write/Read on the SPI
 *
 */
static  uint8_t cb_writeRead(uint8_t data) {
    uint8_t     wRData;

    wRData = data;
    spi_writeRead(KSPI1, &wRData);
    return wRData;
}

/*
 * \brief cb_write
 *
 * - Write on the SPI
 *
 */
static  void    cb_write(const uint8_t *source, uint16_t size) {

    spi_multipleWriteRead(KSPI1, source, size, nullptr, 0U, KWAIT_INFINITY);
}

/*
 * \brief cb_readSPI
 *
 * - Read from the SPI
 *
 */
static  void    cb_readSPI(uint8_t *destination, uint16_t size) {

    spi_multipleWriteRead(KSPI1, nullptr, 0U, destination, size, KWAIT_INFINITY);
}

#include    "model_sdcard_spi.c_inc"
