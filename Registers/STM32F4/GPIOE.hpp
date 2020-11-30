#pragma once

#include "MCUs.hpp"
#include "GPIOEBase.hpp"
#include "RCCBase.hpp"

class GPIOE: protected GPIOEBase<Target>, protected RCCBase<Target>
{
	GPIOE() = delete;
	
	friend class GPIO;
	
public:
	static void Enable()
	{
		AHB1ENR::GPIOEEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		AHB1ENR::GPIOEEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		AHB1RSTR::GPIOERST::RESET::Set();
		AHB1RSTR::GPIOERST::RELEASE::Set();
	}
};