#pragma once

#include "token.h"

#include <vector>

namespace LParse {
	class Sentence final {
	public:
		Sentence(const std::vector<Token> tokens);

	private:
		std::vector<Token> tokens;
	};
};