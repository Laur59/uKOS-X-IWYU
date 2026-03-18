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
 * layer perceptron networks. It provides the building blocks of learning.
 *
 * The mlpn manager creates networks of layers, each with weights and
 * activations. Together they form models that can recognise complex patterns.
 * Training is central. With iterative adjustment, the perceptron learns from
 * examples, reducing error and improving its predictions step by step.
 *
 * The manager supports forward evaluation as well as back propagation. This
 * cycle of trial and correction is the essence of machine intelligence.
 * Applications are many. From classification of signals to prediction of
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
