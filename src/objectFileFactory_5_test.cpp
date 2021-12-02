#define config mock
#include "GameComponentFactory.hpp"
#include "ObjectFileFactory.hpp"
#include <iostream>
#include <stdlib.h>

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
  std::cout << "Component should not be setup" << std::endl;
  c->isSetup();
  off.setup();
  std::cout << "Component should be setup" << std::endl;
  c->isSetup();
  off.setup();
  std::cout << "Component should still be setup" << std::endl;
  c->isSetup();
  return EXIT_SUCCESS;
}
