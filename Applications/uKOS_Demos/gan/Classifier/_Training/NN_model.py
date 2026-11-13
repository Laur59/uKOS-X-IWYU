# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

"""Train a GAN to generate faces and export its generator as a TensorFlow Lite model.

The face images of ``DB_faces`` (written by ``DB_Creator.py`` from the
scikit-learn dataset) are loaded as 64x64 grayscale images scaled to
[-1, 1], and a generator and a discriminator are trained against each other.
Every DISPLAY_EVERY epochs the generator is run on a fixed set of latent
vectors and the 16 faces are plotted and saved to ``generated_faces``; every
CHECKPOINT_EVERY epochs, and at the last one, the generator is saved in Keras
and int8 TFLite format, so that a better-looking epoch can be picked by hand
(see README.md). ``--export`` turns such a Keras checkpoint into the TFLite
model again, in seconds and without training.

Only the generator is exported, quantised to int8 for TensorFlow Lite Micro.
The int8 ranges are calibrated on NB_CALIBRATION_SAMPLES random latent
vectors drawn from ``--calibration-seed``: a given checkpoint and seed always
give the same model, and another seed gives another calibration, which can
be compared by eye.

Generator (embedded-friendly CNN, channels 96 -> 48 -> 24 -> 12 -> 8 -> 8 -> 1)::

    latent vector of LATENT_DIM float32 values
    Dense(4 x 4 x 96), ReLU, Reshape(4, 4, 96)
    Resize  8x8,   Conv2D(48), BatchNorm, ReLU
    Resize 16x16,  Conv2D(24), BatchNorm, ReLU
    Resize 32x32,  Conv2D(12), BatchNorm, ReLU
    Resize 64x64,  Conv2D(8),  BatchNorm, ReLU
                   Conv2D(8),  BatchNorm, ReLU     (feature refinement)
                   Conv2D(1),  tanh                -> 64x64 image in [-1, 1]

The resizes are nearest-neighbour. BatchNormalization stabilises the GAN
training and is folded into the convolution weights by the TFLite
converter, as are the ReLUs, so the exported model uses only
FullyConnected, Reshape, ResizeNearestNeighbor, Conv2D and Tanh.

Discriminator (training only, never exported)::

    64x64 grayscale image
    Conv2D(24), stride 2, LeakyReLU(0.2)
    Conv2D(48), stride 2, LeakyReLU(0.2)
    Conv2D(96), stride 2, LeakyReLU(0.2)
    Flatten, Dense(96), LeakyReLU(0.2)
    Dense(1)                                       -> logit "real face"

Output files of a training:
    * ``generated_faces/generated_epoch_xxxx.png``
    * ``generator_epoch_xxxx.keras``, ``generator_epoch_xxxx.tflite``
    * the TFLite model named by ``--model_file`` (the last epoch)

Usage:
    python3 NN_model.py --model_file NN_model.tflite [--mode full] [--calibration-seed N]
    python3 NN_model.py --export generator_epoch_xxxx.keras --model_file NN_model.tflite [--calibration-seed N]
"""

import argparse
import contextlib
import io
import sys
from collections.abc import Callable, Iterator
from pathlib import Path

import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from PIL import Image
from tensorflow.keras import layers

# Configuration
# -------------

IMAGE_FOLDER = Path("DB_faces")             # Training images
OUTPUT_DIR = Path("generated_faces")        # Plots of the generated faces
IMAGE_SUFFIXES = (".png", ".jpg", ".jpeg")  # Image files loaded from IMAGE_FOLDER

IMG_SIZE = 64                               # Side of the square images, in pixels
LATENT_DIM = 64                             # Size of the generator input

BATCH_SIZE = 32                             # Mini-batch size
EPOCHS = 1000                               # Number of training epochs (0 .. EPOCHS inclusive)
DISPLAY_EVERY = 5                           # Plot the generated faces every DISPLAY_EVERY epochs
CHECKPOINT_EVERY = 50                       # Save the generator every CHECKPOINT_EVERY epochs
NB_SHOWN_FACES = 16                         # Faces plotted, on a 4 x 4 grid

LEARNING_RATE_G = 0.0001                    # Adam learning rate of the generator
LEARNING_RATE_D = 0.0002                    # Adam learning rate of the discriminator
ADAM_BETA_1 = 0.5                           # Adam beta_1 of both optimisers
REAL_LABEL = 0.9                            # One-sided label smoothing of the real images

