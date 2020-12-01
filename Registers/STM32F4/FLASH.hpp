#pragma once

#include "MCUs.hpp"
#include "FLASHBase.hpp"

class FLASH: protected FLASHBase<Target>
{
	FLASH() = delete;
};