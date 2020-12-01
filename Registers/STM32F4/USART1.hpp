#pragma once

#include "MCUs.hpp"
#include "USART1Base.hpp"

class USART1: protected USART1Base<Target>
{
	USART1() = delete;
};