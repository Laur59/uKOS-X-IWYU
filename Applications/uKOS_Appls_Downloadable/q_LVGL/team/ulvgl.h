/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:    Wrapper for LVGL header file
 *          Suppress clang warnings.
 */

#if (defined(__clang__))
// Ignore the clang diagnostic
//
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#endif

#if (defined(__GNUC__))
// Ignore the GCC diagnostic
//
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif

#include    "lvgl.h"

#if (defined(__clang__))
// Restore the clang diagnostic
//
#pragma clang diagnostic pop
#endif

#if (defined(__GNUC__))
// Restore the GCC diagnostic
//
#pragma GCC diagnostic pop
#endif
