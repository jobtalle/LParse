#pragma once

#include <random>
#include <memory>

namespace LParse {
	class Randomizer final {
	public:
		Randomizer();
		Randomizer makeRandomizer();
		int makeInt(const int min, const int max);

	private:
		std::mt19937 randomizer;

		explicit Randomizer(std::seed_seq &seedSeq);

		static std::unique_ptr<std::seed_seq> makeRandomSeedSeq();
	};
}