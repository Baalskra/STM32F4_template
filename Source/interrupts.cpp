#include "startup.hpp"
#include "Clock.hpp"

void IRQ::NMI_Handler(void)
{
	if(!Clock::IsClockSecurityOk())
	{
		Clock::Initialize();
		Clock::ClockSecurityFlagClear();
	}
}