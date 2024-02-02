#include <Converter.h>
#include <iostream>

// option(UTILS_BUILD_TESTS "Build test programs" OFF)

int
main()
{
  //   uint64_t value = 1706278376987;
  //   milliseconds ms(value);
  //   std::string sample;

  //   std::cout << "value: " << value << std::endl;

  //   sample = Converter::ToString(ms, true);
  //   std::cout << "ToString(ms = true): " << sample << std::endl;

  //   ms = Converter::ToMilli(sample);
  //   std::cout << "ToMilli: " << ms.count() << std::endl;

  //   sample = Converter::ToString(ms, false);
  //   std::cout << "ToString(ms = false): " << sample << std::endl;

  //   ms = Converter::ToMilli(sample);
  //   std::cout << "ToMilli: " << ms.count() << std::endl;

  //   ms = Converter::ToMilli("20240131_123456789");
  //   std::cout << "ToMilli(A): " << ms.count() << std::endl;

  std::string str = "20240101_000000000";
  milliseconds ms = Converter::ToMilli(str);
  std::string strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240000_000000000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20241301_000000000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240132_000000000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240134_000000000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240101_240000000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240101_260000000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240101_006000000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240101_006200000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240101_000060000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240101_000062000";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  str = "20240101_000000999";
  ms = Converter::ToMilli(str);
  strFromMs = Converter::ToString(ms, true);
  std::cout << "ToMilli(" << str << ") =  " << ms.count() << " => " << strFromMs << std::endl;

  return 0;
}
