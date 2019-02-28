#include "token.h"

using namespace LParse;

Token::Token(const char symbol) :
	symbol(symbol) {

}

char Token::getSymbol() const {
	return symbol;
}

bool Token::operator==(const Token &other) const {
	return symbol == other.symbol;
}

bool Token::operator!=(const Token &other) const {
	return symbol != other.symbol;
}

Token &Token::operator=(const Token &other) {
	symbol = other.symbol;

	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Token &token) {
	stream << token.getSymbol();

	return stream;
}
