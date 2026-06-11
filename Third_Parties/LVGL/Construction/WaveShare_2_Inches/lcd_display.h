/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Equates for the lcd display
 */

#pragma once

// LCD controller commands

#define SLPOUT                      0x11U           //
#define INVON                       0x21U           //
#define DISPON                      0x29U           //
#define CASET                       0x2AU           //
#define RASET                       0x2BU           //
#define MADCTL                      0x36U           //
#define COLMOD                      0x3AU           //
#define RAMCTRL                     0xB0U           //
#define PORCTRL                     0xB2U           //
#define GCTRL                       0xB7U           //
#define VCOMS                       0xBBU           //
#define LCMCTRL                     0xC0U           //
#define VDVVRHEN                    0xC2U           //
#define VRHS                        0xC3U           //
#define VDVS                        0xC4U           //
#define FRCTRL2                     0xC6U           //
#define PWCTRL1                     0xD0U           //
#define PVGAMCTRL                   0xE0U           //
#define NVGAMCTRL                   0xE1U           //

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
