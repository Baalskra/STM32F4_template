#pragma once

#include "MCUs.hpp"
#include "EXTIBase.hpp"

class EXTI: protected EXTIBase<Target>
{
	EXTI() = delete;
};