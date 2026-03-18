/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 */

/*!
 * \file
 * \ingroup app_imaging
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 1 processes:
 *
 *          - P0: Repeat every xyz ms
 *                  - Prepare an image
 *                  - Send it over usb
 *
 *          1. Download the program video.s3
 *          2. Run the Mac Photo Booth
 */

#include    <inttypes.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#include    "crt0.h"
#include    "serial/serial.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "memo/memo.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "video        Example of how to send an image over usb. (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  video\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Video,                              // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                        // Family (defined in the module.h)
    KNUM_ROMABLE_0,                     // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    prgm,                               // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1u<<BSHOW) | (1u<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);

#else
MODULE(
    UserAppl,                           // Module name (the first letter has to be upper case)
    KID_FAM_APPLICATIONS,               // Family (defined in the module.h)
    KNUM_APPLICATION,                   // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    aStart,                             // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);
#endif

// Prototypes

        void    TinyUSB_video_init(void);
        void    TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
        void    TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h);
static  void    local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t startPosition);

/*
 * \brief aProcess
 *
 * - Px: Repeat every xyz ms
 *          - Prepare an image
 *          - Send it over usb
 *
 */
static void __attribute__ ((noreturn)) aProcess(const void *argument) {
            uint32_t    w, h, frame = 0;
            uint8_t     *image_0, *image_1;
            float64_t   frameRate = 0.0;
    static  uint64_t    vTime[2];

    UNUSED(argument);

    PRIVILEGE_ELEVATE;

    TinyUSB_video_init();

    TinyUSB_video_getImageSize(&w, &h);
    image_0 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h * 2U), "video");
    image_1 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h * 2U), "video");
    if ((image_0 == nullptr) || (image_1 == nullptr)) {
        LOG(KFATAL_USER, "Out of memory");
        exit(EXIT_OS_FAILURE);
    }

    while (true) {
        vTime[0] = vTime[1];
        kern_readTickCount(&vTime[1]);

        frameRate = (1000000.0 / (float64_t)(vTime[1] - vTime[0])) * 2.0;

// Send it over usb
// Prepare the next image

        local_prepareImage(image_0, w, h, frame);
        TinyUSB_video_sendImage(image_0, w, h);
        frame++;

        local_prepareImage(image_1, w, h, frame);
        TinyUSB_video_sendImage(image_1, w, h);
        frame++;

        (void)dprintf(KSYST, "Image size: %"PRIu32" x %"PRIu32", Frame rate = %5.2f-fps\n", w, h, frameRate);
    }
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
MAIN_ENTRY(argc, argv[]) {
    proc_t  *process;

// -------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden[]) = "Process_User";
    STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2026";

    UNUSED(argc);
    UNUSED(argv);

// Specifications for the processes

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess,                           // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_HIGH_05              // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

    LOG(KINFO_USER, "Application launched");
    return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_prepareImage
 *
 * - Prepare an image (vertical bars)
 *
 */
static  void    local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t startPosition) {
            uint8_t     *p, *end;
            uint32_t    i, j, idx;

// EBU color bars: https://stackoverflow.com/questions/6939422

    static  const   uint8_t     colorBars[8][4] = {

//           Y,    U,    Y,    V
        { 235U, 128U, 235U, 128U },     // 100% White
        { 219U,  16U, 219U, 138U },     // Yellow
        { 188U, 154U, 188U,  16U },     // Cyan
        { 173U,  42U, 173U,  26U },     // Green
        {  78U, 214U,  78U, 230U },     // Magenta
        {  63U, 102U,  63U, 240U },     // Red
        {  32U, 240U,  32U, 118U },     // Blue
        {  16U, 128U,  16U, 128U },     // Black
    };

// Generate the 1st line

    end = &image[w * 2U];
    idx = ((w / 2U) - 1U) - (startPosition % (w / 2U));
    p = &image[idx * 4U];

    for (i = 0U; i < 8U; i++) {
        for (j = 0U; j < (w / (2U * 8U)); j++) {

            memcpy(p, &colorBars[i], 4U);
            p += 4U;
            if (end <= p) {
                p = image;
            }
        }
    }

// Duplicate the 1st line to the others

    p = &image[w * 2U];
    for (i = 1U; i < h; i++) {

        memcpy(p, image, (w * 2U));
        p += w * 2U;
    }
}
