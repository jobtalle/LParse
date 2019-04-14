#include "sentence.h"
#include "rule.h"

#include <random>
#include <utility>

using namespace LParse;

Sentence::Sentence(const Token token) :
	tokens({ token }) {

}

Sentence::Sentence(std::vector<Token> tokens) :
	tokens(std::move(tokens)) {

}

Sentence::Sentence(const std::string string) {
	for(const char &c : string)
		tokens.emplace_back(c);
}

bool Sentence::apply(const std::vector<Rule> &rules, Randomizer &randomizer, const size_t limit) {
	std::vector<Token> newTokens;

	for(auto at = tokens.begin(); at < tokens.end();) {
		std::vector<Rule*> possibleRules;

		for(auto rule = rules.begin(); rule < rules.end(); ++rule)
			if(applicable(at, *rule))
				possibleRules.push_back(const_cast<Rule*>(&*rule));

		if(!possibleRules.empty()) {
			const auto rule = possibleRules[randomizer.makeInt(0, possibleRules.size() - 1)];
			const auto result = rule->getRhs().getTokens();

			newTokens.insert(newTokens.end(), result.begin(), result.end());

			std::advance(at, rule->getLhs().getTokens().size());
		}
		else
			newTokens.push_back(*at++);

		if(newTokens.size() > limit)
			return false;
	}

	tokens = newTokens;

	return true;
}

const std::vector<Token> &Sentence::getTokens() const {
	return tokens;
}

bool Sentence::applicable(std::vector<Token>::iterator at, const Rule &rule) const {
	const auto tokens = rule.getLhs().getTokens();

	for(auto tokensAt = tokens.begin(); tokensAt < tokens.end(); ++at, ++tokensAt)
		if(at == this->tokens.end() || *tokensAt != *at)
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