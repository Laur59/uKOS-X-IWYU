/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Demo of a C application.
 * Interface between the lvgl and the hardware.
 */

#include    "stub.h"

#include    <stdint.h>

#include    "kern/kern.h"
#include    "ulvgl.h"
#include    "lcd_display.h"
#include    "macros_core.h"


// Prototypes

static  void        local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y);
extern  int32_t     tft0_init(void);
extern  int32_t     tft0_writeCommand(uint8_t command);
extern  int32_t     tft0_write8(const uint8_t *buffer, uint32_t szBuffer);
extern  int32_t     tft0_write16(const uint16_t *buffer, uint32_t szBuffer);

/*
 * \brief stub_LCD_On
 *
 * - Initialise the LCD & the TFT
 *
 */
void    stub_LCD_On(void) {
    uint8_t     data, direction;

    direction = KDIR_YX_LRUD;

    PRIVILEGE_ELEVATE;

// Soft reset
// Pixel format

    tft0_init();
    tft0_writeCommand(KSOFTWARE_RESET);
    kern_suspendProcess(100U);

    tft0_writeCommand(KSLEEP_OFF);
    kern_suspendProcess(100U);
    tft0_writeCommand(KPIXEL_FORMAT_SET);

// Direction

    data = 0x55U;
    tft0_write8(&data, 1U);
    tft0_writeCommand(KMEMORY_ACCESS_CTL);
    tft0_write8(&direction, 1U);
    kern_suspendProcess(100U);

// Display on

    tft0_writeCommand(KDISPALY_ON);
    PRIVILEGE_RESTORE;
}

/*
 * \brief stub_LCD_flush_cb
 *
 * - Callback for flushing an image in the LCD display
 *
 */
void    stub_LCD_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping) {
    int32_t     w = (area->x2 - area->x1 + 1);
    int32_t     h = (area->y2 - area->y1 + 1);
    uint32_t    n, chunk, sent = 0U;

    PRIVILEGE_ELEVATE;
    local_LCD_SetWindow((uint16_t)area->x1, (uint16_t)area->y1, (uint16_t)area->x2, (uint16_t)area->y2);
    tft0_writeCommand(KMEMORY_WRITE);

// Effective transfer area size (n)

    n = (uint32_t)(w * h);

// Split in chunk transfers

    while(sent < n) {
        chunk = n - sent;
        if(chunk > 65535U) { chunk = 65535U; }

        const   void    *p_aligned = __builtin_assume_aligned(pixelMapping, 2);
        tft0_write16((const uint16_t *)p_aligned, (uint16_t)chunk);
        sent += chunk;
    }

    lv_display_flush_ready(lv_display);
    PRIVILEGE_RESTORE;
}

// Local routines
// ==============

/*
 * \brief local_LCD_SetWindow
 *
 * - Select the window region
 *
 */
static  void    local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y) {
    uint8_t     data[4];

// X

    data[0] = (uint8_t)((start_x>>8) & 0xFFU);
    data[1] = (uint8_t)(start_x & 0xFFU);
    data[2] = (uint8_t)((end_x>>8) & 0xFFU);
    data[3] = (uint8_t)(end_x & 0xFFU);

    tft0_writeCommand(KHORIZONTAL_ADDRESS_SET);
    tft0_write8(&data[0], 4U);

// Y

    data[0] = (uint8_t)((start_y>>8) & 0xFFU);
    data[1] = (uint8_t)(start_y & 0xFFU);
    data[2] = (uint8_t)((end_y>>8) & 0xFFU);
    data[3] = (uint8_t)(end_y & 0xFFU);

    tft0_writeCommand(KVERTICAL_ADDRESS_SET);
    tft0_write8(&data[0], 4U);
}
