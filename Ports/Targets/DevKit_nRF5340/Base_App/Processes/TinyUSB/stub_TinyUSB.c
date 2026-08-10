/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "TinyUSB" library.
 *           Multiple profiles
 */

#include    <tusb.h>             // for SystemCoreClock

#include    "TinyUSB/TinyUSB.h"
#include    "tusb_option.h"      // for BOARD_TUD_RHPORT, CFG_TUD_CDC, CFG_TUD_MSC

// Save the GCC diagnostic
//
#pragma GCC diagnostic push

// Ignore the GCC diagnostic
//
#pragma GCC diagnostic ignored "-Wpedantic"
#include    "tusb_types.h"

#ifdef __clang__

// Ignore the GCC diagnostic
//
#pragma GCC diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#endif

#include    "usbd.h"

#if (CFG_TUD_CDC > 0)
#include    "Interface/Models/model_TinyUSB_cdc.c_inc"      // IWYU pragma: keep
#endif

#if (CFG_TUD_MSC > 0)
#include    "msc/msc_device.h"
#include    "Interface/Models/model_TinyUSB_msc.c_inc"      // IWYU pragma: keep
#endif

#if (CFG_TUD_VIDEO > 0)
#include    "video/video_device.h"
#include    "Interface/Models/model_TinyUSB_video.c_inc"    // IWYU pragma: keep
#endif

// Restore the GCC diagnostic
//
#pragma GCC diagnostic pop

// Prototypes

extern  void    coreUSB_init(void);

// Init device stack on configured roothub port

static  tusb_rhport_init_t deviceInit = {
    .role  = TUSB_ROLE_DEVICE,
    .speed = TUSB_SPEED_AUTO,
};

/*
 * \brief stub_TinyUSB_init
 *
 * - USB initialisation
 *
 */
void    stub_TinyUSB_init(void) {

    coreUSB_init();
    tusb_init(BOARD_TUD_RHPORT, &deviceInit);
}

/*
 * \brief stub_TinyUSB_cyclic
 *
 * - USB management
 *
 */
void    stub_TinyUSB_cyclic(void) {

    tud_task();
}
