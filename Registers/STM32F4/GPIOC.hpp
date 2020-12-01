#pragma once

#include "MCUs.hpp"
#include "GPIOCBase.hpp"

class GPIOC: protected GPIOCBase<Target>
{
	GPIOC() = delete;
};