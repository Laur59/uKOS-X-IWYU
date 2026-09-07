/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host unit tests for OS/Lib_neurals/mlpn/mlpn.c.
 *
 * The first module in this suite with NO environmental coupling at all: no
 * clock, no random source, no heap, no port layer, no kernel. Nothing for a
 * fake to distort, so every assertion here is an exact numeric one and a
 * failure means the arithmetic changed - a materially stronger claim than the
 * string comparisons the CLI suites make.
 *
 * Only two functions are public, but every static kernel is reachable through
 * them by setting oNonLinear, so this does not need to #include the .c.
 *
 * On exactness. The expected values are RESTATEMENTS of each formula rather
 * than decimal literals copied from a run, so a test says what the arithmetic
 * should be instead of what it happened to produce. That this is bit-exact was
 * measured, not assumed: the restated and compiled forms agree to the last bit
 * both with clang's default -ffp-contract=fast and with contraction off.
 *
 * Two things here are NOT pinned exactly, each for a measured reason:
 * KMLPN_TAN0, which goes through the host's tanhf; and the shipped-network
 * golden at the end, whose 74-element dot products round differently at -O0 and
 * -O2. Everything else is exact.
 *
 * WHAT THIS CANNOT REACH. local_dot_f32 has two implementations, and the host
 * only ever compiles one. __ARM_FEATURE_MVE is M-profile only and is undefined
 * on host arm64, so the Helium path (mlpn.c:349-408) - including its tail
 * predication, which is the fiddly part - is unreachable here. These tests pin
 * the scalar reference at mlpn.c:411-417. Closing that gap needs a board test
 * running the same vectors through the vector path and diffing against these
 * results; tfl_vs_ukos is the precedent.
 */

#include    <math.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <string.h>

#include    "mlpn/mlpn.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "types.h"
#include    "ukos_test.h"

extern  const uKOS_module_t     aMlpn_Specifications;

// A one-input, one-output layer. The weight vector is {1, 0}, so the dot
// product is the input untouched and the activation function is under test in
// isolation: local_run(kind, x) returns kind(x) and nothing else.
//
// The input vector is 2 wide because the last slot is the bias - mlpn has no
// separate bias field, it appends a constant 1 to every input vector and lets
// the weight matrix carry the offset.

#define KNB_IN              2U                          // 1 real input + the bias
#define KNB_OUT             1U

static  float32_t       vInput[KNB_IN];
static  float32_t       vActivation[KNB_OUT];
static  float32_t       vOutput[KNB_OUT + 1U];
static  float32_t       vWeight[KNB_OUT][KNB_IN];
static  mlpnLayer_t     vLayer;
static  mlpnNetwork_t   vNetwork;

/*
 * \brief Fixture: a 1x1 network whose dot product is the identity
 *
 */
static  void    local_setup(void) {

    ukos_t_begin("UTC0");

    (void)memset(&vInput[0],      0, sizeof(vInput));
    (void)memset(&vActivation[0], 0, sizeof(vActivation));
    (void)memset(&vOutput[0],     0, sizeof(vOutput));

    vWeight[0][0] = 1.0F;                               // the real input
    vWeight[0][1] = 0.0F;                               // the bias, ignored

    vLayer.oNonLinear  = KMLPN_LINE;
    vLayer.oNBInput    = KNB_IN;
    vLayer.oNBOutput   = KNB_OUT;
    vLayer.oInput      = &vInput[0];
    vLayer.oActivation = &vActivation[0];
    vLayer.oOutput     = &vOutput[0];
    vLayer.oWeight     = &vWeight[0][0];

    vNetwork.oNBLayer  = 1U;
    vNetwork.oLayer_L1 = &vLayer;
    vNetwork.oLayer_L2 = nullptr;
    vNetwork.oLayer_L3 = nullptr;
    vNetwork.oLayer_L4 = nullptr;
    vNetwork.oLayer_L5 = nullptr;

    EXPECT_EQ_I(mlpn_configure(&vNetwork), KERR_MLPN_NOERR);
}

/*
 * \brief Run one activation kernel on one value
 *
 */
static  float32_t   local_run(uint32_t kind, float32_t x) {

    vLayer.oNonLinear = kind;
    vInput[0]         = x;

    EXPECT_EQ_I(mlpn_compute(&vNetwork), KERR_MLPN_NOERR);
    return vOutput[0];
}

