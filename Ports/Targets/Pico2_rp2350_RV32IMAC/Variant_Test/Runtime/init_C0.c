/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Core-0 GPIO and pad initialisation.
 *
 *          !!! This code HAS not to contain static data.
 *          !!! It is called before to copy and to initialise
 *          !!! the variable into the RAM.
 */

#include    <stdint.h>

#include    "board.h"
#include    "macros_core.h"
#include    "soc_reg.h"

/*
 * \brief init_C0_init
 *
 * - Release IO_BANK0 and PADS_BANK0 from reset
 * - Configure GPIO pins for the system and user LEDs
 * - Mux GPIO16/17 to UART0 TX/RX (core 0 serial console)
 * - Mux GPIO4/5   to UART1 TX/RX (core 1 serial console)
 *
 * \note This function does not return a value (None).
 *
 */
void    init_C0_init(void) {

    // Release IO_BANK0 and PADS_BANK0 from reset
    REG(RESETS)->RESET &= ~(RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0);
    while ((REG(RESETS)->RESET_DONE & (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0)) !=
           (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0)) { }

// LED outputs — clear ISO bit, set to SIO function, enable output

    REG(PADS_BANK0)->GPIO11 &= ~PADS_BANK0_GPIO11_ISO;
    REG(PADS_BANK0)->GPIO12 &= ~PADS_BANK0_GPIO12_ISO;
    REG(PADS_BANK0)->GPIO13 &= ~PADS_BANK0_GPIO13_ISO;
    REG(PADS_BANK0)->GPIO25 &= ~PADS_BANK0_GPIO25_ISO;

    REG(IO_BANK0)->GPIO11_CTRL = IO_BANK0_GPIO11_CTRL_FUNCSEL_SIOB_PROC_11;
    REG(IO_BANK0)->GPIO12_CTRL = IO_BANK0_GPIO12_CTRL_FUNCSEL_SIOB_PROC_12;
    REG(IO_BANK0)->GPIO13_CTRL = IO_BANK0_GPIO13_CTRL_FUNCSEL_SIOB_PROC_13;
    REG(IO_BANK0)->GPIO25_CTRL = IO_BANK0_GPIO25_CTRL_FUNCSEL_SIOB_PROC_25;

    REG(SIO)->GPIO_OE_SET = (1u << BLED_s) | (1u << BLED_0) | (1u << BLED_1) | (1u << BLED_2);

// UART0: GPIO16 (TX) output, GPIO17 (RX) input with Schmitt trigger

    REG(PADS_BANK0)->GPIO16    = PADS_BANK0_GPIO16_SCHMITT;
    REG(PADS_BANK0)->GPIO17    = PADS_BANK0_GPIO17_IE | PADS_BANK0_GPIO17_SCHMITT;
    REG(IO_BANK0)->GPIO16_CTRL = IO_BANK0_GPIO16_CTRL_FUNCSEL_UART0_TX;
    REG(IO_BANK0)->GPIO17_CTRL = IO_BANK0_GPIO17_CTRL_FUNCSEL_UART0_RX;

// UART1: GPIO4 (TX) output, GPIO5 (RX) input with Schmitt trigger

    REG(PADS_BANK0)->GPIO4    = PADS_BANK0_GPIO4_SCHMITT;
    REG(PADS_BANK0)->GPIO5    = PADS_BANK0_GPIO5_IE | PADS_BANK0_GPIO5_SCHMITT;
    REG(IO_BANK0)->GPIO4_CTRL = IO_BANK0_GPIO4_CTRL_FUNCSEL_UART1_TX;
    REG(IO_BANK0)->GPIO5_CTRL = IO_BANK0_GPIO5_CTRL_FUNCSEL_UART1_RX;
}
