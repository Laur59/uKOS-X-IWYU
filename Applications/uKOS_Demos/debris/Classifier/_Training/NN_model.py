#!/usr/bin/env python
# -*- coding: utf-8 -*-

# NN_model.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
#
# Project:	uKOS-X
# Goal:		Generate the TensorFlow Lite C model
#			for uKOS system.
#
#			Necessary packages:
#			python -m pip install numpy tensorflow pillow
#
#			python3 NN_model.py --model_file NN_model.tflite --mode val
#			python3 NN_model.py --model_file NN_model.tflite --mode full
#			xxd -i NN_model.tflite > NN_model.c_inc
#
#   (c) 2025-2026, Edo. Franzi
#   --------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

import	argparse
import	numpy as np
import	tensorflow as tf
import	os
import	logging
from	tensorflow import keras
from	tensorflow.keras import layers

# 0 = all logs, 1 = info, 2 = warning, 3 = error only
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
logging.getLogger('absl').setLevel(logging.ERROR)

# Reproducibility
SEED = 42
np.random.seed(SEED)
tf.random.set_seed(SEED)

# Load the learning dataset
# -------------------------

def load_data(file_path):
	try:

		# Use genfromtxt (more flexible than loadtxt)
		print(f"Read the file : {file_path}")
		data = np.genfromtxt(file_path, delimiter = '\t', dtype = np.float32)
		data = np.atleast_2d(data)

		# Remove invalid rows containing NaN or Inf
		data = data[~np.isnan(data).any(axis = 1)]
		data = data[~np.isinf(data).any(axis = 1)]

		print("Data read from the file :")
		print(data)

		if data.shape[1] != 11:
			raise ValueError("The file needs exactly 11 columns (x1, x2, x3, x4, x5, x6, x7, x8, y1, y2, y3) per line.")

		# Get the inputs (X) and the output (Y)
		# (x1, x2, x3, x4, x5, x6, x7, x8) are the inputs
		# (y1, y2, y3) are the output
		X = data[:, :8]
		Y = data[:, 8:]

		# Check that outputs are one-hot encoded
		if Y.shape[1] != 3:
			raise ValueError("The output must contain exactly 3 columns.")
		if not np.all(np.sum(Y, axis = 1) == 1):
			raise ValueError("Each output row must be one-hot encoded (sum = 1).")

		return X, Y

	except Exception as e:
		print(f"Error during the file reading : {e}")
		return None, None

# Build the model
# ---------------

def build_model():
	model = tf.keras.Sequential([
		tf.keras.layers.InputLayer(shape = (8,), dtype = tf.float32),
		tf.keras.layers.Dense(24, activation = 'tanh', kernel_regularizer = tf.keras.regularizers.l2(1e-4)),
		tf.keras.layers.Dense(12, activation = 'tanh', kernel_regularizer = tf.keras.regularizers.l2(1e-4)),
		tf.keras.layers.Dense(3,  activation = 'softmax'),
	])

	# Compile the model
	model.compile(
		optimizer = tf.keras.optimizers.Adam(learning_rate = 1e-3),
		loss = 'categorical_crossentropy',
		metrics = ['accuracy']
	)
	return model

# Display the confusion matrix
# ----------------------------

def print_confusion_matrix(y_true, y_pred, title = "Confusion matrix"):
	cm = tf.math.confusion_matrix(y_true, y_pred, num_classes = 3).numpy()

	print(f"\n{title} :")
	print("           Pred 0   Pred 1   Pred 2")
	for i in range(cm.shape[0]):
		print(f"True {i}    {cm[i, 0]:6d}   {cm[i, 1]:6d}   {cm[i, 2]:6d}")

# Test samples
# ------------

def get_test_samples():
	return np.array([
		[-0.667143288, -0.792564809, -0.507299776, -0.853254438, -0.280102586,  1.0,         -0.612416107, -0.984712332],
		[-0.865927732, -0.951664954, -0.983669003, -0.550295858, -0.994026501, -0.94423152,  -0.203020134, -0.996673267],
		[ 0.189591578, -0.954907283, -0.992381638,  0.797724169, -0.994469972,  0.199817193, -0.874161074, -0.99937882 ],
		[-0.523614221, -0.866881953, -0.50477879,  -0.981247155, -0.276196837, -0.984622643, -0.763422819, -0.995785614],
		[-0.583224976, -0.854860126, -0.507119705, -0.789167046, -0.282229109,  0.199817193, -0.484899329, -0.975107079],
		[-0.102865637, -0.951312904, -0.491356622, -0.622758307, -0.264372729, -0.000278533, -0.818791946, -0.992837852]
	], dtype = np.float32)

