/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_otp_data_raw equates.
 */

#pragma once

#include    <stdint.h>

// OTP_DATA_RAW address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    CHIPID0;
    volatile    uint32_t    CHIPID1;
    volatile    uint32_t    CHIPID2;
    volatile    uint32_t    CHIPID3;
    volatile    uint32_t    RANDID0;
    volatile    uint32_t    RANDID1;
    volatile    uint32_t    RANDID2;
    volatile    uint32_t    RANDID3;
    volatile    uint32_t    RANDID4;
    volatile    uint32_t    RANDID5;
    volatile    uint32_t    RANDID6;
    volatile    uint32_t    RANDID7;
    volatile    uint32_t    RESERVED0[4];
    volatile    uint32_t    ROSC_CALIB;
    volatile    uint32_t    LPOSC_CALIB;
    volatile    uint32_t    RESERVED1[6];
    volatile    uint32_t    NUM_GPIOS;
    volatile    uint32_t    RESERVED2[29];
    volatile    uint32_t    INFO_CRC0;
    volatile    uint32_t    INFO_CRC1;
    volatile    uint32_t    CRIT0;
    volatile    uint32_t    CRIT0_R1;
    volatile    uint32_t    CRIT0_R2;
    volatile    uint32_t    CRIT0_R3;
    volatile    uint32_t    CRIT0_R4;
    volatile    uint32_t    CRIT0_R5;
    volatile    uint32_t    CRIT0_R6;
    volatile    uint32_t    CRIT0_R7;
    volatile    uint32_t    CRIT1;
    volatile    uint32_t    CRIT1_R1;
    volatile    uint32_t    CRIT1_R2;
    volatile    uint32_t    CRIT1_R3;
    volatile    uint32_t    CRIT1_R4;
    volatile    uint32_t    CRIT1_R5;
    volatile    uint32_t    CRIT1_R6;
    volatile    uint32_t    CRIT1_R7;
    volatile    uint32_t    BOOT_FLAGS0;
    volatile    uint32_t    BOOT_FLAGS0_R1;
    volatile    uint32_t    BOOT_FLAGS0_R2;
    volatile    uint32_t    BOOT_FLAGS1;
    volatile    uint32_t    BOOT_FLAGS1_R1;
    volatile    uint32_t    BOOT_FLAGS1_R2;
    volatile    uint32_t    DEFAULT_BOOT_VERSION0;
    volatile    uint32_t    DEFAULT_BOOT_VERSION0_R1;
    volatile    uint32_t    DEFAULT_BOOT_VERSION0_R2;
    volatile    uint32_t    DEFAULT_BOOT_VERSION1;
    volatile    uint32_t    DEFAULT_BOOT_VERSION1_R1;
    volatile    uint32_t    DEFAULT_BOOT_VERSION1_R2;
    volatile    uint32_t    FLASH_DEVINFO;
    volatile    uint32_t    FLASH_PARTITION_SLOT_SIZE;
    volatile    uint32_t    BOOTSEL_LED_CFG;
    volatile    uint32_t    BOOTSEL_PLL_CFG;
    volatile    uint32_t    BOOTSEL_XOSC_CFG;
    volatile    uint32_t    USB_BOOT_FLAGS;
    volatile    uint32_t    USB_BOOT_FLAGS_R1;
    volatile    uint32_t    USB_BOOT_FLAGS_R2;
    volatile    uint32_t    USB_WHITE_LABEL_ADDR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    OTPBOOT_SRC;
    volatile    uint32_t    OTPBOOT_LEN;
    volatile    uint32_t    OTPBOOT_DST0;
    volatile    uint32_t    OTPBOOT_DST1;
    volatile    uint32_t    RESERVED4[30];
    volatile    uint32_t    BOOTKEY0_0;
    volatile    uint32_t    BOOTKEY0_1;
    volatile    uint32_t    BOOTKEY0_2;
    volatile    uint32_t    BOOTKEY0_3;
    volatile    uint32_t    BOOTKEY0_4;
    volatile    uint32_t    BOOTKEY0_5;
    volatile    uint32_t    BOOTKEY0_6;
    volatile    uint32_t    BOOTKEY0_7;
    volatile    uint32_t    BOOTKEY0_8;
    volatile    uint32_t    BOOTKEY0_9;
    volatile    uint32_t    BOOTKEY0_10;
    volatile    uint32_t    BOOTKEY0_11;
    volatile    uint32_t    BOOTKEY0_12;
    volatile    uint32_t    BOOTKEY0_13;
    volatile    uint32_t    BOOTKEY0_14;
    volatile    uint32_t    BOOTKEY0_15;
    volatile    uint32_t    BOOTKEY1_0;
    volatile    uint32_t    BOOTKEY1_1;
    volatile    uint32_t    BOOTKEY1_2;
    volatile    uint32_t    BOOTKEY1_3;
    volatile    uint32_t    BOOTKEY1_4;
    volatile    uint32_t    BOOTKEY1_5;
    volatile    uint32_t    BOOTKEY1_6;
    volatile    uint32_t    BOOTKEY1_7;
    volatile    uint32_t    BOOTKEY1_8;
    volatile    uint32_t    BOOTKEY1_9;
    volatile    uint32_t    BOOTKEY1_10;
    volatile    uint32_t    BOOTKEY1_11;
    volatile    uint32_t    BOOTKEY1_12;
    volatile    uint32_t    BOOTKEY1_13;
    volatile    uint32_t    BOOTKEY1_14;
    volatile    uint32_t    BOOTKEY1_15;
    volatile    uint32_t    BOOTKEY2_0;
    volatile    uint32_t    BOOTKEY2_1;
    volatile    uint32_t    BOOTKEY2_2;
    volatile    uint32_t    BOOTKEY2_3;
    volatile    uint32_t    BOOTKEY2_4;
    volatile    uint32_t    BOOTKEY2_5;
    volatile    uint32_t    BOOTKEY2_6;
    volatile    uint32_t    BOOTKEY2_7;
    volatile    uint32_t    BOOTKEY2_8;
    volatile    uint32_t    BOOTKEY2_9;
    volatile    uint32_t    BOOTKEY2_10;
    volatile    uint32_t    BOOTKEY2_11;
    volatile    uint32_t    BOOTKEY2_12;
    volatile    uint32_t    BOOTKEY2_13;
    volatile    uint32_t    BOOTKEY2_14;
    volatile    uint32_t    BOOTKEY2_15;
    volatile    uint32_t    BOOTKEY3_0;
    volatile    uint32_t    BOOTKEY3_1;
    volatile    uint32_t    BOOTKEY3_2;
    volatile    uint32_t    BOOTKEY3_3;
    volatile    uint32_t    BOOTKEY3_4;
    volatile    uint32_t    BOOTKEY3_5;
    volatile    uint32_t    BOOTKEY3_6;
    volatile    uint32_t    BOOTKEY3_7;
    volatile    uint32_t    BOOTKEY3_8;
    volatile    uint32_t    BOOTKEY3_9;
    volatile    uint32_t    BOOTKEY3_10;
    volatile    uint32_t    BOOTKEY3_11;
    volatile    uint32_t    BOOTKEY3_12;
    volatile    uint32_t    BOOTKEY3_13;
    volatile    uint32_t    BOOTKEY3_14;
    volatile    uint32_t    BOOTKEY3_15;
    volatile    uint32_t    RESERVED5[3720];
    volatile    uint32_t    KEY1_0;
    volatile    uint32_t    KEY1_1;
    volatile    uint32_t    KEY1_2;
    volatile    uint32_t    KEY1_3;
    volatile    uint32_t    KEY1_4;
    volatile    uint32_t    KEY1_5;
    volatile    uint32_t    KEY1_6;
    volatile    uint32_t    KEY1_7;
    volatile    uint32_t    KEY2_0;
    volatile    uint32_t    KEY2_1;
    volatile    uint32_t    KEY2_2;
    volatile    uint32_t    KEY2_3;
    volatile    uint32_t    KEY2_4;
    volatile    uint32_t    KEY2_5;
    volatile    uint32_t    KEY2_6;
    volatile    uint32_t    KEY2_7;
    volatile    uint32_t    KEY3_0;
    volatile    uint32_t    KEY3_1;
    volatile    uint32_t    KEY3_2;
    volatile    uint32_t    KEY3_3;
    volatile    uint32_t    KEY3_4;
    volatile    uint32_t    KEY3_5;
    volatile    uint32_t    KEY3_6;
    volatile    uint32_t    KEY3_7;
    volatile    uint32_t    KEY4_0;
    volatile    uint32_t    KEY4_1;
    volatile    uint32_t    KEY4_2;
    volatile    uint32_t    KEY4_3;
    volatile    uint32_t    KEY4_4;
    volatile    uint32_t    KEY4_5;
    volatile    uint32_t    KEY4_6;
    volatile    uint32_t    KEY4_7;
    volatile    uint32_t    KEY5_0;
    volatile    uint32_t    KEY5_1;
    volatile    uint32_t    KEY5_2;
    volatile    uint32_t    KEY5_3;
    volatile    uint32_t    KEY5_4;
    volatile    uint32_t    KEY5_5;
    volatile    uint32_t    KEY5_6;
    volatile    uint32_t    KEY5_7;
    volatile    uint32_t    KEY6_0;
    volatile    uint32_t    KEY6_1;
    volatile    uint32_t    KEY6_2;
    volatile    uint32_t    KEY6_3;
    volatile    uint32_t    KEY6_4;
    volatile    uint32_t    KEY6_5;
    volatile    uint32_t    KEY6_6;
    volatile    uint32_t    KEY6_7;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    KEY1_VALID;
    volatile    uint32_t    KEY2_VALID;
    volatile    uint32_t    KEY3_VALID;
    volatile    uint32_t    KEY4_VALID;
    volatile    uint32_t    KEY5_VALID;
    volatile    uint32_t    KEY6_VALID;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    PAGE0_LOCK0;
    volatile    uint32_t    PAGE0_LOCK1;
    volatile    uint32_t    PAGE1_LOCK0;
    volatile    uint32_t    PAGE1_LOCK1;
    volatile    uint32_t    PAGE2_LOCK0;
    volatile    uint32_t    PAGE2_LOCK1;
    volatile    uint32_t    PAGE3_LOCK0;
    volatile    uint32_t    PAGE3_LOCK1;
    volatile    uint32_t    PAGE4_LOCK0;
    volatile    uint32_t    PAGE4_LOCK1;
    volatile    uint32_t    PAGE5_LOCK0;
    volatile    uint32_t    PAGE5_LOCK1;
    volatile    uint32_t    PAGE6_LOCK0;
    volatile    uint32_t    PAGE6_LOCK1;
    volatile    uint32_t    PAGE7_LOCK0;
    volatile    uint32_t    PAGE7_LOCK1;
    volatile    uint32_t    PAGE8_LOCK0;
    volatile    uint32_t    PAGE8_LOCK1;
    volatile    uint32_t    PAGE9_LOCK0;
    volatile    uint32_t    PAGE9_LOCK1;
    volatile    uint32_t    PAGE10_LOCK0;
    volatile    uint32_t    PAGE10_LOCK1;
    volatile    uint32_t    PAGE11_LOCK0;
    volatile    uint32_t    PAGE11_LOCK1;
    volatile    uint32_t    PAGE12_LOCK0;
    volatile    uint32_t    PAGE12_LOCK1;
    volatile    uint32_t    PAGE13_LOCK0;
    volatile    uint32_t    PAGE13_LOCK1;
    volatile    uint32_t    PAGE14_LOCK0;
    volatile    uint32_t    PAGE14_LOCK1;
    volatile    uint32_t    PAGE15_LOCK0;
    volatile    uint32_t    PAGE15_LOCK1;
    volatile    uint32_t    PAGE16_LOCK0;
    volatile    uint32_t    PAGE16_LOCK1;
    volatile    uint32_t    PAGE17_LOCK0;
    volatile    uint32_t    PAGE17_LOCK1;
    volatile    uint32_t    PAGE18_LOCK0;
    volatile    uint32_t    PAGE18_LOCK1;
    volatile    uint32_t    PAGE19_LOCK0;
    volatile    uint32_t    PAGE19_LOCK1;
    volatile    uint32_t    PAGE20_LOCK0;
    volatile    uint32_t    PAGE20_LOCK1;
    volatile    uint32_t    PAGE21_LOCK0;
    volatile    uint32_t    PAGE21_LOCK1;
    volatile    uint32_t    PAGE22_LOCK0;
    volatile    uint32_t    PAGE22_LOCK1;
    volatile    uint32_t    PAGE23_LOCK0;
    volatile    uint32_t    PAGE23_LOCK1;
    volatile    uint32_t    PAGE24_LOCK0;
    volatile    uint32_t    PAGE24_LOCK1;
    volatile    uint32_t    PAGE25_LOCK0;
    volatile    uint32_t    PAGE25_LOCK1;
    volatile    uint32_t    PAGE26_LOCK0;
    volatile    uint32_t    PAGE26_LOCK1;
    volatile    uint32_t    PAGE27_LOCK0;
    volatile    uint32_t    PAGE27_LOCK1;
    volatile    uint32_t    PAGE28_LOCK0;
    volatile    uint32_t    PAGE28_LOCK1;
    volatile    uint32_t    PAGE29_LOCK0;
    volatile    uint32_t    PAGE29_LOCK1;
    volatile    uint32_t    PAGE30_LOCK0;
    volatile    uint32_t    PAGE30_LOCK1;
    volatile    uint32_t    PAGE31_LOCK0;
    volatile    uint32_t    PAGE31_LOCK1;
    volatile    uint32_t    PAGE32_LOCK0;
    volatile    uint32_t    PAGE32_LOCK1;
    volatile    uint32_t    PAGE33_LOCK0;
    volatile    uint32_t    PAGE33_LOCK1;
    volatile    uint32_t    PAGE34_LOCK0;
    volatile    uint32_t    PAGE34_LOCK1;
    volatile    uint32_t    PAGE35_LOCK0;
    volatile    uint32_t    PAGE35_LOCK1;
    volatile    uint32_t    PAGE36_LOCK0;
    volatile    uint32_t    PAGE36_LOCK1;
    volatile    uint32_t    PAGE37_LOCK0;
    volatile    uint32_t    PAGE37_LOCK1;
    volatile    uint32_t    PAGE38_LOCK0;
    volatile    uint32_t    PAGE38_LOCK1;
    volatile    uint32_t    PAGE39_LOCK0;
    volatile    uint32_t    PAGE39_LOCK1;
    volatile    uint32_t    PAGE40_LOCK0;
    volatile    uint32_t    PAGE40_LOCK1;
    volatile    uint32_t    PAGE41_LOCK0;
    volatile    uint32_t    PAGE41_LOCK1;
    volatile    uint32_t    PAGE42_LOCK0;
    volatile    uint32_t    PAGE42_LOCK1;
    volatile    uint32_t    PAGE43_LOCK0;
    volatile    uint32_t    PAGE43_LOCK1;
    volatile    uint32_t    PAGE44_LOCK0;
    volatile    uint32_t    PAGE44_LOCK1;
    volatile    uint32_t    PAGE45_LOCK0;
    volatile    uint32_t    PAGE45_LOCK1;
    volatile    uint32_t    PAGE46_LOCK0;
    volatile    uint32_t    PAGE46_LOCK1;
    volatile    uint32_t    PAGE47_LOCK0;
    volatile    uint32_t    PAGE47_LOCK1;
    volatile    uint32_t    PAGE48_LOCK0;
    volatile    uint32_t    PAGE48_LOCK1;
    volatile    uint32_t    PAGE49_LOCK0;
    volatile    uint32_t    PAGE49_LOCK1;
    volatile    uint32_t    PAGE50_LOCK0;
    volatile    uint32_t    PAGE50_LOCK1;
    volatile    uint32_t    PAGE51_LOCK0;
    volatile    uint32_t    PAGE51_LOCK1;
    volatile    uint32_t    PAGE52_LOCK0;
    volatile    uint32_t    PAGE52_LOCK1;
    volatile    uint32_t    PAGE53_LOCK0;
    volatile    uint32_t    PAGE53_LOCK1;
    volatile    uint32_t    PAGE54_LOCK0;
    volatile    uint32_t    PAGE54_LOCK1;
    volatile    uint32_t    PAGE55_LOCK0;
    volatile    uint32_t    PAGE55_LOCK1;
    volatile    uint32_t    PAGE56_LOCK0;
    volatile    uint32_t    PAGE56_LOCK1;
    volatile    uint32_t    PAGE57_LOCK0;
    volatile    uint32_t    PAGE57_LOCK1;
    volatile    uint32_t    PAGE58_LOCK0;
    volatile    uint32_t    PAGE58_LOCK1;
    volatile    uint32_t    PAGE59_LOCK0;
    volatile    uint32_t    PAGE59_LOCK1;
    volatile    uint32_t    PAGE60_LOCK0;
    volatile    uint32_t    PAGE60_LOCK1;
    volatile    uint32_t    PAGE61_LOCK0;
    volatile    uint32_t    PAGE61_LOCK1;
    volatile    uint32_t    PAGE62_LOCK0;
    volatile    uint32_t    PAGE62_LOCK1;
    volatile    uint32_t    PAGE63_LOCK0;
    volatile    uint32_t    PAGE63_LOCK1;
} OTP_DATA_RAW_TypeDef;

