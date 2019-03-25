#pragma once

#include <random>
#include <memory>

namespace LParse {
	class Randomizer final {
	public:
		Randomizer();
		Randomizer makeRandomizer();
		int makeInt(const int min, const int max);
		float makeFloat(const float min, const float max);

	private:
		std::mt19937 randomizer;

		explicit Randomizer(std::seed_seq &seedSeq);

		static std::unique_ptr<std::seed_seq> makeRandomSeedSeq();
	};
}