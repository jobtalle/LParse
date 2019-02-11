#pragma once

#include "token.h"

#include <vector>
#include <ostream>
#include <random>

namespace LParse {
	class Rule;
	class Sentence final {
	public:
		Sentence(const std::vector<Token> tokens);
		void print(std::ostream &stream) const;
		void apply(const std::vector<Rule> &rules, std::mt19937 &randomizer);
		const std::vector<Token> &getTokens() const;

	private:
		std::vector<Token> tokens;

		bool applicable(std::vector<Token>::iterator at, const Rule &rule) const;
	};
};