#include "system.h"

using namespace LParse;

System::System() :
	axiom() {

}

System::System(const Sentence &axiom, const std::vector<Rule> &rules) :
	axiom(axiom),
	rules(rules) {

}

void System::setAxiom(const Sentence &axiom) {
	this->axiom = axiom;
}

void System::setRules(const std::vector<Rule> &rules) {
	this->rules = rules;
}

bool System::isComplete() const {
	return rules.size() && axiom.getTokens().size();
}

Sentence System::getAxiom() const {
	return axiom;
}

std::vector<Rule> System::getRules() const {
	return rules;
}

std::shared_ptr<Sentence> System::generate(const size_t iterations, std::mt19937 &randomizer) const {
	if(!isComplete())
		return std::shared_ptr<Sentence>(new Sentence());

	std::shared_ptr<Sentence> sentence(new Sentence(axiom));

	for(size_t application = 0; application < iterations; ++application)
		sentence->apply(rules, randomizer);

	return sentence;
}