#include "sentence.h"

using namespace LParse;

Sentence::Sentence(const std::vector<Token> tokens) :
	tokens(tokens) {

}

void Sentence::print(std::ostream &stream) const {
	for(const Token token : tokens)
		token.print(stream);
}