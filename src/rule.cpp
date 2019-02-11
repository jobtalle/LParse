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

std::ostream &operator<<(std::ostream &stream, const Rule &rule) {
	stream << rule.getLhs() << Rule::CONNECTIVE << rule.getRhs();

	return stream;
}