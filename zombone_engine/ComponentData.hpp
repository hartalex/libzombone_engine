#ifndef HEADER_COMPONENT_DATA
#define HEADER_COMPONENT_DATA

#include <ObjectIdentifier.hpp>
#include <string>
#include <vector>
using namespace std;

namespace zombone_engine {

struct ComponentData {
  int type;
  string name;
  ObjectIdentifier objectIdentifier;
  vector<string> args;
};

}  // namespace zombone_engine

#endif
