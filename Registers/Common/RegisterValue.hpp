#pragma once

#include "Register_common_files.hpp"

/// @brief Базовый класс для работы с целым регистром, как полем.
/// @tparam MCU Целевой микроконтроллер.
/// @tparam Series Семейство миктроконтроллеров, поддерживающие регистр.
/// @tparam Register Базовый регистр.
/// @tparam value Значение регистра.
template<typename MCU, typename Series, typename Register, typename Register::Type value>
class RegisterValue
{
	/// @brief Удаляю конструктор. 
	RegisterValue() = delete;

	/// @brief Тип (размер) регистра.
	using Type = typename Register::Type;

	/// @brief Режим доступа к полю.
	using AccessMode = typename Register::AccessMode;

	/// @brief Адрес регистра.
	static constexpr auto address = Register::address;

public:
	/// @brief Метод записи значения в регистр.
	/// @param value Новое значение регистра.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<WO, T>::value>,	// Проверка режима доступа. Только те режимы, котрые допускают запись.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>			// Проверка принадлежности регистра к целевому микроконтроллеру.
	static void Set()
	{
		*reinterpret_cast<Type *>(address) = value;
	}
};