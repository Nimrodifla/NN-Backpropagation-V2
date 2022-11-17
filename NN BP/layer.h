#pragma once
#include "neuron.h"

class Neuron;

class Layer {
public:
	int size;
	Neuron* neurons;

	Layer(int size);

	void randomizeLayer();

	void forward(Layer* prevLayer);

	NPR layerNPR(std::vector<float> layerNudges);

};