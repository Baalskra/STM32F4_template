#pragma once

#include "usart_field_values.hpp"
#include "Register.hpp"

template<typename MCU>
class UART4Base
{
	UART4Base() = delete;

private:
	// Адреса регистров.
	static constexpr uint32_t usart_address = 0x40004C00;
	static constexpr uint32_t sr_address 	= usart_address + 0x00;
	static constexpr uint32_t dr_address 	= usart_address + 0x04;
	static constexpr uint32_t brr_address 	= usart_address + 0x08;
	static constexpr uint32_t cr1_address 	= usart_address + 0x0C;
	static constexpr uint32_t cr2_address 	= usart_address + 0x10;
	static constexpr uint32_t cr3_address 	= usart_address + 0x14;

protected:
	struct SR: public Register<MCU, STM32F4xxxx, sr_address, 16, RW>
	{
		using PE = ErrorValues<MCU, STM32F4xxxx, UART4Base::SR, 0, 1, RO>;
		using FE = ErrorValues<MCU, STM32F4xxxx, UART4Base::SR, 1, 1, RO>;
		using NF = DetectValues<MCU, STM32F4xxxx, UART4Base::SR, 2, 1, RO>;
		using ORE = ErrorValues<MCU, STM32F4xxxx, UART4Base::SR, 3, 1, RO>;
		using IDLE = DetectValues<MCU, STM32F4xxxx, UART4Base::SR, 4, 1, RO>;
		using RXNE = Field<MCU, STM32F4xxxx, UART4Base::SR, 5, 1, RC_W0>;
		using TC = Field<MCU, STM32F4xxxx, UART4Base::SR, 6, 1, RC_W0>;
		using TXE = TransmitValues<MCU, STM32F4xxxx, UART4Base::SR, 7, 1, RO>;
		using LBD = Field<MCU, STM32F4xxxx, UART4Base::SR, 8, 1, RC_W0>;
	};
	
	struct DR: public Register<MCU, STM32F4xxxx, dr_address, 16, RW>
	{
	};
	
	struct BRR: public Register<MCU, STM32F4xxxx, brr_address, 16, RW>
	{
		using FRACTION = EmptyValues<MCU, STM32F4xxxx, UART4Base::BRR, 0, 4, RW>;
		using MANTISSA = EmptyValues<MCU, STM32F4xxxx, UART4Base::BRR, 4, 12, RW>;
	};
	
	struct CR1: public Register<MCU, STM32F4xxxx, cr1_address, 16, RW>
	{
		using SBK = TransmitValues<MCU, STM32F4xxxx, UART4Base::CR1, 0, 1, RW>;
		using RWU = USART_CR1_RWU_VALUES<MCU, STM32F4xxxx, UART4Base::CR1, 1, 1, RW>;
		using RE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 2, 1, RW>;
		using TE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 3, 1, RW>;
		using IDLEIE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 4, 1, RW>;
		using RXNEIE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 5, 1, RW>;
		using TCIE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 6, 1, RW>;
		using TXEIE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 7, 1, RW>;
		using PEIE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 8, 1, RW>;
		using PS = USART_CR1_PS_VALUES<MCU, STM32F4xxxx, UART4Base::CR1, 9, 1, RW>;
		using PCE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 10, 1, RW>;
		using WAKE = USART_CR1_WAKE_VALUES<MCU, STM32F4xxxx, UART4Base::CR1, 11, 1, RW>;
		using LEN = USART_CR1_LEN_VALUES<MCU, STM32F4xxxx, UART4Base::CR1, 12, 1, RW>;
		using UE = StateValues<MCU, STM32F4xxxx, UART4Base::CR1, 13, 1, RW>;
		using OVER = USART_CR1_OVER_VALUES<MCU, STM32F4xxxx, UART4Base::CR1, 15, 1, RW>;
	};
	
	struct CR2: public Register<MCU, STM32F4xxxx, cr2_address, 16, RW>
	{
		using ADD = EmptyValues<MCU, STM32F4xxxx, UART4Base::CR2, 0, 4, RW>;
		using LBDL = USART_CR2_LBDL_VALUES<MCU, STM32F4xxxx, UART4Base::CR2, 5, 1, RW>;
		using LBDIE = StateValues<MCU, STM32F4xxxx, UART4Base::CR2, 6, 1, RW>;
		using STOP = UART_CR2_STOP_VALUES<MCU, STM32F4xxxx, UART4Base::CR2, 12, 2, RW>;
		using LINEN = StateValues<MCU, STM32F4xxxx, UART4Base::CR2, 14, 1, RW>;
	};
	
	struct CR3: public Register<MCU, STM32F4xxxx, cr3_address, 16, RW>
	{
		using EIE = StateValues<MCU, STM32F4xxxx, UART4Base::CR3, 0, 1, RW>;
		using IREN = StateValues<MCU, STM32F4xxxx, UART4Base::CR3, 1, 1, RW>;
		using IRPL = USART_CR3_IRPL_VALUES<MCU, STM32F4xxxx, UART4Base::CR3, 2, 1, RW>;
		using HDSEL = StateValues<MCU, STM32F4xxxx, UART4Base::CR3, 3, 1, RW>;
		using DMAR = StateValues<MCU, STM32F4xxxx, UART4Base::CR3, 6, 1, RW>;
		using DMAT = StateValues<MCU, STM32F4xxxx, UART4Base::CR3, 7, 1, RW>;
		using ONEBIT = USART_CR3_ONEBIT_VALUES<MCU, STM32F4xxxx, UART4Base::CR3, 11, 1, RW>;
	};
};