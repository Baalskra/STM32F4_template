#pragma once

#include "gpio_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class GPIOGBase
{
	GPIOGBase() = delete;
	
private:
	// Адреса регистров.
	static constexpr auto gpio_address 		= 0x40021800;
	static constexpr auto moder_address 	= gpio_address + 0x00;
	static constexpr auto otyper_address 	= gpio_address + 0x04;
	static constexpr auto ospeedr_address 	= gpio_address + 0x08;
	static constexpr auto pupdr_address 	= gpio_address + 0x0C;
	static constexpr auto idr_address 		= gpio_address + 0x10;
	static constexpr auto odr_address 		= gpio_address + 0x14;
	static constexpr auto bsrr_address 		= gpio_address + 0x18;
	static constexpr auto lckr_address 		= gpio_address + 0x1C;
	static constexpr auto afrl_address 		= gpio_address + 0x20;
	static constexpr auto afrh_address 		= gpio_address + 0x24;
	
protected:
	struct MODER: public Register<MCU, STM32F4xxxx, moder_address, 32, RW>
	{
		using MODER0 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 0, 2, RW>;
		using MODER1 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 2, 2, RW>;
		using MODER2 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 4, 2, RW>;
		using MODER3 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 6, 2, RW>;
		using MODER4 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 8, 2, RW>;
		using MODER5 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 10, 2, RW>;
		using MODER6 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 12, 2, RW>;
		using MODER7 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 14, 2, RW>;
		using MODER8 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 16, 2, RW>;
		using MODER9 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 18, 2, RW>;
		using MODER10 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 20, 2, RW>;
		using MODER11 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 22, 2, RW>;
		using MODER12 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 24, 2, RW>;
		using MODER13 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 26, 2, RW>;
		using MODER14 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 28, 2, RW>;
		using MODER15 = GPIO_MODER_MODER_VALUES<MCU, STM32F4xxxx, GPIOGBase::MODER, 30, 2, RW>;
	};
	
	struct OTYPER: public Register<MCU, STM32F4xxxx, otyper_address, 16, RW>
	{
		using OT0 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 0, 1, RW>;
		using OT1 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 1, 1, RW>;
		using OT2 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 2, 1, RW>;
		using OT3 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 3, 1, RW>;
		using OT4 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 4, 1, RW>;
		using OT5 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 5, 1, RW>;
		using OT6 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 6, 1, RW>;
		using OT7 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 7, 1, RW>;
		using OT8 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 8, 1, RW>;
		using OT9 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 9, 1, RW>;
		using OT10 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 10, 1, RW>;
		using OT11 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 11, 1, RW>;
		using OT12 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 12, 1, RW>;
		using OT13 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 13, 1, RW>;
		using OT14 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 14, 1, RW>;
		using OT15 = GPIO_OTYPER_OT_VALUES<MCU, STM32F4xxxx, GPIOGBase::OTYPER, 15, 1, RW>;
	};
	
	struct OSPEEDR: public Register<MCU, STM32F4xxxx, ospeedr_address, 32, RW>
	{
		using OSPEEDR0 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 0, 2, RW>;
		using OSPEEDR1 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 2, 2, RW>;
		using OSPEEDR2 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 4, 2, RW>;
		using OSPEEDR3 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 6, 2, RW>;
		using OSPEEDR4 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 8, 2, RW>;
		using OSPEEDR5 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 10, 2, RW>;
		using OSPEEDR6 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 12, 2, RW>;
		using OSPEEDR7 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 14, 2, RW>;
		using OSPEEDR8 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 16, 2, RW>;
		using OSPEEDR9 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 18, 2, RW>;
		using OSPEEDR10 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 20, 2, RW>;
		using OSPEEDR11 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 22, 2, RW>;
		using OSPEEDR12 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 24, 2, RW>;
		using OSPEEDR13 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 26, 2, RW>;
		using OSPEEDR14 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 28, 2, RW>;
		using OSPEEDR15 = GPIO_OSPEEDR_OSPEEDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::OSPEEDR, 30, 2, RW>;
	};
	
	struct PUPDR: public Register<MCU, STM32F4xxxx, pupdr_address, 32, RW>
	{
		using PUPDR0 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 0, 2, RW>;
		using PUPDR1 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 2, 2, RW>;
		using PUPDR2 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 4, 2, RW>;
		using PUPDR3 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 6, 2, RW>;
		using PUPDR4 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 8, 2, RW>;
		using PUPDR5 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 10, 2, RW>;
		using PUPDR6 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 12, 2, RW>;
		using PUPDR7 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 14, 2, RW>;
		using PUPDR8 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 16, 2, RW>;
		using PUPDR9 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 18, 2, RW>;
		using PUPDR10 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 20, 2, RW>;
		using PUPDR11 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 22, 2, RW>;
		using PUPDR12 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 24, 2, RW>;
		using PUPDR13 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 26, 2, RW>;
		using PUPDR14 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 28, 2, RW>;
		using PUPDR15 = GPIO_PUPDR_PUPDR_VALUES<MCU, STM32F4xxxx, GPIOGBase::PUPDR, 30, 2, RW>;
	};
	
	struct IDR: public Register<MCU, STM32F4xxxx, idr_address, 16, RO>
	{
		using IDR0 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 0, 1, RO>;
		using IDR1 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 1, 1, RO>;
		using IDR2 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 2, 1, RO>;
		using IDR3 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 3, 1, RO>;
		using IDR4 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 4, 1, RO>;
		using IDR5 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 5, 1, RO>;
		using IDR6 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 6, 1, RO>;
		using IDR7 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 7, 1, RO>;
		using IDR8 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 8, 1, RO>;
		using IDR9 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 9, 1, RO>;
		using IDR10 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 10, 1, RO>;
		using IDR11 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 11, 1, RO>;
		using IDR12 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 12, 1, RO>;
		using IDR13 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 13, 1, RO>;
		using IDR14 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 14, 1, RO>;
		using IDR15 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::IDR, 15, 1, RO>;
	};
	
	struct ODR: public Register<MCU, STM32F4xxxx, odr_address, 16, RW>
	{
		using ODR0 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 0, 1, RW>;
		using ODR1 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 1, 1, RW>;
		using ODR2 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 2, 1, RW>;
		using ODR3 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 3, 1, RW>;
		using ODR4 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 4, 1, RW>;
		using ODR5 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 5, 1, RW>;
		using ODR6 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 6, 1, RW>;
		using ODR7 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 7, 1, RW>;
		using ODR8 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 8, 1, RW>;
		using ODR9 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 9, 1, RW>;
		using ODR10 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 10, 1, RW>;
		using ODR11 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 11, 1, RW>;
		using ODR12 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 12, 1, RW>;
		using ODR13 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 13, 1, RW>;
		using ODR14 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 14, 1, RW>;
		using ODR15 = GPIO_IODR_IODR_VALUES<MCU, STM32F4xxxx, GPIOGBase::ODR, 15, 1, RW>;
	};
	
	struct BSRR: public Register<MCU, STM32F4xxxx, bsrr_address, 32, WO>
	{
		using BS0 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 0, 1, WO>;
		using BS1 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 1, 1, WO>;
		using BS2 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 2, 1, WO>;
		using BS3 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 3, 1, WO>;
		using BS4 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 4, 1, WO>;
		using BS5 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 5, 1, WO>;
		using BS6 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 6, 1, WO>;
		using BS7 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 7, 1, WO>;
		using BS8 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 8, 1, WO>;
		using BS9 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 9, 1, WO>;
		using BS10 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 10, 1, WO>;
		using BS11 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 11, 1, WO>;
		using BS12 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 12, 1, WO>;
		using BS13 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 13, 1, WO>;
		using BS14 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 14, 1, WO>;
		using BS15 = GPIO_BSRR_BS_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 15, 1, WO>;
		using BR0 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 16, 1, WO>;
		using BR1 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 17, 1, WO>;
		using BR2 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 18, 1, WO>;
		using BR3 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 19, 1, WO>;
		using BR4 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 20, 1, WO>;
		using BR5 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 21, 1, WO>;
		using BR6 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 22, 1, WO>;
		using BR7 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 23, 1, WO>;
		using BR8 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 24, 1, WO>;
		using BR9 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 25, 1, WO>;
		using BR10 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 26, 1, WO>;
		using BR11 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 27, 1, WO>;
		using BR12 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 28, 1, WO>;
		using BR13 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 29, 1, WO>;
		using BR14 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 30, 1, WO>;
		using BR15 = GPIO_BSRR_BR_VALUES<MCU, STM32F4xxxx, GPIOGBase::BSRR, 31, 1, WO>;
	};
	
	struct LCKR: public Register<MCU, STM32F4xxxx, lckr_address, 32, RW>
	{
		using LCK0 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 0, 1, RW>;
		using LCK1 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 1, 1, RW>;
		using LCK2 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 2, 1, RW>;
		using LCK3 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 3, 1, RW>;
		using LCK4 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 4, 1, RW>;
		using LCK5 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 5, 1, RW>;
		using LCK6 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 6, 1, RW>;
		using LCK7 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 7, 1, RW>;
		using LCK8 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 8, 1, RW>;
		using LCK9 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 9, 1, RW>;
		using LCK10 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 10, 1, RW>;
		using LCK11 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 11, 1, RW>;
		using LCK12 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 12, 1, RW>;
		using LCK13 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 13, 1, RW>;
		using LCK14 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 14, 1, RW>;
		using LCK15 = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 15, 1, RW>;
		using LCKK = LockValues<MCU, STM32F4xxxx, GPIOGBase::LCKR, 16, 1, RW>;
	};
	
	struct AFRL: public Register<MCU, STM32F4xxxx, afrl_address, 32, RW>
	{
		using AFR0 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 0, 4, RW>;
		using AFR1 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 4, 4, RW>;
		using AFR2 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 8, 4, RW>;
		using AFR3 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 12, 4, RW>;
		using AFR4 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 16, 4, RW>;
		using AFR5 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 20, 4, RW>;
		using AFR6 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 24, 4, RW>;
		using AFR7 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRL, 28, 4, RW>;
	};

	struct AFRH: public Register<MCU, STM32F4xxxx, afrh_address, 32, RW>
	{
		using AFR8 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 0, 4, RW>;
		using AFR9 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 4, 4, RW>;
		using AFR10 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 8, 4, RW>;
		using AFR11 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 12, 4, RW>;
		using AFR12 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 16, 4, RW>;
		using AFR13 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 20, 4, RW>;
		using AFR14 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 24, 4, RW>;
		using AFR15 = GPIO_AFR_AFR_VALUES<MCU, STM32F4xxxx, GPIOGBase::AFRH, 28, 4, RW>;
	};
};