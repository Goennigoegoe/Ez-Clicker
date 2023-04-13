#pragma once
#include <random>

namespace cRandom {
	int randInt(int min, int max) {
		std::random_device rd;     // Only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(min, max); // Guaranteed unbiased

		return uni(rng);
	}
};