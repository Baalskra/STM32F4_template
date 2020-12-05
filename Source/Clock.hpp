#pragma once

#include "RCC.hpp"
#include "FLASH.hpp"

class Clock: protected RCC, protected FLASH 
{
	Clock() = delete;
	
public:
    static void ClearSecurityFlag()
    {
        SecurityFlagClear();
    }
    static bool IsSecurityFailed()
    {
        return !IsSecurityOk();
    }

    static bool IsPLLPoweredFromInternalCrystal()
    {
        return IsInternalCrystalPLLSource();
    }

	static bool Initialize()
	{
		bool 	hse_failed = true,
				pll_failed = true,
                status = false;
		
		if(IsSecurityOk())
		{
			ExternalCrystalEnable();
			hse_failed = !IsExternalCrystalReady();
		}
		else
			hse_failed = true;
			
		if(!hse_failed)
			SecurityEnable();

        if(!hse_failed)
		{
            SetPLLMDivider<4>();
            SetPLLNMultiplier<168>();
            SetPLLPDivider<2>();
            SetPLLMQivider<7>();
			SetPLLSourceExternalCrystal();
            PLLEnable();
		    pll_failed = !IsPLLReady();
        }

		// FIXME: По хорощему надо посчитать частоту работы и только потом выставлять задержку 
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
			if(pll_failed)  SetLatency<0>();
			else            SetLatency<5>();
		}

		DataCacheEnable();
		InstructionCacheEnable();
		PrefetchEnable();
		
		SetAHBPrescaler<1>();
			
		if(!pll_failed)
		{
			SetAPB1Prescaler<4>();
			SetAPB2Prescaler<2>();
		}
		else
		{
			SetAPB1Prescaler<1>();
			SetAPB2Prescaler<1>();
		}

		if(!pll_failed)                     SetSystemSourcePLL();
		else if(!hse_failed && pll_failed)  SetSystemSourceExternalCrystal();
		else                                SetSystemSourceInternalCrystal();
		
		status = IsSystemClockReady();

        CalculateFrequencies();

        return status;
	}

    inline static uint32_t sysclk_frequency;
    inline static uint32_t hclk_frequency;
    inline static uint32_t pclk1_frequency;
    inline static uint32_t pclk2_frequency;

private:

    static constexpr uint8_t table[] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};

    static void CalculateFrequencies()
    {
        uint32_t pllvco = 0;

        switch(SetSystemSource())
        {
        case 1: sysclk_frequency = hse_value; break;
        case 2:
            if(GetPLLSource())  pllvco = (hse_value / GetPLLMDivider()) * GetPLLNMultiplier();
            else                pllvco = (hsi_value / GetPLLMDivider()) * GetPLLNMultiplier();

            sysclk_frequency = pllvco / GetPLLPDivider();
            break;

        default: sysclk_frequency = hsi_value; break;
        }

        hclk_frequency = sysclk_frequency >> table[GetAHBPrescaler()];
        pclk1_frequency = hclk_frequency >> table[GetAPB1Prescaler()];
        pclk2_frequency = hclk_frequency >> table[GetAPB2Prescaler()];
    }
};