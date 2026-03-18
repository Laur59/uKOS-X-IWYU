/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_ficr equates.
 */

#pragma once

#include    <stdint.h>

// FICR address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[128];
    volatile    uint32_t    INFO_CONFIGID;
    volatile    uint32_t    INFO_DEVICEID[2];
    volatile    uint32_t    INFO_PART;
    volatile    uint32_t    INFO_VARIANT;
    volatile    uint32_t    INFO_PACKAGE;
    volatile    uint32_t    INFO_RAM;
    volatile    uint32_t    INFO_FLASH;
    volatile    uint32_t    INFO_CODEPAGESIZE;
    volatile    uint32_t    INFO_CODESIZE;
    volatile    uint32_t    INFO_DEVICETYPE;
    volatile    uint32_t    RESERVED1[53];
    volatile    uint32_t    TRIMCNF0_ADDR;
    volatile    uint32_t    TRIMCNF0_DATA;
    volatile    uint32_t    TRIMCNF1_ADDR;
    volatile    uint32_t    TRIMCNF1_DATA;
    volatile    uint32_t    TRIMCNF2_ADDR;
    volatile    uint32_t    TRIMCNF2_DATA;
    volatile    uint32_t    TRIMCNF3_ADDR;
    volatile    uint32_t    TRIMCNF3_DATA;
    volatile    uint32_t    TRIMCNF4_ADDR;
    volatile    uint32_t    TRIMCNF4_DATA;
    volatile    uint32_t    TRIMCNF5_ADDR;
    volatile    uint32_t    TRIMCNF5_DATA;
    volatile    uint32_t    TRIMCNF6_ADDR;
    volatile    uint32_t    TRIMCNF6_DATA;
    volatile    uint32_t    TRIMCNF7_ADDR;
    volatile    uint32_t    TRIMCNF7_DATA;
    volatile    uint32_t    TRIMCNF8_ADDR;
    volatile    uint32_t    TRIMCNF8_DATA;
    volatile    uint32_t    TRIMCNF9_ADDR;
    volatile    uint32_t    TRIMCNF9_DATA;
    volatile    uint32_t    TRIMCNF10_ADDR;
    volatile    uint32_t    TRIMCNF10_DATA;
    volatile    uint32_t    TRIMCNF11_ADDR;
    volatile    uint32_t    TRIMCNF11_DATA;
    volatile    uint32_t    TRIMCNF12_ADDR;
    volatile    uint32_t    TRIMCNF12_DATA;
    volatile    uint32_t    TRIMCNF13_ADDR;
    volatile    uint32_t    TRIMCNF13_DATA;
    volatile    uint32_t    TRIMCNF14_ADDR;
    volatile    uint32_t    TRIMCNF14_DATA;
    volatile    uint32_t    TRIMCNF15_ADDR;
    volatile    uint32_t    TRIMCNF15_DATA;
    volatile    uint32_t    TRIMCNF16_ADDR;
    volatile    uint32_t    TRIMCNF16_DATA;
    volatile    uint32_t    TRIMCNF17_ADDR;
    volatile    uint32_t    TRIMCNF17_DATA;
    volatile    uint32_t    TRIMCNF18_ADDR;
    volatile    uint32_t    TRIMCNF18_DATA;
    volatile    uint32_t    TRIMCNF19_ADDR;
    volatile    uint32_t    TRIMCNF19_DATA;
    volatile    uint32_t    TRIMCNF20_ADDR;
    volatile    uint32_t    TRIMCNF20_DATA;
    volatile    uint32_t    TRIMCNF21_ADDR;
    volatile    uint32_t    TRIMCNF21_DATA;
    volatile    uint32_t    TRIMCNF22_ADDR;
    volatile    uint32_t    TRIMCNF22_DATA;
    volatile    uint32_t    TRIMCNF23_ADDR;
    volatile    uint32_t    TRIMCNF23_DATA;
    volatile    uint32_t    TRIMCNF24_ADDR;
    volatile    uint32_t    TRIMCNF24_DATA;
    volatile    uint32_t    TRIMCNF25_ADDR;
    volatile    uint32_t    TRIMCNF25_DATA;
    volatile    uint32_t    TRIMCNF26_ADDR;
    volatile    uint32_t    TRIMCNF26_DATA;
    volatile    uint32_t    TRIMCNF27_ADDR;
    volatile    uint32_t    TRIMCNF27_DATA;
    volatile    uint32_t    TRIMCNF28_ADDR;
    volatile    uint32_t    TRIMCNF28_DATA;
    volatile    uint32_t    TRIMCNF29_ADDR;
    volatile    uint32_t    TRIMCNF29_DATA;
    volatile    uint32_t    TRIMCNF30_ADDR;
    volatile    uint32_t    TRIMCNF30_DATA;
    volatile    uint32_t    TRIMCNF31_ADDR;
    volatile    uint32_t    TRIMCNF31_DATA;
    volatile    uint32_t    RESERVED2[20];
    volatile    uint32_t    NFC_TAGHEADER0;
    volatile    uint32_t    NFC_TAGHEADER1;
    volatile    uint32_t    NFC_TAGHEADER2;
    volatile    uint32_t    NFC_TAGHEADER3;
    volatile    uint32_t    RESERVED3[488];
    volatile    uint32_t    TRNG90B_BYTES;
    volatile    uint32_t    TRNG90B_RCCUTOFF;
    volatile    uint32_t    TRNG90B_APCUTOFF;
    volatile    uint32_t    TRNG90B_STARTUP;
    volatile    uint32_t    TRNG90B_ROSC1;
    volatile    uint32_t    TRNG90B_ROSC2;
    volatile    uint32_t    TRNG90B_ROSC3;
    volatile    uint32_t    TRNG90B_ROSC4;
    volatile    uint32_t    XOSC32MTRIM;
} FICR_TypeDef;

