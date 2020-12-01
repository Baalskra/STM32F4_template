#pragma once

#include "MCUs.hpp"
#include "GPIOHBase.hpp"

class GPIOH: protected GPIOHBase<Target>
{
	GPIOH() = delete;
};