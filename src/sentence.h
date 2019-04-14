#pragma once

#include "token.h"
#include "randomizer.h"

#include <vector>
#include <ostream>
#include <random>
#include <string>
#include <cstddef>
#include <limits>

namespace LParse {
	class Rule;
	class Sentence final {
	public:
		Sentence() = default;
		Sentence(Token token);
		Sentence(std::vector<Token> tokens);
		Sentence(std::string string);
		bool apply(const std::vector<Rule> &rules, Randomizer &randomizer, size_t limit = std::numeric_limits<size_t>::max());
		const std::vector<Token> &getTokens() const;
		bool operator==(const Sentence &other) const;
		std::string getString() const;

	private:
		std::vector<Token> tokens;

		bool applicable(std::vector<Token>::iterator at, const Rule &rule) const;
	};
}

std::ostream &operator<<(std::ostream &stream, const LParse::Sentence &sentence);