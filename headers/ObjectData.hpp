#ifndef HEADER_OBJECT_DATA
#define HEADER_OBJECT_DATA

#include <string>
#include <vector>

#include "ComponentData.hpp"

export struct ObjectData {
  int type;
  std::vector<ComponentData> components;
  std::string name;
};

#endif
