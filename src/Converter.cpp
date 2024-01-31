#include <Converter.h>

std::string
Converter::ToString(const milliseconds& value, bool is_ms)
{
  TimePoint tp_now{ duration_cast<TimePoint::duration>(value) };

  std::time_t now_tt = Clock::to_time_t(tp_now);

  std::tm __tm;
  localtime_s(&__tm, &now_tt);

  std::string result;
  if (is_ms) {
    result.resize(MAIN_SIZE);
    int ms = value.count() % 1000;
    sprintf_s(result.data(),
              result.size() + 1,
              "%04d%02d%02d_%02d%02d%02d%03d",
              __tm.tm_year + 1900,
              __tm.tm_mon + 1,
              __tm.tm_mday,
              __tm.tm_hour,
              __tm.tm_min,
              __tm.tm_sec,
              ms);
  } else {
    result.resize(SHORT_SIZE);
    sprintf_s(result.data(),
              result.size() + 1,
              "%04d%02d%02d_%02d%02d%02d",
              __tm.tm_year + 1900,
              __tm.tm_mon + 1,
              __tm.tm_mday,
              __tm.tm_hour,
              __tm.tm_min,
              __tm.tm_sec);
  }
  return result;
}

milliseconds
Converter::ToMilli(std::string_view sample)
{
  bool is_ms = sample.size() == MAIN_SIZE;

  if (!isCorrectSample(sample)) return milliseconds();

  int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, ms = 0;

  int ret = sscanf_s(
    sample.data(), "%4d%2d%2d_%2d%2d%2d%3d", &year, &month, &day, &hour, &minute, &second, &ms);
  if (ret < 6) return milliseconds();

  std::tm __tm;
  __tm.tm_year = year - 1900;
  __tm.tm_mon = month - 1;
  __tm.tm_mday = day;
  __tm.tm_hour = hour;
  __tm.tm_min = minute;
  __tm.tm_sec = second;

  return duration_cast<milliseconds>(Clock::from_time_t(std::mktime(&__tm)).time_since_epoch()) +
         milliseconds(ms);
}

bool
Converter::isCorrectSample(std::string_view sample)
{
  if (sample.size() != MAIN_SIZE && sample.size() != SHORT_SIZE) return false;

  for (const auto& el : sample) {
    if (std::isdigit(el) || sample.at(8) == '_') continue;
    return false;
  }

  return true;
}