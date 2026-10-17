/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * STM32H7x3 – Register equates of the peripherals the STM32H753 adds to the
 * STM32H743 (CRYP and HASH).
 *
 * Included explicitly by the code that drives them; soc_reg.h holds what both
 * parts have. Empty unless STM32H753_S is defined.
 */

#pragma once

#if defined(STM32H753_S)
#include    "Registers/stm32H753_cryp.h"    // IWYU pragma: export
#include    "Registers/stm32H753_hash.h"    // IWYU pragma: export
#endif