# Main
# ----

def main():

	# Set up command-line arguments using argparse
	parser = argparse.ArgumentParser(description = 'Train and test a TensorFlow model.')
	parser.add_argument('--model_file', type = str, help = 'Path to the TFLite model file', required = True)
	parser.add_argument(
		'--mode',
		type = str,
		choices = ['val', 'full'],
		default = 'val',
		help = 'val = validation mode, full = train on all data'
	)
	args = parser.parse_args()

	# Load the learning dataset
	X, Y = load_data('DB_L_file.txt')

	if X is None or Y is None:
		print("Data cannot be loaded!")
		return

	# Shuffle the dataset
	indices = np.arange(X.shape[0])
	np.random.shuffle(indices)
	X = X[indices]
	Y = Y[indices]

	# Build the model
	model = build_model()

	# Train the model
	early_stop = tf.keras.callbacks.EarlyStopping(
		monitor = 'val_loss' if args.mode == 'val' else 'loss',
		patience = 50,
		restore_best_weights = True,
		verbose = 1
	)

	if args.mode == 'val':

		# Split the dataset: 80% train / 20% validation
		split_index = int(0.8 * X.shape[0])
		X_train = X[:split_index]
		Y_train = Y[:split_index]
		X_val   = X[split_index:]
		Y_val   = Y[split_index:]

		model.fit(
			X_train,
			Y_train,
			epochs = 2000,
			batch_size = 16,
			validation_data = (X_val, Y_val),
			callbacks = [early_stop],
			verbose = 1
		)

		# Evaluate the model
		loss, accuracy = model.evaluate(X_val, Y_val, verbose = 0)
		print(f'\nValidation loss     : {loss:.6f}')
		print(f'Validation accuracy : {accuracy:.6f}')

		# Confusion matrix on validation set
		y_true = np.argmax(Y_val, axis = 1)
		y_pred = np.argmax(model.predict(X_val, verbose = 0), axis = 1)
		print_confusion_matrix(y_true, y_pred, "Validation confusion matrix")

	else:

		# Train on the full dataset
		model.fit(
			X,
			Y,
			epochs = 2000,
			batch_size = 16,
			callbacks = [early_stop],
			verbose = 1
		)

		# Evaluate the model on the full dataset
		loss, accuracy = model.evaluate(X, Y, verbose = 0)
		print(f'\nTrain loss     : {loss:.6f}')
		print(f'Train accuracy : {accuracy:.6f}')

		# Confusion matrix on full dataset
		y_true = np.argmax(Y, axis = 1)
		y_pred = np.argmax(model.predict(X, verbose = 0), axis = 1)
		print_confusion_matrix(y_true, y_pred, "Train confusion matrix")

	# Test the model with TensorFlow
	test_samples = get_test_samples()
	output = model(test_samples, training = False).numpy()

	print("\nOutput TF")
	print(output)
	print("Predicted classes TF :", np.argmax(output, axis = 1))

	# Convert the model to TFLite format
	converter = tf.lite.TFLiteConverter.from_keras_model(model)
	tflite_model = converter.convert()
	with open('NN_model.tflite', 'wb') as f:
		f.write(tflite_model)

	# Use TensorFlow Lite Interpreter to test the TFLite model
	# Use the argument passed to the command line
	interpreter = tf.lite.Interpreter(model_path = args.model_file)
	interpreter.allocate_tensors()
	input_details  = interpreter.get_input_details()
	output_details = interpreter.get_output_details()

	tflite_outputs = []

	for input_data in test_samples:
		interpreter.set_tensor(input_details[0]['index'], np.array([input_data], dtype = np.float32))
		interpreter.invoke()
		output = interpreter.get_tensor(output_details[0]['index'])
		tflite_outputs.append(output[0])
		print("Output TFLite", output)

	tflite_outputs = np.array(tflite_outputs, dtype = np.float32)
	print("Predicted classes TFLite :", np.argmax(tflite_outputs, axis = 1))

# Main entry point
if __name__ == "__main__":
	main()
