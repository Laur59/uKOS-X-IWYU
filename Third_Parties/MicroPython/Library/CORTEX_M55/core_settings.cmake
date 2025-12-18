# Settings for cortex M55 cores

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    CORTEX_M55_S
)

target_compile_options(core_flags INTERFACE
    -mthumb
    -mtune=cortex-m55
    -mcpu=cortex-m55
    $<$<C_COMPILER_ID:Clang>:--target=thumbv8.1m.main-unknown-none-eabihf>
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    -Wdouble-promotion
    $<$<C_COMPILER_ID:GNU>:-fsingle-precision-constant>
    $<$<C_COMPILER_ID:Clang>:-cl-single-precision-constant>
)
