
#include "zombone_engine/FlatObjectFileParser.hpp"

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace zombone_engine; 

FlatObjectFileParser::FlatObjectFileParser() {}

vector<ObjectData> FlatObjectFileParser::parse(fstream &inputFile) {
  string::size_type sz;
  vector<ObjectData> objects;
  return objects;
}

vector<string> FlatObjectFileParser::split(const string &str, char delim) {
  vector<string> strings;
  return strings;
}

