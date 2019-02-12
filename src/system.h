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
		System(const Sentence &axiom, const std::vector<Rule> &rules, const size_t applications);
		void setAxiom(const Sentence &axiom);
		void setRules(const std::vector<Rule> &rules);
		void setApplications(const size_t applications);
		Sentence getAxiom() const;
		std::vector<Rule> getRules() const;
		size_t getApplications() const;
		bool isComplete() const;
		std::shared_ptr<Sentence> generate(std::mt19937 &randomizer) const;

	private:
		Sentence axiom;
		std::vector<Rule> rules;
		size_t applications = 0;
	};
}

std::ostream &operator<<(std::ostream &stream, const LParse::System &system);