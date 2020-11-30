#pragma once

#include "syscfg_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class SYSCFGBase
{
private:
	static constexpr auto syscfg_address 	= 0x40013800;
	static constexpr auto memrmp_address 	= syscfg_address + 0x00;
	static constexpr auto pmc_address 		= syscfg_address + 0x04;
	static constexpr auto exticr1_address 	= syscfg_address + 0x08;
	static constexpr auto exticr2_address 	= syscfg_address + 0x0C;
	static constexpr auto exticr3_address 	= syscfg_address + 0x10;
	static constexpr auto exticr4_address 	= syscfg_address + 0x14;
	static constexpr auto cmpcr_address 	= syscfg_address + 0x20;
	
protected:
	struct MEMRMP: public Register<MCU, STM32F4xxxx, memrmp_address, 32, RW>
	{
		using MEMMODE = SYSCFG_MEMRMP_MEMMODE_VALUES<MCU, STM32F4xxxx, SYSCFGBase::MEMRMP, 0, 2, RW>;
	};
	
	struct PMC: public Register<MCU, STM32F4xxxx, pmc_address, 32, RW>
	{
		using IISEL = SYSCFG_PMC_IISEL_VALUES<MCU, STM32F4xxxx, SYSCFGBase::PMC, 23, 1, RW>;
	};
	
	struct EXTICR1: public Register<MCU, STM32F4xxxx, exticr1_address, 32, RW>
	{
		using EXTI0 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR1, 0, 4, RW>;
		using EXTI1 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR1, 4, 4, RW>;
		using EXTI2 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR1, 8, 4, RW>;
		using EXTI3 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR1, 12, 4, RW>;
	};
	
	struct EXTICR2: public Register<MCU, STM32F4xxxx, exticr2_address, 32, RW>
	{
		using EXTI4 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR2, 0, 4, RW>;
		using EXTI5 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR2, 4, 4, RW>;
		using EXTI6 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR2, 8, 4, RW>;
		using EXTI7 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR2, 12, 4, RW>;
	};
	
	struct EXTICR3: public Register<MCU, STM32F4xxxx, exticr3_address, 32, RW>
	{
		using EXTI8 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR3, 0, 4, RW>;
		using EXTI9 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR3, 4, 4, RW>;
		using EXTI10 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR3, 8, 4, RW>;
		using EXTI11 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR3, 12, 4, RW>;
	};
	
	struct EXTICR4: public Register<MCU, STM32F4xxxx, exticr4_address, 32, RW>
	{
		using EXTI12 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR4, 0, 4, RW>;
		using EXTI13 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR4, 4, 4, RW>;
		using EXTI14 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR4, 8, 4, RW>;
		using EXTI15 = SYSCFG_EXTICR_EXTI_VALUES<MCU, STM32F4xxxx, SYSCFGBase::EXTICR4, 12, 4, RW>;
	};
	
	struct CMPCR: public Register<MCU, STM32F4xxxx, cmpcr_address, 32, RW>
	{
		using CMPPD = StateValues<MCU, STM32F4xxxx, SYSCFGBase::CMPCR, 0, 1, RW>;
		using READY = StatusValues<MCU, STM32F4xxxx, SYSCFGBase::CMPCR, 8, 1, RO>;
	};
};