# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

"""Train a multi-layer perceptron by back-propagation and export it for mlpn.

The network is described by the ``config`` module of the application being
trained (``KLAYERS``, ``KNON_LINEAR``, ``KNON_LINEAR_OUT``, ``KGAIN``,
``KMOMENTUM``, ``KEPOCHS``, ``KVALIDATION``); the application's ``build.sh``
puts its ``_Training`` folder on ``PYTHONPATH`` so that ``import config``
finds it.

The learning dataset ``DB_L_file.txt`` holds one sample per line, columns
separated by whitespace::

    x1 x2 .. xn y1 y2 .. ym

with x the (normalised) input vector and y the expected output vector.

Training is stochastic: one random sample per epoch, quadratic error, plain
gradient descent with momentum. The error is plotted while training runs.
The trained network is written to ``network.c_inc`` in the form the uKOS-X
mlpn library (``mlpn.c``) expects, then run on the validation samples.

Requirements:
    python3 -m pip install numpy matplotlib

Usage (from an application's ``_Training`` folder, through its build.sh):
    python3 backprop.py
"""

import io
from collections.abc import Callable
from typing import NamedTuple

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.axes import Axes
from matplotlib.figure import Figure

import config

KDATASET_FILE = "DB_L_file.txt"     # Learning dataset
KNETWORK_FILE = "network.c_inc"     # Generated C network description
KDISPLAY_SHIFT = 50000              # Width of the plotted error window, in epochs
KDISPLAY_EVERY = 500                # Plot the error every KDISPLAY_EVERY epochs
KMLPN_NB_MAX_LAYERS = 5             # Size of the layer table of mlpnNetwork_t
KSEED = 0                           # Seed of the weight initialisation and sampling

Function = Callable[[np.ndarray], np.ndarray]


# Non-linear functions and their derivatives
# ------------------------------------------
#
# The functions of the mlpn library (mlpn.c), clamps included, so that a
# network is trained with the function the target runs: the name written
# into network.c_inc is the name used here.


def mlp_tanh(x: np.ndarray) -> np.ndarray:
    """KMLPN_TAN0, libm tanh."""
    return np.tanh(x)


def mlp_dtanh(x: np.ndarray) -> np.ndarray:
    """Derivative of KMLPN_TAN0."""
    return 1.0 - np.tanh(x) ** 2


def mlp_tan1(x: np.ndarray) -> np.ndarray:
    """KMLPN_TAN1, Lambert's continued fraction, clamped outside [-3, 3].

    With s = p², a = p (s³ + 378 s² + 17325 s + 135135) and
    b = 28 s³ + 3150 s² + 62370 s + 135135, the function is a / b.
    """
    s = x * x
    a = ((((s + 378.0) * s) + 17325.0) * s + 135135.0) * x
    b = ((((28.0 * s) + 3150.0) * s) + 62370.0) * s + 135135.0
    return np.where(x < -3.0, -1.0, np.where(x > 3.0, 1.0, a / b))


def mlp_dtan1(x: np.ndarray) -> np.ndarray:
    """Derivative of KMLPN_TAN1, zero where the function is clamped."""
    s = x * x
    a = ((((s + 378.0) * s) + 17325.0) * s + 135135.0) * x
    b = ((((28.0 * s) + 3150.0) * s) + 62370.0) * s + 135135.0
    da = ((((s + 378.0) * s) + 17325.0) * s + 135135.0) + (2.0 * s * ((((3.0 * s) + 756.0) * s) + 17325.0))
    db = 2.0 * x * ((((84.0 * s) + 6300.0) * s) + 62370.0)
    return np.where(np.abs(x) > 3.0, 0.0, ((da * b) - (a * db)) / (b * b))


def mlp_tan2(x: np.ndarray) -> np.ndarray:
    """KMLPN_TAN2, the Padé ratio p (27 + p²) / (27 + 9 p²), clamped outside ]-3, 3[."""
    x2 = x * x
    return np.where(x <= -3.0, -1.0, np.where(x >= 3.0, 1.0, (x * (27.0 + x2)) / (27.0 + (9.0 * x2))))


def mlp_dtan2(x: np.ndarray) -> np.ndarray:
    """Derivative of KMLPN_TAN2, (p² - 9)² / (9 (p² + 3)²).

    It is 1 at 0 and 0 at ±3, where it meets the clamp.
    """
    x2 = x * x
    return np.where(np.abs(x) >= 3.0, 0.0, ((x2 - 9.0) ** 2) / (9.0 * ((x2 + 3.0) ** 2)))


def mlp_tan3(x: np.ndarray) -> np.ndarray:
    """KMLPN_TAN3, a hard clamp to [-1, 1]."""
    return np.clip(x, -1.0, 1.0)


