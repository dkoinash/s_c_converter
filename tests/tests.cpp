#include <Converter.h>
#include <iostream>
#include <string>

#include <gtest/gtest.h>


TEST(Converter, ToMilliWithMS)
{
  uint64_t value = 1706278376987;
  milliseconds ms(value);
  std::string sample = Converter::ToString(ms, true);
  ASSERT_EQ(Converter::ToMilli(sample).count(), value);
}

TEST(Converter, ToMilliWithoutMS)
{
  uint64_t value = 1706278376000;
  milliseconds ms(value);
  std::string sample = Converter::ToString(ms, false);
  ASSERT_EQ(Converter::ToMilli(sample).count(), value);
}

TEST(Converter, ToStringWithMS)
{
  std::string str = "20211203_122435898";
  milliseconds ms = Converter::ToMilli(str);
  ASSERT_EQ(Converter::ToString(ms, true), str);
}

TEST(Converter, ToStringWithoutMS)
{
  std::string str = "20211203_122435";
  milliseconds ms = Converter::ToMilli(str);
  ASSERT_EQ(Converter::ToString(ms, false), str);
}