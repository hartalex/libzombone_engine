#include "JournalService.hpp"

#include <cstddef>

#include "Journal.hpp"
#include "MemoryJournal.hpp"

Journal *JournalService::journal_ = NULL;

Journal &JournalService::getJournal() {
  if (journal_ == NULL) {
    journal_ = new MemoryJournal();
  }
  return *journal_;
}