def mlp_dtan3(x: np.ndarray) -> np.ndarray:
    """Derivative of KMLPN_TAN3."""
    return np.where(np.abs(x) >= 1.0, 0.0, 1.0)


def mlp_relu(x: np.ndarray) -> np.ndarray:
    """KMLPN_RELU."""
    return np.where(x <= 0.0, 0.0, x)


def mlp_drelu(x: np.ndarray) -> np.ndarray:
    """Derivative of KMLPN_RELU."""
    return np.where(x <= 0.0, 0.0, 1.0)


def mlp_line(x: np.ndarray) -> np.ndarray:
    """KMLPN_LINE, the identity."""
    return x


def mlp_dline(x: np.ndarray) -> np.ndarray:
    """Derivative of KMLPN_LINE."""
    return np.ones_like(x)


def mlp_softmax(x: np.ndarray) -> np.ndarray:
    """KMLPN_SMAX, with the max subtracted as mlpn.c does."""
    x_shift = x - np.max(x, axis=0, keepdims=True)
    exp_x = np.exp(x_shift)
    return exp_x / np.sum(exp_x, axis=0, keepdims=True)


class Activation(NamedTuple):
    """A non-linear function f(z) and its derivative f'(z).

    KMLPN_SMAX is not elementwise and has no f'(z); see ``mlp_activation_delta``.
    """

    function: Function
    derivative: Function | None


KACTIVATIONS: dict[str, Activation] = {
    "KMLPN_TAN0": Activation(mlp_tanh, mlp_dtanh),
    "KMLPN_TAN1": Activation(mlp_tan1, mlp_dtan1),
    "KMLPN_TAN2": Activation(mlp_tan2, mlp_dtan2),
    "KMLPN_TAN3": Activation(mlp_tan3, mlp_dtan3),
    "KMLPN_RELU": Activation(mlp_relu, mlp_drelu),
    "KMLPN_LINE": Activation(mlp_line, mlp_dline),
    "KMLPN_SMAX": Activation(mlp_softmax, None),
}


def mlp_check_config() -> None:
    """Stop if ``config`` names a non-linear function mlpn does not have."""
    for name in (config.KNON_LINEAR, config.KNON_LINEAR_OUT):
        if name not in KACTIVATIONS:
            raise SystemExit(f"config.py: unknown non-linear function {name}; valid: {', '.join(KACTIVATIONS)}")


def mlp_layer_function(i: int, nb_layers: int) -> str:
    """Return the name of the non-linear function of layer ``i`` (0-based)."""
    return config.KNON_LINEAR_OUT if i == nb_layers - 1 else config.KNON_LINEAR


def mlp_activation(name: str, z: np.ndarray) -> np.ndarray:
    """Apply the non-linear function ``name`` to the potentials ``z``."""
    return KACTIVATIONS[name].function(z)


def mlp_activation_delta(name: str, potential: np.ndarray, output: np.ndarray, gradient: np.ndarray) -> np.ndarray:
    """Turn dE/d(output) into dE/d(potential) through the non-linear function ``name``."""
    if name == "KMLPN_SMAX":
        # J_softmax = diag(s) - s s^T, so for one sample
        # delta     = s * (gradient - sum(s * gradient))
        projection = np.sum(output * gradient, axis=0, keepdims=True)
        return output * (gradient - projection)

    derivative = KACTIVATIONS[name].derivative
    assert derivative is not None
    return gradient * derivative(potential)


# Dataset
# -------


def mlp_load_data(file_path: str = KDATASET_FILE) -> tuple[np.ndarray, np.ndarray]:
    """Load the learning dataset.

    Returns:
        ``(X, Y)``, one sample per column: the inputs (KNB_INPUTS rows) and
        the expected outputs (KNB_OUTPUTS rows).
    """
    data = np.loadtxt(file_path)
    X = data[:, : config.KNB_INPUTS].T
    Y = data[:, -config.KNB_OUTPUTS :].T
    return X, Y


# Forward and backward passes
# ---------------------------


def with_bias(a: np.ndarray) -> np.ndarray:
    """Append the constant bias input (a row of ones) to ``a``."""
    return np.vstack([a, np.ones((1, a.shape[1]))])


def mlp_forward(x: np.ndarray, weights: list[np.ndarray]) -> tuple[list[np.ndarray], list[np.ndarray]]:
    """Run the network on ``x`` (one sample per column).

    Returns:
        ``(outputs, potentials)``: the input followed by the output of every
        layer, and the potential (weighted sum) of every layer.
    """
    outputs = [x]
    potentials = []

    for i, w in enumerate(weights):
        z = np.dot(w, with_bias(outputs[-1]))
        potentials.append(z)
        outputs.append(mlp_activation(mlp_layer_function(i, len(weights)), z))
    return outputs, potentials


