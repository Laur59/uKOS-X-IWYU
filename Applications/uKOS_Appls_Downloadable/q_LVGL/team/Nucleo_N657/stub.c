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

#include    "Registers/stm32N657_gpioe.h"
#include    "../../ulvgl.h"
#include    "macros_core.h"
#include    "spi/spi.h"
#include    "spi_common.h"

#define BLCD_CS         9U              // LCD CS
#define BLCD_DC         10U             // LCD Data/Command
#define BLCD_RST        11U             // LCD Reset

// Macros for controlling the LCD controller ST7789VW

#define CMD_PARAMETER_00(commmande)                                                                 \
                                                                                                    \
    do {                                                                                            \
        local_LCD_WriteCommand(commmande);                                                          \
    } while (0)

#define CMD_PARAMETER_01(commmande, d1)                                                             \
                                                                                                    \
    do {                                                                                            \
        local_LCD_WriteCommand(commmande);                                                          \
        local_LCD_WriteData(d1);                                                                    \
    } while (0)

#define CMD_PARAMETER_02(commmande, d1, d2)                                                         \
                                                                                                    \
    do {                                                                                            \
        local_LCD_WriteCommand(commmande);                                                          \
        local_LCD_WriteData(d1);                                                                    \
        local_LCD_WriteData(d2);                                                                    \
    } while (0)

#define CMD_PARAMETER_04(commmande, d1, d2, d3, d4)                                                 \
                                                                                                    \
    do {                                                                                            \
        local_LCD_WriteCommand(commmande);                                                          \
        local_LCD_WriteData(d1);                                                                    \
        local_LCD_WriteData(d2);                                                                    \
        local_LCD_WriteData(d3);                                                                    \
        local_LCD_WriteData(d4);                                                                    \
    } while (0)

#define CMD_PARAMETER_05(commmande, d1, d2, d3, d4, d5)                                             \
                                                                                                    \
    do {                                                                                            \
        local_LCD_WriteCommand(commmande);                                                          \
        local_LCD_WriteData(d1);                                                                    \
        local_LCD_WriteData(d2);                                                                    \
        local_LCD_WriteData(d3);                                                                    \
        local_LCD_WriteData(d4);                                                                    \
        local_LCD_WriteData(d5);                                                                    \
    } while (0)

#define CMD_PARAMETER_14(commmande, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14)    \
                                                                                                    \
    do {                                                                                            \
        local_LCD_WriteCommand(commmande);                                                          \
        local_LCD_WriteData(d1);                                                                    \
        local_LCD_WriteData(d2);                                                                    \
        local_LCD_WriteData(d3);                                                                    \
        local_LCD_WriteData(d4);                                                                    \
        local_LCD_WriteData(d5);                                                                    \
        local_LCD_WriteData(d6);                                                                    \
        local_LCD_WriteData(d7);                                                                    \
        local_LCD_WriteData(d8);                                                                    \
        local_LCD_WriteData(d9);                                                                    \
        local_LCD_WriteData(d10);                                                                   \
        local_LCD_WriteData(d11);                                                                   \
        local_LCD_WriteData(d12);                                                                   \
        local_LCD_WriteData(d13);                                                                   \
        local_LCD_WriteData(d14);                                                                   \
    } while (0)

// Prototypes

static  void    local_LCD_Init(void);
static  void    local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y);
static  void    local_LCD_WriteCommand(uint8_t command);
static  void    local_LCD_WriteData(uint8_t data);

/*
 * \brief stub_LCD_On
 *
 * - Initialise the LCD & the SPI
 *
 */
void    stub_LCD_On(void) {

// The ST7789VW accept a Tscycw (in write) of 16-ns

    const   spiCnf_t    configure = {
                                .oSpeed    = 62500000U,
                                .oMode     = (uint8_t)KSPI_MASTER,
                                .oClock    = 0U
                            };

    PRIVILEGE_ELEVATE;

// Reset the LCD

    REG(GPIOE)->ODR |= ((1U<<BLCD_CS) | (1U<<BLCD_DC) | (1U<<BLCD_RST));
    kern_suspendProcess(200U);
    REG(GPIOE)->ODR &= (uint32_t)~(1U<<BLCD_RST);
    kern_suspendProcess(200U);
    REG(GPIOE)->ODR |= (1U<<BLCD_RST);
    kern_suspendProcess(200U);

// Initialise the SPI & the LCD

    spi_configure(KSPI0, &configure);
    kern_suspendProcess(200U);

    local_LCD_Init();

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
    local_LCD_WriteCommand(0x2CU);

// Effective transfer area size (n)

    n = (uint32_t)(w * h * 2);

    REG(GPIOE)->ODR &= (uint32_t)~(1U<<BLCD_CS);

// Split in chunk transfers

    while(sent < n) {
        chunk = n - sent;
        if(chunk > 65535U) { chunk = 65535U; }

        spi_multipleWriteRead(KSPI0, &pixelMapping[sent], (uint16_t)chunk, nullptr, 0U, KWAIT_INFINITY);
        sent += chunk;
    }

    REG(GPIOE)->ODR |= (1U<<BLCD_CS);

    lv_display_flush_ready(lv_display);
    PRIVILEGE_RESTORE;
}

// Local routines
// ==============

/*
 * \brief local_LCD_Init
 *
 * - Initialise the LCD
 * - This table is provided by the Waveshare
 *
 */
