# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

"""Create the face dataset of the GAN from Labeled Faces in the Wild (LFW).

The grayscale LFW faces are downloaded through scikit-learn into a temporary
cache, which is removed afterwards, so every run downloads them again. Each
face is stretched to the full [0, 255] range, resized to IMG_SIZE x IMG_SIZE
and written to ``DB_faces/face_xxxx.png``; at most NB_IMAGES are kept (LFW
has 13233). ``NN_model.py`` then trains on that folder.

Requirements:
    python3 -m pip install numpy pillow scikit-learn

Usage:
    python3 DB_Creator.py
"""

import tempfile
from pathlib import Path

import numpy as np
from PIL import Image
from sklearn.datasets import fetch_lfw_people

NB_IMAGES = 50000                   # Upper bound on the number of images written
IMAGE_FOLDER = Path("DB_faces")     # Output folder, read by NN_model.py
IMG_SIZE = 100                      # Side of the square images written, in pixels


def to_uint8(face: np.ndarray) -> np.ndarray:
    """Stretch ``face`` to the full [0, 255] range and return it as uint8."""
    face = face.astype(np.float32)
    face = face - face.min()
    face = face / (face.max() + 1e-8)
    return (face * 255.0).astype(np.uint8)


def load_lfw_faces() -> np.ndarray:
    """Download the grayscale LFW faces and return them, shape (N, height, width)."""
    with tempfile.TemporaryDirectory() as cache_dir:
        lfw = fetch_lfw_people(data_home=cache_dir, resize=1.0, color=False, download_if_missing=True)
    return lfw.images


def main() -> None:
    """Download LFW and write the resized faces to IMAGE_FOLDER."""
    print("Load the images LFW...")
    images = load_lfw_faces()
    print("Shape :", images.shape)
    print("Min :", images.min(), "Max :", images.max())

    IMAGE_FOLDER.mkdir(exist_ok=True)

    nb_images = min(NB_IMAGES, len(images))
    for i, face in enumerate(images[:nb_images]):
        img = Image.fromarray(to_uint8(face)).resize((IMG_SIZE, IMG_SIZE), Image.Resampling.LANCZOS)
        img.save(IMAGE_FOLDER / f"face_{i:04d}.png")

    print(f"{nb_images} images stored in the {IMAGE_FOLDER}/ folder")


if __name__ == "__main__":
    main()
