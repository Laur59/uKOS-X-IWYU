# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

"""Network geometry, activations and training parameters for the classifier MLP.

Layer layout (the bias input of L2 and L3 is added automatically)::

    L1:  2 inputs -> 52 outputs
    L2: 52 inputs -> 73 outputs
    L3: 73 inputs ->  3 outputs

Available activation functions:

* ``KMLPN_TAN0``: libm tanh
* ``KMLPN_TAN1``: Lambert's tanh approximation
* ``KMLPN_TAN2``: ultrafast tanh approximation (~2 % precision)
* ``KMLPN_TAN3``: fastest tanh approximation (less precise)
* ``KMLPN_RELU``: ultrafast ReLU
* ``KMLPN_LINE``: ultrafast linear
* ``KMLPN_SMAX``: ultrafast softmax
"""

from typing import Final

# Network geometry
# ----------------

#: Neurons per layer: inputs, then the outputs of L1, L2 and L3.
KLAYERS: Final = [2, 52, 73, 3]

#: Number of network inputs (x, y).
KNB_INPUTS: Final = KLAYERS[0]

#: Number of network outputs (one per class).
KNB_OUTPUTS: Final = KLAYERS[-1]

# Activation functions
# --------------------

#: Activation of the hidden layers (L1, L2).
KNON_LINEAR: Final = "KMLPN_TAN2"

#: Activation of the output layer (L3).
KNON_LINEAR_OUT: Final = "KMLPN_SMAX"

# Training parameters
# -------------------

#: Learning rate.
KGAIN: Final = 0.005

#: Momentum term of the gradient descent.
KMOMENTUM: Final = 0.0

#: Number of training epochs.
KEPOCHS: Final = 1_000_000

# Rapid validation
# ----------------

#: Input/output samples for rapid validation: ``[x, y, t1, t2, t3]``.
KVALIDATION: Final = [
    # x          y          C1    C2    C3
    [ 0.490344,  0.051584,  0.98, 0.0,  0.0 ],   # C1, ring
    [ 0.458057, -0.458232,  0.98, 0.0,  0.0 ],   # C1, ring
    [ 0.266116,  0.944208,  0.0,  0.98, 0.0 ],   # C2, outer
    [-0.002234, -0.117944,  0.0,  0.98, 0.0 ],   # C2, inner
    [ 0.834344,  0.854564,  0.0,  0.0,  0.98],   # C3, square
]
