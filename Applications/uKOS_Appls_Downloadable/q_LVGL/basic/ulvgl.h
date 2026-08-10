/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Wrapper for LVGL header file: Suppress clang warnings.
 */

#pragma once

#ifdef  __clang__
// Ignore the clang diagnostic
//
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#endif

#ifdef __GNUC__
// Ignore the GCC diagnostic
//
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif

#include    "lvgl.h"

#ifdef __clang__
// Restore the clang diagnostic
//
#pragma clang diagnostic pop
#endif

#ifdef __GNUC__
// Restore the GCC diagnostic
//
#pragma GCC diagnostic pop
#endif