// The bias contract
// =================

TEST(mlpn_configure_writes_the_bias_slot) {
    local_setup();

// mlpn has no bias field: local_initialiseLayer writes a constant 1.0 into the
// LAST input slot, and the weight matrix's last column is the offset. Point the
// weight at that slot alone and the output is the bias itself.

    EXPECT_EQ_F32(vInput[KNB_IN - 1U], 1.0F);

    vWeight[0][0] = 0.0F;
    vWeight[0][1] = 1.0F;
    EXPECT_EQ_F32(local_run(KMLPN_LINE, 12345.0F), 1.0F);
}

TEST(mlpn_compute_without_configure_is_silently_wrong) {
    ukos_t_begin("UTC0");

    (void)memset(&vInput[0], 0, sizeof(vInput));
    vWeight[0][0] = 0.0F;
    vWeight[0][1] = 1.0F;                               // read the bias slot only

    vLayer.oNonLinear  = KMLPN_LINE;
    vLayer.oNBInput    = KNB_IN;
    vLayer.oNBOutput   = KNB_OUT;
    vLayer.oInput      = &vInput[0];
    vLayer.oActivation = &vActivation[0];
    vLayer.oOutput     = &vOutput[0];
    vLayer.oWeight     = &vWeight[0][0];

    vNetwork.oNBLayer  = 1U;
    vNetwork.oLayer_L1 = &vLayer;
    vNetwork.oLayer_L2 = nullptr;
    vNetwork.oLayer_L3 = nullptr;
    vNetwork.oLayer_L4 = nullptr;
    vNetwork.oLayer_L5 = nullptr;

// No configure. mlpn_compute calls local_init(), whose body is empty, and never
// local_initialiseLayer - so the bias slot keeps whatever the caller left. The
// result is wrong and the status is still NOERR: nothing tells the caller.

    EXPECT_EQ_I(mlpn_compute(&vNetwork), KERR_MLPN_NOERR);
    EXPECT_EQ_F32(vOutput[0], 0.0F);                    // should have been 1.0

    KNOWN_BUG("mlpn-compute-without-configure-silent", (vOutput[0] == 0.0F));
}

// The seven activation kernels
// ============================

TEST(mlpn_line_is_the_identity) {
    local_setup();

    EXPECT_EQ_F32(local_run(KMLPN_LINE,  0.0F),      0.0F);
    EXPECT_EQ_F32(local_run(KMLPN_LINE,  0.5F),      0.5F);
    EXPECT_EQ_F32(local_run(KMLPN_LINE, -0.5F),     -0.5F);
    EXPECT_EQ_F32(local_run(KMLPN_LINE,  1000.0F),   1000.0F);
    EXPECT_EQ_F32(local_run(KMLPN_LINE, -1000.0F),  -1000.0F);
}

TEST(mlpn_relu_clamps_at_zero_and_is_the_identity_above) {
    local_setup();

    EXPECT_EQ_F32(local_run(KMLPN_RELU, -1.0F),  0.0F);
    EXPECT_EQ_F32(local_run(KMLPN_RELU, -0.001F), 0.0F);
    EXPECT_EQ_F32(local_run(KMLPN_RELU,  0.0F),  0.0F);     // the boundary is <=

// `p <= 0` versus `p < 0` cannot be distinguished by any assertion worth
// making: at +0.0 both yield +0.0, and the only input they treat differently is
// -0.0, where one returns +0.0 and the other -0.0. IEEE says those compare
// equal, nothing downstream can tell them apart, and pinning the sign of a zero
// would assert something no caller depends on. Equivalent mutant, recorded
// rather than chased.

    EXPECT_EQ_F32(local_run(KMLPN_RELU,  0.5F),  0.5F);
    EXPECT_EQ_F32(local_run(KMLPN_RELU,  1.0F),  1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_RELU,  2.0F),  2.0F);     // NOT clamped above
}

