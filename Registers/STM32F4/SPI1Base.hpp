#pragma once

#include "spi_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class SPI1Base
{
    SPI1Base() = delete;

private:
	static constexpr auto spi_address   	= 0x40013000;
	static constexpr auto cr1_address 	    = spi_address + 0x00;
	static constexpr auto cr2_address 		= spi_address + 0x04;
	static constexpr auto sr_address 	    = spi_address + 0x08;
	static constexpr auto dr_address 	    = spi_address + 0x0C;
	static constexpr auto crcpr_address 	= spi_address + 0x10;
	static constexpr auto rxcrcr_address 	= spi_address + 0x14;
	static constexpr auto txcrcr_address 	= spi_address + 0x18;
	
protected:
	struct CR1: public Register<MCU, STM32F4xxxx, cr1_address, 16, RW>
	{
		using CPHA = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 0, 1, RW>;
        using CPOL = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 1, 1, RW>;
        using MSTR = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 2, 1, RW>;
        using BR = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 3, 3, RW>;
        using SPE = StateValues<MCU, STM32F4xxxx, SPI1Base::CR1, 6, 1, RW>;
        using LSBFIRST = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 7, 1, RW>;
        using SSI = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 8, 1, RW>;
        using SSM = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 9, 1, RW>;
        using RXONLY = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 10, 1, RW>;
        using DFF = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 11, 1, RW>;
        using CRCNEXT = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 12, 1, RW>;
        using CRCEN = StateValues<MCU, STM32F4xxxx, SPI1Base::CR1, 13, 1, RW>;
        using BIDIOE = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 14, 1, RW>;
        using BIDIMODE = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR1, 15, 1, RW>;
	};

    struct CR2: public Register<MCU, STM32F4xxxx, cr2_address, 16, RW>
	{
		using RXDMAEN = StateValues<MCU, STM32F4xxxx, SPI1Base::CR2, 0, 1, RW>;
        using TXDMAEN = StateValues<MCU, STM32F4xxxx, SPI1Base::CR2, 1, 1, RW>;
        using SSOE = StateValues<MCU, STM32F4xxxx, SPI1Base::CR2, 2, 1, RW>;
        using FRF = EmptyValues<MCU, STM32F4xxxx, SPI1Base::CR2, 3, 1, RW>;
        using ERRIE = StateValues<MCU, STM32F4xxxx, SPI1Base::CR2, 5, 1, RW>;
        using RXNEIE = StateValues<MCU, STM32F4xxxx, SPI1Base::CR2, 6, 1, RW>;
        using TXEIE = StateValues<MCU, STM32F4xxxx, SPI1Base::CR2, 7, 1, RW>;
	};

    struct SR: public Register<MCU, STM32F4xxxx, sr_address, 16, RW>
	{
		using RXNE = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 0, 1, RO>;
        using TXE = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 1, 1, RO>;
        using CHSIDE = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 2, 1, RO>;
        using UDR = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 3, 1, RO>;
        using CRCERR = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 4, 1, RC_W0>;
        using MODF = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 5, 1, RO>;
        using OVR = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 6, 1, RO>;
        using BSY = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 7, 1, RO>;
        using FRE = EmptyValues<MCU, STM32F4xxxx, SPI1Base::SR, 8, 1, RO>;
	};

    struct DR: public Register<MCU, STM32F4xxxx, dr_address, 16, RW> {};

    struct CRCPR: public Register<MCU, STM32F4xxxx, crcpr_address, 16, RW> {};

    struct RXCRCR: public Register<MCU, STM32F4xxxx, rxcrcr_address, 16, RO> {};

    struct TXCRCR: public Register<MCU, STM32F4xxxx, txcrcr_address, 16, RO> {};
};