#pragma once

#include "rtc_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class RTCBase
{
private:
	// Адреса регистров.
	static constexpr auto rtc_address   	= 0x40002800;
	static constexpr auto tr_address 		= rtc_address + 0x00;
	static constexpr auto dr_address 		= rtc_address + 0x04;
	static constexpr auto cr_address 		= rtc_address + 0x08;
	static constexpr auto isr_address 		= rtc_address + 0x0C;
	static constexpr auto prep_address 		= rtc_address + 0x10;
	static constexpr auto wutr_address 		= rtc_address + 0x14;
	static constexpr auto calibr_address 	= rtc_address + 0x18;
	static constexpr auto alrmar_address 	= rtc_address + 0x1C;
	static constexpr auto alrmbr_address 	= rtc_address + 0x20;
	static constexpr auto wpr_address 		= rtc_address + 0x24;
	static constexpr auto ssr_address 		= rtc_address + 0x28;
	static constexpr auto shiftr_address 	= rtc_address + 0x2C;
	static constexpr auto tstr_address 		= rtc_address + 0x30;
	static constexpr auto tsdr_address 		= rtc_address + 0x34;
	static constexpr auto tsssr_address 	= rtc_address + 0x38;
	static constexpr auto calr_address 		= rtc_address + 0x3C;
	static constexpr auto tafcr_address 	= rtc_address + 0x40;
	static constexpr auto alrmassr_address 	= rtc_address + 0x44;
	static constexpr auto alrmbssr_address 	= rtc_address + 0x48;
	static constexpr auto bkpr_address 		= rtc_address + 0x50;
	
protected:
    struct TR: public Register<MCU, STM32F4xxxx, tr_address, 32, RW>
	{
		using SU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TR, 0, 4, RW>;
		using ST = EmptyValues<MCU, STM32F4xxxx, RTCBase::TR, 4, 3, RW>;
		using MNU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TR, 8, 4, RW>;
		using MNT = EmptyValues<MCU, STM32F4xxxx, RTCBase::TR, 12, 3, RW>;
		using HU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TR, 16, 4, RW>;
		using HT = EmptyValues<MCU, STM32F4xxxx, RTCBase::TR, 20, 2, RW>;
		using PM = EmptyValues<MCU, STM32F4xxxx, RTCBase::TR, 22, 1, RW>;
	};

	struct DR: public Register<MCU, STM32F4xxxx, tr_address, 32, RW>
	{
		using DU = EmptyValues<MCU, STM32F4xxxx, RTCBase::DR, 0, 4, RW>;
		using DT = EmptyValues<MCU, STM32F4xxxx, RTCBase::DR, 4, 2, RW>;
		using MU = EmptyValues<MCU, STM32F4xxxx, RTCBase::DR, 8, 4, RW>;
		using MT = EmptyValues<MCU, STM32F4xxxx, RTCBase::DR, 12, 1, RW>;
		using WDU = EmptyValues<MCU, STM32F4xxxx, RTCBase::DR, 13, 3, RW>;
		using YU = EmptyValues<MCU, STM32F4xxxx, RTCBase::DR, 16, 4, RW>;
		using YT = EmptyValues<MCU, STM32F4xxxx, RTCBase::DR, 20, 4, RW>;
	};

	struct CR: public Register<MCU, STM32F4xxxx, tr_address, 32, RW>
	{
		using WUCKSEL = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 0, 3, RW>;
		using TSEDGE = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 3, 1, RW>;
		using REFCKON = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 4, 2, RW>;
		using BYPSHAD = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 5, 1, RW>;
		using FMT = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 6, 1, RW>;
		using DCE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 7, 1, RW>;
		using ALRAE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 8, 1, RW>;
		using ALRBE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 9, 1, RW>;
		using WUTE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 10, 1, RW>;
		using TSE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 11, 1, RW>;
		using ALRAIE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 12, 1, RW>;
		using ALRBIE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 13, 1, RW>;
		using WUTIE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 14, 1, RW>;
		using TSIE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 15, 1, RW>;
		using ADD1H = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 16, 1, WO>;
		using SUB1H = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 17, 1, WO>;
		using BKP = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 18, 1, RW>;
		using COSEL = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 19, 1, RW>;
		using POL = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 20, 1, RW>;
		using OSEL = EmptyValues<MCU, STM32F4xxxx, RTCBase::CR, 21, 2, RW>;
		using COE = StateValues<MCU, STM32F4xxxx, RTCBase::CR, 23, 1, RW>;
	};

	struct ISR: public Register<MCU, STM32F4xxxx, isr_address, 32, RW>
	{
		using ALRAWF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 0, 1, RO>;
		using ALRBWF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 1, 1, RO>;
		using WUTWF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 2, 1, RO>;
		using SHPF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 3, 1, RO>;
		using INITS = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 4, 1, RO>;
		using RSF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 5, 1, RC_W0>;
		using INITF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 6, 1, RO>;
		using INIT = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 7, 1, RW>;
		using ALRAF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 8, 1, RC_W0>;
		using ALRBF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 9, 1, RC_W0>;
		using WUTF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 10, 1, RC_W0>;
		using TSF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 11, 1, RC_W0>;
		using TSOVF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 12, 1, RC_W0>;
		using TAMP1F = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 13, 1, RC_W0>;
		using TAMP2F = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 14, 1, RC_W0>;
		using RECALPF = EmptyValues<MCU, STM32F4xxxx, RTCBase::ISR, 16, 1, RO>;
	};

	struct PRER: public Register<MCU, STM32F4xxxx, prep_address, 32, RW>
	{
		using PREDIVS = EmptyValues<MCU, STM32F4xxxx, RTCBase::PRER, 0, 14, RW>;
		using PREDIVA = EmptyValues<MCU, STM32F4xxxx, RTCBase::PRER, 16, 7, RO>;
	};

	struct WUTR: public Register<MCU, STM32F4xxxx, wutr_address, 16, RW> {};

	struct CALIBR: public Register<MCU, STM32F4xxxx, calibr_address, 32, RW>
	{
		using DC = EmptyValues<MCU, STM32F4xxxx, RTCBase::CALIBR, 0, 5, RW>;
		using DCS = EmptyValues<MCU, STM32F4xxxx, RTCBase::CALIBR, 7, 1, RW>;
	};

	struct ALRMAR: public Register<MCU, STM32F4xxxx, alrmar_address, 32, RW>
	{
		using SU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 0, 4, RW>;
		using ST = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 3, 3, RW>;
		using MSK1 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 7, 1, RW>;
		using MNU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 8, 4, RW>;
		using MNT = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 12, 3, RW>;
		using MSK2 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 15, 1, RW>;
		using HU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 16, 4, RW>;
		using HT = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 20, 2, RW>;
		using PM = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 22, 1, RW>;
		using MSK3 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 23, 1, RW>;
		using DU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 24, 4, RW>;
		using DT = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 28, 2, RW>;
		using WDSEL = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 30, 1, RW>;
		using MSK4 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMAR, 31, 1, RW>;
	};

	struct ALRMBR: public Register<MCU, STM32F4xxxx, alrmbr_address, 32, RW>
	{
		using SU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 0, 4, RW>;
		using ST = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 3, 3, RW>;
		using MSK1 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 7, 1, RW>;
		using MNU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 8, 4, RW>;
		using MNT = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 12, 3, RW>;
		using MSK2 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 15, 1, RW>;
		using HU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 16, 4, RW>;
		using HT = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 20, 2, RW>;
		using PM = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 22, 1, RW>;
		using MSK3 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 23, 1, RW>;
		using DU = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 24, 4, RW>;
		using DT = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 28, 2, RW>;
		using WDSEL = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 30, 1, RW>;
		using MSK4 = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBR, 31, 1, RW>;
	};

	struct WPR: public Register<MCU, STM32F4xxxx, wpr_address, 8, WO>
	{
		using KEY1 = RegisterValue<MCU, STM32F4xxxx, RTCBase::WPR, 0xCA>;
		using KEY2 = RegisterValue<MCU, STM32F4xxxx, RTCBase::WPR, 0x53>;
	};


	struct SSR: public Register<MCU, STM32F4xxxx, ssr_address, 16, RO> {};

	struct SHIFTR: public Register<MCU, STM32F4xxxx, shiftr_address, 32, RW>
	{
		using SUBFS = EmptyValues<MCU, STM32F4xxxx, RTCBase::SHIFTR, 0, 14, RO>;
		using ADD1S = EmptyValues<MCU, STM32F4xxxx, RTCBase::SHIFTR, 31, 1, WO>;
	};

	struct TSTR: public Register<MCU, STM32F4xxxx, tstr_address, 32, RO>
	{
		using SU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSTR, 0, 4, RO>;
		using ST = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSTR, 3, 3, RO>;
		using MNU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSTR, 8, 4, RO>;
		using MNT = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSTR, 12, 3, RO>;
		using HU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSTR, 16, 4, RO>;
		using HT = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSTR, 20, 2, RO>;
		using PM = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSTR, 22, 1, RO>;
	};

	struct TSDR: public Register<MCU, STM32F4xxxx, tsdr_address, 32, RO>
	{
		using DU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 0, 4, RO>;
		using DT = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 4, 2, RO>;
		using MU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 8, 4, RO>;
		using MT = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 12, 1, RO>;
		using WDU = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 13, 3, RO>;
	};

	struct TSSSR: public Register<MCU, STM32F4xxxx, tsssr_address, 16, RO> {};

	struct CALR: public Register<MCU, STM32F4xxxx, calr_address, 32, RW>
	{
		using CALM = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 0, 9, RW>;
		using CALW16 = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 13, 1, RW>;
		using CALW8 = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 14, 1, RW>;
		using CALP = EmptyValues<MCU, STM32F4xxxx, RTCBase::TSDR, 15, 1, RW>;
	};

	struct TAFCR: public Register<MCU, STM32F4xxxx, tafcr_address, 32, RW>
	{
		using TAMP1E = StateValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 0, 1, RW>;
		using TAMP1TRG = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 1, 1, RW>;
		using TAMPIE = StateValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 2, 1, RW>;
		using TAMP2E = StateValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 4, 1, RW>;
		using TAMP2TRG = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 4, 1, RW>;
		using TAMPTS = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 7, 1, RW>;
		using TAMPFREQ = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 8, 3, RW>;
		using TAMPFLT = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 11, 2, RW>;
		using TAMPPRCH = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 13, 1, RW>;
		using TAMPPUDIS = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 15, 1, RW>;
		using TAMP1INSEL = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 16, 1, RW>;
		using TSINSEL = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 17, 1, RW>;
		using ALARMOUTTYPE = EmptyValues<MCU, STM32F4xxxx, RTCBase::TAFCR, 18, 1, RW>;
	};

	struct ALRMASSR: public Register<MCU, STM32F4xxxx, alrmassr_address, 32, RW>
	{
		using SS = StateValues<MCU, STM32F4xxxx, RTCBase::ALRMASSR, 0, 14, RW>;
		using MASKSS = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMASSR, 24, 4, RW>;
	};

	struct ALRMBSSR: public Register<MCU, STM32F4xxxx, alrmbssr_address, 32, RW>
	{
		using SS = StateValues<MCU, STM32F4xxxx, RTCBase::ALRMBSSR, 0, 14, RW>;
		using MASKSS = EmptyValues<MCU, STM32F4xxxx, RTCBase::ALRMBSSR, 24, 4, RW>;
	};

	inline static uint32_t* BKPR = (uint32_t *)(bkpr_address);
};