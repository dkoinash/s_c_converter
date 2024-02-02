#pragma once

#include <chrono>
#include <string>
#include <string_view>

/**
 * @brief Класс преобразователь
 */
class Converter
{
public:
  /**
   * @brief Получение строки из метки времени
   *
   * @param value Метка времени
   * @param is_ms Включение миллисекунд с строку, true - включение, иначе - нет
   * @return Возвращает строку из метки времени в формате YYYYMMDD_hhmmssnnn (nnn - значение
   * миллисекунд если включены)
   */
  static std::string ToString(const std::chrono::milliseconds& value, bool is_ms);
  /**
   * @brief Получение метки времени из строки
   *
   * @param sample Строка в формате YYYYMMDD_hhmmssnnn или YYYYMMDD_hhmmss
   * @return Возвращает метку времени в формате std::chrono::milliseconds
   */
  static std::chrono::milliseconds ToMilli(std::string_view sample);
};