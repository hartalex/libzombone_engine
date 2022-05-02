#ifndef HEADER_COMPONENT_DATA
#define HEADER_COMPONENT_DATA

#include <string>
#include <vector>

#include "ObjectIdentifier.hpp"
using namespace std;

struct ComponentData {
  int type;
  string name;
  ObjectIdentifier objectIdentifier;
  vector<string> args;
};

#endif
