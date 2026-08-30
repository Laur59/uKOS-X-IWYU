# uKOS-X – Getting started

This document provides a quick onboarding guide for users.

NOTE: Throughout the documentation, the term *`PATH_UKOS_X_PACKAGE`* is used to refer to
the location where uKOS-X is located (typically the git clone destination).

## Prerequisites

To build binaries of **µKOS-X**, a set of development tools is required. Before proceeding,
ensure that the following components are available on your system.

Mandatory:
- cmake, **3.31 or newer** (the build uses preset schema version 10)
- toolchain for Arm processors with newlib
- toolchain for RISC-V processors with newlib

Optional:
- yq (required by `Ports/Targets/_build.sh`, which builds every target)
- python3 (for building libraries such as Tensorflow Lite)
- toolchain for Arm processors with picolibc
- toolchain for RISC-V processors with picolibc
- toolchain for Arm processors with LLVM libc
- toolchain for RISC-V processors with LLVM libc

## Preparing work environment

It is sufficient to initialise the paths where the toolchains are located.

```bash
PATH_GCC_ARM=Your_Path_To_The_gcc_arm
PATH_GCC_RVXX=Your_Path_To_The_gcc_riscv
PATH_LLVM_ARM=Your_Path_To_The_llvm_arm
PATH_LLVM_RVXX=Your_Path_To_The_llvm_riscv

export PATH_GCC_ARM
export PATH_GCC_RVXX
export PATH_LLVM_ARM
export PATH_LLVM_RVXX
```

The default C library is **newlib**; **picolibc** and **llvmlibc** (LLVM libc) are
also supported and select their own toolchains. Set these additional paths only
if you intend to build with them:

```bash
PATH_LLVM_ARMP=Your_Path_To_The_llvm_arm_picolibc   # for -DC_LIBRARY=picolibc (LLVM)
PATH_LLVM_RVXXP=Your_Path_To_The_llvm_riscv_picolibc   # for -DC_LIBRARY=picolibc (LLVM)
PATH_GCC_ARMP=Your_Path_To_The_gcc_arm_picolibc     # for -DC_LIBRARY=picolibc (GCC)
PATH_GCC_RVXXP=Your_Path_To_The_gcc_riscv_picolibc     # for -DC_LIBRARY=picolibc (GCC)
PATH_LLVM_ARML=Your_Path_To_The_llvm_arm_llvmlibc   # for -DC_LIBRARY=llvmlibc (LLVM)
PATH_LLVM_RVXXL=Your_Path_To_The_llvm_riscv_llvmlibc   # for -DC_LIBRARY=llvmlibc (LLVM)

export PATH_LLVM_ARMP
export PATH_LLVM_RVXXP
export PATH_GCC_ARMP
export PATH_GCC_RVXXP
export PATH_LLVM_ARML
export PATH_LLVM_RVXXL
```

See **[C-library-selection.md](C-library-selection.md)** for the
toolchain requirements of each C library and for building with them.

## Building the package libraries

Once the environment is configured, typically the next step is to build all the libraries.
This step is only mandatory if you intend to build the targets in `Ports/Targets/`. Run the
following commands from the cloned directory.

Every CMake package follows the same three steps. `cmake --build build` only compiles the
libraries into the package build tree; `cmake --install build` is what deploys them into
`Third_Parties/<package>/Library/`, which is where the target and application builds look
for them. Skipping the install step leaves `find_library()` empty and the failure only
shows up later as a link error.

### Building TinyUSB

```bash
cd Third_Parties/TinyUSB
cmake -S . -B build
cmake --build build
cmake --install build
```

### Building MicroPython

```bash
cd Third_Parties/MicroPython
cmake -S . -B build
cmake --build build
cmake --install build
```

### Building FatFs

```bash
cd Third_Parties/FatFs
cmake -S . -B build
cmake --build build
cmake --install build
```

### Building TFLite-micro

If it is the first time you build TFLite-micro, you need to create the virtual environment
first.

```bash
cd Third_Parties/Tflite-micro/Construction/Pyenv
python3.13 -m venv Tflite_Pyenv
source Tflite_Pyenv/bin/activate
pip install -r requirements.txt
deactivate
```

Then, you can build TFLite-micro as follows. The script activates the virtual environment
itself, so there is nothing to source beforehand:

```bash
cd Third_Parties/Tflite-micro
./build.sh
```

### Building decnumber

```bash
cd Third_Parties/decnumber
cmake -S . -B build
cmake --build build
cmake --install build
```

### Building IntelRDFPMath

```bash
cd Third_Parties/IntelRDFPMath
cmake -S . -B build
cmake --build build
cmake --install build
```

### Building LVGL

```bash
cd Third_Parties/LVGL
cmake -S . -B build
cmake --build build
cmake --install build
```

### Building STM32 (N6 FSBL + N6 NPU)

```bash
# The package STEdgeAI has to be installed manually
# The package should be installed here
# "${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/STEdgeAI
# https://www.st.com/en/development-tools/stedgeai-core.html

cd Third_Parties/STM32/STM32N6
./build.sh
```

### Building esp32

```bash
cd Third_Parties/esp32
./build.sh
```

## Building all the targets of the package

This command will build all the targets of the package. It requires that the above
libraries have been built first, and that `yq` is installed.

```bash
cd Ports/Targets
./_build.sh
```

In the folder Targets you can read the document **README.md** for more information.

## Possible operations with one target

For building one specific target we simply need to enter in the **Variant__** folder of the
target and play with **cmake**. For example, if we need to **build** and **burn** the
**FLASH** of the target **Nucleo_H743**.

```bash
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake --preset gcc
cmake --build build --target burn
```

See **[USAGE_cmake.md](USAGE_cmake.md)** for the full list of presets and build options.

#### Working with the target

1. Connect a serial terminal (e.g. CoolTerm) set with the baudrate **460800-b/s**
   (**115200-b/s** for MAIXDUINO)

2. Push reset. On the terminal the OS prompt should appear
