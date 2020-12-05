#pragma once

#include "MCUs.hpp"
#include "PWRBase.hpp"

class PWR: public PWRBase<Target>
{
	PWR() = delete;
};