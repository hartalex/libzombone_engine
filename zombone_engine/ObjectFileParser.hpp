#pragma once
#include <fstream>
#include <vector>

#include "ObjectData.hpp"
#include "ObjectFileParser.hpp"
using namespace std;

namespace zombone_engine {

class ObjectFileParser {
 public:
  virtual ~ObjectFileParser() = default;
  virtual vector<ObjectData> parse(fstream &file) = 0;
};

}  // namespace zombone_engine
