#pragma once

#include "Register_common_files.hpp"

/// @brief Базовый класс для работы с регистром.
/// @tparam MCU Целевой микроконтроллер.
/// @tparam Series Семейство миктроконтроллеров, поддерживающие значение поля.
/// @tparam Field Базовое поле.
/// @tparam value Значение поля.
template<typename MCU, typename Series, typename Field, typename Field::Type value>
class FieldValue
{
	/// @brief Удаляю конструктор. 
	FieldValue() = delete;

	/// @brief Тип (размер) регистра.
	using Type = typename Field::Type;

	/// @brief Режим доступа к полю.
	using AccessMode = typename Field::AccessMode;

	/// @brief Адрес регистра.
	static constexpr auto address = Field::address;

	/// @brief Размер поля в битах.
	static constexpr auto size = Field::size;

	/// @brief Сдвиг поля в битах.
	static constexpr auto offset = Field::offset;

public:
	/// @brief Метод записи значения поля в поле.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<WO, T>::value>,	// Проверка режима доступа. Только те режимы, которые допускают запись.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>			// Проверка принадлежности значения поля к целевому микроконтроллеру.
	static void Set()
	{
		Type tmp = *reinterpret_cast<Type*>(address);

		tmp &= ~(((1 << size) - 1) << offset);
		tmp |= (value << offset);

		*reinterpret_cast<Type*>(address) = tmp;
	}

	/// @brief Метод проверки соответствия значения поля с полем регистра.
	/// @return Истина или ложь.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<RO, T>::value>,
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>
	static bool IsSet()
	{
		return 	((*reinterpret_cast<Type*>(address)) & static_cast<Type>(((1 << size) - 1) << offset)) == (value << offset);
	}
};