#pragma once

#include "MCUs.hpp"
#include "DBGMCUBase.hpp"

class DBGMCU: protected DBGMCUBase<>
{
	DBGMCU() = delete;
};