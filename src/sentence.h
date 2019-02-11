#pragma once

#include "token.h"

#include <vector>
#include <ostream>

namespace LParse {
	class Sentence final {
	public:
		Sentence(const std::vector<Token> tokens);
		void print(std::ostream &stream) const;

	private:
		std::vector<Token> tokens;
	};
};