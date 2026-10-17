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
    float32_t   max_f;
    uint64_t    time[2];
    uint32_t    winner, winnerOut = 0U, delta = 0U;
    char_t      text[40];

    vInput_L1_f[0] = entry->oDataSet_f[0];
    vInput_L1_f[1] = entry->oDataSet_f[1];
    vInput_L1_f[2] = entry->oDataSet_f[2];
    vInput_L1_f[3] = entry->oDataSet_f[3];
    vInput_L1_f[4] = entry->oDataSet_f[4];
    vInput_L1_f[5] = entry->oDataSet_f[5];
    vInput_L1_f[6] = entry->oDataSet_f[6];
    vInput_L1_f[7] = entry->oDataSet_f[7];

    kern_readTickCount(&time[0]);
    mlpn_compute(&aNetwork);
    kern_readTickCount(&time[1]);
    delta = (uint32_t)(time[1] - time[0]);

// The winner take all

    winner = 0U; max_f = 0.0F;
    if (vOutput_L3_f[0] > max_f) { max_f = vOutput_L3_f[0]; winner = 2U; winnerOut = 0U;}
    if (vOutput_L3_f[1] > max_f) { max_f = vOutput_L3_f[1]; winner = 1U; winnerOut = 1U;}
    if (vOutput_L3_f[2] > max_f) {                          winner = 0U; winnerOut = 2U;}

// Display the results

    #if (defined(PRINT_THE_RESULTS_S))
    (void)dprintf(KSYST, "uKOS-X mlpn: result Out-Expected: %7.3f, %7.3f    %7.3f, %7.3f    %7.3f, %7.3f    Class DB = %s   Class Recognised = %s   "
                         "Exec time %"PRIu32" [us]\n", vOutput_L3_f[0],
                                                       entry->oDataSet_f[8],
                                                       vOutput_L3_f[1],
                                                       entry->oDataSet_f[9],
                                                       vOutput_L3_f[2],
                                                       entry->oDataSet_f[10],
                                                       entry->oClassLabel,
                                                       aClass[winner],
                                                       delta);
    #endif

    (void)snprintf(text, sizeof(text), "Probability: %4.1f %%", (vOutput_L3_f[winnerOut] * 100.0));
    ui_drawProbability(text);

    ui_drawClass(aClass[winner]);

    (void)snprintf(text, sizeof(text), "uKOS-X mlpn Ex. time: %" PRIu32 " [us]", delta);
    ui_drawMlpnExecutionTime(text);
}
