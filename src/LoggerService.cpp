#include "LoggerService.hpp"

#include <cstddef>

#include "Logger.hpp"
#include "SyslogLogger.hpp"

Logger *LoggerService::logger_ = NULL;

Logger &LoggerService::getLogger() {
  if (logger_ == NULL) {
    logger_ = new SyslogLogger();
  }
  return *logger_;
}
