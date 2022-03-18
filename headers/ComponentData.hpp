#ifndef HEADER_COMPONENT_DATA
#define HEADER_COMPONENT_DATA

#include <string>
#include <vector>

#include "ObjectIdentifier.hpp"

struct ComponentData {
  int type;
  std::string name;
  ObjectIdentifier objectIdentifier;
  std::vector<std::string> args;
};

#endif
