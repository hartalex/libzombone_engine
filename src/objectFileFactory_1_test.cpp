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
  string::size_type sz;
  int i = stoi(argv[2], &sz);
  ObjectIdentifier oid = off.createObject(i, 0, 0);
  cout << "Type: " << oid.objectType << endl;
  if (oid.objectName.size() > 0) {
    cout << "Name: " << oid.objectName.c_str() << endl;
  } else {
    cout << "Name:" << endl;
  }
  cout << "Id: " << oid.objectId << endl;
  return EXIT_SUCCESS;
}
