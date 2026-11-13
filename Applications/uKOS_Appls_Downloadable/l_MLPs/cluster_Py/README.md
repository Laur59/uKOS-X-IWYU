# Classification with the MLPN Library

(c) 2025-2026, Edo. Franzi, 2026-04-23

## Introduction

This example presents a complete neural network classifier demonstrating the full capabilities of µKOS-X. The objective is to show, step by step, how to design and implement such a classifier.

As an illustrative case, we build a model capable of classifying 2D coordinates (x, y), where both values range from -1 to 1, into five distinct classes:

- **Class A (red):** top-left cluster
- **Class B (green):** top-right cluster
- **Class C (blue):** bottom-left cluster
- **Class D (yellow):** bottom-right cluster
- **Inter-class (violet):** the regions between all clusters

This example demonstrates how a neural network using µKOS-X can learn and distinguish different geometric regions in a two-dimensional space.

![](_Training/cluster.png)

## Dataset Creation and Classifier Generation

The trained network is not kept in git: after a clone, `_Training/network.c_inc` does not exist until the command below has been run. Configuring the application without it (`cmake --preset …`) stops with a message naming the missing file and this README; train the network, then configure again.

### Define the network

The file `_Training/config.py` describes the neural network and its training. It is the single place to edit before training, and `build.sh` passes it to the MLPN trainer. It defines:

- `KLAYERS`: the number of neurons of each layer (`KNB_INPUTS` and `KNB_OUTPUTS` are derived from it);
- `KNON_LINEAR` and `KNON_LINEAR_OUT`: the activation functions of the hidden layers and of the output layer (the available functions are listed in the file);
- `KGAIN`, `KMOMENTUM` and `KEPOCHS`: the learning rate, the momentum and the number of training epochs;
- `KVALIDATION`: a few input/output samples used for a rapid validation of the trained network.

For this example, we use a three-layer neural network with 2 input neurons and three successive layers of 12, 24, and 5 neurons, respectively.

The first two layers (L1 and L2) use a non-linear activation function based on an ultrafast approximation of the hyperbolic tangent (tanh). The final layer (L3) uses an ultrafast softmax function to produce normalized output probabilities for the five target classes.

### Dataset creation

The learning dataset `DB_L_file.txt` and the validation dataset `DB_V_file.txt` are created by `DB_Creator.py`. `build.sh` runs it when the two files do not exist yet and reuses them otherwise. To create them yourself, for instance with another seed:

```bash
# Create the learning DB_L_file.txt and the validation DB_V_file.txt files
cd _Training
python3 DB_Creator.py [-seed nnn]
```

The random generator is seeded with `nnn`, or with 42 when `-seed` is omitted, so the same seed always produces the same datasets. The script overwrites both files and plots the two datasets; close the plot window to finish. Run `build.sh` afterwards to train the network on the new datasets.

### Create the Neural Network

```bash
# Create the Neural Network
cd _Training
./build.sh
```

At this step, the file **`network.c_inc`** is created. It contains the structure of the neural network as well as the set of weights associated with it.

This file must then be included in the application so that the network architecture and its trained parameters can be embedded directly into the program. In this way, the application can use the classifier without requiring any external model file at runtime.
