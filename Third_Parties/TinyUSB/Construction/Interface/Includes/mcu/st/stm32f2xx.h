/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Import the uKOS definition (specially mcu) to provide
 *           the file stm32f2xx.h.
 */

#pragma once

#define __NOP()     __asm volatile ("nop")

#include    "core_reg.h"
#include    "soc_reg.h"
