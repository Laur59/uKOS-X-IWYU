# DB_Creator.
# ===========
#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
#------------------------------------------------------------------------
# Author:	Edo. Franzi			The 2025-01-01
# Modifs:	Laurent von Allmen	The 2026-11-12
#
# Project:	uKOS-X
# Goal:		Generate 2 database files (for learning and for validation).
# 			Display the 2 dataset
#
#			The databases:
#			Class 1:  x < -0.1 and y >  0.1
#			Class 2:  x >  0.1 and y >  0.1
#			Class 3:  x < -0.1 and y < -0.1
#			Class 4:  ((-0.1 < x < 0.1) or (-0.1 < y < 0.1))
#
#			Necessary packages:
#			python3 -m pip install numpy pyserial matplotlib
#
#			python3 DB_Creator.py
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

"""Generate the learning and validation datasets for the cluster MLP.

Two files are written, ``DB_L_file.txt`` (learning) and ``DB_V_file.txt``
(validation), and both datasets are plotted side by side.

Points (x, y) are drawn uniformly in [-KABS_MAX_FUNCTION, +KABS_MAX_FUNCTION]²
and assigned to one of five classes:

* C1, top-left:     x < -KBAND and y > +KBAND
* C2, top-right:    x > +KBAND and y > +KBAND
* C3, bottom-left:  x < -KBAND and y < -KBAND
* C4, bottom-right: x > +KBAND and y < -KBAND
* C5, cross:        |x| < KBAND or |y| < KBAND (the band between the quadrants)

Each class receives KNB_SAMPLES_PER_CLASS points. A drawn point whose class
is already full is discarded, so the classes are interleaved in the files.

Each line of the output files is tab-separated: ``x  y  t1 .. t5``, where
t1..t5 is the one-hot target (KGOOD for the active class, KBAD otherwise).

Requirements:
    python3 -m pip install numpy matplotlib

Usage:
    python3 DB_Creator.py [-seed nnn]

The random generator is seeded with ``nnn``, or with KDEFAULT_SEED when the
option is omitted, so the same seed always produces the same datasets.
"""

import argparse
from collections.abc import Sequence
from typing import TextIO

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.axes import Axes

KNB_CLASSES				= 5								# Number of classes
KNB_SAMPLES				= 5000							# Number of samples
KNB_SAMPLES_PER_CLASS	= KNB_SAMPLES // KNB_CLASSES	# Number of samples per class
KABS_MAX_FUNCTION		= 1								# Max of the function
KBAND					= 0.1							# Half-width of the cross (class C5)
KABS_MAX_OUTPUT			= 0.98							# Abs max of the expected output
KGOOD					= KABS_MAX_OUTPUT				# Target value for the active class
KBAD					= 0.00							# Target value for the other classes
KDEFAULT_SEED			= 42							# Seed of the random generator without -seed

KMARKERS_LEARNING		= ("ro", "go", "bo", "yo", "m.")
KMARKERS_VALIDATION		= ("r+", "g+", "b+", "y+", "m+")

Point = tuple[float, float]

_rng = np.random.default_rng(KDEFAULT_SEED)				# Reseeded by main() from -seed


def generate_random_values() -> Point:
	"""Return a random (x, y) point drawn uniformly in [-KABS_MAX_FUNCTION, +KABS_MAX_FUNCTION]²."""
	x, y = (_rng.random(2) - 0.5) * 2 * KABS_MAX_FUNCTION
	return float(x), float(y)

def normalize_point(x: float, y: float) -> Point:
	"""Scale (x, y) from [-KABS_MAX_FUNCTION, +KABS_MAX_FUNCTION] to [-1, 1]."""
	return x / KABS_MAX_FUNCTION, y / KABS_MAX_FUNCTION

def classify(x: float, y: float) -> int | None:
	"""Return the class index (0 for C1 .. 4 for C5) of (x, y).

	The five regions are disjoint. Points lying exactly on a region
	boundary (|x| or |y| equal to KBAND) belong to none and return None.
	"""
	if -KBAND < x < KBAND or -KBAND < y < KBAND:
		return 4
	if x < -KBAND and y > KBAND:
		return 0
	if x > KBAND and y > KBAND:
		return 1
	if x < -KBAND and y < -KBAND:
		return 2
	if x > KBAND and y < -KBAND:
		return 3
	return None

def one_hot(cls: int) -> list[float]:
	"""Return the target vector of class ``cls``."""
	target = [KBAD] * KNB_CLASSES
	target[cls] = KGOOD
	return target

def setup_axes(ax: Axes, title: str) -> None:
	"""Configure ``ax`` for displaying a dataset."""
	ax.set_title(title)
	ax.set_aspect("equal")
	ax.grid(True)

def generate_dataset(fd: TextIO, ax: Axes, markers: Sequence[str], title: str) -> None:
	"""Generate one dataset, write it to ``fd`` and plot it on ``ax``.

	Args:
		fd: Open text file receiving the tab-separated samples.
		ax: Matplotlib axes on which the samples are plotted.
		markers: One Matplotlib format string per class.
		title: Title of the plot.
	"""
	setup_axes(ax, title)
	points: list[list[Point]] = [[] for _ in range(KNB_CLASSES)]

	while min(len(p) for p in points) < KNB_SAMPLES_PER_CLASS:
		x, y = generate_random_values()
		cls = classify(x, y)
		if cls is None or len(points[cls]) >= KNB_SAMPLES_PER_CLASS:
			continue

		xn, yn = normalize_point(x, y)
		points[cls].append((xn, yn))
		fields = [f"{xn:.6f}", f"{yn:.6f}", *(f"{t:.2f}" for t in one_hot(cls))]
		fd.write("\t".join(fields) + "\n")

	for cls_points, marker in zip(points, markers, strict=True):
		xs, ys = zip(*cls_points)
		ax.plot(xs, ys, marker)

def parse_args() -> argparse.Namespace:
	"""Parse the command-line arguments."""
	parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
	parser.add_argument(
		"-seed",
		"--seed",
		type=int,
		default=KDEFAULT_SEED,
		metavar="nnn",
		help=f"seed of the random generator (default: {KDEFAULT_SEED})",
	)
	return parser.parse_args()

def main() -> None:
	"""Generate the learning and validation datasets and display them."""
	global _rng
	_rng = np.random.default_rng(parse_args().seed)

	_, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))

	with (
		open("DB_L_file.txt", "w", encoding="utf-8") as fd_l,
		open("DB_V_file.txt", "w", encoding="utf-8") as fd_v,
	):
		generate_dataset(fd_l, ax1, markers=KMARKERS_LEARNING, title="Learning")
		generate_dataset(fd_v, ax2, markers=KMARKERS_VALIDATION, title="Validation")

	plt.tight_layout()
	plt.show()

if __name__ == "__main__":
	main()
