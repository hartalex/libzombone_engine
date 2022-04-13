#include "LoggerService.hpp"

#include "Logger.hpp"
#include "MockLogger.hpp"
#include <cstddef>

Logger *LoggerService::logger_ = NULL;

Logger &LoggerService::getLogger() {
  if (logger_ == NULL) {
    logger_ = new MockLogger();
  }
  return *logger_;
}
