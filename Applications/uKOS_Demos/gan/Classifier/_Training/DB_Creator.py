#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# DB_Creator.
# ===========
#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
#------------------------------------------------------------------------
# Author:	Edo. Franzi     The 2026-05-18
# Modifs:
#
# Project:	uKOS-X
# Goal:		Generate the database folder (with 1000 100x100 images).
#
#			python DB_Creator.py
#
#   (c) 2025-2026, Edo. Franzi
#   --------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

import	tempfile
import	shutil
import	numpy as np
import	os
from	sklearn.datasets import fetch_lfw_people
from	PIL import Image

NB_IMAGES		= 50000
IMAGE_FOLDER	= "DB_faces"

print("Load the images LFW...")

# Create a temporary directory for the scikit-learn cache
temp_dir = tempfile.mkdtemp()

lfw = fetch_lfw_people(
	data_home=temp_dir,
	resize=1.0,
	color=False,
	download_if_missing=True
)
print("Shape :", lfw.images.shape)
print("Min :", lfw.images.min(), "Max :", lfw.images.max())

output_dir = IMAGE_FOLDER
os.makedirs(output_dir, exist_ok=True)

n_images = min(NB_IMAGES, lfw.images.shape[0])

for i in range(n_images):
	img = lfw.images[i].astype("float32")

	# Normalise [0, 255]
	img = img - img.min()
	img = img / (img.max() + 1e-8)
	img = img * 255.0
	img = img.astype("uint8")

	pil_img = Image.fromarray(img, mode="L")
	pil_img = pil_img.resize((100, 100), Image.Resampling.LANCZOS)

	filename = os.path.join(output_dir, f"face_{i:04d}.png")
	pil_img.save(filename)

print(f"{n_images} images stored in the {output_dir}/ folder")

# Remove the temporary cache directory
shutil.rmtree(temp_dir, ignore_errors=True)
