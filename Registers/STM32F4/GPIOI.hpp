#pragma once

#include "MCUs.hpp"
#include "GPIOIBase.hpp"

class GPIOI: protected GPIOIBase<Target>
{
	GPIOI() = delete;
};