#pragma once

#include "MCUs.hpp"
#include "GPIOCBase.hpp"
#include "RCCBase.hpp"

class GPIOC: protected GPIOCBase<Target>, protected RCCBase<Target>
{
	GPIOC() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIOCEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOCEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOCRST::RESET::Set();
		AHB1RSTR::GPIOCRST::RELEASE::Set();
	}
};