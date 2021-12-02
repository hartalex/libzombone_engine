#include "ObjectFileFactory.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "ComponentFactory.hpp"
#include "LoggerService.hpp"
#include "ObjectData.hpp"
#include "ObjectIdentifier.hpp"
#include "component.hpp"
#include "types.hpp"

std::vector<std::string> split(const std::string &str, char delim);

ObjectFileFactory::ObjectFileFactory(
    std::unique_ptr<ComponentFactory> componentFactory, std::string fileName)
    : componentFactory(std::move(componentFactory)) {
  nextObjectId = 0;
  LoggerService::getLogger().debug("Opening Object File '%s'",
                                   fileName.c_str());
  std::string::size_type sz;
  std::fstream inputFile(fileName, std::ios::in);
  if (inputFile.is_open()) {
    std::string line;
    ObjectData data;
    data.type = -1;
    while (!inputFile.eof()) {
      std::getline(inputFile, line);
      if (!inputFile.eof()) {
        // new object
        if (line.at(0) != ' ') {
          // Push last object onto vector if it exists
          if (data.type != -1) {
            this->objects.push_back(data);
            LoggerService::getLogger().debug("Parsed Object %i", data.type);
            data.components.clear();
          }
          std::vector<std::string> type_strings = split(line, ' ');
          data.type = std::stoi(type_strings.at(0), &sz);
          data.name = type_strings.at(1);
        } else {
          ComponentData componentData;
          componentData.objectIdentifier.objectType = data.type;
          componentData.objectIdentifier.objectName = data.name;
          std::vector<std::string> componentStrings = split(line, ' ');
          if (componentStrings.size() >= 2) {
            componentData.type = std::stoi(componentStrings.at(0), &sz);
            componentData.name = componentStrings.at(1);
            if (componentStrings.size() > 2) {
              componentData.type = std::stoi(componentStrings.at(0), &sz);
              componentData.name = componentStrings.at(1);
              for (std::vector<std::string>::iterator it =
                       componentStrings.begin() + 2;
                   it != componentStrings.end(); ++it) {
                componentData.args.push_back(*it);
              }
            }
          } else {
            LoggerService::getLogger().warn(
                "Component String Size is not > 2 %i", componentStrings.size());
          }
          data.components.push_back(componentData);
          LoggerService::getLogger().debug("Parsed Component %i",
                                           componentData.type);
        }
      }
    }
    // Push last object onto vector if it exists
    if (data.type != -1) {
      this->objects.push_back(data);
      LoggerService::getLogger().debug("Parsed Object %i", data.type);
    }
    LoggerService::getLogger().debug("Closing Object File '%s'",
                                     fileName.c_str());
    inputFile.close();
  } else {
    LoggerService::getLogger().warn("Unable to Open Object File '%s'",
                                    fileName.c_str());
  }
}

std::vector<std::string> split(const std::string &str, char delim) {
  std::vector<std::string> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {
    end = str.find(delim, start);
    strings.push_back(str.substr(start, end - start));
  }
  return strings;
}

ObjectFileFactory::~ObjectFileFactory() {}

ObjectIdentifier ObjectFileFactory::createObject(int type, int x, int y) {
  ObjectIdentifier oid;
  oid.objectId = -1;
  oid.objectType = -1;
  oid.objectName = "";
  LoggerService::getLogger().info("Creating Object of type %i, %i", type,
                                  nextObjectId);
  std::vector<ObjectData>::iterator it = objects.begin();
  while (it != objects.end() && (*it).type != type) {
    ++it;
  }
  if (it != objects.end()) {
    ObjectData od = *it;

    for (std::vector<ComponentData>::iterator iit = od.components.begin();
         iit != od.components.end(); ++iit) {
      (*iit).objectIdentifier.objectId = nextObjectId;
      createComponent(*iit);
    }
    ComponentData transformData;
    transformData.name = "transform";
    transformData.type = TYPE_COMPONENT_TRANSFORM_2D;
    transformData.objectIdentifier.objectType = od.type;
    transformData.objectIdentifier.objectName = od.name;
    transformData.objectIdentifier.objectId = nextObjectId;
    transformData.args.push_back(std::to_string(x));
    transformData.args.push_back(std::to_string(y));
    createComponent(transformData);
    oid.objectType = od.type;
    oid.objectName = od.name;
    oid.objectId = nextObjectId;
    nextObjectId++;
  } else {
    LoggerService::getLogger().info("Generic Object Type %i Not Found", type);
  }
  return oid;
}

void ObjectFileFactory::createComponent(ComponentData data) {
  std::shared_ptr<Component> component =
      componentFactory->createComponent(data);
  if (component) {
    LoggerService::getLogger().info("Creating component of Type %i", data.type);
    components.push_back(component);
  } else {
    LoggerService::getLogger().info("Unable to create component %i", data.type);
  }
}

void ObjectFileFactory::setup() {
  std::vector<std::shared_ptr<Component>> tmpComponents = components;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 0) {
      (*cit)->setup();
    }
  }
  deleteComponents();
}
void ObjectFileFactory::tearDown() {
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup()) {
      (*cit)->tearDown();
    }
  }
  deleteComponents();
}
void ObjectFileFactory::update() {
  std::vector<std::shared_ptr<Component>> tmpComponents = components;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 0) {
      (*cit)->setup();
    }
  }
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->update();
    }
  }
  deleteComponents();
}

void ObjectFileFactory::input(Input inputData) {
  std::vector<std::shared_ptr<Component>> tmpComponents = components;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->input(inputData);
    }
  }
  deleteComponents();
}

