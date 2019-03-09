#include "rule.h"

using namespace LParse;

const std::string Rule::CONNECTIVE = " => ";

Rule::Rule(const Sentence lhs, const Sentence rhs) :
	lhs(lhs),
	rhs(rhs) {

}

const Sentence &Rule::getLhs() const {
	return lhs;
}

const Sentence &Rule::getRhs() const {
	return rhs;
}

bool Rule::operator==(const Rule &other) const {
	return lhs == other.lhs && rhs == other.rhs;
}

std::string Rule::getString() const {
	return lhs.getString() + Rule::CONNECTIVE + rhs.getString();
}

std::ostream &operator<<(std::ostream &stream, const Rule &rule) {
	stream << rule.getLhs() << Rule::CONNECTIVE << rule.getRhs();

	return stream;
}