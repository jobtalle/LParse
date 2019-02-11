#include "rule.h"

using namespace LParse;

const std::string Rule::CONNECTIVE = " = ";

Rule::Rule(const Sentence lhs, const Sentence rhs) :
	lhs(lhs),
	rhs(rhs) {

}

void Rule::print(std::ostream &stream) const {
	lhs.print(stream);

	stream << CONNECTIVE;

	rhs.print(stream);
}