#pragma once

#include "MCUs.hpp"
#include "USART3Base.hpp"

class USART3: protected USART3Base<Target>
{
	USART3() = delete;
};