#pragma once

#include "MCUs.hpp"
#include "UART5Base.hpp"

class UART5: protected UART5Base<Target>
{
	UART5() = delete;
};