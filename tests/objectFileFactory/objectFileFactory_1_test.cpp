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
  string::size_type sz;
  int i = stoi(argv[2], &sz);
  ObjectIdentifier oid = off.createObject(i);
  cout << "Type: " << oid.getType() << endl;
  if (oid.getName().size() > 0) {
    cout << "Name: " << oid.getName().c_str() << endl;
  } else {
    cout << "Name:" << endl;
  }
  cout << "Id: " << oid.getId() << endl;
  return EXIT_SUCCESS;
}
