/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileContributor: Florence Lorenzin
 *
 * Goal:     ST STTS22H equates.
 */

#pragma once

// I2c interface

#define KI2C_ADD_STTS22H                    0x3FU                           // I2C STTS22H address

#define KSTTS22H_SCALING                    100U                            // Scaling of 100-lsb / Deg

// Registers

#define STTS22H_WHO_AM_I                    0x01U                           // Register WHOAMI
#define STTS22H_TEMP_H_LIMIT                0x02U                           // Register of the input for the high threshold decoder
#define STTS22H_TEMP_L_LIMIT                0x03U                           // Register of the input for the high threshold decoder
#define STTS22H_CNTRL                       0x04U                           // Register of control
#define STTS22H_STATUS                      0x05U                           // Register of status
#define STTS22H_TEMP_L                      0x06U                           // Register L of the temperature
#define STTS22H_TEMP_H                      0x07U                           // Register H of the temperature

// Control register

#define ONE_SHOT                            0U                              // New one-shot temperature acquisition is executed
#define TIME_OUT_DIS                        1U                              // Timeout function of SMBus is disabled
#define FREERUN                             2U                              // Enables freerun mode
#define IF_ADD_INC                          3U                              // Automatic address increment is enabled
#define AVG                                 4U                              // Sampling
#define AVG25HZ                             0U                              // Sampling 25-Hz
#define AVG50HZ                             1U                              // Sampling 50-Hz
#define AVG100HZ                            2U                              // Sampling 100-Hz
#define AVG200HZ                            3U                              // Sampling 200-Hz
#define BDU                                 6U                              // If BDU is used, TEMP_L_OUT must be read first)
#define LOW_ODR_START                       7U                              // Enables 1 Hz ODR operating mode

// Status register

#define BUSY                                1U                              // The conversion is in progress
#define OVER_THH                            2U                              // High limit temperature exceeded
#define OVER_THL                            3U                              // Low limit temperature exceeded
