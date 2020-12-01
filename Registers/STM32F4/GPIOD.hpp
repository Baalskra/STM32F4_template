#pragma once

#include "MCUs.hpp"
#include "GPIODBase.hpp"

class GPIOD: protected GPIODBase<Target>
{
	GPIOD() = delete;
};