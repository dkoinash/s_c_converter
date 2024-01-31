// #include <Converter.h>
#include <iostream>

#include <gtest/gtest.h>

// int
// main()
// {
//   // uint64_t value = 1706278376987;
//   // milliseconds ms(value);
//   // std::string sample;

//   // std::cout << "value: " << value << std::endl;

//   // sample = Converter::ToString(ms, true);
//   // std::cout << "ToString(ms = true): " << sample << std::endl;

//   // ms = Converter::ToMilli(sample);
//   // std::cout << "ToMilli: " << ms.count() << std::endl;

//   // sample = Converter::ToString(ms, false);
//   // std::cout << "ToString(ms = false): " << sample << std::endl;

//   // ms = Converter::ToMilli(sample);
//   // std::cout << "ToMilli: " << ms.count() << std::endl;


//   // ms = Converter::ToMilli("20240131_123456789");
//   // std::cout << "ToMilli(A): " << ms.count() << std::endl;
//   // ms = Converter::ToMilli("20240131_123456");
//   // std::cout << "ToMilli(B): " << ms.count() << std::endl;


//   return 0;
// }

int
main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}