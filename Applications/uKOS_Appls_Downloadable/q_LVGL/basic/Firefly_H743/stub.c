/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Firefly_H743 – Connect the basic LVGL demo to the WKS43WV067 LTDC display.
 */

#include    "stub.h"

#include    <stdint.h>
#include    <string.h>

#include    "ulvgl.h"
#include    "board.h"
#include    "kern/kern.h"
#include    "kern/kern_types.h"
#include    "lcd_display.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "macros_soc.h"
#include    "os_errors.h"
#include    "ui.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

extern  uint32_t                    linker_stLCD_F_BUFFER[];
#define FB_ADDR                     linker_stLCD_F_BUFFER
#define LCD_TFT                     LTDC

// Set the layer 1 and the number of bytes per lane
// The demo draws a KLCD_WIDTH x KLCD_HEIGHT image; the model centres
// the layer inside the LCD_W x LCD_H panel

#define L1_W                        KLCD_WIDTH
#define L1_H                        KLCD_HEIGHT
#define L1_NB_BYTES_LINE            4U

static_assert((L1_W <= LCD_W) && (L1_H <= LCD_H), "The layer 1 does not fit in the panel");

// Color of the panel around the layer 1
//                                    RRGGBB
#define KBACKGROUND                 0x00000000U

// Prototypes
// Defined by the model included at the end of this file; the static
// declaration keeps it local to the stub

static  void    model_lcd_tft_rgb8888_init(uint32_t rgb8888);

/*
 * \brief stub_LCD_On
 *
 * - Initialise the LTDC & turn-on the LCD
 *
 */
void    stub_LCD_On(void) {

    model_lcd_tft_rgb8888_init(KBACKGROUND);
}

/*
 * \brief stub_LCD_flush_cb
 *
 * - Callback for flushing an image in the LCD display
 *
 */
void    stub_LCD_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping) {
    uint8_t     *frameBuffer = (uint8_t *)FB_ADDR;
    int32_t     w = area->x2 - area->x1 + 1;
    int32_t     h = area->y2 - area->y1 + 1;
    int32_t     line, x, y;
    uint8_t     *src, *dst;

    for (line = 0; line < h; line++) {
        y = area->y1 + line;
        x = area->x1;

        src = &pixelMapping[(size_t)line * (size_t)w * L1_NB_BYTES_LINE];
        dst = &frameBuffer[((size_t)y * (size_t)L1_W + (size_t)x) * L1_NB_BYTES_LINE];

        memcpy(dst, src, (size_t)w * L1_NB_BYTES_LINE);
    }

    lv_display_flush_ready(lv_display);
}

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(uint32_t rgb8888) {
                uint32_t    i, pixel;
    volatile    uint32_t    *p = (volatile uint32_t *)FB_ADDR;

    RCC->APB3ENR   |= RCC_APB3ENR_LTDCEN;
    RCC->APB3LPENR |= RCC_APB3LPENR_LTDCLPEN;
    STRONG_BARRIER;

// STM32H743 LTDC kernel clock selection.
// PLL3_R as LTDC pixel clock source.
// For the timings of the panel, 800x480@60 Hz needs about:
// (800+48+88+40) * (480+3+32+13) * fps = 25-MHz:
// So, fps = 48.5
//
// See init.c pll3 initialisation

// Initialise the frame buffer

    pixel = rgb8888 & 0x00FFFFFFU;

    for (i = 0U; i < (L1_W * L1_H); i++) {
        p[i] = pixel;
    }
}

/*
 * \brief cb_powerLCD
 *
 * - Turn-on the LCD
 *
 */
static  void    cb_powerLCD(void) {

// Display powered
// Backlight on

    GPIOC->ODR |= (1U<<BLCD_POWER);
    kern_suspendProcess(100U);

    GPIOB->ODR |= (1U<<BBL_CTRL);
    kern_suspendProcess(100U);
}

#include    "model_lcd_tft_rgb8888.c_inc"
