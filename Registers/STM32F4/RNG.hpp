#pragma once

#include "MCUs.hpp"
#include "RNGBase.hpp"

class RNG: public RNGBase<Target>
{
	RNG() = delete;
};