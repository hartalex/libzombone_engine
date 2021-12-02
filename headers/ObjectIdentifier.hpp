#ifndef HEADER_OBJECT_IDENTIFIER
#define HEADER_OBJECT_IDENTIFIER

#include <string>

export struct ObjectIdentifier {
  int objectType;
  std::string objectName;
  int objectId;
};

#endif
