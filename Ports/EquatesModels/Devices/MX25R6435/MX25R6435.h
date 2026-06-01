/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     FLASH MX25R6435 equates.
 */

#pragma once

// Memory structure

#define KFLASH_SPI_SZ_FLASH                 (8U * 1024U * 1024U)                            // FLASH size
#define KFLASH_SPI_SZ_SECTOR                4096U                                           // Sector size
#define KFLASH_SPI_NB_SECTOR                (KFLASH_SPI_SZ_FLASH / KFLASH_SPI_SZ_SECTOR)    // Number of sectors
#define KFLASH_SPI_SZ_PAGE                  256U                                            // Page size
#define KFLASH_SPI_NB_PAGE                  (KFLASH_SPI_SZ_FLASH / KFLASH_SPI_SZ_PAGE)      // Number of pages
#define KFLASH_SPI_SZ_BLOC                  65536U                                          // Bloc size
#define KFLASH_SPI_NB_BLOC                  (KFLASH_SPI_SZ_FLASH / KFLASH_SPI_SZ_BLOC)      // Number of blocs

// Commands for the chip MX25R6435

#define KFLASH_SPI_CMD_WRITE_STATUS         0x01U                                           // FLASH write status command
#define KFLASH_SPI_CMD_WRITE                0x02U                                           // FLASH write command (pages of 256 bytes)
#define KFLASH_SPI_CMD_READ                 0x03U                                           // FLASH read command
#define KFLASH_SPI_CMD_WRITE_DISABLE        0x04U                                           // FLASH write disable command
#define KFLASH_SPI_CMD_READ_STATUS          0x05U                                           // FLASH read status command
#define KFLASH_SPI_CMD_WRITE_ENABLE         0x06U                                           // FLASH write enable command
#define KFLASH_SPI_CMD_ERASE_SECTOR         0x20U                                           // FLASH erase sector command
#define KFLASH_SPI_CMD_ERASE_BLOC           0xD8U                                           // FLASH erase bloc command
#define KFLASH_SPI_CMD_ERASE_BULK           0xC7U                                           // FLASH bulk erase command

// Status bits for the chip MX25R6435

#define BFLASH_SPI_BUSY                     0U                                              // Erase or write in progress
#define BFLASH_SPI_WEL                      1U                                              // Write enable latch
#define BFLASH_SPI_BP0                      2U                                              // Block protect block 0
#define BFLASH_SPI_BP1                      3U                                              // Block protect block 1
#define BFLASH_SPI_BP2                      4U                                              // Block protect block 2
#define BFLASH_SPI_BP3                      5U                                              // Block protect block 3
#define BFLASH_SPI_SRWD                     7U                                              // Status register protect
