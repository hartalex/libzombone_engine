#include "zombone_engine/LoggerService.hpp"

#include <cstddef>

#include "MockLogger.hpp"
#include "zombone_engine/Logger.hpp"

namespace zombone_engine {

Logger *LoggerService::logger_ = NULL;

Logger &LoggerService::getLogger() {
  if (logger_ == NULL) {
    logger_ = new MockLogger();
  }
  return *logger_;
}

}  // namespace zombone_engine
