# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# TensorFlow Lite Micro integration for CMake builds

# Macro to integrate the TensorFlow Lite Micro library into the build
#
# This macro locates the prebuilt libTFLite.a for the current CORE,
# adds the public TFLite-micro include directories, defines the
# SYSTEM_TFLITE_S compile definition, and appends the imported library
# to UKOS_COMPONENTS so it is picked up by the link step in system.cmake.
#
# Requires (must be set before calling):
#   CORE        - Processor core (e.g. CORTEX_M85, CORTEX_M7, RV64IMAFDC)
#   PATH_UKOS   - Path to the uKOS-X repository root
#   ARTEFACTS_DIR   - Set by proj_config (used to record build flags)
#
# Updates in caller scope (macro):
#   PATH_INCLUDES   - Appended with the TFLite-micro public headers
#   UKOS_COMPONENTS - Appended with the TFLite imported library
#
# Usage example:
#   add_Tflite()
macro(add_Tflite)
    # Locate the prebuilt static library for this CORE
    find_library(TFLITE TFLite
        PATHS ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE}
        NO_DEFAULT_PATH
    )
    if(NOT TFLITE)
        message(FATAL_ERROR
            "add_Tflite: libTFLite.a not found for CORE=${CORE} in "
            "${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE}")
    endif()

    # Public include paths for users of the library
    set(_TFLITE_ROOT
        ${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/CORTEX_M_generic
    )
    list(APPEND PATH_INCLUDES
        ${_TFLITE_ROOT}
        ${_TFLITE_ROOT}/third_party/flatbuffers/include
        ${_TFLITE_ROOT}/third_party/gemmlowp
    )

    # System wide compile definition (mirrors SYSTEM_LVGL_S convention)
    add_compile_definitions(SYSTEM_TFLITE_S)
    file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-DSYSTEM_TFLITE_S ")

    # Append to the link list consumed by system.cmake
    list(APPEND UKOS_COMPONENTS ${TFLITE})
endmacro()
