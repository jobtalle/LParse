#pragma once

#include "rule.h"
#include "sentence.h"
#include "randomizer.h"

#include <vector>
#include <memory>

namespace LParse {
	class System final {
	public:
		System() = default;
		System(const System &other) = default;
		System(Sentence axiom, std::vector<Rule> rules);
		void setAxiom(const Sentence &axiom);
		void setRules(const std::vector<Rule> &rules);
		const Sentence &getAxiom() const;
		const std::vector<Rule> &getRules() const;
		std::shared_ptr<Sentence> generate(size_t iterations, Randomizer &randomizer) const;
		std::vector<Token> getGeneratedTokens() const;

	private:
		Sentence axiom;
		std::vector<Rule> rules;
		static const char branchTokens[];

		void getGeneratedTokens(
			std::vector<Token> &tokens,
			const Sentence &sentence) const;
	};
}