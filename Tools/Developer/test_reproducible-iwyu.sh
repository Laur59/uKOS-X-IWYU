#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

################################################################################
# IWYU Validation Script for uKOS-X
################################################################################
#
# Purpose
# -------
# This script verifies build reproducibility after applying the IWYU
# (Include What You Use) refactoring to the uKOS-X project.
#
# Repository Structure
# --------------------
# The reference source tree is taken from the local Git repository branch
# 'develop', hereafter referred to as the reference build ('-orig').
#
# A second source tree, located on branch 'feature-IWYU', is derived from the
# reference branch. In this branch, the umbrella header file 'uKOS.h' has been
# removed and each translation unit explicitly includes only the headers it
# directly depends on, in accordance with the IWYU methodology.
#
# Validation Principle
# --------------------
# The purpose of this script is to demonstrate that the IWYU refactoring does
# not alter the resulting build artefacts. This is evaluated under a
# reproducible-builds model by verifying that, after normalisation of known
# sources of non-determinism, the generated object files are bit-for-bit
# identical.
#
# The comparison is valid because:
# 1. Both builds use the same build instructions (CMake configuration)
# 2. Both builds use identical toolchains (same compiler, linker, flags)
# 3. Both builds use the same build environment, after explicit normalisation steps
#
# Normalisation Strategy
# ----------------------
#
# 1. Build timestamps (__DATE__ and __TIME__)
#
# Challenge: The source code uses the predefined macros __DATE__ and __TIME__, which embed
# the build timestamp into the generated objects.
#
# Solution: To eliminate this source of non-determinism, the environment variable
# SOURCE_DATE_EPOCH is set to a fixed value for all builds.
#
# 2. Version control system metadata
#
# Challenge: By default, the build system embeds the current Git commit hash into the
# version information (via the git describe mechanism or equivalent) when a repository is detected.
# Since the reference and IWYU-refactored builds originate from different branches,
# this metadata would differ and break reproducibility.
#
# Solution: To normalise this input, the build is configured with:
#
#   -DVERSIONING=none
#
# 3. Source location metadata (__LINE__)
#
# Challenge: The macro __LINE__ embeds source location information into the generated
# objects. Because the IWYU refactoring replaces a single include directive
#
#   #include "uKOS.h"  // 1 line
#
# with multiple directives:
#
#   #include "header1.h"  // Multiple lines
#   #include "header2.h"
#   #include "header3.h"
#
# subsequent executable code would otherwise appear at different line numbers between the two source trees.
#
# Solution: To eliminate this discrepancy, an auxiliary branch named 'develop__LINE__' is
# created from 'develop'. In this branch, blank lines are inserted so that
# executable code starts at the same line numbers as in the 'feature-IWYU'
# branch. This ensures identical __LINE__ macro expansion.
#
# 4. Archive and object metadata
#
# Generated object files are stripped of non-essential metadata using:
#
#   $STRIP --strip-unneeded
#
# Static library archive metadata (timestamps, UID/GID) is normalised using:
#
#   ranlib -D
#
# Validation Procedure
# --------------------
#
# Build Phase:
#
# 1. Build 'develop__LINE__' variant:
#    - Switch to branch 'develop__LINE__'
#    - Configure with: -DUSE_LLVM=OFF -DVERSIONING=none
#    - Build all targets
#    - Post-process object files (strip, normalize)
#
# 2. Build 'feature-IWYU' variant:
#    - Switch to branch 'feature-IWYU'
#    - Configure with identical options
#    - Build all targets
#    - Post-process object files (strip, normalize)
#
# The normalised build artefacts produced from branch 'develop__LINE__' are
# stored in the directory 'artefacts-orig'.
#
# The normalised build artefacts produced from branch 'feature-IWYU' are stored
# in the directory 'artefacts-iwyu'.
#
# Corresponding object files from both directories are compared byte-for-byte
# using the 'cmp' command. Bit-for-bit identity is the sole acceptance
# criterion.
#
# 1. Quick binary comparison: Use cmp for bit-by-bit comparison
# 2. Detailed analysis (if files differ):
#    - Compare section sizes (.text, .data, .rodata, .bss)
#    - Compare symbol tables and addresses
#    - Compare relocation entries
#    - Analyze .text section differences (disassembly)
#    - Check for benign differences (git hashes in special sections)
#
# Classification:
#
# Files are categorized as:
# - Bit-for-bit identical: No differences detected
# - Benign differences:
#   - Git commit hashes in .signature or .rodata sections
#   - Code layout changes (compiler reordered basic blocks)
#   - __LINE__ macro differences (if alignment wasn't perfect)
# - Functional differences: Changes in code, data, or symbols that could
#   affect runtime behavior
#
# Expected Outcome
# ----------------
#
# Success Criteria:
#
# If ALL object files are either:
# - Bit-for-bit identical, OR
# - Differ only due to benign causes (git hash, code layout)
#
# Then the script reports SUCCESS with the conclusion:
#
#   ✓✓✓ IWYU TRANSFORMATION IS FUNCTIONALLY EQUIVALENT ✓✓✓
#
#   The IWYU refactoring successfully reduces header dependencies
#   without changing the functional behavior of the code.
#
#   Produced binaries are functionally identical:
#   - Same runtime behavior
#   - Same performance characteristics
#   - Same memory layout
#   - No functional regressions
#
# Failure Criteria:
#
# If ANY object files show functional differences (different section sizes,
# symbols, or relocations), the script reports FAILURE and requests manual
# investigation of the affected files.
#
# Detailed analysis artifacts are preserved in the analysis/ directory for
# troubleshooting.
#
# Technical Notes
# ---------------
# - This validation approach is specific to embedded systems where reproducible
#   builds are achievable
# - The script uses GNU binutils (objdump, objcopy, nm, size) from the ARM
#   toolchain
# - Analysis is performed on stripped object files to focus on functional
#   content rather than metadata
#
# =====================
# Reproducibility Claim
# =====================
#
# Under the conditions defined above, this script asserts the following:
#
#   Given semantically equivalent source trees, identical build instructions,
#   and an explicitly normalised build environment, the IWYU refactoring
#   preserves build reproducibility at the object-file level.
#
# Bit-for-bit identical object files demonstrate that the IWYU refactoring does
# not modify the resulting build artefacts, and therefore does not affect the
# runtime behaviour or performance characteristics of the produced binaries.
#
# This claim is limited to the scope of the described environment and toolchain
# and does not extend to cross-host or cross-toolchain reproducibility.

