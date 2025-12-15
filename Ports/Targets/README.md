# Building uKOS-X targets (v.1.1)

(c) 2025-20xx, Edo. Franzi, 2025-01-01

## Building all the targets

```bash
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets

# Building using gcc & make
./build.sh

# Building using gcc & CMake
./build.sh -C

# Building using llvm
./build.sh -L
```

## Building a specific target

```bash
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Target_Name/Variant_xyz/System

# Building ARM using the gcc compiler
make -j USER_MODE=1
PREFIX=arm-none-eabi- COMPILER_FAMILY=gcc make -j USER_MODE=1

# Building riscv using the gcc compiler
make -j USER_MODE=1
PREFIX=riscv64-unknown-elf- COMPILER_FAMILY=gcc make -j USER_MODE=1

# Building ARM targets using the llvm compiler
PREFIX=llvm- COMPILER_FAMILY=llvm make -j USER_MODE=1

# Building riscv targets using the llvm compiler
PREFIX=llvm- COMPILER_FAMILY=llvm make -j USER_MODE=1

# Building using cmake and the gcc compiler
# cd Variant_xyz
cmake -S . -B build -DUSER_MODE=ON
cmake --build build -j

# Building using cmake and the llvm compiler
# cd Variant_xyz
cmake -S . -B build -DUSER_MODE=ON -DUSE_LLVM=ON
cmake --build build -j
```

## Static analysis for a specific target

```bash
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Target_Name/Variant_xyz/System

# Building using scan-build & the llvm compiler for ARM targets
${PATH_LLVM_ARM}/bin/scan-build --use-cc=${PATH_LLVM_ARM}/bin/clang --use-analyser=${PATH_LLVM_ARM}/bin/clang -o build-scan make PREFIX=llvm- COMPILER_FAMILY=llvm USER_MODE=1

# Building using scan-build & the llvm compiler for riscv targets
${PATH_LLVM_RVXX}/bin/scan-build --use-cc=${PATH_LLVM_RVXX}/bin/clang --use-analyser=${PATH_LLVM_RVXX}/bin/clang -o build-scan make PREFIX=llvm- COMPILER_FAMILY=llvm USER_MODE=1
```

## Cleaning all the targets (even the static analysis reports)

```bash
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets
./clean.sh
```
