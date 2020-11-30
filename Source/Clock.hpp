#pragma once

#include "RCC.hpp"
#include "SYSCFG.hpp"
#include "FLASH.hpp"

class Clock: public RCC, public FLASH
{
	Clock() = delete;
	
public:
	static void Initialize()
	{
		bool 	hse_failed = false,		// Состояние кварца.
				pll_failed = false;		// Состояние PLL.
		
		if(IsClockSecurityOk())
		{
			ExternalCrystalOn();
			hse_failed = !IsExternalCrystalReady();
		}
		else
			hse_failed = true;
			
		if(!hse_failed)
			ClockSecurityOn();
		
		if(hse_failed)
		{
			// Раз кварц не готов попробую от внутренненго.
			ConfigurePLL<2, 5, 13, 195>();
			SetPLLSourceInternalCrystal();
		}
		else
		{
			// Настройка PLL под внешний кварц.
			ConfigurePLL<2, 5, 4, 168>();
			SetPLLSourceExternalCrystal();
		}

		// Включаю PLL.
		PLLOn();
		// Жду готовности PLL.
		pll_failed = !IsPLLReady();
		
		if(std::is_same<Voltage_1_8_to_2_1, Voltage>::value)
		{
			SetLatency<0>();
		}
		else if(std::is_same<Voltage_2_1_to_2_4, Voltage>::value)
		{
			SetLatency<0>();
		}
		else if(std::is_same<Voltage_2_4_to_2_7, Voltage>::value)
		{
			SetLatency<0>();
		}
		else if(std::is_same<Voltage_2_7_to_3_6, Voltage>::value)
		{
			if(pll_failed)
				// Если PLL не готов, задержку нужно выставить на минимум.
				SetLatency<0>();
			else
				// Если все ок, выставляю задержку.
				SetLatency<5>();
		}
			
		// Включаю крутые причиндалы flash памяти.
		DataCacheEnable();
		InstructionCacheEnable();
		PrefetchEnable();
		
		SetSystemPrescaler<1>();
			
		if(!pll_failed)
		{
			// Если PLL запустился, устанавливаю нормальные делители.
			SetBus1Prescaler<4>();
			SetBus2Prescaler<2>();
		}
		else
		{
			// А если не запустился - то множители нужно по 1.
			SetBus1Prescaler<1>();
			SetBus2Prescaler<1>();
		}
			
		// В зависимости от того, что не запустилось - выбираем источник тактирования.
		if(!pll_failed)
			// PLL запустился
			SetSystemSourcePLL();
		else if(!hse_failed && pll_failed)
			// PLL не запустился, но HSE запустился.
			SetSystemSourceExternalCrystal();
		else
			// Ничего не запустилось, приехали.
			SetSystemSourceInternalCrystal();
		
		// Жду готовности тактирования мк.
		if(!IsSystemClockReady())
			while(1); // Не реальный случай
		
		_Enable<SYSCFG>();
	}
	
	static constexpr auto system_clock_frequency = 0;
	
};