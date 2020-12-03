#pragma once

#include "MCUs.hpp"
#include "SPI1Base.hpp"

class SPI1: public SPI1Base<Target>
{
	SPI1() = delete;
};