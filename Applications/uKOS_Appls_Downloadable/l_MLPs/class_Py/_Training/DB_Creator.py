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
#			Class 1:  150 < data < 600
#			Class 2a: data > (600 + 4 * KCLASS_MARGIN)
#			Class 2b: data < (150 - KCLASS_MARGIN)
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

"""Generate the learning and validation datasets for the MLPN classifier.

Two files are written, ``DB_L_file.txt`` (learning) and ``DB_V_file.txt``
(validation), and both datasets are plotted side by side.

Points (x, y) are drawn uniformly in [-KABS_MAX_FUNCTION, +KABS_MAX_FUNCTION]²,
classified by rejection sampling, then normalised to [-1, 1].
With r² = x² + y²:

* C1,  ring:   KRING_LIMITS_MIN < r² < KRING_LIMITS_MAX
* C2a, outer:  r² > KRING_LIMITS_MAX, excluding the top-right square
* C2b, inner:  r² < KRING_LIMITS_MIN
* C3,  square: x > KSQUARE_LIMITS and y > KSQUARE_LIMITS

C2a and C2b share the same target vector (class 2).

Each line of the output files is tab-separated: ``x  y  t1  t2  t3``, where
t1..t3 is the one-hot target (KGOOD for the active class, KBAD otherwise).

Requirements:
    python3 -m pip install numpy matplotlib

Usage:
    python3 DB_Creator.py [-seed nnn]

The random generator is seeded with ``nnn``, or with KDEFAULT_SEED when the
option is omitted, so the same seed always produces the same datasets.
"""

import argparse
from collections.abc import Callable, Sequence
from typing import NamedTuple, TextIO

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.axes import Axes

KNB_SAMPLES_C1		= 1000								# Number of samples C1 (ring)
KNB_SAMPLES_C2A		= 1000								# Number of samples C2a (outer)
KNB_SAMPLES_C2B		= 1000								# Number of samples C2b (inner)
KNB_SAMPLES_C3		= 1000								# Number of samples C3 (square)
KABS_MAX_FUNCTION	= 40								# Max of the function (+/- 40 in x-y)
KRING_LIMITS_MIN	= (0.4 * KABS_MAX_FUNCTION) ** 2	# Min r² for the ring
KRING_LIMITS_MAX	= (0.7 * KABS_MAX_FUNCTION) ** 2	# Max r² for the ring
KSQUARE_LIMITS		= 0.6 * KABS_MAX_FUNCTION			# Corner size (top-right)
KABS_MAX_OUTPUT		= 0.98								# Abs max of the expected output
KGOOD				= KABS_MAX_OUTPUT					# Target value for the active class
KBAD				= 0.00								# Target value for the other classes
KDEFAULT_SEED		= 42								# Seed of the random generator without -seed

KTARGET_C1			= (KGOOD, KBAD, KBAD)
KTARGET_C2			= (KBAD, KGOOD, KBAD)
KTARGET_C3			= (KBAD, KBAD, KGOOD)

Point = tuple[float, float]
Predicate = Callable[[float, float], bool]

_rng = np.random.default_rng(KDEFAULT_SEED)				# Reseeded by main() from -seed


def generate_random_values() -> Point:
	"""Return a random (x, y) point drawn uniformly in [-KABS_MAX_FUNCTION, +KABS_MAX_FUNCTION]²."""
	x, y = (_rng.random(2) - 0.5) * 2 * KABS_MAX_FUNCTION
	return float(x), float(y)

def norm_squared(x: float, y: float) -> float:
	"""Return the squared Euclidean norm of (x, y)."""
	return x * x + y * y

def normalize_point(x: float, y: float) -> Point:
	"""Scale (x, y) from [-KABS_MAX_FUNCTION, +KABS_MAX_FUNCTION] to [-1, 1]."""
	return x / KABS_MAX_FUNCTION, y / KABS_MAX_FUNCTION

def in_top_right_corner(x: float, y: float) -> bool:
	"""Return True if (x, y) lies in the top-right square (class C3)."""
	return x > KSQUARE_LIMITS and y > KSQUARE_LIMITS

def in_ring(x: float, y: float) -> bool:
	"""Return True if (x, y) lies strictly inside the ring (class C1)."""
	return KRING_LIMITS_MIN < norm_squared(x, y) < KRING_LIMITS_MAX

def in_outer(x: float, y: float) -> bool:
	"""Return True if (x, y) lies outside the ring but not in the top-right square (class C2a)."""
	return norm_squared(x, y) > KRING_LIMITS_MAX and not in_top_right_corner(x, y)

def in_inner(x: float, y: float) -> bool:
	"""Return True if (x, y) lies inside the inner disc (class C2b)."""
	return norm_squared(x, y) < KRING_LIMITS_MIN

class ClassSpec(NamedTuple):
	"""Description of one sampled region: its size, membership test and target vector."""

	nb_samples: int
	predicate: Predicate
	target: tuple[float, float, float]

KCLASSES = (
	ClassSpec(KNB_SAMPLES_C1, in_ring, KTARGET_C1),
	ClassSpec(KNB_SAMPLES_C2A, in_outer, KTARGET_C2),
	ClassSpec(KNB_SAMPLES_C2B, in_inner, KTARGET_C2),
	ClassSpec(KNB_SAMPLES_C3, in_top_right_corner, KTARGET_C3),
)

def sample_class(predicate: Predicate, nb_samples: int) -> list[Point]:
	"""Draw random points until ``nb_samples`` satisfy ``predicate``.

	Rejection sampling: points outside the region are discarded.
	The accepted points are returned normalised to [-1, 1].
	"""
	points: list[Point] = []
	while len(points) < nb_samples:
		x, y = generate_random_values()
		if predicate(x, y):
			points.append(normalize_point(x, y))
	return points

def setup_axes(ax: Axes, title: str) -> None:
	"""Configure ``ax`` for displaying normalised coordinates."""
	ax.set_title(title)
	ax.set_aspect("equal")
	ax.grid(True)
	ax.set_xlim(-1, 1)
	ax.set_ylim(-1, 1)
	ax.set_xticks(np.linspace(-1, 1, 5))
	ax.set_yticks(np.linspace(-1, 1, 5))

def generate_dataset(fd: TextIO, ax: Axes, formats: Sequence[str], title: str) -> None:
	"""Generate one dataset, write it to ``fd`` and plot it on ``ax``.

	Args:
		fd: Open text file receiving the tab-separated samples.
		ax: Matplotlib axes on which the samples are plotted.
		formats: One Matplotlib format string per entry of ``KCLASSES``.
		title: Title of the plot.
	"""
	setup_axes(ax, title)

	for spec, fmt in zip(KCLASSES, formats, strict=True):
		points = sample_class(spec.predicate, spec.nb_samples)
		for xn, yn in points:
			fields = [f"{xn:.6f}", f"{yn:.6f}", *(f"{t:.2f}" for t in spec.target)]
			fd.write("\t".join(fields) + "\n")

		xs, ys = zip(*points)
		ax.plot(xs, ys, fmt)

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
		generate_dataset(fd_l, ax1, formats=["r+", "go", "g.", "bx"], title="Learning data")
		generate_dataset(fd_v, ax2, formats=["ro", "gx", "g+", "b."], title="Validation data")

	plt.tight_layout()
	plt.show()

if __name__ == "__main__":
	main()
