#include "MockLogger.hpp"

#include <stdarg.h>
#include <stdio.h>

#include <iostream>
using namespace std;

MockLogger::MockLogger() {}

MockLogger::~MockLogger() {}

void MockLogger::debug(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  cout << endl;
}
void MockLogger::info(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  cout << endl;
}
void MockLogger::warn(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  cout << endl;
}
void MockLogger::error(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  cout << endl;
}