static  void    local_LCD_Init(void) {

// MADCTL (36h): Memory Data Access Control
// Bottom to Top, Left to Right, Reverse Mode, LCD Refresh Top to Bottom
// RGB, LCD Refresh Left to Right

    CMD_PARAMETER_01(0x36U, 0xA0U);

// COLMOD (3Ah): Interface Pixel Format
// ‘101’ = 16bit/pixel

    CMD_PARAMETER_01(0x3AU, 0x05U);

// INVON (21h): Display Inversion On

    CMD_PARAMETER_00(0x21U);

// CASET (2Ah): Column Address Set
// start: 0001, end: 0063

    CMD_PARAMETER_04(0x2AU, 0x00U, 0x01, 0x00U, 0x3FU);

// RASET (2Bh): Row Address Set
// start: 0000, end: 0239

    CMD_PARAMETER_04(0x2BU, 0x00U, 0x00U, 0x00U, 0xEFU);

// PORCTRL (B2h): Porch Setting
// 0Ch/0Ch/00h/33h/33h (default)

    CMD_PARAMETER_05(0xB2U, 0x0CU, 0x0C, 0x00U, 0x33U, 0x33U);

// GCTRL (B7h): Gate Control
// VGHS = 13.26-V, VGLS = -10.43-V

    CMD_PARAMETER_01(0xB7U, 0x35U);

// VCOMS (BBh): VCOM Setting
// Vcom = 0.875-V

    CMD_PARAMETER_01(0xBBU, 0x1FU);

// LCMCTRL (C0h): LCM Control
// ----

    CMD_PARAMETER_01(0xC0U, 0x2CU);

// VDVVRHEN (C2h): VDV and VRH Command Enable
// 01h/FFh (default)

    CMD_PARAMETER_02(0xC2U, 0x01U, 0xFFU);

// VRHS (C3h): VRH Set
// VAP = 4.45-V +( vcom+vcom offset+vdv)

    CMD_PARAMETER_01(0xC3U, 0x12U);

// RAMCTRL (B0h): RAM Control
// MCU, Little Endian

    CMD_PARAMETER_02(0xB0U, 0x00U, 0xF8);

// VDVS (C4h): VDV Set
// 20h (default)

    CMD_PARAMETER_01(0xC4U, 0x20U);

// FRCTRL2 (C6h): Frame Rate Control in Normal Mode
// FR = 60-Hz

    CMD_PARAMETER_01(0xC6U, 0x0FU);

// PWCTRL1 (D0h): Power Control 1
// A4h/A1h (default)

    CMD_PARAMETER_02(0xD0U, 0xA4U, 0xA1U);

// PVGAMCTRL (E0h): Positive Voltage Gamma Control
// ----

    CMD_PARAMETER_14(0xE0U, 0xD0U, 0x08U, 0x11U, 0x08U, 0x0CU, 0x15U, 0x39U, 0x33U, 0x50U, 0x36U, 0x13U, 0x14U, 0x29U, 0x2DU);

// NVGAMCTRL (E1h): Negative Voltage Gamma Control
// ----

    CMD_PARAMETER_14(0xE1U, 0xD0U, 0x08U, 0x10U, 0x08U, 0x06U, 0x06U, 0x39U, 0x44U, 0x51U, 0x0BU, 0x16U, 0x14U, 0x2FU, 0x31U);

// INVON (21h): Display Inversion On

    CMD_PARAMETER_00(0x21U);

// SLPOUT (11h): Sleep Out

    CMD_PARAMETER_00(0x11U);

// DISPON (29h): Display On

    CMD_PARAMETER_00(0x29U);
}

/*
 * \brief local_LCD_SetWindow
 *
 * - Select the window region
 *
 */
static  void    local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y) {
    uint8_t     startMSB, startLSB;
    uint8_t     endMSB, endLSB;

// X

    startMSB = (uint8_t)((start_x>>8) & 0xFFU);
    startLSB = (uint8_t)(start_x & 0xFFU);
    endMSB   = (uint8_t)((end_x>>8) & 0xFFU);
    endLSB   = (uint8_t)(end_x & 0xFFU);

    local_LCD_WriteCommand(0x2AU);
    local_LCD_WriteData(startMSB);
    local_LCD_WriteData(startLSB);
    local_LCD_WriteData(endMSB);
    local_LCD_WriteData(endLSB);

// Y

    startMSB = (uint8_t)((start_y>>8) & 0xFFU);
    startLSB = (uint8_t)(start_y & 0xFFU);
    endMSB   = (uint8_t)((end_y>>8) & 0xFFU);
    endLSB   = (uint8_t)(end_y & 0xFFU);

    local_LCD_WriteCommand(0x2BU);
    local_LCD_WriteData(startMSB);
    local_LCD_WriteData(startLSB);
    local_LCD_WriteData(endMSB);
    local_LCD_WriteData(endLSB);
}

/*
 * \brief local_LCD_WriteCommand
 *
 * - Write a command
 *
 */
static  void    local_LCD_WriteCommand(uint8_t command) {
    uint8_t     rwData = command;

    REG(GPIOE)->ODR &= (uint32_t)~(1U<<BLCD_DC);
    REG(GPIOE)->ODR &= (uint32_t)~(1U<<BLCD_CS);

    spi_writeRead(KSPI0, &rwData);
    REG(GPIOE)->ODR |= (1U<<BLCD_CS);
    REG(GPIOE)->ODR |= (1U<<BLCD_DC);
}

/*
 * \brief local_LCD_WriteData
 *
 * - Write a data
 *
 */
static  void    local_LCD_WriteData(uint8_t data) {
    uint8_t     rwData = data;

    REG(GPIOE)->ODR |=            (1U<<BLCD_DC);
    REG(GPIOE)->ODR &= (uint32_t)~(1U<<BLCD_CS);

    spi_writeRead(KSPI0, &rwData);
    REG(GPIOE)->ODR |= (1U<<BLCD_CS);
}
