#pragma once

#include "rule.h"
#include "sentence.h"

#include <vector>
#include <random>
#include <memory>
#include <ostream>

namespace LParse {
	class System final {
	public:
		System();
		System(const Sentence &axiom, const std::vector<Rule> &rules);
		void setAxiom(const Sentence &axiom);
		void setRules(const std::vector<Rule> &rules);
		Sentence getAxiom() const;
		std::vector<Rule> getRules() const;
		bool isComplete() const;
		std::shared_ptr<Sentence> generate(const size_t iterations, std::mt19937 &randomizer) const;

	private:
		Sentence axiom;
		std::vector<Rule> rules;
	};
}