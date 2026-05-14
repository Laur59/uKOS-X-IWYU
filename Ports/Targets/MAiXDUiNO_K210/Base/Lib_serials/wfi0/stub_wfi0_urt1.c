/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     stub for the connection of the "wfi0" manager to the "urt1" manager.
 */

#include    <stdint.h>

#include    "types.h"
#include    "urt1/urt1.h"
#include    "wfi0/wfi0.h"

#define DEVICE_IN   wfi0
#define DEVICE_OUT  urt1

#include    "model_uart_swap.c_inc"
