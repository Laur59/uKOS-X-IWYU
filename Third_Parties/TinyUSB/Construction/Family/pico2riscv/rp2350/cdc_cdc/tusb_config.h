/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2019 Ha Thach (tinyusb.org)
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * TinyUSB configuration file for RP2350 Hazard3 (RV32IMAC), profile cdc_cdc.
 */

#pragma once

#ifdef __cplusplus
extern  "C" {
#endif

// Board Specific Configuration
// ============================

#define CFG_TUSB_MCU            OPT_MCU_RP2040

// OSAL selection: the default custom OSAL bridges to the uKOS-X kernel
// (`tusb_os_custom.c`). The validation build (TINYUSB_VALIDATE_PICO_S)
// instead uses the upstream Pico OSAL so the library can be linked into a
// Pico SDK app for hardware unit-testing without the uKOS-X kernel.
#ifdef TINYUSB_VALIDATE_PICO_S
#define CFG_TUSB_OS             OPT_OS_PICO
#else
#define CFG_TUSB_OS             OPT_OS_CUSTOM
#endif

#ifdef SYSTEM_TINYUSB_HS_S
#undef  BOARD_TUD_RHPORT
#undef  CFG_TUD_MAX_SPEED
#define BOARD_TUD_RHPORT        1
#define CFG_TUD_MAX_SPEED       OPT_MODE_HIGH_SPEED

#undef  CFG_TUD_CDC_RX_BUFSIZE
#undef  CFG_TUD_CDC_TX_BUFSIZE
#undef  CFG_TUD_CDC_EP_BUFSIZE
#define CFG_TUD_CDC_RX_BUFSIZE  4096
#define CFG_TUD_CDC_TX_BUFSIZE  4096
#define CFG_TUD_CDC_EP_BUFSIZE  512
#endif

#ifdef SYSTEM_TINYUSB_FS_S
#undef  BOARD_TUD_RHPORT
#undef  CFG_TUD_MAX_SPEED
#define BOARD_TUD_RHPORT        0
#define CFG_TUD_MAX_SPEED       OPT_MODE_FULL_SPEED

#undef  CFG_TUD_CDC_RX_BUFSIZE
#undef  CFG_TUD_CDC_TX_BUFSIZE
#undef  CFG_TUD_CDC_EP_BUFSIZE
#define CFG_TUD_CDC_RX_BUFSIZE  64
#define CFG_TUD_CDC_TX_BUFSIZE  64
#define CFG_TUD_CDC_EP_BUFSIZE  64
#endif

// Common Configuration
// ====================

#define CFG_TUSB_DEBUG          0
#define CFG_TUD_ENABLED         1

// USB DMA on some MCUs can only access a specific SRAM region with restriction on alignment.
// TinyUSB use follows macros to declare transferring memory so that they can be put
// into those specific section.
// e.g
// - CFG_TUSB_MEM SECTION : __attribute__ (( section(".usb_ram") ))
// - CFG_TUSB_MEM_ALIGN   : __attribute__ ((aligned(4)))

#ifndef CFG_TUSB_MEM_SECTION
#define CFG_TUSB_MEM_SECTION
#endif

#ifndef CFG_TUSB_MEM_ALIGN
#define CFG_TUSB_MEM_ALIGN      __attribute__ ((aligned(32)))
#endif

// Device Configuration
// ====================

#ifndef CFG_TUD_ENDPOINT0_SIZE
#define CFG_TUD_ENDPOINT0_SIZE  64
#endif

// Class

#define CFG_TUD_CDC             2
#define CFG_TUD_MSC             0
#define CFG_TUD_HID             0
#define CFG_TUD_MIDI            0
#define CFG_TUD_VENDOR          0
#define CFG_TUD_VIDEO           0

#ifdef __cplusplus
}
#endif