TEST(mlpn_tan3_is_a_hard_clamp_to_plus_minus_one) {
    local_setup();

    EXPECT_EQ_F32(local_run(KMLPN_TAN3, -2.0F), -1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN3, -1.0F), -1.0F);     // inclusive
    EXPECT_EQ_F32(local_run(KMLPN_TAN3, -0.5F), -0.5F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN3,  0.0F),  0.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN3,  0.5F),  0.5F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN3,  1.0F),  1.0F);     // inclusive
    EXPECT_EQ_F32(local_run(KMLPN_TAN3,  2.0F),  1.0F);

// A value strictly BETWEEN the bound and the next test point. Added after a
// mutation moving the bound from 1.0 to 2.0 survived: at p == 1.0 the clamp and
// the identity both give 1.0, and at p == 2.0 the moved bound still clamps, so
// neither of the cases above can tell the two apart.

    EXPECT_EQ_F32(local_run(KMLPN_TAN3,  1.5F),  1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN3, -1.5F), -1.0F);
}

TEST(mlpn_tan2_is_the_pade_ratio_inside_its_clamp) {
    float32_t   p, p2;

    local_setup();

    EXPECT_EQ_F32(local_run(KMLPN_TAN2,  0.0F), 0.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN2, -4.0F), -1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN2,  4.0F), +1.0F);

// p (27 + p^2) / (27 + 9 p^2), restated rather than copied from a run. Measured
// to be bit-exact against the compiled form.

    p  = 1.0F;
    p2 = p * p;
    EXPECT_EQ_F32(local_run(KMLPN_TAN2, p), (p * (27.0F + p2)) / (27.0F + (9.0F * p2)));

    p  = -2.0F;
    p2 = p * p;
    EXPECT_EQ_F32(local_run(KMLPN_TAN2, p), (p * (27.0F + p2)) / (27.0F + (9.0F * p2)));

// Odd, as tanh is.

    EXPECT_EQ_F32(local_run(KMLPN_TAN2, -1.0F), -local_run(KMLPN_TAN2, 1.0F));
}

TEST(mlpn_tan1_is_the_lambert_ratio_inside_its_clamp) {
    float32_t   p, s, a, b;

    local_setup();

    EXPECT_EQ_F32(local_run(KMLPN_TAN1,  0.0F), 0.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN1, -4.0F), -1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN1,  4.0F), +1.0F);

    p = 1.0F;
    s = p * p;
    a = (((((s + 378.0F) * s) + 17325.0F) * s) + 135135.0F) * p;
    b = (((((28.0F * s) + 3150.0F) * s) + 62370.0F) * s) + 135135.0F;
    EXPECT_EQ_F32(local_run(KMLPN_TAN1, p), a / b);

// It is much the better approximation of the two: at 1.0 it is within 1e-6 of
// true tanh where TAN2 is out by ~1.6e-2.

    EXPECT_NEAR_F32(local_run(KMLPN_TAN1, 1.0F), tanhf(1.0F), 1.0e-6F);
    EXPECT_TRUE(fabsf(local_run(KMLPN_TAN2, 1.0F) - tanhf(1.0F)) > 1.0e-3F);
}

TEST(mlpn_the_two_tanh_approximations_clamp_at_different_bounds) {
    float32_t   p, p2;

    local_setup();

// Exactly 3.0 is where the two differ in FORM: TAN1 guards with `p > +3.0F` so
// 3.0 falls through to its polynomial, while TAN2 guards with `p >= +3.0F` and
// takes the clamp.
//
// For TAN2 that is a distinction without a difference, and provably so: at
// p == 3 the ratio is 3(27+9) / (27+81) = 108/108, exactly 1.0. Its clamp is
// redundant at the bound. A mutation weakening `>=` to `>` therefore survives
// and always will - an equivalent mutant, not a coverage gap. TAN1's guard is
// NOT redundant, and the assertion below is what pins it.

    p  = 3.0F;
    p2 = p * p;

    EXPECT_EQ_F32(local_run(KMLPN_TAN2, p), 1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_TAN2, p), (0.0F * p2) + 1.0F);

    EXPECT_TRUE(local_run(KMLPN_TAN1, p) < 1.0F);
    EXPECT_NEAR_F32(local_run(KMLPN_TAN1, p), tanhf(3.0F), 1.0e-4F);

