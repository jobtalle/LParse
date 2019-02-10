#pragma once

#include "sentence.h"

namespace LParse {
	class Rule final {
	public:
		Rule(const Sentence lhs, const Sentence rhs);

	private:
		Sentence lhs;
		Sentence rhs;
	};
};