#ifdef __cplusplus
#define OTP_DATA_RAW_NS reinterpret_cast<OTP_DATA_RAW_TypeDef *>(0x40134000U)
#define OTP_DATA_RAW_S  reinterpret_cast<OTP_DATA_RAW_TypeDef *>(0x40134000U)
#else
#define OTP_DATA_RAW_NS ((OTP_DATA_RAW_TypeDef *)0x40134000U)
#define OTP_DATA_RAW_S  ((OTP_DATA_RAW_TypeDef *)0x40134000U)
#endif

// CHIPID0 Configuration

#define OTP_DATA_RAW_CHIPID0_CHIPID0                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_CHIPID0_CHIPID0_0                                                                          (0x1U<<0U)

// CHIPID1 Configuration

#define OTP_DATA_RAW_CHIPID1_CHIPID1                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_CHIPID1_CHIPID1_0                                                                          (0x1U<<0U)

// CHIPID2 Configuration

#define OTP_DATA_RAW_CHIPID2_CHIPID2                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_CHIPID2_CHIPID2_0                                                                          (0x1U<<0U)

// CHIPID3 Configuration

#define OTP_DATA_RAW_CHIPID3_CHIPID3                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_CHIPID3_CHIPID3_0                                                                          (0x1U<<0U)

// RANDID0 Configuration

#define OTP_DATA_RAW_RANDID0_RANDID0                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID0_RANDID0_0                                                                          (0x1U<<0U)

// RANDID1 Configuration

#define OTP_DATA_RAW_RANDID1_RANDID1                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID1_RANDID1_0                                                                          (0x1U<<0U)

// RANDID2 Configuration

#define OTP_DATA_RAW_RANDID2_RANDID2                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID2_RANDID2_0                                                                          (0x1U<<0U)

// RANDID3 Configuration

#define OTP_DATA_RAW_RANDID3_RANDID3                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID3_RANDID3_0                                                                          (0x1U<<0U)

// RANDID4 Configuration

#define OTP_DATA_RAW_RANDID4_RANDID4                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID4_RANDID4_0                                                                          (0x1U<<0U)

// RANDID5 Configuration

#define OTP_DATA_RAW_RANDID5_RANDID5                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID5_RANDID5_0                                                                          (0x1U<<0U)

