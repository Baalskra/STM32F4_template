#pragma once

#include "MCUs.hpp"
#include "GPIOGBase.hpp"

class GPIOG: protected GPIOGBase<Target>
{
	GPIOG() = delete;
};