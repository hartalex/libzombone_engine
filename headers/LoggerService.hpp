#ifndef HEADER_LOGGER_SERVICE
#define HEADER_LOGGER_SERVICE

#include "Logger.hpp"

class LoggerService {
 public:
  static Logger &getLogger();

 private:
  static Logger *logger_;
};
#endif
