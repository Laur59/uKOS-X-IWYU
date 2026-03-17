/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; MT9V03x.
; ========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Aptina MT9V03x imager equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// I2c interface

#define KI2C_ADD_MT9V03x                    0x48U                           // I2C Aptina address

// Imager generic

typedef struct  mt9v03x     mt9v03x_t;

struct mt9v03x {
            uint8_t     oRegNumber;                                         // Register number
            uint16_t    oValue;                                             // Value
};

// Max image size

#define KNB_ROWS                            480U                            // Max 480 rows
#define KNB_COLS                            752U                            // Max 752 cols

// Constant for the temperature
//
// T = (Ta + KMT9V03x_OFFSET_TEMP) x KMT9V03x_GAIN_TEMP

#define KMT9V03x_OFFSET_TEMP                (-26.9)                         // offset
#define KMT9V03x_GAIN_TEMP                  (10.88)                         // Gain

// Some imager registers

#define KMT9V03x_CTRL_REG                   0x07U                           // Aptina Control Register Address
#define KMT9V03x_START_COL                  0x01U                           // ROI horizontal offset
#define KMT9V03x_START_ROW                  0x02U                           // ROI vertical offset
#define KMT9V03x_ROI_H                      0x03U                           // ROI height
#define KMT9V03x_ROI_W                      0x04U                           // ROI width
#define KMT9V03x_H_BLANK                    0x05U                           // Horizontal blank duration in number of pixels
#define KMT9V03x_V_BLANK                    0x06U                           // Vertical blank duration in number of lines
#define KMT9V03x_EXPOSURE                   0x0BU                           // Exposure Time
#define KMT9V03x_BINNING                    0x0DU                           // Binning control
#define KMT9V03x_ANALOG_GAIN                0x35U                           // Analog Gain
#define KMT9V03x_BLACK_LEVEL_CORRECTION     0x47U                           // Black level correction
#define KMT9V03x_V_BLACK_LEVEL              0x48U                           // VBlack value for correction
#define KMT9V03x_NOISE_ACTIVATION           0x70U                           // Noise correction activation
#define KMT9V03x_CONSTANT_NOISE             0x71U                           // Constant for noise correction
#define KMT9V03x_AUTOMATIC_EXPOSURE         0xAFU                           // Automatic exposure + gain control
#define KMT9V03x_TEMP                       0xC1U                           // I2C Aptina temperature register
#define KMT9V03x_FINE_EXPOSURE              0xD5U                           // Fine exposure tuning

// Reserved register (Aptina datasheet page 21)

#define KMT9V03x_REG20                      0x20U                           // Reserved
#define KMT9V03x_REG24                      0x24U                           // Reserved
#define KMT9V03x_REG2B                      0x2BU                           // Reserved
#define KMT9V03x_REG2F                      0x2FU                           // Reserved

// Reserved register (not documented)

#define KMT9V03x_PRODUCTION_N0              0x68U                           // Production number 0
#define KMT9V03x_PRODUCTION_N1              0x69U                           // Production number 1
#define KMT9V03x_PRODUCTION_N2              0x6AU                           // Production number 2
#define KMT9V03x_PRODUCTION_N3              0x6BU                           // Production number 3
