#pragma once

#include <ostream>

namespace LParse {
	class Token final {
	public:
		Token(const char symbol);
		void print(std::ostream stream) const;

	private:
		const char symbol;
	};
};