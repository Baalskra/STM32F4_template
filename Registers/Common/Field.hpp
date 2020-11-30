#pragma once

#include "Register_common_files.hpp"
#include "FieldValue.hpp"

/// @brief Базовый класс для работы с полем регистра.
/// @tparam MCU Целевой микроконтроллер.
/// @tparam Series Семейство миктроконтроллеров, поддерживающие поле.
/// @tparam Register Базовый регистр.
/// @tparam offset_ Сдвиг поля в битах.
/// @tparam size_ Размер поля в битах.
/// @tparam AccessMode_ Режим доступа к полю.
template<typename MCU, typename Series, typename Register, size_t offset_, size_t size_, typename AccessMode_>
class Field
{
	/// @brief Удаляю конструктор. 
	Field() = delete;

public:
	/// @brief Тип (размер) регистра для доступа из дружественного класса.
	using Type = typename Register::Type;

	/// @brief Режим доступа к полю для доступа из дружественного класса.
	using AccessMode = AccessMode_;

	/// @brief Адрес регистра для доступа из дружественного класса.
	static constexpr auto address = Register::address;

	/// @brief Сдвиг поля в битах для доступа из дружественного класса.
	static constexpr auto offset = offset_;

	/// @brief Размер поля в битах для доступа из дружественного класса.
	static constexpr auto size = size_;

	/// @brief Метод записи значения в поле. Только для режима WO или RW.
	/// @param value Новое значение поля.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<WO, T>::value>,	// Проверка режима доступа. Только те режимы, которые допускают запись.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>			// Проверка принадлежности поля к целевому микроконтроллеру.
	static void Set(Type value)
	{
		Type tmp = *reinterpret_cast<Type*>(address);

		tmp &= ~(((1 << size) - 1) << offset);
		tmp |= (value << offset);

		*reinterpret_cast<Type*>(address) = tmp;
	}

	/// @brief Метод записи 1 в поле. Только для режима RS.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_same<RS, T>::value>,	// Проверка режима доступа. Только режим RS.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>			// Проверка принадлежности поля к целевому микроконтроллеру.
	static void Set()
	{
		/*Type tmp = *reinterpret_cast<Type *>(address);

		tmp |= (1 << offset);

		*reinterpret_cast<Type *>(address) = tmp;*/

		// Записываю прямо в память, так как чтение этого поля может быть ограничено.
		*reinterpret_cast<Type*>(address) |= (1 << offset);
	}

	/// @brief Метод очистки поля, путем записи 0 или 1. Только для режимов RC_W0 и RC_W1 соответвенно.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<T, RC>::value>, // Проверка режима доступа. Только режимы RC_W0 и RC_W1, внутри разберусь.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>			// Проверка принадлежности поля к целевому микроконтроллеру.
	static void Clear()
	{
		/*Type tmp = *reinterpret_cast<Type *>(address);

		tmp &= ~(1 << offset);

		if(std::is_same<T, RC_W1>::value)
			// Если режим доступа RC_W1 - то единицу не записываю.
			tmp |= (1 << offset);

		*reinterpret_cast<Type *>(address) = tmp;*/

		// Записываю 1 или 0, в зависимости от режима прямо в память, так как чтение этого поля может быть ограничено.
		if (std::is_same<T, RC_W1>::value)
			*reinterpret_cast<Type*>(address) |= (1 << offset);
		else
			*reinterpret_cast<Type*>(address) &= ~(1 << offset);
	}

	/// @brief Метод чтения поля. Для всех режимов, кроме WO. 
	/// @return Значение поля.
	/// @note Не уверен в корректности использования || в шаблоне, но вроде работает.
	template<typename T = AccessMode, class = typename std::enable_if_t<std::is_base_of<RO, T>::value || std::is_same<RS, T>::value || std::is_base_of<T, RC>::value>, // Проверка режима доступа. Для всех режимов, кроме WO.
	typename T1 = Series, class = typename std::enable_if_t<std::is_base_of<MCU, T1>::value>>	// Проверка принадлежности поля к целевому микроконтроллеру.
	static Type Get()
	{
		return ((*reinterpret_cast<Type*>(address)) & (((1 << size) - 1) << offset)) >> offset;
	}
};