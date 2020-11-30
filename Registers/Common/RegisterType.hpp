#pragma once

#include <cstdint>

/// @brief Класс для определения типа (размера) регистра.
template <uint32_t size> struct RegisterType {};

/// @brief Специализация для регистра, размером в байт.
template<> struct RegisterType<8> { using Type = uint8_t; };

/// @brief Специализация для регистра, размером в полуслово (2 байта).
template<> struct RegisterType<16> { using Type = uint16_t; };

/// @brief Специализация для регистра, размером в слово (4 байта).
template<> struct RegisterType<32> { using Type = uint32_t; };