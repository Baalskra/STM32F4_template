#pragma once

#include "MCUs.hpp"
#include "RTCBase.hpp"

class RTC: public RTCBase<Target>
{
	RTC() = delete;
};