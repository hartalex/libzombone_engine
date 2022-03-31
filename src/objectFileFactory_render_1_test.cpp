#define config mock
#include <stdlib.h>

#include <iostream>

#include "GameComponentFactory.hpp"
#include "ObjectFileFactory.hpp"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(std::make_unique<GameComponentFactory>(), argv[1]);
  ObjectIdentifier oid = off.createObject(1, 0, 0);
  std::cout << "Type: " << oid.objectType << std::endl;
  if (oid.objectName.size() > 0) {
    std::cout << "Name: " << oid.objectName.c_str() << std::endl;
  } else {
    std::cout << "Name:" << std::endl;
  }
  std::cout << "Id: " << oid.objectId << std::endl;
  std::shared_ptr<Component> c =
      off.getComponentByObjectAndComponentType(1, "transform", oid);
  if (!c) {
    std::cerr << "Component should have been found" << std::endl;
    return -1;
  }
  off.setup();
  std::cout << "Component should not yet be rendered" << std::endl;
  off.render();
  std::cout << "Component should be rendered" << std::endl;
  return EXIT_SUCCESS;
}