// RANDID6 Configuration

#define OTP_DATA_RAW_RANDID6_RANDID6                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID6_RANDID6_0                                                                          (0x1U<<0U)

// RANDID7 Configuration

#define OTP_DATA_RAW_RANDID7_RANDID7                                                                            (0xFFFFU<<0U)
#define OTP_DATA_RAW_RANDID7_RANDID7_0                                                                          (0x1U<<0U)

// ROSC_CALIB Configuration

#define OTP_DATA_RAW_ROSC_CALIB_ROSC_CALIB                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_ROSC_CALIB_ROSC_CALIB_0                                                                    (0x1U<<0U)

// LPOSC_CALIB Configuration

#define OTP_DATA_RAW_LPOSC_CALIB_LPOSC_CALIB                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_LPOSC_CALIB_LPOSC_CALIB_0                                                                  (0x1U<<0U)

// NUM_GPIOS Configuration

#define OTP_DATA_RAW_NUM_GPIOS_NUM_GPIOS                                                                        (0xFFU<<0U)
#define OTP_DATA_RAW_NUM_GPIOS_NUM_GPIOS_0                                                                      (0x1U<<0U)

// INFO_CRC0 Configuration

#define OTP_DATA_RAW_INFO_CRC0_INFO_CRC0                                                                        (0xFFFFU<<0U)
#define OTP_DATA_RAW_INFO_CRC0_INFO_CRC0_0                                                                      (0x1U<<0U)

// INFO_CRC1 Configuration

#define OTP_DATA_RAW_INFO_CRC1_INFO_CRC1                                                                        (0xFFFFU<<0U)
#define OTP_DATA_RAW_INFO_CRC1_INFO_CRC1_0                                                                      (0x1U<<0U)

// CRIT0 Configuration

#define OTP_DATA_RAW_CRIT0_ARM_DISABLE                                                                          (0x1U<<0U)
#define OTP_DATA_RAW_CRIT0_RISCV_DISABLE                                                                        (0x1U<<1U)

// CRIT0_R1 Configuration

#define OTP_DATA_RAW_CRIT0_R1_CRIT0_R1                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT0_R1_CRIT0_R1_0                                                                        (0x1U<<0U)

// CRIT0_R2 Configuration

#define OTP_DATA_RAW_CRIT0_R2_CRIT0_R2                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT0_R2_CRIT0_R2_0                                                                        (0x1U<<0U)

// CRIT0_R3 Configuration

#define OTP_DATA_RAW_CRIT0_R3_CRIT0_R3                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT0_R3_CRIT0_R3_0                                                                        (0x1U<<0U)

// CRIT0_R4 Configuration

#define OTP_DATA_RAW_CRIT0_R4_CRIT0_R4                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT0_R4_CRIT0_R4_0                                                                        (0x1U<<0U)

// CRIT0_R5 Configuration

#define OTP_DATA_RAW_CRIT0_R5_CRIT0_R5                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT0_R5_CRIT0_R5_0                                                                        (0x1U<<0U)

// CRIT0_R6 Configuration

#define OTP_DATA_RAW_CRIT0_R6_CRIT0_R6                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT0_R6_CRIT0_R6_0                                                                        (0x1U<<0U)

// CRIT0_R7 Configuration

#define OTP_DATA_RAW_CRIT0_R7_CRIT0_R7                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT0_R7_CRIT0_R7_0                                                                        (0x1U<<0U)

// CRIT1 Configuration

#define OTP_DATA_RAW_CRIT1_SECURE_BOOT_ENABLE                                                                   (0x1U<<0U)
#define OTP_DATA_RAW_CRIT1_SECURE_DEBUG_DISABLE                                                                 (0x1U<<1U)
#define OTP_DATA_RAW_CRIT1_DEBUG_DISABLE                                                                        (0x1U<<2U)
#define OTP_DATA_RAW_CRIT1_BOOT_ARCH                                                                            (0x1U<<3U)
#define OTP_DATA_RAW_CRIT1_GLITCH_DETECTOR_ENABLE                                                               (0x1U<<4U)
#define OTP_DATA_RAW_CRIT1_GLITCH_DETECTOR_SENS                                                                 (0x3U<<5U)
#define OTP_DATA_RAW_CRIT1_GLITCH_DETECTOR_SENS_0                                                               (0x1U<<5U)

// CRIT1_R1 Configuration

#define OTP_DATA_RAW_CRIT1_R1_CRIT1_R1                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT1_R1_CRIT1_R1_0                                                                        (0x1U<<0U)

// CRIT1_R2 Configuration

#define OTP_DATA_RAW_CRIT1_R2_CRIT1_R2                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT1_R2_CRIT1_R2_0                                                                        (0x1U<<0U)

// CRIT1_R3 Configuration

#define OTP_DATA_RAW_CRIT1_R3_CRIT1_R3                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT1_R3_CRIT1_R3_0                                                                        (0x1U<<0U)

// CRIT1_R4 Configuration

#define OTP_DATA_RAW_CRIT1_R4_CRIT1_R4                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT1_R4_CRIT1_R4_0                                                                        (0x1U<<0U)

// CRIT1_R5 Configuration

#define OTP_DATA_RAW_CRIT1_R5_CRIT1_R5                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT1_R5_CRIT1_R5_0                                                                        (0x1U<<0U)

// CRIT1_R6 Configuration

#define OTP_DATA_RAW_CRIT1_R6_CRIT1_R6                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT1_R6_CRIT1_R6_0                                                                        (0x1U<<0U)

// CRIT1_R7 Configuration

#define OTP_DATA_RAW_CRIT1_R7_CRIT1_R7                                                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_CRIT1_R7_CRIT1_R7_0                                                                        (0x1U<<0U)

// BOOT_FLAGS0 Configuration

#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_BOOTSEL_EXEC2                                                          (0x1U<<0U)
#define OTP_DATA_RAW_BOOT_FLAGS0_ENABLE_BOOTSEL_LED                                                             (0x1U<<1U)
#define OTP_DATA_RAW_BOOT_FLAGS0_ENABLE_BOOTSEL_NON_DEFAULT_PLL_XOSC_CFG                                        (0x1U<<2U)
#define OTP_DATA_RAW_BOOT_FLAGS0_FLASH_IO_VOLTAGE_1V8                                                           (0x1U<<3U)
#define OTP_DATA_RAW_BOOT_FLAGS0_FAST_SIGCHECK_ROSC_DIV                                                         (0x1U<<4U)
#define OTP_DATA_RAW_BOOT_FLAGS0_FLASH_DEVINFO_ENABLE                                                           (0x1U<<5U)
#define OTP_DATA_RAW_BOOT_FLAGS0_OVERRIDE_FLASH_PARTITION_SLOT_SIZE                                             (0x1U<<6U)
#define OTP_DATA_RAW_BOOT_FLAGS0_SINGLE_FLASH_BINARY                                                            (0x1U<<7U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_AUTO_SWITCH_ARCH                                                       (0x1U<<8U)
#define OTP_DATA_RAW_BOOT_FLAGS0_SECURE_PARTITION_TABLE                                                         (0x1U<<9U)
#define OTP_DATA_RAW_BOOT_FLAGS0_HASHED_PARTITION_TABLE                                                         (0x1U<<10U)
#define OTP_DATA_RAW_BOOT_FLAGS0_ROLLBACK_REQUIRED                                                              (0x1U<<11U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_FLASH_BOOT                                                             (0x1U<<12U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_OTP_BOOT                                                               (0x1U<<13U)
#define OTP_DATA_RAW_BOOT_FLAGS0_ENABLE_OTP_BOOT                                                                (0x1U<<14U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_POWER_SCRATCH                                                          (0x1U<<15U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_WATCHDOG_SCRATCH                                                       (0x1U<<16U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_BOOTSEL_USB_MSD_IFC                                                    (0x1U<<17U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_BOOTSEL_USB_PICOBOOT_IFC                                               (0x1U<<18U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_BOOTSEL_UART_BOOT                                                      (0x1U<<19U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_XIP_ACCESS_ON_SRAM_ENTRY                                               (0x1U<<20U)
#define OTP_DATA_RAW_BOOT_FLAGS0_DISABLE_SRAM_WINDOW_BOOT                                                       (0x1U<<21U)

// BOOT_FLAGS0_R1 Configuration

#define OTP_DATA_RAW_BOOT_FLAGS0_R1_BOOT_FLAGS0_R1                                                              (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_BOOT_FLAGS0_R1_BOOT_FLAGS0_R1_0                                                            (0x1U<<0U)

// BOOT_FLAGS0_R2 Configuration

#define OTP_DATA_RAW_BOOT_FLAGS0_R2_BOOT_FLAGS0_R2                                                              (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_BOOT_FLAGS0_R2_BOOT_FLAGS0_R2_0                                                            (0x1U<<0U)

// BOOT_FLAGS1 Configuration

#define OTP_DATA_RAW_BOOT_FLAGS1_KEY_VALID                                                                      (0xFU<<0U)
#define OTP_DATA_RAW_BOOT_FLAGS1_KEY_VALID_0                                                                    (0x1U<<0U)
#define OTP_DATA_RAW_BOOT_FLAGS1_KEY_INVALID                                                                    (0xFU<<8U)
#define OTP_DATA_RAW_BOOT_FLAGS1_KEY_INVALID_0                                                                  (0x1U<<8U)
#define OTP_DATA_RAW_BOOT_FLAGS1_DOUBLE_TAP_DELAY                                                               (0x7U<<16U)
#define OTP_DATA_RAW_BOOT_FLAGS1_DOUBLE_TAP_DELAY_0                                                             (0x1U<<16U)
#define OTP_DATA_RAW_BOOT_FLAGS1_DOUBLE_TAP                                                                     (0x1U<<19U)

// BOOT_FLAGS1_R1 Configuration

