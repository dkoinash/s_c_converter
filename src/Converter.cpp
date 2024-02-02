#include <Converter.h>
#include <ctime>

using namespace std::chrono;

using Clock = system_clock;
using TimePoint = Clock::time_point;

std::string
Converter::ToString(const milliseconds& value, bool is_ms)
{
  std::time_t tt = Clock::to_time_t(TimePoint{ duration_cast<TimePoint::duration>(value) });
  std::tm tm;
  localtime_s(&tm, &tt);
  int ms = value.count() % 1000;

  tm.tm_year += 1900;
  tm.tm_mon += 1;

  const std::string format = is_ms ? "%04d%02d%02d_%02d%02d%02d%03d" : "%04d%02d%02d_%02d%02d%02d";
  std::string result;

  const int bufSize = snprintf(nullptr,
                               0,
                               format.c_str(),
                               tm.tm_year,
                               tm.tm_mon,
                               tm.tm_mday,
                               tm.tm_hour,
                               tm.tm_min,
                               tm.tm_sec,
                               ms);

  result.resize(bufSize);

  snprintf(result.data(),
           bufSize+1,
           format.c_str(),
           tm.tm_year,
           tm.tm_mon,
           tm.tm_mday,
           tm.tm_hour,
           tm.tm_min,
           tm.tm_sec,
           ms);

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