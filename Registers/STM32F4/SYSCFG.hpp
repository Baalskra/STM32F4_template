#pragma once

#include "MCUs.hpp"
#include "SYSCFGBase.hpp"

class SYSCFG: protected SYSCFGBase<Target>
{
	SYSCFG() = delete;
};