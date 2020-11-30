#include "Clock.hpp"
#include "global.hpp"

void main(void)
{
	ButtonState last_key_state = Released;
	
	Clock::Initialize();
	
	if(Clock::IsInternalCrystalPLLSource())
		while(1);
		
	Leds::Initialize();
	Buttons::Initialize();
	
	Led2::Off();
	Led3::Off();
	
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