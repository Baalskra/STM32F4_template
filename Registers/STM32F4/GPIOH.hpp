#pragma once

#include "MCUs.hpp"
#include "GPIOHBase.hpp"
#include "RCCBase.hpp"

class GPIOH: protected GPIOHBase<Target>, protected RCCBase<Target>
{
	GPIOH() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIOHEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOHEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOHRST::RESET::Set();
		AHB1RSTR::GPIOHRST::RELEASE::Set();
	}
};