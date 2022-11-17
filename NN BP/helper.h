#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <vector>

static int rSeed = time(0);

static int myRand() {
	std::srand(rSeed);
	int r = std::rand();
	rSeed = r; // update seed;

	return r;
}

static float randomFloatInRange(float min, float max) {
	float r = min + static_cast <float> (myRand()) / (static_cast <float> (RAND_MAX / (max - min)));
	return r;
}

static float ReLU(float input) {

	// https://www.desmos.com/calculator/j6oghqohqg
	
	float power = (input * input);
	return power / (0.3 + power);
}

struct neuronWeightsNudges
{
	std::vector<float> weightNudges;
} typedef neuronWeightsNudges;

struct NudgeProccesingResult {
	std::vector<float> nudgesForPrevLayer;
	std::vector<neuronWeightsNudges> nudgesForWeights;
} typedef NPR;