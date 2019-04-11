#include "growthProfile.h"

using namespace LParse;

GrowthProfile::GrowthProfile(size_t iterations) :
	iterations(iterations) {
	
}

size_t GrowthProfile::getIterations() const {
	return iterations;
}
