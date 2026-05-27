/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    stub for the connection of the "sdcard" manager with the SDMMC1 device.
 */

#include    <stdint.h>

#include    "clockTree.h"
#include    "sdcard/sdcard.h"
#include    "soc_reg.h"

#undef  WITH_SD_INSERTED_S

// Connect the physical device to the logical manager
// --------------------------------------------------

#define SDMMC                       SDMMC1
#define SDMMC_FREQUENCY             KFREQUENCY_PLL1Q

#define model_sdcard_init           stub_sdcard_init
#define model_sdcard_readStatus     stub_sdcard_readStatus
#define model_sdcard_initialise     stub_sdcard_initialise
#define model_sdcard_read           stub_sdcard_read
#define model_sdcard_write          stub_sdcard_write
#define model_sdcard_ioctl          stub_sdcard_ioctl

enum {
        KSDCARD_INIT = 0U,
};

// Model callbacks
// ---------------

/*
 * \brief cb_control
 *
 * - Control of the SDMMC interface
 *   - Initialise
 *
 */
static  void    cb_control([[maybe_unused]] uint8_t mode) {

    RCC->AHB3ENR |= RCC_AHB3ENR_SDMMC1EN;
}

#include    "model_sdcard_SDMMC.c_inc"
