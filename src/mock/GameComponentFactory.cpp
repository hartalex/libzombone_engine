#include "GameComponentFactory.hpp"

#include <iostream>

#include "zombone_engine/Component.hpp"
#include "zombone_engine/ComponentData.hpp"
using namespace std;
using namespace zombone_engine;

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
       << ", " << data.name << ", " << data.objectIdentifier.getType() << ", "
       << data.objectIdentifier.getName() << ", "
       << data.objectIdentifier.getId() << ")" << endl;
  cout << "data.args: ";
  for (vector<string>::iterator it = data.args.begin(); it != data.args.end();
       ++it) {
    cout << ", " << (*it).c_str();
  }
  cout << endl;
  return make_shared<Component>(data.type, data.name, data.objectIdentifier);
}

