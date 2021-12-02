#include <fstream>
#include <iostream>
#include <string>

#include "ComponentFactory.hpp"
#include "ObjectData.hpp"
#include "ObjectFileFactory.hpp"

std::vector<std::string> split(const std::string &str, char delim);

ObjectFileFactory::ObjectFileFactory(
    std::unique_ptr<ComponentFactory> componentFactory, std::string fileName)
    : componentFactory(std::move(componentFactory)) {
  std::cout << "Mock ObjectFileFactory constructor was called with ("
            << fileName.c_str() << ")" << std::endl;
}

ObjectFileFactory::~ObjectFileFactory() {
  std::cout << "Mock ObjectFileFactory destructor was called" << std::endl;
}

ObjectIdentifier ObjectFileFactory::createObject(int type, int x, int y) {
  std::cout << "Mock ObjectFileFactory CreateObject was called with (" << type
            << ", " << x << ", " << y << ")" << std::endl;
  ObjectIdentifier oid;
  return oid;
}

void ObjectFileFactory::createComponent(ComponentData data) {
  std::cout << "Mock ObjectFileFactory createComponent called with ("
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
}

void ObjectFileFactory::setup() {
  std::cout << "Mock ObjectFileFactory Setup was called." << std::endl;
}
void ObjectFileFactory::tearDown() {
  std::cout << "Mock ObjectFileFactory TearDown was called." << std::endl;
}
void ObjectFileFactory::update() {
  std::cout << "Mock ObjectFileFactory Update was called." << std::endl;
}
void ObjectFileFactory::input(Input i) {
  std::cout << "Mock ObjectFileFactory Input was called with " << i.getInput()
            << std::endl;
}
void ObjectFileFactory::physics() {
  std::cout << "Mock ObjectFileFactory Physics was called." << std::endl;
}
int ObjectFileFactory::getIsDirty() {
  std::cout << "Mock ObjectFileFactory GetIsDirty was called." << std::endl;
  return 1;
}
void ObjectFileFactory::render() {
  std::cout << "Mock ObjectFileFactory Render was called." << std::endl;
}
void ObjectFileFactory::clearAllComponents() {
  std::cout << "Mock ObjectFileFactory ClearAllComponents was called."
            << std::endl;
}
void ObjectFileFactory::removeComponent(int type, std::string name,
                                        ObjectIdentifier oid) {
  std::cout << "Mock ObjectFileFactory removeComponent called with (" << type
            << ", " << name.c_str() << ", " << oid.objectType << ", "
            << oid.objectName << ", " << oid.objectId << ")" << std::endl;
}

void ObjectFileFactory::removeObject(ObjectIdentifier oid) {
  std::cout << "Mock ObjectFileFactory removeObject called with ("
            << oid.objectType << ", " << oid.objectName << ", " << oid.objectId
            << ")" << std::endl;
}
std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(
    int type, std::string name, int otype, std::string oname, int oid) {
  std::cout << "Mock ObjectFileFactory getComponentsByObjectAndComponentType "
               "called with ("
            << type << ", " << name.c_str() << ", " << otype << ", "
            << oname.c_str() << ", " << oid << ")" << std::endl;
  std::vector<std::shared_ptr<Component>> retval;
  return retval;
  ;
}
std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(int type,
                                                         std::string name,
                                                         int otype,
                                                         std::string oname) {
  std::cout << "Mock ObjectFileFactory getComponentsByObjectAndComponentType "
               "called with ("
            << type << ", " << name.c_str() << ", " << otype << ", "
            << oname.c_str() << ")" << std::endl;
  std::vector<std::shared_ptr<Component>> retval;
  return retval;
  ;
}
std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(int type,
                                                         std::string name,
                                                         ObjectIdentifier oid) {
  std::cout << "Mock ObjectFileFactory getComponentsByObjectAndComponentType "
               "called with ("
            << type << ", " << name.c_str() << ", " << oid.objectType << ", "
            << oid.objectName << ", " << oid.objectId << ")" << std::endl;
  std::vector<std::shared_ptr<Component>> retval;
  return retval;
  ;
}
std::shared_ptr<Component>
ObjectFileFactory::getComponentByObjectAndComponentType(int type,
                                                        std::string name,
                                                        ObjectIdentifier oid) {
  std::cout << "Mock ObjectFileFactory getComponentByObjectAndComponentType "
               "called with ("
            << type << ", " << name.c_str() << ", " << oid.objectType << ", "
            << oid.objectName << ", " << oid.objectId << ")" << std::endl;
  std::shared_ptr<Component> retval;
  return retval;
  ;
}
std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObject(ObjectIdentifier oid) {
  std::cout << "Mock ObjectFileFactory getComponentsByObject called with ("
            << oid.objectType << ", " << oid.objectName << ", " << oid.objectId
            << ")" << std::endl;
  std::vector<std::shared_ptr<Component>> retval;
  return retval;
  ;
}
void ObjectFileFactory::deleteComponents() {
  std::cout << "Mock ObjectFileFactory deleteComponents was called."
            << std::endl;
}