// And symmetrically at -3.0.

    EXPECT_EQ_F32(local_run(KMLPN_TAN2, -3.0F), -1.0F);
    EXPECT_TRUE(local_run(KMLPN_TAN1, -3.0F) > -1.0F);
}

TEST(mlpn_tan0_is_the_libm_tanh) {
    local_setup();

// The only kernel that needs a tolerance rather than an exact compare: it calls
// the host's tanhf, and newlib's need not agree with macOS's in the last bit.
// Everything else in this file is pinned exactly.

    EXPECT_NEAR_F32(local_run(KMLPN_TAN0,  0.0F), 0.0F,          1.0e-7F);
    EXPECT_NEAR_F32(local_run(KMLPN_TAN0,  1.0F), tanhf(1.0F),   1.0e-6F);
    EXPECT_NEAR_F32(local_run(KMLPN_TAN0, -1.0F), tanhf(-1.0F),  1.0e-6F);

// No clamp at all, unlike TAN1/TAN2 - it saturates because tanh does.

    EXPECT_NEAR_F32(local_run(KMLPN_TAN0, 20.0F), 1.0F, 1.0e-6F);
}

// Softmax
// =======

TEST(mlpn_softmax_of_a_single_output_is_exactly_one) {
    local_setup();

// One output means a[0] - max is exactly 0, so whatever local_exp returns for 0
// it is divided by itself. Exactly 1.0, and notably NOT dependent on local_exp
// being accurate - which the next test shows it is not.

    EXPECT_EQ_F32(local_run(KMLPN_SMAX,  0.0F), 1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_SMAX,  7.5F), 1.0F);
    EXPECT_EQ_F32(local_run(KMLPN_SMAX, -7.5F), 1.0F);
}

// A second fixture: two outputs, so the softmax proportions are observable.

#define KNB_OUT2            2U

static  float32_t       vInput2[KNB_IN];
static  float32_t       vActivation2[KNB_OUT2];
static  float32_t       vOutput2[KNB_OUT2 + 1U];
static  float32_t       vWeight2[KNB_OUT2][KNB_IN];
static  mlpnLayer_t     vLayer2;
static  mlpnNetwork_t   vNetwork2;

/*
 * \brief Fixture: 1 input, 2 outputs. Output j is x * w[j][0] + w[j][1].
 *
 */
static  void    local_setup2(float32_t w00, float32_t w01, float32_t w10, float32_t w11) {

    ukos_t_begin("UTC0");

    (void)memset(&vInput2[0],      0, sizeof(vInput2));
    (void)memset(&vActivation2[0], 0, sizeof(vActivation2));
    (void)memset(&vOutput2[0],     0, sizeof(vOutput2));

    vWeight2[0][0] = w00;  vWeight2[0][1] = w01;
    vWeight2[1][0] = w10;  vWeight2[1][1] = w11;

    vLayer2.oNonLinear  = KMLPN_SMAX;
    vLayer2.oNBInput    = KNB_IN;
    vLayer2.oNBOutput   = KNB_OUT2;
    vLayer2.oInput      = &vInput2[0];
    vLayer2.oActivation = &vActivation2[0];
    vLayer2.oOutput     = &vOutput2[0];
    vLayer2.oWeight     = &vWeight2[0][0];

    vNetwork2.oNBLayer  = 1U;
    vNetwork2.oLayer_L1 = &vLayer2;
    vNetwork2.oLayer_L2 = nullptr;
    vNetwork2.oLayer_L3 = nullptr;
    vNetwork2.oLayer_L4 = nullptr;
    vNetwork2.oLayer_L5 = nullptr;

    EXPECT_EQ_I(mlpn_configure(&vNetwork2), KERR_MLPN_NOERR);
}

TEST(mlpn_softmax_outputs_sum_to_one_and_order_the_inputs) {
    local_setup2(0.0F, 0.0F, 0.0F, 1.0F);               // logits: {0, 1}

    EXPECT_EQ_I(mlpn_compute(&vNetwork2), KERR_MLPN_NOERR);

// Normalisation is by construction, so the sum is 1 up to rounding whatever
// local_exp does.

    EXPECT_NEAR_F32(vOutput2[0] + vOutput2[1], 1.0F, 1.0e-6F);

// The larger logit gets the larger probability - the property that actually
// matters to a classifier, and the one that survives local_exp's inaccuracy.

    EXPECT_TRUE(vOutput2[1] > vOutput2[0]);

// Equal logits give exactly equal halves.

    local_setup2(0.0F, 2.0F, 0.0F, 2.0F);
    EXPECT_EQ_I(mlpn_compute(&vNetwork2), KERR_MLPN_NOERR);
    EXPECT_EQ_F32(vOutput2[0], 0.5F);
    EXPECT_EQ_F32(vOutput2[1], 0.5F);
}

