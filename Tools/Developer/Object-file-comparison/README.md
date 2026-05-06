# Object File Comparison Tool

This directory contains tools for comparing object files compiled with different header inclusion strategies (BDFL vs IWYU).

## Files

- **compare_obj.sh** - Automated comparison script that generates analysis report
- **ANALYSIS_REPORT.md** - Comprehensive analysis documentation
- **bdfl/** - BDFL approach (master header `uKOS.h`)
- **iwyu/** - IWYU approach (explicit includes)

## Expected Directory Structure

In the variant folder:

```
base_dir/
  ├── bdfl/
  │   ├── source_name.c
  │   ├── source_name.o
  │   └── source_name_stripped.o
  └── iwyu/
      ├── source_name.c
      ├── source_name.o
      └── source_name_stripped.o
```

## How to Generate Test Files

You need to create the object files from scratch.

```bash
# Set environment
export SOURCE_DATE_EPOCH=1785062700
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc
cd to variant of interest
rm -fr base_dir && mkdir -p base_dir/bdfl base_dir/iwyu
export source_name=C filename of interest
```

### bdfl

Switch to git branch with original (bdfl) sources.

```bash
cp source-file base_dir/bdfl
# Compile BDFL version
cd System
make -j NOCLEAN=1 >/dev/null
cp ${source_name}.o ../base_dir/bdfl
make clean_all >/dev/null
cd ..
pushd base_dir/bdfl
arm-none-eabi-strip --strip-debug -o ${source_name}_stripped.o ${source_name}.o
popd
```

### iwyu

Switch to git branch with IWYU sources.

```bash
cp source-file base_dir/iwyu
# Compile IWYU version
cd System
make -j NOCLEAN=1 >/dev/null
cp ${source_name}.o ../base_dir/iwyu
make clean_all >/dev/null
cd ..
pushd base_dir/iwyu
arm-none-eabi-strip --strip-debug -o ${source_name}_stripped.o ${source_name}.o
popd
```

**Important**: Use `SOURCE_DATE_EPOCH` for reproducible builds.

## Quick Start

### Basic Usage

```bash
cd pour-analyse
compare_obj.sh base_dir ${source_name}
```

This will analyze `bdfl/kern.o` vs `iwyu/kern.o` using the current directory.

### Advanced Usage

```bash
./compare_obj.sh [base_dir] [source_name]
```

**Parameters**:
- `base_dir` - Directory containing `bdfl/` and `iwyu/` subdirectories (default: current directory)
- `source_name` - Base name of source file without extension (default: `kern`)

**Examples**:

```bash
# Analyze from parent directory
./compare_obj.sh /path/to/analysis kern

# Analyze different source file
./compare_obj.sh . process

# Analyze from different location
cd /somewhere/else
/path/to/compare_obj.sh /path/to/analysis kern
```

## Output Sections

The script generates the following analysis sections:

### 3.1 Stripped Binary Comparison
- File sizes of stripped object files
- Byte-for-byte comparison using `cmp`
- Verification of functional equivalence

### 3.2 Code Section Analysis
- Output from `arm-none-eabi-size`
- Breakdown of `.text`, `.data`, `.bss` sections
- Verification that code sections are identical

### 4.1 Object File Size Breakdown
- Total file sizes (BDFL vs IWYU)
- Debug information sizes
- Ratios and percentages
- Analysis of what accounts for size differences

### 4.2 Debug Section Comparison
- DWARF debug section sizes (`.debug_str`, `.debug_line`, `.debug_info`, `.debug_abbrev`)
- Size ratios for each section
- Explanation of why debug info differs

### 5.1 ELF Structure Analysis
- Section header counts
- COMDAT group counts (`.group` sections)
- Reduction percentages
- Analysis of linker impact

### Source File Differences
- Line counts
- Full unified diff (`diff -u`)
- Highlights include directive changes

### Summary
- Size reduction metrics
- Functional equivalence verification
- Conclusions

## Prerequisites

### Required Tools

The script requires the ARM cross-compilation toolchain:
- `arm-none-eabi-size`
- `arm-none-eabi-readelf`

The script will automatically attempt to source the environment from:
- `~/Dev/edo-rtos-uKOSX/.zshrc`
- `/Users/lva/Dev/edo-rtos-uKOSX/.zshrc`

If your toolchain is elsewhere, ensure the tools are in your `PATH` before running the script.

### Standard Unix Tools

The script also uses standard tools (should be available on macOS and Linux):
- `diff` - Source code comparison
- `cmp` - Binary comparison
- `stat` - File size information
- `wc` - Line counting
- `grep`, `awk`, `sed` - Text processing

## Interpreting Results

### What to Look For

**Good signs** (IWYU is working correctly):
- ✓ Stripped binaries are identical
- ✓ Code sections (text/data/bss) are identical
- ✓ IWYU object file is significantly smaller (90%+ reduction typical)
- ✓ `.debug_str` section shows largest reduction (10-15x typical)

**Potential issues**:
- ✗ Stripped binaries differ → functional difference exists
- ✗ Code sections differ → different code generated
- ✗ Minimal size difference → IWYU not properly applied

### Typical Results

For a properly implemented IWYU approach:
- Object file size: **90-95% reduction**
- Debug strings: **12-15x reduction**
- ELF sections: **60-70% reduction**
- Stripped size: **Identical**
- Code sections: **Identical**

## Troubleshooting

### Script fails with "ARM toolchain not found"

**Solution**: Ensure the ARM toolchain is in your PATH:

```bash
# Option 1: Source the project environment
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc

# Option 2: Add to PATH manually
export PATH=/opt/embedded/cross/gcc-current/arm/bin:$PATH

# Option 3: Edit script to point to your toolchain location
```

### Script fails with "Required file not found"

**Solution**: Check the directory structure matches the expected layout:

```bash
ls -la bdfl/
ls -la iwyu/
```

Ensure you have:
- `*.c` source files
- `*.o` object files
- `*_stripped.o` stripped object files

### Diff output is too large

**Solution**: If you only want specific sections, you can pipe the output:

```bash
# Only show summary
./compare_obj.sh | grep -A 20 "SUMMARY"

# Only show section 4.2
./compare_obj.sh | sed -n '/4.2 DEBUG SECTION/,/5.1 ELF STRUCTURE/p'

# Save to file for later review
./compare_obj.sh > analysis_output.txt
```

## Related Documentation

- **ANALYSIS_REPORT.md** - Full analysis with detailed explanations
- **CLAUDE.md** - Project-wide IWYU guidelines and header organisation rules
- **task.md** - Original analysis task description

## License

Part of the uKOS-X project. See project LICENSE file.
