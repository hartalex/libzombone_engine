#include "MockLogger.hpp"

#include <iostream>
#include <stdarg.h>
#include <stdio.h>

MockLogger::MockLogger() {}

MockLogger::~MockLogger() {}

void MockLogger::debug(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  std::cout << std::endl;
}
void MockLogger::info(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  std::cout << std::endl;
}
void MockLogger::warn(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  std::cout << std::endl;
}
void MockLogger::error(char const *message, ...) {
  va_list argptr;
  va_start(argptr, message);
  vprintf(message, argptr);
  va_end(argptr);
  std::cout << std::endl;
}

