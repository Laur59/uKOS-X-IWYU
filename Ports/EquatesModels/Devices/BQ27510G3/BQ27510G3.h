/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; BQ27510G3.
; ==========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     TI BQ27510G3 equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// I2c interface

#define KI2C_ADD_BQ27510G3                  0x55U                           // I2C BQ27510G3 address

// Registers & subcommands

#define BQ27510G3_CNTRL                     0x0001U                         // Control register
#define BQ27510G3_STATUS                    0x0000U                         // Reports the status of DF Checksum, Hibernate, IT, etc.
#define BQEN                                0U                              // Status bit indicating the bq27510 Qmax updates enabled. True when set
#define BVOK                                1U                              // Status bit indicating cell voltages are OK for Qmax updates. True when set
#define BRUP_DIS                            2U                              // Status bit indicating the bq27510 Ra table updates disabled. True when set
#define BLDMD                               3U                              // Status bit indicating the bq27510 Impedance TrackTM algorithm using constant-power mode. True when set. Default is 0 (constant-current mode)
#define BSLEEP                              4U                              // Status bit indicating the bq27510 is in SLEEP mode. True when set
#define BHYBERNATE                          6U                              // Status bit indicating a request for entry into HIBERNATE from SLEEP mode. True when set. Default is 0
#define BCA                                 10U                             // Status bit indicating the bq27510 board calibration routine is active. Active when set
#define BCCA                                11U                             // Status bit indicating the bq27510 coulomb counter calibration routine. Active when set
#define BCSV                                12U                             // Status bit indicating a valid data flash checksum has been generated. Active when set
#define BSS                                 13U                             // Status bit indicating the bq27510 is in the SEALED State. Active when set
#define BFAS                                14U                             // Status bit indicating the bq27510 is in FULL ACCESS SEALED state. Active when set

#define BQ27510G3_TYPE                      0x0001U                         // Reports the device type (bq27510)
#define BQ27510G3_VERSION                   0x0002U                         // Reports the firmware version on the device type
#define BQ27510G3_MAC_WRITE                 0x0007U                         // Returns previous MAC command code
#define BQ27510G3_ID                        0x0008U                         // Reports the chemical identifier of the Impedance TrackTM configuration
#define BQ27510G3_CMD                       0x000CU                         // Requests the fuel gauge to take an OCV measurement
#define BQ27510G3_INSERT                    0x000DU                         // Forces Flags( ) [BAT_DET] bit set when OpConfig B [BIE] = 0
#define BQ27510G3_REMOVE                    0x000EU                         // Forces Flags( ) [BAT_DET] bit clear when OpConfig B [BIE] = 0
#define BQ27510G3_SET_HIBERNATE             0x0011U                         // Forces CONTROL_STATUS [HIBERNATE] to 1
#define BQ27510G3_CLR_HIBERNATE             0x0012U                         // Forces CONTROL_STATUS [HIBERNATE] to 0
#define BQ27510G3_SUB_SEALED                0x0020U                         // Places the bq27510 in SEALED access mode
#define BQ27510G3_SUB_ENABLE                0x0021U                         // Enables the Impedance TrackTM algorithm
#define BQ27510G3_SUB_RESET                 0x0041U                         // Forces a full reset of the bq27510

#define BQ27510G3_TRATE                     0x0203U                         //
#define BQ27510G3_TRATE_TIME_TO_EMPTY       0x0405U                         //
#define BQ27510G3_TEMPERATURE               0x0607U                         //
#define BQ27510G3_VOLTAGE                   0x0809U                         //
#define BQ27510G3_FLAGS                     0x0A0BU                         //
#define BDSG                                0U                              // Flag bit indicating discharging detected. True when set
#define BSOCF                               1U                              // Flag bit indicating state-of-Charge-Threshold Final (SOCF Set %) reached. True when set
#define BSOC1                               2U                              // Flag bit indicating state-of-Charge-Threshold 1 (SOC1 Set) reached. True when set
#define BBAT_DET                            3U                              // Flag bit indicating battery detected. True when set
#define BWAIT_ID                            4U                              // Flag bit indicating waiting to identify inserted battery. True when set
#define BOCV_GD                             5U                              // Flag bit indicating good OCV measurement taken. True when set.
#define BCHG                                8U                              // Flag bit indicating (fast) charging allowed. True when set
#define BFC                                 9U                              // Flag bit indicating full-charged condition reached. True when set
#define BXCHG                               10U                             // Flag bit indicating charge Suspend Alert (temp outside the range [Suspend Temperature Low, Suspend Temperature High]). True when set
#define BCHG_INH                            11U                             // Flag bit indicating charge Inhibit: unable to begin charging (temp outside the range [Charge Inhibit Temp Low, Charge Inhibit Temp High]). True when set
#define BOTD                                14U                             // Flag bit indicating over-Temperature in discharge condition is detected. True when set
#define BOC                                 15U                             // Flag bit indicating over-Temperature in charge condition is detected. True when set.

#define BQ27510G3_NOMI_AVAILABLE_CAPACITY   0x0C0DU                         //
#define BQ27510G3_FULL_AVAILABLE_CAPACITY   0x0E0FU                         //
#define BQ27510G3_REMAINING_CAPACITY        0x1011U                         //
#define BQ27510G3_FULL_CHARGE_CAPACITY      0x1213U                         //
#define BQ27510G3_AVERAGE_CURRENT           0x1415U                         //
#define BQ27510G3_TIME_TO_EMPTY             0x1617U                         //
#define BQ27510G3_STBANDBY_CURRENT          0x1819U                         //
#define BQ27510G3_STBANDBY_TIME_TO_EMPTY    0x1A1BU                         //
#define BQ27510G3_CYCLE_COUNT               0x1E1FU                         //
#define BQ27510G3_STATE_OF_CHARGE           0x2021U                         //
#define BQ27510G3_ISTANTANEOUS_CURRENT      0x2223U                         //
#define BQ27510G3_INTERNAL_TEMPERATURE      0x2829U                         //
#define BQ27510G3_DESIGN_CAPACITY           0x2E2FU                         //
#define BQ27510G3_FILTER_DRM                0x6C6DU                         //
