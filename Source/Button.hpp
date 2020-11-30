#pragma once

#include "GPIO.hpp"

enum ButtonState
{
	Pressed,
	Released
};

template<typename GPIO_, std::uint16_t pin, GPIO::Pull pull>
class Button: protected GPIO
{	
	Button() = delete;
	
public:
	static void Initialize()
	{
		InputPin<GPIO_, pin, Input, pull>::Initialize();
	}
	
	static ButtonState Get()
	{
		ButtonState state;
		
		if(ReadInputPin<GPIO_, pin>())
			state = (pull == Pull_up) ? Released : Pressed;
		else
			state = (pull == Pull_up) ? Pressed : Released;
			
		return state;	
	}
	
	// Метод запроса состояния кнопки (нажата ли).
	static bool IsPressed()
	{
		return (pull == Pull_up) ? (!ReadInputPin<GPIO_, pin>()) : ReadInputPin<GPIO_, pin>();
	}
	
	// Метод запроса состояния кнопки (отпущена ли).
	static bool IsReleased()
	{
		return (pull == Pull_up) ? ReadInputPin<GPIO_, pin>() : (!ReadInputPin<GPIO_, pin>());
	}
};