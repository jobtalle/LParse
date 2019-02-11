#pragma once

#include <ostream>

namespace LParse {
	class Token final {
	public:
		Token(const char symbol);
		Token(const Token &other);
		char getSymbol() const;
		bool operator==(const Token &other) const;
		bool operator!=(const Token &other) const;
		Token operator=(const Token &other) const;

	private:
		const char symbol;
	};
};

std::ostream &operator<<(std::ostream &stream, const LParse::Token &token);