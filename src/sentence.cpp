#include "sentence.h"
#include "rule.h"

#include <iostream>
#include <random>

using namespace LParse;

Sentence::Sentence() {

}

Sentence::Sentence(const std::vector<Token> tokens) :
	tokens(tokens) {

}

Sentence::Sentence(const std::string string) {
	for(const char &c : string)
		tokens.push_back(c);
}

void Sentence::apply(const std::vector<Rule> &rules, std::mt19937 &randomizer) {
	std::vector<Token> newTokens;

	for(auto at = tokens.begin(); at < tokens.end();) {
		std::vector<Rule*> possibleRules;

		for(auto rule = rules.begin(); rule < rules.end(); ++rule)
			if(applicable(at, tokens.end(), *rule))
				possibleRules.push_back(const_cast<Rule*>(&*rule));

		if(possibleRules.size()) {
			auto rule = possibleRules[std::uniform_int_distribution<int>(0, possibleRules.size() - 1)(randomizer)];
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

bool Sentence::applicable(
	std::vector<Token>::iterator at,
	const std::vector<Token>::iterator last,
	const Rule &rule) const {
	auto tokens = rule.getLhs().getTokens();

	for(auto tokensAt = tokens.begin(); tokensAt < tokens.end() && at < last; ++at, ++tokensAt)
		if(*tokensAt != *at)
			return false;

	return true;
}

bool Sentence::operator==(const Sentence &other) const {
	if(tokens.size() != other.tokens.size())
		return false;

	for(size_t i = 0; i < tokens.size(); ++i)
		if(tokens[i] != other.tokens[i])
			return false;

	return true;
}

std::string Sentence::getString() const {
	std::string string;

	for(auto token : tokens)
		string += token.getSymbol();

	return string;
}

std::ostream &operator<<(std::ostream &stream, const Sentence &sentence) {
	for(auto token : sentence.getTokens())
		stream << token;

	return stream;
}