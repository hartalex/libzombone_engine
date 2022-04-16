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
  cout << "Type: " << oid.getType() << endl;
  if (oid.getName().size() > 0) {
    cout << "Name: " << oid.getName().c_str() << endl;
  } else {
    cout << "Name:" << endl;
  }
  cout << "Id: " << oid.getId() << endl;
  shared_ptr<Component> c =
      off.getComponentByObjectAndComponentType(1, "transform", oid);
  if (!c) {
    cerr << "Component should have been found" << endl;
    return -1;
  }
  off.setup();
  cout << "Component should not yet be removed" << endl;
  c->isRemoved();
  c->remove();
  cout << "Component should be removed" << endl;
  c->isRemoved();
  cout << "Component should not be update" << endl;
  off.update();
  cout << "Component should still not be updated" << endl;
  return EXIT_SUCCESS;
}