#ifdef __cplusplus
#define FICR_S  reinterpret_cast<FICR_TypeDef *>(0x00FF0000U)

#else
#define FICR_S  ((FICR_TypeDef *)0x00FF0000U)
#endif

// CONFIGID Configuration

#define FICR_INFO_CONFIGID_HWID                             (0xFFFFU<<0)
#define FICR_INFO_CONFIGID_HWID_0                           (0x1U<<0)

// DEVICEID Configuration

#define FICR_INFO_DEVICEID_DEVICEID                         (0xFFFFFFFFU<<0)
#define FICR_INFO_DEVICEID_DEVICEID_0                       (0x1U<<0)

// PART Configuration

#define FICR_INFO_PART_PART                                 (0xFFFFFFFFU<<0)
#define FICR_INFO_PART_PART_0                               (0x1U<<0)
#define FICR_INFO_PART_PART_N5340                           (0x5340U<<0)
#define FICR_INFO_PART_PART_UNSPECIFIED                     (0xFFFFFFFFU<<0)

// VARIANT Configuration

#define FICR_INFO_VARIANT_VARIANT                           (0xFFFFFFFFU<<0)
#define FICR_INFO_VARIANT_VARIANT_0                         (0x1U<<0)
#define FICR_INFO_VARIANT_VARIANT_QKAA                      (0x514B4141U<<0)
#define FICR_INFO_VARIANT_VARIANT_CLAA                      (0x434C4141U<<0)
#define FICR_INFO_VARIANT_VARIANT_UNSPECIFIED               (0xFFFFFFFFU<<0)

// PACKAGE Configuration

#define FICR_INFO_PACKAGE_PACKAGE                           (0xFFFFFFFFU<<0)
#define FICR_INFO_PACKAGE_PACKAGE_0                         (0x1U<<0)
#define FICR_INFO_PACKAGE_PACKAGE_QK                        (0x2000U<<0)
#define FICR_INFO_PACKAGE_PACKAGE_CL                        (0x2005U<<0)
#define FICR_INFO_PACKAGE_PACKAGE_UNSPECIFIED               (0xFFFFFFFFU<<0)

// RAM Configuration

