#pragma once

#include "MCUs.hpp"
#include "GPIOBBase.hpp"
#include "RCCBase.hpp"

class GPIOB: protected GPIOBBase<Target>, protected RCCBase<Target>
{
	GPIOB() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIOBEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOBEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOBRST::RESET::Set();
		AHB1RSTR::GPIOBRST::RELEASE::Set();
	}
};