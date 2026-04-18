/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Import the uKOS definition (specially mcu) to provide
 *           the file stm32u5xx.h.
 */

#pragma once

// For selecting Secure/NSecure

#ifdef SECURE_S
#define REG(x)                  (x ## _S)
#elif (defined(SECURE_NS))
#define REG(x)                  (x ## _NS)
#else
#define REG(x)                  (x ## _S)
#endif

#define SEC(x)                  (x ## _S)
#define NONSEC(x)               (x ## _NS)

#define __NOP()     __asm volatile ("nop")

#include    "core_reg.h"
#include    "soc_reg.h"
