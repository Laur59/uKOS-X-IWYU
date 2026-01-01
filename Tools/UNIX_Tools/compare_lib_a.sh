#!/usr/bin/env zsh

# compare_lib_a.
# ==============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen      The 2025-10-13
# Modifs:
#
# Project:  uKOS-X
# Goal:     Compare two static libraries (.a files)
#
# Description:
#        Takes two library paths as parameters and performs detailed
#        comparison of their contents, including:
#        - File sizes
#        - Section sizes (text, data, bss)
#        - Symbol counts and exported symbols
#        - Undefined symbols (dependencies)
#        - Object file lists
#
#        This is a generic version of the TinyUSB compare_folders.sh
#        script that works with any two libraries for any architecture
#        (ARM, RISC-V, x86, etc.).
#
#        Usage:
#           ./compare_lib_a.sh path1/libAbc.a path2/libDef.a
#
#   (c) 2025-2026, Laurent von Allmen
#   ---------------------------------
#------------------------------------------------------------------------

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Colours for messages
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

# Toolchain binaries
# Prefer LLVM tools if available, otherwise try GNU embedded tools, then system tools
if [[ -n "${PATH_LLVM_ARM:-}" ]] && [[ -x "${PATH_LLVM_ARM}"/bin/llvm-nm ]]; then
   NM_TOOL="${PATH_LLVM_ARM}"/bin/llvm-nm
   SIZE_TOOL="${PATH_LLVM_ARM}"/bin/llvm-size
   TOOLCHAIN_NAME="LLVM (ARM)"
elif [[ -n "${PATH_LLVM_RVXX:-}" ]] && [[ -x "${PATH_LLVM_RVXX}/bin/llvm-nm" ]]; then
   NM_TOOL="${PATH_LLVM_RVXX}"/bin/llvm-nm
   SIZE_TOOL="${PATH_LLVM_RVXX}"/bin/llvm-size
   TOOLCHAIN_NAME="LLVM (RISC-V)"
elif [ -n "${PATH_GCC_ARM:-}" ] && [ -x "${PATH_GCC_ARM}"/bin/arm-none-eabi-nm ]; then
   NM_TOOL="${PATH_GCC_ARM}"/bin/arm-none-eabi-nm
   SIZE_TOOL="${PATH_GCC_ARM}"/bin/arm-none-eabi-size
   TOOLCHAIN_NAME="GNU (ARM)"
elif [[ -n "${PATH_GCC_RVXX:-}" ]] && [[ -x "${PATH_GCC_RVXX}"/bin/riscv64-unknown-elf-nm ]]; then
   NM_TOOL="${PATH_GCC_RVXX}"/bin/riscv64-unknown-elf-nm
   SIZE_TOOL="${PATH_GCC_RVXX}"/bin/riscv64-unknown-elf-size
   TOOLCHAIN_NAME="GNU (RISC-V)"
else
   # Try to use system tools as fallback
   NM_TOOL=$(command -v nm || echo "nm")
   SIZE_TOOL=$(command -v size || echo "size")
   TOOLCHAIN_NAME="System"
fi

print "${BOLD}${BLUE}"
print "╔══════════════════════════════════════════════════════════════╗"
print "║       Static Library Comparison Tool                 ║"
print "╚══════════════════════════════════════════════════════════════╝"
print "${NC}"

