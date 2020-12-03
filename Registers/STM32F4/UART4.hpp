#pragma once

#include "MCUs.hpp"
#include "UART4Base.hpp"

class UART4: protected UART4Base<Target>
{
	UART4() = delete;
};