# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

"""Train the debris classifier and export it as a TensorFlow Lite model.

The learning dataset ``DB_L_file.txt`` is loaded, shuffled and used to train
a small MLP that sorts 8 normalised features into 3 classes. Two modes:

* ``val``: train on 80 % of the dataset, report on the 20 % held out;
* ``full``: train on the whole dataset, report on it (what build.sh uses).

The trained model is converted to TFLite, and the TFLite model is run on a
few reference samples to check that it gives the same answers as the Keras
model.

Network (the input layer has no weights)::

    L1:  8 inputs -> 24 outputs, tanh
    L2: 24 inputs -> 12 outputs, tanh
    L3: 12 inputs ->  3 outputs, softmax

Usage:
    python3 NN_model.py --model_file NN_model.tflite [--mode val|full]
"""

import argparse
import logging
import os
import sys
from pathlib import Path

# Must be set before TensorFlow is imported, otherwise the C++ runtime has
# already read it. 0 = all logs, 1 = info, 2 = warning, 3 = error only.
os.environ["TF_CPP_MIN_LOG_LEVEL"] = "3"

import numpy as np  # noqa: E402
import tensorflow as tf  # noqa: E402

logging.getLogger("absl").setLevel(logging.ERROR)

# tf.lite.Interpreter is deprecated in favour of LiteRT (package ai-edge-litert).
# Use LiteRT when it is installed; otherwise fall back to tf.lite.Interpreter,
# whose deprecation warning then reaches the log as a reminder to install it.
try:
    from ai_edge_litert import interpreter as tflite

    KOP_RESOLVER = tflite.OpResolverType.BUILTIN_WITHOUT_DEFAULT_DELEGATES
except ImportError:
    tflite = tf.lite
    KOP_RESOLVER = tf.lite.experimental.OpResolverType.BUILTIN_WITHOUT_DEFAULT_DELEGATES

KDATASET_FILE = "DB_L_file.txt"     # Learning dataset
KNB_INPUTS = 8                      # x1 .. x8
KNB_OUTPUTS = 3                     # One per class
KHIDDEN_LAYERS = (24, 12)           # Neurons of the hidden layers
KL2_FACTOR = 1e-4                   # L2 regularisation of the hidden layers
KLEARNING_RATE = 1e-3               # Adam learning rate
KEPOCHS = 2000                      # Maximum number of training epochs
KBATCH_SIZE = 16                    # Mini-batch size
KPATIENCE = 50                      # Epochs without improvement before stopping
KTRAIN_FRACTION = 0.8               # Fraction of the dataset trained on in "val" mode
KSEED = 42                          # Seed of NumPy and TensorFlow, for reproducibility

#: Reference inputs used to compare the Keras and TFLite outputs.
KTEST_INPUTS = np.array(
    [
        [-0.667143288, -0.792564809, -0.507299776, -0.853254438, -0.280102586,  1.0,         -0.612416107, -0.984712332],
        [-0.865927732, -0.951664954, -0.983669003, -0.550295858, -0.994026501, -0.94423152,  -0.203020134, -0.996673267],
        [ 0.189591578, -0.954907283, -0.992381638,  0.797724169, -0.994469972,  0.199817193, -0.874161074, -0.99937882 ],
        [-0.523614221, -0.866881953, -0.50477879,  -0.981247155, -0.276196837, -0.984622643, -0.763422819, -0.995785614],
        [-0.583224976, -0.854860126, -0.507119705, -0.789167046, -0.282229109,  0.199817193, -0.484899329, -0.975107079],
        [-0.102865637, -0.951312904, -0.491356622, -0.622758307, -0.264372729, -0.000278533, -0.818791946, -0.992837852],
    ],
    dtype=np.float32,
)  # fmt: skip


def load_data(file_path: str | Path) -> tuple[np.ndarray, np.ndarray]:
    """Load a whitespace-separated dataset and split it into inputs and targets.

    Any run of spaces or tabs separates the columns. Rows containing NaN or
    Inf are discarded.

    Returns:
        ``(X, Y)``: the inputs (x1 .. x8) and the one-hot targets (y1, y2, y3).

    Raises:
        OSError: If the file cannot be read.
        ValueError: If the file does not have KNB_INPUTS + KNB_OUTPUTS columns,
            or a target row is not one-hot.
    """
    print(f"Read the file : {file_path}")
    data = np.atleast_2d(np.genfromtxt(file_path, dtype=np.float32))
    data = data[np.isfinite(data).all(axis=1)]

    print("Data read from the file :")
    print(data)

    nb_columns = KNB_INPUTS + KNB_OUTPUTS
    if data.shape[1] != nb_columns:
        raise ValueError(
            f"{file_path}: expected {nb_columns} columns (x1 .. x8, y1, y2, y3) per line, "
            f"found {data.shape[1]}"
        )

    X, Y = data[:, :KNB_INPUTS], data[:, KNB_INPUTS:]
    if not np.all(np.sum(Y, axis=1) == 1):
        raise ValueError(f"{file_path}: each target row must be one-hot encoded (sum = 1)")

    return X, Y


