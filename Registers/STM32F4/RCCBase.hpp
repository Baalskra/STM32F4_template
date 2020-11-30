#pragma once

#include "rcc_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class RCCBase
{
private:
	// Адреса регистров.
	static constexpr auto rcc_address 			= 0x40023800;
	static constexpr auto cr_address 			= rcc_address + 0x00;
	static constexpr auto pllcfgr_address 		= rcc_address + 0x04;
	static constexpr auto cfgr_address 			= rcc_address + 0x08;
	static constexpr auto cir_address 			= rcc_address + 0x0C;
	static constexpr auto ahb1rstr_address 		= rcc_address + 0x10;
	static constexpr auto ahb2rstr_address 		= rcc_address + 0x14;
	static constexpr auto ahb3rstr_address 		= rcc_address + 0x18;
	static constexpr auto apb1rstr_address 		= rcc_address + 0x20;
	static constexpr auto apb2rstr_address 		= rcc_address + 0x24;
	static constexpr auto ahb1enr_address 		= rcc_address + 0x30;
	static constexpr auto ahb2enr_address 		= rcc_address + 0x34;
	static constexpr auto ahb3enr_address 		= rcc_address + 0x38;
	static constexpr auto apb1enr_address 		= rcc_address + 0x40;
	static constexpr auto apb2enr_address 		= rcc_address + 0x44;
	static constexpr auto ahb1lpenr_address 	= rcc_address + 0x50;
	static constexpr auto ahb2lpenr_address 	= rcc_address + 0x54;
	static constexpr auto ahb3lpenr_address 	= rcc_address + 0x58;
	static constexpr auto apb1lpenr_address 	= rcc_address + 0x60;
	static constexpr auto apb2lpenr_address 	= rcc_address + 0x64;
	static constexpr auto bdcr_address 			= rcc_address + 0x70;
	static constexpr auto csr_address 			= rcc_address + 0x74;
	static constexpr auto sscgr_address 		= rcc_address + 0x80;
	static constexpr auto plli2scfgr_address 	= rcc_address + 0x84;
	static constexpr auto pllsaicfgr_address 	= rcc_address + 0x88;
	static constexpr auto dckcfgr_address 		= rcc_address + 0x8C;
	
protected:
	struct CR: public Register<MCU, STM32F4xxxx, cr_address, 32, RW>
	{
		using HSION = StateValues<MCU, STM32F4xxxx, RCCBase::CR, 0, 1, RW>;
		using HSIRDY = StatusValues<MCU, STM32F4xxxx, RCCBase::CR, 1, 1, RO>;
		using HSITRIM = EmptyValues<MCU, STM32F4xxxx, RCCBase::CR, 3, 5, RW>;
		using HSICAL = EmptyValues<MCU, STM32F4xxxx, RCCBase::CR, 8, 8, RO>;
		using HSEON = StateValues<MCU, STM32F4xxxx, RCCBase::CR, 16, 1, RW>;
		using HSERDY = StatusValues<MCU, STM32F4xxxx, RCCBase::CR, 17, 1, RO>;
		using HSEBYP = RCC_BYP_VALUES<MCU, STM32F4xxxx, RCCBase::CR, 18, 1, RW>;
		using CSSON = StateValues<MCU, STM32F4xxxx, RCCBase::CR, 19, 1, RW>;
		using PLLON = StateValues<MCU, STM32F4xxxx, RCCBase::CR, 24, 1, RW>;
		using PLLRDY = LockValues<MCU, STM32F4xxxx, RCCBase::CR, 25, 1, RO>;
		using PLLI2SON = StateValues<MCU, STM32F4xxxx, RCCBase::CR, 26, 1, RW>;
		using PLLI2SRDY = LockValues<MCU, STM32F4xxxx, RCCBase::CR, 27, 1, RO>;
		using PLLSAION = StateValues<MCU, STM32F42_43xxx, RCCBase::CR, 28, 1, RW>;
		using PLLSAIRDY = LockValues<MCU, STM32F42_43xxx, RCCBase::CR, 29, 1, RO>;
	};
	
	struct PLLCFGR: public Register<MCU, STM32F4xxxx, pllcfgr_address, 32, RW>
	{
		using PLLM = EmptyValues<MCU, STM32F4xxxx, RCCBase::PLLCFGR, 0, 6, RW>;
		using PLLN = EmptyValues<MCU, STM32F4xxxx, RCCBase::PLLCFGR, 6, 9, RW>;
		using PLLP = RCC_PLLCFGR_PLLP_VALUES<MCU, STM32F4xxxx, RCCBase::PLLCFGR, 16, 2, RW>;
		using PLLSRC = RCC_PLLCFGR_PLLSRC_VALUES<MCU, STM32F4xxxx, RCCBase::PLLCFGR, 22, 1, RW>;
		using PLLQ = RCC_PLLCFGR_PLLQ_VALUES<MCU, STM32F4xxxx, RCCBase::PLLCFGR, 24, 4, RW>;
	};
	
	struct CFGR: public Register<MCU, STM32F4xxxx, cfgr_address, 32, RW>
	{
		using SW = RCC_CFGR_SW_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 0, 2, RW>;
		using SWS = RCC_CFGR_SW_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 2, 2, RW>;
		using HPRE = RCC_CFGR_HPRE_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 4, 4, RW>;
		using PPRE1 = RCC_CFGR_PPRE_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 10, 3, RW>;
		using PPRE2 = RCC_CFGR_PPRE_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 13, 3, RW>;
		using RTCPRE = EmptyValues<MCU, STM32F4xxxx, RCCBase::CFGR, 16, 5, RW>;
		using MCO1 = RCC_CFGR_MCO1_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 21, 2, RW>;
		using I2SSRC = RCC_CFGR_I2SSRC_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 23, 1, RW>;
		using MCO1PRE = RCC_CFGR_MCOPRE_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 24, 3, RW>;
		using MCO2PRE = RCC_CFGR_MCOPRE_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 27, 3, RW>;
		using MCO = RCC_CFGR_MCO2_VALUES<MCU, STM32F4xxxx, RCCBase::CFGR, 30, 2, RW>;
	};

	struct CIR: public Register<MCU, STM32F4xxxx, cir_address, 32, RW>
	{
		using LSIRDYF = StatusValues<MCU, STM32F4xxxx, RCCBase::CIR, 0, 1, RO>;
		using LSERDYF = StatusValues<MCU, STM32F4xxxx, RCCBase::CIR, 1, 1, RO>;
		using HSIRDYF = StatusValues<MCU, STM32F4xxxx, RCCBase::CIR, 2, 1, RO>;
		using HSERDYF = StatusValues<MCU, STM32F4xxxx, RCCBase::CIR, 3, 1, RO>;
		using PLLRDYF = StatusValues<MCU, STM32F4xxxx, RCCBase::CIR, 4, 1, RO>;
		using PLLI2SRDYF = StatusValues<MCU, STM32F4xxxx, RCCBase::CIR, 5, 1, RO>;
		using PLLSAIRDYF = StatusValues<MCU, STM32F42_43xxx, RCCBase::CIR, 6, 1, RO>;
		using CSSF = DetectValues<MCU, STM32F4xxxx, RCCBase::CIR, 7, 1, RO>;
		using LSIRDYIE = StateValues<MCU, STM32F4xxxx, RCCBase::CIR, 8, 1, RW>;
		using LSERDYIE = StateValues<MCU, STM32F4xxxx, RCCBase::CIR, 9, 1, RW>;
		using HSIRDYIE = StateValues<MCU, STM32F4xxxx, RCCBase::CIR, 10, 1, RW>;
		using HSERDYIE = StateValues<MCU, STM32F4xxxx, RCCBase::CIR, 11, 1, RW>;
		using PLLRDYIE = StateValues<MCU, STM32F4xxxx, RCCBase::CIR, 12, 1, RW>;
		using PLLI2SRDYIE = StateValues<MCU, STM32F4xxxx, RCCBase::CIR, 13, 1, RW>;
		using PLLSAIRDYIE = StateValues<MCU, STM32F42_43xxx, RCCBase::CIR, 13, 1, RW>;
		using LSIRDYC = Field<MCU, STM32F4xxxx, RCCBase::CIR, 16, 1, RC_W1>;
		using LS3RDYC = Field<MCU, STM32F4xxxx, RCCBase::CIR, 17, 1, RC_W1>;
		using HSIRDYC = Field<MCU, STM32F4xxxx, RCCBase::CIR, 18, 1, RC_W1>;
		using HSERDYC = Field<MCU, STM32F4xxxx, RCCBase::CIR, 19, 1, RC_W1>;
		using PLLRDYC = Field<MCU, STM32F4xxxx, RCCBase::CIR, 20, 1, RC_W1>;
		using PLLI2SRDYC = Field<MCU, STM32F4xxxx, RCCBase::CIR, 21, 1, RC_W1>;
		using PLLSAIRDYC = Field<MCU, STM32F42_43xxx, RCCBase::CIR, 22, 1, RC_W1>;
		using CSSC = Field<MCU, STM32F4xxxx, RCCBase::CIR, 23, 1, RC_W1>;
	};
	
	struct AHB1RSTR: public Register<MCU, STM32F4xxxx, ahb1rstr_address, 32, RW>
	{
		using GPIOARST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 0, 1, RW>;
		using GPIOBRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 1, 1, RW>;
		using GPIOCRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 2, 1, RW>;
		using GPIODRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 3, 1, RW>;
		using GPIOERST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 4, 1, RW>;
		using GPIOFRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 5, 1, RW>;
		using GPIOGRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 6, 1, RW>;
		using GPIOHRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 7, 1, RW>;
		using GPIOIRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 8, 1, RW>;
		using GPIOJRST = ResetValues<MCU, STM32F42_43xxx, RCCBase::AHB1RSTR, 9, 1, RW>;
		using GPIOKRST = ResetValues<MCU, STM32F42_43xxx, RCCBase::AHB1RSTR, 10, 1, RW>;
		using CRCRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 12, 1, RW>;
		using FLITFRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 15, 1, RW>;
		using SRAM1RST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 16, 1, RW>;
		using SRAM2RST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 17, 1, RW>;
		using BKPSRAMRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 18, 1, RW>;
		using SRAM3RST = ResetValues<MCU, STM32F42_43xxx, RCCBase::AHB1RSTR, 19, 1, RW>;
		using CCMDATARAMRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 20, 1, RW>;
		using DMA1RST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 21, 1, RW>;
		using DMA2RST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 22, 1, RW>;
		using DMA2DRST = ResetValues<MCU, STM32F42_43xxx, RCCBase::AHB1RSTR, 23, 1, RW>;
		using ETHMACRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 25, 1, RW>;
		using ETHMACTXRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 26, 1, RW>;
		using ETHMACRXRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 27, 1, RW>;
		using ETHMACPTPRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 28, 1, RW>;
		using OTGHSRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 29, 1, RW>;
		using OTGHSULPIRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB1RSTR, 30, 1, RW>;
	};
	
	struct AHB2RSTR: public Register<MCU, STM32F4xxxx, ahb2rstr_address, 32, RW>
	{
		using DCMIRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB2RSTR, 0, 1, RW>;
		using CRYPRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB2RSTR, 4, 1, RW>;
		using HASHRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB2RSTR, 5, 1, RW>;
		using RNGRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB2RSTR, 6, 1, RW>;
		using OTGFSRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB2RSTR, 7, 1, RW>;
	};
	
	struct AHB3RSTR: public Register<MCU, STM32F4xxxx, ahb3rstr_address, 32, RW>
	{
		using FSMCRST = ResetValues<MCU, STM32F4xxxx, RCCBase::AHB3RSTR, 0, 1, RW>;
	};
	
	struct APB1RSTR: public Register<MCU, STM32F4xxxx, apb1rstr_address, 32, RW>
	{
		using TIM2RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 0, 1, RW>;
		using TIM3RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 1, 1, RW>;
		using TIM4RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 2, 1, RW>;
		using TIM5RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 3, 1, RW>;
		using TIM6RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 4, 1, RW>;
		using TIM7RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 5, 1, RW>;
		using TIM12RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 6, 1, RW>;
		using TIM13RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 7, 1, RW>;
		using TIM14RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 8, 1, RW>;
		using WWDGRST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 11, 1, RW>;
		using SPI2RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 14, 1, RW>;
		using SPI3RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 15, 1, RW>;
		using USART2RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 17, 1, RW>;
		using USART3RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 18, 1, RW>;
		using UART4RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 19, 1, RW>;
		using UART5RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 20, 1, RW>;
		using I2C1RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 21, 1, RW>;
		using I2C2RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 22, 1, RW>;
		using I2C3RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 23, 1, RW>;
		using CAN1RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 25, 1, RW>;
		using CAN2RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 26, 1, RW>;
		using PWRRST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 28, 1, RW>;
		using DACRST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB1RSTR, 29, 1, RW>;
		using UART7RST = ResetValues<MCU, STM32F42_43xxx, RCCBase::APB1RSTR, 30, 1, RW>;
		using UART8RST = ResetValues<MCU, STM32F42_43xxx, RCCBase::APB1RSTR, 31, 1, RW>;
	};
	
	struct APB2RSTR: public Register<MCU, STM32F4xxxx, apb2rstr_address, 32, RW>
	{
		using TIM1RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 0, 1, RW>;
		using TIM8RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 1, 1, RW>;
		using USART1RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 4, 1, RW>;
		using USART6RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 5, 1, RW>;
		using ADCRST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 8, 1, RW>;
		using SDIORST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 11, 1, RW>;
		using SPI1RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 12, 1, RW>;
		using SPI4RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 13, 1, RW>;
		using SYSCFGRST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 14, 1, RW>;
		using TIM9RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 16, 1, RW>;
		using TIM10RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 17, 1, RW>;
		using TIM11RST = ResetValues<MCU, STM32F4xxxx, RCCBase::APB2RSTR, 18, 1, RW>;
		using SPI5RST = ResetValues<MCU, STM32F42_43xxx, RCCBase::APB2RSTR, 20, 1, RW>;
		using SPI6RST = ResetValues<MCU, STM32F42_43xxx, RCCBase::APB2RSTR, 21, 1, RW>;
		using SAI1RST = ResetValues<MCU, STM32F42_43xxx, RCCBase::APB2RSTR, 22, 1, RW>;
		using LTDCRST = ResetValues<MCU, STM32F42_43xxx, RCCBase::APB2RSTR, 26, 1, RW>;
	};
	
	struct AHB1ENR: public Register<MCU, STM32F4xxxx, ahb1enr_address, 32, RW>
	{
		using GPIOAEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 0, 1, RW>;
		using GPIOBEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 1, 1, RW>;
		using GPIOCEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 2, 1, RW>;
		using GPIODEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 3, 1, RW>;
		using GPIOEEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 4, 1, RW>;
		using GPIOFEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 5, 1, RW>;
		using GPIOGEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 6, 1, RW>;
		using GPIOHEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 7, 1, RW>;
		using GPIOIEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 8, 1, RW>;
		using GPIOJEN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1ENR, 9, 1, RW>;
		using GPIOKEN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1ENR, 10, 1, RW>;
		using CRCEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 12, 1, RW>;
		using FLITFEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 15, 1, RW>;
		using SRAM1EN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 16, 1, RW>;
		using SRAM2EN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 17, 1, RW>;
		using BKPSRAMEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 18, 1, RW>;
		using SRAM3EN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1ENR, 19, 1, RW>;
		using CCMDATARAMEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 20, 1, RW>;
		using DMA1EN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 21, 1, RW>;
		using DMA2EN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 22, 1, RW>;
		using DMA2DEN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1ENR, 23, 1, RW>;
		using ETHMACEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 25, 1, RW>;
		using ETHMACTXEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 26, 1, RW>;
		using ETHMACRXEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 27, 1, RW>;
		using ETHMACPTPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 28, 1, RW>;
		using OTGHSEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 29, 1, RW>;
		using OTGHSULPIEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1ENR, 30, 1, RW>;
	};
	
	struct AHB2ENR: public Register<MCU, STM32F4xxxx, ahb2enr_address, 32, RW>
	{
		using DCMIEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2ENR, 0, 1, RW>;
		using CRYPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2ENR, 4, 1, RW>;
		using HASHEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2ENR, 5, 1, RW>;
		using RNGEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2ENR, 6, 1, RW>;
		using OTGFSEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2ENR, 7, 1, RW>;
	};
	
	struct AHB3ENR: public Register<MCU, STM32F4xxxx, ahb3enr_address, 32, RW>
	{
		using FSMCEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB3ENR, 0, 1, RW>;
	};
	
	struct APB1ENR: public Register<MCU, STM32F4xxxx, apb1enr_address, 32, RW>
	{
		using TIM2EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 0, 1, RW>;
		using TIM3EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 1, 1, RW>;
		using TIM4EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 2, 1, RW>;
		using TIM5EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 3, 1, RW>;
		using TIM6EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 4, 1, RW>;
		using TIM7EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 5, 1, RW>;
		using TIM12EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 6, 1, RW>;
		using TIM13EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 7, 1, RW>;
		using TIM14EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 8, 1, RW>;
		using WWDGEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 11, 1, RW>;
		using SPI2EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 14, 1, RW>;
		using SPI3EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 15, 1, RW>;
		using USART2EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 17, 1, RW>;
		using USART3EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 18, 1, RW>;
		using UART4EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 19, 1, RW>;
		using UART5EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 20, 1, RW>;
		using I2C1EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 21, 1, RW>;
		using I2C2EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 22, 1, RW>;
		using I2C3EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 23, 1, RW>;
		using CAN1EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 25, 1, RW>;
		using CAN2EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 26, 1, RW>;
		using PWREN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 28, 1, RW>;
		using DACEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1ENR, 29, 1, RW>;
		using UART7 = StateValues<MCU, STM32F42_43xxx, RCCBase::APB1ENR, 30, 1, RW>;
		using UART8 = StateValues<MCU, STM32F42_43xxx, RCCBase::APB1ENR, 31, 1, RW>;
	};
	
	struct APB2ENR: public Register<MCU, STM32F4xxxx, apb2enr_address, 32, RW>
	{
		using TIM1EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 0, 1, RW>;
		using TIM8EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 1, 1, RW>;
		using USART1EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 4, 1, RW>;
		using USART6EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 5, 1, RW>;
		using ADCEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 8, 1, RW>;
		using SDIOEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 11, 1, RW>;
		using SPI1EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 12, 1, RW>;
		using SPI4EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 13, 1, RW>;
		using SYSCFGEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 14, 1, RW>;
		using TIM9EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 16, 1, RW>;
		using TIM10EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 17, 1, RW>;
		using TIM11EN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2ENR, 18, 1, RW>;
		using SPI5EN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2ENR, 20, 1, RW>;
		using SPI6EN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2ENR, 21, 1, RW>;
		using SAI1EN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2ENR, 22, 1, RW>;
		using LTDCEN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2ENR, 26, 1, RW>;
	};
	
	struct AHB1LPENR: public Register<MCU, STM32F4xxxx, ahb1lpenr_address, 32, RW>
	{
		using GPIOALPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 0, 1, RW>;
		using GPIOBLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 1, 1, RW>;
		using GPIOCLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 2, 1, RW>;
		using GPIODLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 3, 1, RW>;
		using GPIOELPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 4, 1, RW>;
		using GPIOFLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 5, 1, RW>;
		using GPIOGLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 6, 1, RW>;
		using GPIOHLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 7, 1, RW>;
		using GPIOILPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 8, 1, RW>;
		using GPIOJLPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1LPENR, 9, 1, RW>;
		using GPIOKLPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1LPENR, 10, 1, RW>;
		using CRCLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 12, 1, RW>;
		using FLITFLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 15, 1, RW>;
		using SRAM1LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 16, 1, RW>;
		using SRAM2LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 17, 1, RW>;
		using BKPSRAMLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 18, 1, RW>;
		using SRAM3LPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1LPENR, 19, 1, RW>;
		using DMA1LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 21, 1, RW>;
		using DMA2LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 22, 1, RW>;
		using DMA2DLPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::AHB1LPENR, 23, 1, RW>;
		using ETHMACLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 25, 1, RW>;
		using ETHMACTXLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 26, 1, RW>;
		using ETHMACRXLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 27, 1, RW>;
		using ETHMACPTPLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 28, 1, RW>;
		using OTGHSLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 29, 1, RW>;
		using OTGHSULPILPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB1LPENR, 30, 1, RW>;
	};
	
	struct AHB2LPENR: public Register<MCU, STM32F4xxxx, ahb2lpenr_address, 32, RW>
	{
		using DCMILPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2LPENR, 0, 1, RW>;
		using CRYPLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2LPENR, 4, 1, RW>;
		using HASHLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2LPENR, 5, 1, RW>;
		using RNGLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2LPENR, 6, 1, RW>;
		using OTGFSLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB2LPENR, 7, 1, RW>;
	};
	
	struct AHB3LPENR: public Register<MCU, STM32F4xxxx, ahb3lpenr_address, 32, RW>
	{
		using FSMCLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::AHB3LPENR, 0, 1, RW>;
	};
	
	struct APB1LPENR: public Register<MCU, STM32F4xxxx, apb1lpenr_address, 32, RW>
	{
		using TIM2LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 0, 1, RW>;
		using TIM3LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 1, 1, RW>;
		using TIM4LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 2, 1, RW>;
		using TIM5LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 3, 1, RW>;
		using TIM6LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 4, 1, RW>;
		using TIM7LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 5, 1, RW>;
		using TIM12LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 6, 1, RW>;
		using TIM13LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 7, 1, RW>;
		using TIM14LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 8, 1, RW>;
		using WWDGLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 11, 1, RW>;
		using SPI2LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 14, 1, RW>;
		using SPI3LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 15, 1, RW>;
		using USART2LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 17, 1, RW>;
		using USART3LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 18, 1, RW>;
		using UART4LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 19, 1, RW>;
		using UART5LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 20, 1, RW>;
		using I2C1LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 21, 1, RW>;
		using I2C2LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 22, 1, RW>;
		using I2C3LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 23, 1, RW>;
		using CAN1LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 25, 1, RW>;
		using CAN2LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 26, 1, RW>;
		using PWRLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 28, 1, RW>;
		using DACLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB1LPENR, 29, 1, RW>;
		using UART7LPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB1LPENR, 30, 1, RW>;
		using UART8LPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB1LPENR, 31, 1, RW>;
	};
	
	struct APB2LPENR: public Register<MCU, STM32F4xxxx, apb2lpenr_address, 32, RW>
	{
		using TIM1LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 0, 1, RW>;
		using TIM8LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 1, 1, RW>;
		using USART1LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 4, 1, RW>;
		using USART6LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 5, 1, RW>;
		using ADCLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 8, 1, RW>;
		using SDIOLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 11, 1, RW>;
		using SPI1LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 12, 1, RW>;
		using SYSCFGLPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 14, 1, RW>;
		using TIM9LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 16, 1, RW>;
		using TIM10LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 17, 1, RW>;
		using TIM11LPEN = StateValues<MCU, STM32F4xxxx, RCCBase::APB2LPENR, 18, 1, RW>;
		using SPI5LPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2LPENR, 20, 1, RW>;
		using SPI6LPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2LPENR, 21, 1, RW>;
		using SAI1LPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2LPENR, 22, 1, RW>;
		using LTDCLPEN = StateValues<MCU, STM32F42_43xxx, RCCBase::APB2LPENR, 26, 1, RW>;
	};
	
	struct BDCR: public Register<MCU, STM32F4xxxx, bdcr_address, 32, RW>
	{
		using LSEON = StateValues<MCU, STM32F4xxxx, RCCBase::BDCR, 0, 1, RW>;
		using LSERDY = StatusValues<MCU, STM32F4xxxx, RCCBase::BDCR, 1, 1, RO>;
		using LSEBYP = RCC_BYP_VALUES<MCU, STM32F4xxxx, RCCBase::BDCR, 2, 1, RW>;
		using RTCSEL = RCC_BDCR_RTCSEL_VALUES<MCU, STM32F4xxxx, RCCBase::BDCR, 8, 2, RW>;
		using RTCEN = StateValues<MCU, STM32F4xxxx, RCCBase::BDCR, 15, 1, RW>;
		using BDRST = ResetValues<MCU, STM32F4xxxx, RCCBase::BDCR, 16, 1, RW>;
	};
	
	struct CSR: public Register<MCU, STM32F4xxxx, csr_address, 32, RW>
	{
		using LSION = StateValues<MCU, STM32F4xxxx, RCCBase::CSR, 0, 1, RW>;
		using LSIRDY = StatusValues<MCU, STM32F4xxxx, RCCBase::CSR, 1, 1, RO>;
		using RMVF = Field<MCU, STM32F4xxxx, RCCBase::CSR, 24, 1, RC_W1>;
		using BORRSTF = RCC_CSR_OCCUR_VALUES<MCU, STM32F4xxxx, RCCBase::CSR, 25, 2, RO>;
		using PINRSTF = RCC_CSR_OCCUR_VALUES<MCU, STM32F4xxxx, RCCBase::CSR, 26, 1, RO>;
		using PORRSTF = RCC_CSR_OCCUR_VALUES<MCU, STM32F4xxxx, RCCBase::CSR, 27, 1, RO>;
		using SFTRSTF = RCC_CSR_OCCUR_VALUES<MCU, STM32F4xxxx, RCCBase::CSR, 26, 1, RO>;
		using IWDGRSTF = RCC_CSR_OCCUR_VALUES<MCU, STM32F4xxxx, RCCBase::CSR, 29, 1, RO>;
		using WWDGRSTF = RCC_CSR_OCCUR_VALUES<MCU, STM32F4xxxx, RCCBase::CSR, 30, 1, RO>;
		using LPWRRSTF = RCC_CSR_OCCUR_VALUES<MCU, STM32F4xxxx, RCCBase::CSR, 31, 1, RO>;
	};
	
	struct SSCGR: public Register<MCU, STM32F4xxxx, sscgr_address, 32, RW>
	{
		using MODPER = EmptyValues<MCU, STM32F4xxxx, RCCBase::SSCGR, 0, 13, RW>;
		using INCSTEP = EmptyValues<MCU, STM32F4xxxx, RCCBase::SSCGR, 13, 15, RW>;
		using SPREADSEL = RCC_SSCGR_SPREADSEL_VALUES<MCU, STM32F4xxxx, RCCBase::SSCGR, 30, 1, RW>;
		using SSCGREN = StateValues<MCU, STM32F4xxxx, RCCBase::SSCGR, 31, 1, RW>;
	};
	
	struct PLLI2SCFGR: public Register<MCU, STM32F4xxxx, plli2scfgr_address, 32, RW>
	{
		using PLLI2SN = EmptyValues<MCU, STM32F4xxxx, RCCBase::PLLI2SCFGR, 6, 9, RW>;
		using PLLI2SR = EmptyValues<MCU, STM32F4xxxx, RCCBase::PLLI2SCFGR, 28, 3, RW>;
	};
	
	struct PLLSAICFGR: public Register<MCU, STM32F42_43xxx, pllsaicfgr_address, 32, RW>
	{
		using PLLSAIN = EmptyValues<MCU, STM32F42_43xxx, RCCBase::PLLSAICFGR, 6, 9, RW>;
		using PLLSAIQ = EmptyValues<MCU, STM32F42_43xxx, RCCBase::PLLSAICFGR, 24, 4, RW>;
		using PLLSAIR = EmptyValues<MCU, STM32F42_43xxx, RCCBase::PLLSAICFGR, 28, 3, RW>;
	};
	
	struct DCKCFGR: public Register<MCU, STM32F42_43xxx, dckcfgr_address, 32, RW>
	{
		using PLLS2DIVQ = EmptyValues<MCU, STM32F42_43xxx, RCCBase::DCKCFGR, 0, 5, RW>;
		using PLLSAIDIVQ = EmptyValues<MCU, STM32F42_43xxx, RCCBase::DCKCFGR, 8, 5, RW>;
		using PLLSAIDIVR = EmptyValues<MCU, STM32F42_43xxx, RCCBase::DCKCFGR, 16, 2, RW>;
		using SAI1ASRC = EmptyValues<MCU, STM32F42_43xxx, RCCBase::DCKCFGR, 20, 2, RW>;
		using SAI1BSRC = EmptyValues<MCU, STM32F42_43xxx, RCCBase::DCKCFGR, 22, 2, RW>;
		using TIMPRE = EmptyValues<MCU, STM32F42_43xxx, RCCBase::DCKCFGR, 24, 1, RW>;
	};
};