void ObjectFileFactory::physics() {
  std::vector<std::shared_ptr<Component>> tmpComponents = components;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->physics();
    }
  }
  deleteComponents();
}
int ObjectFileFactory::getIsDirty() {
  int isDirty = 0;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      isDirty += (*cit)->getIsDirty();
    }
  }
  return isDirty;
}
void ObjectFileFactory::render() {
  std::vector<std::shared_ptr<Component>> tmpComponents = components;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->render();
    }
  }
  deleteComponents();
}
void ObjectFileFactory::clearAllComponents() { components.clear(); }

std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(
    int componentType, std::string componentName,
    ObjectIdentifier objectIdentifier) {
  std::vector<std::shared_ptr<Component>> retval;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0) {
      if ((*cit)->getType() == componentType &&
          (*cit)->getName().compare(componentName) == 0 &&
          (*cit)->getObjectIdentifier().objectType ==
              objectIdentifier.objectType &&
          (*cit)->getObjectIdentifier().objectName.compare(
              objectIdentifier.objectName) == 0 &&
          (*cit)->getObjectIdentifier().objectId == objectIdentifier.objectId) {
        retval.push_back(*cit);
      }
      if (componentType == TYPE_COMPONENT_HITPOINTS &&
          (*cit)->getObjectIdentifier().objectId == objectIdentifier.objectId) {
        LoggerService::getLogger().info(
            "Component (%i, %s, %i, %s, %i) looking Component(%i, %s, "
            "%i, "
            "%s, %i)",
            componentType, componentName.c_str(), objectIdentifier.objectType,
            objectIdentifier.objectName.c_str(), objectIdentifier.objectId,
            (*cit)->getType(), (*cit)->getName().c_str(),
            (*cit)->getObjectIdentifier().objectType,
            (*cit)->getObjectIdentifier().objectName.c_str(),
            (*cit)->getObjectIdentifier().objectId);
      }
    }
  }
  return retval;
}

std::shared_ptr<Component>
ObjectFileFactory::getComponentByObjectAndComponentType(
    int componentType, std::string componentName,
    ObjectIdentifier objectIdentifier) {
  std::vector<std::shared_ptr<Component>> foundComponents =
      getComponentsByObjectAndComponentType(componentType, componentName,
                                            objectIdentifier);
  LoggerService::getLogger().info("Found %i instances of Component %s",
                                  foundComponents.size(),
                                  componentName.c_str());
  if (foundComponents.size() > 0) {
    return foundComponents[0];
  }
  return 0;
}

std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(
    int componentType, std::string componentName, int objectType,
    std::string objectName, int objectId) {
  std::vector<std::shared_ptr<Component>> retval;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->getType() == componentType &&
        (*cit)->getName().compare(componentName) == 0 &&
        (*cit)->getObjectIdentifier().objectType == objectType &&
        (*cit)->getObjectIdentifier().objectName.compare(objectName) == 0 &&
        (*cit)->getObjectIdentifier().objectId == objectId) {
      retval.push_back(*cit);
    }
  }
  return retval;
}

std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(
    int componentType, std::string componentName, int objectType,
    std::string objectName) {
  std::vector<std::shared_ptr<Component>> retval;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->getType() == componentType &&
        (*cit)->getName().compare(componentName) == 0 &&
        (*cit)->getObjectIdentifier().objectType == objectType &&
        (*cit)->getObjectIdentifier().objectName.compare(objectName) == 0) {
      retval.push_back(*cit);
    }
  }
  return retval;
}

void ObjectFileFactory::removeComponent(int componentType,
                                        std::string componentName,
                                        ObjectIdentifier objectIdentifier) {
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 &&
        (*cit)->getType() == componentType &&
        (*cit)->getName().compare(componentName) == 0 &&
        (*cit)->getObjectIdentifier().objectType ==
            objectIdentifier.objectType &&
        (*cit)->getObjectIdentifier().objectName.compare(
            objectIdentifier.objectName) == 0 &&
        (*cit)->getObjectIdentifier().objectId == objectIdentifier.objectId) {
      (*cit)->remove();
    }
  }
}
void ObjectFileFactory::removeObject(ObjectIdentifier objectIdentifier) {
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 &&
        (*cit)->getObjectIdentifier().objectType ==
            objectIdentifier.objectType &&
        (*cit)->getObjectIdentifier().objectName.compare(
            objectIdentifier.objectName) == 0 &&
        (*cit)->getObjectIdentifier().objectId == objectIdentifier.objectId) {
      (*cit)->remove();
    }
  }
}

void ObjectFileFactory::deleteComponents() {
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end();) {
    if (*cit != 0 && (*cit)->isRemoved() == 1) {
      // remove components marked to be removed
      cit = components.erase(cit);
    } else if (*cit == 0) {
      // remove components that are no longer valid
      cit = components.erase(cit);
    } else {
      ++cit;
    }
  }
}

std::vector<std::shared_ptr<Component>>
ObjectFileFactory::getComponentsByObject(ObjectIdentifier objectIdentifier) {
  std::vector<std::shared_ptr<Component>> retval;
  for (std::vector<std::shared_ptr<Component>>::iterator cit =
           components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 &&
        (*cit)->getObjectIdentifier().objectType ==
            objectIdentifier.objectType &&
        (*cit)->getObjectIdentifier().objectName.compare(
            objectIdentifier.objectName) == 0 &&
        (*cit)->getObjectIdentifier().objectId == objectIdentifier.objectId) {
      retval.push_back(*cit);
    }
  }
  return retval;
}
