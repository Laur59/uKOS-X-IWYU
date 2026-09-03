/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Image viewer.
 *           This tool allows to send an image via the uvc0 manager.
 */

#include    "viewer/viewer_uvc0.h"

#include    <stdint.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "Lib_peripherals/imager_common.h"
#include    "MT9V03x/MT9V03x.h"
#include    "imager/imager.h"
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

#ifdef CONFIG_MAN_IMAGER_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_GLB_CONST(aStrApplication[]) = "viewer       Send img0 images, via the uvc0 manager.   (c) EFr-2026";
STRG_GLB_CONST(aStrHelp[])        = "Acquire & send an image to the computer\n"
                                    "=======================================\n\n"

                                    "Input format:  viewer\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// CLI tool specific
// =================

// ---------------------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden_acquisition[]) = "Process_Acquisition";
STRG_LOC_CONST(aStrText_acquisition[]) = "Process Acquisition.                      (c) EFr-2026";

static  bool    vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

        void    TinyUSB_video_init(void);
        void    TinyUSB_video_clean(void);
        void    TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
        void    TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h, void (*callBack)(const void *argument), const void *argument);
static  void    local_initialiseYUY2(uint8_t *output, uint32_t w, uint32_t h);
static  void    local_convertToYUY2(volatile const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h);
static  void    aProcess_acquisition(const void *argument);

/*
 * \brief viewer_uvc0
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int32_t viewer_uvc0([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
    uint32_t    core;
    proc_t      *process;

    core = GET_RUNNING_CORE;
    vKillRequest[core] = false;

    RESERVE(IMAGER, KMODE_ALL);

// Specifications for the processes

    PROCESS(
        0,                                  // Index
        specification_acquisition,          // Specifications (just use specification_x)
        aStrText_acquisition,               // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_acquisition,               // Code of the process
        aStrIden_acquisition,               // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_HIGH_01              // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification_acquisition, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "viewer: create proc"); return EXIT_OS_FAILURE; }

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
int32_t viewer_uvc0_clean([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
    uint32_t    core;

    core = GET_RUNNING_CORE;
    vKillRequest[core] = true;

    return EXIT_OS_SUCCESS;
}

// Local routines
// ==============

/*
 * \brief aProcess_acquisition
 *
 * - P0: Waiting for the semaphore "imgx - Acquisition"
 *          - Acquire an image
 *          - Send an image
 *
 */
[[noreturn]]
static void aProcess_acquisition(const void *argument) {
                uint32_t        w, h;
                uint8_t         *imageYUY2;
                sema_t          *semaphore;
                imagerCnf_t     configureIMAGER;
    const       bool            *killRequest;
    volatile    void            *imageXX = nullptr;

    killRequest = (const bool *)argument;

    PRIVILEGE_ELEVATE;

    TinyUSB_video_init();
    TinyUSB_video_getImageSize(&w, &h);

    imageYUY2 = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (w * h * 2U), "viewer_uvc0_YUY2");
    if (imageYUY2 == nullptr) {
        LOG(KFATAL_USER, "viewer: out of memory");
        exit(EXIT_OS_FAILURE);
    }

    while (kern_getSemaphoreById(KIMAGER_SEMAPHORE_IM, &semaphore) != KERR_KERN_NOERR) { kern_suspendProcess(1U); }

// Configurations for an imager APTINA

    configureIMAGER.oAcqMode  = KIMAGER_SNAP;
    configureIMAGER.oImgCnf   = nullptr;
    configureIMAGER.oPixMode  = KIMAGER_PIX_8_BITS;
    configureIMAGER.oStRows   = 0U;
    configureIMAGER.oStCols   = 0U;
    configureIMAGER.oImagerNbRows   = KIMAGER_NB_ROWS;
    configureIMAGER.oImagerNbCols   = KIMAGER_NB_COLS;
    configureIMAGER.oFrameNbRows    = (uint16_t)h;
    configureIMAGER.oFrameNbCols    = (uint16_t)w;
    configureIMAGER.oKernSync       = 0U;
    configureIMAGER.oKernSync       = (1U<<(uint8_t)BIMAGER_SEMAPHORE_IM);
    configureIMAGER.oHSync    = nullptr;
    configureIMAGER.oFrame    = nullptr;
    configureIMAGER.oVSync          = nullptr;
    configureIMAGER.oDMAEc          = nullptr;

    if (imager_configure(&configureIMAGER) != KERR_IMAGER_NOERR) {
        (void)dprintf(KSYST, "img0 manager problem\n");
    }

    local_initialiseYUY2(imageYUY2, w, h);

// At the power-on the imager starts to send images.
// Just after the SNAP initialisation it is necessary waiting for the end of the
// current transfer (~ 40-ms) before starting.

    kern_suspendProcess(40U);
    imager_acquisition();

    while (!*killRequest) {
        kern_suspendProcess(50U);

// Waiting for the semaphore "imager - image ready"

        if (kern_waitSemaphore(semaphore, 1000U) == KERR_KERN_TIMEO) {
            TinyUSB_video_sendImage(imageYUY2, w, h, nullptr, nullptr);
            imager_acquisition();
        }
        else {
        imager_read(&imageXX);

            local_convertToYUY2((volatile const uint8_t *)imageXX, imageYUY2, w, h);
            TinyUSB_video_sendImage(imageYUY2, w, h, nullptr, nullptr);
        imager_acquisition();
    }
    }

// Kill the process & the ressources

// Stay elevated through the teardown: INTERRUPTION_OFF writes the interrupt
// mask, which is privileged, and the process is destroyed by exit() below.

    INTERRUPTION_OFF;
    RELEASE(IMAGER, KMODE_READ_WRITE);

    TinyUSB_video_clean();
    kern_killSemaphore(semaphore);
    memo_free(imageYUY2);
    exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_initialiseYUY2
 *
 * - Prepare the YUY2 image with U & V
 *      - i + 1 U = 128
 *      - i + 3 V = 128
 *
 */
static  void    local_initialiseYUY2(uint8_t *output, uint32_t w, uint32_t h) {
    uint32_t    i;

    for (i = 0U; i < (w * h); i += 2U) {
        output[(i * 2U) + 1U] = 128U;
        output[(i * 2U) + 3U] = 128U;
    }
}

/*
 * \brief local_convertToYUY2
 *
 * - Conversion 8-bit Gray scale to YUY2
 *      - i     Pix i
 *      - i + 1 128
 *      - i + 2 Pix i + 1
 *      - i + 3 128
 *
 */
static  void    local_convertToYUY2(volatile const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h) {
    uint32_t    i;

    for (i = 0U; i < (w * h); i += 2U) {

// Conversion Gray scale to YUY2

        output[i * 2U]        = input[i];
        output[(i * 2U) + 2U] = input[i + 1U];
    }
}
#endif
