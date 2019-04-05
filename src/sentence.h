#pragma once

#include "token.h"
#include "randomizer.h"

#include <vector>
#include <ostream>
#include <random>
#include <string>

namespace LParse {
	class Rule;
	class Sentence final {
	public:
		Sentence() = default;
		Sentence(std::vector<Token> tokens);
		Sentence(std::string string);
		void apply(const std::vector<Rule> &rules, Randomizer &randomizer);
		const std::vector<Token> &getTokens() const;
		bool operator==(const Sentence &other) const;
		std::string getString() const;

	private:
		std::vector<Token> tokens;

		bool applicable(
			std::vector<Token>::iterator at,
			const std::vector<Token>::const_iterator &last,
			const Rule &rule) const;
	};
}

std::ostream &operator<<(std::ostream &stream, const LParse::Sentence &sentence);