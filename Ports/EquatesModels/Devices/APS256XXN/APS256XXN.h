/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    APSRam APS256XXN equates.
 */

#pragma once

// Memory structure

#define KAPS_xSPI_SZ_RAM                    (32U * 1024U * 1024U)                           // APSRam size
#define KAPS_DEV_SIZE_VALUE                 24U                                             // 32-MB = 2^(24 + 1)

// Commands for the chip APS256XXN

#define KAPS_OP_LIN_BURST_READ              0x20U                                           // APSRam Burst Read
#define KAPS_OP_LIN_BURST_WRITE             0xA0U                                           // APSRam Burst Write
#define KAPS_OP_MR_READ                     0x40U                                           // APSRam Mode Register Read
#define KAPS_OP_MR_WRITE                    0xC0U                                           // APSRam Mode Register Write
#define KAPS_OP_GLOBAL_RESET                0xFFU                                           // APSRam Global Reset
