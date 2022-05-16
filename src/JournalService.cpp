#include "zombone_engine/JournalService.hpp"

#include <cstddef>

#include "zombone_engine/Journal.hpp"
#include "zombone_engine/MemoryJournal.hpp"

namespace zombone_engine {

Journal *JournalService::journal_ = NULL;

Journal &JournalService::getJournal() {
  if (journal_ == NULL) {
    journal_ = new MemoryJournal();
  }
  return *journal_;
}

}  // namespace zombone_engine
