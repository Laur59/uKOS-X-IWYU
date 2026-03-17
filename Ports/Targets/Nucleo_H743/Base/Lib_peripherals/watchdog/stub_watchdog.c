/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_H743 – Connect the watchdog manager to the watchdog device.
 */

// Connect the physical device to the logical manager
// --------------------------------------------------

#define model_watchdog_arm  stub_watchdog_arm

#include    "model_watchdog.c_inc"
