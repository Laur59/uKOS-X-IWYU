/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     ST LIS2DW12 accelerometer equates.
 */

#pragma once

// Accelerometer registers

#define LIS2DW12_OUT_TEMP_L                 0x0DU                           //
#define LIS2DW12_OUT_TEMP_H                 0x0EU                           //
#define LIS2DW12_WHO_AM_I                   0x0FU                           //
#define LIS2DW12_CTRL1                      0x20U                           //
#define LIS2DW12_CTRL2                      0x21U                           //
#define LIS2DW12_CTRL3                      0x22U                           //
#define LIS2DW12_CTRL4                      0x23U                           //
#define LIS2DW12_CTRL5                      0x24U                           //
#define LIS2DW12_CTRL6                      0x25U                           //
#define LIS2DW12_OUT_T                      0x26U                           //
#define LIS2DW12_STATUS                     0x27U                           //
#define LIS2DW12_OUT_X_L                    0x28U                           //
#define LIS2DW12_OUT_X_H                    0x29U                           //
#define LIS2DW12_OUT_Y_L                    0x2AU                           //
#define LIS2DW12_OUT_Y_H                    0x2BU                           //
#define LIS2DW12_OUT_Z_L                    0x2CU                           //
#define LIS2DW12_OUT_Z_H                    0x2DU                           //
#define LIS2DW12_FIFO_CTRL                  0x2EU                           //
#define LIS2DW12_FIFO_SAMPLES               0x2FU                           //
#define LIS2DW12_TAP_THS_X                  0x30U                           //
#define LIS2DW12_TAP_THS_Y                  0x31U                           //
#define LIS2DW12_TAP_THS_Z                  0x32U                           //
#define LIS2DW12_INT_DUR                    0x33U                           //
#define LIS2DW12_WAKE_UP_THS                0x34U                           //
#define LIS2DW12_WAKE_UP_DUR                0x35U                           //
#define LIS2DW12_FREE_FALL                  0x36U                           //
#define LIS2DW12_STATUS_DUP                 0x37U                           //
#define LIS2DW12_WAKE_UP_SRC                0x38U                           //
#define LIS2DW12_TAP_SRC                    0x39U                           //
#define LIS2DW12_SIXD_SRC                   0x3AU                           //
#define LIS2DW12_ALL_INT_SRC                0x3BU                           //
#define LIS2DW12_X_OFS_USR                  0x3CU                           //
#define LIS2DW12_Y_OFS_USR                  0x3DU                           //
#define LIS2DW12_Z_OFS_USR                  0x3EU                           //
#define LIS2DW12_CTRL7                      0x3FU                           //
