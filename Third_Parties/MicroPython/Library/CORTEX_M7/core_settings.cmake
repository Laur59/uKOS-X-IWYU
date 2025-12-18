# Settings for cortex M7 cores

add_library(core_flags INTERFACE)

target_compile_definitions(core_flags INTERFACE
    CORTEX_M7_S
)

target_compile_options(core_flags INTERFACE
    -mthumb
    -mtune=cortex-m7
    -mcpu=cortex-m7
    $<$<C_COMPILER_ID:Clang>:--target=thumbv7em-unknown-none-eabihf>
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
)
