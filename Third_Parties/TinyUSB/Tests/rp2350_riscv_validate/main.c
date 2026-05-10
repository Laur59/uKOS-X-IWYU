/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Validation test for the prebuilt libTinyUSB_FS.a / libTinyUSB_HS.a
 * archives, built for rp2350-riscv with OPT_OS_PICO (BUILD_VALIDATE_PICO).
 *
 * This standalone Pico SDK app links against our prebuilt validation
 * archive (no uKOS-X kernel) and exercises the TinyUSB device stack as
 * a dual-CDC peripheral.
 *
 * Pass criterion: the device enumerates as two CDC interfaces on the host
 * and `tud_inited()` returns true after `tusb_init()`. UART0 (GPIO0/1) is
 * used for status output so the host can observe what the firmware reports
 * even before USB enumerates.
 */

#include    <stdio.h>
#include    <stdint.h>

#include    "pico/stdlib.h"
#include    "pico/time.h"

#include    "tusb.h"

// `tud_descriptor_string_cb` and the device/configuration descriptor
// callbacks are already supplied by our prebuilt usb_descriptors.c.o
// inside the validation archive — we don't provide them here.
//
// `board_get_unique_id` is referenced by our prebuilt usb_descriptors.c
// for the iSerial string. The Pico SDK exposes flash unique-id via
// pico_unique_id; we use that to mirror the dev_multi_cdc behaviour.
#include "pico/unique_id.h"

void board_get_unique_id(uint8_t id[], int max_len) {
    pico_unique_board_id_t uid;
    pico_get_unique_board_id(&uid);
    int n = (max_len < (int)sizeof(uid.id)) ? max_len : (int)sizeof(uid.id);
    for (int i = 0; i < n; i++) { id[i] = uid.id[i]; }
}

#include "hardware/gpio.h"

int main(void) {
    // Visible "I am running" indicator: blink GPIO25 (Pico2 user LED) 3 times
    // BEFORE doing anything else, so we can rule out total-fail vs USB/UART
    // problems.
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    for (int i = 0; i < 6; i++) {
        gpio_put(25, i & 1);
        sleep_ms(100);
    }
    gpio_put(25, 1);  // leave LED on after the blink burst

    stdio_init_all();
    sleep_ms(200);

    printf("\n[VALIDATE] uKOS-X TinyUSB validation app starting\n");
    printf("[VALIDATE] tud_inited() before tusb_init: %s\n",
           tud_inited() ? "TRUE" : "FALSE");

    static const tusb_rhport_init_t dev_init = {
        .role  = TUSB_ROLE_DEVICE,
        .speed = TUSB_SPEED_AUTO,
    };
    bool ok = tusb_init(0, &dev_init);
    printf("[VALIDATE] tusb_init() returned: %s\n", ok ? "TRUE" : "FALSE");
    printf("[VALIDATE] tud_inited() after  tusb_init: %s\n",
           tud_inited() ? "TRUE" : "FALSE");

    uint32_t loops = 0;
    while (true) {
        if (loops < 5) {
            printf("[VALIDATE] entering tud_task #%u\n", (unsigned)loops);
        }
        tud_task();
        if (loops < 5) {
            printf("[VALIDATE] returned tud_task #%u, mounted=%d, configured=%d\n",
                   (unsigned)loops, (int)tud_mounted(), (int)tud_ready());
        }
        loops++;
        if ((loops & 0x0001FFFFU) == 0U) {
            printf("[VALIDATE] tud_task loop n=%u, mounted=%d\n",
                   (unsigned)loops, (int)tud_mounted());
        }
    }
}
