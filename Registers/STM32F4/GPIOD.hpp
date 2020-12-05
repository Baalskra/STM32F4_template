#pragma once

#include "MCUs.hpp"
#include "GPIODBase.hpp"
#include "RCCBase.hpp"

class GPIOD: protected GPIODBase<Target>, protected RCCBase<Target>
{
	GPIOD() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIODEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIODEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIODRST::RESET::Set();
		AHB1RSTR::GPIODRST::RELEASE::Set();
	}
};