#pragma once

#include "sentence.h"

#include <ostream>
#include <string>

namespace LParse {
	class Rule final {
	public:
		Rule(const Sentence lhs, const Sentence rhs);
		void print(std::ostream &stream) const;

	private:
		static const std::string CONNECTIVE;

		Sentence lhs;
		Sentence rhs;
	};
};