#define FICR_INFO_RAM_RAM                                   (0xFFFFFFFFU<<0)
#define FICR_INFO_RAM_RAM_0                                 (0x1U<<0)
#define FICR_INFO_RAM_RAM_K16                               (0x10U<<0)
#define FICR_INFO_RAM_RAM_K32                               (0x20U<<0)
#define FICR_INFO_RAM_RAM_K64                               (0x40U<<0)
#define FICR_INFO_RAM_RAM_K128                              (0x80U<<0)
#define FICR_INFO_RAM_RAM_K256                              (0x100U<<0)
#define FICR_INFO_RAM_RAM_K512                              (0x200U<<0)
#define FICR_INFO_RAM_RAM_UNSPECIFIED                       (0xFFFFFFFFU<<0)

// FLASH Configuration

#define FICR_INFO_FLASH_FLASH                               (0xFFFFFFFFU<<0)
#define FICR_INFO_FLASH_FLASH_0                             (0x1U<<0)
#define FICR_INFO_FLASH_FLASH_K128                          (0x80U<<0)
#define FICR_INFO_FLASH_FLASH_K256                          (0x100U<<0)
#define FICR_INFO_FLASH_FLASH_K512                          (0x200U<<0)
#define FICR_INFO_FLASH_FLASH_K1024                         (0x400U<<0)
#define FICR_INFO_FLASH_FLASH_K2048                         (0x800U<<0)
#define FICR_INFO_FLASH_FLASH_UNSPECIFIED                   (0xFFFFFFFFU<<0)

// CODEPAGESIZE Configuration

#define FICR_INFO_CODEPAGESIZE_CODEPAGESIZE                 (0xFFFFFFFFU<<0)
#define FICR_INFO_CODEPAGESIZE_CODEPAGESIZE_0               (0x1U<<0)
#define FICR_INFO_CODEPAGESIZE_CODEPAGESIZE_K4096           (0x1000U<<0)

// CODESIZE Configuration

#define FICR_INFO_CODESIZE_CODESIZE                         (0xFFFFFFFFU<<0)
#define FICR_INFO_CODESIZE_CODESIZE_0                       (0x1U<<0)
#define FICR_INFO_CODESIZE_CODESIZE_P256                    (0x100U<<0)

// DEVICETYPE Configuration

#define FICR_INFO_DEVICETYPE_DEVICETYPE                     (0xFFFFFFFFU<<0)
#define FICR_INFO_DEVICETYPE_DEVICETYPE_0                   (0x1U<<0)
#define FICR_INFO_DEVICETYPE_DEVICETYPE_DIE                 (0x0U<<0)
#define FICR_INFO_DEVICETYPE_DEVICETYPE_FPGA                (0xFFFFFFFFU<<0)

// ADDR Configuration

#define FICR_TRIMCNF_ADDR_ADDRESS                           (0xFFFFFFFFU<<0)
#define FICR_TRIMCNF_ADDR_ADDRESS_0                         (0x1U<<0)

// DATA Configuration

#define FICR_TRIMCNF_DATA_DATA                              (0xFFFFFFFFU<<0)
#define FICR_TRIMCNF_DATA_DATA_0                            (0x1U<<0)

// TAGHEADER0 Configuration

#define FICR_NFC_TAGHEADER0_UD3                             (0xFFU<<24)
#define FICR_NFC_TAGHEADER0_UD3_0                           (0x1U<<24)
#define FICR_NFC_TAGHEADER0_UD2                             (0xFFU<<16)
#define FICR_NFC_TAGHEADER0_UD2_0                           (0x1U<<16)
#define FICR_NFC_TAGHEADER0_UD1                             (0xFFU<<8)
#define FICR_NFC_TAGHEADER0_UD1_0                           (0x1U<<8)
#define FICR_NFC_TAGHEADER0_MFGID                           (0xFFU<<0)
#define FICR_NFC_TAGHEADER0_MFGID_0                         (0x1U<<0)

// TAGHEADER1 Configuration

