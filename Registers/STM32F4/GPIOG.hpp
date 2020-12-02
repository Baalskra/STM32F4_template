#pragma once

#include "MCUs.hpp"
#include "GPIOGBase.hpp"
#include "RCCBase.hpp"

class GPIOG: protected GPIOGBase<Target>, protected RCCBase<Target>
{
	GPIOG() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIOGEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOGEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOGRST::RESET::Set();
		AHB1RSTR::GPIOGRST::RELEASE::Set();
	}
};