#define OTP_DATA_RAW_BOOT_FLAGS1_R1_BOOT_FLAGS1_R1                                                              (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_BOOT_FLAGS1_R1_BOOT_FLAGS1_R1_0                                                            (0x1U<<0U)

// BOOT_FLAGS1_R2 Configuration

#define OTP_DATA_RAW_BOOT_FLAGS1_R2_BOOT_FLAGS1_R2                                                              (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_BOOT_FLAGS1_R2_BOOT_FLAGS1_R2_0                                                            (0x1U<<0U)

// DEFAULT_BOOT_VERSION0 Configuration

#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION0_DEFAULT_BOOT_VERSION0                                                (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION0_DEFAULT_BOOT_VERSION0_0                                              (0x1U<<0U)

// DEFAULT_BOOT_VERSION0_R1 Configuration

#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION0_R1_DEFAULT_BOOT_VERSION0_R1                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION0_R1_DEFAULT_BOOT_VERSION0_R1_0                                        (0x1U<<0U)

// DEFAULT_BOOT_VERSION0_R2 Configuration

#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION0_R2_DEFAULT_BOOT_VERSION0_R2                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION0_R2_DEFAULT_BOOT_VERSION0_R2_0                                        (0x1U<<0U)

// DEFAULT_BOOT_VERSION1 Configuration

#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION1_DEFAULT_BOOT_VERSION1                                                (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION1_DEFAULT_BOOT_VERSION1_0                                              (0x1U<<0U)

// DEFAULT_BOOT_VERSION1_R1 Configuration

#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION1_R1_DEFAULT_BOOT_VERSION1_R1                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION1_R1_DEFAULT_BOOT_VERSION1_R1_0                                        (0x1U<<0U)

// DEFAULT_BOOT_VERSION1_R2 Configuration

#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION1_R2_DEFAULT_BOOT_VERSION1_R2                                          (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_DEFAULT_BOOT_VERSION1_R2_DEFAULT_BOOT_VERSION1_R2_0                                        (0x1U<<0U)

// FLASH_DEVINFO Configuration

#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_GPIO                                                                     (0x3FU<<0U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_GPIO_0                                                                   (0x1U<<0U)
#define OTP_DATA_RAW_FLASH_DEVINFO_D8H_ERASE_SUPPORTED                                                          (0x1U<<7U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE                                                                     (0xFU<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_0                                                                   (0x1U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE                                                                     (0xFU<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_0                                                                   (0x1U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_NONE                                                                (0x0U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_8K                                                                  (0x1U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_16K                                                                 (0x2U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_32K                                                                 (0x3U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_64K                                                                 (0x4U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_128K                                                                (0x5U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_256K                                                                (0x6U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_512K                                                                (0x7U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_1M                                                                  (0x8U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_2M                                                                  (0x9U<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_4M                                                                  (0xAU<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_8M                                                                  (0xBU<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS0_SIZE_16M                                                                 (0xCU<<8U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_NONE                                                                (0x0U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_8K                                                                  (0x1U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_16K                                                                 (0x2U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_32K                                                                 (0x3U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_64K                                                                 (0x4U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_128K                                                                (0x5U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_256K                                                                (0x6U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_512K                                                                (0x7U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_1M                                                                  (0x8U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_2M                                                                  (0x9U<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_4M                                                                  (0xAU<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_8M                                                                  (0xBU<<12U)
#define OTP_DATA_RAW_FLASH_DEVINFO_CS1_SIZE_16M                                                                 (0xCU<<12U)

// FLASH_PARTITION_SLOT_SIZE Configuration

#define OTP_DATA_RAW_FLASH_PARTITION_SLOT_SIZE_FLASH_PARTITION_SLOT_SIZE                                        (0xFFFFU<<0U)
#define OTP_DATA_RAW_FLASH_PARTITION_SLOT_SIZE_FLASH_PARTITION_SLOT_SIZE_0                                      (0x1U<<0U)

// BOOTSEL_LED_CFG Configuration

#define OTP_DATA_RAW_BOOTSEL_LED_CFG_PIN                                                                        (0x3FU<<0U)
#define OTP_DATA_RAW_BOOTSEL_LED_CFG_PIN_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_BOOTSEL_LED_CFG_ACTIVELOW                                                                  (0x1U<<8U)

// BOOTSEL_PLL_CFG Configuration

#define OTP_DATA_RAW_BOOTSEL_PLL_CFG_FBDIV                                                                      (0x1FFU<<0U)
#define OTP_DATA_RAW_BOOTSEL_PLL_CFG_FBDIV_0                                                                    (0x1U<<0U)
#define OTP_DATA_RAW_BOOTSEL_PLL_CFG_POSTDIV1                                                                   (0x7U<<9U)
#define OTP_DATA_RAW_BOOTSEL_PLL_CFG_POSTDIV1_0                                                                 (0x1U<<9U)
#define OTP_DATA_RAW_BOOTSEL_PLL_CFG_POSTDIV2                                                                   (0x7U<<12U)
#define OTP_DATA_RAW_BOOTSEL_PLL_CFG_POSTDIV2_0                                                                 (0x1U<<12U)
#define OTP_DATA_RAW_BOOTSEL_PLL_CFG_REFDIV                                                                     (0x1U<<15U)

// BOOTSEL_XOSC_CFG Configuration

#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_STARTUP                                                                   (0x3FFFU<<0U)
#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_STARTUP_0                                                                 (0x1U<<0U)
#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_RANGE                                                                     (0x3U<<14U)
#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_RANGE_0                                                                   (0x1U<<14U)
#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_RANGE_1_15MHZ                                                             (0x0U<<14U)
#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_RANGE_10_30MHZ                                                            (0x1U<<14U)
#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_RANGE_25_60MHZ                                                            (0x2U<<14U)
#define OTP_DATA_RAW_BOOTSEL_XOSC_CFG_RANGE_40_100MHZ                                                           (0x3U<<14U)

// USB_BOOT_FLAGS Configuration

#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_DEVICE_VID_VALUE_VALID                                               (0x1U<<0U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_DEVICE_PID_VALUE_VALID                                               (0x1U<<1U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_DEVICE_SERIAL_NUMBER_VALUE_VALID                                     (0x1U<<2U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_DEVICE_LANG_ID_VALUE_VALID                                           (0x1U<<3U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_DEVICE_MANUFACTURER_STRDEF_VALID                                     (0x1U<<4U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_DEVICE_PRODUCT_STRDEF_VALID                                          (0x1U<<5U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_DEVICE_SERIAL_NUMBER_STRDEF_VALID                                    (0x1U<<6U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_USB_CONFIG_ATTRIBUTES_MAX_POWER_VALUES_VALID                             (0x1U<<7U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_VOLUME_LABEL_STRDEF_VALID                                                (0x1U<<8U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_SCSI_INQUIRY_VENDOR_STRDEF_VALID                                         (0x1U<<9U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_SCSI_INQUIRY_PRODUCT_STRDEF_VALID                                        (0x1U<<10U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_SCSI_INQUIRY_VERSION_STRDEF_VALID                                        (0x1U<<11U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_INDEX_HTM_REDIRECT_URL_STRDEF_VALID                                      (0x1U<<12U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_INDEX_HTM_REDIRECT_NAME_STRDEF_VALID                                     (0x1U<<13U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_INFO_UF2_TXT_MODEL_STRDEF_VALID                                          (0x1U<<14U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WL_INFO_UF2_TXT_BOARD_ID_STRDEF_VALID                                       (0x1U<<15U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_WHITE_LABEL_ADDR_VALID                                                      (0x1U<<22U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_DP_DM_SWAP                                                                  (0x1U<<23U)

// USB_BOOT_FLAGS_R1 Configuration

#define OTP_DATA_RAW_USB_BOOT_FLAGS_R1_USB_BOOT_FLAGS_R1                                                        (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_R1_USB_BOOT_FLAGS_R1_0                                                      (0x1U<<0U)

// USB_BOOT_FLAGS_R2 Configuration

#define OTP_DATA_RAW_USB_BOOT_FLAGS_R2_USB_BOOT_FLAGS_R2                                                        (0xFFFFFFU<<0U)
#define OTP_DATA_RAW_USB_BOOT_FLAGS_R2_USB_BOOT_FLAGS_R2_0                                                      (0x1U<<0U)

// USB_WHITE_LABEL_ADDR Configuration

#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR                                                  (0xFFFFU<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_0                                                (0x1U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_VID_VALUE                       (0x0U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_PID_VALUE                       (0x1U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_BCD_DEVICE_VALUE                (0x2U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_LANG_ID_VALUE                   (0x3U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_MANUFACTURER_STRDEF             (0x4U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_PRODUCT_STRDEF                  (0x5U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_SERIAL_NUMBER_STRDEF            (0x6U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_CONFIG_ATTRIBUTES_MAX_POWER_VALUES     (0x7U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_VOLUME_LABEL_STRDEF                        (0x8U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_SCSI_INQUIRY_VENDOR_STRDEF                 (0x9U<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_SCSI_INQUIRY_PRODUCT_STRDEF                (0xAU<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_SCSI_INQUIRY_VERSION_STRDEF                (0xBU<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INDEX_HTM_REDIRECT_URL_STRDEF              (0xCU<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INDEX_HTM_REDIRECT_NAME_STRDEF             (0xDU<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INFO_UF2_TXT_MODEL_STRDEF                  (0xEU<<0U)
#define OTP_DATA_RAW_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INFO_UF2_TXT_BOARD_ID_STRDEF               (0xFU<<0U)

// OTPBOOT_SRC Configuration

#define OTP_DATA_RAW_OTPBOOT_SRC_OTPBOOT_SRC                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_OTPBOOT_SRC_OTPBOOT_SRC_0                                                                  (0x1U<<0U)

// OTPBOOT_LEN Configuration

