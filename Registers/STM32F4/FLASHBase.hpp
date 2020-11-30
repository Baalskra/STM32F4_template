#pragma once

#include "flash_field_values.hpp"
#include "Register.hpp"
#include "RegisterValue.hpp"

template<typename MCU>
class FLASHBase
{
private:
	// Адреса регистров.
	static constexpr auto flash_address 		= 0x40023C00;
	static constexpr auto acr_address 			= flash_address + 0x00;
	static constexpr auto keyr_address 			= flash_address + 0x04;
	static constexpr auto optkeyr_address 		= flash_address + 0x08;
	static constexpr auto sr_address 			= flash_address + 0x0C;
	static constexpr auto cr_address 			= flash_address + 0x10;
	static constexpr auto optcr_address 		= flash_address + 0x14;
	static constexpr auto optcr1_address 		= flash_address + 0x18;
	
public:
	struct ACR: public Register<MCU, STM32F4xxxx, acr_address, 32, RW>
	{
		using LATENCY = FLASH_ACR_LATENCY_VALUES<MCU, STM32F4xxxx, FLASHBase::ACR, 0, 4, RW>;
		using PRFTBEN = StateValues<MCU, STM32F4xxxx, FLASHBase::ACR, 8, 1, RW>;
		using ICEN = StateValues<MCU, STM32F4xxxx, FLASHBase::ACR, 9, 1, RW>;
		using DCEN = StateValues<MCU, STM32F4xxxx, FLASHBase::ACR, 10, 1, RW>;
		using ICRST = ResetValues<MCU, STM32F4xxxx, FLASHBase::ACR, 11, 1, WO>;
		using DCRST = ResetValues<MCU, STM32F4xxxx, FLASHBase::ACR, 12, 1, RW>;
	};
	
	struct KEYR: public Register<MCU, STM32F4xxxx, keyr_address, 32, WO>
	{
		using KEY1 = RegisterValue<MCU, STM32F4xxxx, FLASHBase::KEYR, 0x45670123>;
		using KEY2 = RegisterValue<MCU, STM32F4xxxx, FLASHBase::KEYR, 0xCDEF89AB>;
	};
	
	struct OPTKEYR: public Register<MCU, STM32F4xxxx, optkeyr_address, 32, WO>
	{
		using KEY1 = RegisterValue<MCU, STM32F4xxxx, FLASHBase::OPTKEYR, 0x08192A3B>;
		using KEY2 = RegisterValue<MCU, STM32F4xxxx, FLASHBase::OPTKEYR, 0x4C5D6E7F>;
	};
	
	struct SR: public Register<MCU, STM32F4xxxx, sr_address, 32, RW>
	{
		using EOP = Field<MCU, STM32F4xxxx, FLASHBase::SR, 0, 1, RC_W1>;
		using OPERR = Field<MCU, STM32F4xxxx, FLASHBase::SR, 1, 1, RC_W1>;
		using WRPERR = Field<MCU, STM32F4xxxx, FLASHBase::SR, 4, 1, RC_W1>;
		using PGAERR = Field<MCU, STM32F4xxxx, FLASHBase::SR, 5, 1, RC_W1>;
		using PGPERR = Field<MCU, STM32F4xxxx, FLASHBase::SR, 6, 1, RC_W1>;
		using PGSERR = Field<MCU, STM32F4xxxx, FLASHBase::SR, 7, 1, RC_W1>;
		using RDERR = Field<MCU, STM32F42_43xxx, FLASHBase::SR, 8, 1, RC_W1>;
		using BSY = FLASH_SR_BSY_VALUES<MCU, STM32F4xxxx, FLASHBase::SR, 16, 1, RO>;
	};
	
	struct CR: public Register<MCU, STM32F4xxxx, cr_address, 32, RW>
	{
		using PG = StateValues<MCU, STM32F4xxxx, FLASHBase::CR, 0, 1, RW>;
		using SER = StateValues<MCU, STM32F4xxxx, FLASHBase::CR, 1, 1, RW>;
		using MER = StateValues<MCU, STM32F4xxxx, FLASHBase::CR, 2, 1, RW>;
		using SNB = EmptyValues<MCU, STM32F4xxxx, FLASHBase::CR, 3, 5, RW>;
		using PSIZE = FLASH_CR_PSIZE_VALUES<MCU, STM32F4xxxx, FLASHBase::CR, 8, 2, RW>;
		using MER1 = StateValues<MCU, STM32F42_43xxx, FLASHBase::CR, 15, 1, RW>;
		using STRT = Field<MCU, STM32F4xxxx, FLASHBase::CR, 16, 1, RS>;
		using EOPIE = StateValues<MCU, STM32F4xxxx, FLASHBase::CR, 24, 1, RW>;
		using ERRIE = StateValues<MCU, STM32F4xxxx, FLASHBase::CR, 25, 1, RW>;
		using LOCK = LockValues<MCU, STM32F4xxxx, FLASHBase::CR, 31, 1, RW>;
	};
	
	struct OPTCR: public Register<MCU, STM32F4xxxx, optcr_address, 32, RW>
	{
		using OPTLOCK = Field<MCU, STM32F4xxxx, FLASHBase::OPTCR, 0, 1, RS>;
		using OPTSTRT = Field<MCU, STM32F4xxxx, FLASHBase::OPTCR, 1, 1, RS>;
		using BORLEV = FLASH_OPTCR_BORLEV_VALUES<MCU, STM32F4xxxx, FLASHBase::OPTCR, 2, 2, RW>;
		using BFB2 = StateValues<MCU, STM32F42_43xxx, FLASHBase::OPTCR, 4, 1, RW>;
		using WDGSW = FLASH_OPTCR_WDGSW_VALUES<MCU, STM32F4xxxx, FLASHBase::OPTCR, 5, 1, RW>;
		using RSTSTOP = FLASH_OPTCR_RST_VALUES<MCU, STM32F4xxxx, FLASHBase::OPTCR, 6, 1, RW>;
		using RSTSTBY = FLASH_OPTCR_RST_VALUES<MCU, STM32F4xxxx, FLASHBase::OPTCR, 7, 1, RW>;
		using RDP = FLASH_OPTCR_RDP_VALUES<MCU, STM32F4xxxx, FLASHBase::OPTCR, 8, 8, RW>;
		using WRP = EmptyValues<MCU, STM32F4xxxx, FLASHBase::OPTCR, 16, 12, RW>;
		using DB1M = FLASH_OPTCR_DB1M_VALUES<MCU, STM32F42_43xxx, FLASHBase::OPTCR, 30, 1, RW>;
		using SPRMOD = StateValues<MCU, STM32F42_43xxx, FLASHBase::OPTCR, 31, 1, RW>;
	};
	
	struct OPTCR1: public Register<MCU, STM32F42_43xxx, optcr1_address, 32, RW>
	{
		using WRP = EmptyValues<MCU, STM32F42_43xxx, FLASHBase::OPTCR, 16, 12, RW>;
	};
};