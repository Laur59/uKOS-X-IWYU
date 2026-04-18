/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_H743 – TinyUSB library stub (multi-profile).
 */

#include    <stdint.h>

#include    <tusb.h>             // for SystemCoreClock

#include    "TinyUSB/TinyUSB.h"
#include    "clockTree.h"
#include    "core_reg.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "soc_reg.h"
#include    "tusb_option.h"      // for BOARD_TUD_RHPORT, CFG_TUD_CDC, CFG_TUD_MSC

// Save the GCC diagnostic
//
#pragma GCC diagnostic  push

// Ignore the GCC diagnostic
//
#pragma GCC diagnostic  ignored "-Wpedantic"
#include    "tusb.h"        // IWYU pragma: keep
#include    "tusb_types.h"
#include    "usbd.h"

// Restore the GCC diagnostic
//
#pragma GCC diagnostic  pop

#if (CFG_TUD_CDC > 0)
#include    "TinyUSB/Construction/Interface/Models/model_TinyUSB_cdc.c_inc" // IWYU pragma: keep
#endif

#if (CFG_TUD_MSC > 0)
#include    "TinyUSB/Construction/Interface/Models/model_TinyUSB_msc.c_inc" // IWYU pragma: keep
#endif

#if (CFG_TUD_VIDEO > 0)
#include    "TinyUSB/Construction/Interface/Models/model_TinyUSB_video.c_inc"   // IWYU pragma: keep
#endif

uint32_t    SystemCoreClock = KFREQUENCY_CORE;

// Prototypes

static  void    local_OTG_FS_IRQHandler(void);

// Init device stack on configured roothub port

static  tusb_rhport_init_t deviceInit = {
    .role  = TUSB_ROLE_DEVICE,
    .speed = TUSB_SPEED_AUTO
};

/*
 * \brief stub_TinyUSB_init
 *
 * - USB initialisation
 *
 */
void    stub_TinyUSB_init(void) {

    INTERRUPT_VECTOR(OTG_FS_C0_IRQn, local_OTG_FS_IRQHandler);
    NVIC_SetPriority(OTG_FS_C0_IRQn, KINT_LEVEL_COMMUNICATIONS);

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

// Local routines
// ==============

/*
 * \brief local_OTG_FS_IRQHandler
 *
 */
static  void    local_OTG_FS_IRQHandler(void) {

    tud_int_handler(BOARD_TUD_RHPORT);
}
