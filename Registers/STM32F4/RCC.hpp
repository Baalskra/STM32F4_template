#pragma once

#include "MCUs.hpp"
#include "RCCBase.hpp"
#include "SYSCFG.hpp"

class RCC: protected RCCBase<Target>
{
	RCC() = delete;

public:
	static bool IsInternalCrystalPLLSource()
	{
		return PLLCFGR::PLLSRC::HSI::IsSet();
	}
	
	static bool IsClockSecurityOk()
	{
		return !CIR::CSSF::DETECTED::IsSet();
	}

	static void ClockSecurityFlagClear()
	{
		CIR::CSSC::Clear();
	}
	
protected:
	template<typename ... Periph>
	static void _Enable()
	{
		(Periph::Enable(), ...);
	}
	
	template<typename ... Periph>
	static void _Disable()
	{
		(Periph::Disable(), ...);
	}
	
	template<typename ... Periph>
	static void Reset()
	{
		(Periph::_Reset(), ...);
	}
	
	static void ExternalCrystalOn()
	{
		CR::HSEON::ENABLED::Set();
	}
	
	static void ExternalCrystalOff()
	{
		CR::HSEON::DISABLED::Set();
	}
	
	static bool IsExternalCrystalReady()
	{
		bool status = true;
		
		for(uint32_t i = 0; !CR::HSERDY::READY::IsSet(); i++)
			if(i > 0x500)
				// Кварц не готов.
				status = false;
		
		return status;
	}
	
	static void ClockSecurityOn()
	{
		CR::CSSON::ENABLED::Set();
	}
	
	template<uint32_t p_div, uint32_t q_div, uint32_t m_div, uint32_t n_mult>
	static void ConfigurePLL()
	{
		PLLCFGR::PLLP::Set(p_div);
		PLLCFGR::PLLQ::Set(q_div);
		PLLCFGR::PLLM::Set(m_div);
		PLLCFGR::PLLN::Set(n_mult);
	}
	
	static void SetPLLSourceInternalCrystal()
	{
		PLLCFGR::PLLSRC::HSI::Set();
	}

	static void SetPLLSourceExternalCrystal()
	{
		PLLCFGR::PLLSRC::HSE::Set();
	}
		
	static void PLLOn()
	{
		CR::PLLON::ENABLED::Set();
	}
	
	static bool IsPLLReady()
	{
		bool status = true;
		
		for(uint32_t i = 0; CR::PLLRDY::UNLOCKED::IsSet(); i++)
			if(i > 0x500)
				// PLL не готов.
				status = false;
		
		return status;
	}
				
	template<uint32_t div>
	static void SetSystemPrescaler()
	{
		CFGR::HPRE::Set(div);
	}
				
	template<uint32_t div>
	static void SetBus1Prescaler()
	{
		CFGR::PPRE1::Set(div);
	}

	template<uint32_t div>
	static void SetBus2Prescaler()
	{
		CFGR::PPRE2::Set(div);
	}
	
	static void SetSystemSourcePLL()
	{
		CFGR::SW::PLL::Set();
	}

	static void SetSystemSourceExternalCrystal()
	{
		CFGR::SW::HSE::Set();
	}
	
	static void SetSystemSourceInternalCrystal()
	{
		CFGR::SW::HSI::Set();
	}
	
	static bool IsSystemClockReady()
	{
		bool status = true;
		
		for(uint32_t i = 0; CFGR::SWS::Get() != CFGR::SW::Get(); i++)
			if(i > 0x500)
				status = false;
		
		return status;
	}
};