def build_model() -> tf.keras.Model:
    """Build and compile the MLP classifier."""
    regularizer = tf.keras.regularizers.l2(KL2_FACTOR)
    model = tf.keras.Sequential(
        [
            tf.keras.layers.InputLayer(shape=(KNB_INPUTS,), dtype=tf.float32),
            *(
                tf.keras.layers.Dense(units, activation="tanh", kernel_regularizer=regularizer)
                for units in KHIDDEN_LAYERS
            ),
            tf.keras.layers.Dense(KNB_OUTPUTS, activation="softmax"),
        ]
    )
    model.compile(
        optimizer=tf.keras.optimizers.Adam(learning_rate=KLEARNING_RATE),
        loss="categorical_crossentropy",
        metrics=["accuracy"],
    )
    return model


def print_confusion_matrix(y_true: np.ndarray, y_pred: np.ndarray, title: str = "Confusion matrix") -> None:
    """Print the confusion matrix of the class indices ``y_true`` and ``y_pred``."""
    cm = tf.math.confusion_matrix(y_true, y_pred, num_classes=KNB_OUTPUTS).numpy()

    print(f"\n{title} :")
    print("           " + "   ".join(f"Pred {j}" for j in range(KNB_OUTPUTS)))
    for i, row in enumerate(cm):
        print(f"True {i}    " + "   ".join(f"{n:6d}" for n in row))


def train_and_report(model: tf.keras.Model, X: np.ndarray, Y: np.ndarray, mode: str) -> None:
    """Train ``model`` in ``mode`` and print the loss, accuracy and confusion matrix.

    In "val" mode the last (1 - KTRAIN_FRACTION) of the samples are held out,
    early stopping watches their loss and the report is on them; in "full"
    mode everything is trained on and reported on.
    """
    if mode == "val":
        split_index = int(KTRAIN_FRACTION * len(X))
        X_train, Y_train = X[:split_index], Y[:split_index]
        X_report, Y_report = X[split_index:], Y[split_index:]
        validation_data = (X_report, Y_report)
        monitor, label = "val_loss", "Validation"
    else:
        X_train, Y_train = X, Y
        X_report, Y_report = X, Y
        validation_data = None
        monitor, label = "loss", "Train"

    early_stop = tf.keras.callbacks.EarlyStopping(
        monitor=monitor, patience=KPATIENCE, restore_best_weights=True, verbose=1
    )
    model.fit(
        X_train,
        Y_train,
        epochs=KEPOCHS,
        batch_size=KBATCH_SIZE,
        validation_data=validation_data,
        callbacks=[early_stop],
        verbose=1,
    )

    loss, accuracy = model.evaluate(X_report, Y_report, verbose=0)
    print(f"\n{label} loss     : {loss:.6f}")
    print(f"{label} accuracy : {accuracy:.6f}")

    y_true = np.argmax(Y_report, axis=1)
    y_pred = np.argmax(model.predict(X_report, verbose=0), axis=1)
    print_confusion_matrix(y_true, y_pred, f"{label} confusion matrix")


def run_tflite(model_file: Path, inputs: np.ndarray) -> np.ndarray:
    """Run the TFLite model in ``model_file`` on each row of ``inputs``.

    Reference kernels only: no XNNPACK delegate (and no "Created TensorFlow
    Lite XNNPACK delegate" message), closer to what TFLite Micro runs on the
    target.

    Returns:
        The outputs, one row per input.
    """
    interpreter = tflite.Interpreter(model_path=str(model_file), experimental_op_resolver_type=KOP_RESOLVER)
    interpreter.allocate_tensors()
    input_index = interpreter.get_input_details()[0]["index"]
    output_index = interpreter.get_output_details()[0]["index"]

    outputs = []
    for row in inputs:
        interpreter.set_tensor(input_index, row[np.newaxis, :])
        interpreter.invoke()
        output = interpreter.get_tensor(output_index)
        print("Output TFLite", output)
        outputs.append(output[0])
    return np.array(outputs, dtype=np.float32)


def parse_args() -> argparse.Namespace:
    """Parse the command-line arguments."""
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument(
        "--model_file",
        type=Path,
        required=True,
        help="path of the TFLite model to write",
    )
    parser.add_argument(
        "--mode",
        choices=["val", "full"],
        default="val",
        help="val = train on 80%% and validate on 20%%, full = train on all data",
    )
    return parser.parse_args()


def main() -> int:
    """Train, convert and check the model. Return the process exit status."""
    args = parse_args()
    tflite_file: Path = args.model_file

    np.random.seed(KSEED)
    tf.random.set_seed(KSEED)

    try:
        X, Y = load_data(KDATASET_FILE)
    except (OSError, ValueError) as error:
        print(f"Error: data cannot be loaded: {error}", file=sys.stderr)
        return 1

    # Shuffle: the file is grouped by class and "val" mode holds out the last rows.
    order = np.random.permutation(len(X))
    X, Y = X[order], Y[order]

    model = build_model()
    train_and_report(model, X, Y, args.mode)

    output = model(KTEST_INPUTS, training=False).numpy()
    print("\nOutput TF")
    print(output)
    print("Predicted classes TF :", np.argmax(output, axis=1))

    tflite_file.write_bytes(tf.lite.TFLiteConverter.from_keras_model(model).convert())

    tflite_outputs = run_tflite(tflite_file, KTEST_INPUTS)
    print("Predicted classes TFLite :", np.argmax(tflite_outputs, axis=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
