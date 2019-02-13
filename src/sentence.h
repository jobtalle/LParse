#pragma once

#include "token.h"

#include <vector>
#include <ostream>
#include <random>
#include <string>

namespace LParse {
	class Rule;
	class Sentence final {
	public:
		Sentence();
		Sentence(const std::vector<Token> tokens);
		Sentence(const std::string string);
		void apply(const std::vector<Rule> &rules, std::mt19937 &randomizer);
		const std::vector<Token> &getTokens() const;

	private:
		std::vector<Token> tokens;

		bool applicable(std::vector<Token>::iterator at, const Rule &rule) const;
	};
};

std::ostream &operator<<(std::ostream &stream, const LParse::Sentence &sentence);