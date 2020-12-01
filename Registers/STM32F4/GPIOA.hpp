#pragma once

#include "MCUs.hpp"
#include "GPIOABase.hpp"

class GPIOA: protected GPIOABase<Target>
{
	GPIOA() = delete;
};