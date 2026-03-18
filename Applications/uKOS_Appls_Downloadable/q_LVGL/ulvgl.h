/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Wrapper for LVGL header file: Suppress clang warnings.
 */

#ifdef  __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#endif

#include    "lvgl.h"

#ifdef  __clang__
#pragma clang diagnostic pop
#endif
