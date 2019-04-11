#include "system.h"
#include "legend.h"

#include <utility>

using namespace LParse;

const char System::branchTokens[] = {
	Legend::LEAF,
	Legend::BRANCH_OPEN,
	Legend::BRANCH_CLOSE
};

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

std::shared_ptr<Sentence> System::generate(const GrowthProfile &growthProfile, Randomizer &randomizer) const {
	std::shared_ptr<Sentence> sentence(std::make_shared<Sentence>(axiom));

	for(size_t application = 0; application < growthProfile.getIterations(); ++application)
		sentence->apply(rules, randomizer);

	return sentence;
}

std::vector<Token> System::getGeneratedTokens() const {
	std::vector<Token> tokens;

	getGeneratedTokens(tokens, axiom);

	for(const auto &rule : rules) {
		getGeneratedTokens(tokens, rule.getLhs());
		getGeneratedTokens(tokens, rule.getRhs());
	}

	return tokens;
}

void System::getGeneratedTokens(std::vector<Token>& tokens, const Sentence& sentence) const {
	for(const auto &token : sentence.getTokens())
		if(std::find(
			std::begin(branchTokens),
			std::end(branchTokens),
			token.getSymbol()) == std::end(branchTokens))
			tokens.emplace_back(token.getSymbol());
}