TEST(mlpn_softmax_is_translation_invariant) {
    float32_t   a0, a1;

    local_setup2(0.0F, 0.0F, 0.0F, 1.0F);               // logits {0, 1}
    EXPECT_EQ_I(mlpn_compute(&vNetwork2), KERR_MLPN_NOERR);
    a0 = vOutput2[0];
    a1 = vOutput2[1];

// Adding a constant to every logit must not change the answer - that is what
// the max-subtraction pass is for, and it is what stops a large activation
// overflowing local_exp.

    local_setup2(0.0F, 50.0F, 0.0F, 51.0F);             // logits {50, 51}
    EXPECT_EQ_I(mlpn_compute(&vNetwork2), KERR_MLPN_NOERR);

    EXPECT_EQ_F32(vOutput2[0], a0);
    EXPECT_EQ_F32(vOutput2[1], a1);
}

TEST(mlpn_softmax_max_subtraction_protects_local_exp) {
    local_setup2(0.0F, -88.0F, 0.0F, -89.0F);           // logits {-88, -89}

    EXPECT_EQ_I(mlpn_compute(&vNetwork2), KERR_MLPN_NOERR);

// Subtracting the max brings these to {0, -1}, which local_exp handles. Without
// it the arguments stay at -88 and -89, and local_exp's bit hack returns NaN
// there - so the whole distribution becomes NaN.
//
// The exact pair matters and was measured, not guessed. A first attempt used
// {-100, -110} and the mutation SURVIVED: the bit hack's errors largely cancel
// in the ratio, so the unprotected version still produced 0.999955 against a
// correct 0.999952. Only right at the NaN band does the protection become
// observable from outside. Past about -177 the float-to-int conversion is
// undefined behaviour and the answer collapses to 0.5/0.5 - also observable,
// but not worth writing a test that relies on UB.
//
// Values below are what the correct algorithm gives: local_exp(0) = 0.971 and
// local_exp(-1) = 0.3748, normalised.

    EXPECT_TRUE(vOutput2[0] == vOutput2[0]);            // not NaN
    EXPECT_TRUE(vOutput2[1] == vOutput2[1]);

    EXPECT_NEAR_F32(vOutput2[0], 0.721489F, 1.0e-5F);
    EXPECT_NEAR_F32(vOutput2[1], 0.278511F, 1.0e-5F);
    EXPECT_NEAR_F32(vOutput2[0] + vOutput2[1], 1.0F, 1.0e-6F);
}

// Layer chaining
// ==============

#define KNB_IN_B            (KNB_OUT + 1U)              // layer A's output + bias

static  float32_t       vActivationB[1];
static  float32_t       vOutputB[2];
static  float32_t       vWeightB[1][KNB_IN_B];
static  mlpnLayer_t     vLayerB;

TEST(mlpn_a_second_layer_reads_the_first_layers_output) {
    local_setup();

// The chain is pointer aliasing, not copying: layer B's oInput IS layer A's
// oOutput. That is also why layer A's output vector is one wider than its
// output count - the extra slot becomes layer B's bias.

    vWeight[0][0] = 2.0F;                               // layer A: y = 2x
    vWeight[0][1] = 0.0F;
    vLayer.oNonLinear = KMLPN_LINE;

    vWeightB[0][0] = 3.0F;                              // layer B: y = 3 * (layer A) + 0
    vWeightB[0][1] = 0.0F;

    vLayerB.oNonLinear  = KMLPN_LINE;
    vLayerB.oNBInput    = KNB_IN_B;
    vLayerB.oNBOutput   = 1U;
    vLayerB.oInput      = &vOutput[0];                  // aliases layer A's output
    vLayerB.oActivation = &vActivationB[0];
    vLayerB.oOutput     = &vOutputB[0];
    vLayerB.oWeight     = &vWeightB[0][0];

    vNetwork.oNBLayer  = 2U;
    vNetwork.oLayer_L2 = &vLayerB;

    EXPECT_EQ_I(mlpn_configure(&vNetwork), KERR_MLPN_NOERR);

    vInput[0] = 5.0F;
    EXPECT_EQ_I(mlpn_compute(&vNetwork), KERR_MLPN_NOERR);

    EXPECT_EQ_F32(vOutput[0],  10.0F);                  // 2 * 5
    EXPECT_EQ_F32(vOutputB[0], 30.0F);                  // 3 * 10

// Configuring the pair wrote layer B's bias slot, which is layer A's output
// vector one past its outputs.

    EXPECT_EQ_F32(vOutput[KNB_OUT], 1.0F);
}

