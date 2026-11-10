/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal: stub for the connection of the "sdnand" manager with the SDMMC2 device.
 */

#include    <stdint.h>

#include    "Registers/stm32H7x7_CM7_rcc.h"
#include    "clockTree.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define SDMMC                       SDMMC2
#define SDMMC_FREQUENCY             KFREQUENCY_PLL1Q

#define model_sdnand_init           stub_sdnand_init
#define model_sdnand_initialise     stub_sdnand_initialise
#define model_sdnand_isPresent      stub_sdnand_isPresent
#define model_sdnand_read           stub_sdnand_read
#define model_sdnand_write          stub_sdnand_write
#define model_sdnand_ioctl          stub_sdnand_ioctl

enum {
        KSDNAND_INIT = 0U,
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

    RCC->AHB2ENR |= RCC_AHB2ENR_SDMMC2EN;
}

#include    "model_sdnand_SDMMC.c_inc"
