#ifndef HEADER_JOURNAL_SERVICE
#define HEADER_JOURNAL_SERVICE

#include "Journal.hpp"

export class JournalService {
 public:
  static Journal &getJournal();

 private:
  static Journal *journal_;
};
#endif
