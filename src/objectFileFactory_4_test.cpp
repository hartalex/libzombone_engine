#define config mock
#include <stdlib.h>

#include <iostream>

#include "GameComponentFactory.hpp"
#include "ObjectFileFactory.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(make_unique<GameComponentFactory>(), argv[1]);
  ObjectIdentifier oid = off.createObject(1, 0, 0);
  cout << "Type: " << oid.objectType << endl;
  if (oid.objectName.size() > 0) {
    cout << "Name: " << oid.objectName.c_str() << endl;
  } else {
    cout << "Name:" << endl;
  }
  cout << "Id: " << oid.objectId << endl;
  shared_ptr<Component> c =
      off.getComponentByObjectAndComponentType(1, "transform", oid);
  if (!c) {
    cerr << "Component should have been found" << endl;
    return -1;
  }
  cout << "Component should not be setup" << endl;
  c->isSetup();
  off.setup();
  cout << "Component should be setup" << endl;
  c->isSetup();
  return EXIT_SUCCESS;
}