#define OTP_DATA_RAW_OTPBOOT_LEN_OTPBOOT_LEN                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_OTPBOOT_LEN_OTPBOOT_LEN_0                                                                  (0x1U<<0U)

// OTPBOOT_DST0 Configuration

#define OTP_DATA_RAW_OTPBOOT_DST0_OTPBOOT_DST0                                                                  (0xFFFFU<<0U)
#define OTP_DATA_RAW_OTPBOOT_DST0_OTPBOOT_DST0_0                                                                (0x1U<<0U)

// OTPBOOT_DST1 Configuration

#define OTP_DATA_RAW_OTPBOOT_DST1_OTPBOOT_DST1                                                                  (0xFFFFU<<0U)
#define OTP_DATA_RAW_OTPBOOT_DST1_OTPBOOT_DST1_0                                                                (0x1U<<0U)

// BOOTKEY0_0 Configuration

#define OTP_DATA_RAW_BOOTKEY0_0_BOOTKEY0_0                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_0_BOOTKEY0_0_0                                                                    (0x1U<<0U)

// BOOTKEY0_1 Configuration

#define OTP_DATA_RAW_BOOTKEY0_1_BOOTKEY0_1                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_1_BOOTKEY0_1_0                                                                    (0x1U<<0U)

// BOOTKEY0_2 Configuration

#define OTP_DATA_RAW_BOOTKEY0_2_BOOTKEY0_2                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_2_BOOTKEY0_2_0                                                                    (0x1U<<0U)

// BOOTKEY0_3 Configuration

#define OTP_DATA_RAW_BOOTKEY0_3_BOOTKEY0_3                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_3_BOOTKEY0_3_0                                                                    (0x1U<<0U)

// BOOTKEY0_4 Configuration

#define OTP_DATA_RAW_BOOTKEY0_4_BOOTKEY0_4                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_4_BOOTKEY0_4_0                                                                    (0x1U<<0U)

// BOOTKEY0_5 Configuration

#define OTP_DATA_RAW_BOOTKEY0_5_BOOTKEY0_5                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_5_BOOTKEY0_5_0                                                                    (0x1U<<0U)

// BOOTKEY0_6 Configuration

#define OTP_DATA_RAW_BOOTKEY0_6_BOOTKEY0_6                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_6_BOOTKEY0_6_0                                                                    (0x1U<<0U)

// BOOTKEY0_7 Configuration

#define OTP_DATA_RAW_BOOTKEY0_7_BOOTKEY0_7                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_7_BOOTKEY0_7_0                                                                    (0x1U<<0U)

// BOOTKEY0_8 Configuration

#define OTP_DATA_RAW_BOOTKEY0_8_BOOTKEY0_8                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_8_BOOTKEY0_8_0                                                                    (0x1U<<0U)

// BOOTKEY0_9 Configuration

#define OTP_DATA_RAW_BOOTKEY0_9_BOOTKEY0_9                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_9_BOOTKEY0_9_0                                                                    (0x1U<<0U)

// BOOTKEY0_10 Configuration

#define OTP_DATA_RAW_BOOTKEY0_10_BOOTKEY0_10                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_10_BOOTKEY0_10_0                                                                  (0x1U<<0U)

// BOOTKEY0_11 Configuration

#define OTP_DATA_RAW_BOOTKEY0_11_BOOTKEY0_11                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_11_BOOTKEY0_11_0                                                                  (0x1U<<0U)

// BOOTKEY0_12 Configuration

#define OTP_DATA_RAW_BOOTKEY0_12_BOOTKEY0_12                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_12_BOOTKEY0_12_0                                                                  (0x1U<<0U)

// BOOTKEY0_13 Configuration

#define OTP_DATA_RAW_BOOTKEY0_13_BOOTKEY0_13                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_13_BOOTKEY0_13_0                                                                  (0x1U<<0U)

// BOOTKEY0_14 Configuration

#define OTP_DATA_RAW_BOOTKEY0_14_BOOTKEY0_14                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_14_BOOTKEY0_14_0                                                                  (0x1U<<0U)

// BOOTKEY0_15 Configuration

#define OTP_DATA_RAW_BOOTKEY0_15_BOOTKEY0_15                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY0_15_BOOTKEY0_15_0                                                                  (0x1U<<0U)

// BOOTKEY1_0 Configuration

#define OTP_DATA_RAW_BOOTKEY1_0_BOOTKEY1_0                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_0_BOOTKEY1_0_0                                                                    (0x1U<<0U)

// BOOTKEY1_1 Configuration

#define OTP_DATA_RAW_BOOTKEY1_1_BOOTKEY1_1                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_1_BOOTKEY1_1_0                                                                    (0x1U<<0U)

// BOOTKEY1_2 Configuration

#define OTP_DATA_RAW_BOOTKEY1_2_BOOTKEY1_2                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_2_BOOTKEY1_2_0                                                                    (0x1U<<0U)

// BOOTKEY1_3 Configuration

#define OTP_DATA_RAW_BOOTKEY1_3_BOOTKEY1_3                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_3_BOOTKEY1_3_0                                                                    (0x1U<<0U)

// BOOTKEY1_4 Configuration

#define OTP_DATA_RAW_BOOTKEY1_4_BOOTKEY1_4                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_4_BOOTKEY1_4_0                                                                    (0x1U<<0U)

// BOOTKEY1_5 Configuration

#define OTP_DATA_RAW_BOOTKEY1_5_BOOTKEY1_5                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_5_BOOTKEY1_5_0                                                                    (0x1U<<0U)

// BOOTKEY1_6 Configuration

#define OTP_DATA_RAW_BOOTKEY1_6_BOOTKEY1_6                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_6_BOOTKEY1_6_0                                                                    (0x1U<<0U)

// BOOTKEY1_7 Configuration

#define OTP_DATA_RAW_BOOTKEY1_7_BOOTKEY1_7                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_7_BOOTKEY1_7_0                                                                    (0x1U<<0U)

// BOOTKEY1_8 Configuration

#define OTP_DATA_RAW_BOOTKEY1_8_BOOTKEY1_8                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_8_BOOTKEY1_8_0                                                                    (0x1U<<0U)

// BOOTKEY1_9 Configuration

#define OTP_DATA_RAW_BOOTKEY1_9_BOOTKEY1_9                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_9_BOOTKEY1_9_0                                                                    (0x1U<<0U)

// BOOTKEY1_10 Configuration

#define OTP_DATA_RAW_BOOTKEY1_10_BOOTKEY1_10                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_10_BOOTKEY1_10_0                                                                  (0x1U<<0U)

// BOOTKEY1_11 Configuration

#define OTP_DATA_RAW_BOOTKEY1_11_BOOTKEY1_11                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_11_BOOTKEY1_11_0                                                                  (0x1U<<0U)

// BOOTKEY1_12 Configuration

#define OTP_DATA_RAW_BOOTKEY1_12_BOOTKEY1_12                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_12_BOOTKEY1_12_0                                                                  (0x1U<<0U)

// BOOTKEY1_13 Configuration

#define OTP_DATA_RAW_BOOTKEY1_13_BOOTKEY1_13                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_13_BOOTKEY1_13_0                                                                  (0x1U<<0U)

// BOOTKEY1_14 Configuration

#define OTP_DATA_RAW_BOOTKEY1_14_BOOTKEY1_14                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_14_BOOTKEY1_14_0                                                                  (0x1U<<0U)

// BOOTKEY1_15 Configuration

#define OTP_DATA_RAW_BOOTKEY1_15_BOOTKEY1_15                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY1_15_BOOTKEY1_15_0                                                                  (0x1U<<0U)

// BOOTKEY2_0 Configuration

#define OTP_DATA_RAW_BOOTKEY2_0_BOOTKEY2_0                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_0_BOOTKEY2_0_0                                                                    (0x1U<<0U)

// BOOTKEY2_1 Configuration

#define OTP_DATA_RAW_BOOTKEY2_1_BOOTKEY2_1                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_1_BOOTKEY2_1_0                                                                    (0x1U<<0U)

// BOOTKEY2_2 Configuration

#define OTP_DATA_RAW_BOOTKEY2_2_BOOTKEY2_2                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_2_BOOTKEY2_2_0                                                                    (0x1U<<0U)

// BOOTKEY2_3 Configuration

#define OTP_DATA_RAW_BOOTKEY2_3_BOOTKEY2_3                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_3_BOOTKEY2_3_0                                                                    (0x1U<<0U)

// BOOTKEY2_4 Configuration

#define OTP_DATA_RAW_BOOTKEY2_4_BOOTKEY2_4                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_4_BOOTKEY2_4_0                                                                    (0x1U<<0U)

// BOOTKEY2_5 Configuration

#define OTP_DATA_RAW_BOOTKEY2_5_BOOTKEY2_5                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_5_BOOTKEY2_5_0                                                                    (0x1U<<0U)

// BOOTKEY2_6 Configuration

#define OTP_DATA_RAW_BOOTKEY2_6_BOOTKEY2_6                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_6_BOOTKEY2_6_0                                                                    (0x1U<<0U)

// BOOTKEY2_7 Configuration

#define OTP_DATA_RAW_BOOTKEY2_7_BOOTKEY2_7                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_7_BOOTKEY2_7_0                                                                    (0x1U<<0U)

// BOOTKEY2_8 Configuration

#define OTP_DATA_RAW_BOOTKEY2_8_BOOTKEY2_8                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_8_BOOTKEY2_8_0                                                                    (0x1U<<0U)

// BOOTKEY2_9 Configuration

#define OTP_DATA_RAW_BOOTKEY2_9_BOOTKEY2_9                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_9_BOOTKEY2_9_0                                                                    (0x1U<<0U)

// BOOTKEY2_10 Configuration

#define OTP_DATA_RAW_BOOTKEY2_10_BOOTKEY2_10                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_10_BOOTKEY2_10_0                                                                  (0x1U<<0U)

