/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Board mapping.
 */

#pragma once

#ifndef Asmodee_H747_S
#define Asmodee_H747_S
#endif

// GPIO settings
// -------------

#define KNB_LED             (8U + 3U)                           // Number of LEDs

// PORTs

#define BLED_0              9U                                  // PORT I 9, LED
#define BLED_1              10U                                 // PORT I 10, LED
#define BLED_2              13U                                 // PORT I 13, LED
#define BLED_3              14U                                 // PORT I 14, LED
#define BLED_4              15U                                 // PORT I 15, LED
#define BLED_5              13U                                 // PORT H 13, LED
#define BLED_6              6U                                  // PORT D 6, LED
#define BLED_7              2U                                  // PORT E 2, LED
#define BLED_RED            5U                                  // PORT K 5, LED Red
#define BLED_GREEN          6U                                  // PORT K 6, LED Green
#define BLED_BLUE           7U                                  // PORT K 7, LED Blue

#define BPUSH_0             0U                                  // PORT A 0, PUSH0

#define BSW_0               8U                                  // PORT B 8, SW0
#define BSW_1               14U                                 // PORT B 14, SW1
#define BSW_2               15U                                 // PORT B 15, SW2
#define BSW_3               2U                                  // PORT B 2, SW3

#define BLOGIC_0            15U                                 // PORT I 15, LOGIC0
#define BLOGIC_1            13U                                 // PORT H 13, LOGIC1
#define BRZ_CAMERA          7U                                  // PORT J 7, Camera reset
#define BEN_CLK             10U                                 // PORT J 10, Enable the Aptina clock
#define BSTANDBY            4U                                  // PORT D 4, Standby imager
#define BEXPOSURE           5U                                  // PORT D 5, Exposure imager

#define BSEL_MAGNETO        9U                                  // PORT B 9, /CS magnetometer
#define BSEL_ACCELERO       3U                                  // PORT G 3, /CS accelerometer/gyroscope
#define BDEN_AG             15U                                 // PORTC 15, BDEN_AG IMU
#define BINT_IMU            3U                                  // PORT E 3, /int IMU

#define BRZ_PHY             4U                                  // PORT J 4, Reset of the USB PHY
