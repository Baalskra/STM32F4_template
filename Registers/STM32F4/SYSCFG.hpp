#pragma once

#include "MCUs.hpp"
#include "SYSCFGBase.hpp"
#include "RCCBase.hpp"

class SYSCFG: protected SYSCFGBase<Target>, protected RCCBase<Target>
{
	SYSCFG() = delete;
	
	friend class RCC;
	
protected:
	static void Enable()
	{
		APB2ENR::SYSCFGEN::ENABLED::Set();
	}
	
	static void Disable()
	{
		APB2ENR::SYSCFGEN::DISABLED::Set();
	}
	
	static void Reset()
	{
		APB2RSTR::SYSCFGRST::RESET::Set();
		APB2RSTR::SYSCFGRST::RELEASE::Set();
	}
};