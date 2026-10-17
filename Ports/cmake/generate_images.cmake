# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Cross-platform generation of the .bin, .hex and .s3 images.
#
# The .bin fills the gaps between the sections with 0x00
# (i.e. alignment padding between output sections). The .hex
# and the .s3 are made from the .bin, so that they contain the
# same bytes; a programmer then writes 0x00 in these gaps
# instead of leaving them erased (0xFF), and the flash content
# matches the image signed by generate_signature.cmake.
# llvm-objcopy only supports --gap-fill for the binary output,
# hence this detour, which works with both toolchains.
#
# Required input variables (pass via -D on command line):
#   INPUT_ELF    - Path to input elf file (e.g., FLASH.elf)
#   OUTPUT_NAME  - Base name of the images (e.g., FLASH)
#   OBJCOPY      - Path to the objcopy of the toolchain
#   READELF      - Path to the readelf of the toolchain
#
# Example usage:
#   cmake -DINPUT_ELF=FLASH.elf \
#       -DOUTPUT_NAME=FLASH \
#       -DOBJCOPY=arm-none-eabi-objcopy \
#       -DREADELF=arm-none-eabi-readelf \
#       -P generate_images.cmake

# Validate required variables
foreach(var IN ITEMS INPUT_ELF OUTPUT_NAME OBJCOPY READELF)
    if(NOT DEFINED ${var})
        message(FATAL_ERROR "${var} variable is required")
    endif()
endforeach()

if(NOT EXISTS "${INPUT_ELF}")
    message(FATAL_ERROR "Input file does not exist: ${INPUT_ELF}")
endif()

# Binary image (gaps filled with 0x00 by objcopy)
execute_process(
    COMMAND "${OBJCOPY}" -O binary --strip-all "${INPUT_ELF}" "${OUTPUT_NAME}.bin"
    COMMAND_ERROR_IS_FATAL ANY
)

# Load address of the binary image: lowest physical address of the
# LOAD segments with a content (same output for GNU and LLVM readelf)
execute_process(
    COMMAND "${READELF}" -lhW "${INPUT_ELF}"
    OUTPUT_VARIABLE elf_headers
    COMMAND_ERROR_IS_FATAL ANY
)
string(REPLACE "\n" ";" elf_headers "${elf_headers}")

unset(load_address)
unset(entry_point)
foreach(line IN LISTS elf_headers)
    if(line MATCHES "^ *Entry point address: *(0x[0-9a-fA-F]+)")
        set(entry_point "${CMAKE_MATCH_1}")
    elseif(line MATCHES "^ *LOAD +0x[0-9a-fA-F]+ +0x[0-9a-fA-F]+ +(0x[0-9a-fA-F]+) +(0x[0-9a-fA-F]+)")
        set(address "${CMAKE_MATCH_1}")
        math(EXPR file_size "${CMAKE_MATCH_2}")
        if(file_size GREATER 0)
            math(EXPR value "${address}")
            math(EXPR end "${value} + ${file_size}")
            if(NOT DEFINED load_address OR value LESS lowest)
                set(load_address "${address}")
                set(lowest "${value}")
            endif()
            if(NOT DEFINED highest OR end GREATER highest)
                set(highest "${end}")
            endif()
        endif()
    endif()
endforeach()

if(NOT DEFINED load_address OR NOT DEFINED entry_point)
    message(FATAL_ERROR "No loadable segment or entry point found in ${INPUT_ELF}")
endif()

# A span larger than 64 MiB means that a section is loaded in another memory
# (i.e. an orphan section placed in RAM by the linker): the images would then
# fill the whole space in between

math(EXPR span "${highest} - ${lowest}")
if(span GREATER 67108864)
    math(EXPR span_mib "${span} / 1048576")
    message(WARNING "${INPUT_ELF}: the loadable sections span ${span_mib} MiB from ${load_address}; "
                    "check the linker script for a section loaded outside the code memory")
endif()

# Intel hex and Motorola s-record images, made from the binary one
foreach(format IN ITEMS ihex srec)
    if(format STREQUAL "ihex")
        set(extension hex)
    else()
        set(extension s3)
    endif()
    execute_process(
        COMMAND "${OBJCOPY}" -I binary -O ${format}
            --change-section-address .data=${load_address}
            --set-start ${entry_point}
            "${OUTPUT_NAME}.bin" "${OUTPUT_NAME}.${extension}"
        COMMAND_ERROR_IS_FATAL ANY
    )
endforeach()
