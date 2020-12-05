#pragma once

#include "rng_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class RNGBase
{
	RNGBase() = delete;
	
private:
	// Адреса регистров.
	static constexpr auto rng_address   = 0x50060800;
	static constexpr auto cr_address 	= rng_address + 0x00;
	static constexpr auto sr_address 	= rng_address + 0x04;
	static constexpr auto dr_address 	= rng_address + 0x08;
	
protected:
    struct CR: public Register<MCU, STM32F4xxxx, cr_address, 16, RW>
	{
		using RNGEN = StateValues<MCU, STM32F4xxxx, RNGBase::CR, 2, 1, RW>;
		using IE = StateValues<MCU, STM32F4xxxx, RNGBase::CR, 3, 1, RW>;
	};

    struct SR: public Register<MCU, STM32F4xxxx, sr_address, 16, RW>
	{
		using DRDY = StatusValues<MCU, STM32F4xxxx, RNGBase::SR, 0, 1, RO>;
		using CECS = EmptyValues<MCU, STM32F4xxxx, RNGBase::SR, 1, 1, RO>;
        using SECS = EmptyValues<MCU, STM32F4xxxx, RNGBase::SR, 2, 1, RO>;
        using CEIS = EmptyValues<MCU, STM32F4xxxx, RNGBase::SR, 5, 1, RC_W0>;
        using SEIS = EmptyValues<MCU, STM32F4xxxx, RNGBase::SR, 6, 1, RC_W0>;
	};

    struct DR: public Register<MCU, STM32F4xxxx, dr_address, 32, RW> {};
};