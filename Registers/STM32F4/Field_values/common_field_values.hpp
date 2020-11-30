#pragma once

#include "Field.hpp"
#include "FieldValue.hpp"

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct StateValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using DISABLED = FieldValue<MCU, Series, StateValues, 0>;
	using ENABLED = FieldValue<MCU, Series, StateValues, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct StatusValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using READY = FieldValue<MCU, Series, StatusValues, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct EmptyValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct ResetValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using RELEASE = FieldValue<MCU, Series, ResetValues, 0>;
	using RESET = FieldValue<MCU, Series, ResetValues, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct LockValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using UNLOCKED = FieldValue<MCU, Series, LockValues, 0>;
	using LOCKED = FieldValue<MCU, Series, LockValues, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct ErrorValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using ERROR = FieldValue<MCU, Series, ErrorValues, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct DetectValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using DETECTED = FieldValue<MCU, Series, DetectValues, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct TransmitValues: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using TRANSMITTED = FieldValue<MCU, Series, TransmitValues, 1>;
};