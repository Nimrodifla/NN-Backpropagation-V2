#include "layer.h"

Layer::Layer(int size) {
	this->size = size;
	neurons = new Neuron[size];
}

void Layer::randomizeLayer() {
	for (int i = 0; i < size; i++) {
		neurons[i].randomizeWeights();
	}
}

void Layer::forward(Layer* prevLayer) {
	for (int i = 0; i < size; i++) {
		this->neurons[i].forward(prevLayer, i);
	}
}