def mlp_backprop(
    weights: list[np.ndarray],
    outputs: list[np.ndarray],
    potentials: list[np.ndarray],
    y: np.ndarray,
    gain: float,
    momentum: float,
    previous_deltas: list[np.ndarray],
) -> tuple[list[np.ndarray], list[np.ndarray]]:
    """Back-propagate the error of one forward pass and update ``weights`` in place.

    The error is quadratic, E = 0.5 sum (output - y)², so dE/d(output) = output - y.

    Returns:
        ``(weights, deltas)``: the updated weights and the weight changes,
        which feed the momentum term of the next call.
    """
    nb_layers = len(weights)
    gradients: list[np.ndarray] = [np.empty(0)] * nb_layers

    # The last layer
    last = nb_layers - 1
    gradients[last] = mlp_activation_delta(
        mlp_layer_function(last, nb_layers), potentials[last], outputs[last + 1], outputs[last + 1] - y
    )

    # From the last layer - 1 down to the first one; the bias column takes no part
    for i in reversed(range(last)):
        W = weights[i + 1][:, :-1]
        gradients[i] = mlp_activation_delta(
            mlp_layer_function(i, nb_layers), potentials[i], outputs[i + 1], np.dot(W.T, gradients[i + 1])
        )

    deltas = []
    for i in range(nb_layers):
        dW = (-gain * np.dot(gradients[i], with_bias(outputs[i]).T)) + (momentum * previous_deltas[i])
        deltas.append(dW)
        weights[i] += dW
    return weights, deltas


# Export the C model for the mlpn library
# ---------------------------------------


def mlp_export_network(weights: list[np.ndarray], filename: str = KNETWORK_FILE) -> None:
    """Write ``weights`` to ``filename`` as an mlpn network description.

    Written in the repository's typography (CONTRIBUTING.md): no tabs, 4-column
    stops, upper-case F suffixes and trailing commas, so that a retrained network
    differs from the committed one by its weights only.
    """
    f = io.StringIO()

    f.write("// MLPN description\n")
    f.write("// ----------------\n\n")

    for index, w in enumerate(weights, 1):
        nb_out, nb_in = w.shape

        # Layer description
        f.write(f"// Layer {index}\n\n")

        f.write(f"#define\tKMLPN_L{index}_NB_IN\t{nb_in}\n")
        f.write(f"#define\tKMLPN_L{index}_NB_OUT\t{nb_out}\n")

        if index == 1:
            f.write("\n[[gnu::aligned(16)]]\nstatic\t\t\tfloat32_t\tvInput_L1_f[KMLPN_L1_NB_IN];\n")
        f.write(f"\n[[gnu::aligned(16)]]\nstatic\t\t\tfloat32_t\tvActivation_L{index}_f[KMLPN_L{index}_NB_OUT];\n")
        f.write(f"\n[[gnu::aligned(16)]]\nstatic\t\t\tfloat32_t\tvOutput_L{index}_f[KMLPN_L{index}_NB_OUT + 1];\n")
        f.write(
            f"\n[[gnu::aligned(16)]]\n"
            f"static\tconst\tfloat32_t\tvWeight_L{index}_f[KMLPN_L{index}_NB_OUT][KMLPN_L{index}_NB_IN] = {{\n"
        )
        for row in w:
            values = ", ".join(f"{v:.6f}f" for v in row)
            f.write(f"\t\t\t\t\t\t\t\t{{ {values} }},\n")
        f.write("\t\t\t\t\t\t\t};\n\n")

        # Layer structure
        function = config.KNON_LINEAR_OUT if index == len(weights) else config.KNON_LINEAR
        layer_input = "vInput_L1_f" if index == 1 else f"vOutput_L{index - 1}_f"

        f.write(f"static\tmlpnLayer_t\taLayer_L{index} = {{\n")
        f.write(f"\t\t\t\t\t\t\t{function},\n")
        f.write(f"\t\t\t\t\t\t\tKMLPN_L{index}_NB_IN,\n")
        f.write(f"\t\t\t\t\t\t\tKMLPN_L{index}_NB_OUT,\n")
        f.write(f"\t\t\t\t\t\t\t&{layer_input}[0],\n")
        f.write(f"\t\t\t\t\t\t\t&vActivation_L{index}_f[0],\n")
        f.write(f"\t\t\t\t\t\t\t&vOutput_L{index}_f[0],\n")
        f.write(f"\t\t\t\t\t\t\t&vWeight_L{index}_f[0][0]\n")
        f.write("\t\t\t\t\t\t};\n\n")

    # Network structure
    f.write("// The full network\n\n")

    f.write(f"#define\tKMLPN_NB_LAYERS\t{len(weights)}\n\n")

    f.write("static\tconst\tmlpnNetwork_t\taNetwork = {\n")
    f.write("\t\t\t\t\t\t\t\t\tKMLPN_NB_LAYERS,\n")
    for index in range(1, len(weights) + 1):
        f.write(f"\t\t\t\t\t\t\t\t\t&aLayer_L{index},\n")
    for _ in range(len(weights), KMLPN_NB_MAX_LAYERS):
        f.write("\t\t\t\t\t\t\t\t\tnullptr,\n")
    f.write("\t\t\t\t\t\t\t\t};\n")

    with open(filename, "w", encoding="utf-8") as out:
        out.write(f.getvalue().expandtabs(4))


