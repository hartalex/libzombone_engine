#include "MemoryJournal.hpp"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

MemoryJournal::MemoryJournal() { nextMessage = 0; }

MemoryJournal::~MemoryJournal() {}

void MemoryJournal::addMessage(char const *message, ...) {
  char dest[MAX_JOURNAL_LINE_LEN];
  va_list argptr;
  va_start(argptr, message);
  vsprintf(dest, message, argptr);
  va_end(argptr);

  strncpy(&messages[nextMessage][0], dest, MAX_JOURNAL_LINE_LEN);
  nextMessage++;
  if (nextMessage >= MAX_MESSAGE_SIZE) {
    nextMessage = 0;
  }
}

std::list<char *> MemoryJournal::getLastMessages(int count) {
  std::list<char *> retval;
  int numToReturn = count;
  int index = nextMessage;
  int counter = 0;
  if (count > MAX_MESSAGE_SIZE) {
    numToReturn = MAX_MESSAGE_SIZE;
  }
  if (count < 0) {
    numToReturn = 0;
  };
  while (counter < numToReturn) {
    index--;
    if (index < 0) {
      index = MAX_MESSAGE_SIZE - 1;
    }
    retval.push_front(messages[index]);
    counter++;
  }
  return retval;
}
