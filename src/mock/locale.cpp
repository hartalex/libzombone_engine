#include <iostream>
#include <locale.h>

char *setlocale(int cat, const char *locale) {
  std::cout << "Mock Locale setlocale was called with (" << cat << ", "
            << locale << ")" << std::endl;
  return 0;
}
