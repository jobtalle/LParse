#pragma once

#include "sentence.h"

#include <ostream>
#include <string>

namespace LParse {
	class Rule final {
	public:
		static const std::string CONNECTIVE;

		Rule(const Sentence lhs, const Sentence rhs);
		const Sentence &getLhs() const;
		const Sentence &getRhs() const;
		bool operator==(const Rule &other) const;
		std::string getString() const;

	private:
		Sentence lhs;
		Sentence rhs;
	};
}

std::ostream &operator<<(std::ostream &stream, const LParse::Rule &rule);