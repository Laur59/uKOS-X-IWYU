/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; W25X80L.
; ========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     EEPROM W25X80L equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// Memory structure

#define KSPIM_SZ_SECTOR                     4096U                           // Sector size
#define KSPIM_SZ_PAGE                       256U                            // Page size
#define KSPIM_NB_SECTOR_BLOC                16U                             // Number of sector by block
#define KSPIM_NB_BLOC                       16U                             // Number of blocks
#define KSPIM_SZ_FLASH                      (KSZBLOC * KSPIM_NB_BLOC)       // EEPROM size

// Commands for the chip W25X80L

#define KCMD_WR_STATUS                      0x01U                           // EEPROM write status command
#define KCMD_WRITE                          0x02U                           // EEPROM write command
#define KCMD_READ                           0x03U                           // EEPROM read command
#define KCMD_WR_DISABLE                     0x04U                           // EEPROM write disable command
#define KCMD_RD_STATUS                      0x05U                           // EEPROM read status command
#define KCMD_WR_ENABLE                      0x06U                           // EEPROM write enable command
#define KCMD_ERASE_SECTOR                   0x20U                           // EEPROM erase sector command
#define KCMD_BULK_ERASE                     0xC7U                           // EEPROM bulk erase command

// Status bits for the chip W25X80L

#define BBUSY                               0U                              // Erase or write in progress
#define BWEL                                1U                              // Write enable latch
#define BBP0                                2U                              // Block protect block 0
#define BBP1                                3U                              // Block protect block 1
#define BBP2                                4U                              // Block protect block 2
#define BTB                                 5U                              // Top/Bottom write protect
#define BSRP                                7U                              // Status register protect