#define FICR_NFC_TAGHEADER1_UD7                             (0xFFU<<24)
#define FICR_NFC_TAGHEADER1_UD7_0                           (0x1U<<24)
#define FICR_NFC_TAGHEADER1_UD6                             (0xFFU<<16)
#define FICR_NFC_TAGHEADER1_UD6_0                           (0x1U<<16)
#define FICR_NFC_TAGHEADER1_UD5                             (0xFFU<<8)
#define FICR_NFC_TAGHEADER1_UD5_0                           (0x1U<<8)
#define FICR_NFC_TAGHEADER1_UD4                             (0xFFU<<0)
#define FICR_NFC_TAGHEADER1_UD4_0                           (0x1U<<0)

// TAGHEADER2 Configuration

#define FICR_NFC_TAGHEADER2_UD11                            (0xFFU<<24)
#define FICR_NFC_TAGHEADER2_UD11_0                          (0x1U<<24)
#define FICR_NFC_TAGHEADER2_UD10                            (0xFFU<<16)
#define FICR_NFC_TAGHEADER2_UD10_0                          (0x1U<<16)
#define FICR_NFC_TAGHEADER2_UD9                             (0xFFU<<8)
#define FICR_NFC_TAGHEADER2_UD9_0                           (0x1U<<8)
#define FICR_NFC_TAGHEADER2_UD8                             (0xFFU<<0)
#define FICR_NFC_TAGHEADER2_UD8_0                           (0x1U<<0)

// TAGHEADER3 Configuration

#define FICR_NFC_TAGHEADER3_UD15                            (0xFFU<<24)
#define FICR_NFC_TAGHEADER3_UD15_0                          (0x1U<<24)
#define FICR_NFC_TAGHEADER3_UD14                            (0xFFU<<16)
#define FICR_NFC_TAGHEADER3_UD14_0                          (0x1U<<16)
#define FICR_NFC_TAGHEADER3_UD13                            (0xFFU<<8)
#define FICR_NFC_TAGHEADER3_UD13_0                          (0x1U<<8)
#define FICR_NFC_TAGHEADER3_UD12                            (0xFFU<<0)
#define FICR_NFC_TAGHEADER3_UD12_0                          (0x1U<<0)

// BYTES Configuration

#define FICR_TRNG90B_BYTES_BYTES                            (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_BYTES_BYTES_0                          (0x1U<<0)

// RCCUTOFF Configuration

#define FICR_TRNG90B_RCCUTOFF_RCCUTOFF                      (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_RCCUTOFF_RCCUTOFF_0                    (0x1U<<0)

// APCUTOFF Configuration

#define FICR_TRNG90B_APCUTOFF_APCUTOFF                      (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_APCUTOFF_APCUTOFF_0                    (0x1U<<0)

// STARTUP Configuration

#define FICR_TRNG90B_STARTUP_STARTUP                        (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_STARTUP_STARTUP_0                      (0x1U<<0)

// ROSC1 Configuration

#define FICR_TRNG90B_ROSC1_ROSC1                            (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_ROSC1_ROSC1_0                          (0x1U<<0)

// ROSC2 Configuration

#define FICR_TRNG90B_ROSC2_ROSC2                            (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_ROSC2_ROSC2_0                          (0x1U<<0)

// ROSC3 Configuration

#define FICR_TRNG90B_ROSC3_ROSC3                            (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_ROSC3_ROSC3_0                          (0x1U<<0)

// ROSC4 Configuration

#define FICR_TRNG90B_ROSC4_ROSC4                            (0xFFFFFFFFU<<0)
#define FICR_TRNG90B_ROSC4_ROSC4_0                          (0x1U<<0)

// XOSC32MTRIM Configuration

#define FICR_XOSC32MTRIM_OFFSET                             (0x1FU<<5)
#define FICR_XOSC32MTRIM_OFFSET_0                           (0x1U<<5)
#define FICR_XOSC32MTRIM_SLOPE                              (0x1FU<<0)
#define FICR_XOSC32MTRIM_SLOPE_0                            (0x1U<<0)
