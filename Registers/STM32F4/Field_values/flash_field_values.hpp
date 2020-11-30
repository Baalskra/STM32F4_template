#pragma once

#include "common_field_values.hpp"

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_ACR_LATENCY_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using WS_0 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 0>;
	using WS_1 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 1>;
	using WS_2 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 2>;
	using WS_3 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 3>;
	using WS_4 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 4>;
	using WS_5 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 5>;
	using WS_6 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 6>;
	using WS_7 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 7>;
	using WS_8 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 8>;
	using WS_9 = FieldValue<MCU, Series, FLASH_ACR_LATENCY_VALUES, 9>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_SR_BSY_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using FREE = FieldValue<MCU, Series, FLASH_SR_BSY_VALUES, 0>;
	using BUZY = FieldValue<MCU, Series, FLASH_SR_BSY_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_CR_PSIZE_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using PROG8 = FieldValue<MCU, Series, FLASH_CR_PSIZE_VALUES, 0>;
	using PROG16 = FieldValue<MCU, Series, FLASH_CR_PSIZE_VALUES, 0>;
	using PROG32 = FieldValue<MCU, Series, FLASH_CR_PSIZE_VALUES, 0>;
	using PROG64 = FieldValue<MCU, Series, FLASH_CR_PSIZE_VALUES, 0>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_OPTCR_BORLEV_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using BOR3 = FieldValue<MCU, Series, FLASH_OPTCR_BORLEV_VALUES, 0>;
	using BOR2 = FieldValue<MCU, Series, FLASH_OPTCR_BORLEV_VALUES, 1>;
	using BOR1 = FieldValue<MCU, Series, FLASH_OPTCR_BORLEV_VALUES, 2>;
	using BOROFF = FieldValue<MCU, Series, FLASH_OPTCR_BORLEV_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_OPTCR_WDGSW_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using HARDWARE = FieldValue<MCU, Series, FLASH_OPTCR_WDGSW_VALUES, 0>;
	using SOFTWARE = FieldValue<MCU, Series, FLASH_OPTCR_WDGSW_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_OPTCR_RST_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using GENERATED = FieldValue<MCU, Series, FLASH_OPTCR_RST_VALUES, 0>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_OPTCR_RDP_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using UNPROTECTED = FieldValue<MCU, Series, FLASH_OPTCR_RDP_VALUES, 0xAA>;
	using MEMORYPROTECTED = FieldValue<MCU, Series, FLASH_OPTCR_RDP_VALUES, 0xBB>;
	using FULLPROTECTED = FieldValue<MCU, Series, FLASH_OPTCR_RDP_VALUES, 0xCC>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct FLASH_OPTCR_DB1M_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using SINGLE = FieldValue<MCU, Series, FLASH_OPTCR_DB1M_VALUES, 0>;
	using DUAL = FieldValue<MCU, Series, FLASH_OPTCR_DB1M_VALUES, 1>;
};