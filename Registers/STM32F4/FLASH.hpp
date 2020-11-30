#pragma once

#include "MCUs.hpp"
#include "Voltage.hpp"
#include "FLASHBase.hpp"

class FLASH: protected FLASHBase<Target>
{
	FLASH() = delete;

protected:
	template<uint8_t latency>
	static void SetLatency()
	{
		FLASH::ACR::LATENCY::Set(latency);
	}
	
	static void DataCacheEnable()
	{
		FLASH::ACR::DCEN::ENABLED::Set();
	}
	
	static void InstructionCacheEnable()
	{
		FLASH::ACR::ICEN::ENABLED::Set();
	}
	
	static void PrefetchEnable()
	{
		FLASH::ACR::PRFTBEN::ENABLED::Set();
	}

};