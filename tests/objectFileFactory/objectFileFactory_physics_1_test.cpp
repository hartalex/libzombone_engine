#define config mock
#include <stdlib.h>

#include <iostream>

#include "GameComponentFactory.hpp"
#include "zombone_engine/ObjectFileFactory.hpp"
#include "zombone_engine/FlatObjectFileParser.hpp"
using namespace std;
using namespace zombone_engine;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(make_unique<GameComponentFactory>(), make_unique<FlatObjectFileParser>(), argv[1]);
  ObjectIdentifier oid = off.createObject(1);
  cout << "Type: " << oid.getType() << endl;
  if (oid.getName().size() > 0) {
    cout << "Name: " << oid.getName().c_str() << endl;
  } else {
    cout << "Name:" << endl;
  }
  cout << "Id: " << oid.getId() << endl;
  shared_ptr<Component> c =
      off.getComponentByObjectAndComponentType(1, "direction", oid);
  if (!c) {
    cerr << "Component should have been found" << endl;
    return -1;
  }
  off.setup();
  cout << "Component should not yet be updated" << endl;
  off.physics();
  cout << "Component should be physiced" << endl;
  return EXIT_SUCCESS;
}
