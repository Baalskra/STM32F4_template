#pragma once

#include "MCUs.hpp"
#include "GPIOIBase.hpp"
#include "RCCBase.hpp"

class GPIOI: protected GPIOIBase<Target>, protected RCCBase<Target>
{
	GPIOI() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIOIEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOIEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOIRST::RESET::Set();
		AHB1RSTR::GPIOIRST::RELEASE::Set();
	}
};