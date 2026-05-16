/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Image viewer.
 *           This tool allows to send a simulated image via the uvc0 manager.
 */

#include    "viewer/viewer_uvc0.h"

#include    <inttypes.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "macros_soc.h"
#include    "memo/memo.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_GLB_CONST(aStrApplication[]) = "viewer       Send an image, via the uvc0 manager.      (c) EFr-2026";
STRG_GLB_CONST(aStrHelp[])        = "Send a simulated image to the computer\n"
                                    "======================================\n\n"

                                    "Input format:  viewer\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// CLI tool specific
// =================

typedef struct  graphic     graphic_t;

struct  graphic {
            uint32_t    oW;                 // Image width
            uint32_t    oH;                 // Image heigh
            uint8_t     *oImage;            // Ptr on the image
        };

[[gnu::weak]]
extern  uint8_t     linker_stUSB_V_BUFFER_0[];

[[gnu::weak]]
extern  uint8_t     linker_stUSB_V_BUFFER_1[];
static  bool        vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

        void    TinyUSB_video_init(void);
        void    TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
        void    TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h, void (*callBack)(const void *argument), const void *argument);
static  void    aProcess(const void *argument);
static  void    local_callBack(const void *argument);
static  void    local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t position);

/*
 * \brief viewer_uvc0
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int32_t viewer_uvc0(uint32_t argc, const char_t *argv[]) {
    uint32_t    core;
    proc_t      *process;

// -------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden[]) = "Process_User";
    STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2026";

    UNUSED(argc);
    UNUSED(argv);

    core = GET_RUNNING_CORE;
    vKillRequest[core] = false;

// Specifications for the processes

    PROCESS(
        0,                                  // Index
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess,                           // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_HIGH_05              // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "viewer: create proc"); return EXIT_OS_FAILURE; }

    LOG(KINFO_USER, "viewer: application launched");
    return EXIT_OS_SUCCESS_CLI;
}

/*
 * \brief viewer_uvc0_clean
 *
 * - Try to clean the ressources
 *      - Free all the ressources
 *
 */
int32_t viewer_uvc0_clean(uint32_t argc, const char_t *argv[]) {
    uint32_t    core;

    UNUSED(argc);
    UNUSED(argv);

    core = GET_RUNNING_CORE;
    vKillRequest[core] = true;

    return EXIT_OS_SUCCESS;
}

// Local routines
// ==============

/*
 * \brief aProcess
 *
 * - Px: Repeat every xyz ms
 *          - Prepare an image
 *          - Send it over usb
 *
 */
[[noreturn]]
static void aProcess(const void *argument) {
            uint32_t    w, h;
            float64_t   frameRate;
            uint8_t     *image_0, *image_1;
            uint64_t    time[2];
            graphic_t   pack_0, pack_1;
    const   bool        *killRequest;

    killRequest = (const bool *)argument;

    PRIVILEGE_ELEVATE;

    TinyUSB_video_init();
    TinyUSB_video_getImageSize(&w, &h);

    image_0 = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (w * h * 2U), "video");
    image_1 = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (w * h * 2U), "video");
    if ((image_0 == nullptr) || (image_1 == nullptr)) {

        memo_free(image_0);
        memo_free(image_1);

        if ((linker_stUSB_V_BUFFER_0 != nullptr) && (linker_stUSB_V_BUFFER_1 != nullptr)) {
            image_0 = (uint8_t *)linker_stUSB_V_BUFFER_0;
            image_1 = (uint8_t *)linker_stUSB_V_BUFFER_1;

            LOG(KINFO_USER, "viewer: video buffers in PSRAm");
        }
        else {
            LOG(KFATAL_USER, "viewer: out of memory");
            exit(EXIT_OS_FAILURE);
        }
    }

    pack_0.oW = w; pack_0.oH = h; pack_0.oImage = image_0;
    pack_1.oW = w; pack_1.oH = h; pack_1.oImage = image_1;

    local_prepareImage(image_0, w, h, 0U);

    while (!*killRequest) {

// Send it over usb
// Prepare the next image
// During the waiting for the transfer acknowledge, the callback prepares the next image

        kern_readTickCount(&time[0]);
        TinyUSB_video_sendImage(image_0, w, h, local_callBack, (const void *)&pack_1);
        TinyUSB_video_sendImage(image_1, w, h, local_callBack, (const void *)&pack_0);
        kern_readTickCount(&time[1]);

        frameRate = (1000000.0 / (float64_t)(time[1] - time[0])) * 2.0;

        (void)dprintf(KSYST, "Image size: %"PRIu32" x %"PRIu32", Frame rate = %5.2f-fps\n", w, h, frameRate);
    }

// Kill the process & the ressources

    PRIVILEGE_RESTORE;

    INTERRUPTION_OFF;
    memo_free(image_0);
    memo_free(image_1);

    exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_callBack
 *
 * - Prepare an image (called by TinyUSB_video_sendImage)
 *
 */
static  void    local_callBack(const void *argument) {
    const   graphic_t   *pack;
    static  uint32_t    position = 0U;

    pack = (const graphic_t *)argument;

    local_prepareImage(pack->oImage, pack->oW, pack->oH, position++);
}

/*
 * \brief local_prepareImage
 *
 * - Prepare an image (vertical bars)
 *
 */
static  void    local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t position) {
                    uint32_t    i, x, y, bar;
                    uint32_t    shiftPairs;
                    uint32_t    pairsPerLine;
    static  const   uint8_t     aColorBars[8][4] = {
                                    { 235U, 128U, 235U, 128U },     // White
        { 219U,  16U, 219U, 138U },     // Yellow
        { 188U, 154U, 188U,  16U },     // Cyan
        { 173U,  42U, 173U,  26U },     // Green
        {  78U, 214U,  78U, 230U },     // Magenta
        {  63U, 102U,  63U, 240U },     // Red
        {  32U, 240U,  32U, 118U },     // Blue
        {  16U, 128U,  16U, 128U },     // Black
    };

    if ((w & 1U) != 0U) {
        return;
            }

    pairsPerLine = w / 2U;
    shiftPairs = position % pairsPerLine;

    for (y = 0U; y < h; y++) {
        uint8_t *p = image + ((size_t)y * (size_t)w * 2U);

        for (i = 0U; i < pairsPerLine; i++) {
            x = (i + shiftPairs) % pairsPerLine;
            bar = (x * 8U) / pairsPerLine;

            memcpy(p, aColorBars[bar], 4U);
            p += 4U;
        }
    }
}
