#pragma once

#include "GPIO.hpp"

struct VDD {};
struct VSS {};

template<typename GPIO_, uint16_t pin, typename Common = VSS>
class Led: protected GPIO
{
	Led() = delete;
	
public:
	static void Initialize()
	{
		OutputPin<GPIO_, pin, Type::PushPull, 2>::Initialize();
	}
	
	static void Toggle()
	{
		_Toggle<GPIO_, pin>();
	}
	
	static void On()
	{
		if(std::is_same<VSS, Common>::value)    WritePin<GPIO_, pin>(1);
		else                                    WritePin<GPIO_, pin>(0);
	}
	
	static void Off()
	{
		if(std::is_same<VSS, Common>::value)    WritePin<GPIO_, pin>(0);
		else                                    WritePin<GPIO_, pin>(1);
	}
};

template<typename ... Leds>
struct LedList
{
    static void Initialize()
    {
        (Leds::Initialize(), ...);
    }

    static void On()
    {
        (Leds::On(), ...);
    }

    static void Off()
    {
        (Leds::Off(), ...);
    }

    static void Toggle()
    {
        (Leds::Toggle(), ...);
    }
};