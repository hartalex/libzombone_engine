#ifndef HEADER_COMPONENT_DATA
#define HEADER_COMPONENT_DATA

#include <string>
#include <vector>

#include <ObjectIdentifier.hpp>
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
