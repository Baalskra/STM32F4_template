#pragma once

#include "MCUs.hpp"
#include "GPIOFBase.hpp"

class GPIOF: protected GPIOFBase<Target>
{
	GPIOF() = delete;
};