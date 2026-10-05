/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 */

#pragma once

/*!
 * \defgroup Lib_neurals Library for the neural networks
 *
 * \brief Neural network manager system calls
 *
 * The Lib_neurals library introduces the mlpn manager, focused on multi
 * layer perceptron networks. It runs networks that were trained beforehand.
 *
 * The mlpn manager evaluates networks of layers, each with weights and
 * activations. Together they form models that can recognise complex patterns.
 * The training is done off the target: mlpn/backprop.py adjusts the weights
 * by back propagation, learning from examples step by step, and exports them
 * as C tables for the manager.
 *
 * The manager itself performs forward evaluation only - it runs a trained
 * network, it does not learn. Applications are many. From classification of signals to prediction of
 * trends, the mlpn manager delivers flexibility and power to developers.
 *
 * With Lib_neurals, perception becomes programmable, and learning is not a
 * mystery but a process shaped by clear design and careful structure.
 *
 * @{
 */

#ifdef CONFIG_MAN_MLPN_S
#include    "mlpn/mlpn.h"       // IWYU pragma: export
#endif

/**!@}*/
