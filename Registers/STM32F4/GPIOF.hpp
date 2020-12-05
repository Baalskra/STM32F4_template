#pragma once

#include "MCUs.hpp"
#include "GPIOFBase.hpp"
#include "RCCBase.hpp"

class GPIOF: protected GPIOFBase<Target>, protected RCCBase<Target>
{
	GPIOF() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIOFEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOFEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOFRST::RESET::Set();
		AHB1RSTR::GPIOFRST::RELEASE::Set();
	}
};