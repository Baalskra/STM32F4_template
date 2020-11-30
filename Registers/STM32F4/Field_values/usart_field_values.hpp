#pragma once

#include "common_field_values.hpp"

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR1_RWU_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using ACTIVE = FieldValue<MCU, Series, USART_CR1_RWU_VALUES, 0>;
	using MUTE = FieldValue<MCU, Series, USART_CR1_RWU_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR1_PS_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using EVEN = FieldValue<MCU, Series, USART_CR1_PS_VALUES, 0>;
	using ODD = FieldValue<MCU, Series, USART_CR1_PS_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR1_WAKE_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using IDLE = FieldValue<MCU, Series, USART_CR1_WAKE_VALUES, 0>;
	using ADDRESS = FieldValue<MCU, Series, USART_CR1_WAKE_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR1_LEN_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using DATA_8 = FieldValue<MCU, Series, USART_CR1_LEN_VALUES, 0>;
	using DATA_9 = FieldValue<MCU, Series, USART_CR1_LEN_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR1_OVER_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using OVER_16 = FieldValue<MCU, Series, USART_CR1_OVER_VALUES, 0>;
	using OVER_8 = FieldValue<MCU, Series, USART_CR1_OVER_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR2_LBDL_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using BIT_10 = FieldValue<MCU, Series, USART_CR2_LBDL_VALUES, 0>;
	using BIT_11 = FieldValue<MCU, Series, USART_CR2_LBDL_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR2_LBCL_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using OUTPUT = FieldValue<MCU, Series, USART_CR2_LBCL_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR2_CPHA_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using FIRST = FieldValue<MCU, Series, USART_CR2_CPHA_VALUES, 0>;
	using SECOND = FieldValue<MCU, Series, USART_CR2_CPHA_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR2_CPOL_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using LOW = FieldValue<MCU, Series, USART_CR2_CPOL_VALUES, 0>;
	using HIGH = FieldValue<MCU, Series, USART_CR2_CPOL_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR2_STOP_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using BIT_1 = FieldValue<MCU, Series, USART_CR2_STOP_VALUES, 0>;
	using BIT_0_5 = FieldValue<MCU, Series, USART_CR2_STOP_VALUES, 1>;
	using BIT_2 = FieldValue<MCU, Series, USART_CR2_STOP_VALUES, 2>;
	using BIT_1_5 = FieldValue<MCU, Series, USART_CR2_STOP_VALUES, 3>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct UART_CR2_STOP_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using BIT_1 = FieldValue<MCU, Series, UART_CR2_STOP_VALUES, 0>;
	using BIT_2 = FieldValue<MCU, Series, UART_CR2_STOP_VALUES, 2>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR3_IRPL_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using NORMAL = FieldValue<MCU, Series, USART_CR3_IRPL_VALUES, 0>;
	using LOWPOWER = FieldValue<MCU, Series, USART_CR3_IRPL_VALUES, 1>;
};

template<typename MCU, typename Series, typename Resister, size_t offset, size_t size, typename AccessMode>
struct USART_CR3_ONEBIT_VALUES: public Field<MCU, Series, Resister, offset, size, AccessMode>
{
	using THREE = FieldValue<MCU, Series, USART_CR3_ONEBIT_VALUES, 0>;
	using ONE = FieldValue<MCU, Series, USART_CR3_ONEBIT_VALUES, 1>;
};
