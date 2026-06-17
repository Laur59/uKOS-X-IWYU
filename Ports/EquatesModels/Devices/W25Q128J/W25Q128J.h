/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Flash W25Q128J equates.
 */

#pragma once

// Memory structure

#define KFLASH_xSPI_SZ_FLASH                (16U * 1024U * 1024U)                           // FLASH size
#define KFLASH_xSPI_SZ_SECTOR               4096U                                           // Sector size
#define KFLASH_xSPI_NB_SECTOR               (KFLASH_xSPI_SZ_FLASH / KFLASH_xSPI_SZ_SECTOR)  // Number of sectors
#define KFLASH_xSPI_SZ_PAGE                 256U                                            // Page size
#define KFLASH_xSPI_NB_PAGE                 (KFLASH_xSPI_SZ_FLASH / KFLASH_xSPI_SZ_PAGE)    // Number of pages
#define KFLASH_xSPI_SZ_BLOC                 65536U                                          // Bloc size
#define KFLASH_xSPI_NB_BLOC                 (KFLASH_xSPI_SZ_FLASH / KFLASH_xSPI_SZ_BLOC)    // Number of blocs

// Commands for the chip W25Q128J

#define KFLASH_xSPI_CMD_WRITE_STATUS        0x01U                                           // FLASH write status command
#define KFLASH_xSPI_CMD_WRITE               0x02U                                           // FLASH write command (pages of 256 bytes)
#define KFLASH_xSPI_CMD_READ                0x03U                                           // FLASH read command
#define KFLASH_xSPI_CMD_WRITE_DISABLE       0x04U                                           // FLASH write disable command
#define KFLASH_xSPI_CMD_READ_STATUS         0x05U                                           // FLASH read status command
#define KFLASH_xSPI_CMD_WRITE_ENABLE        0x06U                                           // FLASH write enable command
#define KFLASH_xSPI_CMD_ERASE_SECTOR        0x20U                                           // FLASH erase sector command
#define KFLASH_xSPI_CMD_ERASE_BLOC          0xD8U                                           // FLASH erase bloc command
#define KFLASH_xSPI_CMD_ERASE_BULK          0xC7U                                           // FLASH bulk erase command

// Extension QUAD

#define KFLASH_QSPI_CMD_READ_STATUS         0x35U                                           // FLASH read status 2 command
#define KFLASH_QSPI_CMD_WRITE_STATUS        0x31U                                           // FLASH write status 2 command
#define KFLASH_QSPI_CMD_READ                0xEBU                                           // FLASH read quad command
#define KFLASH_QSPI_CMD_WRITE               0x32U                                           // FLASH write quad command (pages of 256 bytes)

// Status bits for the chip W25Q128J

#define BFLASH_xSPI_BUSY                    0U                                              // Erase or write in progress
#define BFLASH_xSPI_WEL                     1U                                              // Write enable latch
#define BFLASH_xSPI_BP0                     2U                                              // Block protect block 0
#define BFLASH_xSPI_BP1                     3U                                              // Block protect block 1
#define BFLASH_xSPI_BP2                     4U                                              // Block protect block 2
#define BFLASH_xSPI_TB                      5U                                              // Top/Bottom write protect
#define BFLASH_xSPI_SEC                     6U                                              // Top/Bottom write protect
#define BFLASH_xSPI_SRWD                    7U                                              // Status register protect

// Extension QUAD

#define BFLASH_xSPI_QE                      1U                                              // Quad enable
