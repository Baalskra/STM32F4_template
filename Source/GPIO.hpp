#pragma once

#include "Common.hpp"

class GPIO: protected RCC
{
    GPIO() = delete;

public:
	template<typename ... Pins>
    struct PinList
    {
        static void Initialize()
        {
            (Pins::Initialize(), ...);
        }
    };

	enum class Type
	{
		PushPull = 0,
		OpenDrain,
	};

    enum class Pull
    {
        None = 0,
        Up,
        Down,
    };

protected:
//public: Test

    template<typename GPIO, uint16_t pin, Type type = Type::PushPull, uint8_t speed = 2>
	struct OutputPin
	{
		static void Initialize()
		{
			static_assert(pin < 16, "Pin number must be from 0 to 15");
            static_assert(speed == 2 || speed == 25 || speed == 50 || speed == 100, "Speed must be 2, 25, 50 or 100 MHz");
		
			_Enable<GPIO>();
			
			SetMode<GPIO, pin, Mode::Output>();
			SetType<GPIO, pin, type>();
			SetSpeed<GPIO, pin, speed>();
		}
	};

    template<typename GPIO, uint16_t pin, Pull pull = Pull::None>
	struct InputPin
	{
		static void Initialize()
		{
			static_assert(pin < 16, "Pin number must be from 0 to 15");
		
			_Enable<GPIO>();
			
			SetMode<GPIO, pin, Mode::Input>();
			SetPull<GPIO, pin, pull>();
		}
	};

	template<typename GPIO, uint16_t pin>
	static void WritePin(bool value)
	{
		static_assert(pin < 16, "Pin number must be from 0 to 15");
		
		GPIO::BSRR::Set(1 << pin + 16 * (!value));
	}
		
	template<typename GPIO, uint16_t pin>
	static void _Toggle(void)
	{
		static_assert(pin < 16, "Pin number must be from 0 to 15");
		
		GPIO::ODR::Set(GPIO::ODR::Get() ^ (1 << pin));
	}
		
	template<typename GPIO>
	static void WriteGPIO(uint16_t data)
	{
		GPIO::ODR::Set(data);
	}
	
	template<typename GPIO, uint16_t pin>
	static bool ReadInputPin(void)
	{
		static_assert(pin < 16, "Pin number must be from 0 to 15");
		
		return GPIO::IDR::Get() & (1 << pin);
	}
		
	template<typename GPIO, uint16_t pin>
	static bool ReadOutputPin(void)
	{
		static_assert(pin < 16, "Pin number must be from 0 to 15");
		
		return GPIO::ODR::Get() & (1 << pin);
	}
		
	template<typename GPIO>
	static uint16_t ReadInputGPIO(void)
	{
		return GPIO::IDR::Get();
	}
		
	template<typename GPIO>
	static uint16_t ReadOutputGPIO(void)
	{
		return GPIO::ODR::Get();
	}

private:
    enum class Mode
    {
        Input = 0,
        Output,
        AltMode,
        Analog,
    };

    template<typename GPIO, uint16_t pin, Mode mode>
	static void SetMode()
	{
		GPIO::MODER::Set((GPIO::MODER::Get() & ~(2 << pin * 2)) | (static_cast<uint32_t>(mode) << pin * 2));
	}
	
	template<typename GPIO, uint16_t pin, Type type>
	static void SetType()
	{
		GPIO::OTYPER::Set((GPIO::OTYPER::Get() & ~(1 << pin)) | (static_cast<uint32_t>(type) << pin));
	}
	
	template<typename GPIO, uint16_t pin, uint8_t speed>
	static void SetSpeed()
	{
        if constexpr (speed == 2)
		    GPIO::OSPEEDR::Set((GPIO::OSPEEDR::Get() & ~(3 << pin * 2)) | (0 << pin * 2));
        else if constexpr (speed == 25)
		    GPIO::OSPEEDR::Set((GPIO::OSPEEDR::Get() & ~(3 << pin * 2)) | (1 << pin * 2));
        else if constexpr (speed == 50)
		    GPIO::OSPEEDR::Set((GPIO::OSPEEDR::Get() & ~(3 << pin * 2)) | (2 << pin * 2));
        else if constexpr (speed == 100)
		    GPIO::OSPEEDR::Set((GPIO::OSPEEDR::Get() & ~(3 << pin * 2)) | (3 << pin * 2));
	}
	
	template<typename GPIO, uint16_t pin, Pull pull>
	static void SetPull()
	{
		GPIO::PUPDR::Set((GPIO::PUPDR::Get() & ~(2 << pin * 2)) | (static_cast<uint32_t>(pull) << pin * 2));
	}
};