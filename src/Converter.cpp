#include <Converter.h>
#include <ctime>

using namespace std::chrono;

using Clock = system_clock;
using TimePoint = Clock::time_point;

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
  std::tm tm;
  int ms = 0;

  int ret = sscanf_s(sample.data(),
                     "%4d%2d%2d_%2d%2d%2d%3d",
                     &tm.tm_year,
                     &tm.tm_mon,
                     &tm.tm_mday,
                     &tm.tm_hour,
                     &tm.tm_min,
                     &tm.tm_sec,
                     &ms);
  if (ret < 6) return milliseconds();

  tm.tm_year -= 1900;
  tm.tm_mon -= 1;

  return duration_cast<milliseconds>(Clock::from_time_t(std::mktime(&tm)).time_since_epoch()) +
         milliseconds(ms);
}