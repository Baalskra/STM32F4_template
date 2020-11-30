#pragma once

#include "Register_common_files.hpp"
#include "Field.hpp"

/// @brief Базовый класс для работы с регистром.
/// @tparam MCU Целевой микроконтроллер.
/// @tparam Series Семейство миктроконтроллеров, поддерживающие регистр.
/// @tparam address_ Адрес регистра.
/// @tparam size Тип (размер) регистра в битах.
/// @tparam AccessMode Режим доступа к регистру.
template<typename MCU, typename Series, uint32_t address_, size_t size, typename AccessMode>
class Register
{
	/// @brief Удаляю конструктор. 
	Register() = delete;

public:
	/// @brief Тип (размер) регистра для доступа из дружественного класса.
	using Type = typename RegisterType<size>::Type;

	/// @brief Адрес регистра для доступа из дружественного класса.
	static constexpr auto address = address_;

	/// @brief Метод записи значения в регистр.
	/// @param value Новое значение регистра.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<WO, T>::value>,	// Проверка режима доступа. Только те режимы, котрые допускают запись.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>			// Проверка принадлежности регистра к целевому микроконтроллеру.
	static void Set(Type value)
	{
		*reinterpret_cast<Type*>(address) = value;
	}

	/// @brief Метод чтения регистра.
	/// @return Значение регистра.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<RO, T>::value>,	// Проверка режима доступа. Только те режимы, котрые допускают чтение.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>			// Проверка принадлежности регистра к целевому микроконтроллеру.
	static Type Get()
	{
		return *reinterpret_cast<Type*>(address);
	}
};