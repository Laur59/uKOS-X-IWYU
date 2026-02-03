/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub.
; =====

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;   Demo of a C application.
;   Interface between the lvgl and the hardware.
;
;-----
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#include    <stdint.h>

#include    "kern/kern.h"
#include    "../../ulvgl.h"
#include    "macros_core.h"

// TFT controller commands

#define KNO_OPERATION               0x00U
#define KSOFTWARE_RESET             0x01U
#define KREAD_ID                    0x04U
#define KREAD_STATUS                0x09U
#define KREAD_POWER_MODE            0x0AU
#define KREAD_MADCTL                0x0BU
#define KREAD_PIXEL_FORMAT          0x0CU
#define KREAD_IMAGE_FORMAT          0x0DU
#define KREAD_SIGNAL_MODE           0x0EU
#define KREAD_SELT_DIAG_RESULT      0x0FU
#define KSLEEP_ON                   0x10U
#define KSLEEP_OFF                  0x11U
#define KPARTIAL_DISPALY_ON         0x12U
#define KNORMAL_DISPALY_ON          0x13U
#define KINVERSION_DISPALY_OFF      0x20U
#define KINVERSION_DISPALY_ON       0x21U
#define KGAMMA_SET                  0x26U
#define KDISPALY_OFF                0x28U
#define KDISPALY_ON                 0x29U
#define KHORIZONTAL_ADDRESS_SET     0x2AU
#define KVERTICAL_ADDRESS_SET       0x2BU
#define KMEMORY_WRITE               0x2CU
#define KCOLOR_SET                  0x2DU
#define KMEMORY_READ                0x2EU
#define KPARTIAL_AREA               0x30U
#define KVERTICAL_SCROL_DEFINE      0x33U
#define KTEAR_EFFECT_LINE_OFF       0x34U
#define KTEAR_EFFECT_LINE_ON        0x35U
#define KMEMORY_ACCESS_CTL          0x36U
#define KVERTICAL_SCROL_S_ADD       0x37U
#define KIDLE_MODE_OFF              0x38U
#define KIDLE_MODE_ON               0x39U
#define KPIXEL_FORMAT_SET           0x3AU
#define KWRITE_MEMORY_CONTINUE      0x3CU
#define KREAD_MEMORY_CONTINUE       0x3EU
#define KSET_TEAR_SCANLINE          0x44U
#define KGET_SCANLINE               0x45U
#define KWRITE_BRIGHTNESS           0x51U
#define KREAD_BRIGHTNESS            0x52U
#define KWRITE_CTRL_DISPALY         0x53U
#define KREAD_CTRL_DISPALY          0x54U
#define KWRITE_BRIGHTNESS_CTL       0x55U
#define KREAD_BRIGHTNESS_CTL        0x56U
#define KWRITE_MIN_BRIGHTNESS       0x5EU
#define KREAD_MIN_BRIGHTNESS        0x5FU
#define KREAD_ID1                   0xDAU
#define KREAD_ID2                   0xDBU
#define KREAD_ID3                   0xDCU
#define KRGB_IF_SIGNAL_CTL          0xB0U
#define KNORMAL_FRAME_CTL           0xB1U
#define KIDLE_FRAME_CTL             0xB2U
#define KPARTIAL_FRAME_CTL          0xB3U
#define KINVERSION_CTL              0xB4U
#define KBLANK_PORCH_CTL            0xB5U
#define KDISPALY_FUNCTION_CTL       0xB6U
#define KENTRY_MODE_SET             0xB7U
#define KBACKLIGHT_CTL1             0xB8U
#define KBACKLIGHT_CTL2             0xB9U
#define KBACKLIGHT_CTL3             0xBAU
#define KBACKLIGHT_CTL4             0xBBU
#define KBACKLIGHT_CTL5             0xBCU
#define KBACKLIGHT_CTL7             0xBEU
#define KBACKLIGHT_CTL8             0xBFU
#define KPOWER_CTL1                 0xC0U
#define KPOWER_CTL2                 0xC1U
#define KVCOM_CTL1                  0xC5U
#define KVCOM_CTL2                  0xC7U
#define KNV_MEMORY_WRITE            0xD0U
#define KNV_MEMORY_PROTECT_KEY      0xD1U
#define KNV_MEMORY_STATUS_READ      0xD2U
#define KREAD_ID4                   0xD3U
#define KPOSITIVE_GAMMA_CORRECT     0xE0U
#define KNEGATIVE_GAMMA_CORRECT     0xE1U
#define KDIGITAL_GAMMA_CTL1         0xE2U
#define KDIGITAL_GAMMA_CTL2         0xE3U
#define KINTERFACE_CTL              0xF6U

// LCD directions

#define KDIR_XY_RLUD                0x00U
#define KDIR_YX_RLUD                0x20U
#define KDIR_XY_LRUD                0x40U
#define KDIR_YX_LRUD                0x60U
#define KDIR_XY_RLDU                0x80U
#define KDIR_YX_RLDU                0xA0U
#define KDIR_XY_LRDU                0xC0U
#define KDIR_YX_LRDU                0xE0U
#define KDIR_XY_MASK                0x20U
#define KDIR_MASK                   0xE0U

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
 * - Callback for flushing an image in the LCD displa
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
