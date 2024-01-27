#include <Converter.h>
#include <iostream>

int
main()
{
  uint64_t value = 1706278376987;
  milliseconds ms(value);
  std::string sample;

  std::cout << "value: " << value << std::endl;

  sample = Converter::ToString(ms, true);
  std::cout << "ToString(ms = true): " << sample << std::endl;

  ms = Converter::ToChrono(sample);
  std::cout << "ToChrono: " << ms.count() << std::endl;

  sample = Converter::ToString(ms, false);
  std::cout << "ToString(ms = false): " << sample << std::endl;

  ms = Converter::ToChrono(sample);
  std::cout << "ToChrono: " << ms.count() << std::endl;

  return 0;
}