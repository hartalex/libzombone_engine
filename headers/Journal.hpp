#ifndef HEADER_JOURNAL
#define HEADER_JOURNAL

#include <list>

class Journal {
 public:
  virtual ~Journal(){};
  virtual void addMessage(char const *message, ...) = 0;
  virtual std::list<char *> getLastMessages(int count) = 0;
};

#endif