# Validation and display
# ----------------------


def mlp_validation(weights: list[np.ndarray]) -> None:
    """Run the network on the samples of ``config.KVALIDATION`` and print the results."""
    print("\nTest samples:")
    for sample in config.KVALIDATION:
        x = np.array(sample[: config.KNB_INPUTS]).reshape(-1, 1)
        y_true = np.array(sample[-config.KNB_OUTPUTS :]).reshape(-1, 1)

        outputs, _ = mlp_forward(x, weights)
        y_pred = outputs[-1]
        error = 0.5 * np.mean((y_pred - y_true) ** 2)

        print(f"Input: {x.ravel()} | Target: {y_true.ravel()} → Pred: {y_pred.ravel()} | Err = {error:.6f}")


def display_error(fig: Figure, ax: Axes, shown_x: list[int], shown_y: list[float], epoch: int, error: float) -> None:
    """Add ``error`` to the plotted history and redraw the last KDISPLAY_SHIFT epochs."""
    shown_x.append(epoch)
    shown_y.append(error)

    x_visible = np.array(shown_x)
    y_visible = np.array(shown_y)
    mask = x_visible > (epoch - KDISPLAY_SHIFT)
    x_visible = x_visible[mask]
    y_visible = y_visible[mask]

    ax.clear()
    ax.plot(x_visible, y_visible, label="Quadratic Error")
    ax.set_xlabel("Epoch")
    ax.set_ylabel("Error")
    ax.set_title("Quadratic Error")
    ax.grid(True)
    ax.legend()
    ax.set_xlim(x_visible[0], x_visible[-1])

    y_min, y_max = float(np.min(y_visible)), float(np.max(y_visible))
    padding = 0.01 if abs(y_max - y_min) < 1e-6 else 0.05 * (y_max - y_min)
    ax.set_ylim(y_min - padding, y_max + padding)

    fig.canvas.draw()
    fig.canvas.flush_events()
    plt.pause(0.001)


def format_vector(v: np.ndarray) -> str:
    """Format ``v`` as ``[a, b, ...]`` with two decimals."""
    return "[" + ", ".join(f"{e:.2f}" for e in v.ravel()) + "]"


# Main
# ----


def main() -> None:
    """Train the network, export it to KNETWORK_FILE and validate it."""
    mlp_check_config()
    X, Y = mlp_load_data()
    nb_samples = X.shape[1]

    # A legacy RandomState, not default_rng(): it draws the same stream as the
    # former np.random.seed(KSEED), so a retrained network is unchanged.
    rng = np.random.RandomState(KSEED)

    # Small random initial weights; the extra column is the bias
    weights = [
        rng.randn(config.KLAYERS[i + 1], config.KLAYERS[i] + 1) * 0.5 for i in range(len(config.KLAYERS) - 1)
    ]
    previous_deltas = [np.zeros_like(w) for w in weights]

    shown_x: list[int] = []
    shown_y: list[float] = []
    plt.ion()
    fig, ax = plt.subplots()

    # One random sample per epoch: forward, error, back-propagation
    for epoch in range(config.KEPOCHS):
        index = rng.randint(nb_samples)
        x = X[:, index : index + 1]
        y = Y[:, index : index + 1]
        outputs, potentials = mlp_forward(x, weights)
        y_prediction = outputs[-1]
        error = 0.5 * np.mean((y_prediction - y) ** 2)

        if epoch % KDISPLAY_EVERY == 0:
            display_error(fig, ax, shown_x, shown_y, epoch, error)

        print(f"Epoch {epoch}: Err = {error:.6f} | y: {format_vector(y)} -> pred: {format_vector(y_prediction)}")

        weights, previous_deltas = mlp_backprop(
            weights, outputs, potentials, y, config.KGAIN, config.KMOMENTUM, previous_deltas
        )

    plt.ioff()
    plt.show()

    mlp_export_network(weights)
    mlp_validation(weights)


if __name__ == "__main__":
    main()
