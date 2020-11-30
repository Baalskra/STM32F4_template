#pragma once

template<typename ... Pins>
struct PinList
{
	static void Initialize()
  	{
    	(Pins::Initialize(), ...);
  	}
};