// BOOTKEY2_11 Configuration

#define OTP_DATA_RAW_BOOTKEY2_11_BOOTKEY2_11                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_11_BOOTKEY2_11_0                                                                  (0x1U<<0U)

// BOOTKEY2_12 Configuration

#define OTP_DATA_RAW_BOOTKEY2_12_BOOTKEY2_12                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_12_BOOTKEY2_12_0                                                                  (0x1U<<0U)

// BOOTKEY2_13 Configuration

#define OTP_DATA_RAW_BOOTKEY2_13_BOOTKEY2_13                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_13_BOOTKEY2_13_0                                                                  (0x1U<<0U)

// BOOTKEY2_14 Configuration

#define OTP_DATA_RAW_BOOTKEY2_14_BOOTKEY2_14                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_14_BOOTKEY2_14_0                                                                  (0x1U<<0U)

// BOOTKEY2_15 Configuration

#define OTP_DATA_RAW_BOOTKEY2_15_BOOTKEY2_15                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY2_15_BOOTKEY2_15_0                                                                  (0x1U<<0U)

// BOOTKEY3_0 Configuration

#define OTP_DATA_RAW_BOOTKEY3_0_BOOTKEY3_0                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_0_BOOTKEY3_0_0                                                                    (0x1U<<0U)

// BOOTKEY3_1 Configuration

#define OTP_DATA_RAW_BOOTKEY3_1_BOOTKEY3_1                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_1_BOOTKEY3_1_0                                                                    (0x1U<<0U)

// BOOTKEY3_2 Configuration

#define OTP_DATA_RAW_BOOTKEY3_2_BOOTKEY3_2                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_2_BOOTKEY3_2_0                                                                    (0x1U<<0U)

// BOOTKEY3_3 Configuration

#define OTP_DATA_RAW_BOOTKEY3_3_BOOTKEY3_3                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_3_BOOTKEY3_3_0                                                                    (0x1U<<0U)

// BOOTKEY3_4 Configuration

#define OTP_DATA_RAW_BOOTKEY3_4_BOOTKEY3_4                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_4_BOOTKEY3_4_0                                                                    (0x1U<<0U)

// BOOTKEY3_5 Configuration

#define OTP_DATA_RAW_BOOTKEY3_5_BOOTKEY3_5                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_5_BOOTKEY3_5_0                                                                    (0x1U<<0U)

// BOOTKEY3_6 Configuration

#define OTP_DATA_RAW_BOOTKEY3_6_BOOTKEY3_6                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_6_BOOTKEY3_6_0                                                                    (0x1U<<0U)

// BOOTKEY3_7 Configuration

#define OTP_DATA_RAW_BOOTKEY3_7_BOOTKEY3_7                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_7_BOOTKEY3_7_0                                                                    (0x1U<<0U)

// BOOTKEY3_8 Configuration

#define OTP_DATA_RAW_BOOTKEY3_8_BOOTKEY3_8                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_8_BOOTKEY3_8_0                                                                    (0x1U<<0U)

// BOOTKEY3_9 Configuration

#define OTP_DATA_RAW_BOOTKEY3_9_BOOTKEY3_9                                                                      (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_9_BOOTKEY3_9_0                                                                    (0x1U<<0U)

// BOOTKEY3_10 Configuration

#define OTP_DATA_RAW_BOOTKEY3_10_BOOTKEY3_10                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_10_BOOTKEY3_10_0                                                                  (0x1U<<0U)

// BOOTKEY3_11 Configuration

#define OTP_DATA_RAW_BOOTKEY3_11_BOOTKEY3_11                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_11_BOOTKEY3_11_0                                                                  (0x1U<<0U)

// BOOTKEY3_12 Configuration

#define OTP_DATA_RAW_BOOTKEY3_12_BOOTKEY3_12                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_12_BOOTKEY3_12_0                                                                  (0x1U<<0U)

// BOOTKEY3_13 Configuration

#define OTP_DATA_RAW_BOOTKEY3_13_BOOTKEY3_13                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_13_BOOTKEY3_13_0                                                                  (0x1U<<0U)

// BOOTKEY3_14 Configuration

#define OTP_DATA_RAW_BOOTKEY3_14_BOOTKEY3_14                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_14_BOOTKEY3_14_0                                                                  (0x1U<<0U)

// BOOTKEY3_15 Configuration

#define OTP_DATA_RAW_BOOTKEY3_15_BOOTKEY3_15                                                                    (0xFFFFU<<0U)
#define OTP_DATA_RAW_BOOTKEY3_15_BOOTKEY3_15_0                                                                  (0x1U<<0U)

// KEY1_0 Configuration

#define OTP_DATA_RAW_KEY1_0_KEY1_0                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_0_KEY1_0_0                                                                            (0x1U<<0U)

// KEY1_1 Configuration

#define OTP_DATA_RAW_KEY1_1_KEY1_1                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_1_KEY1_1_0                                                                            (0x1U<<0U)

// KEY1_2 Configuration

#define OTP_DATA_RAW_KEY1_2_KEY1_2                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_2_KEY1_2_0                                                                            (0x1U<<0U)

// KEY1_3 Configuration

#define OTP_DATA_RAW_KEY1_3_KEY1_3                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_3_KEY1_3_0                                                                            (0x1U<<0U)

// KEY1_4 Configuration

#define OTP_DATA_RAW_KEY1_4_KEY1_4                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_4_KEY1_4_0                                                                            (0x1U<<0U)

// KEY1_5 Configuration

#define OTP_DATA_RAW_KEY1_5_KEY1_5                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_5_KEY1_5_0                                                                            (0x1U<<0U)

// KEY1_6 Configuration

#define OTP_DATA_RAW_KEY1_6_KEY1_6                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_6_KEY1_6_0                                                                            (0x1U<<0U)

// KEY1_7 Configuration

#define OTP_DATA_RAW_KEY1_7_KEY1_7                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY1_7_KEY1_7_0                                                                            (0x1U<<0U)

// KEY2_0 Configuration

#define OTP_DATA_RAW_KEY2_0_KEY2_0                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_0_KEY2_0_0                                                                            (0x1U<<0U)

// KEY2_1 Configuration

#define OTP_DATA_RAW_KEY2_1_KEY2_1                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_1_KEY2_1_0                                                                            (0x1U<<0U)

// KEY2_2 Configuration

#define OTP_DATA_RAW_KEY2_2_KEY2_2                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_2_KEY2_2_0                                                                            (0x1U<<0U)

// KEY2_3 Configuration

#define OTP_DATA_RAW_KEY2_3_KEY2_3                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_3_KEY2_3_0                                                                            (0x1U<<0U)

// KEY2_4 Configuration

#define OTP_DATA_RAW_KEY2_4_KEY2_4                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_4_KEY2_4_0                                                                            (0x1U<<0U)

// KEY2_5 Configuration

#define OTP_DATA_RAW_KEY2_5_KEY2_5                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_5_KEY2_5_0                                                                            (0x1U<<0U)

// KEY2_6 Configuration

#define OTP_DATA_RAW_KEY2_6_KEY2_6                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_6_KEY2_6_0                                                                            (0x1U<<0U)

// KEY2_7 Configuration

#define OTP_DATA_RAW_KEY2_7_KEY2_7                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY2_7_KEY2_7_0                                                                            (0x1U<<0U)

// KEY3_0 Configuration

#define OTP_DATA_RAW_KEY3_0_KEY3_0                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_0_KEY3_0_0                                                                            (0x1U<<0U)

// KEY3_1 Configuration

#define OTP_DATA_RAW_KEY3_1_KEY3_1                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_1_KEY3_1_0                                                                            (0x1U<<0U)

// KEY3_2 Configuration

#define OTP_DATA_RAW_KEY3_2_KEY3_2                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_2_KEY3_2_0                                                                            (0x1U<<0U)

// KEY3_3 Configuration

#define OTP_DATA_RAW_KEY3_3_KEY3_3                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_3_KEY3_3_0                                                                            (0x1U<<0U)

// KEY3_4 Configuration

#define OTP_DATA_RAW_KEY3_4_KEY3_4                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_4_KEY3_4_0                                                                            (0x1U<<0U)

// KEY3_5 Configuration

#define OTP_DATA_RAW_KEY3_5_KEY3_5                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_5_KEY3_5_0                                                                            (0x1U<<0U)

// KEY3_6 Configuration

#define OTP_DATA_RAW_KEY3_6_KEY3_6                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_6_KEY3_6_0                                                                            (0x1U<<0U)

// KEY3_7 Configuration

#define OTP_DATA_RAW_KEY3_7_KEY3_7                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY3_7_KEY3_7_0                                                                            (0x1U<<0U)

// KEY4_0 Configuration

#define OTP_DATA_RAW_KEY4_0_KEY4_0                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_0_KEY4_0_0                                                                            (0x1U<<0U)

// KEY4_1 Configuration

#define OTP_DATA_RAW_KEY4_1_KEY4_1                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_1_KEY4_1_0                                                                            (0x1U<<0U)

// KEY4_2 Configuration

#define OTP_DATA_RAW_KEY4_2_KEY4_2                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_2_KEY4_2_0                                                                            (0x1U<<0U)

// KEY4_3 Configuration

#define OTP_DATA_RAW_KEY4_3_KEY4_3                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_3_KEY4_3_0                                                                            (0x1U<<0U)

// KEY4_4 Configuration

#define OTP_DATA_RAW_KEY4_4_KEY4_4                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_4_KEY4_4_0                                                                            (0x1U<<0U)

// KEY4_5 Configuration

#define OTP_DATA_RAW_KEY4_5_KEY4_5                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_5_KEY4_5_0                                                                            (0x1U<<0U)

// KEY4_6 Configuration

#define OTP_DATA_RAW_KEY4_6_KEY4_6                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_6_KEY4_6_0                                                                            (0x1U<<0U)

