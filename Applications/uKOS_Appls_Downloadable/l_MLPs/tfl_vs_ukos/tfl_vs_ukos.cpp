/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 *
 *           Launch 1 processes in C++:
 *
 *          - P0: Forever
 *                Wait 500-ms
 *                Compute the inference for the TensorFlowLite model
 *                Wait 500-ms
 *                Compute the inference for the uKOS-X model
 *                Display the inference execution times
 */

/*!
 * \file
 * \ingroup app_mlp
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 1 processes:
 *
 *          - P0: Forever
 *                  - Wait 500-ms
 *                  - Compute the inference for the TensorFlowLite model
 *                  - Wait 500-ms
 *                  - Compute the inference for the uKOS-X model
 *                  - Display the inference execution times
 *
 */

#include    <stdio.h>
#include    <stdlib.h>
#include    <math.h>
#include    <cinttypes>

#include    "crt0.h"
#include    "serial/serial.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "macros_runtime.h"
#include    "memo/memo.h"
#include    "led/led.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "random/random.h"
#include    "record/record.h"
#include    "types.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wcast-align"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wswitch-default"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wpedantic"
#include    "tensorflow/lite/core/c/common.h"
#include    "tensorflow/lite/micro/micro_interpreter.h"
#include    "tensorflow/lite/micro/micro_log.h"
#include    "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include    "tensorflow/lite/micro/micro_profiler.h"
#include    "tensorflow/lite/micro/recording_micro_interpreter.h"
#include    "tensorflow/lite/micro/system_setup.h"
#include    "tensorflow/lite/schema/schema_generated.h"

#ifdef CORTEX
#include    "tensorflow/lite/micro/cortex_m_generic/debug_log_callback.h"
#endif

#pragma GCC diagnostic pop

// TFLite & uKOS-X models

#include    "./_Models/mlp_model.c_inc"
#include    "./_Models/network.c_inc"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "tfl_vs_ukos  TLF vs uKOS-X inference test speed.       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  tfl_vs_ukos\n"
                                    "Output format: [result]\n\n";

#ifdef ROMABLE_S

// Prototypes

namespace {
static  int32_t     prgm(uint32_t argc, const char_t *argv[]);
}

