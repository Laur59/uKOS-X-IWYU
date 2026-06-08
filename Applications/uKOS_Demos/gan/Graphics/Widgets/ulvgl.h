/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:        Wrapper for LVGL header file
 *          Suppress clang warnings.
 */

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"

#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif

#include "lvgl.h"

#ifdef __clang__
#pragma clang diagnostic pop

#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