// Validation
// ==========

TEST(mlpn_a_layer_count_outside_one_to_five_is_refused) {
    local_setup();

    vNetwork.oNBLayer = 0U;
    EXPECT_EQ_I(mlpn_configure(&vNetwork), KERR_MLPN_GEERR);
    EXPECT_EQ_I(mlpn_compute(&vNetwork),   KERR_MLPN_GEERR);

    vNetwork.oNBLayer = 6U;
    EXPECT_EQ_I(mlpn_configure(&vNetwork), KERR_MLPN_GEERR);
    EXPECT_EQ_I(mlpn_compute(&vNetwork),   KERR_MLPN_GEERR);

// Five is the documented maximum and must still be accepted - the descriptor
// has five fixed pointer slots, not an array, and backprop.py mirrors the limit.

    vNetwork.oNBLayer  = 5U;
    vNetwork.oLayer_L2 = &vLayer;
    vNetwork.oLayer_L3 = &vLayer;
    vNetwork.oLayer_L4 = &vLayer;
    vNetwork.oLayer_L5 = &vLayer;
    EXPECT_EQ_I(mlpn_configure(&vNetwork), KERR_MLPN_NOERR);
}

TEST(mlpn_a_null_layer_is_refused_at_every_depth) {
    uint32_t    depth;

    local_setup();

    vNetwork.oLayer_L2 = &vLayer;
    vNetwork.oLayer_L3 = &vLayer;
    vNetwork.oLayer_L4 = &vLayer;
    vNetwork.oLayer_L5 = &vLayer;

// Each arm of the switch checks its own layers, so a null in the LAST slot of
// each depth is the case that distinguishes a correct arm from one that checked
// too few. Both entry points duplicate the switch, so both are driven.

    for (depth = 1U; depth <= 5U; depth++) {
        mlpnLayer_t     *slots[5];
        uint32_t        i;

        slots[0] = vNetwork.oLayer_L1;
        slots[1] = vNetwork.oLayer_L2;
        slots[2] = vNetwork.oLayer_L3;
        slots[3] = vNetwork.oLayer_L4;
        slots[4] = vNetwork.oLayer_L5;

        vNetwork.oNBLayer = depth;

        for (i = 0U; i < depth; i++) {
            mlpnLayer_t *saved = slots[i];

            switch (i) {
                case 0U:  { vNetwork.oLayer_L1 = nullptr; break; }
                case 1U:  { vNetwork.oLayer_L2 = nullptr; break; }
                case 2U:  { vNetwork.oLayer_L3 = nullptr; break; }
                case 3U:  { vNetwork.oLayer_L4 = nullptr; break; }
                default:  { vNetwork.oLayer_L5 = nullptr; break; }
            }

            EXPECT_EQ_I(mlpn_configure(&vNetwork), KERR_MLPN_GEERR);
            EXPECT_EQ_I(mlpn_compute(&vNetwork),   KERR_MLPN_GEERR);

            switch (i) {
                case 0U:  { vNetwork.oLayer_L1 = saved; break; }
                case 1U:  { vNetwork.oLayer_L2 = saved; break; }
                case 2U:  { vNetwork.oLayer_L3 = saved; break; }
                case 3U:  { vNetwork.oLayer_L4 = saved; break; }
                default:  { vNetwork.oLayer_L5 = saved; break; }
            }
        }
    }
}

// The module descriptor
// =====================

