#pragma once

#include <random>
#include <memory>
#include <string>
#include <vector>

namespace LParse {
	class Randomizer final {
	public:
		Randomizer();
		Randomizer(const std::string &state);
		Randomizer makeRandomizer();
		int makeInt(int min, int max);
		float makeFloat(float min = 0, float max = 1);
		std::mt19937 &getRandomizer();
		std::string toString() const;

	private:
		std::mt19937 randomizer;

		explicit Randomizer(std::seed_seq &seedSeq);

		static std::unique_ptr<std::seed_seq> makeRandomSeedSeq();
	};
}