NB_CALIBRATION_SAMPLES = 500                # Latent vectors used to calibrate the int8 quantisation
CALIBRATION_SEED = 0                        # Default seed of those latent vectors

FINAL_TFLITE_FILE = Path("NN_model.tflite")


# Load the learning dataset
# -------------------------


def load_faces_from_folder(folder: Path) -> np.ndarray:
    """Load every image of ``folder`` as a grayscale IMG_SIZE x IMG_SIZE array.

    Returns:
        A float32 array of shape (N, IMG_SIZE, IMG_SIZE, 1), scaled to [-1, 1].

    Raises:
        RuntimeError: If ``folder`` holds no image.
    """
    image_paths = sorted(path for path in folder.glob("*") if path.suffix in IMAGE_SUFFIXES)
    if not image_paths:
        raise RuntimeError(f"No images in the folder {folder}")

    print(f"{len(image_paths)} images found.")

    faces = []
    for i, path in enumerate(image_paths):
        img = Image.open(path).convert("L").resize((IMG_SIZE, IMG_SIZE), Image.Resampling.LANCZOS)

        # Scaling [0, 255] -> [-1, 1]
        faces.append(np.asarray(img, dtype=np.float32) / 127.5 - 1.0)

        if i % 100 == 0:
            print(f"Loaded {i}/{len(image_paths)}")

    # (N, IMG_SIZE, IMG_SIZE) -> (N, IMG_SIZE, IMG_SIZE, 1)
    return np.expand_dims(np.array(faces, dtype=np.float32), axis=-1)


# Models
# ------


def conv_block(filters: int) -> list[layers.Layer]:
    """Return a 3x3 convolution to ``filters`` channels, followed by BatchNorm and ReLU."""
    return [
        layers.Conv2D(filters, 3, padding="same"),
        layers.BatchNormalization(),
        layers.ReLU(),
    ]


def upsample_block(size: int, filters: int) -> list[layers.Layer]:
    """Return the layers that resize to ``size`` x ``size`` and convolve to ``filters`` channels."""
    return [
        layers.Resizing(size, size, interpolation="nearest"),
        *conv_block(filters),
    ]


def build_generator() -> tf.keras.Model:
    """Build the generator: a LATENT_DIM vector in, a 64x64 image in [-1, 1] out."""
    return tf.keras.Sequential(
        [
            layers.Input(shape=(LATENT_DIM,)),
            layers.Dense(4 * 4 * 96),
            layers.ReLU(),
            layers.Reshape((4, 4, 96)),
            *upsample_block(8, 48),
            *upsample_block(16, 24),
            *upsample_block(32, 12),
            *upsample_block(64, 8),
            *conv_block(8),
            layers.Conv2D(1, 3, padding="same", activation="tanh"),
        ]
    )


def build_discriminator() -> tf.keras.Model:
    """Build the discriminator: a 64x64 image in, one "real face" logit out."""
    return tf.keras.Sequential(
        [
            layers.Input((IMG_SIZE, IMG_SIZE, 1)),
            *(
                layer
                for filters in (24, 48, 96)
                for layer in (layers.Conv2D(filters, 4, strides=2, padding="same"), layers.LeakyReLU(0.2))
            ),
            layers.Flatten(),
            layers.Dense(96),
            layers.LeakyReLU(0.2),
            layers.Dense(1),
        ]
    )


# Loss functions
# --------------

cross_entropy = tf.keras.losses.BinaryCrossentropy(from_logits=True)


def discriminator_loss(real_output: tf.Tensor, fake_output: tf.Tensor) -> tf.Tensor:
    """Loss of the discriminator: real images towards REAL_LABEL, fakes towards 0."""
    real_loss = cross_entropy(tf.ones_like(real_output) * REAL_LABEL, real_output)
    fake_loss = cross_entropy(tf.zeros_like(fake_output), fake_output)
    return real_loss + fake_loss


def generator_loss(fake_output: tf.Tensor) -> tf.Tensor:
    """Loss of the generator: its fakes taken for real images."""
    return cross_entropy(tf.ones_like(fake_output), fake_output)


# Display & save images
# ---------------------