TEST(mlpn_module_metadata) {
    local_setup();

// A library descriptor: all three function pointers null and BSHOW without
// BEXE_CONSOLE, so there is no oExecution to drive and the tests call the
// functions directly. That is the structural difference from every CLI suite.

    EXPECT_EQ_U(aMlpn_Specifications.oIdModule,
                (((uint32_t)KID_FAM_NEURALS << 24U) | ((uint32_t)KNUM_MLPN << 8U) | (uint32_t)(uint8_t)'_'));

    EXPECT_EQ_PTR((const void *)aMlpn_Specifications.oInit,      nullptr);
    EXPECT_EQ_PTR((const void *)aMlpn_Specifications.oExecution, nullptr);
    EXPECT_EQ_PTR((const void *)aMlpn_Specifications.oClean,     nullptr);

    EXPECT_EQ_STR(aMlpn_Specifications.oStrRevision, " 1.0");
    EXPECT_EQ_U(aMlpn_Specifications.oFlag & (1U << BSHOW),        (1U << BSHOW));
    EXPECT_EQ_U(aMlpn_Specifications.oFlag & (1U << BEXE_CONSOLE), 0U);

// The help string is a placeholder in the production source. Asserted so that
// filling it in is a deliberate act rather than a silent one, but its prose is
// not pinned.

    EXPECT_TRUE(aMlpn_Specifications.oStrHelp != nullptr);
}

// The shipped network
// ===================
//
// Everything above is a hand-built network with hand-restated expected values.
// This section is different in kind and says so: it runs the REAL weights that
// ship in the class_Py demo - 2 inputs -> 52 -> 73 -> 3, TAN2 hidden, SMAX out -
// and its expected outputs are FROZEN FROM A RUN, not derived. That proves
// "unchanged", not "correct", and the two sorts of assertion must not be
// confused.
//
// What it is worth, measured rather than claimed: on the mutations tried so far
// it caught nothing the hand-built networks did not also catch. Its value is as
// a broad net over a realistic topology - 74-element dot products, a softmax
// saturating to ~1e-13, three chained layers - not as the sole guard on any
// particular behaviour. Kept for that reason, and because it is the only case
// here running the weights that actually ship.
//
// If someone retrains the demo, this section goes red. That is correct: the
// golden is a statement about a specific set of weights, and new weights need
// new values. It has already happened once - these numbers are from the network
// retrained after class_Py's DB_Creator.py double-normalisation was fixed.

#include    "network.c_inc"

// The five validation samples from class_Py/_Training/config.py:36-42.
// Columns are x, y, then the one-hot target for classes 1..3.

static  const   float32_t   vSample[5][5] = {
                    {  0.490344F,  0.051584F, 0.98F, 0.0F,  0.0F },
                    {  0.458057F, -0.458232F, 0.98F, 0.0F,  0.0F },
                    {  0.266116F,  0.944208F, 0.0F,  0.98F, 0.0F },
                    { -0.002234F, -0.117944F, 0.0F,  0.98F, 0.0F },
                    {  0.834344F,  0.854564F, 0.0F,  0.0F,  0.98F },
                };

/*
 * \brief Run one validation sample through the shipped network
 *
 */
static  void    local_classify(uint32_t sample) {

    vInput_L1[0] = vSample[sample][0];
    vInput_L1[1] = vSample[sample][1];

    EXPECT_EQ_I(mlpn_compute(&aNetwork), KERR_MLPN_NOERR);
}

TEST(mlpn_the_shipped_network_produces_a_probability_distribution) {
    uint32_t    sample, k;
    float32_t   sum;

    ukos_t_begin("UTC0");
    EXPECT_EQ_I(mlpn_configure(&aNetwork), KERR_MLPN_NOERR);

// Derived, not observed: whatever the weights are, a softmax output layer must
// produce non-negative values summing to one. This is the assertion that would
// catch local_exp returning a negative - which it does for a logit spread wider
// than about 88, and this network's spread is already ~30.

    for (sample = 0U; sample < 5U; sample++) {
        local_classify(sample);

        sum = 0.0F;
        for (k = 0U; k < 3U; k++) {
            EXPECT_TRUE(vOutput_L3[k] >= 0.0F);
            EXPECT_TRUE(vOutput_L3[k] <= 1.0F);
            sum += vOutput_L3[k];
        }
        EXPECT_NEAR_F32(sum, 1.0F, 1.0e-6F);
    }
}

