/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    stub for the connection of the "ble0" manager to the "urt2" manager.
 */

#include    "urt2/urt2.h"       // IWYU pragma: keep for urt2
#include    "ble0/ble0.h"       // IWYU pragma: keep for ble0

#define DEVICE_IN   ble0
#define DEVICE_OUT  urt2

#include    "model_uart_swap.c_inc"
