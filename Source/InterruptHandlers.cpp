#include "startup.hpp"
#include "Clock.hpp"

void IRQ::NMI_Handler(void)
{
	if(Clock::IsSecurityFailed())
	{
		Clock::Initialize();
		Clock::ClearSecurityFlag();
	}
}