#include "net.h"

int main() {
	// define & create nn
	std::vector<int> structure = { 4, 3, 2, 1 }; // sizes of layers by order
	Net* net = new Net(structure); // create net

	// input -> output
	std::vector<float> input = { 0.4, 0.9, 0.1, 0.7 };
	std::vector<float> output = net->forward(input);

	// show net
	net->printNet(true);

	return 0;
}