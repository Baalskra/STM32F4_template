#pragma once

#include "MCUs.hpp"
#include "GPIOEBase.hpp"

class GPIOE: protected GPIOEBase<Target>
{
	GPIOE() = delete;
};