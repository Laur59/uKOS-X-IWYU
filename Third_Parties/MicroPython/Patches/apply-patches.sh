#!/usr/bin/env sh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Apply the uKOS-X patches to the fetched MicroPython source tree.
#
#   Both ways of obtaining the source call this script: the CMake flow
#   (CMakeLists.txt, after FetchContent_MakeAvailable) and the shell wrapper
#   (build_with_cmake.sh, after the checkout). Either alone would leave the
#   other unpatched.
#
#   Idempotent: a patch that is already applied is reported and skipped, so the
#   script is safe to run on every configure and on every build.
#
#   A patch that no longer applies is a hard error: the pinned upstream tag has
#   moved and the patch has to be refreshed against it.

set -eu

SRC="${1:?usage: apply-patches.sh <path to MicroPython-current>}"
DIR="$(cd "$(dirname "$0")" && pwd)"

if [ ! -d "${SRC}/.git" ]; then
    echo "apply-patches: '${SRC}' is not a git clone" >&2
    exit 1
fi

for patch in "${DIR}"/*.patch; do
    [ -e "${patch}" ] || continue           # no patches at all: nothing to do
    name="$(basename "${patch}")"

    if git -C "${SRC}" apply --reverse --check "${patch}" 2>/dev/null; then
        echo "apply-patches: ${name} already applied"
    elif git -C "${SRC}" apply "${patch}" 2>/dev/null; then
        echo "apply-patches: ${name} applied"
    else
        echo "apply-patches: ${name} does not apply to ${SRC}" >&2
        echo "  The pinned MicroPython tag has probably moved." >&2
        echo "  Refresh the patch against the new tag, then rebuild." >&2
        exit 1
    fi
done
