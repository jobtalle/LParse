#include "sentence.h"
#include "rule.h"

#include <iostream>
#include <random>

using namespace LParse;

Sentence::Sentence(const std::vector<Token> tokens) :
	tokens(tokens) {

}

void Sentence::apply(const std::vector<Rule> &rules, std::mt19937 &randomizer) {
	std::vector<Token> newTokens;

	for(auto at = tokens.begin(); at < tokens.end();) {
		std::vector<Rule*> possibleRules;

		for(auto rule = rules.begin(); rule < rules.end(); ++rule)
			if(applicable(at, *rule))
				possibleRules.push_back(const_cast<Rule*>(&*rule));

		if(possibleRules.size()) {
			std::uniform_int_distribution<int> distribution(0, possibleRules.size() - 1);
			auto rule = possibleRules[distribution(randomizer)];
			auto result = rule->getRhs().getTokens();

			newTokens.insert(newTokens.end(), result.begin(), result.end());

			std::advance(at, rule->getLhs().getTokens().size());
		}
		else
			newTokens.push_back(*at++);
	}

	tokens = newTokens;
}

const std::vector<Token> &Sentence::getTokens() const {
	return tokens;
}

bool Sentence::applicable(std::vector<Token>::iterator at, const Rule &rule) const {
	auto tokens = rule.getLhs().getTokens();

	for(auto tokensAt = tokens.begin(); tokensAt < tokens.end(); ++at, ++tokensAt)
		if(*tokensAt != *at)
			return false;

	return true;
}

std::ostream &operator<<(std::ostream &stream, const Sentence &sentence) {
	for(auto token : sentence.getTokens())
		stream << token;

	return stream;
}