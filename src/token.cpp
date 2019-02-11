#include "token.h"

#include <iostream.>

using namespace LParse;

Token::Token(const char symbol) :
	symbol(symbol) {

}

Token::Token(const Token &other) :
	symbol(other.symbol) {
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

Token Token::operator=(const Token &other) const {
	return Token(other);
}

std::ostream &operator<<(std::ostream &stream, const Token &token) {
	stream << token.getSymbol();

	return stream;
}