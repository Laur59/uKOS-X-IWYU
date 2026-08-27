/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Demo of a C application.
 *           Management of the LVGL.
 */

#include    <stdint.h>
#include    <stdlib.h>

#include    "ulvgl.h"
#include    "kern/kern.h"
#include    "kern/kern_types.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "macros_soc.h"
#include    "os_errors.h"
#include    "stub.h"
#include    "ui.h"

#define KLVGL_MUTEX_API     "Protect_LVGL_API"

static              lv_display_t    *display[KNB_CORES];
static  volatile    bool            vLVGLReady[KNB_CORES] = MCSET(false);
                    mutx_t          *vLVGL_API[KNB_CORES];
// Prototypes

extern  void    ui_draw(void);

/*
 * \brief aProcess_lvgl_tick
 *
 * - P_lvgl_tick: Every 1-ms
 *                - Increment the VLGL tick
 *
 */
[[noreturn]]
static void aProcess_lvgl_tick([[maybe_unused]] const void *argument) {
    uint32_t    core, delta;
    uint64_t    last, now;

    core = GET_RUNNING_CORE;

    do { kern_suspendProcess(1u); } while (!vLVGLReady[core]);

    kern_readTickCount(&last);

    while (true) {
        kern_readTickCount(&now);

        kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
        delta = (uint32_t)((now - last) / 1000u);
        if (delta > 0u) {
            lv_tick_inc(delta);
            last += (uint64_t)delta * 1000u;
        }
        lv_timer_handler();
        kern_unlockMutex(vLVGL_API[core]);

       kern_suspendProcess(1u);
    }
}

/*
 * \brief aProcess_lvgl
 *
 * - P_lvgl: Draw all the widgets
 *           Every 500-ms
 *               - do nothing
 *
 */
[[noreturn]]
static void aProcess_lvgl([[maybe_unused]] const void *argument) {
    uint32_t    core, LCDBufferSize;
    lv_color_t  *LCDBuffer;

    core = GET_RUNNING_CORE;

// Initialise the LCD and the LVGL
// Ask for a small image buffer (for partial rendering)

    PRIVILEGE_ELEVATE;
//                  RRGGBB
    stub_LCD_On(0x00FF0000u);

    kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
    lv_init();

    LCDBufferSize = (uint32_t)((uint64_t)KLCD_WIDTH * (uint64_t)KLCD_BUF_LINES * (uint64_t)sizeof(lv_color_t));
    LCDBuffer     = (lv_color_t *)memo_malloc(KMEMO_ALIGN_16, LCDBufferSize, "lcd_buffer");

// Create a display
// Activate it

    display[core] = lv_display_create(KLCD_WIDTH, KLCD_HEIGHT);
    lv_display_set_default(display[core]);

    lv_display_set_buffers(display[core], LCDBuffer, nullptr, LCDBufferSize, LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_flush_cb(display[core], stub_LCD_flush_cb);
    kern_unlockMutex(vLVGL_API[core]);

// Draw the different widgets
// Activate the lvgl tick

    ui_draw();

    vLVGLReady[core] = true;

// Display the classification result

    while (true) {
        kern_suspendProcess(500u);
    }
}

/*
 * \brief demo_init
 *
 * - Initialise the graphic stufs
 * - Launch all the processes
 *
 */
void    lvgl_init(void) {
    uint32_t    core;
    proc_t      *process_lvgl_tick, *process_lvgl;

    core = GET_RUNNING_CORE;

// -----------------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden_lvgl_tick[]) = "Process_lvgl_tick";
    STRG_LOC_CONST(aStrText_lvgl_tick[]) = "Process lvgl_tick.                        (c) EFr-2026";
    STRG_LOC_CONST(aStrIden_lvgl[])      = "Process_lvgl";
    STRG_LOC_CONST(aStrText_lvgl[])      = "Process lvgl.                             (c) EFr-2026";

// Specifications for the processes

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification_lvgl_tick,            // Specifications (just use specification_x)
        aStrText_lvgl_tick,                 // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_XL,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_lvgl_tick,                 // Code of the process
        aStrIden_lvgl_tick,                 // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_HIGH_01              // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    PROCESS_STACKMALLOC(
        1,                                  // Index
        specification_lvgl,                 // Specifications (just use specification_x)
        aStrText_lvgl,                      // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_XL,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_lvgl,                      // Code of the process
        aStrIden_lvgl,                      // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_MEDIUM_01            // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createMutex(KLVGL_MUTEX_API, &vLVGL_API[core])                       != KERR_KERN_NOERR) { LOG(KFATAL_USER, "lvgl: create mutx"); exit(EXIT_OS_FAILURE); }
    if (kern_createProcess(&specification_lvgl_tick, nullptr, &process_lvgl_tick) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "lvgl: Create proc"); exit(EXIT_OS_FAILURE); }
    if (kern_createProcess(&specification_lvgl, nullptr, &process_lvgl)           != KERR_KERN_NOERR) { LOG(KFATAL_USER, "lvgl: Create proc"); exit(EXIT_OS_FAILURE); }

    LOG(KINFO_USER, "Application launched");
}
