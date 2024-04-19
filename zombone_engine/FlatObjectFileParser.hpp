#pragma once
#include <fstream>
#include <string>
#include <vector>

#include <ObjectData.hpp>
#include <ObjectFileParser.hpp>
using namespace std;

namespace zombone_engine {

class FlatObjectFileParser : public ObjectFileParser {
 public:
  FlatObjectFileParser();
  virtual ~FlatObjectFileParser() = default;
  virtual vector<ObjectData> parse(fstream &file) override;

 private:
  vector<string> split(const string &str, char delim);
};

}  // namespace zombone_engine
