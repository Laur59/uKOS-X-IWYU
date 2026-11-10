# Classification with the MLPN Library

(c) 2025-2026, Edo. Franzi, 2026-04-23

## Introduction

This is an example of a complete neural network classifier demonstrating the full capabilities of µKOS-X. The goal is to present, step by step, how to design and implement such a classifier.

As an illustrative case, we aim to build a model capable of classifying 2D coordinates (x, y), where both values range from -1 to 1, into three distinct classes:

- **C1 – Ring (red):** points forming a circular ring structure
- **C2 – Inner-Outer (green):** points inside the ring (inner disc) or outside it, except for the top-right square
- **C3 – Square (blue):** points in the top-right square

This example highlights how different geometric patterns can be learned and distinguished by a neural network using µKOS-X.

![](_Training/class.png)

## Dataset Creation and Classifier Generation

### Dataset creation

```bash
# Create the learning DB_L_file.txt and the validation DB_V_file.txt files
cd _Training
python3 DB_Creator.py
```

### Define the network

The file `_Training/config.py` describes the neural network and its training. It is the single place to edit before training, and `build.sh` passes it to the MLPN trainer. It defines:

- `KLAYERS`: the number of neurons of each layer (`KNB_INPUTS` and `KNB_OUTPUTS` are derived from it);
- `KNON_LINEAR` and `KNON_LINEAR_OUT`: the activation functions of the hidden layers and of the output layer (the available functions are listed in the file);
- `KGAIN`, `KMOMENTUM` and `KEPOCHS`: the learning rate, the momentum and the number of training epochs;
- `KVALIDATION`: a few input/output samples used for a rapid validation of the trained network.

For this example, we use a three-layer neural network with 2 input neurons and three successive layers of 52, 73, and 3 neurons, respectively.

The first two layers (L1 and L2) use a non-linear activation function based on an ultrafast approximation of the hyperbolic tangent (tanh). The final layer (L3) uses an ultrafast softmax function to produce normalized output probabilities for the three target classes.

### Create the Neural Network

```bash
# Create the Neural Network
cd _Training
./build.sh
```

At this step, the file **`network.c_inc`** is created. It contains the structure of the neural network as well as the set of weights associated with it.

This file must then be included in the application so that the network architecture and its trained parameters can be embedded directly into the program. In this way, the application can use the classifier without requiring any external model file at runtime.

