#pragma once

#include "MCUs.hpp"
#include "FLASHBase.hpp"

class FLASH: protected FLASHBase<Target>
{
	FLASH() = delete;

protected:
	template<uint8_t latency>
	static void SetLatency()
	{
		static_assert(latency <= 7, "Latency must be less or equal 7");

		ACR::LATENCY::Set(latency);
	}
	
	static void DataCacheEnable()
	{
		ACR::DCEN::ENABLED::Set();
	}

	static void DataCacheDisable()
	{
		ACR::DCEN::DISABLED::Set();
	}
	
	static void InstructionCacheEnable()
	{
		ACR::ICEN::ENABLED::Set();
	}

	static void InstructionCacheDisable()
	{
		ACR::ICEN::DISABLED::Set();
	}
	
	static void PrefetchEnable()
	{
		ACR::PRFTBEN::ENABLED::Set();
	}

	static void PrefetchDisable()
	{
		ACR::PRFTBEN::DISABLED::Set();
	}

};