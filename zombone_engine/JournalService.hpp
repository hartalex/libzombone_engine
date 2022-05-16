#ifndef HEADER_JOURNAL_SERVICE
#define HEADER_JOURNAL_SERVICE

#include "Journal.hpp"

namespace zombone_engine {

class JournalService {
 public:
  static Journal &getJournal();

 private:
  static Journal *journal_;
};

}  // namespace zombone_engine

#endif
