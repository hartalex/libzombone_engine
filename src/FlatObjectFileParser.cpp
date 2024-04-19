
#include <fstream>
#include <iostream>
#include <vector>
#include <zombone_engine/FlatObjectFileParser.hpp>
#include <zombone_engine/LoggerService.hpp>

using namespace std;

namespace zombone_engine {

FlatObjectFileParser::FlatObjectFileParser() {}

vector<ObjectData> FlatObjectFileParser::parse(fstream &inputFile) {
  string::size_type sz;
  vector<ObjectData> objects;
  if (inputFile.is_open()) {
    string line;
    ObjectData data;
    data.type = -1;
    while (!inputFile.eof()) {
      getline(inputFile, line);
      if (!inputFile.eof()) {
        // new object
        if (line.at(0) != ' ') {
          // Push last object onto vector if it exists
          if (data.type != -1) {
            objects.push_back(data);
            LoggerService::getLogger().debug("Parsed Object %i", data.type);
            data.components.clear();
          }
          vector<string> type_strings = split(line, ' ');
          if (type_strings.size() >= 2) {
            data.type = stoi(type_strings.at(0), &sz);
            data.name = type_strings.at(1);
          } else {
            LoggerService::getLogger().warn(
                "Object Type String Size is not >= 2 %i", type_strings.size());
            throw logic_error("Object Type String Size is not >= 2");
          }
        } else {
          ComponentData componentData;
          componentData.objectIdentifier =
              ObjectIdentifier(data.type, data.name, -1);
          vector<string> componentStrings = split(line, ' ');
          if (componentStrings.size() >= 2) {
            componentData.type = stoi(componentStrings.at(0), &sz);
            componentData.name = componentStrings.at(1);
            if (componentStrings.size() > 2) {
              componentData.type = stoi(componentStrings.at(0), &sz);
              componentData.name = componentStrings.at(1);
              for (vector<string>::iterator it = componentStrings.begin() + 2;
                   it != componentStrings.end(); ++it) {
                componentData.args.push_back(*it);
              }
            }
          } else {
            LoggerService::getLogger().warn(
                "Component String Size is not > 2 %i", componentStrings.size());
            throw logic_error("Component String Size is not > 2");
          }
          data.components.push_back(componentData);
          LoggerService::getLogger().debug("Parsed Component %i",
                                           componentData.type);
        }
      }
    }
    // Push last object onto vector if it exists
    if (data.type != -1) {
      objects.push_back(data);
      LoggerService::getLogger().debug("Parsed Object %i", data.type);
    }
  }
  return objects;
}

vector<string> FlatObjectFileParser::split(const string &str, char delim) {
  vector<string> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != string::npos) {
    end = str.find(delim, start);
    strings.push_back(str.substr(start, end - start));
  }
  return strings;
}

}  // namespace zombone_engine
