# Settings for cortex M33 cores

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    CORTEX_M33_S
)

target_compile_options(core_flags INTERFACE
    -mthumb
    -mtune=cortex-m33
    -mcpu=cortex-m33
    $<$<C_COMPILER_ID:Clang>:--target=thumbv8m.main-unknown-none-eabihf>
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    -Wdouble-promotion
    $<$<C_COMPILER_ID:GNU>:-fsingle-precision-constant>
    $<$<C_COMPILER_ID:Clang>:-cl-single-precision-constant>
)
