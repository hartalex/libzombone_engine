#include "zombone_engine/LoggerService.hpp"

#include <MockLogger.hpp>
#include <cstddef>

namespace zombone_engine {

Logger *LoggerService::logger_ = NULL;

Logger &LoggerService::getLogger() {
  if (logger_ == NULL) {
    logger_ = new MockLogger();
  }
  return *logger_;
}

}  // namespace zombone_engine
