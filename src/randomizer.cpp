#include "randomizer.h"

#include <array>

using namespace LParse;

Randomizer::Randomizer() :
	randomizer(*makeRandomSeedSeq()) {
	
}

Randomizer::Randomizer(std::seed_seq& seedSeq) :
	randomizer(seedSeq) {
	
}

int Randomizer::makeInt(const int min, const int max) {
	return std::uniform_int_distribution<int>(min, max)(randomizer);
}

Randomizer Randomizer::makeRandomizer() {
	std::array<int, std::mt19937::state_size> seeds{};
	std::generate_n(seeds.data(), seeds.size(), std::ref(randomizer));
	std::seed_seq seq(std::begin(seeds), std::end(seeds));

	return Randomizer(seq);
}

std::unique_ptr<std::seed_seq> Randomizer::makeRandomSeedSeq() {
	std::random_device rd;
	std::array<int, std::mt19937::state_size> seeds{};
	std::generate_n(seeds.data(), seeds.size(), std::ref(rd));

	return std::make_unique<std::seed_seq>(std::begin(seeds), std::end(seeds));
}
