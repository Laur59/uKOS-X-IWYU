/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Demo of a C application.
 *          Hardware classifier.
 */

#include    <inttypes.h>
#include    <math.h>
#include    <stdlib.h>
#include    <stdio.h>

#include    "nn.h"
#include    "ui.h"

#ifdef USE_NN_HARDWARE
#include    "libNN_Hardware.h"
#include    "kern/kern.h"
#include    "types.h"

static  int8_t  vInput[KNN_INPUT_SIZE];
static  int8_t  vOutput[KNN_OUTPUT_SIZE];

// Prototypes

void    ui_drawNPUExecutionTime(const char_t *s);

/*
 * \brief nnh_init
 *
 * - Initialise the used resources
 *
 */
void    nnh_init(void) {

    nn_hardware_init();
}

/*
 * \brief nnh_classify
 *
 * - Classify a data vector
 *
 */
void    nnh_classify(float32_t *entry, uint8_t *face) {
    uint64_t    time[2];
    int32_t     q;
    uint32_t    i, delta = 0U;
    char_t      text[40];

// Prepare the inputs

    for (i = 0U; i < KNN_INPUT_SIZE; i++) {

// !!! Value extracted from the .tflite file

    #define KSCALE  0.03315797075629234F
    #define KZERO   -13

        q = (int32_t)roundf(entry[i] / KSCALE) + KZERO;

        if (q < -128) { q = -128; }
        if (q >  127) { q =  127; }

        vInput[i] = (int8_t)q;
    }

    nn_hardware_putInput(vInput);

    kern_readTickCount(&time[0]);
    nn_hardware_inference();
    kern_readTickCount(&time[1]);
    delta = (uint32_t)(time[1] - time[0]);

// Return the face

    nn_hardware_getOutput(vOutput);

    for (i = 0U; i < KNN_OUTPUT_SIZE; i++) {
        face[i] = (uint8_t)(vOutput[i] + 128);
    }

    (void)snprintf(text, sizeof(text), "NPU Ex. time: %" PRIu32 " [ms]", (delta / 1000));
    ui_drawNPUExecutionTime(text);
}
#endif
