#define config mock
#include "GameComponentFactory.hpp"
#include "ObjectFileFactory.hpp"
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(std::make_unique<GameComponentFactory>(), argv[1]);
  std::string::size_type sz;
  int i = std::stoi(argv[2], &sz);
  ObjectIdentifier oid = off.createObject(i, 0, 0);
  std::cout << "Type: " << oid.objectType << std::endl;
  if (oid.objectName.size() > 0) {
    std::cout << "Name: " << oid.objectName.c_str() << std::endl;
  } else {
    std::cout << "Name:" << std::endl;
  }
  std::cout << "Id: " << oid.objectId << std::endl;
  return EXIT_SUCCESS;
}
