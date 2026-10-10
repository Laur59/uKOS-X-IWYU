/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Splash process; draw the boot banner on the LCD display.
 */

#pragma once

#include    <stdint.h>

#include    "ulvgl.h"

// Display size

#define KLCD_BUF_LINES          10U                                         // Lines of the draw buffer (partial rendering)
#define KLCD_NB_BYTES_PIXEL     4U                                          // XRGB8888
#define KLCD_WIDTH              800U                                        // LCD width
#define KLCD_HEIGHT             480U                                        // LCD height

// Used colors
//                                RRGGBB
#define KBACKGROUND             0x00000000U                                 // Black
#define KFOREGROUND             0x00E0E0E0U                                 // Light grey

#if (defined(__cplusplus))
extern  "C" {
#endif

// Provided by the board stub
// stub_splash_on needs the privileged mode and has to be called by a process

extern  void    stub_splash_on(uint32_t rgb8888);
extern  void    stub_splash_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping);

#if (defined(__cplusplus))
}
#endif
