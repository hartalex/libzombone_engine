#include "zombone_engine/ObjectFileFactory.hpp"

#include <exception>
#include <expected>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "zombone_engine/Component.hpp"
#include "zombone_engine/ComponentFactory.hpp"
#include "zombone_engine/ComponentStorageService.hpp"
#include "zombone_engine/LoggerService.hpp"
#include "zombone_engine/ObjectData.hpp"
#include "zombone_engine/ObjectFileParser.hpp"
#include "zombone_engine/ObjectIdentifier.hpp"

using namespace std;

namespace zombone_engine {

ObjectFileFactory::ObjectFileFactory(
    unique_ptr<ComponentFactory> componentFactory,
    unique_ptr<ObjectFileParser> objectFileParser, string fileName)
    : componentFactory(move(componentFactory)),
      objectFileParser(move(objectFileParser)) {
  nextObjectId = 0;
  LoggerService::getLogger().debug("Opening Object File '%s'",
                                   fileName.c_str());
  fstream inputFile(fileName, ios::in);
  if (inputFile.is_open()) {
    objects = this->objectFileParser->parse(inputFile);

    LoggerService::getLogger().debug("Closing Object File '%s'",
                                     fileName.c_str());
    inputFile.close();
  } else {
    LoggerService::getLogger().warn("Unable to Open Object File '%s'",
                                    fileName.c_str());
  }
}

ObjectFileFactory::~ObjectFileFactory() {}

expected<ObjectData, logic_error> ObjectFileFactory::findObjectData(int type) {
  auto it = objects.begin();
  while (it != objects.end() && (*it).type != type) {
    ++it;
  }
  if (it != objects.end()) {
    return *it;
  }
  LoggerService::getLogger().info("Generic Object Type %i Not Found", type);
  return unexpected(logic_error("Object Type Not Found"));
}

ObjectIdentifier ObjectFileFactory::createObject(int type) {
  ObjectIdentifier oid;
  LoggerService::getLogger().info("Creating Object of type %i, %i", type,
                                  nextObjectId);
  auto result = this->findObjectData(type);
  if (result) {
    ObjectData od = result.value();

    for (vector<ComponentData>::iterator iit = od.components.begin();
         iit != od.components.end(); ++iit) {
      (*iit).objectIdentifier.setId(nextObjectId);
      createComponent(*iit);
    }
    oid = ObjectIdentifier(od.type, od.name, nextObjectId);
    nextObjectId++;
    return oid;
  } else {
    LoggerService::getLogger().info("Unable to create object of type %i, %i",
                                    type, nextObjectId);
  }
}

void ObjectFileFactory::createComponent(ComponentData data) {
  shared_ptr<Component> component = componentFactory->createComponent(data);
  if (component) {
    LoggerService::getLogger().info("Creating component of Type %i", data.type);
    ComponentStorageService::getComponentStorage().addComponent(component);
  } else {
    LoggerService::getLogger().info("Unable to create component %i", data.type);
  }
}

// deprecate
vector<shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(
    int componentType, string componentName,
    ObjectIdentifier objectIdentifier) {
  return ComponentStorageService::getComponentStorage()
      .getComponentsByObjectAndComponentType(componentType, componentName,
                                             objectIdentifier);
}

// deprecate
shared_ptr<Component> ObjectFileFactory::getComponentByObjectAndComponentType(
    int componentType, string componentName,
    ObjectIdentifier objectIdentifier) {
  return ComponentStorageService::getComponentStorage()
      .getComponentByObjectAndComponentType(componentType, componentName,
                                            objectIdentifier);
}

// deprecate
vector<shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(int componentType,
                                                         string componentName,
                                                         int objectType,
                                                         string objectName,
                                                         int objectId) {
  return ComponentStorageService::getComponentStorage()
      .getComponentsByObjectAndComponentType(componentType, componentName,
                                             objectType, objectName, objectId);
}

// deprecate
vector<shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(int componentType,
                                                         string componentName,
                                                         int objectType,
                                                         string objectName) {
  return ComponentStorageService::getComponentStorage()
      .getComponentsByObjectAndComponentType(componentType, componentName,
                                             objectType, objectName);
}

// deprecate
void ObjectFileFactory::removeComponent(int componentType, string componentName,
                                        ObjectIdentifier objectIdentifier) {
  ComponentStorageService::getComponentStorage().removeComponent(
      componentType, componentName, objectIdentifier);
}
// deprecate
void ObjectFileFactory::removeObject(ObjectIdentifier objectIdentifier) {
  ComponentStorageService::getComponentStorage().removeObject(objectIdentifier);
}

// deprecate
vector<shared_ptr<Component>> ObjectFileFactory::getComponentsByObject(
    ObjectIdentifier objectIdentifier) {
  return ComponentStorageService::getComponentStorage().getComponentsByObject(
      objectIdentifier);
}

}  // namespace zombone_engine
