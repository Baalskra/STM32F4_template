#include "Common.hpp"

void main(void)
{
	Clock::Initialize();
	
	if(Clock::IsPLLPoweredFromInternalCrystal())
		while(1);

	/*using Led2 = GPIO::OutputPin<GPIOA, 6>;
	using Led3 = GPIO::OutputPin<GPIOA, 7>;
	using Leds = GPIO::PinList<Led2, Led3>;

	using Key0 		= GPIO::InputPin<GPIOE, 4, GPIO::Pull::Up>;
	using Key1 		= GPIO::InputPin<GPIOE, 3>;
	using Buttons   = GPIO::PinList<Key0, Key1>;

	Leds::Initialize();
	Buttons::Initialize()*/

	while(1);
}