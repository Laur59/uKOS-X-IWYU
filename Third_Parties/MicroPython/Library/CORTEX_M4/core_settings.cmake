# Settings for cortex M4 cores

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    CORTEX_M4_S
)

target_compile_options(core_flags INTERFACE
    -mthumb
    -mcpu=cortex-m4
    $<$<C_COMPILER_ID:Clang>:--target=thumbv7em-unknown-none-eabihf>
    -mtune=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -Wdouble-promotion
    $<$<C_COMPILER_ID:GNU>:-fsingle-precision-constant>
    $<$<C_COMPILER_ID:Clang>:-cl-single-precision-constant>
)
