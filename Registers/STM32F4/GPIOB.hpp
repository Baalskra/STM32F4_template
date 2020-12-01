#pragma once

#include "MCUs.hpp"
#include "GPIOBBase.hpp"

class GPIOB: protected GPIOBBase<Target>
{
	GPIOB() = delete;
};