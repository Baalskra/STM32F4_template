#pragma once

#include "common_field_values.hpp"

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_BYP_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using BYPASSED = FieldValue<MCU, Series, RCC_BYP_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_PLLCFGR_PLLP_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using DIV_2 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLP_VALUES, 0>;
	using DIV_4 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLP_VALUES, 1>;
	using DIV_6 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLP_VALUES, 2>;
	using DIV_8 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLP_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_PLLCFGR_PLLSRC_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using HSI = FieldValue<MCU, Series, RCC_PLLCFGR_PLLSRC_VALUES, 0>;
	using HSE = FieldValue<MCU, Series, RCC_PLLCFGR_PLLSRC_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_PLLCFGR_PLLQ_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using DIV_2 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 2>;
	using DIV_3 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 3>;
	using DIV_4 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 4>;
	using DIV_5 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 5>;
	using DIV_6 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 6>;
	using DIV_7 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 7>;
	using DIV_8 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 8>;
	using DIV_9 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 9>;
	using DIV_10 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 10>;
	using DIV_11 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 11>;
	using DIV_12 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 12>;
	using DIV_13 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 13>;
	using DIV_14 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 14>;
	using DIV_15 = FieldValue<MCU, Series, RCC_PLLCFGR_PLLQ_VALUES, 15>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CFGR_SW_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using HSI = FieldValue<MCU, Series, RCC_CFGR_SW_VALUES, 0>;
	using HSE = FieldValue<MCU, Series, RCC_CFGR_SW_VALUES, 1>;
	using PLL = FieldValue<MCU, Series, RCC_CFGR_SW_VALUES, 2>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CFGR_HPRE_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using DIV_1 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 0>;
	using DIV_2 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 8>;
	using DIV_4 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 9>;
	using DIV_8 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 10>;
	using DIV_16 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 11>;
	using DIV_64 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 12>;
	using DIV_128 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 13>;
	using DIV_256 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 14>;
	using DIV_512 = FieldValue<MCU, Series, RCC_CFGR_HPRE_VALUES, 15>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CFGR_PPRE_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using DIV_1 = FieldValue<MCU, Series, RCC_CFGR_PPRE_VALUES, 0>;
	using DIV_2 = FieldValue<MCU, Series, RCC_CFGR_PPRE_VALUES, 4>;
	using DIV_4 = FieldValue<MCU, Series, RCC_CFGR_PPRE_VALUES, 5>;
	using DIV_8 = FieldValue<MCU, Series, RCC_CFGR_PPRE_VALUES, 6>;
	using DIV_16 = FieldValue<MCU, Series, RCC_CFGR_PPRE_VALUES, 7>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CFGR_MCO1_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using HSI = FieldValue<MCU, Series, RCC_CFGR_MCO1_VALUES, 0>;
	using LSE = FieldValue<MCU, Series, RCC_CFGR_MCO1_VALUES, 1>;
	using HSE = FieldValue<MCU, Series, RCC_CFGR_MCO1_VALUES, 2>;
	using PLL = FieldValue<MCU, Series, RCC_CFGR_MCO1_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CFGR_I2SSRC_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using PLLI2S = FieldValue<MCU, Series, RCC_CFGR_I2SSRC_VALUES, 0>;
	using EXTERNAL = FieldValue<MCU, Series, RCC_CFGR_I2SSRC_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CFGR_MCOPRE_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using DIV_1 = FieldValue<MCU, Series, RCC_CFGR_MCOPRE_VALUES, 0>;
	using DIV_2 = FieldValue<MCU, Series, RCC_CFGR_MCOPRE_VALUES, 4>;
	using DIV_3 = FieldValue<MCU, Series, RCC_CFGR_MCOPRE_VALUES, 5>;
	using DIV_4 = FieldValue<MCU, Series, RCC_CFGR_MCOPRE_VALUES, 6>;
	using DIV_5 = FieldValue<MCU, Series, RCC_CFGR_MCOPRE_VALUES, 7>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CFGR_MCO2_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using SYSCLK = FieldValue<MCU, Series, RCC_CFGR_MCO2_VALUES, 0>;
	using PLLI2S = FieldValue<MCU, Series, RCC_CFGR_MCO2_VALUES, 1>;
	using HSE = FieldValue<MCU, Series, RCC_CFGR_MCO2_VALUES, 2>;
	using PLL = FieldValue<MCU, Series, RCC_CFGR_MCO2_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_BDCR_RTCSEL_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using NOCLOCK = FieldValue<MCU, Series, RCC_BDCR_RTCSEL_VALUES, 0>;
	using LSE = FieldValue<MCU, Series, RCC_BDCR_RTCSEL_VALUES, 1>;
	using LSI = FieldValue<MCU, Series, RCC_BDCR_RTCSEL_VALUES, 2>;
	using HSEDIV = FieldValue<MCU, Series, RCC_BDCR_RTCSEL_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_CSR_OCCUR_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using OCCURED = FieldValue<MCU, Series, RCC_CSR_OCCUR_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, size_t offset, size_t size, typename AccessMode>
struct RCC_SSCGR_SPREADSEL_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using CENTER = FieldValue<MCU, Series, RCC_SSCGR_SPREADSEL_VALUES, 0>;
	using DOWN = FieldValue<MCU, Series, RCC_SSCGR_SPREADSEL_VALUES, 1>;
};