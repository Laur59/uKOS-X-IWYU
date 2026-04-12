# Building uKOS-X targets (v.1.1)

(c) 2025-2026, Edo. Franzi, 2025-01-01

## Building all the targets

```bash
cd Ports/Targets

# Building using llvm & cmake
./_build.sh

# Building using gcc
./_build.sh -G
```

## Building a specific target

```bash
# Building using the gcc compiler
# cd Variant_xyz
cmake -S . -B build -DUSER_MODE=ON
cmake --build build -j

# Building using the llvm compiler
# cd Variant_xyz
cmake -S . -B build -DUSER_MODE=ON -DUSE_LLVM=ON
cmake --build build -j
```

## Static analysis for a specific target

```bash
cd Ports/Targets/Target_Name/Variant_xyz

# Building using scan-build & the llvm compiler for ARM targets
${PATH_LLVM_ARM}/bin/scan-build --use-cc=${PATH_LLVM_ARM}/bin/clang --use-analyser=${PATH_LLVM_ARM}/bin/clang -o build-scan make PREFIX=llvm- COMPILER_FAMILY=llvm USER_MODE=1

# Building using scan-build & the llvm compiler for riscv targets
${PATH_LLVM_RVXX}/bin/scan-build --use-cc=${PATH_LLVM_RVXX}/bin/clang --use-analyser=${PATH_LLVM_RVXX}/bin/clang -o build-scan make PREFIX=llvm- COMPILER_FAMILY=llvm USER_MODE=1
```

## Cleaning all the targets (even the static analysis reports)

```bash
cd Ports/Targets
./_clean.sh
```
