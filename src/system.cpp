#include "system.h"
#include <utility>

using namespace LParse;

System::System(Sentence axiom, std::vector<Rule> rules) :
	axiom(std::move(axiom)),
	rules(std::move(rules)) {

}

void System::setAxiom(const Sentence &axiom) {
	this->axiom = axiom;
}

void System::setRules(const std::vector<Rule> &rules) {
	this->rules = rules;
}

const Sentence &System::getAxiom() const {
	return axiom;
}

const std::vector<Rule> &System::getRules() const {
	return rules;
}

std::shared_ptr<Sentence> System::generate(const size_t iterations, Randomizer &randomizer) const {
	std::shared_ptr<Sentence> sentence(std::make_shared<Sentence>(axiom));

	for(size_t application = 0; application < iterations; ++application)
		sentence->apply(rules, randomizer);

	return sentence;
}
