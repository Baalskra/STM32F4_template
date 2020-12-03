#pragma once

#include "MCUs.hpp"
#include "USART6Base.hpp"

class USART6: protected USART6Base<Target>
{
	USART6() = delete;
};