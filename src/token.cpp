#include "token.h"

using namespace LParse;

Token::Token(const char symbol) :
	symbol(symbol) {

}

void Token::print(std::ostream stream) const {
	stream << symbol;
}