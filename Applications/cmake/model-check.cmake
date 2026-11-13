# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Stop the configuration when a trained model included by an application is missing.

# The models of the neural network applications (l_MLPs) are not versioned: the
# scripts of their _Training folder create them, as each README describes. A
# fresh clone therefore configures, then fails to compile with a bare "file not
# found". This check reports it at configure time instead.
#
# An include of "<path>/_Training/<name>.c_inc" or "<path>/_Models/<name>.c_inc"
# is satisfied when that file exists, or when <name>.xxd exists next to it
# (ukos_add_tflite_models() generates the .c_inc from it during the build).
#
# Usage example:
#   ukos_check_trained_models(${OBJ})
function(ukos_check_trained_models)
    set(MISSING "")
    set(TRAINING_DIRS "")
    foreach(SRC IN LISTS ARGN)
        if(NOT EXISTS "${SRC}")
            continue()
        endif()
        file(STRINGS "${SRC}" INCLUDE_LINES
            REGEX "^[ \t]*#[ \t]*include[ \t]*\"[^\"]*(_Training|_Models)/[^\"]+\\.c_inc\""
        )
        cmake_path(GET SRC PARENT_PATH SRC_DIR)
        cmake_path(GET SRC FILENAME SRC_NAME)
        foreach(LINE IN LISTS INCLUDE_LINES)
            string(REGEX REPLACE "^[^\"]*\"([^\"]+)\".*$" "\\1" INC "${LINE}")
            cmake_path(ABSOLUTE_PATH INC BASE_DIRECTORY "${SRC_DIR}" NORMALIZE OUTPUT_VARIABLE INC_ABS)
            cmake_path(REPLACE_EXTENSION INC_ABS LAST_ONLY ".xxd" OUTPUT_VARIABLE INC_XXD)
            if(NOT EXISTS "${INC_ABS}" AND NOT EXISTS "${INC_XXD}")
                list(APPEND MISSING "  - ${INC_ABS}\n    (included by ${SRC_NAME})")
                cmake_path(GET INC_ABS PARENT_PATH INC_DIR)
                list(APPEND TRAINING_DIRS "${INC_DIR}")
            endif()
        endforeach()
    endforeach()

    if(NOT MISSING)
        return()
    endif()

    list(REMOVE_DUPLICATES TRAINING_DIRS)
    list(JOIN MISSING "\n" MISSING_TEXT)

    set(HOWTO "")
    foreach(DIR IN LISTS TRAINING_DIRS)
        cmake_path(GET DIR PARENT_PATH APP_DIR)
        string(APPEND HOWTO "\nSee ${APP_DIR}/README.md, section \"Dataset Creation and Classifier Generation\"")
        if(EXISTS "${DIR}/DB_Creator.py" AND EXISTS "${DIR}/build.sh")
            string(APPEND HOWTO ":\n"
                "    cd ${DIR}\n"
                "    python3 DB_Creator.py\n"
                "    ./build.sh\n")
            if(EXISTS "${DIR}/NN_model.py")
                string(APPEND HOWTO
                    "  (build.sh trains with TensorFlow, using the TFLite Python environment\n"
                    "   Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv when it exists)\n")
            endif()
        else()
            string(APPEND HOWTO ".\n")
        endif()
    endforeach()

    message(FATAL_ERROR
        "The trained model of this application is missing:\n"
        "${MISSING_TEXT}\n"
        "Models are not kept in git; they are created by training the network."
        "${HOWTO}"
        "Then run the cmake configuration (cmake --preset ...) again.")
endfunction()
