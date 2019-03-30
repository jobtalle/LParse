#pragma once

#include <random>
#include <memory>
#include <string>

namespace LParse {
	class Randomizer final {
	public:
		Randomizer();
		Randomizer(const std::string &state);
		Randomizer makeRandomizer();
		int makeInt(int min, int max);
		float makeFloat(float min, float max);
		std::string toString() const;

	private:
		std::mt19937 randomizer;

		explicit Randomizer(std::seed_seq &seedSeq);

		static std::unique_ptr<std::seed_seq> makeRandomSeedSeq();
	};
}