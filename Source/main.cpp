#include "Common.hpp"

void main(void)
{
	ButtonState last_key_state = Released;

	Clock::Initialize();
	
	if(Clock::IsPLLPoweredFromInternalCrystal())
		while(1);
	
	using Led2 = 	Led<GPIOA, 6, VDD>;
	using Led3 = 	Led<GPIOA, 7, VDD>;
	using Leds = 	LedList<Led2, Led3>;

	using Key0 		= Button<GPIOE, 4, GPIO::Pull::Up>;
	using Key1 		= Button<GPIOE, 3, GPIO::Pull::None>;
	using Buttons   = ButtonList<Key0, Key1>;

	Leds::Initialize();
	Buttons::Initialize();

	Leds::Off();
		
	while(1)
	{
		if(Key0::IsPressed() && last_key_state == Released)
		{
			Led2::Toggle();
			last_key_state = Pressed;
		}
		else if(Key0::IsReleased() && last_key_state == Pressed)
		{
			last_key_state = Released;
		}
	}
}