# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

"""Train the class_TFL classifier and export it as a TensorFlow Lite model.

The learning dataset ``DB_L_file.txt`` (written by ``DB_Creator.py``) is
loaded, shuffled and used to train a small MLP; 20 % of it is held out for
validation. The trained model is saved in Keras format next to the TFLite
file, converted to TFLite, and the TFLite model is run on a few reference
points to check that it gives the same answers as the Keras model.

Network (the input layer has no weights)::

    L1:  2 inputs -> 52 outputs, tanh
    L2: 52 inputs -> 73 outputs, tanh
    L3: 73 inputs ->  3 outputs, softmax

Usage:
    python3 NN_model.py --model_file NN_model.tflite
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
    from ai_edge_litert import interpreter as tflite  # noqa: E402
    KOP_RESOLVER = tflite.OpResolverType.BUILTIN_WITHOUT_DEFAULT_DELEGATES
except ImportError:
    tflite = tf.lite
    KOP_RESOLVER = tf.lite.experimental.OpResolverType.BUILTIN_WITHOUT_DEFAULT_DELEGATES

KDATASET_FILE = "DB_L_file.txt"     # Learning dataset
KNB_INPUTS = 2                      # x, y
KNB_OUTPUTS = 3                     # One per class
KHIDDEN_LAYERS = (52, 73)           # Neurons of the hidden layers
KL2_FACTOR = 1e-4                   # L2 regularisation of the hidden layers
KLEARNING_RATE = 1e-3               # Adam learning rate
KEPOCHS = 100                       # Number of training epochs
KBATCH_SIZE = 32                    # Mini-batch size
KVALIDATION_SPLIT = 0.2             # Fraction of the dataset held out for validation

#: Reference inputs used to compare the Keras and TFLite outputs.
KTEST_INPUTS = np.array(
    [
        [0.912431, 0.719052],       # C3, square
        [-0.460302, -0.637331],     # C2, outer
        [-0.626125, -0.250060],     # C1, ring
    ],
    dtype=np.float32,
)


def load_data(file_path: str | Path) -> tuple[np.ndarray, np.ndarray]:
    """Load a whitespace-separated dataset and split it into inputs and targets.

    Any run of spaces or tabs separates the columns, so the files load the
    same whether their tabs were kept or expanded by an editor. Rows
    containing NaN or Inf are discarded.

    Returns:
        ``(X, Y)``: the inputs (x, y) and the one-hot targets (t1, t2, t3).

    Raises:
        OSError: If the file cannot be read.
        ValueError: If the file does not have KNB_INPUTS + KNB_OUTPUTS columns.
    """
    print(f"Read the file : {file_path}")
    data = np.atleast_2d(np.genfromtxt(file_path, dtype=np.float32))
    data = data[np.isfinite(data).all(axis=1)]

    print("Data read from the file :")
    print(data)

    nb_columns = KNB_INPUTS + KNB_OUTPUTS
    if data.shape[1] != nb_columns:
        raise ValueError(
            f"{file_path}: expected {nb_columns} columns (x, y, t1, t2, t3) per line, "
            f"found {data.shape[1]}"
        )

    return data[:, :KNB_INPUTS], data[:, KNB_INPUTS:]


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


def run_tflite(model_file: Path, inputs: np.ndarray) -> None:
    """Run the TFLite model in ``model_file`` on each row of ``inputs`` and print the outputs."""
    # Reference kernels only: no XNNPACK delegate (and no "Created TensorFlow Lite
    # XNNPACK delegate" message), closer to what TFLite Micro runs on the target.
    interpreter = tflite.Interpreter(
        model_path=str(model_file), experimental_op_resolver_type=KOP_RESOLVER
    )
    interpreter.allocate_tensors()
    input_index = interpreter.get_input_details()[0]["index"]
    output_index = interpreter.get_output_details()[0]["index"]

    for row in inputs:
        interpreter.set_tensor(input_index, row[np.newaxis, :])
        interpreter.invoke()
        print("Output TFLite", interpreter.get_tensor(output_index))


def parse_args() -> argparse.Namespace:
    """Parse the command-line arguments."""
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument(
        "--model_file",
        type=Path,
        required=True,
        help="path of the TFLite model to write (the Keras model is saved alongside it)",
    )
    return parser.parse_args()


def main() -> int:
    """Train, convert and check the model. Return the process exit status."""
    args = parse_args()
    tflite_file: Path = args.model_file
    keras_file = tflite_file.with_suffix(".keras")

    try:
        X, Y = load_data(KDATASET_FILE)
    except (OSError, ValueError) as error:
        print(f"Error: data cannot be loaded: {error}", file=sys.stderr)
        return 1

    # Shuffle: the file is grouped by class and validation_split takes the last rows.
    order = np.random.default_rng().permutation(len(X))
    X, Y = X[order], Y[order]

    model = build_model()
    model.fit(X, Y, epochs=KEPOCHS, batch_size=KBATCH_SIZE, validation_split=KVALIDATION_SPLIT)
    loss, accuracy = model.evaluate(X, Y)
    print(f"Loss of the model : {loss}, accuracy : {accuracy}")

    print("Output TF", model(KTEST_INPUTS))

    model.save(keras_file)
    tflite_file.write_bytes(tf.lite.TFLiteConverter.from_keras_model(model).convert())

    run_tflite(tflite_file, KTEST_INPUTS)
    return 0


if __name__ == "__main__":
    sys.exit(main())
