#ifndef HEADER_JOURNAL
#define HEADER_JOURNAL

#include <list>
using namespace std;

namespace zombone_engine {

class Journal {
 public:
  virtual ~Journal(){};
  virtual void addMessage(char const *message, ...) = 0;
  virtual list<char *> getLastMessages(int count) = 0;
};

}  // namespace zombone_engine

#endif
