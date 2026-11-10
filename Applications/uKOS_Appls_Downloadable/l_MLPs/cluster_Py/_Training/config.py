# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

"""Network geometry, activations and training parameters for the cluster MLP.

Layer layout (the bias input of L2 and L3 is added automatically)::

    L1:  2 inputs -> 12 outputs
    L2: 12 inputs -> 24 outputs
    L3: 24 inputs ->  5 outputs

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
KLAYERS: Final = [2, 12, 24, 5]

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
KEPOCHS: Final = 200_000

# Rapid validation
# ----------------

#: Input/output samples for rapid validation: ``[x, y, t1, .., t5]``.
KVALIDATION: Final = [
    # x          y          C1    C2    C3    C4    C5
    [-0.988388,  0.867081,  0.98, 0.00, 0.00, 0.00, 0.00],   # C1, top-left
    [ 0.757057,  0.295996,  0.00, 0.98, 0.00, 0.00, 0.00],   # C2, top-right
    [ 0.327959, -0.888219,  0.00, 0.00, 0.00, 0.98, 0.00],   # C4, bottom-right
    [-0.478465, -0.454157,  0.00, 0.00, 0.98, 0.00, 0.00],   # C3, bottom-left
    [-0.561333, -0.588802,  0.00, 0.00, 0.98, 0.00, 0.00],   # C3, bottom-left
    [ 0.474768, -0.188733,  0.00, 0.00, 0.00, 0.98, 0.00],   # C4, bottom-right
]
