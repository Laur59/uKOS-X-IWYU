# Inference performance of a TFL vs µKOS-X MLPN

(c) 2025-2026, Edo. Franzi, 2026-04-23

## Introduction

This example aims to compare the inference speed of a TensorFlow Lite model with that of the µKOS-X MLPN implementation.

The starting point is to use an existing TensorFlow Lite model and extract all the relevant information required to run it with the µKOS-X MLPN library. This includes the network architecture, weights, and associated parameters.

The two models come from other examples, which have to be trained first:

- From `class_TFL` : **NN_model.xxd**, the TensorFlow Lite model
- From `class_Py` : **network.c_inc**, the MLPN description of a network with the same architecture

The models are not kept in git. Configuring the application without them (`cmake --preset …`) stops with a message naming the missing file; run the two trainings and the script below, then configure again.

## Generate the model for MLPN library

```bash
# Copy the two models, extract the TFLite network into structure.c
# and give network.c_inc the weights of the TFLite model
cd _Models
./build.sh
```

The script `build.sh`:

1. copies `NN_model.xxd` from `class_TFL/_Training` and `network.c_inc` from `class_Py/_Training`, at every run, so a new training is always picked up;
2. converts `NN_model.xxd` back to `NN_model.tflite` and extracts its layers (sizes, activations and weights) into `structure.c` with `tflite_structure.py`;
3. runs `inject_weights.py`, which replaces the weights of every layer of `network.c_inc` (`vWeight_L<n>_f`) with those of `structure.c` (`vWeight_L<n>`). It first checks that both files describe the same network — the same layers, the same sizes and compatible activations — and stops without changing anything otherwise.

The MLPN and TensorFlow Lite then infer the same trained network. There is nothing to edit by hand: after a new training, run `build.sh` again.

## Compile & execute the test

The CMake build of the application regenerates `NN_model.c_inc` from `NN_model.xxd`.

```bash
# i.e. for the target Alastor_H743
cd Alastor_H743
cmake --preset llvm
cmake --build build
```

```bash
# Typical results
Exec time for TensorFlowLite, min = 333 [us], max = 351 [us]
Exec time for MLPN uKOS-X,    min = 186 [us], max = 191 [us]
```
