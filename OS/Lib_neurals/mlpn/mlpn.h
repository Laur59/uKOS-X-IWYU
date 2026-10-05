/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     mlpn manager.
 */

#pragma once

/*!
 * \addtogroup Lib_neurals
 */
/**@{*/

/*!
 * \defgroup mlpn Mlpn
 *
 * \brief Mlpn
 *
 * Mlpn management
 *
 * @{
 */

#include    <stdint.h>

#include    "types.h"

// Configuration structure
// -----------------------

typedef struct  mlpnNetwork     mlpnNetwork_t;
typedef struct  mlpnLayer       mlpnLayer_t;

struct mlpnNetwork {
            uint32_t        oNBLayer;                           // Number of layers
            mlpnLayer_t     *oLayer_L1;                         // Ptr on the layer 1
            mlpnLayer_t     *oLayer_L2;                         // Ptr on the layer 2
            mlpnLayer_t     *oLayer_L3;                         // Ptr on the layer 3
            mlpnLayer_t     *oLayer_L4;                         // Ptr on the layer 4
            mlpnLayer_t     *oLayer_L5;                         // Ptr on the layer 5
};

struct mlpnLayer {
            uint32_t        oNonLinear;                         // Non linear function
            uint32_t        oNBInput;                           // Number of inputs
            uint32_t        oNBOutput;                          // Number of outputs
            float32_t       *oInput;                            // Ptr on the input vector
            float32_t       *oActivation;                       // Ptr on the activation vector
            float32_t       *oOutput;                           // Ptr on the output vector
    const   float32_t       *oWeight;                           // Ptr on the weight matrix
};

// Non linear (oNonLinear)

enum {
            KMLPN_TAN0 = 0U,                                    // libm tanh
            KMLPN_TAN1,                                         // Lambert's tanh approximation
            KMLPN_TAN2,                                         // Ultrafast tanh approximation (~2% precision)
            KMLPN_TAN3,                                         // Fastest tanh approximation (less precise)
            KMLPN_RELU,                                         // Ultrafast relu
            KMLPN_LINE,                                         // Ultrafast linear
            KMLPN_SMAX,                                         // Ultrafast softmax
};

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

/*!
 * \brief Configure the mlpn manager
 *
 * Call example in C:
 *
 * \code{.c}
 * // Layer 1: 3 inputs + the bias, 5 neurons
 *
 * #define    KMLPN_L1_NB_IN     (3 + 1)
 * #define    KMLPN_L1_NB_OUT    5
 *
 * static                  float32_t          vInput_L1[KMLPN_L1_NB_IN];
 * static                  float32_t          vActivation_L1[KMLPN_L1_NB_OUT];
 * static                  float32_t          vOutput_L1[KMLPN_L1_NB_OUT + 1];
 * static     const        float32_t          vWeight_L1[KMLPN_L1_NB_OUT][KMLPN_L1_NB_IN] = {
 *                                                { -0.7654f,  1.3442f,  4.6543f,  3.1234f },
 *                                                {  0.2654f, -5.3442f,  1.6543f,  8.1234f },
 *                                                {  0.3654f,  6.3442f, -2.6543f,  7.1234f },
 *                                                {  0.4654f, -7.3442f,  6.6543f,  3.1234f },
 *                                                {  0.5654f, -6.3442f,  4.6543f,  1.1234f }
 *                                            };
 *
 * // A layer is not const: mlpnNetwork_t holds non-const mlpnLayer_t pointers.
 * // mlpn_configure writes the bias (the last entry) of each input vector
 *
 * static                  mlpnLayer_t        aLayer_L1 = {
 *                                                KMLPN_TAN0,
 *                                                KMLPN_L1_NB_IN,
 *                                                KMLPN_L1_NB_OUT,
 *                                                &vInput_L1[0],
 *                                                &vActivation_L1[0],
 *                                                &vOutput_L1[0],
 *                                                &vWeight_L1[0][0]
 *                                            };
 *
 * // Layer 2: the 5 outputs of layer 1 + the bias, 2 neurons
 *
 * #define    KMLPN_L2_NB_IN     (KMLPN_L1_NB_OUT + 1)
 * #define    KMLPN_L2_NB_OUT    2
 *
 * static                  float32_t          vActivation_L2[KMLPN_L2_NB_OUT];
 * static                  float32_t          vOutput_L2[KMLPN_L2_NB_OUT + 1];
 * static     const        float32_t          vWeight_L2[KMLPN_L2_NB_OUT][KMLPN_L2_NB_IN] = {
 *                                                { -0.3654f,  0.4654f,  0.3654f,  0.4654f,  0.5684f,  0.0654f },
 *                                                {  6.3442f,  7.3432f,  9.3482f,  8.3442f,  3.3472f,  2.3442f }
 *                                            };
 *
 * static                  mlpnLayer_t        aLayer_L2 = {
 *                                                KMLPN_TAN0,
 *                                                KMLPN_L2_NB_IN,
 *                                                KMLPN_L2_NB_OUT,
 *                                                &vOutput_L1[0],
 *                                                &vActivation_L2[0],
 *                                                &vOutput_L2[0],
 *                                                &vWeight_L2[0][0]
 *                                            };
 *
 * // The full network
 *
 * #define    KMLPN_NB_LAYERS    2
 *
 * static     const        mlpnNetwork_t      aNetwork = {
 *                                                KMLPN_NB_LAYERS,
 *                                                &aLayer_L1,
 *                                                &aLayer_L2,
 *                                                nullptr,
 *                                                nullptr,
 *                                                nullptr
 *                                            };
 *
 *    status = mlpn_configure(&aNetwork);
 * \endcode
 *
 * \param[in]   *network        Ptr on the network description
 * \return      KERR_MLPN_NOERR OK
 * \return      KERR_MLPN_GEERR General error (a layer count outside 1..5, a null layer)
 * \return      KERR_MLPN_CNERR Configuration error (an unknown non-linear function, no input or
 *                              no output, a null vector or weight matrix); nothing is written
 *
 */
extern  int32_t mlpn_configure(const mlpnNetwork_t *network);

/*!
 * \brief Compute the network
 *
 * Call example in C:
 *
 * \code{.c}
 * // Compute the network (declared as in the mlpn_configure example)
 *
 *    vInput_L1[0] = accelerationX;
 *    vInput_L1[1] = accelerationY;
 *    vInput_L1[2] = accelerationZ;
 *
 *    status = mlpn_compute(&aNetwork);
 *
 *    (void)dprintf(KSYST, "Activation %.3f %.3f, Output %.3f %.3f\n", (double)vActivation_L2[0],
 *                                                                      (double)vActivation_L2[1],
 *                                                                      (double)vOutput_L2[0],
 *                                                                      (double)vOutput_L2[1]);
 * \endcode
 *
 * \param[in]   *network        Ptr on the network description
 * \return      KERR_MLPN_NOERR OK
 * \return      KERR_MLPN_GEERR General error
 *
 */
extern  int32_t mlpn_compute(const mlpnNetwork_t *network);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
