#pragma once

#include "GPIOA.hpp"
#include "GPIOE.hpp"
#include "RCC.hpp"
#include "USART1.hpp"
#include "EXTI.hpp"

class GPIO: protected RCC
{
	GPIO() = delete;
	
public:
	enum Mode
	{
		Input = 0,
		Output,
		Alt_mode,
		Analog,
	};

	enum Type
	{
		Push_pull = 0,
		Open_drain,	
	};
		
	enum Pull
	{
		Pull_none = 0,
		Pull_up,
		Pull_down,
	};
		
	enum Speed
	{
		Mhz_2 = 0,
		Mhz_25,
		Mhz_50,
		Mhz_100,
	};
	
	/*enum AltFunction
	{
		AF_0 = 0,
		AF_1,
		AF_2,
		AF_3,
		AF_4,
		AF_5,
		AF_6,
		AF_7,
		AF_8,
		AF_9,
		AF_10,
		AF_11,
		AF_12,
		AF_13,
		AF_14,
		AF_15,
		AF_none,
	};*/
	
	template<typename Periph, typename GPIO, uint16_t pin, Type type>
	struct AFPin
	{
		static void Initialize()
		{
			uint32_t af = 0;
			
			static_assert(pin < 16, "Pin number must be from 0 to 15");
			
			static_assert(	
						  	(std::is_same<USART1, Periph>::value &&
						  		(((std::is_same<GPIOA, GPIO>::value && pin == 9) || (std::is_same<GPIOA, GPIO>::value && pin == 10)) /*||
								((std::is_same<GPIOB, GPIO>::value && pin == 6) || (std::is_same<GPIOB, GPIO>::value && pin == 7))*/))/* ||
						  
						  	(std::is_same<USART2, Periph>::value &&
						  		(((std::is_same<GPIOA, GPIO>::value && pin == 2) || (std::is_same<GPIOA, GPIO>::value && pin == 3)) ||
								((std::is_same<GPIOD, GPIO>::value && pin == 5) || (std::is_same<GPIOD, GPIO>::value && pin == 6)))) ||
						  
						  	(std::is_same<USART3, Periph>::value &&
						  		(((std::is_same<GPIOB, GPIO>::value && pin == 10) || (std::is_same<GPIOC, GPIO>::value && pin == 11)) ||
								((std::is_same<GPIOC, GPIO>::value && pin == 10) || (std::is_same<GPIOC, GPIO>::value && pin == 11)) ||
								((std::is_same<GPIOD, GPIO>::value && pin == 8) || (std::is_same<GPIOD, GPIO>::value && pin == 9)))) ||
								
							(std::is_same<UART4, Periph>::value &&
						  		(((std::is_same<GPIOA, GPIO>::value && pin == 0) || (std::is_same<GPIOA, GPIO>::value && pin == 1)) ||
								((std::is_same<GPIOC, GPIO>::value && pin == 10) || (std::is_same<GPIOC, GPIO>::value && pin == 11)))) ||
								
							(std::is_same<UART5, Periph>::value &&
						  		(((std::is_same<GPIOC, GPIO>::value && pin == 12) || (std::is_same<GPIOD, GPIO>::value && pin == 2)))) ||
								
							(std::is_same<USART6, Periph>::value &&
						  		(((std::is_same<GPIOC, GPIO>::value && pin == 6) || (std::is_same<GPIOC, GPIO>::value && pin == 7)) ||
								((std::is_same<GPIOG, GPIO>::value && pin == 14) || (std::is_same<GPIOG, GPIO>::value && pin == 9))))*/,
							
							"AF not exist");
			
			// Выбор альтернативной конфигурации
			if(std::is_same<USART1, Periph>::value)
				af = 7;
			/*if(std::is_same<USART1, Periph>::value || std::is_same<USART2, Periph>::value || std::is_same<USART3, Periph>::value)
				af = AF_7;
			
			else if(std::is_same<UART4, Periph>::value || std::is_same<UART5, Periph>::value || std::is_same<USART6, Periph>::value)
				af = AF_8;*/
			
			_Enable<GPIO>();
				
			SetMode<GPIO, pin, Alt_mode>();
			SetType<GPIO, pin, type>();
			SetSpeed<GPIO, pin, Mhz_100>();
			SetAltFunction<GPIO, pin, af>();
		}
	};

protected:
	template<typename GPIO, uint16_t pin, Mode mode = Output, Type type = Push_pull, Speed speed = Mhz_100>
	struct OutputPin
	{
		static void Initialize()
		{
			static_assert(pin < 16, "Pin number must be from 0 to 15");
		
			_Enable<GPIO>();
			
			SetMode<GPIO, pin, mode>();
			SetType<GPIO, pin, type>();
			SetSpeed<GPIO, pin, speed>();
		}
	};

	template<typename GPIO, uint16_t pin, Mode mode = Input, Pull pull = Pull_none>
	struct InputPin
	{
		static void Initialize()
		{
			static_assert(mode == Input || mode == Analog, "Only output mode");
			static_assert(pin < 16, "Pin number must be from 0 to 15");
		
			_Enable<GPIO>();
		
			SetMode<GPIO, pin, mode>();
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
	template<typename GPIO, uint16_t pin, Mode mode>
	static void SetMode()
	{
		GPIO::MODER::Set((GPIO::MODER::Get() & ~(2 << pin * 2)) | (mode << pin * 2));
	}
	
	template<typename GPIO, uint16_t pin, Type type>
	static void SetType()
	{
		GPIO::OTYPER::Set((GPIO::OTYPER::Get() & ~(1 << pin)) | (type << pin));
	}
	
	template<typename GPIO, uint16_t pin, Speed speed>
	static void SetSpeed()
	{
		GPIO::OSPEEDR::Set((GPIO::OSPEEDR::Get() & ~(2 << pin * 2)) | (speed << pin * 2));
	}
	
	template<typename GPIO, uint16_t pin, Pull pull>
	static void SetPull()
	{
		GPIO::PUPDR::Set((GPIO::PUPDR::Get() & ~(2 << pin * 2)) | (pull << pin * 2));
	}
	
	template<typename GPIO, uint16_t pin>
	static void SetAltFunction(uint32_t af)
	{
		if constexpr (pin < 8)
			GPIO::AFRL::Set(GPIO::AFRL::Get() & ~(4 << pin * 4) | (af << pin * 4));
		else
			GPIO::AFRH::Set(GPIO::AFRH::Get() & ~(4 << (pin - 8) * 4) | (af << (pin - 8) * 4));
	}
};