#include <iostream>

#include "ComponentData.hpp"
#include "GameComponentFactory.hpp"
#include "component.hpp"
using namespace std;

GameComponentFactory::GameComponentFactory() {
  cout << "Mock GameComponentFactory constructor was called" << endl;
}

GameComponentFactory::~GameComponentFactory() {
  cout << "Mock GameComponentFactory destructor was called" << endl;
}

shared_ptr<Component> GameComponentFactory::createComponent(
    ComponentData data) {
  (void)data;
  cout << "Mock GameComponentFactory createComponent called with (" << data.type
       << ", " << data.name << ", " << data.objectIdentifier.objectType << ", "
       << data.objectIdentifier.objectName << ", "
       << data.objectIdentifier.objectId << ")" << endl;
  cout << "data.args: ";
  for (vector<string>::iterator it = data.args.begin(); it != data.args.end();
       ++it) {
    cout << ", " << (*it).c_str();
  }
  cout << endl;
  return 0;
}

