#ifndef HEADER_LOGGER
#define HEADER_LOGGER

class Logger {
public:
  virtual ~Logger(){};
  virtual void debug(char const *message, ...) = 0;
  virtual void info(char const *message, ...) = 0;
  virtual void warn(char const *message, ...) = 0;
  virtual void error(char const *message, ...) = 0;
};

#endif
