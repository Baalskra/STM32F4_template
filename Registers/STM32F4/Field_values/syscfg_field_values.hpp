#pragma once

#include "common_field_values.hpp"

template<typename MCU, typename Series, typename Register, std::size_t offset, std::size_t size, typename AccessMode>
struct SYSCFG_MEMRMP_MEMMODE_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using MAIN = FieldValue<MCU, Series, SYSCFG_MEMRMP_MEMMODE_VALUES, 0>;
	using SYSTEM = FieldValue<MCU, Series, SYSCFG_MEMRMP_MEMMODE_VALUES, 1>;
	using FSMC = FieldValue<MCU, Series, SYSCFG_MEMRMP_MEMMODE_VALUES, 2>;
	using EMBEDDED = FieldValue<MCU, Series, SYSCFG_MEMRMP_MEMMODE_VALUES, 3>;
};

template<typename MCU, typename Series, typename Register, std::size_t offset, std::size_t size, typename AccessMode>
struct SYSCFG_PMC_IISEL_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using MII = FieldValue<MCU, Series, SYSCFG_PMC_IISEL_VALUES, 0>;
	using RMII = FieldValue<MCU, Series, SYSCFG_PMC_IISEL_VALUES, 1>;
};

template<typename MCU, typename Series, typename Register, std::size_t offset, std::size_t size, typename AccessMode>
struct SYSCFG_EXTICR_EXTI_VALUES: public Field<MCU, Series, Register, offset, size, AccessMode>
{
	using PAx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 0>;
	using PBx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 1>;
	using PCx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 2>;
	using PDx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 3>;
	using PEx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 4>;
	using PFx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 5>;
	using PGx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 6>;
	using PHx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 7>;
	using PIx = FieldValue<MCU, Series, SYSCFG_EXTICR_EXTI_VALUES, 8>;
};