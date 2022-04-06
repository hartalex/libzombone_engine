#include <locale.h>

#include <iostream>
using namespace std;

char *setlocale(int cat, const char *locale) {
  cout << "Mock Locale setlocale was called with (" << cat << ", " << locale
       << ")" << endl;
  return 0;
}
