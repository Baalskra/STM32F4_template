#pragma once

#include "MCUs.hpp"
#include "RCCBase.hpp"

class RCC: protected RCCBase<Target>
{
	RCC() = delete;
};