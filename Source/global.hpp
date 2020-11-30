#pragma once

#include "Button.hpp"
#include "Led.hpp"
#include "PinList.hpp"

using Led2 		= Led<GPIOA, 6, VDD>;
using Led3 		= Led<GPIOA, 7, VDD>;
using Leds      = PinList<Led2, Led3>;
		
using Key0 		= Button<GPIOE, 4, GPIO::Pull_up>;
using Key1 		= Button<GPIOE, 3, GPIO::Pull_none>;
using Buttons   = PinList<Key0, Key1>;