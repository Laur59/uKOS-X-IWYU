/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 *  Goal:   Demo of a C application.
 *          mlpn classifier.
 */

#include    <math.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#include    "ulvgl.h"
#include    "database.h"
#include    "kern/temporal.h"
#include    "mlpn/mlpn.h"
#include    "serial/serial.h"

// MLP model

#include    "./_Models/network.c_inc"

extern  void    ui_drawProbability(const char_t *s);
extern  void    ui_drawClass(const char_t *s);
extern  void    ui_drawMlpnExecutionTime(const char_t *s);

/*
 * \brief mlpn_init
 *
 * - Initialise the used resources
 *
 */
void    mlpn_init(void) {

    mlpn_configure(&aNetwork);
}

/*
 * \brief mlpn_classify
 *
 * - Classify a data vector
 *
 */
void    mlpn_classify(const dataBase_t *entry) {
    float32_t   max;
    uint64_t    time[2];
    uint32_t    winner, winnerOut = 0U, delta = 0U;
    char_t      text[40];

    vInput_L1[0] = entry->oDataSet[0];
    vInput_L1[1] = entry->oDataSet[1];
    vInput_L1[2] = entry->oDataSet[2];
    vInput_L1[3] = entry->oDataSet[3];
    vInput_L1[4] = entry->oDataSet[4];
    vInput_L1[5] = entry->oDataSet[5];
    vInput_L1[6] = entry->oDataSet[6];
    vInput_L1[7] = entry->oDataSet[7];

    kern_readTickCount(&time[0]);
    mlpn_compute(&aNetwork);
    kern_readTickCount(&time[1]);
    delta = (uint32_t)(time[1] - time[0]);

// The winner take all

    winner = 0U; max = 0.0F;
    if (vOutput_L3[0] > max) { max = vOutput_L3[0]; winner = 2U; winnerOut = 0U;}
    if (vOutput_L3[1] > max) { max = vOutput_L3[1]; winner = 1U; winnerOut = 1U;}
    if (vOutput_L3[2] > max) {                      winner = 0U; winnerOut = 2U;}

// Display the results

    #if (defined(PRINT_THE_RESULTS_S))
    (void)dprintf(KSYST, "uKOS-X mlpn: result Out-Expected: %7.3f, %7.3f    %7.3f, %7.3f    %7.3f, %7.3f    Class DB = %s   Class Recognised = %s   "
                         "Exec time %"PRIu32" [us]\n", vOutput_L3[0],
                                                       entry->oDataSet[8],
                                                       vOutput_L3[1],
                                                       entry->oDataSet[9],
                                                       vOutput_L3[2],
                                                       entry->oDataSet[10],
                                                       entry->oClassLabel,
                                                       aClass[winner],
                                                       delta);
    #endif

    (void)snprintf(text, sizeof(text), "Probability: %4.1f %%", (vOutput_L3[winnerOut] * 100.0));
    ui_drawProbability(text);

    ui_drawClass(aClass[winner]);

    (void)snprintf(text, sizeof(text), "uKOS-X mlpn Ex. time: %" PRIu32 " [us]", delta);
    ui_drawMlpnExecutionTime(text);
}
