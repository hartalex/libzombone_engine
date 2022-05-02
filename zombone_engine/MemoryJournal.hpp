#ifndef HEADER_MEMORY_JOURNAL
#define HEADER_MEMORY_JOURNAL

#include <list>

#include "Journal.hpp"
using namespace std;

// The maximum length a log message
#define MAX_JOURNAL_LINE_LEN 1024

// The maximum length a log message
#define MAX_MESSAGE_SIZE 50

class MemoryJournal : public Journal {
 public:
  MemoryJournal();
  virtual ~MemoryJournal();
  virtual void addMessage(char const *message, ...) override
      __attribute__((format(printf, 2, 3)));
  virtual list<char *> getLastMessages(int count) override;

 private:
  char messages[MAX_MESSAGE_SIZE][MAX_JOURNAL_LINE_LEN];
  int nextMessage;
};

#endif
