#pragma once

#include "MCUs.hpp"
#include "USART2Base.hpp"

class USART2: protected USART2Base<Target>
{
	USART2() = delete;
};