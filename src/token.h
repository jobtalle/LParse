#pragma once

#include <ostream>

namespace LParse {
	class Token final {
	public:
		Token(const char symbol);
		Token(const Token &other);
		void print(std::ostream &stream) const;
		bool operator==(const Token &other) const;
		bool operator!=(const Token &other) const;
		Token operator=(const Token &other);

	private:
		const char symbol;
	};
};