/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2019 Ha Thach
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Board initial set-up.
 */

#include    "tusb.h"
#include    "nrfx_config.h"
#include    "drivers/include/nrfx_power.h"

#define VBUSDETECT  USBREG_USBREGSTATUS_VBUSDETECT_Msk
#define OUTPUTRDY   USBREG_USBREGSTATUS_OUTPUTRDY_Msk

// Prototypes

extern  void    tusb_hal_nrf_power_event(uint32_t event);
static  void    power_event_handler(nrfx_power_usb_evt_t event);
extern  void    USBREGULATOR_IRQHandler(void);
        void    USBD_IRQHandler(void);

/*
 * \brief xyz_C0_IRQHandler
 *
 * - Redirection of the USB interruptions
 *
 */
void    USBD_C0_IRQHandler(void)            { USBD_IRQHandler();         }
void    USBREGULATOR_C0_IRQHandler(void)    { USBREGULATOR_IRQHandler(); }

/*
 * \brief coreUSB_init
 *
 * - USB / Power initialisation
 *
 */
void    coreUSB_init(void) {
    const   nrfx_power_usbevt_config_t  config  = { .handler = power_event_handler };
    const   nrfx_power_config_t         pwr_cfg = { 0                              };

    NVIC_SetPriority(USBD_IRQn, 2);

// USB power may already be ready at this time -> no event generated
// We need to invoke the handler based on the status initially

    nrfx_power_init(&pwr_cfg);

// Register tusb function as USB power handler

    nrfx_power_usbevt_init(&config);
    nrfx_power_usbevt_enable();

// USB power may already be ready at this time -> no event generated
// We need to invoke the handler based on the status initially

    if (NRF_USBREGULATOR->USBREGSTATUS & VBUSDETECT) { tusb_hal_nrf_power_event(NRFX_POWER_USB_EVT_DETECTED); }
    if (NRF_USBREGULATOR->USBREGSTATUS & OUTPUTRDY)  { tusb_hal_nrf_power_event(NRFX_POWER_USB_EVT_READY);    }
}

// Local routines
// ==============

/*
 * \brief power_event_handler
 *
 * - This function execute the nrf power callback
 *
 */
TU_ATTR_UNUSED  static  void    power_event_handler(nrfx_power_usb_evt_t event) {

    tusb_hal_nrf_power_event((uint32_t)event);
}

/*
 * \brief USBD_C0_IRQHandler
 *
 * - Interruption USB
 *
 */
void    USBD_IRQHandler(void) {

    tud_int_handler(BOARD_TUD_RHPORT);
}
