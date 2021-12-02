#include "GameComponentFactory.hpp"
#include "ComponentData.hpp"
#include "component.hpp"
#include <iostream>

GameComponentFactory::GameComponentFactory() {
  std::cout << "Mock GameComponentFactory constructor was called" << std::endl;
}

GameComponentFactory::~GameComponentFactory() {
  std::cout << "Mock GameComponentFactory destructor was called" << std::endl;
}

std::shared_ptr<Component>
GameComponentFactory::createComponent(ComponentData data) {
  (void)data;
  std::cout << "Mock GameComponentFactory createComponent called with ("
            << data.type << ", " << data.name << ", "
            << data.objectIdentifier.objectType << ", "
            << data.objectIdentifier.objectName << ", "
            << data.objectIdentifier.objectId << ")" << std::endl;
  std::cout << "data.args: ";
  for (std::vector<std::string>::iterator it = data.args.begin();
       it != data.args.end(); ++it) {
    std::cout << ", " << (*it).c_str();
  }
  std::cout << std::endl;
  return std::make_shared<Component>(data.type, data.name,
                                     data.objectIdentifier);
}

