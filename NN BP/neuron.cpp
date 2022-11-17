#include "neuron.h"

Neuron::Neuron() {
	value = 0;
	weights = nullptr;
	weightsSize = 0;
}

void Neuron::initWeights(int nextLayerSize) {
	weightsSize = nextLayerSize;
	weights = new float[nextLayerSize];
}

void Neuron::randomizeWeights() {
	// randomize weights
	for (int i = 0; i < weightsSize; i++) {
		weights[i] = randomFloatInRange(0.0, 1.0);
	}
}

// set neuron value according to the values & weights of the prev layer
void Neuron::forward(Layer* prevLayer, int indexInCurrentLayer) {
	float sum = 0;
	for (int i = 0; i < prevLayer->size; i++) {
		//        prev layer neuron               prev layer neuron weight
		sum += (prevLayer->neurons[i].value) * (prevLayer->neurons[i].weights[indexInCurrentLayer]);
	}

	this->value = ReLU(sum); // set this neuron's value
}