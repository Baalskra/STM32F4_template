#pragma once

/// @brief Режим доступа только на запись.
struct WO {};

/// @brief Режим доступа только на чтение.
struct RO {};

/// @brief Режим доступа на чтение и на запись.
struct RW: public WO, public RO {};

/// @brief Режим доступа только на чтение и очистку, путем записи 0. Запись 1 не имеет эффекта.
struct RC_W0 {};

/// @brief Режим доступа только на чтение и очистку, путем записи 1. Запись 0 не имеет эффекта.
struct RC_W1 {};

/// @brief Для удобства наследую оба, в методе разберусь.
struct RC: public RC_W0, public RC_W1 {};

/// @brief Режим доступа только на чтение и запись 1. Запись 0 не имеет эффекта.
struct RS {};