def show_and_save_generated_images(generator: tf.keras.Model, noise: tf.Tensor, epoch: int) -> None:
    """Plot the faces ``generator`` makes from ``noise`` and save the plot to OUTPUT_DIR."""
    generated = ((generator(noise, training=False) + 1.0) / 2.0).numpy()

    plt.close("all")
    fig = plt.figure(figsize=(6, 6))

    for i in range(NB_SHOWN_FACES):
        ax = fig.add_subplot(4, 4, i + 1)
        ax.imshow(generated[i, :, :, 0], cmap="gray", vmin=0, vmax=1)
        ax.axis("off")

    fig.suptitle(f"Epoch {epoch}")

    filename = OUTPUT_DIR / f"generated_epoch_{epoch:04d}.png"
    fig.savefig(filename)

    plt.show(block=False)
    plt.pause(0.1)

    print(f"Image saved : {filename}")


# Training
# --------


@tf.function
def train_step(
    real_images: tf.Tensor,
    generator: tf.keras.Model,
    discriminator: tf.keras.Model,
    g_optimizer: tf.keras.optimizers.Optimizer,
    d_optimizer: tf.keras.optimizers.Optimizer,
) -> tuple[tf.Tensor, tf.Tensor]:
    """Train the discriminator, then the generator, on one batch.

    Returns:
        ``(g_loss, d_loss)``: the losses of the generator and the discriminator.
    """
    batch_size = tf.shape(real_images)[0]

    # Training the discriminator
    noise = tf.random.normal([batch_size, LATENT_DIM])
    with tf.GradientTape() as d_tape:
        fake_images = generator(noise, training=True)
        real_output = discriminator(real_images, training=True)
        fake_output = discriminator(fake_images, training=True)
        d_loss = discriminator_loss(real_output, fake_output)

    d_gradients = d_tape.gradient(d_loss, discriminator.trainable_variables)
    d_optimizer.apply_gradients(zip(d_gradients, discriminator.trainable_variables))

    # Training the generator
    noise = tf.random.normal([batch_size, LATENT_DIM])
    with tf.GradientTape() as g_tape:
        fake_images = generator(noise, training=True)
        fake_output = discriminator(fake_images, training=False)
        g_loss = generator_loss(fake_output)

    g_gradients = g_tape.gradient(g_loss, generator.trainable_variables)
    g_optimizer.apply_gradients(zip(g_gradients, generator.trainable_variables))
    return g_loss, d_loss


# Export
# ------


def representative_dataset(seed: int) -> Callable[[], Iterator[list[np.ndarray]]]:
    """Return the calibration dataset of the int8 quantisation for ``seed``.

    The converter calls the returned function to get its samples; each call
    yields the same NB_CALIBRATION_SAMPLES latent vectors for a given seed.
    """

    def dataset() -> Iterator[list[np.ndarray]]:
        rng = np.random.default_rng(seed)
        for _ in range(NB_CALIBRATION_SAMPLES):
            yield [rng.normal(0.0, 1.0, (1, LATENT_DIM)).astype(np.float32)]

    return dataset


def export_tflite_int8(generator: tf.keras.Model, filename: Path, seed: int) -> None:
    """Convert ``generator`` to a fully int8 TFLite model and write it to ``filename``.

    The quantisation is calibrated on latent vectors drawn from ``seed``, so
    the same generator and seed always give the same model.

    The generator is wrapped in a model whose batch is fixed to 1, so that the
    TFLite model has a static [1, LATENT_DIM] input and needs no shape ops,
    and is converted with ``from_keras_model``. Converting a ``tf.function``
    with ``from_concrete_functions`` instead leaves the Keras 3 variables
    unresolved: the int8 calibration then fails with "READ_VARIABLE failed
    to invoke" (TensorFlow 2.21, Keras 3.15).
    """
    print("")
    print("Export TFLite int8...")

    z = tf.keras.Input(shape=(LATENT_DIM,), batch_size=1)
    serving_model = tf.keras.Model(z, generator(z, training=False))

    converter = tf.lite.TFLiteConverter.from_keras_model(serving_model)
    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    converter.representative_dataset = representative_dataset(seed)
    converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
    converter.inference_input_type = tf.int8
    converter.inference_output_type = tf.int8

    # from_keras_model saves the model as a temporary SavedModel first, and
    # Keras then lists its endpoints and the ~34 captured variables on stdout
    # ("Saved artifact at ...", "Captures: ... TensorSpec(... tf.resource)").
    # Errors are raised and warnings go to stderr, so only that listing is lost.
    with contextlib.redirect_stdout(io.StringIO()):
        tflite_model = converter.convert()
    filename.write_bytes(tflite_model)

    print(f"TFLite int8 model saved : {filename.resolve()}")
    print(f"TFLite int8 size        : {len(tflite_model) / 1024 / 1024:.2f} MB")
    print(f"Calibration seed        : {seed}")


