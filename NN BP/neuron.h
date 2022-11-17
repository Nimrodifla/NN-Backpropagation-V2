#pragma once
#include "helper.h"
#include "layer.h"

class Layer;

class Neuron {
public:
	float value;
	float* weights; // weights between this layer and the next
	int weightsSize;

	Neuron();

	void initWeights(int nextLayerSize);

	void randomizeWeights();

	// set neuron value according to the values & weights of the prev layer
	void forward(Layer* prevLayer, int indexInCurrentLayer);
};