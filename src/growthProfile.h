#pragma once

#include <cstddef>

namespace LParse {
	class GrowthProfile {
	public:
		GrowthProfile(size_t iterations);
		virtual ~GrowthProfile() = default;
		virtual size_t getGrowth(size_t iteration) const = 0;
		size_t getIterations() const;

	private:
		const size_t iterations;
	};
}