#ifndef HEADER_MOCK_LOGGER
#define HEADER_MOCK_LOGGER

#include "Logger.hpp"

// The maximum length a log message
#define MAX_LOG_LINE_LEN 1024

// Log levels
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 3

class MockLogger : public Logger {
public:
  MockLogger();
  virtual ~MockLogger();
  virtual void debug(char const *message, ...) override
      __attribute__((format(printf, 2, 3)));
  virtual void info(char const *message, ...) override
      __attribute__((format(printf, 2, 3)));
  virtual void warn(char const *message, ...) override
      __attribute__((format(printf, 2, 3)));
  virtual void error(char const *message, ...) override
      __attribute__((format(printf, 2, 3)));
};

#endif
