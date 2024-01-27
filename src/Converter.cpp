#include <Converter.h>

std::string
Converter::ToString(milliseconds value, bool is_ms)
{
  TimePoint tp_now{ duration_cast<TimePoint::duration>(value) };

  std::time_t now_tt = Clock::to_time_t(tp_now);
  std::tm* __tm = std::localtime(&now_tt);

  std::string result = std::to_string(__tm->tm_year + 1900);
  if (__tm->tm_mon < 9) result += "0";
  result += std::to_string(__tm->tm_mon + 1);
  if (__tm->tm_mday < 10) result += "0";
  result += std::to_string(__tm->tm_mday);
  result += "_";
  result += std::to_string(__tm->tm_hour);
  result += std::to_string(__tm->tm_min) + std::to_string(__tm->tm_sec);

  if (is_ms) result += std::to_string(value.count() % 1000);

  return result;
}

milliseconds
Converter::ToChrono(std::string sample)
{
  bool is_ms = sample.size() == 18;
  Converter conv;
  if (!conv.isCorrectSample(sample)) return milliseconds();

  int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, ms = 0;

  int ret;
  if (is_ms)
    ret = sscanf(
      sample.c_str(), "%4d%2d%2d_%2d%2d%2d%3d", &year, &month, &day, &hour, &minute, &second, &ms);
  else
    ret =
      sscanf(sample.c_str(), "%4d%2d%2d_%2d%2d%2d", &year, &month, &day, &hour, &minute, &second);

  std::tm __tm;
  __tm.tm_year = year - 1900;
  __tm.tm_mon = month - 1;
  __tm.tm_mday = day;
  __tm.tm_hour = hour;
  __tm.tm_min = minute;
  __tm.tm_sec = second;

  std::time_t now_tt2 = std::mktime(&__tm);
  TimePoint tp_now2 = Clock::from_time_t(now_tt2);

  if (is_ms)
    return milliseconds(duration_cast<milliseconds>(tp_now2.time_since_epoch()).count() + ms);
  else
    return duration_cast<milliseconds>(tp_now2.time_since_epoch());
}

bool
Converter::isCorrectSample(const std::string& sample)
{
  if (sample.size() != 18 && sample.size() != 15) return false;

  for (const auto& el : sample) {
    if (std::isdigit(el) || sample.at(8) == '_') continue;
    return false;
  }

  return true;
}