#include <Converter.h>
#include <iostream>
#include <string>

#include <gtest/gtest.h>

// TEST_F(TestCache, Overflow)
TEST(TestCache, Overflow)
{
  const uint64_t COUNT = 5;

  uint64_t value = 1706278376987;
  milliseconds ms(value);
  std::string sample = Converter::ToString(ms, true);
  ASSERT_EQ(Converter::ToMilli(sample).count(), value);
}