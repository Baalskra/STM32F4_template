#pragma once

#include "MCUs.hpp"
#include "RCCBase.hpp"

class RCC: protected RCCBase<Target>
{
	RCC() = delete;

	static constexpr auto lock_timeout = 0x500;
	
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
	static void _Reset()
	{
		(Periph::_Reset(), ...);
	}
	static bool IsInternalCrystalPLLSource()
	{
		return PLLCFGR::PLLSRC::HSI::IsSet();
	}

	static bool IsExternalCrystalPLLSource()
	{
		return PLLCFGR::PLLSRC::HSE::IsSet();
	}
	
	static bool IsSecurityOk()
	{
		return !CIR::CSSF::DETECTED::IsSet();
	}

	static void SecurityFlagClear()
	{
		CIR::CSSC::Clear();
	}

	static void ExternalCrystalEnable()
	{
		CR::HSEON::ENABLED::Set();
	}
	
	static void ExternalCrystalDisable()
	{
		CR::HSEON::DISABLED::Set();
	}
	
	static bool IsExternalCrystalReady()
	{
		bool status = true;
		
		for(uint32_t i = 0; !CR::HSERDY::READY::IsSet(); i++)
			if(i > lock_timeout)
				status = false;
		
		return status;
	}
	
	static void SecurityEnable()
	{
		CR::CSSON::ENABLED::Set();
	}

	static void SecurityDisable()
	{
		CR::CSSON::DISABLED::Set();
	}

	template<uint32_t div>
	static void SetPLLMDivider()
	{
		static_assert(div <= 63 && div >= 2, "M divider must be from 2 to 63");
		
		PLLCFGR::PLLM::Set(div);
	}

	template<uint32_t mult>
	static void SetPLLNMultiplier()
	{
		static_assert(mult <= 432 && mult >= 50, "N multiplier must be from 50 to 432");
		
		PLLCFGR::PLLN::Set(mult);
	}

	template<uint32_t div>
	static void SetPLLPDivider()
	{
		static_assert(div == 2 || div == 4 || div == 6 || div == 8, "P divider must be 2, 4 , 6 or 8");
		
		PLLCFGR::PLLP::Set(div / 2 - 1);
	}

	template<uint32_t div>
	static void SetPLLMQivider()
	{
		static_assert(div <= 15 && div >= 2, "Q divider must be from 2 to 15");
		
		PLLCFGR::PLLQ::Set(div);
	}
	
	static void SetPLLSourceInternalCrystal()
	{
		PLLCFGR::PLLSRC::HSI::Set();
	}

	static void SetPLLSourceExternalCrystal()
	{
		PLLCFGR::PLLSRC::HSE::Set();
	}
		
	static void PLLEnable()
	{
		CR::PLLON::ENABLED::Set();
	}

	static void PLLDisable()
	{
		CR::PLLON::DISABLED::Set();
	}
	
	static bool IsPLLReady()
	{
		bool status = true;
		
		for(uint32_t i = 0; CR::PLLRDY::UNLOCKED::IsSet(); i++)
			if(i > lock_timeout)
				status = false;
		
		return status;
	}
				
	template<uint32_t presc>
	static void SetAHBPrescaler()
	{
		static_assert(presc == 1 || presc == 2 || presc == 4 || presc == 8 || presc == 16 || presc == 64 || presc == 128 || presc == 256 || presc == 512, "AHB Prescaler must be 1, 2, 4, 8, 16, 64, 128, 256 or 512");
		
		if constexpr (presc == 1) 			CFGR::HPRE::DIV_1::Set();
		else if constexpr (presc == 2) 		CFGR::HPRE::DIV_2::Set();
		else if constexpr (presc == 4) 		CFGR::HPRE::DIV_4::Set();
		else if constexpr (presc == 8) 		CFGR::HPRE::DIV_8::Set();
		else if constexpr (presc == 16) 	CFGR::HPRE::DIV_16::Set();
		else if constexpr (presc == 64) 	CFGR::HPRE::DIV_64::Set();
		else if constexpr (presc == 128) 	CFGR::HPRE::DIV_128::Set();
		else if constexpr (presc == 256) 	CFGR::HPRE::DIV_256::Set();
		else if constexpr (presc == 512)	CFGR::HPRE::DIV_512::Set();
	}
				
	template<uint32_t presc>
	static void SetAPB1Prescaler()
	{
		static_assert(presc == 1 || presc == 2 || presc == 4 || presc == 8 || presc == 16, "AHB Prescaler must be 1, 2, 4, 8 or 16");

		if constexpr (presc == 1) 		CFGR::PPRE1::DIV_1::Set();
		else if constexpr (presc == 2) 	CFGR::PPRE1::DIV_2::Set();
		else if constexpr (presc == 4) 	CFGR::PPRE1::DIV_4::Set();
		else if constexpr (presc == 8) 	CFGR::PPRE1::DIV_8::Set();
		else if constexpr (presc == 16) CFGR::PPRE1::DIV_16::Set();

	}

	template<uint32_t presc>
	static void SetAPB2Prescaler()
	{
		static_assert(presc == 1 || presc == 2 || presc == 4 || presc == 8 || presc == 16, "AHB Prescaler must be 1, 2, 4, 8 or 16");

		if constexpr (presc == 1) 		CFGR::PPRE2::DIV_1::Set();
		else if constexpr (presc == 2) 	CFGR::PPRE2::DIV_2::Set();
		else if constexpr (presc == 4) 	CFGR::PPRE2::DIV_4::Set();
		else if constexpr (presc == 8) 	CFGR::PPRE2::DIV_8::Set();
		else if constexpr (presc == 16) CFGR::PPRE2::DIV_16::Set();
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
			if(i > lock_timeout)
				status = false;
		
		return status;
	}

	static auto SetSystemSource()
	{
		return CFGR::SWS::Get();
	}

	static auto GetPLLSource()
	{
		return PLLCFGR::PLLSRC::Get();
	}

	static auto GetPLLMDivider()
	{
		return PLLCFGR::PLLM::Get();
	}

	static auto GetPLLNMultiplier()
	{
		return PLLCFGR::PLLN::Get();
	}

	static auto GetPLLPDivider()
	{
		return (PLLCFGR::PLLP::Get() + 1) * 2;
	}

	static auto GetAHBPrescaler()
	{
		return CFGR::HPRE::Get();
	}

	static auto GetAPB1Prescaler()
	{
		return CFGR::PPRE1::Get();
	}

	static auto GetAPB2Prescaler()
	{
		return CFGR::PPRE2::Get();
	}
};