// KEY4_7 Configuration

#define OTP_DATA_RAW_KEY4_7_KEY4_7                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY4_7_KEY4_7_0                                                                            (0x1U<<0U)

// KEY5_0 Configuration

#define OTP_DATA_RAW_KEY5_0_KEY5_0                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_0_KEY5_0_0                                                                            (0x1U<<0U)

// KEY5_1 Configuration

#define OTP_DATA_RAW_KEY5_1_KEY5_1                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_1_KEY5_1_0                                                                            (0x1U<<0U)

// KEY5_2 Configuration

#define OTP_DATA_RAW_KEY5_2_KEY5_2                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_2_KEY5_2_0                                                                            (0x1U<<0U)

// KEY5_3 Configuration

#define OTP_DATA_RAW_KEY5_3_KEY5_3                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_3_KEY5_3_0                                                                            (0x1U<<0U)

// KEY5_4 Configuration

#define OTP_DATA_RAW_KEY5_4_KEY5_4                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_4_KEY5_4_0                                                                            (0x1U<<0U)

// KEY5_5 Configuration

#define OTP_DATA_RAW_KEY5_5_KEY5_5                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_5_KEY5_5_0                                                                            (0x1U<<0U)

// KEY5_6 Configuration

#define OTP_DATA_RAW_KEY5_6_KEY5_6                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_6_KEY5_6_0                                                                            (0x1U<<0U)

// KEY5_7 Configuration

#define OTP_DATA_RAW_KEY5_7_KEY5_7                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY5_7_KEY5_7_0                                                                            (0x1U<<0U)

// KEY6_0 Configuration

#define OTP_DATA_RAW_KEY6_0_KEY6_0                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_0_KEY6_0_0                                                                            (0x1U<<0U)

// KEY6_1 Configuration

#define OTP_DATA_RAW_KEY6_1_KEY6_1                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_1_KEY6_1_0                                                                            (0x1U<<0U)

// KEY6_2 Configuration

#define OTP_DATA_RAW_KEY6_2_KEY6_2                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_2_KEY6_2_0                                                                            (0x1U<<0U)

// KEY6_3 Configuration

#define OTP_DATA_RAW_KEY6_3_KEY6_3                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_3_KEY6_3_0                                                                            (0x1U<<0U)

// KEY6_4 Configuration

#define OTP_DATA_RAW_KEY6_4_KEY6_4                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_4_KEY6_4_0                                                                            (0x1U<<0U)

// KEY6_5 Configuration

#define OTP_DATA_RAW_KEY6_5_KEY6_5                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_5_KEY6_5_0                                                                            (0x1U<<0U)

// KEY6_6 Configuration

#define OTP_DATA_RAW_KEY6_6_KEY6_6                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_6_KEY6_6_0                                                                            (0x1U<<0U)

// KEY6_7 Configuration

#define OTP_DATA_RAW_KEY6_7_KEY6_7                                                                              (0xFFFFU<<0U)
#define OTP_DATA_RAW_KEY6_7_KEY6_7_0                                                                            (0x1U<<0U)

// KEY1_VALID Configuration

#define OTP_DATA_RAW_KEY1_VALID_VALID                                                                           (0x1U<<0U)
#define OTP_DATA_RAW_KEY1_VALID_VALID_R1                                                                        (0x1U<<8U)
#define OTP_DATA_RAW_KEY1_VALID_VALID_R2                                                                        (0x1U<<16U)

// KEY2_VALID Configuration

#define OTP_DATA_RAW_KEY2_VALID_VALID                                                                           (0x1U<<0U)
#define OTP_DATA_RAW_KEY2_VALID_VALID_R1                                                                        (0x1U<<8U)
#define OTP_DATA_RAW_KEY2_VALID_VALID_R2                                                                        (0x1U<<16U)

// KEY3_VALID Configuration

#define OTP_DATA_RAW_KEY3_VALID_VALID                                                                           (0x1U<<0U)
#define OTP_DATA_RAW_KEY3_VALID_VALID_R1                                                                        (0x1U<<8U)
#define OTP_DATA_RAW_KEY3_VALID_VALID_R2                                                                        (0x1U<<16U)

// KEY4_VALID Configuration

#define OTP_DATA_RAW_KEY4_VALID_VALID                                                                           (0x1U<<0U)
#define OTP_DATA_RAW_KEY4_VALID_VALID_R1                                                                        (0x1U<<8U)
#define OTP_DATA_RAW_KEY4_VALID_VALID_R2                                                                        (0x1U<<16U)

// KEY5_VALID Configuration

#define OTP_DATA_RAW_KEY5_VALID_VALID                                                                           (0x1U<<0U)
#define OTP_DATA_RAW_KEY5_VALID_VALID_R1                                                                        (0x1U<<8U)
#define OTP_DATA_RAW_KEY5_VALID_VALID_R2                                                                        (0x1U<<16U)

// KEY6_VALID Configuration

#define OTP_DATA_RAW_KEY6_VALID_VALID                                                                           (0x1U<<0U)
#define OTP_DATA_RAW_KEY6_VALID_VALID_R1                                                                        (0x1U<<8U)
#define OTP_DATA_RAW_KEY6_VALID_VALID_R2                                                                        (0x1U<<16U)

// PAGE0_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE0_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE0_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE0_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE0_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE0_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE0_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE0_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE0_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE0_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE0_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE0_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE0_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE0_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE0_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE0_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE1_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE1_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE1_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE1_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE1_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE1_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE1_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE1_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE1_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE1_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE1_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE1_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE1_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE1_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE1_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE1_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE2_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE2_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE2_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE2_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE2_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE2_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE2_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE2_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE2_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE2_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE2_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE2_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE2_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE2_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE2_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE2_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE3_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE3_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE3_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE3_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE3_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE3_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE3_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE3_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE3_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE3_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE3_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE3_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE3_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE3_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE3_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE3_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE4_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE4_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE4_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE4_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE4_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE4_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE4_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE4_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE4_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE4_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE4_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE4_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE4_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE4_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE4_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE4_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE5_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE5_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE5_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE5_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE5_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE5_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE5_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE5_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE5_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE5_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE5_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE5_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE5_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE5_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE5_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE5_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE6_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE6_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE6_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE6_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE6_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE6_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE6_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE6_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE6_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE6_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE6_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE6_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE6_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE6_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE6_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE6_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE7_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE7_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE7_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE7_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE7_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE7_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE7_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE7_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE7_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE7_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE7_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE7_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE7_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE7_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE7_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE7_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE8_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE8_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE8_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE8_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE8_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE8_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE8_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE8_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE8_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE8_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE8_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE8_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE8_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE8_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE8_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE8_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE9_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE9_LOCK0_KEY_W                                                                          (0x7U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK0_KEY_W_0                                                                        (0x1U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK0_KEY_R                                                                          (0x7U<<3U)
#define OTP_DATA_RAW_PAGE9_LOCK0_KEY_R_0                                                                        (0x1U<<3U)
#define OTP_DATA_RAW_PAGE9_LOCK0_NO_KEY_STATE                                                                   (0x1U<<6U)
#define OTP_DATA_RAW_PAGE9_LOCK0_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE9_LOCK0_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE9_LOCK0_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE9_LOCK0_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE9_LOCK0_NO_KEY_STATE_READ_ONLY                                                         (0x0U<<6U)
#define OTP_DATA_RAW_PAGE9_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                      (0x1U<<6U)

// PAGE9_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_S                                                                         (0x3U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_S_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_NS                                                                        (0x3U<<2U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_NS_0                                                                      (0x1U<<2U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_BL                                                                        (0x3U<<4U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_BL_0                                                                      (0x1U<<4U)
#define OTP_DATA_RAW_PAGE9_LOCK1_R1                                                                             (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE9_LOCK1_R1_0                                                                           (0x1U<<8U)
#define OTP_DATA_RAW_PAGE9_LOCK1_R2                                                                             (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE9_LOCK1_R2_0                                                                           (0x1U<<16U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_S_READ_WRITE                                                              (0x0U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_S_READ_ONLY                                                               (0x1U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_S_RESERVED                                                                (0x2U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_S_INACCESSIBLE                                                            (0x3U<<0U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_NS_READ_WRITE                                                             (0x0U<<2U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_NS_READ_ONLY                                                              (0x1U<<2U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_NS_RESERVED                                                               (0x2U<<2U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_NS_INACCESSIBLE                                                           (0x3U<<2U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_BL_READ_WRITE                                                             (0x0U<<4U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_BL_READ_ONLY                                                              (0x1U<<4U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_BL_RESERVED                                                               (0x2U<<4U)
#define OTP_DATA_RAW_PAGE9_LOCK1_LOCK_BL_INACCESSIBLE                                                           (0x3U<<4U)