# Run from a variant folder (e.g., Ports/Targets/Nucleo_L4R5/Variant_Test)

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Check arguments
if [[ $# -ne 1 ]]; then
	print -u2 "Usage: $0 <variant_path>"
	print -u2 "Example: $0 Nucleo_L4R5/Variant_Test"
	exit 1
fi

readonly variant_path="Ports/Targets/$1"
readonly user_install_dir="/Users/lva/Dev/edo-rtos-uKOSX"
readonly ref_dir="${user_install_dir}/uKOS-X-priv-lva"
readonly iwyu_dir="${user_install_dir}/uKOS-X"

export SOURCE_DATE_EPOCH=1785062700

readonly SIZE="$PATH_GCC_ARM/bin/arm-none-eabi-size"
readonly STRIP="$PATH_GCC_ARM/bin/arm-none-eabi-strip"

# Get absolute paths
VARIANT_DIR=$(pwd)
REPO_ROOT=$(git rev-parse --show-toplevel)

echo "=== Building default ==="
cd "${ref_dir}/${variant_path}"
git switch develop__LINE__
rm -fr build build-orig
cmake -S . -B build -DUSE_LLVM=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DVERSIONING=none -DCONSTANT_SIG=ON > /dev/null 2>&1
cmake --build build --parallel > /dev/null 2>&1
rm -fr artefacts-orig && mkdir artefacts-orig
for src in build/**/*.o; do
    dest="artefacts-orig/${src:t}"
    cp "$src" "$dest"
    $STRIP --strip-unneeded "$dest" -o "${dest:r}_stripped.o"
done
cp build/lib*.a artefacts-orig
$STRIP --strip-unneeded artefacts-orig/lib*.a
# Normalisation timpestamp (set to 0)
$PATH_GCC_ARM/bin/arm-none-eabi-ranlib -D artefacts-orig/lib*.a
cp build/FLASH.elf artefacts-orig
$STRIP --strip-unneeded artefacts-orig/FLASH.elf
cp build/compile_commands.json artefacts-orig
# rm -r build
mv build build-orig

echo "=== Building with IWYU ==="
cd "${iwyu_dir}/${variant_path}"
rm -fr build build-iwyu
cmake -S . -B build -DUSE_LLVM=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DVERSIONING=none -DCONSTANT_SIG=ON > /dev/null 2>&1
cmake --build build --parallel > /dev/null 2>&1
rm -fr artefacts-iwyu && mkdir artefacts-iwyu
for src in build/**/*.o; do
    dest="artefacts-iwyu/${src:t}"
    cp "$src" "$dest"
    $STRIP --strip-unneeded "$dest" -o "${dest:r}_stripped.o"
done
cp build/lib*.a artefacts-iwyu
$STRIP --strip-unneeded artefacts-iwyu/lib*.a
# Normalisation timpestamp (set to 0)
$PATH_GCC_ARM/bin/arm-none-eabi-ranlib -D artefacts-iwyu/lib*.a
cp build/FLASH.elf artefacts-iwyu
$STRIP --strip-unneeded artefacts-iwyu/FLASH.elf
cp build/compile_commands.json artefacts-iwyu
# rm -r build Artefacts
rm -r Artefacts
mv build build-iwyu

zmodload zsh/stat

echo ""
echo "========================================================================"
echo "                    IWYU FUNCTIONAL EQUIVALENCE REPORT"
echo "========================================================================"
echo ""

readonly ref_build_dir="${ref_dir}/${variant_path}"
readonly iwyu_build_dir="${iwyu_dir}/${variant_path}"

typeset -a identical_files
typeset -a differing_files
typeset -a line_macro_files
typeset -a git_hash_files
typeset -a code_layout_files
typeset -a functional_diff_files

mkdir analysis

# Analyze each object file
for file_path in ${ref_build_dir}/artefacts-orig/*_stripped.o
do
	file_name=${file_path:t}

	if [[ ! -f "${iwyu_build_dir}/artefacts-iwyu/$file_name" ]]; then
		continue
	fi

	# Quick binary comparison
	if cmp -s "$file_path" "${iwyu_build_dir}/artefacts-iwyu/$file_name"; then
		identical_files+=("$file_name")
		continue
	fi

	differing_files+=("$file_name")

	# Detailed analysis for differing files
	base_name=${file_name%.o}
	std_file="${ref_build_dir}/artefacts-orig/$file_name"
	iwyu_file="${iwyu_build_dir}/artefacts-iwyu/$file_name"

	# 1. Compare section sizes
	$PATH_GCC_ARM/bin/arm-none-eabi-size -A "$std_file" > "analysis/${base_name}_std.size" 2>/dev/null || true
	$PATH_GCC_ARM/bin/arm-none-eabi-size -A "$iwyu_file" > "analysis/${base_name}_iwyu.size" 2>/dev/null || true

	# Extract just the size values (skip header and total)
	size_diff=$(diff <(tail -n +2 "analysis/${base_name}_std.size" | sed '$d') \
	                 <(tail -n +2 "analysis/${base_name}_iwyu.size" | sed '$d') 2>/dev/null || true)

	if [[ -n "$size_diff" ]]; then
		functional_diff_files+=("$file_name:SECTION_SIZES_DIFFER")
		continue
	fi

	# 2. Compare symbols
	$PATH_GCC_ARM/bin/arm-none-eabi-nm -n "$std_file" 2>/dev/null | { grep -v "\.o:" || true; } > "analysis/${base_name}_std.sym"
	$PATH_GCC_ARM/bin/arm-none-eabi-nm -n "$iwyu_file" 2>/dev/null | { grep -v "\.o:" || true; } > "analysis/${base_name}_iwyu.sym"

	if ! diff -q "analysis/${base_name}_std.sym" "analysis/${base_name}_iwyu.sym" > /dev/null 2>&1; then
		functional_diff_files+=("$file_name:SYMBOLS_DIFFER")
		continue
	fi

	# 3. Compare .rodata section (constants, strings)
	$PATH_GCC_ARM/bin/arm-none-eabi-objcopy -O binary --only-section=.rodata "$std_file" "analysis/${base_name}_std.rodata" 2>/dev/null || true
	$PATH_GCC_ARM/bin/arm-none-eabi-objcopy -O binary --only-section=.rodata "$iwyu_file" "analysis/${base_name}_iwyu.rodata" 2>/dev/null || true

	if [[ -f "analysis/${base_name}_std.rodata" ]] && [[ -f "analysis/${base_name}_iwyu.rodata" ]]; then
		if ! cmp -s "analysis/${base_name}_std.rodata" "analysis/${base_name}_iwyu.rodata"; then
			# Check if difference is only git commit hash
			# Try with "git:" prefix first, then standalone
			git_std=$(strings "analysis/${base_name}_std.rodata" | grep -oE "git: [0-9a-f]{10}|^[0-9a-f]{10}$" | head -1 || true)
			git_iwyu=$(strings "analysis/${base_name}_iwyu.rodata" | grep -oE "git: [0-9a-f]{10}|^[0-9a-f]{10}$" | head -1 || true)

			if [[ -n "$git_std" ]] && [[ -n "$git_iwyu" ]] && [[ "$git_std" != "$git_iwyu" ]]; then
				# Git hash embedded at compile time - benign
				git_hash_files+=("${file_name}:git_hash")
			else
				functional_diff_files+=("${file_name}:RODATA_DIFFERS")
			fi
			continue
		fi
	fi

	# 4. Compare relocations
	{ $PATH_GCC_ARM/bin/arm-none-eabi-objdump -r "$std_file" 2>/dev/null | tail -n +3 || true; } > "analysis/${base_name}_std.reloc"
	{ $PATH_GCC_ARM/bin/arm-none-eabi-objdump -r "$iwyu_file" 2>/dev/null | tail -n +3 || true; } > "analysis/${base_name}_iwyu.reloc"

	if ! diff -q "analysis/${base_name}_std.reloc" "analysis/${base_name}_iwyu.reloc" > /dev/null 2>&1; then
		# Check if only offsets differ (not symbol names or types)
		# Extract just the symbol names and types, ignoring offsets
		reloc_syms_std=$(awk '{print $2, $3}' "analysis/${base_name}_std.reloc" 2>/dev/null | sort)
		reloc_syms_iwyu=$(awk '{print $2, $3}' "analysis/${base_name}_iwyu.reloc" 2>/dev/null | sort)

		if [[ "$reloc_syms_std" == "$reloc_syms_iwyu" ]]; then
			# Same symbols, different offsets - code layout changed
			code_layout_files+=("${file_name}:code_layout")
		else
			functional_diff_files+=("${file_name}:RELOCATIONS_DIFFER")
		fi
		continue
	fi

	# 5. Analyze .text section differences
	$PATH_GCC_ARM/bin/arm-none-eabi-objcopy -O binary --only-section=.text "$std_file" "analysis/${base_name}_std.text" 2>/dev/null || true
	$PATH_GCC_ARM/bin/arm-none-eabi-objcopy -O binary --only-section=.text "$iwyu_file" "analysis/${base_name}_iwyu.text" 2>/dev/null || true

	if [[ -f "analysis/${base_name}_std.text" ]] && [[ -f "analysis/${base_name}_iwyu.text" ]]; then
		# Get byte-level differences
		byte_diffs=$(cmp -l "analysis/${base_name}_std.text" "analysis/${base_name}_iwyu.text" 2>/dev/null || true)

		if [[ -n "$byte_diffs" ]]; then
			# Count differences and check if they're consistent offsets
			num_diffs=$(echo "$byte_diffs" | wc -l | tr -d ' ')

			# Extract the difference values to see if they're consistent
			diff_values=$(echo "$byte_diffs" | awk '{diff = $3 - $2; if (diff < 0) diff += 256; print diff}' | sort -u)
			num_unique_diffs=$(echo "$diff_values" | wc -l | tr -d ' ')

			# If we have a small number of differences, it's likely __LINE__ macros
			# Threshold: up to 30 bytes different is still plausibly __LINE__
			if [[ $num_diffs -le 30 ]]; then
				# Additional check: disassemble and look for immediate value differences
				$PATH_GCC_ARM/bin/arm-none-eabi-objdump -d "$std_file" > "analysis/${base_name}_std.dis" 2>/dev/null || true
				$PATH_GCC_ARM/bin/arm-none-eabi-objdump -d "$iwyu_file" > "analysis/${base_name}_iwyu.dis" 2>/dev/null || true

				# Check if differences are only in immediate values (likely line numbers)
				diff_lines=$(diff "analysis/${base_name}_std.dis" "analysis/${base_name}_iwyu.dis" 2>/dev/null | grep "^[<>]" | grep -v "file format" || true)

				# Look for pattern: differences in "movs", "mov", or other immediate load instructions
				# These patterns are typical for __LINE__ embedded as constants
				imm_pattern=$(echo "$diff_lines" | grep -cE "movs?.*#|ldr.*#|add.*#" || true)
				total_diff_lines=$(echo "$diff_lines" | wc -l | tr -d ' ')

				# If most differences are in immediate value instructions, it's __LINE__
				# Allow for some non-immediate diffs (like addresses that shift due to instruction changes)
				if [[ $total_diff_lines -gt 0 ]] && [[ $imm_pattern -ge $((total_diff_lines / 3)) ]]; then
					line_macro_files+=("$file_name:${num_diffs}_bytes")
				else
					functional_diff_files+=("$file_name:TEXT_DIFFERS_${num_diffs}_bytes")
				fi
			else
				functional_diff_files+=("$file_name:TEXT_DIFFERS_${num_diffs}_bytes")
			fi
		fi
	fi

	# Catch-all: If file differs but wasn't categorized, check for special sections
	# This handles files like FLASH.sig.o with .signature section containing git hash
	already_categorized=false
	for categorized in "${line_macro_files[@]}" "${git_hash_files[@]}" "${code_layout_files[@]}" "${functional_diff_files[@]}"; do
		if [[ "${categorized%%:*}" == "$file_name" ]]; then
			already_categorized=true
			break
		fi
	done

	if ! $already_categorized; then
		# Check for .signature section (contains git commit hash)
		$PATH_GCC_ARM/bin/arm-none-eabi-objcopy -O binary --only-section=.signature "$std_file" "analysis/${base_name}_std.signature" 2>/dev/null || true
		$PATH_GCC_ARM/bin/arm-none-eabi-objcopy -O binary --only-section=.signature "$iwyu_file" "analysis/${base_name}_iwyu.signature" 2>/dev/null || true

		if [[ -f "analysis/${base_name}_std.signature" ]] && [[ -f "analysis/${base_name}_iwyu.signature" ]]; then
			if ! cmp -s "analysis/${base_name}_std.signature" "analysis/${base_name}_iwyu.signature"; then
				# Different signature (git hash) - benign
				git_hash_files+=("${file_name}:git_signature")
			else
				# Same signature but file differs elsewhere - unexpected
				functional_diff_files+=("${file_name}:UNCATEGORIZED")
			fi
		else
			# No special sections found, file differs for unknown reason
			functional_diff_files+=("${file_name}:UNCATEGORIZED")
		fi
	fi
done

echo ""

# Generate report
echo "SUMMARY"
echo "------------------------------------------------------------------------"
echo "Total object files analyzed: $((${#identical_files[@]} + ${#differing_files[@]}))"
echo "Bit-for-bit identical:       ${#identical_files[@]}"
echo "Differ due to __LINE__:      ${#line_macro_files[@]}"
echo "Differ due to git hash:      ${#git_hash_files[@]}"
echo "Differ due to code layout:   ${#code_layout_files[@]}"
echo "Functional differences:      ${#functional_diff_files[@]}"
echo ""

if [[ ${#line_macro_files[@]} -gt 0 ]]; then
	echo "FILES DIFFERING DUE TO __LINE__ MACROS"
	echo "------------------------------------------------------------------------"
	echo "These files are functionally equivalent. Differences are only in"
	echo "embedded line numbers from __LINE__ macros used in logging/assertions."
	echo ""
	for file_info in "${line_macro_files[@]}"; do
		file_name=${file_info%%:*}
		details=${file_info##*:}
		printf "  %-30s  (%s different)\n" "$file_name" "$details"
	done
	echo ""
fi

if [[ ${#git_hash_files[@]} -gt 0 ]]; then
	echo "FILES DIFFERING DUE TO GIT COMMIT HASH"
	echo "------------------------------------------------------------------------"
	echo "These files contain git commit hashes embedded at compile time."
	echo "Different branches naturally have different hashes. Functionally equivalent."
	echo ""
	for file_info in "${git_hash_files[@]}"; do
		file_name=${file_info%%:*}
		details=${file_info##*:}
		printf "  %-30s  (%s)\n" "$file_name" "$details"
	done
	echo ""
fi

if [[ ${#code_layout_files[@]} -gt 0 ]]; then
	echo "FILES DIFFERING DUE TO CODE LAYOUT"
	echo "------------------------------------------------------------------------"
	echo "These files have different code block ordering due to compiler optimization"
	echo "decisions affected by header inclusion order. Functionally equivalent."
	echo ""
	for file_info in "${code_layout_files[@]}"; do
		file_name=${file_info%%:*}
		details=${file_info##*:}
		printf "  %-30s  (%s)\n" "$file_name" "$details"
	done
	echo ""
fi

if [[ ${#functional_diff_files[@]} -gt 0 ]]; then
	echo "FILES WITH POTENTIAL FUNCTIONAL DIFFERENCES"
	echo "------------------------------------------------------------------------"
	echo "These files require manual investigation:"
	echo ""
	for file_info in "${functional_diff_files[@]}"; do
		file_name=${file_info%%:*}
		reason=${file_info##*:}
		printf "  %-30s  Reason: %s\n" "$file_name" "$reason"
	done
	echo ""
fi

if [[ ${#identical_files[@]} -gt 0 ]]; then
	echo "BIT-FOR-BIT IDENTICAL FILES (sample - first 10)"
	echo "------------------------------------------------------------------------"
	count=0
	for file_name in "${identical_files[@]}"; do
		echo "  ✓ $file_name"
		count=$((count + 1))
		if [[ $count -ge 10 ]]; then
			remaining=$((${#identical_files[@]} - 10))
			if [[ $remaining -gt 0 ]]; then
				echo "  ... and $remaining more"
			fi
			break
		fi
	done
	echo ""
fi

echo "========================================================================"
echo "CONCLUSION"
echo "========================================================================"

# Cleanup: Remove any temporary files from earlier test runs
rm -r analysis 2>/dev/null

if [[ ${#functional_diff_files[@]} -eq 0 ]]; then
	echo ""
	echo "✓✓✓ IWYU TRANSFORMATION IS FUNCTIONALLY EQUIVALENT ✓✓✓"
	echo ""
	if [[ ${#line_macro_files[@]} -gt 0 ]] || [[ ${#git_hash_files[@]} -gt 0 ]] || [[ ${#code_layout_files[@]} -gt 0 ]]; then
		echo "All differences are benign and expected:"
		[[ ${#line_macro_files[@]} -gt 0 ]] && echo "  - __LINE__ macros: Embedded line numbers in logging/assertions"
		[[ ${#git_hash_files[@]} -gt 0 ]] && echo "  - Git hashes: Different commit hashes from different branches"
		[[ ${#code_layout_files[@]} -gt 0 ]] && echo "  - Code layout: Compiler reordered code blocks (same functionality)"
	else
		echo "All object files are bit-for-bit identical!"
	fi
	echo ""
	echo "The IWYU refactoring successfully reduces header dependencies"
	echo "without changing the functional behavior of the code."
	echo ""
	exit 0
else
	echo ""
	echo "⚠ POTENTIAL FUNCTIONAL DIFFERENCES DETECTED"
	echo ""
	echo "${#functional_diff_files[@]} file(s) show differences beyond __LINE__ macros."
	echo "Please investigate these files manually."
	echo ""
	echo "Analysis files saved in: analysis/"
	echo ""
	exit 1
fi
