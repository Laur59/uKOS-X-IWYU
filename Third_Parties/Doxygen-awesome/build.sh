#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Build the Doxygen-awesome package

set -euo pipefail

# Determine script directory (works if executed via ./script.sh or zsh script.sh)

readonly PATH_PRG="${0:a:h}"


# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

readonly splash='
╔════════════════════════════════════════════════════════════╗
║           Doxygen-awesome Package Build System             ║
║      Fetching upstream + Building all the project          ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${BLUE}" "${splash}" "${NC}"

# Packages
# --------

readonly package=2.4.2

# Clone the right package

cd "${PATH_PRG}"
rm -rf "${PATH_PRG}/Doxygen-awesome-${package}"
git clone https://github.com/jothepro/doxygen-awesome-css.git "Doxygen-awesome-${package}" -b "v${package}"

# Update path links

rm -f Doxygen-awesome-current
ln -s "Doxygen-awesome-${package}" Doxygen-awesome-current

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
