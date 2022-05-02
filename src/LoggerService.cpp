#include "zombone_engine/LoggerService.hpp"

#include <cstddef>

#include "zombone_engine/Logger.hpp"
#include "zombone_engine/SyslogLogger.hpp"

Logger *LoggerService::logger_ = NULL;

Logger &LoggerService::getLogger() {
  if (logger_ == NULL) {
    logger_ = new SyslogLogger();
  }
  return *logger_;
}
