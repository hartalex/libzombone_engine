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
  off.setup();
  std::cout << "Component should not be removed" << std::endl;
  c->isRemoved();
  c->remove();
  std::cout << "Component should be removed" << std::endl;
  c->isRemoved();
  std::cout << "Component should not be torn down" << std::endl;
  off.tearDown();
  std::cout << "Component should still not be torn down" << std::endl;
  return EXIT_SUCCESS;
}
