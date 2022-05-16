#ifndef HEADER_LOGGER_SERVICE
#define HEADER_LOGGER_SERVICE

#include "Logger.hpp"

namespace zombone_engine {

class LoggerService {
 public:
  static Logger &getLogger();

 private:
  static Logger *logger_;
};

}  // namespace zombone_engine

#endif
