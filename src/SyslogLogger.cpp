#include "SyslogLogger.hpp"

#include "config.hpp"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

SyslogLogger::SyslogLogger() {}

SyslogLogger::~SyslogLogger() {}

void SyslogLogger::debug(char const *message, ...) {
  ;
  if (LOG_LEVEL <= LOG_LEVEL_DEBUG) {
    char dest[MAX_LOG_LINE_LEN];
    va_list argptr;
    va_start(argptr, message);
    vsprintf(dest, message, argptr);
    va_end(argptr);

    syslog(LOG_DEBUG, "%s", dest);
  }
}

void SyslogLogger::info(char const *message, ...) {
  if (LOG_LEVEL <= LOG_LEVEL_INFO) {
    char dest[MAX_LOG_LINE_LEN];
    va_list argptr;
    va_start(argptr, message);
    vsprintf(dest, message, argptr);
    va_end(argptr);

    syslog(LOG_INFO, "%s", dest);
  }
}
void SyslogLogger::warn(char const *message, ...) {
  if (LOG_LEVEL <= LOG_LEVEL_WARN) {
    char dest[MAX_LOG_LINE_LEN];
    va_list argptr;
    va_start(argptr, message);
    vsprintf(dest, message, argptr);
    va_end(argptr);

    syslog(LOG_WARNING, "%s", dest);
  }
}
void SyslogLogger::error(char const *message, ...) {
  if (LOG_LEVEL <= LOG_LEVEL_ERROR) {
    char dest[MAX_LOG_LINE_LEN];
    va_list argptr;
    va_start(argptr, message);
    vsprintf(dest, message, argptr);
    va_end(argptr);

    syslog(LOG_ERR, "%s", dest);
  }
}