// PAGE10_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE10_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE10_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE10_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE10_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE10_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE10_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE10_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE10_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE10_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE10_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE10_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE10_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE10_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE10_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE10_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE11_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE11_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE11_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE11_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE11_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE11_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE11_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE11_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE11_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE11_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE11_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE11_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE11_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE11_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE11_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE11_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE12_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE12_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE12_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE12_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE12_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE12_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE12_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE12_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE12_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE12_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE12_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE12_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE12_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE12_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE12_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE12_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE13_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE13_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE13_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE13_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE13_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE13_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE13_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE13_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE13_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE13_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE13_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE13_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE13_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE13_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE13_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE13_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE14_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE14_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE14_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE14_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE14_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE14_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE14_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE14_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE14_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE14_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE14_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE14_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE14_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE14_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE14_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE14_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE15_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE15_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE15_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE15_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE15_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE15_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE15_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE15_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE15_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE15_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE15_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE15_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE15_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE15_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE15_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE15_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE16_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE16_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE16_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE16_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE16_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE16_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE16_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE16_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE16_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE16_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE16_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE16_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE16_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE16_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE16_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE16_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE17_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE17_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE17_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE17_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE17_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE17_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE17_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE17_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE17_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE17_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE17_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE17_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE17_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE17_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE17_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE17_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE18_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE18_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE18_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE18_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE18_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE18_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE18_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE18_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE18_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE18_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE18_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE18_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE18_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE18_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE18_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE18_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE19_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE19_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE19_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE19_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE19_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE19_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE19_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE19_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE19_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE19_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE19_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE19_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE19_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE19_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE19_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE19_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE20_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE20_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE20_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE20_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE20_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE20_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE20_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE20_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE20_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE20_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE20_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE20_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE20_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE20_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE20_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE20_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE21_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE21_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE21_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE21_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE21_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE21_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE21_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE21_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE21_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE21_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE21_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE21_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE21_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE21_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE21_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE21_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE22_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE22_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE22_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE22_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE22_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE22_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE22_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE22_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE22_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE22_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE22_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE22_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE22_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE22_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE22_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE22_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE23_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE23_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE23_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE23_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE23_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE23_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE23_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE23_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE23_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE23_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE23_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE23_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE23_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE23_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE23_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE23_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE24_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE24_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE24_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE24_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE24_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE24_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE24_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE24_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE24_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE24_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE24_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE24_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE24_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE24_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE24_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE24_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE25_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE25_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE25_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE25_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE25_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE25_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE25_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE25_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE25_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE25_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE25_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE25_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE25_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE25_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE25_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE25_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE26_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE26_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE26_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE26_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE26_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE26_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE26_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE26_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE26_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE26_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE26_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE26_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE26_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE26_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE26_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE26_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE27_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE27_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE27_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE27_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE27_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE27_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE27_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE27_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE27_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE27_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE27_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE27_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE27_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE27_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE27_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE27_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE28_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE28_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE28_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE28_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE28_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE28_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE28_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE28_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE28_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE28_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE28_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE28_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE28_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE28_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE28_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE28_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE29_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE29_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE29_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE29_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE29_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE29_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE29_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE29_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE29_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE29_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE29_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE29_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE29_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE29_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE29_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE29_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE30_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE30_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE30_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE30_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE30_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE30_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE30_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE30_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE30_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE30_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE30_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE30_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE30_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE30_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE30_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE30_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE31_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE31_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE31_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE31_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE31_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE31_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE31_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE31_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE31_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE31_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE31_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE31_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE31_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE31_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE31_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE31_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE32_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE32_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE32_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE32_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE32_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE32_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE32_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE32_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE32_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE32_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE32_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE32_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE32_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE32_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE32_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE32_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE33_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE33_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE33_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE33_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE33_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE33_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE33_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE33_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE33_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE33_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE33_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE33_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE33_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE33_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE33_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE33_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE34_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE34_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE34_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE34_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE34_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE34_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE34_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE34_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE34_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE34_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE34_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE34_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE34_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE34_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE34_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE34_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE35_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE35_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE35_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE35_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE35_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE35_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE35_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE35_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE35_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE35_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE35_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE35_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE35_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE35_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE35_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE35_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE36_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE36_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE36_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE36_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE36_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE36_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE36_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE36_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE36_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE36_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE36_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE36_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE36_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE36_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE36_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE36_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE37_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE37_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE37_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE37_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE37_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE37_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE37_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE37_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE37_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE37_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE37_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE37_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE37_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE37_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE37_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE37_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE38_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE38_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE38_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE38_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE38_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE38_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE38_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE38_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE38_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE38_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE38_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE38_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE38_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE38_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE38_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE38_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE39_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE39_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE39_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE39_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE39_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE39_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE39_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE39_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE39_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE39_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE39_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE39_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE39_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE39_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE39_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE39_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE40_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE40_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE40_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE40_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE40_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE40_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE40_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE40_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE40_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE40_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE40_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE40_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE40_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE40_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE40_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE40_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE41_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE41_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE41_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE41_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE41_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE41_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE41_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE41_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE41_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE41_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE41_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE41_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE41_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE41_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE41_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE41_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE42_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE42_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE42_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE42_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE42_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE42_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE42_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE42_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE42_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE42_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE42_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE42_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE42_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE42_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE42_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE42_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE43_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE43_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE43_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE43_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE43_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE43_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE43_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE43_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE43_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE43_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE43_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE43_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE43_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE43_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE43_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE43_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE44_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE44_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE44_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE44_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE44_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE44_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE44_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE44_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE44_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE44_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE44_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE44_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE44_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE44_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE44_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE44_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE45_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE45_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE45_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE45_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE45_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE45_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE45_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE45_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE45_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE45_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE45_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE45_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE45_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE45_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE45_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE45_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE46_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE46_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE46_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE46_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE46_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE46_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE46_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE46_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE46_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE46_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE46_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE46_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE46_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE46_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE46_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE46_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE47_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE47_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE47_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE47_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE47_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE47_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE47_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE47_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE47_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE47_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE47_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE47_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE47_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE47_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE47_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE47_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE48_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE48_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE48_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE48_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE48_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE48_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE48_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE48_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE48_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE48_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE48_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE48_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE48_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE48_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE48_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE48_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE49_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE49_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE49_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE49_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE49_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE49_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE49_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE49_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE49_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE49_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE49_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE49_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE49_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE49_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE49_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE49_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE50_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE50_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE50_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE50_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE50_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE50_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE50_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE50_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE50_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE50_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE50_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE50_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE50_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE50_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE50_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE50_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE51_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE51_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE51_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE51_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE51_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE51_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE51_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE51_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE51_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE51_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE51_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE51_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE51_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE51_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE51_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE51_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE52_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE52_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE52_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE52_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE52_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE52_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE52_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE52_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE52_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE52_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE52_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE52_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE52_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE52_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE52_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE52_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE53_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE53_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE53_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE53_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE53_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE53_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE53_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE53_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE53_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE53_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE53_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE53_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE53_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE53_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE53_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE53_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE54_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE54_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE54_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE54_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE54_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE54_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE54_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE54_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE54_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE54_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE54_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE54_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE54_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE54_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE54_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE54_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE55_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE55_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE55_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE55_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE55_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE55_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE55_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE55_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE55_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE55_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE55_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE55_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE55_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE55_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE55_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE55_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE56_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE56_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE56_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE56_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE56_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE56_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE56_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE56_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE56_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE56_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE56_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE56_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE56_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE56_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE56_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE56_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE57_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE57_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE57_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE57_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE57_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE57_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE57_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE57_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE57_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE57_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE57_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE57_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE57_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE57_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE57_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE57_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE58_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE58_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE58_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE58_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE58_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE58_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE58_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE58_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE58_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE58_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE58_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE58_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE58_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE58_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE58_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE58_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE59_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE59_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE59_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE59_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE59_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE59_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE59_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE59_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE59_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE59_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE59_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE59_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE59_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE59_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE59_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE59_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE60_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE60_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE60_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE60_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE60_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE60_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE60_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE60_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE60_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE60_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE60_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE60_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE60_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE60_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE60_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE60_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE61_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE61_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE61_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE61_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE61_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE61_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE61_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE61_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE61_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE61_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE61_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE61_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE61_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE61_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE61_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE61_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE62_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE62_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE62_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE62_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE62_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE62_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE62_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE62_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE62_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE62_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE62_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE62_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE62_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE62_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE62_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE62_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)

// PAGE63_LOCK0 Configuration

#define OTP_DATA_RAW_PAGE63_LOCK0_KEY_W                                                                         (0x7U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK0_KEY_W_0                                                                       (0x1U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK0_KEY_R                                                                         (0x7U<<3U)
#define OTP_DATA_RAW_PAGE63_LOCK0_KEY_R_0                                                                       (0x1U<<3U)
#define OTP_DATA_RAW_PAGE63_LOCK0_NO_KEY_STATE                                                                  (0x1U<<6U)
#define OTP_DATA_RAW_PAGE63_LOCK0_RMA                                                                           (0x1U<<7U)
#define OTP_DATA_RAW_PAGE63_LOCK0_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE63_LOCK0_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE63_LOCK0_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE63_LOCK0_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE63_LOCK0_NO_KEY_STATE_READ_ONLY                                                        (0x0U<<6U)
#define OTP_DATA_RAW_PAGE63_LOCK0_NO_KEY_STATE_INACCESSIBLE                                                     (0x1U<<6U)

// PAGE63_LOCK1 Configuration

#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_S                                                                        (0x3U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_S_0                                                                      (0x1U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_NS                                                                       (0x3U<<2U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_NS_0                                                                     (0x1U<<2U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_BL                                                                       (0x3U<<4U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_BL_0                                                                     (0x1U<<4U)
#define OTP_DATA_RAW_PAGE63_LOCK1_R1                                                                            (0xFFU<<8U)
#define OTP_DATA_RAW_PAGE63_LOCK1_R1_0                                                                          (0x1U<<8U)
#define OTP_DATA_RAW_PAGE63_LOCK1_R2                                                                            (0xFFU<<16U)
#define OTP_DATA_RAW_PAGE63_LOCK1_R2_0                                                                          (0x1U<<16U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_S_READ_WRITE                                                             (0x0U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_S_READ_ONLY                                                              (0x1U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_S_RESERVED                                                               (0x2U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_S_INACCESSIBLE                                                           (0x3U<<0U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_NS_READ_WRITE                                                            (0x0U<<2U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_NS_READ_ONLY                                                             (0x1U<<2U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_NS_RESERVED                                                              (0x2U<<2U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_NS_INACCESSIBLE                                                          (0x3U<<2U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_BL_READ_WRITE                                                            (0x0U<<4U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_BL_READ_ONLY                                                             (0x1U<<4U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_BL_RESERVED                                                              (0x2U<<4U)
#define OTP_DATA_RAW_PAGE63_LOCK1_LOCK_BL_INACCESSIBLE                                                          (0x3U<<4U)
