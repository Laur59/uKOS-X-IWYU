/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Contract between the basic LVGL application and its board specific stubs.
 */

#pragma once

#include    <stdint.h>

#include    "ulvgl.h"

// Provided by the board stub, used by the application

extern  void    stub_LCD_On(void);
extern  void    stub_LCD_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping);
