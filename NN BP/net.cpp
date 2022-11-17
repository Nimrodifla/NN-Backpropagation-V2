#include "net.h"

Net::Net(std::vector<int> layersSizes) {
	this->size = layersSizes.size();
	this->layers = new Layer * [size];

	for (int i = 0; i < size - 1; i++) {
		// init layers
		layers[i] = new Layer(layersSizes[i]);
		layers[i + 1] = new Layer(layersSizes[i + 1]);
		// init weights in all the neurons in all the layers
		for (int j = 0; j < layers[i]->size; j++) {
			layers[i]->neurons[j].initWeights(layers[i + 1]->size);
		}
		layers[i]->randomizeLayer(); // randomize layer weights
	}
}

std::vector<float> Net::forward(std::vector<float> input) {
	// set input values in first layer
	for (int i = 0; i < input.size(); i++) {
		layers[0]->neurons[i].value = input[i];
	}

	// forward on all the layers
	for (int i = 1 /* first layer has the input values */; i < size; i++) {
		layers[i]->forward(layers[i - 1]);
	}

	// take the output layer and return it's values
	std::vector<float> result;
	Layer* lastLayer = layers[size - 1];
	for (int i = 0; i < lastLayer->size; i++) {
		result.push_back(lastLayer->neurons[i].value);
	}

	return result;
}

void Net::printNet(bool showWeights) {
	for (int i = 0; i < this->size; i++) {
		std::cout << "-- Layer " << i << "\n";
		for (int j = 0; j < this->layers[i]->size; j++) {
			std::cout << "(" << this->layers[i]->neurons[j].value << ") ";
		}
		std::cout << "\n";
		if (showWeights && i < this->size - 1)
		{
			std::cout << "\n---- Weights [layer " << i << "]\n";
			for (int j = 0; j < this->layers[i]->size; j++) {
				std::cout << "(( ";
				for (int h = 0; h < this->layers[i]->neurons[j].weightsSize; h++) {

					std::cout << "[" << this->layers[i]->neurons[j].weights[h] << "] ";
				}
				std::cout << "))\n";
			}
			std::cout << "\n";
		}
	}
}

float Net::calcNetCost(std::vector<float> trueOutput) {
	// net output -> vector
	std::vector<float> netOutput;
	Layer* lastLayer = this->layers[this->size - 1];
	for (int i = 0; i < lastLayer->size; i++) {
		netOutput.push_back(lastLayer->neurons[i].value);
	}

	// calc cost
	float cost = 0;
	for (int i = 0; i < netOutput.size(); i++) {
		cost += (netOutput[i] - trueOutput[i]) * (netOutput[i] - trueOutput[i]); // diff squred
	}

	return cost;
}