MODULE(
    Tfl_vs_ukos,                        // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                        // Family (defined in the module.h)
    KNUM_ROMABLE_0,                     // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    prgm,                               // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1u<<BSHOW) | (1u<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);

#else
MODULE(
    UserAppl,                           // Module name (the first letter has to be upper case)
    KID_FAM_APPLICATIONS,               // Family (defined in the module.h)
    KNUM_APPLICATION,                   // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    aStart,                             // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1u<<BSHOW) | (1u<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);
#endif

// Suggested memory allocation

constexpr   int         KTENSOR_ARENA_SIZE = (10 * 1024);
namespace {
            uint8_t     tensor_arena[KTENSOR_ARENA_SIZE];
}

// Operators necessary for the model

namespace {
void    RegisterOps(tflite::MicroMutableOpResolver<3> &resolver) {

    resolver.AddFullyConnected();
    resolver.AddTanh();
    resolver.AddSoftmax();
}
}

#ifdef RISCV
extern "C"  char_t  putchar_(char_t ch) {

    UNUSED(ch);

    return ch;
}
#endif

#ifdef CORTEX
namespace {
void    debuglog(const char *s) {

    (void)dprintf(KSYST, "%s\n", s);
}
}
#endif

/*
 * \brief aProcess
 *
 * - P0: Forever
 *          - Wait 500-ms
 *          - Compute the inference for the TensorFlowLite model
 *          - Wait 500-ms
 *          - Compute the inference for the uKOS-X model
 *          - Display the inference execution times
 *
 */
namespace {
void    __attribute__ ((noreturn)) aProcess_0(const void *argument) {
    TfLiteTensor    *input;
    uint64_t        time[2];
    uint32_t        random[2], delta = 0U;
    uint32_t        minUkos = 0xFFFFFFFFU, minTFL = 0xFFFFFFFFU;
    uint32_t        maxUkos = 0U, maxTFL = 0U;
    float32_t       x, y, gain = 2.0F;

    UNUSED(argument);

    #if (defined(CORTEX))
    RegisterDebugLogCallback(debuglog);
    #endif

    while (true) {
        led_toggle(KLED_1);

// Load the TFLite model

        const tflite::Model *model = tflite::GetModel(mlp_model_tflite);
        if (model->version() != TFLITE_SCHEMA_VERSION) {
            (void)dprintf(KSYST, "Error : Model version not compatible\n");
            exit(EXIT_OS_FAILURE);
        }

// Create the resolver operator
// Create the micro interpreter

        tflite::MicroMutableOpResolver<3> resolver;
        RegisterOps(resolver);
        tflite::MicroInterpreter interpreter(model, resolver, tensor_arena, KTENSOR_ARENA_SIZE);

// Allocate for the tensors

        if (interpreter.AllocateTensors() != kTfLiteOk) {
            (void)dprintf(KSYST, "Error: Tensor allocation!\n");
            exit(EXIT_OS_FAILURE);
        }

// Measure the inference time
// --------------------------

        random_read(KRANDOM_SOFT, &random[0], 2u);
        x = (((float32_t)random[0] / (float32_t)(KRAND_MAX)) - 0.5f) * gain;
        y = (((float32_t)random[1] / (float32_t)(KRAND_MAX)) - 0.5f) * gain;

// For TensorFlowLite
// Prepare the inputs

        kern_suspendProcess(500U);
        input = interpreter.input(0);
        input->data.f[0] = x;
        input->data.f[1] = y;

        kern_readTickCount(&time[0]);
        interpreter.Invoke();
        kern_readTickCount(&time[1]);
        delta = (uint32_t)(time[1] - time[0]);

        if (delta < minTFL) { minTFL = delta; }
        if (delta > maxTFL) { maxTFL = delta; }
        (void)dprintf(KSYST, "Exec time for TensorFlowLite, min = %" PRIu32 " [us], max = %" PRIu32 " [us]\n", minTFL, maxTFL);

// For MLPN uKOS-X
// Prepare the inputs

        kern_suspendProcess(500U);
        vInput_L1[0] = x;
        vInput_L1[1] = y;

        kern_readTickCount(&time[0]);
        mlpn_compute(&aNetwork);
        kern_readTickCount(&time[1]);
        delta = (uint32_t)(time[1] - time[0]);

        if (delta < minUkos) { minUkos = delta; }
        if (delta > maxUkos) { maxUkos = delta; }
        (void)dprintf(KSYST, "Exec time for MLPN uKOS-X,    min = %" PRIu32 " [us], max = %" PRIu32 " [us]\n\n", minUkos, maxUkos);
    }
}
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
CPP_INTERNAL_SCOPE_BEGIN
MAIN_ENTRY(argc, argv[]) {
    proc_t  *process_0;

// ------------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden_0[]) =    "Process_User";
    STRG_LOC_CONST(aStrText_0[]) =    "Process user.                             (c) EFr-2026";

    UNUSED(argc);
    UNUSED(argv);

// Initialise the C++ constructors

    CPP_INIT_ARRAYS;

// Specifications for the processes

// NOLINTBEGIN(misc-const-correctness)
//
    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification_0,                    // Specifications (just use vSpecification_x)
        aStrText_0,                         // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_XLIB,                // KSZSTACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_0,                         // Code of the process
        aStrIden_0,                         // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_HIGH_02              // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

// NOLINTEND(misc-const-correctness)
//

    if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { exit(EXIT_OS_FAILURE); }

    LOG(KINFO_USER, "Application launched");
    return EXIT_OS_SUCCESS_CLI;
}
CPP_INTERNAL_SCOPE_END
