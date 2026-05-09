/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:        Low level init for the uKOS-X Pico2_rp2350 RISC-V module.
 */

#pragma once

/*
 * \brief init_init
 *
 * - Initialise basic peripherals for RISC-V
 * - GPIO, clocks
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    init_init(void);

/*
 * \brief init_launchCore_1
 *
 * - Launch the core 1 using the RP2350 SIO FIFO mailbox protocol
 * - Sends {0, 0, 1, vtor, sp, pc} sequence and waits for echoes
 *
 */
extern  void    init_launchCore_1(void (*entry)(void));
