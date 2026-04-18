/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "TinyUSB" library.
 *           Multiple profiles
 */

#include    <stdint.h>

#include    "Registers/nvic.h"
#include    "TinyUSB/TinyUSB.h"
#include    "Registers/soc_vectors.h"
#include    "clockTree.h"
#include    "macros_core.h"
#include    "macros_soc.h"

// Save the GCC diagnostic
//
#pragma GCC diagnostic  push

// Ignore the GCC diagnostic
//
#pragma GCC diagnostic  ignored "-Wpedantic"
#include    "tusb.h"
#include    "tusb_option.h"
#include    "tusb_os_custom.h"
#include    "device/usbd.h"

// Restore the GCC diagnostic
//
#pragma GCC diagnostic  pop

#if (CFG_TUD_CDC > 0)
#include    "TinyUSB/Construction/Interface/Models/model_TinyUSB_cdc.c_inc"
#endif

#if (CFG_TUD_MSC > 0)
#include    "TinyUSB/Construction/Interface/Models/model_TinyUSB_msc.c_inc"
#endif

#if (CFG_TUD_VIDEO > 0)
#include    "TinyUSB/Construction/Interface/Models/model_TinyUSB_video.c_inc"
#endif

uint32_t    SystemCoreClock = KFREQUENCY_CORE;

// Prototypes

static  void    local_USB_FS_IRQHandler(void);

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

    INTERRUPT_VECTOR(USBCTRL_IRQ_C0_IRQn, local_USB_FS_IRQHandler);
    NVIC_ClearPendingIRQ(USBCTRL_IRQ_C0_IRQn);
    NVIC_SetPriority(USBCTRL_IRQ_C0_IRQn, KINT_LEVEL_COMMUNICATIONS);
    NVIC_EnableIRQ(USBCTRL_IRQ_C0_IRQn);

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
 * \brief local_USB_FS_IRQHandler
 *
 */
static  void    local_USB_FS_IRQHandler(void) {

    tud_int_handler(BOARD_TUD_RHPORT);
}
