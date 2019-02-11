#include "token.h"

#include <iostream.>

using namespace LParse;

Token::Token(const char symbol) :
	symbol(symbol) {

}

Token::Token(const Token &other) :
	symbol(other.symbol) {
}

void Token::print(std::ostream &stream) const {
	stream << symbol;
}

bool Token::operator==(const Token &other) const {
	return symbol == other.symbol;
}

bool Token::operator!=(const Token &other) const {
	return symbol != other.symbol;
}

Token Token::operator=(const Token &other) {
	return Token(other);
}