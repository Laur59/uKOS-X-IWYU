# Debris demo for uKOS-X (v.1.0)

(c) 2025-2026, Edo. Franzi, 2026-04-23

## Tools and libraries installation

### Generate the NN_model.c_inc for the demo

The Third_Parties Tflite-micro has to be installed

```bash
# Activate the the virtual environment
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv
source Tflite_Pyenv/bin/activate

# Train the network
cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Demos/debris/Classifier/_Training
./build

# At this stage, mlp_model.xxd should be in the folder (a reversible hex dump
# of the trained model; xxd -r mlp_model.xxd mlp_model.tflite recreates the
# flatbuffer). The build generates mlp_model.c_inc from it automatically
# Now, build the system with the embedded the demo
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Discovery_xyz/Variant_Test/System
make -j USER_MODE=1 WITHAPP=debris
```



