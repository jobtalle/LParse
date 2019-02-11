#pragma once

#include "sentence.h"

#include <ostream>
#include <string>

namespace LParse {
	class Rule final {
	public:
		Rule(const Sentence lhs, const Sentence rhs);
		const Sentence &getLhs() const;
		const Sentence &getRhs() const;

	private:
		Sentence lhs;
		Sentence rhs;
	};
};

std::ostream &operator<<(std::ostream &stream, const LParse::Rule &rule);