TEST(mlpn_the_shipped_network_is_deterministic) {
    float32_t   first[3];
    uint32_t    k;

    ukos_t_begin("UTC0");
    EXPECT_EQ_I(mlpn_configure(&aNetwork), KERR_MLPN_NOERR);

// No clock, no random source, no heap: the same input must give bit-identical
// output every time, including across a reconfigure. Worth stating because it
// is the property that makes the golden below meaningful at all.

    local_classify(1U);
    for (k = 0U; k < 3U; k++) { first[k] = vOutput_L3[k]; }

    local_classify(0U);                                 // perturb the state
    EXPECT_EQ_I(mlpn_configure(&aNetwork), KERR_MLPN_NOERR);
    local_classify(1U);

    for (k = 0U; k < 3U; k++) { EXPECT_EQ_F32(vOutput_L3[k], first[k]); }
}

TEST(mlpn_the_shipped_network_golden) {
    uint32_t        sample, k;
    static  const   float32_t   vGolden[5][3] = {
                        { 0.999561012F,    0.00043900928F,   2.06008588e-09F },
                        { 0.999689341F,    0.000309214374F,  1.38527321e-06F },
                        { 1.76430112e-05F, 0.999970257F,     1.213613e-05F   },
                        { 1.11503333e-07F, 0.999999881F,     3.62172586e-13F },
                        { 3.06912291e-08F, 3.89208299e-06F,  0.999996066F    },
                    };

    ukos_t_begin("UTC0");
    EXPECT_EQ_I(mlpn_configure(&aNetwork), KERR_MLPN_NOERR);

// GOLDEN BY OBSERVATION. These numbers were produced by this code, not derived
// from the algorithm, so they pin behaviour rather than correctness.
//
// RELATIVE, not bit-exact, and the reason is worth recording. Unlike the toy
// networks above - whose single-kernel arithmetic was measured to be
// bit-identical with and without FP contraction - a 74-element dot product
// rounds differently at -O0 and -O2, because contraction changes the order the
// sum accumulates. The values below moved by up to 3.5e-6 relative between the
// two, so an equality here would fail on a build-flag change and prove nothing.
//
// 1e-4 is still four orders tighter than any real defect: a wrong weight index,
// a broken bias or a mis-stepped dot product moves these by orders of
// magnitude, not by parts per million.

    for (sample = 0U; sample < 5U; sample++) {
        local_classify(sample);
        for (k = 0U; k < 3U; k++) {
            EXPECT_NEAR_F32(vOutput_L3[k], vGolden[sample][k],
                            (fabsf(vGolden[sample][k]) * 1.0e-4F) + 1.0e-30F);
        }
    }
}

TEST(mlpn_the_shipped_network_classifies_its_validation_set) {
    uint32_t    sample, k, argmax, want;

    ukos_t_begin("UTC0");
    EXPECT_EQ_I(mlpn_configure(&aNetwork), KERR_MLPN_NOERR);

// A real assertion now, not an observation. This suite previously recorded that
// the shipped weights got only three of these five right; the cause was found in
// class_Py's DB_Creator.py, which divided by KABS_MAX_FUNCTION twice and so
// trained the network on data 40x smaller than the range it is asked about.
// With that fixed and the demo retrained, the network scores 98.6% on its own
// validation database and gets all five of these right.
//
// Worth keeping as an assertion rather than a golden: it is derived from the
// labels in config.py, so it stays meaningful across a retrain in a way the
// frozen probabilities above do not.

    for (sample = 0U; sample < 5U; sample++) {
        local_classify(sample);

        argmax = 0U;
        want   = 0U;
        for (k = 1U; k < 3U; k++) {
            if (vOutput_L3[k]              > vOutput_L3[argmax])       { argmax = k; }
            if (vSample[sample][2U + k] > vSample[sample][2U + want])  { want   = k; }
        }
        EXPECT_EQ_U(argmax, want);

// And it is confident about each one, rather than scraping in - the winning
// class takes more than 99% of the probability mass in every case.

        EXPECT_TRUE(vOutput_L3[argmax] > 0.99F);
    }
}
