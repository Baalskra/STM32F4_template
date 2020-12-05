#pragma once

#include "MCUs.hpp"
#include "DMABase.hpp"

//class DMA1: protected DMABase<Target, 0x40026000>
class DMA1: public DMABase<Target, 0x40026000>
{
	DMA1() = delete;
};

//class DMA2: protected DMABase<Target, 0x40026400>
class DMA2: public DMABase<Target, 0x40026400>
{
	DMA2() = delete;
};