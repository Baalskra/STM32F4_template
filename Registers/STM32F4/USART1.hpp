#pragma once

#include "MCUs.hpp"
#include "USART1Base.hpp"
#include "RCCBase.hpp"

class USART1: protected USART1Base<Target>, protected RCCBase<Target>
{
	USART1() = delete;

	friend class USART;
	
public:
	static void Enable()
	{
		APB2ENR::USART1EN::ENABLED::Set();
	}
	
	static void Disable()
	{
		APB2ENR::USART1EN::DISABLED::Set();
	}
	
	static void Reset()
	{
		APB2RSTR::USART1RST::RESET::Set();
		APB2RSTR::USART1RST::RELEASE::Set();
	}
};