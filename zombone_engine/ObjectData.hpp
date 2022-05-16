#ifndef HEADER_OBJECT_DATA
#define HEADER_OBJECT_DATA

#include <string>
#include <vector>

#include "ComponentData.hpp"
using namespace std;

namespace zombone_engine {

struct ObjectData {
  int type;
  vector<ComponentData> components;
  string name;
};

}  // namespace zombone_engine
#endif
