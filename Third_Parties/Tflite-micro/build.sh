#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Build the Tflite-micro package

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

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
║           TFlite-micro Package Build System                ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${BLUE}" "${splash}" "${NC}"

if [[ -d 'Tflite-env/bin' ]]; then
    source 'Tflite-env/bin/activate'
fi

# Packages
# --------

readonly hash=f5302ed

printf '\n%bDownload the Tflite-micro package ...%b\n\n' "${BOLD}" "${NC}"

# Clone the right package
cd "${PATH_PRG}"
if [[ ! -d Tflite-micro-current ]]; then
    git clone https://github.com/tensorflow/tflite-micro.git Tflite-micro-current
else
    git -C Tflite-micro-current fetch
fi
git -C Tflite-micro-current checkout "${hash}"

# Parse core.yaml file using yq
parse_core_yaml() {
    local yaml_file='../core.yaml'

    if ! [[ -f "${yaml_file}" ]]; then
        printf "%bError: YAML file not found: %s%b\n" "${RED}" "${yaml_file}" "${NC}" >&2
        exit 1
    fi

    if ! command -v yq >/dev/null 2>&1; then
        printf "%bError: yq is not installed%b\n" "${RED}" "${NC}" >&2
        exit 1
    fi

    # Parse YAML: iterate through models and their cores
    yq eval 'to_entries[] | .key as $model | .value[] | "\($model)\t\(.core)\t\(.target_arch)\t\(.fpu)"' "${yaml_file}"
}

# Generate the `.h` interface files for all the cortex-M (generic, -m3, m4, -m7, -m33, -m55 -m85)
# Generate the `.h` interface files for all the risc-v (generic, rv64imafdc)
cd ./Tflite-micro-current/

python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
    --makefile_options='TARGET=cortex_m_generic OPTIMIZED_KERNEL_DIR=cmsis_nn TARGET_ARCH=project_generation' \
    ../uKOS_Interface/CORTEX_M_generic

python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
    --makefile_options='TARGET=riscv32_generic TARGET_ARCH=project_generation' \
    ../uKOS_Interface/RISCV64_generic

printf '\n%bBuilding all the Tflite-micro libraries ...%b\n' "${BOLD}" "${NC}"

cd "tensorflow/lite/micro/tools/make/downloads"
if [[ ! -L gcc_embedded ]]; then
    rm -fr gcc_embedded
    ln -s "${PATH_GCC_ARM}" gcc_embedded
fi
if [[ ! -L riscv_toolchain ]]; then
    rm -fr riscv_toolchain
    ln -s "${PATH_GCC_RVXX}" riscv_toolchain
fi
cd ../../../../../..

# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r model core target_arch fpu
do

    # Build a specific core library
    printf '\n%bBuild for the core %s ...%b\n' "${BOLD}" "${core}" "${NC}"

    if [[ ${model} == cortex_m_generic ]]; then
        make -f tensorflow/lite/micro/tools/make/Makefile \
            TARGET=cortex_m_generic TARGET_ARCH="${target_arch}" \
            OPTIMIZED_KERNEL_DIR=cmsis_nn microlite -j8 FLOAT="${fpu}" BUILD_TYPE=debug
        mkdir -p "../Library/${core}"
        cp "./gen/cortex_m_generic_${target_arch}_debug_cmsis_nn_gcc/lib/libtensorflow-microlite.a" \
            "../Library/${core}/libTFLite.a"
    fi

    if [[ ${model} == riscv32_generic ]]; then
        make -f tensorflow/lite/micro/tools/make/Makefile \
            TARGET=riscv32_generic TARGET_ARCH="${target_arch}" \
            RISCV_ARCH=rv64imafdc \
            RISCV_ABI=lp64d \
            DISABLE_PRINTF=true \
            microlite -j8 FLOAT="${fpu}" BUILD_TYPE=debug \
            CFLAGS_EXTRA='-march=rv64imafdc -mabi=lp64d' \
            CXXFLAGS_EXTRA='-march=rv64imafdc -mabi=lp64d' \
            LDFLAGS_EXTRA='-march=rv64imafdc -mabi=lp64d'
        mkdir -p "../Library/${core}"
        cp "./gen/riscv32_generic_${target_arch}_debug_gcc/lib/libtensorflow-microlite.a" \
            "../Library/${core}/libTFLite.a"
    fi
done < <(parse_core_yaml)

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