def save_checkpoint(generator: tf.keras.Model, epoch: int, seed: int) -> None:
    """Save ``generator`` as ``generator_epoch_xxxx`` in Keras and int8 TFLite format."""
    name = f"generator_epoch_{epoch:04d}"
    generator.save(f"{name}.keras")
    export_tflite_int8(generator, Path(f"{name}.tflite"), seed)


def export_checkpoint(keras_file: Path, tflite_file: Path, seed: int) -> int:
    """Export the generator saved in ``keras_file`` to ``tflite_file``. Return the exit status."""
    try:
        generator = tf.keras.models.load_model(keras_file)
    except (OSError, ValueError) as error:
        print(f"Error: {keras_file} cannot be loaded: {error}", file=sys.stderr)
        return 1

    export_tflite_int8(generator, tflite_file, seed)
    return 0


# Main
# ----


def parse_args() -> argparse.Namespace:
    """Parse the command-line arguments."""
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument(
        "--model_file",
        type=Path,
        default=FINAL_TFLITE_FILE,
        help=f"path of the final TFLite model to write (default: {FINAL_TFLITE_FILE})",
    )
    parser.add_argument(
        "--mode",
        choices=["full"],
        default="full",
        help="accepted for symmetry with the other trainings; the GAN always trains on all data",
    )
    parser.add_argument(
        "--export",
        type=Path,
        metavar="CHECKPOINT",
        help="do not train: export this generator_epoch_xxxx.keras checkpoint to --model_file",
    )
    parser.add_argument(
        "--calibration-seed",
        type=int,
        default=CALIBRATION_SEED,
        help=f"seed of the latent vectors calibrating the int8 quantisation (default: {CALIBRATION_SEED})",
    )
    return parser.parse_args()


def main() -> int:
    """Train the GAN and export its generator, or export a checkpoint. Return the exit status."""
    args = parse_args()
    seed: int = args.calibration_seed

    if args.export is not None:
        return export_checkpoint(args.export, args.model_file, seed)

    OUTPUT_DIR.mkdir(exist_ok=True)

    print("Load the images...")
    try:
        faces = load_faces_from_folder(IMAGE_FOLDER)
    except (OSError, RuntimeError) as error:
        print(f"Error: images cannot be loaded: {error}", file=sys.stderr)
        return 1

    dataset = (
        tf.data.Dataset.from_tensor_slices(faces)
        .shuffle(buffer_size=len(faces))
        .batch(BATCH_SIZE)
        .prefetch(tf.data.AUTOTUNE)
    )

    print("Create the generator...")
    generator = build_generator()

    print("Create the discriminator...")
    discriminator = build_discriminator()

    generator.summary()
    discriminator.summary()

    g_optimizer = tf.keras.optimizers.Adam(learning_rate=LEARNING_RATE_G, beta_1=ADAM_BETA_1)
    d_optimizer = tf.keras.optimizers.Adam(learning_rate=LEARNING_RATE_D, beta_1=ADAM_BETA_1)

    # The same latent vectors at every display, so the epochs can be compared
    fixed_noise = tf.random.normal([NB_SHOWN_FACES, LATENT_DIM])

    plt.ion()

    print("Start of the training...")
    for epoch in range(EPOCHS + 1):
        for real_batch in dataset:
            g_loss, d_loss = train_step(real_batch, generator, discriminator, g_optimizer, d_optimizer)

        if epoch % DISPLAY_EVERY == 0:
            print(f"Epoch {epoch} | G loss: {g_loss.numpy():.4f} | D loss: {d_loss.numpy():.4f}")
            show_and_save_generated_images(generator, fixed_noise, epoch)

        # Checkpoint, so that a better-looking epoch can be picked by hand
        if epoch % CHECKPOINT_EVERY == 0 or epoch == EPOCHS:
            save_checkpoint(generator, epoch, seed)

    print("Training terminated.")
    export_tflite_int8(generator, args.model_file, seed)
    return 0


if __name__ == "__main__":
    sys.exit(main())
