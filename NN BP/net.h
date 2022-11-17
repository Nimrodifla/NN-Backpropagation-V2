#pragma once
#include "layer.h"
#include <vector>

class Net {
public:
	int size;
	Layer** layers;

	Net(std::vector<int> layersSizes);

	std::vector<float> forward(std::vector<float> input);

	void printNet(bool showWeights);

	float calcNetCost(std::vector<float> trueOutput);

};