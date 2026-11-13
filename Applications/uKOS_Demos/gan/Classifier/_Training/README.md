# Gan demo for uKOS-X (v.1.0)

(c) 2025-2026, Edo. Franzi, 2026-07-29

## Tools and libraries installation

### Generate the NN_model.c_inc for the demo

The Third_Parties Tflite-micro has to be installed

```bash
# Activate the the virtual environment
cd Third_Parties/Tflite-micro/Construction/Pyenv
source Tflite_Pyenv/bin/activate

# Train the network
cd Applications/uKOS_Demos/gan/Classifier/_Training
./build

# At this stage, NN_model.xxd should be in the folder (a reversible hex dump
# of the trained model; xxd -r NN_model.xxd NN_model.tflite recreates the
# flatbuffer). The build generates mlp_model.c_inc from it automatically
# Now, build the system with the embedded the demo
cd Ports/Targets/Discovery_xyz/Variant_Test/System
make -j USER_MODE=1 WITHAPP=gan
```

### How to use a better model?

Inside the `generated_faces` folder, there is a list of result images for each epoch. If visual inspection shows that the generator from another epoch performs better, we can use it for the application. Every 50 epochs, and at the last one, the training saves the generator as `generator_epoch_xxxx.keras` and `generator_epoch_xxxx.tflite`.

```bash
# Example, the epoch 0300 is the better visual result
# We want to use it
cd Applications/uKOS_Demos/gan/Classifier/_Training
xxd generator_epoch_0300.tflite > NN_model.xxd
```

The int8 quantisation is calibrated on random latent vectors drawn from a seed (`--calibration-seed`, 0 by default), so the same checkpoint and seed always give the same model. `--export` turns a Keras checkpoint into the TFLite model again, in seconds and without training, for instance to try another calibration:

```bash
python NN_model.py --export generator_epoch_0300.keras --model_file NN_model.tflite --calibration-seed 7
xxd NN_model.tflite > NN_model.xxd
```

No label renaming is required: the build reconstructs the model as `NN_model.tflite` before generating `NN_model.c_inc`, so the symbol is always `NN_model_tflite`.
