#pragma once

#include "common_field_values.hpp"

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_MODER_MODER_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using INPUT = FieldValue<MCU, Series, GPIO_MODER_MODER_VALUES, 0>;
	using OUTPUT = FieldValue<MCU, Series, GPIO_MODER_MODER_VALUES, 1>;
	using ALTFUNCTION = FieldValue<MCU, Series, GPIO_MODER_MODER_VALUES, 2>;
	using ANALOG = FieldValue<MCU, Series, GPIO_MODER_MODER_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_OTYPER_OT_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using PUSHPULL = FieldValue<MCU, Series, GPIO_OTYPER_OT_VALUES, 0>;
	using OPENDRAIN = FieldValue<MCU, Series, GPIO_OTYPER_OT_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_OSPEEDR_OSPEEDR_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using LOW = FieldValue<MCU, Series, GPIO_OSPEEDR_OSPEEDR_VALUES, 0>;
	using MEDIUM = FieldValue<MCU, Series, GPIO_OSPEEDR_OSPEEDR_VALUES, 1>;
	using HIGH = FieldValue<MCU, Series, GPIO_OSPEEDR_OSPEEDR_VALUES, 2>;
	using VERYHIGH = FieldValue<MCU, Series, GPIO_OSPEEDR_OSPEEDR_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_PUPDR_PUPDR_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using NOPULL = FieldValue<MCU, Series, GPIO_PUPDR_PUPDR_VALUES, 0>;
	using PULLUP = FieldValue<MCU, Series, GPIO_PUPDR_PUPDR_VALUES, 1>;
	using PULLDOWN = FieldValue<MCU, Series, GPIO_PUPDR_PUPDR_VALUES, 2>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_IODR_IODR_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using LOW = FieldValue<MCU, Series, GPIO_IODR_IODR_VALUES, 0>;
	using HIGH = FieldValue<MCU, Series, GPIO_IODR_IODR_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_BSRR_BS_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using HIGH = FieldValue<MCU, Series, GPIO_BSRR_BS_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_BSRR_BR_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using LOW = FieldValue<MCU, Series, GPIO_BSRR_BR_VALUES, 0>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct GPIO_AFR_AFR_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using AF0 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 0>;
	using AF1 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 1>;
	using AF2 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 2>;
	using AF3 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 3>;
	using AF4 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 4>;
	using AF5 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 5>;
	using AF6 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 6>;
	using AF7 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 7>;
	using AF8 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 8>;
	using AF9 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 9>;
	using AF10 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 10>;
	using AF11 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 11>;
	using AF12 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 12>;
	using AF13 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 13>;
	using AF14 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 14>;
	using AF15 = FieldValue<MCU, Series, GPIO_AFR_AFR_VALUES, 15>;
};