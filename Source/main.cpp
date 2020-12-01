#include "Common.hpp"

void main(void)
{
	Clock::Initialize();
	
	if(Clock::IsPLLPoweredFromInternalCrystal())
		while(1);

	while(1);
}