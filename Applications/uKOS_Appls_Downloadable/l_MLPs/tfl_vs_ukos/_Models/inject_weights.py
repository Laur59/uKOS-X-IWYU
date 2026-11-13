#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Copy the TFLite weights of structure.c into the MLPN network network.c_inc.
#
# Usage: python3 inject_weights.py structure.c network.c_inc
#
# structure.c (written by tflite_structure.py) holds the sizes, activations and
# weights of each layer; network.c_inc holds the complete MLPN description. The
# rows of every vWeight_L<n> of structure.c replace those of vWeight_L<n>_f in
# network.c_inc, after checking that both files describe the same network.

import argparse
import re
import sys
from pathlib import Path

RE_DEFINE = re.compile(r"^\s*#define\s+KMLPN_L(\d+)_NB_(IN|OUT)\s+(\d+)")
RE_ROW = re.compile(r"^\s*\{([^{}]*)\},?\s*$")
RE_END = re.compile(r"^\s*\};")
RE_STRUCT_ACT = re.compile(r"^//\s*Layer\s+(\d+):.*ACT=(\w+)")
RE_STRUCT_WEIGHT = re.compile(r"\bvWeight_L(\d+)\s*\[.*=\s*\{\s*$")
RE_NET_WEIGHT = re.compile(r"\bvWeight_L(\d+)_f\s*\[.*=\s*\{\s*$")
RE_NET_LAYER = re.compile(r"\baLayer_L(\d+)\s*=\s*\{\s*$")
RE_NET_ACT = re.compile(r"^\s*(KMLPN_\w+)\s*,")

# TFLite activation (as named by tflite_structure.py) -> accepted MLPN functions
ACTIVATIONS = {
    "TANH": {"KMLPN_TAN0", "KMLPN_TAN1", "KMLPN_TAN2", "KMLPN_TAN3"},
    "RELU": {"KMLPN_RELU"},
    "LINEAR": {"KMLPN_LINE"},
    "SOFTMAX": {"KMLPN_SMAX"},
}


def fail(message: str) -> None:
    sys.exit(f"inject_weights: {message}")


def read_sizes(lines: list[str], name: str) -> dict[int, tuple[int, int]]:
    """Return {layer: (NB_IN, NB_OUT)} from the KMLPN_L<n>_NB_IN/OUT defines."""
    found: dict[int, dict[str, int]] = {}
    for line in lines:
        if m := RE_DEFINE.match(line):
            found.setdefault(int(m[1]), {})[m[2]] = int(m[3])
    sizes = {}
    for layer, d in found.items():
        if set(d) != {"IN", "OUT"}:
            fail(f"{name}: layer {layer} lacks NB_IN or NB_OUT")
        sizes[layer] = (d["IN"], d["OUT"])
    return sizes


def find_arrays(lines: list[str], pattern: re.Pattern, name: str) -> dict[int, tuple[int, int]]:
    """Return {layer: (first row index, closing '};' index)} of every weight array."""
    arrays = {}
    for i, line in enumerate(lines):
        if m := pattern.search(line):
            layer = int(m[1])
            end = next((j for j in range(i + 1, len(lines)) if RE_END.match(lines[j])), None)
            if end is None:
                fail(f"{name}: vWeight_L{layer} is not closed")
            arrays[layer] = (i + 1, end)
    return arrays


def parse_rows(lines: list[str], start: int, end: int, name: str, layer: int) -> list[str]:
    """Return the rows of a weight array as stripped '{ ... }' bodies."""
    rows = []
    for line in lines[start:end]:
        if not line.strip():
            continue
        m = RE_ROW.match(line)
        if not m:
            fail(f"{name}: unexpected line in vWeight_L{layer}: {line.strip()}")
        rows.append(", ".join(v.strip() for v in m[1].split(",") if v.strip()))
    return rows


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Copy the TFLite weights of structure.c into the MLPN network.c_inc.")
    parser.add_argument("structure", type=Path, help="structure.c written by tflite_structure.py")
    parser.add_argument("network", type=Path, help="MLPN network.c_inc to update in place")
    args = parser.parse_args()

    s_name, n_name = args.structure.name, args.network.name
    s_lines = args.structure.read_text(encoding="utf-8").splitlines()
    n_lines = args.network.read_text(encoding="utf-8").splitlines()

    # Same layers, same sizes
    s_sizes, n_sizes = read_sizes(s_lines, s_name), read_sizes(n_lines, n_name)
    if not s_sizes:
        fail(f"{s_name}: no layer found")
    if s_sizes != n_sizes:
        fail(f"the layer sizes differ: {s_name} {dict(sorted(s_sizes.items()))}, "
             f"{n_name} {dict(sorted(n_sizes.items()))}")

    # Same activations
    s_acts = {int(m[1]): m[2] for line in s_lines if (m := RE_STRUCT_ACT.match(line))}
    for i, line in enumerate(n_lines):
        if m := RE_NET_LAYER.search(line):
            layer = int(m[1])
            act = next((a[1] for l in n_lines[i + 1:] if (a := RE_NET_ACT.match(l))), None)
            tfl = s_acts.get(layer)
            if tfl not in ACTIVATIONS:
                fail(f"{s_name}: layer {layer} activation {tfl} has no MLPN equivalent")
            if act not in ACTIVATIONS[tfl]:
                fail(f"layer {layer}: {s_name} uses {tfl}, {n_name} uses {act}")

    # Replace the rows, from the last array up so the indices stay valid
    s_arrays = find_arrays(s_lines, RE_STRUCT_WEIGHT, s_name)
    n_arrays = find_arrays(n_lines, RE_NET_WEIGHT, n_name)
    if set(s_arrays) != set(s_sizes) or set(n_arrays) != set(n_sizes):
        fail("every layer needs exactly one weight array in both files")

    for layer in sorted(n_arrays, reverse=True):
        nb_in, nb_out = s_sizes[layer]
        rows = parse_rows(s_lines, *s_arrays[layer], s_name, layer)
        if len(rows) != nb_out or any(len(r.split(",")) != nb_in for r in rows):
            fail(f"{s_name}: vWeight_L{layer} is not {nb_out} x {nb_in}")

        start, end = n_arrays[layer]
        old = next((l for l in n_lines[start:end] if l.strip()), n_lines[end])
        indent = old[: len(old) - len(old.lstrip())]
        n_lines[start:end] = [f"{indent}{{ {r} }}," for r in rows]

    args.network.write_text("\n".join(n_lines) + "\n", encoding="utf-8")
    print(f"{n_name}: weights of {len(n_arrays)} layers taken from {s_name}")


if __name__ == "__main__":
    main()
