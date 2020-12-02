#pragma once

#include "MCUs.hpp"
#include "GPIOABase.hpp"
#include "RCCBase.hpp"

class GPIOA: protected GPIOABase<Target>, protected RCCBase<Target>
{
	GPIOA() = delete;

	friend class GPIO;
	friend class RCC;

protected:
	static void Enable()
	{
		AHB1ENR::GPIOAEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOAEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOARST::RESET::Set();
		AHB1RSTR::GPIOARST::RELEASE::Set();
	}
};