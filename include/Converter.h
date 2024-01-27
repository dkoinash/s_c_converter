#include <chrono>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std::chrono;
using Clock = system_clock;
using TimePoint = Clock::time_point;
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
 * @return Возвращает строку из метки времени в формате YYYYMMDD_hhmmssnnn (nnn - значение миллисекунд если включены)
 */
  static std::string ToString(const milliseconds& value, bool is_ms);
  /**
   * @brief Получение метки времени из строки
   * 
   * @param sample Строка в формате YYYYMMDD_hhmmssnnn или YYYYMMDD_hhmmss
   * @return Возвращает метку времени
   */
  static milliseconds ToChrono(std::string_view sample);

private:
/**
 * @brief Construct a new Converter object
 */
  Converter() = default;

/**
 * @brief Destroy the Converter object
 */
  ~Converter() = default;

/**
 * @brief Проверка корректности строки
 * 
 * @param sample Строка в формате YYYYMMDD_hhmmssnnn или YYYYMMDD_hhmmss
 *
 * @return Возвращает true если строка соотвествует формату, иначе возвращает false
 */
  bool isCorrectSample(std::string_view sample);
};