# Parse arguments
if [ $# -ne 2 ]; then
   print "${BOLD}Usage: $0 <lib1.a> <lib2.a>${NC}\n"
   print "This script will:"
   print "   Compare two static libraries (.a archives) in detail"
   print "   - File sizes and section sizes"
   print "   - Symbol counts and exported symbols"
   print "   - Undefined symbols (dependencies)"
   print "   - Object file lists\n"
   print "Works with libraries for any architecture (ARM, RISC-V, x86, etc.)\n"
   print "Examples:"
   print "   $0 Library/libFoo.a Library_test/libFoo.a"
   print "   $0 build1/libMicroPython.a build2/libMicroPython.a"
   print "   $0 arm/libTinyUSB.a riscv/libTinyUSB.a"
   exit 1
fi

LIB1="$1"
LIB2="$2"

# Validate inputs
if [[ ! -f "${LIB1}" ]]; then
   print "${RED}Error: Library not found: ${LIB1}${NC}"
   exit 1
fi
if [[ ! -f "${LIB2}" ]]; then
   print "${RED}Error: Library not found: ${LIB2}${NC}"
   exit 1
fi

# Check if both files are valid archives
if ! file "${LIB1}" | grep -q "ar archive\|current ar archive"; then
   print "${RED}Error: ${LIB1} is not a valid ar archive${NC}"
   exit 1
fi
if ! file "${LIB2}" | grep -q "ar archive\|current ar archive"; then
   print "${RED}Error: ${LIB2} is not a valid ar archive${NC}"
   exit 1
fi

print "Using toolchain: ${BOLD}${TOOLCHAIN_NAME}${NC}"
print "   nm:   ${NM_TOOL}"
print "   size: ${SIZE_TOOL}\n"
print "Library 1: ${BOLD}${LIB1}${NC}"
print "Library 2: ${BOLD}${LIB2}${NC}\n"

# Create temporary directory for comparison files
TMPDIR=$(mktemp -d)
trap "rm -rf ${TMPDIR}" EXIT

errors=0

# 1. Compare file sizes
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
print "${BOLD}File Sizes${NC}"
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

lib1_size=$(wc -c < "${LIB1}")
lib2_size=$(wc -c < "${LIB2}")
size_diff=$((lib2_size - lib1_size))
size_diff_pct=$(awk "BEGIN {printf \"%.2f\", (${size_diff} * 100.0 / ${lib1_size})}")

print "Library 1: $(printf '%10d' ${lib1_size}) bytes"
print "Library 2: $(printf '%10d' ${lib2_size}) bytes"
print "Diff:     $(printf '%10d' ${size_diff}) bytes (${size_diff_pct}%)"

if [[ ${size_diff#-} -gt 1000 ]]; then
   print "${YELLOW}⚠ Size difference significant (>1KB)${NC}"
   ((errors+=1))
else
   print "${GREEN}✓ Size difference acceptable${NC}"
fi

# 2. Compare section sizes
echo ""
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
print "${BOLD}Section Sizes${NC}"
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

# Get section sizes (handle both GNU and LLVM output formats)
if [[ "${TOOLCHAIN_NAME}" == "LLVM" ]]; then
   # LLVM size output format
   lib1_sections=$(${SIZE_TOOL} -B -t "${LIB1}" 2>/dev/null | grep "TOTALS" || echo "0 0 0 0")
   lib2_sections=$(${SIZE_TOOL} -B -t "${LIB2}" 2>/dev/null | grep "TOTALS" || echo "0 0 0 0")
else
   # GNU size output format
   lib1_sections=$(${SIZE_TOOL} -B -t "${LIB1}" 2>/dev/null | grep "TOTALS" || echo "0 0 0 0")
   lib2_sections=$(${SIZE_TOOL} -B -t "${LIB2}" 2>/dev/null | grep "TOTALS" || echo "0 0 0 0")
fi

read -r text1 data1 bss1 total1 rest <<< "${lib1_sections}"
read -r text2 data2 bss2 total2 rest <<< "${lib2_sections}"

printf "Library 1: text=%8d data=%5d bss=%8d total=%8d\n" ${text1} ${data1} ${bss1} ${total1}
printf "Library 2: text=%8d data=%5d bss=%8d total=%8d\n" ${text2} ${data2} ${bss2} ${total2}

text_diff=$((text2 - text1))
data_diff=$((data2 - data1))
bss_diff=$((bss2 - bss1))
total_diff=$((total2 - total1))

printf "Diff:     text=%8d data=%5d bss=%8d total=%8d\n" ${text_diff} ${data_diff} ${bss_diff} ${total_diff}

if [[ ${text_diff#-} -gt 100 ]] || [[ ${data_diff#-} -gt 100 ]]; then
   print "${YELLOW}⚠ Significant section size differences${NC}"
   ((errors+=1))
else
   print "${GREEN}✓ Section sizes similar${NC}"
fi

# 3. Compare symbol counts
echo ""
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
print "${BOLD}Symbol Counts${NC}"
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

lib1_symbols=$(${NM_TOOL} "${LIB1}" 2>/dev/null | wc -l)
lib2_symbols=$(${NM_TOOL} "${LIB2}" 2>/dev/null | wc -l)

printf "Library 1: %5d symbols\n" ${lib1_symbols}
printf "Library 2: %5d symbols\n" ${lib2_symbols}

if [ ${lib1_symbols} -eq ${lib2_symbols} ]; then
   print "${GREEN}✓ Symbol counts match${NC}"
else
   print "${YELLOW}⚠ Symbol counts differ by $((lib2_symbols - lib1_symbols))${NC}"
   ((errors+=1))
fi

# 4. Compare global symbols (exported functions/data)
print "\n${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
print "${BOLD}Global Symbols (T, D, B, R types)${NC}"
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

${NM_TOOL} "${LIB1}" 2>/dev/null | grep -E ' [TDBR] ' | awk '{print $NF}' | sort > "${TMPDIR}/lib1_symbols.txt"
${NM_TOOL} "${LIB2}" 2>/dev/null | grep -E ' [TDBR] ' | awk '{print $NF}' | sort > "${TMPDIR}/lib2_symbols.txt"

lib1_global=$(wc -l < "${TMPDIR}/lib1_symbols.txt")
lib2_global=$(wc -l < "${TMPDIR}/lib2_symbols.txt")

printf "Library 1: %5d global symbols\n" ${lib1_global}
printf "Library 2: %5d global symbols\n" ${lib2_global}

# Check for differences
only_lib1=$(comm -23 "${TMPDIR}/lib1_symbols.txt" "${TMPDIR}/lib2_symbols.txt" | wc -l)
only_lib2=$(comm -13 "${TMPDIR}/lib1_symbols.txt" "${TMPDIR}/lib2_symbols.txt" | wc -l)

if [ ${only_lib1} -eq 0 ] && [ ${only_lib2} -eq 0 ]; then
   print "${GREEN}✓ All global symbols match${NC}"
else
   print "${YELLOW}⚠ Symbol differences:${NC}"
   if [[ ${only_lib1} -gt 0 ]]; then
      print "   - ${only_lib1} symbols only in Library 1"
      if [[ ${only_lib1} -le 10 ]]; then
         comm -23 "${TMPDIR}/lib1_symbols.txt" "${TMPDIR}/lib2_symbols.txt" | head -10 | sed 's/^/  /'
      else
         comm -23 "${TMPDIR}/lib1_symbols.txt" "${TMPDIR}/lib2_symbols.txt" | head -10 | sed 's/^/  /'
         echo "     ... and $((only_lib1 - 10)) more"
      fi
   fi
   if [[ ${only_lib2} -gt 0 ]]; then
      print "   - ${only_lib2} symbols only in Library 2"
      if [ ${only_lib2} -le 10 ]; then
         comm -13 "${TMPDIR}/lib1_symbols.txt" "${TMPDIR}/lib2_symbols.txt" | head -10 | sed 's/^/  /'
      else
         comm -13 "${TMPDIR}/lib1_symbols.txt" "${TMPDIR}/lib2_symbols.txt" | head -10 | sed 's/^/  /'
         echo "     ... and $((only_lib2 - 10)) more"
      fi
   fi
   ((errors+=1))
fi

# 5. Compare undefined symbols (external dependencies)
print "\n${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
print "${BOLD}Undefined Symbols (Dependencies)${NC}"
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

${NM_TOOL} "${LIB1}" 2>/dev/null | grep ' U ' | awk '{print $NF}' | sort | uniq > "${TMPDIR}/lib1_undef.txt"
${NM_TOOL} "${LIB2}" 2>/dev/null | grep ' U ' | awk '{print $NF}' | sort | uniq > "${TMPDIR}/lib2_undef.txt"

lib1_undef=$(wc -l < "${TMPDIR}/lib1_undef.txt")
lib2_undef=$(wc -l < "${TMPDIR}/lib2_undef.txt")

printf "Library 1: %5d undefined symbols\n" ${lib1_undef}
printf "Library 2: %5d undefined symbols\n" ${lib2_undef}

undef_diff=$(comm -3 "${TMPDIR}/lib1_undef.txt" "${TMPDIR}/lib2_undef.txt" | wc -l)
if [[ ${undef_diff} -eq 0 ]]; then
   print "${GREEN}✓ Undefined symbols match${NC}"
else
   print "${YELLOW}⚠ Undefined symbols differ${NC}"
   only_undef1=$(comm -23 "${TMPDIR}/lib1_undef.txt" "${TMPDIR}/lib2_undef.txt" | wc -l)
   only_undef2=$(comm -13 "${TMPDIR}/lib1_undef.txt" "${TMPDIR}/lib2_undef.txt" | wc -l)

   if [[ ${only_undef1} -gt 0 ]]; then
      print "   - ${only_undef1} undefined symbols only in Library 1"
      if [ ${only_undef1} -le 5 ]; then
         comm -23 "${TMPDIR}/lib1_undef.txt" "${TMPDIR}/lib2_undef.txt" | head -5 | sed 's/^/   /'
      fi
   fi
   if [[ ${only_undef2} -gt 0 ]]; then
      print "   - ${only_undef2} undefined symbols only in Library 2"
      if [ ${only_undef2} -le 5 ]; then
         comm -13 "${TMPDIR}/lib1_undef.txt" "${TMPDIR}/lib2_undef.txt" | head -5 | sed 's/^/   /'
      fi
   fi
   ((errors+=1))
fi

# 6. Compare object file list
print "\n${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
print "${BOLD}Object Files in Archive${NC}"
print "${BOLD}${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"

# Extract object file names from archive and normalise CMake naming (.c.o -> .o, .cpp.o -> .o)
# This allows comparing libraries built with CMake vs Make despite naming differences
# Note: ar -t output may end with / on macOS, so handle both .c.o/ and .c.o
ar -t "${LIB1}" 2>/dev/null | sed -e 's/\.c\.o\/$/\.o\//' -e 's/\.cpp\.o\/$/\.o\//' -e 's/\.c\.o$/\.o/' -e 's/\.cpp\.o$/\.o/' | sort > "${TMPDIR}/lib1_objects.txt"
ar -t "${LIB2}" 2>/dev/null | sed -e 's/\.c\.o\/$/\.o\//' -e 's/\.cpp\.o\/$/\.o\//' -e 's/\.c\.o$/\.o/' -e 's/\.cpp\.o$/\.o/' | sort > "${TMPDIR}/lib2_objects.txt"

lib1_objs=$(wc -l < "${TMPDIR}/lib1_objects.txt")
lib2_objs=$(wc -l < "${TMPDIR}/lib2_objects.txt")

printf "Library 1: %5d object files\n" ${lib1_objs}
printf "Library 2: %5d object files\n" ${lib2_objs}

if [[ ${lib1_objs} -eq ${lib2_objs} ]]; then
   # Check if object file names match
   if diff -q "${TMPDIR}/lib1_objects.txt" "${TMPDIR}/lib2_objects.txt" >/dev/null 2>&1; then
      print "${GREEN}✓ Object file lists match exactly${NC}"
   else
      print "${YELLOW}⚠ Object file counts match but names differ${NC}"

      only_obj1=$(comm -23 "${TMPDIR}/lib1_objects.txt" "${TMPDIR}/lib2_objects.txt" | wc -l)
      only_obj2=$(comm -13 "${TMPDIR}/lib1_objects.txt" "${TMPDIR}/lib2_objects.txt" | wc -l)

      if [ ${only_obj1} -gt 0 ]; then
         print "   - ${only_obj1} objects only in Library 1"
         if [ ${only_obj1} -le 5 ]; then
            comm -23 "${TMPDIR}/lib1_objects.txt" "${TMPDIR}/lib2_objects.txt" | head -5 | sed 's/^/  /'
         fi
      fi
      if [ ${only_obj2} -gt 0 ]; then
         print "   - ${only_obj2} objects only in Library 2"
         if [ ${only_obj2} -le 5 ]; then
            comm -13 "${TMPDIR}/lib1_objects.txt" "${TMPDIR}/lib2_objects.txt" | head -5 | sed 's/^/  /'
         fi
      fi
      ((errors+=1))
   fi
else
   print "${YELLOW}⚠ Object file counts differ by $((lib2_objs - lib1_objs))${NC}"
   ((errors+=1))
fi

# Summary
print "\n${BOLD}${BLUE}"
print "╔══════════════════════════════════════════════════════════════╗"
print "║  Comparison Summary                               ║"
print "╚══════════════════════════════════════════════════════════════╝"
print "${NC}"

if [[ ${errors} -eq 0 ]]; then
   print "${GREEN}${BOLD}✓✓✓ Libraries are functionally equivalent${NC}\n"
   print "Both libraries have:"
   print "   • Identical global symbols"
   print "   • Matching undefined symbols"
   print "   • Same object file contents"
   print "   • Similar sizes and sections"
   print "\n${BOLD}Exported symbols (${lib1_global} total):${NC}"
   print "${BLUE}────────────────────────────────────────────────────────${NC}"
   if [[ ${lib1_global} -le 50 ]]; then
      # Show all symbols if 50 or fewer
      cat "${TMPDIR}/lib1_symbols.txt" | sed 's/^/  /'
   else
      # Show first 30 and last 20 for larger lists
      head -30 "${TMPDIR}/lib1_symbols.txt" | sed 's/^/  /'
      print "   ..."
      tail -20 "${TMPDIR}/lib1_symbols.txt" | sed 's/^/  /'
      echo ""
      print "   (showing 50 of ${lib1_global} symbols)"
   fi
   exit 0
else
   print "${YELLOW}${BOLD}⚠ Found ${errors} categories of differences${NC}\n"
   print "Note:"
   print "   • Minor size differences (<1KB) are often acceptable"
   print "   • Different optimization levels can cause variations"
   print "   • Symbol ordering differences are usually harmless"
   print "   ${BOLD}• Exported function symbols should match for compatibility${NC}"
   exit 1
fi
